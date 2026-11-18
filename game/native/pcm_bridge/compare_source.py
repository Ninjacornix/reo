#!/usr/bin/env python3
"""Exact reconstructed121 actions -> independent raw-ID session bridge.

Frozen expected output is read only. The native bridge computes its own actual
unordered-map traversal; expected traversal is compared, never supplied to it.
No game/device/real bank or runtime is opened.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
SOURCE_ROOT=ROOT/'tools/native_reconstruction'
FROZEN={
 'game/native/pcm/pcm.cpp':'fe31c38f6c276c60c1f1f7cbf5bea2d9132b83c85fd0b49629b0ca721bf4e844',
 'game/native/pcm/pcm.hpp':'9fe0aff92070569bfd6744856ea438b92099ec38f1875dc660261ef755b659cb',
 'game/native/pcm_bridge/session_bridge.cpp':'fcf284fa46a752f07a2f48a019cce8f6f2df8eae7d864aef787ca46854bc9649',
 'game/native/pcm_bridge/session_bridge.hpp':'0b7c0b6f70234110035d05757aa93095ea4176b069f55fd581dee00ade31f9f3',
 'tools/native_reconstruction/pcm_owner_oracle.py':'697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183',
 'tools/native_reconstruction/pcm_order_oracle.py':'0695fde97a5eb1888e838084bffca096bda129244d028043ee515f1cc835617d',
 'tools/native_reconstruction/pcm_source_domains_oracle.py':'10d91f6ff7473d6e9c21723b52b982e8db888cabbacf29cd90629394cc82a8ac',
}
EXPECTED={
 'owner':{'819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909'},
 'order':{'86aef42be64adbed4b6fcd43045348f19691a0de8b1323b13858f08c5494ee10',
          '361d4d35971e692ee4b5e62fff0edcce4f3d985f61b627f4b295a15394440c4d'},
 'domains':{'15547497f2fa81c1c9f50f40ddc5a67f5b84176dfe3d552e6a939e4a63c86206',
            'b3fcb8285711942c47fa3d644f1d236c8474db5442428d81b1bd911b90edd6e8'},
}
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def load(name):
    path=SOURCE_ROOT/(name+'.py')
    spec=importlib.util.spec_from_file_location(name,path)
    module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    return module
def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True)
    p.add_argument('--dependency',type=Path,default=ROOT/'build-native-sjuni/dependency-workers-reapply-v2')
    p.add_argument('--owner-fixture',type=Path,default=ROOT/'build-native-sjuni/pcm-owner-oracle/gcc/fixtures.json')
    p.add_argument('--order-fixture',type=Path,required=True)
    p.add_argument('--domains-fixture',type=Path,required=True)
    args=p.parse_args()
    cc=shutil.which(args.cxx);out=args.output.resolve()
    if not cc or out==ROOT/'build-native-sjuni' or not out.is_relative_to(ROOT/'build-native-sjuni'):
        raise ValueError('Requires existing compiler and private ignored output')
    for name,digest in FROZEN.items():
        if sha(ROOT/name)!=digest:raise ValueError('Frozen independent input changed: '+name)
    reconstruction=ROOT/'build-native-sjuni/dependency-workers-reapply-v2-receipt.json'
    reconstruction_sha='2b8088a430a63517ad2a77910970e37bccf9658e3c7c91ac6525a70b1db0cca8'
    if sha(reconstruction)!=reconstruction_sha:raise ValueError('Exact source reconstruction receipt changed')
    fixtures={'owner':args.owner_fixture,'order':args.order_fixture,'domains':args.domains_fixture}
    for name in fixtures:
        if sha(fixtures[name]) not in EXPECTED[name]:raise ValueError('Frozen '+name+' fixture changed')
    ref=load('pcm_owner_oracle');order=load('pcm_order_oracle');domains=load('pcm_source_domains_oracle')
    dep=args.dependency.resolve()/'ps2xRuntime/src/lib'
    for name,digest in ref.EXPECTED.items():
        if sha(dep/name)!=digest:raise ValueError('Exact source mismatch: '+name)
    out.mkdir(parents=True,exist_ok=True)
    snapshot=out/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    for name in ('CriAudio.h','CriAudio.cpp'):shutil.copyfile(dep/'Kernel/Syscalls/Helpers'/name,helpers/name)
    (helpers/'ReoSoundBanks.h').write_text(ref.MOCK_BANK)
    (snapshot/'ps2_host_backend.h').write_text(ref.MOCK_HOST)
    (snapshot/'vblank_music_diag.h').write_text(ref.MOCK_DIAG)
    shutil.copyfile(dep/'cri_pcm_retire.h',snapshot/'cri_pcm_retire.h')
    rpc=(dep/'Kernel/Syscalls/RPC.cpp').read_text();state=(dep/'Kernel/Syscalls/Helpers/State.h').read_text()
    parts=[ref.block(state,'struct '+s,';') for s in ('DtxSjxState','DtxPs2RnaState','DtxSjrmtState','DtxTransferState')]
    parts+=['std::unordered_map<uint32_t,DtxSjxState> g_dtx_sjx_by_handle;std::unordered_map<uint32_t,DtxSjrmtState> g_dtx_sjrmt_by_handle;']
    parts+=[ref.block(rpc,'struct '+s,';') for s in ('SjxReply','PcmPending')]
    parts+=['std::deque<PcmPending> g_pcmPending;std::deque<SjxReply> g_sjxReplies;std::mutex g_dtx_rpc_mutex;',
        re.search(r'constexpr uint64_t kIopPcmBufferBytes=[^;]+;',rpc).group(0),'uint8_t wire[1024];',
        'uint8_t* getMemPtr(uint8_t* p,uint32_t at){if(p!=wire||at>sizeof(wire)-16)throw std::runtime_error("mock wire bounds");return p+at;}',
        'void writeGuestU32(uint8_t* p,uint32_t at,uint32_t v){std::memcpy(getMemPtr(p,at),&v,4);}',
        ref.block(rpc,'uint32_t resolveRnaRing('),ref.block(rpc,'void collectSjxReplies('),
        ref.block(rpc,'void discardUnlessNaturalEnd('),ref.block(rpc,'uint32_t dtxPacedConsumeBudgetBytes(')]
    (out/'rpc_methods.inc').write_text('\n'.join(parts)+'\n')
    marker='#define std pcm_test_std\n#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"\n#undef std'
    if ref.HARNESS.count(marker)!=1:raise ValueError('Source replacement not unique')
    prefix=ref.HARNESS.split(marker)[0]+'#include "test_facade.hpp"\n'
    owner=ref.HARNESS.replace(marker,'#include "test_facade.hpp"')
    order_harness=order.HARNESS.replace('for(const auto& row:a::voices)order.push_back(row.first);','for(auto key:a::raw_order())order.push_back(key);')
    order_harness=order_harness.replace('a::voices.bucket_count()','a::bridge.voice_bucket_count()')
    domain_harness=domains.HARNESS.replace('for(const auto& row:a::voices)result.push_back(row.first);','for(auto key:a::raw_order())result.push_back(key);')
    domain_harness=domain_harness.replace('a::voices.bucket_count()','a::bridge.voice_bucket_count()')
    expected={name:json.loads(path.read_text()) for name,path in fixtures.items()}
    programs={'owner':owner,
        'order':prefix+order_harness+order.action_program(expected['order']['inputs']),
        'domains':prefix+domain_harness+domains.action_program(expected['domains']['inputs'])}
    extra=(HERE/'source_hooks.inc').read_text()
    native_extra=extra.replace('bool comma=false;for(const auto& row:a::voices){if(comma)std::cout<<\',\';comma=true;std::cout<<row.first;}',
        'bool comma=false;for(auto key:a::raw_order()){if(comma)std::cout<<\',\';comma=true;std::cout<<key;}')
    programs['hooks-original']=ref.HARNESS.split(marker)[0]+marker+'\n'+extra
    programs['hooks']=prefix+native_extra
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),
        frozen_inputs=FROZEN,dependency_reconstruction_sha256=reconstruction_sha,
        exact_source_sha256=ref.EXPECTED,fixture_sha256={k:sha(v) for k,v in fixtures.items()},runs={},game_run=False,device_opened=False)
    try:
        for name,code in programs.items():
            source=out/(name+'.cpp');source.write_text(code);exe=out/(name+'.exe')
            native_sources=[] if name=='hooks-original' else [str(HERE/'session_bridge.cpp'),str(HERE.parent/'pcm/pcm.cpp')]
            command=[cc,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
                '-I'+str(snapshot),'-I'+str(ROOT),'-I'+str(HERE),str(source)]+native_sources+['-o',str(exe)]
            result=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120)
            item=receipt['runs'][name]=dict(command=command,compile_exit=result.returncode,compile_stderr=result.stderr)
            if result.returncode:raise RuntimeError(result.stderr)
            run=subprocess.run([str(exe)],env=env,capture_output=True,text=True,timeout=40)
            item.update(exit_code=run.returncode,stderr=run.stderr)
            if run.returncode:raise RuntimeError(run.stderr)
            actual=[json.loads(line) for line in run.stdout.splitlines()]
            (out/(name+'-actual.json')).write_text(json.dumps(actual,indent=2)+'\n')
            if name=='hooks-original':
                expected['hooks']=dict(records=actual)
                item.update(cases=len(actual),snapshots=len(actual),float_values=sum(len(r.get('float_bits',[])) for r in actual),expected_only=True)
                item['fixture_sha256']=sha(out/(name+'-actual.json'))
                continue
            rows=expected[name]['records'];differences=[]
            if len(actual)!=len(rows):raise ValueError(name+' snapshot count changed')
            for index,(a,b) in enumerate(zip(actual,rows)):
                for key in set(a)|set(b):
                    if a.get(key)!=b.get(key):differences.append(dict(record=index,case=b['case'],field=key,actual=a.get(key),expected=b.get(key)))
            item.update(cases=len({r['case'] for r in actual}),snapshots=len(actual),float_values=sum(len(r.get('float_bits',[])) for r in actual),differences=differences)
            if differences:raise ValueError(name+': '+str([(d['record'],d['case'],d['field']) for d in differences]))
        unit=out/'unit.exe'
        command=[cc,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
            str(HERE/'session_bridge_tests.cpp'),str(HERE/'session_bridge.cpp'),str(HERE.parent/'pcm/pcm.cpp'),'-o',str(unit)]
        build=subprocess.run(command,env=env,capture_output=True,text=True,timeout=120)
        receipt['unit']=dict(command=command,compile_exit=build.returncode,compile_stderr=build.stderr)
        if build.returncode:raise RuntimeError(build.stderr)
        run=subprocess.run([str(unit)],env=env,capture_output=True,text=True,timeout=40)
        receipt['unit'].update(exit_code=run.returncode,stdout=run.stdout,stderr=run.stderr)
        if run.returncode:raise RuntimeError(run.stderr)
        receipt['status']='passed'
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['source_sha256']={str(p.relative_to(ROOT)):sha(p) for p in (HERE/'session_bridge.hpp',HERE/'session_bridge.cpp',HERE/'session_bridge_tests.cpp',HERE/'source_hooks.inc',HERE/'test_facade.hpp',Path(__file__))}
        receipt['limitations']=['Real PCM core and computed raw-map traversal; host clock/gain/bank/provider mocked.',
            'Original RPC policy methods reused unchanged as test callers, not migrated or installed.',
            'No provider callback fence, runtime registration, unrestricted game capacity or game behavior established.']
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps(dict(status=receipt['status'],runs={k:{n:v[n] for n in ('cases','snapshots','float_values')} for k,v in receipt['runs'].items()})))
if __name__=='__main__':main()
