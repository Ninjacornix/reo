import hashlib
import json
import tempfile
import unittest
import zipfile
from pathlib import Path

from pack_assets import create


class PackTests(unittest.TestCase):
    def test_string_only_json_and_csv_translations(self):
        for game in ('file1', 'file2'):
            with self.subTest(game=game), tempfile.TemporaryDirectory() as folder:
                from pack_assets import ELF
                import csv
                root = Path(folder); edited = root / 'edited'; references = edited / 'executable-strings'; references.mkdir(parents=True)
                index = root / 'assets.json'; index.write_text(json.dumps(dict(format=1, verified=True, entries=[])))
                entry = dict(id='test', address='0x00250f30', maxBytes=8, originalText='original', originalBytesHex=b'original'.hex(),
                             originalSha256=hashlib.sha256(b'original').hexdigest(), translation='PAK TEST')
                doc = dict(format=1, game=game, elfSha256=ELF[game], entries=[entry])
                path = references / 'ui-strings.json'; path.write_text(json.dumps(doc), encoding='utf-8')
                result = create(index, edited, root / 'text.pak', game, 'test.text', 'Text', '1')
                self.assertEqual(result['replace'], []); self.assertEqual(result['strings'][0]['text'], 'PAK TEST')
                entry['translation'] = None; path.write_text(json.dumps(doc), encoding='utf-8')
                with (references / 'ui-strings.csv').open('w', encoding='utf-8-sig', newline='') as stream:
                    writer = csv.writer(stream); writer.writerow(['id', 'address', 'maxBytes', 'originalText', 'translation'])
                    writer.writerow(['test', entry['address'], 8, 'original', 'PAK CSV'])
                result = create(index, edited, root / 'csv.pak', game, 'test.csv', 'CSV', '1')
                self.assertEqual(result['strings'][0]['text'], 'PAK CSV')
                entry['translation'] = 'far too long for slot'; path.write_text(json.dumps(doc), encoding='utf-8')
                with self.assertRaises(ValueError): create(index, edited, root / 'bad.pak', game, 'test.bad', 'Bad', '1')

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
