#!/usr/bin/env python3
"""Correlate completed native movie evidence; never attach or invent a cause."""
import argparse
import csv
import hashlib
import json
from pathlib import Path
import re
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/coop_playtest'))
import coop_playtest as owned


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def read_trace(path):
    if not path.exists():
        return None
    with path.open() as stream:
        retention = next(stream).strip()
        rows = []
        for number, row in enumerate(csv.DictReader(stream), 3):
            values = {k: float(v) if k == 'position_seconds' else int(v) for k, v in row.items()}
            values['line'] = number
            rows.append(values)
    return dict(file=path.name, retention=retention, rows=rows)


def correlate_pipeline(incident, producer, consumer):
    begin, end = incident['begin_ns'], incident['end_ns']
    result = {}
    if consumer:
        requests = [r for r in consumer['rows'] if begin <= r['begin_ns'] <= end]
        result['consumer'] = dict(file=consumer['file'], retention=consumer['retention'],
            requests=len(requests), fresh_frames=sum(r['available'] for r in requests),
            first_request_offset_ms=(requests[0]['begin_ns']-begin)/1e6 if requests else None,
            last_request_offset_ms=(end-requests[-1]['begin_ns'])/1e6 if requests else None,
            first_line=requests[0]['line'] if requests else None,
            last_line=requests[-1]['line'] if requests else None,
            max_request_gap_ms=max(((b['begin_ns']-a['begin_ns'])/1e6 for a, b in zip(requests, requests[1:])), default=None),
            max_borrow_ms=max(((r['borrowed_ns']-r['begin_ns'])/1e6 for r in requests), default=None))
    if producer:
        rows = producer['rows']
        published = [r for r in rows if r['publish_end_ns']]
        previous = next((r for r in reversed(published) if r['publish_end_ns'] <= begin), None)
        following = next((r for r in published if r['publish_end_ns'] > begin), None)
        same_source = bool(previous and following and
            (previous['generation'], previous['clip']) == (following['generation'], following['clip']))
        surrounding = [r for r in rows if begin-100_000_000 <= r['end_ns'] <= end+100_000_000]
        heartbeat = bool(rows and 'position_seconds' in rows[0])
        heartbeat_rows = [r for r in surrounding if previous and
            (r['generation'], r['clip']) == (previous['generation'], previous['clip'])]
        result['producer'] = dict(file=producer['file'], retention=producer['retention'],
            previous_publication=previous, next_publication=following,
            same_source=same_source,
            publication_gap_ms=(following['publish_end_ns']-previous['publish_end_ns'])/1e6 if same_source else None,
            observed_iterations=len(surrounding),
            max_recorded_iteration_ms=max(((r['end_ns']-r['wake_begin_ns'])/1e6 for r in surrounding), default=None),
            periodic_heartbeat_available=heartbeat,
            max_unobserved_interval_ms=max((max(0, b['wake_begin_ns']-a['end_ns'])/1e6
                for a, b in zip(heartbeat_rows, heartbeat_rows[1:])), default=None) if heartbeat else None,
            empty_poll_observations=sum(not r['updated'] for r in heartbeat_rows) if heartbeat else None,
            native_clock_advance_seconds=(heartbeat_rows[-1]['position_seconds']-heartbeat_rows[0]['position_seconds'])
                if heartbeat and len(heartbeat_rows)>1 else None,
            native_event_count_change=(heartbeat_rows[-1]['events']-heartbeat_rows[0]['events'])
                if heartbeat and len(heartbeat_rows)>1 else None)
    return result


def classify_incident(incident):
    consumer = incident['pipeline'].get('consumer', {})
    if (incident['observer_max_gap_ms'] is not None and incident['observer_max_gap_ms'] >= 50 and
            consumer.get('requests', 0) >= 3 and consumer['fresh_frames'] == consumer['requests'] and
            consumer['retention'] == '# dropped=0' and consumer['max_request_gap_ms'] <= 50 and
            consumer['first_request_offset_ms'] <= 50 and consumer['last_request_offset_ms'] <= 50):
        return 'observer sampling gap with continued fresh consumer frames; pipeline freeze not established'
    return 'measured public-frame observation gap; cause unknown'


