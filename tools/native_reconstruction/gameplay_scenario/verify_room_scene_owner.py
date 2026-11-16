"""Full original room initializer and math chain versus native typed owners."""
import argparse,hashlib,json,os,re,shlex,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--native-build',type=Path);p.add_argument('--build-receipt',type=Path);p.add_argument('--immutable-snapshot',type=Path);a=p.parse_args();out=a.output.resolve();cc=a.compiler.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');assert bool(a.native_build)==bool(a.build_receipt);out.mkdir()
 snapshot=a.immutable_snapshot.resolve() if a.immutable_snapshot else None
 if snapshot:
  frozen=json.loads((snapshot/'receipt.json').read_text());assert frozen['status']=='passed' and sha(snapshot/'cohort.json')==frozen['cohort_sha256']
  assert all(sha(snapshot/'source'/name)==digest for name,digest in frozen['source_sha256'].items())
  a.native_build=snapshot/'native-build';a.build_receipt=snapshot/'cohort.json'
 def selected(name):return snapshot/'source'/name if snapshot and name.startswith('game/native/')else ROOT/name
 def logical(path):return path.relative_to(snapshot/'source').as_posix() if snapshot and path.is_relative_to(snapshot/'source')else path.relative_to(ROOT).as_posix()
 expected={'main':'06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46','o2':'45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226','o0':'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'};reads={}
 for kind,h in expected.items():
  path=ROOT/('game_data/SLUS_207.65'if kind=='main'else f'build-function-index/owned-overlays/{kind}.bin');assert sha(path)==h;data=path.read_bytes();reads[kind]=elf_reader(data)if kind=='main'else lambda at,n,data=data,kind=kind:data[at-(0x370000 if kind=='o0'else 0x570000):at-(0x370000 if kind=='o0'else 0x570000)+n]
 ids={'o2':[0x5819c0,0x5c1120,0x5c11b0,0x5c12a0,0x5c1390,0x5c45c0,0x5c5d30,0x5c6100,0x5c66c0],'o0':[0x370500,0x370570],'main':[0x1900e0,0x191430,0x1919d0,0x1920a0]};names=[];texts=[];proof=[];authorities={}
 for kind,entries in ids.items():
  for at in entries:
   prefix='sub'if kind=='main'else kind;path=ROOT/(f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp'if kind=='main'else f'recomp/config/output_ovl/{kind}/{kind}_{at:08X}_0x{at:x}.cpp');t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('complete room initializer/model helper',path.relative_to(ROOT).as_posix(),begin,end,reads[kind]));authorities[path.relative_to(ROOT).as_posix()]=sha(path);texts.append('\n'.join(l for l in t.splitlines()if not l.startswith('#include')));names.append(f'{prefix}_{at:08X}_0x{at:x}')
 path=ROOT/'recomp/config/output/sub_00195E50_0x195e50.cpp';t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('initialized identity cache static authority, not dynamically executed',path.relative_to(ROOT).as_posix(),begin,end,reads['main']));authorities[path.relative_to(ROOT).as_posix()]=sha(path)
 fixture=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';t=fixture.read_text().replace('Function lookupFunction(std::uint32_t)const noexcept{return original_transform_port;}','Function lookupFunction(std::uint32_t)const;');t+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n#include "word_conversion.hpp"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n#define FPU_ABS_S(a) std::abs(a)\n#define FPU_DIV_S(a,b) (float(a)/float(b))\n';(out/'original_fixture.hpp').write_text(t);shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'word_conversion.hpp')
 body='\n'.join(texts);allnames=sorted(set(re.findall(r'\b((?:sub|o2|o0)_[A-Za-z0-9_]+)\(',body)));(out/'original_declarations.inc').write_text('\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);'for n in allnames)+'\n');body+='\n'+'\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*){{throw std::runtime_error("Unadmitted room dependency {n}");}}'for n in allnames if n not in names);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+body);(out/'original_lookup.inc').write_text('\n'.join('case '+n.split('_')[-1]+':return '+n+';'for n in names)+'\n')
 init='inline void owned_room_constants(std::uint8_t* p){\n'
 for at,n in [(0x70a740,14),(0x73e860,56)]:
  data=reads['o2'](at,n);init+=f'const std::array<std::uint8_t,{n}> c{at}{{'+','.join(str(v)for v in data)+f'}};std::memcpy(p+{at},c{at}.data(),{n});\n'
 init+='const std::array<std::uint32_t,16> identity{0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000};std::memcpy(p+0x294e00,identity.data(),64);\n';(out/'owned_constants.hpp').write_text(init+'}\n')
 units=[ROOT/'game/native/gameplay_scenario'/n for n in ['room_scene_input.cpp','room_scene_owner.cpp','scene_controls.cpp','scene_models.cpp','scene_model_bindings.cpp','scene_matrix_programs.cpp','scene_matrix_playback.cpp','scene_matrix_tables.cpp','content.cpp','flags.cpp']]+[ROOT/'game/native/gameplay_collision'/n for n in ['collision.cpp','response.cpp','sweep.cpp','actors.cpp','ownership.cpp']]+[ROOT/'game/native/gameplay_session/session.cpp',ROOT/'game/native/gameplay_actors/entity.cpp',ROOT/'game/native/transform_math/transform_math.cpp']
 units=[selected(path.relative_to(ROOT).as_posix())for path in units]
 sources=units+[HERE/'room_scene_owner_tests.cpp',HERE/'control_vm_fixture.inc',Path(__file__),fixture,ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];pending=list(sources);closure=set(sources)
 while pending:
  path=pending.pop()
  for name in re.findall(r'#include "([^"\n]+)"',path.read_text()):
   inc=next((p.resolve()for p in [path.parent/name,*([snapshot/'source'/name]if snapshot else[]),ROOT/name]if p.exists()),None)
   if inc and inc not in closure:closure.add(inc);pending.append(inc)
 hashes={logical(p):sha(p)for p in sorted(closure)}
 for name in hashes|authorities:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(selected(name).read_bytes())
 (out/'control_export.inc').write_text((HERE/'control_vm_fixture.inc').read_text().split('struct ControlFixture')[0]);shutil.copyfile(HERE/'room_scene_owner_tests.cpp',out/'tests.cpp')
 corpus=ROOT/'build-native-sjuni/gameplay-room-scene-assets-v1';cr=json.loads((corpus/'receipt.json').read_text());assert cr['status']=='passed'and cr['package_sha256']==sha(corpus/'room_scene_inputs.bin');shutil.copyfile(corpus/'room_scene_inputs.bin',out/'room_scene_inputs.bin')
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');base=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out)];commands=[('original',base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')])]
 build=a.native_build.resolve() if a.native_build else None;build_receipt=a.build_receipt.resolve() if a.build_receipt else None
 built=json.loads(build_receipt.read_text()) if build_receipt else None;archives={}
 if built:
  assert built['status']=='passed' and built['compiler_sha256']==sha(cc) and not built['source_drift'] and not built['archive_drift']
  ninja=(build/'build.ninja').read_text();pos=ninja.index('build gameplay_application/native_session_tests.exe:');libs=shlex.split(re.search(r'^  LINK_LIBRARIES = (.*)$',ninja[pos:],re.M).group(1))
  for lib in libs:
   if lib.endswith('.a'):assert lib in built['archives_sha256'];archives[lib]=sha(build/lib);assert archives[lib]==built['archives_sha256'][lib]
  if snapshot:assert all(built['sources_sha256'][name]==digest for name,digest in hashes.items()if name.startswith('game/native/'))
  else:assert all(sha(ROOT/name)==digest for name,digest in built['sources_sha256'].items())
  commands.append(('fixture',base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(out/'tests.cpp'),'-o',str(out/'fixture.o')]))
  link=[str(cc),str(out/'original.o'),str(out/'fixture.o'),*[str(build/lib) if lib.endswith('.a') else lib for lib in libs],'-o',str(out/'checks.exe')]
 else:
  for i,path in enumerate(units+[out/'tests.cpp']):commands.append((str(i),base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path if path.is_relative_to(out)else out/'source'/path.relative_to(ROOT)),'-o',str(out/f'{i}.o')]))
  link=[str(cc),str(out/'original.o'),*[str(out/f'{i}.o')for i in range(len(units)+1)],'-o',str(out/'checks.exe')]
 commands+=[('link',link),('run',[str(out/'checks.exe'),str(out/'room_scene_inputs.bin')])];receipt=dict(status='failed',qualification_scope='immutable_cohort_source_header_and_archive_snapshot'if snapshot else'current_source_and_shared_archives',immutable_snapshot=str(snapshot.relative_to(ROOT))if snapshot else None,compiler=str(cc),compiler_sha256=sha(cc),source_sha256=hashes,original_source_sha256=authorities,original_word_audits=proof,owned_image_sha256=expected,checks=[],game_launched=False,live_process_access=False,installed_in_game=False,asset_corpus=dict(receipt=(corpus/'receipt.json').relative_to(ROOT).as_posix(),receipt_sha256=sha(corpus/'receipt.json'),package_sha256=cr['package_sha256']),build_receipt_sha256=sha(build_receipt) if build_receipt else None,archives_sha256=archives)
 try:
  for name,cmd in commands:
   r=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/f'{name}.stdout.txt').write_text(r.stdout);(out/f'{name}.stderr.txt').write_text(r.stderr);receipt['checks'].append(dict(label=name,exit_code=r.returncode,command=cmd));assert r.returncode==0,name+': '+r.stderr[-4000:]
  receipt['result']=json.loads((out/'run.stdout.txt').read_text());assert all(sha(selected(n))==v for n,v in hashes.items());assert all(sha(build/name)==digest for name,digest in archives.items())
  if built and not snapshot:assert all(sha(ROOT/name)==digest for name,digest in built['sources_sha256'].items())
  receipt.update(status='passed',executable_sha256=sha(out/'checks.exe'))
 finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
 print(json.dumps(receipt.get('result',{})))
if __name__=='__main__':main()
