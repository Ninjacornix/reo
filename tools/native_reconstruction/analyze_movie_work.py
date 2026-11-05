#!/usr/bin/env python3
"""Offline bounded movie-work evidence; elapsed overlap is not causal attribution."""
import argparse
from bisect import bisect_right
import csv
import hashlib
import io
import json
from pathlib import Path
import re

from analyze_movie_pacing import read_frames
from analyze_sjuni_playtest import analyze as analyze_session, iter_log

BOUNDARIES = ('owner_control', 'decode', 'output', 'release_partial_fence', 'batch_fence', 'upload_fence')
META = ('owner_begin_ns', 'epoch', 'slow_threshold_ns', 'event_capacity',
        'elapsed_includes_descheduling', 'dropped_slow_events', 'invalid_intervals', 'aggregates_saturated')
HEADER = 'boundary,generation,serial,begin_ns,end_ns,elapsed_ns'
AGG_HEADER = '# aggregate,boundary,calls,elapsed_sum_ns,elapsed_max_ns,slow_calls'
UINT64 = (1 << 64) - 1
MARKER = re.compile(r'# reo_movie_timing_schema=([0-9]+)')
SUCCESS = re.compile(r'\[MOVIE-TIMING\] exported owner epoch=([0-9]+) retained=([0-9]+) dropped=([0-9]+) invalid=([0-9]+) saturated=([01]) path=(.*)')


def unsigned(text):
    if not re.fullmatch(r'[0-9]+', text) or int(text) > UINT64:
        raise ValueError('Expected uint64 decimal')
    return int(text)


def issue(section, line, message, error=True):
    section['issues'].append(dict(line=line, severity='error' if error else 'partial', message=message))


def finish(section, end_line):
    section['end_line'] = end_line
    meta, events, aggregates = section['metadata'], section['events'], section['aggregates']
    trailer = section['declared_retained']
    complete = trailer is not None
    missing = [key for key in META if key not in meta]
    if missing:
        issue(section, end_line, 'Missing metadata: ' + ', '.join(missing), complete)
    if not section['csv_header_seen']:
        issue(section, end_line, 'Missing event CSV header', complete)
    if not section.get('aggregate_header_seen'):
        issue(section, end_line, 'Missing aggregate header', complete)
    if set(aggregates) != set(BOUNDARIES):
        issue(section, end_line, 'Incomplete boundary aggregates', complete)
    if not complete:
        issue(section, end_line, 'Missing owner completion trailer', False)
    elif trailer != len(events):
        issue(section, end_line, 'Trailer retained count differs from valid retained rows')
    if meta.get('event_capacity', 0) < len(events):
        issue(section, end_line, 'Retained rows exceed declared capacity')
    if meta.get('event_capacity', 4096) > 4096:
        issue(section, end_line, 'Declared capacity exceeds schema1 recorder bound')
    if meta.get('elapsed_includes_descheduling', 1) != 1:
        issue(section, end_line, 'Unexpected elapsed-time semantics')
    if meta.get('aggregates_saturated', 0) not in (0, 1):
        issue(section, end_line, 'Invalid saturation flag')
    for key in ('event_capacity', 'slow_threshold_ns'):
        if key in meta and meta[key] == 0:
            issue(section, end_line, 'Zero ' + key)
    for boundary, aggregate in aggregates.items():
        count, total, maximum, slow = (aggregate[key] for key in ('calls', 'elapsed_sum_ns', 'elapsed_max_ns', 'slow_calls'))
        retained = [event for event in events if event['boundary'] == boundary]
        threshold = meta.get('slow_threshold_ns')
        if (slow > count or maximum > total or (count == 0 and (total or maximum or slow)) or
                (count and total > count * maximum) or
                (threshold is not None and ((slow and maximum < threshold) or
                                           (not slow and count and maximum >= threshold)))):
            issue(section, aggregate['line'], 'Inconsistent aggregate for ' + boundary)
        if (len(retained) > slow or any(event['elapsed_ns'] > maximum for event in retained) or
                (not meta.get('aggregates_saturated') and
                 (sum(event['elapsed_ns'] for event in retained) > total or
                  (threshold is not None and slow * threshold > total)))):
            issue(section, aggregate['line'], 'Retained rows conflict with aggregate for ' + boundary)
    if complete and len(aggregates) == len(BOUNDARIES) and not meta.get('aggregates_saturated'):
        if sum(value['slow_calls'] for value in aggregates.values()) != len(events) + meta.get('dropped_slow_events', 0):
            issue(section, end_line, 'Slow counts do not equal retained plus dropped events')
    section['integrity'] = ('invalid' if any(x['severity'] == 'error' for x in section['issues']) else
                            'partial' if section['issues'] else 'complete')
    return section


