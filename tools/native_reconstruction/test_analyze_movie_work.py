"""Synthetic offline evidence checks; none of these fixtures represents a game run."""
import hashlib
import io
import json
from pathlib import Path
import tempfile
import unittest

from analyze_movie_pacing import read_frames
from analyze_movie_work import (AGG_HEADER, BOUNDARIES, HEADER, HEADER2, UINT64, analyze,
                                associate_exports, correlate, markdown, private_path,
                                read_export_log, read_work)


def section(events=(), epoch=1, owner=10, dropped=0, overrides=None, complete=True, saturated=0):
    """Build schema1 test bytes from supplied synthetic elapsed events."""
    aggregates = {key: dict(calls=0, elapsed_sum_ns=0, elapsed_max_ns=0, slow_calls=0) for key in BOUNDARIES}
    for boundary, generation, serial, begin, end in events:
        value = aggregates[boundary]
        value['calls'] += 1
        value['slow_calls'] += 1
        value['elapsed_sum_ns'] += end - begin
        value['elapsed_max_ns'] = max(value['elapsed_max_ns'], end - begin)
    for key, values in (overrides or {}).items():
        aggregates[key].update(values)
    lines = ['# reo_movie_timing_schema=1', f'# owner_begin_ns={owner}', f'# epoch={epoch}',
             '# slow_threshold_ns=2000000', '# event_capacity=4096',
             '# elapsed_includes_descheduling=1', f'# dropped_slow_events={dropped}',
             '# invalid_intervals=0', f'# aggregates_saturated={saturated}', AGG_HEADER]
    lines += ['# aggregate,' + key + ',' + ','.join(str(value[k]) for k in
        ('calls', 'elapsed_sum_ns', 'elapsed_max_ns', 'slow_calls')) for key, value in aggregates.items()]
    lines.append(HEADER)
    lines += [','.join(map(str, (*event, event[-1] - event[-2]))) for event in events]
    if complete:
        lines.append(f'# owner_complete=1 retained={len(events)}')
    return '\n'.join(lines) + '\n'


def receipt(path, epoch=1, retained=0, dropped=0, invalid=0, saturated=0):
    return (f'[MOVIE-TIMING] exported owner epoch={epoch} retained={retained} '
            f'dropped={dropped} invalid={invalid} saturated={saturated} path={path}')


def section2(rows, seen, recent=2, longest=1, overrides=None, exact=1, saturated=0, complete=True):
    events=[tuple(row[2:]) for row in rows]
    text=section(events,overrides=overrides,saturated=saturated,complete=False)
    text=text.replace('# reo_movie_timing_schema=1','# reo_movie_timing_schema=2')
    text=text.replace('# event_capacity=4096',f'# event_capacity={recent+longest}')
    missing=seen-len(rows) if exact else UINT64
    text=text.replace('# dropped_slow_events=0',f'# dropped_slow_events={missing}')
    extra=(f'# recent_capacity={recent}\n# longest_capacity={longest}\n# slow_events_seen={seen}\n'
           f'# retained_recent={min(recent,seen)}\n# retained_longest={min(longest,seen)}\n'
           f'# retained_unique={len(rows)}\n# missing_count_exact={exact}\n# sequence_saturated={1-exact}\n')
    text=text.split(HEADER+'\n')[0].replace(AGG_HEADER,extra+AGG_HEADER)+HEADER2+'\n'
    text+=''.join(','.join(map(str,(*row,row[-1]-row[-2])))+'\n' for row in rows)
    if complete:text+=f'# owner_complete=1 retained={len(rows)}\n'
    return text


