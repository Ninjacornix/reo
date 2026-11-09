"""Convert owned File1 contact content into pointer-free native values.

The input is the user's disc BIN/2.DAT, not an analysis/build directory. Physical
table windows are explicit. Their existence does not prove every cross-product
of actor class, bank and signed numeric selector is a valid original caller.
"""
import argparse
import hashlib
import json
import math
import struct
import sys
from pathlib import Path

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools'))
from overlay_extract import Iso, decompress

BASE = 0x570000
EXPECTED = '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
BANKS = [(0x71bde0, 512, 0x7200f0), (0x714710, 139, 0x716050),
         (0x709980, 5, 0x709a90)]


def digest(data):
    return hashlib.sha256(data).hexdigest()


def owned_overlay(iso_path):
    iso = Iso(iso_path)
    try:
        root = iso.root()
        directories = [(lsn, size) for name, lsn, size, flags in iso.listdir(*root)
                       if name == 'BIN' and flags & 2]
        if len(directories) != 1:
            raise ValueError('Unique owned BIN directory required')
        members = [(lsn, size) for name, lsn, size, flags in iso.listdir(*directories[0])
                   if name == '2.DAT' and not flags & 2]
        if len(members) != 1:
            raise ValueError('Unique owned BIN/2.DAT required')
        lsn, size = members[0]
        raw = iso.read(lsn, size)
    finally:
        iso.f.close()
    image = decompress(raw) if raw[:2] == b'\x02\x00' else raw
    if digest(image) != EXPECTED or image[:4] != b'MWo3' or struct.unpack_from('<I', image, 8)[0] != BASE:
        raise ValueError('Owned File1 US overlay identity mismatch')
    return image, dict(member='BIN/2.DAT', lsn=lsn, bytes=size,
                       compressed_sha256=digest(raw), decoded_sha256=digest(image))


