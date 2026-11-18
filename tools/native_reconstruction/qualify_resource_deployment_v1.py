"""Seal current resource deployment comparisons and parent integration checks."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_deployment_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for name in ['resource-deployment-llvm-v7', 'resource-deployment-gcc-v1']:
        path = ROOT / 'build-native-sjuni' / name / 'receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['deployment_cases'] == 7680 and observed['deployment_effects'] == 7680
        assert observed['deployment_lifecycle'] == 360 and observed['deployment_capacity'] == 7920
        assert observed['deployment_frontends'] == 1720320 and observed['deployment_refusals'] == 720
        assert not observed['game_run']
        assert expected is None or expected == observed
        expected = observed
        for name_, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name_) == digest, name_
            assert name_ not in source or source[name_] == digest, name_
            source[name_] = digest
        cohorts[name] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
    for name in ['game/native/gameplay_world/CMakeLists.txt', 'game/native/gameplay_world/owned_resource_recipes_tests.cpp', 'game/native/gameplay_update/cooperative_events_tests.cpp']:
        source[name] = sha(ROOT / name)
    for cc in ['llvm', 'gcc']:
        for kind in ['parent', 'tests']:
            version = 2 if kind == 'parent' else 1
            path = ROOT / f'build-native-sjuni/stage4-resource-deployment-{kind}-{cc}-v{version}.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified admitted native resource deployment, count, admission and typed position messages', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Placement requires admitted finite coordinates, canonical owners, primary assets and actual bound companion/floor consumers.',
        'Final message queue/transport and room authority remain explicit ports; dispatch completion does not prove delivery.',
        'Original primary/secondary retention and duplicate model counting are preserved, including full-capacity conversion prefixes.',
        'Outer item effects, weapon depletion, remaining gameplay families, real installation and coherent scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))

if __name__ == '__main__':
    main()
