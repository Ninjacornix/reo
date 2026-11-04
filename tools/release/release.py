"""Package verified existing game inputs; publish only for a pushed version tag."""
import argparse
import hashlib
import json
import os
from pathlib import Path, PurePosixPath
import re
import shutil
import subprocess
import zipfile


ELFS = {'file1': '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46',
        'file2': '5c0411a26247ef9974cd94b844ac5aecbcbf4705db543f51814aeed89da0fd8d'}
GAME_INPUTS = ('game/', 'media/', 'network/', 'runtime/', 'recomp/', 'src/',
               'cmake/', 'deps/', 'third_party/', 'tools/local_build/', 'tools/parallel_gs_backend/',
               'tools/vu_whole_aot/', 'tools/elf_analyze/')
TAG = r'v(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)\.(0|[1-9][0-9]*)(?:-([0-9A-Za-z]+(?:[.-][0-9A-Za-z]+)*))?'


def run(*args, cwd=None, input=None):
    result = subprocess.run(args, cwd=cwd, input=input, text=True, capture_output=True)
    if result.returncode:
        detail = result.stderr.strip()
        for key in ('GH_TOKEN', 'GITHUB_TOKEN', 'RELEASE_TOKEN'):
            if os.environ.get(key):
                detail = detail.replace(os.environ[key], '[redacted]')
        raise RuntimeError(f'{args[0]} failed ({result.returncode}): {detail}')
    return result.stdout.strip()


def api(path, method='GET', data=None):
    command = ['gh', 'api', '--method', method, path]
    if data is not None:
        command += ['--input', '-']
    result = run(*command, input=None if data is None else json.dumps(data))
    return json.loads(result) if result else None


def options(tag, prerelease, publication):
    match = re.fullmatch(TAG, tag)
    if not match or bool(match[4]) != prerelease:
        raise ValueError('Use vMAJOR.MINOR.PATCH for stable, or add a suffix for a prerelease.')
    if publication not in ('validate-only', 'publish'):
        raise ValueError('Unknown publication mode.')
    return {'tag': tag, 'version': '.'.join(match.groups()[:3]), 'prerelease': prerelease,
            'publication': publication}


def requested_options():
    """A pushed version tag publishes that tag; a manual run only validates.

    CI never creates tags: a release exists only after a maintainer pushes its tag.
    The suffix decides the kind: v1.0.20-rc3 is a prerelease, v1.0.20 is stable.
    """
    if os.environ.get('GITHUB_EVENT_NAME') == 'push':
        ref = os.environ.get('GITHUB_REF', '')
        if not ref.startswith('refs/tags/'):
            raise ValueError('Releases are published only from a pushed version tag.')
        tag = ref[len('refs/tags/'):]
        match = re.fullmatch(TAG, tag)
        if not match:
            raise ValueError('Pushed tag is not a version tag (vMAJOR.MINOR.PATCH[-suffix]).')
        return options(tag, bool(match[4]), 'publish')
    return options(os.environ['RELEASE_TAG'], os.environ['PRERELEASE'] == 'true', 'validate-only')


def sha(path):
    with Path(path).open('rb') as source:
        return hashlib.file_digest(source, 'sha256').hexdigest()


def write_json(path, value):
    Path(path).write_text(json.dumps(value, indent=2) + '\n', encoding='utf-8')


def entries(archive):
    result = {}
    for item in archive.infolist():
        name = item.filename.rstrip('/')
        parts = name.split('/')
        if (not name or '\\' in name or ':' in name or name.startswith('/') or
                any(p in ('', '.', '..') or p.endswith((' ', '.')) for p in parts)):
            raise ValueError('Unsafe archive path: ' + item.filename)
        key = name.casefold()
        if key in result:
            raise ValueError('Duplicate archive path: ' + name)
        result[key] = item
    return {item.filename: item for item in result.values() if not item.is_dir()}


