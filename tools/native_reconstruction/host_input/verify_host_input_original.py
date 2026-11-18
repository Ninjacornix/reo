"""Bounded original input-chain comparison with real native normalization."""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
IDS=[0x1a6140,0x1a6090,0x1a5f50,0x1a6480,0x1a65d0,0x1a1b60,0x1a1c60,0x1a1cb0,0x1b06f0,0x191ef0,0x1a1d40,0x1b0ac0,0x1b0aa0,
 0x10faa0,0x111770,0x111888,0x1118f8,0x1119d0,0x111a90,0x111cf0,0x111d48,0x111db0,0x112038,0x112178,0x112298,0x1122e8,0x1123a0,0x112470,0x11f878,0x1201c0,0x121a28,0x121ef0,0x122690,0x1226c0]
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--build',type=Path,default=ROOT/'build-native-sjuni/gameplay-native-llvm-v1');p.add_argument('--build-receipt',type=Path,default=ROOT/'build-native-sjuni/stage4-orchestration/input-action-integration-llvm-v2/receipt.json');a=p.parse_args();out=a.output.resolve();build=a.build.resolve()
 assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
 receipt=json.loads(a.build_receipt.read_text());assert receipt['status']=='passed' and not receipt['source_drift'] and not receipt['archive_drift'] and sha(CC)==receipt['compiler_sha256']
 def source_hashes():
  base=ROOT/'game/native';paths=[p for p in sorted(base.rglob('*')) if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')];paths += [ROOT/'runtime/input/input.h',ROOT/'runtime/input/input.cpp'];return {p.relative_to(ROOT).as_posix():sha(p) for p in paths}
 before=source_hashes();assert before==receipt['sources_sha256']
 archives={name:sha(build/name) for name in receipt['archives_sha256']};assert archives==receipt['archives_sha256']
 lines=(build/'build.ninja').read_text().splitlines();link_at=next(i for i,line in enumerate(lines) if line.startswith('build gameplay_actors/gameplay_entities_tests.exe:'))
 libraries=next(line.split('=',1)[1].split() for line in lines[link_at+1:link_at+8] if line.lstrip().startswith('LINK_LIBRARIES ='))
 image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(image.read_bytes())
 units=[];audits=[]
 for at in IDS:
  path=ROOT/f'recomp/config/output/sub_{at:08X}_0x{at:x}.cpp';body=path.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
  audits.append(compare_source('input original and numeric helper',path.relative_to(ROOT).as_posix(),at,end,read));units.append((at,path,body))
 body='\n'.join('\n'.join(line for line in text.splitlines() if not line.startswith('#include')) for _,_,text in units)
 defs={f'sub_{at:08X}_0x{at:x}' for at,_,_ in units};allnames=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));missing=allnames-defs
 fixture=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];float f[32]{};','Register r[32];std::uint64_t hi{},lo{},hi1{},lo1{};float f[32]{};')
 fixture+='\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (std::int32_t(a)>>(unsigned(b)&31))\n#include "word_conversion.hpp"\n#define FPU_CVT_W_S(a) Ps2FpuConvertWord(float(a))\n'
 (out/'reference.hpp').write_text(fixture);(out/'word_conversion.hpp').write_bytes((ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h').read_bytes())
 declarations=''.join(f'void {name}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for name in sorted(defs))
 declarations+=''.join(f'inline void {name}(std::uint8_t*m,R5900Context*c,PS2Runtime*r){{c->pc={name.split("_")[-1]};original_transform_port(m,c,r);}}\n' for name in sorted(missing))
 (out/'functions.hpp').write_text(declarations)
 (out/'original.cpp').write_text('#include "reference.hpp"\n#include "functions.hpp"\n'+body)
 (out/'dispatch.hpp').write_text(''.join(f'case {hex(at)}:sub_{at:08X}_0x{at:x}(memory,context,runtime);return;\n' for at,_,_ in units))
 env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));exe=out/'checks.exe'
 flags=[str(CC),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(ROOT)]
 cmds=[('original',flags+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]),
  ('test',flags+['-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-parameter','-c',str(ROOT/'tools/native_reconstruction/host_input/original_tests.cpp'),'-o',str(out/'test.o')]),
  ('link',[str(CC),str(out/'original.o'),str(out/'test.o'),'-o',str(exe),*[str(build/p) if p.endswith('.a') else p for p in libraries]]),
  ('run',[str(exe),str(image)])]
 r={'status':'failed','compiler_sha256':sha(CC),'build_receipt_sha256':sha(a.build_receipt),'original_word_audits':audits,'sources_sha256':before,'archives_sha256':archives,'fixture_sha256':sha(ROOT/'tools/native_reconstruction/host_input/original_tests.cpp'),'elf_sha256':sha(image),'ports':['hardware poll 1A6760','discarded 1A1970 output'],'checks':[]}
 try:
  for name,cmd in cmds:
   start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,capture_output=True,timeout=180);(out/(name+'.out')).write_bytes(run.stdout);(out/(name+'.err')).write_bytes(run.stderr);r['checks'].append({'name':name,'exit':run.returncode,'seconds':round(time.monotonic()-start,3)})
   if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-5000:])
  assert source_hashes()==before and {name:sha(build/name) for name in archives}==archives
  r['result']=json.loads((out/'run.out').read_text());r['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(r,indent=2)+'\n')
 print(json.dumps(r['result']))
if __name__=='__main__':main()
