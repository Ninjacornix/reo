"""Bind linked-model allocation domains and type1 pose policy to owned images."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 o0=ROOT/'build-function-index/owned-overlays/o0.bin';o2=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';zero=o0.read_bytes();two=o2.read_bytes();base,count=struct.unpack_from('<2I',zero,0x387e98-0x370000);assert base==0x3872d0 and count==100 and base+16*count==0x387910;raw=zero[base-0x370000:base-0x370000+16*count];flags=[raw[i*16+5]for i in range(count)]
 target=ROOT/'game/native/gameplay_world/linked_model_profile.inc';assert not target.exists();target.write_text('// Exact file-backed File1 o0 type1 variant flags at3872D0+16*i+5.\nconstexpr std::array<std::uint8_t,100> type1_flags{{'+','.join(map(str,flags))+'}};\n');(out/target.name).write_bytes(target.read_bytes());proof=[]
 for bank,at in [('o0',0x376b80),('o2',0x6ba260),('o2',0x6ba300),('o2',0x58f7a0),('o2',0x651a30),('o2',0x651b80)]:
  f=next((ROOT/f'recomp/config/output_ovl/{bank}').glob(f'{bank}_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',f.read_text()).groups()];data,start=(zero,0x370000)if bank=='o0'else(two,0x570000);proof.append(compare_source('complete original linked model/list or distinct effect-domain body',f.relative_to(ROOT).as_posix(),begin,end,lambda at,size:data[at-start:at-start+size]))
 q=dict(schema=1,status='passed',images={str(p.relative_to(ROOT)):sha(p)for p in [o0,o2]},type1={'pointer':hex(base),'count':count,'bytes':len(raw),'sha256':hashlib.sha256(raw).hexdigest(),'skip_correction_value':1},linked_domain={'capacity':50,'source_stride':'0xd90','source_pool':'0x42eb00','free_count_signed_half':'0x3b58f0','free_stack':'0x3b5910','head':'0x3b58f8','tail':'0x3b5900','budget_recycled_only_on_explicit_reset':True},distinct_effect_domain={'capacity':168,'source_stride':'0x250','free_head':'0x3b5838','free_count':'0x3b5828','bank_heads':['0x3b5848','0x3b584c']},original_owned_bodies=proof,output_path=target.relative_to(ROOT).as_posix(),output_sha256=sha(target),generator_sha256=sha(Path(__file__)),game_run=False)
 (out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':str(out/'receipt.json'),'sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
