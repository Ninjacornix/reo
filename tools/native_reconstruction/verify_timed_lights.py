"""Complete timed-light bodies against native shared light/task/world owners."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
from effect_work_sources import SURFACE_WORLD_UNITS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());banks={}
 for name,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
  file=ROOT/'build-function-index/owned-overlays'/f'{name}.bin';assert sha(file)==digest;banks[name]=file.read_bytes()
 entries={};proof=[]
 for at in [0x6b2680,0x6b2760,0x5d85e0,0x6b3090,0x6b2fa0,0x6b3020,0x192190,0x18f340]:
  bank='sub'if at<0x370000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/o2');file=next(folder.glob(f'{bank}_{at:08X}_*'));name=file.relative_to(ROOT).as_posix();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',file.read_text())[1],16);reader=read if bank=='sub'else lambda x,n:banks['o2'][x-0x570000:x-0x570000+n];proof.append(compare_source('complete timed light construction/update/retirement or shared helper',name,at,end,reader));entries[at]=name
 combined='tools/native_reconstruction/timed_light_byte_angle_oracle.inc';proof.append(compare_source('exact370080..3700BF helper extracted from older combined source with explicit delay-slot comments',combined,0x370080,0x3700c0,lambda x,n:banks['o0'][x-0x370000:x-0x370000+n]))
 units=list(dict.fromkeys(SURFACE_WORLD_UNITS+['game/native/'+n for n in ['gameplay_lighting/lights.cpp','gameplay_lighting/timed_lights.cpp','gameplay_scenario/lighting.cpp','gameplay_scenario/scene_resources.cpp','gameplay_scenario/resource_templates.cpp','gameplay_tasks/tasks.cpp','gameplay_actors/entity.cpp','gameplay_session/session.cpp','animation/model.cpp','animation/model_math.cpp','animation/curves.cpp','transform_math/transform_math.cpp']]))
 fixture='tools/native_reconstruction/timed_lights_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files=list(dict.fromkeys(units+list(entries.values())+[combined,fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),'tools/native_reconstruction/effect_work_sources.py','game/native/gameplay_lighting/CMakeLists.txt']))
 for name in files:
  if name.startswith('game/native/')and name.endswith(('.cpp','.hpp','.inc')):
   for inc in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
    target=((ROOT/name).parent/inc).resolve();target=target if target.is_file()else(ROOT/inc).resolve();assert target.is_file()and target.is_relative_to(ROOT),(name,inc);relative=target.relative_to(ROOT).as_posix()
    if relative not in files:files.append(relative)
 frozen={n:(ROOT/n).read_bytes()for n in files};out.mkdir(parents=True)
 for n,b in frozen.items():target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b)
 reference=frozen[helper].decode()+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define AND32(a,b) (std::uint32_t(a)&std::uint32_t(b))\n#define OR32(a,b) (std::uint32_t(a)|std::uint32_t(b))\n';(out/'reference.hpp').write_text(reference)
 extracted=frozen[combined].decode();body='\n'.join(frozen[n].decode().replace('case 0x5d871cu: goto label_5d871c;','case 0x5d8620u: goto label_5d8630;\n        case 0x5d871cu: goto label_5d871c;')for n in entries.values())+'\n'+extracted;(out/'original.cpp').write_text(body)
 actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+='void oracle_370080(std::uint8_t*,R5900Context*,PS2Runtime*);\n';decl+=''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n'for at,n in entries.items())+'case 0x5d8620:o2_005D85E0_0x5d85e0(memory,context,runtime);return;\ncase 0x370080:oracle_370080(memory,context,runtime);return;\n')
 for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
 for n in ['o2_functions.h','ps2_recompiled_functions.h','ps2_overlay_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
 for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
 constants='inline void owned_constants(std::uint8_t* memory){'
 for at,n,blob,base in [(0x22fe20,32,None,0),(0x241c78,32,None,0),(0x38b298,4,banks['o0'],0x370000),(0x7202c0,52,banks['o2'],0x570000),(0x720300,52,banks['o2'],0x570000),(0x73eb18,24,banks['o2'],0x570000)]:
  values=read(at,n)if blob is None else blob[at-base:at-base+n];constants+='{const std::uint8_t bytes[]{'+','.join(str(v)for v in values)+'};std::memcpy(memory+'+str(at)+',bytes,sizeof bytes);}'
 (out/'owned_constants.hpp').write_text(constants+'}\n');cc=COMPILERS[a.compiler];exe=out/'timed.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'source'/fixture),'-o',str(exe)];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');record={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'extracted_helper_sha256':hashlib.sha256(extracted.encode()).hexdigest(),'declared_ports':['107C68/107AB0 bounded pool clearing/copying','573890 captured scheduler admission,573740 captured retirement; native uses actual canonical Scheduler, not a stub'],'modernization_deviations':['Full light pool rolls back the new task and reports failure instead of retaining a task that writes through null.','Retired actor/light capabilities cannot retarget reused physical storage; tasks retire safely.'],'command':cmd}
 record['entry_routing']={'5D8620':'Test entry shim skips only its unconditional branch and two nop words, entering the already included complete5D8630 body; the entire source interval is instruction-audited.'};record['ungated_template_sha256']=hashlib.sha256(banks['o2'][0x720300-0x570000:0x720300-0x570000+52]).hexdigest();assert record['ungated_template_sha256']=='03e9cda8ccd43b532c8a36c5335c2301758af65b531424c740c03a8d1d78b962'
 try:
  for label,command in [('compile',cmd),('run',[str(exe)])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=150);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':record['observed']=json.loads(result.stdout)
  record['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(exe))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
