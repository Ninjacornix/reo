import hashlib
import json
from pathlib import Path
import struct
import tempfile
import unittest

from export_source_recipes import recipe
from generate_queue_control import generate as queue
from reconstruct_vu import reconstruct
from source_recipes import apply_recipe, normalized


class LocalGenerationTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def plan(self, value):
        target = self.root / "plan.json"
        target.write_text(json.dumps(value))
        return target

    def test_authored_changes_are_reapplied_to_local_base(self):
        base = "void function() {\n  generated_call();\n}\n"
        result = base.replace("generated_call();", "probe();\n  generated_call();")
        edits = recipe(base, result)
        self.assertEqual(apply_recipe(base, edits), result)
        self.assertTrue(any(part[0] == "copy" for part in edits["parts"]))
        self.assertNotIn("generated_call", "".join(p[1] for p in edits["parts"] if p[0] == "text"))

    def test_wrong_generator_result_is_refused(self):
        edits = recipe("old source", "new authored source")
        with self.assertRaisesRegex(ValueError, "differs"):
            apply_recipe("different generator", edits)

    def test_copy_bounds_are_checked(self):
        edits = recipe("local", "local")
        edits["parts"] = [["copy", 0, 100]]
        with self.assertRaisesRegex(ValueError, "range"):
            apply_recipe("local", edits)

    def test_instruction_annotations_are_not_exported(self):
        self.assertEqual(normalized("// 0x100000: 0x01234567 synthetic\nbody\n"), "body\n")

    def vu_fixture(self):
        elf = self.root / "owned.elf"
        elf.write_bytes(b"\x01\x02\x03\x04")
        code = elf.read_bytes() + bytes(16380)
        plan = {"format": 1, "elfSha256": hashlib.sha256(elf.read_bytes()).hexdigest(),
                "images": [{"sha256": hashlib.sha256(code).hexdigest(), "bytes": 16384,
                            "entryPcs": [0], "copies": [[0, 0, 4]]}], "specialized": []}
        return elf, plan

    def test_vu_images_come_from_owned_input(self):
        elf, plan = self.vu_fixture()
        output = self.root / "generated"
        self.assertEqual(reconstruct(elf, self.plan(plan), output), 1)
        actual = next(output.glob("image-*.bin")).read_bytes()
        self.assertEqual(actual[:4], elf.read_bytes())
        self.assertEqual(actual[4:], bytes(16380))

    def test_vu_digest_mismatch_is_refused_before_output(self):
        elf, plan = self.vu_fixture()
        plan["images"][0]["copies"][0][1] = 4
        output = self.root / "generated"
        with self.assertRaisesRegex(ValueError, "identity"):
            reconstruct(elf, self.plan(plan), output)
        self.assertFalse(output.exists())

    def test_vu_overlap_is_refused(self):
        elf, plan = self.vu_fixture()
        plan["images"][0]["copies"].append([0, 2, 2])
        with self.assertRaisesRegex(ValueError, "Overlapping"):
            reconstruct(elf, self.plan(plan), self.root / "generated")

    def test_queue_uses_instruction_operands_from_local_elf(self):
        # Synthetic addiu $v0,$zero,7; no commercial instructions or data.
        image = bytearray(132)
        struct.pack_into("<I", image, 28, 52)
        struct.pack_into("<HH", image, 42, 32, 1)
        struct.pack_into("<8I", image, 52, 1, 128, 0x100000, 0x100000, 4, 4, 5, 4)
        struct.pack_into("<I", image, 128, 9 << 26 | 2 << 16 | 7)
        elf = self.root / "owned.elf"
        elf.write_bytes(image)
        plan = {"format": 1, "elfSha256": hashlib.sha256(image).hexdigest(),
                "blocks": [{"pc": 0x100000, "sites": [0x100000]}]}
        target = self.root / "queue.inc"
        queue(elf, self.plan(plan), target)
        self.assertIn("set32(2u, g32(0u) + 0x00000007u)", target.read_text())


if __name__ == "__main__":
    unittest.main()
