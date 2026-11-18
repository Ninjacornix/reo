"""Seal zero-health transitions through actual native inventory and behavior owners."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_zero_health_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-zero-health-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        assert not receipt['focused_recovery_run'] and not receipt['focused_zero_health_run']
        observed = receipt['observed']
        assert observed['checks'] == 930875421
        assert observed['zero_health_cases'] == observed['zero_health_parent_cases'] == 40960
        assert observed['zero_health_messages'] == 80 and observed['zero_health_models'] == 16
        assert observed['zero_health_compositions'] == 3 and observed['zero_health_refusals'] == 25
        assert observed['heap_allocations'] == observed['heap_releases'] == 90899
        assert expected is None or expected == observed
        expected = observed
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        inputs = [receipt]
        for kind in ['status', 'behavior']:
            path = ROOT / f'build-native-sjuni/actor-zero-health-{kind}-{cc}-v1/receipt.json'
            regression = json.loads(path.read_bytes())
            if kind == 'status':
                assert regression['status'] == 'native actor status timers and actions match seven complete original bodies'
                assert regression['source_unchanged'] and regression['observed'] == dict(cases=163840, ordered_trace_words=189996, rng_requests=32768, original_bodies_executed=7, game_run=False)
            else:
                assert regression['status'] == 'passed'
                assert regression['full_original_behavior_body'] and regression['result'] == dict(status='passed', cases=32768, trace_words=2572551)
            cohorts[cc][kind] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=regression.get('observed', regression.get('result')))
            inputs.append(regression)
        for item in inputs:
            for name, digest in item['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in source or source[name] == digest
                source[name] = digest
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-zero-health-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native65FBA0 and6607D0 through canonical inventory, pose, message and behavior owners',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete65FBA0 reuses canonical response_flags143 and retains source ordering around actual5F6800,667370 and67E230 selector1. Complete6607D0 uses the same native status core with optional actual effects, without duplicating its policy.',
        '40960 direct and40960 parent cases cover gates, timer/phase/status/response flags, category and locality over five actual ITEM banks. Eighty enabled snapshots compare, and16 actual primary/shared-secondary model cases cover retirement and nonlocal rejection.',
        'Three native World/frame/behavior compositions bind actual zero-health, pending-hit gauge, progression, terminal timing and later action7 notice. Other action/frame effects and transition selector5 remain declared providers. Rejected early snapshot or later notice retains the corresponding prefix.',
        'Twenty-five refusal groups include rejected snapshots, foreign World/Actor, invalid identity and shutdown. The status163840-case and behavior32768-case original regressions preserve unbound required-provider behavior.',
        'The initial fixture had an ambiguous sink name and compared uninitialized unused descriptor/gauge cells. Corrected tests explicitly seed those controlled inputs. Failed/canceled cohorts remain retained; production does not acquire guessed zero defaults.',
        'Actual UI, remaining actor actions and message transport, semantic native saves, initialization/import and game installation/acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
