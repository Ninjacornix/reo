"""Seal bounded graph adoption through cost/local/actual native Owner APIs."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_cost_adoption_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-adoption-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        data = receipt['observed']
        for key, value in dict(checks=63898732,cost_cases=82085,cost_refusals=10,cost_budgets=9,
            cost_retail_refusals=0,cost_retail_budgets=0,local_cases=56772,
            local_retail_refusals=0,local_retail_budgets=0,graph_cost_cases=753667,
            graph_retail_admitted=20004,graph_retail_equivalent=16378,graph_retail_new=3626,
            graph_retail_refused=0,graph_original_extended=314,graph_original_limited=6725,
            graph_original_total_entries=2000000,graph_original_per_query_limited=45,
            graph_original_global_limited=6680,graph_guard_self_tests=1,
            api_graph_cases=75833,local_api_graph_cases=9561,api_graph_work_maximum=688,
            api_graph_vertex_maximum=5151,original_extended_by_kind=[157,156,1],
            original_limited_by_kind=[3469,3256,0]).items():
            assert data[key] == value, key
        rows = data['graph_original_limited_queries']
        assert len(rows) == 6725
        assert all(len(row)==10 and row[0] in [0,1] and
            (row[-1]==0 and row[-2]==16385 or row[-1]==1 and 1<=row[-2]<=16384) for row in rows)
        assert [sum(row[0]==kind for row in rows) for kind in range(3)] == [3469,3256,0]
        assert sum(row[-1]==0 for row in rows)==45 and sum(row[-1]==1 for row in rows)==6680
        assert receipt['original_cost_observation_limit']['guard_at_test_recursive_label']
        assert receipt['original_cost_observation_limit']['guard_self_test_required']
        assert observed is None or observed == data
        observed = data
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest, name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest, name
        summary = {key: value for key, value in data.items() if key!='graph_original_limited_queries'}
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=summary,
            limited_rows_in_hashed_receipt=True)
        for kind in ['parent','tests']:
            version=2 if cc=='llvm' and kind=='tests' else 1
            path=ROOT/f'build-native-sjuni/navigation-adoption-{kind}-{cc}-v{version}.log'
            raw=path.read_bytes()
            text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe',
            'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj',
            'gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_navigation/libreo_native_gameplay_navigation.a',
            'gameplay_navigation/libreo_native_navigation_visibility.a',
            'gameplay_navigation/CMakeFiles/reo_native_gameplay_navigation.dir/cost_graph.cpp.obj',
            'gameplay_navigation/CMakeFiles/reo_native_gameplay_navigation.dir/cost_routes.cpp.obj',
            'gameplay_navigation/reo_native_gameplay_navigation_tests.exe']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py',__file__]:
        path=Path(name) if Path(name).is_absolute() else ROOT/name
        sources[path.relative_to(ROOT).as_posix()]=sha(path)
    prior=ROOT/'tools/native_reconstruction/native_navigation_cost_graph_qualification_v1.json'
    failed=ROOT/'build-native-sjuni/navigation-adoption-tests-llvm-v1.log'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded graph adoption into cost/local/native Owner APIs',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,candidate_and_parent_binaries=binaries,
        prior_graph=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),
        failed_test_launch=dict(path=failed.relative_to(ROOT).as_posix(),sha256=sha(failed),
            reason='LLVM runtime DLL directory was absent from test PATH; no tests executed. Correct compiler PATH passes all ten without source changes.'),
        limitations=[
            'Both compiler cohorts pass63898732 identical checks. The actual cost API uses the graph solver75833 times; local dispatch uses it9561 times across controlled/retail profiles. All20004 sampled retail cost queries and sampled local queries complete without work-budget refusals. The old enumeration baseline is retained separately:16378 cost queries complete and3626 exhaust its4096-edge profile.',
            'Original-completed comparisons count82085 cost API calls,56772 local calls and753667 separately exercised graph calls. Extended source comparisons complete157 cost API calls,156 local calls and one graph guard self-test.3469 cost and3256 local contexts remain unverified at recorded original-work limits. These are repeated function contexts, not6725 unique incidents or game failures. Exact identities remain in each hashed cohort receipt.',
            'Known-graph dispatch requires a conservative16*N+28 edge-inspection allowance, counts preparation/construction/relaxation/selection and keeps at most2*N*N vertex scans. Measured maxima are688 inspections and5151 vertex scans. First-direct and tiny-budget behavior is preserved. Unknown whole-graph preparation commits nothing and bounded enumeration continues with the remaining budget; unavailable is not converted to no-path.',
            'Both current parent builds and ten integration checks pass. Actual Owner checks exercise an eight-node graph through cost/local APIs, budget13 refusal without output changes, and successful enumeration when only the unvisited target outgoing slot is malformed. Local post-link refusal retains work metadata.',
            'This qualifies native components; installed V39 remains unchanged. No game was launched, slowdown reproduced, speed improvement measured or Stage4 completion claimed. Full AI/movement/scene/stock VM/input/network/save owners and coherent native game installation/acceptance remain open.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
