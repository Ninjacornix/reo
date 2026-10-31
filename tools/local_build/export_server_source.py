"""Export verified openSNAP source; Python and pip packages remain external."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tempfile

from server_source import REVISION, archive, patch_source


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def export(component, output, root, *, checkout=None):
    output, root = Path(output).resolve(), Path(root).resolve()
    if output.exists():
        raise FileExistsError('Choose a new server export directory')
    if checkout is not None:
        with tempfile.TemporaryDirectory(prefix='reo-server-source-') as temporary:
            source = Path(temporary) / 'source'
            archive(checkout, source)
            original = {'revision': REVISION, 'files': [
                {'path': p.relative_to(Path(temporary)).as_posix(), 'sha256': sha(p)}
                for p in sorted(source.rglob('*')) if p.is_file()]}
            (Path(temporary) / 'server-manifest.json').write_text(json.dumps(original), encoding='utf-8')
            return export(temporary, output, root)
    component = Path(component).resolve()
    original = json.loads((component / 'server-manifest.json').read_text())
    if original['revision'] != REVISION:
        raise ValueError('Outdated server component; export pinned RC2 source with --checkout')
    prefixes = ('source/opensnap/', 'source/opensnap_app/',
                'source/opensnap_web/', 'source/opensnap_dns/', 'source/data/logo/',
                'source/data/outbreak/files/', 'source/data/outbreak2/files/')
    for entry in original['files']:
        relative = entry['path']
        if relative not in ('source/run.py', 'source/LICENSE') and not relative.startswith(prefixes):
            continue
        source = (component / relative).resolve()
        if not source.is_relative_to(component) or sha(source) != entry['sha256']:
            raise ValueError('Server source verification failed: ' + relative)
        if source.suffix.lower() in ('.pyc', '.pyd', '.dll', '.exe', '.db'):
            raise ValueError('Unexpected binary or state in server source: ' + relative)
        target = output / relative
        target.parent.mkdir(parents=True, exist_ok=True)
        shutil.copyfile(source, target)
    patch_source(output / 'source', root)
    shutil.copyfile(root / 'network/server/requirements-portable.txt', output / 'requirements.txt')
    shutil.copyfile(root / 'network/server/SETUP.md', output / 'README.md')
    record = {'format': 2, 'architecture': 'win-x64', 'revision': original['revision'],
              'patches': [{'path': p.name, 'sha256': sha(p)}
                          for p in sorted((root / 'network/server/patches').glob('*.patch'))],
              'runtime': 'external-python', 'source': 'source',
              'requirements': 'requirements.txt',
              'files': [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                        for p in sorted(output.rglob('*')) if p.is_file()]}
    (output / 'server-manifest.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'files': len(record['files']),
                      'bytes': sum(p.stat().st_size for p in output.rglob('*') if p.is_file())}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    group = parser.add_mutually_exclusive_group(required=True)
    for name in ('component', 'checkout'):
        group.add_argument('--' + name, type=Path)
    for name in ('output', 'root'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    export(args.component, args.output, args.root, checkout=args.checkout)
