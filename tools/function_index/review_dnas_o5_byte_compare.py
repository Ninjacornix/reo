"""Save owned/candidate full-owner evidence, without executing guest instructions."""
from pathlib import Path
import argparse
import hashlib
import json
import os
import struct
import recover_dnas_o5_byte_compare as rt

root = rt.ROOT / 'build-function-index/dnas-offline-o5-702f74'
parser = argparse.ArgumentParser(description=__doc__)
parser.add_argument('--artifacts', type=Path, default=root/'artifacts')
parser.add_argument('--output', type=Path, default=root/'owner-evidence')
args = parser.parse_args()
original_image = rt.IMAGE.read_bytes()
assert rt.sha(original_image) == rt.IMAGE_HASH
start, end = 0x702EF0, 0x703028
owned = original_image[start-rt.BASE:end-rt.BASE]
assert len(owned) == 312
proof = json.loads((args.artifacts/'proof.json').read_text())
candidate_payload = (args.artifacts/'candidate.bin').read_bytes()
assert rt.sha(candidate_payload) == proof['artifactHashes']['candidate.bin']
candidate = bytearray(owned)
candidate[rt.START-start:rt.END-start] = candidate_payload
struct.pack_into('<I', candidate, rt.HEADER-start, rt.HEADER)
restored = bytearray(candidate)
struct.pack_into('<I', restored, rt.HEADER-start, 0)
rt.apply_words(restored, start, rt.START, rt.END, [5, 2, 1], rt.original_forward_word)
assert bytes(restored) == owned

regions = [
    (start, 0x702F48, 'clear entry and branch delay slots'),
    (0x702F48, 0x702F60, 'skipped bytes before decode descriptor'),
    (0x702F60, 0x702F74, 'decode descriptor data'),
    (0x702F74, 0x702FB8, 'reconstructed candidate comparison instructions'),
    (0x702FB8, 0x702FC0, 'clear branch and delay slot'),
    (0x702FC0, 0x702FD8, 'skipped bytes before restore metadata'),
    (0x702FD8, 0x702FE8, 'restore metadata and unused zero word'),
    (0x702FE8, end, 'clear restore setup call and epilogue'),
]
assert regions[0][0] == start and regions[-1][1] == end
assert all(a[1] == b[0] for a, b in zip(regions, regions[1:]))

# Word-based static target check, never branch execution. These are all direct
# comparison branches plus their required delay-slot words in the candidate.
branch_expectations = {
    0x702F74: (0x1220000F, 0x702FB4, 0x0000282D),
    0x702F9C: (0x14400006, 0x702FB8, 0x2410FFFF),
    0x702FA4: (0x14800004, 0x702FB8, 0x24100001),
    0x702FAC: (0x14C0FFF4, 0x702F80, 0x02651821),
}
for pc, (word, target, delay) in branch_expectations.items():
    assert rt.u32(candidate, pc-start) == word
    imm = word & 65535
    imm = imm if imm < 32768 else imm-65536
    assert pc+4+imm*4 == target
    assert rt.u32(candidate, pc-start+4) == delay
assert rt.u32(candidate, 0x702FB4-start) == 0x0000802D
assert rt.u32(candidate, 0x703008-start) == 0x0200102D
assert rt.u32(candidate, 0x703020-start) == 0x03E00008
assert rt.u32(candidate, 0x703024-start) == 0x27BD0030

out = args.output.resolve()
out.mkdir(exist_ok=False)
files = {'owner-original.bin': owned, 'owner-candidate.bin': bytes(candidate), 'owner-restored.bin': bytes(restored)}
for name, raw in files.items():
    with (out/name).open('xb') as f:
        f.write(raw)
lines = ['address\townedWord\tcandidateWord\tregion']
for lo, hi, label in regions:
    for pc in range(lo, hi, 4):
        lines.append(f'{pc:08X}\t{rt.u32(owned, pc-start):08X}\t{rt.u32(candidate, pc-start):08X}\t{label}')
(out/'all-owner-words.tsv').write_text('\n'.join(lines)+'\n', encoding='utf-8')
result = {'ownerStart': hex(start), 'ownerEndExclusive': hex(end), 'bytes': len(owned), 'words': len(owned)//4,
          'roundtripEqual': bytes(restored) == owned,
          'payloadProof': os.path.relpath(args.artifacts.resolve()/'proof.json', out),
          'hashes': {name: rt.sha(raw) for name, raw in files.items()},
          'regions': [{'start': hex(a), 'endExclusive': hex(b), 'classification': label} for a, b, label in regions],
          'comparisonBranches': [{'pc': hex(pc), 'candidateWord': hex(word), 'target': hex(target), 'delaySlotWord': hex(delay)}
                                 for pc, (word, target, delay) in branch_expectations.items()],
          'semanticReview': 'Static full-owner and branch-delay-slot review only; guest instructions never executed.'}
(out/'owner-proof.json').write_text(json.dumps(result, indent=2)+'\n', encoding='utf-8')
assert rt.sha(rt.IMAGE.read_bytes()) == rt.IMAGE_HASH
print(json.dumps(result, indent=2))