def producer_epochs(trace):
    if not trace:
        return []
    epochs, current, previous = [], [], None
    for row in trace['rows']:
        if not row['publish_end_ns']:
            continue
        identity = (row['generation'], row['clip'])
        if previous and (identity != (previous['generation'], previous['clip']) or row['ordinal'] < previous['ordinal']):
            epochs.append(current)
            current = []
        current.append(row)
        previous = row
    if current:
        epochs.append(current)
    return [dict(generation=rows[0]['generation'], clip=rows[0]['clip'],
        publications=len(rows), unique_ordinals=len({r['ordinal'] for r in rows}),
        first_ordinal=rows[0]['ordinal'], last_ordinal=rows[-1]['ordinal'],
        first_line=rows[0]['line'], last_line=rows[-1]['line'],
        first_publication_ns=rows[0]['publish_end_ns'], last_publication_ns=rows[-1]['publish_end_ns'],
        max_publication_gap_ms=max(((b['publish_end_ns']-a['publish_end_ns'])/1e6
            for a, b in zip(rows, rows[1:])), default=None),
        max_backpressure=max(r['backpressure'] for r in rows)) for rows in epochs]


def analyze(folder):
    manifest = json.loads((folder / 'session.json').read_text())
    run = json.loads((folder / 'run.json').read_text())
    if not run.get('finishedUtc') or manifest['game'] != 'file1' or len(run['players']) != 1:
        raise ValueError('One completed File1 test required')
    if run['networkConfig']['environment'].get('REO_NATIVE_HOST_MOVIE') != '1':
        raise ValueError('Actual native host selection required')
    logs = Path(manifest['players'][0]['logs'])
    text = (logs / 'stderr.log').read_text(errors='replace')
    source_starts = [dict(generation=int(a), clips=int(b), loop=int(c)) for a, b, c in re.findall(
        r'\[NATIVE-HOST-MOVIE\] source started generation=(\d+) clips=(\d+) loop=(\d+)', text)]
    reports = [dict(joined=int(a), sources=int(b), delivered_frames=int(c), error=d) for a, b, c, d in re.findall(
        r'\[NATIVE-HOST-MOVIE-REPORT\] joined=(\d+) sources=(\d+) delivered_frames=(\d+) error=([^\r\n]+)', text)]
    unique_reports = list({json.dumps(r, sort_keys=True): r for r in reports}.values())
    progress = folder / 'native-progress-v1.csv'
    rows = [{k: int(v) for k, v in row.items()} for row in csv.DictReader(progress.open())]
    changes, previous = [], None
    for number, row in enumerate(rows, 2):
        if not row['handle'] or row['status'] != 2:
            previous = None
            continue
        identity = (row['handle'], row['width'], row['height'])
        if previous is None or identity != previous[2] or row['frame'] < previous[1]:
            previous = (row['qpc_ns'], row['frame'], identity, number)
        elif row['frame'] != previous[1]:
            changes.append(dict(begin_ns=previous[0], end_ns=row['qpc_ns'],
                gap_ms=(row['qpc_ns']-previous[0])/1e6, advance=row['frame']-previous[1],
                frame=row['frame'], previous_line=previous[3], line=number))
            previous = (row['qpc_ns'], row['frame'], identity, number)
    pacing = folder / 'frame-pacing.csv'
    with pacing.open() as stream:
        retained = next(stream).strip()
        frames = [{k: int(v) for k, v in row.items()} for row in csv.DictReader(stream)]
    producer, consumer = (read_trace(folder / name) for name in ('producer.csv', 'consumer.csv'))
    incidents = sorted((r for r in changes if r['gap_ms'] >= 50), key=lambda r: r['gap_ms'], reverse=True)[:32]
    for incident in incidents:
        samples = [r for r in rows if incident['begin_ns'] <= r['qpc_ns'] <= incident['end_ns']]
        incident['observer_max_gap_ms'] = max(((b['qpc_ns']-a['qpc_ns'])/1e6 for a, b in zip(samples, samples[1:])), default=None)
        incident['observer_max_read_ms'] = max((r['read_ns']/1e6 for r in samples), default=None)
        window = [r for r in frames if incident['begin_ns']-100_000_000 <= r['begin_ns'] <= incident['end_ns']+100_000_000]
        incident['presentation_loop'] = dict(observations=len(window),
            max_begin_gap_ms=max(((b['begin_ns']-a['begin_ns'])/1e6 for a, b in zip(window, window[1:])), default=None),
            max_span_ms=max(((r['end_ns']-r['begin_ns'])/1e6 for r in window), default=None))
        incident['evidence'] = dict(progress=progress.name, pacing=pacing.name)
        incident['pipeline'] = correlate_pipeline(incident, producer, consumer)
        incident['classification'] = classify_incident(incident)
    controls = folder / 'native-controls-v1.jsonl'
    observed = [json.loads(line) for line in controls.read_text().splitlines() if line]
    diagnostics = owned.classify_native_logs(logs)
    files = [folder / 'run.json', folder / 'session.json', progress, pacing, controls,
             folder / 'native-progress-v1-receipt.json', folder / 'native-controls-v1-receipt.json',
             folder / 'native-audio-v1-receipt.json', logs / 'stderr.log']
    files += [folder / trace['file'] for trace in (producer, consumer) if trace]
    audio = json.loads((folder / 'audio-candidate-analysis.json').read_text())['native_audio']
    return dict(schema=1, executable_sha256=manifest['sourceSha256'], identity=run['players'][0],
        source_starts=source_starts, final_reports=unique_reports, duplicate_report_lines=len(reports)-len(unique_reports),
        supervisor_original_verdict=run['runVerdict'], current_diagnostics=diagnostics,
        current_outcome=owned.native_outcome(run['exitCodes'][0], diagnostics),
        original_player_slot_samples=len(observed),
        original_player_slot_nonzero_samples=sum(any(r['original_mwsfd_player_active']) for r in observed),
        progress_samples=len(rows), progress_changes=len(changes), frame_trace_retention=retained,
        producer_epochs=producer_epochs(producer),
        incidents=incidents, native_audio=audio,
        process_audio_capture=json.loads((folder / 'native-audio-v1-receipt.json').read_text())['capture'],
        evidence_sha256={str(p.relative_to(folder)): sha(p) for p in files},
        limitations=['CPU observations do not independently prove display scanout or audible synchronization.',
            'The player was away from the PC; no subjective A/V confirmation is claimed.',
            'The progress observer retains its teardown WinError 299 and partial receipt.',
            'Native audio aggregate underruns cannot be assigned to a video incident without per-event timing.',
            'Normal guest-thread shutdown is reclassified by the corrected analyzer; historical run.json remains intact.',
            'Pipeline timestamps include host descheduling; short recorded calls do not prove continuous worker execution.',
            'Older producer traces omit fast empty polls; absent records cannot distinguish engine starvation from worker preemption.',
            'This exercised route does not complete Step 3.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', type=Path, required=True)
    parser.add_argument('--output-name', default='native-movie-analysis.json')
    args = parser.parse_args()
    folder = args.session.resolve()
    if not folder.is_relative_to(ROOT / 'build-native-sjuni/playtests'):
        raise ValueError('Private owned test evidence required')
    if Path(args.output_name).name != args.output_name or not args.output_name.endswith('.json'):
        raise ValueError('A local JSON output filename is required')
    output = folder / args.output_name
    if output.exists():
        raise ValueError('Preserve existing analysis')
    result = analyze(folder)
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ('current_outcome', 'final_reports', 'original_player_slot_nonzero_samples', 'progress_samples')}))
    print(output)


if __name__ == '__main__':
    main()
