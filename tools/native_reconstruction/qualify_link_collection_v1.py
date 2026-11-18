"""Seal bounded known-cost link collection and observed lower cost writes."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_link_collection_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=28556205,nearest_cases=26930,action_cases=265608,
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
        local_retail_refusals=3412,local_retail_budgets=3412,
        collection_cases=26401,collection_entries=31767,collection_refusals=290,
        collection_unknown_costs=289,collection_retail_refusals=288,
        collection_retail_unknown_costs=288)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-collection-{cc}-v2/receipt.json';receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-collection-{kind}-{cc}-v1.log';raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
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
    prior = ROOT/'tools/native_reconstruction/native_local_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded known-cost link collection; unknown initial-cost contexts remain open',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_local=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete8179F0 executes with the existing complete route/condition originals. Both endpoint directions use policy1. Omission controls node/XYZ output copying, not policy selection. Exact pairwise sort and indirect tie reordering are preserved with associated metadata.',
            'Native collection uses a bounded16-candidate value array and actual visit masks. All five pinned inputs have at most13 raw links per room/variant. Source append bounds are unchecked; native capacity refusal is an explicit admission boundary. The current256-link input budget also keeps source LBU/SH id swaps within the admitted width.',
            'The source body does not initialize its incoming cost scratch. Native initial_cost is optional and no invented zero is consumed: lower-query cost_written metadata identifies actual assignments, including failed-prefix writes. Unknown cost is unavailable only when an admitted candidate needs it. last_cost tracks known query/sort scratch; it is not another persisted game owner.',
            'A test-only observer records actual original cost-address writes without changing original memory effects. Metadata compares across41326 ranked,81928 cost and56616 local-dispatch calls, including equal-value assignments that value comparison alone cannot detect. Controlled collector initial seeds or proven earlier writes are explicit inputs, not a claim of captured live-game stack values.',
            'Both compilers pass28556205 checks with26401 completed collections and31767 entries.288 sampled retail queries with deliberately unknown initial-cost profiles require that missing value; one synthetic unknown case and one capacity refusal are explicit. These are not288 diagnosed retail bugs or measured slowdowns. Both parent builds and all ten integration tests pass.',
            'Actual UpdateOwner uses its own World actor, canonical current variant/flags and the same actor visit mask. Recursive cross-room traversal, an accepted initialization policy or real known producer, actor destination/AI mutation, broader work/content admission, real loading, semantic saves and coherent native game acceptance remain open. No game launched, installed fix or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':main()
