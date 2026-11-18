#!/usr/bin/env python3
"""Classify tiny owned guest bodies, without guessing original API names.

Reads an existing offline index and verified file-backed images only. Does not
execute generated code, inspect a process, or mutate reviewed annotations.
"""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import sqlite3
import struct

from index import Elf, ELF_SHA, ROOT


def classify_words(words):
    """Accept only a complete JR ra / proven harmless delay-slot body + zeros."""
    if not 2 <= len(words) <= 8 or words[0] != 0x03E00008:
        return None
    if any(words[2:]):
        return None
    delay = words[1]
    if delay == 0:
        return dict(kind='no_op', behavior='Returns without modifying guest registers or memory.')
    if delay in (0x0000102D, 0x00001021, 0x00001025):
        return dict(kind='return_zero', value=0,
                    behavior='Returns integer zero in v0; no memory access.')
    if delay >> 16 == 0x2402:
        value = delay & 0xFFFF
        if value & 0x8000:
            value -= 0x10000
        return dict(kind='return_constant', value=value,
                    behavior=f'Returns sign-extended constant {value} in v0; no memory access.')
    return None


def classify_accessor_words(words):
    """A single memory instruction, JR ra, and NOPs; no structure-name inference."""
    if not 2 <= len(words) <= 8:
        return None
    if words[0] == 0x03E00008 and not any(words[2:]):
        instruction = words[1]
    elif len(words) >= 3 and words[1] == 0x03E00008 and not any(words[2:]):
        instruction = words[0]
    else:
        return None
    op, base, register = instruction >> 26, (instruction >> 21) & 31, (instruction >> 16) & 31
    if base != 4:  # a0 only: stack/global/MMIO identity is not inferred.
        return None
    offset = instruction & 0xFFFF
    if offset & 0x8000:
        offset -= 0x10000
    address = f'a0{offset:+d}'
    reads = {0x20: ('signed', 8), 0x24: ('unsigned', 8),
             0x21: ('signed', 16), 0x25: ('unsigned', 16),
             0x23: ('signed', 32), 0x27: ('unsigned', 32), 0x37: ('raw', 64)}
    if op in reads and register == 2:
        extension, width = reads[op]
        return dict(kind='read_a0_field', offset=offset, width=width, extension=extension,
                    behavior=f'Reads {extension} {width}-bit guest memory at {address} into v0.')
    stores = {0x28: 8, 0x29: 16, 0x2B: 32, 0x3F: 64}
    if op in stores and register in (0, 5):
        source = 'zero' if register == 0 else 'a1'
        return dict(kind='write_a0_field', offset=offset, width=stores[op], register=source,
                    behavior=f'Stores low {stores[op]} bits of {source} to guest memory at {address}; preserves v0.')
    if op == 0x31 and register == 0:
        return dict(kind='read_a0_float_field', offset=offset, width=32,
                    behavior=f'Loads guest memory at {address} into f0 as 32 raw floating-point bits.')
    if op == 0x39 and register == 12:
        return dict(kind='write_a0_float_field', offset=offset, width=32,
                    behavior=f'Stores f12 raw 32-bit floating-point bits to guest memory at {address}; preserves v0.')
    return None


def classify_tail_words(address, words):
    """A direct J plus a known delay operation; no callee semantics inferred."""
    if not 2 <= len(words) <= 8 or words[0] >> 26 != 2 or any(words[2:]):
        return None
    target = (((address + 4) & 0xF0000000) | ((words[0] & 0x3FFFFFF) << 2))
    if address <= target < address + len(words)*4:
        return None  # A local loop/continuation is not a whole-body tail adapter.
    delay = words[1]
    if delay == 0:
        detail = 'Preserves argument registers before transfer.'
        adjustment = None
    elif delay >> 16 == 0x2485:  # ADDIU a1,a0,signed16; no memory access.
        adjustment = delay & 0xFFFF
        if adjustment & 0x8000:
            adjustment -= 0x10000
        detail = f'Sets a1 to sign-extended 32-bit (a0{adjustment:+d}) in the delay slot.'
    else:
        return None
    return dict(kind='direct_tail_adapter', target=f'0x{target:08X}',
                argument_adjustment=adjustment,
                behavior=f'Jumps to guest 0x{target:08X} without linking ra. {detail} '
                         'Callee effects and return value are not inferred.')


