"""Decode immutable sound properties for existing admitted native model IDs."""
import hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    source=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(source)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    raw=source.read_bytes();models=ROOT/'game/native/gameplay_world/model_scale_profile.inc'
    ids=[int(x)for x in re.findall(r'\{(\d+),0x',models.read_text())];assert len(ids)==125 and ids==sorted(set(ids))
    player=list(struct.unpack_from('<24b',raw,0x7314f0-0x570000));variants=[(i,struct.unpack_from('<b',raw,0x7313c1-0x570000+2*(i-1))[0])for i in ids]
    text='// Immutable File1 sound properties; model IDs reuse the qualified model profile.\n'
    text+='constexpr std::array<std::int8_t,24> player_footwear{'+','.join(map(str,player))+'};\n'
    text+='constexpr std::array<FootwearEntry,125> variant_footwear{{\n'+''.join('    {%d,%d},\n'%row for row in variants)+'}};\n'
    target=ROOT/'game/native/gameplay_world/footwear_profile.inc';assert not target.exists();target.write_bytes(text.encode())
    out=ROOT/'build-native-sjuni/footwear-profile-v1';assert not out.exists();out.mkdir()
    receipt={'schema':1,'status':'immutable properties extracted; runtime behavior requires independent comparison','owned_image_sha256':sha(source),'model_ids_sha256':sha(models),'player_address':'0x7314f0','variant_byte_address':'0x7313c1+2*(id-1)','player_offsets':player,'variant_offsets':variants,'output_sha256':sha(target),'game_run':False}
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');(out/'footwear_profile.inc').write_bytes(target.read_bytes());print(sha(target))
if __name__=='__main__':main()
