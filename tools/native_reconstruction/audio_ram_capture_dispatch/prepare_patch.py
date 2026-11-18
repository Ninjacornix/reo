#!/usr/bin/env python3
"""Author0125 from verified full125 source; never modifies an active checkout."""
import argparse,difflib,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
BASE=ROOT/'build-native-sjuni/dependency-bank-reapply-v3'
RECEIPT=ROOT/'build-native-sjuni/dependency-bank-reapply-v3-receipt.json'
RECEIPT_SHA='3019662f2fd62dbe4a9b3c7b99528bd631338424597ad78d2a4a04bcebeb3d6a'
PATCH=ROOT/'third_party/patches/ps2recomp/0125-explicit-native-sound-ram-capture-companion.patch'
HELPER='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'
RPC='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp';RPCH='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.h';SIF='ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp'
FILES=[HELPER+x for x in ('CriAudio.cpp','CriAudioBackend.h','CriAudioDispatch.h')]+[RPC,RPCH,SIF]
NEW=[HELPER+'CriAudioRamCapture.h']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def replace(tree,name,old,new):
    p=tree/name;s=read(p)
    if s.count(old)!=1:raise ValueError(f'Nonunique anchor {name}: {old[:100]!r} ({s.count(old)})')
    write(p,s.replace(old,new))
def modify(t):
    write(t/NEW[0],read(HERE/'CriAudioRamCapture.h'))
    p=HELPER+'CriAudioBackend.h'
    replace(t,p,'    friend class SoundCallScope;','    friend class SoundCallScope;\n    friend class NativeSoundRamCallV1;')
    p=HELPER+'CriAudioDispatch.h'
    replace(t,p,'#include "CriAudioBackend.h"','#include "CriAudioBackend.h"\n#include "CriAudioRamCapture.h"\n#include <atomic>')
    replace(t,p,'    AdmittedRenderV2 render_admitted{};','    AdmittedRenderV2 render_admitted{};\n    NativeSoundRamApiV1 ram_capture;')
    replace(t,p,'AdmittedRenderV2 admitted_render)\n','AdmittedRenderV2 admitted_render,const NativeSoundRamApiV1& capture)\n')
    replace(t,p,'render_admitted(admitted_render){}','render_admitted(admitted_render),ram_capture(capture){}')
    replace(t,p,'std::uint64_t controls{};','std::atomic<bool> ram_capture{};std::uint64_t controls{};')
    replace(t,p,'AdmittedRenderV2 render_admitted=nullptr) noexcept {','AdmittedRenderV2 render_admitted=nullptr,const NativeSoundRamApiV1& capture={}) noexcept {')
    replace(t,p,'std::move(registration),runtime,banks,render_admitted);','std::move(registration),runtime,banks,render_admitted,capture);')
    replace(t,p,'registry.mode=Mode::native;','registry.mode=Mode::native;registry.ram_capture.store(capture.abi_version!=0,std::memory_order_release);')
    replace(t,p,'BackendStatusV1 backendStatusV1() noexcept {','''BackendInstallStatusV1 installBackendWithNativeSoundRamBeforeRunV1(PS2Runtime& runtime,BackendRegistrationV2 registration,NativeSoundRamApiV1 capture) noexcept {
    auto& a=registration.api;auto& b=a.banks;
    if(a.abi_version!=backendAbiVersionV2||a.structure_bytes!=sizeof(a)||a.capabilities!=backendRequiredCapabilitiesV2||
       !backend_detail::complete(a.pcm)||!a.render_admitted||!b.submit_bank||!b.submit_packet||!b.mix||!b.reset||
       !b.pending_loads||!b.port_state||!b.se_state||!b.report_audio_paths||
       capture.abi_version!=nativeSoundRamAbiVersionV1||capture.structure_bytes!=sizeof(capture)||
       capture.capabilities!=nativeSoundRamCapabilitiesV1||!capture.max_packet_bytes||capture.max_packet_bytes>(1u<<20)||
       !capture.begin||!capture.end||!capture.read_batch||!capture.control_batch||!capture.copy_forward||
       !capture.snapshot_packet||!capture.log_owned_packet||!capture.report)return BackendInstallStatusV1::invalid_api;
    // This NEW companion alone requires phase ownership through registration
    // AND publication. Actual beginRun waits the allocation-free lease, so no
    // guest RPC can observe old false selection then the new binding. Old V1/V2
    // admission and the no-companion legacy path are deliberately unchanged.
    auto setup=runtime.acquirePreRunSetup();if(!setup)return BackendInstallStatusV1::runtime_rejected;
    return backend_detail::install(runtime,{a.pcm,std::move(registration.owner)},b,a.render_admitted,capture);
}
BackendStatusV1 backendStatusV1() noexcept {''')
    p=HELPER+'CriAudio.cpp';replace(t,p,'namespace ps2_cri_audio {','namespace ps2_cri_audio {\n'+read(HERE/'ram_call.inc'))
    replace(t,RPC,'#include "Helpers/CriAudioBackend.h"','#include "Helpers/CriAudioBackend.h"\n#include "Helpers/CriAudioRamCapture.h"')
    replace(t,RPC,'    } // namespace\n\n    bool handleSoundDriverRpcService','\n'+read(HERE/'rpc_capture.inc')+'\n    } // namespace\n\n    bool handleSoundDriverRpcService')
    replace(t,RPC,'    bool resolveSoundDriverIopTransfer(',read(HERE/'status_capture.inc')+'\n    bool resolveSoundDriverIopTransfer(')
    replace(t,RPC,'    void SifCallRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)',read(HERE/'rpc_outer.inc')+'\n    void SifCallRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)')
    replace(t,RPC,'        std::lock_guard<std::recursive_mutex> rpcCallLock(g_sif_call_rpc_mutex);','        std::lock_guard<std::recursive_mutex> rpcCallLock(g_sif_call_rpc_mutex);\n        if(tryNativeSoundRamRpc(rdram,ctx,runtime))return;')
    # Direct IOP sound entry also captures; the outer SIF companion path calls
    # its captured implementation directly, so never reacquires this token.
    old='''        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum))return false;'''
    new='''        if(ps2_cri_audio::nativeSoundRamSelectedV1()&&(sid==IOP_SID_SNDDRV_COMMAND||sid==IOP_SID_SNDDRV_STATE)){
            auto audio=ps2_cri_audio::acquireSoundCall(runtime);ps2_cri_audio::SoundCallScope audioScope(audio);
            RamCall capture(audio,runtime,rdram,sid==IOP_SID_SNDDRV_COMMAND?ps2_cri_audio::NativeSoundRamUseV1::command:ps2_cri_audio::NativeSoundRamUseV1::query);
            if(!audio||!capture)return true;
            if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum)){
                capture.reject(ps2_cri_audio::NativeSoundRamStageV1::read,ps2_cri_audio::BankStatusV2::unsupported);return true;}
            return handleSoundDriverRpcCaptured(rdram,runtime,sid,rpcNum,sendBuf,sendSize,recvBuf,recvSize,resultPtr,signalNowaitCompletion,audio,capture);
        }
        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum))return false;'''
    replace(t,RPC,old,new)
    replace(t,RPCH,'namespace ps2_cri_audio {class SoundCall;}','namespace ps2_cri_audio {class SoundCall;class NativeSoundRamCallV1;}')
    replace(t,RPCH,'    bool resolveSoundDriverIopTransfer(','''    bool describeSoundDriverIopTransfer(PS2Runtime*,uint32_t,uint32_t,bool&);
    bool prepareSoundDriverStatusTransferCaptured(uint32_t,uint32_t,PS2Runtime*,ps2_cri_audio::NativeSoundRamCallV1&);
    bool resolveSoundDriverIopTransfer(''')
    replace(t,SIF,'#include "../Syscalls/Helpers/CriAudioBackend.h"','#include "../Syscalls/Helpers/CriAudioBackend.h"\n#include "../Syscalls/Helpers/CriAudioRamCapture.h"')
    replace(t,SIF,'        ps2_syscalls::prepareSoundDriverStatusTransfer(rdram, srcAddr, size,runtime,audio);',read(HERE/'sif_capture.inc')+'\n        ps2_syscalls::prepareSoundDriverStatusTransfer(rdram, srcAddr, size,runtime,audio);')
