"""Seal the corrected track roles and actual periodic visual/task consumer."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    folders = ['periodic-visuals-llvm-v7', 'periodic-visuals-gcc-v1', 'effect-tracks-llvm-v3', 'effect-tracks-gcc-v3']
    paths = [ROOT / 'build-native-sjuni' / n / 'receipt.json' for n in folders]
    records = [json.loads(path.read_bytes()) for path in paths]
    for record in records:
        assert record['status'] == 'passed' and record['source_unchanged']
        for name, digest in record['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
    for a, b in [(0, 1), (2, 3)]:
        assert records[a]['source_sha256'] == records[b]['source_sha256']
        assert records[a]['observed'] == records[b]['observed']
    names = ['docs/native-gameplay/PERIODIC_VISUALS.md', 'tools/native_reconstruction/qualify_periodic_visuals.py']
    result = dict(schema=1, status='qualified_native_periodic_visual_resource_consumer_and_corrected_track_roles',
                  game_run=False, installed_in_game=False, stage4_complete=False, opcode131_installed=False,
                  source_sha256=records[0]['source_sha256'],
                  documentation_and_tools_sha256={n: sha(ROOT / n) for n in names},
                  observed=records[0]['observed'], corrected_track_regression=records[2]['observed'],
                  original_owned_bodies=records[0]['original_owned_bodies'], declared_ports=records[0]['declared_ports'],
                  selected_profile=records[0]['selected_visual_family'], native_modernization=records[0]['native_modernization'],
                  receipts=[dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p), compiler_sha256=r['compiler_sha256']) for p, r in zip(paths, records)],
                  limitations=['The three periodic profiles have complete actual visual/resource consumers; other effect families are unadmitted.',
                               'The actual source work/piece domains must be shared as remaining families migrate before game installation.',
                               'Opcode131 VM admission, native renderer submission and complete Stage4 gameplay installation remain separate.',
                               'Scale/translation semantic roles supersede earlier v1 names; historical receipts retain their original snapshots.',
                               'No game, physical PS2 FPU exception, measured speedup or subjective visual validation is claimed.'])
    path = ROOT / 'tools/native_reconstruction/native_periodic_visuals_qualification_v1.json'
    assert not path.exists()
    path.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path))))


if __name__ == '__main__':
    main()
