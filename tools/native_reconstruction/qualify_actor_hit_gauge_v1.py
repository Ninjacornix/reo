"""Seal actual pending-hit gauge application and canonical control-counter reset."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_hit_gauge_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 2), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-hit-gauge-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 70212138 and observed['hit_gauge_cases'] == 8192
        assert observed['hit_gauge_events'] == 5443 and observed['hit_gauge_failures'] == 3
        assert observed['gauge_adjustment_cases'] == 720920 and observed['actor_activity_cases'] == 481
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_hit_gauge_admission'].startswith('Actual native World/behavior/pending-hit/gauge/cooperative pool')
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        entries = [receipt]
        for kind in ['hit', 'behavior']:
            path = ROOT / f'build-native-sjuni/actor-hit-gauge-{kind}-{cc}-v1/receipt.json'
            item = json.loads(path.read_bytes())
            if kind == 'hit':
                assert item['source_unchanged'] and item['status'].startswith('native pending-hit response matches')
                assert item['observed'] == dict(cases=131072, ordered_trace_words=718877, invalid_timer_case=True, game_run=False)
            else:
                assert item['status'] == 'passed' and item['full_original_behavior_body']
                assert item['result'] == dict(status='passed', cases=32768, trace_words=2572551)
            entries.append(item)
            cohorts[cc][kind] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path))
        for item in entries:
            for name, digest in item['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in source or source[name] == digest, name
                source[name] = digest
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-hit-gauge-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native pending-hit gauge consumer and canonical D28 reset through World/behavior/update Owner',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'The native World/frame/behavior chain now applies pending-hit gauge amounts through the actual Owner/Events/clock when a borrowed GaugeApplication is supplied. Without it progression remains a required HitServices provider.',
        'Original666D90 resets actorD28 for class0. That field now belongs once to HitActor, is inherited by WorldActor and is cleared directly; the mislabeled clear_owner_interaction provider and fixture shadow counter were removed.',
        '8192 composition cases execute complete original660AF0 with actual660060/666620/666D90 and gauge/event helpers on the controlled numeric80 damage/800000 retained-action branch. UI-close, statistics and final-contact effects remain declared ports.',
        'Fresh131072-case original hit and32768-case original behavior regressions pass. Their remaining declared service/action effects are not silently promoted to qualified native consumers.',
        'Capability failure retains consumed-hit, transient cleanup, notice and control-counter effects before later statistics/contact/behavior/action work. Foreign worlds/detached actors and a closed Owner with a live actor refuse.',
        'Other hit effects/callers, periodic667420 progression, gauge import, remaining actors/opcodes/save/transport and coherent native game installation/acceptance remain open. InstalledV39 is unchanged.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