def main():
    p=argparse.ArgumentParser();p.add_argument('--author',type=Path,required=True);a=p.parse_args();t=a.author.resolve()
    if t.exists()or not t.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh author below build-native-sjuni required')
    if sha(RECEIPT)!=RECEIPT_SHA:raise ValueError('Full125 receipt drift')
    receipt=json.loads(read(RECEIPT))
    if receipt['applied_count']!=125:raise ValueError('Wrong prior patch count')
    for name,digest in receipt['source_sha256'].items():
        if sha(BASE/name)!=digest:raise ValueError('Full125 source drift: '+name)
    for entry in receipt['patches']:
        if sha(ROOT/entry['path'])!=entry['sha256']:raise ValueError('Prior public patch drift')
    for n in FILES:write(t/n,read(BASE/n))
    modify(t);patch=[]
    for n in sorted(FILES+NEW):
        before=read(BASE/n)if(BASE/n).exists()else'';after=read(t/n)
        if before==after:continue
        patch+=['diff --git a/'+n+' b/'+n+'\n']
        if not before:patch+=['new file mode 100644\n']
        patch+=list(difflib.unified_diff(before.splitlines(keepends=True),after.splitlines(keepends=True),fromfile='a/'+n if before else'/dev/null',tofile='b/'+n))
    write(PATCH,''.join(patch));print('patch',sha(PATCH))
if __name__=='__main__':main()
