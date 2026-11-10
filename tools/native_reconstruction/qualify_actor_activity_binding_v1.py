"""Seal the real native behavior activity-publication composition."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_activity_binding_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-activity-binding-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 61281324 and observed['actor_activity_cases'] == 481
        assert observed['actor_activity_deliveries'] == 8 and observed['actor_activity_failures'] == 5
        assert observed['actor_state_cases'] == 589824 and observed['actor_gauge_cases'] == 1049104
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_activity_admission'].startswith('Native World/BehaviorFrameServices/update_behavior/Owner/StatePublication')
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        path = ROOT / f'build-native-sjuni/actor-activity-behavior-{cc}-v2/receipt.json'
        behavior = json.loads(path.read_bytes())
        assert behavior['status'] == 'passed' and behavior['full_original_behavior_body']
        assert behavior['result'] == dict(status='passed', cases=32768, trace_words=2572551)
        cohorts[cc]['behavior'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=behavior['result'])
        for item in [receipt, behavior]:
            for name, digest in item['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in source or source[name] == digest, name
                source[name] = digest
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-activity-binding-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native World and behavior activity publication through canonical update Owner',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'The native adapter now invokes actual periodic/state publication at66B500 activity order when its borrowed Owner is supplied. Without it the old provider remains required; there is no implicit no-op.',
        'Composition covers481 native frame/direct-behavior cases, eight actual state sink observations and five failure/ownership groups. Other frame/action effects are declared test providers; health/hit effects are deliberately unentered for healthy actors.',
        'A separate32768-case comparison executes complete original66B500 and actual666D60/666DB0/667370/1B0310. Status/hit are declared native fixture ports and other action/effect providers remain explicit in that cohort.',
        'Failure retains earlier action/counter/gauge-status changes and stops before secondary dispatch or frame completion. Foreign worlds, detached actors, retired leases and a closed Owner with a live replacement actor refuse.',
        'BAC writers/import, remaining actor message selectors, actual queue/receiver/transport and coherent native game installation/acceptance remain open. InstalledV39 is unchanged.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
