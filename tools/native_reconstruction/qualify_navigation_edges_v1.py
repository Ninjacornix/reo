"""Seal complete bounded819010 with owned graph flags and actual UpdateOwner."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_navigation_edges_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, binaries = {}, {}, {}, {}
    expected = dict(checks=15688521,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,
        clears=40,bank_cells=327680,bank_visit_cells=6912,bank_clears=20,
        condition_cases=561008,link_cases=2062,link_refusals=3077,
        edge_cases=338009,edge_refusals=13,retail_edge_refusals=12,edge_flag_bindings=2)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/navigation-edges-{cc}-v4/receipt.json'
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
            path = ROOT/f'build-native-sjuni/navigation-edges-{kind}-{cc}-v3.log'
            raw = path.read_bytes();text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe', 'gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/navigation.cpp.obj', 'gameplay_update/libreo_native_gameplay_update.a']:
            path = ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/update.cpp',
        'game/native/gameplay_update/navigation.cpp','game/native/gameplay_update/navigation_tests.cpp',
        'game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_world/world.cpp','game/native/gameplay_scenario/flags.hpp',
        'game/native/gameplay_scenario/flags.cpp','tools/native_reconstruction/gameplay_update_sources.py',
        'tools/native_reconstruction/effect_work_sources.py']:
        sources[name] = sha(ROOT/name)
    historical = ROOT/'tools/native_reconstruction/native_gameplay_navigation_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded native navigation edge admission',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,owner_binaries=binaries,
        correction=dict(historical_path=historical.relative_to(ROOT).as_posix(),historical_sha256=sha(historical),
            superseded_text='The initial narrative incorrectly said r041 descriptor29/node0 ordinal19 equalled its condition count.',
            measured='The encoded count is14. Resource offset138140, room70/variant1, node0 references ordinal19. Production import always used14; only the narrative was wrong. The original historical seal remains unchanged.'),
        limitations=[
            'Complete819010 executes against pinned word-audited original instructions and the14-entry action switch. Equal node codes return1 before graph reads; destination-1 selects the node condition directly. Otherwise the first match among four signed neighbor slots wins, independently of neighbor_count.',
            'Action1..13 uses canonical actor status8/80 gates; action10 bypasses packed predicates. Four packed bytes preserve code1/3 nonzero,2 zero and other/default ignore semantics. Node conditions are consulted only on original eligible paths through the existing condition owner.',
            'Four mutable edge-flag bytes are owned once per immutable loaded graph, initialized from its encoded tail word and retained across same-asset binds and clear/rebind. Duplicate room selections of one graph share their flags. Two controlled complete815E70 comparisons verify pointer-alias/persistence equivalence; actual high-level flag writers remain open.',
            'Both compilers pass15688521 checks including338009 completed edge comparisons, all65536 action words, packed byte/lane combinations and current condition/link/bank regressions. Thirteen edge contexts are unavailable: one synthetic invalid ordinal and twelve controlled retail queries reaching r041 room70/node0 ordinal19 beyond count14. The latter twelve are explicitly asserted in the fixture and are an outstanding native admission/content gate, not repaired assets or an established retail root cause.',
            'Actual UpdateOwner uses the same World bank, actor status/AI-control and its own canonical flag bank. All ten current parent tests pass on both compilers. No game launched, installed fix, physical PS2 exception claim or measured performance change is made. Route policies, actual flag writers, scene/AI execution, semantic saves and coherent native acceptance remain open; Stage4 is incomplete.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
