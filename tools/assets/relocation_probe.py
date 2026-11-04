"""Create a private T0 ISO with unchanged assets at shifted nested AFS offsets.

Never edits the source ISO. Output contains owned game data; do not distribute it.
Usage: relocation_probe.py original.iso output.iso [--room r001.afs]
"""
import argparse
import json
import shutil
import struct
from pathlib import Path

SECTOR = 2048


def toc(stream, base, size):
    stream.seek(base)
    header = stream.read(8)
    if header[:4] != b'AFS\0':
        raise ValueError('Not an AFS archive')
    count = struct.unpack_from('<I', header, 4)[0]
    if not 0 < count <= 10000 or 16 + count * 8 > size:
        raise ValueError('Invalid AFS table')
    table = stream.read(count * 8 + 8)
    entries = [struct.unpack_from('<II', table, i * 8) for i in range(count)]
    if any(off < 16 + count * 8 or off + length > size for off, length in entries):
        raise ValueError('AFS entry outside archive')
    names_offset, names_size = struct.unpack_from('<II', table, count * 8)
    if names_offset + names_size > size:
        raise ValueError('AFS name table outside archive')
    stream.seek(base + names_offset)
    names = stream.read(names_size)
    labels = [names[i * 48:i * 48 + 32].split(b'\0')[0].decode('ascii', 'replace')
              for i in range(min(count, len(names) // 48))]
    return entries, names_offset, names_size, labels


def copy_range(source, output, offset, length):
    source.seek(offset)
    while length:
        data = source.read(min(length, 1024 * 1024))
        if not data:
            raise EOFError('Truncated input')
        output.write(data)
        length -= len(data)


def build(source_path, output_path, room):
    source_path, output_path = Path(source_path).resolve(), Path(output_path).resolve()
    if source_path == output_path or output_path.exists():
        raise ValueError('Output must be a new file, separate from the owned ISO')
    with source_path.open('rb') as source:
        source.seek(16 * SECTOR)
        pvd = source.read(SECTOR)
        if pvd[1:6] != b'CD001':
            raise ValueError('Unsupported ISO descriptor')
        root_lba, root_size = struct.unpack_from('<I', pvd, 158)[0], struct.unpack_from('<I', pvd, 166)[0]
        source.seek(root_lba * SECTOR)
        directory = source.read(root_size)
        record = None
        at = 0
        while at < len(directory):
            length = directory[at]
            if not length:
                at = (at // SECTOR + 1) * SECTOR
                continue
            name = directory[at + 33:at + 33 + directory[at + 32]].split(b';')[0]
            if name == b'NETBIO00.DAT':
                record = at
                break
            at += length
        if record is None:
            raise ValueError('NETBIO00.DAT was not found')
        lba, size = struct.unpack_from('<I', directory, record + 2)[0], struct.unpack_from('<I', directory, record + 10)[0]
        base = lba * SECTOR
        entries, names_offset, names_size, labels = toc(source, base, size)
        room_index = labels.index(room)
        inner_offset, inner_size = entries[room_index]
        inner, inner_names, _, _ = toc(source, base + inner_offset, inner_size)
        # Insert a sector before the first outer payload and the first room asset.
        cuts = sorted([min(off for off, _ in entries), inner_offset + inner[0][0]])
        def shifted(value):
            return value + SECTOR * sum(cut <= value for cut in cuts)
        with output_path.open('xb+') as output:
            source.seek(0)
            shutil.copyfileobj(source, output, 1024 * 1024)
            padding = (-output.tell()) % SECTOR
            output.write(bytes(padding))
            new_base = output.tell()
            previous = 0
            for cut in cuts:
                copy_range(source, output, base + previous, cut - previous)
                output.write(bytes(SECTOR))
                previous = cut
            copy_range(source, output, base + previous, size - previous)
            new_size = size + 2 * SECTOR
            def word(offset, value):
                output.seek(offset)
                output.write(struct.pack('<I', value))
            for index, (offset, length) in enumerate(entries):
                word(new_base + 8 + index * 8, shifted(offset))
                if index == room_index:
                    word(new_base + 12 + index * 8, length + SECTOR)
                    # Update a proven size copy, preserving unknown metadata.
                    if names_size >= (index + 1) * 48:
                        output.seek(new_base + shifted(names_offset) + index * 48 + 44)
                        if struct.unpack('<I', output.read(4))[0] == length:
                            word(new_base + shifted(names_offset) + index * 48 + 44, length + SECTOR)
            if names_offset:
                word(new_base + 8 + len(entries) * 8, shifted(names_offset))
            new_inner = new_base + shifted(inner_offset)
            for index, (offset, _) in enumerate(inner):
                word(new_inner + 8 + index * 8, offset + (SECTOR if offset >= inner[0][0] else 0))
            if inner_names:
                word(new_inner + 8 + len(inner) * 8, inner_names + (SECTOR if inner_names >= inner[0][0] else 0))
            # Update the ISO directory record, preserving the executable and other files.
            for offset, value in [(root_lba * SECTOR + record + 2, new_base // SECTOR),
                                  (root_lba * SECTOR + record + 10, new_size)]:
                output.seek(offset)
                output.write(struct.pack('<I', value) + struct.pack('>I', value))
            output.seek(0, 2)
            output.write(bytes((-output.tell()) % SECTOR))
            sectors = output.tell() // SECTOR
            output.seek(16 * SECTOR + 80)
            output.write(struct.pack('<I', sectors) + struct.pack('>I', sectors))
        return dict(source=str(source_path), output=str(output_path), room=room,
                    original_netbio_lba=lba, relocated_netbio_lba=new_base // SECTOR,
                    original_netbio_bytes=size, relocated_netbio_bytes=new_size,
                    room_entries=len(inner), status='prepared; gameplay verification pending')


if __name__ == '__main__':
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('source')
    parser.add_argument('output')
    parser.add_argument('--room', default='r001.afs')
    args = parser.parse_args()
    print(json.dumps(build(args.source, args.output, args.room), indent=2))
