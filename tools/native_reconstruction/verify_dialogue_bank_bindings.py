"""Compare complete6B7350 publication against real retained banks and canonical actors."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--native-snapshot',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');base=a.native_snapshot.resolve();prior=json.loads((base/'receipt.json').read_text());assert prior['snapshot_ready']and prior['compiler_sha256']==sha(a.compiler)
 for name,digest in prior['source_sha256'].items():assert sha(base/'source'/name)==digest
 for name,digest in prior['native_archives'].items():assert sha(base/'archives'/name)==digest
 units=['game/native/gameplay_world/dialogue_bank_bindings.cpp'];helpers=['game/native/gameplay_world/dialogue_bank_bindings.hpp','tools/native_reconstruction/dialogue_bank_bindings_tests.cpp','tools/native_reconstruction/verify_dialogue_bank_bindings.py'];owned=units+helpers
 before={name:sha(ROOT/name)for name in owned};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),native_snapshot=dict(path=base.relative_to(ROOT).as_posix(),sha256=sha(base/'receipt.json')),game_run=False,audio_device_opened=False,stage4_complete=False,limits=['Complete6B7350 executes against actual owned SP/SPM resources and canonical primary actor character fields. New typed physical tables will be owned exclusively by Pool after its actual cold clear; this pure qualifier does not yet bind the full1D41F0 caller.','Invalid character255 interrupts the original exact map write after its completed physical-table publication. Native preserves that physical prefix and refuses the out-of-range map.'])
 try:
  overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();name='recomp/config/output_ovl/o2/o2_006B7350_0x6b7350.cpp';source=base/'source'/name;begin,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];record['original_owned_body']=compare_source('complete physical dialogue bank publication',name,begin,end,lambda at,n:raw[at-0x570000:at-0x570000+n])
  # New units use their actual relative includes. Pin every existing header they
  # can reach to the immutable, ABI-matching canonical source snapshot.
  pending=units+[helpers[0]];visited=set();shared={}
  while pending:
   item=pending.pop()
   if item in visited:continue
   visited.add(item)
   for rel in re.findall(r'#\s*include\s*"([^\"]+)"',(ROOT/item).read_text()):
    if rel in {'reference.hpp','functions.h'}:continue
    path=next((value.resolve()for value in[(ROOT/item).parent/rel,ROOT/rel]if value.is_file()),None);assert path and path.is_relative_to(ROOT),(item,rel);dep=path.relative_to(ROOT).as_posix()
    if dep not in owned:assert prior['source_sha256'].get(dep)==sha(path),dep;shared[dep]=sha(path)
    if dep not in visited:pending.append(dep)
  record['shared_source_sha256']=shared
  for name,digest in prior['source_sha256'].items():
   if Path(name).suffix.lower()in {'.hpp','.h','.inc'}:
    target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((base/'source'/name).read_bytes());assert sha(target)==digest
  for name in owned:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  header=(base/'source/tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text()+'\nvoid observed_binding_write(std::uint8_t*,const R5900Context*,std::uint32_t,std::uint8_t);\n#undef WRITE8\n#define WRITE8(at,value) observed_binding_write(rdram,ctx,at,value)\n';(out/'reference.hpp').write_text(header);(out/'functions.h').write_text('#pragma once\nvoid o2_006B7350_0x6b7350(std::uint8_t*,R5900Context*,PS2Runtime*);\n');(out/'original.cpp').write_bytes(source.read_bytes())
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'o2_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  assets=json.loads((ROOT/'build-native-sjuni/dialogue-assets-gcc-v1/receipt.json').read_text());record['owned_assets']=[]
  with a.archive.open('rb')as stream:
   for row in assets['owned_assets']:
    if row['name'].lower()in {'sp010000.bin','sp010001.bin','sp010008.bin','spm010000.bin','spm010001.bin','spm010008.bin'}:
     stream.seek(row['offset']);assert hashlib.sha256(stream.read(row['bytes'])).hexdigest()==row['sha256'];record['owned_assets'].append(row)
  assert len(record['owned_assets'])==6
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/units[0]),str(out/'source'/helpers[1]),str(out/'original.cpp'),'-Wl,--start-group',*[str(base/'archives'/name)for name in prior['native_archives']],'-Wl,--end-group','-o',str(out/'checks.exe')];record['command']=command
  for label,cmd in [('compile',command),('run',[str(out/'checks.exe'),str(a.archive.resolve())])]:
   done=subprocess.run(cmd,capture_output=True,env=env,timeout=300);(out/(label+'.txt')).write_bytes(done.stdout+done.stderr);assert done.returncode==0,label+': '+(done.stdout+done.stderr).decode(errors='replace')[-1500:]
   if label=='run':record['observed']=json.loads(done.stdout)
  record['source_unchanged']=all(sha(ROOT/name)==digest for name,digest in before.items())and all(sha(ROOT/name)==digest for name,digest in shared.items());assert record['source_unchanged'];record['snapshot_unchanged']=all(sha(base/'source'/name)==digest for name,digest in prior['source_sha256'].items())and all(sha(base/'archives'/name)==digest for name,digest in prior['native_archives'].items());assert record['snapshot_unchanged'];record['status']='passed'
 finally:
  record['output_sha256']={path.relative_to(out).as_posix():sha(path)for path in out.rglob('*')if path.is_file()and path.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record.get('observed'))))
if __name__=='__main__':main()
