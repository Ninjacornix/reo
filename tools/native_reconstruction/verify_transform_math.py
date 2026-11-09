"""Full original helper/trig execution against ordinary native transform math."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
SDK=ROOT/'build-native-sjuni/dependency-muted-rna-reapply-v1/ps2xRuntime/include/ps2_runtime_macros.h'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());o0=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';blob=o0.read_bytes()
 originals=[next((ROOT/'recomp/config/output').glob('sub_'+f'{at:08X}_*')).relative_to(ROOT).as_posix()for at in [0x18f570,0x18fdf0,0x18fe20,0x18fe60,0x1902d0,0x190a10,0x191300,0x1919d0,0x191f80]]+[next((ROOT/'recomp/config/output_ovl/o0').glob('o0_'+f'{at:08X}_*')).relative_to(ROOT).as_posix()for at in [0x370220,0x370320]]
 proof=[]
 for n in originals+['recomp/config/output/sub_00195E50_0x195e50.cpp']:
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/n).read_text()).groups()];proof.append(compare_source('native transform original helper or required identity initialization',n,begin,end,read if begin<0x370000 else lambda at,size:blob[at-0x370000:at-0x370000+size]))
 sdk=SDK.read_text();assert '#define PS2_VMUL(a, b) _mm_mul_ps'in sdk and '#define PS2_VADD(a, b) _mm_add_ps'in sdk and '#define PS2_VSUB(a, b) _mm_sub_ps'in sdk
 unsigned=sdk[sdk.index('#define SET_GPR_U32'):sdk.index('#define SET_GPR_S32')];assert '(int64_t)(int32_t)(val)'in unsigned
 constants={hex(at):dict(bytes=read(at,size).hex(),sha256=hashlib.sha256(read(at,size)).hexdigest())for at,size in [(0x22fe20,32),(0x241c78,32)]}
 native=['game/native/transform_math/transform_math.hpp','game/native/transform_math/transform_math.cpp'];helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/gameplay_world_oracle/transform_math_tests.cpp','tools/native_reconstruction/verify_transform_math.py'];files=originals+native+helpers+['recomp/config/output/sub_00195E50_0x195e50.cpp'];before={n:sha(ROOT/n)for n in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,constant_content=constants,sdk_macros=dict(path=str(SDK),sha256=sha(SDK),sign_extended_unsigned_setter_verified=True,separate_finite_simd_operations_verified=True),actual_game_run=False,native_context_execution=False,physical_ps2_exceptional_parity_claimed=False)
 try:
  for n in files:
   dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());(out/'tests.cpp').write_bytes((ROOT/helpers[1]).read_bytes());body='\n'.join((ROOT/n).read_text()for n in originals);(out/'original_transforms.cpp').write_text(body)
  actual={Path(n).stem for n in originals};names=set(re.findall(r'\b((?:sub|o0)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''
  decl+=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual))
  decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl)
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['ps2_recompiled_functions.h','o0_functions.h']:(out/n).write_text('#pragma once\n#include "functions.h"\n')
  for n in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/n).write_text('#pragma once\n')
  initialization='inline void owned_constants(std::uint8_t* p){\n'
  for at,size in [(0x22fe20,32),(0x241c78,32)]:
   words=struct.unpack('<'+'I'*(size//4),read(at,size));initialization+='const std::array<std::uint32_t,'+str(len(words))+'> c'+str(at)+'{'+','.join(hex(x)+'u'for x in words)+'};std::memcpy(p+'+str(at)+',c'+str(at)+'.data(),'+str(size)+');\n'
  (out/'owned_constants.hpp').write_text(initialization+'}\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'native-transform-math.exe';command=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),str(out/'source'/native[1]),str(out/'tests.cpp'),'-o',str(binary)];record['command']=command
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see sealed compile.txt'
  result=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=180);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'comparison failed; see run.txt'
  observed=json.loads(result.stdout);assert observed['angle_cases']==65536 and observed['trig_cases']==73744 and observed['euler_cases']==131072 and observed['matrix_cases']==observed['direction_cases']==observed['scale_cases']==4096
  assert all(sha(ROOT/n)==h for n,h in before.items()),'source drift during compile/qualification'
  record.update(status='native original-polynomial trig/Euler/matrix operations match complete original helper execution bit-for-bit within declared FP32 profile',observed=observed,binary_sha256=sha(binary),source_unchanged=True,profile=dict(rounding='nearest',gradual_underflow=True,contraction=False,fast_math=False,trig_radian_domain='finite[-2*pi,2*pi]',all_turn16_values=True,preserved_unused_bits=True,initialized_identity_required=True),limits=['Original primary entry/helper bodies execute. Unreachable merged entry tails remain static source evidence, not alternate dynamic-entry qualification.','Native production contains ordinary floats, owned matrices and immutable polynomial constants; CPU/register context exists only in the oracle.','The reference finite scalar/SIMD profile matches auditedSDK131 code; physical PS2 exceptional values/flags/accumulator precision are not claimed.','Original identity cache294E00 is runtime-initialized, not file-backed ELF tabledata; its required initialized identity profile is bound to original195E50 stores.','Arbitrary unused matrixW/translation bits are preserved; wider radians, nonnearest/flush modes and nonfinite arithmetic explicitly refuse.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
