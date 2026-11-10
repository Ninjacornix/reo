"""Seal recovery policy with canonical status, animation, inventory and gauge owners."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_recovery_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 4), ('gcc', 2)]:
        path = ROOT / f'build-native-sjuni/actor-recovery-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and not receipt['focused_recovery_run']
        observed = receipt['observed']
        assert observed['checks'] == 904744826 and observed['actor_recovery_cases'] == 40960
        assert observed['actor_recovery_animation'] == 30510 and observed['actor_recovery_ui'] == 17920
        assert observed['actor_recovery_refusals'] == 45 and observed['actor_recovery_messages'] == 120
        assert observed['actor_recovery_compositions'] == 5
        assert observed['heap_allocations'] == observed['heap_releases'] == 90395
        assert expected is None or expected == observed
        expected = observed
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed,
                           tables=receipt['recovery_tables'], skeletons_sha256=receipt['recovery_skeletons_sha256'])
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-recovery-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    name = 'game/native/gameplay_world/CMakeLists.txt'
    assert 'actor_recovery.cpp' in (ROOT / name).read_text()
    source[name] = sha(ROOT / name)
    result = dict(schema=1, status='qualified native65FCB0 recovery policy and real periodic gauge binding',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete65FCB0 executes through actual6605B0/67E230/65FAB0/5F6800/667370 consumers. The native policy uses canonical UpdateOwner, inventory/resource owners, pose snapshots and health-class logic.',
        'Caller modes0/1 skip animation selection/activation after selecting actions3/11 or3/10. Other low-byte modes use action1/0/1/0 and actual WorldAnimation/Playback. The comparison caught and corrected this new policy before installation.',
        '30510 animation routes use an owned native skeleton with confirmed absent banks. Actual source descriptor selection, body/local-shape metadata, cache fields and channel activation execute. Loaded-clip recovery and representative game acceptance remain open.',
        '120 enabled status/snapshot observations compare through actual messages. Rejected delivery retains the exact status/timer/UI/inventory prefixes. Forty-five refusal groups include unavailable UI/animation, first/second/final message failures, invalid identity, foreign animation, zero health denominator and shutdown.',
        'Five native667420 compositions bind ActorRecovery directly and require the old recovery effect port to stay unentered. Remaining gauge UI and off-room effects, and recovery6E1430, still have declared explicit consumers.',
        'Earlier failed cohorts retain the original branch mistake, incomplete fixture selector/collision/table initialization and GCC strict-warning failure. Corrected fresh cohorts pass without relaxing checks.',
        'The separate65FBA0 zero-health entry and its behavior caller, remaining actions/UI/message transport, semantic native save/load, installation and acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
