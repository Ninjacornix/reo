"""Compare actual archive selection owner with original bodies using shared LLVM archives."""
import argparse,hashlib,json,os,re,struct,subprocess,sys,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
CC=Path('C:/Users/Ninjacornix/AppData/Local/OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def source_hashes(source):
 paths=[p for p in sorted((source/'game/native').rglob('*')) if p.is_file() and (p.suffix in ('.cpp','.hpp','.h','.inc') or p.name=='CMakeLists.txt')]
 paths += [source/'runtime/input/input.h',source/'runtime/input/input.cpp']
 return {p.relative_to(source).as_posix():sha(p) for p in paths}
def main():
 p=argparse.ArgumentParser();p.add_argument('--build-receipt',type=Path,required=True);p.add_argument('--audio-archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--source',type=Path,default=ROOT);p.add_argument('--build',type=Path,default=ROOT/'build-native-sjuni/gameplay-native-llvm-v1');p.add_argument('--supplement',type=Path);a=p.parse_args();source=a.source.resolve()
 out=a.output.resolve();build=a.build.resolve();assert not out.exists() and out.is_relative_to((ROOT/'build-native-sjuni').resolve())
 receipt=json.loads(a.build_receipt.read_text());assert receipt['status']=='passed' and not receipt['source_drift'] and not receipt['archive_drift'] and sha(CC)==receipt['compiler_sha256']
 def archive_path(name):return build/name if (build/name).is_file() else a.supplement/name
 before=source_hashes(source);assert all(before.get(k)==v for k,v in receipt['sources_sha256'].items());archives={k:sha(archive_path(k)) for k in receipt['archives_sha256']};assert archives==receipt['archives_sha256']
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 audit_path=ROOT/'build-native-sjuni/actor-voice-archive-activation-audit-v1/receipt.json';audit=json.loads(audit_path.read_text());assert audit['status']=='static_source_and_owned_archive_audit' and len(audit['archives'])==8
 with a.audio_archive.open('rb') as stream:
  for row in audit['archives']:
   stream.seek(row['offset']);data=stream.read(row['bytes']);assert len(data)==row['bytes'] and hashlib.sha256(data).hexdigest()==row['archive_sha256']
 entries={};proof=[]
 for at in [0x1ba440,0x1ab450,0x1ab2f0,0x1ab050,0x1ba330]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete actor voice activation/reset/lookup body executed',path.relative_to(ROOT).as_posix(),begin,end,read));entries[at]=path
 out.mkdir(parents=True);reference=(ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp').read_text().replace('Register r[32];','std::uint64_t lo{},hi{};Register r[32];')+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n';(out/'reference.hpp').write_text(reference)
 body='\n'.join(path.read_text()for path in entries.values());actual={path.stem for path in entries.values()};calls=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+name+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for name in sorted(actual));decl+=''.join('inline void '+name+'(std::uint8_t* m,R5900Context* c,PS2Runtime* r){original_transform_port(m,c,r);}\n'for name in sorted(calls-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original.cpp').write_text(body);(out/'original_dispatch.hpp').write_text(''.join('case '+hex(at)+':'+path.stem+'(memory,context,runtime);return;\n'for at,path in entries.items()));(out/'actor_voice_archive_reference.inc').write_bytes((ROOT/'tools/native_reconstruction/actor_voice_archive_reference.inc').read_bytes())
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 (out/'ps2_recompiled_functions.h').write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 constants=[]
 for at,size in [(0x2337c0,422*4),(0x250220,32),(0x24fd10,32)]+[(pointer,128) for pointer in struct.unpack('<422I',read(0x2337c0,422*4))]:
  data=read(at,size);constants.append('{const std::uint8_t b[]{'+','.join(map(str,data))+'};std::memcpy(p+'+str(at)+',b,sizeof b);}')
 (out/'owned_constants.hpp').write_text('inline void owned_constants(std::uint8_t* p){\n'+'\n'.join(constants)+'\n}\n')
 lines=(build/'build.ninja').read_text().splitlines();at=next(i for i,line in enumerate(lines) if line.startswith('build gameplay_application/actor_voice_tests.exe:'));libs=next(line.split('=',1)[1].split() for line in lines[at+1:at+8] if line.lstrip().startswith('LINK_LIBRARIES ='));libs=[str(archive_path(x)) if x.endswith('.a') else x for x in libs]
 fixture=ROOT/'tools/native_reconstruction/gameplay_scenario/stream_instances_oracle/actor_voice_archive_tests.cpp';exe=out/'checks.exe';env=dict(os.environ,PATH=str(CC.parent)+os.pathsep+os.environ.get('PATH',''));flags=[str(CC),'-std=c++20','-O2','-msse4.1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-Wno-unused-variable','-I'+str(out),'-I'+str(source),'-I'+str(ROOT)]
 commands=[('original',flags+['-c',str(out/'original.cpp'),'-o',str(out/'original.o')]),('fixture',flags+['-DREO_ACTOR_ARCHIVE_ORIGINAL=1','-c',str(fixture),'-o',str(out/'fixture.o')]),('link',[str(CC),str(out/'original.o'),str(out/'fixture.o'),'-o',str(exe),*libs]),('run',[str(exe),str(a.audio_archive.resolve())])]
 result={'status':'failed','compiler_sha256':sha(CC),'build_receipt_sha256':sha(a.build_receipt),'sources_sha256':before,'extra_unlinked_sources':{k:v for k,v in before.items() if k not in receipt['sources_sha256']},'archives_sha256':archives,'original_word_audits':proof,'fixture_sha256':sha(fixture),'reference_sha256':sha(ROOT/'tools/native_reconstruction/actor_voice_archive_reference.inc'),'owned_archive_audit_sha256':sha(audit_path),'driver_sha256':sha(Path(__file__)),'checks':[],'game_run':False}
 try:
  for name,cmd in commands:
   started=time.monotonic();run=subprocess.run(cmd,capture_output=True,env=env,timeout=180);(out/(name+'.out')).write_bytes(run.stdout);(out/(name+'.err')).write_bytes(run.stderr);result['checks'].append({'name':name,'seconds':time.monotonic()-started,'exit':run.returncode})
   if run.returncode:raise RuntimeError(name+': '+run.stderr.decode(errors='replace')[-3000:])
  assert before==source_hashes(source) and archives=={k:sha(archive_path(k)) for k in archives};result['observed']=json.loads((out/'run.out').read_text());result['status']='passed'
 finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
 print(json.dumps(result['observed']))
if __name__=='__main__':main()
