"""Seal native resource debris, shared visual lifetime and regression evidence."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_debris_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for name in ['resource-debris-llvm-v5', 'resource-debris-gcc-v1', 'resource-debris-vm-llvm-v1', 'resource-debris-vm-gcc-v1']:
        path = ROOT / 'build-native-sjuni' / name / 'receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed'
        observed = receipt.get('observed', receipt.get('result'))
        if '-vm-' in name:
            assert observed['checks'] == 14080853 and not receipt['pinned_shared_sources']
        else:
            assert receipt['source_unchanged'] and observed['checks'] == 265223723
            assert observed['debris_cases'] == 65968 and observed['debris_frames'] == 70248
            assert observed['debris_capacity'] == 48 and observed['debris_refusals'] == 48 and observed['debris_child_full'] == 6
            assert expected is None or expected == observed
            expected = observed
            obj = ROOT / 'build-native-sjuni' / name / receipt['original_object']['object']
            assert sha(obj) == receipt['original_object']['object_sha256']
        for name_, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name_) == digest, name_
            assert name_ not in source or source[name_] == digest, name_
            source[name_] = digest
        cohorts[name] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
    for name in ['game/native/gameplay_effects/CMakeLists.txt', 'game/native/gameplay_world/CMakeLists.txt']:
        source[name] = sha(ROOT / name)
    for cc in ['llvm', 'gcc']:
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-resource-debris-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    paths = [ROOT / f'build-native-sjuni/resource-debris-llvm-v{v}/receipt.json' for v in [3,4,5]]
    before, separated, reused = [json.loads(p.read_bytes()) for p in paths]
    assert before['observed'] == separated['observed'] and before['original_owned_bodies'] == separated['original_owned_bodies']
    for name_, digest in before['source_sha256'].items():
        if name_.startswith('game/native/'):
            assert separated['source_sha256'][name_] == digest
    assert reused['original_object']['cache_hit'] and reused['original_object']['identity'] == separated['original_object']['identity']
    assert reused['original_object']['object_sha256'] == separated['original_object']['object_sha256']
    transition = dict(receipts={p.relative_to(ROOT).as_posix():sha(p) for p in paths}, observations_equal_before_after_separation=True, owned_bodies_equal=True, exact_object_reused_after_fixture_change=True)
    result = dict(schema=1, status='qualified native resource debris construction, ballistic lifetime, shared capacity and actual floor consumer', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, original_object_transition=transition, limitations=[
        'Finite native pose/integration profile; unknown phase and unavailable current room/factory explicitly refuse.',
        '57D560 delegates to actual canonical trace.floor and controlled room geometry; independent trace internals are not requalified here.',
        'No sampled child rendering is invented for this constructor/lifetime; typed state is retained for Stage5 submission.',
        'Weapon depletion/cost, other gameplay owners/callers, real installation and coherent scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))

if __name__ == '__main__':
    main()
