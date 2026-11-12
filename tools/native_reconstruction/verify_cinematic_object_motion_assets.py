"""Compare all owned object banks and the complete original named loader."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2];sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 profile=ROOT/'build-native-sjuni/cinematic-object-motion-profile-v1/receipt.json';pr=json.loads(profile.read_bytes());assert pr['status']=='passed'and sha(ROOT/'game/native/gameplay_world/cinematic_object_motion_members.inc')==pr['output_sha256']['cinematic_object_motion_members.inc']
 for name,digest in pr['source_sha256'].items():assert sha(ROOT/name)==digest,name
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());entries={};proof=[]
 for at in [0x1d1e00,0x1d1960,0x1d1500]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];entries[at]=name;proof.append(compare_source('complete cinematic object named load/strided bank body',name,begin,end,read))
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={x['member']:x for x in json.loads(inventory.read_bytes())};rows=[];lines=[];stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns
 with a.archive.open('rb')as f:
  root=read_toc(f,0);common=[i for i,(name,_)in enumerate(root[2])if name.lower()=='romdata_usa.afs'];assert len(common)==1;base=root[0][common[0]][0];directory=read_toc(f,base);assert len(directory[0])==1342
  for row in pr['rows']:
   at,size=directory[0][row['member']];f.seek(base+at);raw=f.read(size);item=members['NETBIO00.DAT/%d/%d'%(common[0],row['member'])];assert len(raw)==item['bytes']==size and hashlib.sha256(raw).hexdigest()==item['sha256'];lines.append(' '.join(map(str,[row['scenario'],row['area'],row['member'],base+at,size])));rows.append(dict(**row,offset=base+at,bytes=size,sha256=item['sha256']))
 units=['game/native/'+name for name in ['gameplay_world/cinematic_object_motion_assets.cpp','animation/motion_bank.cpp','animation/curves.cpp','transform_math/transform_math.cpp']];native=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   dep=next((x.resolve()for x in[(ROOT/name).parent/rel,ROOT/rel]if x.is_file()),None);assert dep and dep.is_relative_to(ROOT),(name,rel);key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/cinematic_object_motion_tests.cpp','tools/native_reconstruction/verify_cinematic_object_motion_assets.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/generate_cinematic_object_motion_profile.py'];files=sorted(native)+helpers+list(entries.values());before={name:sha(ROOT/name)for name in files};out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),game_run=False,installed_in_game=False,stage4_complete=False,owned_banks=rows,original_owned_bodies=proof,profile=dict(receipt=profile.relative_to(ROOT).as_posix(),receipt_sha256=sha(profile)),limits=['Actual52 ROM members read by exact owned alias ordinals; duplicate AFS display names are not used as identities.','Complete1D1E00/1D1960/1D1500 execute.1CC8F0 supplies controlled actual bytes/failed read results;1D3550 and192500 expose raw-block provenance and token allocation, not original packed curve construction.','Bank headers/all2000 slots, raw block provenance/bytes, old-bank retention and immutable leases compare. Playback of every curve/model pairing is not claimed.','No live scene bank publication, game installation or full Step4 acceptance.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  (out/'members.txt').write_text('\n'.join(lines)+'\n');reference=(ROOT/helpers[2]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n';(out/'reference.hpp').write_text(reference)
  body='\n'.join((ROOT/name).read_text()for name in entries.values());actual={Path(name).stem for name in entries.values()};names=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(name).stem+'(memory,context,runtime);return;\n'for at,name in entries.items()))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  raw=read(0x2564c0,100).split(b'\0')[0]+b'\0';(out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+0x2564c0,b,sizeof b);}\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';cmd=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/name)for name in units],str(out/'original.cpp'),str(out/'source'/helpers[0]),'-o',str(binary)];record['command']=cmd
  r=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(a.archive.resolve()),str(out/'members.txt')],env=env,capture_output=True,text=True,timeout=120);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed';record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/name)==digest for name,digest in before.items()));assert record['source_unchanged']and(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)==stamp
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