def read_work(text):
    """Recover section-local evidence; a bad section never discards later owners."""
    sections, preamble = [], []
    current = None
    lines = text.splitlines()
    for number, line in enumerate(lines, 1):
        marker = MARKER.fullmatch(line)
        if marker:
            if current:
                sections.append(finish(current, number - 1))
            current = dict(id=len(sections) + 1, schema=int(marker[1]), start_line=number,
                           metadata={}, aggregates={}, events=[], issues=[], csv_header_seen=False,
                           declared_retained=None)
            if current['schema'] != 1:
                issue(current, number, 'Unsupported timing schema; section not interpreted')
            continue
        if not line:
            continue
        if current is None:
            preamble.append(number)
            continue
        if current['schema'] != 1:
            continue
        if current['declared_retained'] is not None:
            issue(current, number, 'Unexpected data after owner completion trailer')
            continue
        try:
            if match := re.fullmatch(r'# owner_complete=1 retained=([0-9]+)', line):
                current['declared_retained'] = unsigned(match[1])
            elif match := re.fullmatch(r'# (\w+)=([0-9]+)', line):
                key, value = match.groups()
                if key not in META or key in current['metadata'] or current['csv_header_seen']:
                    raise ValueError('Unknown, duplicated or late metadata')
                current['metadata'][key] = unsigned(value)
            elif line == AGG_HEADER:
                if current.get('aggregate_header_seen') or current['csv_header_seen']:
                    raise ValueError('Duplicated or late aggregate header')
                current['aggregate_header_seen'] = True
            elif line.startswith('# aggregate,'):
                values = next(csv.reader([line]))
                if (len(values) != 6 or values[1] not in BOUNDARIES or
                        values[1] in current['aggregates'] or current['csv_header_seen']):
                    raise ValueError('Unknown, duplicated or malformed aggregate')
                current['aggregates'][values[1]] = dict(zip(
                    ('calls', 'elapsed_sum_ns', 'elapsed_max_ns', 'slow_calls'), map(unsigned, values[2:])), line=number)
            elif line == HEADER:
                if current['csv_header_seen']:
                    raise ValueError('Duplicated event CSV header')
                current['csv_header_seen'] = True
            else:
                values = next(csv.reader([line]))
                if not current['csv_header_seen'] or len(values) != 6 or values[0] not in BOUNDARIES:
                    raise ValueError('Unknown or malformed event row')
                event = dict(zip(('generation', 'serial', 'begin_ns', 'end_ns', 'elapsed_ns'), map(unsigned, values[1:])),
                             boundary=values[0], line=number)
                if (event['end_ns'] < event['begin_ns'] or event['end_ns'] - event['begin_ns'] != event['elapsed_ns'] or
                        event['elapsed_ns'] < current['metadata'].get('slow_threshold_ns', 0) or
                        event['begin_ns'] < current['metadata'].get('owner_begin_ns', 0)):
                    raise ValueError('Invalid event elapsed/threshold/owner interval')
                # RAII appends on completion; nested spans may begin earlier.
                if current['events'] and event['end_ns'] < current['events'][-1]['end_ns']:
                    raise ValueError('Completion timestamps regressed within one owner')
                capacity = min(current['metadata'].get('event_capacity', 4096), 4096)
                if len(current['events']) >= capacity:
                    raise ValueError('Event exceeds schema1 bounded retention')
                current['events'].append(event)
        except (ValueError, csv.Error) as error:
            truncated_end = number == len(lines) and not text.endswith('\n')
            issue(current, number, str(error), not truncated_end)
    if current:
        if text and not text.endswith('\n'):
            issue(current, len(lines), 'File ends without newline; truncation cannot be excluded', False)
        sections.append(finish(current, len(lines)))
    return dict(sections=sections, preamble_lines=preamble,
                unknown=not sections, file_ends_with_newline=not text or text.endswith('\n'))


