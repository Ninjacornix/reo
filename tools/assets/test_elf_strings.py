import csv
import io
import json
import struct
import tempfile
import unittest
import zipfile
from pathlib import Path

import extract_elf_strings as strings


def elf_fixture():
    data = bytearray(512)
    struct.pack_into('<16sHHIIIIIHHHHHH', data, 0,
                     b'\x7fELF\x01\x01\x01' + b'\0' * 9, 2, 8, 1, 0x100000,
                     52, 0, 0, 52, 32, 1, 0, 0, 0)
    struct.pack_into('<8I', data, 52, 1, 128, 0x100000, 0x100000, 384, 384, 7, 128)
    struct.pack_into('<I', data, 128, 0x100020)
    raw = b'  EQUIP\0<p1>Use %s?\n\0' + '\uff22\uff12\uff26'.encode('cp932') + b'\0  EQUIP\0\x01junk\0UNTERMINATED'
    data[160:160 + len(raw)] = raw
    return bytes(data), 160, 160 + len(raw)


class ElfStringTests(unittest.TestCase):
    def test_addresses_budgets_tokens_and_duplicates(self):
        data, start, end = elf_fixture()
        _, entries, originals = strings.candidates(data, start, end, end)
        self.assertEqual(len(entries), 4)
        self.assertEqual(entries[0]['address'], '0x00100020')
        self.assertEqual(entries[0]['maxBytes'], 7)
        self.assertEqual(entries[0]['originalText'], '  EQUIP')
        self.assertEqual(entries[0]['literalAddressWordFileOffsets'], ['0x00000080'])
        self.assertEqual(entries[1]['controlTokens'], ['<p1>'])
        self.assertEqual(entries[1]['formatTokens'], ['%s'])
        self.assertGreater(entries[2]['maxBytes'], len(entries[2]['originalText']))
        self.assertNotEqual(entries[0]['id'], entries[3]['id'])
        for entry in entries:
            offset, size = entry['fileOffset'], entry['maxBytes']
            expected = data[offset:offset + size + 1]
            self.assertEqual(bytes.fromhex(entry['originalBytesHex']) + b'\0', expected)
            self.assertEqual(originals[entry['originalsOffset']:entry['originalsOffset'] + size + 1], expected)

    def test_invalid_layout_and_ranges(self):
        data, start, end = elf_fixture()
        for corrupt in (data[:40], b'BAD!' + data[4:]):
            with self.assertRaises(ValueError): strings.load_segments(corrupt)
        corrupt = bytearray(data); struct.pack_into('<I', corrupt, 52 + 16, 5000)
        with self.assertRaises(ValueError): strings.load_segments(corrupt)
        for first, last in ((start + 1, end), (start, len(data) + 1), (end, start)):
            with self.assertRaises(ValueError): strings.candidates(data, first, last, last)

    def test_second_game_reference_identity(self):
        data, start, end = elf_fixture()
        with tempfile.TemporaryDirectory(prefix='reo-elf-file2-tests-') as temp:
            root = Path(temp); imported = root / 'import'; imported.mkdir()
            elf = imported / 'SLUS_209.84'; elf.write_bytes(data)
            result = strings.export(elf, root / 'export', game='file2', expected_sha=strings.sha(data), start=start, end=end, ui_end=end)
            self.assertEqual(result['game'], 'file2')
            self.assertEqual(Path(result['pak']).name, 'executable-strings-file2.pak')
            with zipfile.ZipFile(result['pak']) as archive:
                header = json.loads(archive.read('string-reference.json'))
                self.assertEqual(header['elf'], 'SLUS_209.84')
                self.assertEqual(json.loads(archive.read('strings.json'))['game'], 'file2')
            with self.assertRaises(ValueError): strings.export(elf, root / 'wrong-revision', game='file2')

    def test_verified_reference_pack_and_refusals(self):
        data, start, end = elf_fixture()
        with tempfile.TemporaryDirectory(prefix='reo-elf-string-tests-') as temp:
            root = Path(temp); elf = root / 'SLUS_207.65'; elf.write_bytes(data)
            output = root / 'export'
            kwargs = dict(expected_sha=strings.sha(data), start=start, end=end, ui_end=end)
            # The source and references must be in separate data directories.
            imported = root / 'import'; imported.mkdir(); elf = imported / elf.name; elf.write_bytes(data)
            result = strings.export(elf, output, **kwargs)
            self.assertTrue(result['passed']); self.assertTrue(result['runtimePatchSupported'])
            self.assertEqual(elf.read_bytes(), data)
            with zipfile.ZipFile(result['pak']) as archive:
                self.assertIsNone(archive.testzip())
                header = json.loads(archive.read('string-reference.json'))
                for name, info in header['files'].items():
                    self.assertEqual(strings.sha(archive.read(name)), info['sha256'])
                rows = list(csv.DictReader(io.StringIO(archive.read('ui-strings.csv').decode('utf-8-sig'))))
                self.assertEqual(len(rows), 4); self.assertEqual(rows[1]['originalText'], '<p1>Use %s?\n')
                self.assertNotIn('pak.json', archive.namelist())
            with self.assertRaises(ValueError): strings.export(elf, output, **kwargs)
            with self.assertRaises(ValueError): strings.export(elf, imported / 'bad-output', **kwargs)
            with self.assertRaises(ValueError): strings.export(elf, root / 'wrong-hash')


if __name__ == '__main__':
    unittest.main()
