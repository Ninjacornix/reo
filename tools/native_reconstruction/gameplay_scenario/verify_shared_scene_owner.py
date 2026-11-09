"""Freeze and verify the actual script/collision composition, without a game."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=a.compiler.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 units=[ROOT/'game/native/gameplay_collision'/n for n in ['collision.cpp','response.cpp','sweep.cpp','actors.cpp','ownership.cpp']]+[ROOT/'game/native/gameplay_scenario/scene_controls.cpp',ROOT/'game/native/gameplay_session/session.cpp',ROOT/'game/native/gameplay_actors/entity.cpp',Path(__file__).with_name('shared_scene_owner_tests.cpp')]
 pending=units+[Path(__file__)];closure=set(pending)
 while pending:
  path=pending.pop()
  for name in re.findall(r'#include "([^"\n]+)"',path.read_text()):
   inc=next((p.resolve()for p in [path.parent/name,ROOT/name]if p.exists()),None)
   if inc and inc not in closure:closure.add(inc);pending.append(inc)
 hashes={p.relative_to(ROOT).as_posix():sha(p)for p in sorted(closure)}
 for name in hashes:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/name).read_bytes())
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');base=[str(cc),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source')];cmds=[]
 for i,path in enumerate(units):cmds.append((str(i),base+['-c',str(out/'source'/path.relative_to(ROOT)),'-o',str(out/f'{i}.o')]))
 cmds+=[('link',[str(cc),*[str(out/f'{i}.o')for i in range(len(units))],'-o',str(out/'checks.exe')]),('run',[str(out/'checks.exe')])];receipt=dict(status='failed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=hashes,checks=[],game_launched=False,installed_in_game=False)
 try:
  for name,cmd in cmds:
   r=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/f'{name}.stdout.txt').write_text(r.stdout);(out/f'{name}.stderr.txt').write_text(r.stderr);receipt['checks'].append(dict(label=name,exit_code=r.returncode,command=cmd));assert r.returncode==0,r.stderr[-4000:]
  receipt['result']=json.loads((out/'run.stdout.txt').read_text());assert all(sha(ROOT/n)==v for n,v in hashes.items());receipt.update(status='passed',executable_sha256=sha(out/'checks.exe'))
 finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
 print(json.dumps(receipt['result']))
if __name__=='__main__':main()
