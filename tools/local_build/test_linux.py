import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import sys
import tempfile
import unittest
from unittest.mock import patch

from compile_linux import compile_plan
from import_iso import import_iso

sys.path.insert(0, str(Path(__file__).resolve().parents[2] / "launcher/linux"))
from core import game_environment, inside, native_elf, output_hashes, verify_kit


class LinuxPortableTests(unittest.TestCase):
    def setUp(self):
        self.temp = tempfile.TemporaryDirectory()
        self.addCleanup(self.temp.cleanup)
        self.root = Path(self.temp.name)

    def iso(self, unsafe=False):
        image = bytearray(26 * 2048)

        def entry(name, lba, size, flags=0):
            record = bytearray(33 + len(name) + (len(name) % 2 == 0))
            record[0], record[25], record[32] = len(record), flags, len(name)
            struct.pack_into("<I", record, 2, lba)
            struct.pack_into("<I", record, 10, size)
            record[33:33 + len(name)] = name
            return record

        executable = b"synthetic-owned-elf-no-game-code"
        pvd = memoryview(image)[16 * 2048:17 * 2048]
        pvd[:7] = b"\x01CD001\x01"
        struct.pack_into("<H", pvd, 128, 2048)
        pvd[156:190] = entry(b"\x00", 20, 2048, 2)
        records = (entry(b"\x00", 20, 2048, 2) + entry(b"\x01", 20, 2048, 2) +
                   entry(b"../escape;1" if unsafe else b"SLUS_207.65;1", 21, len(executable)))
        image[20 * 2048:20 * 2048 + len(records)] = records
        image[21 * 2048:21 * 2048 + len(executable)] = executable
        path = self.root / "owned.iso"
        path.write_bytes(image)
        return path, executable

    def test_iso_is_imported_and_reverified_without_mount(self):
        iso, executable = self.iso()
        with patch("import_iso.ELF_SHA256", hashlib.sha256(executable).hexdigest()):
            data = import_iso(iso, self.root / "cache")
            self.assertEqual((data / "SLUS_207.65").read_bytes(), executable)
            self.assertEqual(import_iso(iso, self.root / "cache"), data)
            (data / "SLUS_207.65").write_bytes(b"tampered")
            with self.assertRaisesRegex(ValueError, "verification"):
                import_iso(iso, self.root / "cache")

    def test_iso_traversal_is_rejected(self):
        iso, _ = self.iso(unsafe=True)
        with self.assertRaisesRegex(ValueError, "Unsafe"):
            import_iso(iso, self.root / "cache")
        self.assertFalse((self.root / "escape").exists())

    def test_wrong_game_revision_is_not_admitted(self):
        iso, _ = self.iso()
        with self.assertRaisesRegex(ValueError, "revision"):
            import_iso(iso, self.root / "cache")
        self.assertFalse(list((self.root / "cache").glob("*/import.json")))

    def test_kit_paths_cannot_escape(self):
        for name in ("../out", "/root", "a/../b", "a\\b", "C:/bad", "./tool"):
            with self.subTest(name=name), self.assertRaises(ValueError):
                inside(self.root, name)

    def test_windows_kit_is_refused(self):
        (self.root / "build-kit.json").write_text(json.dumps({"format": 1, "architecture": "win-x64"}))
        with self.assertRaisesRegex(ValueError, "linux-x64"):
            verify_kit(self.root)

    def test_native_game_output_is_required(self):
        (self.root / "reo_recomp").write_bytes(b"MZ-not-a-Linux-game")
        with self.assertRaisesRegex(ValueError, "native Linux"):
            output_hashes(self.root, ["reo_recomp"])

    def test_environment_matches_windows_launcher_baseline(self):
        windows = (Path(__file__).resolve().parents[2] / "launcher/GameSession.cs").read_text(encoding="utf-8")
        environment = game_environment(self.root / "owned.iso", {})
        for name in ("REO_NATURAL", "REO_TURBO", "REO_GS_BACKEND", "REO_GS_THREAD", "REO_GS_GPU_PRESENT",
                     "REO_GS_DISPATCH_PACE", "REO_GS_SPRITE_DEPTH_PARALLEL", "REO_VIF1_GPU_RESIDENT"):
            self.assertIn(f'Set("{name}", "{environment[name]}")', windows)

    def test_debug_environment_does_not_leak_into_game(self):
        with patch.dict(os.environ, {"REO_TEST_ROUTE": "unsafe-test", "REO_FORCE_BAD": "1"}):
            env = game_environment(self.root / "owned.iso", {"Brightness": 110, "Gamma": 1.2})
        self.assertNotIn("REO_TEST_ROUTE", env)
        self.assertNotIn("REO_FORCE_BAD", env)
        self.assertEqual(env["REO_BRIGHTNESS"], "1.10")
        self.assertEqual(env["REO_GAMMA"], "1.20")

    def test_display_defaults_and_invalid_values_match_windows(self):
        defaults = game_environment(self.root / "owned.iso", {})
        self.assertEqual((defaults["REO_WINDOW_WIDTH"], defaults["REO_WINDOW_HEIGHT"]), ("1024", "768"))
        invalid = game_environment(self.root / "owned.iso", {"ScreenFit": "invalid", "AspectRatio": "invalid",
            "Anisotropy": 3, "Gamma": float("nan"), "Brightness": 200, "AntiAliasing": False})
        self.assertEqual(invalid["REO_DISPLAY_FIT"], "fit")
        self.assertEqual(invalid["REO_DISPLAY_ASPECT"], "4:3")
        self.assertEqual(invalid["REO_TEXTURE_ANISOTROPY"], "1")
        self.assertEqual(invalid["REO_GAMMA"], "1.00")
        self.assertEqual(invalid["REO_BRIGHTNESS"], "1.50")
        self.assertEqual(invalid["REO_POST_AA"], "off")

    @unittest.skipUnless(sys.platform == "linux", "Native compile/link/cache integration runs on Linux CI")
    def test_real_native_compilation_archive_link_and_cache(self):
        compiler, archiver = shutil.which("clang++"), shutil.which("llvm-ar")
        if not compiler or not archiver:
            self.skipTest("Clang and llvm-ar are required")
        kit, generated, work, output = [self.root / name for name in ("kit", "generated", "work", "output")]
        kit.mkdir()
        generated.mkdir()
        for source, name in ((compiler, "clang++"), (archiver, "llvm-ar")):
            shutil.copyfile(Path(source).resolve(), kit / name)
            (kit / name).chmod(0o755)
        (generated / "main.cpp").write_text("int helper(); int main() { return helper() != 42; }")
        (generated / "helper.cpp").write_text("int helper() { return 42; }")
        plan = {"format": 1, "architecture": "linux-x64", "runtimeAbi": "synthetic-test",
                "compiler": "{kit}/clang++", "archiver": "{kit}/llvm-ar",
                "units": [{"id": "main", "sources": ["{generated}/main.cpp"]},
                          {"id": "helper", "sources": ["{generated}/helper.cpp"], "archive": "runtime"}]}
        (kit / "compile-plan-linux.json").write_text(json.dumps(plan))
        compile_plan(kit, generated, work, output, 2)
        self.assertTrue(native_elf(output / "reo_recomp"))
        subprocess.run([str(output / "reo_recomp")], check=True)
        first = (work / "linux-objects/main.o").stat().st_mtime_ns
        compile_plan(kit, generated, work, output, 2)
        self.assertEqual((work / "linux-objects/main.o").stat().st_mtime_ns, first)
        (work / "linux-objects/main.json").write_text('[]')
        compile_plan(kit, generated, work, output, 2)
        self.assertNotEqual((work / "linux-objects/main.o").stat().st_mtime_ns, first)
        subprocess.run([str(output / "reo_recomp")], check=True)


if __name__ == "__main__":
    unittest.main()
