import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch
import zipfile

import seal_kit


class SealKitGameTests(unittest.TestCase):
    def seal_fixture(self, directory, game=None, elf=None, forbidden=None):
        root = Path(directory)
        kit = root / "kit"
        (kit / "tools").mkdir(parents=True)
        (kit / "notices").mkdir()
        plan = {"runtimeAbi": "fixture", "toolchain": "llvm-mingw", "copyOutputs": [],
                "independentInputs": []}
        if game is not None:
            plan["game"] = game
        if elf is not None:
            plan["elfSha256"] = elf
        (kit / "compile-plan.json").write_text(json.dumps(plan))
        if forbidden:
            (kit / forbidden).write_text("Synthetic forbidden-name fixture, no game bytes.")
        archive = root / "synthetic-python.zip"
        with zipfile.ZipFile(archive, "w") as output:
            output.writestr("python.exe", b"Synthetic manifest fixture; never executed.")
        digest = hashlib.sha256(archive.read_bytes()).hexdigest()
        with patch.object(seal_kit, "PYTHON_SHA256", digest):
            seal_kit.seal(kit, archive)
        return json.loads((kit / "build-kit.json").read_text())

    def test_existing_file1_plan_retains_its_supported_elf(self):
        with tempfile.TemporaryDirectory() as directory:
            result = self.seal_fixture(directory)
        self.assertEqual(result["elfSha256"], "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46")

    def test_file2_plan_seals_with_file2_elf_and_private_build_worker(self):
        with tempfile.TemporaryDirectory() as directory:
            result = self.seal_fixture(directory, "file2", "5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d")
        self.assertEqual(result["elfSha256"], "5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d")
        self.assertEqual(result["outputs"], ["reo_recomp.exe"])
        self.assertEqual(result["steps"][0]["tool"], "tools/python/python.exe")

    def test_mixed_game_profile_cannot_be_sealed(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaisesRegex(ValueError, "matching ELF"):
                self.seal_fixture(directory, "file2", "06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46")
            self.assertFalse((Path(directory) / "kit/build-kit.json").exists())

    def test_file2_game_executable_cannot_enter_public_inputs(self):
        with tempfile.TemporaryDirectory() as directory:
            with self.assertRaisesRegex(ValueError, "private/game-derived"):
                self.seal_fixture(directory, "file2", forbidden="reo_recomp_file2.exe")
            self.assertFalse((Path(directory) / "kit/build-kit.json").exists())


if __name__ == "__main__":
    unittest.main()
