"""Seal selector6 publication through the canonical typed alignment target."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_alignment_message_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc in ['llvm', 'gcc']:
        path = ROOT / f'build-native-sjuni/actor-alignment-message-{cc}-v1/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 74567101 and observed['actor_alignment_cases'] == 196609
        assert observed['actor_alignment_messages'] == 29156 and observed['actor_alignment_lookups'] == 14610
        assert observed['actor_alignment_refusals'] == 10
        assert expected is None or expected == observed
        expected = observed
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/actor-alignment-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified canonical alignment target and selector6 publication',
                  game_launched=False, installed_in_game=False, stage4_complete=False,
                  source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Complete67E230 selector6 executes with actual common admission/dispatch. Native payload contains raw targetXYZ and signed yaw, with original20-byte framing evidence; untouched padding is not a native wire layout.',
        'AlignmentTarget is an optional canonical actor value for the admitted C34/C38/C3C/C4C contract. The two original field-provenance bodies666F50/66D850 are statically word-audited but are not executed or claimed migrated by this fixture.',
        '196609 cases include complete low16 yaw and dispersed raw float domains, phase/category/status/slot/suppression gates, wrapping channel mapping and lookup mutation. Ten refusal groups cover missing state, absent/default/rejected consumers, mapping, identity and shutdown.',
        'Selector6 neither reads the selected gauge nor changes status or the shared suppression word. The actual Owner facade is checked with an unavailable gauge. Payload capture precedes room lookup and final dispatch rereads mode.',
        'Target producers/import, alignment movement, selectors3/5/8/9/11, actual queue/receiver/transport, semantic save/load and installation/acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
