#!/usr/bin/env python3
"""Native PCM vs frozen exact-candidate-source observations; no game/device."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import re
import shutil
import subprocess

ROOT=Path(__file__).resolve().parents[4]
HERE=Path(__file__).resolve().parent
FIXTURE_SHA='819470f5433c09a5549fefae5f726012ba9ab34f3cc2e4ed3545007d89bea909'
TRANSCRIPT_SHA='697194d2089779baf86074cf8cce28819607c4f7fd2e7561bcf557ac1d189183'
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',required=True,type=Path)
    p.add_argument('--dependency',type=Path,default=ROOT/'build-native-sjuni/dependency-workers-v1')
    p.add_argument('--fixture',type=Path,default=ROOT/'build-native-sjuni/pcm-owner-oracle/gcc/fixtures.json');args=p.parse_args()
    compiler=shutil.which(args.cxx)
    if not compiler:p.error('Existing C++20 compiler required')
    out=args.output.resolve();allowed=ROOT/'build-native-sjuni'
    if out==allowed or not out.is_relative_to(allowed):p.error('Use ignored output')
    if sha(args.fixture)!=FIXTURE_SHA:raise ValueError('Frozen expected observations changed')
    transcript=ROOT/'tools/native_reconstruction/pcm_owner_oracle.py'
    if sha(transcript)!=TRANSCRIPT_SHA:raise ValueError('Authored action transcript changed')
    spec=importlib.util.spec_from_file_location('reference_transcript',transcript);ref=importlib.util.module_from_spec(spec);spec.loader.exec_module(ref)
    expected=json.loads(args.fixture.read_text());dep=args.dependency.resolve()/'ps2xRuntime/src/lib'
    for name,value in expected['source_sha256'].items():
        if sha(dep/name)!=value:raise ValueError('Pinned bridge/reference source changed: '+name)
    out.mkdir(parents=True,exist_ok=True);snapshot=out/'snapshot';helpers=snapshot/'Kernel/Syscalls/Helpers';helpers.mkdir(parents=True,exist_ok=True)
    shutil.copyfile(dep/'Kernel/Syscalls/Helpers/CriAudio.h',helpers/'CriAudio.h')
    (helpers/'ReoSoundBanks.h').write_text(ref.MOCK_BANK);(snapshot/'ps2_host_backend.h').write_text(ref.MOCK_HOST);(snapshot/'vblank_music_diag.h').write_text(ref.MOCK_DIAG)
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
        'void discardUnlessNaturalEnd(const DtxPs2RnaState& rna,uint32_t,uint32_t){bool unreturned=false;const auto left=resolveRnaRing(rna.sjHandle0),right=resolveRnaRing(rna.sjHandle1);for(const auto& p:g_pcmPending)if((p.ring==left||p.ring==right)&&!p.replied)unreturned=true;ps2_cri_audio::native_stop(rna.handle,unreturned,rna.sampleFreq);}',
        'uint32_t dtxPacedConsumeBudgetBytes(DtxPs2RnaState& rna,uint64_t now){reo::native::pcm::PacedState state{rna.lastConsumeNs};auto result=reo::native::pcm::paced_budget(state,rna.sampleFreq,rna.channelCount,rna.sjHandle0!=0,rna.sjHandle1!=0,now);rna.lastConsumeNs=state.last_ns;return result;}']
    (out/'rpc_methods.inc').write_text('\n'.join(parts)+'\n')
    replacement='#define std pcm_test_std\n#include "snapshot/Kernel/Syscalls/Helpers/CriAudio.cpp"\n#undef std'
    if ref.HARNESS.count(replacement)!=1:raise ValueError('Action transcript substitution not unique')
    harness=ref.HARNESS.replace(replacement,'#include "native_facade.hpp"')
    source=out/'native_probe.cpp';source.write_text(harness);exe=out/'native_probe.exe'
    command=[compiler,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread','-I'+str(snapshot),'-I'+str(ROOT),'-I'+str(HERE),str(source),str(HERE.parent/'pcm.cpp'),'-o',str(exe)]
    env=dict(os.environ);cc=Path(compiler).resolve();bins=[cc.parent,cc.parent.parent/'x86_64-w64-mingw32/bin'];env['PATH']=os.pathsep.join(str(b) for b in bins if b.is_dir())+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',fixture_sha256=FIXTURE_SHA,transcript_sha256=TRANSCRIPT_SHA,compiler=compiler,
        command=command,compiler_sha256=sha(cc),game_run=False,device_opened=False,source_sha256={str(f.relative_to(ROOT)):sha(f) for f in (HERE.parent/'pcm.hpp',HERE.parent/'pcm.cpp',HERE/'native_facade.hpp',HERE/'pcm_tests.cpp',Path(__file__))})
    try:
        unit_command=[compiler,'-std=c++20','-O1','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-pthread',
            '-I'+str(HERE.parent),str(HERE.parent/'pcm.cpp'),str(HERE/'pcm_tests.cpp'),'-o',str(out/'pcm_tests.exe')]
        unit_build=subprocess.run(unit_command,capture_output=True,text=True,env=env,timeout=90)
        receipt['unit_compile']={'command':unit_command,'exit_code':unit_build.returncode,'stderr':unit_build.stderr}
        if unit_build.returncode:raise RuntimeError(unit_build.stderr)
        unit_run=subprocess.run([str(out/'pcm_tests.exe')],capture_output=True,text=True,env=env,timeout=30)
        receipt['unit_tests']={'exit_code':unit_run.returncode,'stdout':unit_run.stdout,'stderr':unit_run.stderr}
        if unit_run.returncode:raise RuntimeError(unit_run.stderr)
        build=subprocess.run(command,capture_output=True,text=True,env=env,timeout=90);receipt['compile']={'exit_code':build.returncode,'stderr':build.stderr}
        if build.returncode:raise RuntimeError(build.stderr)
        run=subprocess.run([str(exe)],capture_output=True,text=True,env=env,timeout=30);receipt['execution']={'exit_code':run.returncode,'stderr':run.stderr}
        if run.returncode:raise RuntimeError(run.stderr)
        actual=[json.loads(line) for line in run.stdout.splitlines()];(out/'actual.json').write_text(json.dumps(actual,indent=2)+'\n')
        if len(actual)!=len(expected['records']):raise ValueError('Snapshot count differs')
        differences=[]
        for n,(a,b) in enumerate(zip(actual,expected['records'])):
            for key in set(a)|set(b):
                if a.get(key)!=b.get(key):differences.append(dict(record=n,case=b['case'],operation=b['operation'],field=key,actual=a.get(key),expected=b.get(key)))
        receipt['differences']=differences
        if differences:raise ValueError(str([(d['record'],d['case'],d['field']) for d in differences]))
        receipt.update(status='passed',cases=len({r['case'] for r in actual}),snapshots=len(actual),float_values=sum(len(r['float_bits']) for r in actual))
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        receipt['limitations']=['Core PCM/timing/stop/paced policies compared; original RPC credit publication reused as a test-only bridge, not migrated.',
            'Action transcript reused read-only; frozen expected observations never regenerated.',
            'No device/bank/PS2 runtime/native integration parity claim.']
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n')
    print(json.dumps({k:receipt[k] for k in ('status','cases','snapshots','float_values')}))

if __name__=='__main__':main()
