#!/usr/bin/env python3
"""Isolated Source2 ownership checks, including real unchanged async provider."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-shared-source'):raise ValueError('Existing compiler and fresh private output required')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    deps=['game/native/sjrb/sjrb.cpp','game/native/adxt_refill/adxt_refill.cpp','game/native/resource_io/async_read_owner.cpp',
          'game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp','game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp']
    sources=[ROOT/n for n in deps]+[HERE/'shared_source.cpp',HERE/'shared_source_tests.cpp']
    tracked=set(sources)|set(HERE.glob('*.hpp'))|{HERE/'verify.py'}
    for folder in ('sjrb','adxt_refill','resource_io','tasks','resources'):
        tracked.update((ROOT/'game/native'/folder).glob('*.hpp'))
    inputs={str(x.relative_to(ROOT)):sha(x)for x in sorted(tracked)}
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),inputs=inputs,checks=[],game_run=False,device_opened=False,
        original39_expected_previously_seen=True,native_core_frozen_before_comparator=False)
    def run(name,command,expected=0):
        r=subprocess.run([str(x)for x in command],env=env,cwd=ROOT,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n')
        receipt['checks'].append(dict(name=name,command=[str(x)for x in command],exit_code=r.returncode,expected=expected,stdout=r.stdout))
        if r.returncode!=expected:raise RuntimeError(name+':\n'+r.stdout+r.stderr)
    try:
        flags=[cc,'-std=c++20','-O1','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-ffp-contract=off','-I'+str(ROOT)]
        exe=out/'source_tests.exe';run('compile',flags+sources+['-o',exe]);run('units',[exe]);receipt['executable_sha256']=sha(exe)
        original=(HERE/'shared_source.cpp').read_text(encoding='utf-8')
        anchor='const auto actual=ring_.snapshot();'
        if original.count(anchor)!=1:raise ValueError('Fault injection anchor changed')
        injected=original.replace(anchor,'if(i==0)status=sjrb::Status::unsafe_state;\n        '+anchor)
        private=out/'injected.cpp';private.write_text(injected,encoding='utf-8',newline='\n')
        variants=[(private,out/'fault.exe','posteffect',0),
                  (out/'negative.cpp',out/'negative.exe','posteffect',1)]
        (out/'negative.cpp').write_text(injected.replace('if(status!=sjrb::Status::completed)return fail(Status::ring_failure,true,true);','(void)status; /* negative: ignore proven post-effect error */'),encoding='utf-8',newline='\n')
        for index,(source,binary,argument,expected)in enumerate(variants):
            variant=[source if x==HERE/'shared_source.cpp'else x for x in sources]
            run('fault_compile_'+str(index),flags+['-I'+str(HERE)]+variant+['-o',binary]);run('fault_'+str(index),[binary,argument],expected)
        receipt['status']='passed'
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['inputs_postcheck']=[n for n,d in inputs.items()if sha(ROOT/n)!=d]
        if receipt['inputs_postcheck']:receipt.update(status='failed',failure='Source drift')
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],receipt=str(out/'receipt.json'),sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
