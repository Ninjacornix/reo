"""Complete66B960/66B990 action with real reset/class/pose dependencies.

Only the already independently qualified motion select, tick and activation
boundary is recorded; no original action or health decision is replaced.
"""
import argparse, hashlib, json, os, re, subprocess, time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
COMPILER=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',required=True,type=Path);p.add_argument('--cohort',required=True,type=Path);args=p.parse_args()
    out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    cohort=json.loads(args.cohort.read_text());assert cohort['status']=='passed'
    assert sha(COMPILER)==cohort['compiler_sha256']=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    build=ROOT/'build-native-sjuni/gameplay-native-llvm-v1'
    for name,value in cohort['sources_sha256'].items():assert sha(ROOT/name)==value,name
    for name,value in cohort['archives_sha256'].items():assert sha(build/name)==value,name
    image=ROOT/'build-function-index/owned-overlays/o2.bin';raw=image.read_bytes()
    assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    entries=[0x66b960,0x6673c0,0x64f690,0x65fab0,0x667370,0x6673a0]
    sources=[ROOT/f'recomp/config/output_ovl/o2/o2_{entry:08X}_0x{entry:x}.cpp' for entry in entries]
    audits=[];bodies=[]
    for entry,source in zip(entries,sources):
        body=source.read_text();end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
        audits.append(compare_source('Complete idle action dependency',source.relative_to(ROOT).as_posix(),entry,end,lambda at,n:raw[at-0x570000:at-0x570000+n]))
        bodies.append(body[body.index('// Function:'):])
    reference=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp'
    fixture=ROOT/'tools/native_reconstruction/idle_action_tests.cpp'
    prefix=reference.read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    prefix+='\n#define WRITE16(at,v) ref_write(rdram,at,std::uint16_t(v))\n'
    for entry in (0x5d4cf0,0x58c7b0,0x58c300):
        prefix+=f'void o2_{entry:08X}_0x{entry:x}(uint8_t* ram,R5900Context* c,PS2Runtime* runtime){{runtime->lookupFunction(0x{entry:x})(ram,c,runtime);}}\n'
    declarations='\n'.join(f'void o2_{entry:08X}_0x{entry:x}(uint8_t*,R5900Context*,PS2Runtime*);' for entry in entries)
    generated=out/'original_native.cpp';generated.write_text(prefix+declarations+'\n'+'\n'.join(bodies)+'\n'+fixture.read_text())
    inputs=[*sources,reference,fixture,Path(__file__).resolve(),ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h']
    before={name:value for name,value in cohort['sources_sha256'].items()}
    before.update({p.relative_to(ROOT).as_posix():sha(p) for p in inputs})
    exe=out/'idle_action.exe'
    command=[str(COMPILER),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),str(generated),'-Wl,--start-group',*[str(build/name) for name in cohort['archives_sha256']],'-Wl,--end-group','-lwinmm','-lxinput','-luser32','-o',str(exe)]
    result=dict(status='failed',cohort_receipt=str(args.cohort.resolve()),cohort_receipt_sha256=sha(args.cohort),compiler_sha256=sha(COMPILER),input_sha256=before,archives_sha256=cohort['archives_sha256'],original_image_sha256=sha(image),original_word_audits=audits,commands=[],game_run=False,stage4_complete=False,declared_boundary=['5D4CF0 motion select','58C7B0 activation','58C300 motion tick'])
    env=dict(os.environ);env['PATH']=str(COMPILER.parent)+os.pathsep+env.get('PATH','')
    for label,cmd in [('compile',command),('execute',[str(exe)])]:
        start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        result['commands'].append(dict(label=label,command=cmd,returncode=run.returncode,seconds=time.monotonic()-start))
        print(label,run.returncode,run.stdout[-600:],run.stderr[-2000:],flush=True)
        if run.returncode:break
    result['source_drift']=[name for name,value in before.items() if sha(ROOT/name)!=value]
    result['archive_drift']=[name for name,value in cohort['archives_sha256'].items() if sha(build/name)!=value]
    if not run.returncode and not result['source_drift'] and not result['archive_drift']:
        result.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n')
    return int(result['status']!='passed')
if __name__=='__main__':raise SystemExit(main())
