"""Seal the canonical cold InventoryUi owner and both original108 dispatchers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
CORE=['game/native/gameplay_world/recovery_ui.hpp','game/native/gameplay_world/inventory_ui.hpp','game/native/gameplay_world/inventory_ui.cpp','game/native/gameplay_world/actor_recovery.hpp','game/native/gameplay_application/native_session.hpp','game/native/gameplay_application/native_session.cpp','game/native/gameplay_application/native_session_tests.cpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp']
NAMES=CORE+['tools/native_reconstruction/gameplay_scenario/tests.cpp','tools/native_reconstruction/gameplay_scenario/verify.py','tools/native_reconstruction/gameplay_scenario/inventory_ui_vm_tests.inc','tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/inventory_ui_tests.cpp','tools/native_reconstruction/verify_inventory_ui.py','tools/native_reconstruction/qualify_inventory_ui_v1.py','docs/native-gameplay/INVENTORY_UI.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md']
def load(name):
    path=ROOT/'build-native-sjuni'/name/'receipt.json';data=json.loads(path.read_bytes());assert data['status']=='passed',name
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)),data
def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        owner,p=load(f'inventory-ui-{cc}-v1');vm,v=load(f'inventory-ui-vm-{cc}-v2');admit,a=load(f'inventory-ui-admission-{cc}-v1');parents,t=load(f'inventory-ui-parents-{cc}-v2');assets,r=load(f'inventory-ui-room-lighting-assets-{cc}-v1')
        assert p['source_unchanged']and not p['source_drift']and not a['current_shared_source_drift']and not t['source_drift']and not r['source_drift']
        assert p['observed']['checks']==4262927 and p['observed']['commands']==16384 and p['observed']['recovery_closes']==16384
        assert v['result']['checks']==578910460 and v['result']['inventory_ui_dispatches']==65536 and v['result']['inventory_ui_refusals']==4
        for name in CORE:
            proof=t if name=='game/native/gameplay_world/actor_recovery.hpp' else v
            assert proof['source_sha256'][name]==sha(ROOT/name),name
        assert t['parent_tests']==28 and r['result']['checks']==285448 and r['result']['room_keys']==227
        assert a['admitted']=={'before':[34,27],'after':[34,27]}
        assert a['evbs'][2]['after'][0]==dict(status=2,block=2,offset=300,opcode=0x63)
        evidence.extend([owner,vm,admit,parents,assets]);observed.append(dict(compiler=cc,owner=p['observed'],vm={key:v['result'][key]for key in ['checks','inventory_ui_dispatches','inventory_ui_refusals']},parent_tests=28,room_lighting=r['result']))
    frontier,f=load('inventory-ui-frontier-v1');assert f['totals'][0]['unsupported_instructions']==68 and len(f['totals'][0]['counts'])==11;evidence.append(frontier)
    result=dict(schema='reo.native.inventory_ui.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in NAMES},evidence=evidence,observed=observed,game_launched=False,device_opened=False,installed_in_game=False,stage4_complete=False,
        limitations=['The native owner implements a typed cold projection of complete6DEC80, not every later role in its16004-byte source domain.','Only phase0 of6E1430 is admitted; active UI phases require actual equipment/audio/teardown owners and refuse.','All original register/memory contexts are offline qualification fixtures, absent from native production.','All five EVBs still refuse complete admission;68 ordinary authored instructions across11 distinct opcodes remain unsupported.','Native terminal frame services, installed gameV39 replacement, input/transport/media hosts and semantic save/resume remain Stage4 gates.'])
    path=ROOT/'tools/native_reconstruction/native_inventory_ui_qualification_v1.json';path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',seal=path.relative_to(ROOT).as_posix(),sha256=sha(path))))
if __name__=='__main__':main()
