"""Seal bounded complete817DB0 and actual canonical UpdateOwner dispatch."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_local_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=25073840,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=40,bank_cells=327680,bank_visit_cells=6912,bank_clears=20,
        condition_cases=561008,link_cases=2062,link_refusals=3077,edge_cases=338009,
        edge_refusals=13,retail_edge_refusals=12,edge_flag_bindings=2,
        ranked_cases=41326,ranked_refusals=1,ranked_retail_refusals=0,
        cost_cases=81928,cost_refusals=3636,cost_budgets=3635,
        cost_retail_refusals=3626,cost_retail_budgets=3626,
        cost_maximum_work=4096,cost_scratch_clears=93240,
        local_cases=56616,local_refusals=3414,local_budgets=3413,
        local_retail_refusals=3412,local_retail_budgets=3412)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-local-{cc}-v2/receipt.json';receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-local-{kind}-{cc}-v2.log';raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix;binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_cost_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded native local route dispatch; wider cost admission remains open',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_cost=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete817DB0 and817170 execute with all earlier native navigation originals in the reference fixture. Policy0/1 selects the distinct ranked variants; all other32-bit values select cost search. Source==target bypasses every inner policy, preserves prior cost and still performs post-routing destination-link admission.',
            'A target represented by an unfiltered current-variant link receives node-level admission first. Known denial returns completed/-1 with all route/link outputs untouched. Inner route failure instead writes source nodes/positions and clears destination_link. Successful routing then clears the link and stores the first admitted target link; unavailable post-admission retains the known route/link=-1 prefix.',
            'Both link passes use the actual current Session variant, even while a previously selected graph remains bound. No copied variant field or automatic rebind is introduced. Actual UpdateOwner composition verifies these aliases and same-node cost-policy bypass.',
            'Both compiler cohorts pass25073840 checks with56616 completed local-dispatch comparisons. Three-policy retail sampling leaves3412 cost-work exhaustions at the lower4096-edge verification profile. One additional synthetic cost exhaustion and one unavailable post-link condition are explicit; unknown source accesses are not executed in the oracle.',
            'Both parent builds and all ten integration tests pass. Actor destination/movement and cross-room traversal are still separate work. Full work/content admission, real asset loading, semantic saves and coherent native game acceptance remain open. No game launched, installed fix, performance diagnosis or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':main()
