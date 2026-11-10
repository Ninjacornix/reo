"""Seal canonical actor route/action mutation and its real UpdateOwner consumer."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-actor-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        for key, value in dict(checks=35106105,actor_route_cases=8205,actor_action_cases=8211,
            actor_route_refusals=1,actor_route_corrected_cases=2304,actor_route_retail_cases=13336,
            cross_search_cases=259,cross_route_cases=4473,cross_corrected_cases=3617).items():
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
            path = ROOT/f'build-native-sjuni/navigation-actor-{kind}-{cc}-v1.log'
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
    prior = ROOT/'tools/native_reconstruction/native_cross_room_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded canonical actor route and action mutation',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_cross_room=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete8173D0/816EF0 execute with all existing complete condition, local and cross-room bodies. Both compilers pass35106105 checks,8205 route refreshes and8211 action updates, including13336 retail-data calls.14112 actor comparisons use the strict profile;2304 select the separately declared collector initialization correction, including early denials without collection.',
            'A single optional ActorRouteState belongs to the actual World Actor. Absence is unavailable, not implicitly zero. Current/destination node, route outputs, final position, action/previous action, destination room, completion/refresh and last-current node are distinct typed fields. Room/status/slot/AI, actor identity and mutable navigation data reuse their existing canonical owners.',
            'Last-current node is written after any completed refresh, including completed no-path. A successful action update publishes the actual occupancy bit using32-bit masked shift then byte truncation, takes the first direct edge action, then any applicable last reverse match at a link node. Final-position substitution changes positions without inventing node rewrites. Previous action/completion/refresh remain untouched by these two functions.',
            'One controlled query requires an unspecified initial cost and remains unavailable, preserving the prefix. The v1 fixture incorrectly expected unknown when a prior source route supplied a known scalar; both failed receipts are retained. v2 explicitly clears visits and places the actor on its source link to exercise the intended no-writer case. No production route policy was changed for that fixture correction.',
            'Both parent builds and all ten integration tests pass, including actual UpdateOwner capability absence, canonical actor mutation, shared occupancy and closure/foreign identity handling. Initial/current-node and destination producers, outer816890, movement/transition actions, other AI/VM owners, broader cost/content admission, real loading, semantic saves, coherent game installation and gameplay acceptance remain open. No game launched, installed fix or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
