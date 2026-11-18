"""Reproduce bounded initialized File #1 enemy route metadata from owned bytes."""
import argparse
import hashlib
from pathlib import Path
import struct

ROOT=Path(__file__).resolve().parents[3]
OUTPUT=ROOT/'game/native/gameplay_scenario/enemy_route_profiles.inc'
OVERLAY_SHA='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'


def generate():
    data=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(data).hexdigest()==OVERLAY_SHA
    # Extents stop at the next independently identified authored object.
    roots={1:(0x731908,2),6:(0x731920,8),35:(0x7319a0,8),41:(0x731a80,4)}
    groups={0x7318f0:6,0x731918:2,0x731950:2,0x731960:2,0x731970:2,
            0x731998:2,0x7319d8:2,0x731a40:6,0x731a70:4}
    words=lambda at,count:struct.unpack_from('<'+'I'*count,data,at-0x570000)
    paths={}
    for group,count in groups.items():
        for address in words(group,count):
            if not address or address in paths:continue
            offset=address-0x570000
            assert 0<=offset<len(data)
            path=[]
            for byte in data[offset:offset+128]:
                value=byte if byte<128 else byte-256
                path.append(value)
                if value<0:break
            assert path and path[-1]<0 and len(path)<=128
            paths[address]=path
    lines=['// Owned File #1 o2 SHA256 '+OVERLAY_SHA,
           '// Reproduce with qualify_enemy_route_profile.py.']
    for address,path in sorted(paths.items()):
        lines.append('constexpr std::array<std::int8_t,'+str(len(path))+'> path_'+format(address,'x')+
                     '{'+','.join(map(str,path))+'};')
    for address,count in sorted(groups.items()):
        values=['Path{path_'+format(pointer,'x')+'}' if pointer else 'Path{}' for pointer in words(address,count)]
        lines.append('constexpr std::array<Path,'+str(count)+'> group_'+format(address,'x')+
                     '{{'+','.join(values)+'}};')
    for scenario,(address,count) in roots.items():
        assert words(0x731a90+4*scenario,1)==(address,)
        values=[]
        for pointer in words(address,count):
            assert not pointer or pointer in groups
            values.append('Paths{group_'+format(pointer,'x')+'}' if pointer else 'Paths{}')
        lines.append('constexpr std::array<Paths,'+str(count)+'> scenario_'+str(scenario)+
                     '{{'+','.join(values)+'}};')
    lines.append('constexpr std::array<ScenarioPaths,4> route_scenarios{{'+
                 ','.join('ScenarioPaths{'+str(scenario)+',scenario_'+str(scenario)+'}' for scenario in roots)+'}};')
    return '\n'.join(lines)+'\n'


if __name__=='__main__':
    parser=argparse.ArgumentParser()
    parser.add_argument('--write',action='store_true')
    arguments=parser.parse_args()
    text=generate()
    if arguments.write:OUTPUT.write_text(text,encoding='utf-8')
    assert OUTPUT.read_text(encoding='utf-8')==text
    print(hashlib.sha256(OUTPUT.read_bytes()).hexdigest())
