"""A refreshed slim kit carries RC1's path helper without repository imports."""
import hashlib
import json
from pathlib import Path
import subprocess
import sys
import tempfile
import unittest
import zipfile

from export_slim_inputs import export


class SlimLongPathTests(unittest.TestCase):
    def test_refreshed_worker_imports_outside_repository(self):
        with tempfile.TemporaryDirectory() as directory:
            root = Path(directory)
            kit = root / 'kit'
            (kit / 'tools/local_build').mkdir(parents=True)
            (kit / 'tools/local_build/build_game.py').write_text('# Synthetic previous worker\n')
            (kit / 'notices').mkdir()
            (kit / 'notices/LICENSE.txt').write_text('Synthetic notice fixture\n')
            (kit / 'toolchain/bin').mkdir(parents=True)
            (kit / 'toolchain/bin/compiler.exe').write_bytes(b'Synthetic compiler identity')
            (kit / 'compile-plan.json').write_text(json.dumps({
                'format': 1, 'sourceGroups': [], 'compiler': '{kit}/toolchain/bin/compiler.exe'}))
            files = [{'path': p.relative_to(kit).as_posix(),
                      'sha256': hashlib.sha256(p.read_bytes()).hexdigest()}
                     for p in kit.rglob('*') if p.is_file()]
            (kit / 'build-kit.json').write_text(json.dumps({'format': 1, 'files': files}))
            output, archive = root / 'output', root / 'inputs.zip'
            export(kit, output, archive, Path(__file__).resolve().parents[2])
            with zipfile.ZipFile(archive) as zipped:
                manifest = json.loads(zipped.read('build-kit.json'))
                helper = next(f for f in manifest['files']
                              if f['path'] == 'tools/local_build/long_paths.py')
                self.assertEqual(hashlib.sha256(zipped.read(helper['path'])).hexdigest(), helper['sha256'])
            result = subprocess.run([sys.executable, '-I', '-c',
                'import sys; sys.path.insert(0, sys.argv[1]); import compile_game, long_paths',
                str(output / 'tools/local_build')], cwd=root, capture_output=True, text=True)
            self.assertEqual(result.returncode, 0, result.stderr)


if __name__ == '__main__':
    unittest.main()
