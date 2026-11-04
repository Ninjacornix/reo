"""Portable worker game selection and original-runtime queue safety."""
import hashlib
import json
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

from build_game import build, game_profile
from generate_game import GAMES, prepare_recipe_sources
from generate_queue_control import generate as queue


class GameProfileTests(unittest.TestCase):
    def setUp(self):
        self.directory = tempfile.TemporaryDirectory(prefix="reo-game-profile-")
        self.addCleanup(self.directory.cleanup)
        self.root = Path(self.directory.name)
        self.kit = self.root / "kit"
        self.kit.mkdir()

    def plan(self, data):
        (self.kit / "compile-plan.json").write_text(json.dumps(data))

    def test_legacy_kit_remains_file1(self):
        self.plan({"format": 1})
        game, profile = game_profile(self.kit)
        self.assertEqual((game, profile["elf"]), ("file1", "SLUS_207.65"))

    def test_file2_uses_its_pinned_elf(self):
        self.plan({"game": "file2", "elfSha256": GAMES["file2"]["sha256"]})
        game, profile = game_profile(self.kit, "file2")
        self.assertEqual((game, profile["elf"]), ("file2", "SLUS_209.84"))

    def test_cross_game_and_unknown_profiles_fail_closed(self):
        self.plan({"game": "file2"})
        with self.assertRaisesRegex(ValueError, "differs"):
            game_profile(self.kit, "file1")
        self.plan({"game": "unknown"})
        with self.assertRaisesRegex(ValueError, "differs"):
            game_profile(self.kit)

    def test_wrong_elf_revision_cannot_select_another_game(self):
        self.plan({"game": "file2", "elfSha256": GAMES["file1"]["sha256"]})
        with self.assertRaisesRegex(ValueError, "disagree"):
            game_profile(self.kit)

    def test_worker_passes_file2_to_generation_without_file1_inputs(self):
        self.plan({"game": "file2", "elfSha256": GAMES["file2"]["sha256"]})
        disc = self.root / "disc"
        disc.mkdir()
        (disc / "SLUS_209.84").write_bytes(b"Synthetic worker fixture, generator is mocked")
        metadata = self.kit / "metadata"
        metadata.mkdir()
        for name in ("local_source_recipes.json", "local_queue_control.json", "local_vu_images.json"):
            (metadata / name).write_text("{}")
        (self.kit / "source").mkdir()
        (self.kit / "tools").mkdir()
        (self.kit / "tools/ps2_recomp.exe").write_bytes(b"Never executed")
        for name in ("generate.py", "decode.py"):
            target = self.kit / "tools/vu_whole_aot" / name
            target.parent.mkdir(exist_ok=True)
            target.write_text("# Not executed")
        observed = []

        def generate(recompiler, selected_disc, selected_metadata, output, *, jobs, game):
            observed.append(game)
            self.assertEqual(selected_disc, disc.resolve())
            (output / "output").mkdir(parents=True)
            (output / "output/generated.cpp").write_text("// synthetic generated source")
            (output / "local_source_catalogues").mkdir()

        def vu(elf, recipe, output):
            self.assertEqual(elf.name, "SLUS_209.84")
            output.mkdir()
            (output / "image.bin").write_bytes(b"Synthetic VU output")

        with patch("build_game.sys.platform", "win32"), \
             patch("build_game.extended", side_effect=lambda p: Path(p).resolve()), \
             patch("build_game.msvc_environment", return_value=({"VCToolsRedistDir": str(self.root)}, "cl", "lib")), \
             patch("build_game.generate", side_effect=generate), \
             patch("build_game.apply_plan"), patch("build_game.generate_queue_control"), \
             patch("build_game.reconstruct", side_effect=vu), \
             patch("build_game.subprocess.run"), patch("build_game.compile_plan") as compile_plan:
            build(self.kit, disc, self.root / "work", self.root / "output", 1)
            self.assertEqual(observed, ["file2"])
            self.assertEqual(compile_plan.call_count, 1)

    def queue_fixture(self, mode="original-runtime-only", game="file2", blocks=None):
        elf = self.root / "synthetic.elf"
        elf.write_bytes(b"Synthetic profile fixture; no original instructions")
        plan = self.root / "queue.json"
        plan.write_text(json.dumps({"format": 1, "elfSha256": hashlib.sha256(elf.read_bytes()).hexdigest(),
                                    "mode": mode, "game": game, "blocks": [] if blocks is None else blocks}))
        return elf, plan, self.root / "generated/queue.inc"

    def test_original_runtime_profile_emits_only_a_rejection(self):
        elf, plan, output = self.queue_fixture()
        self.assertEqual(queue(elf, plan, output), 0)
        source = output.read_text()
        self.assertIn("throw std::invalid_argument", source)
        self.assertNotIn("tick(", source)
        self.assertNotIn("set64(", source)

    def test_original_runtime_mode_rejects_other_games_and_instruction_claims(self):
        for game, blocks in (("file1", []), ("file2", [{"pc": 0x100000, "sites": [0x100000]}])):
            elf, plan, output = self.queue_fixture(game=game, blocks=blocks)
            with self.assertRaisesRegex(ValueError, "Invalid original-runtime"):
                queue(elf, plan, output)
            self.assertFalse(output.exists())

    def test_queue_mode_and_elf_identity_are_checked_before_output(self):
        elf, plan, output = self.queue_fixture(mode="unknown")
        with self.assertRaisesRegex(ValueError, "mode"):
            queue(elf, plan, output)
        self.assertFalse(output.exists())
        elf, plan, output = self.queue_fixture()
        elf.write_bytes(b"Changed fixture")
        with self.assertRaisesRegex(ValueError, "ELF"):
            queue(elf, plan, output)
        self.assertFalse(output.exists())

    def test_plain_movie_recipe_uses_plain_local_body_without_audit_regeneration(self):
        ordinary = self.root / "output/plain.cpp"
        ordinary.parent.mkdir()
        ordinary.write_text("void synthetic() { ordinary_call(); }\n")
        passes = prepare_recipe_sources(self.root, [{"source": "output/plain.cpp", "sourceAudit": False},
                                                    {"source": "output/audited.cpp"}])
        self.assertEqual(passes, {"main": {Path("output/audited.cpp")}})
        self.assertEqual((self.root / "audit_sources/output/plain.cpp").read_text(), ordinary.read_text())

    def test_recipe_sources_reject_escaping_paths_and_conflicting_modes(self):
        for source in ("../outside.cpp", "output/../../outside.cpp", "unsupported/helper.cpp"):
            with self.assertRaises(ValueError):
                prepare_recipe_sources(self.root, [{"source": source, "sourceAudit": False}])
        ordinary = self.root / "output/plain.cpp"
        ordinary.parent.mkdir()
        ordinary.write_text("// synthetic\n")
        with self.assertRaisesRegex(ValueError, "Conflicting"):
            prepare_recipe_sources(self.root, [{"source": "output/plain.cpp", "sourceAudit": False},
                                               {"source": "output/plain.cpp", "sourceAudit": True}])


if __name__ == "__main__":
    unittest.main()
