import unittest
from analyze_audio_candidate import parse

INSTALL='[NATIVE-AUDIO] complete PCM/bank/RAM candidate installed pcm_bytes=391680000'
REPORT='[NATIVE-AUDIO-REPORT] owner_joined=1 output_started=1 frames=100 signal_frames=90 underrun_frames=0 hard_failures=0 queue_rejections=0'
RAM='[NATIVE-SOUND-RAM-REPORT] retired=1 active_slots=0 active_operations=0 diagnostic_reports=3 first_refusal_or_diagnostic=65540 attempts=2,2,1,0,0,1,1,1,0,4,1 refused=0,0,0,0,0,0,1,0,0,0,0 order=begin,end,read,control,forward,snapshot,log,packet,bank,pcm,retire'
ENV={'REO_NATIVE_AUDIO':'1','REO_NATIVE_PCM':'0'}


class AudioCandidateParserTests(unittest.TestCase):
    def test_positive_proof_keeps_diagnostics_and_optional_log_refusal(self):
        r=parse([INSTALL,REPORT,RAM],ENV)
        self.assertEqual(r['status'],'retired')
        self.assertEqual(r['ram_reports'][0]['diagnostic_reports'],3)
        self.assertEqual(r['ram_reports'][0]['first_refusal_or_diagnostic'],65540)
        self.assertEqual(r['ram_reports'][0]['operations']['log']['refused'],1)

    def test_setting_alone_is_no_selection(self):
        self.assertEqual(parse([],ENV)['status'],'requested-without-selection-proof')
        self.assertEqual(parse(['[NATIVE-AUDIO-ERROR] installation=4'],ENV)['status'],'unavailable')

    def test_installed_is_not_retired(self):
        self.assertEqual(parse([INSTALL],ENV)['status'],'installed-without-complete-retirement-proof')
        self.assertEqual(parse([INSTALL,REPORT],ENV)['status'],'installed-without-complete-retirement-proof')
        self.assertEqual(parse([INSTALL,REPORT,RAM.replace('active_slots=0','active_slots=1')],ENV)['status'],'incomplete-retirement')

    def test_faults_and_underruns_are_not_suppressed(self):
        r=parse([INSTALL,REPORT.replace('underrun_frames=0','underrun_frames=7').replace('hard_failures=0','hard_failures=1'),RAM],ENV)
        self.assertEqual(r['status'],'retired-with-audio-faults')
        self.assertEqual(r['audio_reports'][0]['underrun_frames'],7)

    def test_malformed_counters_and_duplicate_proof_refuse(self):
        for lines in([INSTALL,INSTALL],[INSTALL,REPORT,REPORT],[INSTALL,RAM,RAM],[INSTALL,RAM.replace('retire','future')],
            [INSTALL,RAM.replace('refused=0,0,0','refused=0,0,2')],[INSTALL,REPORT.replace('signal_frames=90','signal_frames=101')]):
            with self.subTest(lines=lines),self.assertRaises(ValueError):parse(lines,ENV)

    def test_environment_and_install_identity_are_required(self):
        for lines,env in([INSTALL],{}),([REPORT],ENV),([RAM],ENV),([],dict(ENV,REO_NATIVE_PCM='1')):
            with self.assertRaises(ValueError):parse(lines,env)
        self.assertEqual(parse([],{})['status'],'not-requested')


if __name__=='__main__':unittest.main()
