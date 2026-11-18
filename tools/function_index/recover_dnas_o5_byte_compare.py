"""One bounded owned DNAS byte transform. Never executes recovered instructions."""
from pathlib import Path
import argparse
import hashlib
import json
import re
import sqlite3
import struct

ROOT = Path(__file__).resolve().parents[2]
IMAGE = ROOT / 'build-function-index/owned-overlays/o5.bin'
IMAGE_HASH = '97174f5d367cd90bedd5ba397c6492e9fb4bbd0ec7d6021c2be524c49925d38e'
BASE = 0x6E0000
MASK = 0xFFFFFFFF
XOR_A = 0x09F8ED17
XOR_B = 0xA95128C3
HEADER = 0x702F60
START = 0x702F74
END = 0x702FB8
RESTORE_META = 0x702FD8


def sha(raw):
    return hashlib.sha256(raw).hexdigest()


def u32(raw, offset=0):
    return struct.unpack_from('<I', raw, offset)[0]


def normalize(selector):
    # 700CE8: low three bits of the count nibble, with zero replaced by five;
    # each of seven lower selector nibbles is independently masked to 0..7.
    count = (selector >> 28) & 7
    count = count or 5
    low = sum(((selector >> (4*i)) & 7) << (4*i) for i in range(7))
    return ((count << 28) | low) & MASK


def schedule(selector):
    n = normalize(selector)
    return n, [(n >> (4*i)) & 15 for i in range(n >> 28)]


def rotate_right(word, bits):
    return ((word >> bits) | (word << (32-bits))) & MASK


def inverse_word(word, index):
    # Independently reviewed 7015F0,701690,7018E8, not a generic interpreter.
    if index == 1:
        return (word ^ XOR_B) & MASK
    if index == 2:
        return rotate_right(word, 13)
    if index == 5:
        return rotate_right(word ^ XOR_A, 13)
    raise ValueError('Unreviewed inverse primitive')


def original_forward_word(word, index):
    # Match the separate original forward primitives' shifts/mask/order.
    # Do not implement restore merely as Python's inverse of inverse_word.
    if index == 1:  # 700EC8
        return (word ^ XOR_B) & MASK
    rotated = (((word << 13) & MASK) & 0xFFFFE000) | (word >> 19)
    if index == 2:  # 700F68
        return rotated
    if index == 5:  # 7011A0
        return rotated ^ XOR_A
    raise ValueError('Unreviewed forward primitive')


def apply_words(frame, window_base, start, end, indices, function):
    assert start % 4 == end % 4 == 0 and start <= end
    assert window_base <= start and end <= window_base + len(frame)
    for index in indices:
        for pc in range(start, end, 4):
            offset = pc-window_base
            struct.pack_into('<I', frame, offset, function(u32(frame, offset), index))


