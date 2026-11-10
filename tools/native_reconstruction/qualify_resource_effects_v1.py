"""Seal current full item-effect dispatch and native lifecycle evidence."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_effects_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for name in ['resource-effects-llvm-v4', 'resource-effects-gcc-v2']:
        path = ROOT / 'build-native-sjuni' / name / 'receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['effect_cases'] == 95238 and observed['effect_depletions'] == 1035
        assert observed['effect_deployments'] == 6348 and observed['effect_mutations'] == 294
        assert observed['effect_refusals'] == 36 and not observed['game_run']
        assert expected is None or expected == observed
        expected = observed
        for name_, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name_) == digest, name_
            assert name_ not in source or source[name_] == digest, name_
            source[name_] = digest
        cohorts[name] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
    for name in ['game/native/gameplay_world/CMakeLists.txt', 'game/native/gameplay_world/owned_resource_recipes_tests.cpp']:
        source[name] = sha(ROOT / name)
    for cc in ['llvm', 'gcc']:
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-resource-effects-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified complete native item-effect admission, healing/deployment dispatch and post-effect lifecycle', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Primary resource-owner domain1..4; missing extended actors remain unavailable rather than source-array alias emulation.',
        'Actual UI/device/text, room authority and final network queue/transport remain declared required consumers.',
        'Known capability-failure mutation prefixes remain visible and do not invent later quantity or retirement success.',
        'Weapon depletion/cost, ownership/transfer, remaining gameplay families, installation and coherent scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))

if __name__ == '__main__':
    main()
