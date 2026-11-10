"""Seal native navigation visibility, full collision/math originals and actor node selection."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_visibility_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-visibility-{cc}-v4/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        for key, value in dict(checks=40293789,actor_route_cases=8205,actor_action_cases=8211,
            actor_route_refusals=1,actor_route_corrected_cases=2304,actor_route_retail_cases=13336,
            cross_search_cases=259,cross_route_cases=4473,cross_corrected_cases=3617,
            destination_cases=15884,destination_refusals=2,destination_corrected_cases=4608,destination_retail_cases=6668,
            visibility_cases=68,visible_nearest_cases=3408,visibility_refusals=2,visibility_retail_cases=3334,node_policy_cases=6144,node_choice_cases=480,node_choice_refusals=0).items():
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
            path = ROOT/f'build-native-sjuni/navigation-visibility-{kind}-{cc}-v{2 if kind == "parent" else 1}.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a', 'gameplay_navigation/libreo_native_gameplay_navigation.a', 'gameplay_navigation/libreo_native_navigation_visibility.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:
        sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_navigation_destination_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified native filtered navigation and actor policy with full geometry/math originals',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_destination=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete81A340, flags1 nearest8171E0/8171C0 and815BC0/813BD0 execute through complete579980 sampler/filter/triangle bodies and full finite SDK acos/square-root math. Both compilers pass40293789 checks with68 visibility,3408 filtered nearest,6144 policy and480 node-choice comparisons. No geometry-clear stub or host-acos replacement is used.',
            'The3334 retail-node profiles use actual authored SGL coordinates with controlled empty geometry, not actual retail wall acceptance. Controlled static/dynamic triangles verify type classification, disabled masks, slot state and ordered first hit, including ignoring an allowed first hit rather than replacing it with a later blocker. Two nonfinite/incomplete-sampling contexts stay unavailable.',
            'Source query origin rises10 and endpoint Y becomes query origin+20. Pairwise sort temporary s1 survives as last swapped old-head when all candidate visibility tests block; that source behavior is intentionally retained. Empty filtered input completes with-1; empty unfiltered input retains its prior unknown-source boundary.',
            'One actual optional ActorRouteState now owns the distinct105B selection mode. UpdateOwner uses canonical actor identity, room, position, motion class, status/auxiliary status, mode and World Bank. It publishes the selector return as in the statically audited812540 entry prefix. The remainder of812540 is not executed or claimed migrated. Real scene loading/binding and full AI/movement/transition callers stay open.',
            'Both parent builds and all ten integration tests pass, including actual current-node publication, missing capability, and foreign/closed identity rejection. v1 reference builds failed a copied-loop-variable warning; v2 fixed that, v3 added actor policies, and v4 adds ordered-hit/slot-state coverage and an explicit test-only cstring include after the GCC parent build caught its absence. Failed evidence remains.',
            'Pinned main ELF load segments and owned o2 bytes are original-only test inputs; native production has no guest RAM/register model. All previous navigation/destination comparison counts remain. Broader cost/content admission, actual scene loading, remaining AI/VM/input/network owners, semantic saves and coherent game installation/acceptance remain required. No game launched, measured performance fix or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
