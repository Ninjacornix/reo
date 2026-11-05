#!/usr/bin/env python3
"""Offline, hash-bound evidence for the nine final resident leaf-role reviews.

Scans file-backed words for possible pointers/direct transfers, not live memory.
A raw hit is a candidate reference, never proof of execution or reachability.
"""
from __future__ import annotations

import hashlib
import json
from pathlib import Path
import re
import sqlite3
import struct

from index import Elf, ROOT

TARGETS = (0x11707C, 0x132FB0, 0x132FC8, 0x1A1DA0, 0x1A2C80,
           0x1A3590, 0x1A9190, 0x1B3830, 0x1D66D0)


def main():
    elf = Elf(ROOT / 'game_data/SLUS_207.65')
    images = [('main', base, elf.data[offset:offset+size])
              for base, offset, size in elf.segments]
    profile = json.loads((ROOT / 'tools/function_index/overlay_identities.json').read_text())
    for item in profile['images']:
        data = (ROOT / f'build-function-index/owned-overlays/{item["image"]}.bin').read_bytes()
        assert hashlib.sha256(data).hexdigest() == item['imageSha256']
        images.append((item['image'], item['base'], data))
    connection = sqlite3.connect(ROOT / 'build-function-index/index.sqlite')
    connection.row_factory = sqlite3.Row
    records = {target: dict(address=f'0x{target:08X}', pointer_candidates=[],
                            unaligned_or_alias_pointer_candidates=[], direct_transfer_candidates=[])
               for target in TARGETS}
    words_scanned = 0
    for image, base, data in images:
        # Include unaligned literal words and EE cached/uncached virtual aliases.
        # Matching a numeric word is still only a discovery candidate.
        for target in TARGETS:
            for alias in (0, 0x80000000, 0xA0000000):
                needle = struct.pack('<I', target | alias)
                offset = data.find(needle)
                while offset != -1:
                    if alias or (base+offset) % 4:
                        records[target]['unaligned_or_alias_pointer_candidates'].append(
                            dict(image=image, site=f'0x{base+offset:08X}', value=f'0x{target|alias:08X}'))
                    offset = data.find(needle, offset+1)
        for offset in range((-base) % 4, len(data)-3, 4):
            pc = base+offset
            word = struct.unpack_from('<I', data, offset)[0]
            words_scanned += 1
            if word in records:
                records[word]['pointer_candidates'].append(dict(image=image, site=f'0x{pc:08X}'))
            if word >> 26 not in (2, 3):
                continue
            target = ((pc+4) & 0xF0000000) | ((word & 0x3FFFFFF) << 2)
            if target in records:
                records[target]['direct_transfer_candidates'].append(
                    dict(image=image, site=f'0x{pc:08X}', kind='jal' if word >> 26 == 3 else 'j'))
    verified_words = 0
    for target, result in records.items():
        f = connection.execute('select * from functions where image=? and start=?', ('main', target)).fetchone()
        raw = elf.read(target, f['end']-target)
        assert raw is not None
        result.update(end=f'0x{f["end"]:08X}', sha256=hashlib.sha256(raw).hexdigest(),
                      source=f['source'], words=[f'{word[0]:08X}' for word in struct.iter_unpack('<I', raw)])
        comments = {}
        for match in re.finditer(r'// 0x([\da-f]+): 0x([\da-f]+)\s+', (ROOT / f['source']).read_text(), re.I):
            pc, word = int(match[1], 16), int(match[2], 16)
            if target <= pc < f['end']:
                assert int.from_bytes(elf.read(pc, 4), 'little') == word
                comments[pc] = word
        # Missing NOPs are allowed; omitted nonzero words are not.
        assert all(pc in comments or elf.read(pc, 4) == bytes(4) for pc in range(target, f['end'], 4))
        verified_words += len(comments)
        result['indexed_callers'] = [dict(row) for row in connection.execute(
            'select caller,site,kind from edges where target=? order by caller,site', (target,))]
        expected = {(row['caller'].split(':')[0], row['site'], row['kind'])
                    for row in result['indexed_callers']}
        observed = {(row['image'], int(row['site'], 16), 'call' if row['kind'] == 'jal' else 'jump')
                    for row in result['direct_transfer_candidates']}
        assert observed == expected, (result['address'], observed ^ expected)
    strings = {f'0x{address:08X}': elf.string(address)
               for address in (0x24FDE8, 0x24FED0, 0x24FEF0)}
    result = dict(schema=1, elf_sha256=elf.sha256, aligned_file_words_scanned=words_scanned,
                  original_instruction_comments_verified=verified_words,
                  raw_direct_transfers_equal_indexed_callers=True,
                  pointer_scope='All file-backed main PT_LOAD segments and nine hash-verified overlays; aligned words only.',
                  limitations='Raw hits include data/encoded bytes. Literal search also checks every byte offset and cached/uncached EE aliases. No computed pointers, relocated runtime tables, BSS, or execution evidence.',
                  boundary_11707c_context=elf.read(0x117074, 16).hex(), strings=strings,
                  entries=list(records.values()))
    out = ROOT / 'build-function-index/residual-leaf-role-review.json'
    out.write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
    print(f'Verified {len(records)} complete catalogue intervals, {verified_words} source-comment words; scanned {words_scanned:,} file words.')
    for entry in records.values():
        print(entry['address'], 'raw transfer candidates', len(entry['direct_transfer_candidates']),
              'raw pointer candidates', len(entry['pointer_candidates']),
              'unaligned/alias candidates', len(entry['unaligned_or_alias_pointer_candidates']),
              'indexed callers', len(entry['indexed_callers']))
    print('Owned strings:', strings)


if __name__ == '__main__':
    main()
