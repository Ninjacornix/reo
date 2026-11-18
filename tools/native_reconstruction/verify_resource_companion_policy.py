"""Focused complete654720 policy comparison; effect/task/audio ports are intents."""
import argparse,hashlib,json,os,re,struct,subprocess
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',choices=COMPILERS,required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 image=ROOT/'game_data/SLUS_207.65';assert sha(image)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(image.read_bytes());banks={}
 for name,digest in [('o0','bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2'),('o2','45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226')]:
  file=ROOT/'build-function-index/owned-overlays'/f'{name}.bin';assert sha(file)==digest;banks[name]=file.read_bytes()
 ports={0x652880,0x652d60,0x651d00,0x654180,0x6b2680,0x1b8c70};pending=[0x654720];entries={};proof=[]
 while pending:
  at=pending.pop()
  if at in entries or at in ports:continue
  bank='sub' if at<0x370000 else 'o0' if at<0x570000 else 'o2';folder=ROOT/('recomp/config/output' if bank=='sub' else 'recomp/config/output_ovl/'+bank);file=next(folder.glob(f'{bank}_{at:08X}_*'));name=file.relative_to(ROOT).as_posix();entries[at]=name;body=file.read_text();begin,end=[int(x,16) for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups()];reader=read if bank=='sub' else lambda a,n,bank=bank:banks[bank][a-(0x370000 if bank=='o0' else 0x570000):a-(0x370000 if bank=='o0' else 0x570000)+n];proof.append(compare_source('complete resource-companion state body/helper; effect consumers excluded',name,begin,end,reader));pending.extend(int(v,16) for v in re.findall(r'// 0x[0-9a-f]+: 0x[0-9a-f]+\s+(?:jal|j)\s+func_([0-9A-Fa-f]+)',body))
 units=['game/native/'+n for n in ['gameplay_effects/resource_companion.cpp','transform_math/transform_math.cpp','gameplay_session/session.cpp']];fixture='tools/native_reconstruction/resource_companion_policy_tests.cpp';inc='tools/native_reconstruction/resource_companion_policy_tests.inc';helper='tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';files=list(dict.fromkeys(units+list(entries.values())+[fixture,inc,helper,Path(__file__).relative_to(ROOT).as_posix()]))
 for name in units:
  for include in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
   target=((ROOT/name).parent/include).resolve();assert target.is_file() and target.is_relative_to(ROOT);relative=target.relative_to(ROOT).as_posix()
   if relative not in files:files.append(relative)
 for name in list(files):
  if name.startswith('game/native/'):
   for include in re.findall(r'^\s*#include "([^"]+)"',(ROOT/name).read_text(),re.M):
    target=((ROOT/name).parent/include).resolve();relative=target.relative_to(ROOT).as_posix()
    if relative not in files:files.append(relative)
 frozen={name:(ROOT/name).read_bytes() for name in files};out.mkdir(parents=True)
 for name,body in frozen.items():target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes(body)
 reference=frozen[helper].decode().replace('pc{},branch_pc{},fcr31{}','pc{},branch_pc{},fcr31{},vu0_vpu_stat{}').replace('Register r[32];','Register r[32];std::uint64_t lo{},hi{};');reference+='\n#define GPR_S32(c,n) std::bit_cast<std::int32_t>(GPR_U32(c,n))\n#define SRA32(a,b) (static_cast<std::int32_t>(a) >> (static_cast<std::uint32_t>(b)&31))\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define FPU_C_LT_S(a,b) ((a)<(b))\n';(out/'reference.hpp').write_text(reference);body='\n'.join(frozen[n].decode() for n in entries.values());(out/'original_visuals.cpp').write_text(body);actual={Path(n).stem for n in entries.values()};names=set(re.findall(r'\b((?:sub|o0|o2)_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);\n' for n in sorted(actual));decl+=''.join(f'inline void {n}(std::uint8_t* m,R5900Context* c,PS2Runtime* r){{original_transform_port(m,c,r);}}\n' for n in sorted(names-actual));(out/'functions.h').write_text('#pragma once\n'+decl);(out/'original_dispatch.hpp').write_text(''.join(f'case {at}:{Path(n).stem}(memory,context,runtime);return;\n' for at,n in entries.items()))
 for name in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/name).write_text('#pragma once\n#include "reference.hpp"\n')
 for name in ['o0_functions.h','o2_functions.h','ps2_recompiled_functions.h']:(out/name).write_text('#pragma once\n#include "functions.h"\n')
 for name in ['ps2_recompiled_stubs.h','ps2_stubs.h','ps2_syscalls.h']:(out/name).write_text('#pragma once\n')
 constants='inline void owned_constants(std::uint8_t* memory){'
 for at,n in [(0x7401b0,28),(0x7401d0,28)]:
  values=banks['o2'][at-0x570000:at-0x570000+n];constants+='{const std::uint8_t bytes[]{'+','.join(str(v)for v in values)+'};std::memcpy(memory+'+str(at)+',bytes,sizeof bytes);}'
 (out/'owned_constants.hpp').write_text(constants+'}\n');cc=COMPILERS[args.compiler];exe=out/'policy.exe';cmd=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source'),*[str(out/'source'/n)for n in units],str(out/'source'/fixture),'-o',str(exe)];env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');record={'schema':1,'status':'failed','game_run':False,'installed_in_game':False,'stage4_complete':False,'actual_companion_consumers':False,'source_sha256':{n:hashlib.sha256(b).hexdigest()for n,b in frozen.items()},'compiler_sha256':sha(cc),'original_word_audits':proof,'declared_ports':['652880 child rendering,652D60/651D00 retirement,654180 child fade,6B2680 light-task request and1B8C70 resource audio are captured intents; real integration remains open'],'command':cmd}
 try:
  for label,command in [('compile',cmd),('run',[str(exe)])]:
   result=subprocess.run(command,capture_output=True,env=env,timeout=90);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);assert result.returncode==0,label+' failed; see retained logs'
   if label=='run':record['observed']=json.loads(result.stdout)
  record['source_unchanged']=all((ROOT/n).read_bytes()==b for n,b in frozen.items());assert record['source_unchanged'];record.update(status='passed',binary_sha256=sha(exe))
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(record['observed']))
if __name__=='__main__':main()
