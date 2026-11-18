"""Seal periodic gauge policy with actual inventory, event and behavior consumers."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_gauge_progression_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 3), ('gcc', 2)]:
        path = ROOT / f'build-native-sjuni/actor-gauge-progression-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 891370284 and observed['gauge_progression_cases'] == 543744
        assert observed['gauge_progression_callbacks'] == 142664 and observed['gauge_progression_live'] == 16
        assert observed['gauge_progression_compositions'] == 3 and observed['gauge_progression_refusals'] == 12
        assert observed['gauge_progression_recoveries'] == 3072 and observed['gauge_progression_notifications'] == 19082
        assert observed['heap_allocations'] == observed['heap_releases'] == 90290
        assert expected is None or expected == observed
        expected = observed
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed,
                           owned_tables=receipt['gauge_progression_tables'])
        path = ROOT / f'build-native-sjuni/actor-progression-behavior-{cc}-v1/receipt.json'
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
            path = ROOT / f'build-native-sjuni/actor-progression-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    name = 'game/native/gameplay_world/CMakeLists.txt'
    assert 'actor_gauge_progression.cpp' in (ROOT / name).read_text()
    source[name] = sha(ROOT / name)
    result = dict(schema=1, status='qualified periodic gauge policy through native inventory, event, pose and behavior owners',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete667420 uses actual source inventory/resource retirement, modifier helpers, threshold events and pose snapshots. UI6DF160/6DEE80/6E1430, recovery65FCB0 and notification81C690 remain declared effect ports, not migrated consumers.',
        'All eight rates/scales/caps are compared against pinned owned bytes. Only finite bounded arithmetic is admitted; exceptional physicalPS2 floating behavior is not claimed. Original per-invocation steps2/60 and subsecond admission are retained.',
        'Three native World/frame/behavior compositions bind actual progression, terminal timing and later action7 publication. Remaining actions, activity publication and transition selector5 are declared providers in those cases.',
        'Twelve refusal groups include all five effect frontiers and closed event-pool prefixes: below-cap gauge storage waits for the event consumer; cap health, inventory, flags and UI prefix remain committed before failure.',
        'Fresh complete-original behavior regressions preserve the unbound required-provider path. UI/recovery/other actions, semantic native save/load, real caller installation and representative game acceptance remain open.',
        'InstalledV39 is unchanged. This is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
