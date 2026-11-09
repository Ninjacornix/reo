"""Native segment triangle/list/grid comparison with owned original bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from verify_gameplay_collision_response import PROFILES as RESPONSE
ROOT=Path(__file__).resolve().parents[2]
EXTRA=[('o2',f'{s:08X}',s) for s in [0x579b40,0x579cd0,0x57ab70,0x579fc0,0x57ac60,0x57b650,0x578ea0,0x578f10,0x578f60,0x579140,0x579300,0x579730,0x5795e0,0x579980,0x579a50,0x57d040,0x57d290,0x57d4a0,0x57d560,0x57d630,0x616cc0,0x6175c0]]+[('main','00191EF0',0x191ef0),('o0','00371070',0x371070),('o0','00371160',0x371160)]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def path(o,n,s):return ROOT/(f'recomp/config/output/sub_{n}_0x{s:x}.cpp' if o=='main' else f'recomp/config/output_ovl/{o}/{o}_{n}_0x{s:x}.cpp')
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sources=[];bodies=[];audits=[];profiles=list(RESPONSE)
 for o,n,s in EXTRA:
  source=path(o,n,s);end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',source.read_text())[1],16);profiles.append((o,n,s,end))
 for o,n,s,end in profiles:
  image=ROOT/('game_data/SLUS_207.65' if o=='main' else f'build-function-index/owned-overlays/{o}.bin');data=image.read_bytes();base=0x370000 if o=='o0' else 0x570000
  expected='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46' if o=='main' else 'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if o=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(image)!=expected:raise ValueError('Owned image changed')
  read=elf_reader(data) if o=='main' else lambda at,size:data[at-base:at-base+size]
  source=path(o,n,s);sources.append(source);audits.append(compare_source('collision-trace-original',str(source.relative_to(ROOT)),s,end,read));text=source.read_text();bodies.append(text[text.index('// Function:'):])
 base_header=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp';header=base_header.read_text().replace('bool hasFunction(std::uint32_t)const{return false;}','bool hasFunction(std::uint32_t)const{return true;}').replace('#include "reference.hpp"','#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"')
 names=[('sub' if o=='main' else o,n,s) for o,n,s in EXTRA];declarations='\n'.join(f'void {o}_{n}_0x{s:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for o,n,s in names)
 ports='''
inline void port_acos(std::uint8_t*,R5900Context* c,PS2Runtime*){c->f[0]=std::acos(c->f[12]);c->pc=GPR_U32(c,31);}
inline void port_offset(std::uint8_t* m,R5900Context* c,PS2Runtime*){using namespace response_oracle;const auto v=read(m,GPR_U32(c,4)),origin=read(m,GPR_U32(c,5));const auto n=length(v);const auto scaled=n==0?Vector{}:scale(v,1/n);write(m,GPR_U32(c,6),{origin[0]+scaled[0]*c->f[12],origin[1]+scaled[1]*c->f[12],origin[2]+scaled[2]*c->f[12]});finish(c);}
'''
 ports+='\ninline void o0_00370420_0x370420(std::uint8_t* m,R5900Context* c,PS2Runtime* r){o0_00370570_0x370570(m,c,r);}\n'
 marker='inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{';header=header.replace(marker,declarations+'\n'+ports+'\n#include "tools/native_reconstruction/gameplay_collision_oracle/spatial_ports.hpp"\n'+marker)
 cases='\n'.join(f'    case 0x{s:x}:return {o}_{n}_0x{s:x};' for o,n,s in names)+'\ncase 0x370420:return o0_00370420_0x370420;case 0x1aec80:return sub_001AEC80_0x1aec80;case 0x5719d0:return o2_005719D0_0x5719d0;case 0x5a87a0:return o2_005A87A0_0x5a87a0;case 0x5a8a50:return o2_005A8A50_0x5a8a50;case 0x6683e0:return o2_006683E0_0x6683e0;case 0x192100:return port_acos;case 0x370fe0:return port_offset;\n';header=header.replace('    default:throw',cases+'    default:throw');header=header.replace('case 0x579b40:return o2_00579B40_0x579b40;','case 0x579b40:return spatial_probe_sphere;').replace('case 0x579cd0:return o2_00579CD0_0x579cd0;','case 0x579cd0:return spatial_probe_margin;').replace('case 0x579980:return o2_00579980_0x579980;','case 0x579980:return spatial_occlusion;')
 names=['trace.cpp','trace.hpp','spatial.cpp','spatial.hpp','nearest.hpp','spatial_tests.cpp','collision.cpp','collision.hpp','response.cpp','response.hpp'];paths=[ROOT/'game/native/gameplay_collision'/n for n in names]+[ROOT/'tools/native_reconstruction/gameplay_collision_oracle/spatial_ports.hpp',ROOT/'game/native/gameplay_actors/entity.hpp',ROOT/'game/native/gameplay_actors/entity.cpp',base_header,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'trace_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "trace_reference.hpp"\n#pragma GCC diagnostic ignored "-Wunused-variable"\n'+'\n'.join(bodies))
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
 if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned inventory changed')
 assets=[]
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
  for entry in json.loads(inventory.read_bytes()):
   valid=[n for n in entry['names'] if re.fullmatch('[wg][0-9]{7}\\.bin',n)]
   if not valid or not {'r001.afs','r002.afs','r028.afs','r035.afs','r041.afs'}.intersection(entry['names']):continue
   stream.seek(entry['iso_offset']);data=stream.read(entry['bytes'])
   if hashlib.sha256(data).hexdigest()!=entry['sha256']:raise ValueError('Owned grid changed')
   destination=out/valid[0];destination.write_bytes(data);assets.append((destination,entry))
 manifest=out/'assets.txt';manifest.write_text('\n'.join(str(p) for p,e in assets)+'\n')
 compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'trace.exe';record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,owned_assets=[{'path':str(p.relative_to(ROOT)),**e} for p,e in assets],game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/n) for n in names if n.endswith('.cpp')],str(ROOT/'game/native/gameplay_actors/entity.cpp'),str(original),'-o',str(exe)]
 try:
  for label,cmd in [('compile',command),('test',[str(exe),str(manifest)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-3000:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Source changed: '+name)
  record['status']='native spatial region/sphere contact comparisons passed'
 finally:
  record['output_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