def main():
    ap = argparse.ArgumentParser(description=__doc__)
    ap.add_argument('--output', type=Path, default=ROOT / 'build-function-index/dnas-offline-o5-702f74/artifacts')
    args = ap.parse_args()
    original = IMAGE.read_bytes()
    assert sha(original) == IMAGE_HASH

    def read(address, length):
        offset = address-BASE
        assert 0 <= offset <= len(original) and 0 <= length <= len(original)-offset
        return original[offset:offset+length]

    flag, selector, packed, operand, reserved = struct.unpack('<5I', read(HEADER, 20))
    restore_selector, restore_packed, restore_operand = struct.unpack('<3I', read(RESTORE_META, 12))
    assert (flag, selector, packed, operand, reserved) == (0, 0x3CAE8DA9, 0, 0x3CAE8DED, 0)
    assert (restore_selector, restore_packed, restore_operand) == (0x3CAE89AD, 1, 0x3CAE89E9)
    assert packed >> 1 == restore_packed >> 1 == 0
    assert packed & 1 == 0 and restore_packed & 1 == 1
    assert selector ^ operand == restore_selector ^ restore_operand == END-START == 0x44
    inv_normalized, inv_indices = schedule(selector)
    fwd_normalized, fwd_indices = schedule(restore_selector)
    assert inv_indices == [1, 2, 5] and fwd_indices == [5, 2, 1]
    forward_table = struct.unpack('<8I', read(0x70B7B0, 32))
    inverse_table = struct.unpack('<8I', read(0x70B7D0, 32))
    assert [inverse_table[i] for i in inv_indices] == [0x7015F0, 0x701690, 0x7018E8]
    assert [forward_table[i] for i in fwd_indices] == [0x7011A0, 0x700F68, 0x700EC8]

    # Verify the clear post-payload restore call's address/loads, including delay slot.
    restore_call_words = struct.unpack('<8I', read(0x702FE8, 32))
    assert restore_call_words == (0x3C020070, 0x24422FD8, 0x3C040070, 0x24842FB8,
                                  0x8C470004, 0x8C450008, 0x0C1C02C6, 0x8C460000)
    assert u32(read(0x702F38, 4)) == 0x0C1C02C6
    assert u32(read(0x702FB8, 4)) == 0x1000000B  # branch to clear restore setup

    # A fresh private copied bytearray, with 16 guard bytes on either side.
    window_base, window_end = HEADER-16, END+16
    initial_frame = read(window_base, window_end-window_base)
    candidate_frame = bytearray(initial_frame)
    # Actual700B18 direction0 marks header selfpointer before inverse passes.
    struct.pack_into('<I', candidate_frame, HEADER-window_base, HEADER)
    apply_words(candidate_frame, window_base, START, END, inv_indices, inverse_word)
    payload_slice = slice(START-window_base, END-window_base)
    encoded = initial_frame[payload_slice]
    candidate = bytes(candidate_frame[payload_slice])
    assert sha(encoded) == 'b70c789cbc9d6787941e81fd57f197608880aa6016e8c1110250ea7d17da33de'
    assert sha(candidate) == 'e507066b82b2fdcae2e125652cd50fee53febe455dcd130cdb380c25b1544da9'

    restored_frame = bytearray(candidate_frame)
    # Actual700B18 direction1 clears the original header at(end-span)-14hex.
    struct.pack_into('<I', restored_frame, END-(restore_selector ^ restore_operand)-0x14-window_base, 0)
    apply_words(restored_frame, window_base, END-(restore_selector ^ restore_operand), END,
                fwd_indices, original_forward_word)
    restored = bytes(restored_frame[payload_slice])
    assert restored == encoded
    assert bytes(restored_frame) == initial_frame
    writable = set(range(HEADER-window_base, HEADER-window_base+4)) | set(range(START-window_base, END-window_base))
    assert all(a == b for i, (a, b) in enumerate(zip(initial_frame, candidate_frame)) if i not in writable)

    # Algebraic independent control: a selected primitive only changes one u32.
    controls = [0, 1, 0x7FFFFFFF, 0x80000000, MASK, XOR_A, XOR_B, 0x12345678]
    controls += [1 << i for i in range(32)]
    for word in controls:
        for index in (1, 2, 5):
            assert original_forward_word(inverse_word(word, index), index) == word
            assert inverse_word(original_forward_word(word, index), index) == word

    dependencies = [0x702EF0, 0x700B18, 0x700BF0, 0x700CA8, 0x700CE8, 0x700D50,
                    0x701478, 0x7015F0, 0x701690, 0x7018E8, 0x700EC8, 0x700F68, 0x7011A0]
    db = sqlite3.connect('file:' + (ROOT/'build-function-index/index.sqlite').as_posix()+'?mode=ro', uri=True)
    db.row_factory = sqlite3.Row
    evidence = []
    total_words = omitted_zero = 0
    for address in dependencies:
        row = db.execute('select * from functions where image=? and start=?', ('o5', address)).fetchone()
        assert row is not None
        pcs = set()
        for m in re.finditer(r'// 0x([0-9a-f]+): 0x([0-9a-f]+)\s', (ROOT/row['source']).read_text(), re.I):
            pc = int(m[1], 16)
            if address <= pc < row['end']:
                assert u32(read(pc, 4)) == int(m[2], 16)
                pcs.add(pc)
        for pc in range(address, row['end'], 4):
            if pc not in pcs:
                assert u32(read(pc, 4)) == 0
                omitted_zero += 1
        total_words += len(pcs)
        evidence.append({'image': 'o5', 'start': hex(address), 'end': hex(row['end']),
                         'sha256': sha(read(address, row['end']-address)), 'verifiedCommentWords': len(pcs)})
    db.close()
    assert sha(IMAGE.read_bytes()) == IMAGE_HASH
    out = args.output.resolve()
    out.mkdir(parents=True, exist_ok=False)
    artifacts = {'encoded.bin': encoded, 'candidate.bin': candidate, 'restored.bin': restored,
                 'original-frame.bin': initial_frame, 'candidate-frame.bin': bytes(candidate_frame),
                 'restored-frame.bin': bytes(restored_frame)}
    for name, raw in artifacts.items():
        with (out/name).open('xb') as f:
            f.write(raw)
    result = {'kind': 'offline byte arithmetic only; recovered instructions never executed',
              'ownedImage': str(IMAGE.relative_to(ROOT)), 'ownedImageSha256': IMAGE_HASH,
              'payloadStart': hex(START), 'payloadEndExclusive': hex(END), 'payloadBytes': END-START,
              'entry': hex(0x702EF0), 'decodeCall': hex(0x702F38), 'decodeAnchor': hex(START),
              'decodeDescriptor': hex(HEADER), 'decodeDescriptorWords': [hex(x) for x in (flag,selector,packed,operand,reserved)],
              'decodeNormalizedSelector': hex(inv_normalized), 'decodeIndicesLowToHigh': inv_indices,
              'decodePrimitiveAddresses': [hex(inverse_table[i]) for i in inv_indices],
              'restoreCall': hex(0x703000), 'restoreAnchor': hex(END), 'restoreMetadata': hex(RESTORE_META),
              'restoreMetadataWords': [hex(x) for x in (restore_selector,restore_packed,restore_operand)],
              'restoreNormalizedSelector': hex(fwd_normalized), 'restoreIndicesLowToHigh': fwd_indices,
              'restorePrimitiveAddresses': [hex(forward_table[i]) for i in fwd_indices],
              'exceptionKey': 0, 'exceptionCount': 0, 'exceptionListNeeded': False,
              'payloadChangedWords': sum(a != b for (a,), (b,) in zip(struct.iter_unpack('<I',encoded),struct.iter_unpack('<I',candidate))),
              'payloadRoundtripEqual': restored == encoded, 'completeGuardedFrameRoundtripEqual': bytes(restored_frame)==initial_frame,
              'guardedFrameStart': hex(window_base), 'guardedFrameEndExclusive': hex(window_end),
              'onlyDescriptorAndPayloadChanged': True, 'primitiveControlWords': len(controls),
              'artifactHashes': {name: sha(raw) for name,raw in artifacts.items()},
              'dependencyOwnedWordAudit': {'verifiedCommentWords': total_words, 'omittedZeroWords': omitted_zero,
                                           'conflicts': 0, 'omittedNonzeroWords': 0}, 'dependencies': evidence,
              'limits': ['No recovered instruction execution or runtime observation.',
                         'Roundtrip validates selected byte transform and paired restore schedule, not function semantics.',
                         'No nonzero exception-key or other protected interval is admitted by this proof.']}
    with (out/'proof.json').open('x', encoding='utf-8') as f:
        json.dump(result, f, indent=2)
        f.write('\n')
    print(json.dumps({'output': str(out), 'payloadBytes': END-START, 'changedWords': result['payloadChangedWords'],
                      'roundtripEqual': result['payloadRoundtripEqual'], 'frameRoundtripEqual': result['completeGuardedFrameRoundtripEqual'],
                      'artifactHashes': result['artifactHashes'], 'audit': result['dependencyOwnedWordAudit']}, indent=2))


if __name__ == '__main__':
    main()
