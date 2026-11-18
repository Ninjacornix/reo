"""Seal complete68F180 and both original script dispatchers on canonical54D."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
NAMES=['game/native/gameplay_scenario/actor_model_classes.hpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp','game/native/gameplay_application/native_session.cpp','tools/native_reconstruction/gameplay_scenario/tests.cpp','tools/native_reconstruction/gameplay_scenario/verify.py','tools/native_reconstruction/gameplay_scenario/actor_model_classes_vm_tests.inc','tools/native_reconstruction/qualify_actor_model_classes_v1.py','docs/native-gameplay/ACTOR_MODEL_CLASSES.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md']
def load(name):
    p=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed',name
    return dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p)),r
def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        vm,v=load(f'actor-model-classes-vm-{cc}-v2');admit,a=load(f'actor-model-classes-admission-{cc}-v1');parents,t=load(f'actor-model-classes-parents-{cc}-v2')
        assert not a['current_shared_source_drift']and not t['source_drift']and t['parent_tests']==28
        assert v['result']['checks']==579254551 and v['result']['actor_model_class_dispatches']==24576 and v['result']['actor_model_class_refusals']==9
        for name in NAMES[:7]:assert v['source_sha256'][name]==sha(ROOT/name),name
        assert a['admitted']=={'before':[34,27],'after':[34,27]}
        assert a['evbs'][0]['after'][0]==dict(status=2,block=2,offset=7844,opcode=0x151)
        evidence.extend([vm,admit,parents]);observed.append(dict(compiler=cc,checks=v['result']['checks'],programs=24576,refusals=9,parent_tests=28))
    item,f=load('actor-model-classes-frontier-v1');assert f['totals'][0]['unsupported_instructions']==67 and len(f['totals'][0]['counts'])==10;evidence.append(item)
    result=dict(schema='reo.native.actor_model_classes.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in NAMES},evidence=evidence,observed=observed,game_launched=False,device_opened=False,installed_in_game=False,stage4_complete=False,
        limitations=['Canonical signed population must be known; positive counts above eight or absent writable records refuse before a Program prefix. Negative full words perform no writes.','Model class54D is the existing Actor field consumed by native models and contacts, with no duplicate bank or fabricated reload effect.','Original CPU/register/memory objects occur only in offline qualification.','All five scenario EVBs remain unsupported;67 ordinary authored instructions across10 opcodes remain. Static authored counts do not prove dynamic reachability.','The application resource graph, terminal frame services, installed gameV39 replacement, input/network/media and semantic save/resume remain Stage4 gates.'])
    p=ROOT/'tools/native_reconstruction/native_actor_model_classes_qualification_v1.json';p.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',seal=p.relative_to(ROOT).as_posix(),sha256=sha(p))))
if __name__=='__main__':main()
