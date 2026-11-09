"""Complete original binding copies versus native targets, generations and cleanup."""
import argparse,hashlib,json,os,re,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 paths=[next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))for at in [0x5d8280,0x5d8300]];authority=paths+[next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'))for at in [0x6ad9b0,0x6adab0,0x6ae390]];proof=[]
 for p in authority:
  start,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',p.read_text()).groups()];proof.append(compare_source('full binding body or caller full-pose/mark contract',p.relative_to(ROOT).as_posix(),start,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
 reference=ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp';test=HERE/'scene_model_binding_tests.cpp'
 native=[ROOT/p for p in ['game/native/gameplay_scenario/scene_models.cpp','game/native/gameplay_scenario/scene_model_bindings.cpp','game/native/gameplay_scenario/content.cpp','game/native/transform_math/transform_math.cpp','game/native/gameplay_actors/entity.cpp']]
 pending=native+[reference,test,Path(__file__),*authority];closure=set(p.resolve()for p in pending)
 while pending:
  p=pending.pop()
  for included in re.findall(r'#include "([^"]+)"',p.read_text()):
   candidate=next((x.resolve()for x in [p.parent/included,ROOT/included]if x.exists()),None)
   if candidate and candidate.is_relative_to(ROOT/'game/native')and candidate not in closure:closure.add(candidate);pending.append(candidate)
 sources={p.relative_to(ROOT).as_posix():sha(p)for p in sorted(closure)}
 for name in sources:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/name).read_bytes())
 (out/'reference.hpp').write_text(reference.read_text()+'\n#define GPR_S32(c,n) (std::bit_cast<std::int32_t>(GPR_U32(c,n)))\n#define SRA32(a,b) (std::int32_t(a)>>(b))\n');(out/'tests.cpp').write_bytes(test.read_bytes());body='\n'.join('\n'.join(line for line in p.read_text().splitlines()if not line.startswith('#include'))for p in paths);(out/'original_models.cpp').write_text(body)
 (out/'functions.h').write_text('#pragma once\n'+''.join('void '+p.stem+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for p in paths))
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');binary=out/'checks.exe';command=[str(cc),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-fno-fast-math','-ffp-contract=off','-I'+str(out),'-I'+str(out/'source')]+[str(out/'source'/p.relative_to(ROOT))for p in native]+[str(out/'tests.cpp'),'-o',str(binary)]
 record=dict(status='failed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=sources,original_word_audits=proof,command=command,game_launched=False,live_process_access=False,installed_in_game=False,owned_room_import_exercised=False)
 try:
  result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=180);(out/'compile.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'compile failed; see '+str(out/'compile.txt')
  result=subprocess.run([str(binary)],cwd=out,env=env,capture_output=True,text=True,timeout=180);(out/'run.txt').write_text(result.stdout+result.stderr);assert result.returncode==0,'comparison failed; see '+str(out/'run.txt')
  observed=json.loads(result.stdout);assert observed['binding_cases']==512 and observed['lifetime_cases']>=9;assert all(sha(ROOT/p)==h for p,h in sources.items()),'source drift'
  record.update(status='passed',result=observed,binary_sha256=sha(binary),limitations=['Complete5D8280/5D8300 bodies execute for512 declared synthetic pose/slot cases; caller constructors/mark/retention are separate static source authority until the full real-provider composition cohort.','Native storage retains strong typed targets and rejects foreign/stale generations; original dangling/foreign pointer misuse is not reproduced.','All sixteen pose bits are retained, including unused W and nonfinite copied values; no exceptional arithmetic behavior is claimed.','Sticky errors remain visible during valid-slot cleanup; callbacks cannot republish targets during mutation or shutdown.','No game caller, renderer or runtime performance is qualified.'])
 finally:
  record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps(dict(status=record['status'],result=record.get('result'),receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