def verify_files(archive, inventory, manifest_name):
    members = entries(archive)
    expected = {manifest_name}
    if not inventory:
        raise ValueError('Empty archive inventory.')
    for item in inventory:
        name = item['path']
        if name in expected or name not in members:
            raise ValueError('Invalid inventory member: ' + name)
        expected.add(name)
        with archive.open(members[name]) as source:
            actual = hashlib.file_digest(source, 'sha256').hexdigest()
        if actual != item['sha256']:
            raise ValueError('Archive hash mismatch: ' + name)
        if 'bytes' in item and item['bytes'] != members[name].file_size:
            raise ValueError('Archive size mismatch: ' + name)
    if set(members) != expected:
        raise ValueError('Archive contains unlisted files.')


def verify_kit(path, manifest_path, game):
    with zipfile.ZipFile(path) as archive:
        manifest_bytes = archive.read('build-kit.json')
        manifest = json.loads(manifest_bytes)
        if (manifest.get('format') != 1 or manifest.get('architecture') != 'win-x64' or
                manifest.get('toolchain') != 'llvm-mingw' or manifest.get('elfSha256') != ELFS[game]):
            raise ValueError('Incompatible sealed ' + game + ' kit.')
        verify_files(archive, manifest['files'], 'build-kit.json')
        for name in entries(archive):
            if (PurePosixPath(name).suffix.lower() in ('.iso', '.elf', '.obj', '.bin', '.ps2', '.db') or
                    PurePosixPath(name).name.lower() in ('reo_recomp.exe', 'reo_recomp_file2.exe', 'reo_launcher_game.exe')):
                raise ValueError('Private/game-derived content in input kit: ' + name)
        Path(manifest_path).write_bytes(manifest_bytes)


def check_reuse(changed):
    # Server source is rebuilt separately; its edits do not change the game kits.
    affected = [p for p in changed if not p.startswith('network/server/') and
                (p.startswith(GAME_INPUTS) or p in ('CMakeLists.txt', '.gitmodules'))]
    if affected:
        raise ValueError('Refresh and validate the sealed game inputs before release; changed inputs: ' +
                         ', '.join(affected[:12]))


def verify_package(path, tag=None, prerelease=None, source=None):
    with zipfile.ZipFile(path) as archive:
        verify_files(archive, json.loads(archive.read('package-manifest.json').decode('utf-8-sig')),
                     'package-manifest.json')
        members = entries(archive)
        required = {'Outbreak.Launcher.exe', 'XINPUT1_4.dll', 'reo-movie-check.exe',
                    'build-inputs.zip', 'build-inputs-file2.zip', 'distribution.json',
                    'network-server/server-manifest.json', 'THIRD-PARTY-NOTICES.txt'}
        if not required <= set(members):
            raise ValueError('Incomplete player package.')
        for name in members:
            if (PurePosixPath(name).suffix.lower() in ('.iso', '.elf', '.obj', '.db', '.ps2') or
                    PurePosixPath(name).name.lower() in ('reo_recomp.exe', 'reo_recomp_file2.exe', 'reo_launcher_game.exe')):
                raise ValueError('Private game content in player package.')
        distribution = json.loads(archive.read('distribution.json').decode('utf-8-sig'))
        if tag is not None and (distribution.get('releaseTag') != tag or
                               distribution.get('prerelease') is not prerelease or
                               distribution.get('revision') != source or
                               distribution.get('version') != options(tag, prerelease, 'validate-only')['version']):
            raise ValueError('Player package release identity mismatch.')
        return distribution


