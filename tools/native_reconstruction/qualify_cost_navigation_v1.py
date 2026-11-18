"""Seal bounded-work native cost routing; retain unadmitted retail searches."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_cost_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=23092224,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=40,bank_cells=327680,bank_visit_cells=6912,bank_clears=20,
        condition_cases=561008,link_cases=2062,link_refusals=3077,edge_cases=338009,
        edge_refusals=13,retail_edge_refusals=12,edge_flag_bindings=2,
        ranked_cases=41326,ranked_refusals=1,ranked_retail_refusals=0,
        cost_cases=81928,cost_refusals=3636,cost_budgets=3635,
        cost_retail_refusals=3626,cost_retail_budgets=3626,
        cost_maximum_work=4096,cost_scratch_clears=80037)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-cost-{cc}-v1/receipt.json';receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/navigation-cost-{kind}-{cc}-v1.log';raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
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
    prior = ROOT/'tools/native_reconstruction/native_ranked_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded-work native cost routing component; retail work admission remains partial',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        prior_ranked=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Complete818B70/818E30 execute against pinned word-audited originals for completed native searches. Native work is bounded by an explicit caller-visible edge budget; exhaustion returns unavailable, with no approximate route committed. The original has no such explicit budget; this is native admission, not a matched original failure.',
            'This policy ignores actor occupancy, searches all four slots with local visited scratch and preserves10000 sentinel, strict comparisons, direct-target early exits, earlier secondary/cost retention and failure outputs. A later direct edge can retain an earlier recursive secondary/cost; a direct edge inside recursion can replace a cheaper prior branch. Source==target writes10000, while failure leaves existing output cost untouched.',
            'Both compiler cohorts pass23092224 checks with81928 completed cost comparisons. Synthetic cases exercise all65536 cost halfwords, slot/cost ordering, sentinel boundaries, direct/recursive/cyclic paths, occupancy independence and exact budget boundaries. Nine synthetic work exhaustions and one invalid-node refusal are explicit.',
            'The five retail inputs contribute20004 sampled cost queries at a deliberately lower4096-edge verification budget:16378 complete and compare,3626 exhaust before original execution. These3626 contexts are not claimed qualified or diagnosed slowdowns. The default API allowance65536 is distinct from this test profile and has not closed that broader retail admission gap.',
            'The actual UpdateOwner query uses the same actor, graph, status and canonical flag bank. Both parent builds and all ten integration tests pass. Source107C68 is a declared bounded original-only zero/FF fill port; native code has no guest memory or register machine.',
            'Outer/cross-room route dispatch, actor/AI execution, out-of-profile content and work admission, real loading, semantic saves and coherent native game acceptance remain open. No live game, installed performance fix or Stage4 completion is claimed.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':main()
