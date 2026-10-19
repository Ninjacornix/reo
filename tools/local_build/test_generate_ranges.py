"""Function-boundary validation with fabricated compiler output."""

from pathlib import Path
import tempfile
import unittest

from generate_game import validate_mapped_ranges


class MappedRangeTests(unittest.TestCase):
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
