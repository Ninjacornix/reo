"""Seal original-compared scene collection through canonical records and Actor."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target=ROOT/'tools/native_reconstruction/native_navigation_scene_candidates_qualification_v1.json'
    assert not target.exists()
    sources,cohorts,parents,binaries,failures={},{},{},{},{}
    observed=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/navigation-scene-{cc}-v2/receipt.json'
        receipt=json.loads(path.read_bytes());data=receipt['observed']
        assert receipt['status']=='passed' and receipt['source_unchanged']
        for key,value in dict(checks=67621991,scene_candidate_cases=7172,scene_actor_cases=131329,
            scene_candidate_refusals=5,cost_cases=82085,local_cases=56772,graph_cost_cases=753667,
            cost_retail_refusals=0,local_retail_refusals=0,graph_original_limited=6725,
            graph_original_total_entries=2000000).items():
            assert data[key]==value,key
        assert observed is None or observed==data
        observed=data
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in receipt['output_sha256'].items():
            assert sha(path.parent/name)==digest,name
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),
            observed={key:value for key,value in data.items() if key!='graph_original_limited_queries'},
            original_limited_rows_in_hashed_receipt=True)
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/navigation-scene-{kind}-{cc}-v1.log'
            raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 10' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_navigation_owner_tests.exe',
            'gameplay_update/libreo_native_gameplay_update.a',
            'gameplay_navigation/libreo_native_gameplay_navigation.a',
            'gameplay_navigation/libreo_native_navigation_visibility.a',
            'gameplay_navigation/CMakeFiles/reo_native_navigation_visibility.dir/scene_candidates.cpp.obj',
            'gameplay_navigation/reo_native_gameplay_navigation_tests.exe']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix
            binaries[path.relative_to(ROOT).as_posix()]=sha(path)
        path=ROOT/f'build-native-sjuni/navigation-scene-{cc}-v1/receipt.json'
        assert json.loads(path.read_bytes())['status']=='failed'
        failures[path.relative_to(ROOT).as_posix()]=sha(path)
    for name in ['game/native/gameplay_update/update.hpp','game/native/gameplay_update/navigation.cpp',
        'game/native/gameplay_update/navigation_tests.cpp','game/native/gameplay_world/world.hpp',
        'game/native/gameplay_scenario/scene_controls.cpp','game/native/gameplay_scenario/scene_controls.hpp',
        'tools/native_reconstruction/animation/world_playback_tests.cpp',
        'tools/native_reconstruction/gameplay_world_oracle/collision_tests.cpp',
        'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
        Path(__file__).relative_to(ROOT).as_posix()]:
        sources[name]=sha(ROOT/name)
    prior=ROOT/'tools/native_reconstruction/native_navigation_cost_adoption_qualification_v1.json'
    target.write_text(json.dumps(dict(schema=1,status='qualified canonical scene candidate collector and actor probe',
        game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,
        cohorts=cohorts,parent_checks=parents,qualified_binaries=binaries,failed_compile_receipts=failures,
        prior_cost_adoption=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)),limitations=[
            'Both compilers pass67621991 identical checks, including7172 completed819DA0 and131329 completed819BC0 original comparisons. Every65536 heading is exercised with two different local-center-Z values; every256 motion class is exercised, plus motion1A with an unused NaN center. Full sampled query XYZ is bit-compared to the original stack, independently of whether geometry matches.',
            'Complete original geometry370490/370760/3707A0/370960/370DD0/371200 and3700C0/370100 with complete SDK sine/cosine reduction/polynomial bodies execute. No overlap, clear-path or host-trig port is substituted. Finite conversion guards admit signed scene X/Z explicitly; the prior heading/sampler domains are retained.',
            'Source1B4 is the canonical local collision center Z, not current radius1B8. Both source World collision and full playback fixtures already establish center1AC..1B4/radius1B8. Actual Owner checks distinguish center54/radius999, radius-only mutation and center-only mutation. No extra actor radius or shadow scene record was added.',
            'Native collection borrows the same128-capacity scene Records used by scripts/collision, traverses newest-to-oldest, preserves enabled/busy/kind85/height semantics and the original pairwise sort excluding the last candidate. Results hold domain/generation identities. Tests cover script disable/re-enable, stale identity after retirement, reuse, full capacity, all kind bytes, height boundaries and actor-versus-query positions. Five explicit missing-geometry/nonfinite/out-of-range profiles refuse; unavailable does not mean an empty completed collection.',
            'Both current parent builds and ten integration tests pass. v1 comparison compilation failed because the original-only context lacked HI1/LO1 and generated tail jumps declared unused entry-PC locals. v2 supplies the context lanes and suppresses that warning only in the generated original translation unit. Original instructions remain word-audited and unchanged; native warnings stay errors.',
            'All prior cost/local graph results remain unchanged, including6725 repeated original-work-limited contexts. Real room loading/provider binding, the remainder of812540, condition-based scene lookup, broader AI/movement/VM/input/network/save owners and coherent native gameplay installation/acceptance remain open. Installed V39 is unchanged; no game launched, incident reproduced or speed improvement measured.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__=='__main__':
    main()
