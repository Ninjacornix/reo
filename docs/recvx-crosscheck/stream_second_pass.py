"""Offline stream identity/size audit; never builds or executes either game."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct
import subprocess
import sys

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent.parent
sys.path.insert(0, str(ROOT / 'tools/function_index'))
from index import Elf  # noqa: E402

COMMIT = '657b0c0c9489943116c71f151804ad7304fca975'
NOTES = ('SYMBOLS_CRI_SJUNI_LINKED_CHUNK_POOLS.md',
         'SYMBOLS_CRI_SJRB_POOL_AND_CHUNK_OWNERSHIP.md',
         'SYMBOLS_CRI_DTX_TRANSFER_CONTEXT_AND_ACKNOWLEDGEMENT.md')


def digest(data):
    return hashlib.sha256(data).hexdigest()


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--reference', required=True, type=Path)
    args = parser.parse_args()
    reference = args.reference.resolve()
    def git(*args):
        return subprocess.check_output(['git', '-C', str(reference), *args],
                                       text=True, encoding='utf-8').strip()
    assert git('rev-parse', 'HEAD') == COMMIT, 'Reference revision mismatch'
    assert not git('status', '--porcelain', '--untracked-files=no'), 'Dirty reference'
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    files = {}
    for stem in ('sj_uni', 'sj_rbf', 'dtx', 'sj_utl'):
        for directory, suffix in (('src', '.c'), ('include', '.h')):
            path = f'{directory}/cri/mwlib/ee/lib/libadxe/{stem}{suffix}'
            files[path] = (reference / path).read_bytes()
    uuid_checks = []
    for stem, name, address in (('sj_rbf', 'sjrbf_uuid', 0x23DA58),
                                ('sj_uni', 'sjuni_uuid', 0x23DA78)):
        path = f'src/cri/mwlib/ee/lib/libadxe/{stem}.c'
        match = re.search(r'\b'+name+r'\s*=\s*\{(.*?)\};',
                          files[path].decode('utf-8-sig'), re.S)
        assert match
        fields = [int(value, 16) for value in re.findall(r'0x[0-9a-f]+', match[1], re.I)]
        assert len(fields) == 11
        packed = struct.pack('<IHH8B', *fields)
        assert elf.read(address, 16) == packed
        uuid_checks.append(dict(reference_identifier=name, owned_address=f'0x{address:08X}',
                                ps2_little_endian_bytes=packed.hex(), identical=True))
    # These actual immediate instructions establish byte lengths, not C sizeof
    # in a host build with a different pointer width.
    sizes = []
    for pc, expected, role, size in (
        (0x1401C4, 0x24060030, 'SJUNI object clear', 48),
        (0x13F9B8, 0x24060040, 'SJRB object clear', 64),
        (0x139164, 0x24060044, 'DTX object clear', 68),
    ):
        assert int.from_bytes(elf.read(pc, 4), 'little') == expected
        sizes.append(dict(pc=f'0x{pc:08X}', word=f'{expected:08X}', role=role,
                          decimal_bytes=size, hexadecimal_bytes=f'0x{size:X}'))
    entries = {0x138EA8, 0x138EC0}
    for note in NOTES:
        entries.update(int(value, 16) for value in re.findall(
            r'^\| \[0x([0-9a-f]+)\]', (ROOT / 'docs' / note).read_text(encoding='utf-8'), re.M|re.I))
    db = sqlite3.connect(ROOT / 'build-function-index/index.sqlite')
    db.row_factory = sqlite3.Row
    bodies = []
    total_comments = total_zeros = 0
    for address in sorted(entries):
        f = db.execute('select * from functions where image=? and start=?', ('main', address)).fetchone()
        assert f and f['source']
        raw = elf.read(address, f['end']-address)
        assert raw is not None and len(raw) % 4 == 0
        seen = set()
        for match in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s+',
                                 (ROOT / f['source']).read_text(encoding='utf-8'), re.I):
            pc, word = int(match[1], 16), int(match[2], 16)
            if address <= pc < f['end']:
                assert int.from_bytes(elf.read(pc, 4), 'little') == word
                seen.add(pc)
        omitted = [pc for pc in range(address, f['end'], 4) if pc not in seen]
        assert all(elf.read(pc, 4) == bytes(4) for pc in omitted)
        total_comments += len(seen)
        total_zeros += len(omitted)
        bodies.append(dict(id=f['id'], end=f'0x{f["end"]:08X}', source=f['source'],
                           sha256=digest(raw), instruction_comments=len(seen),
                           omitted_zero_words=len(omitted)))
    hello = elf.string(0x23C950)
    assert hello == 'Hello from EE (%d)'
    out = dict(schema=1, date='2026-11-05', reference_commit=COMMIT,
               elf_sha256=elf.sha256, reference_files={path:digest(raw) for path,raw in files.items()},
               uuid_checks=uuid_checks, byte_size_checks=sizes, owned_default_DTX_format=hello,
               verified_complete_intervals=len(bodies), instruction_comments=total_comments,
               omitted_zero_words=total_zeros, omitted_nonzero_words=0, bodies=bodies,
               scope='Word/hash integrity and explicit UUID/size/string checks; comparative semantics remain authored in STREAM_SECOND_PASS.md. No runtime or equivalence claim.')
    (ROOT / 'build-function-index/recvx-stream-second-pass.json').write_text(
        json.dumps(out, indent=2)+'\n', encoding='utf-8')
    print(f'{len(bodies)} complete intervals; {total_comments} comments; {total_zeros} omitted NOPs; '
          '0 conflicts/nonzero omissions; 2 matching UUIDs; decimal byte lengths48/64/68.')


if __name__ == '__main__':
    main()
