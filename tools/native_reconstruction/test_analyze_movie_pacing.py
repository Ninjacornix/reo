import io
import unittest

from analyze_movie_pacing import read_frames, summarize, audio_evidence, native_audio_evidence, complete_audio_evidence
from analyze_pcm_playtest import parse as parse_pcm
from test_analyze_pcm_playtest import INSTALL, REPORT


class MoviePacingTests(unittest.TestCase):
    def test_complete_backend_underruns_survive_absent_legacy_pcm_reports(self):
        environment = {'REO_NATIVE_AUDIO': '1', 'REO_NATIVE_PCM': '0'}
        installed = '[NATIVE-AUDIO] complete PCM/bank/RAM candidate installed pcm_bytes=391680000'
        final = '[NATIVE-AUDIO-REPORT] owner_joined=1 output_started=1 frames=48000 signal_frames=40000 underrun_frames=18208 hard_failures=0 queue_rejections=0'
        report = dict(environment=environment, audio_starvation_window_count=0,
                      native_pcm=parse_pcm([], environment),
                      native_complete_audio=complete_audio_evidence([installed, final], environment))
        self.assertIn('18208 starved output frames / 48000 output frames', audio_evidence(report))
        self.assertIn('cannot be aligned', audio_evidence(report))
        for logs in ([installed], [installed, final.replace('owner_joined=1', 'owner_joined=0')]):
            report['native_complete_audio'] = complete_audio_evidence(logs, environment)
            self.assertIn('unknown', audio_evidence(report))
            self.assertIn('do not mean zero', audio_evidence(report))
        report['native_complete_audio'] = complete_audio_evidence([installed, final.replace('frames=48000', 'frames=1')], environment)
        self.assertIn('counters unknown', audio_evidence(report))
        _, frames = self.parse('1,100,101,102,103\n2,80000100,80000101,80000102,80000103\n')
        self.assertEqual(summarize(frames, [])['presentation_return_intervals']['over_50_ms'], 1)

    def test_invalid_audio_does_not_invalidate_other_timing_evidence(self):
        environment = {'REO_NATIVE_PCM': '1'}
        native = native_audio_evidence([INSTALL, REPORT.replace('signal_frames=40000',
                                        'signal_frames=48001')], environment)
        self.assertEqual(native['status'], 'invalid-evidence')
        self.assertEqual(native['joined_reports'], [])
        self.assertIn('counters unknown', audio_evidence(dict(environment=environment, native_pcm=native)))
        _, frames = self.parse('1,100,101,102,103\n2,80000100,80000101,80000102,80000103\n')
        self.assertEqual(summarize(frames, [])['presentation_return_intervals']['over_50_ms'], 1)

    def test_native_final_starvation_is_not_hidden_by_absent_legacy_windows(self):
        environment = {'REO_NATIVE_PCM': '1'}
        report = dict(environment=environment, audio_starvation_window_count=0,
                      native_pcm=parse_pcm([INSTALL, REPORT], environment))
        self.assertIn('3 starved output frames / 48000 output frames', audio_evidence(report))
        self.assertIn('cannot be aligned', audio_evidence(report))
        report['native_pcm'] = parse_pcm([INSTALL], environment)
        self.assertIn('unknown', audio_evidence(report))
        self.assertIn('do not mean zero', audio_evidence(report))

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
