"""Extract the five bounded File1 scenario sound remap tables."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    source=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(source)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw=source.read_bytes();addresses=[0x730ba0,0x730d40,0x730ee0,0x731080,0x731220]
    rows=[struct.unpack_from('<208h',raw,at-0x570000)for at in addresses]
    text='// Immutable owned File1 scenario sound remaps, scenarios1/2/28/35/41.\nconstexpr std::array<std::array<std::int16_t,208>,5> scenario_cues{{\n'
    text+=''.join('    {{'+','.join(map(str,row))+'}},\n' for row in rows)+'}};\n'
    target=ROOT/'game/native/gameplay_audio/scenario_cues_profile.inc';assert not target.exists();target.write_bytes(text.encode())
    out=ROOT/'build-native-sjuni/scenario-audio-profile-v1';assert not out.exists();out.mkdir()
    (out/target.name).write_bytes(target.read_bytes())
    (out/'receipt.json').write_text(json.dumps({'schema':1,'status':'immutable extraction; runtime comparison required','owned_sha256':sha(source),'addresses':addresses,'count':208,'output_sha256':sha(target),'game_run':False},indent=2)+'\n')
    print(sha(target))
if __name__=='__main__':main()
