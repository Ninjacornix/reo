#!/usr/bin/env python3
"""Author focused0124 from immutable full124, without editing its source tree.

Only a small isolated source copy is created here. Full clean series reapplication
is a separate required verification step; this tool never edits active checkouts.
"""
import argparse
import difflib
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[3]
HERE=Path(__file__).resolve().parent
BASE=ROOT/'build-native-sjuni/dependency-pcm-boot-reapply-v3'
RECEIPT=ROOT/'build-native-sjuni/dependency-pcm-boot-reapply-v3-receipt.json'
RECEIPT_SHA='944b72d4cc977ac01d8e7a4459c601f0a331b06c8adbb5048bec45a2963f91cb'
PATCH=ROOT/'third_party/patches/ps2recomp/0124-complete-audio-bank-owner-dispatch.patch'
HELPER='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/'
RPC='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
FILES=[HELPER+x for x in ['CriAudio.cpp','CriAudioBackend.h','CriAudioDispatch.h','ReoSoundBanks.cpp']]+[RPC,
    'ps2xRuntime/include/ps2_syscalls.h','ps2xRuntime/src/lib/ps2_runtime.cpp',
    'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.h','ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp']

def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def read(path):return path.read_text(encoding='utf-8')
def write(path,text):path.parent.mkdir(parents=True,exist_ok=True);path.write_text(text,encoding='utf-8',newline='\n')
def replace(tree,name,old,new):
    p=tree/name;s=read(p)
    if s.count(old)!=1:raise ValueError(f'Nonunique change {name}: {old[:100]!r} ({s.count(old)})')
    write(p,s.replace(old,new))

