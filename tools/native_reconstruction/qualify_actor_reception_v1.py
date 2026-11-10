"""Seal typed actor reception, actual equipment reconciliation and bounded queue."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_reception_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected_full = expected_focus = None
    for cc, version in [('llvm', 4), ('gcc', 1)]:
        full_path = ROOT / f'build-native-sjuni/actor-reception-{cc}-v1/receipt.json'
        focus_path = ROOT / f'build-native-sjuni/actor-reception-focus-{cc}-v{version}/receipt.json'
        full, focus = [json.loads(path.read_bytes()) for path in [full_path, focus_path]]
        assert full['source_sha256'] == focus['source_sha256']
        assert full['observed']['checks'] == 951424625
        assert full['observed']['heap_allocations'] == full['observed']['heap_releases'] == 114671
        assert focus['observed'] == dict(checks=20350184, reception_cases=516096,
            reception_equipment=257, reception_refusals=8, reception_queue_cases=147, game_run=False)
        assert expected_full is None or expected_full == full['observed']
        assert expected_focus is None or expected_focus == focus['observed']
        expected_full, expected_focus = full['observed'], focus['observed']
        for kind, path, receipt in [('full', full_path, full), ('focus', focus_path, focus)]:
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            for name, digest in receipt['source_sha256'].items():
                assert sha(ROOT / name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
            for name, digest in receipt['output_sha256'].items():
                assert sha(path.parent / name) == digest, name
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-reception-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text and 'reo_native_gameplay_reception' in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    for name in ['game/native/gameplay_update/CMakeLists.txt', 'game/native/CMakeLists.txt']:
        sources[name] = sha(ROOT / name)
    target.write_text(json.dumps(dict(schema=1, status='qualified native actor reception, equipment tail and bounded queue',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete67ED50 executes selectors4/6/9/10/12/14/15 with original phase/local-echo filtering, notice clear before selected-status filter, initialized payload effects and shared pose/equipment tail. Remaining selector branches are compiled original evidence, not claimed migrated.',
            'Native reception shares World Actor, inventory, alignment and the actual32-record RoomObject Owner. Coordinate receipt updates only X/Z; it does not advance geometry or occupancy ahead of their original stages.',
            'Equipment reconciliation invokes actual native attachment/resource/model owners, then derives the same selected action kind.257 source comparisons use pinned owned assets, signed action bytes, active/inactive or retained models, full-width versus halfword owner tags, and a naturally full64-model pool. Unknown population is an explicit native refusal with retained model/pose prefix.',
            '516096 receiver cases cover all seven branches, phase bytes, local echo, all eight primary channels, selected-status suppression, raw float/angle values, inventory and signed room coordinates.147 queue checks compose actual UpdateOwner publication through bounded owned messages into the same receiver, including payload lifetime, FIFO/budget/full/wrap/close and consumed partial failures.',
            'The queue allocates its storage at construction. Unsupported message families and absent mapped-room routing return unavailable. A failed receiver consumes that one queued value before reporting error, because its state prefix may already have committed; it is never silently replayed.',
            'Full cohorts pass951424625 checks and114671 balanced original allocations/releases. Component counters are printed by focused cohorts with exactly identical frozen sources and compiler identities; the full aggregate retains its previous output fields. Both compiler observations match. Parent builds include the actual reception/queue library and all eight integration checks pass.',
            'Actual network authentication/encoding/transport, remaining senders3/8/11, other receivers/actions/AI, semantic saves and installed gameplay acceptance remain open. This is not whole Stage4 or a measured slowdown fix; installedV39 is unchanged.'
        ]), indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
