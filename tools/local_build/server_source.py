"""Reproducible, separately licensed openSNAP source and local patch closure."""
import io
from pathlib import Path
import shutil
import subprocess
import tarfile
import tempfile

REVISION = '1014371ba70d1caa415a09b1fa39f550b1e9cb55'


def archive(checkout, destination):
    checkout, destination = Path(checkout).resolve(), Path(destination)
    actual = subprocess.check_output(['git', '-C', str(checkout), 'rev-parse', 'HEAD'], text=True).strip()
    if actual != REVISION:
        raise ValueError('Use pinned openSNAP revision ' + REVISION)
    data = subprocess.check_output(['git', '-C', str(checkout), 'archive', REVISION])
    destination.mkdir(parents=True, exist_ok=True)
    with tarfile.open(fileobj=io.BytesIO(data)) as package:
        package.extractall(destination, filter='data')


def patch_source(source, root):
    """Apply each published patch idempotently, independent of a parent git checkout."""
    source, root = Path(source), Path(root)
    patches = sorted((root / 'network/server/patches').glob('*.patch'))
    with tempfile.TemporaryDirectory(prefix='reo-server-patch-') as temporary:
        work = Path(temporary)
        subprocess.run(['git', 'init', '--quiet', str(work)], check=True)
        shutil.copytree(source, work, dirs_exist_ok=True)
        for patch in patches:
            command = ['git', 'apply', '--no-index', '--exclude=tests/*']
            forward = subprocess.run([*command, '--check', str(patch.resolve())], cwd=work, capture_output=True)
            if not forward.returncode:
                subprocess.run([*command, str(patch.resolve())], cwd=work, check=True)
            elif subprocess.run([*command, '--reverse', '--check', str(patch.resolve())],
                                cwd=work, capture_output=True).returncode:
                raise ValueError('Server source does not match published patch: ' + patch.name)
        # Only copy files mentioned by the patch series, excluding upstream tests.
        for patch in patches:
            for line in patch.read_text(encoding='utf-8').splitlines():
                if not line.startswith('+++ b/'):
                    continue
                relative = Path(line[6:])
                if relative.is_absolute() or '..' in relative.parts:
                    raise ValueError('Unsafe server patch path')
                if relative.parts[0] == 'tests':
                    continue
                target = source / relative
                target.parent.mkdir(parents=True, exist_ok=True)
                shutil.copyfile(work / relative, target)
    native = root / 'network/server/native'
    if native.is_dir():
        shutil.copytree(native, source / 'reo_native', dirs_exist_ok=True,
                        ignore=shutil.ignore_patterns('__pycache__', '*.pyc', 'test_*'))