def modify(tree):
    p=HELPER+'CriAudioBackend.h'
    replace(tree,p,'} // namespace ps2_cri_audio',read(HERE/'CriAudioBackendV2.inc')+'\n} // namespace ps2_cri_audio')
    p=HELPER+'CriAudioDispatch.h'
    replace(tree,p,'    BackendRegistrationV1 registration;','''    BackendRegistrationV1 registration;
    PS2Runtime* runtime{};
    BankApiV2 banks;
    AdmittedRenderV2 render_admitted{};''')
    replace(tree,p,'explicit Binding(BackendRegistrationV1 value):registration(std::move(value)){}',
        '''explicit Binding(BackendRegistrationV1 value,PS2Runtime& identity,const BankApiV2& bank_api,AdmittedRenderV2 admitted_render)
        :registration(std::move(value)),runtime(&identity),banks(bank_api),render_admitted(admitted_render){}''')
    replace(tree,p,'    const bool admitted;','    bool admitted;')
    replace(tree,p,'bool installing=false,boot_resetting=false;','bool installing=false,boot_resetting=false,joint_banks=false;')
    replace(tree,p,'std::weak_ptr<Binding> binding;};','std::uint64_t controls{};std::weak_ptr<Binding> binding;};')
    replace(tree,p,'if(registry.installing||registry.boot_resetting)return BackendInstallStatusV1::installation_busy;',
        'if(registry.installing||registry.boot_resetting||registry.controls)return BackendInstallStatusV1::installation_busy;')
    replace(tree,p,'BackendInstallStatusV1 installBackendBeforeRunV1(PS2Runtime& runtime,BackendRegistrationV1 registration) noexcept {',
        '''namespace backend_detail {
inline BackendInstallStatusV1 install(PS2Runtime& runtime,BackendRegistrationV1 registration,const BankApiV2& banks={},AdmittedRenderV2 render_admitted=nullptr) noexcept {''')
    replace(tree,p,'auto binding=std::make_shared<Binding>(std::move(registration));','auto binding=std::make_shared<Binding>(std::move(registration),runtime,banks,render_admitted);')
    replace(tree,p,'registry.binding=binding;registry.mode=Mode::native;','registry.binding=binding;registry.joint_banks=render_admitted!=nullptr;registry.mode=Mode::native;')
    replace(tree,p,'BackendStatusV1 backendStatusV1() noexcept {','''} // namespace backend_detail
BackendInstallStatusV1 installBackendBeforeRunV1(PS2Runtime& runtime,BackendRegistrationV1 registration) noexcept {
    return backend_detail::install(runtime,std::move(registration));
}
BackendInstallStatusV1 installBackendBeforeRunV2(PS2Runtime& runtime,BackendRegistrationV2 registration) noexcept {
    auto& a=registration.api;auto& b=a.banks;
    if(a.abi_version!=backendAbiVersionV2||a.structure_bytes!=sizeof(a)||a.capabilities!=backendRequiredCapabilitiesV2||
       !backend_detail::complete(a.pcm)||!a.render_admitted||!b.submit_bank||!b.submit_packet||!b.mix||!b.reset||
       !b.pending_loads||!b.port_state||!b.se_state||!b.report_audio_paths)return BackendInstallStatusV1::invalid_api;
    return backend_detail::install(runtime,{a.pcm,std::move(registration.owner)},b,a.render_admitted);
}
BackendStatusV1 backendStatusV1() noexcept {''')
    p=HELPER+'CriAudio.cpp'
    replace(tree,p,'#include "ReoSoundBanks.h"','#include "ReoSoundBanks.h"\n#include "ReoSoundBanksLegacy.h"')
    replace(tree,p,'namespace ps2_cri_audio {','namespace ps2_cri_audio {\n'+read(HERE/'sound_call.inc'))
    replace(tree,p,'if(backend_detail::registry.mode!=backend_detail::Mode::unselected || backend_detail::registry.installing)return false;',
        'if(backend_detail::registry.mode!=backend_detail::Mode::unselected || backend_detail::registry.installing||backend_detail::registry.controls)return false;')
    old='''        if(call.admitted){backend_detail::Scope scope(backend_detail::active_call,call.binding.get());auto& r=call.binding->registration;r.api.render(r.owner.get(),dst,frames);}'''
    new='''        if(call.admitted){
            backend_detail::Scope scope(backend_detail::active_call,call.binding.get());auto& r=call.binding->registration;
            if(call.binding->render_admitted){
                // Transfer, do not reacquire, this complete render's lease.
                SoundCall sound;sound.binding_=call.binding;sound.status_=BankStatusV2::ok;sound.admitted_=std::exchange(call.admitted,false);
                call.binding->render_admitted(r.owner.get(),sound,dst,frames);
                // SoundCall owns the transferred count through bank completion.
            }else r.api.render(r.owner.get(),dst,frames);
        }'''
    replace(tree,p,old,new)
    # Render's SoundCall takes the existing Call count, without reacquiring. Its
    # fields remain inaccessible to external owners; only this facade is friend.
    p=HELPER+'CriAudioBackend.h'
    replace(tree,p,'    friend class SoundCallScope;','    friend class SoundCallScope;\n    friend void render(float*,unsigned);')
    p=HELPER+'ReoSoundBanks.cpp'
    replace(tree,p,'#include "ReoSoundBanks.h"','#include "ReoSoundBanks.h"\n#include "CriAudioBackend.h"\n#include "ReoSoundBanksLegacy.h"')
    replace(tree,p,'bool submitBank(unsigned port, const uint8_t* hd, size_t hn, const uint8_t* bd, size_t bn,','namespace legacy_detail {\nbool submitBank(unsigned port, const uint8_t* hd, size_t hn, const uint8_t* bd, size_t bn,')
    s=read(tree/p);end=s.rfind('\n}')
    write(tree/p,s[:end]+'\n} // namespace legacy_detail\n'+read(HERE/'bank_wrappers.inc')+s[end:])
    write(tree/(HELPER+'ReoSoundBanksLegacy.h'),read(HERE/'ReoSoundBanksLegacy.h'))
    p=RPC
    replace(tree,p,'#include "Helpers/CriAudio.h"','#include "Helpers/CriAudio.h"\n#include "Helpers/CriAudioBackend.h"')
    replace(tree,p,'void resetDtxRpcStateUnlocked(PS2Runtime *runtime = nullptr)',
        'void resetDtxRpcStateUnlocked(PS2Runtime *runtime = nullptr,const ps2_cri_audio::SoundCall* admitted_audio=nullptr)')
    replace(tree,p,'            if (!runtime || !ps2_cri_audio::resetBeforeRuntimeRun(*runtime)) ps2_cri_audio::reset();',
        '            if(admitted_audio)(void)admitted_audio->reset_pcm();\n            else if (!runtime || !ps2_cri_audio::resetBeforeRuntimeRun(*runtime)) ps2_cri_audio::reset();')
    replace(tree,p,'''    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime)
    {
        std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);
        g_dtxCompatLayout = layout;
        resetDtxRpcStateUnlocked(runtime);
    }''','''    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime)
    {
        struct Arguments {const PS2DtxCompatLayout* layout;} arguments{&layout};
        const auto operation=[](void* context,const ps2_cri_audio::SoundCall& audio) noexcept {
            std::scoped_lock lock(g_rpc_mutex,g_dtx_rpc_mutex);
            g_dtxCompatLayout=*static_cast<Arguments*>(context)->layout;
            resetDtxRpcStateUnlocked(nullptr,&audio);
        };
        if(runtime&&ps2_cri_audio::withAudioSetupBeforeRun(*runtime,operation,&arguments))return;
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);if(!audio||(!runtime&&audio.native()))return;
        ps2_cri_audio::SoundCallScope scope(audio);operation(&arguments,audio);
    }''')
    replace(tree,p,'''    void clearDtxCompatLayout(PS2Runtime *runtime)
    {
        std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);
        g_dtxCompatLayout = {};
        resetDtxRpcStateUnlocked(runtime);
    }''','''    void clearDtxCompatLayout(PS2Runtime *runtime)
    {
        const auto operation=[](void*,const ps2_cri_audio::SoundCall& audio) noexcept {
            std::scoped_lock lock(g_rpc_mutex,g_dtx_rpc_mutex);
            g_dtxCompatLayout={};resetDtxRpcStateUnlocked(nullptr,&audio);
        };
        if(runtime&&ps2_cri_audio::withAudioSetupBeforeRun(*runtime,operation,nullptr))return;
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);if(!audio||(!runtime&&audio.native()))return;
        ps2_cri_audio::SoundCallScope scope(audio);operation(nullptr,audio);
    }''')
    replace(tree,p,'''    void SifInitRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);''','''    void SifInitRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        // Generic SIF entry still mutates selected PCM/sound status on init.
        // Refuse foreign/unknown/stopped V2 before ANY such shared-state write.
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);
        if(!audio||(audio.native()&&(!runtime||rdram!=runtime->memory().getRDRAM()))){setReturnS32(ctx,-1);return;}
        ps2_cri_audio::SoundCallScope scope(audio);
        std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);''')
    replace(tree,p,'            resetDtxRpcStateUnlocked();','            resetDtxRpcStateUnlocked(nullptr,audio.native()?&audio:nullptr);')
    replace(tree,p,'''    void setSoundDriverCompatLayout(const PS2SoundDriverCompatLayout &layout)
    {
        std::lock_guard<std::mutex> lock(g_rpc_mutex);''','''    void setSoundDriverCompatLayout(const PS2SoundDriverCompatLayout &layout)
    {
        auto audio=ps2_cri_audio::acquireSoundControlCall(nullptr);if(!audio)return;
        std::lock_guard<std::mutex> lock(g_rpc_mutex);''')
    replace(tree,p,'''    void clearSoundDriverCompatLayout()
    {
        std::lock_guard<std::mutex> lock(g_rpc_mutex);''','''    void clearSoundDriverCompatLayout()
    {
        auto audio=ps2_cri_audio::acquireSoundControlCall(nullptr);if(!audio)return;
        std::lock_guard<std::mutex> lock(g_rpc_mutex);''')
    replace(tree,p,'''    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size)
    {
        std::lock_guard<std::mutex> lock(g_rpc_mutex);''','''    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size,PS2Runtime* runtime)
    {
        auto audio=ps2_cri_audio::acquireSoundControlCall(runtime);if(!audio)return;
        if(audio.native()&&rdram!=runtime->memory().getRDRAM())return;
        ps2_cri_audio::SoundCallScope scope(audio);
        std::lock_guard<std::mutex> lock(g_rpc_mutex);
        if(audio.native()&&g_soundDriverRpcState.ownerRuntime!=reinterpret_cast<uintptr_t>(runtime))return;''')
    replace(tree,p,'    void finalizeSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t dstAddr, uint32_t size)',
        '''    void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size)
    {prepareSoundDriverStatusTransfer(rdram,srcAddr,size,nullptr);}

    void finalizeSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t dstAddr, uint32_t size)''')
    replace(tree,p,'void resetSoundDriverRpcStateUnlocked()','bool resetSoundDriverRpcStateUnlocked(ps2_cri_audio::SoundCall& audio)')
    replace(tree,p,'            ps2_reo_sound::reset();','            if(audio.reset_banks()!=ps2_cri_audio::BankStatusV2::ok)return false;')
    replace(tree,p,'            g_soundDriverCompatLayout = compat;','            g_soundDriverCompatLayout = compat;\n            return true;')
    replace(tree,p,'void adoptSoundDriverRuntimeUnlocked(PS2Runtime *runtime)','bool adoptSoundDriverRuntimeUnlocked(PS2Runtime *runtime,ps2_cri_audio::SoundCall& audio)')
    replace(tree,p,'                resetSoundDriverRpcStateUnlocked();','                if(!resetSoundDriverRpcStateUnlocked(audio))return false;')
    replace(tree,p,'                g_soundDriverRpcState.ownerRuntime = runtimeCookie;\n            }','                g_soundDriverRpcState.ownerRuntime = runtimeCookie;\n            }\n            return true;')
    replace(tree,p,'bool checkSoundDriverMemoryUnlocked(uint8_t *rdram, PS2Runtime *runtime)','bool checkSoundDriverMemoryUnlocked(uint8_t *rdram, PS2Runtime *runtime,ps2_cri_audio::SoundCall& audio)')
    replace(tree,p,'            adoptSoundDriverRuntimeUnlocked(runtime);','            if(!adoptSoundDriverRuntimeUnlocked(runtime,audio))return false;')
    replace(tree,p,'void handleSoundDriverCommandBuffer(uint8_t *rdram, PS2Runtime *runtime, uint32_t sendBuf, uint32_t sendSize)',
        'void handleSoundDriverCommandBuffer(uint8_t *rdram, PS2Runtime *runtime, uint32_t sendBuf, uint32_t sendSize,ps2_cri_audio::SoundCall& audio)')
    s=read(tree/p).replace('checkSoundDriverMemoryUnlocked(rdram, runtime)','checkSoundDriverMemoryUnlocked(rdram, runtime,audio)')
    write(tree/p,s)
    replace(tree,p,'            ps2_cri_audio::ensureHostOutput();\n            (void)ps2_reo_sound::submitPacket(rdram, 32u * 1024u * 1024u, packet, sendSize);',
        '            if(audio.ensure_output()!=ps2_cri_audio::BankStatusV2::ok)return;\n            (void)audio.submit_packet(rdram, 32u * 1024u * 1024u, packet, sendSize);')
    replace(tree,p,'                                             bool &signalNowaitCompletion)\n        {','                                             bool &signalNowaitCompletion,ps2_cri_audio::SoundCall& audio)\n        {')
    replace(tree,p,'            if (!runtime || !rdram)\n            {\n                return false;\n            }\n\n            if (sid == IOP_SID_SNDDRV_COMMAND',
        '''            // Owned terminal cancellation: no payload/status/owner side effects,
            // no synthetic successful query word, and never service fallback.
            if(!audio || (audio.native()&&(!runtime||!rdram||rdram!=runtime->memory().getRDRAM()))) {
                signalNowaitCompletion=true;return true;
            }
            if (!runtime || !rdram)return false;

            if (sid == IOP_SID_SNDDRV_COMMAND''')
    replace(tree,p,'handleSoundDriverCommandBuffer(rdram, runtime, sendBuf, sendSize);','handleSoundDriverCommandBuffer(rdram, runtime, sendBuf, sendSize,audio);')
    old='''                if (soundQuery == 0x0Cu) words[0] = ps2_reo_sound::pendingLoads();
                else if (soundQuery == 6u) words[0] = ps2_reo_sound::portState(input, words[1]);
                else words[0] = ps2_reo_sound::seState((input >> 16) & 127u, (input >> 8) & 127u, input & 127u);'''
    new='''                ps2_cri_audio::BankQueryV2 query;
                if (soundQuery == 0x0Cu) query = audio.pending_loads();
                else if (soundQuery == 6u) query = audio.port_state(input, words[1]);
                else query = audio.se_state((input >> 16) & 127u, (input >> 8) & 127u, input & 127u);
                if(query.status!=ps2_cri_audio::BankStatusV2::ok){signalNowaitCompletion=true;return true;}
                words[0]=query.value;'''
    replace(tree,p,old,new)
    replace(tree,p,'''                    if (!checkSoundDriverMemoryUnlocked(rdram, runtime,audio))
                    {
                        return false;
                    }''','''                    if (!checkSoundDriverMemoryUnlocked(rdram, runtime,audio))
                    {
                        if(audio.native()){signalNowaitCompletion=true;return true;}
                        return false;
                    }''')
    # Only the public sound wrapper has this exact delegation. Classification
    # precedes selection; direct IOP callers retain through all helper writes.
    replace(tree,p,'        return handleSoundDriverRpcServiceImpl(rdram, runtime,',
        '''        resultPtr=0;signalNowaitCompletion=false;
        if(!ps2_cri_audio::coversSoundRpcV2(sid,rpcNum))return false;
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);
        ps2_cri_audio::SoundCallScope audioScope(audio);
        return handleSoundDriverRpcServiceImpl(rdram, runtime,''')
    replace(tree,p,'                                               signalNowaitCompletion);','                                               signalNowaitCompletion,audio);')
    replace(tree,p,'    void resetSoundDriverRpcState()\n    {\n        std::lock_guard<std::mutex> lock(g_rpc_mutex);\n        resetSoundDriverRpcStateUnlocked();\n    }',
        '''    void resetSoundDriverRpcState(PS2Runtime* runtime)
    {
        auto audio=ps2_cri_audio::acquireSoundCall(runtime);
        if(!audio||(!runtime&&audio.native()))return; // V2 RPC reset requires actual runtime provenance.
        ps2_cri_audio::SoundCallScope scope(audio);
        std::lock_guard<std::mutex> lock(g_rpc_mutex);
        (void)resetSoundDriverRpcStateUnlocked(audio);
    }
    void resetSoundDriverRpcState(){resetSoundDriverRpcState(nullptr);}''')
    replace(tree,p,'        uint32_t serverPtr = client->server;',
        '''        // Classify before any transport payload copy. Hold accepted audio
        // through generic result writes, semaphore completion and end callback.
        const bool isSoundRpc=ps2_cri_audio::coversSoundRpcV2(sid,rpcNum);
        ps2_cri_audio::SoundCall soundCall;
        if(isSoundRpc)soundCall=ps2_cri_audio::acquireSoundCall(runtime);
        ps2_cri_audio::SoundCallScope soundScope(soundCall);
        if(isSoundRpc&&(!soundCall||(soundCall.native()&&(!runtime||rdram!=runtime->memory().getRDRAM())))) {
            // Terminal cancellation, not a successful query or legacy fallback.
            // No packet/result/arena access or guest end callback follows.
            {std::lock_guard<std::mutex> lock(g_rpc_mutex);g_rpc_clients[clientPtr].busy=false;}
            uint32_t semaId=static_cast<uint32_t>(client->hdr.sema_id);
            if(semaId==0xFFFFFFFFu||semaId==0u)semaId=endParam;
            (void)signalRpcCompletionSema(semaId);setReturnS32(ctx,-1);return;
        }
        uint32_t serverPtr = client->server;''')
    replace(tree,p,'            if (runtime->iop().handleRPC(runtime,',
        '''            const bool iopHandled=isSoundRpc
                ? handleSoundDriverRpcServiceImpl(rdram,runtime,sid,rpcNum,sendBuf,sendSize,recvBuf,recvSize,iopResultPtr,iopSignalNowaitCompletion,soundCall)
                : runtime->iop().handleRPC(runtime,''')
    replace(tree,p,'                                         iopSignalNowaitCompletion))\n            {','                                         iopSignalNowaitCompletion);\n            if(iopHandled)\n            {')
    replace(tree,'ps2xRuntime/include/ps2_syscalls.h','    void resetSoundDriverRpcState();',
        '    void resetSoundDriverRpcState();\n    void resetSoundDriverRpcState(PS2Runtime* runtime);')
    replace(tree,'ps2xRuntime/src/lib/ps2_runtime.cpp','ps2_syscalls::resetSoundDriverRpcState();','ps2_syscalls::resetSoundDriverRpcState(this);')
    replace(tree,'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.h',
        '    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size);',
        '    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size);\n    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size,PS2Runtime* runtime);')
    # Transfer holds one selected admission through backfill, pointer borrow,
    # copy, descriptor writes and completion; preparation reuses that same token.
    replace(tree,p,'''    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size,PS2Runtime* runtime)
    {
        auto audio=ps2_cri_audio::acquireSoundControlCall(runtime);if(!audio)return;
        if(audio.native()&&rdram!=runtime->memory().getRDRAM())return;''','''    void prepareSoundDriverStatusTransfer(uint8_t *rdram,uint32_t srcAddr,uint32_t size,PS2Runtime* runtime,const ps2_cri_audio::SoundCall& audio)
    {
        if(!audio||(audio.native()&&(!runtime||rdram!=runtime->memory().getRDRAM())))return;''')
    replace(tree,p,'    void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size)',
        '''    void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size,PS2Runtime* runtime)
    {auto audio=ps2_cri_audio::acquireSoundControlCall(runtime);prepareSoundDriverStatusTransfer(rdram,srcAddr,size,runtime,audio);}

    void prepareSoundDriverStatusTransfer(uint8_t* rdram,uint32_t srcAddr,uint32_t size)''')
    replace(tree,'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.h','#include "ps2_syscalls.h"',
        '#include "ps2_syscalls.h"\nnamespace ps2_cri_audio {class SoundCall;}')
    replace(tree,'ps2xRuntime/src/lib/Kernel/Syscalls/RPC.h',
        '    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size,PS2Runtime* runtime);',
        '    void prepareSoundDriverStatusTransfer(uint8_t *rdram, uint32_t srcAddr, uint32_t size,PS2Runtime* runtime);\n    void prepareSoundDriverStatusTransfer(uint8_t *rdram,uint32_t srcAddr,uint32_t size,PS2Runtime* runtime,const ps2_cri_audio::SoundCall& audio);')
    p='ps2xRuntime/src/lib/Kernel/Stubs/SIF.cpp'
    replace(tree,p,'#include "../Syscalls/RPC.h"','#include "../Syscalls/RPC.h"\n#include "../Syscalls/Helpers/CriAudioBackend.h"')
    replace(tree,p,'''    void sceSifGetOtherData(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        (void)runtime;''','''    void sceSifGetOtherData(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        auto audio=ps2_cri_audio::acquireSoundControlCall(runtime);
        if(!audio||(audio.native()&&(!runtime||rdram!=runtime->memory().getRDRAM()))){setReturnS32(ctx,-1);return;}
        ps2_cri_audio::SoundCallScope scope(audio);''')
    replace(tree,p,'ps2_syscalls::prepareSoundDriverStatusTransfer(rdram, srcAddr, size);',
        'ps2_syscalls::prepareSoundDriverStatusTransfer(rdram, srcAddr, size,runtime,audio);')

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--author',type=Path,required=True);a=p.parse_args();author=a.author.resolve()
    if author.exists() or not author.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh isolated author directory required')
    if sha(RECEIPT)!=RECEIPT_SHA:raise ValueError('Immutable full124 receipt changed')
    receipt=json.loads(read(RECEIPT))
    for name in FILES:
        if sha(BASE/name)!=receipt['source_sha256'][name]:raise ValueError('Immutable124 source changed: '+name)
        write(author/name,read(BASE/name))
    modify(author)
    # Export normalized text against the selected actual source, including the
    # new private header. No checkout/index/base tree is mutated.
    patch=[]
    for name in sorted(FILES+[HELPER+'ReoSoundBanksLegacy.h']):
        before=read(BASE/name) if (BASE/name).exists() else ''
        after=read(author/name)
        if before==after:continue
        patch.append('diff --git a/'+name+' b/'+name+'\n')
        if not before:patch.append('new file mode 100644\n')
        patch.extend(difflib.unified_diff(before.splitlines(keepends=True),after.splitlines(keepends=True),fromfile='a/'+name if before else '/dev/null',tofile='b/'+name))
    write(PATCH,''.join(patch));print('patch',sha(PATCH))
if __name__=='__main__':main()