def collect(connection, read_image):
    records = []
    for f in connection.execute('SELECT * FROM functions ORDER BY image,start'):
        size = f['end'] - f['start']
        if f['proposed_name'] or not f['source'] or not 8 <= size <= 32:
            continue
        if f['start'] % 4 or f['end'] % 4:
            continue
        data = read_image(f['image'], f['start'], size)
        if data is None or len(data) != size:
            continue
        words = struct.unpack('<' + 'I' * (size // 4), data)
        finding = classify_words(words) or classify_accessor_words(words)
        # Keep protected/data-carrier images out of new tail admission. A valid
        # jump-shaped word inside encoded bytes is not a recovered code entry.
        if finding is None and f['image'] not in ('o4', 'o5'):
            tail = classify_tail_words(f['start'], words)
            if tail is not None:
                target = int(tail['target'], 16)
                resolved = connection.execute(
                    "SELECT id FROM functions WHERE image=? AND start=? AND proposed_name!=''",
                    (f['image'], target)).fetchall()
                if len(resolved) == 1:
                    finding = dict(**tail, reviewed_target=resolved[0]['id'])
        if finding:
            records.append(dict(id=f['id'], image=f['image'], address=f'0x{f["start"]:08X}',
                                end=f'0x{f["end"]:08X}', source=f['source'],
                                words=[f'{w:08X}' for w in words], **finding))
    return records


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--db', type=Path, default=ROOT / 'build-function-index/index.sqlite')
    parser.add_argument('--elf', type=Path, default=ROOT / 'game_data/SLUS_207.65')
    parser.add_argument('--overlay-dir', type=Path, default=ROOT / 'build-function-index/owned-overlays')
    parser.add_argument('--out', type=Path, default=Path(__file__).with_name('leaf_classifications.json'))
    parser.add_argument('--markdown', type=Path, default=ROOT / 'docs/FUNCTION_LEAF_CLASSIFICATIONS.md')
    args = parser.parse_args()
    elf = Elf(args.elf)
    profile = json.loads(Path(__file__).with_name('overlay_identities.json').read_text(encoding='utf-8'))
    if profile['elf_sha256'] != ELF_SHA:
        raise ValueError('Profile/main image identity mismatch')
    images = {}
    for item in profile['images']:
        data = (args.overlay_dir / (item['image'] + '.bin')).read_bytes()
        if hashlib.sha256(data).hexdigest() != item['imageSha256']:
            raise ValueError(f'Overlay identity mismatch: {item["image"]}')
        if data[:4] != b'MWo3' or struct.unpack_from('<II', data, 4) != (item['id'], item['base']):
            raise ValueError(f'Overlay header mismatch: {item["image"]}')
        images[item['image']] = (item['base'], data)

    def read_image(image, address, size):
        if image == 'main':
            try:
                return elf.read(address, size)
            except ValueError:
                return None
        if image not in images:
            return None
        base, data = images[image]
        offset = address - base
        return data[offset:offset + size] if 0 <= offset <= len(data) - size else None

    # SQLite read-only URI also prevents accidentally creating a missing index.
    with sqlite3.connect(args.db.resolve().as_uri() + '?mode=ro', uri=True) as connection:
        connection.row_factory = sqlite3.Row
        records = collect(connection, read_image)
    result = dict(schema=1, edition='SLUS-20765', elf_sha256=ELF_SHA,
                  confidence='Confirmed/static narrow whole-body behavior, not original semantic identity.',
                  provenance='Owned raw words; admitted JR ra/delay/zero padding, single a0-relative memory instruction, or bounded direct tail to a reviewed same-image entry.',
                  overlay_profile='tools/function_index/overlay_identities.json', entries=records)
    lines = ['# Mechanically classified guest leaves', '',
             'These exact whole-body classifications are separate from reviewed semantic names.',
             'They establish only the stated register/memory behavior. Original API purpose,',
             'return type and caller expectations remain unknown. Field accesses retain guest',
             'memory exceptions/alias/MMIO behavior; no pure-getter, null-safety or host-memory',
             'replacement contract is inferred. A no-op preserves v0; it',
             'does **not** return zero. No gameplay, build, replay or live process was used.', '',
             f'Current snapshot: **{len(records)}** previously unnamed entries.', '',
             'Only aligned catalogue intervals of 8..32 bytes are admitted. Every original',
             'word is read from the identity-checked main ELF or overlay. Accepted bodies are',
             'JR ra with one admitted delay instruction, or one admitted a0-relative memory',
             'instruction followed by JR ra/NOP. Direct J tails are also admitted only',
             'outside protected o4/o5, to one reviewed same-image catalogue entry, with',
             'NOP or ADDIU a1,a0,signed16 delay. Local loops, JAL, other delay effects',
             'and callee behavior are excluded. All trailing words must be zero. Padding',
             'is included in the recorded fingerprint.',
             'Unaligned/byte-sized catalogue artifacts are excluded. No reviewed name is replaced.', '',
             'Regenerate after refreshing the index:', '', '```powershell',
             'python tools/function_index/classify_leaves.py', '```', '',
             '| Image / original entry | Complete observed behavior | Source |',
             '| --- | --- | --- |']
    for entry in records:
        lines.append(f'| {entry["image"]} {entry["address"]} | {entry["behavior"]} | '
                     f'[generated body](../{entry["source"]}) |')
    args.out.write_text(json.dumps(result, indent=2) + '\n', encoding='utf-8')
    args.markdown.write_text('\n'.join(lines) + '\n', encoding='utf-8')
    print(f'Classified {len(records)} exact guest leaves; reviewed annotations unchanged.')


if __name__ == '__main__':
    main()
