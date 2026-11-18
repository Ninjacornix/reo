#!/usr/bin/env python3
"""Completed private complete-audio candidate evidence; no automatic diagnosis."""
import argparse
import json
from pathlib import Path
import re
from analyze_adx_playtest import analyze as analyze_adx
from analyze_sjuni_playtest import iter_log

ORDER=('begin','end','read','control','forward','snapshot','log','packet','bank','pcm','retire')
INSTALL=re.compile(r'\[NATIVE-AUDIO\] complete PCM/bank/RAM candidate installed pcm_bytes=(\d+)(?=$|\s|\[)')
REPORT=re.compile(r'\[NATIVE-AUDIO-REPORT\] owner_joined=([01]) output_started=([01]) frames=(\d+) signal_frames=(\d+) underrun_frames=(\d+) hard_failures=(\d+) queue_rejections=(\d+)(?=$|\s|\[)')
RAM=re.compile(r'\[NATIVE-SOUND-RAM-REPORT\] retired=([01]) active_slots=(\d+) active_operations=(\d+) diagnostic_reports=(\d+) first_refusal_or_diagnostic=(\d+) attempts=([\d,]+) refused=([\d,]+) order=([a-z_,]+)(?=$|\s|\[)')


def parse(lines, environment):
    installed=[];reports=[];ram=[];errors=[]
    for number,line in enumerate(lines,1):
        if m:=INSTALL.search(line):installed.append(dict(line=number,pcm_bytes=int(m[1])))
        elif '[NATIVE-AUDIO] complete PCM/bank/RAM' in line:raise ValueError('Malformed installation proof')
        if m:=REPORT.search(line):
            row=dict(zip(('owner_joined','output_started','frames','signal_frames','underrun_frames','hard_failures','queue_rejections'),map(int,m.groups())))
            if row['signal_frames']>row['frames']or row['underrun_frames']>row['frames']:raise ValueError('Invalid audio counters')
            reports.append(dict(line=number,**row))
        elif '[NATIVE-AUDIO-REPORT]'in line:raise ValueError('Unknown audio report schema')
        if m:=RAM.search(line):
            retired,slots,operations,diagnostics,first=map(int,m.groups()[:5])
            attempts=list(map(int,m[6].split(',')));refused=list(map(int,m[7].split(',')))
            if tuple(m[8].split(','))!=ORDER or len(attempts)!=len(ORDER)or len(refused)!=len(ORDER):raise ValueError('Unknown RAM counter schema')
            if any(b>a for a,b in zip(attempts,refused,strict=True)):raise ValueError('RAM refusals exceed attempts')
            ram.append(dict(line=number,retired=retired,active_slots=slots,active_operations=operations,
                diagnostic_reports=diagnostics,first_refusal_or_diagnostic=first,
                operations={name:dict(attempts=a,refused=b)for name,a,b in zip(ORDER,attempts,refused,strict=True)}))
        elif '[NATIVE-SOUND-RAM-REPORT]'in line:raise ValueError('Unknown RAM report schema')
        if '[NATIVE-AUDIO-ERROR]'in line:errors.append(dict(line=number,text=line))
    if any(len(rows)>1 for rows in(installed,reports,ram)):raise ValueError('Multiple owner/install reports in one process')
    requested=environment.get('REO_NATIVE_AUDIO')=='1'
    if requested and environment.get('REO_NATIVE_PCM')=='1':raise ValueError('Conflicting complete backend selections')
    if (installed or reports or ram)and not requested:raise ValueError('Native proof contradicts actual launch environment')
    if (reports or ram)and not installed:raise ValueError('Final counters have no installation proof')
    status='not-requested'
    if requested:status='unavailable'if errors and not installed else'requested-without-selection-proof'
    if installed:status='installed-without-complete-retirement-proof'
    if reports and ram:
        a,r=reports[0],ram[0]
        retired=bool(a['owner_joined']and r['retired']and not r['active_slots']and not r['active_operations'])
        status='retired-with-audio-faults'if retired and(errors or a['hard_failures']or a['queue_rejections'])else'retired'if retired else'incomplete-retirement'
    return dict(status=status,installations=installed,audio_reports=reports,ram_reports=ram,errors=errors,
        limitations=['Final totals have no per-window timestamps; cannot attribute an underrun to a movie gap.',
          'Diagnostic reports and optional packet-log refusals are separate from audio failures; neither may be silently cleared.',
          'Aggregate first diagnostic lacks RPC/request identity; unrecorded diagnostic details remain unknown.',
          'Installation and joined output are not waveform, all-bank, every-room, clock or performance-equivalence proof.'])


def analyze(session):
    session=Path(session).resolve();report=analyze_adx(session)
    manifest=json.loads((session/'session.json').read_bytes())
    log=Path(manifest['players'][0]['logs'])/'stderr.log'
    report['native_audio']=parse(iter_log(log),report['environment'])
    if report['environment'].get('REO_NATIVE_AUDIO')=='1':
        report['legacy_audio_windows']=report.pop('audio')
        values=report['native_audio']['audio_reports']
        report['audio']=dict(source='native_complete_final',status='measured',**values[0])if values else dict(source='native_complete_final',status='unknown')
    report['limitations']+=report['native_audio']['limitations']
    return report


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--session',type=Path,required=True);a=p.parse_args()
    report=analyze(a.session);out=a.session.resolve()/'audio-candidate-analysis.json'
    if out.exists():raise ValueError('Preserve earlier analysis; use its retained result')
    out.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(report['native_audio'],indent=2));print('Evidence summary: '+str(out))


if __name__=='__main__':main()
