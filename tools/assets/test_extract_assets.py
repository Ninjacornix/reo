import io
import struct
import tempfile
import unittest
from pathlib import Path

from extract_assets import extract, table
from test_relocation_probe import afs


class ExtractTests(unittest.TestCase):
    def test_duplicate_and_unsafe_names_preserve_indexed_payloads(self):
        with tempfile.TemporaryDirectory() as folder:
            data, output = Path(folder) / 'data', Path(folder) / 'output'
            data.mkdir()
            payload = afs([('../room.afs', afs([('SOUN', b'one'), ('SOUN', b'two')])),
                           ('../../outside', b'other')])
            source = data / 'NETBIO00.DAT'
            source.write_bytes(payload)
            manifest = extract(data, output)
            self.assertEqual([r['path'] for r in manifest['entries']],
                             ['NETBIO00.DAT/0/0', 'NETBIO00.DAT/0/1', 'NETBIO00.DAT/1'])
            self.assertEqual([(output / r['file']).read_bytes() for r in manifest['entries']],
                             [b'one', b'two', b'other'])
            self.assertEqual(source.read_bytes(), payload)
            self.assertTrue(all(output.resolve() in (output / r['file']).resolve().parents
                                for r in manifest['entries']))
            with self.assertRaises(ValueError):
                extract(data, output)
            with self.assertRaises(ValueError):
                extract(data, data / 'nested')

    def test_rejects_out_of_bounds_entry(self):
        raw = bytearray(afs([('bad', b'payload')]))
        struct.pack_into('<II', raw, 8, len(raw) - 1, 100)
        with self.assertRaises(ValueError):
            table(io.BytesIO(raw), 0, len(raw))


if __name__ == '__main__':
    unittest.main()
