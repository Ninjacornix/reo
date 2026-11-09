"""Real save/session entry adapters against byte-verified original entry bodies.
The SDK, source bank, clock and media observers are explicit offline fixture ports.
"""
import argparse,hashlib,json,os,re,shutil,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import elf_reader,compare_source
from observations import parse as parse_observations
ADAPTER=ROOT/'recomp/overrides/native_gameplay'
ENTRIES=[(0x1c5410,'capture'),(0x1c55c0,'restore'),(0x1c5630,'clear_second'),(0x1aec50,'seed'),(0x1aec80,'random'),(0x1aed60,'defaults'),(0x1aedb0,'capture_options'),(0x1aee40,'sanitize'),(0x1badf0,'restore_options')]
PROVIDERS=[(0x1bf660,0x1c5438,0x40),(0x1b8290,0x1aed9c,0x10),(0x1af790,0x1bae8c,0x10),(0x1b86c0,0x1bae98,0x10),(0x1b86f0,0x1baea4,0x10),(0x1b8780,0x1baeb0,0x10)]
SAVE_IDS=['001C52B0','001C5300','001C5340','001C53B0','001C5410','001C5480','001C54E0','001C5500','001C5520','001C55C0','001C5630','001C56A0','001C5760']
def source(at):return next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'))
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def invoke(cmd,out,label,env):
 r=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf8');assert r.returncode==0,label+': '+r.stderr[-3000:];return dict(command=cmd,exit_code=r.returncode,log_sha256=sha(out/(label+'.txt')))
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path);p.add_argument('--output',type=Path);p.add_argument('--write-admission',action='store_true');a=p.parse_args()
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes())
 proof=[];hashlines=[]
 for at in dict.fromkeys([v[0] for v in ENTRIES+PROVIDERS]):
  src=source(at);begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];proof.append(compare_source('native save/session adapter admission',src.relative_to(ROOT).as_posix(),begin,end,read));hashlines.append(f'H(0x{begin:x},0x{end-begin:x},"{hashlib.sha256(read(begin,end-begin)).hexdigest()}")')
 hashlines.append('H(0x24fe30,16,"'+hashlib.sha256(read(0x24fe30,16)).hexdigest()+'")')
 expected={'entries.inc':'\n'.join(f'X(0x{at:x},{source(at).stem},{kind})' for at,kind in ENTRIES)+'\n','providers.inc':'\n'.join(f'P(0x{at:x},{source(at).stem},0x{back:x},0x{depth:x})' for at,back,depth in PROVIDERS)+'\n','image.inc':'\n'.join(hashlines)+'\n'}
 for name,text in expected.items():
  if a.write_admission:(ADAPTER/name).write_text(text,encoding='utf8',newline='\n')
  assert (ADAPTER/name).read_text()==text
 if a.write_admission:return
 assert a.compiler and a.output
 out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 original_sources=[source(int(s,16)) for s in SAVE_IDS]+[source(v) for v,k in ENTRIES if v<0x1c0000]
 original_proof=[]
 for src in original_sources:
  begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];original_proof.append(compare_source('executed original save/session oracle',src.relative_to(ROOT).as_posix(),begin,end,read))
 caller_inventory=ROOT/'tools/native_reconstruction/gameplay_save_qualification_v1.json';caller_q=json.loads(caller_inventory.read_bytes());caller_proof=[]
 for row in caller_q['caller_inventory']:
  src=ROOT/row['source'];assert sha(src)==row['source_sha256'];begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];checked=compare_source('real save caller ABI inventory',row['source'],begin,end,read)
  sites=[]
  for site in row['sites']:
   pc=int(site['pc'],16);assert int.from_bytes(read(pc,4),'little')==int(site['instruction'],16);sites.append(dict(site,return_pc=hex(pc+8),return_window_hex=read(pc+8,16).hex()))
  caller_proof.append(dict(source=checked,sites=sites))
 texts=[s.read_text() for s in original_sources];body='\n'.join('\n'.join(l for l in t.splitlines() if not l.startswith('#include')) for t in texts)
 defined=set(re.findall(r'void (sub_[A-Za-z0-9_]+)\(',body));calls=set(re.findall(r'\b(sub_[A-Za-z0-9_]+)\(rdram',body));missing=calls-defined
 declarations='\n'.join('void '+s+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for s in sorted(defined|calls|{source(p[0]).stem for p in PROVIDERS}))+'\n'
 (out/'original_declarations.inc').write_text(declarations);(out/'original.cpp').write_text('#include "fixture.hpp"\n#include "original_declarations.inc"\n'+body)
 special={'sub_00107AB0_0x107ab0','sub_00107C68_0x107c68'}|{source(v[0]).stem for v in PROVIDERS}
 (out/'unreached.cpp').write_text('#include "fixture.hpp"\n'+''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unreached original dependency '+n+'");}\n' for n in sorted(missing-special)))
 (out/'fixture.hpp').write_bytes((HERE/'fixture.hpp').read_bytes());(out/'tests.cpp').write_bytes((HERE/'tests.cpp').read_bytes())
 for h in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/h).write_text('#pragma once\n#include "fixture.hpp"\n')
 (out/'source_instruction_access.hpp').write_text('#pragma once\n#include "fixture.hpp"\nnamespace reo_source_instrumentation {inline thread_local PS2Runtime* current{};class EntryScope {PS2Runtime* prior;public:EntryScope(PS2Runtime* r,R5900Context*):prior(current){current=r;}~EntryScope(){current=prior;}};inline std::uint64_t copies{},writes{};inline void* copyBytesForBank(const void* ram,void* dst,const void* src,std::size_t bytes){if(!current||current->storage.ram!=ram||!current->depth.load())throw std::runtime_error("Declared bank scope missing");++copies;const auto p=reinterpret_cast<std::uintptr_t>(dst),r=reinterpret_cast<std::uintptr_t>(ram);if(p>=r&&p-r<0x2000000){++writes;if(fixture_before_write)fixture_before_write(ram,std::uint32_t(p-r),bytes);}return std::memcpy(dst,src,bytes);}}\n')
 frozen=out/'source';paths=list(ADAPTER.glob('*'))+[ROOT/'game/native/gameplay_save'/n for n in ['snapshot.hpp','snapshot.cpp']]+[ROOT/'game/native/gameplay_session'/n for n in ['session.hpp','session.cpp']]+[Path(__file__),HERE/'observations.py',HERE/'fixture.hpp',HERE/'tests.cpp',ROOT/'recomp/overrides/native_geometry/reo_vu_native_sha256.h',caller_inventory]+[ROOT/row['source'] for row in caller_q['caller_inventory']]+original_sources
 inputs={f.relative_to(ROOT).as_posix():sha(f) for f in paths if f.is_file()}
 for f in paths:
  if f.is_file():target=frozen/f.relative_to(ROOT);target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(f,target)
 # Load only the verified text/table admission ranges; all mutable bytes are
 # deterministic test state. No dumped or running guest state is consumed.
 ram=bytearray(0x2000000)
 for h in hashlines:
  at,count=re.match(r'H\((0x[0-9a-f]+|[0-9]+),(0x[0-9a-f]+|[0-9]+),',h).groups();at,count=int(at,0),int(count,0);ram[at:at+count]=read(at,count)
 (out/'admission-ram.bin').write_bytes(ram)
 env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
 common=[str(a.compiler),'-std=c++20','-O2','-I'+str(out),'-I'+str(frozen),'-DREO_BUILD_NATIVE_GAMEPLAY_SAVE=1']
 record=dict(schema=1,status='failed',compiler=str(a.compiler),compiler_sha256=sha(a.compiler),source_sha256=inputs,owned_elf_sha256=sha(elf),admission_proof=proof,executed_original_proof=original_proof,original_save_caller_proof=caller_proof,game_run=False,live_process_access=False,checks=[])
 try:
  for label,path in [('original',out/'original.cpp'),('unreached',out/'unreached.cpp'),('adapter',frozen/'recomp/overrides/native_gameplay/save_session.cpp'),('save',frozen/'game/native/gameplay_save/snapshot.cpp'),('session',frozen/'game/native/gameplay_session/session.cpp'),('tests',out/'tests.cpp')]:
   flags=['-w'] if label=='original' else ['-Wall','-Wextra','-Wpedantic','-Werror'];record['checks'].append(invoke(common+flags+['-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label,env))
  record['checks'].append(invoke([str(a.compiler)]+[str(out/(n+'.o')) for n in ['original','unreached','adapter','save','session','tests']]+['-o',str(out/'checks.exe')],out,'link',env))
  record['checks'].append(invoke([str(out/'checks.exe'),str(out/'admission-ram.bin')],out,'run',env));record['result']=json.loads((out/'run.txt').read_text().splitlines()[0]);observed=parse_observations((out/'run.txt').read_text(),require_fixture=True);(out/'observations.json').write_text(json.dumps(observed,indent=2)+'\n');record['observations']={key:value for key,value in observed.items()if key not in ['groups','limits']};assert all(sha(ROOT/k)==v for k,v in inputs.items());record['status']='passed'
 finally:
  record['artifacts_sha256']={f.relative_to(out).as_posix():sha(f) for f in out.rglob('*') if f.is_file() and f.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps({'status':record['status'],'result':record['result'],'receipt_sha256':sha(out/'receipt.json')}))
if __name__=='__main__':main()
