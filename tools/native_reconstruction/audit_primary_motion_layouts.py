"""Owned static primary motion track-layout audit; no target or game is run."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]
sha = lambda path: hashlib.sha256(path.read_bytes()).hexdigest()


def tracks(payload):
    offset, length = struct.unpack_from('<II', payload, 0x24)
    assert offset and 0 < length <= len(payload) - offset
    raw = payload[offset:offset + length]
    count, extent = struct.unpack_from('<II', raw, 4)
    assert 12 <= extent <= len(raw)
    at = 12
    roots, nodes = [], []
    for _ in range(count):
        kind, entries, size = struct.unpack_from('<III', raw, at)
        assert size >= 12 and size <= extent - at
        if kind & 255:
            assert size >= 84
            nodes.append(at + 12)
        else:
            assert not roots and 4 * entries <= size - 12
            roots = list(struct.unpack_from('<' + str(entries) + 'I', raw, at + 12))
        at += size
    assert at == extent and roots
    reached, pending = set(), [roots[0]]
    while pending:
        node = pending.pop()
        assert 0 <= node < len(nodes) and node not in reached
        reached.add(node)
        pending.extend(link for link in struct.unpack_from('<ii', raw, nodes[node] + 8) if link != -1)
    first = min(reached)
    assert reached == set(range(first, first + len(reached)))
    return [struct.unpack_from('<I', raw, nodes[i] + 0x44)[0] & 65535
            for i in range(first, first + len(reached))]


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    parser.add_argument('--emit-layouts', action='store_true')
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    elf = ROOT / 'game_data/SLUS_207.65'
    overlay = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    assert sha(overlay) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    main_read, raw_overlay = elf_reader(elf.read_bytes()), overlay.read_bytes()
    overlay_read = lambda at, size: raw_overlay[at - 0x570000:at - 0x570000 + size]
    proof, files = [], [Path(__file__).resolve()]
    for at in [0x5d1c70, 0x5d1da0, 0x5d1ea0, 0x5d1f20, 0x5d2240, 0x1aa740, 0x1a2e00]:
        folder = ROOT / ('recomp/config/output_ovl/o2' if at >= 0x570000 else 'recomp/config/output')
        path = next(folder.glob(f'*_{at:08X}_*'))
        begin, end = [int(x, 16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', path.read_text()).groups()]
        assert begin == at
        proof.append(compare_source('complete primary motion routing/layout boundary', path.relative_to(ROOT).as_posix(), begin, end, overlay_read if at >= 0x570000 else main_read))
        files.append(path)
    table = overlay_read(0x70ad60, 2 * 0xa0)
    assert len(table) == 2 * 0xa0
    layouts = [list(struct.unpack_from('<' + str(73 if kind == 1 else 36) + 'H', table, kind * 0xa0)) for kind in range(2)]
    adjacent = overlay_read(0x70aea0, 0xa0)
    adjacent_words = struct.unpack_from('<4I', adjacent)
    assert adjacent_words[:2] == (0x5d2480, 0x5d2790)
    profile_path = ROOT / 'build-native-sjuni/primary-actor-member-profile-v1/receipt.json'
    profile = json.loads(profile_path.read_bytes())
    assert profile['status'] == 'passed' and profile['elf_sha256'] == sha(elf)
    assert sha(ROOT / 'game/native/gameplay_world/primary_actor_members.inc') == profile['output_sha256']
    inventory = ROOT / 'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory) == '276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    members = {row['member']: row for row in json.loads(inventory.read_bytes())}
    rows = []
    with (ROOT / 'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as image:
        for row in profile['rows']:
            member = members[f"NETBIO00.DAT/0/{row['member']}"]
            image.seek(member['iso_offset'])
            payload = image.read(member['bytes'])
            assert len(payload) == member['bytes'] and hashlib.sha256(payload).hexdigest() == member['sha256']
            actual = tracks(payload)
            expected = layouts[row['model_class']] if row['model_class'] < 2 else None
            rows.append(dict(**row, sha256=member['sha256'], nodes=len(actual), authored_tracks=actual,
                             restore_tracks=expected, same_layout=actual == expected,
                             prefix_matches=expected is not None and actual[:len(expected)] == expected,
                             retained_tail=actual[len(expected):] if expected is not None else None))
    generated = None
    if args.emit_layouts:
        assert sum(row['prefix_matches'] for row in rows) == 27
        payload = '// Generated from owned File1 primary track restoration data.\n'
        for name, layout in zip(['ordinary_primary_tracks', 'high_primary_tracks'], layouts):
            payload += 'inline constexpr std::array<std::uint16_t,' + str(len(layout)) + '> ' + name + '{{' + ','.join(map(str, layout)) + '}};\n'
        target = ROOT / 'game/native/animation/primary_track_layouts.inc'
        if target.exists():
            assert target.read_text() == payload
        else:
            target.write_text(payload)
        generated = dict(path=target.relative_to(ROOT).as_posix(), sha256=sha(target))
    out.mkdir()
    for path in files:
        target = out / 'source' / path.relative_to(ROOT)
        target.parent.mkdir(parents=True, exist_ok=True)
        target.write_bytes(path.read_bytes())
    result = dict(schema=1, status='static_owned_layout_audit', game_run=False, installed_in_game=False,
                  stage4_complete=False, source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in files},
                  original_owned_bodies=proof, restore_table=dict(address='0x70ad60', bytes=table.hex(), sha256=hashlib.sha256(table).hexdigest()),
                  adjacent_kind2_probe=dict(address='0x70aea0', words=[hex(word) for word in adjacent_words], interpreted_as_restore_layout=False),
                  assets=len(rows), matched_layouts=sum(row['same_layout'] for row in rows),
                  matched_prefixes=sum(row['prefix_matches'] for row in rows),
                  supported_class_assets=sum(row['model_class'] < 2 for row in rows), generated_layouts=generated, rows=rows,
                  limitations=['Static owned asset/source layout comparison, not execution of retargeting, configuration or advancement.',
                               'Only kinds0/1 supply admitted restore data. Raw kind2 indexing reaches adjacent function-address words; no kind2 layout is invented.',
                               'HP07/P07 have seven tail nodes outside the73/36 restored prefix. Their existing labels must remain.',
                               'Source compatible packed clip counts are22/36/73 decimal; this audit supplies no new motion admission.'])
    (out / 'receipt.json').write_text(json.dumps(result, indent=2) + '\n')
    print(json.dumps({key: result[key] for key in ['status', 'assets', 'matched_layouts', 'matched_prefixes', 'supported_class_assets']}))


if __name__ == '__main__':
    main()
