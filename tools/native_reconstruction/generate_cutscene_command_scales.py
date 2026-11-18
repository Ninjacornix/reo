"""Extract the actual5EEC50 scale operands for admitted File1 actor identities."""
import argparse, hashlib, json, math, struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    source=ROOT/'build-native-sjuni/model-scale-profile-v1/receipt.json';profile=json.loads(source.read_bytes());assert profile['status']=='passed'
    raw=image.read_bytes();players=[struct.unpack_from('<3I',raw,0x71ae00+12*i-0x570000) for i in range(8)]
    # This command uses716458+20*BB4, distinct from5D6FC0's716444 base.
    variants=[(i,struct.unpack_from('<I',raw,0x716458+20*i-0x570000)[0]) for i in sorted({0}|{r[0] for r in profile['variant_scale_bits']})]
    for bits in [v for row in players for v in row]+[r[1] for r in variants]:assert math.isfinite(struct.unpack('<f',struct.pack('<I',bits))[0])
    text='// Actual5EEC50 scales: distinct NPC table expression, retained literally.\nconstexpr std::array<std::array<std::uint32_t,3>,8> cue_player_scales{{\n'
    text+=''.join('    {{'+','.join(hex(v)+'u' for v in row)+'}},\n' for row in players)+'}};\n'
    text+='constexpr std::array<CueVariantScale,'+str(len(variants))+'> cue_variant_scales{{\n'
    text+=''.join('    {'+str(i)+','+hex(bits)+'u},\n' for i,bits in variants)+'}};\n'
    target=ROOT/'game/native/gameplay_scenario/cutscene_command_scales.inc'
    if target.exists():assert target.read_bytes()==text.encode()
    else:target.write_bytes(text.encode())
    out.mkdir();(out/target.name).write_bytes(target.read_bytes())
    receipt=dict(status='passed',source_sha256={str(Path(__file__).relative_to(ROOT)):sha(Path(__file__))},overlay_sha256=sha(image),
        actor_identity_profile=dict(path=str(source),sha256=sha(source)),player_bits=players,variant_bits=variants,output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',variants=len(variants),sha256=sha(target))))
if __name__=='__main__':main()
