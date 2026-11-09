"""Build isolated native collision and byte-verified original geometry oracles.

No game, process attachment, window, device, VM write or existing build changes.
The generated original routines execute only in a declared test-memory harness.
"""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
PROFILES=[('o0','00370760',0x370760,0x370798),('o0','003707A0',0x3707a0,0x3708ac),('o0','00370960',0x370960,0x370ab4),('o0','00370DD0',0x370dd0,0x370fd8),('o0','00371200',0x371200,0x371268),('o2','005DC570',0x5dc570,0x5dc9a4),('o2','005DC9B0',0x5dc9b0,0x5dca84)]
COMPILERS={'llvm':Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'),'gcc':Path('C:/msys64/mingw64/bin/g++.exe')}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',required=True,type=Path);p.add_argument('--compiler',choices=COMPILERS,required=True);a=p.parse_args()
 out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output under build-native-sjuni required')
 compiler=COMPILERS[a.compiler];source_files=[];bodies=[];audits=[]
 for overlay,number,start,end in PROFILES:
  source=ROOT/f'recomp/config/output_ovl/{overlay}/{overlay}_{number}_0x{start:x}.cpp';image=ROOT/f'build-function-index/owned-overlays/{overlay}.bin'
  data=image.read_bytes();base=0x370000 if overlay=='o0' else 0x570000
  expected='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2' if overlay=='o0' else '45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
  if sha(image)!=expected:raise ValueError('Owned overlay identity changed')
  audit=compare_source('collision-original',str(source.relative_to(ROOT)),start,end,lambda at,n:data[at-base:at-base+n]);audits.append(audit)
  text=source.read_text();bodies.append(text[text.index('// Function:'):]);source_files.append(source)
 paths=[ROOT/'game/native/gameplay_collision/collision.cpp',ROOT/'game/native/gameplay_collision/collision.hpp',ROOT/'game/native/gameplay_collision/collision_tests.cpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',Path(__file__),*source_files]
 inputs={str(f.relative_to(ROOT)).replace('\\','/'):sha(f) for f in paths};out.mkdir()
 original=out/'original.cpp';original.write_text('#include "tools/native_reconstruction/gameplay_collision_oracle/reference.hpp"\n'+'\n'.join(bodies),encoding='utf8')
 metadata=json.loads((ROOT/'build-native-sjuni/first-room-door-targets-v1.json').read_bytes())['assets'][0]
 iso=ROOT/'iso/Resident Evil - Outbreak (v2.00).iso'
 with iso.open('rb') as f:f.seek(metadata['iso_offset']);room=f.read(metadata['bytes'])
 if hashlib.sha256(room).hexdigest()!=metadata['sha256']:raise ValueError('Owned first-room payload changed')
 section=out/'room-section-a.bin';section.write_bytes(room[metadata['sectionA_offset']:metadata['sectionA_offset']+metadata['sectionA_bytes']])
 receipt=dict(schema=1,status='failed',compiler=a.compiler,compiler_sha256=sha(compiler),source_sha256=inputs,original_word_audits=audits,asset_sha256=metadata['sha256'],game_launched=False,device_opened=False,checks=[])
 env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','');exe=out/'collision.exe'
 cmd=[str(compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-ffp-contract=off','-I'+str(ROOT),str(ROOT/'game/native/gameplay_collision/collision.cpp'),str(ROOT/'game/native/gameplay_collision/collision_tests.cpp'),str(original),'-o',str(exe)]
 try:
  for label,command in [('compile',cmd),('test',[str(exe),str(section)])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);receipt['checks'].append(dict(label=label,command=command,exit=result.returncode))
   if result.returncode:raise RuntimeError(label+': '+result.stderr.decode(errors='replace')[-1800:])
   if label=='test':receipt['results']=json.loads(result.stdout)
  for relative,digest in inputs.items():
   if sha(ROOT/relative)!=digest:raise ValueError('Input changed during test: '+relative)
  receipt['status']='native collision boundary and owned original geometry comparisons passed'
 finally:
  receipt['outputs_sha256']={f.name:sha(f) for f in out.iterdir() if f.is_file()};(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
 print(json.dumps(receipt['results']))
if __name__=='__main__':main()
