"""Small original-word phase/window contracts, not an ADX codec test."""
import unittest
from adx_phase_oracle import Machine,CONTEXT,DECODER,INPUT,LEFT,RIGHT,generate
from sjuni_oracle import OracleError,StepLimit


class AdxPhaseTests(unittest.TestCase):
    def test_idle_configuration_and_nonidle_refusal(self):
        for phase in range(4):
            for op in ('mono','stereo'):
                m=Machine(phase=phase);before=m.snapshot()
                args=[CONTEXT,INPUT,3,LEFT]+([RIGHT] if op=='stereo' else [])
                r=m.run(op,args);words=r['state']['context_words_u32']
                self.assertEqual(r['return_u32'],1 if phase==0 else 0)
                if phase==0:
                    self.assertEqual(words[5:10],[1 if op=='mono' else 2,INPUT,3,LEFT,0 if op=='mono' else RIGHT])
                else:self.assertEqual(r['state'],before)

    def test_request_always_returns_one_but_nonidle_does_not_accept(self):
        for phase in range(4):
            m=Machine(phase=phase)
            r=m.run('request',[CONTEXT]);words=r['state']['context_words_u32']
            self.assertEqual(r['return_u32'],1)
            self.assertEqual(words[3],1 if phase==0 else phase)
            self.assertEqual(words[4],0 if phase==0 else 0x89ABCDEF)

    def test_cancel_only_resets_phase_and_eight_history_bytes(self):
        m=Machine(phase=2);before=m.snapshot()
        r=m.run('cancel',[CONTEXT]);expected=before['context_words_u32'].copy()
        expected[3]=0;expected[10]=expected[11]=0
        self.assertEqual(r['state']['context_words_u32'],expected)
        self.assertEqual(r['state']['payload_probe_u32'],before['payload_probe_u32'])
        self.assertEqual(len(r['events']),1)
        self.assertFalse(r['return_is_defined'])

    def test_acknowledge_only_phase_three_and_completed_counter_retained(self):
        for phase in range(4):
            m=Machine(phase=phase)
            self.assertEqual(m.run('acknowledge',[CONTEXT])['state']['context_words_u32'][3],0 if phase==3 else phase)
            self.assertEqual(m.run('completed',[CONTEXT])['return_u32'],0x89ABCDEF)

    def test_output_window_units_and_stereo_count_doubling(self):
        for op in ('mono_window','stereo_window'):
            m=Machine();r=m.run(op,[DECODER,3]);w=r['state']['context_words_u32']
            self.assertEqual(r['return_u32'],1)
            self.assertEqual(w[3:10],[1,0,1 if op=='mono_window' else 2,INPUT,
                3 if op=='mono_window' else 6,LEFT+14,0 if op=='mono_window' else LEFT+14+256])
        m=Machine();m.mem.store(DECODER+0x68,4,0x7FFFFFFF)
        w=m.run('stereo_window',[DECODER,0x7FFFFFFF])['state']['context_words_u32']
        self.assertEqual((w[7],w[8],w[9]),(0xFFFFFFFE,LEFT-2,LEFT-2+256))

    def test_rejection_and_deterministic_fixture(self):
        with self.assertRaises(OracleError):Machine(phase=7)
        with self.assertRaises(OracleError):Machine().run('not_adx',[])
        with self.assertRaises(StepLimit):Machine().run('cancel',[CONTEXT],step_cap=1)
        fixture=generate();self.assertEqual(fixture,generate())
        self.assertEqual((fixture['counts']['cases'],fixture['counts']['operations']),(16,96))


if __name__=='__main__':unittest.main()
