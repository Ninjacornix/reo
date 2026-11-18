"""Generate/check bounded File1 firing metadata against the pinned owned overlay."""
import argparse, hashlib, struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--write',action='store_true');args=parser.parse_args()
    image=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
    assert hashlib.sha256(image).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    read=lambda address,size:image[address-0x570000:address-0x570000+size]
    values=lambda address,count:','.join('f(0x%08xu)'%v for v in struct.unpack('<%dI'%count,read(address,4*count)))
    rows=[]
    for n in range(64):
        at=0x719a60+68*n
        rows.append('    {%d,%d,{%s}}'%(read(at+5,1)[0],read(at+7,1)[0],values(at+56,3)))
    text='// Generated from pinned File1 o2 by generate_weapon_fire_profile.py.\nconstexpr std::array<FireProfile,64> fire_profiles{{\n'+',\n'.join(rows)+'\n}};\n'
    text+='constexpr std::array<std::array<float,8>,13> fire_distances{{\n'+',\n'.join('    {{'+values(0x71ae80+32*n,8)+'}}'for n in range(13))+'\n}};\n'
    path=ROOT/'game/native/gameplay_world/weapon_fire_profile.inc'
    if args.write:
        assert not path.exists();path.write_text(text,encoding='utf-8')
    assert path.read_text(encoding='utf-8')==text
    print('64 firing rows and13 eight-character distance rows match pinned File1 overlay')
if __name__=='__main__':main()