def same_path(a, b):
    try:
        return Path(a).resolve() == Path(b).resolve()
    except (OSError, ValueError):
        return False


def read_export_log(lines, path):
    success, failures, unparsed, foreign = [], [], [], []
    for number, line in enumerate(lines, 1):
        if '[MOVIE-TIMING]' not in line:
            continue
        match = SUCCESS.fullmatch(line)
        if match and same_path(match[6], path):
            try:
                success.append(dict(zip(('epoch', 'retained', 'dropped', 'invalid', 'saturated'), map(unsigned, match.groups()[:5])),
                                    line=number, text=line))
            except ValueError:
                unparsed.append(dict(line=number, text=line))
        elif ('[MOVIE-TIMING] export failed:' in line and ' path=' in line and
              same_path(line.rsplit(' path=', 1)[1], path)) or '[MOVIE-TIMING] unavailable:' in line:
            failures.append(dict(line=number, text=line, owner_identity='not-emitted'))
        elif match:
            foreign.append(dict(line=number, text=line))
        elif not match:
            unparsed.append(dict(line=number, text=line))
    return dict(success=success, failures_without_owner_identity=failures, unparsed=unparsed,
                other_path_success=foreign)


def associate_exports(sections, logs):
    candidates = []
    for section in sections:
        meta = section['metadata']
        candidates.append([index for index, receipt in enumerate(logs['success'])
            if (receipt['epoch'] == meta.get('epoch') and receipt['retained'] == section['declared_retained'] and
                receipt['dropped'] == meta.get('dropped_slow_events') and receipt['invalid'] == meta.get('invalid_intervals') and
                receipt['saturated'] == meta.get('aggregates_saturated'))])
    matched = set()
    for section, found in zip(sections, candidates):
        unique = len(found) == 1 and sum(found[0] in values for values in candidates) == 1
        section['export_success_candidate_log_lines'] = [logs['success'][i]['line'] for i in found]
        if unique:
            matched.add(found[0])
            section['export_status'] = ('success-reported' if section['integrity'] == 'complete' else
                                        'success-reported-but-section-partial-or-invalid')
        elif found:
            section['export_status'] = 'unknown-ambiguous-success-receipts'
        elif logs['failures_without_owner_identity']:
            # Even one retained section may coexist with a second owner whose
            # failed export left no section. Failure lines carry no owner ID.
            section['export_status'] = 'unknown-unattributed-export-failures'
        else:
            section['export_status'] = 'unknown-no-success-receipt'
        section['unattributed_failure_log_lines'] = [value['line'] for value in logs['failures_without_owner_identity']]
    logs['unmatched_success_log_lines'] = [value['line'] for i, value in enumerate(logs['success']) if i not in matched]


