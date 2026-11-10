"""Compare real resource use, quantity and inventory-content consumers."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from effect_work_sources import SURFACE_WORLD_UNITS
from comparison_objects import compile_objects
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();entries={};proof=[]
 for at in [0x5b3aa0,0x5b3b80,0x5b4e60,0x5f2210,0x5921d0,0x5919f0,0x1b02d0]:
  bank='sub'if at<0x370000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/o2');file=next(folder.glob(f'{bank}_{at:08X}_*'));name=file.relative_to(ROOT).as_posix();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',file.read_text())[1],16);proof.append(compare_source('complete resource use/query or actual template import body',name,at,end,read if bank=='sub'else lambda x,n:raw[x-0x570000:x-0x570000+n]));entries[at]=name
 getter='recomp/config/output/sub_001B0300_0x1b0300.cpp';proof.append(compare_source('exact three-word raw mode getter; implemented as a declared bounded value port',getter,0x1b0300,0x1b030c,read))
 units=list(dict.fromkeys(SURFACE_WORLD_UNITS+['game/native/'+n for n in ['gameplay_world/resource_use.cpp','gameplay_world/resource_models.cpp','gameplay_world/model_attachments.cpp','gameplay_world/resource_frames.cpp','gameplay_world/resource_programs.cpp','gameplay_world/inventory.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','gameplay_scenario/periodic_effects.cpp','gameplay_scenario/scene_controls.cpp','gameplay_scenario/flags.cpp','gameplay_tasks/tasks.cpp','gameplay_actors/entity.cpp','gameplay_session/session.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','animation/weapon_program.cpp','transform_math/transform_math.cpp']]))
 fixture='tools/native_reconstruction/resource_use_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files=list(dict.fromkeys(units+list(entries.values())+[getter,fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),'tools/native_reconstruction/effect_work_sources.py','tools/native_reconstruction/comparison_objects.py','game/native/gameplay_world/CMakeLists.txt']))
 for name in files:
  if name.startswith('game/native/')and name.endswith(('.cpp','.hpp','.inc')):
   for inc in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
    local=((ROOT/name).parent/inc).resolve();target=local if local.is_file()else(ROOT/inc).resolve();assert target.is_file()and target.is_relative_to(ROOT),(name,inc);n=target.relative_to(ROOT).as_posix()
    if n not in files:files.append(n)
 frozen={n:(ROOT/n).read_bytes()for n in files};out.mkdir(parents=True)
 for n,b in frozen.items():target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b)
 reference=frozen[helper].decode().replace('Register r[32];','Register r[32];std::uint64_t lo{},hi{};')+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n';(out/'reference.hpp').write_text(reference);body='\n'.join(frozen[n].decode()for n in entries.values());(out/'original.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n'for at,n in entries.items()))
 for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
 for n in ['o2_functions.h','ps2_recompiled_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
 for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';selected=[m for m in json.loads(inventory.read_bytes())if any(n.lower().startswith('item')and n.lower().endswith('.dat')for n in m.get('names',[]))];assert len(selected)==5
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as iso,(out/'owned_templates.bin').open('wb')as data:
  data.write(struct.pack('<I',len(selected)))
  for member in selected:
   iso.seek(member['iso_offset']);payload=iso.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];at,n=struct.unpack_from('<II',payload);assert at+n<=len(payload);data.write(struct.pack('<I',n)+payload[at:at+n])
 cc=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');exe=out/'use.exe';flags=['-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')];record={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'template_members':selected,'declared_ports':['107C68/107AB0 bounded clearing/copying','1B0300 exact raw mode byte3243F2 getter'],'limitations':['Value payloads do not claim arbitrary original pointer-alias profiles.','Higher-level use/recipe/transfer callers and actual game installation remain open.']}
 try:
  objects,object_receipts=compile_objects(ROOT,out,cc,flags,units,frozen,env);record['production_objects']=object_receipts;cmd=[str(cc),*flags,*objects,str(out/'source'/fixture),'-o',str(exe)];record['command']=cmd
  for label,command in [('compile',cmd),('run',[str(exe),str(out/'owned_templates.bin')])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':record['observed']=json.loads(result.stdout)
  record['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(exe))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
