"""Generate/check pinned File1 type7 effect style/resource/offset metadata."""
import argparse,hashlib,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--write',action='store_true');args=parser.parse_args()
    image=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(image).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    read=lambda at,size:image[at-0x570000:at-0x570000+size]
    styles=read(0x709460,32);assert all(value<9 or value==255 for value in styles)
    rows=[]
    for n in range(9):
        offset=','.join('f(0x%08xu)'%v for v in struct.unpack('<3I',read(0x7093f0+12*n,12)))
        rows.append('    {%d,%d,{%s}}'%(read(0x7093d8+n,1)[0],n,offset))
    text='// Generated from pinned File1 o2 by generate_resource_flight_profile.py.\nconstexpr std::array<std::uint8_t,32> flight_styles{'+','.join(str(value)for value in styles)+'};\nconstexpr std::array<ResourceFlightProfile,9> flight_profiles{{\n'+',\n'.join(rows)+'\n}};\n'
    path=ROOT/'game/native/gameplay_effects/resource_flight_profile.inc'
    if args.write:assert not path.exists();path.write_text(text,encoding='utf-8')
    assert path.read_text(encoding='utf-8')==text;print('32 style entries and9 flight resource/offset rows match pinned File1')
if __name__=='__main__':main()
