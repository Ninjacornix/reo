import copy
import json
from pathlib import Path
import subprocess
import os
import struct
import time
import tempfile
import unittest

from core import Store, DEFAULTS, ELF_SHA256, ROOT
from services import HostedServer, discover, host_randomizers, fetch_randomizers, shared_randomizer_manifests


class ServerTests(unittest.TestCase):
    def test_native_host_discovery_shared_mods_and_transport(self):
        with tempfile.TemporaryDirectory() as temporary:
            root=Path(temporary)
            store=Store(root/'config',data_home=root/'data')
            store.settings.update(Username='mac_test',CoopMode='host')
            from mods import install
            identity=install(ROOT/'examples/mods/randomizer.json',store.home)
            store.settings['EnabledMods']=[identity]
            shared=host_randomizers(store.settings,store.home)
            server=HostedServer(store)
            try:
                server.start(store.settings)
                server.randomizers=shared
                found=discover()
                self.assertTrue(any(value['address']=='127.0.0.1' for value in found))
                self.assertEqual(fetch_randomizers(store.settings),shared)
                manifests=shared_randomizer_manifests(shared)
                self.assertIn('itemRandomizer',manifests[0])
                self.assertIn('enemyRandomizer',manifests[0])
                # A test-only credential provider exercises registration/input
                # without reading or writing the real user's Keychain.
                from services import OnlineAccount
                tools=root/'resources/tools';tools.mkdir(parents=True)
                helper=tools/'AccountKeychain'
                helper.write_text('#!/bin/sh\nprintf abcdefghijk1234\n');helper.chmod(0o700)
                session=root/'session';session.mkdir()
                account=OnlineAccount(store.settings,session,lambda text:None,root/'resources')
                def wait_for(predicate):
                    deadline=time.monotonic()+5
                    while not predicate():
                        if time.monotonic()>deadline:self.fail('account protocol timed out')
                        time.sleep(.01)
                try:
                    account.on_line('[COOP-AUTO] account-request 1')
                    wait_for(lambda:account.status.is_file() and account.status.read_text()=='ready 1')
                    account.on_line('[COOP-AUTO] password-ready 1')
                    credential=Path(str(account.status)+'.credential')
                    wait_for(credential.is_file)
                    self.assertEqual(credential.stat().st_mode & 0o777,0o600)
                    self.assertEqual(credential.read_bytes(),struct.pack('<III',0x52454f41,1,15)+b'abcdefghijk1234\0')
                    Path(str(account.status)+'.applied').write_text('1')
                    wait_for(lambda:account.status.read_text()=='typed 1')
                finally:account.close()
                self.assertFalse(credential.exists())
                server.randomizers=None
                with self.assertRaisesRegex(ValueError,'not launched'):fetch_randomizers(store.settings)
                checker=ROOT/'build-macos/snap_iop_check'
                if checker.is_file():
                    result=subprocess.run([str(checker)],capture_output=True,text=True,check=True,timeout=30)
                    self.assertIn('capcom_app=1',result.stdout)
            finally:server.close()
            self.assertEqual(server.children,[])

    def test_untrusted_shared_configuration_rejected(self):
        for value in ({}, {'protocol':3,'elf':'wrong'}, {'protocol':3,'elf':ELF_SHA256,'session':'x'*32}):
            with self.assertRaises(ValueError):shared_randomizer_manifests(json.dumps(value).encode())
        with self.assertRaises(ValueError):shared_randomizer_manifests(b'x'*32769)


if __name__=='__main__':unittest.main()
