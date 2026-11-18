#!/usr/bin/env python3
"""Hash-bound o5 copied-data recovery; never executes guest instructions.

Headers are discovered by exact metadata keys and bounded aligned lengths, then
bound to original clear entry calls. Metadata-paired restoration is arithmetic
evidence only. Noncanonical restore paths and logical ownership remain separate.
"""
import hashlib
import json
from pathlib import Path
import struct

from recover_dnas_zero_upper import transform, schedule

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x6E0000
SHA = '97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e'
FAMILIES = (
    (0x6E2828,0x7096A0,18,0x709D08,0x709D28),
    (0x700B18,0x700770,19,0x70B7B0,0x70B7D0),
    (0x708E18,0x708968,30,0x711240,0x711220),
)


def main():
    image = ROOT/'build-function-index/owned-overlays/o5.bin'
    original = image.read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA
    def read(a,n):
        assert BASE <= a <= a+4*n <= BASE+len(original)
        return struct.unpack_from('<'+'I'*n,original,a-BASE)
    pack = lambda w: struct.pack('<'+'I'*len(w),*w)
    jal = lambda a: 0x0C000000|(a>>2)
    lui = lambda reg,a: 0x3C000000|(reg<<16)|((a+0x8000)>>16)
    addiu = lambda reg,a: 0x24000000|(reg<<21)|(reg<<16)|(a&65535)
    families = []
    for dispatcher,table,count,forward,inverse in FAMILIES:
        assert read(table,1)[0] == count
        metadata = {}
        for i in range(count):
            key,offset = read(table+4+i*8,2)
            assert offset < 0x80000000
            record = table+4+8*count+offset
            relative,n = read(record,2)
            assert n < 0x10000
            assert key>>1 not in metadata
            metadata[key>>1] = dict(index=i,record_address=hex(record),
                relative_base=relative,exception_offsets=list(read(record+8,n)))
        families.append(dict(dispatcher=dispatcher,table=table,metadata=metadata,
            forward_table=forward,inverse_table=inverse))
    records = []
    for h in range(BASE,BASE+0x29CC0-20,4):
        header = read(h,5)
        size = header[1]^header[3]
        if header[0] or header[4] or not header[1] or header[2]&1 or not 4<=size<=0x10000 or size%4:
            continue
        possible = [f for f in families if not header[2] or header[2]>>1 in f['metadata']]
        if not possible:
            continue
        start,end = h+20,h+20+size
        if end+48 > BASE+len(original):
            continue
        # These are instruction-pattern comparisons, not target execution.
        bindings = []
        for f in possible:
            for call in range(max(BASE,start-160),start,4):
                if read(call,2) != (jal(f['dispatcher']),0x8C660004):
                    continue
                before = read(call-16,4)
                if before[:2] != (lui(4,start),addiu(4,start)):
                    continue
                if set(before[2:]) != {0x8C670008,0x8C65000C}:
                    continue
                # Header pointer setup and flag read/guard occur before args.
                prefixes = [(p,read(p,5)) for p in range(max(BASE,call-64),call-16,4)
                            if read(p,3)==(lui(3,h),addiu(3,h),0x8C620000)]
                assert len(prefixes)==1, (hex(start),hex(call))
                pointer_pc,prefix = prefixes[0]
                assert prefix[3]&0xFFFF0000 == 0x14400000 and prefix[4] == 0
                guard_target = pointer_pc+16+(prefix[3]&65535)*4
                assert guard_target in (call+8,call+12)
                branch = read(guard_target,1)[0]
                assert branch&0xFFFF0000 == 0x10000000
                assert guard_target+4+(branch&65535)*4 == start
                bindings.append((f,call))
        assert len(bindings) == 1, (hex(start),bindings)
        family,entry_call = bindings[0]
        meta = family['metadata'].get(header[2]>>1,dict(index=None,
            record_address=None,relative_base=0,exception_offsets=[]))
        restore = read(end+32,4)
        assert restore[1] == header[2]+1 and restore[3] == 0
        assert restore[0]^restore[2] == size
        entry_slots,restore_slots = schedule(header[1]),schedule(restore[0])
        assert restore_slots == tuple(reversed(entry_slots))
        words = list(read(start,size//4))
        exceptions = set(meta['exception_offsets'])
        eligible = [(meta['relative_base']+4*i)&0xFFFFFFFF not in exceptions for i in range(len(words))]
        candidate = list(words)
        for slot in entry_slots:
            candidate = [transform(w,slot,True) if eligible[i] else w for i,w in enumerate(candidate)]
        restored = list(candidate)
        for slot in restore_slots:
            restored = [transform(w,slot,False) if eligible[i] else w for i,w in enumerate(restored)]
        assert restored == words
        expected = (lui(2,end+32),addiu(2,end+32),lui(4,end),addiu(4,end),
                    0x8C470004,0x8C450008,jal(family['dispatcher']),0x8C460000)
        canonical = read(end+48,8) == expected
        records.append(dict(start=hex(start),end_exclusive=hex(end),bytes=size,
            dispatcher=hex(family['dispatcher']),entry_call=hex(entry_call),
            entry_clear_setup_verified=True,header=[f'{v:08X}' for v in header],
            restore_header_address=hex(end+32),restore_header=[f'{v:08X}' for v in restore],
            metadata=meta,entry_slots=entry_slots,restore_slots=restore_slots,
            original_sha256=hashlib.sha256(pack(words)).hexdigest(),
            candidate_sha256=hashlib.sha256(pack(candidate)).hexdigest(),
            candidate_words=[f'{w:08X}' for w in candidate],
            preserved_exception_words=len(words)-sum(eligible),
            metadata_paired_roundtrip_exact=True,
            canonical_clear_restore_setup_verified=canonical,
            canonical_restore_call=hex(end+72) if canonical else None,
            noncanonical_restore_binding='Pending connected path review' if not canonical else None))
    assert len(records) == 73
    for f in families:
        admitted = [r for r in records if int(r['dispatcher'],16)==f['dispatcher']]
        assert {int(r['header'][2],16)>>1 for r in admitted if int(r['header'][2],16)} == set(f['metadata'])
    assert hashlib.sha256(image.read_bytes()).hexdigest() == SHA
    receipt = dict(schema=1,image='o5',runtime_overlay_id=7,image_sha256=SHA,
        total_spans=len(records),total_words=sum(r['bytes']//4 for r in records),
        preserved_exception_words=sum(r['preserved_exception_words'] for r in records),
        clear_entry_bindings=len(records),
        canonical_clear_restore_bindings=sum(r['canonical_clear_restore_setup_verified'] for r in records),
        families=[dict(dispatcher=hex(f['dispatcher']),metadata_table=hex(f['table']),
            metadata_count=len(f['metadata']),forward_table=hex(f['forward_table']),
            inverse_table=hex(f['inverse_table']),metadata=f['metadata']) for f in families],
        spans=records,no_guest_execution=True,
        limitations='Arithmetic copied-data reconstruction only. Spans are not standalone functions. '
        'Noncanonical restore calls, complete connected owner paths and instruction semantics need individual review. '
        'No function mapping credit is assigned; no original or generated inputs are modified.')
    out = ROOT/'build-function-index/dnas-o5-family-recovery-inventory.json'
    out.write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    lines = ['# O5 DNAS copied-data recovery inventory','',
        f"**73 spans / {receipt['total_words']:,} words / {receipt['preserved_exception_words']} preserved exception words.** "
        f"All 73 clear entry setups bind their descriptor and start anchor; {receipt['canonical_clear_restore_bindings']} "
        'adjacent canonical clear restore setups bind the paired end anchor. Every metadata-paired schedule restores '
        'the exact original bytes. **This inventory admits zero function mappings.**','',
        'Owned o5 (`insdnas.bin`, runtime overlay 7), base `6E0000`, SHA-256 `'+SHA+'`. '
        'No target instructions, game, build, replay, network operation or process attachment ran. '
        'Original and generated inputs remain unchanged.','',
        'All 18/19/30 keyed records of the three tables are accounted for, plus six zero-key spans. '
        'The entry direction selects the inverse word table, while the paired restore selects the forward table. '
        'Selectors are read independently from both descriptors; exception membership uses '
        '`relative_base + 4 * word_index`, modulo 32 bits. Unsigned offset lists are not sorted or reinterpreted.','',
        'Reproduce with `python tools/function_index/recover_dnas_o5_family_inventory.py`. '
        'The private JSON receipt `build-function-index/dnas-o5-family-recovery-inventory.json` retains '
        'every original/candidate hash, candidate word, descriptor, schedule, key and exception list. '
        'Noncanonical restore bindings stay pending until complete connected paths are reviewed. '
        'Nested spans and generated catalogue cuts remain parts of their logical owners.','',
        '| Span, end exclusive | Dispatcher | Words | Exceptions | Canonical clear restore | Candidate SHA-256 |',
        '| --- | --- | ---: | ---: | --- | --- |']
    for r in records:
        lines.append(f"| `{int(r['start'],16):06X}..{int(r['end_exclusive'],16):06X}` | `{r['dispatcher']}` | "
            f"{r['bytes']//4} | {r['preserved_exception_words']} | "
            f"{'Verified' if r['canonical_clear_restore_setup_verified'] else 'Pending individual binding'} | `{r['candidate_sha256']}` |")
    (ROOT/'docs/STATIC_DNAS_O5_RECOVERY_INVENTORY.md').write_text('\n'.join(lines)+'\n',encoding='utf-8')
    print({k:receipt[k] for k in ('total_spans','total_words','preserved_exception_words','clear_entry_bindings','canonical_clear_restore_bindings')})


if __name__ == '__main__':
    main()
