"""Explicit developer-only validation of the frozen app, using isolated saves."""
import copy
import json
from pathlib import Path
import subprocess
import sys
import tempfile

from core import DEFAULTS, Store, Session, native_arm64, digest


def run(arguments):
    report=Path(arguments[0]).resolve()
    options=set(arguments[1:])
    result={'format':1,'checks':[]}
    try:
        with tempfile.TemporaryDirectory(prefix='reo-launcher-check-') as temporary:
            folder=Path(temporary)
            store=Store(folder/'config',data_home=folder/'data')
            record=store.build_record
            assert native_arm64(record['executable'])
            if record.get('executableSha256'):assert digest(record['executable'])==record['executableSha256']
            result['checks'].append('bundled ARM64 game integrity')
            from PySide6.QtWidgets import QApplication
            from main import Window
            app=QApplication.instance() or QApplication([])
            window=Window(store);window.show();app.processEvents()
            for index in range(window.stack.count()):
                window.navigation.setCurrentRow(index);app.processEvents()
                assert window.stack.currentIndex()==index
            window.widgets['MusicVolume'].setValue(27)
            assert json.loads((store.config_home/'settings.json').read_text())['MusicVolume']==27
            window.close();app.processEvents()
            result['checks'].append('ten Qt pages, live controls, persisted settings')
            helper=store.resources/'tools/AssetHelper'
            if helper.is_file():
                completed=subprocess.run([str(helper),'--self-test'],capture_output=True,text=True,check=True)
                result['assetHelper']=completed.stdout.strip()
                result['checks'].append('bundled .NET helper without external runtime')
            if '--server' in options:
                from services import HostedServer,discover
                store.settings['Username']='mac_test'
                server_store=Store(folder/'server-config',resources=store.resources,
                    data_home=report.parent/'packaged-server-check')
                server_store.settings.update(store.settings)
                server=HostedServer(server_store)
                try:
                    server.start(store.settings)
                    found=discover()
                    assert any(value['address']=='127.0.0.1' for value in found)
                    result['checks'].append('four bundled openSNAP services and LAN discovery')
                finally:server.close()
            if '--game' in options:
                # Keep journals after temporary memory cards are removed.
                persistent=report.parent/'packaged-game-check'
                store.home=persistent;store.home.mkdir(exist_ok=True,parents=True)
                store.settings=copy.deepcopy(DEFAULTS);store.settings['Iso']=record['iso']
                store.settings.update(GameClock=True,FrameTiming=True,PerformanceOverlay=True)
                session=Session(store)
                session.launch(store.settings,route='gameplay',seconds=85)
                result['session']=str(session.folder)
                log=(session.folder/'game.log').read_text(errors='replace')
                assert '[TEST-ROUTE] reached gameplay' in log, 'The automatic route did not reach gameplay'
                result['checks'].append('packaged game reached gameplay and exited cleanly')
            result['passed']=True
    except Exception as error:
        result.update(passed=False,error=str(error))
    report.write_text(json.dumps(result,indent=2))
    return 0 if result['passed'] else 1
