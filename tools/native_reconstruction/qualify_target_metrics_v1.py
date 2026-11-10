"""Seal the native World target-cache rebuild and explicit scratch correction."""
import json
from seal_gameplay_component import ROOT,seal,sha
if __name__=='__main__':
    prior='tools/native_reconstruction/native_target_cache_scratch_audit_v1.json'
    assert sha(ROOT/prior)=='4095dd1e5c165df4171ad37a0eee89c9c546da7b6ea32b000f8b9437c362374b'
    evidence=[]
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/target-metrics-trace-{cc}-v1/receipt.json';receipt=json.loads(path.read_bytes())
        assert receipt['status']=='native collision trace comparisons passed' and receipt['results']==dict(checks=482015,maximum_error=0,owned_assets=366,owned_triangles=22363,declared_numeric_ports=True,game_launched=False)
        for name,digest in receipt['source_sha256'].items():assert sha(ROOT/name)==digest,name
        for name,digest in receipt['output_sha256'].items():assert sha(path.parent/name)==digest,name
        evidence.append(path.relative_to(ROOT).as_posix())
        for version in [1,2]:
            name=f'build-native-sjuni/target-metrics-{cc}-v{version}/receipt.json';assert json.loads((ROOT/name).read_bytes())['status']=='failed';evidence.append(name)
        evidence.extend([f'build-native-sjuni/target-metrics-compile-{cc}-v1.log',f'build-native-sjuni/target-metrics-parent-{cc}-v1.log',f'build-native-sjuni/target-metrics-tests-{cc}-v1.log'])
    seal(target='tools/native_reconstruction/native_target_metrics_qualification_v1.json',suite='target-metrics',receipt_version=3,parent_version=2,
        status='qualified native World target metric cache with explicit initialized work policy',test_count=13,
        expected=dict(checks=5781399,profiles=192,strict_profiles=75,corrected_profiles=192,unknown_profiles=117,
            pairs=22218,wall_queries=3639,floor_queries=6426,sorts=4744,comparisons=380102,swaps=54259,refusals=3,
            original_sorts=31860,original_comparisons=11420860,floor_hits=276,near_wall_hits=0),
        extra_sources=['game/native/CMakeLists.txt','game/native/gameplay_collision/CMakeLists.txt',
            'tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/effect_work_sources.py',
            'tools/native_reconstruction/qualify_target_metrics_v1.py'],
        binaries=['gameplay_world/gameplay_target_metrics_tests.exe','gameplay_world/libreo_native_gameplay_world.a',
            'gameplay_world/CMakeFiles/reo_native_gameplay_world.dir/target_metrics.cpp.obj',
            'gameplay_world/CMakeFiles/reo_native_gameplay_world.dir/world.cpp.obj',
            'gameplay_collision/libreo_native_gameplay_collision.a','gameplay_collision/CMakeFiles/reo_native_gameplay_collision.dir/trace.cpp.obj'],
        prior=prior,additional_evidence=evidence,
        ports=['376E70 finite direction through existing native heading helper','579980 and57D630 actual native Grid wall/floor consumers with audited arguments'],
        limitations=[
            'Actual World-owned cache rebuild borrows the8 primary,10 auxiliary and50 linked physical slots, canonical model world translations and room Grid inputs. Native production contains no guest state. Held cache metrics are bound to source and target generation identities; lifetime replacement invalidates previous cells, while known skipped cells retain their values for the same identity.',
            'Both compilers pass5781399 checks across192 profiles and22218 metrics.75 naturally defined profiles compare strict original outputs;117 original calls reach unwritten scratch and are not counted as strict comparisons. All192 compare the separately initialized source profile, including the sparse-primary compact/physical order asymmetry, status/mode/model/room gates and all untouched output bytes.',
            'Only two68x68 work arrays receive the explicit finite-maximum initialization, preserving source reuse across all three sorting phases. The first finite row sort is retained; subsequent passes can make no further swaps. The same controlled initialized profile produces4744 native sort calls/380102 comparisons versus31860 original calls/11420860 comparisons. This is operation-count evidence, not measured game speed.',
            'Complete original rebuild, pairwise sort, raw-mode chain and XYZ distance execute. Existing heading and actual Grid consumers are declared comparison ports. Current trace regression independently passes482015 checks across366 owned grids/22363 triangles per compiler, including the checked floor API preserving the original boolean wrapper. Cache fixture exercises276 floor hits and both far-wall and clear near-wall branches; no near-wall hit is claimed in that fixture.',
            'First native GCC setup rejected misleading indentation, fixed without suppressing warnings. v1/v2 reference comparisons exposed incorrect work count for primary-to-auxiliary sorting: it uses compact active sources, physical counts and a compact-count inverse limit. v3 preserves that asymmetry and adds sparse primary profiles. Parent v2 rebuilds the final source and all thirteen tests pass.',
            'The actual frame worker hookup, complete812540 observations, real model/room/targeting producers, remaining AI/actions/VM/network/save integration and coherent native gameplay acceptance remain open. V39 remains installed. No game run or stutter fix is claimed.'
        ])
