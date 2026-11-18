"""Bind concrete File1 descriptor-selected body/local-shape immutable content."""
import argparse,hashlib,json,re,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda b:hashlib.sha256(b).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--write-include',action='store_true');a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');image=ROOT/'build-function-index/owned-overlays/o2.bin';data=image.read_bytes();assert sha(data)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';read=lambda at,n:data[at-0x570000:at-0x570000+n];bodies=struct.unpack('<8I',read(0x71bd80,32));shapes=struct.unpack('<8I',read(0x71bda0,32));assert shapes==(0x70c2d0,)*5+(0x70c4e0,)*3
 text='// Qualified immutable File1 body/shape content; no runtime guest pointers.\nconstexpr std::array<std::array<std::uint8_t,56>,8> body_bytes{{\n';evidence=[]
 for model,at in enumerate(bodies):
  raw=read(at,56);assert struct.unpack_from('<H',raw)[0]in[0,1];text+='std::array<std::uint8_t,56>{'+','.join(map(str,raw))+'},\n';evidence.append(dict(kind='body',model=model,address=hex(at),bytes=56,sha256=sha(raw)))
 text+='}};\nconstexpr std::array<std::array<std::array<std::uint32_t,5>,9>,2> shape_words{{\n'
 for at in [0x70c2d0,0x70c4e0]:
  text+='std::array<std::array<std::uint32_t,5>,9>{{\n'
  for selector in range(9):
   target=struct.unpack('<I',read(at+4*selector,4))[0];raw=read(target,20);words=struct.unpack('<5I',raw);assert all(__import__('math').isfinite(x)for x in struct.unpack('<4f',raw[:16]));text+='std::array<std::uint32_t,5>{'+','.join(hex(x)+'u'for x in words)+'},\n';evidence.append(dict(kind='shape',table=hex(at),selector=selector,address=hex(target),bytes=20,sha256=sha(raw)))
  text+='}},\n'
 text+='}};\n';target=ROOT/'game/native/gameplay_world/motion_body_profile.inc'
 if a.write_include:assert not target.exists();target.write_text(text)
 assert target.read_text()==text;source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_005D50F0_*'));start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];proof=compare_source('complete original actor motion descriptor application',source.relative_to(ROOT).as_posix(),start,end,read);out.mkdir(parents=True);(out/'motion_body_profile.inc').write_bytes(target.read_bytes());(out/'source_qualifier.py').write_bytes(Path(__file__).read_bytes());q=dict(schema=1,status='passed',owned_overlay_sha256=sha(data),source_tool_sha256=sha(Path(__file__).read_bytes()),output_sha256=sha(target.read_bytes()),tables=dict(body_pointer_bytes=read(0x71bd80,32).hex(),shape_pointer_bytes=read(0x71bda0,32).hex()),owned_content=evidence,original_owned_body=proof,blend_addition=dict(address='0x70afa0',bytes=read(0x70afa0,4).hex()),game_run=False);(out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(status=q['status'],sha256=sha((out/'receipt.json').read_bytes()))))
if __name__=='__main__':main()
