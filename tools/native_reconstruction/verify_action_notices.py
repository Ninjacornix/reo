"""Check the complete owned6651F0 policy without a duplicate production build."""
import argparse,hashlib,json,os,re,subprocess,time
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
COMPILER=Path(os.environ['LOCALAPPDATA'])/'OutbreakRecomp/launcher/toolchains/llvm-mingw-20251216-ucrt-x86_64/bin/x86_64-w64-mingw32-clang++.exe'
def sha(path):return hashlib.sha256(Path(path).read_bytes()).hexdigest()
def main():
    parser=argparse.ArgumentParser();parser.add_argument('--output',required=True,type=Path);args=parser.parse_args()
    out=args.output.resolve();out.mkdir(parents=True,exist_ok=False)
    assert sha(COMPILER)=='f1377bd9c4e35669930d0fb2ebdc51cac1d1f4ca16638c0ed0d77c113bc195d3'
    image=ROOT/'build-function-index/owned-overlays/o2.bin';raw=image.read_bytes()
    assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    source=ROOT/'recomp/config/output_ovl/o2/o2_006651F0_0x6651f0.cpp';body=source.read_text()
    end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',body)[1],16)
    audit=compare_source('Complete action-notice policy',source.relative_to(ROOT).as_posix(),0x6651f0,end,lambda at,n:raw[at-0x570000:at-0x570000+n])
    reference=ROOT/'tools/native_reconstruction/gameplay_collision_oracle/reference.hpp'
    prefix=reference.read_text().split('void o0_00370760')[0].replace('#pragma once','',1)
    fixture=ROOT/'tools/native_reconstruction/action_notice_tests.cpp'
    generated=out/'original_native.cpp';generated.write_text(prefix+body[body.index('// Function:'):]+'\n'+fixture.read_text())
    # Snapshot transitive repository headers before compiling. The policy is
    # header-only, but Actor and the original FPU environment are dependencies.
    inputs=[source,fixture,reference,Path(__file__).resolve(),ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_fpu_convert.h',
            *sorted((ROOT/'game/native').rglob('*.hpp')),*sorted((ROOT/'game/native').rglob('*.h'))]
    before={p.relative_to(ROOT).as_posix():sha(p) for p in inputs}
    exe=out/'action_notice.exe';command=[str(COMPILER),'-std=c++20','-O2','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),str(generated),'-o',str(exe)]
    receipt=dict(status='failed',compiler_sha256=sha(COMPILER),input_sha256=before,original_image_sha256=sha(image),original_word_audit=audit,commands=[],game_run=False,stage4_complete=False,scope='Complete standalone action-notice predicate and resource-read admission; application binding requires its own coherent cohort.')
    env=dict(os.environ);env['PATH']=str(COMPILER.parent)+os.pathsep+env.get('PATH','')
    for label,cmd in [('compile',command),('execute',[str(exe)])]:
        start=time.monotonic();run=subprocess.run(cmd,cwd=ROOT,env=env,text=True,capture_output=True,timeout=180)
        (out/(label+'.stdout.txt')).write_text(run.stdout);(out/(label+'.stderr.txt')).write_text(run.stderr)
        receipt['commands'].append(dict(label=label,command=cmd,returncode=run.returncode,seconds=time.monotonic()-start))
        print(label,run.returncode,run.stdout[-600:],run.stderr[-1000:],flush=True)
        if run.returncode:break
    receipt['source_drift']=[name for name,digest in before.items() if sha(ROOT/name)!=digest]
    if not run.returncode and not receipt['source_drift']:
        receipt.update(status='passed',observed=json.loads(run.stdout),executable_sha256=sha(exe))
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    return 0 if receipt['status']=='passed' else 1
if __name__=='__main__':raise SystemExit(main())
