"""Seal native semantic interaction requests and canonical hit/model aliases."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_interaction_request_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, expected = {}, {}, {}, {}
    for cc in ['llvm', 'gcc']:
        for kind in ['message', 'reception']:
            path = ROOT/f'build-native-sjuni/actor-request-{kind}-{cc}-v1/receipt.json'
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            observed = receipt['observed']
            metrics = dict(checks=128645539, actor_request_cases=589825,
                actor_request_messages=258290, actor_request_lookups=131074,
                actor_request_refusals=9, actor_request_hit_aliases=8192) if kind == 'message' else dict(
                checks=975334803, reception_cases=729088, reception_equipment=257,
                reception_refusals=8, reception_queue_cases=153,
                reception_auxiliary_cases=65536, reception_speech_cases=131072,
                reception_presence_cases=65536, reception_speech_refusals=7,
                heap_allocations=114671, heap_releases=114671)
            for name, value in metrics.items():
                assert observed[name] == value, (name, observed[name], value)
            assert kind not in expected or expected[kind] == observed
            expected[kind] = observed
            for name, digest in receipt['source_sha256'].items():
                assert sha(ROOT/name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
            for name, digest in receipt['output_sha256'].items():
                assert sha(path.parent/name) == digest, name
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/actor-request-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native semantic interaction request publication and reception',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete67E230 selector3 and67ED50 branch3 execute against owned originals. Native InteractionRequest owns AB9/ABA and semantic anchor, orientation, travel-distance and endpoint fields. Inherited transient_action is the only AB8 owner; scene_model is the existing ABB owner. D32 retains its phase-dependent numeric cached-target/state meaning.',
            'Source copies seven complete words, including three trailing bytes with no admitted producer/consumer meaning. Typed native messages omit these bytes, rather than turning unused guest padding into canonical state or claiming a compatible wire format. Static producer/consumer instruction slices establish the semantic views but those higher bodies do not execute in this message fixture.',
            'Sender requires a supplied request and a known real model slot0..127. Authored NoModel repair and unknown/invalid references remain an explicit outgoing capability refusal. Receiver stores all byte-domain logical model values; invalid values remain unavailable to later model operations instead of granting a model capability.',
            '589825 request sender cases compare signed/unsigned and raw floating payloads, category/mode/admission gates, mapped-room mutation, wrapping channels and unavailable delivery.8192 actual World/behavior/pending-hit/gauge cases compare shared AB8 cleanup while retaining the other request fields and canonical model reference.',
            'Both compiler observations match. Full reception covers729088 existing/request cases, existing131072 speech and65536 presence cases, and153 queue checks. Actual UpdateOwner sends a captured request across Worlds into the receiving actor and clears D32 before shared pose/equipment cleanup. Parent builds and all eight integration checks pass per compiler.',
            'All outgoing selector branches now have native policy within documented capability profiles, including intentional no-message0/13. This does not migrate actual interaction producers/consumption, remaining incoming/action/AI/VM branches, external transport/authentication/encoding, semantic saves or game installation/acceptance. InstalledV39 remains unchanged and Stage4 is incomplete; no measured slowdown fix is claimed.'
        ]), indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
