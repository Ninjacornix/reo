"""Offscreen launcher checks; no proprietary image, ISO or GPU required."""
import os
from pathlib import Path
import tempfile
import unittest
from unittest.mock import patch

os.environ.setdefault("QT_QPA_PLATFORM", "offscreen")
from PySide6.QtWidgets import QApplication
from main import Launcher


class LauncherTests(unittest.TestCase):
    @classmethod
    def setUpClass(cls):
        cls.application = QApplication.instance() or QApplication([])

    def test_pages_and_preview_cannot_launch_without_native_kit(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            with patch("main.locations", return_value=(root / "data", root / "config", root / "missing-kit")):
                window = Launcher()
                self.assertEqual(window.windowTitle(), "RE: Outbreak")
                self.assertEqual(window.pages.count(), window.navigation.count())
                self.assertFalse(window.play.isEnabled())
                for index in range(window.pages.count()):
                    window.navigation.setCurrentRow(index)
                    self.assertEqual(window.pages.currentIndex(), index)
                window.set_value("Gamma", 1.2)
                window.close()
                another = Launcher()
                self.assertEqual(another.settings["Gamma"], 1.2)
                another.close()


if __name__ == "__main__":
    unittest.main()