def encode_owned(iso_path):
    image, identity = owned_overlay(iso_path)
    data_begin = BASE + 0x40 + struct.unpack_from('<I', image, 0xc)[0]
    windows = []

    def read(at, size):
        offset = at - BASE
        if offset < 0 or size < 0 or offset > len(image) or size > len(image) - offset:
            raise ValueError(f'Owned contact content range outside image: {at:x}+{size:x}')
        return image[offset:offset+size]

    def word(at):
        return struct.unpack('<I', read(at, 4))[0]

    def window(name, at, size):
        body = read(at, size)
        windows.append(dict(name=name, start=hex(at), bytes=size, sha256=digest(body)))
        return body

    def response(raw):
        # Named native fields. The output is not a copied original work record.
        offsets = [4, 6, 7, 8, 0xa, 0xb, 0xd, 0xf, 0x11, 0x12, 0x13,
                   0x16, 0x17, 0x18, 0x19, 0x1a]
        return raw[2:4] + raw[0x14:0x16] + bytes(raw[at] for at in offsets)

    definitions = []
    keys = set()
    for bank, (root, count, shapes) in enumerate(BANKS):
        descriptors = window(f'bank{bank}_physical_descriptors', root, 32*count)
        entries = []
        active = 0
        selectors = {}
        for ordinal in range(count):
            raw = descriptors[32*ordinal:32*(ordinal+1)]
            tag, pointer = struct.unpack('<II', read(shapes + 8*raw[0xe], 8))
            selectors[raw[0xe]] = (tag, pointer)
            key = raw[0x13] if bank == 0 else ordinal & 255
            native = bytes([raw[0], raw[1], raw[0xc], raw[0xd], key]) + response(raw)
            if not pointer and not raw[1]:
                geometry = b'\0'
            else:
                if tag not in [1, 2, 3, 4]:
                    raise ValueError(f'Unknown stock contact geometry tag bank{bank}/{ordinal}: {tag}')
                size = 28 if tag == 1 else 16 if tag == 2 else 30
                body = read(pointer, size)
                coordinates = struct.unpack_from('<3f' if tag == 2 else '<6f', body)
                if not all(math.isfinite(value) for value in coordinates):
                    raise ValueError('Nonfinite stock contact geometry cannot be admitted')
                geometry = bytes([tag]) + body
            if raw[1]:
                active += 1
                keys.add(struct.unpack_from('<h', raw, 2)[0])
            entries.append(native + geometry)
        for selector, (tag, pointer) in sorted(selectors.items()):
            window(f'bank{bank}_selector{selector}', shapes + 8*selector, 8)
            if pointer:
                window(f'bank{bank}_geometry{selector}', pointer,
                       28 if tag == 1 else 16 if tag == 2 else 30)
        definitions.append((entries, active, len(selectors)))

    probabilities = b''.join(window(f'probability{index}', 0x719a6c+68*index, 4)
                             for index in range(100))
    weights = window('value_weights128', 0x7346e0, 256)

    def values(at):
        raw = read(at, 128*12)
        return b''.join(raw[offset:offset+2] + bytes([raw[offset+2]])
                        for offset in range(0, len(raw), 4))

    window('flat128x3', 0x73bb00, 128*12)
    flat = values(0x73bb00)
    roots = window('physical_category_root72', 0x73b9e0, 72*4)
    categories = bytearray()
    category_tables = 0
    for index, (pointer,) in enumerate(struct.iter_unpack('<I', roots)):
        categories.append(bool(pointer))
        if pointer:
            category_tables += 1
            window(f'category{index}_128x3', pointer, 128*12)
            categories += values(pointer)
    random = bytearray()
    missing = []
    admitted = []
    for key in sorted(keys):
        try:
            if min(0x72bea0+64*key, 0x72d460+64*key) < data_begin:
                raise ValueError('Numeric selector would read original instructions')
            damage = read(0x72bea0+64*key, 64)
            progression = read(0x72d460+64*key, 64)
        except ValueError:
            missing.append(key)
            continue
        admitted.append(key)
        random += struct.pack('<h', key) + damage + progression
        window(f'random_damage_selector{key}', 0x72bea0+64*key, 64)
        window(f'random_progression_selector{key}', 0x72d460+64*key, 64)
    header = b'REOCNT01' + struct.pack('<6I', 1, 72, len(admitted), *(count for _, count, _ in BANKS))
    content = (header + probabilities + weights + flat + categories + random +
               b''.join(entry for entries, _, _ in definitions for entry in entries))
    record = dict(schema=1, format='REOCNT01', input=identity,
                  output_bytes=len(content), output_sha256=digest(content),
                  banks=[dict(bank=bank, physical_records=len(entries), active_records=active,
                              referenced_selectors=selectors)
                         for bank, (entries, active, selectors) in enumerate(definitions)],
                  category_root_words=72, category_value_tables=category_tables,
                  random_selectors=admitted, missing_random_selectors=missing,
                  data_begin=hex(data_begin),
                  source_windows=windows, original_addresses_in_runtime_format=False,
                  source_instructions_in_runtime_format=False, game_launched=False,
                  limits=['Physical bank/table windows are source-bound; valid caller combinations remain actor/scenario admission contracts.',
                          'Only signed random selectors actually carried by active physical descriptors are imported, with both original read windows present.',
                          'Generic bases -2400 and9999 remain descriptor data; their source-category pair1/3 random-table combination would read code/outside owned data and is explicitly unsupported until caller admission is proved.',
                          'This conversion is immutable asset preparation, not a game execution, packet processing or performance measurement.'])
    return content, record


def main():
    p = argparse.ArgumentParser()
    p.add_argument('--iso', type=Path, required=True)
    p.add_argument('--output', type=Path, required=True)
    a = p.parse_args()
    out = a.output.resolve()
    allowed = (ROOT / 'build-native-sjuni').resolve()
    if out.exists() or out == allowed or not out.is_relative_to(allowed):
        raise ValueError('Fresh private conversion output required')
    content, record = encode_owned(a.iso)
    out.mkdir()
    (out / 'contact-content-v1.bin').write_bytes(content)
    record['converter_sha256'] = digest(Path(__file__).read_bytes())
    record['overlay_reader_sha256'] = digest((ROOT / 'tools/overlay_extract.py').read_bytes())
    (out / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({key: record[key] for key in ['output_bytes', 'output_sha256', 'banks',
                                                 'category_value_tables', 'missing_random_selectors']}))


if __name__ == '__main__':
    main()
