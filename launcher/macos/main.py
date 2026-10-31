#!/usr/bin/env python3
"""Native macOS desktop launcher. Qt is bundled in the standalone application."""
import copy
import json
import os
from pathlib import Path
import runpy
import sys
import time

# Frozen children dispatch before initializing Qt, and own only their service.
if len(sys.argv) >= 3 and sys.argv[1] == '--server-worker':
    from server_worker import run
    run(Path(sys.argv[2]),sys.argv[3:])
    raise SystemExit

from PySide6.QtCore import Qt, QThread, Signal, QTimer, QUrl
from PySide6.QtGui import QDesktopServices, QIcon
from PySide6.QtWidgets import (QApplication, QMainWindow, QWidget, QVBoxLayout, QHBoxLayout,
    QFormLayout, QLabel, QPushButton, QListWidget, QListWidgetItem, QStackedWidget,
    QLineEdit, QComboBox, QCheckBox, QSpinBox, QDoubleSpinBox, QSlider, QPlainTextEdit,
    QFileDialog, QMessageBox, QInputDialog, QScrollArea, QProgressBar, QGroupBox)
from core import Store, Session, CHEATS, RESOLUTIONS, KEY_DEFAULTS, PAD_NAMES, ROOT, atomic_json
import mods
from services import HostedServer, discover, host_randomizers, fetch_randomizers, shared_randomizer_manifests


class Work(QThread):
    line = Signal(str)
    done = Signal(object, str)
    def __init__(self, action):
        super().__init__()
        self.action = action
    def run(self):
        last = 0
        def report(value):
            nonlocal last
            now = time.monotonic()
            if now-last >= .05:
                self.line.emit(value)
                last = now
        try:
            self.done.emit(self.action(report), '')
        except Exception as error:
            self.done.emit(None, str(error))


class KeyCapture(QPushButton):
    changed = Signal(int)
    def __init__(self, code):
        super().__init__()
        self.code, self.waiting = code, False
        self.clicked.connect(self.capture)
        self.update_label()
    def update_label(self):
        labels = {0:'A',1:'S',2:'D',6:'Z',7:'X',12:'Q',13:'W',14:'E',15:'R',18:'1',19:'2',20:'3',21:'4',
                  36:'Return',49:'Space',51:'Delete',53:'Escape',123:'←',124:'→',125:'↓',126:'↑'}
        self.setText(labels.get(self.code, f'Key {self.code}') + ' · change')
    def capture(self):
        self.waiting = True
        self.setText('Press a key…')
        self.setFocus()
    def keyPressEvent(self, event):
        if self.waiting:
            code = event.nativeVirtualKey()
            if 0 <= code < 256:
                self.code, self.waiting = int(code), False
                self.update_label()
                self.changed.emit(self.code)
            event.accept()
        else:
            super().keyPressEvent(event)
    def focusOutEvent(self, event):
        self.waiting = False
        self.update_label()
        super().focusOutEvent(event)


