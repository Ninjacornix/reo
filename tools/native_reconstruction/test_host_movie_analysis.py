"""Check attribution limits in the offline movie timing correlation."""
import tempfile
from pathlib import Path
import unittest

from analyze_host_movie_playtest import correlate_pipeline, read_trace


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

    def test_new_trace_preserves_fractional_clock_and_drop_count(self):
        with tempfile.TemporaryDirectory() as folder:
            path = Path(folder) / 'trace.csv'
            path.write_text('# dropped=7\nend_ns,position_seconds,state\n100,0.033366667,3\n')
            trace = read_trace(path)
            self.assertEqual(trace['retention'], '# dropped=7')
            self.assertEqual(trace['rows'][0]['line'], 3)
            self.assertAlmostEqual(trace['rows'][0]['position_seconds'], 0.033366667)
            self.assertIsNone(read_trace(Path(folder) / 'absent.csv'))


if __name__ == '__main__':
    unittest.main()
