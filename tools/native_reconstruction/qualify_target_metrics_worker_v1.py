"""Seal actual target cache adoption in the native collision frame worker."""
import json
from seal_gameplay_component import ROOT,sha
if __name__=='__main__':
    target=ROOT/'tools/native_reconstruction/native_target_metrics_worker_qualification_v1.json';assert not target.exists()
    prior='tools/native_reconstruction/native_target_metrics_qualification_v1.json'
    assert sha(ROOT/prior)=='e3a969b1009419983e8e94e472fc104eeb62045d3972b82c1df15529270bd3fd'
    previous=json.loads((ROOT/prior).read_bytes())
    for name in ['game/native/gameplay_world/target_metrics.cpp','game/native/gameplay_world/world.cpp','game/native/gameplay_collision/trace.cpp']:
        assert sha(ROOT/name)==previous['source_sha256'][name],name
    paths=['game/native/gameplay_update/collision_workers.cpp','game/native/gameplay_update/collision_workers.hpp','game/native/gameplay_update/collision_workers_tests.cpp',
        'game/native/gameplay_update/update.cpp','game/native/gameplay_update/CMakeLists.txt','game/native/gameplay_world/target_metrics.hpp','game/native/gameplay_world/target_metrics.cpp',
        'tools/native_reconstruction/qualify_target_metrics_worker_v1.py']
    results={}
    for cc in ['llvm','gcc']:
        for kind in ['parent','tests']:
            path=ROOT/f'build-native-sjuni/target-metrics-worker-{kind}-{cc}-v1.log';raw=path.read_bytes();text=raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 13' in text and 'native_gameplay_collision_workers' in text) if kind=='tests' else ('FAILED:' not in text and 'error:' not in text)
            results[path.relative_to(ROOT).as_posix()]=sha(path)
        for suffix in ['gameplay_update/gameplay_collision_workers_tests.exe','gameplay_update/CMakeFiles/reo_native_gameplay_update.dir/collision_workers.cpp.obj','gameplay_world/CMakeFiles/reo_native_gameplay_world.dir/target_metrics.cpp.obj']:
            path=ROOT/f'build-native-sjuni/gameplay-native-{cc}-v1'/suffix;results[path.relative_to(ROOT).as_posix()]=sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native target metrics worker adoption',game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256={name:sha(ROOT/name) for name in paths},results=results,prior=dict(path=prior,sha256=sha(ROOT/prior)),limitations=[
            'Actual CollisionWorkers intercepts the existing target_caches stage after the established pause gate and before World primary updates. It obtains the current canonical room and publishes through the existing World TargetMetricCache. Its algorithm source and room/trace dependencies retain their prior qualified hashes.',
            'Actual frame test builds two primary metrics to a canonical linked target with native models and real Grid consumers. The cache is built before actor motion, the paused frame does not acquire the room, and acquisition failure invalidates the prior published view and stops before later workers. Existing body/height failure and recovery checks remain.',
            'Thirteen current parent tests pass on both compilers. This is native worker composition with remaining game effects declared, not an installed game caller. Real room/model/targeting construction, full observations/actions, VM/network/save integration and game acceptance remain open. V39 is unchanged.'
        ]),indent=2)+'\n');print(sha(target))
