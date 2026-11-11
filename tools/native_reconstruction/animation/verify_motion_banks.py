"""Compare full native sparse/strided motion bank construction with original bodies."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--corpus',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');corpus=a.corpus.resolve();cr=json.loads((corpus/'receipt.json').read_bytes());assert cr['clips']==59
 assets=[];raws=[]
 for n in ['pc_000.bin','pc_001.bin']:
  item=next(x for x in cr['assets']if x['name'].lower()==n);raw=(corpus/n).read_bytes();assert hashlib.sha256(raw).hexdigest()==item['sha256'];assets.append(item);raws.append(raw)
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=json.loads(inventory.read_bytes());iso=ROOT/'iso/Resident Evil - Outbreak (v2.00).iso'
 for member in ['NETBIO00.DAT/0/735','NETBIO00.DAT/0/757','NETBIO00.DAT/0/758']:
  item=next(x for x in members if x['member']==member)
  with iso.open('rb')as f:f.seek(item['iso_offset']);raw=f.read(item['bytes'])
  assert hashlib.sha256(raw).hexdigest()==item['sha256'];assets.append(item);raws.append(raw)
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());entries={};proof=[]
 for at in [0x1d1500,0x1d16c0,0x1d1940,0x1d1960,0x1d1990,0x1d19d0,0x1b1bc0,0x1b1b40,0x1b2130,0x1b1c20,0x1b1cb0,0x1b1df0,0x1b1e20,0x1b1e50]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete original motion bank constructor body',name,begin,end,read));entries[at]=name
 native=['game/native/animation/'+x for x in ['motion_bank.cpp','motion_bank.hpp','curves.cpp','curves.hpp']]+['game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp'];helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/motion_bank_tests.cpp','tools/native_reconstruction/animation/verify_motion_banks.py'];files=native+helpers+list(entries.values());before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True);record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),owned_assets=assets,original_owned_bodies=proof,game_run=False,resource_heap_seams=['1D3550 raw-block provenance registration instead of repacking','192500 native fixture token identity assignment','1925A0 records release; no original heap implementation claim'])
 try:
  for n in files:
   target=out/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes())
  (out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());(out/'reference.hpp').write_text((ROOT/helpers[0]).read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n');body='\n'.join((ROOT/n).read_text()for n in entries.values());(out/'original_banks.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual))+''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r); }\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in entries.items()))
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  raw=read(0x2366f0,12);record['owned_mode_table']=dict(address='0x2366f0',bytes_hex=raw.hex());family_raw=read(0x234410,24);record['owned_release_families']=dict(address='0x234410',bytes_hex=family_raw.hex());(out/'constants.hpp').write_text('inline void constants(std::uint8_t* p){const std::uint8_t b[]{'+','.join(str(v)for v in raw)+'};std::memcpy(p+0x2366f0,b,sizeof b);const std::uint8_t f[]{'+','.join(str(v)for v in family_raw)+'};std::memcpy(p+0x234410,f,sizeof f); }\n');package=struct.pack('<I',len(raws))+b''.join(struct.pack('<I',len(b))+b for b in raws);(out/'owned_banks.bin').write_bytes(package)
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';cmd=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source/game/native/animation/motion_bank.cpp'),str(out/'source/game/native/animation/curves.cpp'),str(out/'source/game/native/transform_math/transform_math.cpp'),str(out/'tests.cpp'),'-o',str(binary)];record['command']=cmd;r=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed';r=subprocess.run([str(binary),str(out/'owned_banks.bin')],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed';record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
