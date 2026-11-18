#!/usr/bin/env python3
"""Recover the 53 previously inventoried upper o4 spans as copied data only.

This produces evidence candidates, never runtime patches or function mappings.
Exception offsets and BOTH schedules come from owned bytes. No guest execution.
"""
from pathlib import Path
import hashlib
import json
import re
import struct

from recover_dnas_zero_upper import transform, schedule, BASE, SHA, FORWARD, INVERSE

ROOT = Path(__file__).resolve().parents[2]


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    original = image.read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA

    def read(address, count):
        offset = address - BASE
        assert 0 <= offset and offset + count*4 <= len(original)
        return struct.unpack_from('<'+'I'*count, original, offset)

    assert read(0x767A40, 8) == FORWARD and read(0x767A60, 8) == INVERSE
    metadata_count = read(0x744F28, 1)[0]
    assert metadata_count == 49
    metadata = {}
    for index in range(metadata_count):
        key, offset = read(0x744F2C+index*8, 2)
        record = 0x7450B4+offset
        relative_base, count = read(record, 2)
        exceptions = list(read(record+8, count))
        assert key >> 1 not in metadata
        metadata[key >> 1] = dict(index=index, record=hex(record), relative_base=relative_base,
                                  exception_offsets=exceptions)

    def lookup(packed):
        key = packed >> 1
        if not key:
            return dict(index=None, record=None, relative_base=0, exception_offsets=[])
        assert key in metadata
        return metadata[key]

    # Reuse the already audited boundary inventories, but re-read every value
    # and digest from the original image instead of trusting printed selectors.
    spans = []
    source = ROOT / 'docs/SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md'
    for line in source.read_text(encoding='utf-8').splitlines():
        match = re.search(r'\| `([0-9A-F]{6})\.\.([0-9A-F]{6})` \|', line)
        if match:
            digest = re.findall(r'`([0-9a-f]{64})`', line)
            assert len(digest) == 1
            spans.append((int(match[1], 16), int(match[2], 16), digest[0]))
    assert len(spans) == 49
    source = ROOT / 'docs/SYMBOLS_NETDNAS_RESIDUAL_BOUNDARIES.md'
    for line in source.read_text(encoding='utf-8').splitlines():
        match = re.match(r'\| `[0-9A-F]{6}` \| `[0-9A-F]{6}` \| `([0-9A-F]{6})\.\.([0-9A-F]{6})` \|', line)
        if match:
            digest = re.findall(r'`([0-9a-f]{64})`', line)
            assert len(digest) == 1
            spans.append((int(match[1], 16), int(match[2], 16), digest[0]))
    assert len(spans) == len({start for start, end, digest in spans}) == 53
    records = []
    for start, end, expected_sha in sorted(spans):
        assert start % 4 == end % 4 == 0 and start < end
        header = read(start-20, 5)
        restore = read(end+32, 4)
        assert header[0] == header[4] == 0 and header[2] & 1 == 0
        assert restore[1] & 1 == 1 and restore[3] == 0
        assert header[1] ^ header[3] == restore[0] ^ restore[2] == end-start
        entry_meta, restore_meta = lookup(header[2]), lookup(restore[1])
        assert entry_meta == restore_meta
        entry_slots, restore_slots = schedule(header[1]), schedule(restore[0])
        assert restore_slots == tuple(reversed(entry_slots))
        # Independently bind the clear restore setup to its owned end anchor,
        # descriptor pointer, mode, span operand, selector and dispatcher call.
        setup = read(end+48, 8)
        assert setup == (0x3C020000 | ((end+32+0x8000)>>16), 0x24420000 | ((end+32)&65535),
                         0x3C040000 | ((end+0x8000)>>16), 0x24840000 | (end&65535),
                         0x8C470004, 0x8C450008, 0x0C1D15F2, 0x8C460000), hex(start)
        words = list(read(start, (end-start)//4))
        pack = lambda values: struct.pack('<'+'I'*len(values), *values)
        assert hashlib.sha256(pack(words)).hexdigest() == expected_sha
        excluded = set(entry_meta['exception_offsets'])
        eligible = [entry_meta['relative_base']+4*i not in excluded for i in range(len(words))]
        candidate = list(words)
        for slot in entry_slots:
            candidate = [transform(w, slot, True) if eligible[i] else w for i, w in enumerate(candidate)]
        restored = list(candidate)
        for slot in restore_slots:
            restored = [transform(w, slot, False) if eligible[i] else w for i, w in enumerate(restored)]
        assert restored == words
        assert all(candidate[i] == w for i, w in enumerate(words) if not eligible[i])
        records.append(dict(start=hex(start), end_exclusive=hex(end), bytes=end-start,
                            header=[f'{w:08X}' for w in header], restore_header=[f'{w:08X}' for w in restore],
                            metadata=entry_meta, entry_slots=entry_slots, restore_slots=restore_slots,
                            original_sha256=expected_sha, candidate_sha256=hashlib.sha256(pack(candidate)).hexdigest(),
                            eligible_words=sum(eligible), preserved_exception_words=len(words)-sum(eligible),
                            candidate_words=[f'{w:08X}' for w in candidate], payload_roundtrip_exact=True,
                            restore_call=hex(end+72)))
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    receipt = dict(schema=1, image='o4', image_sha256=SHA, spans=records,
                   total_spans=len(records), total_words=sum(r['bytes']//4 for r in records),
                   preserved_exception_words=sum(r['preserved_exception_words'] for r in records),
                   no_guest_execution=True, owned_image_unchanged=True,
                   limitations='Reconstruction candidates only. Actual forward restores reproduce original payloads; '
                   'this does not independently recover function ownership, validate instruction semantics or admit '
                   'additional mapping credit. Entry paths, aliasing, runtime mutation/cache/thread behavior require '
                   'separate review. Existing generated-source graph is unchanged.')
    out = ROOT / 'build-function-index/dnas-upper-recovery-inventory.json'
    out.write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf-8')
    lines = ['# Upper DNAS copied-data recovery inventory', '',
             f'All **{len(records)} previously inventoried spans / {receipt["total_words"]:,} words** '
             'restore exactly using their actual opposite-mode metadata. '
             f'**{receipt["preserved_exception_words"]} exception words** remain unchanged. '
             '**This inventory adds zero function mappings.**', '',
             'Owned o4/runtime5/base6E0000, image SHA-256 `'+SHA+'`. '
             'Only Python integer values copied from this file were transformed. '
             'No recovered instructions were executed, loaded into the runtime or written to owned/generated inputs.', '',
             'The49 keyed records were read directly from the complete owned lookup table. '
             'Four zero-key spans use the original zero-exception route. For every span, the entry/restore '
             'metadata names the same range, relative base and exception offsets; the clear restore setup '
             'loads the exact end anchor, actual mode/operands and original dispatcher. All actual restore '
             'schedules reverse their entry schedules. Listed exceptions are preserved on every pass. '
             'The original encoded payload digest is checked against the earlier boundary inventory.', '',
             'Full connected-function review has already admitted '
             '[three bounded local operations](SYMBOLS_NETDNAS_THREE_ZERO_KEY_RECOVERED_LOCAL_ROLES.md) '
             'and [the two-bit query](SYMBOLS_NETDNAS_RECOVERED_TWO_BIT_FIELD_QUERY.md) '
             'as a fourth operation. Remaining candidates still require that same '
             'instruction, boundary, caller and data-flow review. A catalogue fragment inside recovered code '
             'does not become an independent function. Bytes in skipped metadata are not decoded here.', '',
             'Reproduce with `python tools/function_index/recover_dnas_upper_inventory.py`. '
             'The JSON receipt at `build-function-index/dnas-upper-recovery-inventory.json` retains '
             'all candidate words, exception offsets, selectors and hashes. The '
             '[original protection inventory](SYMBOLS_NETDNAS_PROTECTED_DISPATCH.md) and '
             '[residual boundaries](SYMBOLS_NETDNAS_RESIDUAL_BOUNDARIES.md) preserve the source provenance. '
             'Static graph edges from encoded/generated source remain unvalidated.', '',
             '| Span, end exclusive | Words | Preserved exceptions | Candidate SHA-256 |', '| --- | ---: | ---: | --- |']
    lines += [f'| {r["start"]}..{r["end_exclusive"]} | {r["bytes"]//4} | {r["preserved_exception_words"]} | `{r["candidate_sha256"]}` |' for r in records]
    (ROOT / 'docs/STATIC_DNAS_UPPER_RECOVERY_INVENTORY.md').write_text('\n'.join(lines)+'\n', encoding='utf-8')
    print(f'Restored {len(records)} spans/{receipt["total_words"]} copied words exactly; '
          f'{receipt["preserved_exception_words"]} exception words preserved; zero new mappings; no execution.')


if __name__ == '__main__':
    main()
