"""Seal immutable native SGL import and source-compared navigation queries."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT/'tools/native_reconstruction/native_gameplay_navigation_qualification_v1.json'
    assert not target.exists()
    sources, cohorts, parents = {}, {}, {}
    expected = dict(checks=2683729,nearest_cases=26930,action_cases=265608,
        asset_rooms=166,asset_nodes=3334,asset_conditions=2167,asset_links=432,
        refusals=27155,nearest_refusals=26672,action_refusals=0,bindings=1920,clears=30)
    for cc in ['llvm', 'gcc']:
        path = ROOT/f'build-native-sjuni/gameplay-navigation-{cc}-v4/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged'] and receipt['observed'] == expected
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT/name) == digest, name
            assert name not in sources or sources[name] == digest
            sources[name] = digest
        for name, digest in receipt['output_sha256'].items():
            assert sha(path.parent/name) == digest, name
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=receipt['observed'])
        for kind in ['parent', 'tests']:
            path = ROOT/f'build-native-sjuni/gameplay-navigation-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            text = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 9' in text) if kind == 'tests' else ('FAILED:' not in text and 'error:' not in text)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    target.write_text(json.dumps(dict(schema=1,status='qualified bounded immutable SGL input and native navigation queries',
        game_launched=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,parent_checks=parents,limitations=[
            'All five selected retail SGL members are rehashed from exact owned ISO extents using the pinned inventory. This does not rehash the full ISO or prove the live resource loader is migrated.',
            'The native importer owns immutable authored data, deduplicates identical resource offsets, preserves descriptor order and relative directory offsets and never relocates to process pointers. Unnamed operands remain authored encoding, not guessed mutable state.',
            'Complete original accessors, relocation and mode2 room binding compare against native views, with controlled explicit variant bytes. The canonical variant producer, native mutable room bank, occupancy/visited lifetime and runtime load caller are separate outstanding work.',
            'Unfiltered nearest selection uses finite ordered distance arithmetic and first minimum ties. Empty candidate, nonfinite query or overflow is unavailable; original uninitialized reads are not asserted meaningful results. Collision-filtered flags1 remains open.',
            'Reverse action preserves signed count early exit, last accepted full action word within the first productive neighbor and immediate11 for types11/12. All 65536 condition type/subtype pairs and three passes through the full action-word domain compare with originals.',
            'All3334 actual nodes reach a completed reverse-action query in this cohort. The authored r041 descriptor29/node0 condition ordinal19 equals its condition count and is preserved. This query does not reach the invalid fallback because a reverse edge supplies an action; other future consumers must independently validate that ordinal. Synthetic reachable invalid ordinals/neighbor references are unavailable.',
            'Both compiler source comparisons and all nine parent integration checks pass. No game launched, gameplay installed, performance fix measured or Stage4 completion claimed. Dynamic navigation conditions, route/AI/action consumers, semantic saves and coherent native game acceptance remain open.'
        ]),indent=2)+'\n')
    print(sha(target))


if __name__ == '__main__':
    main()
