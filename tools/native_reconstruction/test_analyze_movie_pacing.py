import io
import unittest

from analyze_movie_pacing import read_frames, summarize


class MoviePacingTests(unittest.TestCase):
    def parse(self, body):
        return read_frames(io.StringIO('# dropped=7\ntick,begin_ns,scanout_ns,present_ns,end_ns\n'+body))

    def test_brief_hitch_survives_quiet_surrounding_frames(self):
        body = ''.join(f'{i},{t},{t+1},{t+2},{t+3}\n' for i,t in enumerate((100,16666800,33333500,113333500,130000200)))
        dropped, rows = self.parse(body)
        report = summarize(rows,[])
        self.assertEqual(dropped,7)
        self.assertEqual(report['presentation_return_intervals']['over_50_ms'],1)
        self.assertEqual(report['presentation_return_intervals']['max_ms'],80)
        self.assertEqual(report['sampled_movie_return_intervals'],{'count':0})

    def test_skipped_presentation_is_not_a_zero_duration_frame(self):
        _, rows = self.parse('1,10,11,12,13\n2,14,0,0,15\n3,80,81,82,83\n')
        report = summarize(rows,[])
        self.assertEqual(report['frame_rows'],3)
        self.assertEqual(report['presented_rows'],2)
        self.assertEqual(report['presentation_return_intervals']['count'],1)
        self.assertEqual(report['stages']['vsync_to_present_return']['count'],2)

    def test_does_not_bridge_movie_reset_or_missing_samples(self):
        _, rows = self.parse('1,100,101,102,103\n2,200,201,202,203\n')
        a=dict(ns=50,time_num=10,time_den=60,decoded_num=5,decoded_den=30)
        b=dict(a,ns=250,time_num=20,decoded_num=10)
        self.assertEqual(summarize(rows,[a,b])['sampled_movie_return_intervals']['count'],1)
        for changed in (dict(b,time_num=1),dict(b,ns=3_000_000_000),dict(b,decoded_den=60)):
            self.assertEqual(summarize(rows,[a,changed])['sampled_movie_return_intervals']['count'],0)

    def test_rejects_corruption_and_overlapping_spans(self):
        for body in ('1,10,11,12,9\n','1,10,0,12,13\n',
                     '1,10,11,12,13\n2,12,14,15,16\n','1,10,11,12,13,14\n',
                     '1,10,11,12,\n'):
            with self.subTest(body=body),self.assertRaises(ValueError):
                self.parse(body)


if __name__ == '__main__':
    unittest.main()