class MovieWorkTests(unittest.TestCase):
    def test_nested_spans_have_completion_order_not_begin_order(self):
        events = [('batch_fence', 4, 8, 100, 2000100), ('owner_control', 4, 0, 10, 3000010)]
        result = read_work(section(events))['sections'][0]
        self.assertEqual(result['integrity'], 'complete')
        self.assertEqual([x['begin_ns'] for x in result['events']], [100, 10])
        self.assertNotIn('total_work_ns', result)

    def test_reversed_completion_or_incorrect_duration_is_local_error(self):
        body = section([('decode', 1, 2, 10, 4000010), ('output', 1, 3, 10, 2000010)])
        first = read_work(body)['sections'][0]
        self.assertEqual(first['integrity'], 'invalid')
        self.assertEqual(len(first['events']), 1)
        body = section([('decode', 1, 2, 10, 2000010)]).replace(',2000000\n# owner_complete', ',1\n# owner_complete')
        self.assertEqual(read_work(body)['sections'][0]['integrity'], 'invalid')

    def test_partial_tail_and_later_reset_section_are_preserved(self):
        first = section([('decode', 1, 2, 10, 2000010)], complete=False) + 'decode,1,3,20,4'
        self.assertEqual(read_work(first)['sections'][0]['integrity'], 'partial')
        result = read_work(first + '\n' + section(epoch=2, owner=5))
        self.assertEqual(len(result['sections']), 2)
        self.assertEqual(len(result['sections'][0]['events']), 1)
        self.assertEqual(result['sections'][1]['integrity'], 'complete')
        self.assertEqual(result['sections'][1]['metadata']['owner_begin_ns'], 5)

    def test_missing_trailer_does_not_remove_valid_rows(self):
        result = read_work(section([('upload_fence', 3, 4, 10, 2000010)], complete=False))['sections'][0]
        self.assertEqual(result['integrity'], 'partial')
        self.assertEqual(len(result['events']), 1)

    def test_unknown_schema_and_garbage_do_not_consume_next_section(self):
        result = read_work('old-partial-bytes\n# reo_movie_timing_schema=3\ngarbage\n' + section())
        self.assertEqual(result['preamble_lines'], [1])
        self.assertEqual(result['sections'][0]['integrity'], 'invalid')
        self.assertEqual(result['sections'][1]['integrity'], 'complete')

    def test_rejects_corrupt_enums_uints_metadata_and_counts(self):
        good = section([('decode', 1, 2, 10, 2000010)])
        variants = [good.replace('decode,1,2,10', 'mystery,1,2,10'),
                    good.replace('# epoch=1', '# epoch=-1'),
                    good.replace('# epoch=1', '# epoch=' + str(UINT64 + 1)),
                    good.replace('# epoch=1', '# epoch=1\n# epoch=1'),
                    good.replace('# event_capacity=4096', '# event_capacity=4097'),
                    good.replace('# owner_complete=1 retained=1', '# owner_complete=1 retained=2'),
                    good.replace('# aggregate,decode,1,2000000,2000000,1', '# aggregate,decode,0,0,0,0'),
                    good.replace('# dropped_slow_events=0', '# dropped_slow_events=1')]
        for value in variants:
            with self.subTest(value=value):
                self.assertEqual(read_work(value)['sections'][0]['integrity'], 'invalid')

    def test_loss_and_saturation_remain_explicit(self):
        body = section([('decode', 1, 2, 10, 2000010)], dropped=1,
                       overrides={'decode': dict(calls=2, elapsed_sum_ns=4000000, slow_calls=2)})
        self.assertEqual(read_work(body)['sections'][0]['integrity'], 'complete')
        saturated = section(saturated=1, dropped=UINT64,
                            overrides={'decode': dict(calls=UINT64, elapsed_sum_ns=UINT64,
                                                     elapsed_max_ns=UINT64, slow_calls=UINT64)})
        self.assertEqual(read_work(saturated)['sections'][0]['integrity'], 'complete')

    def test_trailer_alone_is_not_export_success(self):
        sections = read_work(section())['sections']
        logs = read_export_log([], Path('synthetic.csv').resolve())
        associate_exports(sections, logs)
        self.assertEqual(sections[0]['export_status'], 'unknown-no-success-receipt')

    def test_export_success_matches_path_epoch_and_counts(self):
        path = Path('synthetic.csv').resolve()
        sections = read_work(section(epoch=7))['sections']
        logs = read_export_log([receipt(path, epoch=7), receipt(path.with_name('other.csv'), epoch=7)], path)
        associate_exports(sections, logs)
        self.assertEqual(sections[0]['export_status'], 'success-reported')
        self.assertEqual(sections[0]['export_success_candidate_log_lines'], [1])
        self.assertEqual(len(logs['other_path_success']), 1)

    def test_repeated_epochs_preserve_ambiguous_success_and_failures(self):
        path = Path('synthetic.csv').resolve()
        sections = read_work(section(epoch=7) + section(epoch=7, owner=100))['sections']
        logs = read_export_log([receipt(path, epoch=7),
            '[MOVIE-TIMING] export failed: write/flush/close; partial output possible path=' + str(path)], path)
        associate_exports(sections, logs)
        self.assertTrue(all(x['export_status'] == 'unknown-ambiguous-success-receipts' for x in sections))
        self.assertTrue(all(x['unattributed_failure_log_lines'] == [2] for x in sections))
        self.assertEqual(logs['unmatched_success_log_lines'], [1])

    def test_failed_export_cannot_be_hidden_by_complete_trailer(self):
        path = Path('synthetic.csv').resolve()
        sections = read_work(section())['sections']
        logs = read_export_log(['[MOVIE-TIMING] export failed: write/flush/close; partial output possible path=' + str(path)], path)
        associate_exports(sections, logs)
        self.assertEqual(sections[0]['export_status'], 'unknown-unattributed-export-failures')

    def test_complete_footer_without_final_newline_is_still_partial(self):
        result = read_work(section().rstrip('\n'))
        self.assertFalse(result['file_ends_with_newline'])
        self.assertEqual(result['sections'][0]['declared_retained'], 0)
        self.assertEqual(result['sections'][0]['integrity'], 'partial')

    def test_exact_overlap_keeps_nested_spans_separate(self):
        sections = read_work(section([('batch_fence', 4, 8, 20, 60000020),
                                      ('owner_control', 4, 0, 15, 70000015)]))['sections']
        _, frames = read_frames(io.StringIO('# dropped=0\ntick,begin_ns,scanout_ns,present_ns,end_ns\n'
                                '1,10,11,12,13\n2,100000010,100000011,100000012,100000013\n'))
        result = correlate(sections, frames)
        self.assertEqual(result['overlapping_retained_events'], 2)
        self.assertEqual([x['return_interval_overlap_ns'] for x in result['overlaps']], [60000000, 70000000])
        self.assertEqual([x['between_endpoint_spans_overlap_ns'] for x in result['overlaps']], [60000000, 70000000])
        self.assertNotIn('total_attributed_ns', result)
        self.assertEqual(result['overlaps'][0]['generation'], 4)
        self.assertEqual(result['overlaps'][0]['serial'], 8)

    def test_touching_endpoints_and_absent_presentation_do_not_invent_overlap(self):
        sections = read_work(section([('decode', 1, 2, 10, 2000010)]))['sections']
        _, frames = read_frames(io.StringIO('# dropped=0\ntick,begin_ns,scanout_ns,present_ns,end_ns\n'
            '1,2000008,2000009,2000010,2000011\n2,3000000,0,0,3000010\n'
            '3,100000010,100000011,100000012,100000013\n'))
        result = correlate(sections, frames)
        self.assertEqual(result['overlaps'], [])
        self.assertEqual(result['gaps'][0]['intervening_capture_rows'], 1)


