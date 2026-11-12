"""Actual1B9310 frontend through canonical metadata/audio/pose owners and owned PCM."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 parent=ROOT/'build-native-sjuni'/f'projectile-trail-owner-current-{a.compiler}-v1';prior=json.loads((parent/'receipt.json').read_bytes());assert prior['status']=='passed'
 units=['game/native/gameplay_world/canonical_actor_sounds.cpp','game/native/gameplay_world/actor_offset_sound_policy.cpp'];fixture='tools/native_reconstruction/actor_sound_ownership_tests.cpp';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';owned={*units,fixture,Path(__file__).relative_to(ROOT).as_posix()};frozen={}
 for name,digest in prior['source_sha256'].items():assert sha(parent/'source'/name)==digest;frozen[name]=(parent/'source'/name).read_bytes()
 pending=list(owned)+[helper]
 for name in pending:
  if name not in frozen or name in owned:frozen[name]=(ROOT/name).read_bytes()
  if name.startswith('game/native/')or name==fixture:
   for include in re.findall(r'^\s*#include "([^"\n]+)"',frozen[name].decode(),re.M):
    if name==fixture and include in ['reference.hpp','functions.h','original_dispatch.hpp']:continue
    path=((ROOT/name).parent/include).resolve();path=path if path.is_file()else(ROOT/include).resolve();assert path.is_file()and path.is_relative_to(ROOT);key=path.relative_to(ROOT).as_posix()
    if key not in pending:pending.append(key)
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());path=next((ROOT/'recomp/config/output').glob('sub_001B9310_*'));name=path.relative_to(ROOT).as_posix();body=path.read_bytes();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body.decode()).groups()];proof=compare_source('complete actor offset sound frontend',name,begin,end,read);frozen[name]=body
 out.mkdir(parents=True)
 for name,data in frozen.items():
  target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(data)
 (out/'reference.hpp').write_bytes(frozen[helper]);symbol=path.stem;(out/'functions.h').write_text('#pragma once\nvoid '+symbol+'(std::uint8_t*,R5900Context*,PS2Runtime*);\ninline void sub_001B93D0_0x1b93d0(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n');(out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.h"\n'+body.decode());(out/'original_dispatch.hpp').write_text('case 0x1b9310:'+symbol+'(memory,context,runtime);return;\n')
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/name).write_text('#pragma once\n')
 libraries=[]
 for name,digest in prior['native_library_sha256'].items():
  source=parent/'libraries'/name;assert sha(source)==digest;target=out/'archives'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(source,target);libraries.append(str(target))
 cue_parent=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4';cue_record=json.loads((cue_parent/'receipt.json').read_bytes());cue=cue_parent/'owned_flight_cue.bin';assert sha(cue)==cue_record['flight_cue_asset']['sha256'];shutil.copyfile(cue,out/'owned_cue.bin');assets=[out/'owned_cue.bin'];asset_parent=ROOT/'build-native-sjuni/pose-callbacks-current-llvm-v8';asset_record=json.loads((asset_parent/'receipt.json').read_bytes())
 for name in ['contact-content-v1.bin','owned_effect_geometry.bin','owned_flight_walls.bin','owned_flight_floors.bin']:
  source=asset_parent/name;assert sha(source)==asset_record['output_sha256'][name];shutil.copyfile(source,out/name);assets.append(out/name)
 compiler=COMPILERS[a.compiler];binary=out/'checks.exe';command=[str(compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/fixture),str(out/'original.cpp'),'-Wl,--gc-sections','-Wl,--start-group',*libraries,'-Wl,--end-group','-o',str(binary)];env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''));record=dict(schema=1,status='failed',game_run=False,audio_device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256={n:hashlib.sha256(v).hexdigest()for n,v in frozen.items()},native_parent={'path':str(parent/'receipt.json'),'sha256':sha(parent/'receipt.json')},native_archives=prior['native_library_sha256'],compiler_sha256=sha(compiler),owned_assets={p.name:sha(p)for p in assets},original_owned_bodies=[proof],command=command,limits=['Complete1B9310 executes;1B93D0 is the explicit existing native bank/spatial/PCM boundary, with two independent actual audio/RNG owners.','Metadata byte matrix is explicit input projection, not a claim that6BB040 population audio assignment is ported. Known-zero metadata is supplied by actual native full-record clear producers.','All6owned effect banks exercise actual splitting-arc four-child allocation/samepass continuation/lifetime with knownzero audio gate and actualCF2/timing readers. No installedgame/completeStage4 claim.'])
 try:
  for label,cmd in [('compile',command),('run',[str(binary),*[str(p)for p in assets]])]:
   result=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see logs'
   if label=='run':record['observed']=json.loads(result.stdout);assert record['observed']['owned_banks']==6 and record['observed']['signal_samples']>0
  owned|={n for n in pending if n not in prior['source_sha256']};record['owned_source_drift']={n:sha(ROOT/n)for n in owned if(ROOT/n).read_bytes()!=frozen[n]};assert not record['owned_source_drift'];record['subsequent_parent_changes']={n:sha(ROOT/n)for n in pending if n in prior['source_sha256']and n not in owned and(ROOT/n).read_bytes()!=frozen[n]};record.update(status='passed',binary_sha256=sha(binary))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