class Window(QMainWindow):
    def __init__(self, store=None):
        super().__init__()
        self.store = store or Store()
        self.session = None
        self.worker = None
        self.server = HostedServer(self.store)
        self.widgets = {}
        self.setWindowTitle('RE Outbreak · RC1 for Mac')
        icon=self.store.resources/'artwork/app-icon.png'
        if not icon.is_file():icon=ROOT/'launcher/Assets/app-icon.png'
        if icon.is_file():self.setWindowIcon(QIcon(str(icon)))
        self.resize(1080, 760)
        base = QWidget(); self.setCentralWidget(base)
        layout = QVBoxLayout(base)
        header = QHBoxLayout()
        brand = QLabel('RESIDENT EVIL  OUTBREAK')
        brand.setStyleSheet('font-size: 24px; font-weight: 700; letter-spacing: 2px')
        header.addWidget(brand); header.addStretch()
        header.addWidget(QLabel('RC1  •  Apple Silicon  •  Metal'))
        layout.addLayout(header)
        body = QHBoxLayout(); layout.addLayout(body,1)
        self.navigation = QListWidget(); self.navigation.setFixedWidth(180)
        self.stack = QStackedWidget()
        body.addWidget(self.navigation); body.addWidget(self.stack,1)
        self.navigation.currentRowChanged.connect(self.stack.setCurrentIndex)
        self.play_page(); self.graphics_page(); self.audio_page(); self.controls_page()
        self.saves_page(); self.mods_page(); self.coop_page(); self.files_page(); self.developer_page(); self.logs_page()
        self.navigation.setCurrentRow(0)
        footer = QHBoxLayout()
        self.status = QLabel('Ready'); self.status.setWordWrap(True)
        footer.addWidget(self.status,1)
        self.progress = QProgressBar(); self.progress.setRange(0,0); self.progress.hide(); self.progress.setMaximumWidth(120)
        footer.addWidget(self.progress)
        self.stop_button = QPushButton('Stop'); self.stop_button.setEnabled(False)
        self.stop_button.clicked.connect(self.stop_job)
        self.play_button = QPushButton('Play File #1'); self.play_button.setMinimumWidth(150)
        self.play_button.setStyleSheet('background: #9e252e; color: white; padding: 9px; font-weight: bold')
        self.play_button.clicked.connect(self.play)
        footer.addWidget(self.stop_button); footer.addWidget(self.play_button)
        layout.addLayout(footer)
        self.timer = QTimer(self); self.timer.timeout.connect(self.check_server); self.timer.start(2000)

    def page(self, title, description):
        content = QWidget(); outer = QVBoxLayout(content)
        heading = QLabel(title); heading.setStyleSheet('font-size: 23px; font-weight: 600')
        outer.addWidget(heading)
        label = QLabel(description); label.setWordWrap(True); outer.addWidget(label)
        form = QFormLayout(); form.setFieldGrowthPolicy(QFormLayout.FieldGrowthPolicy.AllNonFixedFieldsGrow)
        outer.addLayout(form)
        outer.addStretch()
        scroll = QScrollArea(); scroll.setWidgetResizable(True); scroll.setWidget(content)
        self.stack.addWidget(scroll); self.navigation.addItem(title)
        return form, outer

    def change(self, key, value):
        self.store.settings[key] = value
        self.store.save()
        if self.session and (key.endswith('Volume') or key == 'ShowSubtitles'):
            self.session.live_settings(self.store.settings)

    def combo(self, form, label, key, values):
        widget = QComboBox()
        for entry in values:
            title, value = entry if isinstance(entry, tuple) else (str(entry), entry)
            widget.addItem(title, value)
        index = widget.findData(self.store.settings[key])
        widget.setCurrentIndex(max(0,index))
        widget.currentIndexChanged.connect(lambda _: self.change(key,widget.currentData()))
        form.addRow(label,widget); self.widgets[key] = widget
        return widget

    def check(self, form, label, key):
        widget = QCheckBox(label); widget.setChecked(bool(self.store.settings[key]))
        widget.toggled.connect(lambda value:self.change(key,value))
        form.addRow(widget); self.widgets[key]=widget
        return widget

    def number(self, form, label, key, low, high, decimal=False):
        widget = QDoubleSpinBox() if decimal else QSpinBox()
        widget.setRange(low,high)
        if decimal: widget.setSingleStep(.05)
        widget.setValue(self.store.settings[key]); widget.valueChanged.connect(lambda value:self.change(key,value))
        form.addRow(label,widget); self.widgets[key]=widget
        return widget

    def text(self, form, label, key):
        widget = QLineEdit(str(self.store.settings[key]))
        widget.editingFinished.connect(lambda:self.change(key,widget.text().strip()))
        form.addRow(label,widget); self.widgets[key]=widget
        return widget

    def button(self, form, text, action):
        widget=QPushButton(text); widget.clicked.connect(lambda:self.guard(action))
        form.addRow(widget); return widget

    def guard(self, action):
        try: action()
        except Exception as error: self.error(str(error))

    def error(self, message):
        self.status.setText(message)
        self.log.appendPlainText('ERROR: '+message)
        QMessageBox.warning(self,'Outbreak',message)

    def play_page(self):
        form,outer = self.page('Play','File #1 · NTSC-U v2.00. Uses your original ISO, native ARM64 game code and MoltenVK on Metal.')
        self.summary=QLabel('Your graphics, controls, audio, memory card and selected offline mods apply when you press Play.')
        self.summary.setWordWrap(True); form.addRow(self.summary)
        self.button(form,'Choose game ISO…',self.choose_iso)
        self.button(form,'Open latest session logs',self.open_latest)
        self.button(form,'Open save folder',lambda:self.open_path(self.store.card()))
        label=QLabel('First-time shader compilation can pause gameplay. Later runs reuse the driver cache.\n'
                     'Audio and subtitles update live. Other settings apply to the next game.\n'
                     'Default controls: WASD, Space (Cross), E (Circle), Q (Square), R (Triangle), Return (Start).')
        label.setWordWrap(True); form.addRow(label)

    def graphics_page(self):
        form,_=self.page('Graphics','Metal presentation with GPU-resident scanout. Higher internal resolution increases GPU load.')
        self.combo(form,'Window resolution','Resolution',list(RESOLUTIONS))
        self.check(form,'Fullscreen','Fullscreen')
        self.combo(form,'Aspect ratio','AspectRatio',['4:3','16:9','21:9','32:9'])
        self.check(form,'Widescreen camera','WidescreenCamera')
        self.combo(form,'Screen fit','ScreenFit',['fit','fill','stretch','center'])
        self.combo(form,'Internal resolution','InternalResolution',[('1× (original)',1),('2×',2),('4×',4)])
        self.combo(form,'Anti-aliasing','AntiAliasingMode',['off','fxaa','smaa'])
        self.combo(form,'Anisotropic filtering','Anisotropy',[1,2,4,8,16])
        self.check(form,'Smooth output scaling','LinearFilter')
        self.check(form,'Linear texture filtering','TextureLinear')
        self.check(form,'Asynchronous VIF processing','AsyncVif')
        self.check(form,'Performance overlay (FPS / game updates)','PerformanceOverlay')
        self.number(form,'Brightness (%)','Brightness',50,150)
        self.number(form,'Gamma','Gamma',.5,2,True)

    def audio_page(self):
        form,_=self.page('Audio','Volume and subtitles update while a game is running. Audio uses the current macOS output device.')
        for label,key in [('Master','MasterVolume'),('Music','MusicVolume'),('Sound effects','SfxVolume'),('Voice','VoiceVolume'),('Interface','UiVolume')]:
            row=QWidget(); line=QHBoxLayout(row); line.setContentsMargins(0,0,0,0)
            slider=QSlider(Qt.Orientation.Horizontal); slider.setRange(0,100); slider.setValue(self.store.settings[key])
            value=QLabel(str(slider.value())); value.setMinimumWidth(32)
            slider.valueChanged.connect(lambda number,k=key,v=value:(v.setText(str(number)),self.change(k,number)))
            line.addWidget(slider); line.addWidget(value); form.addRow(label,row); self.widgets[key]=slider
        self.check(form,'Show subtitles','ShowSubtitles')
        self.button(form,'Open macOS sound settings',lambda:QDesktopServices.openUrl(QUrl('x-apple.systempreferences:com.apple.Sound-Settings.extension')))

    def controls_page(self):
        form,_=self.page('Controls','Connect a controller supported by macOS GameController. Keyboard bindings use macOS hardware key positions.')
        self.combo(form,'Input device','InputDevice',[('Keyboard + first controller','auto'),('Keyboard only','keyboard'),('Controller 1','0'),('Controller 2','1'),('Controller 3','2'),('Controller 4','3')])
        self.number(form,'Stick deadzone (%)','DeadZone',0,30)
        self.check(form,'Controller vibration (supported hardware)','RumbleEnabled')
        for name in PAD_NAMES:
            key=KeyCapture(self.store.settings['Keyboard'][name])
            key.changed.connect(lambda code,n=name:self.set_key(n,code))
            form.addRow(name+' key',key)
        for index,name in enumerate(PAD_NAMES):
            widget=QComboBox(); widget.addItems(PAD_NAMES); widget.setCurrentIndex(self.store.settings['PadMapping'][index])
            widget.currentIndexChanged.connect(lambda value,i=index:self.set_pad(i,value))
            form.addRow(name+' controller source',widget)

    def set_key(self,name,code):
        self.store.settings['Keyboard'][name]=code; self.store.save()
    def set_pad(self,index,value):
        self.store.settings['PadMapping'][index]=value; self.store.save()

    def saves_page(self):
        form,_=self.page('Save games','Each memory card is persistent and locked during gameplay. Restoring a backup creates a separate card.')
        self.card_picker=QComboBox(); self.refresh_cards()
        self.card_picker.currentIndexChanged.connect(lambda _:self.change('MemoryCard',self.card_picker.currentData()))
        form.addRow('Memory card',self.card_picker)
        self.button(form,'New memory card…',self.new_card)
        self.button(form,'Back up selected card…',self.backup)
        self.button(form,'Restore backup as a new card…',self.restore)
        self.button(form,'Open selected card folder',lambda:self.open_path(self.store.card()))
        self.button(form,'Open storage folder',lambda:self.open_path(self.store.home))

    def refresh_cards(self):
        self.card_picker.blockSignals(True); self.card_picker.clear()
        for name,identity,path in self.store.cards(): self.card_picker.addItem(name,identity)
        self.card_picker.setCurrentIndex(max(0,self.card_picker.findData(self.store.settings['MemoryCard'])))
        self.card_picker.blockSignals(False)
    def new_card(self):
        name,ok=QInputDialog.getText(self,'Memory card','Name')
        if ok: self.store.create_card(name); self.refresh_cards()
    def backup(self):
        path,_=QFileDialog.getSaveFileName(self,'Back up memory card',f'Outbreak-{time.strftime("%Y%m%d-%H%M%S")}.zip','ZIP (*.zip)')
        if path: self.store.backup_card(path); self.status.setText('Memory-card backup saved')
    def restore(self):
        path,_=QFileDialog.getOpenFileName(self,'Restore memory-card backup','','ZIP (*.zip)')
        if path:
            self.store.restore_card(path,'Restored '+time.strftime('%Y-%m-%d %H:%M')); self.refresh_cards()

    def mods_page(self):
        form,_=self.page('Cheats & mods','Offline cheats and File #1 JSON manifests. Global randomizers reuse the shared original-asset catalogue code.')
        self.check(form,'Enable cheats','CheatsEnabled')
        for identity,name in CHEATS.items():
            check=QCheckBox(name); check.setChecked(identity in self.store.settings['EnabledCheats'])
            check.toggled.connect(lambda enabled,i=identity:self.select_list('EnabledCheats',i,enabled)); form.addRow(check)
        self.pnach=QListWidget(); self.pnach.setMaximumHeight(95); form.addRow('PNACH files',self.pnach)
        self.refresh_pnach()
        self.button(form,'Add PNACH file…',self.add_pnach)
        self.button(form,'Remove selected PNACH',self.remove_pnach)
        self.mod_list=QListWidget(); self.mod_list.setMinimumHeight(130); form.addRow('Installed mods',self.mod_list)
        self.refresh_mods(); self.mod_list.itemChanged.connect(self.mod_changed)
        self.button(form,'Install mod manifest…',self.install_mod)
        self.button(form,'Open installed mods',lambda:self.open_path(self.store.home/'mods/file1'))

    def select_list(self,key,value,enabled):
        values=list(self.store.settings[key])
        if enabled and value not in values: values.append(value)
        if not enabled and value in values: values.remove(value)
        self.change(key,values)
    def refresh_pnach(self):
        self.pnach.clear(); self.pnach.addItems(self.store.settings['PnachFiles'])
    def add_pnach(self):
        path,_=QFileDialog.getOpenFileName(self,'Choose PNACH','','Cheats (*.pnach)')
        if path:
            from core import pnach_program
            pnach_program([path]); self.select_list('PnachFiles',path,True); self.refresh_pnach()
    def remove_pnach(self):
        item=self.pnach.currentItem()
        if item:self.select_list('PnachFiles',item.text(),False);self.refresh_pnach()
    def refresh_mods(self):
        self.mod_list.blockSignals(True);self.mod_list.clear()
        for path,manifest,error in mods.installed(self.store.home):
            item=QListWidgetItem(manifest['name'] if manifest else path.name+' · '+error)
            if manifest:
                item.setData(Qt.ItemDataRole.UserRole,manifest['id'])
                item.setFlags(item.flags()|Qt.ItemFlag.ItemIsUserCheckable)
                item.setCheckState(Qt.CheckState.Checked if manifest['id'] in self.store.settings['EnabledMods'] else Qt.CheckState.Unchecked)
            self.mod_list.addItem(item)
        self.mod_list.blockSignals(False)
    def mod_changed(self,item):
        self.select_list('EnabledMods',item.data(Qt.ItemDataRole.UserRole),item.checkState()==Qt.CheckState.Checked)
    def install_mod(self):
        path,_=QFileDialog.getOpenFileName(self,'Install mod manifest','','JSON (*.json)')
        if path:mods.install(path,self.store.home);self.refresh_mods()

    def coop_page(self):
        form,_=self.page('Co-op','Host an openSNAP server or connect to an IPv4 host. Credentials are stored in your macOS Keychain; log in through the game Network menu.')
        self.combo(form,'Play mode','CoopMode',['offline','host','join'])
        self.text(form,'Server / advertised IPv4','CoopHost')
        self.text(form,'Player name','Username')
        self.number(form,'Signup TCP port','SignupPort',1024,65535)
        self.number(form,'Game UDP port','GamePort',1024,65535)
        self.host_status=QLabel('Server stopped');self.host_status.setWordWrap(True);form.addRow(self.host_status)
        self.button(form,'Start local server',self.start_server)
        self.button(form,'Stop local server',self.stop_server)
        self.button(form,'Find LAN hosts',self.find_hosts)
        self.host_list=QListWidget();self.host_list.setMaximumHeight(140);form.addRow(self.host_list)
        self.host_list.itemDoubleClicked.connect(self.use_host)
        self.button(form,'Open server logs',lambda:self.open_path(self.store.home/'hosted-server'))
        note=QLabel('Create or join rooms with the game menus. LAN discovery reports the server; room readiness is not inferred.\n'
                    'Hosting beyond your LAN requires reachable UDP 9090/game port and TCP 10127/signup port.\n'
                    'Shared randomizer settings are taken from the host. Mac co-op gameplay still requires multiplayer validation.')
        note.setWordWrap(True);form.addRow(note)

    def start_server(self):
        settings=copy.deepcopy(self.store.settings)
        self.run_job(lambda report:self.server.start(settings,report), 'Starting openSNAP…')
    def stop_server(self):
        self.server.close();self.host_status.setText('Server stopped')
    def check_server(self):
        if self.server.children:
            if any(child.poll() is not None for child in self.server.children):
                self.host_status.setText('A server service stopped. Check server logs.');self.server.close()
            else:self.host_status.setText('Server running · '+self.store.settings['CoopHost'])
    def find_hosts(self):
        self.run_job(lambda report:discover(),'Searching LAN…',self.show_hosts)
    def show_hosts(self,values):
        self.host_list.clear()
        for value in values:
            item=QListWidgetItem(value['name']+' · '+value['address']);item.setData(Qt.ItemDataRole.UserRole,value);self.host_list.addItem(item)
        if not values:self.status.setText('No LAN hosts found')
    def use_host(self,item):
        value=item.data(Qt.ItemDataRole.UserRole)
        for key,data in [('CoopHost',value['address']),('SignupPort',value['signup'])]:
            self.change(key,data)
            widget=self.widgets[key]
            widget.setText(str(data)) if isinstance(widget,QLineEdit) else widget.setValue(data)
        self.widgets['CoopMode'].setCurrentIndex(self.widgets['CoopMode'].findData('join'))

    def files_page(self):
        form,_=self.page('Game files','Import your supported disc, rebuild the native game, or select a Mac build record. No game assets are downloaded.')
        self.iso_label=QLabel(self.store.settings['Iso'] or 'No ISO selected');self.iso_label.setWordWrap(True);form.addRow('ISO',self.iso_label)
        self.button(form,'Choose ISO…',self.choose_iso)
        self.button(form,'Import / verify disc',self.import_disc)
        self.button(form,'Build native game from ISO',self.build_game)
        self.button(form,'Select existing Mac build record…',self.select_build)
        self.number(form,'Build workers','BuildJobs',1,16)
        note=QLabel('Rebuilding requires the source checkout, Xcode Command Line Tools and the dependencies documented in docs/MACOS.md. The bundled game can play without Python or .NET installed.')
        note.setWordWrap(True);form.addRow(note)

    def choose_iso(self):
        path,_=QFileDialog.getOpenFileName(self,'Choose File #1 NTSC-U v2.00 ISO',str(ROOT/'iso'),'Disc image (*.iso)')
        if path:self.change('Iso',path);self.iso_label.setText(path)
    def import_disc(self):
        self.require_idle()
        self.session=Session(self.store);self.run_job(lambda report:str(self.session.import_disc(self.store.settings['Iso'],report)),'Importing disc…')
    def build_game(self):
        self.require_idle()
        self.session=Session(self.store);settings=copy.deepcopy(self.store.settings)
        self.run_job(lambda report:self.session.build(settings,report),'Building native game…')
    def select_build(self):
        path,_=QFileDialog.getOpenFileName(self,'Choose macos-build.json','','JSON (*.json)')
        if path:
            value=json.loads(Path(path).read_text())
            if value.get('format')!=1 or not Path(value.get('executable','')).is_file():raise ValueError('Invalid Mac build record')
            atomic_json(self.store.config_home/'local-build.json',value);self.store.build_record=self.store.locate_build()
            self.status.setText('Mac build selected')

    def developer_page(self):
        form,_=self.page('Diagnostics','Collect timing data to investigate slowdowns. Diagnostic files are saved with each game session.')
        self.check(form,'Frame pacing CSV','FrameTiming');self.check(form,'Original game clock CSV','GameClock')
        self.check(form,'Network transport trace','NetworkTrace')
        self.button(form,'Export diagnostic archive…',self.export_diagnostics)
        self.button(form,'Open validation report',lambda:self.open_path(ROOT/'build-macos/macos-validation.json'))
        label=QLabel('This M2 sustained approximately 30 game updates / 60 display frames per second after shader warmup. MoltenVK parity with a native Metal renderer has not been measured.');label.setWordWrap(True);form.addRow(label)

    def logs_page(self):
        form,_=self.page('Logs','Build, game and server output. Each game keeps its full log in its session folder.')
        self.log=QPlainTextEdit();self.log.setReadOnly(True);self.log.setMinimumHeight(440);self.log.setMaximumBlockCount(2500)
        form.addRow(self.log)
        self.button(form,'Open session folder',self.open_latest)
        self.button(form,'Export diagnostic archive…',self.export_diagnostics)

    def latest(self):
        sessions=self.store.home/'sessions'
        values=sorted(sessions.iterdir()) if sessions.is_dir() else []
        if not values:raise ValueError('No game sessions yet')
        return values[-1]
    def open_latest(self):self.open_path(self.latest())
    def open_path(self,path):
        path=Path(path)
        if not path.exists():raise ValueError('This file or folder does not exist yet: '+str(path))
        QDesktopServices.openUrl(QUrl.fromLocalFile(str(path)))
    def export_diagnostics(self):
        path,_=QFileDialog.getSaveFileName(self,'Export diagnostics','Outbreak-diagnostics.zip','ZIP (*.zip)')
        if not path:return
        import zipfile
        session=self.latest()
        with zipfile.ZipFile(path,'x',zipfile.ZIP_DEFLATED) as archive:
            for item in session.iterdir():
                if item.is_file() and item.suffix in ('.log','.csv','.json') and item.name!='mods.json':
                    archive.write(item,item.name)
            archive.writestr('launcher.json',json.dumps({'platform':'macOS ARM64','settings':{key:self.store.settings[key] for key in ['Resolution','AspectRatio','InternalResolution','AntiAliasingMode','AsyncVif']}}))
        self.status.setText('Diagnostic archive exported')

    def run_job(self,action,title,callback=None):
        self.require_idle()
        self.status.setText(title);self.progress.show();self.play_button.setEnabled(False);self.stop_button.setEnabled(self.session is not None)
        self.worker=Work(action);self.worker.line.connect(self.receive_log)
        def done(value,error):
            self.progress.hide();self.play_button.setEnabled(True);self.stop_button.setEnabled(False)
            self.session=None
            if error:self.error(error)
            else:
                self.status.setText('Ready')
                if callback:callback(value)
        self.worker.done.connect(done);self.worker.start()
    def receive_log(self,line):
        self.log.appendPlainText(line)
        if line:self.status.setText(line[-160:])
    def play(self):self.guard(self.start_play)
    def require_idle(self):
        if self.worker and self.worker.isRunning():raise RuntimeError('Wait for the current operation to finish')
    def start_play(self):
        self.require_idle()
        settings=copy.deepcopy(self.store.settings)
        self.session=Session(self.store)
        def action(report):
            shared=None
            if settings['CoopMode']=='host':
                if not self.server.children:self.server.start(settings,report)
                shared=host_randomizers(settings,self.store.home)
                self.server.randomizers=shared
            elif settings['CoopMode']=='join':
                report('Reading shared randomizers from host…')
                shared=fetch_randomizers(settings)
            if shared:settings['_OnlineMods']=shared_randomizer_manifests(shared)
            try:return self.session.launch(settings,report)
            finally:
                if settings['CoopMode']=='host':self.server.randomizers=None
        self.run_job(action,'Preparing File #1…')
    def stop_job(self):
        if self.session:self.session.cancel();self.status.setText('Stopping; waiting for saves and runtime shutdown…')
    def closeEvent(self,event):
        if self.worker and self.worker.isRunning():
            self.stop_job();self.status.setText('Waiting for the active operation to stop. Close again when finished.');event.ignore();return
        self.server.close();self.store.save();event.accept()


