#!/usr/bin/env python3
"""Add verified native preparation metadata/tool to a fresh coherent File1 SDK."""
import argparse
import hashlib
import json
from pathlib import Path, PurePosixPath
import shutil

ROOT = Path(__file__).resolve().parents[2]


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def member(folder, name):
    relative = PurePosixPath(name)
    if relative.is_absolute() or '..' in relative.parts or '\\' in name or ':' in name:
        raise ValueError('Unsafe SDK member: '+name)
    path = (folder / name).resolve()
    if not path.is_relative_to(folder):
        raise ValueError('SDK member escapes its root')
    return path


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('kit', 'helper', 'output'):
        parser.add_argument('--'+name, type=Path, required=True)
    args = parser.parse_args()
    kit, helper, output = (p.resolve() for p in (args.kit, args.helper, args.output))
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if output.exists() or output == allowed or not output.is_relative_to(allowed) or output.is_relative_to(kit):
        raise ValueError('A fresh independent private SDK output is required')
    manifest = json.loads((kit / 'build-kit.json').read_text())
    delta = json.loads((kit / 'notices/native-candidate-source-delta.json').read_text())
    required = ('disc_stream', 'resource_reads', 'adx_block', 'adx_stereo', 'audio_backend', 'host_movie')
    if (manifest['elfSha256'] != '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46' or
            manifest.get('nativeMedia') or delta['dependency_patch_count'] != 131 or
            not all(delta['optional_adapters'].get(name) for name in required)):
        raise ValueError('The complete undeclared File1 native media input cohort is required')
    qualification = json.loads((ROOT / 'tools/native_reconstruction/native_movie_asset_cache_qualification.json').read_text())
    helper_sha = sha(helper)
    if helper_sha != qualification['native_helper_binary_sha256']:
        raise ValueError('The qualified static helper is required')
    # Ship the source cohort that produced the qualified executable, rather
    # than silently pairing an older helper with subsequently edited sources.
    for filename in ('CMakeLists.txt', 'prepare_movies.cpp', 'file1_movies.inc', 'file1_movies.json'):
        source_name = 'tools/native_media_import/'+filename
        if sha(ROOT / source_name) != qualification['source_sha256'][source_name]:
            raise ValueError('Qualified helper source changed: '+source_name)
    for file in manifest['files']:
        if sha(member(kit, file['path'])) != file['sha256']:
            raise ValueError('SDK input changed: '+file['path'])
    output.mkdir(parents=True)
    for file in manifest['files']:
        target = member(output, file['path'])
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(member(kit, file['path']), target)
    name = 'tools/reo-prepare-movies.exe'
    target = member(output, name)
    if target.exists():
        raise ValueError('The undeclared SDK unexpectedly contains a native preparation helper')
    shutil.copyfile(helper, target)
    # Include the helper's corresponding authored sources and import-only
    # metadata. No extracted game movie/audio payload enters this SDK.
    for filename in ('CMakeLists.txt', 'prepare_movies.cpp', 'file1_movies.inc', 'file1_movies.json', 'README.md'):
        source = ROOT / 'tools/native_media_import' / filename
        relative = 'source/tools/native_media_import/'+filename
        target = member(output, relative)
        if target.exists():
            raise ValueError('Conflicting native helper source in SDK')
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
        manifest['files'].append(dict(path=relative, sha256=sha(target)))
    manifest['files'].append(dict(path=name, sha256=helper_sha))
    manifest['nativeMedia'] = dict(format=1, game='file1', profileId='file1-native-media-v1',
                                  helper=name, helperSha256=helper_sha)
    for file in manifest['files']:
        if sha(member(output, file['path'])) != file['sha256']:
            raise ValueError('Copied SDK input changed: '+file['path'])
    (output / 'build-kit.json').write_text(json.dumps(manifest, indent=2)+'\n')
    receipt = dict(schema=1, parent_manifest_sha256=sha(kit / 'build-kit.json'),
        manifest_sha256=sha(output / 'build-kit.json'), source_revision=delta['root_revision'],
        packager_sha256=sha(Path(__file__)),
        native_media=manifest['nativeMedia'], game_built=False, game_launched=False,
        extracted_movie_audio_payloads_included=False,
        limitations=['Input packaging only. The launcher publishes a declaration after a verified local game build.',
                     'Packaging does not complete Step 3 or prove audible synchronization.'])
    (output / 'native-media-sdk-packaging-receipt.json').write_text(json.dumps(receipt, indent=2)+'\n')
    print(json.dumps(receipt))


if __name__ == '__main__':
    main()
