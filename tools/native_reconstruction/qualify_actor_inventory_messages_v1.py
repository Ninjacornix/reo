"""Seal typed actor interaction/pair/inventory messages and true no-message cases."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_inventory_message_qualification_v1.json'
    assert not target.exists()
    source,cohorts,parents = {},{},{}
    expected = None
    for cc in ['llvm','gcc']:
        path = ROOT / f'build-native-sjuni/actor-inventory-message-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 53603432 and observed['actor_inventory_cases'] == 1179648
        assert observed['actor_inventory_messages'] == 116624 and observed['actor_inventory_lookups'] == 58440
        assert observed['actor_inventory_refusals'] == 19
        assert observed['actor_status_cases'] == 327680 and observed['actor_status_messages'] == 23080
        assert observed['actor_action_cases'] == 393216 and observed['actor_action_messages'] == 231448
        assert observed['actor_action_requests'] == 124301
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_message_admission'].startswith('67E230 selectors0/4/7/10/12/13/14/15')
        assert receipt['actor_inventory_admission'].startswith('67E230 selectors0/13')
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
        for kind in ['parent','tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-inventory-message-{kind}-{cc}-v1.log'
            raw = path.read_bytes();value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1,status='qualified native actor interaction, pair, carried and extra inventory publication with intentional selector0/13 no-message paths',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=source,cohorts=cohorts,parent_checks=parents,limitations=[
        'The shared gate/dispatch now supplies admitted selectors0/4/7/10/12/13/14/15. Two are actual no-message paths; selectors1/2/3/5/6/8/9/11 remain unsupported when reached.',
        'Typed known fields omit unknown original padding, including the remaining bytes of selector10 length16. No native struct is advertised as a packed wire format.',
        'Complete original selector bodies execute;18DBB0 is an explicit bounded four-byte actor-to-stack copy. Final room-owner and message sinks remain declared ports.',
        'Higher-level inventory/action producers, queue/receiver/transport, remaining gameplay and coherent installation remain open. This is not whole native gameplay or a slowdown retest.'
    ])
    target.write_text(json.dumps(result,indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
