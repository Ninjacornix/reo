"""Seal separately callable bounded cost graph candidate and honest reference-work evidence."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_cost_graph_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    observed = None
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-graph-{cc}-v6/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        for key, value in dict(checks=63606968,actor_route_cases=8205,actor_action_cases=8211,
            actor_route_refusals=1,actor_route_corrected_cases=2304,actor_route_retail_cases=13336,
            cross_search_cases=259,cross_route_cases=4473,cross_corrected_cases=3617,
            destination_cases=15884,destination_refusals=2,destination_corrected_cases=4608,destination_retail_cases=6668,
            visibility_cases=68,visible_nearest_cases=3408,visibility_refusals=2,visibility_retail_cases=3334,node_policy_cases=6144,node_choice_cases=480,node_choice_refusals=0,
            graph_cost_cases=753902,graph_cost_refusals=1,graph_admission_maximum=204,graph_relaxation_maximum=284,graph_scan_maximum=5151,
            graph_retail_admitted=20004,graph_retail_equivalent=16378,graph_retail_new=3626,graph_retail_refused=0,
            graph_original_extended=236,graph_original_limited=3391,graph_original_total_entries=2000000,
            graph_original_per_query_limited=49,graph_original_global_limited=3342,graph_guard_self_tests=1).items():
            assert receipt['observed'][key] == value
        rows = receipt['observed']['graph_original_limited_queries']
        assert len(rows) == 3391 and sum(row[-1]==0 for row in rows) == 49 and sum(row[-1]==1 for row in rows) == 3342
        assert all(len(row)==9 and (row[-1]==0 and row[-2]==16385 or row[-1]==1 and 1<=row[-2]<=16384) for row in rows)
        assert receipt['original_cost_observation_limit']['guard_at_test_recursive_label']
        assert receipt['original_cost_observation_limit']['guard_self_test_required']
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
            path = ROOT/f'build-native-sjuni/navigation-graph-{kind}-{cc}-v3.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a', 'gameplay_navigation/libreo_native_gameplay_navigation.a', 'gameplay_navigation/libreo_native_navigation_visibility.a', 'gameplay_navigation/CMakeFiles/reo_native_gameplay_navigation.dir/cost_graph.cpp.obj', 'gameplay_navigation/reo_native_gameplay_navigation_tests.exe']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:
        sources[name] = sha(ROOT/name)
    prior = ROOT/'tools/native_reconstruction/native_navigation_visibility_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified separately callable graph cost candidate; default API adoption and game acceptance remain open',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,candidate_and_parent_binaries=binaries,
        prior_visibility=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compilers pass63606968 checks with753902 completed graph-candidate original comparisons.753666 controlled calls cover all4096 directed four-node graphs across three weights/all endpoints,8192 seeded four-node graphs and4096 seeded six-node graphs with self/duplicate edges, full halfword weights, status gates and zero cycles, plus explicit root-self and zero-cycle secondary counterexamples. One controlled unknown graph refuses without output changes.',
            'The candidate admits all20004 sampled retail-data queries.16378 agree with the existing native results already checked against complete originals.235 additional formerly over-budget retail queries finish extended original comparisons; one separate two-entry guard self-test also contributes to236 extended completions.3391 retail queries remain source-unverified at observation limits:49 query limits and3342 total-work limits. Their exact room/variant/endpoints/status/flags/slot identities and limit reason are retained as structured rows. These are not diagnosed game incidents.',
            'The graph proof preserves recursive forced direct-target terminals, root direct cost/secondary retention, root self entry and source-ordered secondary choice excluding both the root and recursive owner. Nonnegative u16 path sums below2^23 permit exact integral distance computation in this bounded128-node FP32 profile. Whole-graph admission is deliberately conservative and must not be substituted for no-path when predicates are unknown.',
            'Measured candidate work maxima across these profiles are204 edge admissions,284 incoming-edge relaxations and5151 vertex scans. The implementation has fixed arrays and at most two128-by128 vertex passes. These are operation counts, not a measured game-speed improvement or incident root cause.',
            'v1/v2 candidate and baseline comparisons passed. Extended v3/v4 reference runs timed out because a dispatcher-only guard missed recursive jumps to an internal label. v5 setup caught CRLF in the label match. v6 adds an observation callback at the generated test-only recursive entry label, preserves every source instruction, verifies both entries in a known two-entry call and records per-query16384/total2000000 entry limits separately. Failed evidence is retained; no failed run is counted as a source match.',
            'Both current parent builds and all ten integration checks pass. The candidate is separately callable; the current bounded-cost API and installed V39 still select the existing algorithm. Adoption must preserve low-budget/direct-edge behavior, honest work accounting, bounded handling of unknown graph data and actual local/Owner consumers. Real scene loading, remaining AI/VM/input/network owners, semantic saves and coherent native game installation/acceptance remain open. No game launched or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
