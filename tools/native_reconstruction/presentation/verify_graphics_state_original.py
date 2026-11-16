"""Run complete original selector 0x0E against the native color owner."""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());paths=[];audits=[]
 for at in (0x1af780,0x196010,0x18b2c0):
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];audits.append(compare_source('complete graphics selector source',path.relative_to(ROOT).as_posix(),begin,end,read));paths.append(path)
 extra='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n';(out/'reference.hpp').write_text((ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+extra)
 body='\n'.join(path.read_text()for path in paths);names={path.stem for path in paths};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(names));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(calls-names));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body)
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 fixture=ROOT/'tools/native_reconstruction/presentation/graphics_state_original_tests.cpp';native=ROOT/'game/native/gameplay_presentation/graphics_state.cpp';exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));flags=[str(CC),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out),'-I'+str(ROOT),'-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
 header=native.with_suffix('.hpp');cmds=[('compile',flags+[str(out/'original.cpp'),str(fixture),str(native),'-o',str(exe)]),('run',[str(exe)])];result={'status':'failed','compiler_sha256':sha(CC),'original_word_audits':audits,'fixture_sha256':sha(fixture),'native_sha256':sha(native),'header_sha256':sha(header),'driver_sha256':sha(Path(__file__)),'checks':[],'game_run':False}
 try:
  for name,cmd in cmds:
   start=time.monotonic();run=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(name+'.out')).write_bytes(run.stdout);(out/(name+'.err')).write_bytes(run.stderr);result['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':run.returncode})
   if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-3000:])
  assert result['native_sha256']==sha(native) and result['header_sha256']==sha(header) and result['fixture_sha256']==sha(fixture);result['observed']=json.loads((out/'run.out').read_text());result['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(result['observed']))
if __name__=='__main__':main()
