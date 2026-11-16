"""Compare ordinary actor entry and room-claim encoding against owned bodies."""
import argparse,hashlib,json,os,re,shutil,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--snapshot',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve();out.mkdir(parents=True,exist_ok=False);snapshot=args.snapshot.resolve()
    manifest=json.loads((snapshot/'receipt.json').read_text());assert manifest['status']=='passed'
    compiler=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    for name,digest in manifest['source_sha256'].items():assert sha(snapshot/'source'/name)==digest,name
    for name,digest in manifest['archives_sha256'].items():assert sha(snapshot/'native-build'/name)==digest,name
    shutil.copytree(snapshot/'source',out/'source')
    inputs=[Path(__file__).resolve(),ROOT/'tools/native_reconstruction/ordinary_action_entry_tests.cpp',ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp']
    for name in ['game/native/gameplay_world/ordinary_action_entry.hpp','game/native/gameplay_update/room_publication.hpp','third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(ROOT/name,target);inputs.append(ROOT/name)
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    bodies=[];audits=[];symbols=[];images={}
    entries=[('o2',0x66b8e0),('o2',0x61a620),('main',0x1aff90),('o9',0x811970),('o8',0x811140)]
    for family,entry in entries:
        if family=='main':source=ROOT/f'recomp/config/output/sub_{entry:08X}_0x{entry:x}.cpp';reader=elf_reader(elf.read_bytes());symbol=f'sub_{entry:08X}_0x{entry:x}'
        else:
            source=ROOT/f'recomp/config/output_ovl/{family}/{family}_{entry:08X}_0x{entry:x}.cpp';image=ROOT/f'build-function-index/owned-overlays/{family}.bin';raw=image.read_bytes();base=0x570000 if family=='o2' else 0x810000
            images[family]=sha(image);reader=lambda at,n,raw=raw,base=base:raw[at-base:at-base+n];symbol=f'{family}_{entry:08X}_0x{entry:x}'
        text=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
        audits.append(compare_source('Ordinary actor entry',source.relative_to(ROOT).as_posix(),entry,end,reader));inputs.append(source);symbols.append(symbol);bodies.append(text[text.index('// Function:'):])
    assert images['o2']=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    assert images['o9']=='604126d6edca1b1333948d79d1d2c8d2f2e22f4a233efbdfb769c106dafe7343'
    mode=ROOT/'recomp/config/output/sub_001B0300_0x1b0300.cpp';inputs.append(mode)
    audits.append(compare_source('Mode predicate bridge',mode.relative_to(ROOT).as_posix(),0x1b0300,0x1b030c,elf_reader(elf.read_bytes())))
    prefix=inputs[2].read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix+='\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n'
    prefix+='\n'.join(f'void {name}(uint8_t*,R5900Context*,PS2Runtime*);' for name in symbols)
    for name,at in [('sub_001B0300_0x1b0300',0x1b0300),('o2_0066B960_0x66b960',0x66b960),('o9_00810960_0x810960',0x810960),('o8_008129C0_0x8129c0',0x8129c0)]:
        prefix+=f'\nvoid {name}(uint8_t* r,R5900Context* c,PS2Runtime* t){{t->lookupFunction(0x{at:x})(r,c,t);}}'
    generated=out/'original_native.cpp';generated.write_text(prefix+'\n'+'\n'.join(bodies)+'\n'+inputs[1].read_text())
    before={p.relative_to(ROOT).as_posix():sha(p) for p in inputs};exe=out/'ordinary_entry.exe'
    command=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),str(generated),'-Wl,--start-group',*[str(snapshot/'native-build'/name) for name in manifest['archives_sha256']],'-Wl,--end-group','-lwinmm','-lxinput','-luser32','-lgdi32','-ldxgi','-luuid','-o',str(exe)]
    receipt=dict(status='failed',snapshot=str(snapshot),snapshot_receipt_sha256=sha(snapshot/'receipt.json'),input_sha256=before,images_sha256=images,original_word_audits=audits,compiler_sha256=sha(compiler),commands=[],game_run=False,stage4_complete=False,declared_boundaries=['1B0300 word-audited signed mode read','66B960 observed secondary dispatch','810960/8129C0 observed channel7 transport bytes'])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    for label,cmd in [('compile',command),('run',[str(exe)])]:
        start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,capture_output=True,text=True,timeout=120)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        receipt['commands'].append(dict(label=label,command=cmd,returncode=run.returncode,seconds=time.monotonic()-start));print(label,run.returncode,run.stdout[-1000:],run.stderr[-2400:],flush=True)
        if run.returncode:break
    receipt['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    receipt['archive_drift']=[name for name,digest in manifest['archives_sha256'].items() if sha(snapshot/'native-build'/name)!=digest]
    if not run.returncode and not receipt['source_drift'] and not receipt['archive_drift']:receipt.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');return receipt['status']!='passed'
if __name__=='__main__':raise SystemExit(main())
