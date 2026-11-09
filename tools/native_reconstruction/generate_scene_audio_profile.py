"""Decode the ten authored sound properties and42 nonnull scenario mappings."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    source=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(source)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw=source.read_bytes();pointers=struct.unpack_from('<44I',raw,0x730af0-0x570000)
    addresses=[0x730aa0+16*i for i in range(5)];assert all(p in addresses for p in pointers[:42])and pointers[42:]==(0,0)
    rows=[list(raw[at-0x570000:at-0x570000+10])for at in addresses];scenarios=[addresses.index(p)for p in pointers[:42]]
    text='// Owned File1 scene sound properties. Alignment padding is not a resource.\nconstexpr std::array<std::array<std::uint8_t,10>,5> scene_audio_offsets{{\n'
    text+=''.join('    {{'+','.join(map(str,row))+'}},\n'for row in rows)+'}};\nconstexpr std::array<std::uint8_t,42> scene_audio_scenarios{'+','.join(map(str,scenarios))+'};\n'
    target=ROOT/'game/native/gameplay_scenario/scene_audio_profile.inc';assert not target.exists();target.write_bytes(text.encode())
    out=ROOT/'build-native-sjuni/scene-audio-profile-v1';assert not out.exists();out.mkdir();(out/target.name).write_bytes(target.read_bytes())
    (out/'receipt.json').write_text(json.dumps({'schema':1,'status':'immutable extraction; runtime comparison required','owned_sha256':sha(source),'property_addresses':addresses,'scenario_pointer_address':'0x730af0','properties':rows,'scenario_rows':scenarios,'output_sha256':sha(target),'game_run':False},indent=2)+'\n');print(sha(target))
if __name__=='__main__':main()
