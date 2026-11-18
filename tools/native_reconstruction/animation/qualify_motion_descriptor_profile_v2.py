"""Bind File1 descriptor lookup roots and exact single-level character indirections."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda b:hashlib.sha256(b).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--write-include',action='store_true');a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');image=ROOT/'build-function-index/owned-overlays/o2.bin';body=image.read_bytes();assert sha(body)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';read=lambda at,n:body[at-0x570000:at-0x570000+n];tables={};text='// Qualified owned File1 motion metadata; no runtime guest addresses.\n'
 for name,at,count in [('direct',0x7269f0,88),('class_zero',0x725cb0,472),('class_one',0x726060,488),('class_two',0x726430,80),('class_three',0x7264d0,80),('state_map',0x726570,576)]:
  raw=read(at,count*2);values=struct.unpack('<'+'H'*count,raw);assert max(values)<568;tables[name]=dict(address=hex(at),count=count,sha256=sha(raw));text+='constexpr std::array<std::uint16_t,'+str(count)+'> '+name+'{'+','.join(map(str,values))+'};\n'
 ptrs=struct.unpack('<4I',read(0x725ca0,16));assert ptrs==(0x725cb0,0x726060,0x726430,0x7264d0)
 raw=read(0x719a60,64*68);assert all(raw[68*i+6]==i for i in range(64));classes=[raw[68*i+4]for i in range(64)];assert max(classes)<4;text+='constexpr std::array<std::uint8_t,64> resource_classes{'+','.join(map(str,classes))+'};\n';tables['resource_classes']=dict(base='0x719a60',stride=68,admitted_records=64,raw_sha256=sha(raw),selection='record byte4; all64 record byte6 ordinals match admitted IDs; no claim about IDs64+')
 admitted=set(range(568))
 for i in range(568):
  packed=read(0x726aa0+i*8,8)
  if packed[0]>>4==15:
   base=struct.unpack_from('<H',packed,6)[0];admitted.update(range(base,base+8))
 assert len(admitted)==768 and max(admitted)==1111
 text+='constexpr std::array<bool,1112> descriptor_admission{'+','.join('true'if i in admitted else'false'for i in range(1112))+'};\n'
 raw=read(0x726aa0,1112*8);text+='constexpr std::array<PackedMotion,1112> descriptors{{\n' +',\n'.join('PackedMotion{{'+','.join(map(str,raw[i:i+8]))+'}}'for i in range(0,len(raw),8))+'\n}};\n';tables['descriptors']=dict(address='0x726aa0',count=1112,admitted_count=768,admitted_ids=sorted(admitted),sha256=sha(raw),selection='all568 lookup roots plus200 exact category0/1 character/subtype0..7 single-indirection targets; unreferenced gaps refused')
 target=ROOT/'game/native/animation/motion_descriptor_profile.inc'
 previous=ROOT/'build-native-sjuni/motion-descriptor-profile-v1/receipt.json';prior=json.loads(previous.read_bytes());old_include=ROOT/'build-native-sjuni/motion-descriptor-profile-v1/motion_descriptor_profile.inc';assert sha(old_include.read_bytes())==prior['output_sha256'];out.mkdir(parents=True);(out/'previous_motion_descriptor_profile.inc').write_bytes(old_include.read_bytes())
 if a.write_include:
  assert sha(target.read_bytes())==prior['output_sha256'];target.write_text(text)
 assert target.read_text()==text
 proofs=[]
 for at in [0x5d4570,0x5d46c0]:
  f=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',f.read_text()).groups()];proofs.append(compare_source('complete original descriptor resolve/unpack body',f.relative_to(ROOT).as_posix(),start,end,read))
 (out/'motion_descriptor_profile.inc').write_bytes(target.read_bytes());(out/'source_qualifier.py').write_bytes(Path(__file__).read_bytes());q=dict(schema=2,status='passed',previous_profile=dict(path=str(previous),sha256=sha(previous.read_bytes()),include_sha256=prior['output_sha256']),output_sha256=sha(target.read_bytes()),source_tool_sha256=sha(Path(__file__).read_bytes()),owned_overlay_sha256=sha(body),tables=tables,family2_pointer_bytes=read(0x725ca0,16).hex(),original_owned_bodies=proofs,game_run=False);(out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(status=q['status'],sha256=sha((out/'receipt.json').read_bytes()))))
if __name__=='__main__':main()
