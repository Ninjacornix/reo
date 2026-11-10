"""Seal native SPK-state messages and the actual inventory-map cache consumer."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_actor_speech_message_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents, expected = {}, {}, {}, {}
    for cc in ['llvm', 'gcc']:
        for kind in ['message', 'reception']:
            path = ROOT/f'build-native-sjuni/actor-speech-{kind}-{cc}-v1/receipt.json'
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            observed = receipt['observed']
            metrics = dict(checks=121616785, actor_speech_cases=589825,
                actor_speech_messages=258290, actor_speech_lookups=131074,
                actor_speech_refusals=10) if kind == 'message' else dict(
                checks=968551054, reception_cases=655360, reception_equipment=257,
                reception_refusals=8, reception_queue_cases=151,
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
            path = ROOT/f'build-native-sjuni/actor-speech-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native speech publication, reception and inventory-map presence',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete67E230 selector11, incoming67ED50 branch11 and actual6DFEE0 cache refresh execute against the owned original words. Higher SPK/SPM selection/construction, text/audio consumers and the rest of the inventory/map UI remain open.',
            'Canonical Actor speech selection, variant and gauge notice remain independently unknown until an actual producer/import/receipt supplies them. Sender captures signed fields before actual667F90 gauge evaluation, writes DB8 notice0/1 before routing, and preserves captured payload across mode/state mutation during room lookup.',
            'Receiver refreshes the World-bound four-slot native inventory cache before the variant write. Zero variant plus a different room preserves selection/gauge while still applying shared pose/equipment cleanup. Context halfword and response word narrow to signed bytes; gauge byte sign-extends to its native word.',
            'Actual6DFEE0 copies raw XYZ and low room byte with lifetime90. Local/inactive gates precede active slot bounds. Activation does not construct the remaining UI; no guessed decrement clock is added. Missing ownership refuses after the measured shared prefix; foreign or closed ownership is rejected.',
            'Both compiler sender observations match across589825 speech cases and121616785 combined checks. Full receiver observations include131072 speech cases,65536 independent presence producer cases and151 queue checks including actual UpdateOwner-to-queue delivery across Worlds. Parent builds and all eight integration checks pass per compiler.',
            'Remaining outgoing selector3, other incoming messages/actions/AI/VM tasks, actual speech/UI producers and consumers, real external transport/authentication/encoding, semantic saves and coherent game installation/acceptance remain open. InstalledV39 is unchanged; this is not completed Stage4 or a measured slowdown fix.'
        ]), indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
