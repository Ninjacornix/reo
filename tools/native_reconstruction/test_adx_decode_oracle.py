"""Independent simple-case/invariant tests of the complete original-word run."""
import hashlib
from pathlib import Path
import struct
import unittest

from adx_decode_oracle import Machine,block,generate,ENTRY,END,INPUT,OUTPUT
from sjuni_oracle import OracleError,StepLimit


class DecodeTests(unittest.TestCase):
    def machine(self,encoded=None,count=1,**overrides):
        params=dict(history=(0,0),coefficients=(0,0),key=0,multiplier=1,addend=0)
        params.update(overrides)
        return Machine(block(0,bytes(16)) if encoded is None else encoded,count,**params)

    def test_all256_nibble_pairs_high_then_low_without_predictor(self):
        for high in range(16):
            encoded=block(0,bytes(high<<4|low for low in range(16)))
            result=self.machine(encoded).run();expected=[]
            for low in range(16):expected.extend([high if high<8 else high-16,low if low<8 else low-16])
            self.assertEqual(result['state']['pcm_i16'],expected)
            self.assertEqual(result['state']['history_i16'],expected[-1:-3:-1])
            self.assertEqual(result['return_i32'],1)

    def test_masked_plus_one_scale_and_saturation(self):
        # With zero coefficients each sample is solely signedNibble * scale.
        for header,positive,negative in ((0,7,-8),(1,14,-16),(0x1FFF,32767,-32768),(0x2000,7,-8)):
            r=self.machine(block(header,bytes([0x78])*16)).run()
            self.assertEqual(r['state']['pcm_i16'],[positive,negative]*16)
        r=self.machine(block(0,bytes([0x78])*16),key=0x1FFF).run()
        self.assertEqual(r['state']['pcm_i16'],[32767,-32768]*16)

    def test_marker_has_no_pcm_or_key_writes_and_skips_history_commit(self):
        for header in (0x8000,0xFFFF):
            m=self.machine(header.to_bytes(2,'big'),history=(1234,-5678),key=65535)
            r=m.run();self.assertEqual(r['return_i32'],0)
            self.assertEqual(r['state']['history_i16'],[1234,-5678]);self.assertEqual(r['state']['key_u16'],65535)
            self.assertEqual(r['pcm_store_count'],0)
            self.assertNotIn('pcm',r['writes']);self.assertNotIn('history',r['writes']);self.assertNotIn('key',r['writes'])
            self.assertNotIn('owned_nibble_table',r['reads'])

    def test_marker_after_block_keeps_prior_pcm_and_key_but_old_external_history(self):
        m=self.machine(block(0,bytes([0x12])*16)+b'\x80\x00',2,history=(99,-77),key=0,multiplier=7,addend=9)
        r=m.run();self.assertEqual(r['return_i32'],1);self.assertEqual(r['state']['key_u16'],9)
        self.assertEqual(r['state']['pcm_i16'][:32],[1,2]*16)
        self.assertEqual(r['state']['pcm_i16'][32:],[-23131]*32)
        self.assertEqual(r['state']['history_i16'],[99,-77]);self.assertNotIn('history',r['writes'])
        self.assertEqual(r['reads']['encoded']['last_end'],20)

    def test_nonpositive_count_preserves_buffers_but_loads_and_rewrites_history(self):
        for count in (0,-1,-2147483648):
            r=self.machine(b'',count,history=(-32768,32767),key=65535).run()
            self.assertEqual(r['return_i32'],count);self.assertEqual(r['pcm_store_count'],0)
            self.assertEqual(r['state']['history_i16'],[-32768,32767]);self.assertEqual(r['state']['key_u16'],65535)
            self.assertNotIn('encoded',r['reads']);self.assertNotIn('key',r['reads'])
            self.assertEqual(r['writes']['history']['bytes'],4)

    def test_boundaries_readonly_input_guards_and_abi(self):
        encoded=block(0,bytes(range(16)))
        m=self.machine(encoded);r=m.run()
        self.assertEqual(r['state']['encoded_sha256'],hashlib.sha256(encoded).hexdigest())
        self.assertEqual(r['state']['output_guard_hex'],'a5'*16)
        self.assertEqual(r['abi'],dict(stack_restored=True,saved_registers_restored=True))
        self.assertEqual(r['reads']['encoded']['last_end'],18)
        self.assertEqual(r['writes']['pcm']['last_end'],64)
        self.assertEqual([w['offset'] for w in r['pcm_stores']],list(range(0,64,2)))
        self.assertEqual(r['observations_not_abi']['input_cursor_u32'],INPUT+18)
        self.assertEqual(r['observations_not_abi']['output_cursor_u32'],OUTPUT+64)
        self.assertEqual(r['mac_instruction_counts'],dict(mult=81,mult1=16))

    def test_nonzero_initial_mac_state_does_not_change_defined_codec_outputs(self):
        params=dict(history=(32767,-32768),coefficients=(-32768,32767),key=12345)
        a=self.machine(**params).run()
        b=self.machine(**params,mac_initial=(0x123456789ABCDEF0,1,0xFFFFFFFFFFFFFFFF,0xABCDEF0123456789)).run()
        self.assertEqual(a['state'],b['state']);self.assertEqual(a['return_i32'],b['return_i32'])

    def test_finite_domain_and_unmapped_reads_reject(self):
        with self.assertRaises(OracleError):self.machine(count=17)
        with self.assertRaises(OracleError):self.machine(key=65536)
        with self.assertRaises(OracleError):self.machine(coefficients=(32768,0))
        with self.assertRaises(OracleError):self.machine(b'\x00').run()
        with self.assertRaises(OracleError):self.machine(output_samples=31).run()
        with self.assertRaises(StepLimit):self.machine().run(step_cap=2)
        m=self.machine();m.code=struct.pack('<I',0xFFFFFFFF)+m.code[4:]
        with self.assertRaises(OracleError):m.run()

    def test_deterministic_fixture_complete_body_coverage_and_source_immutability(self):
        shared=Path(__file__).with_name('sjuni_oracle.py');before=shared.read_bytes()
        fixture=generate();self.assertEqual(fixture,generate())
        self.assertEqual(fixture['counts']['cases'],104)
        reached=set().union(*(set(c['expected']['visited_pcs']) for c in fixture['cases']))
        self.assertEqual(reached,set(range(ENTRY,END,4)))
        self.assertEqual(shared.read_bytes(),before)


if __name__=='__main__':unittest.main()
