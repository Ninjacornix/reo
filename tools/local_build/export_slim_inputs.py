"""Pack independent first-run inputs without redistributing a system toolchain."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import zipfile

from compilation_batches import with_generated_batches


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def export(kit, output, archive, root, version='1.0.7'):
    kit, output, archive, root = map(lambda p: Path(p).resolve(), (kit, output, archive, root))
    if output.exists() or archive.exists():
        raise FileExistsError('Choose new output paths; previous exports are preserved')
    original = json.loads((kit / 'build-kit.json').read_text())
    for entry in original['files']:
        if entry['path'].startswith('toolchain/') or entry['path'] == 'notices/independent-sdk-sources.zip':
            continue
        source = kit / entry['path']
        if not source.resolve().is_relative_to(kit) or sha(source) != entry['sha256']:
            raise ValueError('Independent input verification failed: ' + entry['path'])
        destination = output / entry['path']
        destination.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, destination)
    plan_file = output / 'compile-plan.json'
    plan = with_generated_batches(json.loads(plan_file.read_text()))
    external_compiler = plan.get('externalCompilerSha256') if plan.get('externalToolchain') else None
    if plan.get('externalToolchain'):
        if not isinstance(external_compiler, str) or len(external_compiler) != 64 or any(
                c not in '0123456789abcdef' for c in external_compiler):
            raise ValueError('An external-toolchain kit must retain its verified compiler identity')
    else:
        external_compiler = sha(kit / plan['compiler'].removeprefix('{kit}/'))
    plan['externalToolchain'] = True
    plan['externalCompilerSha256'] = external_compiler
    plan_file.write_text(json.dumps(plan, indent=2), encoding='utf-8')
    for name in ['build_game.py', 'generate_game.py', 'generate_support.py', 'registration_chunks.py',
                 'compile_game.py', 'compile_linux.py', 'build_scheduler.py', 'compilation_batches.py',
                 'long_paths.py']:
        shutil.copyfile(root / 'tools/local_build' / name, output / 'tools/local_build' / name)
    (output / 'notices/SDK-SOURCES.txt').write_text(
        'Exact corresponding dependency sources are available beside this release:\n'
        f'https://github.com/Ninjacornix/reo/releases/download/v{version}/RE-Outbreak-v{version}-Dependency-Sources.zip\n',
        encoding='utf-8')
    original['files'] = [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                         for p in sorted(output.rglob('*')) if p.is_file()]
    (output / 'build-kit.json').write_text(json.dumps(original, indent=2), encoding='utf-8')
    with zipfile.ZipFile(archive, 'x', zipfile.ZIP_DEFLATED, compresslevel=6) as zipped:
        for source in sorted(output.rglob('*')):
            if source.is_file():
                zipped.write(source, source.relative_to(output).as_posix())
    print(json.dumps({'files': len(original['files']), 'archiveBytes': archive.stat().st_size,
                      'inputsSha256': sha(archive), 'kitSha256': sha(output / 'build-kit.json')}, indent=2))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('kit', 'output', 'archive', 'root'):
        parser.add_argument('--' + name, type=Path, required=True)
    parser.add_argument('--version', default='1.0.7')
    args = parser.parse_args()
    export(args.kit, args.output, args.archive, args.root, args.version)
