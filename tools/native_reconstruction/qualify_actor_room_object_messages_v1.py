"""Seal actor room-object publication through the canonical32-record owner."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_room_object_message_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 1), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-room-object-message-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        for key, value in dict(checks=88870413, room_object_message_cases=655361,
                               room_object_messages=323826, room_object_message_lookups=131074,
                               room_object_message_refusals=11).items():
            assert observed[key] == value, key
        assert expected is None or observed == expected
        expected = observed
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent / name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-room-object-message-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1, status='qualified actor room-object publication through canonical coordinates',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete67E230 selector9 executes with actual gate/dispatch helpers. Native publication borrows the same imported RoomObject Owner used by geometry, occupancy and scenario actions; no copied coordinate table is held.',
            'The admitted authored physical ordinal is0..31. Initialized inactive records retain their canonical coordinates; uninitialized owners and unchecked original out-of-domain byte ordinals are refused. No object ID, activation or mask alias is fabricated.',
            '655361 cases include every signed X/Z byte pair, all32 initialized records, partial populations, primary/category1 routes, capture before room lookup, owner replacement and mode mutation during lookup. Known payload fields retain type9/length8/dispatch4; unknown final stack padding is omitted.',
            'Selector9 does not require gauge state or write actor status/suppression. Actual UpdateOwner construction borrows the same RoomObject Owner. Eleven refusal groups cover missing owner, unknown initialization, invalid ordinals, absent/default/rejected consumers, mapping, identities and shutdown.',
            'Both compiler cohorts rerun the previous contact snapshot, contact alignment/math and cooperative/event/message matrices with identical observations. Parent builds and eight integration checks pass per compiler.',
            'Messages3/8/11, incoming application, actual queue/receiver/transport, remaining action callers, semantic saves and installation/acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
        ]), indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
