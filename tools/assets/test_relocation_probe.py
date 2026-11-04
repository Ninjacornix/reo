import hashlib
import json
import struct
import tempfile
import unittest
from pathlib import Path

from relocation_probe import build, toc


def afs(items):
    data = bytearray(2048)
    data[:8] = b'AFS\0' + struct.pack('<I', len(items))
    for index, (_, payload) in enumerate(items):
        struct.pack_into('<II', data, 8 + index * 8, len(data), len(payload))
        data += payload
        data += b'\xa5' * (-len(data) % 2048)
    names = len(data)
    for name, payload in items:
        data += name.encode().ljust(32, b'\0') + bytes(12) + struct.pack('<I', len(payload))
    struct.pack_into('<II', data, 8 + len(items) * 8, names, len(items) * 48)
    return bytes(data)


def directory_entry(lba, size, name):
    result = bytearray(34 + len(name))
    result[0] = len(result)
    struct.pack_into('<I', result, 2, lba)
    struct.pack_into('<I', result, 10, size)
    result[32] = len(name)
    result[33:33 + len(name)] = name
    return result


class RelocationTests(unittest.TestCase):
    def test_nested_relocation_preserves_payloads_and_source(self):
        with tempfile.TemporaryDirectory(prefix='reo-afs-probe-') as folder:
            source, output = Path(folder) / 'owned.iso', Path(folder) / 'relocated.iso'
            room = afs([('texture.bin', bytes(range(256)) * 3), ('model.bin', b'model' * 500)])
            archive = afs([('romdata_usa.afs', b'unchanged'), ('r001.afs', room), ('r001_h.bin', b'names')])
            image = bytearray(22 * 2048)
            image[16 * 2048 + 1:16 * 2048 + 6] = b'CD001'
            image[16 * 2048 + 156:16 * 2048 + 190] = directory_entry(20, 2048, b'')
            record = directory_entry(22, len(archive), b'NETBIO00.DAT;1')
            image[20 * 2048:20 * 2048 + len(record)] = record
            source.write_bytes(image + archive)
            digest = hashlib.sha256(source.read_bytes()).hexdigest()
            result = build(source, output, 'r001.afs')
            self.assertEqual(hashlib.sha256(source.read_bytes()).hexdigest(), digest)
            self.assertEqual(result['relocated_netbio_bytes'], len(archive) + 4096)
            with source.open('rb') as old, output.open('rb') as new:
                old_base, new_base = 22 * 2048, result['relocated_netbio_lba'] * 2048
                old_entries, _, _, old_labels = toc(old, old_base, len(archive))
                new_entries, _, _, new_labels = toc(new, new_base, len(archive) + 4096)
                self.assertEqual(old_labels, new_labels)
                for index in (0, 2):
                    old.seek(old_base + old_entries[index][0])
                    new.seek(new_base + new_entries[index][0])
                    self.assertEqual(old.read(old_entries[index][1]), new.read(new_entries[index][1]))
                old_room = old_base + old_entries[1][0]
                new_room = new_base + new_entries[1][0]
                old_inner, _, _, _ = toc(old, old_room, old_entries[1][1])
                new_inner, _, _, _ = toc(new, new_room, new_entries[1][1])
                for (offset, size), (changed_offset, changed_size) in zip(old_inner, new_inner):
                    self.assertEqual(changed_offset, offset + 2048)
                    self.assertEqual(size, changed_size)
                    old.seek(old_room + offset)
                    new.seek(new_room + changed_offset)
                    self.assertEqual(old.read(size), new.read(size))
            with self.assertRaises(ValueError):
                build(source, source, 'r001.afs')
            with self.assertRaises(ValueError):
                build(source, output, 'r001.afs')


if __name__ == '__main__':
    unittest.main()
