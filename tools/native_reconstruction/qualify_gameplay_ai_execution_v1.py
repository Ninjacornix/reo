"""Seal native AI state primitives and actual canonical Actor composition."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_gameplay_ai_execution_qualification_v1.json'
    assert not target.exists()
    sources,cohorts,parents,binaries={},{},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/gameplay-ai-{cc}-v1/receipt.json'
        receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged']
        assert data==dict(checks=6629721,goal_cases=131072,action_cases=131072,phase_cases=256,
            finish_cases=65536,profile_cases=256,profile_refusals=4,copies=20,clears=40)
        assert observed is None or observed==data;observed=data
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=data)
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/gameplay-ai-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 12' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_ai_owner_tests.exe','gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/ai.cpp.obj',
            'gameplay_ai/gameplay_ai_tests.exe','gameplay_ai/libreo_native_gameplay_ai.a']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in ['game/native/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_update/ai.cpp','game/native/gameplay_update/ai_tests.cpp',
        'game/native/gameplay_update/update.hpp','game/native/gameplay_update/CMakeLists.txt',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
        Path(__file__).relative_to(ROOT).as_posix()]:sources[name]=sha(ROOT/name)
    target.write_text(json.dumps(dict(schema=1,status='qualified native AI goal/action state and weight-profile selector',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,qualified_binaries=binaries,limitations=[
            'Both compilers pass6629721 identical source-comparison checks. Complete813380 goal reset and81A6E0 action selection each compare131072 calls covering all65536 halfwords with zero/FFFF high halfwords. Complete81A6F0 phase reset compares256 cases; complete814B30 goal-six reset compares65536 calls. Complete8123E0 selector compares256 nonnegative profiles; four negative profiles refuse without changes.',
            'The goal-zero gate tests the full low halfword, not the low byte. Nonzero goals preserve previous_goal; zero records the old goal. Action selection always records the previous action and clears its phases. These execution action fields are distinct from route edge actions. Whole original actor projections compare all known fields and untouched bytes across every completed call.',
            'The twenty immutable56-byte authored weight profiles are regenerated exactly from hash-pinned o9. Native state stores a logical profile index, not an original pointer. Selection copies eight base weights and clears only reactive/status banks, preserving combined weights. >=20 preserves original no-op. Negative source indexing lacks a lower bound and is explicitly unavailable, not clamped or guessed.',
            'Complete107AB0 original copy executes; the two exact eight-byte zero fills remain a declared original-only surroundings port. No source register context or guest RAM appears in production. Both parent builds and twelve integration tests pass, including actual Owner identity, missing component, retirement/closure and canonical Actor composition.',
            'The optional Actor execution component requires an actual producer/import; setters do not invent prior state. Full8120C0 initialization, observations, goal reevaluation/remaining callbacks, action execution, real input/network/save ownership and coherent native gameplay installation remain open. The separately callable goal-six primitive is not claimed as an installed goal dispatcher. Installed V39 is unchanged; no game launch or performance result is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__=='__main__':
    main()
