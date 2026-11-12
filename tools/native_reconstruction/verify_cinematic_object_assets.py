"""Compare native cinematic assets with bounded complete original construction."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
PORTS={0x1cd1c0,0x1af780,0x1b2a70,0x1ce110,0x1aaad0,0x1b1360,0x1cd1e0,0x1cd250,0x1cd2c0,0x18dc50,0x18dca0,0x1b10c0,0x1b1260}
ALIASES={0x18f624:0x18f570,0x193590:0x193580}
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--audit',type=Path,required=True);p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 audit=a.audit.resolve();receipt=json.loads((audit/'receipt.json').read_bytes());assert receipt['status']=='passed'
 for name,digest in receipt['source_sha256'].items():assert sha(ROOT/name)==digest,name
 for name,digest in receipt['output_sha256'].items():assert sha(audit/name)==digest,name
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());pending=[0x1d13f0,0x1d25b0,0x1d2c00,0x1a31b0];entries={};proof=[]
 while pending:
  at=pending.pop()
  if at in entries or at in PORTS:continue
  original=ALIASES.get(at,at);path=next((ROOT/'recomp/config/output').glob(f'sub_{original:08X}_*'));name=path.relative_to(ROOT).as_posix();entries[at]=name
  pending.extend(int(v,16)for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',path.read_text()))
 originals=sorted(set(entries.values()))
 for name in originals:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/name).read_text()).groups()];proof.append(compare_source('complete cinematic object construction/material/root0/math body',name,begin,end,read))
 units=['game/native/'+n for n in ['gameplay_world/cinematic_object_assets.cpp','gameplay_world/model_parts.cpp','animation/model.cpp','animation/model_math.cpp','animation/constraint_math.cpp','animation/curves.cpp','transform_math/transform_math.cpp','gameplay_scenario/scenario_archive.cpp','gameplay_scenario/content.cpp']];native=set(units);pending=list(units)
 while pending:
  name=pending.pop()
  for rel in re.findall(r'^#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   dep=((ROOT/name).parent/rel).resolve()
   if not dep.is_file():dep=ROOT/rel
   assert dep.is_file()and dep.is_relative_to(ROOT),(name,rel)
   key=dep.relative_to(ROOT).as_posix()
   if key not in native:native.add(key);pending.append(key)
 helpers=['tools/native_reconstruction/cinematic_object_asset_tests.cpp','tools/native_reconstruction/verify_cinematic_object_assets.py','tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'];files=sorted(native)+helpers+originals;before={n:sha(ROOT/n)for n in files};stamp=(a.archive.stat().st_size,a.archive.stat().st_mtime_ns);out.mkdir();record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),game_run=False,installed_in_game=False,stage4_complete=False,original_owned_bodies=proof,audit=dict(receipt=(audit/'receipt.json').relative_to(ROOT).as_posix(),receipt_sha256=sha(audit/'receipt.json')),limits=['1D13F0 executes completely, including original render API default calls and literal8-part allocation request. Renderer/material/resource/node allocators are bounded observation ports.','1CE110/1AAAD0 are explicit archive/renderer boundaries: native actual archive reads are tested independently and complete1D25B0/1D2C00 run on those owned bytes. This does not claim original combined model-loader execution.','All root0 construction/packing/static initialization/local/inverse-bind pose routines execute through complete owned bodies. Fresh test node arenas are cleared; allocator reuse is not inferred.','All452 bundles import;450 canonical numeric filename requests read actual archive bytes. Two noncanonical padded names are retained as data and are not guessed aliases.','No renderer admission, actual scene construction caller, game installation or full Step4 completion.'])
 try:
  for name in files:
   target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/name).read_bytes())
  reference=(ROOT/helpers[2]).read_text().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}').replace('Register r[32];','std::uint64_t lo{},hi{},lo1{},hi1{};Register r[32];')
  reference+='\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define FPU_DIV_S(a,b) ((a)/(b))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_SQRT_S(a) std::sqrt(a)\n#define PS2_VOPMUL(a,b) _mm_mul_ps(_mm_shuffle_ps((a),(a),_MM_SHUFFLE(3,0,2,1)),_mm_shuffle_ps((b),(b),_MM_SHUFFLE(3,1,0,2)))\n#define SRA32(v,n) (std::int32_t(v) >> (n))\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n';(out/'reference.hpp').write_text(reference);(out/'ps2_fpu_convert.h').write_bytes((ROOT/helpers[3]).read_bytes())
  actual={Path(n).stem for n in originals};body='\n'.join((ROOT/n).read_text()for n in originals);names=set(re.findall(r'\b((?:sub|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+Path(n).stem+'(memory,context,runtime);return;\n'for at,n in sorted(entries.items())))
  for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
  (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
  for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
  constants='inline void owned_constants(std::uint8_t* p){\n';record['owned_constants']={}
  for at,n in [(0x22fe20,32),(0x241c78,40),(0x241e90,4)]:
   raw=read(at,n);record['owned_constants'][hex(at)]=raw.hex();constants+='{const std::uint8_t b[]{'+','.join(map(str,raw))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}\n'
  (out/'owned_constants.hpp').write_text(constants+'}\n');rows=json.loads((audit/'owned_objects.json').read_bytes());(out/'owned_objects.txt').write_text('\n'.join(' '.join(map(str,[x['scenario'],*x['request'],x['model'],x['name'],x['parts'],x['materials'],x['first_root_nodes'],int(x['canonical_name_matches'])]))for x in rows)+'\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'original.cpp'),str(out/'source'/helpers[0]),'-o',str(binary)];record['command']=command
  r=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  r=subprocess.run([str(binary),str(a.archive.resolve()),str(audit/'owned_objects.bin'),str(out/'owned_objects.txt')],env=env,capture_output=True,text=True,timeout=180);(out/'run.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'comparison failed'
  record.update(status='passed',observed=json.loads(r.stdout),source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged'];assert(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)==stamp
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],observed=record['observed'])))
if __name__=='__main__':main()
