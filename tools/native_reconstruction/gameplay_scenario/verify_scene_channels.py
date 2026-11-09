"""Complete original scene-channel mask commands versus native owner."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def run(cmd,out,label):
 p=subprocess.run(cmd,capture_output=True,text=True,timeout=120);(out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
 if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-5000:])
 return dict(command=cmd,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
 cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 text=[];original={};comments=0
 for ident in ['00690340','00690370','006903A0','006903C0']:
  p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));s=p.read_text();original[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
  for pc,w in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',s):assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(w,16);comments+=1
  text.append('\n'.join(l for l in s.splitlines() if not l.startswith('#include')))
 s='\n'.join(text);names=sorted(set(re.findall(r'\b(o2_[A-Za-z0-9_]+)\(',s)));(out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names)+'\n')
 fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000');fixture+='\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n'
 (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+s)
 paths=[ROOT/'game/native/gameplay_scenario/scene_channels.hpp',HERE/'scene_channel_tests.cpp',Path(__file__)];before={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
 for p in paths:shutil.copyfile(p,out/p.name)
 os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
 checks=[run(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original'),run(base+['-Wall','-Wextra','-Wpedantic','-Werror',str(out/'scene_channel_tests.cpp'),str(out/'original.o'),'-o',str(out/'checks.exe')],out,'compile-tests'),run([str(out/'checks.exe')],out,'test')]
 assert all(sha(ROOT/p)==d for p,d in before.items());receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=original,checked_owned_instruction_comments=comments,checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),game_launched=False,installed_in_game=False,limitations=['Canonical scene-channel mask only; actual native channel program evaluation/renderer consumption is not implemented.','Original memory/register fixture is offline comparison scaffolding only.'])
 (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'],instruction_comments=comments)))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
