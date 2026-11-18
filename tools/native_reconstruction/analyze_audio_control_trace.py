#!/usr/bin/env python3
"""Locate measured audio shortages between native controller observations."""
import argparse
import csv
import hashlib
import json
import math
from pathlib import Path
import re

COLUMNS = 'begin_ns,end_ns,game_tick,output_frames,signal_frames,underrun_frames,slot,generation,active,playing,draining,queued_left,queued_right,late_samples,skipped_samples,volume,gain,frequency'.split(',')
DETAIL_COLUMNS = 'source_known,source_observed_ns,source_state,source_in_flight,encoded_buffered,encoded_free,encoded_capacity,source_progress_sectors,source_cumulative_bytes,source_request_id,decoded_samples,copied_samples'.split(',')


def read_trace(path):
    snapshots, errors, current = [], [], None
    with Path(path).open() as stream:
        retention = next(stream).strip()
        match = re.fullmatch(r'# dropped=(\d+); owner_joined=1; control_snapshots=([12])', retention)
        if not match:
            raise ValueError('Unsupported audio-control trace header')
        rows = csv.DictReader(stream)
        version=int(match[2])
        if rows.fieldnames != COLUMNS + (DETAIL_COLUMNS if version==2 else []):
            raise ValueError('Unsupported audio-control columns')
        for line, raw in enumerate(rows, 3):
            try:
                if None in raw or any(v is None for v in raw.values()):
                    raise ValueError('Truncated or extra fields')
                row = {k: float(v) if k == 'gain' else int(v) for k, v in raw.items()}
                if not math.isfinite(row['gain']) or any(v < 0 for k, v in row.items() if k not in ('slot', 'gain')):
                    raise ValueError('Invalid counter or gain')
                if row['end_ns'] < row['begin_ns'] or row['slot'] < -1 or row['slot'] >= 16:
                    raise ValueError('Invalid interval or native slot')
                if row['signal_frames'] > row['output_frames'] or row['underrun_frames'] > row['output_frames']:
                    raise ValueError('Invalid aggregate counters')
                if any(row[k] not in (0, 1) for k in ('active', 'playing', 'draining')):
                    raise ValueError('Invalid stream flag')
                if version==2 and any(row[k] not in (0,1) for k in ('source_known','source_in_flight')):
                    raise ValueError('Invalid source observation flag')
                identity = tuple(row[k] for k in ('begin_ns', 'end_ns', 'game_tick'))
                if current is None or current['identity'] != identity:
                    if current:
                        snapshots.append(current)
                    current = dict(identity=identity, begin_ns=row['begin_ns'], end_ns=row['end_ns'],
                        tick=row['game_tick'], output_frames=row['output_frames'], signal_frames=row['signal_frames'],
                        underrun_frames=row['underrun_frames'], first_line=line, last_line=line, streams={})
                if any(row[k] != current[k] for k in ('output_frames', 'signal_frames', 'underrun_frames')):
                    raise ValueError('Inconsistent aggregate within snapshot')
                if row['slot'] in current['streams']:
                    raise ValueError('Duplicate native slot within snapshot')
                current['last_line'] = line
                current['streams'][row['slot']] = dict(row, line=line)
            except (ValueError, TypeError) as error:
                errors.append(dict(line=line, reason=str(error)))
        if current:
            snapshots.append(current)
    return dict(file=str(path), retention=retention, trace_version=version, dropped=int(match[1]), snapshots=snapshots, invalid_rows=errors)


