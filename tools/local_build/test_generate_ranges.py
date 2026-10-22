"""Function-boundary validation with fabricated compiler output."""

from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from generate_game import validate_mapped_ranges, recompiler_environment


class MappedRangeTests(unittest.TestCase):
    def test_player_build_uses_plain_cpu_code_for_every_executable_pass(self):
        with patch.dict('os.environ', {'PS2RECOMP_UNGUARDED_RANGES': 'invalid-inherited-setting'}):
            for name in ['main', 'extra', 'o2', 'ovl9', 'support']:
                self.assertEqual(recompiler_environment(name)['PS2RECOMP_UNGUARDED_RANGES'],
                                 '0x0-0x2000000')

    def test_source_audit_is_explicit_and_preserves_overlay_witnesses(self):
        with patch.dict('os.environ', {'PS2RECOMP_UNGUARDED_RANGES': 'invalid-inherited-setting'}):
            for name in ['main', 'extra']:
                self.assertEqual(recompiler_environment(name, True)['PS2RECOMP_UNGUARDED_RANGES'],
                                 '0x142000-0x148000')
            for name in ['o2', 'ovl9', 'support']:
                self.assertNotIn('PS2RECOMP_UNGUARDED_RANGES', recompiler_environment(name, True))

    def validate(self, end, *, missing=False, skip=False):
        with tempfile.TemporaryDirectory(prefix="reo-range-check-") as folder:
            root = Path(folder)
            function_map = root / "functions.csv"
            function_map.write_text("name,start,end,size\nsub_00100080,0x100080,0x100088,8\n")
            if not missing:
                (root / "sub_00100080_0x100080.cpp").write_text(
                    f"// Address: 0x100080 - {end}\nvoid synthetic() {{}}\n")
            validate_mapped_ranges(root, function_map, ("sub_00100080",) if skip else ())

    def test_exact_explicit_range(self):
        self.validate("0x100088")

    def test_discovered_oversized_range_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "ignored mapped bounds"):
            self.validate("0x200000")

    def test_missing_function_is_rejected(self):
        with self.assertRaisesRegex(ValueError, "omitted mapped function"):
            self.validate("0x100088", missing=True)

    def test_intentional_skip_is_allowed(self):
        self.validate("0x100088", missing=True, skip=True)


if __name__ == "__main__":
    unittest.main()
