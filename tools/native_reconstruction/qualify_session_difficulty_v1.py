"""Seal canonical launch difficulty import and both original EE dispatchers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
NAMES=['game/native/gameplay_world/world.hpp','game/native/gameplay_application/native_session.hpp','game/native/gameplay_application/native_session.cpp','game/native/gameplay_application/native_session_tests.cpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp','game/native/gameplay_scenario/difficulty_predicate.hpp','tools/native_reconstruction/gameplay_scenario/tests.cpp','tools/native_reconstruction/gameplay_scenario/verify.py','tools/native_reconstruction/gameplay_scenario/difficulty_vm_tests.inc','tools/native_reconstruction/launch_difficulty_tests.cpp','tools/native_reconstruction/verify_launch_difficulty.py','tools/native_reconstruction/qualify_session_difficulty_v1.py','docs/native-gameplay/SESSION_DIFFICULTY.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md']
def load(name):
    path=ROOT/'build-native-sjuni'/name/'receipt.json';data=json.loads(path.read_bytes());assert data['status']=='passed',name
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)),data
def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        prefix,p=load(f'launch-difficulty-{cc}-v1');vm,v=load(f'difficulty-vm-{cc}-v2');admit,a=load(f'difficulty-admission-{cc}-v1');parents,t=load(f'difficulty-parents-{cc}-v1')
        assert p['source_unchanged']and not p['source_drift']and not a['current_shared_source_drift']and not t['source_drift']
        assert p['observed']['source_prefixes']==256 and p['observed']['checks']==1542 and t['parent_tests']==28
        assert v['result']['checks']==577009894 and v['result']['difficulty_dispatches']==605958 and v['result']['difficulty_refusals']==13
        for name in NAMES[:7]:assert v['source_sha256'][name]==sha(ROOT/name),name
        assert a['admitted']=={'before':[34,27],'after':[34,27]}
        assert a['evbs'][0]['after'][0]==dict(status=2,block=2,offset=4700,opcode=0x64)
        evidence.extend([prefix,vm,admit,parents]);observed.append(dict(compiler=cc,launch=p['observed'],vm={key:v['result'][key]for key in ['checks','difficulty_dispatches','difficulty_refusals']},parent_tests=28))
    frontier,f=load('difficulty-frontier-v1');assert f['totals'][0]['unsupported_instructions']==69 and len(f['totals'][0]['counts'])==12;evidence.append(frontier)
    result=dict(schema='reo.native.session_difficulty.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in NAMES},evidence=evidence,observed=observed,game_launched=False,device_opened=False,installed_in_game=False,stage4_complete=False,
        limitations=['Launch proof executes actual37F330 entry prefix through the first copy boundary, with an explicit interruption before remaining launch effects. It does not claim complete frontend/roster/room entry.','Generic sessions retain unknown difficulty; explicit application import is required before valid EE comparisons. Invalid selectors preserve source scanning without reading difficulty.','All original register/memory contexts are offline qualification fixtures, absent from native production.','All five EVBs still refuse complete admission;69 ordinary authored instructions across12 distinct opcodes remain unsupported.','Native terminal frame services, installed gameV39 replacement, input/transport/media hosts and semantic save/resume remain Stage4 gates.'])
    path=ROOT/'tools/native_reconstruction/native_session_difficulty_qualification_v1.json';path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',seal=path.relative_to(ROOT).as_posix(),sha256=sha(path))))
if __name__=='__main__':main()
