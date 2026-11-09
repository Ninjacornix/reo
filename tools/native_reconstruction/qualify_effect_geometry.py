"""Seal native effect metadata and material sampling with both compilers."""
import hashlib
import json
from pathlib import Path
ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    paths = [ROOT / 'build-native-sjuni' / n / 'receipt.json' for n in ['effect-geometry-llvm-v9', 'effect-geometry-gcc-v3']]
    records = [json.loads(path.read_bytes()) for path in paths]
    for record in records:
        assert record['status'] == 'passed' and record['source_unchanged']
        for name, digest in record['source_sha256'].items():
            assert sha(ROOT / name) == digest, name
    assert records[0]['source_sha256'] == records[1]['source_sha256']
    assert records[0]['observed'] == records[1]['observed']
    names = ['docs/native-gameplay/EFFECT_RESOURCE_METADATA.md', 'tools/native_reconstruction/import_effect_geometry.py',
             'tools/native_reconstruction/qualify_effect_geometry.py']
    result = dict(schema=1, status='qualified_native_effect_resource_metadata_and_materials', game_run=False,
                  installed_in_game=False, stage4_complete=False, full_effect_pipeline=False,
                  source_sha256=records[0]['source_sha256'], documentation_and_tools_sha256={n: sha(ROOT / n) for n in names},
                  observed=records[0]['observed'], corpus=records[0]['corpus'],
                  original_owned_bodies=records[0]['original_owned_bodies'], declared_ports=records[0]['declared_ports'],
                  receipts=[dict(path=p.relative_to(ROOT).as_posix(), sha256=sha(p), compiler_sha256=r['compiler_sha256']) for p, r in zip(paths, records)],
                  limitations=['EF35 root53 has a stale-workspace original palette dependency and is unadmitted.',
                               '24 authored part profiles reference missing resource/material data; runtime reachability remains unknown.',
                               'All variant0 periodic logical36/37/38 groups pass full resource/material/transform admission in the six captured banks.',
                               'Native visual lifetime, real gameplay installation and rendering remain separate requirements.'])
    path = ROOT / 'tools/native_reconstruction/native_effect_geometry_qualification_v1.json'
    assert not path.exists()
    path.write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps(dict(path=path.relative_to(ROOT).as_posix(), sha256=sha(path))))


if __name__ == '__main__':
    main()
