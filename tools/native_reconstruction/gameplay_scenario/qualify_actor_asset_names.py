"""Reproduce the owned ordinary and alternate actor model name catalogues."""
import argparse
import hashlib
from pathlib import Path
import struct
import sys

ROOT = Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT / 'tools/native_reconstruction'))
from audit_retail_effect_descriptors import elf_reader

OUTPUT = ROOT / 'game/native/gameplay_world/actor_asset_names.inc'


def generate():
    image = (ROOT / 'game_data/SLUS_207.65').read_bytes()
    assert hashlib.sha256(image).hexdigest() == '06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    read = elf_reader(image)
    lines = ['// Owned File #1 model asset names. Reproduce with qualify_actor_asset_names.py.']
    for name,address,count in [('ordinary_actor_names',0x236310,156),('alternate_actor_names',0x236580,30)]:
        pointers = struct.unpack('<' + str(count) + 'I',read(address,4*count))
        lines.append('constexpr std::array<std::string_view,' + str(count) + '> ' + name + '{{')
        for pointer in pointers:
            if not pointer:
                lines.append('    {},')
                continue
            raw = read(pointer,128).split(b'\0')[0]
            assert raw.startswith(b'DATA\\ROM\\MODEL\\') and len(raw) < 128
            stem = raw.rsplit(b'\\',1)[1].decode('ascii')
            assert stem and all(character.isalnum() or character == '_' for character in stem)
            lines.append('    "' + stem + '.NBD",')
        lines.append('}};')
    return '\n'.join(lines) + '\n'


if __name__ == '__main__':
    parser = argparse.ArgumentParser()
    parser.add_argument('--write',action='store_true')
    arguments = parser.parse_args()
    expected = generate()
    if arguments.write:
        OUTPUT.write_text(expected,encoding='utf-8')
    assert OUTPUT.read_text(encoding='utf-8') == expected
    print(OUTPUT.name,hashlib.sha256(OUTPUT.read_bytes()).hexdigest())
