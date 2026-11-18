"""Seal native contact alignment and the complete source math-chain comparison."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_actor_contact_alignment_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm', 3), ('gcc', 1)]:
        path = ROOT / f'build-native-sjuni/actor-contact-alignment-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        for key, value in dict(checks=79490412, contact_alignment_cases=525440,
                               heading_cases=589827, contact_alignment_rejections=131073,
                               contact_alignment_refusals=17, contact_alignment_owner_cases=4).items():
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
            path = ROOT / f'build-native-sjuni/actor-contact-alignment-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1, status='qualified native contact alignment producer and heading math',
        game_launched=False, installed_in_game=False, stage4_complete=False,
        source_sha256=sources, cohorts=cohorts, parent_checks=parents, limitations=[
            'Complete666F50 executes with original376E70,192180,1226F0,120908,122140,1224A8,191EF0,1920A0,3700C0,370100,192190,1921A0,18F340,18F470. Merged source spans also contain unentered neighboring entries; these are not claimed migrated.',
            'Native arithmetic uses finite FP32, round-to-nearest and gradual underflow. Original generated-body surroundings model the admitted finite scalar/SIMD profile, not physical PS2 exceptional values or FP status flags. The source heading polynomial and all used constants are independently checked against the pinned owned ELF/overlay.',
            'The full low16 turn domain compares the actual separate sine/cosine chain against native paired trig, without a host atan2 or trig-result source port. Heading tests include signed zeros, subnormal policy, exponent cutoffs, polynomial boundaries and dispersed finite bits.',
            'Producer cases cover signed-low16 gate versus full signed32 angular comparison, wrapped facing/yaw differences, offsets, raw copied Y and retained previous targets on rejection. Canonical contact point/normal and optional AlignmentTarget are shared with native World; current pose is retained.',
            'Actual UpdateOwner prepare, failed/successful selector6 publication and stale/closed identities are exercised. No implicit message send is added to the target producer.',
            'Other target producers/import, animation-driven alignment movement, messages3/5/8/9/11, actual transport, semantic saves and installed gameplay acceptance remain open. InstalledV39 is unchanged; this is not whole Stage4 or a measured slowdown fix.'
        ]), indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
