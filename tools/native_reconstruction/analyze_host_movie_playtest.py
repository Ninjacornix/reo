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
    incidents = sorted((r for r in changes if r['gap_ms'] >= 50), key=lambda r: r['gap_ms'], reverse=True)[:32]
    for incident in incidents:
        samples = [r for r in rows if incident['begin_ns'] <= r['qpc_ns'] <= incident['end_ns']]
        incident['observer_max_gap_ms'] = max(((b['qpc_ns']-a['qpc_ns'])/1e6 for a, b in zip(samples, samples[1:])), default=None)
        incident['observer_max_read_ms'] = max((r['read_ns']/1e6 for r in samples), default=None)
        window = [r for r in frames if incident['begin_ns']-100_000_000 <= r['begin_ns'] <= incident['end_ns']+100_000_000]
        incident['presentation_loop'] = dict(observations=len(window),
            max_begin_gap_ms=max(((b['begin_ns']-a['begin_ns'])/1e6 for a, b in zip(window, window[1:])), default=None),
            max_span_ms=max(((r['end_ns']-r['begin_ns'])/1e6 for r in window), default=None))
        incident['classification'] = 'measured public-frame handoff gap; cause unknown'
        incident['evidence'] = dict(progress=progress.name, pacing=pacing.name)
    controls = folder / 'native-controls-v1.jsonl'
    observed = [json.loads(line) for line in controls.read_text().splitlines() if line]
    diagnostics = owned.classify_native_logs(logs)
    files = [folder / 'run.json', folder / 'session.json', progress, pacing, controls,
             folder / 'native-progress-v1-receipt.json', folder / 'native-controls-v1-receipt.json',
             folder / 'native-audio-v1-receipt.json', logs / 'stderr.log']
    audio = json.loads((folder / 'audio-candidate-analysis.json').read_text())['native_audio']
    return dict(schema=1, executable_sha256=manifest['sourceSha256'], identity=run['players'][0],
        source_starts=source_starts, final_reports=unique_reports, duplicate_report_lines=len(reports)-len(unique_reports),
        supervisor_original_verdict=run['runVerdict'], current_diagnostics=diagnostics,
        current_outcome=owned.native_outcome(run['exitCodes'][0], diagnostics),
        original_player_slot_samples=len(observed),
        original_player_slot_nonzero_samples=sum(any(r['original_mwsfd_player_active']) for r in observed),
        progress_samples=len(rows), progress_changes=len(changes), frame_trace_retention=retained,
        incidents=incidents, native_audio=audio,
        process_audio_capture=json.loads((folder / 'native-audio-v1-receipt.json').read_text())['capture'],
        evidence_sha256={str(p.relative_to(folder)): sha(p) for p in files},
        limitations=['CPU observations do not independently prove display scanout or audible synchronization.',
            'The player was away from the PC; no subjective A/V confirmation is claimed.',
            'The progress observer retains its teardown WinError 299 and partial receipt.',
            'Native audio aggregate underruns cannot be assigned to a video incident without per-event timing.',
            'Normal guest-thread shutdown is reclassified by the corrected analyzer; historical run.json remains intact.',
            'The native producer and game-side consumer need separate timestamps to locate the handoff stall.',
            'This exercised route does not complete Step 3.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', type=Path, required=True)
    args = parser.parse_args()
    folder = args.session.resolve()
    if not folder.is_relative_to(ROOT / 'build-native-sjuni/playtests'):
        raise ValueError('Private owned test evidence required')
    output = folder / 'native-movie-analysis.json'
    if output.exists():
        raise ValueError('Preserve existing analysis')
    result = analyze(folder)
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({k: result[k] for k in ('current_outcome', 'final_reports', 'original_player_slot_nonzero_samples', 'progress_samples')}))
    print(output)


if __name__ == '__main__':
    main()
