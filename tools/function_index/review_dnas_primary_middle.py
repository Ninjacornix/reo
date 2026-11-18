#!/usr/bin/env python3
"""Static copied-data/connected-owner receipt for primary DNAS middle owners.

Only arithmetic on new Python buffers and instruction-field inspection. Never
executes or emulates recovered instructions; owned/generated inputs are read-only.
"""
import hashlib
import json
from pathlib import Path
import struct

from recover_dnas_zero_upper import BASE, SHA, schedule, transform
from review_dnas_query_adapters import extra_fields

ROOT = Path(__file__).resolve().parents[2]
# Real owner bounds include jr ra and its stack-restoring delay word. Multiple
# payload islands are deliberately grouped under their single clear owner.
OWNERS = (
    (0x6E4148, 0x6E4310, (0x6E41C0,)),
    (0x6E4310, 0x6E4CF4, (0x6E43A0,)),
    (0x6E4CF8, 0x6E525C, (0x6E4D8C, 0x6E4E9C)),
    (0x6E5260, 0x6E5384, (0x6E52E8,)),
    (0x6E5FE8, 0x6E6260, (0x6E6088,)),
    (0x6E6260, 0x6E64E0, (0x6E62F0,)),
    (0x6E64E0, 0x6E6A40, (0x6E6578, 0x6E66AC, 0x6E682C)),
    (0x6E6A40, 0x6E6B30, (0x6E6AB0,)),
    (0x6E6B30, 0x6E6C8C, (0x6E6BB4,)),
    (0x6E6C90, 0x6E6D80, (0x6E6D00,)),
    (0x6E6FE8, 0x6E71B0, (0x6E709C,)),
    (0x6E71B0, 0x6E7388, (0x6E7268,)),
    (0x6E74D0, 0x6E7778, (0x6E75BC,)),
)
RESTORE_CALL = dict(zip(
    (0x6E41C0,0x6E43A0,0x6E4D8C,0x6E4E9C,0x6E52E8,0x6E6088,0x6E62F0,0x6E6578,
     0x6E66AC,0x6E682C,0x6E6AB0,0x6E6BB4,0x6E6D00,0x6E709C,0x6E7268,0x6E75BC),
    (0x6E42F0,0x6E4BD4,0x6E4E18,0x6E50B8,0x6E5360,0x6E6224,0x6E64AC,0x6E660C,
     0x6E6740,0x6E68CC,0x6E6B14,0x6E6C64,0x6E6D64,0x6E7138,0x6E72F4,0x6E7658)))


