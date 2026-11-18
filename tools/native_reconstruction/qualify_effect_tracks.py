"""Seal matching original-body effect track cohorts without changing history."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [ROOT / 'build-native-sjuni' / ('effect-tracks-' + cc + '-v2') / 'receipt.json' for cc in ['llvm', 'gcc']]
    records = [json.loads(path.read_bytes()) for path in paths]
    for record in records:
        assert record['status'] == 'passed' and record['source_unchanged']
        for name, digest in record['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
        assert not record['game_run'] and not record['full_effect_pipeline']
    assert records[0]['source_sha256'] == records[1]['source_sha256']
    assert records[0]['observed'] == records[1]['observed']
    extra = ['docs/native-gameplay/EFFECT_TRACKS.md', 'tools/native_reconstruction/import_effect_tracks.py',
             'tools/native_reconstruction/qualify_effect_tracks.py']
    result = dict(schema=1, status='qualified_native_effect_tracks_partial_visual_pipeline',
                  stage4_complete=False, installed_in_game=False, game_run=False, full_effect_pipeline=False,
                  source_sha256=records[0]['source_sha256'], documentation_and_tools_sha256={name: sha(ROOT / name) for name in extra},
                  corpus=records[0]['corpus'], observed=records[0]['observed'],
                  original_owned_bodies=records[0]['original_owned_bodies'], owned_switch_table=records[0]['owned_switch_table'],
                  receipts=[dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path), compiler_sha256=record['compiler_sha256']) for path, record in zip(paths, records)],
                  limitations=['One efdata26 member is refused under the observed original +0x400 group-base profile.',
                               'Native geometry/material ownership, complete visual lifetime and real game consumers remain required.',
                               'Original instructions execute only in offline tests; production owns ordinary typed asset values.',
                               'Counts include physical duplicate assets and repeated comparisons; no reachability or physical PS2 FPU claim.'])
    output = ROOT / 'tools/native_reconstruction/native_effect_tracks_qualification_v1.json'
    assert not output.exists()
    output.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=output.relative_to(ROOT).as_posix(), sha256=sha(output))))


if __name__ == '__main__':
    main()
