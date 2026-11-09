"""Focused original-body comparisons for native capsule/floor/grid response."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
PROFILES=[('o2','006F00D0',0x6f00d0,0x6f0310),('o2','006F0310',0x6f0310,0x6f0e00),('o2','006F0E00',0x6f0e00,0x6f0e60),('o2','006F0E60',0x6f0e60,0x6f0f30),('o0','00370AC0',0x370ac0,0x370b00),('o0','00370B00',0x370b00,0x370c6c),('o0','00370C70',0x370c70,0x370dd0),('o2','00617000',0x617000,0x6172f0),('o2','00617430',0x617430,0x6175b0),('o2','006161E0',0x6161e0,0x616304),('o2','00616310',0x616310,0x616420),('o2','00619A50',0x619a50,0x619a70)]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sources=[];bodies=[];audits=[]
 for overlay,number,start,end in PROFILES:
  image=ROOT/f'build-function-index/owned-overlays/{overlay}.bin';data=image.read_bytes();base=0x370000 if overlay=='o0' else 0x570000
  expected='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if overlay=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(image)!=expected:raise ValueError('Owned overlay changed')
  source=ROOT/f'recomp/config/output_ovl/{overlay}/{overlay}_{number}_0x{start:x}.cpp';sources.append(source)
  audits.append(compare_source('response-original',str(source.relative_to(ROOT)),start,end,lambda at,n:data[at-base:at-base+n]));text=source.read_text();bodies.append(text[text.index('// Function:'):])
 paths=[ROOT/'game/native/gameplay_collision/response.hpp',ROOT/'game/native/gameplay_collision/response.cpp',ROOT/'game/native/gameplay_collision/response_tests.cpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*sources]
 # Preserve the precise source/header closure; historical receipts stay intact.
 for f in paths:
  for include in re.findall(r'^\s*#include "([^"]+)"',f.read_text(),re.M):
   local=(f.parent/include).resolve();target=local if local.is_file() else (ROOT/include).resolve()
   if target.is_file() and target.is_relative_to(ROOT) and target not in paths:paths.append(target)
 inputs={f.relative_to(ROOT).as_posix():sha(f) for f in paths};out.mkdir()
 for f in paths:
  target=out/'source'/f.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(f.read_bytes())
 original=out/'original.cpp';original.write_text('#include "tools/native_reconstruction/gameplay_collision_oracle/response_reference.hpp"\n'+'\n'.join(bodies))
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
 if sha(inventory)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Pinned inventory changed')
 members=json.loads(inventory.read_bytes());assets=[];scenarios={'r001.afs','r002.afs','r028.afs','r035.afs','r041.afs'}
 selected=[entry for entry in members if scenarios.intersection(entry['names']) and any(re.fullmatch('[wg][0-9]{7}\\.bin',name) for name in entry['names'])]
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb') as stream:
  for entry in selected:
   name=next(name for name in entry['names'] if re.fullmatch('[wg][0-9]{7}\\.bin',name));stream.seek(entry['iso_offset']);body=stream.read(entry['bytes'])
   if hashlib.sha256(body).hexdigest()!=entry['sha256']:raise ValueError('Owned collision asset changed')
   destination=out/name
   if destination.exists():raise ValueError('Ambiguous collision asset basename')
   destination.write_bytes(body);assets.append((destination,entry))
 asset_list=out/'asset-list.txt';asset_list.write_text('\n'.join(str(path) for path,_ in assets)+'\n')
 compiler=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'response.exe';record=dict(schema=1,status='failed',compiler_sha256=sha(compiler),source_sha256=inputs,original_word_audits=audits,game_launched=False,checks=[])
 command=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(out/'source'),str(out/'source/game/native/gameplay_collision/response.cpp'),str(out/'source/game/native/gameplay_collision/response_tests.cpp'),str(original),'-o',str(exe)]
 try:
  record['owned_assets']=[entry for _,entry in assets]
  for name,cmd in [('compile',command),('test',[str(exe),str(asset_list)])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(name+'.stdout.txt')).write_bytes(result.stdout);(out/(name+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append(dict(label=name,command=cmd,exit=result.returncode))
   if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-2500:])
   if name=='test':record['results']=json.loads(result.stdout)
  for name,digest in inputs.items():
   if sha(ROOT/name)!=digest:raise ValueError('Changed source: '+name)
  record['status']='native capsule/floor/grid response focused comparisons passed'
 finally:
  record['output_sha256']={f.relative_to(out).as_posix():sha(f) for f in out.rglob('*') if f.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['results']))
if __name__=='__main__':main()