def main():
    path = ROOT/'build-function-index/owned-overlays/o4.bin'
    raw = path.read_bytes()
    assert hashlib.sha256(raw).hexdigest() == SHA
    inventory = json.loads((ROOT/'build-function-index/dnas-primary-recovery-inventory.json').read_text())
    assert inventory['image_sha256'] == SHA
    records = {int(r['start'],16):r for r in inventory['spans']}
    read = lambda a,n: struct.unpack_from('<'+'I'*n,raw,a-BASE)
    pack = lambda ws: struct.pack('<'+'I'*len(ws),*ws)
    assert read(0x70CB48,1) == (52,)
    metadata = {}
    for i in range(52):
        key, offset = read(0x70CB4C+8*i,2)
        relative, count = read(0x70CCEC+offset,2)
        metadata[key>>1] = (relative, set(read(0x70CCEC+offset+8,count)))
    output = ROOT/'build-function-index/dnas-primary-middle-review'
    output.mkdir(exist_ok=True)
    receipts, listings = [], []
    for owner, owner_end, starts in OWNERS:
        original_owner = raw[owner-BASE:owner_end-BASE]
        candidate = bytearray(original_owner)
        excluded, spans = set(), []
        for start in starts:
            r = records[start]
            end = int(r['end_exclusive'],16)
            header, restore = read(start-20,5), read(end+32,4)
            assert header[0] == header[4] == restore[3] == 0
            assert header[2]&1 == 0 and restore[1]&1 == 1
            assert header[2]>>1 == restore[1]>>1
            assert header[1]^header[3] == restore[0]^restore[2] == end-start
            entry_expected = (
                0x3C030000|((start-20+0x8000)>>16),0x24630000|((start-20)&65535),
                0x8C620000,0x14400007,0,
                0x3C040000|((start+0x8000)>>16),0x24840000|(start&65535),
                0x8C670008,0x8C65000C,0x0C000000|(0x70BA68>>2),0x8C660004,
                0x1000000C,0)
            assert read(start-96,13) == entry_expected
            relative, exceptions = metadata[header[2]>>1] if header[2]>>1 else (0,set())
            source = list(read(start,(end-start)//4))
            eligible = [relative+4*i not in exceptions for i in range(len(source))]
            words = list(source)
            for slot in schedule(header[1]):
                words = [transform(w,slot,True) if eligible[i] else w for i,w in enumerate(words)]
            assert [f'{w:08X}' for w in words] == r['candidate_words']
            assert hashlib.sha256(pack(source)).hexdigest() == r['original_sha256']
            assert hashlib.sha256(pack(words)).hexdigest() == r['candidate_sha256']
            restored = list(words)
            assert schedule(restore[0]) == tuple(reversed(schedule(header[1])))
            for slot in schedule(restore[0]):
                restored = [transform(w,slot,False) if eligible[i] else w for i,w in enumerate(restored)]
            assert restored == source
            candidate[start-owner:end-owner] = pack(words)
            excluded.update(range(start-44,start,4))
            excluded.update(range(end+8,end+48,4))
            setup, call = end+48, RESTORE_CALL[start]
            expected = (0x3C020000|((end+32+0x8000)>>16),0x24420000|((end+32)&65535),
                        0x3C040000|((end+0x8000)>>16),0x24840000|(end&65535))
            assert read(setup,4) == expected
            window = read(setup+16,(call+8-(setup+16))//4)
            assert read(call,1)[0] == 0x0C000000|(0x70BA68>>2)
            loads = [w for w in window if w in (0x8C450008,0x8C460000,0x8C470004)]
            assert sorted(loads) == sorted((0x8C450008,0x8C460000,0x8C470004))
            # Every other interleaved word is an explicitly reviewed independent
            # saved-register/float-constant setup; none writes a0..a3 or v0.
            for w in window:
                if w in loads or w == 0x0C000000|(0x70BA68>>2):
                    continue
                op,rs,rt,rd = w>>26,(w>>21)&31,(w>>16)&31,(w>>11)&31
                assert (op in (0xF,0xD) and rt not in (2,4,5,6,7)) or (op==0 and rd not in (2,4,5,6,7)) or (op==0x11 and rs==4), hex(w)
            spans.append(dict(start=hex(start),endExclusive=hex(end),candidateSha256=r['candidate_sha256'],
                              encodedSha256=r['original_sha256'],candidateWords=r['candidate_words'],
                              preservedExceptionWords=sum(not x for x in eligible),
                              entrySlots=schedule(header[1]),restoreSlots=schedule(restore[0]),
                              entryPackedMetadataKey=hex(header[2]),restorePackedMetadataKey=hex(restore[1]),
                              conditionalEntryCall=hex(start-60),entrySetup=hex(start-96),
                              restoreCall=hex(call),restoreSetup=hex(setup),restoreArgumentLoadOrder=[f'{w:08X}' for w in loads],
                              exactMetadataPairedByteRoundtrip=True))
        word = lambda a: struct.unpack_from('<I',candidate,a-owner)[0]
        # Reviewed literal islands use an unconditional forward branch, its NOP
        # delay word and two following padding NOPs before the skipped bytes.
        strings = []
        for pc in range(owner,owner_end,4):
            if pc in excluded:
                continue
            w = word(pc)
            if w>>16 == 0x1000 and w&65535 < 0x8000:
                target = pc+4+4*(w&65535)
                if target>pc+16 and target<owner_end and word(pc+4)==word(pc+8)==word(pc+12)==0:
                    data = bytes(candidate[pc+16-owner:target-owner])
                    if data.rstrip(b'\0') and all(c in (9,10,13) or 32<=c<127 for c in data.rstrip(b'\0')):
                        excluded.update(range(pc+8,target,4))
                        strings.append(dict(branch=hex(pc),address=hex(pc+16),endExclusive=hex(target),bytesHex=data.hex(),text=data.rstrip(b'\0').decode('ascii')))
        allowed = set(range(owner,owner_end,4))-excluded
        branches, unknown = [], []
        for pc in sorted(allowed):
            w = word(pc)
            decoded = extra_fields(pc,w)
            if 'UNDECODED' in decoded:
                unknown.append(hex(pc))
            op,rs = w>>26,(w>>21)&31
            if op in (1,4,5,6,7,20,21,22,23) or (op==17 and rs==8):
                imm=w&65535; imm=imm-65536 if imm&32768 else imm
                target=pc+4+4*imm
                assert target in allowed and pc+4 in allowed,(hex(owner),hex(pc),hex(target))
                branches.append(dict(pc=hex(pc),target=hex(target),delayWord=f'{word(pc+4):08X}'))
            if op==3:
                assert pc+4 in allowed
        assert not unknown, unknown
        assert word(owner_end-8)==0x03E00008 and word(owner_end-4)>>16==0x27BD
        listings.append(f'\nOWNER {owner:08X}..{owner_end:08X} (end exclusive)')
        for pc in range(owner,owner_end,4):
            w=word(pc)
            listings.append(f'{pc:08X}: {w:08X} '+('SKIPPED DATA / DESCRIPTOR' if pc in excluded else extra_fields(pc,w)))
        receipts.append(dict(owner=hex(owner),endExclusive=hex(owner_end),
                             originalOwnerSha256=hashlib.sha256(original_owner).hexdigest(),
                             candidateOwnerSha256=hashlib.sha256(candidate).hexdigest(),spans=spans,
                             skippedLiteralIslands=strings,directBranches=branches,
                             admittedInstructionWords=len(allowed),unrecognizedInstructionFields=unknown))
    assert hashlib.sha256(path.read_bytes()).hexdigest()==SHA
    receipt=dict(image='o4',imageSha256=SHA,owners=receipts,totalOwners=len(receipts),
                 totalSpans=sum(len(r['spans']) for r in receipts),
                 totalPayloadWords=sum(len(s['candidateWords']) for r in receipts for s in r['spans']),
                 totalPreservedExceptions=sum(s['preservedExceptionWords'] for r in receipts for s in r['spans']),
                 totalAdmittedInstructionWords=sum(r['admittedInstructionWords'] for r in receipts),
                 totalCheckedDirectBranches=sum(len(r['directBranches']) for r in receipts),
                 noGuestExecutionOrEmulation=True,ownedInputsUnchanged=True,
                 limitation='Static word/branch/restore-argument checking; semantics require the accompanying human full-body review. Early epilogue branches may skip a paired restore.')
    (output/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    (output/'words.txt').write_text('\n'.join(listings)+'\n',encoding='utf-8')
    print(f"{receipt['totalOwners']} owners / {receipt['totalSpans']} spans / {receipt['totalPayloadWords']} payload words; actual restore argument loads verified; no unknown admitted instruction fields; owned input unchanged.")


if __name__ == '__main__':
    main()
