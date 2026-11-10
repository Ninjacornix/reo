"""Compare the native cooperative evidence pool with complete owned originals."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--statistics',action='store_true');p.add_argument('--automatic',action='store_true');p.add_argument('--publication',action='store_true');p.add_argument('--actor-status',action='store_true');p.add_argument('--actor-actions',action='store_true');p.add_argument('--actor-inventory',action='store_true');p.add_argument('--actor-state',action='store_true');p.add_argument('--actor-activity',action='store_true');p.add_argument('--actor-gauge',action='store_true');p.add_argument('--actor-hit-gauge',action='store_true');p.add_argument('--actor-snapshot',action='store_true');a=p.parse_args();a.actor_hit_gauge|=a.actor_snapshot;a.actor_gauge|=a.actor_hit_gauge;a.actor_activity|=a.actor_gauge;a.actor_state|=a.actor_activity;a.actor_inventory|=a.actor_state;a.actor_actions|=a.actor_inventory;a.actor_status|=a.actor_actions;a.publication|=a.actor_status;a.automatic|=a.publication;a.statistics|=a.automatic;out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 image=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(image)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';raw=image.read_bytes();entries={};proof=[]
 addresses=[0x37bfb0,0x37c060,0x37c170,0x37c200,0x37c2c0,0x37c3b0]+([0x37b990,0x37bbc0,0x37c470,0x1b02d0]if a.statistics else[])
 if a.automatic:
  overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';o2=overlay.read_bytes();addresses += [0x37baf0,0x37bca0,0x666080,0x5709b0]
 if a.publication:addresses += [0x67dbd0,0x1b0310,0x1afdd0]
 if a.actor_status:addresses += [0x67e230,0x6605b0,0x1b0240]
 if a.actor_state:addresses += [0x664d00,0x664f60,0x667f90,0x668c80]
 if a.actor_gauge:addresses += [0x660060,0x667e90,0x668050,0x668110,0x1b0340]
 if a.actor_hit_gauge:addresses += [0x660af0,0x666620,0x666d90]
 if a.statistics:
  elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 for at in addresses:
  bank='sub'if at<0x370000 else'o0'if at<0x570000 else'o2';folder=ROOT/('recomp/config/output'if bank=='sub'else'recomp/config/output_ovl/'+bank);source=next(folder.glob(f'{bank}_{at:08X}_*'));name=source.relative_to(ROOT).as_posix();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16);proof.append(compare_source('complete cooperative event pool/admission/pruning or completion body',name,at,end,read if bank=='sub'else (lambda x,n:o2[x-0x570000:x-0x570000+n])if bank=='o2'else lambda x,n:raw[x-0x370000:x-0x370000+n]));entries[at]=name
 field_sources=[]
 if a.actor_snapshot:
  for entry,first,last in [(0x5f2b70,0x5f2b9c,0x5f2bbc),(0x586aa0,0x586b88,0x586bc8),(0x65ed70,0x65efd4,0x65f004),(0x5d76d0,0x5d7734,0x5d7758)]:
   name=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{entry:08X}_*')).relative_to(ROOT).as_posix();field_sources.append(name);proof.append(compare_source('primary actor item ID, pitch adjustment/base and target index provenance',name,first,last,lambda x,n:o2[x-0x570000:x-0x570000+n]))
 fixture='tools/native_reconstruction/cooperative_events_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';unit='game/native/gameplay_events/events.cpp';profile='game/native/gameplay_events/event_priority_profile.inc'
 files=[unit,'game/native/gameplay_events/events.hpp',profile,'game/native/gameplay_events/CMakeLists.txt','game/native/CMakeLists.txt',fixture,helper,Path(__file__).relative_to(ROOT).as_posix(),*entries.values(),*field_sources]
 if a.statistics:
  getter='recomp/config/output/sub_001B0300_0x1b0300.cpp';proof.append(compare_source('exact three-word raw-mode getter, ignored by completion caller',getter,0x1b0300,0x1b030c,read));files += [getter,'game/native/gameplay_events/statistics.hpp','game/native/gameplay_events/statistics.cpp','game/native/gameplay_events/scenario_event_rules.inc','tools/native_reconstruction/completion_statistics_tests.inc']
 if a.automatic:
  from gameplay_update_sources import UPDATE_UNITS
  files += UPDATE_UNITS+['tools/native_reconstruction/automatic_completion_tests.inc','tools/native_reconstruction/gameplay_update_sources.py','tools/native_reconstruction/comparison_objects.py']
  if a.publication:files += ['tools/native_reconstruction/scenario_publication_tests.inc']
  if a.actor_status:files += ['tools/native_reconstruction/actor_status_message_tests.inc']
  if a.actor_actions:files += ['tools/native_reconstruction/actor_action_message_tests.inc']
  if a.actor_inventory:files += ['tools/native_reconstruction/actor_inventory_message_tests.inc']
  if a.actor_state:files += ['tools/native_reconstruction/actor_state_message_tests.inc']
  if a.actor_activity:files += ['tools/native_reconstruction/actor_activity_binding_tests.inc']
  if a.actor_gauge:files += ['tools/native_reconstruction/actor_gauge_effects_tests.inc','game/native/gameplay_update/CMakeLists.txt']
  if a.actor_hit_gauge:files += ['tools/native_reconstruction/actor_hit_gauge_tests.inc']
  if a.actor_snapshot:files += ['tools/native_reconstruction/actor_snapshot_message_tests.inc']
  files=list(dict.fromkeys(files))
  for name in files:
   for inc in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
    if not name.startswith('game/native/'):continue
    local=((ROOT/name).parent/inc).resolve();target=local if local.is_file()else(ROOT/inc).resolve();assert target.is_file()and target.is_relative_to(ROOT),(name,inc);dep=target.relative_to(ROOT).as_posix()
    if dep not in files:files.append(dep)
 frozen={n:(ROOT/n).read_bytes()for n in files};priorities=bytes(int(v)for v in re.findall(r'\d+',frozen[profile].decode().split('\n',1)[1]));assert len(priorities)==39 and priorities==raw[0x389d30-0x370000:0x389d30-0x370000+39]
 out.mkdir(parents=True)
 for n,b in frozen.items():target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(b)
 (out/'reference.hpp').write_bytes(frozen[helper].replace(b'Register r[32];',b'Register r[32];std::uint64_t hi{},lo{};')+b'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::int32_t(a) >> (std::uint32_t(b)&31))\n');body='\n'.join(frozen[n].decode()for n in entries.values());(out/'original.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));(out/'functions.h').write_text('#pragma once\n'+''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in actual)+''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n'for n in names-actual));(out/'dispatch.inc').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n'for at,n in entries.items()))
 for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
 for n in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
 for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
 (out/'priorities.bin').write_bytes(priorities);cc=COMPILERS[a.compiler];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');exe=out/'events.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/unit),str(out/'source'/fixture),'-o',str(exe)];r={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'priority_prefix':{'address':'0x389d30','bytes':priorities.hex()},'command':cmd,'declared_ports':['107C68 bounded actual clearing'],'limitations':['Typed priority admission is the measured39-byte prefix; other IDs remain unavailable.','Native update/recipe caller binding is separate from this pool comparison.']}
 if a.statistics:
  import struct
  tables=re.findall(r'\{ // (0x[0-9a-f]+)\r?\n(.*?)\r?\n\s*\},',frozen['game/native/gameplay_events/scenario_event_rules.inc'].decode(),re.S);pointers=struct.unpack_from('<10I',raw,0x38a4d0-0x370000);assert len(tables)==10
  mapping=bytes(int(v)for v in re.search(r'mapping\{([^}]*)\}',frozen['game/native/gameplay_events/scenario_event_rules.inc'].decode())[1].split(','));assert mapping==raw[0x38a4a0-0x370000:0x38a4d0-0x370000]
  blocks=[]
  for (address,body),expected in zip(tables,pointers):
   assert int(address,16)==expected;rows=re.findall(r'\{(\d+),(\d+),(\d+),(\d+),(\d+),(\d+)\}',body);encoded=b''.join(struct.pack('<BB4H',*(int(v)for v in row))for row in rows);start=expected-0x370000;assert encoded==raw[start:start+len(encoded)]and raw[start+len(encoded)]==255;blocks.append((expected,raw[start:start+len(encoded)+10]))
  with (out/'scenario_rules.bin').open('wb')as data:
   data.write(struct.pack('<I',len(mapping))+mapping)
   for address,body in blocks:data.write(struct.pack('<II',address,len(body))+body)
  r['scenario_rules']={'mapping':mapping.hex(),'tables':[{'address':hex(at),'bytes':len(b),'sha256':hashlib.sha256(b).hexdigest()}for at,b in blocks]};r['declared_ports'].append('1B0300 exact three-word raw-mode getter3243F2; actual1B02D0 executes, caller ignores return');cmd.insert(1,'-DREO_COMPLETION_STATISTICS=1');cmd.insert(-2,str(out/'source/game/native/gameplay_events/statistics.cpp'))
 if a.automatic:
  from comparison_objects import compile_objects
  (out/'condition_switch.bin').write_bytes(raw[0x38cce0-0x370000:0x38cce0-0x370000+64]);r['condition_switch_sha256']=sha(out/'condition_switch.bin');r['automatic_worker_installed_in_native_owner']=True
  flags=cmd[1:cmd.index(str(out/'source'/unit))];flags += ['-DREO_AUTOMATIC_COMPLETION=1','-pthread','-fno-fast-math','-ffp-contract=off']
  if a.publication:flags += ['-DREO_SCENARIO_PUBLICATION=1']
  if a.actor_snapshot:flags += ['-DREO_ACTOR_SNAPSHOT_MESSAGE=1'];r['actor_snapshot_admission']='Complete67E230 selector1 with raw float XYZ, canonical action/aim/resource fields, actual gauge helpers and shared suppression word; unknown stack padding is not a native wire format'
  if a.actor_hit_gauge:flags += ['-DREO_ACTOR_HIT_GAUGE=1'];r['actor_hit_gauge_admission']='Actual native World/behavior/pending-hit/gauge/cooperative pool; complete660AF0 with actual660060/666620/666D90 for the controlled numeric80/800000 retained-action branch; UI/statistics/final contact effects are declared ports'
  if a.actor_gauge:flags += ['-DREO_ACTOR_GAUGE_EFFECTS=1'];r['actor_gauge_admission']='Complete660060/667E90/668050/1B0340 through actual Events and bound clock; complete pure668110 runs only at source caller argument100 and its discarded return is not projected'
  if a.actor_activity:flags += ['-DREO_ACTOR_ACTIVITY_BINDING=1'];r['actor_activity_admission']='Native World/BehaviorFrameServices/update_behavior/Owner/StatePublication composition at the actual66B500 activity stage; other frame/action effects are declared providers'
  if a.actor_state:flags += ['-DREO_ACTOR_STATE_MESSAGE=1'];r['actor_state_admission']='Complete664D00/664F60/667F90/668C80 and67E230 selector2; typed position/status/yaw and selected gauge band; actual bound update clock'
  if a.actor_inventory:flags += ['-DREO_ACTOR_INVENTORY_MESSAGE=1'];r['actor_inventory_admission']='67E230 selectors0/13 intentional no-message paths and4/10/12/15 typed interaction/pair/inventory payloads;18DBB0 is a bounded four-byte source-to-stack copy port'
  if a.actor_actions:flags += ['-DREO_ACTOR_ACTION_MESSAGE=1'];r['actor_action_admission']='Complete67E230 selector7, actual offline peer request mutations and typed captured payload; final mapped-room/message sinks remain declared ports'
  if a.actor_status:
   flags += ['-DREO_ACTOR_STATUS_MESSAGE=1'];(out/'actor_status_switch.bin').write_bytes(o2[0x740710-0x570000:0x740710-0x570000+64]+o2[0x740340-0x570000:0x740340-0x570000+40]);r['actor_status_switch_sha256']=sha(out/'actor_status_switch.bin');r['actor_message_admission']=('67E230 selectors0/4/7/10/12/13/14/15, typed known payloads and offline peer requests; remaining selectors stay open'if a.actor_inventory else'67E230 selectors7/14 and early gates, actual offline peer requests, all6605B0 low-byte clear selectors; remaining message selectors stay open'if a.actor_actions else'67E230 selector14 and its early gates, all6605B0 low-byte clear selectors; other message selectors remain open')
   with (out/'reference.hpp').open('a')as reference:reference.write('\ninline std::int32_t actor_message_unadmitted_conversion(float){throw std::runtime_error("Unadmitted actor message float conversion");}\n#define FPU_CVT_W_S(x) actor_message_unadmitted_conversion(x)\n')
   r['declared_ports'].append('Unentered67E230 selector5 float-conversion paths throw if reached; selectors1/2/14 execute no conversion')
  if a.actor_state:
   import struct
   limits=o2[0x71adb0-0x570000:0x71adb0-0x570000+32];assert struct.unpack('<8I',limits)==(151200,273600,100800,345600,345600,201600,345600,100800)
   r['actor_gauge_limits']={'address':'0x71adb0','bytes':32,'sha256':hashlib.sha256(limits).hexdigest()}
   with (out/'actor_status_switch.bin').open('ab')as data:data.write(limits)
   r['actor_status_switch_sha256']=sha(out/'actor_status_switch.bin')
   r['actor_message_admission']='67E230 selectors0/2/4/7/10/12/13/14/15, typed known payloads; selector2 executes actual selected gauge helpers and periodic caller; remaining selectors stay open'
  if a.actor_gauge:
   near_cap=o2[0x740478-0x570000:0x740478-0x570000+4];r['gauge_near_cap_sha256']=hashlib.sha256(near_cap).hexdigest()
   with (out/'actor_status_switch.bin').open('ab')as data:data.write(near_cap)
   r['actor_status_switch_sha256']=sha(out/'actor_status_switch.bin')
   with (out/'reference.hpp').open('a')as reference:reference.write('\ninline std::int32_t actor_gauge_exact_word(float value,std::uint32_t pc){if(pc!=0x668180u||value<0.f||value>400000.f||std::trunc(value)!=value)throw std::runtime_error("Unadmitted gauge float conversion");return std::int32_t(value); }\n#undef FPU_CVT_W_S\n#define FPU_CVT_W_S(x) actor_gauge_exact_word(x,ctx->pc)\n')
   r['declared_ports'].append('Pure668110 conversion admitted only at668180 for exact integral owned caps from caller percentage100; every other float-to-word conversion throws')
  objects,receipts=compile_objects(ROOT,out,cc,flags,UPDATE_UNITS,frozen,env);r['production_objects']=receipts
  cmd[:]=[str(cc),*flags,*objects,str(out/'source'/fixture),'-o',str(exe)]
 try:
  for label,command in [('compile',cmd),('run',[str(exe),str(out/'priorities.bin')]+([str(out/'scenario_rules.bin')]if a.statistics else[])+([str(out/'condition_switch.bin')]if a.automatic else[])+([str(out/'actor_status_switch.bin')]if a.actor_status else[]))]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=180);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':r['observed']=json.loads(result.stdout)
  r['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert r['source_unchanged'];r.update(status='passed',binary_sha256=sha(exe))
 finally:
  r['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps(r['observed']))
if __name__=='__main__':main()
