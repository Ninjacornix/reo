"""Complete5B5350 actor inventory trait query through canonical resource metadata."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes();read=lambda at,n:data[at-0x570000:at-0x570000+n];entries={};proof=[]
 for at in [0x5b5350,0x5b43f0,0x5b4380]:
  original=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',original.read_text()).groups()];entries[at]=original.relative_to(ROOT).as_posix();proof.append(compare_source('complete actor inventory trait or reached resource metadata getter',entries[at],begin,end,read))
 units=['game/native/gameplay_world/dialogue_inventory_traits.cpp','game/native/gameplay_scenario/scene_resources.cpp','game/native/gameplay_scenario/resource_templates.cpp'];files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/dialogue_inventory_traits_tests.cpp','tools/native_reconstruction/verify_dialogue_inventory_traits.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];files=sorted(files)+helpers+list(entries.values());before={name:sha(ROOT/name)for name in files};result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,stage4_complete=False,game_run=False,limits=['Complete5B5350 and both metadata getters compare all256 signed-low-byte selectors and all256 characters across five owned template banks plus one declared controlled bank.','Canonical actor inventory, SceneResources descriptors and ResourceTemplates metadata are borrowed directly; selector2 preserves the contradictory character6/7 storage gate. Actual caller evaluation and host bindings are separate integration.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  (out/'reference.hpp').write_bytes((ROOT/helpers[2]).read_bytes());body='\n'.join((ROOT/name).read_text()for name in entries.values());(out/'functions.h').write_text('#pragma once\n'+''.join('void '+Path(name).stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in entries.values()));(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){const std::uint8_t b[]{'+','.join(map(str,read(0x73e550,32)))+'};std::memcpy(p+0x73e550,b,sizeof b); }\n')
  inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=[m for m in json.loads(inventory.read_bytes())if any(n.lower().startswith('item')and n.lower().endswith('.dat')for n in m.get('names',[]))];assert len(members)==5;result['owned_template_members']=members
  with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as archive,(out/'owned_templates.bin').open('wb')as output:
   output.write(struct.pack('<I',len(members)))
   for member in members:
    archive.seek(member['iso_offset']);payload=archive.read(member['bytes']);assert hashlib.sha256(payload).hexdigest()==member['sha256'];at,n=struct.unpack_from('<II',payload);assert at+n<=len(payload);output.write(struct.pack('<I',n)+payload[at:at+n])

  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-ffunction-sections','-fdata-sections','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-Wl,--gc-sections','-o',str(binary)];result['command']=command
  for label,cmd in [('compile',command),('run',[str(binary),str(out/'owned_templates.bin')])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=180);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':result['observed']=json.loads(done.stdout)
  result['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in before.items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in before.items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
