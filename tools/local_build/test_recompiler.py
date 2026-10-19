"""Optional tool integration tests using fabricated MIPS input, never game data."""

import csv
import json
import os
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile
import unittest

sys.path.insert(0, str(Path(__file__).resolve().parents[1]))
from overlay_extract import wrap_elf


@unittest.skipUnless(os.environ.get("REO_TEST_RECOMPILER"), "Set REO_TEST_RECOMPILER to the freshly built tool")
class RecompilerTests(unittest.TestCase):
    def generate(self, words):
        with tempfile.TemporaryDirectory(prefix="reo-compiler-test-") as folder:
            root = Path(folder)
            code = bytearray(256)
            for n, word in enumerate(words):
                struct.pack_into("<I", code, 128 + 4 * n, word)
            image = bytearray(wrap_elf(code, 0x100000, len(code)))
            struct.pack_into("<I", image, 24, 0x100080)
            elf = root / "synthetic.elf"
            elf.write_bytes(image)
            functions = root / "functions.csv"
            with functions.open("w", newline="") as f:
                writer = csv.writer(f)
                writer.writerow(["name", "start", "end", "size"])
                writer.writerow(["sub_00100080", "0x100080", hex(0x100080 + 4 * len(words)), str(4 * len(words))])
            quote = lambda p: json.dumps(str(p).replace("\\", "/"))
            config = root / "config.toml"
            config.write_text("[general]\ninput=" + quote(elf) + "\nghidra_output=" + quote(functions) +
                              "\noutput=" + quote(root / "out") + "\nsingle_file_output=false\nstubs=[]\nskip=[]\n")
            result = subprocess.run([os.environ["REO_TEST_RECOMPILER"], str(config)],
                                    stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
            self.assertEqual(result.returncode, 0, result.stdout)
            return (root / "out/sub_00100080_0x100080.cpp").read_text()

    def test_explicit_map_bounds_replace_discovery_range(self):
        source = self.generate([0x03e00008, 0])  # synthetic jr ra; nop
        self.assertRegex(source, r"// Address: 0x100080 - 0x100088\b")

    def test_halfword_broadcast_uses_rt_operand(self):
        # Fabricated pcpyh encoding with rs=0, rt=10 and rd=8.
        instruction = (0x1c << 26) | (10 << 16) | (8 << 11) | (0x1b << 6) | 0x29
        source = self.generate([instruction, 0x03e00008, 0])
        self.assertIn("__m128i src = GPR_VEC(ctx, 10)", source)


if __name__ == "__main__":
    unittest.main()
