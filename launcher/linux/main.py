"""Native Qt launcher for the Linux portable build."""

import json
import os
from pathlib import Path
import sys
import time

from PySide6.QtCore import QThread, Signal, QUrl
from PySide6.QtGui import QDesktopServices
from PySide6.QtWidgets import (QApplication, QCheckBox, QComboBox, QFileDialog, QFormLayout,
    QHBoxLayout, QLabel, QLineEdit, QListWidget, QMainWindow, QMessageBox, QPlainTextEdit,
    QProgressBar, QPushButton, QSlider, QStackedWidget, QVBoxLayout, QWidget)
from PySide6.QtCore import Qt

from core import RESOLUTIONS, Session, game_environment, resolution


def locations():
    home = Path(os.environ.get("XDG_DATA_HOME", str(Path.home() / ".local/share"))) / "OutbreakRecomp/launcher"
    config = Path(os.environ.get("XDG_CONFIG_HOME", str(Path.home() / ".config"))) / "OutbreakRecomp"
    if getattr(sys, "frozen", False):
        root = Path(sys.executable).resolve().parent
    else:
        root = Path(__file__).resolve().parents[1]
    return home, config, root / "build-kit"


class Worker(QThread):
    message = Signal(str)
    failed = Signal(str)
    phase = Signal(str)

    def __init__(self, session, kit, home, settings):
        super().__init__()
        self.session, self.kit, self.home, self.settings = session, kit, home, settings

    def run(self):
        try:
            self.phase.emit("Preparing game")
            executable, disc = self.session.prepare(self.kit, self.settings["Iso"], self.home, self.message.emit)
            work = self.home / "sessions" / time.strftime("%Y%m%d-%H%M%S")
            work.mkdir(parents=True, exist_ok=False)
            self.phase.emit("Running")
            card = self.home / "memory-cards/default/file1/data"
            card.mkdir(parents=True, exist_ok=True)
            environment = game_environment(self.settings["Iso"], self.settings)
            environment.update({"REO_MC0_ROOT": str(card), "REO_MC1_ROOT": ":none:"})
            from core import cache_lock
            with cache_lock(card.parent / "launcher.lock"):
                self.session.run([str(executable), "--game", "file1", "--elf", str(disc / "SLUS_207.65"),
                                  "--data", str(disc)], work, environment, self.message.emit, work / "game.log")
        except Exception as error:
            self.failed.emit(str(error))


