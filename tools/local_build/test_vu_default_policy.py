"""Scoped VU AOT admission tests using authored images, never game data."""

import hashlib
import importlib.util
import json
from pathlib import Path
import re
import struct
import subprocess
import sys
import tempfile
from types import SimpleNamespace
import unittest

from reconstruct_vu import reconstruct

TOOLS = Path(__file__).resolve().parents[1]
SPEC = importlib.util.spec_from_file_location("vu_policy_decode", TOOLS / "vu_whole_aot/decode.py")
DECODE = importlib.util.module_from_spec(SPEC)
SPEC.loader.exec_module(DECODE)


class VuDefaultPolicyTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)
        self.codes = []
        for marker in (1, 2):
            code = bytearray(16384)
            # Authored NOP/E pair followed by its NOP delay pair. An unreachable
            # marker makes the full immutable image identities distinct.
            struct.pack_into("<4I", code, 0, 0x8000033C, 0x400002FF, 0x8000033C, 0x000002FF)
            code[16] = marker
            self.codes.append(bytes(code))
        self.elf = self.root / "synthetic.elf"
        self.elf.write_bytes(b"".join(self.codes))
        self.plan = {"format": 1, "elfSha256": hashlib.sha256(self.elf.read_bytes()).hexdigest(),
                     "images": [{"sha256": hashlib.sha256(code).hexdigest(), "bytes": len(code),
                                 "entryPcs": [0, 8], "copies": [[index * len(code), 0, len(code)]]}
                                for index, code in enumerate(self.codes)], "specialized": []}

    def reconstruct(self):
        plan = self.root / "plan.json"
        plan.write_text(json.dumps(self.plan))
        collection = self.root / "collection"
        reconstruct(self.elf, plan, collection)
        return collection

    def generate(self, collection, capture=None):
        output = self.root / "factory"
        command = [sys.executable, str(TOOLS / "vu_whole_aot/generate.py"), "--collection", str(collection),
                   "--out", str(output)]
        if capture:
            command += ["--capture-dir", str(capture)]
        result = subprocess.run(
            command, stdout=subprocess.PIPE, stderr=subprocess.STDOUT, text=True)
        self.assertEqual(result.returncode, 0, result.stdout)
        return ((output / "reo_vu_whole_registered_generated.cpp").read_text(),
                (output / "reo_vu_whole_registered_generated.h").read_text(),
                json.loads((output / "manifest.json").read_text()))

    def load(self, collection):
        return DECODE.load_inputs(SimpleNamespace(capture_dir=[], collection=collection))

    def test_only_marked_images_enter_default_table(self):
        self.plan["images"][0]["enabledByDefault"] = True
        self.plan["images"][1]["enabledByDefault"] = False
        collection = self.reconstruct()
        programs = self.load(collection)
        self.assertTrue(programs[self.plan["images"][0]["sha256"]]["enabled_by_default"])
        self.assertFalse(programs[self.plan["images"][1]["sha256"]]["enabled_by_default"])
        self.assertTrue(all(item["starts"] == {0, 8} for item in programs.values()))
        source, header, manifest = self.generate(collection)
        self.assertEqual((manifest["programs"], manifest["default_programs"]), (2, 1))
        number = sorted(programs).index(self.plan["images"][0]["sha256"]) + 1
        descriptor = f"{{code{number},16384,16384,starts{number},2,execute{number}}}"
        self.assertIn("const vu_whole_program::Program defaultPrograms[]={" + descriptor + "};", source)
        self.assertIn("const vu_whole_program::Table table{programs,2};", source)
        self.assertIn("const vu_whole_program::Table defaultTable{defaultPrograms,1};", source)
        self.assertIn("#define REO_VU_HAS_DEFAULT_PROGRAM_TABLE 1", header)
        self.assertIn("defaultProgramTable() noexcept", header)

    def test_legacy_plans_keep_valid_empty_default_table(self):
        collection = self.reconstruct()
        events = [json.loads(line) for line in (collection / "events.jsonl").read_text().splitlines()]
        self.assertTrue(all("enabled_by_default" not in event for event in events))
        self.assertTrue(all(not item["enabled_by_default"] for item in self.load(collection).values()))
        source, _, manifest = self.generate(collection)
        self.assertEqual((manifest["programs"], manifest["default_programs"]), (2, 0))
        self.assertIn("const vu_whole_program::Table defaultTable{nullptr,0};", source)
        self.assertNotIn("Program defaultPrograms[]", source)
        self.assertIn("programTable() noexcept{return &table;}", source)

    def test_explicitly_enabled_full_subset_preserves_full_table(self):
        for image in self.plan["images"]:
            image["enabledByDefault"] = True
        source, _, manifest = self.generate(self.reconstruct())
        self.assertEqual((manifest["programs"], manifest["default_programs"]), (2, 2))
        tables = re.findall(r"Program (?:programs|defaultPrograms)\[\]=\{(.*)\};", source)
        self.assertEqual(len(tables), 2)
        self.assertEqual(tables[0], tables[1])

    def test_non_boolean_metadata_policy_is_refused_before_output(self):
        for value in (1, 0, "true", None):
            with self.subTest(value=value):
                self.plan["images"][0]["enabledByDefault"] = value
                with self.assertRaisesRegex(ValueError, "default policy"):
                    self.reconstruct()
                self.assertFalse((self.root / "collection").exists())

    def test_non_boolean_collection_policy_is_refused(self):
        collection = self.reconstruct()
        events_path = collection / "events.jsonl"
        events = [json.loads(line) for line in events_path.read_text().splitlines()]
        for value in (1, 0, "true", None):
            with self.subTest(value=value):
                events[0]["enabled_by_default"] = value
                events_path.write_text("\n".join(json.dumps(event) for event in events) + "\n")
                with self.assertRaisesRegex(ValueError, "default policy"):
                    self.load(collection)

    def test_raw_captures_remain_opt_in(self):
        capture = self.root / "capture"
        capture.mkdir()
        (capture / "synthetic.code.bin").write_bytes(self.codes[0])
        state = bytearray(632)
        struct.pack_into("<I", state, 604, 0)
        (capture / "synthetic.state.bin").write_bytes(state)
        programs = DECODE.load_inputs(SimpleNamespace(capture_dir=[capture], collection=None))
        self.assertEqual(len(programs), 1)
        self.assertFalse(next(iter(programs.values()))["enabled_by_default"])
        self.assertEqual(next(iter(programs.values()))["default_starts"], set())

    def test_unmarked_capture_cannot_expand_default_entry_keys(self):
        self.plan["images"][0]["enabledByDefault"] = True
        collection = self.reconstruct()
        capture = self.root / "capture"
        capture.mkdir()
        (capture / "synthetic.code.bin").write_bytes(self.codes[0])
        state = bytearray(632)
        struct.pack_into("<I", state, 604, 16)
        (capture / "synthetic.state.bin").write_bytes(state)
        programs = DECODE.load_inputs(SimpleNamespace(capture_dir=[capture], collection=collection))
        digest = self.plan["images"][0]["sha256"]
        self.assertEqual(programs[digest]["starts"], {0, 8, 16})
        self.assertEqual(programs[digest]["default_starts"], {0, 8})
        number = sorted(programs).index(digest) + 1
        source, _, manifest = self.generate(collection, capture)
        self.assertEqual(manifest["default_programs"], 1)
        self.assertIn(f"static constexpr uint32_t starts{number}[]={{0,8,16}};", source)
        self.assertIn(f"static constexpr uint32_t defaultStarts{number}[]={{0,8}};", source)
        descriptor = f"{{code{number},16384,16384,defaultStarts{number},2,execute{number}}}"
        self.assertIn("Program defaultPrograms[]={" + descriptor + "};", source)


if __name__ == "__main__":
    unittest.main()
