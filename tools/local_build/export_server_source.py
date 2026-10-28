"""Export verified openSNAP source; Python and pip packages remain external."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess
import tempfile


def sha(path):
    with path.open('rb') as stream:
        return hashlib.file_digest(stream, 'sha256').hexdigest()


def export(component, output, root):
    component, output, root = map(lambda p: Path(p).resolve(), (component, output, root))
    if output.exists():
        raise FileExistsError('Choose a new server export directory')
    original = json.loads((component / 'server-manifest.json').read_text())
    prefixes = ('source/opensnap/', 'source/opensnap_app/',
                'source/opensnap_web/', 'source/opensnap_dns/')
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
    # Frozen reference components may predate the current room-query fix.
    # Bind the shipped server to the published patch, including when the
    # component already contains it, without modifying the reference source.
    patch = root / 'network/server/patches/0001-outbreak-current-room-query.patch'
    relative = 'opensnap/plugins/outbreak/plugin.py'
    with tempfile.TemporaryDirectory(prefix='reo-server-patch-') as temporary:
        # An isolated repository prevents git apply from silently filtering paths
        # when the export directory is inside the maintainer's checkout.
        work = Path(temporary)
        subprocess.run(['git', 'init', '--quiet', str(work)], check=True)
        target = work / relative
        target.parent.mkdir(parents=True)
        shutil.copyfile(output / 'source' / relative, target)
        command = ['git', 'apply', '--no-index', '--include=' + relative]
        forward = subprocess.run([*command, '--check', str(patch)], cwd=work, capture_output=True)
        if forward.returncode == 0:
            subprocess.run([*command, str(patch)], cwd=work, check=True)
        else:
            reverse = subprocess.run([*command, '--reverse', '--check', str(patch)], cwd=work,
                                     capture_output=True)
            if reverse.returncode:
                raise ValueError('Server component does not match the published room-query patch')
        shutil.copyfile(target, output / 'source' / relative)
    shutil.copyfile(root / 'network/server/requirements-portable.txt', output / 'requirements.txt')
    shutil.copyfile(root / 'network/server/SETUP.md', output / 'README.md')
    record = {'format': 2, 'architecture': 'win-x64', 'revision': original['revision'],
              'runtime': 'external-python', 'source': 'source',
              'requirements': 'requirements.txt',
              'files': [{'path': p.relative_to(output).as_posix(), 'sha256': sha(p)}
                        for p in sorted(output.rglob('*')) if p.is_file()]}
    (output / 'server-manifest.json').write_text(json.dumps(record, indent=2) + '\n', encoding='utf-8')
    print(json.dumps({'files': len(record['files']),
                      'bytes': sum(p.stat().st_size for p in output.rglob('*') if p.is_file())}))


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    for name in ('component', 'output', 'root'):
        parser.add_argument('--' + name, type=Path, required=True)
    args = parser.parse_args()
    export(args.component, args.output, args.root)