def main():
    app=QApplication(sys.argv)
    app.setApplicationName('RE Outbreak RC1')
    app.setOrganizationName('OutbreakRecomp')
    app.setStyle('Fusion')
    app.setStyleSheet('QMainWindow { background: #17191d; } QWidget { color: #e6e7e9; font-size: 13px; } '
        'QScrollArea, QStackedWidget { border: 0; } QListWidget, QPlainTextEdit, QLineEdit, QComboBox, QSpinBox, QDoubleSpinBox { background: #25282e; color: #e6e7e9; padding: 6px; border: 1px solid #41454e; border-radius: 4px; } '
        'QPushButton { background: #343840; color: #f0f0f0; padding: 7px; border: 1px solid #505661; border-radius: 4px; } '
        'QPushButton:disabled { color: #777; } QListWidget::item { padding: 8px; } QListWidget::item:selected { background: #783039; } '
        'QLabel { background: transparent; } QScrollArea > QWidget > QWidget { background: #1d2025; }')
    try:window=Window()
    except Exception as error:QMessageBox.critical(None,'Outbreak',str(error));return 1
    window.show()
    return app.exec()

if __name__=='__main__':
    if len(sys.argv)>2 and sys.argv[1]=='--verify-bundle':
        from validation import run
        raise SystemExit(run(sys.argv[2:]))
    raise SystemExit(main())
