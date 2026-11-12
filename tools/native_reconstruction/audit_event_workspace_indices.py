"""Inventory owned event NBD static indices that can reach the shared workspace writer."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
import sys

ROOT = Path(__file__).resolve().parents[2]
sys.path.insert(0, str(ROOT / 'tools/assets'))
from afs_inspect import read_toc
from audit_retail_effect_descriptors import compare_source, elf_reader

sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def inspect_skeleton(payload):
    offset, length = struct.unpack_from('<II', payload, 0x24)
    if not offset:
        return dict(roots=0, nodes=0, indices=[])
    assert 12 <= length <= len(payload) - offset
    raw = payload[offset:offset + length]
    count, extent = struct.unpack_from('<II', raw, 4)
    assert 12 <= extent <= len(raw)
    at, roots, nodes = 12, [], []
    for _ in range(count):
        kind, entries, size = struct.unpack_from('<III', raw, at)
        assert size >= 12 and at + size <= extent
        if kind & 255:
            assert size >= 84
            nodes.append(dict(links=struct.unpack_from('<ii', raw, at + 20),
                              index=struct.unpack_from('<h', raw, at + 12 + 0x40)[0]))
        else:
            assert not roots and 4 * entries <= size - 12
            roots = list(struct.unpack_from('<' + str(entries) + 'I', raw, at + 12))
        at += size
    assert at == extent and roots
    reached = set()
    for root in roots:
        seen, pending = set(), [root]
        while pending:
            node = pending.pop()
            assert 0 <= node < len(nodes) and node not in seen
            seen.add(node)
            pending.extend(link for link in nodes[node]['links'] if link != -1)
        assert seen == set(range(min(seen), min(seen) + len(seen)))
        reached.update(seen)
    # Inspect all records as well, so unused roots or future root selection do not
    # quietly weaken the bound established for this exact owned namespace.
    return dict(roots=len(roots), nodes=len(nodes), reached_nodes=len(reached),
                indices=[node['index'] for node in nodes])


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    output = args.output.resolve()
    assert not output.exists() and output.is_relative_to(ROOT / 'build-native-sjuni')
    image = ROOT / 'game_data/SLUS_207.65'
    assert sha(image) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(image.read_bytes())
    authorities = []
    for address in [0x1cd5b0, 0x1cdfe0, 0x1d2fe0, 0x193bd0, 0x1a2e00]:
        path = next((ROOT / 'recomp/config/output').glob(f'sub_{address:08X}_*'))
        text = path.read_text()
        start, end = (int(value, 16) for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', text).groups())
        authorities.append(compare_source('event resource routing, filename formatting, skeleton index propagation or workspace write',
                                          path.relative_to(ROOT).as_posix(), start, end, read))
    fmt = read(0x255ff0, 64).split(b'\0')[0].decode('ascii')
    assert fmt == '%sST\\R%03d\\E%03d%02d%02d'
    prefixes = []
    for address in struct.unpack('<II', read(0x2366d0, 8)):
        prefixes.append(read(address, 64).split(b'\0')[0].decode('ascii'))
    assert prefixes == ['DATA\\ROM\\TEX\\', 'DATA\\ROM\\MODEL\\']
    prior = json.loads((ROOT / 'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_text())
    archive = Path(prior['commands'][2]['command'][1])
    rows, archives, authored_indices = [], [], []
    for archive in sorted(archive.parent.glob('*.DAT')):
        stamp = archive.stat().st_size, archive.stat().st_mtime_ns
        scanned = []
        with archive.open('rb') as source:
            outer = read_toc(source, 0)
            if outer is None:
                continue
            nested_by_name = {}
            for (outer_offset, _), (outer_name, _) in zip(outer[0], outer[2]):
                nested = read_toc(source, outer_offset)
                if nested is None:
                    continue
                nested_by_name[outer_name.lower()] = (outer_offset, nested)
                scanned.append(dict(name=outer_name, names_sha256=hashlib.sha256(
                    '\n'.join(row[0] for row in nested[2]).encode()).hexdigest(), entries=len(nested[0])))
                for (offset, length), (name, _) in zip(nested[0], nested[2]):
                    if not re.fullmatch(r'E\d{7,9}\.NBD', name, re.I):
                        continue
                    source.seek(outer_offset + offset)
                    payload = source.read(length)
                    assert len(payload) == length
                    data = inspect_skeleton(payload)
                    rows.append(dict(container=archive.name, archive=outer_name, name=name,
                                     offset=outer_offset + offset, bytes=length,
                                     sha256=hashlib.sha256(payload).hexdigest(), **data))
            for (offset, length), (name, _) in zip(outer[0], outer[2]):
                match = re.fullmatch(r'r([0-9a-f]{3})_h\.bin', name, re.I)
                if not match:
                    continue
                source.seek(offset)
                header = source.read(length)
                first, count = struct.unpack_from('<II', header)
                assert len(header) == 8 + 16 * count
                base, nested = nested_by_name['r' + match[1] + '.afs']
                assert first + count <= len(nested[0])
                keys = [header[8 + 16 * index:24 + 16 * index].split(b'\0')[0].decode('ascii')
                        for index in range(count)]
                matched = []
                placement_keys = 0
                for ordinal, key in enumerate(keys):
                    if re.fullmatch(r'E\d{7,9}_BIN', key, re.I):
                        placement_keys += 1
                    if not re.fullmatch(r'E\d{7,9}(?:_NBD)?', key, re.I):
                        continue
                    member_offset, size = nested[0][first + ordinal]
                    member_name = nested[2][first + ordinal][0]
                    source.seek(base + member_offset)
                    payload = source.read(size)
                    assert len(payload) == size
                    data = inspect_skeleton(payload)
                    matched.append(dict(key=key, member=member_name, bytes=size,
                                        sha256=hashlib.sha256(payload).hexdigest(), **data))
                    rows.append(dict(container=archive.name, archive='r' + match[1] + '.afs',
                        name=member_name, authored_key=key, offset=base + member_offset,
                        bytes=size, sha256=hashlib.sha256(payload).hexdigest(), **data))
                authored_indices.append(dict(container=archive.name, name=name, entries=count,
                    sha256=hashlib.sha256(header).hexdigest(), event_model_keys=matched,
                    distinct_event_placement_bin_keys=placement_keys))
        assert stamp == (archive.stat().st_size, archive.stat().st_mtime_ns)
        archives.append(dict(name=archive.name, bytes=stamp[0], nested=scanned))
    nonnegative = [index for row in rows for index in row['indices'] if index >= 0]
    source_paths = [Path(__file__), ROOT / 'tools/assets/afs_inspect.py',
                    ROOT / 'tools/native_reconstruction/audit_retail_effect_descriptors.py',
                    ROOT / 'game/native/animation/model.cpp']
    source_paths += [ROOT / item['path'] for item in authorities]
    record = dict(schema=1, status=('namespace_absent' if not rows else
                  'bounded_owned_namespace' if nonnegative and max(nonnegative) < 4096 else 'outside_workspace_prefix'),
                  source_sha256={path.relative_to(ROOT).as_posix(): sha(path) for path in source_paths},
                  image_sha256=sha(image), original_owned_bodies=authorities,
                  formatter=fmt, prefixes=prefixes, resource_range='2100..23FF',
                  scanned_archives=archives, authored_indices=authored_indices,
                  assets=len(rows), nodes=sum(row['nodes'] for row in rows),
                  nonnegative_min=min(nonnegative, default=None), nonnegative_max=max(nonnegative, default=None),
                  exclusive_write_end=(max(nonnegative) + 1) * 64 if nonnegative else None,
                  descriptor_partition_offset=0x40000,
                  rows=rows, game_run=False, stage4_complete=False,
                  limits=['Static inventory of every matching owned event NBD and every raw skeleton node, including all roots. '
                          'If no display names or authoritative resource keys match, no writer bound is established. Scene-placement E*.BIN files are a distinct format. '
                          'This does not certify absent/replaced future assets or execute complete resource construction.'])
    output.mkdir()
    (output / 'receipt.json').write_text(json.dumps(record, indent=2) + '\n')
    print(json.dumps({key: record[key] for key in ['status', 'assets', 'nodes', 'nonnegative_min', 'nonnegative_max', 'exclusive_write_end']}))


if __name__ == '__main__':
    main()
