"""Seal strict and explicitly zero-initialized cross-room profiles separately."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_cross_room_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-cross-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert receipt['observed']['checks'] == 29554496
        assert receipt['observed']['cross_search_cases'] == 259
        assert receipt['observed']['cross_route_cases'] == 4473
        assert receipt['observed']['cross_corrected_cases'] == 3617
        assert receipt['observed']['cross_retail_cases'] == 3704
        assert receipt['observed']['cross_refusals'] == 189
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
            path = ROOT/f'build-native-sjuni/navigation-cross-{kind}-{cc}-v1.log'
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
    prior = ROOT/'tools/native_reconstruction/native_link_collection_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,
        status='qualified bounded cross-room search; strict and deterministic-initialization profiles distinguished',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_collection=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),
        profiles=dict(strict_completed=1115,explicit_initialization_profile_completed=3617,
            total_completed=4732,retail_completed=3704,unavailable=189),limitations=[
            'Complete817470/817820,819370 and107AB0 bodies execute against pinned original words and all existing complete local route/condition bodies. Visit-copy107AB0 is not a port. Both compiler cohorts pass29554496 checks,259 recursive and4473 outer comparisons; all ten parent integration checks pass per compiler.',
            'The strict default invents no initial collector cost. Root source-to-target collection carries only a proven prior scalar; recursive calls require a writer before any use. Reused original stack frames may contain earlier values that the native strict profile intentionally does not emulate, so some source-executable contexts remain conservatively unavailable.',
            'The separate initialize_collection_cost profile explicitly initializes cost to zero at EVERY collector entry. The reference dispatcher applies this same declared correction before executing otherwise unchanged original bodies.3617 completed comparisons select this profile, including early-denial cases that need no collector. These are not3617 claims of unmodified source equivalence or live-game validation.1115 completed comparisons use the strict profile without that intervention.',
            'Traversal preserves first direct pair match, exact adjacency byte==1, candidate-wide visit marking before recursion, no visit rollback and last recursive return overwriting an earlier success. Outer attempts use independent visit snapshots and publish persistent visits only when selected first node equals the chosen source link node. Early status/empty-collection denial leaves outputs untouched; later no-path writes only link=-1.',
            'Bounded native profiles admit at most256 links,16 collector results,128 recursion depth and4096 collector calls by default. Budget or malformed/unknown contexts are unavailable, never approximate successful routes.189 sampled comparisons refuse: five controlled initialization/work/depth cases and184 additional retail route contexts. These are not diagnosed game bugs or slowdown counts.',
            'The actual UpdateOwner resolves canonical actor identity, status/AI/slot, reads one ephemeral snapshot of canonical room flags, and uses the World Bank and its persistent visit masks. This is not a second mutable navigation owner. Actor destination/current-node producers, route-state mutation and AI execution, broader cost/content admission, loading, semantic saves, coherent game installation and gameplay acceptance remain open. V39 is unchanged.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
