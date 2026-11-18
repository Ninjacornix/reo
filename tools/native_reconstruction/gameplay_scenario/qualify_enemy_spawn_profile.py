"""Reproduce initialized File #1 enemy health and selector metadata."""
import argparse
import hashlib
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[3]
OUTPUT=ROOT/'game/native/gameplay_scenario/enemy_spawn_profiles.inc'
OVERLAY_SHA='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'


def generate():
    data=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(data).hexdigest()==OVERLAY_SHA
    lines=['// Owned File #1 o2 SHA256 '+OVERLAY_SHA,
           '// Reproduce with qualify_enemy_spawn_profile.py.']
    for name,address in (('ordinary_health',0x729270),('offline_health',0x72a1f0)):
        values=struct.unpack_from('<1984h',data,address-0x570000)
        lines.append('constexpr std::array<std::int16_t,1984> '+name+'{')
        for index in range(0,len(values),32):
            lines.append('    '+','.join(map(str,values[index:index+32]))+',')
        lines.append('};')
    values=data[0x72f820-0x570000:0x72f920-0x570000]
    assert len(values)==256
    lines.append('constexpr std::array<std::uint8_t,256> spawn_parameters{')
    for index in range(0,256,32):
        lines.append('    '+','.join(map(str,values[index:index+32]))+',')
    lines.append('};')
    return '\n'.join(lines)+'\n'


if __name__=='__main__':
    parser=argparse.ArgumentParser()
    parser.add_argument('--write',action='store_true')
    arguments=parser.parse_args()
    text=generate()
    if arguments.write:OUTPUT.write_text(text,encoding='utf-8')
    assert OUTPUT.read_text(encoding='utf-8')==text
    print(hashlib.sha256(OUTPUT.read_bytes()).hexdigest())
