"""Extract File1 scripted motion member identities from the owned ROM aliases."""
import argparse, hashlib, json, re, struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source, elf_reader

ROOT = Path(__file__).resolve().parents[2]
sha = lambda p: hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--output', type=Path, required=True)
    args = parser.parse_args()
    out = args.output.resolve()
    assert not out.exists() and out.is_relative_to(ROOT / 'build-native-sjuni')
    elf = ROOT / 'game_data/SLUS_207.65'
    assert sha(elf) == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(elf.read_bytes())
    aliases, rows = [], []
    for ordinal in range(1342):
        address = struct.unpack('<I', read(0x2322c0 + 4 * ordinal, 4))[0]
        raw = bytearray()
        for offset in range(256):
            value = read(address + offset, 1)[0]
            if not value:
                break
            raw.append(value ^ 255)
        else:
            raise ValueError('Unbounded original ROM alias')
        alias = raw.decode('ascii')
        aliases.append(alias)
        match = re.fullmatch(r'MOTION_DEMO_R(\d{3})_(D(\d{2})(FACE)?|HD(\d{2}))_BIN', alias)
        if match:
            kind = 2 if match[5] else 1 if match[4] else 0
            clip = int(match[5] or match[3])
            rows.append(dict(scenario=int(match[1]), clip=clip, kind=kind,
                             member=ordinal, alias=alias))
    assert len(set(aliases)) == len(aliases) == 1342 and len(rows) == 89
    assert len({(r['scenario'], r['clip'], r['kind']) for r in rows}) == len(rows)
    proofs = []
    for address in [0x1d1cc0, 0x1cc8f0, 0x1aa480, 0x1aa110, 0x1ab050]:
        path = ROOT / f'recomp/config/output/sub_{address:08X}_0x{address:x}.cpp'
        end = int(re.search(r'// Address: 0x[\da-f]+ - (0x[\da-f]+)', path.read_text())[1], 16)
        proofs.append(compare_source('scripted motion load, routing and ROM alias authority',
                                     path.relative_to(ROOT).as_posix(), address, end, read))
    formats = {hex(at): read(at, 64).split(b'\0')[0].decode('ascii')
               for at in [0x256430, 0x256460, 0x256490]}
    text = '// File1 owned ROM alias ordinals; duplicate AFS display names are not identities.\n'
    text += 'constexpr std::array<ScriptedMotionMember,89> scripted_motion_members{{\n'
    text += ''.join('    {' + ','.join(str(row[key]) for key in ['scenario', 'clip', 'kind', 'member']) + '},\n'
                    for row in rows)
    text += '}};\n'
    target = ROOT / 'game/native/gameplay_world/scripted_motion_members.inc'
    if target.exists():
        assert target.read_bytes() == text.encode(), 'Existing native profile differs'
    else:
        target.write_bytes(text.encode())
    out.mkdir()
    (out / target.name).write_bytes(target.read_bytes())
    receipt = dict(schema=1, status='passed', game_run=False, elf_sha256=sha(elf),
                   source_sha256={Path(__file__).relative_to(ROOT).as_posix(): sha(Path(__file__))},
                   alias_table=dict(address='0x2322c0', count=1342,
                                    sha256=hashlib.sha256('\n'.join(aliases).encode()).hexdigest()),
                   formats=formats, rows=rows, original_owned_bodies=proofs,
                   output_sha256=sha(target))
    (out / 'receipt.json').write_text(json.dumps(receipt, indent=2) + '\n')
    print(json.dumps(dict(status='passed', members=len(rows), sha256=sha(target))))


if __name__ == '__main__':
    main()
