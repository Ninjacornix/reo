"""Seal complete actor destination setup and its audited heading chain."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_destination_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-destination-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        for key, value in dict(checks=40202873,actor_route_cases=8205,actor_action_cases=8211,
            actor_route_refusals=1,actor_route_corrected_cases=2304,actor_route_retail_cases=13336,
            cross_search_cases=259,cross_route_cases=4473,cross_corrected_cases=3617,
            destination_cases=15884,destination_refusals=2,destination_corrected_cases=4608,destination_retail_cases=6668).items():
            assert receipt['observed'][key] == value
        assert observed is None or observed == receipt['observed']
        observed = receipt['observed']
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-destination-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a', 'gameplay_navigation/libreo_native_gameplay_navigation.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:
        sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_actor_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded actor destination setup with complete heading and distance originals',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_actor_routes=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete816890 executes against complete nearest, actor action, local/cross-room, condition, heading and distance originals. Both compilers pass40202873 checks and15884 completed destination comparisons, including6668 retail-data calls.11276 destination comparisons use the strict profile;4608 select the separately declared collector initialization correction, including early denials without collection.',
            'Actual UpdateOwner resolves the canonical optional actor route component and existing room, position, motion class, status/auxiliary status, transient marker, slot/AI, session room and flags. Destination/completion/refresh prefix, nearest selection, same Bank visit reset, actual occupancy/route/action, normalization and previous-action copy preserve original order.',
            'Destination preparation keeps height rules for action low bytes1/2/8/9, otherwise the exact quarter-turn window and50/100 distance gates. Source370140 biases zero Z with pinned0x38D1B717; the existing contact helper biases X and is not substituted. Complete370140/192180/1226F0/120908/122140/1224A8/191EF0 and817100/191D10 run with pinned polynomial/constant data. Finite/representable SDK profiles do not claim physical exceptional parity.',
            'Both parent builds and all ten integration tests pass. Two controlled unavailable cases retain their written prefix: nonfinite destination and actor slot outside the four-mask visit profile. The v1 builds failed because the new o0 declaration shim was missing; both failed receipts remain. v2 adds that shim and executes unchanged audited bodies, including all6668 retail destination cases.',
            'The collector cost initialization correction remains explicit and disabled by default; no live stack values or actual game acceptance are claimed. Initial/current-node producers, filtered navigation/collision queries, complete AI/movement/room transitions, broader work/content admission, loading, semantic saves and coherent native game installation/acceptance remain open. No game was launched and Stage4 is incomplete.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
