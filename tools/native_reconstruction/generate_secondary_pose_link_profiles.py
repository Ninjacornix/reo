"""Emit exact owned secondary-pose selectors and four restore recipes."""
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct
from audit_retail_effect_descriptors import compare_source

ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    image = ROOT / 'build-function-index/owned-overlays/o2.bin'
    assert sha(image) == '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    data = image.read_bytes()
    read = lambda at, size: data[at-0x570000:at-0x570000+size]
    files, proof = [Path(__file__).resolve()], []
    for at in [0x61a6a0, 0x61b1a0]:
        path = next((ROOT / 'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))
        start, end = [int(v, 16) for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)', path.read_text()).groups()]
        assert start == at
        proof.append(compare_source('complete secondary link selection/restoration', path.relative_to(ROOT).as_posix(), start, end, read))
        files.append(path)
    generated = '// Generated from owned File1 secondary-pose link tables.\n'
    tables = []
    for name, at, size in [('ordinary_character_secondary_links', 0x70f298, 8), ('high_character_secondary_links', 0x70f2a0, 8),
                           ('ordinary_variant_secondary_links', 0x70f2b0, 224), ('high_variant_secondary_links', 0x70f390, 224)]:
        raw = read(at, size)
        assert len(raw) == size and all(v in [0, 1, 2, 3, 255] for v in raw)
        generated += f'inline constexpr std::array<std::uint8_t,{size}> {name}' + '{{' + ','.join(map(str, raw)) + '}};\n'
        tables.append(dict(name=name, address=hex(at), bytes=raw.hex(), sha256=hashlib.sha256(raw).hexdigest()))
    recipes = []
    for profile in range(4):
        at = struct.unpack('<I', read(0x70f650+4*profile, 4))[0]
        records, cursor = [], at
        while read(cursor, 1) != b'\xff':
            node, kind, target = read(cursor, 3)
            assert kind < 3 and len(records) < 32
            records.append((node, kind, target))
            cursor += 3
        generated += f'inline constexpr std::array<NodeLinkPatch,{len(records)}> secondary_restore_links_{profile}' + '{{'
        generated += ','.join('{' + f'{node},NodeLink::' + ['parent', 'child', 'sibling'][kind] + ',' + ('{}' if target == 255 else str(target)) + '}' for node, kind, target in records)
        generated += '}};\n'
        recipes.append(dict(profile=profile, address=hex(at), records=records, bytes=read(at, cursor-at+1).hex()))
    target = ROOT / 'game/native/gameplay_world/secondary_pose_link_profiles.inc'
    if target.exists():
        assert target.read_text() == generated
    else:
        target.write_text(generated)
    out.mkdir()
    for source in files:
        frozen = out / 'source' / source.relative_to(ROOT)
        frozen.parent.mkdir(parents=True, exist_ok=True)
        frozen.write_bytes(source.read_bytes())
    receipt = dict(schema=1, status='static_owned_secondary_link_profile', game_run=False, installed_in_game=False, stage4_complete=False,
                   source_sha256={p.relative_to(ROOT).as_posix(): sha(p) for p in files}, original_owned_bodies=proof,
                   tables=tables, recipes=recipes, output_sha256=sha(target), generated=target.relative_to(ROOT).as_posix(),
                   limitations=['The224-byte physical selector windows include padding. A bounded index is not proof of a stock actor/model asset or scene assignment.',
                                'Only link restoration is generated; secondary-chain solving, traversal and game acceptance remain separate.'])
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(status=receipt['status'], tables=len(tables), recipes=len(recipes), output_sha256=receipt['output_sha256'])))


if __name__ == '__main__':
    main()
