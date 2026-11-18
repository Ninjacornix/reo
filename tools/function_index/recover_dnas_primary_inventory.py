#!/usr/bin/env python3
"""Reconstruct 63 primary o4 spans as data; defer noncanonical call binding.

Metadata-paired byte restores do not constitute function ownership or execution.
Owned bytes and generated/runtime code are never modified.
"""
import hashlib
import json
from pathlib import Path
import re
import struct

from recover_dnas_zero_upper import BASE, SHA, transform, schedule

ROOT = Path(__file__).resolve().parents[2]


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    original = image.read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA

    def read(address, count):
        offset = address-BASE
        assert 0 <= offset and offset+4*count <= len(original)
        return struct.unpack_from('<'+'I'*count, original, offset)

    assert read(0x764A78, 8) == (0x70BD78,0x70BE18,0x70BEB8,0x70BF68,0x70C018,0x70C0F0,0x70C1B0,0x70C2B0)
    assert read(0x764A98, 8) == (0x70C4A0,0x70C540,0x70C5E0,0x70C6A0,0x70C760,0x70C838,0x70C910,0x70CA20)
    assert read(0x70CB48, 1)[0] == 52
    metadata = {}
    for index in range(52):
        packed, offset = read(0x70CB4C+8*index, 2)
        address = 0x70CCEC+offset
        relative, count = read(address, 2)
        exceptions = list(read(address+8, count))
        assert packed >> 1 not in metadata
        metadata[packed >> 1] = dict(index=index, address=hex(address), relative_base=relative,
                                      exception_offsets=exceptions)

    def lookup(packed):
        if packed >> 1 == 0:
            return dict(index=None, address=None, relative_base=0, exception_offsets=[])
        assert packed >> 1 in metadata
        return metadata[packed >> 1]

    inventory = ROOT / 'docs/SYMBOLS_NETDNAS_PRIMARY_PROTECTED_DISPATCH.md'
    spans = []
    for line in inventory.read_text(encoding='utf-8').splitlines():
        match = re.search(r'\| `([0-9A-F]{6})\.\.([0-9A-F]{6})` \|', line)
        if match:
            digests = re.findall(r'`([0-9a-f]{64})`', line)
            assert len(digests) == 1
            spans.append((int(match[1],16), int(match[2],16), digests[0]))
    assert len(spans) == len({a for a,z,h in spans}) == 63
    records = []
    for start, end, source_sha in spans:
        assert start < end and start % 4 == end % 4 == 0
        header, restore = read(start-20,5), read(end+32,4)
        assert header[0] == header[4] == 0 and header[2] & 1 == 0
        assert restore[1] & 1 == 1 and restore[3] == 0
        assert header[1]^header[3] == restore[0]^restore[2] == end-start
        meta = lookup(header[2])
        assert meta == lookup(restore[1])
        entry_slots, restore_slots = schedule(header[1]), schedule(restore[0])
        assert restore_slots == tuple(reversed(entry_slots))
        words = list(read(start,(end-start)//4))
        pack = lambda values: struct.pack('<'+'I'*len(values),*values)
        assert hashlib.sha256(pack(words)).hexdigest() == source_sha
        exceptions = set(meta['exception_offsets'])
        eligible = [meta['relative_base']+4*i not in exceptions for i in range(len(words))]
        candidate = list(words)
        for slot in entry_slots:
            candidate = [transform(w,slot,True) if eligible[i] else w for i,w in enumerate(candidate)]
        restored = list(candidate)
        for slot in restore_slots:
            restored = [transform(w,slot,False) if eligible[i] else w for i,w in enumerate(restored)]
        assert restored == words
        assert all(candidate[i] == w for i,w in enumerate(words) if not eligible[i])
        expected = (0x3C020000 | ((end+32+0x8000)>>16), 0x24420000 | ((end+32)&65535),
                    0x3C040000 | ((end+0x8000)>>16), 0x24840000 | (end&65535),
                    0x8C470004, 0x8C450008, 0x0C000000 | (0x70BA68>>2), 0x8C460000)
        canonical = read(end+48,8) == expected
        records.append(dict(start=hex(start),end_exclusive=hex(end),bytes=end-start,
                            header=[f'{w:08X}' for w in header],restore_header=[f'{w:08X}' for w in restore],
                            metadata=meta,entry_slots=entry_slots,restore_slots=restore_slots,
                            original_sha256=source_sha,candidate_sha256=hashlib.sha256(pack(candidate)).hexdigest(),
                            candidate_words=[f'{w:08X}' for w in candidate],
                            preserved_exception_words=len(words)-sum(eligible),metadata_paired_roundtrip_exact=True,
                            canonical_clear_restore_setup_verified=canonical,
                            noncanonical_restore_call_binding='not established by this arithmetic inventory' if not canonical else None))
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    bound = sum(r['canonical_clear_restore_setup_verified'] for r in records)
    total_words = sum(r['bytes']//4 for r in records)
    receipt = dict(schema=1,image='o4',image_sha256=SHA,total_spans=len(records),total_words=total_words,
                   canonical_clear_restore_setups=bound,spans=records,no_guest_execution=True,
                   limitations='Metadata-paired data reconstruction only. Noncanonical clear restore call binding, '
                   'whole-function ownership and instruction semantics require separate review. A paired arithmetic '
                   'round trip is not evidence that every runtime path restores code. No mapping credit assigned.')
    out = ROOT / 'build-function-index/dnas-primary-recovery-inventory.json'
    out.write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    lines = ['# Primary DNAS copied-data recovery candidates','',
             f'**{len(records)} spans / {total_words:,} words** were reconstructed from the owned file as data. '
             'Applying each paired metadata schedule restores its exact original encoded payload. '
             f'**{bound}** canonical clear restore setups also match the exact end-anchor/metadata/call sequence. '
             f'The remaining **{len(records)-bound} call bindings** need individual clear-path review. '
             '**Zero new function mappings are admitted by this inventory.**','',
             'Owned o4/runtime5/base6E0000, SHA-256 `'+SHA+'`. All52 keyed metadata records, '
             'zero-key behavior, actual selector orders, range lengths and exception offsets were read from '
             'owned bytes. No recovered instructions, game, runtime, network, cache operation or target process '
             'was executed. Owned and generated inputs are unchanged.','',
             'This extends [the primary boundary inventory](SYMBOLS_NETDNAS_PRIMARY_PROTECTED_DISPATCH.md). '
             'It does not establish standalone ownership for every span, validate generated edges through '
             'encoded/skipped bytes, or imply every runtime exit follows the paired restore. '
             'The [upper-family recovery](STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md) demonstrates how '
             'individual connected function reviews must follow copied-data recovery.','',
             'Reproduce with `python tools/function_index/recover_dnas_primary_inventory.py`. '
             'All candidate words, exact schedules, exceptions and hashes are retained in '
             '`build-function-index/dnas-primary-recovery-inventory.json`.','',
             '| Span, end exclusive | Words | Preserved exceptions | Canonical restore setup | Candidate SHA-256 |',
             '| --- | ---: | ---: | --- | --- |']
    lines += [f'| {r["start"]}..{r["end_exclusive"]} | {r["bytes"]//4} | {r["preserved_exception_words"]} | '
              f'{"Verified" if r["canonical_clear_restore_setup_verified"] else "Needs individual binding"} | `{r["candidate_sha256"]}` |' for r in records]
    (ROOT/'docs/STATIC_DNAS_PRIMARY_RECOVERY_INVENTORY.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print(f'Primary candidates: {len(records)} spans/{total_words} words; exact metadata-paired restores; '
          f'{bound} canonical clear restore bindings; zero new mappings; no execution.')


if __name__ == '__main__':
    main()
