"""Extract owned imported NETBIO archives without decoding or changing payloads.

Output paths use archive indices because AFS names can be absent or duplicated.
Requires a new output directory. Owned game data must not be distributed.
"""
import argparse
import hashlib
import json
import re
import shutil
import struct
from pathlib import Path


def read_at(stream, offset, length):
    stream.seek(offset)
    value = stream.read(length)
    if len(value) != length:
        raise ValueError('Truncated archive')
    return value


def table(stream, base, size):
    head = read_at(stream, base, min(8, size))
    if head[:4] != b'AFS\0':
        return None
    if len(head) != 8:
        raise ValueError('Truncated AFS header')
    count = struct.unpack_from('<I', head, 4)[0]
    end = 16 + count * 8
    if not 0 < count <= 100000 or end > size:
        raise ValueError('Invalid AFS entry count')
    raw = read_at(stream, base + 8, count * 8 + 8)
    entries = [struct.unpack_from('<II', raw, i * 8) for i in range(count)]
    if any(off < end or off + length > size for off, length in entries):
        raise ValueError('AFS entry outside its archive')
    noff, nsize = struct.unpack_from('<II', raw, count * 8)
    if noff + nsize > size or nsize > 48 * count + 2048:
        raise ValueError('Invalid AFS name table')
    names = read_at(stream, base + noff, nsize) if nsize else b''
    return [(off, length, names[i * 48:i * 48 + 32].split(b'\0')[0]
             .decode('ascii', 'replace') if i * 48 + 48 <= len(names) else '')
            for i, (off, length) in enumerate(entries)]


def label(index, name):
    safe = re.sub(r'[^a-zA-Z0-9_.-]', '_', name).strip('. ')[:80]
    return f'{index:05d}' + ('_' + safe if safe else '.bin')


def extract(data, output):
    data, output = Path(data).resolve(), Path(output).resolve()
    archives = sorted(data.glob('NETBIO*.DAT'))
    if not archives:
        raise ValueError('No NETBIO archives in the imported data directory')
    if output == data or data in output.parents or output in data.parents:
        raise ValueError('Output must be separate from the source import')
    if output.exists():
        raise ValueError('Output must be a new directory')
    output.mkdir(parents=True)
    records = []
    for archive in archives:
        with archive.open('rb') as stream:
            def walk(base, size, key, relative, depth):
                entries = table(stream, base, size)
                if entries is not None:
                    if depth >= 4:
                        raise ValueError('Unexpected AFS nesting depth')
                    for index, (off, length, name) in enumerate(entries):
                        walk(base + off, length, f'{key}/{index}',
                             relative / label(index, name), depth + 1)
                    return
                target = output / relative
                target.parent.mkdir(parents=True, exist_ok=True)
                digest = hashlib.sha256()
                stream.seek(base)
                remaining = size
                with target.open('xb') as dest:
                    while remaining:
                        block = stream.read(min(1024 * 1024, remaining))
                        if not block:
                            raise ValueError('Truncated payload')
                        dest.write(block)
                        digest.update(block)
                        remaining -= len(block)
                with target.open('rb') as check:
                    actual = hashlib.file_digest(check, 'sha256').hexdigest()
                if actual != digest.hexdigest():
                    raise ValueError(f'Extracted payload hash mismatch: {key}')
                records.append(dict(path=key, file=relative.as_posix(),
                                    bytes=size, sha256=actual, sourceOffset=base))
            walk(0, archive.stat().st_size, archive.name, Path(archive.name), 0)
        print(f'{archive.name}: {len(records)} total extracted files', flush=True)
    manifest = dict(format=1, source=str(data), verified=True, entries=records,
                    totalBytes=sum(row['bytes'] for row in records))
    (output / 'assets.json').write_text(json.dumps(manifest, indent=2) + '\n', encoding='utf-8')
    print(json.dumps(dict(output=str(output), files=len(records), bytes=manifest['totalBytes'],
                          verified=True)), flush=True)
    return manifest


def main():
    parser = argparse.ArgumentParser(description=__doc__)
    parser.add_argument('data', type=Path)
    parser.add_argument('output', type=Path)
    args = parser.parse_args()
    required = sum(p.stat().st_size for p in args.data.glob('NETBIO*.DAT'))
    if shutil.disk_usage(args.output.parent).free < required + 256 * 1024 * 1024:
        raise ValueError('Insufficient free space for extraction')
    extract(args.data, args.output)


if __name__ == '__main__':
    main()
