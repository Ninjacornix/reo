"""Compare standalone native post-pose summaries with owned original bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_gameplay_collision_response import PROFILES as RESPONSE
ROOT=Path(__file__).resolve().parents[2]
EXTRA=[('o2','006F14F0',0x6f14f0),('o2','005DA600',0x5da600),('o2','005DA620',0x5da620),('o2','006EF150',0x6ef150),('o2','006EF270',0x6ef270),('o2','006EF720',0x6ef720),('o2','006EFBC0',0x6efbc0),('o2','006EFDE0',0x6efde0),('o2','006F0010',0x6f0010),('o2','006F1430',0x6f1430),('o2','006F1700',0x6f1700),('o2','006F1750',0x6f1750),('o0','00376E70',0x376e70),('main','00191EF0',0x191ef0)]
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
 ports='''
inline void sub_00107C68_0x107c68(std::uint8_t* m,R5900Context* c,PS2Runtime*){std::memset(m+GPR_U32(c,4),int(GPR_U32(c,5)&255),GPR_U32(c,6));c->g[2].lo=GPR_U32(c,4);c->pc=GPR_U32(c,31);}
inline void sub_001B0310_0x1b0310(std::uint8_t* m,R5900Context* c,PS2Runtime*){c->g[2].lo=m[64];c->pc=GPR_U32(c,31);}
inline void sub_001B02D0_0x1b02d0(std::uint8_t* m,R5900Context* c,PS2Runtime*){c->g[2].lo=m[65];c->pc=GPR_U32(c,31);}
inline void sub_00192180_0x192180(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=std::atan2(c->f[12],c->f[13]);c->pc=GPR_U32(c,31);}
inline void sub_001919D0_0x1919d0(std::uint8_t* m,R5900Context* c,PS2Runtime*){const auto a=GPR_U32(c,5),b=GPR_U32(c,6),out=GPR_U32(c,4);const auto p=ref_read<std::array<float,3>>(m,a);std::array<float,3> result;for(unsigned i=0;i<3;++i)result[i]=(ref_read<float>(m,b+4*i)*p[0]+ref_read<float>(m,b+16+4*i)*p[1])+ref_read<float>(m,b+32+4*i)*p[2];ref_write(m,out,result);c->pc=GPR_U32(c,31);}
'''
 marker='inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{'
 header=header.replace(marker,declarations+'\n'+ports+marker)
 cases='\n'.join(f'    case 0x{s:x}:return {o}_{n}_0x{s:x};' for o,n,s in names)+'\n'
 cases+='    case 0x107c68:return sub_00107C68_0x107c68;case 0x1b0310:return sub_001B0310_0x1b0310;case 0x1b02d0:return sub_001B02D0_0x1b02d0;case 0x192180:return sub_00192180_0x192180;case 0x1919d0:return sub_001919D0_0x1919d0;\n'
 header=header.replace('    default:throw',cases+'    default:throw')
 paths=[ROOT/'game/native/gameplay_collision'/n for n in ['actors.hpp','actors.cpp','actor_views.cpp','actor_views.hpp','actor_views_tests.cpp','actor_metadata.hpp','actor_metadata.cpp','actor_metadata_tests.cpp','postmove_view.hpp','postmove.hpp','footprint.hpp','regions.hpp','room_objects.hpp','ownership.hpp','response.hpp','response.cpp','collision.hpp','collision.cpp']]+[ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',base_header,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'actors_reference.hpp').write_text(header);(out/'metadata_support.hpp').write_text((ROOT/'game/native/gameplay_collision/actor_views_tests.cpp').read_text().split('void compare(')[0].replace('#include "actor_views.hpp"','#include "game/native/gameplay_collision/actor_views.hpp"'));original=out/'original.cpp';original.write_text('#include "actors_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies))
 compiler=COMPILERS[a.compiler];exe=out/'actors.exe';env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in ['actors.cpp','actor_views.cpp','actor_metadata.cpp','actor_metadata_tests.cpp','response.cpp','collision.cpp']],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native standalone actor metadata passes original comparisons'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