def correlate(sections, frames, minimum_gap_ns=50_000_000):
    presented = [row for row in frames if row['present_ns']]
    gaps = []
    for prior, following in zip(presented, presented[1:]):
        begin, end = prior['present_ns'], following['present_ns']
        if end - begin < minimum_gap_ns:
            continue
        gaps.append(dict(id=len(gaps) + 1, from_csv_line=prior['line'], to_csv_line=following['line'],
                         from_tick=prior['tick'], to_tick=following['tick'], begin_ns=begin, end_ns=end,
                         elapsed_ns=end - begin, between_begin_ns=prior['end_ns'],
                         between_end_ns=following['begin_ns'],
                         intervening_capture_rows=following['line'] - prior['line'] - 1))
    ends = [gap['end_ns'] for gap in gaps]
    overlaps = []
    for section in sections:
        for event in section['events']:
            start = bisect_right(ends, event['begin_ns'])
            for index in range(start, len(gaps)):
                gap = gaps[index]
                if gap['begin_ns'] >= event['end_ns']:
                    break
                amount = min(event['end_ns'], gap['end_ns']) - max(event['begin_ns'], gap['begin_ns'])
                if amount > 0:
                    between = max(0, min(event['end_ns'], gap['between_end_ns']) -
                                  max(event['begin_ns'], gap['between_begin_ns']))
                    overlaps.append(dict(section_id=section['id'], event_csv_line=event['line'],
                        boundary=event['boundary'], generation=event['generation'], serial=event['serial'],
                        event_begin_ns=event['begin_ns'], event_end_ns=event['end_ns'],
                        section_integrity=section['integrity'],
                        export_status=section.get('export_status', 'not-associated'),
                        gap_id=gap['id'], return_interval_overlap_ns=amount,
                        between_endpoint_spans_overlap_ns=between))
    return dict(minimum_gap_ns=minimum_gap_ns, gaps=gaps, overlaps=overlaps,
                overlapping_retained_events=len({(x['section_id'], x['event_csv_line']) for x in overlaps}),
                limitation='Overlaps are separate elapsed observations; nested events are not added or assigned causal responsibility.')


def private_path(session, configured):
    path = Path(configured)
    if not path.is_absolute():
        raise ValueError('Diagnostic output must be an absolute private-session path')
    resolved = path.resolve()
    if not resolved.is_relative_to(session):
        raise ValueError('Diagnostic output escaped private session')
    # Check lexical ancestors too; resolving first would hide a symlink/junction.
    for part in (path, *path.parents):
        if part.is_symlink() or (part.exists() and getattr(part.lstat(), 'st_file_attributes', 0) & 0x400):
            raise ValueError('Diagnostic output traverses a symlink/reparse point')
        if part == session:
            break
    if path.exists() and not path.is_file():
        raise ValueError('Diagnostic output is not a regular file')
    return resolved


def analyze(session, minimum_gap_ns=50_000_000):
    provenance = analyze_session(Path(session))  # rejects unfinished/unowned/wrong executable sessions
    session = Path(provenance['session'])
    manifest = json.loads((session / 'session.json').read_text(encoding='utf-8'))
    log = Path(manifest['players'][0]['logs']) / 'stderr.log'
    files = []
    def load(environment_key):
        configured = provenance['environment'].get(environment_key)
        if not configured:
            return dict(status='not-requested', sections=[], path=None), None
        path = private_path(session, configured)
        if not path.exists():
            return dict(status='missing-output', sections=[], path=str(path)), None
        data = path.read_bytes()
        files.append(dict(path=str(path.relative_to(session)), bytes=len(data),
                          sha256=hashlib.sha256(data).hexdigest()))
        return dict(status='available', path=str(path)), data
    work, work_bytes = load('REO_MOVIE_TIMING_FILE')
    logs = read_export_log(iter_log(log), work['path']) if work['path'] else dict(
        success=[], failures_without_owner_identity=[], unparsed=[], other_path_success=[])
    if work_bytes is not None:
        work.update(read_work(work_bytes.decode('utf-8', errors='replace')))
        if not work['sections']:
            work['status'] = 'unknown-no-owner-sections'
    associate_exports(work['sections'], logs)
    trace, frame_bytes = load('REO_FRAME_PACING_FILE')
    frames = []
    if frame_bytes is not None:
        try:
            dropped, frames = read_frames(io.StringIO(frame_bytes.decode('utf-8')))
            trace.update(frame_rows=len(frames), dropped_records=dropped)
        except (ValueError, UnicodeError) as error:
            trace.update(status='invalid-output', error=str(error))
    correlation = correlate(work['sections'], frames, minimum_gap_ns) if trace['status'] == 'available' else None
    return dict(schema=1, session=str(session), source_executable_sha256=provenance['source_executable_sha256'],
        process_identity=provenance['process_identity'], environment=provenance['environment'],
        exit_codes=provenance['exit_codes'], stop_reason=provenance['stop_reason'],
        evidence_sha256=provenance['evidence_sha256'], evidence_files=files,
        movie_work=work, exporter_log=logs, frame_trace=trace, correlation=correlation,
        limitations=['This report does not establish a slowdown root cause or a complete native player.',
            'CPU elapsed spans include descheduling and nested work; never add nested boundary totals or overlaps.',
            'Only retained >=threshold spans have details; aggregate-only, dropped, invalid, missing and uninstrumented work remains unknown.',
            'Trailer presence does not prove successful flush/close; stderr receipts can be ambiguous across owners with repeated epochs.',
            'Exporter failures omit owner identity; failure lines are preserved without inventing a section association.',
            'Frame timings are CPU backend/presentation-return observations, not unique movie pictures, physical scanout or game FPS.',
            'Sections may predate this process if a path was reused; unmatched/ambiguous receipts do not establish current-process ownership.',
            'The caller must provide a session-private output path; no concurrent writer or complete clock-generation join is proved.'])