def prepare(root, work):
    opts = requested_options()
    repo, seed = os.environ['GITHUB_REPOSITORY'], os.environ['INPUTS_RELEASE']
    if not re.fullmatch(TAG, seed):
        raise ValueError('Select an existing versioned release for the game input kits.')
    source = run('git', 'rev-parse', 'HEAD', cwd=root)
    if source != os.environ['GITHUB_SHA']:
        raise ValueError('Checkout does not match the dispatched commit.')
    if not opts['prerelease']:
        if opts['publication'] == 'publish':
            try:
                run('git', 'merge-base', '--is-ancestor', source, 'refs/remotes/origin/main', cwd=root)
            except RuntimeError:
                raise ValueError('Stable release tags must point to a commit on main.') from None
        elif os.environ['GITHUB_REF'] != 'refs/heads/main':
            raise ValueError('Select main when preparing a stable release.')
    version_source = (root / 'launcher/Updates.cs').read_text(encoding='utf-8-sig')
    if not re.search(r'DefaultVersion\s*=\s*"' + re.escape(opts['version']) + '"', version_source):
        raise ValueError('Commit the matching launcher DefaultVersion before preparing this version.')
    seed_source = run('git', 'rev-parse', 'refs/tags/' + seed + '^{commit}', cwd=root)
    changed = run('git', 'diff', '--no-renames', '--name-only', seed_source, source, cwd=root).splitlines()
    check_reuse(changed)
    work.mkdir(parents=True, exist_ok=False)
    metadata = api(f'repos/{repo}/releases/tags/{seed}')
    if metadata.get('draft'):
        raise ValueError('Reuse kits from an existing published release.')
    names = [f'RE-Outbreak-{seed}-Windows-x64.zip', f'RE-Outbreak-{seed}-Dependency-Sources.zip']
    assets = {item['name']: item for item in metadata['assets']}
    for name in names:
        asset = assets[name]
        if not re.fullmatch(r'sha256:[0-9a-f]{64}', asset.get('digest') or ''):
            raise ValueError('Input release asset has no GitHub SHA-256 digest: ' + name)
        run('gh', 'release', 'download', seed, '--repo', repo, '--pattern', name, '--dir', str(work))
        if sha(work / name) != asset['digest'][7:]:
            raise ValueError('Downloaded release asset hash mismatch: ' + name)
    dist = verify_package(work / names[0], seed, bool(metadata['prerelease']), seed_source)
    with zipfile.ZipFile(work / names[0]) as archive:
        for game, name, kit_key, input_key in (
                ('file1', 'build-inputs.zip', 'kitSha256', 'inputsSha256'),
                ('file2', 'build-inputs-file2.zip', 'file2KitSha256', 'file2InputsSha256')):
            payload = work / name
            payload.write_bytes(archive.read(name))
            manifest = work / (game + '-build-kit.json')
            verify_kit(payload, manifest, game)
            if sha(payload) != dist[input_key] or sha(manifest) != dist[kit_key]:
                raise ValueError('Sealed kit does not match the input release identity.')
    with zipfile.ZipFile(work / names[1]) as archive:
        if archive.testzip() is not None:
            raise ValueError('Dependency source archive is corrupt.')
    opts.update(repository=repo, source=source, inputsRelease=seed, inputsSource=seed_source,
                dependencySources=names[1], dependencySourcesSha256=sha(work / names[1]),
                gameInputs={key: dist[key] for key in ('kitSha256', 'inputsSha256',
                                                      'file2KitSha256', 'file2InputsSha256')})
    write_json(work / 'options.json', opts)
    print(json.dumps({'tag': opts['tag'], 'source': source, 'publication': opts['publication'],
                      'inputsRelease': seed, 'gameInputsChanged': False}))


