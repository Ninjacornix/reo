"""Seal shared native AI registration/request producers and actual Session owner."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_gameplay_ai_controls_qualification_v1.json'
    assert not target.exists()
    sources,cohorts,parents,binaries={},{},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/gameplay-ai-control-{cc}-v1/receipt.json'
        receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged']
        assert data==dict(checks=30579888,goal_cases=131072,action_cases=131072,phase_cases=256,
            finish_cases=65536,profile_cases=256,profile_refusals=4,copies=20,clears=40,
            control_membership_cases=64,control_register_cases=152,control_unregister_cases=44,
            control_lookup_cases=18432,control_request_cases=18432,control_publish_cases=66)
        assert observed is None or observed==data;observed=data
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=data)
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/gameplay-ai-control-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 12' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a',
            'gameplay_ai/CMakeFiles/reo_native_gameplay_ai.dir/control_requests.cpp.obj']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in ['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
        'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
        Path(__file__).relative_to(ROOT).as_posix()]:sources[name]=sha(ROOT/name)
    prior=ROOT/'tools/native_reconstruction/native_gameplay_ai_execution_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified native AI control registration and request producers',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,qualified_binaries=binaries,
        prior_execution=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compiler cohorts pass30579888 identical checks, including all prior goal/action/profile comparisons and complete681240/6812B0/681330/681710/681790/815DF0. Membership64, registration152, removal44, lookup18432, request18432 and actor-control publisher66 calls execute complete original bodies without new surroundings ports.',
            'One Session-owned ControlRequests holds64 typed registrations and64 pending requests. Registration membership narrows kind/target to byte/signed halfword; request lookup compares full arguments against stored values. Selector-1 means FF; other selectors use low-byte+1 with wrapping. Registration preserves old phase/payload fields while replacing key/counters/owner tag; removal clears only original fields. Source projections compare changed and unchanged bytes.',
            'Requests copy exactly four bytes and append only after a matching registration and capacity admission. Full and missing registration outcomes remain distinct; lookup occurs before the full check. Actor-control publication narrows its parameter to one byte followed by three zero bytes. Source full-capacity and duplicate/reuse cases compare without overwritten pending data.',
            'Both parent builds and twelve integration tests pass. Actual Owner uses the canonical actor slot, checks identity/open state, and reaches the SAME Session queue for registration/publication. Tests distinguish actor slot5 from primary physical index0, reject foreign/retired identities and verify the copied payload.',
            'This is a native producer/queue component, not an installed service loop or network transport. The service, acknowledgement/owner updates, reset/consumption and full AI initialization/observations/dispatch remain open. The queue currently exposes pending values for its future actual service consumer; no fabricated delivery or successful network send is claimed. Installed V39 and game speed remain unchanged; no game or slowdown test occurred.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__=='__main__':
    main()
