"""Owned second-table SP response programs against complete metadata registration/getter."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser()
 for name in ['compiler','archive','output']:p.add_argument('--'+name,type=Path,required=True)
 a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();read=lambda at,n:raw[at-0x570000:at-0x570000+n];entries={};proof=[]
 for at in [0x6b7350,0x6b7520]:
  path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];entries[at]=path.relative_to(ROOT).as_posix();proof.append(compare_source('complete cue metadata registration/getter or text line helper',entries[at],begin,end,read))
 units=['game/native/gameplay_scenario/'+name+'.cpp'for name in ['dialogue_assets','dialogue_response_program','scenario_archive','content']];files=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"\n]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve();dep=dep if dep.is_file()else(ROOT/rel).resolve();assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in files:files.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/dialogue_response_program_tests.cpp','tools/native_reconstruction/verify_dialogue_response_program.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];files=sorted(files)+helpers+list(entries.values());before={name:sha(ROOT/name)for name in files};result=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),owned_o2_sha256=sha(image),original_owned_bodies=proof,game_run=False,stage4_complete=False,limits=['All540 ownedSP/SPM files are verified against the pinned File1 inventory; native preparation resolves the actual scenario_H.BIN resource index.','Complete6B7520(mode0) compares all second-table response fields and preserved physical row identities; complete6B7350 executes as metadata registration. Immutable program initial state is distinct from future live mutable response state.','The actor-response evaluator and conditions dispatcher5F71F0 remain separate production integration; the importer does not mutate immutable assets or claim a frame worker.'])
 try:
  for name in files:
   path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes((ROOT/name).read_bytes())
  inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';rows=[row for row in json.loads(inventory.read_bytes())if row['names']and re.fullmatch(r'spm?[0-9]{6}\.bin',row['names'][-1],re.I)];assert len(rows)==540
  tables={};profile={};result['owned_assets']=[];stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns
  with a.archive.open('rb')as stream:
   for row in rows:
    base=0
    for ordinal in map(int,row['member'].split('/')[1:]):
     if base not in tables:tables[base]=read_toc(stream,base)
     offset,size=tables[base][0][ordinal];base+=offset
    stream.seek(base);data=stream.read(size);assert len(data)==size==row['bytes']and hashlib.sha256(data).hexdigest()==row['sha256'];result['owned_assets'].append(dict(member=row['member'],name=row['names'][-1],offset=base,bytes=size,sha256=row['sha256']))
    prefix,scenario,section,character=re.fullmatch(r'(spm?)([0-9]{2})([0-9]{2})([0-9]{2})\.bin',row['names'][-1],re.I).groups();key=tuple(map(int,[scenario,section,character]));profile.setdefault(key,{})[prefix.lower()]=row['names'][-1].lower()
  assert len(profile)==270 and all(set(value)=={'sp','spm'}for value in profile.values());(out/'dialogue_asset_profile.hpp').write_text('#pragma once\nstruct DialogueAssetProfile {std::uint16_t scenario;std::uint8_t section,character;const char* cue;const char* text;};\ninline constexpr std::array<DialogueAssetProfile,270> dialogue_asset_profile{{\n'+''.join('{'+','.join(map(str,key))+',"'+row['sp']+'","'+row['spm']+'"},\n'for key,row in sorted(profile.items()))+'}};\n')
  (out/'reference.hpp').write_text((ROOT/helpers[2]).read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n');body='\n'.join((ROOT/name).read_text()for name in entries.values());(out/'functions.h').write_text('#pragma once\n'+''.join('void '+Path(name).stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in entries.values()));(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  for name in ['o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'source'/helpers[0]),str(out/'original.cpp'),'-o',str(binary)];result['command']=command
  for label,cmd in [('compile',command),('run',[str(binary),str(a.archive.resolve())])]:
   done=subprocess.run(cmd,env=env,capture_output=True,timeout=300);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+' failed: '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':result['observed']=json.loads(done.stdout)
  assert stamp==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns);result['snapshot_unchanged']=all(sha(out/'source'/name)==digest for name,digest in before.items());assert result['snapshot_unchanged'];result['live_source_drift']=[name for name,digest in before.items()if not(ROOT/name).is_file()or sha(ROOT/name)!=digest];result['status']='passed'
 finally:
  result['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.iterdir()if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(dict(status=result['status'],observed=result['observed'],live_source_drift=result['live_source_drift'])))
if __name__=='__main__':main()