def analyze(trace):
    rows, windows, gaps, resets = trace['snapshots'], [], [], []
    for before, after in zip(rows, rows[1:]):
        if after['begin_ns'] < before['begin_ns'] or any(after[k] < before[k] for k in ('output_frames', 'underrun_frames')):
            resets.append(dict(before_line=before['last_line'], after_line=after['first_line']))
            continue
        gap = (after['begin_ns']-before['begin_ns'])/1e6
        delta = after['underrun_frames']-before['underrun_frames']
        refs = dict(before_line=before['first_line'], after_line=after['first_line'],
                    begin_ns=before['begin_ns'], end_ns=after['end_ns'], service_observation_gap_ms=gap)
        if gap >= 50:
            gaps.append(dict(refs, underrun_delta=delta))
        if not delta:
            continue
        increases = []
        for slot, stream in after['streams'].items():
            old = before['streams'].get(slot)
            if slot < 0 or not old or old['generation'] != stream['generation']:
                continue
            missing = stream['late_samples']+stream['skipped_samples']-old['late_samples']-old['skipped_samples']
            if missing > 0:
                increases.append(dict(slot=slot, generation=stream['generation'], missing_sample_counter_delta=missing,
                    before=old, after=stream))
        windows.append(dict(refs, underrun_delta=delta, output_frame_delta=after['output_frames']-before['output_frames'],
            missing_counter_increases=increases,
            finding='measured aggregate audio shortage between controller observations; cause unconfirmed'))
    return dict(schema=1, status='limited observations' if trace['dropped'] or trace['invalid_rows'] or resets else 'observations parsed',
        file=trace['file'], retention=trace['retention'],trace_version=trace['trace_version'], dropped_snapshots=trace['dropped'], invalid_rows=trace['invalid_rows'],
        counter_or_time_resets=resets, snapshots=len(rows),
        first_observation={k:rows[0][k] for k in ('begin_ns', 'output_frames', 'underrun_frames')} if rows else None,
        last_observation={k:rows[-1][k] for k in ('end_ns', 'output_frames', 'underrun_frames')} if rows else None,
        shortage_windows=len(windows), measured_underrun_increase=sum(w['underrun_delta'] for w in windows),
        largest_shortage_windows=sorted(windows, key=lambda w:w['underrun_delta'], reverse=True)[:32],
        largest_service_gaps=sorted(gaps, key=lambda g:g['service_observation_gap_ms'], reverse=True)[:32],
        limitations=['A counter increase is bounded by two control observations, not an individual audio-callback timestamp.',
            'Late/skipped counters identify observed stream shortages; they do not prove their upstream cause.',
            'Replacement or counter rebasing can hide per-stream increments; aggregate counts must not be summed across streams.',
            'A service observation gap includes host scheduling and unobserved work.',
            'Muted/gain state at an endpoint does not establish audibility during the whole interval.',
            'Dropped/invalid records and activity after the last snapshot limit coverage; compare final native totals.',
            'This analysis is neither an A/V synchronization check nor a controlled fix/retest.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--trace', type=Path, required=True)
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--producer', type=Path)
    parser.add_argument('--consumer', type=Path)
    args = parser.parse_args()
    if args.output.exists():
        raise ValueError('Preserve earlier analysis')
    result = analyze(read_trace(args.trace))
    if args.producer or args.consumer:
        from analyze_host_movie_playtest import read_trace as read_movie_trace, correlate_pipeline
        producer = read_movie_trace(args.producer) if args.producer else None
        consumer = read_movie_trace(args.consumer) if args.consumer else None
        for window in result['largest_shortage_windows'] + result['largest_service_gaps']:
            window['movie_pipeline'] = correlate_pipeline(window, producer, consumer)
        result['correlation_inputs_sha256'] = {str(p):hashlib.sha256(p.read_bytes()).hexdigest()
            for p in (args.producer,args.consumer) if p and p.exists()}
        result['limitations'].append('CSV headers alone do not prove common process identity; the containing bundle must bind correlation inputs.')
    result['trace_sha256'] = hashlib.sha256(args.trace.read_bytes()).hexdigest()
    result['analyzer_sha256'] = hashlib.sha256(Path(__file__).read_bytes()).hexdigest()
    with args.output.open('x') as stream:
        json.dump(result, stream, indent=2)
        stream.write('\n')
    print(json.dumps({k:result[k] for k in ('status', 'snapshots', 'shortage_windows', 'measured_underrun_increase')}))


if __name__ == '__main__':
    main()
