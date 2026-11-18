#!/usr/bin/env python3
"""Reconstruct one owned instruction span as data; never execute recovered code.

Reads a fixed, hash-bound o4 image, transforms copied word values and writes a
JSON evidence receipt. Owned inputs, generated code and runtime stay untouched.
"""
import hashlib
import json
from pathlib import Path
import struct

ROOT = Path(__file__).resolve().parents[2]
BASE = 0x6E0000
IMAGE_SHA = '8f090617fa1ef420ad73ae2d1c960998c55259d372677804d2a1e07e1a182e16'
A = 0x09F8ED17
MASK = 0xFFFFFFFF


def rol(word, count):
    return ((word << count) | (word >> (32-count))) & MASK


def ror(word, count):
    return ((word >> count) | (word << (32-count))) & MASK


def permute(word, order):
    raw = word.to_bytes(4, 'little')
    return int.from_bytes(bytes(raw[i] for i in order), 'little')


def transform(word, slot, inverse):
    # This bounded example requires only three of the original eight slots.
    if slot == 0:
        return word ^ A
    if slot == 3:
        return ror(word, 8) if inverse else rol(word, 8)
    if slot == 7:
        if inverse:
            return permute(ror(ror(word ^ A, 8), 13), (2, 0, 3, 1))
        return rol(rol(permute(word, (1, 3, 0, 2)), 13), 8) ^ A
    raise ValueError(f'Unreviewed slot in bounded example: {slot}')


def schedule(packed):
    count = ((packed >> 28) & 7) or 5
    return [(packed >> (4*i)) & 7 for i in range(count)]


def apply(words, slots, inverse):
    result = list(words)
    for slot in slots:
        result = [transform(w, slot, inverse) for w in result]
    return result


def main():
    image = ROOT / 'build-function-index/owned-overlays/o4.bin'
    original = image.read_bytes()
    assert hashlib.sha256(original).hexdigest() == IMAGE_SHA
    read = lambda address, count: struct.unpack_from('<'+'I'*count, original, address-BASE)
    header = read(0x74E794, 5)
    restore = read(0x74E7E4, 4)
    assert header == (0, 0x5DB33B87, 0, 0x5DB33B9B, 0)
    assert restore == (0x5DB78B33, 1, 0x5DB78B2F, 0)
    assert header[2] == 0 and restore[1] == 1  # zero metadata key, opposite modes
    size = header[1] ^ header[3]
    assert size == restore[0] ^ restore[2] == 28
    entry_slots, restore_slots = schedule(header[1]), schedule(restore[0])
    assert entry_slots == [7, 0, 3, 3, 3]
    assert restore_slots == [3, 3, 3, 0, 7] == list(reversed(entry_slots))
    # Algebra checks support the Python transcription; the original instruction
    # and table reviews remain necessary evidence for matching the guest code.
    for slot in (0, 3, 7):
        for word in [0, MASK] + [1 << bit for bit in range(32)]:
            assert transform(transform(word, slot, True), slot, False) == word
    start, end = 0x74E7A8, 0x74E7C4
    source_words = list(read(start, size//4))
    candidate = apply(source_words, entry_slots, True)
    assert candidate == [0x3C020001, 0x00511021, 0x9042FCA0, 0x30420003,
                         0x2C430002, 0xA2420000, 0x0003800B]
    restored = apply(candidate, restore_slots, False)
    assert restored == source_words
    pack = lambda words: struct.pack('<'+'I'*len(words), *words)
    source_sha = hashlib.sha256(pack(source_words)).hexdigest()
    candidate_sha = hashlib.sha256(pack(candidate)).hexdigest()
    assert source_sha == '333d28887795a61690c2765fb8dc48754a54a4396263aeaf7dff3ab46110a216'
    assert candidate_sha == 'f74cfcb674d483ad4ca99b5a1be0dbdfeb79b96303f3bdfd8de4185ab2e57faf'
    assert hashlib.sha256(image.read_bytes()).hexdigest() == IMAGE_SHA
    receipt = dict(schema=1, image='o4', image_sha256=IMAGE_SHA,
                   owner='o4:0x0074E728', interval_start=hex(start), interval_end_exclusive=hex(end),
                   header_address='0x74E794', header_words=[f'{w:08X}' for w in header],
                   restore_header_address='0x74E7E4', restore_header_words=[f'{w:08X}' for w in restore],
                   exception_key=0, exception_offsets=[], entry_direction='inverse', entry_slots=entry_slots,
                   restore_direction='forward', restore_slots=restore_slots,
                   original_sha256=source_sha, reconstructed_sha256=candidate_sha,
                   original_words=[f'{w:08X}' for w in source_words],
                   reconstructed_words=[f'{w:08X}' for w in candidate],
                   payload_roundtrip_exact=True, owned_image_unchanged=True,
                   limitations='Data reconstruction and static review only. No recovered instructions executed. '
                   'Round trip proves these bytes under these schedules; not runtime reachability, thread safety, '
                   'full original API identity or performance improvement. Descriptor self-pointer/cache side effects '
                   'were reviewed statically and are not simulated by this receipt.')
    out = ROOT / 'build-function-index/dnas-recovery-example.json'
    out.write_text(json.dumps(receipt, indent=2)+'\n', encoding='utf-8')
    print('Reconstructed7 words as data; exact payload restore using owned opposite-mode schedule; image unchanged. No execution.')


if __name__ == '__main__':
    main()
