"""Seal actual ordinary bootstrap and one canonical native application graph."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
APP='game/native/gameplay_application/'
CORE=[APP+name for name in ['native_session.hpp','native_session.cpp','session_rooms.hpp','session_rooms.cpp','session_resources.hpp','session_resources.cpp','session_resource_assets.cpp','session_resource_import.hpp','session_resource_import.cpp','session_resource_workers.hpp','session_resource_workers.cpp','starting_resources.inc','CMakeLists.txt']]
NAMES=CORE+[APP+'session_resources_tests.cpp','tools/native_reconstruction/session_resource_import_tests.cpp','tools/native_reconstruction/verify_session_resource_import.py','tools/native_reconstruction/verify_session_resources_current.py','tools/native_reconstruction/verify_session_resources_parents.py','tools/native_reconstruction/qualify_session_resources_v1.py','docs/native-gameplay/SESSION_RESOURCES.md','docs/native-gameplay/NATIVE_SESSION_APPLICATION.md','docs/native-gameplay/STAGE4_INTEGRATION_AUDIT.md','docs/native-gameplay/STAGE4_PLAN.md']

def load(name):
    path=ROOT/'build-native-sjuni'/name/'receipt.json';data=json.loads(path.read_bytes());assert data['status']=='passed',name
    return dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)),data

def main():
    evidence=[];observed=[]
    for cc in ['llvm','gcc']:
        bootstrap,b=load(f'session-resource-import-{cc}-v4');current,c=load(f'session-resources-current-{cc}-v5');vm,v=load(f'session-resources-vm-{cc}-v1');parents,p=load(f'session-resources-parents-{cc}-v3')
        assert b['source_unchanged']and not b['source_drift']and not c['source_drift']and not p['source_drift']
        assert b['observed']['checks']==9125409 and b['observed']['cases']==8765 and b['observed']['asset_mode_prefixes']==256 and b['observed']['refusals']==4
        assert c['result']==dict(checks=68,selected=222,placed=222,starting=4,workers=4,refusals=9,guards=1,game_run=False)
        assert len(c['native_library_sha256'])==67 and p['parent_tests']==31
        assert v['result']['checks']==586070532 and v['result']['original_dispatch_invocations']==46249
        assert p['resources']==c['result']and p['speech']['owned_clips']==33 and p['speech']['checks']==4715864 and p['room_lighting']['room_keys']==227
        assert p['dialogue_worker']=='Canonical dialogue worker contract passed 44 checks'
        for name in CORE:
            for proof in [b,c,v,p]:assert proof['source_sha256'][name]==sha(ROOT/name),(cc,name)
        for name in [APP+'session_resources_tests.cpp','tools/native_reconstruction/verify_session_resources_current.py']:assert c['source_sha256'][name]==sha(ROOT/name)
        for name in ['tools/native_reconstruction/session_resource_import_tests.cpp','tools/native_reconstruction/verify_session_resource_import.py']:assert b['source_sha256'][name]==sha(ROOT/name)
        evidence.extend([bootstrap,current,vm,parents]);observed.append(dict(compiler=cc,bootstrap=b['observed'],graph=c['result'],vm_checks=v['result']['checks'],parent_tests=31,speech=p['speech'],room_lighting=p['room_lighting']))
    result=dict(schema='reo.native.session_resources.qualification.v1',status='passed',source_sha256={name:sha(ROOT/name)for name in NAMES},evidence=evidence,observed=observed,game_launched=False,device_opened=False,installed_in_game=False,stage4_complete=False,
        prerequisites=['4aafc8d7:canonical World cinematic lookup and no-data resource friends plus actual actor sound/CF2 producer metadata.','Current qualified native canonical actor sound readers and projectile/pose dependency graph.'],
        limitations=['Actual ordinary591C50 archive profile only; offline adjustment and filesystem mode refuse.','NativeSession owns one descriptor/model/inventory/pose graph; immutable asset validation templates are not an extra mutable runtime bank.','Room replacement refuses pending actual591920 persistent reset/rebind; an empty or retired owner does not admit resource Programs.','Resource model update requires the sole CutscenePlayback actual4BAE9A state. The owned room test uses its real zero-current-object dynamic branch.','Required companion/audio/spatial/inherited-mode1/projectile consumers and terminal phase/actor/physics services remain explicit refusals.','Controlled roster/cinematic/174 fixtures prove composition, not authored launch or complete cinematic/gameplay acceptance.','Complete scenario EVB admission, semantic save/resume, input/transport/media installation and replacement/acceptance of installedgameV39 remain Stage4 gates.','Original CPU/register/memory models exist solely in offline qualification.'])
    path=ROOT/'tools/native_reconstruction/native_session_resources_qualification_v1.json';path.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',files=len(NAMES),receipts=len(evidence),seal=path.relative_to(ROOT).as_posix(),sha256=sha(path))))
if __name__=='__main__':main()
