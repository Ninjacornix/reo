"""Full primary idle selection, with reached interaction/aim owners observed.

Builds one small comparison against immutable shipping-library dependencies;
no global source freeze or reconstruction of unrelated libraries is required.
"""
import argparse,hashlib,json,os,re,shutil,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
def sha(p):return hashlib.sha256(Path(p).read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);parser.add_argument('--snapshot',type=Path,required=True);a=parser.parse_args()
    out=a.output.resolve();out.mkdir(parents=True,exist_ok=False);snapshot=a.snapshot.resolve()
    manifest=json.loads((snapshot/'receipt.json').read_text());assert manifest['status']=='passed'
    compiler=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
    assert sha(compiler)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    for name,digest in manifest['source_sha256'].items():assert sha(snapshot/'source'/name)==digest,name
    for name,digest in manifest['archives_sha256'].items():assert sha(snapshot/'native-build'/name)==digest,name
    image=ROOT/'build-function-index/owned-overlays/o2.bin';raw=image.read_bytes();assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    entries=[0x65f580,0x66bb10,0x6673c0,0x667370,0x6673a0]
    ports=[0x5d4cf0,0x58c300,0x58c7b0,0x58c7f0,0x5d4a10]
    inputs=[ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',Path(__file__).resolve(),ROOT/'tools/native_reconstruction/primary_turn_tests.cpp']
    conversion='third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h'
    conversion_copy=out/'source'/conversion;conversion_copy.parent.mkdir(parents=True,exist_ok=True)
    shutil.copy2(ROOT/conversion,conversion_copy);inputs.append(ROOT/conversion)
    native=['game/native/gameplay_world/primary_turn.hpp','game/native/gameplay_world/primary_turn.cpp','game/native/gameplay_world/primary_turn_profile.inc','game/native/gameplay_world/idle_action.hpp','game/native/gameplay_world/idle_action.cpp','game/native/gameplay_world/animation.hpp','game/native/gameplay_world/motion_selection.cpp']
    for name in native:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(ROOT/name,target);inputs.append(ROOT/name)
    bodies=[];audits=[]
    for entry in entries:
        source=ROOT/f'recomp/config/output_ovl/o2/o2_{entry:08X}_0x{entry:x}.cpp';text=source.read_text();inputs.append(source)
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',text)[1],16)
        audits.append(compare_source('Primary action selection',source.relative_to(ROOT).as_posix(),entry,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
        bodies.append(text[text.index('// Function:'):])
    absolute=ROOT/'recomp/config/output/sub_001920A0_0x1920a0.cpp';inputs.append(absolute)
    absolute_text=absolute.read_text();bodies.append(absolute_text[absolute_text.index('// Function:'):])
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',absolute_text)[1],16)
    audits.append(compare_source('Original absolute value and unreachable adjacent entries',absolute.relative_to(ROOT).as_posix(),0x1920a0,end,elf_reader(elf.read_bytes())))
    prefix=inputs[0].read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n#define SRA32(v,n) (std::int32_t(v)>>(n))\n'
    prefix+='\n'.join(f'void o2_{at:08X}_0x{at:x}(uint8_t*,R5900Context*,PS2Runtime*);' for at in entries+ports)
    prefix+='\nvoid sub_001920A0_0x1920a0(uint8_t*,R5900Context*,PS2Runtime*);\n'
    for at in (0x192220,0x1226d8,0x192170):
        prefix+=f'void sub_{at:08X}_0x{at:x}(uint8_t*,R5900Context*,PS2Runtime*){{throw std::runtime_error("Unreached adjacent math entry");}}\n'
    prefix+='\n'+'\n'.join(f'void o2_{at:08X}_0x{at:x}(uint8_t* r,R5900Context* c,PS2Runtime* t){{t->lookupFunction(0x{at:x})(r,c,t);}}' for at in ports)
    generated=out/'original_native.cpp';generated.write_text(prefix+'\n'+'\n'.join(bodies)+'\n'+inputs[2].read_text())
    before={str(p.relative_to(ROOT)):sha(p) for p in inputs}
    exe=out/'primary_turn.exe'
    command=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),'-I'+str(snapshot/'source'),'-I'+str(snapshot/'source/game/native/gameplay_world'),str(generated),*[str(out/'source'/name) for name in native if name.endswith('.cpp')],'-Wl,--start-group',*[str(snapshot/'native-build'/name) for name in manifest['archives_sha256']],'-Wl,--end-group','-lwinmm','-lxinput','-luser32','-lgdi32','-o',str(exe)]
    result=dict(status='failed',snapshot=str(snapshot),snapshot_receipt_sha256=sha(snapshot/'receipt.json'),input_sha256=before,original_word_audits=audits,compiler_sha256=sha(compiler),commands=[],game_run=False,stage4_complete=False,declared_boundaries=['5D4CF0 motion selection','58C300 tick','58C7B0 activation','58C7F0 flags','5D4A10 initial frame'])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    for label,cmd in [('compile',command),('run',[str(exe),str(image)])]:
        start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        result['commands'].append(dict(label=label,command=cmd,returncode=run.returncode,seconds=time.monotonic()-start))
        print(label,run.returncode,run.stdout[-1000:],run.stderr[-2500:],flush=True)
        if run.returncode:break
    result['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    if not run.returncode and not result['source_drift']:result.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');return int(result['status']!='passed')
if __name__=='__main__':raise SystemExit(main())
