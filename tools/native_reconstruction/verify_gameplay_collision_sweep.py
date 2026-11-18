"""Compare native six-contact/shared-edge solver to owned original bodies."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
from verify_gameplay_collision_response import PROFILES as RESPONSE
ROOT=Path(__file__).resolve().parents[2]
EXTRA=[('o2','006169B0',0x6169b0),('o2','00616BD0',0x616bd0),('o0','00370640',0x370640),('o0','003708B0',0x3708b0),('o2','00617E70',0x617e70),('o2','00618680',0x618680),('o2','006195C0',0x6195c0),('o2','00619850',0x619850),('o2','00616420',0x616420),('o2','006165D0',0x6165d0),('o2','00616870',0x616870),('o2','006177C0',0x6177c0)]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sources=[];bodies=[];audits=[];profiles=list(RESPONSE)
 for overlay,number,start in EXTRA:
  source=ROOT/f'recomp/config/output_ovl/{overlay}/{overlay}_{number}_0x{start:x}.cpp';end=int(re.search(r'// Address: 0x[0-9a-fA-F]+ - 0x([0-9a-fA-F]+)',source.read_text())[1],16);profiles.append((overlay,number,start,end))
 for overlay,number,start,end in profiles:
  image=ROOT/f'build-function-index/owned-overlays/{overlay}.bin';data=image.read_bytes();base=0x370000 if overlay=='o0' else 0x570000
  expected='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if overlay=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(image)!=expected:raise ValueError('Owned overlay changed')
  source=ROOT/f'recomp/config/output_ovl/{overlay}/{overlay}_{number}_0x{start:x}.cpp';sources.append(source);audits.append(compare_source('sweep-original',str(source.relative_to(ROOT)),start,end,lambda at,n:data[at-base:at-base+n]));text=source.read_text();bodies.append(text[text.index('// Function:'):])
 base_header=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp';header=base_header.read_text().replace('#include "reference.hpp"','#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"')
 declarations='\n'.join(f'void {o}_{n}_0x{s:x}(std::uint8_t*,R5900Context*,PS2Runtime*);' for o,n,s in EXTRA)
 marker='inline PS2Runtime::Fn PS2Runtime::lookupFunction(std::uint32_t at)const{'
 port='inline void o0_00370420_0x370420(std::uint8_t* m,R5900Context* c,PS2Runtime* r){o0_00370570_0x370570(m,c,r);}\n'
 if header.count(marker)!=1:raise ValueError('Reference environment changed')
 header=header.replace(marker,declarations+'\n'+port+marker)
 cases='\n'.join(f'    case 0x{s:x}:return {o}_{n}_0x{s:x};' for o,n,s in EXTRA)+'\n    case 0x370420:return o0_00370420_0x370420;\n'
 header=header.replace('    default:throw',cases+'    default:throw')
 paths=[ROOT/'game/native/gameplay_collision'/name for name in ['collision.cpp','collision.hpp','response.cpp','response.hpp','sweep.cpp','sweep.hpp','sweep_tests.cpp']]+[base_header,ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 inputs={p.relative_to(ROOT).as_posix():sha(p) for p in paths};out.mkdir();(out/'sweep_reference.hpp').write_text(header);original=out/'original.cpp';original.write_text('#include "sweep_reference.hpp"\n'+'\n'.join(bodies))
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
 if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned inventory changed')
 scenarios={'r001.afs','r002.afs','r028.afs','r035.afs','r041.afs'};assets=[]
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
  for entry in json.loads(inventory.read_bytes()):
   names=[name for name in entry['names'] if re.fullmatch('w[0-9]{7}\\.bin',name)]
   if not names or not scenarios.intersection(entry['names']):continue
   stream.seek(entry['iso_offset']);data=stream.read(entry['bytes'])
   if hashlib.sha256(data).hexdigest()!=entry['sha256']:raise ValueError('Owned wall asset changed')
   destination=out/names[0];destination.write_bytes(data);assets.append((destination,entry))
 asset_list=out/'asset-list.txt';asset_list.write_text('\n'.join(str(path) for path,_ in assets)+'\n')
 compiler=COMPILERS[a.compiler];exe=out/'sweep.exe';env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');record=dict(schema=1,status='failed',source_sha256=inputs,compiler_sha256=sha(compiler),original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),'-I'+str(out),*[str(ROOT/'game/native/gameplay_collision'/name) for name in ['collision.cpp','response.cpp','sweep.cpp','sweep_tests.cpp']],str(original),'-o',str(exe)]
 try:
  record['owned_assets']=[entry for _,entry in assets]
  for label,cmd in [('compile',command),('test',[str(exe),str(asset_list),str(out/'indeterminate-owned-probes.jsonl')])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=label,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-2500:])
   if label=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Changed source: '+name)
  record['status']='native swept-sphere contact collection/selection comparisons passed'
 finally:
  record['output_sha256']={f.name:sha(f) for f in out.iterdir() if f.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
