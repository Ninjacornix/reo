"""Byte-verified original-body comparison for native shared RNG and options."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source,elf_reader
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True,type=Path);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 ids=['001AEC50','001AEC80','001AED60','001AEDB0','001AEE40','001BADF0'];sources=[next((ROOT/'recomp/config/output').glob('sub_'+i+'_*')) for i in ids]
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());proof=[]
 for src in sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];proof.append(compare_source('native session domain',src.relative_to(ROOT).as_posix(),begin,end,read))
 assert read(0x24fe30,16)==bytes([0,7,7,0,1,128,0,0,1,0,0,0,0,0,0,0])
 files=sources+[ROOT/n for n in ('game/native/gameplay_session/session.hpp','game/native/gameplay_session/session.cpp','tools/native_reconstruction/gameplay_session/tests.cpp','tools/native_reconstruction/gameplay_session/verify.py','tools/native_reconstruction/gameplay_save/original_fixture.hpp')];before={f.relative_to(ROOT).as_posix():sha(f) for f in files};out.mkdir(parents=True)
 record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),source_sha256=before,original_bodies=proof,game_run=False,stage4_complete=False)
 try:
  core=out/'source/game/native/gameplay_session';core.mkdir(parents=True)
  for n in ('session.hpp','session.cpp'):(core/n).write_bytes((ROOT/'game/native/gameplay_session'/n).read_bytes())
  (out/'tests.cpp').write_bytes((Path(__file__).parent/'tests.cpp').read_bytes());(out/'original_fixture.hpp').write_bytes((ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_bytes())
  for n in ('ps2_runtime.h','ps2_runtime_macros.h','o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h'):(out/n).write_text('#pragma once\n#include "original_fixture.hpp"\n',encoding='utf8',newline='\n')
  declarations=''.join('void '+src.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for src in sources)
  body='\n'.join(src.read_text() for src in sources);calls=sorted(set(re.findall(r'\b(sub_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body)));declarations+=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in calls)
  (out/'original_declarations.inc').write_text(declarations,encoding='utf8',newline='\n');(out/'functions.h').write_text(declarations,encoding='utf8',newline='\n');(out/'ps2_recompiled_functions.h').write_text(declarations,encoding='utf8',newline='\n');(out/'original.cpp').write_text('#include "original_declarations.inc"\n'+body,encoding='utf8',newline='\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'session.exe';command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),'-I'+str(out/'source'),'-include',str(out/'original_fixture.hpp'),str(core/'session.cpp'),str(out/'tests.cpp'),str(out/'original.cpp'),'-o',str(binary)];record['command']=command
  c=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'compile'
  c=subprocess.run([str(binary)],env=env,capture_output=True,text=True,timeout=90);(out/'run.txt').write_text(c.stdout+c.stderr,encoding='utf8',newline='\n');assert c.returncode==0,'original comparison'
  result=json.loads(c.stdout);assert result['rng_requests']==655360 and result['option_cases']==4096
  assert all(sha(ROOT/n)==v for n,v in before.items())
  record.update(status='native shared RNG and options match all six original bodies',result=result,source_unchanged=True,binary_sha256=sha(binary),limits=['Clock, audio and rendering observers are declared service ports; their effects remain to migrate.','No actual game owner/callers are replaced by this component comparison.'])
 finally:
  record['output_sha256']={f.relative_to(out).as_posix():sha(f) for f in out.rglob('*') if f.is_file() and f.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8',newline='\n')
 print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
