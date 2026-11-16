"""Bounded 1AF6A0/1AF780/197470 original comparison; selector 0x14 dispatch is a declared static bridge."""
import argparse,hashlib,json,os,re,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def sources(source):
 paths=[p for p in sorted((source/'game/native').rglob('*')) if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')]
 paths += [source/'runtime/input/input.h',source/'runtime/input/input.cpp']
 return {p.relative_to(source).as_posix():sha(p) for p in paths}
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--build-receipt',type=Path);p.add_argument('--source',type=Path,default=ROOT);p.add_argument('--build',type=Path,default=ROOT/'build-native-sjuni/gameplay-native-llvm-v1');p.add_argument('--supplement',type=Path);a=p.parse_args();source=a.source.resolve();out=a.output.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve())
 def archive_path(name):return a.build/name if (a.build/name).is_file() else a.supplement/name
 before=sources(source);archives={};receipt=None
 if a.build_receipt:
  receipt=json.loads(a.build_receipt.read_text());assert receipt['status']=='passed' and not receipt['source_drift'] and not receipt['archive_drift'] and sha(CC)==receipt['compiler_sha256']
  assert all(before.get(k)==v for k,v in receipt['sources_sha256'].items());archives={k:sha(archive_path(k)) for k in receipt['archives_sha256']};assert archives==receipt['archives_sha256']
 out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());entries={};audits=[]
 for at in [0x1af6a0,0x1af780,0x197470,0x196010]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];audits.append(compare_source('background body or selector dispatch',path.relative_to(ROOT).as_posix(),begin,end,read));entries[at]=path
 (out/'reference.hpp').write_text((ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text())
 actual=[entries[x] for x in (0x1af6a0,0x1af780,0x197470)];body='\n'.join(path.read_text() for path in actual);names={path.stem for path in actual};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(names));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-names));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body)
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 (out/'palette.bin').write_bytes(read(0x234350,48));fixture=ROOT/'tools/native_reconstruction/presentation/background_original_tests.cpp';native=source/'game/native/gameplay_presentation/background.cpp';exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''))
 flags=[str(CC),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out),'-I'+str(source),'-I'+str(ROOT)]
 commands=[('original',flags+['-c',str(out/'original.cpp'),'-o',str(out/'original.o')]),('fixture',flags+['-c',str(fixture),'-o',str(out/'fixture.o')])]
 if receipt:
  archive=next(k for k in archives if k.replace('\\','/').endswith('/libreo_native_gameplay_presentation.a'))
  objects=[str(archive_path(archive))]
 else:
  commands.append(('native',flags+['-c',str(native),'-o',str(out/'native.o')]));objects=[str(out/'native.o')]
 commands += [('link',[str(CC),str(out/'original.o'),str(out/'fixture.o'),*objects,'-o',str(exe)]),('run',[str(exe),str(out/'palette.bin')])]
 result={'status':'failed','compiler_sha256':sha(CC),'build_receipt_sha256':sha(a.build_receipt) if receipt else None,'sources_sha256':before,'extra_unlinked_sources':{k:v for k,v in before.items() if receipt and k not in receipt['sources_sha256']},'archives_sha256':archives,'original_word_audits':audits,'native_sha256':sha(native),'fixture_sha256':sha(fixture),'palette_sha256':sha(out/'palette.bin'),'driver_sha256':sha(Path(__file__)),'declared_port':'196010 selector 0x14 control-flow bridge; exact full dispatcher is statically word-audited, not executed','checks':[],'game_run':False}
 try:
  for name,cmd in commands:
   start=time.monotonic();run=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/(name+'.out')).write_bytes(run.stdout);(out/(name+'.err')).write_bytes(run.stderr);result['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':run.returncode})
   if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-3000:])
  assert before==sources(source) and archives=={k:sha(archive_path(k)) for k in archives} and result['fixture_sha256']==sha(fixture);result['observed']=json.loads((out/'run.out').read_text());result['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(result['observed']))
if __name__=='__main__':main()
