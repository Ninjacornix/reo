"""Verify eleven reviewed DNAS owners as copied words, without guest execution."""
from pathlib import Path
import hashlib
import json
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x6E0000
SHA = '8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16'
OWNERS = [
    (0x7497A8,0x749830,0x749950), (0x749950,0x7499DC,0x749BC8),
    (0x749BC8,0x749C34,0x749CD8), (0x749CD8,0x749D60,0x749EE0),
    (0x74A380,0x74A424,0x74A8AC), (0x74A8B0,0x74A924,0x74AA04),
    (0x74CE60,0x74CEE8,0x74CF78), (0x74CF78,0x74D010,0x74D244),
    (0x74D248,0x74D2FC,0x74D75C), (0x74D760,0x74D7D8,0x74D8B0),
    (0x74D8B0,0x74D93C,0x74DB58),
]


def main():
    path = ROOT/'build-function-index/owned-overlays/o4.bin'
    original = path.read_bytes()
    assert hashlib.sha256(original).hexdigest() == SHA
    inventory = json.loads((ROOT/'build-function-index/dnas-upper-recovery-inventory.json').read_text())
    assert inventory['image_sha256'] == SHA
    receipts = []
    total_words = exceptions = branch_count = 0
    for owner, start, owner_end in OWNERS:
        record = next(r for r in inventory['spans'] if int(r['start'],16) == start)
        end = int(record['end_exclusive'],16)
        raw = original[owner-BASE:owner_end-BASE]
        words = [int(w,16) for w in record['candidate_words']]
        payload = struct.pack('<'+'I'*len(words), *words)
        assert hashlib.sha256(payload).hexdigest() == record['candidate_sha256']
        candidate = bytearray(raw)
        candidate[start-owner:end-owner] = payload
        struct.pack_into('<I', candidate, start-owner-20, start-20)

        def word(pc):
            return struct.unpack_from('<I',candidate,pc-owner)[0]

        # These sets classify words statically, not by executing a path.
        allowed = set(range(owner,start-44,4)) | set(range(start,end+8,4)) | set(range(end+48,owner_end,4))
        if start in (0x749C34,0x74A924):
            # Their unconditional entry branches skip embedded driver-name bytes.
            allowed -= set(range(start+8,start+36,4))
        branches = []
        for pc in sorted(allowed):
            value = word(pc)
            opcode, rs = value>>26, (value>>21)&31
            if opcode in (1,4,5,6,7,20,21,22,23) or (opcode == 17 and rs == 8):
                immediate = value&65535
                immediate = immediate if immediate < 32768 else immediate-65536
                target = pc+4+4*immediate
                assert target in allowed, (hex(owner),hex(pc),hex(target))
                assert pc+4 in allowed, (hex(pc),'missing delay-slot word')
                branches.append({'pc':hex(pc),'word':f'{value:08X}','target':hex(target),
                                 'delayWord':f'{word(pc+4):08X}'})
            if opcode == 3:
                assert pc+4 in allowed, (hex(pc),'missing call delay slot')
        assert word(owner_end-8) == 0x03E00008
        assert word(owner_end-4)>>16 == 0x27BD
        offsets = set(record['metadata']['exception_offsets'])
        preserved = 0
        for index in range(len(words)):
            if record['metadata']['relative_base']+4*index in offsets:
                assert payload[4*index:4*index+4] == original[start-BASE+4*index:start-BASE+4*index+4]
                preserved += 1
        assert preserved == record['preserved_exception_words']
        total_words += len(words)
        exceptions += preserved
        branch_count += len(branches)
        receipts.append({'owner':hex(owner),'ownerEndExclusive':hex(owner_end),'ownerBytes':len(raw),
                         'originalOwnerSha256':hashlib.sha256(raw).hexdigest(),
                         'candidateOwnerSha256':hashlib.sha256(candidate).hexdigest(),
                         'payload':record['start'],'payloadEndExclusive':record['end_exclusive'],
                         'candidatePayloadSha256':record['candidate_sha256'],
                         'payloadWords':len(words),'unchangedExceptionWords':preserved,
                         'branchTargetsChecked':branches,'returnDelayWord':f'{word(owner_end-4):08X}',
                         'allDirectBranchesLandInReviewedInstructionRegions':True})
    receipt = {'image':'o4','imageSha256':SHA,
               'kind':'Full connected static owner review, not guest instruction execution',
               'owners':receipts,'totalOwners':len(receipts),'recoveredPayloadWords':total_words,
               'preservedExceptionWords':exceptions,'directBranchTargetsChecked':branch_count,
               'limitations':'This checks owned/candidate identities, exceptions and branch targets. '
                             'The separate human full-body review establishes semantic roles. '
                             'It does not execute instructions or validate arbitrary runtime inputs.'}
    assert hashlib.sha256(path.read_bytes()).hexdigest() == SHA
    (ROOT/'build-function-index/dnas-middle-owner-review.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(f'{len(receipts)} owners, {total_words} reconstructed words, {exceptions} preserved exceptions, '
          f'{branch_count} checked branch targets; owned input unchanged; no execution.')


if __name__ == '__main__':
    main()
