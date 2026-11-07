#!/usr/bin/env python3
"""Compare full old/new SifInitRpc bodies using explicit host fixture ports."""
import argparse,hashlib,json,os,re,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];OLD=ROOT/'build-native-sjuni/dependency-sound-rpc10-reapply-v1';NEW=ROOT/'build-native-sjuni/dependency-sif-init-timing-reapply-v1';NAME='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
MODES=['native','foreign','unavailable','legacy_null','delay_audio','delay_lock','delay_log','disabled_delay_log','refused_slow']
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/sif-init-timing'):raise ValueError('Fresh owned output required')
    prior=OLD.with_name(OLD.name+'-receipt.json');current=NEW.with_name(NEW.name+'-receipt.json')
    if sha(prior)!='692d86d3e19c51039e58749cedf86597810fcff672e95b62a451d3b14605514b':raise ValueError('Frozen prior SDK changed')
    receipts=[json.loads(x.read_bytes())for x in [prior,current]]
    for root,receipt,count in [(OLD,receipts[0],129),(NEW,receipts[1],130)]:
        if receipt['status']!='passed' or receipt['applied_count']!=count:raise ValueError('Complete SDK audit required')
        for name,digest in receipt['source_sha256'].items():
            if sha(root/name)!=digest:raise ValueError('SDK source drift '+name)
    fixture=ROOT/'tools/native_reconstruction/sif_init_fixture.cpp';out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(status='failed',compiler_sha256=sha(a.compiler),prior_sdk_receipt_sha256=sha(prior),current_sdk_receipt_sha256=sha(current),fixture_sha256=sha(fixture),verifier_sha256=sha(Path(__file__)),original_sdk_observations_executed_after_timing_authored=True,game_run=False,device_opened=False,profiles=[])
    try:
        binaries=[]
        for label,root in [('prior',OLD),('timed',NEW)]:
            text=(root/NAME).read_text();start=text.index('    void SifInitRpc(');end=text.index('    void SifBindRpc(',start);helper=''
            if label=='timed':
                begin=text.index('        // Owner-thread elapsed timing only.');finish=text.index('        constexpr uint32_t kSoundDriverStatusSize',begin);helper=text[begin:finish]
                if helper.count('std::fprintf(stderr,')!=1:raise ValueError('One diagnostic observer adaptation required')
                helper=helper.replace('std::fprintf(stderr,','probe_fprintf(stderr,')
            folder=out/label;folder.mkdir();(folder/'body.inc').write_text('namespace ps2_syscalls {\n'+helper+text[start:end]+'}\n',encoding='utf-8',newline='\n');binary=folder/'check.exe';binaries.append(binary)
            command=[str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Werror','-Wno-misleading-indentation','-I'+str(folder),str(fixture),'-o',str(binary)]
            run=subprocess.run(command,capture_output=True,text=True,env=env);(folder/'compile.txt').write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
            if run.returncode:raise ValueError(label+' compilation failed')
        for mode in MODES:
            observed=[]
            for label,binary in zip(['prior','timed'],binaries):
                run=subprocess.run([str(binary),mode],capture_output=True,text=True,env=env,timeout=15);(out/(label+'-'+mode+'.txt')).write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n')
                if run.returncode:raise ValueError(label+' '+mode+' failed')
                observed.append(run.stdout)
                if label=='timed':
                    m=re.search(r'\[FIXTURE-AUDIT\] reports=(\d+) bad_scope=(\d+)',run.stderr)
                    if not m or int(m[2]) or int(m[1])>64:raise ValueError('Report scope/bound violation')
                    if mode in ['delay_audio','delay_lock','delay_log','refused_slow'] and int(m[1])!=64:raise ValueError('Expected slow-stage reports absent')
                    if mode=='disabled_delay_log' and int(m[1]):raise ValueError('Disabled timing emitted records')
                    for line in run.stderr.splitlines():
                        if not line.startswith('[SIF-INIT-TIMING] '):continue
                        values={k:int(v)for k,v in re.findall(r'(\w+)=(\d+)',line)}
                        parts=['audio_call_ns','lock_wait_ns','work_ns','logging_ns','release_ns']
                        if sum(values[k]for k in parts)!=values['end_ns']-values['begin_ns']:raise ValueError('Stage timing partition differs from total elapsed')
                        expected={'delay_audio':'audio_call_ns','refused_slow':'audio_call_ns','delay_lock':'lock_wait_ns','delay_log':'logging_ns'}.get(mode)
                        if expected and values[expected]<2000000:raise ValueError('Injected delay attributed to wrong stage '+mode)
            if observed[0]!=observed[1]:raise ValueError('Full initializer state/return trace differs '+mode)
            record['profiles'].append(dict(mode=mode,operations=70,identical=True))
        record.update(status='SifInitRpc timing preserves full declared host fixture observations',operations=70*len(MODES),max_reports=64,report_after_sound_and_rpc_release=True)
    finally:
        record['outputs_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.suffix in ['.txt','.inc']};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],operations=record['operations'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
