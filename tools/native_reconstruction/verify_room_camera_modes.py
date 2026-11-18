"""Differential 5BE9A0 and linked camera tasks using the sealed camera oracle."""
import argparse,hashlib,json,os,re,shlex,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
COMPILER=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--native-build',type=Path,required=True);p.add_argument('--build-receipt',type=Path);a=p.parse_args()
 out=a.output.resolve();build=a.native_build.resolve();base=ROOT/'build-native-sjuni/room-camera-llvm-v6';allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists() or out==allowed or not out.is_relative_to(allowed):raise ValueError('Fresh private output required')
 sealed=json.loads((base/'receipt.json').read_text());assert sealed['status']=='passed' and sealed['compiler_sha256']==sha(COMPILER)
 for name in ('original.o','reference.hpp','functions.h','original_dispatch.hpp','owned_constants.hpp'):
  assert sha(base/name)==sealed['generated_sha256'][name],name
 image=ROOT/'build-function-index/owned-overlays/o2.bin';o0=ROOT/'build-function-index/owned-overlays/o0.bin';elf=ROOT/'game_data/SLUS_207.65'
 assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 blobs={'o2':image.read_bytes(),'o0':o0.read_bytes(),'sub':elf.read_bytes()}
 readers={'o2':lambda at,n:blobs['o2'][at-0x570000:at-0x570000+n], 'o0':lambda at,n:blobs['o0'][at-0x370000:at-0x370000+n], 'sub':elf_reader(blobs['sub'])}
 entries={};audits=[]
 for group,addresses in [('o2',(0x5be9a0,0x5d9960,0x5d9790,0x5d9dd0,0x5817a0,0x5819c0,0x581a50,0x6b3090,0x6b3020,0x6b2fa0)),('o0',(0x370500,0x370570)),('sub',(0x1900e0,0x191430))]:
  directory=ROOT/('recomp/config/output' if group=='sub' else 'recomp/config/output_ovl/'+group)
  for at in addresses:
   path=next(directory.glob(f'{group}_{at:08X}_*.cpp'));text=path.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
   audits.append(compare_source('camera modes/tasks',path.relative_to(ROOT).as_posix(),at,end,readers[group]));entries[at]=path
 body='\n'.join(path.read_text() for path in entries.values());old=(base/'functions.h').read_text();actual=set(re.findall(r'\bvoid ((?:sub|o0|o2)_[A-Za-z0-9_]+)\(',body));existing=set(re.findall(r'\bvoid ((?:sub|o0|o2)_[A-Za-z0-9_]+)\(',old));called=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body))
 missing=called-actual-existing
 ports={0x573890:'allocation observation',0x573740:'retirement observation',0x616f60:'floor material observation'}
 assert all(int(name.split('_')[-1],16) in ports for name in missing),sorted(missing)
 out.mkdir();
 for name in ('reference.hpp','ps2_fpu_convert.h','ps2_runtime.h','ps2_runtime_macros.h','ps2_recompiled_functions.h','o0_functions.h','o2_functions.h','ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h'):(out/name).write_bytes((base/name).read_bytes())
 declarations=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(actual-existing))
 declarations+=''.join('inline void '+name+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){c->pc='+name.split('_')[-1]+';original_transform_port(m,c,r);}\n' for name in sorted(missing))
 declarations+='void mode_port_allocate(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid mode_port_retire(std::uint8_t*,R5900Context*,PS2Runtime*);\nvoid mode_port_floor(std::uint8_t*,R5900Context*,PS2Runtime*);\n'
 (out/'functions.h').write_text(old+declarations)
 dispatch=(base/'original_dispatch.hpp').read_text()+''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n' for at,path in entries.items())
 dispatch+='case 0x573890:mode_port_allocate(memory,context,runtime);return;\ncase 0x573740:mode_port_retire(memory,context,runtime);return;\ncase 0x616f60:mode_port_floor(memory,context,runtime);return;\n'
 (out/'original_dispatch.hpp').write_text(dispatch)
 constants=(base/'owned_constants.hpp').read_text();assert constants.rstrip().endswith('}')
 constants=constants.rstrip()[:-1]
 for at,size in ((0x70b490,48),(0x70b4c0,52),(0x70b500,48),(0x70b530,2),(0x70b540,48),(0x70b570,36),(0x70b5a0,40),(0x70b5c8,16)):
  data=readers['o2'](at,size);constants+='{const std::uint8_t data[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',data,sizeof data);}\n'
 (out/'owned_constants.hpp').write_text(constants+'}\n')
 (out/'original_modes.cpp').write_text(body)
 ninja=(build/'build.ninja').read_text();at=ninja.index('build gameplay_application/native_session_tests.exe:');libs=shlex.split(re.search(r'^  LINK_LIBRARIES = (.*)$',ninja[at:],re.M).group(1))
 source=ROOT/'game/native/gameplay_scenario/room_camera_modes.cpp';scene_source=ROOT/'game/native/gameplay_scenario/room_scene_owner.cpp';fixture=ROOT/'tools/native_reconstruction/room_camera_modes_tests.cpp';exe=out/'checks.exe'
 receipt_path=a.build_receipt.resolve() if a.build_receipt else None
 built=json.loads(receipt_path.read_text()) if receipt_path else None
 if built:
  assert built['status']=='passed' and built['compiler_sha256']==sha(COMPILER)
  assert not built['source_drift'] and not built['archive_drift']
  for f in (source,scene_source):assert f.relative_to(ROOT).as_posix() in built['sources_sha256']
  for lib in libs:
   if lib.endswith('.a'):assert lib in built['archives_sha256'],lib
  def verify_build():
   source_drift=[p for p,v in built['sources_sha256'].items() if not (ROOT/p).is_file() or sha(ROOT/p)!=v]
   archive_drift=[p for p,v in built['archives_sha256'].items() if not (build/p).is_file() or sha(build/p)!=v]
   if source_drift or archive_drift:raise RuntimeError('Build receipt drift: '+str((source_drift,archive_drift)))
  verify_build()
 env=dict(os.environ,PATH=str(COMPILER.parent)+os.pathsep+os.environ.get('PATH',''))
 flags=[str(COMPILER),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(ROOT),'-I'+str(ROOT/'tools/native_reconstruction')]
 record={'status':'failed','compiler_sha256':sha(COMPILER),'native_source_sha256':sha(source),'scene_source_sha256':sha(scene_source),'fixture_sha256':sha(fixture),'original_word_audits':audits,'parent_camera_receipt_sha256':sha(base/'receipt.json'),'ports':ports,'checks':[],
  'build_receipt_sha256':sha(receipt_path) if receipt_path else None,'archive_sha256':{lib:sha(build/lib) for lib in libs if lib.endswith('.a')},
  'original_assets_sha256':{'o2':sha(image),'o0':sha(o0),'elf':sha(elf)}}
 def run(name,cmd):
  started=time.monotonic();result=subprocess.run(cmd,cwd=build,env=env,capture_output=True,timeout=180);(out/(name+'.stdout.txt')).write_bytes(result.stdout);(out/(name+'.stderr.txt')).write_bytes(result.stderr);record['checks'].append({'name':name,'exit':result.returncode,'seconds':round(time.monotonic()-started,3)})
  if result.returncode:raise RuntimeError(name+': '+result.stderr.decode(errors='replace')[-5000:])
  return result.stdout
 try:
  run('original',flags+['-w','-c',str(out/'original_modes.cpp'),'-o',str(out/'original_modes.o')])
  run('fixture',flags+['-c',str(fixture),'-o',str(out/'fixture.o')])
  fresh=[]
  if not built:
   run('native',flags+['-c',str(source),'-o',str(out/'native.o')]);fresh.append(str(out/'native.o'))
   run('scene',flags+['-c',str(scene_source),'-o',str(out/'scene.o')]);fresh.append(str(out/'scene.o'))
  run('link',[str(COMPILER),str(base/'original.o'),str(out/'original_modes.o'),str(out/'fixture.o'),*fresh,*libs,'-o',str(exe)])
  archive='C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/NETBIO00.DAT'
  record['result']=json.loads(run('test',[str(exe),archive]));assert sha(source)==record['native_source_sha256'] and sha(scene_source)==record['scene_source_sha256'] and sha(fixture)==record['fixture_sha256']
  assert all(sha(build/lib)==value for lib,value in record['archive_sha256'].items())
  if built:verify_build()
  record['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['result']))
if __name__=='__main__':main()