def finalize(work):
    opts = json.loads((work / 'options.json').read_text())
    assets = work / 'assets'
    assets.mkdir()
    package_name = f'RE-Outbreak-{opts["tag"]}-Windows-x64.zip'
    package = work / 'staged' / package_name
    dist = verify_package(package, opts['tag'], opts['prerelease'], opts['source'])
    if any(dist.get(key) != value for key, value in opts['gameInputs'].items()):
        raise ValueError('Player package changed the verified game input identity.')
    if sha(work / opts['dependencySources']) != opts['dependencySourcesSha256']:
        raise ValueError('Verified dependency source archive changed during packaging.')
    shutil.copyfile(package, assets / package_name)
    sources_name = f'RE-Outbreak-{opts["tag"]}-Dependency-Sources.zip'
    shutil.copyfile(work / opts['dependencySources'], assets / sources_name)
    for name in (package_name, sources_name):
        (assets / (name + '.sha256')).write_text(sha(assets / name) + '  ' + name + '\n', encoding='ascii')
    opts['assets'] = [{'name': p.name, 'sha256': sha(p)} for p in sorted(assets.iterdir())]
    write_json(work / 'release-plan.json', opts)
    notes = os.environ.get('RELEASE_NOTES', '').strip() or ('# RE: Outbreak ' + opts['tag'])
    notes += (f'\n\nBuilt from `{opts["source"]}`. Reuses unchanged, hash-verified File #1 and File #2 '
              f'game input kits and dependency sources from `{opts["inputsRelease"]}`. '
              'The launcher and package are rebuilt and checked in CI. Game compilation and gameplay '
              'are not rerun by this workflow.\n')
    (work / 'release-notes.md').write_text(notes, encoding='utf-8')


def publish(work):
    opts = json.loads((work / 'release-plan.json').read_text())
    checked = options(opts['tag'], opts['prerelease'], opts['publication'])
    if checked['publication'] == 'validate-only':
        print('Validate-only: no GitHub tag or release created.')
        return
    if (opts['source'] != os.environ['GITHUB_SHA'] or
            opts['repository'] != os.environ['GITHUB_REPOSITORY']):
        raise ValueError('Release artifact belongs to another commit or repository.')
    for asset in opts['assets']:
        name = asset['name']
        if name != PurePosixPath(name).name or '\\' in name or ':' in name:
            raise ValueError('Invalid release asset name.')
        if sha(work / 'assets' / name) != asset['sha256']:
            raise ValueError('Release artifact hash mismatch: ' + name)
    repo, tag = opts['repository'], opts['tag']
    # The maintainer's pushed tag must still name the validated commit; CI never moves
    # or creates tags.
    ref = api(f'repos/{repo}/git/ref/tags/{tag}')['object']
    for _ in range(8):
        if ref['type'] != 'tag':
            break
        ref = api(f'repos/{repo}/git/tags/{ref["sha"]}')['object']
    if ref['type'] != 'commit' or ref['sha'] != opts['source']:
        raise ValueError('Existing tag does not point to the validated commit.')
    files = [str(work / 'assets' / item['name']) for item in opts['assets']]
    run('gh', 'release', 'create', tag, '--repo', repo, '--verify-tag', '--target', opts['source'],
        '--title', 'RE: Outbreak ' + tag, '--draft', '--notes-file', str(work / 'release-notes.md'), *files)
    release = api(f'repos/{repo}/releases/tags/{tag}')
    remote = {a['name']: a for a in release['assets']}
    for asset in opts['assets']:
        if remote.get(asset['name'], {}).get('digest') != 'sha256:' + asset['sha256']:
            raise ValueError('Uploaded asset verification failed; release remains a draft.')
    # Configure draft prereleases too; stable releases become Latest only when published.
    api(f'repos/{repo}/releases/{release["id"]}', 'PATCH',
        {'prerelease': opts['prerelease'], 'draft': opts['publication'] != 'publish',
         'make_latest': 'false' if opts['prerelease'] or opts['publication'] != 'publish' else 'true'})
    print(release['html_url'])


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('command', choices=('prepare', 'finalize', 'publish'))
    parser.add_argument('--work', type=Path, required=True)
    parser.add_argument('--root', type=Path, default=Path.cwd())
    args = parser.parse_args()
    if args.command == 'prepare':
        prepare(args.root.resolve(), args.work.resolve())
    elif args.command == 'finalize':
        finalize(args.work.resolve())
    else:
        publish(args.work.resolve())
