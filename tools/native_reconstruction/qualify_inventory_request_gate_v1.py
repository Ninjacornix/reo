"""Seal canonical63 nonzero request gate; retain unowned zero payload explicitly."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
NAMES=['game/native/gameplay_world/inventory_ui.hpp','game/native/gameplay_world/inventory_ui.cpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp','game/native/gameplay_application/native_session_tests.cpp','tools/native_reconstruction/gameplay_scenario/tests.cpp','tools/native_reconstruction/gameplay_scenario/verify.py','tools/native_reconstruction/gameplay_scenario/inventory_request_gate_vm_tests.inc','tools/native_reconstruction/audit_scenario_opcode_frontier.py','tools/native_reconstruction/qualify_inventory_request_gate_v1.py','docs/native-gameplay/INVENTORY_REQUEST_GATE.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md']
def load(name):
    p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed',name
    return dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p)),r
def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        vm,v=load(f'inventory-request-vm-{cc}-v1');admit,a=load(f'inventory-request-admission-{cc}-v1');parents,t=load(f'inventory-request-parents-{cc}-v1')
        assert not a['current_shared_source_drift']and not t['source_drift']and t['parent_tests']==28
        assert v['result']['checks']==586070532 and v['result']['inventory_request_dispatches']==524296 and v['result']['inventory_request_refusals']==6 and v['result']['inventory_request_initializers']==64
        for name in NAMES[:8]:assert v['source_sha256'][name]==sha(ROOT/name),name
        assert a['admitted']=={'before':[34,27],'after':[34,27]}
        assert a['evbs'][2]['after'][0]==dict(status=2,block=2,offset=2536,opcode=0x153)
        evidence.extend([vm,admit,parents]);observed.append(dict(compiler=cc,checks=v['result']['checks'],programs=524296,refusals=6,initializers=64,parent_tests=28))
    item,f=load('inventory-request-frontier-v1');assert f['tool_sha256']==sha(ROOT/NAMES[8]);assert f['totals'][0]['unsupported_instructions']==65 and len(f['totals'][0]['counts'])==9 and f['totals'][0]['known_profile_limits']==1 and f['totals'][0]['known_unimplemented_instructions']==66;evidence.append(item)
    result=dict(schema='reo.native.inventory_request_gate.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in NAMES},evidence=evidence,observed=observed,game_launched=False,device_opened=False,installed_in_game=False,stage4_complete=False,
        limitations=['Only full-word nonzero63/604300 is admitted. Zero604310 requires actual6DDD70 resource-reset ownership and refuses before the Program prefix.','Canonical8D stays unknown before its actual producer, and6DEC80 preserves it.','Original CPU/register/memory objects occur only in offline qualification.','All five scenario EVBs remain unsupported;65 ordinary opcode-mask records plus one known zero63 payload branch remain. Static authored counts do not prove dynamic reachability.','Application resource composition, terminal frame services, installed gameV39 replacement, input/network/media and semantic save/resume remain Stage4 gates.'])
    p=ROOT/'tools/native_reconstruction/native_inventory_request_gate_qualification_v1.json';p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',seal=p.relative_to(ROOT).as_posix(),sha256=sha(p))))
if __name__=='__main__':main()