class RollingMovieWorkTests(unittest.TestCase):
    def example(self, complete=True):
        rows=[(1,'longest','batch_fence',4,1,50_000_000,100_000_000),
              (3,'recent','batch_fence',4,3,298_000_000,300_000_000),
              (4,'recent','batch_fence',4,4,393_000_000,400_000_000)]
        return section2(rows,4,overrides={'batch_fence':dict(calls=4,slow_calls=4,elapsed_sum_ns=61_000_000)},complete=complete)

    def test_old_long_spike_and_recent_history_union_have_exact_missing_count(self):
        item=read_work(self.example())['sections'][0]
        self.assertEqual(item['integrity'],'complete')
        self.assertEqual([event['sequence'] for event in item['events']],[1,3,4])
        self.assertEqual(item['retention_summary']['recorder_missing_slow_events'],1)
        self.assertEqual(item['metadata']['retained_recent'],2)
        self.assertEqual(item['metadata']['retained_longest'],1)
        self.assertEqual(item['metadata']['retained_unique'],3)

    def test_recent_top_duplicate_is_corruption_and_does_not_duplicate_evidence(self):
        text=self.example().replace('# owner_complete',
            '4,longest,batch_fence,4,4,393000000,400000000,7000000\n# owner_complete')
        item=read_work(text)['sections'][0]
        self.assertEqual(item['integrity'],'invalid')
        self.assertEqual(len(item['events']),3)
        self.assertTrue(any('Duplicate' in issue['message'] for issue in item['issues']))

    def test_mixed_schema_partial_and_later_owner_are_not_lost(self):
        text=section()+self.example(complete=False)+'5,recent,batch_fence,4'+ '\n'+section(epoch=9)
        result=read_work(text)['sections']
        self.assertEqual([item['schema'] for item in result],[1,2,1])
        self.assertEqual(result[2]['integrity'],'complete')
        self.assertEqual(len(result[1]['events']),3)
        self.assertTrue(any(issue['message']=='Missing owner completion trailer' for issue in result[1]['issues']))

    def test_rejects_corrupt_retention_flags_counters_sequence_and_top_rank(self):
        good=self.example()
        changes=[('1,longest','1,recent'),('4,recent','2,recent'),
                 ('# retained_unique=3','# retained_unique=2'),
                 ('# retained_recent=2','# retained_recent=3'),
                 ('# dropped_slow_events=1','# dropped_slow_events=0'),
                 ('# longest_capacity=1','# longest_capacity=65'),
                 ('# sequence_saturated=0','# sequence_saturated=1'),
                 ('1,longest,batch_fence,4,1,50000000,100000000,50000000',
                  '1,longest,batch_fence,4,1,98000000,100000000,2000000')]
        for before,after in changes:
            with self.subTest(after=after):
                self.assertEqual(read_work(good.replace(before,after))['sections'][0]['integrity'],'invalid')

    def test_counter_exhaustion_preserves_records_but_marks_missing_unknown(self):
        rows=[(1,'longest','batch_fence',4,1,50_000_000,100_000_000),
              (UINT64-1,'recent','batch_fence',4,2,298_000_000,300_000_000),
              (UINT64,'recent','batch_fence',4,3,393_000_000,400_000_000)]
        text=section2(rows,UINT64,exact=0,saturated=1,
            overrides={'batch_fence':dict(calls=UINT64,slow_calls=UINT64,elapsed_sum_ns=UINT64)})
        item=read_work(text)['sections'][0]
        self.assertEqual(item['integrity'],'complete')
        self.assertFalse(item['retention_summary']['missing_count_exact'])
        self.assertIsNone(item['retention_summary']['recorder_missing_slow_events'])
        self.assertEqual(len(item['events']),3)

    def test_sum_saturation_does_not_discard_exact_missing_counter(self):
        item=read_work(self.example().replace('# aggregates_saturated=0','# aggregates_saturated=1'))['sections'][0]
        self.assertEqual(item['integrity'],'complete')
        self.assertTrue(item['retention_summary']['missing_count_exact'])
        self.assertEqual(item['retention_summary']['recorder_missing_slow_events'],1)

    def test_nested_union_row_is_correlated_once_with_retention_identity(self):
        rows=[(1,'recent','batch_fence',4,8,50_000_000,100_000_000),
              (2,'recent+longest','owner_control',4,0,50_000_000,110_000_000)]
        sections=read_work(section2(rows,2))['sections']
        self.assertEqual(sections[0]['integrity'],'complete')
        _,frames=read_frames(io.StringIO('# dropped=0\ntick,begin_ns,scanout_ns,present_ns,end_ns\n'
            '1,10,11,12,13\n2,200000000,200000001,200000002,200000003\n'))
        result=correlate(sections,frames)
        self.assertEqual(result['overlapping_retained_events'],2)
        self.assertEqual([x['event_sequence'] for x in result['overlaps']],[1,2])
        self.assertEqual(result['overlaps'][1]['retention'],'recent+longest')
        self.assertNotIn('total_attributed_ns',result)

    def test_untrusted_huge_recent_counter_never_allocates_declared_range(self):
        text=self.example().replace('# retained_recent=2',f'# retained_recent={UINT64}')
        self.assertEqual(read_work(text)['sections'][0]['integrity'],'invalid')


