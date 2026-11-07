#!/usr/bin/env python3
"""Run unchanged sound-capture expectations against the complete 128-patch SDK.

Retain the exact private driver adaptations: patch count, output scope, patch
reverse check and explicit standard headers. No expected wire result changes.
"""
import argparse,hashlib,json,os,subprocess,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
PRIOR=ROOT/'tools/native_reconstruction/audio_ram_capture_dispatch/verify.py'
PATCH=ROOT/'third_party/patches/ps2recomp/0127-identify-native-sound-rpc-refusals.patch'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--mode',choices=['companion','objects'],required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/sound-rpc-diagnostics'):raise ValueError('Fresh owned scope required')
    # The immutable prior driver still verifies its frozen older regression
    # source/harness and original PCM/bank observations before executing them.
    text=PRIOR.read_text();assert text.count("receipt['applied_count']!=126")==2
    text=text.replace("receipt['applied_count']!=126","receipt['applied_count']!=128")
    text=text.replace("ROOT/'build-native-sjuni/audio-ram-capture-dispatch'","ROOT/'build-native-sjuni/sound-rpc-diagnostics'")
    out.parent.mkdir(parents=True,exist_ok=True);adapted=out.with_name(out.name+'-adapted.py');adapted.write_text(text,encoding='utf-8',newline='\n')
    module=types.ModuleType('sound_diagnostic_verifier');module.__file__=str(PRIOR)
    exec(compile(text,str(adapted),'exec'),module.__dict__);module.PATCH=PATCH
    factory=module.prior_module
    def prior_module(folder):
        old=factory(folder);old.PATCH=PATCH;extract=old.rpc_extract
        old.rpc_extract=lambda *args:'#include <atomic>\n#include <cstdio>\n'+extract(*args)
        return old
    module.prior_module=prior_module
    sys.argv=[sys.argv[0],'--checkout',str(a.checkout),'--receipt',str(a.receipt),'--cxx',str(a.compiler),'--output',str(out),'--mode',a.mode]
    module.main()
    receipt=json.loads((out/'receipt.json').read_bytes())
    receipt['diagnostic_status']='failed'
    try:
        if a.mode=='companion':
            harness=(out/'harness.cpp').read_text()
            old='else if(name=="unknown0")unknown_capture(0);'
            assert harness.count(old)==1
            harness=harness.replace(old,'else if(name=="repeat_unknown")repeat_unknown();'+old)
            repeat_body='''void repeat_unknown(){CaptureSetup s;s.install();auto ctx=context(s,0,0xdeadbeefu);const auto before=s.value->ee;
        for(unsigned i=0;i<20;++i){
            check(c::tryNativeSoundRamRpc(s.value->ee.data(),&ctx,&s.runtime));check(ctx.result==-1);
            uint32_t result=123;bool signal=true;
            check(rpc_fixture::handleSoundDriverRpcService(s.value->ee.data(),&s.runtime,0,0xdeadbeefu,sendAt,8,recvAt,8,result,signal));
            check(result==0&&!signal&&s.value->ee==before&&s.value->reads==0&&s.value->controls==0&&s.value->copies==0&&c::signals==0&&s.value->begins==2*(i+1)&&s.value->ends==2*(i+1));
        }}
    '''
            assert harness.count('int main(int argc,char** argv)')==1
            harness=harness.replace('int main(int argc,char** argv)',repeat_body+'int main(int argc,char** argv)')
            repeat=out/'repeat.cpp';repeat.write_text(harness,encoding='utf-8',newline='\n')
            compile_check=next(r for r in receipt['checks'] if r['name']=='compile_companion')
            command=compile_check['command'][:];command[command.index(str(out/'harness.cpp'))]=str(repeat);command[-1]=str(out/'repeat.exe')
            env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
            run=subprocess.run(command,capture_output=True,text=True,env=env);(out/'repeat-compile.txt').write_text(run.stdout+run.stderr,encoding='utf-8')
            if run.returncode:raise ValueError('Repeated-refusal fixture compile failed')
            run=subprocess.run([str(out/'repeat.exe'),'repeat_unknown'],capture_output=True,text=True,env=env,timeout=30)
            (out/'repeat.txt').write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
            rows=[s for s in run.stderr.splitlines() if s.startswith('[NATIVE-SOUND-RPC-REFUSAL]')]
            if run.returncode or len(rows)!=16:raise ValueError('Expected eight bounded logs per direct/outer refusal site')
            if sum('reason=uncovered_rpc ' in s for s in rows)!=8 or sum('reason=direct_uncovered_rpc ' in s for s in rows)!=8:raise ValueError('Refusal site identity missing')
            if not all('sid=00000000 rpc=deadbeef' in s for s in rows):raise ValueError('Request identity missing')
            receipt.update(repeated_refusals=40,bounded_identity_logs=16)
        receipt['diagnostic_status']='passed'
    finally:
        receipt.update(diagnostic_driver_sha256=sha(Path(__file__)),adapted_outer_driver_sha256=sha(adapted),public_patch_sha256=sha(PATCH))
        (out/'diagnostic-receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
if __name__=='__main__':main()
