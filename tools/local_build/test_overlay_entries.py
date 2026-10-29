"""Hellfire callback registration regression, using fabricated MIPS input only."""

import csv
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
from generate_game import recompiler_environment

ROOT = Path(__file__).resolve().parents[2]
ENTRIES = (0x5D85E0, 0x5D8620, 0x5D8630)


def callback_rows():
    with (ROOT / "recomp/config/overlay_maps/ovl2.csv").open(newline="") as stream:
        return [row for row in csv.DictReader(stream)
                if int(row["start"], 16) in ENTRIES]


class OverlayEntryMapTests(unittest.TestCase):
    def test_callback_and_shared_body_are_separate_callable_entries(self):
        rows = callback_rows()
        self.assertEqual([int(row["start"], 16) for row in rows], list(ENTRIES))
        ranges = [(int(row["start"], 16), int(row["end"], 16)) for row in rows]
        for row, (start, end) in zip(rows, ranges):
            self.assertEqual(int(row["size"]), end - start)
            self.assertEqual(row["name"], f"sub_{start:08X}")
        # A callback at 5D8620 must not enter the state-changing 5D85E0 prelude.
        self.assertLessEqual(ranges[0][1], ENTRIES[1])
        self.assertEqual(ranges[1], (ENTRIES[1], ENTRIES[1] + 8))
        self.assertLessEqual(ranges[1][1], ENTRIES[2])
        self.assertEqual(ranges[2][1], 0x5D8850)


@unittest.skipUnless(os.environ.get("REO_TEST_RECOMPILER"),
                     "Set REO_TEST_RECOMPILER to the freshly built tool")
class OverlayEntryGenerationTests(unittest.TestCase):
    def test_overlay_registration_preserves_callback_tail_entry(self):
        with tempfile.TemporaryDirectory(prefix="reo-overlay-entry-test-") as folder:
            root = Path(folder)
            rows = callback_rows()
            base = 0x570000
            code = bytearray(0x5D8850 - base)
            struct.pack_into("<4s4I", code, 0, b"MWo3", 3, base, len(code) - 64, 0)
            # Authored fixture: one entry stores a prefix marker, another skips
            # that store, and both tail-call a body that writes a second marker.
            jump = 0x08000000 | (ENTRIES[2] >> 2)
            for pc, words in [(ENTRIES[0], [0xA0850000, jump, 0]),
                              (ENTRIES[1], [jump, 0]),
                              (ENTRIES[2], [0xA0860001, 0x03E00008, 0])]:
                for index, word in enumerate(words):
                    struct.pack_into("<I", code, pc - base + 4 * index, word)
            (root / "2.elf").write_bytes(wrap_elf(code, base, len(code)))
            with (root / "ovl2.csv").open("w", newline="") as stream:
                writer = csv.DictWriter(stream, fieldnames=["name", "start", "end", "size"])
                writer.writeheader()
                writer.writerows(rows)
            result = subprocess.run(
                [sys.executable, str(ROOT / "tools/overlay_recomp.py"), str(root),
                 os.environ["REO_TEST_RECOMPILER"], "2"], cwd=root,
                env=recompiler_environment("o2"), stdout=subprocess.PIPE,
                stderr=subprocess.STDOUT, text=True)
            self.assertEqual(result.returncode, 0, result.stdout)
            output = root / "recomp/config/output_ovl/o2"
            registry = (output / "register_o2.cpp").read_text()
            registered = re.findall(
                r"registerOverlayFunction\(0x570000u, 0x336F574Du, 4u, 3u, "
                r"(0x[\da-fA-F]+)u, (\w+)\);", registry)
            self.assertEqual({int(pc, 16) for pc, _ in registered}, set(ENTRIES))
            sources = {int(pc, 16): (output / (name + ".cpp")).read_text()
                       for pc, name in registered}
            # The callback must execute its own tail jump, with no prelude store
            # copied in from its formerly containing function.
            self.assertNotIn("WRITE8(", sources[ENTRIES[1]])
            self.assertIn("ctx->pc = 0x5D8630u;", sources[ENTRIES[1]])
            self.assertIn("o2_005D8630_0x5d8630(rdram, ctx, runtime)", sources[ENTRIES[1]])
            self.assertIn("WRITE8(ADD32(GPR_U32(ctx, 4), 0)", sources[ENTRIES[0]])
            self.assertIn("WRITE8(ADD32(GPR_U32(ctx, 4), 1)", sources[ENTRIES[2]])
            for row in rows:
                start, end = int(row["start"], 16), int(row["end"], 16)
                self.assertIn(f"// Address: {start:#x} - {end:#x}", sources[start])


if __name__ == "__main__":
    unittest.main()
