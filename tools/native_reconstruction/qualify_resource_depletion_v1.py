"""Seal admitted weapon depletion, cost and real native consumer composition."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    target = ROOT / 'tools/native_reconstruction/native_resource_depletion_qualification_v1.json'
    assert not target.exists()
    source, cohorts, parents = {}, {}, {}
    expected = None
    for name in ['resource-depletion-llvm-v6', 'resource-depletion-gcc-v2']:
        path = ROOT / 'build-native-sjuni' / name / 'receipt.json'
        receipt = json.loads(path.read_bytes())
        assert receipt['status'] == 'passed' and receipt['source_unchanged']
        observed = receipt['observed']
        assert observed['checks'] == 272433193 and observed['depletion_cases'] == 786433
        assert observed['depletion_live'] == 577 and observed['depletion_refusals'] == 4
        assert observed['depletion_audio_commands'] == 49 and observed['depletion_signal'] == 8548
        assert expected is None or expected == observed
        expected = observed
        assert sha(path.parent / 'owned_depletion_cue.bin') == receipt['depletion_cue_asset']['sha256']
        for name_, digest in receipt['source_sha256'].items():
            assert sha(ROOT / name_) == digest, name_
            assert name_ not in source or source[name_] == digest, name_
            source[name_] = digest
        cohorts[name] = dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), observed=observed)
    source['game/native/gameplay_world/CMakeLists.txt'] = sha(ROOT / 'game/native/gameplay_world/CMakeLists.txt')
    for cc in ['llvm', 'gcc']:
        for kind in ['parent', 'tests']:
            path = ROOT / f'build-native-sjuni/stage4-resource-depletion-{kind}-{cc}-v1.log'
            raw = path.read_bytes()
            value = raw.decode('utf-16' if raw.startswith(b'\xff\xfe') else 'utf-8-sig')
            assert ('100% tests passed, 0 tests failed out of 8' in value) if kind == 'tests' else ('FAILED:' not in value and 'error:' not in value)
            parents[path.relative_to(ROOT).as_posix()] = sha(path)
    result = dict(schema=1, status='qualified admitted native weapon depletion/use cost with actual model, debris, audio and weapon consumers', game_launched=False, installed_in_game=False, stage4_complete=False, source_sha256=source, cohorts=cohorts, parent_checks=parents, limitations=[
        'Current sixteen-WMD catalogue admission; eighteen real stock selectors without WMD files still need an explicit cleared-bank absence profile and continuing sound enqueue.',
        'Native boolean model visibility admits original0/1; foreign/stale model/actor capabilities are not raw slot alias emulation.',
        'Complete equipped-resource cue frontend executes; final positioned bank request delegates to independently qualified native audio/mixer with controlled actual-bank assignment.',
        'Ownership/transfer/UI callers, remaining gameplay families, installation and coherent scenario acceptance remain open.'
    ])
    target.write_text(json.dumps(result, indent=2) + '\n')
    print(sha(target))

if __name__ == '__main__':
    main()
