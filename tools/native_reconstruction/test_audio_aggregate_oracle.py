"""Check authored transport and freeze safety, without playback expectations."""
import io
import struct
import tempfile
import unittest
from pathlib import Path

import audio_aggregate_oracle as oracle


class AudioAggregateOracleTests(unittest.TestCase):
    def test_deterministic_authored_inputs(self):
        self.assertEqual(oracle.canonical(oracle.transcript()),
                         oracle.canonical(oracle.transcript()))

    def test_unique_cases_and_asset_names(self):
        value=oracle.transcript()
        self.assertEqual(len(value["cases"]),len({c["name"] for c in value["cases"]}))
        self.assertEqual(len(value["assets"]),len({a["name"] for a in value["assets"]}))

    def test_binary_transports_exact_original_inputs(self):
        value=oracle.transcript()
        for case in value["cases"]:
            with self.subTest(case=case["name"]):
                data=io.BytesIO(oracle.encode(value,case))
                def word(): return struct.unpack("<I",data.read(4))[0]
                def blob(): return data.read(word())
                self.assertEqual(data.read(8),b"AAGO1\0\0\0")
                self.assertEqual(word(),len(value["assets"]))
                for asset in value["assets"]:
                    for key in ("hd_hex","bd_hex","tq_hex"):
                        self.assertEqual(blob(),bytes.fromhex(asset[key]))
                self.assertEqual(blob().decode(),case["name"])
                self.assertEqual(word(),len(case["actions"]))
                for action in case["actions"]:
                    self.assertEqual(word(),oracle.KINDS[action["op"]])
                    self.assertEqual([word() for _ in range(word())],action["words"])
                    self.assertEqual(blob(),bytes.fromhex(action["bytes_hex"]))
                self.assertEqual(data.read(),b"")

    def test_entire_declared_action_protocol_is_exercised(self):
        kinds={a["op"] for c in oracle.transcript()["cases"] for a in c["actions"]}
        self.assertEqual(kinds,set(oracle.KINDS))

    def test_freeze_never_replaces_different_input(self):
        with tempfile.TemporaryDirectory() as directory:
            path=Path(directory)/"input"
            oracle.frozen_write(path,b"original")
            oracle.frozen_write(path,b"original")
            with self.assertRaisesRegex(ValueError,"Frozen cohort differs"):
                oracle.frozen_write(path,b"replacement")
            self.assertEqual(path.read_bytes(),b"original")

    def test_every_case_fresh_reset_and_bounded_wire(self):
        value=oracle.transcript()
        for case in value["cases"]:
            self.assertEqual([a["op"] for a in case["actions"][:2]],
                             ["pcm_reset","bank_reset"])
            self.assertLessEqual(len(case["actions"]),128)
            for action in case["actions"]:
                self.assertLessEqual(len(action["words"]),16)
                self.assertLessEqual(len(bytes.fromhex(action["bytes_hex"])),65536)
                if action["op"]=="render":self.assertLessEqual(action["words"][0],1200)

    def test_audio_assets_are_synthetic_no_expected_output(self):
        for asset in oracle.transcript()["assets"]:
            self.assertEqual(set(asset),{"name","hd_hex","bd_hex","tq_hex"})
            self.assertEqual(bytes.fromhex(asset["hd_hex"])[:8],b"IECSsreV")
        self.assertEqual(oracle.float_bits(.5),0x3f000000)


if __name__=="__main__":unittest.main()