class Launcher(QMainWindow):
    def __init__(self):
        super().__init__()
        self.home, self.config, self.kit = locations()
        self.settings = {}
        try:
            self.settings = json.loads((self.config / "settings.json").read_text())
        except (OSError, ValueError):
            pass
        self.worker = None
        self.setWindowTitle("RE: Outbreak")
        self.resize(1000, 690)
        self.setMinimumSize(760, 530)
        outer = QWidget()
        self.setCentralWidget(outer)
        layout = QHBoxLayout(outer)
        self.navigation = QListWidget()
        self.navigation.setFixedWidth(175)
        self.navigation.addItems(["Play", "Graphics", "Save games", "Log"])
        layout.addWidget(self.navigation)
        right = QVBoxLayout()
        layout.addLayout(right, 1)
        self.pages = QStackedWidget()
        right.addWidget(self.pages, 1)
        self.status = QLabel("Choose your ISO to begin.")
        self.status.setWordWrap(True)
        right.addWidget(self.status)
        self.progress = QProgressBar()
        self.progress.setRange(0, 0)
        self.progress.hide()
        right.addWidget(self.progress)
        actions = QHBoxLayout()
        right.addLayout(actions)
        actions.addStretch()
        self.stop = QPushButton("Stop")
        self.stop.setEnabled(False)
        self.stop.clicked.connect(self.cancel)
        actions.addWidget(self.stop)
        self.play = QPushButton("Play")
        self.play.setDefault(True)
        self.play.clicked.connect(self.start)
        actions.addWidget(self.play)
        self.build_play()
        self.build_graphics()
        self.build_saves()
        self.log = QPlainTextEdit()
        self.log.setReadOnly(True)
        self.log.setMaximumBlockCount(6000)
        self.pages.addWidget(self.log)
        self.navigation.currentRowChanged.connect(self.pages.setCurrentIndex)
        self.navigation.setCurrentRow(0)
        self.setStyleSheet("""
            QMainWindow, QWidget { background: #14181c; color: #e2e5e8; }
            QWidget { font-size: 14px; }
            QListWidget { border: 0; background: #101316; padding: 12px 4px; }
            QListWidget::item { padding: 14px 12px; }
            QListWidget::item:selected { background: #32383d; border-radius: 5px; }
            QPushButton, QLineEdit, QComboBox { padding: 9px 12px; border: 1px solid #444c54;
                border-radius: 5px; background: #22282e; }
            QPushButton:hover { background: #343d45; }
            QPushButton:disabled { color: #7e858c; }
            QPlainTextEdit { background: #101316; border: 0; font-family: monospace; }
        """)
        if not (self.kit / "build-kit.json").exists():
            self.status.setText("Development preview — a validated native Linux build kit is not included yet.")
            self.play.setEnabled(False)

    def page(self, heading):
        widget = QWidget()
        box = QVBoxLayout(widget)
        box.setContentsMargins(24, 16, 24, 16)
        title = QLabel(heading)
        title.setStyleSheet("font-size: 25px; font-weight: 600; padding-bottom: 16px")
        box.addWidget(title)
        self.pages.addWidget(widget)
        return box

    def build_play(self):
        box = self.page("Play")
        box.addWidget(QLabel("Outbreak (File #1)"))
        row = QHBoxLayout()
        self.iso = QLineEdit(self.settings.get("Iso", ""))
        self.iso.setPlaceholderText("Select your NTSC-U v2.00 ISO")
        self.iso.editingFinished.connect(lambda: self.set_value("Iso", self.iso.text()))
        row.addWidget(self.iso, 1)
        select = QPushButton("Browse…")
        select.clicked.connect(self.select_iso)
        row.addWidget(select)
        box.addLayout(row)
        self.check(box, "Skip logos", "SkipIntros", False)
        box.addSpacing(24)
        unavailable = QLabel("Outbreak File #2 — not available")
        unavailable.setEnabled(False)
        box.addWidget(unavailable)
        box.addStretch()

    def set_value(self, key, value):
        self.settings[key] = value
        self.config.mkdir(parents=True, exist_ok=True)
        pending = self.config / "settings.pending"
        pending.write_text(json.dumps(self.settings, indent=2), encoding="utf-8")
        pending.replace(self.config / "settings.json")

    def check(self, layout, label, key, default):
        check = QCheckBox(label)
        check.setChecked(self.settings.get(key, default))
        check.toggled.connect(lambda value: self.set_value(key, value))
        layout.addWidget(check)

    def combo(self, form, label, key, values, default):
        control = QComboBox()
        control.addItems(values)
        control.setCurrentText(str(self.settings.get(key, default)))
        control.currentTextChanged.connect(lambda value: self.set_value(key, int(value) if key == "Anisotropy" else value))
        form.addRow(label, control)

    def build_graphics(self):
        box = self.page("Graphics")
        form = QFormLayout()
        form.setVerticalSpacing(18)
        box.addLayout(form)
        self.combo(form, "Resolution", "Resolution", list(RESOLUTIONS), resolution(self.settings))
        self.combo(form, "Aspect ratio", "AspectRatio", ["4:3", "16:9"], "4:3")
        self.combo(form, "Screen fit", "ScreenFit", ["fit", "center", "stretch", "fill"], "fit")
        self.combo(form, "Anti-aliasing", "AntiAliasingMode", ["off", "fxaa", "smaa"], "fxaa")
        self.combo(form, "Anisotropic filtering", "Anisotropy", ["1", "2", "4", "8", "16"], "1")
        for label, key, low, high, default, scale in (("Brightness", "Brightness", 50, 150, 100, 1),
                                                     ("Gamma", "Gamma", 50, 200, 100, 100)):
            slider = QSlider(Qt.Orientation.Horizontal)
            slider.setRange(low, high)
            slider.setValue(int(self.settings.get(key, default / scale) * scale))
            slider.valueChanged.connect(lambda value, k=key, s=scale: self.set_value(k, value / s))
            form.addRow(label, slider)
        self.check(box, "Smooth display scaling", "LinearFilter", True)
        self.check(box, "Linear texture filtering", "TextureLinear", False)
        self.check(box, "Asynchronous geometry", "AsyncVif", True)
        box.addStretch()

    def build_saves(self):
        box = self.page("Save games")
        box.addWidget(QLabel("Memory cards remain separate from the application and game-build cache."))
        open_folder = QPushButton("Open save folder")
        open_folder.clicked.connect(self.open_saves)
        box.addWidget(open_folder, alignment=Qt.AlignmentFlag.AlignLeft)
        box.addStretch()

    def open_saves(self):
        saves = self.home / "memory-cards/default/file1/data"
        saves.mkdir(parents=True, exist_ok=True)
        QDesktopServices.openUrl(QUrl.fromLocalFile(str(saves)))

    def select_iso(self):
        name, _ = QFileDialog.getOpenFileName(self, "Choose game ISO", self.iso.text(), "ISO images (*.iso);;All files (*)")
        if name:
            self.iso.setText(name)
            self.set_value("Iso", name)

    def start(self):
        if self.worker is not None:
            return
        self.set_value("Iso", self.iso.text())
        if not Path(self.iso.text()).is_file():
            QMessageBox.warning(self, "Game files", "Choose an existing ISO image.")
            return
        self.worker = Worker(Session(), self.kit, self.home, dict(self.settings))
        self.worker.message.connect(self.log.appendPlainText)
        self.worker.phase.connect(self.status.setText)
        self.worker.failed.connect(self.failure)
        self.worker.finished.connect(self.finished)
        self.play.setEnabled(False)
        self.pages.setEnabled(False)
        self.stop.setEnabled(True)
        self.progress.show()
        self.worker.start()

    def cancel(self):
        if self.worker is not None:
            self.worker.session.cancel()
            self.status.setText("Stopping…")

    def failure(self, text):
        self.log.appendPlainText(text)
        self.status.setText(text)
        self.navigation.setCurrentRow(3)

    def finished(self):
        self.worker.deleteLater()
        self.worker = None
        self.play.setEnabled(True)
        self.pages.setEnabled(True)
        self.stop.setEnabled(False)
        self.progress.hide()

    def closeEvent(self, event):
        if self.worker is not None:
            self.cancel()
            event.ignore()
        else:
            event.accept()


if __name__ == "__main__":
    application = QApplication(sys.argv)
    window = Launcher()
    window.show()
    raise SystemExit(application.exec())
