"""Trace original 1AF0C0 with a controlled non-wrapping graphics arena."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve());out.mkdir()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';data=elf.read_bytes();read=elf_reader(data);paths={};audits=[]
 image=bytearray(0x2000000);phoff=struct.unpack_from('<I',data,28)[0];size,count=struct.unpack_from('<HH',data,42)
 for i in range(count):
  kind,offset,address,_,filesz,memsz=struct.unpack_from('<6I',data,phoff+i*size)
  if kind==1:assert address+memsz<=len(image) and offset+filesz<=len(data);image[address:address+filesz]=data[offset:offset+filesz]
 (out/'elf_image.bin').write_bytes(image)
 for at in (0x1af0c0,0x1af770,0x1af780,0x196010,0x197470,0x197bb0,0x1982d0,0x198390,0x18ddd0,0x18cfb0,0x18dca0,0x1a0d70,0x1a1330):
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];audits.append(compare_source('frontend graphics defaults source',path.relative_to(ROOT).as_posix(),begin,end,read));paths[at]=path
 extra='\n#include "ps2_fpu_convert.h"\n#define FPU_CVT_W_S(v) Ps2FpuConvertWord(v)\n#define PS2_PCPYLD(a,b) _mm_unpacklo_epi64((b),(a))\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n';reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};std::uint32_t cop0_status{};Register r[32];').replace('using Function=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*);','using Function=void(*)(std::uint8_t*,R5900Context*,PS2Runtime*); void Store32(std::uint8_t*,R5900Context*,std::uint32_t,std::uint32_t){throw std::runtime_error("unmapped graphics MMIO write");}')
 (out/'reference.hpp').write_text(reference+extra)
 body='\n'.join(path.read_text()for path in paths.values());body=re.sub(r'^#include "third_party/PS2Recomp/ps2xRuntime/src/lib/pre_entry_heap_source_scope.hpp"\n','',body,flags=re.M);body=re.sub(r'^\s*reo_parent_natural::PreEntryHeapSourceScope heapControlSource\([^\n]*\);\n','\n',body,flags=re.M);body=re.sub(r'^\s*heapControlSource\.at\([^\n]*\);\n','\n',body,flags=re.M);names={path.stem for path in paths.values()};calls=set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(names));decl+=''.join('inline void '+n+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for n in sorted(calls-names));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in paths.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 fixture=ROOT/'tools/native_reconstruction/presentation/frontend_graphics_heap_probe.cpp';exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));flags=[str(CC),'-std=c++20','-O0','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out),'-I'+str(ROOT/'third_party/PS2Recomp/ps2xRuntime/include')]
 cmds=[('compile',flags+[str(out/'original.cpp'),str(fixture),'-o',str(exe)]),('run',[str(exe),str(out/'elf_image.bin')])];result={'status':'failed','compiler_sha256':sha(CC),'elf_sha256':sha(elf),'image_sha256':sha(out/'elf_image.bin'),'original_word_audits':audits,'fixture_sha256':sha(fixture),'driver_sha256':sha(Path(__file__)),'checks':[],'game_run':False}
 try:
  for name,cmd in cmds:
   start=time.monotonic();run=subprocess.run(cmd,capture_output=True,env=env,timeout=120);(out/(name+'.out')).write_bytes(run.stdout);(out/(name+'.err')).write_bytes(run.stderr);result['checks'].append({'name':name,'seconds':time.monotonic()-start,'exit':run.returncode})
   if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-3000:])
  result['observed']=json.loads((out/'run.out').read_text())
  assert result['observed']['selectors']==[[14,0],[1,512],[21,2],[18,0],[15,0x80ffffff],[16,0x43fa0000],[17,0x461c4000],[12,0],[102,0],[98,0],[2,0],[0,0],[94,50],[99,65536]]
  assert all(start>=0x1000 for start,end in result['observed']['changed_ranges'])
  result['controlled_fixture']='non-wrapping packet arena and initialized two-list queue; no MMIO stub'
  result['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(result['observed']))
if __name__=='__main__':main()
