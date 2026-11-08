#!/usr/bin/env python3
"""Package an identified native game/helper pair; never include owned game assets."""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import shutil

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for key in ('game-folder', 'build-receipt', 'kit', 'helper', 'output'):
        parser.add_argument('--'+key, type=Path, required=True)
    args = parser.parse_args()
    game, receipt, kit, helper, output = (getattr(args, name).resolve() for name in
        ('game_folder', 'build_receipt', 'kit', 'helper', 'output'))
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output.exists() or output == allowed or not output.is_relative_to(allowed):
        raise ValueError('A fresh private package directory is required')
    build = json.loads(receipt.read_text())
    delta = json.loads((kit / 'notices/native-candidate-source-delta.json').read_text())
    expected = ('disc_stream', 'resource_reads', 'adx_block', 'adx_stereo', 'audio_backend', 'host_movie')
    if (build.get('status') != 'passed' or not build.get('game_linked') or build.get('preflight_only') or
            build['candidate_manifest_sha256'] != sha(kit / 'build-kit.json') or
            not all(delta['optional_adapters'].get(key) for key in expected) or
            delta['dependency_patch_count'] != 131):
        raise ValueError('The complete, successfully linked native File1 cohort is required')
    qualification_path = ROOT / 'tools/native_reconstruction/native_movie_asset_cache_qualification.json'
    qualification = json.loads(qualification_path.read_text())
    if sha(helper) != qualification['native_helper_binary_sha256']:
        raise ValueError('The qualified static native preparation helper is required')
    files = build['outputs_sha256']
    if files.get('reo_recomp.exe') != build['executable_sha256']:
        raise ValueError('Executable receipt is inconsistent')
    for name, digest in files.items():
        relative = PurePosixPath(name)
        if relative.is_absolute() or '..' in relative.parts or '\\' in name or ':' in name:
            raise ValueError('Unsafe package member')
        if sha(game / name) != digest:
            raise ValueError('Changed game artifact: '+name)
    output.mkdir(parents=True)
    for name, digest in files.items():
        target = output / name
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(game / name, target)
        if sha(target) != digest:
            raise ValueError('Package copy failed integrity validation')
    shutil.copyfile(helper, output / 'reo-prepare-movies.exe')
    if sha(output / 'reo-prepare-movies.exe') != qualification['native_helper_binary_sha256']:
        raise ValueError('Helper copy failed integrity validation')
    profile = dict(format=1, game='file1', profileId='file1-native-media-v1',
        executableSha256=build['executable_sha256'], helperSha256=sha(helper))
    (output / 'native-media.json').write_text(json.dumps(profile, indent=2)+'\n')
    result = dict(schema=1, source_revision=delta['root_revision'],
        build_receipt_sha256=sha(receipt), kit_manifest_sha256=sha(kit / 'build-kit.json'),
        helper_qualification_sha256=sha(qualification_path), profile=profile,
        files_sha256={p.relative_to(output).as_posix():sha(p) for p in output.rglob('*') if p.is_file()},
        owned_assets_included=False, game_launched=False,
        limitations=['Game folder only; use the launcher native-media integration for automatic preparation.',
                    'Private packaging is not Step 3 completion or audible synchronization evidence.'])
    (output / 'native-media-package-receipt.json').write_text(json.dumps(result, indent=2)+'\n')
    print(json.dumps(dict(output=str(output), executable_sha256=profile['executableSha256'], owned_assets_included=False)))


if __name__ == '__main__':
    main()
