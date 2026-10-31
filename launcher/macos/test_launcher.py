"""Isolated launcher integration checks; never touch real cards or Keychain."""
import copy
import json
import os
from pathlib import Path
import subprocess
import sys
import tempfile
import threading
import time
import unittest
import zipfile

from core import Store, Session, DEFAULTS, KEY_DEFAULTS, graphics_environment, input_environment, lease, pnach_program
from mods import install, installed, mod_environment
from services import HostedServer, discover, online_environment


class LauncherTests(unittest.TestCase):
    def setUp(self):
        self.temp=tempfile.TemporaryDirectory()
        self.root=Path(self.temp.name)
        self.store=Store(self.root/'config',data_home=self.root/'data')
    def tearDown(self):self.temp.cleanup()

    def test_settings_roundtrip_and_isolation(self):
        self.store.settings['Gamma']=1.25;self.store.save()
        other=Store(self.root/'config',data_home=self.root/'data')
        self.assertEqual(other.settings['Gamma'],1.25)
        other.settings['Keyboard']['UP']=40
        self.assertEqual(DEFAULTS['Keyboard']['UP'],13)

    def test_card_roundtrip_and_lock(self):
        card=self.store.create_card('テスト save')
        (card/'folder').mkdir();(card/'folder/save.bin').write_bytes(bytes(range(256)))
        backup=self.root/'save.zip';self.store.backup_card(backup)
        restored=self.store.restore_card(backup,'Restored')
        self.assertNotEqual(card,restored)
        self.assertEqual((restored/'folder/save.bin').read_bytes(),bytes(range(256)))
        with lease(restored.parent/'.reo-lock'):
            with self.assertRaises(RuntimeError):self.store.backup_card(self.root/'locked.zip')

    def test_unsafe_restore_preserves_selection(self):
        previous=self.store.settings['MemoryCard']
        for name in ('../escape','/absolute','nested/../../escape','a\\b'):
            path=self.root/'unsafe.zip'
            with zipfile.ZipFile(path,'w') as archive:archive.writestr(name,b'x')
            with self.assertRaises(ValueError):self.store.restore_card(path,'Bad')
            self.assertEqual(previous,self.store.settings['MemoryCard'])
        self.assertFalse((self.root/'escape').exists())

    def test_restore_crc_error_is_transactional(self):
        path=self.root/'truncated.zip'
        with zipfile.ZipFile(path,'w',zipfile.ZIP_STORED) as archive:archive.writestr('save',b'original')
        path.write_bytes(path.read_bytes().replace(b'original',b'corrupt!'))
        previous=self.store.settings['MemoryCard']
        with self.assertRaises(zipfile.BadZipFile):self.store.restore_card(path,'Broken')
        self.assertEqual(previous,self.store.settings['MemoryCard'])
        self.assertEqual(len(self.store.cards()),1)

    def test_graphics_and_controller_configuration(self):
        settings=copy.deepcopy(DEFAULTS);settings.update(InternalResolution=4,Fullscreen=True,AspectRatio='16:9',WidescreenCamera=True)
        env=graphics_environment(settings)
        self.assertEqual(env['REO_INTERNAL_RESOLUTION'],'4');self.assertEqual(env['REO_WIDESCREEN'],'1')
        self.assertEqual(len(input_environment(settings)['REO_MACOS_KEYS'].split(',')),16)
        settings['Gamma']=float('nan')
        with self.assertRaises(ValueError):graphics_environment(settings)
        settings['PadMapping'][0]=16
        with self.assertRaises(ValueError):input_environment(settings)

    def test_pnach_real_data_and_code_rejection(self):
        path=self.root/'test.pnach';path.write_text('gametitle=Test\npatch=1,EE,00380000,word,00000005\n')
        self.assertEqual(pnach_program([path]),['1 00380000 4 0000000000000005'])
        path.write_text('patch=1,EE,00100000,word,00000005')
        with self.assertRaises(ValueError):pnach_program([path])

    def test_live_settings_atomic_format(self):
        session=Session(self.store);session.live_file=self.root/'live.txt'
        settings=copy.deepcopy(DEFAULTS);settings['MusicVolume']=25;settings['ShowSubtitles']=False
        session.live_settings(settings)
        self.assertEqual(session.live_file.read_text(),'100,25,100,100,100\n0\n')

    def test_online_profile_is_preserved(self):
        settings=copy.deepcopy(DEFAULTS);settings.update(CoopMode='join',Username='mac_test')
        card=self.store.card();env=online_environment(settings,card)
        marker=card/'BWNETCNF/BWNETDCNF';self.assertIn('host profile',marker.read_text())
        marker.write_text('Existing original profile')
        online_environment(settings,card);self.assertEqual(marker.read_text(),'Existing original profile')
        self.assertEqual(env['REO_COOP_HOST'],'127.0.0.1')

    def test_process_cancellation_and_logs(self):
        from core import Processes,clean_environment
        process=Processes();log=self.root/'process.log'
        worker=threading.Thread(target=lambda:process.run([sys.executable,'-u','-c','import time;print("ready",flush=True);time.sleep(60)'],self.root,clean_environment(),log))
        worker.start()
        deadline=time.monotonic()+5
        while not log.exists() or 'ready' not in log.read_text():
            if time.monotonic()>deadline:self.fail('child not started')
            time.sleep(.02)
        process.cancel();worker.join(5);self.assertFalse(worker.is_alive());self.assertIn('ready',log.read_text())

    def test_example_mods_and_manifest_validation(self):
        from core import ROOT
        source=ROOT/'examples/mods/no-infection.json'
        identity=install(source,self.store.home)
        settings=copy.deepcopy(DEFAULTS);settings['EnabledMods']=[identity]
        session=self.root/'session';session.mkdir()
        env=mod_environment(settings,self.store.home,self.root,session)
        self.assertEqual((session/'cheats.txt').read_text(),'REO-CHEATS-2\nbuiltin infection\n')
        self.assertIn('REO_CHEATS_FILE',env)
        with self.assertRaises(FileExistsError):install(source,self.store.home)


if __name__=='__main__':unittest.main()
