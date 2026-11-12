"""Seal packed audio, linked flight, attachment and actual-owner integration."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    production=['game/native/'+n for n in ['gameplay_world/linked_resource_flight.hpp','gameplay_world/linked_resource_flight.cpp','gameplay_world/linked_flight_effects.hpp','gameplay_world/linked_flight_effects.cpp','gameplay_world/packed_actor_audio.hpp','gameplay_world/packed_actor_audio.cpp','gameplay_world/resource_pose_work.hpp','gameplay_world/resource_pose_work.cpp','gameplay_lighting/timed_lights.hpp','gameplay_lighting/timed_lights.cpp','gameplay_world/pose_weapon_effects.hpp','gameplay_world/pose_weapon_effects.cpp']]
    tests=['tools/native_reconstruction/'+n for n in ['packed_actor_audio_tests.cpp','verify_packed_actor_audio.py','linked_resource_flight_tests.cpp','linked_flight_owner_tests.inc','verify_linked_resource_flight.py','timed_lights_tests.cpp','verify_timed_lights.py']]
    owned=production+tests+['game/native/gameplay_world/linked_flight_contract_tests.cpp','game/native/gameplay_world/CMakeLists.txt','docs/native-gameplay/LINKED_RESOURCE_FLIGHT.md',Path(__file__).relative_to(ROOT).as_posix()]
    record=dict(schema=1,status='passed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:sha(ROOT/n)for n in owned},cohorts={},limits=['Full kind20/other reached pose callbacks and full host/game acceptance remain required.','Owner event0x12 matches silent PCM for the explicitly bound weapon01 cue; this is not an audible in-game bank assignment claim.','Class2/3 sound tags require their actual producer. Unassigned original class routes refuse.'])
    for cc in ['llvm','gcc']:
        record['cohorts'][cc]={};covered={}
        for label,directory in [('packed_audio',f'packed-actor-audio-{cc}-v3'),('flight_and_attachment',f'linked-flight-owner-{cc}-v1'),('timed_lights',f'ungated-timed-light-{cc}-v3'),('current_parents',f'session-rooms-parents-{cc}-v6')]:
            p=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed',(p,r.get('status'))
            for key in ['owned_source_drift','current_shared_source_drift','current_owned_source_drift','source_drift']:
                assert not r.get(key),(p,key,r.get(key))
            if 'source_unchanged'in r:assert r['source_unchanged']
            if label=='current_parents':
                assert r['parent_tests']==25
                # This is the actual current dependency closure, not merely a
                # name/path claim about a previously compiled executable.
                current=r.get('source_sha256',{})
                for n in production+['game/native/gameplay_world/linked_flight_contract_tests.cpp','game/native/gameplay_world/CMakeLists.txt']:
                    assert n in current and current[n]==sha(ROOT/n),(p,n)
            else:
                for n in production+tests:
                    if r.get('source_sha256',{}).get(n)==sha(ROOT/n):covered[n]=label
            record['cohorts'][cc][label]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':r.get('observed',r.get('parent_tests')),'compiler_sha256':r.get('compiler_sha256'),'subsequent_parent_header_changes':r.get('subsequent_parent_header_changes',{})}
        # Firing adapter is exercised by the current self-contained contract;
        # the remaining production bodies must also match a full-source cohort.
        assert all(n in covered for n in production if 'pose_weapon_effects'not in n),set(production)-set(covered)
        assert all(n in covered for n in tests),set(tests)-set(covered)
    target=ROOT/'tools/native_reconstruction/native_linked_resource_flight_qualification_v1.json';assert not target.exists();target.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps({'status':record['status'],'sha256':sha(target),'game_run':False,'stage4_complete':False}))
if __name__=='__main__':main()
