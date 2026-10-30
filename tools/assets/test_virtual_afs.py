"""Compile the standalone probe first; set REO_AFS_CHECK to its executable."""
import os
import struct
import subprocess
import tempfile
import unittest
from pathlib import Path

from test_relocation_probe import afs


@unittest.skipUnless(os.environ.get('REO_AFS_CHECK'), 'Set REO_AFS_CHECK to compiled virtual_afs_check')
class VirtualAfsTests(unittest.TestCase):
    def run_probe(self, source, output, *changes, ok=True):
        result = subprocess.run([os.environ['REO_AFS_CHECK'], str(source), str(output), *changes], capture_output=True)
        self.assertEqual(result.returncode == 0, ok, result.stderr.decode(errors='replace'))

    def test_identity_nested_sizes_alignment_names_and_determinism(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder)
            inner = afs([('one.bin', b'original'), ('two.bin', b'untouched' * 300)])
            src = root / 'original.afs'
            src.write_bytes(afs([('nested.afs', inner), ('other.bin', b'outer unchanged')]))
            out = root / 'identity.afs'
            self.run_probe(src, out)
            self.assertEqual(src.read_bytes(), out.read_bytes())
            for payload in (b'x', bytes(range(256)) * 40, b''):
                change = root / 'replacement.bin'; change.write_bytes(payload)
                out = root / 'changed.afs'; self.run_probe(src, out, f'0/0={change}')
                changed = out.read_bytes()
                outer_off, outer_size = struct.unpack_from('<II', changed, 8)
                off, size = struct.unpack_from('<II', changed, outer_off + 8)
                self.assertEqual(off % 2048, 0)
                self.assertEqual(outer_off % 2048, 0)
                self.assertEqual(changed[outer_off + off:outer_off + off + size], payload)
                next_off, next_size = struct.unpack_from('<II', changed, outer_off + 16)
                self.assertEqual(changed[outer_off + next_off:outer_off + next_off + next_size], b'untouched' * 300)
                outside, length = struct.unpack_from('<II', changed, 16)
                self.assertEqual(changed[outside:outside + length], b'outer unchanged')
                names, _ = struct.unpack_from('<II', changed, outer_off + 24)
                self.assertEqual(changed[outer_off + names:outer_off + names + 44], inner[struct.unpack_from('<I', inner, 24)[0]:][:44])
                self.assertEqual(struct.unpack_from('<I', changed, outer_off + names + 44)[0], len(payload))
                outer_names, _ = struct.unpack_from('<II', changed, 24)
                self.assertEqual(struct.unpack_from('<I', changed, outer_names + 44)[0], outer_size)
                self.run_probe(src, root / 'again.afs', f'0/0={change}')
                self.assertEqual(changed, (root / 'again.afs').read_bytes())

    def test_nameless_metadata_preservation_and_rejections(self):
        with tempfile.TemporaryDirectory() as folder:
            root = Path(folder); src = root / 'source.afs'; replacement = root / 'new.bin'; replacement.write_bytes(b'changed')
            raw = bytearray(afs([('one.bin', b'one'), ('room_h.bin', b'names')]))
            names = struct.unpack_from('<I', raw, 24)[0]
            struct.pack_into('<I', raw, names + 44, 0x12345678)
            src.write_bytes(raw)
            self.run_probe(src, root / 'out.afs', f'0={replacement}')
            changed = (root / 'out.afs').read_bytes(); new_names = struct.unpack_from('<I', changed, 24)[0]
            self.assertEqual(struct.unpack_from('<I', changed, new_names + 44)[0], 0x12345678)
            self.run_probe(src, root / 'bad.afs', f'1={replacement}', ok=False)
            self.run_probe(src, root / 'bad.afs', f'9={replacement}', ok=False)
            self.run_probe(src, root / 'bad.afs', f'0/0={replacement}', ok=False)
            struct.pack_into('<II', raw, 24, 0, 0); src.write_bytes(raw)
            self.run_probe(src, root / 'nameless.afs', f'0={replacement}')
            changed = (root / 'nameless.afs').read_bytes()
            off, size = struct.unpack_from('<II', changed, 8)
            self.assertEqual(changed[off:off + size], b'changed')
            self.assertEqual(struct.unpack_from('<II', changed, 24), (0, 0))
            src.write_bytes(afs([('child.afs', afs([('leaf', b'bytes')]))]))
            self.run_probe(src, root / 'bad.afs', f'0={replacement}', ok=False)


if __name__ == '__main__':
    unittest.main()
