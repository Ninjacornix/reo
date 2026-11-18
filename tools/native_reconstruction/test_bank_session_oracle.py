"""Input-format and source-observation checks; no Python DSP expectations."""
import json
import os
from pathlib import Path
import struct
import tempfile
import unittest

import bank_session_oracle as oracle


class SyntheticInputs(unittest.TestCase):
    def test_transcript_deterministic_and_authored_format_bounds(self):
        a,b=oracle.transcript(),oracle.transcript()
        self.assertEqual(oracle.canonical(a),oracle.canonical(b))
        self.assertEqual(oracle.encode(a),oracle.encode(b))
        self.assertEqual(oracle.encode(a)[:8],b"RBSO1\0\0\0")
        assets={asset["name"]:asset for asset in a["assets"]}
        normal=assets["loop"]
        hd=bytes.fromhex(normal["hd_hex"])
        self.assertEqual(hd[:8],b"IECSsreV")
        self.assertEqual(hd[16:24],b"IECSdaeH")
        self.assertEqual(struct.unpack_from("<4I",hd,0x24),(0x40,0x140,0x1C0,0x300))
        self.assertEqual(normal["hd_hex"],assets["loop_changed_bd"]["hd_hex"])
        self.assertNotEqual(normal["bd_hex"],assets["loop_changed_bd"]["bd_hex"])
        self.assertEqual(len(bytes.fromhex(assets["resolution_65025"]["hd_hex"])),0x1940)
        for case in a["cases"]:
            self.assertEqual(case["actions"][0],{"op":"reset"})
            for action in case["actions"]:
                if action["op"]=="mix": self.assertLessEqual(action["frames"],a["max_mix_frames"])

    def test_frozen_input_change_is_rejected(self):
        with tempfile.TemporaryDirectory() as temporary:
            output=Path(temporary)
            _,first=oracle.freeze(output)
            _,second=oracle.freeze(output)
            self.assertEqual(first,second)
            (output/"input.bin").write_bytes(b"changed")
            with self.assertRaises(ValueError): oracle.freeze(output)

    def test_source_identity_and_no_candidate_build_input(self):
        self.assertIn('#include "source/ReoSoundBanks.cpp"',oracle.HARNESS)
        self.assertNotIn("#define private",oracle.HARNESS)
        self.assertIn("std::weak_ptr<const s::DecodedSample>",oracle.HARNESS)
        self.assertEqual(len(oracle.SOURCE_SHA),64)


