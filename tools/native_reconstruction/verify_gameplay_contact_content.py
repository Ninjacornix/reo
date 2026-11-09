"""Compare owned converted native contact content against complete original bank attachment and value helpers."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_gameplay_collision_response import PROFILES as RESPONSE
from import_gameplay_contact_content import encode_owned,owned_overlay
ROOT=Path(__file__).resolve().parents[2]
EXTRA=[('o2','00578EA0',0x578ea0),('o2','00578F10',0x578f10),('o2','00578F60',0x578f60),('o2','005790E0',0x5790e0),('o2','0057B650',0x57b650),('o2','006683E0',0x6683e0),('o2','005A87A0',0x5a87a0),('o2','005A8A50',0x5a8a50),('o2','005DC3A0',0x5dc3a0),('main','001AEC80',0x1aec80)]

EXTRA += [('o2',f'{at:08X}',at) for at in [0x5da040,0x5da0d0,0x5da1c0,0x5da2c0]]

def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def source_path(o,n,s):return ROOT/(f'recomp/config/output/sub_{n}_0x{s:x}.cpp' if o=='main' else f'recomp/config/output_ovl/{o}/{o}_{n}_0x{s:x}.cpp')
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sources=[];bodies=[];audits=[];profiles=list(RESPONSE)
 for o,n,s in EXTRA:
  path=source_path(o,n,s);end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',path.read_text())[1],16);profiles.append((o,n,s,end))
 for o,n,s,end in profiles:
  image=ROOT/('game_data/SLUS_207.65' if o=='main' else f'build-function-index/owned-overlays/{o}.bin');data=image.read_bytes();base=0x370000 if o=='o0' else 0x570000
  expected='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46' if o=='main' else 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if o=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(image)!=expected:raise ValueError('Owned source image changed')
  read=elf_reader(data) if o=='main' else lambda at,size:data[at-base:at-base+size]
  source=source_path(o,n,s);sources.append(source);audits.append(compare_source('actor-collision-original',str(source.relative_to(ROOT)),s,end,read));text=source.read_text();bodies.append(text[text.index('// Function:'):])
 base_header=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp';header=base_header.read_text().replace('#include "reference.hpp"','#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"')
 names=[('sub' if o=='main' else o,n,s) for o,n,s in EXTRA];declarations='\n'.join(f'void {o}_{n}_0x{s:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for o,n,s in names)
 ports=(ROOT/'tools/native_reconstruction/gameplay_collision_oracle/delivery_ports.hpp').read_text()+'\n'+(ROOT/'tools/native_reconstruction/gameplay_collision_oracle/contact_content_ports.hpp').read_text()
 marker='inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{'
 header=header.replace(marker,declarations+'\n'+ports+'\n'+marker)
 cases='\n'.join(f'    case 0x{s:x}:return {o}_{n}_0x{s:x};' for o,n,s in names)+'\n'
 cases+='    case 0x107c68:return sub_00107C68_0x107c68;case 0x1b0340:return sub_001B0340_0x1b0340;case 0x1ba9f0:return sub_001BA9F0_0x1ba9f0;\n'
 header=header.replace('    default:throw',cases+'    default:throw')
 paths=[ROOT/'game/native/gameplay_collision'/n for n in ['contact_content.hpp','contact_content.cpp','contact_content_tests.cpp','delivery.hpp','delivery.cpp','delivery_core_tests.cpp','contact_component.hpp','hit_regions.hpp','hit_regions.cpp','spatial.hpp','postmove_view.hpp','postmove.hpp','footprint.hpp','regions.hpp','room_objects.hpp','ownership.hpp','actors.hpp','actors.cpp','response.hpp','response.cpp','collision.hpp','collision.cpp']]+[ROOT/'game/native/gameplay_actors'/n for n in ['entity.hpp','entity.cpp','hit.hpp','status.hpp','health.hpp']]+[ROOT/'game/native/gameplay_session'/n for n in ['session.hpp','session.cpp']]+[base_header,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/delivery_ports.hpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/contact_content_ports.hpp',ROOT/'tools/native_reconstruction/import_gameplay_contact_content.py',ROOT/'tools/overlay_extract.py',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'content_reference.hpp').write_text(header);support=(ROOT/'game/native/gameplay_collision/delivery_core_tests.cpp').read_text().split('int main()')[0].replace('#include "delivery.hpp"','#include "game/native/gameplay_collision/delivery.hpp"').replace('#include "delivery_reference.hpp"','#include "content_reference.hpp"');(out/'content_support.hpp').write_text(support);content,conversion=encode_owned(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso');(out/'contact-content-v1.bin').write_bytes(content);owned,_=owned_overlay(ROOT/'iso/Resident Evil - Outbreak (v2.00).iso');(out/'owned-o2.bin').write_bytes(owned);(out/'conversion.json').write_text(json.dumps(conversion,indent=2)+'\n');original=out/'original.cpp';original.write_text('#include "content_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies))
 compiler=COMPILERS[a.compiler];exe=out/'actors.exe';env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in ['actors.cpp','delivery.cpp','contact_content.cpp','contact_content_tests.cpp','hit_regions.cpp','response.cpp','collision.cpp']],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(ROOT/'game/native/gameplay_session/session.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe),str(out/'contact-content-v1.bin'),str(out/'owned-o2.bin')])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='owned converted native contact content passes original attachment and arithmetic comparisons'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
