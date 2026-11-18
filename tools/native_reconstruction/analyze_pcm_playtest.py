#!/usr/bin/env python3
"""Inspect completed owned native-PCM evidence, with explicit unknown states."""
import argparse
import json
from pathlib import Path
import re

from analyze_adx_playtest import analyze as analyze_adx
from analyze_sjuni_playtest import iter_log

METHODS = ('ensure_output','queue','configure','consumed','render','discard','drain',
           'release','queued_samples','reset','shutdown')
REPORT_KEYS = ('output_owner_joined','host_output_started','stream_fence_joined',
    'frames','signal_frames','underrun_frames','device_callback_attempts',
    'device_frame_requests','device_callbacks_completed','hard_failures',
    'queue_rejections','stop_requests','join_attempts_at_report','self_join_refusals',
    'method_order','method_attempts','method_completed')
UINT64 = (1 << 64)-1


def fields(text):
    result = {}
    for part in text.split():
        if '=' not in part:
            raise ValueError('Malformed native PCM field')
        key,value = part.split('=',1)
        if key in result:
            raise ValueError('Duplicate native PCM field')
        result[key] = value
    return result


def unsigned(value):
    if not re.fullmatch(r'\d+',value) or int(value)>UINT64:
        raise ValueError('Native PCM field is not uint64')
    return int(value)


def parse(lines, environment):
    installs, reports, errors, unavailable = [], [], [], []
    for number,line in enumerate(lines,1):
        if '[NATIVE-PCM] candidate installed ' in line:
            values = fields(line.split('[NATIVE-PCM] candidate installed ',1)[1])
            if set(values) != {'channels','voices','pcm_bytes','metadata_bytes'}:
                raise ValueError('Unknown native PCM installation schema')
            values = {k:unsigned(v) for k,v in values.items()}
            if values != dict(channels=2040,voices=2041,pcm_bytes=391680000,metadata_bytes=4194304):
                raise ValueError('Unreviewed native PCM domain')
            installs.append(dict(line=number,**values))
        if '[NATIVE-PCM-REPORT] ' in line:
            values = fields(line.split('[NATIVE-PCM-REPORT] ',1)[1])
            if set(values)!=set(REPORT_KEYS) or values['method_order'].split(',')!=list(METHODS):
                raise ValueError('Unknown native PCM report schema/method order')
            attempts = [unsigned(v) for v in values.pop('method_attempts').split(',')]
            completed = [unsigned(v) for v in values.pop('method_completed').split(',')]
            values.pop('method_order')
            if len(attempts)!=len(METHODS) or len(completed)!=len(METHODS) or any(c>a for a,c in zip(attempts,completed)):
                raise ValueError('Native PCM completed/attempt counters contradict')
            values = {k:unsigned(v) for k,v in values.items()}
            if (values['output_owner_joined']!=1 or values['host_output_started'] not in (0,1) or
                values['stream_fence_joined']!=values['host_output_started'] or
                values['signal_frames']>values['frames'] or values['underrun_frames']>values['frames'] or
                values['device_callbacks_completed']>values['device_callback_attempts']):
                raise ValueError('Native PCM output/lifetime counters contradict')
            reports.append(dict(line=number,**values,method_attempts=dict(zip(METHODS,attempts)),
                                method_completed=dict(zip(METHODS,completed))))
        if '[NATIVE-PCM-ERROR]' in line:
            errors.append(dict(line=number,text=line))
        if '[NATIVE-PCM] installation unavailable' in line:
            unavailable.append(dict(line=number,text=line))
    if len(installs)>1 or len(reports)>1:
        raise ValueError('Multiple native PCM installations/join reports')
    if (installs or reports) and environment.get('REO_NATIVE_PCM')!='1':
        raise ValueError('Native PCM proof contradicts exact launch opt-in')
    if reports and not installs:
        raise ValueError('Native PCM join report lacks installation evidence')
    status = ('joined-with-faults' if errors or reports[0]['hard_failures'] else 'joined') if reports else (
        'installed-without-join-proof' if installs else 'unavailable' if unavailable else
        'requested-without-selection-proof' if environment.get('REO_NATIVE_PCM')=='1' else 'not-requested')
    return dict(status=status,installations=installs,joined_reports=reports,
        errors=errors,unavailable_notices=unavailable,
        audio_evidence='native final counters' if reports else 'unknown for native backend')


def analyze(session):
    report = analyze_adx(session)
    manifest = json.loads((session/'session.json').read_text(encoding='utf-8'))
    log = Path(manifest['players'][0]['logs'])/'stderr.log'
    report['native_pcm'] = parse(iter_log(log),report['environment'])
    if report['environment'].get('REO_NATIVE_PCM')=='1':
        report['legacy_cri_audio'] = report.pop('audio')
        joined = report['native_pcm']['joined_reports']
        report['audio'] = (dict(source='native_pcm_final',status='measured',
            frames=joined[0]['frames'],signal_frames=joined[0]['signal_frames'],
            underrun_frames=joined[0]['underrun_frames'],
            host_output_started=bool(joined[0]['host_output_started'])) if joined else
            dict(source='native_pcm_final',status='unknown'))
    report['limitations'] += [
        'Method attempts include refused calls; only completed counters establish successful facade execution.',
        'Native PCM final frame/underrun counters replace the legacy CRI report windows; missing legacy windows mean unknown, not zero native underruns.',
        'A joined stream and successful operations do not prove speaker waveform, every bank/RPC producer retirement, whole-game domain admission or a speedup.']
    return report


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session',required=True,type=Path)
    args = parser.parse_args()
    report = analyze(args.session.resolve())
    output = args.session.resolve()/'pcm-analysis.json'
    output.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(report['native_pcm'],indent=2))
    print('Evidence summary: '+str(output))


if __name__=='__main__':
    main()