class OriginalSourceObservations(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.output=Path(os.environ.get("BANK_SESSION_ORACLE_OUTPUT",
            str(oracle.ROOT/"build-native-sjuni/bank-session-oracle-v2")))
        if not (cls.output/"receipt.json").exists():
            raise unittest.SkipTest("Original-source expected observations have not been generated")
        cls.receipt=json.loads((cls.output/"receipt.json").read_text())
        cls.inputs=json.loads((cls.output/"input.json").read_text())
        cls.expected=[json.loads(Path(row["expected"]).read_text()) for row in cls.receipt["compilers"]]

    def test_frozen_source_and_inputs(self):
        self.assertFalse(self.receipt["candidate_read"])
        self.assertFalse(self.receipt["device_opened"])
        self.assertFalse(self.receipt["game_run"])
        frozen=json.loads((self.output/"input-manifest.json").read_text())
        for name,digest in frozen["inputs"].items(): self.assertEqual(oracle.sha(self.output/name),digest)
        self.assertEqual(oracle.sha(self.output/"source/ReoSoundBanks.cpp"),oracle.SOURCE_SHA)
        self.assertEqual(oracle.sha(self.output/"source/ReoSoundBanks.h"),oracle.HEADER_SHA)
        for row in self.receipt["compilers"]:
            self.assertEqual(oracle.sha(Path(row["expected"])),row["expected_sha256"])

    def test_cross_compiler_exact_and_gain_call_order(self):
        self.assertEqual(len(self.expected),2)
        self.assertEqual(self.expected[0],self.expected[1])
        for expected in self.expected:
            for spec,case in zip(self.inputs["cases"],expected["cases"]):
                previous=None
                for action,observed in zip(spec["actions"],case["actions"]):
                    state=observed["state"]
                    self.assertEqual(len(state["ports"]),14)
                    self.assertTrue(all(len(p["requests"])==16 for p in state["ports"]))
                    self.assertLessEqual(len(state["voices"]),48)
                    if action["op"]=="mix" and action["kind"]!="null" and action["frames"]:
                        self.assertEqual(len(observed["gain_calls"]),224)
                        for index,row in enumerate(observed["gain_calls"]):
                            port,slot=divmod(index,16)
                            self.assertEqual(row[:3],[port,previous["ports"][port]["requests"][slot][5],
                                                       previous["ports"][port]["fingerprint"]])
                        self.assertEqual(state["clock"],previous["clock"]+action["frames"])
                    else:
                        self.assertEqual(observed["gain_calls"],[])
                        if action["op"]!="reset": self.assertEqual(state["clock"],previous["clock"])
                    previous=state

    def test_partition_tick_and_cancel_tail(self):
        cases={c["name"]:c for c in self.expected[0]["cases"]}
        split=cases["split_600"]["actions"]; whole=cases["whole_600"]["actions"]
        self.assertEqual([bit for a in split for bit in a["pcm_bits"]],
                         [bit for a in whole for bit in a["pcm_bits"]])
        self.assertEqual(split[-1]["state"],whole[-1]["state"])
        # First-frame tick, then no scheduler tick until frameClock reaches200.
        self.assertEqual(split[4]["state"]["ports"][2]["requests"],split[5]["state"]["ports"][2]["requests"])
        self.assertEqual(split[5]["state"]["ports"][2]["requests"],split[6]["state"]["ports"][2]["requests"])
        self.assertNotEqual(split[6]["state"]["ports"][2]["requests"],split[7]["state"]["ports"][2]["requests"])
        cancelled=cases["cancel_tail"]["actions"][5]["state"]
        self.assertTrue(any(v["active"] and v["envelope"][0]==3 for v in cancelled["voices"]))
        self.assertFalse(any(r[3] for r in cancelled["ports"][2]["requests"]))
        self.assertEqual(cases["cancel_tail"]["actions"][6]["query"][2],0)

    def test_prefix_failure_and_replacement_clip_lifetime(self):
        cases={c["name"]:c for c in self.expected[0]["cases"]}
        failed=cases["packet_prefix_failures"]["actions"][5]
        self.assertFalse(failed["returned"])
        self.assertTrue(failed["state"]["muted"])
        self.assertEqual(failed["state"]["ports"][2]["volume"],64)
        replaced=cases["stop_unload_replace"]["actions"][5]["state"]
        old=replaced["voices"][0]
        new=replaced["ports"][2]["resolved"][0]["samples"][0]["clip"]
        self.assertFalse(old["active"])
        self.assertNotEqual(old["clip"]["id"],new["id"])
        self.assertNotEqual(old["clip"]["pcm_hash"],new["pcm_hash"])
        self.assertEqual(cases["stop_unload_replace"]["actions"][4]["state"]["ports"][2]["fingerprint"],
                         replaced["ports"][2]["fingerprint"])
        reset=cases["stop_unload_replace"]["actions"][-1]["state"]
        self.assertTrue(all(not p["loaded"] and p["bank_sequences"]==0 for p in reset["ports"]))
        self.assertEqual(reset["voices"],[])

    def test_source_large_event_and_layer_boundaries(self):
        cases={c["name"]:c for c in self.expected[0]["cases"]}
        layers=cases["layer_count_boundary"]["actions"][-1]["state"]
        self.assertEqual(layers["ports"][0]["resolved"][0]["sample_count"],65025)
        self.assertEqual(len(layers["voices"]),48)
        self.assertGreaterEqual(layers["unsupported_reports"],65025-48)
        spec=next(c for c in self.inputs["cases"] if c["name"]=="parser_vag_sequence")
        observed=cases["parser_vag_sequence"]["actions"]
        index=next(i for i,a in enumerate(spec["actions"]) if a.get("asset")=="events_1025")
        events=observed[index]["probe"]["sequences"][0]["ticks"][0]["events"]
        self.assertEqual(len(events),1025)
        self.assertEqual([event[0] for event in events[-2:]],[8,9])

    def test_all_envelope_phases_and_nonzero_loop_start_observed(self):
        cases={c["name"]:c for c in self.expected[0]["cases"]}
        states=[a["state"] for a in cases["loop_offset_envelope_phases"]["actions"]]
        phases={v["envelope"][0] for state in states for v in state["voices"]}
        self.assertEqual(phases,{0,1,2,3,4})
        self.assertTrue(any(v["clip"]["loop_start"]==28 and v["clip"]["loop"]
                            for state in states for v in state["voices"]))


if __name__=="__main__": unittest.main()
