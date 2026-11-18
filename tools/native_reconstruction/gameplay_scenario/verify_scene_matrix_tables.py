"""Compare compiled native immutable values with independently decoded owned data."""
import argparse,hashlib,json,os,subprocess,shutil
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=a.compiler.resolve();out=a.output.resolve();assert cc.exists()and not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 evidence=ROOT/'build-native-sjuni/gameplay-scene-matrix-tables-v1';receipt=json.loads((evidence/'receipt.json').read_text());assert receipt['status']=='passed'
 for n,h in receipt['output_sha256'].items():assert sha(evidence/n)==h
 assert sha(ROOT/'game/native/gameplay_scenario/scene_matrix_program_tables.inc')==receipt['output_sha256']['scene_matrix_program_tables.inc'];t=json.loads((evidence/'tables.json').read_text());expected=list(t['descriptors'])+sum(t['metadata'],[])+t['direct_remap']
 for p in t['programs']:expected += [p['transform'],len(p['groups'])]+p['groups']+[0]*(6-len(p['groups']))
 for g in t['groups']:expected += g['curves']+g['sounds']
 for curve in t['curves']:expected += [len(curve)]+sum(([k['value_bits'],k['time']]for k in curve),[])
 for sound in t['sounds']:expected += [len(sound)]+sum(([k['event'],k['time']]for k in sound),[])
 source=[ROOT/'game/native/gameplay_scenario'/n for n in ['scene_matrix_tables.hpp','scene_matrix_tables.cpp','scene_matrix_program_tables.inc']]+[Path(__file__),HERE/'scene_matrix_table_tests.cpp',HERE/'collect_scene_matrix_tables.py'];before={p.relative_to(ROOT).as_posix():sha(p)for p in source};out.mkdir()
 for p in source:shutil.copyfile(p,out/p.name)
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');exe=out/'checks.exe';cmd=[str(cc),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(ROOT),str(ROOT/'game/native/gameplay_scenario/scene_matrix_tables.cpp'),str(HERE/'scene_matrix_table_tests.cpp'),'-o',str(exe)];checks=[]
 for label,command in [('compile',cmd),('native-values',[str(exe)])]:
  result=subprocess.run(command,capture_output=True,text=True,env=env,timeout=120);(out/(label+'.stdout.txt')).write_text(result.stdout);(out/(label+'.stderr.txt')).write_text(result.stderr);checks.append(dict(label=label,exit_code=result.returncode,command=command));assert result.returncode==0,result.stderr[-4000:]
 actual=json.loads((out/'native-values.stdout.txt').read_text());assert actual==expected
 for p,h in before.items():assert sha(ROOT/p)==h,p
 result=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,owned_data_receipt=dict(path=(evidence/'receipt.json').relative_to(ROOT).as_posix(),sha256=sha(evidence/'receipt.json')),checked_native_values=len(expected),native_value_sha256=sha(out/'native-values.stdout.txt'),executable_sha256=sha(exe),checks=checks,game_launched=False,installed_in_game=False,live_process_access=False,limitations=['Immutable native data qualification only; actual matrix selector, evaluator and native model consumer remain separate.','Descriptor admission is the verified four-byte profile.']);(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',checked_native_values=len(expected))))
if __name__=='__main__':main()
