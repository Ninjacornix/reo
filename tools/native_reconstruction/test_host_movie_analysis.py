"""Check attribution limits in the offline movie timing correlation."""
import tempfile
from pathlib import Path
import unittest

from analyze_host_movie_playtest import classify_incident, correlate_pipeline, producer_epochs, read_trace


def publication(time, generation=1, clip=0):
    return dict(publish_end_ns=time, end_ns=time, wake_begin_ns=time-1,
                generation=generation, clip=clip)


class TimingCorrelationTests(unittest.TestCase):
    def test_empty_requests_and_source_publication_gap(self):
        incident = dict(begin_ns=100_000_000, end_ns=300_000_000)
        producer = dict(file='producer.csv', retention='# dropped=0', rows=[
            publication(90_000_000), publication(290_000_000)])
        consumer = dict(file='consumer.csv', retention='# dropped=0', rows=[
            dict(begin_ns=n, borrowed_ns=n+100, available=int(n == 300_000_000), line=i)
            for i, n in enumerate(range(100_000_000, 300_000_001, 50_000_000), 3)])
        result = correlate_pipeline(incident, producer, consumer)
        self.assertEqual(result['consumer']['requests'], 5)
        self.assertEqual(result['consumer']['fresh_frames'], 1)
        self.assertEqual(result['consumer']['max_request_gap_ms'], 50)
        self.assertEqual(result['producer']['publication_gap_ms'], 200)
        self.assertFalse(result['producer']['periodic_heartbeat_available'])

    def test_new_source_does_not_become_same_source_freeze(self):
        for new in [publication(300, generation=2), publication(300, clip=1)]:
            result = correlate_pipeline(dict(begin_ns=100, end_ns=400),
                dict(file='p.csv', retention='# dropped=0', rows=[publication(90), new]), None)
            self.assertIsNone(result['producer']['publication_gap_ms'])
            self.assertFalse(result['producer']['same_source'])

    def test_missing_pipeline_evidence_stays_missing(self):
        self.assertEqual(correlate_pipeline(dict(begin_ns=0, end_ns=100), None, None), {})

    def test_heartbeat_measures_empty_polls_and_unobserved_interval(self):
        rows = [publication(90_000_000), publication(140_000_000), publication(300_000_000)]
        for i, row in enumerate(rows):
            row.update(position_seconds=i*0.05, events=10+i, updated=int(i != 1))
        rows[1]['publish_end_ns'] = 0
        result = correlate_pipeline(dict(begin_ns=100_000_000, end_ns=310_000_000),
            dict(file='p.csv', retention='# dropped=0', rows=rows), None)['producer']
        self.assertTrue(result['periodic_heartbeat_available'])
        self.assertEqual(result['empty_poll_observations'], 1)
        self.assertAlmostEqual(result['max_unobserved_interval_ms'], 159.999999)
        self.assertAlmostEqual(result['native_clock_advance_seconds'], 0.1)
        self.assertEqual(result['native_event_count_change'], 2)

    def test_new_trace_preserves_fractional_clock_and_drop_count(self):
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'trace.csv'
            path.write_text('# dropped=7\nend_ns,position_seconds,state\n100,0.033366667,3\n')
            trace = read_trace(path)
            self.assertEqual(trace['retention'], '# dropped=7')
            self.assertEqual(trace['rows'][0]['line'], 3)
            self.assertAlmostEqual(trace['rows'][0]['position_seconds'], 0.033366667)
            self.assertIsNone(read_trace(Path(folder) / 'absent.csv'))

    def test_observer_stall_is_not_misreported_as_movie_freeze(self):
        consumer = dict(requests=7, fresh_frames=7, retention='# dropped=0',
            max_request_gap_ms=34, first_request_offset_ms=20, last_request_offset_ms=12)
        incident = dict(observer_max_gap_ms=211, pipeline=dict(consumer=consumer))
        self.assertIn('pipeline freeze not established', classify_incident(incident))
        for key, value in [('fresh_frames', 6), ('retention', '# dropped=1'),
                           ('first_request_offset_ms', 60), ('max_request_gap_ms', 70)]:
            changed = dict(consumer, **{key:value})
            self.assertEqual(classify_incident(dict(incident, pipeline=dict(consumer=changed))),
                'measured public-frame observation gap; cause unknown')

    def test_publication_gaps_do_not_span_different_clips_or_loop_wraps(self):
        rows = [publication(100), publication(200), publication(900, clip=1),
                publication(1000, clip=1)]
        for i, row in enumerate(rows):
            row.update(ordinal=i % 2, line=i+3, backpressure=0)
        # A single-clip repeat starts another epoch even with the same identity.
        row = dict(rows[-1], publish_end_ns=2000, ordinal=0, line=7)
        rows.append(row)
        epochs = producer_epochs(dict(rows=rows))
        self.assertEqual([r['publications'] for r in epochs], [2, 2, 1])
        self.assertIsNone(epochs[-1]['max_publication_gap_ms'])
        self.assertEqual(producer_epochs(None), [])


if __name__ == '__main__':
    unittest.main()
