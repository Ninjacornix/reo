"""Seal selected-gauge helpers, actor state publication and its periodic caller."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_state_message_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-state-message-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 61277948 and observed['actor_state_cases'] == 589824
        assert observed['actor_state_messages'] == 231652 and observed['actor_state_lookups'] == 116869
        assert observed['actor_state_refusals'] == 9 and observed['actor_gauge_cases'] == 1049104
        assert observed['actor_state_class_cases'] == 65536 and observed['actor_periodic_cases'] == 131072
        assert observed['actor_clock_cases'] == 60
        assert observed['actor_status_messages'] == 23080 and observed['actor_action_messages'] == 231448
        assert observed['actor_action_requests'] == 124301 and observed['actor_inventory_messages'] == 116624
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_state_admission'].startswith('Complete664D00/664F60/667F90/668C80')
        assert receipt['actor_gauge_limits']['sha256'] == 'b93e890c9c05473f981cb841891bc3d973f8ddfa50d5674972cf65b46c93f1b0'
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-state-message-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native actor state publication, selected gauge helpers and periodic caller',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'BAC gauge state is optional until its actual producer/import owns it. Missing selected actors, unsupported character profiles and absent gauge values refuse after any earlier status mutation.',
        'Complete664D00/664F60/667F90/668C80 execute against original instruction-word audits. The eight denominator words match owned File#1 US71ADB0. Exceptional PS2 floating point is not qualified.',
        'Selector2 uses dispatch mode2, raw XYZ, signed yaw and selected gauge band. Unknown trailing stack padding is omitted; this typed object is not a packed network format.',
        'The periodic facade reads the actual bound UpdateOwner clock. Outer66B500 activity-notice binding, gauge writers/import, queue/receiver/transport and coherent native game installation remain open.',
        'InstalledV39 is unchanged. This component is not whole native gameplay or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
