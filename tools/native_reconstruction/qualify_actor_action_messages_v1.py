"""Seal selector7, actual offline peer requests and the shared744638 word."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_action_message_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents, worlds = {}, {}, {}, {}
    expected = None
    def verify_sources(receipt):
        for name,digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
    for cc in ['llvm','gcc']:
        path = ROOT / f'build-native-sjuni/actor-action-message-{cc}-v2/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 45764730 and observed['actor_action_cases'] == 393216
        assert observed['actor_action_messages'] == 231448 and observed['actor_action_lookups'] == 116868
        assert observed['actor_action_requests'] == 124301 and observed['actor_action_refusals'] == 8
        assert observed['actor_action_world_publications'] == 4
        assert expected is None or expected == observed
        expected = observed
        assert receipt['actor_message_admission'].startswith('67E230 selectors7/14')
        assert all(any(row['start'] == hex(at) for row in receipt['original_word_audits']) for at in [0x67e230,0x1b0310,0x1b02d0,0x1b0240,0x1afdd0])
        verify_sources(receipt)
        prior = ROOT / f'build-native-sjuni/actor-action-message-{cc}-v1/receipt.json'
        assert json.loads(prior.read_bytes())['observed'] == observed
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed,prior_matching_observation=dict(path=prior.relative_to(ROOT).as_posix(),sha256=sha(prior)))
        for kind in ['parent','tests']:
            path = ROOT / f'build-native-sjuni/stage4-actor-action-message-{kind}-{cc}-v1.log'
            raw = path.read_bytes();value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
        path = ROOT / f'build-native-sjuni/actor-action-shared-word-world-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['source_unchanged'] and receipt['original_body_executed']
        assert receipt['observed']['cases'] == 4096 and receipt['observed']['ordered_calls'] == 291127
        assert receipt['observed']['native_lifetime'] == dict(checks=81,status='passed',game_run=False)
        verify_sources(receipt)
        worlds[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
    result = dict(schema=1,status='qualified native action notice selector7, offline peer request writes and shared frame/suppression state',game_launched=False,installed_in_game=False,stage4_complete=False,source_sha256=source,cohorts=cohorts,parent_checks=parents,current_world_regressions=worlds,limitations=[
        'Typed initialized message fields omit unknown original trailing stack padding. Final message and room-owner consumers remain declared ports; completed dispatch does not prove network delivery.',
        'Peer side effects admit all eight registered canonical primary actors; unknown peers refuse at the reached mutation and preserve earlier effects.',
        'The124301 request metric counts changed peer records, including idempotent/overlapping effects only when final values differ. It is not a request-call or packet-delivery count.',
        'Four native World/Owner publication-stage invocations include intentional suppression and unavailable-consumer failure; other World services remain declared seams.',
        'Other actor message selectors, actual queue/receiver/transport, remaining pickup/AI/action consumers, semantic World save/load and coherent installation remain open.'
    ])
    target.write_text(json.dumps(result,indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
