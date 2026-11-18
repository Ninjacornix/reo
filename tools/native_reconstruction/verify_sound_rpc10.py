#!/usr/bin/env python3
"""Qualify captured RPC 0x10 reply against frozen SDK generic memory results."""
import argparse,hashlib,json,os,shutil,subprocess,sys,types
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/sound-rpc10'
PRIOR=ROOT/'tools/native_reconstruction/verify_sound_rpc_diagnostics.py'
PATCH=ROOT/'third_party/patches/ps2recomp/0128-native-sound-rpc10-reply.patch'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--checkout',type=Path,required=True);p.add_argument('--receipt',type=Path,required=True);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--mode',choices=['companion','objects'],required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned qualification scope required')
    source=PRIOR.read_text()
    for old,new in [("receipt['applied_count']!=128","receipt['applied_count']!=129"),('0127-identify-native-sound-rpc-refusals.patch','0128-native-sound-rpc10-reply.patch'),('build-native-sjuni/sound-rpc-diagnostics','build-native-sjuni/sound-rpc10')]:
        if old not in source:raise ValueError('Prior adaptation anchor missing')
        source=source.replace(old,new)
    out.parent.mkdir(parents=True,exist_ok=True);adapted=out.with_name(out.name+'-driver.py');adapted.write_text(source,encoding='utf-8',newline='\n')
    module=types.ModuleType('rpc10_prior_verifier');module.__file__=str(PRIOR);exec(compile(source,str(adapted),'exec'),module.__dict__)
    sys.argv=[sys.argv[0],'--checkout',str(a.checkout),'--receipt',str(a.receipt),'--compiler',str(a.compiler),'--output',str(out),'--mode',a.mode]
    module.main();record=dict(status='failed',mode=a.mode,driver_sha256=sha(Path(__file__)),prior_driver_sha256=sha(PRIOR),adapted_driver_sha256=sha(adapted),patch_sha256=sha(PATCH),negative_controls=[],game_run=False,device_opened=False)
    try:
        if a.mode=='companion':
            original=[]
            for tag in ['llvm','gcc']:
                folder=BASE/('original-'+tag+'-v1');r=json.loads((folder/'receipt.json').read_bytes())
                if r['status']!='existing generic sound RPC reply frozen' or r['native_route_patch_exists']:raise ValueError('Pre-native reference required')
                for name,digest in {**r['memory_outputs'],**r['outputs_sha256']}.items():
                    if sha(folder/name)!=digest:raise ValueError('Original observation drift')
                original.append((json.loads((folder/'cases.json').read_bytes()),r['memory_outputs']))
            if original[0]!=original[1]:raise ValueError('Original compiler cohorts differ')
            cases=original[0][0];fixture=out/'native_reply.cpp'
            support=(out/'harness.cpp').read_text()
            if support.count('int main(int argc,char** argv)')!=1:raise ValueError('One capture entry required')
            (out/'capture_support.hpp').write_text(support.replace('int main(int argc,char** argv)','int capture_regression_main(int argc,char** argv)'),encoding='utf-8',newline='\n')
            fixture.write_text('''#include "capture_support.hpp"
#include <fstream>
int main(int argc,char** argv){try{
    check(argc==6);const auto send=uint32_t(std::stoul(argv[1])),count=uint32_t(std::stoul(argv[2])),recv=uint32_t(std::stoul(argv[3])),bytes=uint32_t(std::stoul(argv[4]));
    CaptureSetup s;s.value->ee.resize(4*1024*1024);s.runtime.memory().rdram=s.value->ee.data();s.install();
    for(std::size_t i=0;i<s.value->ee.size();++i)s.value->ee[i]=static_cast<uint8_t>(i*17+i/251);
    uint32_t result=123;bool signal=true;
    check(rpc_fixture::handleSoundDriverRpcService(s.value->ee.data(),&s.runtime,1,0x10,send,count,recv,bytes,result,signal));
    check(result==0 && !signal && s.value->begins==1 && s.value->ends==1 && !s.value->reports);
    std::vector<uint8_t> expected(s.value->ee.size());std::ifstream f(argv[5],std::ios::binary);f.read(reinterpret_cast<char*>(expected.data()),expected.size());check(bool(f));
    check(expected==s.value->ee && !s.value->reads && !s.value->snapshots && !s.value->calls[PacketSubmit] && !s.value->calls[BankReset]);
    // Neighboring RPC values must retain explicit unsupported refusal.
    const auto before=s.value->ee;result=123;signal=true;
    check(rpc_fixture::handleSoundDriverRpcService(s.value->ee.data(),&s.runtime,1,0x110,send,count,recv,bytes,result,signal));
    check(result==0 && !signal && s.value->ee==before && s.value->diagnostic.status==Status::unsupported);
    std::cout<<"captured reply matches frozen original memory\\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\\n';return 1;}}
''',encoding='utf-8',newline='\n')
            proof=json.loads((out/'receipt.json').read_bytes());command=next(r['command'] for r in proof['checks'] if r['name']=='compile_companion')[:]
            env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
            def compile_source(label,path,binary):
                cmd=command[:];cmd[cmd.index(str(out/'harness.cpp'))]=str(path);cmd[-1]=str(binary)
                value=subprocess.run(cmd,capture_output=True,text=True,env=env);(out/(label+'-compile.txt')).write_text(value.stdout+value.stderr,encoding='utf-8')
                if value.returncode:raise ValueError('Reply fixture compile failed '+label)
            binary=out/'native_reply.exe';compile_source('reply',fixture,binary)
            def run(label,binary,index,expect_failure=False):
                vector=cases[index];cmd=[str(binary),*[str(vector[k]) for k in ['send','count','recv','bytes']],str(BASE/'original-llvm-v1'/f'case-{index}.bin')]
                value=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=30);(out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8')
                if (value.returncode==0)==expect_failure:raise ValueError('Unexpected reply result '+label)
            for index in range(len(cases)):run('reply-'+str(index),binary,index)
            record.update(cases=len(cases),full_memory_bytes_per_case=4*1024*1024,native_memory_differences=0,native_binary_sha256=sha(binary))
            # Copy only fixture sources. The original qualification's generated
            # files and the actual SDK checkout remain immutable.
            rpc=out/'prior/rpc_sound.inc';body=rpc.read_text()
            mutations=[('omit-self-alias-clear','}else if(cap.zero(RamSpace::ee,recvBuf,','}else if(sendBuf!=recvBuf && cap.zero(RamSpace::ee,recvBuf,',0),
                       ('reverse-copy-arguments','cap.forward(RamSpace::ee,sendBuf,RamSpace::ee,recvBuf,bytes)','cap.forward(RamSpace::ee,recvBuf,RamSpace::ee,sendBuf,bytes)',2),
                       ('extra-nowait-signal','// completion, just as in the previous generic SIF path.\n                return true;','// completion, just as in the previous generic SIF path.\n                signalNowaitCompletion=true;return true;',0)]
            for label,old,new,index in mutations:
                if body.count(old)!=1:raise ValueError('Mutation anchor missing '+label)
                negative=out/label
                for path in out.rglob('*'):
                    if path.is_relative_to(negative) or any(path.is_relative_to(out/m[0]) for m in mutations):continue
                    if path.is_file() and path.suffix in ['.h','.hpp','.inc','.cpp']:
                        target=negative/path.relative_to(out);target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(path,target)
                (negative/'prior/rpc_sound.inc').write_text(body.replace(old,new),encoding='utf-8',newline='\n')
                bad=negative/'reply.exe';compile_source(label,negative/'native_reply.cpp',bad);run(label,bad,index,True)
                record['negative_controls'].append(dict(name=label,detected=True))
        record['status']='captured RPC 0x10 checks passed'
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.is_file() and p.suffix in ['.json','.txt','.cpp'] and p.name!='rpc10-receipt.json'}
        (out/'rpc10-receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k] for k in ['status','mode']}))
if __name__=='__main__':main()
