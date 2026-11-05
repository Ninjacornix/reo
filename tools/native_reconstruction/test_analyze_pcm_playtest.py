import unittest
from analyze_pcm_playtest import METHODS,parse

INSTALL='[NATIVE-PCM] candidate installed channels=2040 voices=2041 pcm_bytes=391680000 metadata_bytes=4194304'
REPORT=('[NATIVE-PCM-REPORT] output_owner_joined=1 host_output_started=1 stream_fence_joined=1 '
    'frames=48000 signal_frames=40000 underrun_frames=3 device_callback_attempts=100 '
    'device_frame_requests=48000 device_callbacks_completed=99 hard_failures=0 queue_rejections=2 '
    'stop_requests=2 join_attempts_at_report=1 self_join_refusals=0 method_order='+','.join(METHODS)+
    ' method_attempts='+','.join(['5']*11)+' method_completed='+','.join(['4']*11))


class NativePcmReportTests(unittest.TestCase):
    def test_counts_actual_native_output_separately_from_attempts(self):
        result=parse([INSTALL,REPORT],{'REO_NATIVE_PCM':'1'})
        self.assertEqual(result['status'],'joined')
        report=result['joined_reports'][0]
        self.assertEqual(report['underrun_frames'],3)
        self.assertEqual(report['method_attempts']['render'],5)
        self.assertEqual(report['method_completed']['render'],4)

    def test_requested_or_installed_without_teardown_remains_unknown(self):
        self.assertEqual(parse([],{'REO_NATIVE_PCM':'1'})['status'],'requested-without-selection-proof')
        self.assertEqual(parse([INSTALL],{'REO_NATIVE_PCM':'1'})['status'],'installed-without-join-proof')
        self.assertEqual(parse([], {})['status'],'not-requested')

    def test_explicit_fault_survives_successful_join(self):
        result=parse([INSTALL,'[NATIVE-PCM-ERROR] fault=1',REPORT],{'REO_NATIVE_PCM':'1'})
        self.assertEqual(result['status'],'joined-with-faults')

    def test_refuses_inconsistent_or_misidentified_reports(self):
        for lines,env in [([INSTALL,REPORT],{}),([REPORT],{'REO_NATIVE_PCM':'1'}),
            ([INSTALL,REPORT.replace('signal_frames=40000','signal_frames=48001')],{'REO_NATIVE_PCM':'1'}),
            ([INSTALL,REPORT.replace('method_completed=4','method_completed=6')],{'REO_NATIVE_PCM':'1'}),
            ([INSTALL,REPORT.replace('method_order=ensure_output','method_order=wrong')],{'REO_NATIVE_PCM':'1'}),
            ([INSTALL,REPORT,REPORT],{'REO_NATIVE_PCM':'1'}),
            ([INSTALL.replace('channels=2040','channels=64')],{'REO_NATIVE_PCM':'1'})]:
            with self.subTest(lines=lines),self.assertRaises(ValueError):
                parse(lines,env)


if __name__=='__main__':unittest.main()
