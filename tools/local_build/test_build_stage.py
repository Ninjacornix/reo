from pathlib import Path
import tempfile
import unittest

from build_game import stage


class StageCacheTests(unittest.TestCase):
    def test_removed_unused_inputs_preserve_verified_output(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            source, unused, output = root / "input", root / "unused", root / "output"
            source.write_text("source")
            unused.write_text("not used by the action")
            calls = []

            def action():
                calls.append(1)
                output.write_text(source.read_text())

            stage(root, "generate", [source, unused], action, lambda: [output])
            unused.write_text("changed")
            stage(root, "generate", [source], action, lambda: [output])
            self.assertEqual(len(calls), 1)
            source.write_text("new source")
            stage(root, "generate", [source], action, lambda: [output])
            self.assertEqual(len(calls), 2)
            output.write_text("damaged")
            stage(root, "generate", [source], action, lambda: [output])
            self.assertEqual(output.read_text(), "new source")
            self.assertEqual(len(calls), 3)


if __name__ == "__main__":
    unittest.main()
