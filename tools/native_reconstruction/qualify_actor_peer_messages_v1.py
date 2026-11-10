"""Seal native paired actor requests, canonical hit alias and queue reception."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_peer_message_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = {}
    for cc, version in [('llvm', 3), ('gcc', 1)]:
        for kind, path in [('sender', ROOT/f'build-native-sjuni/actor-peer-message-{cc}-v{version}/receipt.json'),
                           ('receiver', ROOT/f'build-native-sjuni/actor-peer-reception-{cc}-v3/receipt.json')]:
            receipt = json.loads(path.read_bytes())
            assert receipt['status'] == 'passed' and receipt['source_unchanged']
            observed = receipt['observed']
            metrics = dict(checks=116373882, actor_peer_cases=589826, actor_peer_messages=247689,
                actor_peer_lookups=125613, actor_peer_mirrors=120151, actor_peer_refusals=10,
                actor_peer_hit_aliases=8192) if kind == 'sender' else dict(checks=965916741,
                reception_cases=655360, reception_equipment=257, reception_refusals=8,
                reception_queue_cases=149, reception_auxiliary_cases=65536,
                heap_allocations=114671, heap_releases=114671)
            for key, value in metrics.items():
                assert observed[key] == value, key
            assert kind not in expected or expected[kind] == observed
            expected[kind] = observed
            for name, digest in receipt['source_sha256'].items():
                assert sha(ROOT/name) == digest, name
                assert name not in sources or sources[name] == digest
                sources[name] = digest
            for name, digest in receipt['output_sha256'].items():
                assert sha(path.parent/name) == digest, name
            cohorts[f'{cc}-{kind}'] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent','tests']:
            path = ROOT/f'build-native-sjuni/actor-peer-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified native paired actor publication and reception',
        game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,parent_checks=parents,limitations=[
            'Complete67E230 selector8 and67ED50 branch8 execute with actual666640 auxiliary lookup. Portable primary-slot/auxiliary-identifier references resolve through the receiving World; they are logical gameplay values, not EntityId capabilities or guest addresses.',
            'C64 low byte remains canonical HitActor.transient_contact. PeerRequest owns only C65/C66/C68/C6A, and is unknown until supplied by a producer or receipt.8192 actual World/behavior/pending-hit/gauge cases preserve the upper request byte and parameters while clearing the shared low byte.',
            '589826 sender cases compare full request/parameter domains, primary/self/auxiliary/missing targets, common admission, lookup mutation, wrapping channels and offline mirror-before-dispatch. Native malformed/out-of-domain or missing primary capabilities refuse explicitly instead of performing unchecked source indexing.',
            '655360 receiver cases include65536 auxiliary/missing-auxiliary cases and all eight primary channels. A missing auxiliary stores the base request and exits before shared pose/equipment cleanup, matching the measured source prefix. Mirrored peers receive the sender slot as a primary logical reference.',
            '149 queue composition checks include actual UpdateOwner publication of a captured peer request across separate Worlds, proving the portable reference resolves through the target owners rather than carrying a source-local EntityId.',
            'Both compiler observations match. Full receiver/resource/event/behavior/recovery regressions pass965916741 checks with114671 balanced source allocations/releases; sender/alias/pool regressions pass116373882 checks. Parent builds and all eight integration checks pass per compiler.',
            'Higher request producers, remaining senders3/11, other incoming/action/AI paths, real external transport/authentication/encoding, semantic saves and game installation/acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