def markdown(report):
    work, trace, correlation = report['movie_work'], report['frame_trace'], report['correlation']
    lines = ['# Private movie work evidence', '', 'Measured elapsed evidence; cause remains unknown.', '',
        f"Executable: `{report['source_executable_sha256']}`. Exit codes: `{report['exit_codes']}`.",
        f"Work output: {work['status']}. Frame trace: {trace['status']}.", '',
        '| Section / epoch | Integrity / export | Retained / dropped | Invalid / saturated |',
        '| --- | --- | ---: | ---: |']
    for section in work['sections']:
        meta = section['metadata']
        lines.append(f"| {section['id']} / {meta.get('epoch', 'unknown')} | {section['integrity']} / {section['export_status']} | {len(section['events'])} / {meta.get('dropped_slow_events', 'unknown')} | {meta.get('invalid_intervals', 'unknown')} / {meta.get('aggregates_saturated', 'unknown')} |")
    lines += ['', '| Section | Boundary | Calls | Maximum ms | Slow calls |', '| --- | --- | ---: | ---: | ---: |']
    for section in work['sections']:
        for boundary, aggregate in section['aggregates'].items():
            if aggregate['calls']:
                lines.append(f"| {section['id']} | {boundary} | {aggregate['calls']} | {aggregate['elapsed_max_ns']/1e6:.4f} | {aggregate['slow_calls']} |")
    lines += ['', ('Correlation unavailable; missing or invalid frame evidence.' if correlation is None else
        f"CPU return intervals >= {correlation['minimum_gap_ns']/1e6:g}ms: {len(correlation['gaps'])}; retained events overlapping them: {correlation['overlapping_retained_events']}."),
        'Overlapping nested spans remain separate observations and are not summed into responsibility.', '',
        'JSON preserves every section, validation issue, retained row, exporter log reference and exact overlap.', '',
        '| Evidence file | SHA-256 |', '| --- | --- |']
    for name, digest in report['evidence_sha256'].items():
        lines.append(f"| {name} | `{digest}` |")
    for file in report['evidence_files']:
        lines.append(f"| {file['path']} | `{file['sha256']}` |")
    lines += ['', '## Limits', ''] + ['- ' + value for value in report['limitations']]
    return '\n'.join(lines) + '\n'


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--session', required=True, type=Path)
    args = parser.parse_args()
    report = analyze(args.session)
    output = Path(report['session']) / 'movie-work-analysis.json'
    output.write_text(json.dumps(report, indent=2) + '\n', encoding='utf-8')
    output.with_suffix('.md').write_text(markdown(report), encoding='utf-8')
    print('Evidence summary: ' + str(output))


if __name__ == '__main__':
    main()
