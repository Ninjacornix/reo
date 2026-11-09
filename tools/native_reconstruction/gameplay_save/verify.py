"""Owned instruction/table validation and focused native/original save parity."""
import argparse,hashlib,json,os,re,shutil,struct,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
IDS=['001C52B0','001C5300','001C5340','001C53B0','001C5410','001C5480','001C54E0','001C5500','001C5520','001C55C0','001C5630','001C56A0','001C5760']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def invoke(command,out,label):
    p=subprocess.run(command,capture_output=True,text=True,timeout=180)
    (out/(label+'.stdout.txt')).write_text(p.stdout);(out/(label+'.stderr.txt')).write_text(p.stderr)
    if p.returncode:raise RuntimeError(label+' failed: '+p.stderr[-4000:])
    return dict(command=command,exit_code=p.returncode,stdout_sha256=sha(out/(label+'.stdout.txt')),stderr_sha256=sha(out/(label+'.stderr.txt')))
def main(args):
    cc=Path(args.compiler).resolve();out=args.output.resolve()
    assert cc.exists() and not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
    out.mkdir(parents=True)
    elf=ROOT/'build-native-sjuni/launcher-native-prep-v1/imports/file1/25e64b631bbaa0cac9a4822cb66174ff14c3531851d1e502c0a06704379bf446/data/SLUS_207.65'
    assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    raw=elf.read_bytes();assert raw[:6]==b'\x7fELF\x01\x01'
    phoff=struct.unpack_from('<I',raw,28)[0];size,count=struct.unpack_from('<HH',raw,42)
    loads=[struct.unpack_from('<IIIIIIII',raw,phoff+i*size) for i in range(count)]
    loads=[p for p in loads if p[0]==1]
    def word(at):
        p=next(p for p in loads if p[2]<=at and at+4<=p[2]+p[4]);return struct.unpack_from('<I',raw,p[1]+at-p[2])[0]
    sources=[];comments=0;texts=[]
    for ident in IDS:
        path=next((ROOT/'recomp/config/output').glob('sub_'+ident+'_*'));text=path.read_text()
        for pc,instruction in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):
            assert word(int(pc,16))==int(instruction,16),(path,pc);comments+=1
        sources.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path)))
        shutil.copyfile(path,out/path.name)
        texts.append('\n'.join(line for line in text.splitlines() if not line.startswith('#include')))
    alltext='\n'.join(texts)
    names=sorted(set(re.findall(r'\b(sub_[A-Za-z0-9_]+)\(',alltext)))
    (out/'original_declarations.inc').write_text('\n'.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);' for n in names)+'\n')
    (out/'original.cpp').write_text('#include "original_fixture.hpp"\n#include "original_declarations.inc"\n'+alltext)
    # Scenario inventory is structural provenance, with an explicitly zero native mask.
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin'
    assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    owned=overlay.read_bytes();table=struct.unpack_from('<432I',owned,0x717830-0x570000)
    assert len(set(table))==213 and table.count(0x68cd80)==220
    scenario=dict(owned_image_sha256=sha(overlay),table_address='0x717830',slots=432,default_slots=220,nondefault_slots=212,distinct_targets=213,
        next_word=hex(struct.unpack_from('<I',owned,0x717ef0-0x570000)[0]),native_opcodes_implemented=0,native_mask=[False]*432,
        warning='Body-mapping coverage is not native opcode execution coverage. No partial native interpreter replaces this table.',
        handlers=[dict(opcode=i,original_handler=hex(target),native=False) for i,target in enumerate(table)])
    (out/'scenario-inventory.json').write_text(json.dumps(scenario,indent=2)+'\n')
    for name in ('original_fixture.hpp','tests.cpp'):shutil.copyfile(HERE/name,out/name)
    for name in ('snapshot.hpp','snapshot.cpp'):shutil.copyfile(ROOT/'game/native/gameplay_save'/name,out/name)
    envbin=str(cc.parent);os.environ['PATH']=envbin+os.pathsep+os.environ.get('PATH','')
    base=[str(cc),'-std=c++20','-O2','-I'+str(ROOT),'-I'+str(out)]
    checks=[invoke(base+['-w','-c',str(out/'original.cpp'),'-o',str(out/'original.o')],out,'compile-original')]
    for label,path in [('native',ROOT/'game/native/gameplay_save/snapshot.cpp'),('tests',out/'tests.cpp')]:
        checks.append(invoke(base+['-Wall','-Wextra','-Wpedantic','-Werror','-c',str(path),'-o',str(out/(label+'.o'))],out,'compile-'+label))
    checks.append(invoke([str(cc),str(out/'original.o'),str(out/'native.o'),str(out/'tests.o'),'-o',str(out/'checks.exe')],out,'link'))
    checks.append(invoke([str(out/'checks.exe')],out,'test'))
    result=json.loads((out/'test.stdout.txt').read_text())
    inputs={p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),HERE/'tests.cpp',HERE/'original_fixture.hpp',ROOT/'game/native/gameplay_save/snapshot.cpp',ROOT/'game/native/gameplay_save/snapshot.hpp']}
    assert all(sha(ROOT/p)==v for p,v in inputs.items())
    receipt=dict(schema=1,status='passed',compiler=str(cc),compiler_sha256=sha(cc),owned_elf_sha256=sha(elf),owned_overlay_sha256=sha(overlay),
        checked_original_instruction_comments=comments,original_sources=sources,source_sha256=inputs,checks=checks,result=result,
        scenario_inventory_sha256=sha(out/'scenario-inventory.json'),game_launched=False,live_process_access=False,game_adapter_installed=False,
        original_fixture='Actual generated original function bodies execute with bounded integer-register/memory scaffolding and explicit memcpy/time/RNG/notify dependency doubles, all instruction comments verified against owned ELF. This is an offline comparison oracle, not a shipped MIPS interpreter.',
        limitations=['No original card image loaded or rewritten. No claimed full native scenario VM, cardUI, filesystem or co-op migration.',
            'Original decoder source includes an adjacent icon-loading body; its dependencies throw if reached, and decoder returns before it in every qualified case.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status='passed',checks=result,owned_instruction_comments=comments,output=str(out))))
if __name__=='__main__':
    p=argparse.ArgumentParser();p.add_argument('--compiler',required=True);p.add_argument('--output',required=True,type=Path);main(p.parse_args())
