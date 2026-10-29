import hashlib
import json
import tempfile
import unittest
import zipfile
from pathlib import Path

from pack_assets import create


class PackTests(unittest.TestCase):
    def test_only_edited_payloads_are_packaged_and_existing_output_is_preserved(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder); edited = root / 'edited'; edited.mkdir()
            (edited / 'same.bin').write_bytes(b'original')
            (edited / 'changed.bin').write_bytes(b'modder edit')
            entries = [dict(path=f'NETBIO00.DAT/0/{i}', file=name,
                            sha256=hashlib.sha256(b'original').hexdigest())
                       for i, name in enumerate(['same.bin', 'changed.bin', 'absent.bin'])]
            index = root / 'assets.json'; index.write_text(json.dumps(dict(format=1, verified=True, entries=entries)))
            output = root / 'test.pak'
            result = create(index, edited, output, 'file2', 'test.asset', 'Test', '1')
            self.assertEqual([e['path'] for e in result['replace']], ['NETBIO00.DAT/0/1'])
            with zipfile.ZipFile(output) as archive:
                self.assertEqual(len(archive.namelist()), 2)
                self.assertEqual(archive.read(result['replace'][0]['file']), b'modder edit')
            before = output.read_bytes()
            with self.assertRaises(FileExistsError):
                create(index, edited, output, 'file2', 'test.asset', 'Test', '1')
            self.assertEqual(output.read_bytes(), before)


if __name__ == '__main__':
    unittest.main()