class PrivateSessionTests(unittest.TestCase):
    def setUp(self):
        root = Path(__file__).resolve().parents[2] / 'build-native-sjuni'
        root.mkdir(exist_ok=True)
        self.temporary = tempfile.TemporaryDirectory(prefix='synthetic-movie-work-test-', dir=root)
        self.session = Path(self.temporary.name).resolve()
        self.assertTrue(self.session.is_relative_to(root.resolve()))
        self.addCleanup(self.temporary.cleanup)
        image = self.session / 'fixture-not-an-executable.bin'
        image.write_bytes(b'synthetic provenance test; never executed')
        logs = self.session / 'logs'
        logs.mkdir()
        (logs / 'stderr.log').write_text('', encoding='utf-8')
        self.work = self.session / 'work.csv'
        self.frames = self.session / 'frames.csv'
        manifest = dict(owner='reo-coop-playtest', session=str(self.session),
                        sourceSha256=hashlib.sha256(image.read_bytes()).hexdigest(),
                        players=[dict(image=str(image), logs=str(logs))])
        self.run = dict(finishedUtc='2000-01-01T00:00:00Z', elapsedSeconds=0, exitCodes=[0], nativeResults=[],
            players=[dict(pid=1, image=str(image), creationFileTime=1, environment={
                'REO_MOVIE_TIMING_FILE': str(self.work), 'REO_FRAME_PACING_FILE': str(self.frames)})])
        (self.session / 'session.json').write_text(json.dumps(manifest))
        self.save_run()

    def save_run(self):
        (self.session / 'run.json').write_text(json.dumps(self.run))

    def test_missing_outputs_are_unknown_not_no_stutters(self):
        result = analyze(self.session)
        self.assertEqual(result['movie_work']['status'], 'missing-output')
        self.assertEqual(result['frame_trace']['status'], 'missing-output')
        self.assertIsNone(result['correlation'])
        self.assertIn('cause remains unknown', markdown(result))

    def test_completed_provenance_and_exact_file_hashes(self):
        self.work.write_text(section(), encoding='utf-8')
        self.frames.write_text('# dropped=2\ntick,begin_ns,scanout_ns,present_ns,end_ns\n1,10,11,12,13\n')
        (self.session / 'logs/stderr.log').write_text(receipt(self.work) + '\n')
        result = analyze(self.session)
        self.assertEqual(result['movie_work']['sections'][0]['export_status'], 'success-reported')
        self.assertEqual(result['frame_trace']['dropped_records'], 2)
        hashes = {value['path']: value['sha256'] for value in result['evidence_files']}
        self.assertEqual(hashes['work.csv'], hashlib.sha256(self.work.read_bytes()).hexdigest())
        self.run.pop('finishedUtc')
        self.save_run()
        with self.assertRaises(ValueError):
            analyze(self.session)

    def test_escape_and_relative_path_rejected_before_reading(self):
        with self.assertRaises(ValueError):
            private_path(self.session, 'relative.csv')
        self.run['players'][0]['environment']['REO_MOVIE_TIMING_FILE'] = str(self.session.parent / 'outside.csv')
        self.save_run()
        with self.assertRaises(ValueError):
            analyze(self.session)

    def test_invalid_frame_trace_does_not_discard_work_sections(self):
        self.work.write_text(section(), encoding='utf-8')
        self.frames.write_text('truncated-header')
        result = analyze(self.session)
        self.assertEqual(result['frame_trace']['status'], 'invalid-output')
        self.assertEqual(result['movie_work']['sections'][0]['integrity'], 'complete')
        self.assertIsNone(result['correlation'])


if __name__ == '__main__':
    unittest.main()
