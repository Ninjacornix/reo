"""Native linked-control ownership versus complete original script handlers."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
IDS=['0068E630','0068E6D0','0068E730','0068E800','0068E8B0','0068E920','0068E9E0','0068EA70','0068EB30','0068EBF0','0068ECC0','0068ED30','0068EDA0','0068EE30','0068EEC0','0068F5C0','00691F00','00690810']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def invoke(command,out,label):
    p=subprocess.run(command,capture_output=True,text=True,timeout=120)
    (out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
    if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-5000:])
    return dict(command=command,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(a):
    cc=Path(a.compiler).resolve();out=a.output.resolve();assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    texts=[];sources={};words=0
    for ident in IDS:
        p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+ident+'_*'));text=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p);shutil.copyfile(p,out/p.name)
        for pc,opcode in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(opcode,16);words+=1
        texts.append('\n'.join(l for l in text.splitlines() if not l.startswith('#include')))
    text='\n'.join(texts);names=sorted(set(re.findall(r'\b((?:o2|sub)_[A-Za-z0-9_]+)\(',text)))
    (out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names)+'\n')
    fixture=(ROOT/'tools/native_reconstruction/gameplay_save/original_fixture.hpp').read_text().replace('0x400000','0x800000').replace('#include <cstdint>','#include <cstdint>\n#include <array>')
    fixture+='\n#define WRITE32(a,v) fixture_write<std::uint32_t>(rdram,a,v)\n'
    (out/'original_fixture.hpp').write_text(fixture);(out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+text)
    paths=[HERE/'scene_control_tests.cpp',Path(__file__),ROOT/'game/native/gameplay_scenario/scene_controls.hpp',ROOT/'game/native/gameplay_scenario/scene_controls.cpp']
    paths += [ROOT/'game/native/gameplay_session/session.hpp',ROOT/'game/native/gameplay_session/session.cpp',ROOT/'game/native/gameplay_scenario/action_choices.hpp']
    before={p.relative_to(ROOT).as_posix():sha(p) for p in paths}
    for p in paths:shutil.copyfile(p,out/p.name)
    os.environ['PATH']=str(cc.parent)+os.pathsep+os.environ.get('PATH','');base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
    checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
    for label,path in [('session',ROOT/'game/native/gameplay_session/session.cpp'),('core',ROOT/'game/native/gameplay_scenario/scene_controls.cpp'),('tests',out/'scene_control_tests.cpp')]:checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label))
    checks.append(invoke([str(cc)]+[str(out/(n+'.o')) for n in ['original','session','core','tests']]+['-o',str(out/'checks.exe')],out,'link'))
    checks.append(invoke([str(out/'checks.exe')],out,'test'));assert all(sha(ROOT/n)==digest for n,digest in before.items())
    receipt=dict(status='passed',compiler=str(cc),compiler_sha256=sha(cc),source_sha256=before,original_sources_sha256=sources,checked_owned_instruction_comments=words,checks=checks,result=json.loads((out/'test.stdout.txt').read_text()),
        installed_in_game=False,game_launched=False,limitations=['Native typed linked-control state and command algorithms only; actual content importer, renderer and consumers are not migrated.','No new interpreter opcode is admitted by this independent owner qualification.','Reset and refresh implementations are explicit effect doubles, not original implementations in production.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status='passed',result=receipt['result'],instruction_comments=words,output=str(out))))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
