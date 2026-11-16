"""Compare locomotion actions, transitions and floor classification against owned code."""
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
    shutil.copytree(snapshot/'source',out/'source')
    image=ROOT/'build-function-index/owned-overlays/o2.bin';raw=image.read_bytes();assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    entries=[0x666bb0,0x5d6910,0x66bdb0,0x5d43c0,0x5d7bc0,0x5d7890,0x66c160,0x66c4b0,0x66c840,0x6673c0,0x667370,0x6673a0,0x58c7f0,0x66c040,0x58bf50]
    ports=[0x616f20,0x616fa0,0x5d4b10,0x5d4930,0x5d4cf0,0x58c7b0,0x58c300,0x65f580]
    inputs=[ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp',Path(__file__).resolve(),ROOT/'tools/native_reconstruction/locomotion_action_tests.cpp']
    native=['game/native/gameplay_world/'+name for name in ['world.hpp','locomotion_floor.hpp','locomotion_floor.cpp','locomotion_animation.hpp','locomotion_animation.cpp','locomotion_transition_profile.inc','primary_locomotion.hpp','primary_locomotion.cpp','primary_turn.cpp','primary_turn_profile.inc','idle_action.hpp','idle_action.cpp','animation.hpp','motion_selection.cpp','motion.cpp']]+['game/native/animation/playback.hpp','game/native/animation/playback.cpp']
    for name in native+['third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']:
        target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copy2(ROOT/name,target);inputs.append(ROOT/name)
    bodies=[];audits=[]
    for entry in entries:
        source=ROOT/f'recomp/config/output_ovl/o2/o2_{entry:08X}_0x{entry:x}.cpp';source_text=source.read_text();inputs.append(source)
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source_text)[1],16)
        audits.append(compare_source('Motion frame queries',source.relative_to(ROOT).as_posix(),entry,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
        bodies.append(source_text[source_text.index('// Function:'):])
    elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
    mains=[0x191bc0,0x191ef0,0x1920a0]
    for entry in mains:
        source=ROOT/f'recomp/config/output/sub_{entry:08X}_0x{entry:x}.cpp';inputs.append(source);source_text=source.read_text()
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source_text)[1],16)
        audits.append(compare_source('Original animation header queries',source.relative_to(ROOT).as_posix(),entry,end,elf_reader(elf.read_bytes())))
        bodies.append(source_text[source_text.index('// Function:'):])
    prefix=inputs[0].read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix=prefix.replace('bool hasFunction','void SignalException(R5900Context*,unsigned){throw std::runtime_error("Original integer overflow");}\n    bool hasFunction')
    prefix+='\n#define FPU_C_EQ_S(a,b) ((a)==(b))\n#define EXCEPTION_INTEGER_OVERFLOW 1u\n#define ADD32_OV(a,b,out,ov) do{const auto wide=std::int64_t(std::bit_cast<std::int32_t>(std::uint32_t(a)))+std::int64_t(std::int32_t(b));out=std::uint32_t(wide);ov=wide<INT32_MIN||wide>INT32_MAX;}while(0)\n'
    prefix+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n'
    prefix+='\n'.join(f'void o2_{at:08X}_0x{at:x}(uint8_t*,R5900Context*,PS2Runtime*);' for at in entries+ports)
    prefix+='\n#define FPU_DIV_S(a,b) ((a)/(b))\n'
    prefix+='\n#define SRL32(v,n) (std::uint32_t(v)>>(n))\n'
    prefix+='\n'.join(f'void sub_{at:08X}_0x{at:x}(uint8_t* r,R5900Context* c,PS2Runtime* t){{t->lookupFunction(0x{at:x})(r,c,t);}}' for at in [0x1921b0,0x1919d0,0x192180,0x107c68,0x192220,0x1226d8,0x192170,0x193230,0x1925c0])
    prefix+='\n'.join(f'void sub_{at:08X}_0x{at:x}(uint8_t*,R5900Context*,PS2Runtime*);' for at in mains)
    prefix+='\n'+'\n'.join(f'void o2_{at:08X}_0x{at:x}(uint8_t* r,R5900Context* c,PS2Runtime* t){{t->lookupFunction(0x{at:x})(r,c,t);}}' for at in ports)
    generated=out/'original_native.cpp';generated.write_text(prefix+'\n'+'\n'.join(bodies)+'\n'+inputs[2].read_text())
    before={str(p.relative_to(ROOT)):sha(p) for p in inputs};exe=out/'locomotion_action.exe'
    command=[str(compiler),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(out/'source'),str(generated),*[str(out/'source'/name) for name in native if name.endswith('.cpp')],'-Wl,--start-group',*[str(snapshot/'native-build'/name) for name in manifest['archives_sha256']],'-Wl,--end-group','-lwinmm','-lxinput','-luser32','-lgdi32','-o',str(exe)]
    result=dict(status='failed',snapshot=str(snapshot),snapshot_receipt_sha256=sha(snapshot/'receipt.json'),input_sha256=before,original_word_audits=audits,compiler_sha256=sha(compiler),commands=[],game_run=False,stage4_complete=False,declared_boundaries=['616F20/616FA0 qualified Grid floor and up column','1919D0 qualified matrix direction','1921B0/192180 qualified sin_cos and quadrant_angle','5D4B10/5D4930 observed frame query results','5D4CF0/58C7B0/58C300 observed action animation operations','193230/1925C0 qualified canonical Instance sample and translation difference','65F580 qualified primary_turn_step','107C68 bounded channel clear'])
    env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    for label,cmd in [('compile',command),('run',[str(exe),str(image),str(elf)])]:
        start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        result['commands'].append(dict(label=label,command=cmd,returncode=run.returncode,seconds=time.monotonic()-start));print(label,run.returncode,run.stdout[-1000:],run.stderr[-2500:],flush=True)
        if run.returncode:break
    result['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    result['archive_drift']=[name for name,digest in manifest['archives_sha256'].items() if sha(snapshot/'native-build'/name)!=digest]
    if not run.returncode and not result['source_drift'] and not result['archive_drift']:result.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');return int(result['status']!='passed')
if __name__=='__main__':raise SystemExit(main())
