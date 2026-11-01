"""Server exports must apply their patch even inside a parent checkout."""
import hashlib
import json
from pathlib import Path
import subprocess
import tempfile
import unittest

from export_server_source import export
from server_source import REVISION


class ServerSourceExportTests(unittest.TestCase):
    def test_nested_export_applies_patch_and_accepts_already_patched_source(self):
        with tempfile.TemporaryDirectory(prefix='reo-server-export-') as temporary:
            root = Path(temporary)
            subprocess.run(['git', 'init', '--quiet', str(root)], check=True)
            component = root / 'reference'
            relative = 'source/opensnap/plugins/outbreak/plugin.py'
            source = component / relative
            source.parent.mkdir(parents=True)
            source.write_text('room = original\n', encoding='utf-8')
            patch = root / 'network/server/patches/0001-outbreak-current-room-query.patch'
            patch.parent.mkdir(parents=True)
            patch.write_text('--- a/opensnap/plugins/outbreak/plugin.py\n'
                             '+++ b/opensnap/plugins/outbreak/plugin.py\n'
                             '@@ -1 +1 @@\n-room = original\n+room = current\n', encoding='utf-8')
            for name in ['requirements-portable.txt', 'SETUP.md']:
                (root / 'network/server' / name).write_text('Fixture\n', encoding='utf-8')

            def manifest():
                (component / 'server-manifest.json').write_text(json.dumps({
                    'revision': REVISION, 'files': [{'path': relative,
                        'sha256': hashlib.sha256(source.read_bytes()).hexdigest()}]}), encoding='utf-8')

            def check_output(folder):
                self.assertEqual((folder / relative).read_text(), 'room = current\n')
                record = json.loads((folder / 'server-manifest.json').read_text())
                entry = next(item for item in record['files'] if item['path'] == relative)
                self.assertEqual(entry['sha256'], hashlib.sha256((folder / relative).read_bytes()).hexdigest())

            manifest()
            first = root / 'nested portable Čakovec 測試' / 'first'
            export(component, first, root)
            check_output(first)
            self.assertEqual(source.read_text(), 'room = original\n')
            source.write_text('room = current\n', encoding='utf-8')
            manifest()
            second = first.parent / 'second'
            export(component, second, root)
            check_output(second)
            source.write_text('room = incompatible\n', encoding='utf-8')
            manifest()
            with self.assertRaisesRegex(ValueError, 'published patch'):
                export(component, first.parent / 'bad', root)


if __name__ == '__main__':
    unittest.main()
