"""Seal original5B1F30 through actual native cost/depletion/lifecycle owners."""
import hashlib
import json
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_owned_resource_use_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for cc, version in [('llvm',3), ('gcc',2)]:
        path = ROOT / f'build-native-sjuni/owned-resource-use-{cc}-v{version}/receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 277182080
        assert observed['owned_use_cases'] == 393216 and observed['owned_use_live'] == 2032
        assert observed['owned_use_retirements'] == 4 and observed['owned_use_refusals'] == 1
        assert observed['depletion_cases'] == 1179649 and observed['depletion_live'] == 6049
        assert observed['depletion_refusals'] == 4 and observed['depletion_audio_commands'] == 449
        assert observed['depletion_signal'] == 74592
        assert expected is None or expected == observed
        expected = observed
        assert any(row['start'] == '0x5b1f30' for row in receipt['original_owned_bodies'])
        for name, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
            assert name not in source or source[name] == digest, name
            source[name] = digest
        cohorts[cc] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-owned-resource-use-{kind}-{cc}-v2.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified native outer owned-resource use with actual cost, depletion, audio and model retirement consumers', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Canonical primary actors and admitted model visibility0/1; unknown/foreign capabilities preserve their known prefix and refuse.',
        'Original5B1F30 executes through complete original cost/replacement/audio frontends. Final filesystem/audio ports retain the previously declared stock WMD and independently qualified mixer boundaries.',
        'Actual primary and shared-secondary retirement leave equipped and inventory references unchanged; actor callers still need migration.',
        'Ownership/transfer/UI, remaining gameplay families, coherent installation and scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))


if __name__ == '__main__':
    main()
