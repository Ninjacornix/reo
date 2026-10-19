import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest

from generate_catalogues import generate


class CatalogueTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        # Synthetic ELF32 fixture, not bytes from a commercial game.
        elf = bytearray(128)
        elf[:7] = b"\x7fELF\x01\x01\x01"
        struct.pack_into("<I", elf, 28, 52)
        struct.pack_into("<HH", elf, 42, 32, 1)
        struct.pack_into("<8I", elf, 52, 1, 96, 0x1000, 0x1000, 8, 8, 5, 4)
        struct.pack_into("<II", elf, 96, 0x11223344, 0x55667788)
        self.elf = self.root / "input.elf"
        self.elf.write_bytes(elf)
        self.manifest = {"format": 1, "elfSha256": hashlib.sha256(elf).hexdigest(),
                         "catalogues": {"sample.inc": {"instructionPcField": 0,
                             "fields": [[0x1000, "instruction", 0x1000],
                                        [0x1004, "instruction", 0x1000]]}}}
        self.plan = self.root / "plan.json"

    def run_plan(self):
        self.plan.write_text(json.dumps(self.manifest))
        return generate(self.elf, self.plan, self.root / "generated")

    def test_local_instruction_extraction(self):
        self.assertEqual(self.run_plan(), 2)
        source = (self.root / "generated/sample.inc").read_text()
        self.assertIn("{0x1000u,0x11223344u,0x1000u}", source)
        self.assertIn("{0x1004u,0x55667788u,0x1000u}", source)

    def test_wrong_revision_does_not_create_outputs(self):
        self.manifest["elfSha256"] = "0" * 64
        with self.assertRaisesRegex(ValueError, "Unsupported ELF"):
            self.run_plan()
        self.assertFalse((self.root / "generated").exists())

    def test_unmapped_instruction_refused(self):
        self.manifest["catalogues"]["sample.inc"]["fields"][0][0] = 0x2000
        with self.assertRaisesRegex(ValueError, "not file-backed"):
            self.run_plan()

    def test_unaligned_instruction_refused(self):
        self.manifest["catalogues"]["sample.inc"]["fields"][0][0] = 0x1001
        with self.assertRaisesRegex(ValueError, "Unaligned"):
            self.run_plan()

    def test_output_traversal_refused(self):
        self.manifest["catalogues"]["../outside.inc"] = self.manifest["catalogues"].pop("sample.inc")
        with self.assertRaisesRegex(ValueError, "filename"):
            self.run_plan()
        self.assertFalse((self.root / "outside.inc").exists())


if __name__ == "__main__":
    unittest.main()
