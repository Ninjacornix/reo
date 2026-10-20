"""Ensure masked instruction equality cannot hide a changed named call target."""
import os
from pathlib import Path
import struct
import subprocess
import tempfile
import unittest

from compare_unity_functions import bodies
from compare_compiled_outputs import inspect_pe


class PeMetadataTests(unittest.TestCase):
    def test_only_link_timestamps_and_checksum_are_ignored(self):
        def fixture(stamp):
            data = bytearray(2048)
            data[:2] = b"MZ"
            struct.pack_into("<I", data, 0x3c, 0x80)
            data[0x80:0x84] = b"PE\0\0"
            struct.pack_into("<HHIIIHH", data, 0x84, 0x8664, 2, stamp, 0, 0, 240, 0x22)
            optional = 0x98
            struct.pack_into("<H", data, optional, 0x20b)
            struct.pack_into("<I", data, optional+64, stamp ^ 31)
            struct.pack_into("<I", data, optional+108, 16)
            struct.pack_into("<II", data, optional+160, 0x2000, 28)
            for i, (name, rva, raw) in enumerate([(b".text", 0x1000, 0x400),
                                                 (b".buildid", 0x2000, 0x600)]):
                at = optional+240+i*40
                data[at:at+len(name)] = name
                struct.pack_into("<IIII", data, at+8, 512, rva, 512, raw)
            data[0x400] = 0xc3
            struct.pack_into("<IIHHIIII", data, 0x600, 0, stamp, 0, 0, 2, 24, 0x201c, 0x61c)
            data[0x61c:0x620] = b"RSDS"
            return data

        with tempfile.TemporaryDirectory(prefix="reo-pe-check-") as folder:
            path = Path(folder) / "fixture.exe"
            path.write_bytes(fixture(123))
            before = inspect_pe(path)
            changed = fixture(456)
            path.write_bytes(changed)
            after = inspect_pe(path)
            self.assertEqual(before["normalizedSha256"], after["normalizedSha256"])
            self.assertEqual(after["characteristics"], 0x22)
            self.assertEqual(len(after["normalizedFields"]), 3)
            for offset in (0x400, 0x620):
                corrupt = changed[:]
                corrupt[offset] ^= 1
                path.write_bytes(corrupt)
                self.assertNotEqual(before["normalizedSha256"], inspect_pe(path)["normalizedSha256"])


@unittest.skipUnless(os.environ.get("REO_TEST_CXX"), "Set REO_TEST_CXX to the pinned Clang driver")
class CoffComparisonTests(unittest.TestCase):
    def test_changed_call_target_is_reported_separately(self):
        with tempfile.TemporaryDirectory(prefix="reo-coff-check-") as folder:
            root = Path(folder)
            source, obj = root / "fixture.cpp", root / "fixture.obj"
            source.write_text(
                'extern "C" int targetA(int);extern "C" int targetB(int);\n'
                'int sub_00001000(int value){return targetA(value)+targetB(value);}\n')
            subprocess.run([os.environ["REO_TEST_CXX"], "-O2", "-c", str(source), "-o", str(obj)],
                           check=True, capture_output=True)
            before = bodies(obj)
            self.assertEqual(len(before), 1)
            data = bytearray(obj.read_bytes())
            _, sections, _, sympos, symcount, optional, _ = struct.unpack_from("<HHIIIHH", data)
            names, index = {}, 0
            while index < symcount:
                record = data[sympos+index*18:sympos+(index+1)*18]
                if record[:4] != bytes(4):
                    names[record[:8].split(b"\0", 1)[0].decode()] = index
                index += 1 + record[17]
            changed = False
            for n in range(sections):
                offset = 20+optional+n*40
                reloc = struct.unpack_from("<I", data, offset+24)[0]
                count = struct.unpack_from("<H", data, offset+32)[0]
                for i in range(count):
                    target = struct.unpack_from("<I", data, reloc+i*10+4)[0]
                    if target == names["targetA"]:
                        struct.pack_into("<I", data, reloc+i*10+4, names["targetB"])
                        changed = True
            self.assertTrue(changed)
            altered = root / "altered.obj"
            altered.write_bytes(data)
            after = bodies(altered)
            name = next(iter(before))
            self.assertEqual(before[name]["sha256"], after[name]["sha256"])
            self.assertNotEqual(before[name]["namedRelocationsSha256"],
                                after[name]["namedRelocationsSha256"])


if __name__ == "__main__":
    unittest.main()
