"""Compare shared native scene allocation/order/retirement with complete owned bodies."""
import argparse,hashlib,json,os,re,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();cc=a.compiler.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';image=overlay.read_bytes();sources=[Path(__file__),ROOT/'game/native/gameplay_scene/record_pool.hpp',Path(__file__).with_name('shared_record_pool_tests.cpp'),ROOT/'tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp'];text=[];proof=[];names=[]
 for at in [0x5c1120,0x5c11b0,0x5c12a0]:
  name=f'o2_{at:08X}_0x{at:x}';path=ROOT/f'recomp/config/output_ovl/o2/{name}.cpp';t=path.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('complete shared128 allocator',path.relative_to(ROOT).as_posix(),begin,end,lambda at,n:image[at-0x570000:at-0x570000+n]));sources.append(path);text.append('\n'.join(l for l in t.splitlines()if not l.startswith('#include')));names.append(name)
 hashes={p.relative_to(ROOT).as_posix():sha(p)for p in sources}
 (out/'original_fixture.hpp').write_bytes(sources[3].read_bytes());(out/'original_declarations.inc').write_text('\n'.join(f'void {n}(std::uint8_t*,R5900Context*,PS2Runtime*);'for n in names)+'\n');(out/'original.cpp').write_text('#include "original_fixture.hpp"\n'+ '\n'.join(text));(out/'tests.cpp').write_bytes(sources[2].read_bytes())
 for name in hashes:
  dest=out/'source'/name;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/name).read_bytes())
 env=dict(os.environ);env['PATH']=str(cc.parent)+os.pathsep+env.get('PATH','');base=[str(cc),'-std=c++20','-O2','-msse4.1','-I'+str(out/'source'),'-I'+str(out)];cmds=[('original',base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')]),('test',base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(out/'tests.cpp'),'-o',str(out/'tests.o')]),('link',[str(cc),str(out/'original.o'),str(out/'tests.o'),'-o',str(out/'checks.exe')]),('run',[str(out/'checks.exe')])];receipt=dict(status='failed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=hashes,owned_overlay_sha256=sha(overlay),original_word_audits=proof,checks=[],game_launched=False,installed_in_game=False)
 try:
  for name,cmd in cmds:
   r=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=180);(out/f'{name}.stdout.txt').write_text(r.stdout);(out/f'{name}.stderr.txt').write_text(r.stderr);receipt['checks'].append(dict(label=name,exit_code=r.returncode,command=cmd));assert r.returncode==0,r.stderr[-4000:]
  receipt['result']=json.loads((out/'run.stdout.txt').read_text());assert all(sha(ROOT/n)==v for n,v in hashes.items());receipt.update(status='passed',executable_sha256=sha(out/'checks.exe'))
 finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
 print(json.dumps(receipt['result']))
if __name__=='__main__':main()
