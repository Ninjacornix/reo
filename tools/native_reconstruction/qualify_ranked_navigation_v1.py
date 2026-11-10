"""Seal the two native ranked policies against all four complete originals."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_ranked_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=20535871,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=40,bank_cells=327680,bank_visit_cells=6912,bank_clears=20,
        condition_cases=561008,link_cases=2062,link_refusals=3077,edge_cases=338009,
        edge_refusals=13,retail_edge_refusals=12,edge_flag_bindings=2,
        ranked_cases=41326,ranked_refusals=1,ranked_retail_refusals=0)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-ranked-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-ranked-{kind}-{cc}-v1.log'
            raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix;binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:
        sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_navigation_edges_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified native ranked route policies and canonical query consumers',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_edges=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete818010/8185C0 and818390/818940 execute against pinned word-audited originals. Policy0 tries four ranked candidates at the root; policy1 tries only rank0. Both recursive companions try only rank0. Native recursion uses bounded local typed scratch rather than a shared guest-addressed scratch bank.',
            'Rank bytes select neighbor slots, but cost indexes the candidate rank. Exact source behavior is preserved, including first/secondary node bytes, both XYZ outputs, signed result, occupancy bit shift wrapping and accumulated failed-attempt cost. Same-node or no eligible attempt retains existing cost bits.',
            'All five owned inputs contribute40008 route comparisons over three destination choices per source node, two actor/occupancy profiles and both policies. Synthetic coverage adds1318 comparisons for reordered ranks/slots, direct/recursive/cyclic/absent paths, retained NaN cost and all256 actor-slot bytes. One synthetic malformed rank is unavailable. These sampled retail route cases do not trigger the known r041 ordinal gate; they do not remove the twelve edge-context refusals retained in the prior qualification.',
            'Both compiler cohorts pass20535871 total checks and41326 ranked comparisons, including current predicate/edge/bank regressions. Actual UpdateOwner query methods use canonical actor facts/status, its own flag bank and World navigation owner. All ten parent tests pass per compiler; actor destination/movement execution and actual game callers are separate outstanding work.',
            'Bounded-cost policy818B70/818E30, outer route dispatcher817DB0, cross-room route traversal, AI/action consumers, real loading, semantic saves and coherent native acceptance remain open. No game launched or installed and no performance fix is claimed; Stage4 is incomplete.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
