#!/usr/bin/env python3
"""Inspect buffered graphics timings from a completed private test.

Presentation timestamps are CPU return times, not display scanout or original
game updates. Movie log samples give approximate context, never a root cause.
"""
import argparse
import csv
import io
import json
from pathlib import Path
import re

from analyze_sjuni_playtest import analyze as analyze_session, iter_log, sha

FIELDS = ['tick', 'begin_ns', 'scanout_ns', 'present_ns', 'end_ns']
MOVIE = re.compile(r'\[CRI-SYNC\] movie ns=(\d+) vsync=(\d+) time=(-?\d+)/(\d+) decoded=(-?\d+)/(\d+)')


def read_frames(stream):
    header = stream.readline().rstrip('\r\n')
    match = re.fullmatch(r'# dropped=(\d+)', header)
    if not match:
        raise ValueError('Missing dropped-record count')
    reader = csv.DictReader(stream)
    if reader.fieldnames != FIELDS:
        raise ValueError('Unknown frame timing schema')
    rows = []
    previous_end = 0
    for line, raw in enumerate(reader, 3):
        if set(raw) != set(FIELDS) or any(not re.fullmatch(r'\d+', v or '') for v in raw.values()):
            raise ValueError('Malformed frame timing row ' + str(line))
        row = {key: int(value) for key, value in raw.items()}
        points = [row[key] for key in FIELDS[1:] if row[key]]
        if not row['begin_ns'] or not row['end_ns'] or points != sorted(points) or row['begin_ns'] < previous_end:
            raise ValueError('Nonmonotonic frame timing row ' + str(line))
        if row['present_ns'] and not row['scanout_ns']:
            raise ValueError('Presentation lacks scanout stage at row ' + str(line))
        row['line'] = line
        rows.append(row)
        previous_end = row['end_ns']
    return int(match[1]), rows


def distribution(values):
    values = sorted(values)
    if not values:
        return {'count': 0}
    def percentile(p):
        return values[((len(values)-1)*p + 99)//100] / 1e6
    return dict(count=len(values), p50_ms=percentile(50), p95_ms=percentile(95),
                p99_ms=percentile(99), max_ms=values[-1]/1e6,
                over_33_367_ms=sum(v > 33367000 for v in values),
                over_50_ms=sum(v > 50000000 for v in values))


def summarize(rows, movie_samples):
    # Only adjacent samples within two seconds, with an advancing same-rational
    # clock and decoded position, define a sampled movie window. Never bridge a
    # reset, seek, long unobserved gap or frozen pair into one continuous movie.
    windows = []
    for a, b in zip(movie_samples, movie_samples[1:]):
        if (0 < b['ns']-a['ns'] <= 2_000_000_000 and
                a['time_den'] == b['time_den'] and a['decoded_den'] == b['decoded_den'] and
                a['time_den'] > 0 and a['decoded_den'] > 0 and
                b['time_num'] > a['time_num'] and b['decoded_num'] >= a['decoded_num']):
            windows.append((a['ns'], b['ns']))
    def context(begin, end):
        return any(a <= begin <= end <= b for a, b in windows)
    presented = [r for r in rows if r['present_ns']]
    intervals = []
    for a, b in zip(presented, presented[1:]):
        intervals.append(dict(from_line=a['line'], to_line=b['line'], tick=b['tick'],
            begin_ns=a['present_ns'], end_ns=b['present_ns'],
            duration_ns=b['present_ns']-a['present_ns'],
            sampled_movie=context(a['present_ns'], b['present_ns'])))
    stages = {'capture_work': [], 'before_scanout': [], 'present_call': [], 'after_present': []}
    for row in rows:
        stages['capture_work'].append(row['end_ns']-row['begin_ns'])
        if row['scanout_ns']:
            stages['before_scanout'].append(row['scanout_ns']-row['begin_ns'])
        if row['present_ns']:
            stages['present_call'].append(row['present_ns']-row['scanout_ns'])
            stages['after_present'].append(row['end_ns']-row['present_ns'])
    return dict(frame_rows=len(rows), presented_rows=len(presented),
        sampled_movie_windows=len(windows),
        presentation_return_intervals=distribution([v['duration_ns'] for v in intervals]),
        sampled_movie_return_intervals=distribution([v['duration_ns'] for v in intervals if v['sampled_movie']]),
        stages={name: distribution(values) for name, values in stages.items()},
        longest_intervals=sorted(intervals, key=lambda v: v['duration_ns'], reverse=True)[:32])


def analyze(session):
    provenance = analyze_session(session)
    session = Path(provenance['session'])
    configured = provenance['environment'].get('REO_FRAME_PACING_FILE')
    if not configured:
        raise ValueError('Session did not request frame timings')
    path = Path(configured).resolve()
    if not path.is_relative_to(session) or path.is_symlink() or not path.is_file():
        raise ValueError('Missing/private frame timing output required')
    text = path.read_text(encoding='utf-8')
    dropped, rows = read_frames(io.StringIO(text))
    manifest = json.loads((session/'session.json').read_text(encoding='utf-8'))
    log = Path(manifest['players'][0]['logs'])/'stderr.log'
    samples = []
    for line, value in enumerate(iter_log(log), 1):
        if match := MOVIE.search(value):
            sample = dict(zip(('ns','vsync','time_num','time_den','decoded_num','decoded_den'), map(int,match.groups())))
            sample['line'] = line
            samples.append(sample)
    result = summarize(rows, samples)
    return dict(schema=1, session=str(session), source_executable_sha256=provenance['source_executable_sha256'],
        process_identity=provenance['process_identity'], environment=provenance['environment'],
        exit_codes=provenance['exit_codes'], stop_reason=provenance['stop_reason'],
        evidence_sha256=provenance['evidence_sha256'] | {path.name: sha(path)},
        dropped_frame_records=dropped, movie_samples=samples, **result,
        limitations=['CPU presentation-return intervals do not measure actual display scanout or game-update speed.',
            'Graphics spans exclude upstream decoder, resource and game-worker work before capture begins.',
            'Movie context is approximate, sampled about once a second; frozen/reset/gapped intervals are unclassified.',
            'Long CPU intervals are measured symptoms, without an automatically established bottleneck or cause.',
            'Diagnostics, warmup, scheduling and window visibility can affect timing; compare controlled runs.',
            'Buffered records appear after graphics teardown; dropped or absent records cannot exclude stutters.'])


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    report = analyze(args.session.resolve())
    output = args.session.resolve()/'movie-pacing-analysis.json'
    output.write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({key:report[key] for key in ('frame_rows','dropped_frame_records',
        'presentation_return_intervals','sampled_movie_return_intervals','stages')},indent=2))
    print('Evidence summary: '+str(output))


if __name__ == '__main__':
    main()
