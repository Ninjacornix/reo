"""Create a new verified input kit with optimized generation tools; preserve old kits."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import shutil
import zipfile

from compilation_batches import with_generated_batches


def sha(path):
    with Path(path).open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def refresh(kit, output, recompiler, root, archive=None, dependency_sources=None, version=None,
            updated_sources=(), added_sources=(), added_shaders=()):
    kit, output, recompiler, root = [Path(p).resolve() for p in (kit, output, recompiler, root)]
    if output.exists() or output.is_relative_to(kit) or (archive and Path(archive).exists()):
        raise FileExistsError('Choose fresh immutable kit/archive paths')
    if bool(dependency_sources) != bool(version) or (
            version and not re.fullmatch(r'\d+\.\d+\.\d+', version)):
        raise ValueError('Supply both dependency sources and a three-part release version')
    if dependency_sources and not zipfile.is_zipfile(dependency_sources):
        raise ValueError('Dependency sources must be an existing ZIP')
    original = json.loads((kit / 'build-kit.json').read_text())
    if original.get('format') != 1 or original.get('architecture') != 'win-x64':
        raise ValueError('An existing Windows x64 input kit is required')
    output.mkdir(parents=True)
    seen = set()
    for entry in original['files']:
        name = entry['path']
        source = (kit / name).resolve()
        target = (output / name).resolve()
        if (not source.is_relative_to(kit) or not target.is_relative_to(output) or
                name.casefold() in seen or sha(source) != entry['sha256']):
            raise ValueError('Invalid or changed input: ' + name)
        seen.add(name.casefold())
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
        if sha(target) != entry['sha256']:
            raise ValueError('Copied input failed verification: ' + name)
    for name in ['build_game.py', 'generate_game.py', 'registration_chunks.py',
                 'compile_game.py', 'compile_linux.py', 'build_scheduler.py', 'compilation_batches.py']:
        shutil.copyfile(root / 'tools/local_build' / name, output / 'tools/local_build' / name)
    for name in ('compile-plan.json', 'compile-plan-linux.json'):
        plan_file = output / name
        if plan_file.is_file():
            plan_file.write_text(json.dumps(with_generated_batches(
                json.loads(plan_file.read_text())), indent=2) + '\n', encoding='utf-8')
    shutil.copyfile(recompiler, output / 'tools/ps2_recomp.exe')
    # Authored runtime fixes replace files the kit already carries; nothing new is added.
    for name in updated_sources:
        target = (output / 'source' / name).resolve()
        if not target.is_relative_to(output / 'source') or not target.is_file():
            raise ValueError('Only existing kit sources can be updated: ' + name)
        shutil.copyfile(root / name, target)
    for name in added_sources:
        target = (output / 'source' / name).resolve()
        if not target.is_relative_to(output / 'source') or target.exists():
            raise ValueError('Added sources must be new kit files: ' + name)
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(root / name, target)
    # Compiled helper shaders the runtime loads from reo-gpu-present beside the game.
    for name in added_shaders:
        source = (root / name).resolve()
        if source.suffix != '.spv' or (output / 'shaders' / source.name).exists():
            raise ValueError('Added shaders must be new .spv kit files: ' + name)
        shutil.copyfile(source, output / 'shaders' / source.name)
        destination = 'reo-gpu-present/' + source.name
        for plan_name in ('compile-plan.json', 'compile-plan-linux.json'):
            plan_file = output / plan_name
            if plan_file.is_file():
                plan = json.loads(plan_file.read_text())
                plan.setdefault('copyOutputs', []).append(
                    {'source': '{kit}/shaders/' + source.name, 'destination': destination})
                plan_file.write_text(json.dumps(plan, indent=2) + '\n', encoding='utf-8')
        original['outputs'].append(destination)
    # The existing corresponding SDK archive plus this independent-source delta
    # reproduces the changed compiler; runtime/library inputs are unchanged.
    updates = output / 'notices/source-updates'
    updates.mkdir(parents=True, exist_ok=True)
    shutil.copyfile(root / 'third_party/patches/ps2recomp/0096-faster-source-instrumentation.patch',
                    updates / '0096-faster-source-instrumentation.patch')
    if dependency_sources:
        notices = output / 'notices'
        (notices / 'SDK-SOURCES.txt').write_text(
            'Exact corresponding dependency sources are available beside this release:\n'
            f'https://github.com/Ninjacornix/reo/releases/download/v{version}/'
            f'RE-Outbreak-v{version}-Dependency-Sources.zip\n', encoding='utf-8')
        inventory_path = notices / 'independent-sdk-sources.json'
        inventory = json.loads(inventory_path.read_text())
        hashes = [item for item in inventory if 'sourceArchiveSha256' in item]
        if len(hashes) != 1:
            raise ValueError('Expected one corresponding source archive receipt')
        hashes[0]['sourceArchiveSha256'] = sha(dependency_sources)
        inventory_path.write_text(json.dumps(inventory, indent=2) + '\n', encoding='utf-8')
    original['files'] = [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                         for p in sorted(output.rglob('*')) if p.is_file()]
    (output / 'build-kit.json').write_text(json.dumps(original, indent=2) + '\n')
    if archive:
        with zipfile.ZipFile(archive, 'x', zipfile.ZIP_DEFLATED, compresslevel=6) as zipped:
            for source in sorted(output.rglob('*')):
                if source.is_file():
                    zipped.write(source, source.relative_to(output).as_posix())
    return {'files': len(original['files']), 'kitSha256': sha(output / 'build-kit.json'),
            'inputsSha256': sha(archive) if archive else None}


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ['kit', 'output', 'recompiler']:
        parser.add_argument('--' + name, required=True, type=Path)
    parser.add_argument('--root', type=Path, default=Path(__file__).resolve().parents[2])
    parser.add_argument('--archive', type=Path)
    parser.add_argument('--dependency-sources', type=Path)
    parser.add_argument('--version')
    parser.add_argument('--update-source', action='append', default=[],
                        help='Repository-relative authored source replacing the kit copy')
    parser.add_argument('--add-source', action='append', default=[],
                        help='Repository-relative authored source new to the kit')
    parser.add_argument('--add-shader', action='append', default=[],
                        help='Repository-relative compiled .spv shipped in reo-gpu-present')
    args = parser.parse_args()
    print(json.dumps(refresh(args.kit, args.output, args.recompiler, args.root, args.archive,
                             args.dependency_sources, args.version, args.update_source,
                             args.add_source, args.add_shader), indent=2))
