"""Seal terminal countdown through actual inventory, pose and frame consumers."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_terminal_timer_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 2), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-terminal-timer-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 709511182 and observed['terminal_timer_cases'] == 396288
        assert observed['terminal_timer_transitions'] == 3072 and observed['terminal_timer_live'] == 16
        assert observed['terminal_timer_compositions'] == 2 and observed['terminal_timer_refusals'] == 4
        assert observed['heap_allocations'] == observed['heap_releases'] == 89597
        assert expected is None or expected == observed
        expected = observed
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        path = ROOT / f'build-native-sjuni/actor-terminal-behavior-{cc}-v1/receipt.json'
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
            path = ROOT / f'build-native-sjuni/stage4-actor-terminal-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    name = 'game/native/gameplay_world/CMakeLists.txt'
    assert 'actor_terminal_timer.cpp' in (ROOT / name).read_text()
    source[name] = sha(ROOT / name)
    result = dict(schema=1, status='qualified native actor terminal countdown through actual inventory, pose and behavior consumers',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete6687A0 executes with actual5F6800/auxiliary lists/resource-frame release and667370 pose snapshot. GaugeBAC zeroing establishes a known value even when its earlier value was unavailable.',
        'C62 is a separate unsigned halfword countdown. It preserves direct-call absence of a pause gate and clock-mode0 versus nonzero reset21600/10800; no host-time or callback-to-global-frame conversion is introduced.',
        'The native frame composition binds the real terminal timer and actual action7 notice through UpdateOwner. Other frame/action providers and transition selector5 notification remain explicit declared providers in those two cases.',
        'Fresh32768-case complete-original behavior regressions preserve the unbound required-provider path. Other actor actions, periodic667420 progression, initialization/import, transport, semantic save/load and game installation/acceptance remain open.',
        'InstalledV39 is unchanged. This is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
