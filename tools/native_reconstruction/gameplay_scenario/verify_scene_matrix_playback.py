"""Complete matrix-program playback chains against independently owned instructions."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--pin-scenario-commit');a=p.parse_args();cc=a.compiler.resolve();out=a.output.resolve();assert cc.exists()and not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 pinned={}
 if a.pin_scenario_commit:
  for name in ['game/native/gameplay_scenario/scene_controls.hpp','game/native/gameplay_scenario/scene_controls.cpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp']:
   pinned[name]=subprocess.run(['git','show',a.pin_scenario_commit+':'+name],cwd=ROOT,capture_output=True,check=True).stdout
 def content(path):
  name=path.relative_to(ROOT).as_posix()
  own={'scene_models.cpp','scene_models.hpp','scene_matrix_programs.hpp','scene_matrix_programs.cpp','scene_matrix_playback.cpp','scene_matrix_tables.hpp','scene_matrix_tables.cpp','scene_matrix_program_tables.inc'}
  if a.pin_scenario_commit and name.startswith('game/native/') and path.name not in own and name not in pinned:
   pinned[name]=subprocess.run(['git','show',a.pin_scenario_commit+':'+name],cwd=ROOT,capture_output=True,check=True).stdout
  return pinned.get(name,path.read_bytes())
 images={};reads={};authorities={};expected={'main':'06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46','o2':'45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226','o0':'bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'}
 for kind in expected:
  path=ROOT/('game_data/SLUS_207.65'if kind=='main'else f'build-function-index/owned-overlays/{kind}.bin');assert sha(path)==expected[kind];images[kind]=path.read_bytes();reads[kind]=elf_reader(images[kind])if kind=='main'else lambda at,n,kind=kind:images[kind][at-(0x370000 if kind=='o0'else 0x570000):at-(0x370000 if kind=='o0'else 0x570000)+n]
 ids={'o2':[0x6b4ba0,0x6b5760,0x6b5920,0x6b5ab0,0x6b5c60,0x6b5e10,0x6b5050,0x5819c0,0x5d8280],'o0':[0x370320],'main':[0x18f570,0x18fdf0,0x18fe20,0x1902d0,0x191380,0x1919d0,0x191ef0,0x191f80]};texts=[];proof=[];original_names=[]
 for kind,entries in ids.items():
  for at in entries:
   prefix='sub'if kind=='main'else kind;path=ROOT/(f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp'if kind=='main'else f'recomp/config/output_ovl/{kind}/{kind}_{at:08X}_0x{at:x}.cpp');t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('complete scene-matrix chain',path.relative_to(ROOT).as_posix(),begin,end,reads[kind]));authorities[path.relative_to(ROOT).as_posix()]=sha(path);texts.append('\n'.join(l for l in t.splitlines()if not l.startswith('#include')));original_names.append(f'{prefix}_{at:08X}_0x{at:x}')
 path=ROOT/'recomp/config/output/sub_00195E50_0x195e50.cpp';t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('required initialized identity cache authority',path.relative_to(ROOT).as_posix(),begin,end,reads['main']));authorities[path.relative_to(ROOT).as_posix()]=sha(path)
 for at in [0x5d7d60,0x5d7ed0,0x5d7f00]:
  path=ROOT/f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('sixteen-channel reset/service ownership authority',path.relative_to(ROOT).as_posix(),begin,end,reads['o2']));authorities[path.relative_to(ROOT).as_posix()]=sha(path)
 fixture_path=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';fixture=fixture_path.read_text().replace('Function lookupFunction(std::uint32_t)const noexcept{return original_transform_port;}','Function lookupFunction(std::uint32_t)const;')
 fixture+='\ntemplate<class T>T fixture_read(const std::uint8_t* p,std::uint32_t a){return transform_read<T>(p,a);}\ntemplate<class T>void fixture_write(std::uint8_t* p,std::uint32_t a,T value){transform_write(p,a,value);}\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(std::int32_t(a)>>(std::uint32_t(b)&31)))\n#include "word_conversion.hpp"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n#define FPU_DIV_S(a,b) (float(a)/float(b))\n'
 (out/'original_fixture.hpp').write_text(fixture);shutil.copyfile(ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',out/'word_conversion.hpp');body='\n'.join(texts);names=sorted(set(re.findall(r'\b((?:sub|o2|o0)_[A-Za-z0-9_]+)\(',body)));(out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);'for n in names)+'\n');body+='\n'+'\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted original matrix dependency '+n+'");}'for n in names if n not in original_names);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+body);(out/'original_lookup.inc').write_text('\n'.join('case '+n.split('_')[-1]+':return '+n+';'for n in original_names))
 init='inline void owned_matrix_constants(std::uint8_t* p){\n'
 for kind,at,n in [('main',0x22fe20,32),('main',0x241c78,32),('o2',0x70b190,4),('o2',0x720380,0x2010)]:
  data=reads[kind](at,n);init+='const std::array<std::uint8_t,'+str(n)+'> c'+str(at)+'{'+','.join(str(v)for v in data)+'};std::memcpy(p+'+str(at)+',c'+str(at)+'.data(),'+str(n)+');\n'
 init+='const std::array<std::uint32_t,16> identity{0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000,0,0,0,0,0x3f800000};std::memcpy(p+0x294e00,identity.data(),64);\n'
 (out/'owned_constants.hpp').write_text(init+'}\n')
 units=[ROOT/'game/native/gameplay_scenario'/n for n in ['scene_matrix_playback.cpp','scene_matrix_programs.cpp','scene_matrix_tables.cpp','scene_model_bindings.cpp','scene_models.cpp','content.cpp','flags.cpp','scene_controls.cpp']]+[ROOT/'game/native/gameplay_session/session.cpp',ROOT/'game/native/gameplay_actors/entity.cpp',ROOT/'game/native/transform_math/transform_math.cpp'];sources=units+[HERE/'scene_matrix_playback_tests.cpp',HERE/'control_vm_fixture.inc',Path(__file__),fixture_path,ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',ROOT/'game/native/gameplay_scenario/scene_matrix_program_tables.inc'];pending=list(sources);closure=set(p.resolve()for p in sources)
 while pending:
  p=pending.pop()
  for name in re.findall(r'#include "([^"\n]+)"',content(p).decode()):
   found=next((q.resolve()for q in [p.parent/name,ROOT/name]if q.exists()),None)
   if found and found.is_relative_to(ROOT/'game/native')and found not in closure:closure.add(found);pending.append(found)
 before={p.relative_to(ROOT).as_posix():hashlib.sha256(content(p)).hexdigest()for p in sorted(closure)}
 for name in before|authorities:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes(content(ROOT/name))
 shutil.copyfile(HERE/'control_vm_fixture.inc',out/'control_vm_fixture.inc');shutil.copyfile(HERE/'scene_matrix_playback_tests.cpp',out/'tests.cpp');env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');base=[str(cc),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(out)];commands=[('original',base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')])]
 for i,path in enumerate([out/'source'/p.relative_to(ROOT)for p in units]+[out/'tests.cpp']):commands.append((str(i),base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(str(i)+'.o'))]))
 commands+=[('link',[str(cc),str(out/'original.o')]+[str(out/(str(i)+'.o'))for i in range(len(units)+1)]+['-o',str(out/'checks.exe')]),('run',[str(out/'checks.exe')])];record=dict(status='failed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=authorities,owned_image_sha256=expected,original_word_audits=proof,pinned_shared_commit=a.pin_scenario_commit,pinned_sources_sha256={n:before[n]for n in pinned if n in before},initialized_identity_cache_required=True,identity_authority='00195E50',game_launched=False,live_process_access=False,installed_in_game=False,sound_request_fixture_seam='6B60E0 arguments captured; room sound resolver and actual audio consumer remain open',checks=[])
 try:
  for label,cmd in commands:
   result=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr);record['checks'].append(dict(label=label,exit_code=result.returncode,command=cmd));assert result.returncode==0,label+': '+result.stderr[-4000:]
  record['result']=json.loads((out/'run.stdout.txt').read_text());assert all(sha(ROOT/n)==h for n,h in before.items()if n not in pinned);record['current_pinned_source_drift']={n:sha(ROOT/n)for n,h in before.items()if n in pinned and sha(ROOT/n)!=h};record.update(status='passed',executable_sha256=sha(out/'checks.exe'))
 finally:(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record.get('result',{})))
if __name__=='__main__':main()
