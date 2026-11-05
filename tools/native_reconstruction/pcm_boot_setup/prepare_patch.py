#!/usr/bin/env python3
"""Author focused0123 and reapply full124 in fresh ignored private clones."""
import argparse
import hashlib
import json
import re
from pathlib import Path
import subprocess

ROOT=Path(__file__).resolve().parents[3]
PIN='c46d1c7d8ab00fbfa18d2c1f764c559e4e5dc78f'
PATCH=ROOT/'third_party/patches/ps2recomp/0123-explicit-pcm-pre-run-reset-transaction.patch'
BASE_RECEIPT=ROOT/'build-native-sjuni/dependency-pcm-profile-reapply-v1-receipt.json'
BASE_RECEIPT_SHA='8f8a001fd50b1bad9c9da8729888b1f682e75c8321bdfd1076da085db52baeb8'
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def run(command):return subprocess.run(command,check=True,capture_output=True,text=True,timeout=120)
def replace(tree,name,old,new):
    path=tree/name;text=path.read_text(encoding='utf-8')
    if text.count(old)!=1:raise ValueError('Nonunique modification in '+name+': '+old[:70])
    path.write_text(text.replace(old,new),encoding='utf-8',newline='\n')
def modify(tree):
    hdr='ps2xRuntime/include/ps2_runtime.h'
    replace(tree,hdr,'#include <mutex>','#include <mutex>\n#include <condition_variable>')
    replace(tree,hdr,'    using RecompiledFunction = void (*)(uint8_t *, R5900Context *, PS2Runtime *);', '''    // Explicit initialization transaction, not a PCM-use or worker-registration
    // exemption. Keep this runtime alive through the token; release before run.
    class PreRunSetupLease final
    {
    public:
        PreRunSetupLease() noexcept = default;
        PreRunSetupLease(PreRunSetupLease&& other) noexcept;
        ~PreRunSetupLease();
        PreRunSetupLease(const PreRunSetupLease&) = delete;
        PreRunSetupLease& operator=(const PreRunSetupLease&) = delete;
        PreRunSetupLease& operator=(PreRunSetupLease&&) = delete;
        explicit operator bool() const noexcept { return m_runtime != nullptr; }
    private:
        friend class PS2Runtime;
        explicit PreRunSetupLease(PS2Runtime* runtime) noexcept : m_runtime(runtime) {}
        PS2Runtime* m_runtime = nullptr;
    };
    // Allocation-free; refuses sealed/stopped runtime. No mutex remains held.
    PreRunSetupLease acquirePreRunSetup() noexcept;

    using RecompiledFunction = void (*)(uint8_t *, R5900Context *, PS2Runtime *);''')
    replace(tree,hdr,'    bool m_externalWorkersSealed = false;','''    bool m_externalWorkersSealed = false;
    std::condition_variable m_preRunSetupChanged;
    size_t m_preRunSetupCount = 0;
    void releasePreRunSetup() noexcept;''')
    runtime='ps2xRuntime/src/lib/ps2_runtime.cpp'
    replace(tree,runtime,'bool PS2Runtime::externalWorkerResetAllowed()','''PS2Runtime::PreRunSetupLease::PreRunSetupLease(PreRunSetupLease&& other) noexcept
    : m_runtime(other.m_runtime)
{
    other.m_runtime = nullptr;
}

PS2Runtime::PreRunSetupLease::~PreRunSetupLease()
{
    if (m_runtime) m_runtime->releasePreRunSetup();
}

PS2Runtime::PreRunSetupLease PS2Runtime::acquirePreRunSetup() noexcept
{
    std::lock_guard<std::mutex> lock(m_externalWorkersMutex);
    if (m_externalWorkersSealed || m_stopRequested.load(std::memory_order_acquire) ||
        m_preRunSetupCount == size_t(-1)) return {};
    ++m_preRunSetupCount;
    return PreRunSetupLease(this);
}

void PS2Runtime::releasePreRunSetup() noexcept
{
    {
        std::lock_guard<std::mutex> lock(m_externalWorkersMutex);
        --m_preRunSetupCount;
    }
    m_preRunSetupChanged.notify_all();
}

bool PS2Runtime::externalWorkerResetAllowed()''')
    replace(tree,runtime,'    return !m_externalWorkers || m_externalWorkers->empty();',
        '    return m_preRunSetupCount == 0 && (!m_externalWorkers || m_externalWorkers->empty());')
    replace(tree,runtime,'''void PS2Runtime::beginExternalWorkerRun()
{
    std::lock_guard<std::mutex> lock(m_externalWorkersMutex);''','''void PS2Runtime::beginExternalWorkerRun()
{
    std::unique_lock<std::mutex> lock(m_externalWorkersMutex);
    // A setup token holds no mutex across initialization hooks. Wait here,
    // releasing the registration mutex, before any run can seal publication.
    m_preRunSetupChanged.wait(lock, [this] { return m_preRunSetupCount == 0; });''')
    audio='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.cpp'
    replace(tree,audio,'void reset() { if(backend_detail::invoke_void<&BackendApiV1::reset>())return; std::lock_guard<std::mutex> lock(mutex);reoAudioResetStreams();channels.clear();voices.clear();externalClock=false;lastTick=std::chrono::steady_clock::now(); }', '''namespace {
void resetLegacyState() { std::lock_guard<std::mutex> lock(mutex);reoAudioResetStreams();channels.clear();voices.clear();externalClock=false;lastTick=std::chrono::steady_clock::now(); }
}
bool resetBeforeRuntimeRun(PS2Runtime& runtime) noexcept {
    auto setup=runtime.acquirePreRunSetup();
    if(!setup)return false;
    {
        std::unique_lock<std::mutex> lock(backend_detail::registry.mutex);
        while(backend_detail::registry.boot_resetting)backend_detail::registry.changed.wait(lock);
        if(backend_detail::registry.mode!=backend_detail::Mode::unselected || backend_detail::registry.installing)return false;
        backend_detail::registry.boot_resetting=true;
    }
    backend_detail::BootResetReservation reservation;
    resetLegacyState(); // Never hold registry/runtime locks across host hooks.
    return true;
}
void reset() { if(backend_detail::invoke_void<&BackendApiV1::reset>())return; resetLegacyState(); }''')
    replace(tree,'ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudio.h','namespace ps2_cri_audio {',
        '''class PS2Runtime;
namespace ps2_cri_audio {
// Only explicit runtime initialization may reset unselected legacy state without
// selecting it. False requires the caller to use ordinary public reset().
bool resetBeforeRuntimeRun(PS2Runtime& runtime) noexcept;''')
    dispatch='ps2xRuntime/src/lib/Kernel/Syscalls/Helpers/CriAudioDispatch.h'
    replace(tree,dispatch,'struct Registry {std::mutex mutex;Mode mode=Mode::unselected;bool installing=false;std::weak_ptr<Binding> binding;};',
        'struct Registry {std::mutex mutex;std::condition_variable changed;Mode mode=Mode::unselected;bool installing=false,boot_resetting=false;std::weak_ptr<Binding> binding;};')
    replace(tree,dispatch,'struct Reservation {','''struct BootResetReservation {
    ~BootResetReservation(){
        {std::lock_guard<std::mutex> lock(registry.mutex);registry.boot_resetting=false;}
        registry.changed.notify_all();
    }
};
struct Reservation {''')
    old='''{std::lock_guard<std::mutex> lock(registry.mutex);
        if(registry.mode==Mode::unselected)registry.mode=Mode::legacy;'''
    new='''{std::unique_lock<std::mutex> lock(registry.mutex);
        while(registry.boot_resetting)registry.changed.wait(lock);
        if(registry.mode==Mode::unselected)registry.mode=Mode::legacy;'''
    path=tree/dispatch;text=path.read_text(encoding='utf-8')
    if text.count(old)!=2:raise ValueError('Expected both public acquisition and shutdown selection sites')
    path.write_text(text.replace(old,new),encoding='utf-8',newline='\n')
    replace(tree,dispatch,'        if(registry.installing)return BackendInstallStatusV1::installation_busy;',
        '        if(registry.installing||registry.boot_resetting)return BackendInstallStatusV1::installation_busy;')
    syscalls='ps2xRuntime/include/ps2_syscalls.h'
    replace(tree,syscalls,'    void setDtxCompatLayout(const PS2DtxCompatLayout &layout);',
        '    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime = nullptr);')
    replace(tree,syscalls,'    void clearDtxCompatLayout();','    void clearDtxCompatLayout(PS2Runtime *runtime = nullptr);')
    rpc='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
    replace(tree,rpc,'        void resetDtxRpcStateUnlocked()\n        {\n            ps2_cri_audio::reset();',
        '        void resetDtxRpcStateUnlocked(PS2Runtime *runtime = nullptr)\n        {\n            if (!runtime || !ps2_cri_audio::resetBeforeRuntimeRun(*runtime)) ps2_cri_audio::reset();')
    replace(tree,rpc,'    void setDtxCompatLayout(const PS2DtxCompatLayout &layout)',
        '    void setDtxCompatLayout(const PS2DtxCompatLayout &layout, PS2Runtime *runtime)')
    replace(tree,rpc,'    void clearDtxCompatLayout()','    void clearDtxCompatLayout(PS2Runtime *runtime)')
    path=tree/rpc;text=path.read_text(encoding='utf-8')
    if len(re.findall(r'^        resetDtxRpcStateUnlocked\(\);$',text,flags=re.M))!=2:raise ValueError('Unexpected DTX layout reset callers')
    path.write_text(re.sub(r'^        resetDtxRpcStateUnlocked\(\);$','        resetDtxRpcStateUnlocked(runtime);',text,flags=re.M),encoding='utf-8',newline='\n')
    overrides='ps2xRuntime/src/lib/game_overrides.cpp'
    replace(tree,overrides,'        ps2_syscalls::clearDtxCompatLayout();','        ps2_syscalls::clearDtxCompatLayout(&runtime);')
    replace(tree,overrides,'        ps2_syscalls::setDtxCompatLayout(layout);','        ps2_syscalls::setDtxCompatLayout(layout, &runtime);')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--author',required=True,type=Path);p.add_argument('--reapply',required=True,type=Path);args=p.parse_args()
    if sha(BASE_RECEIPT)!=BASE_RECEIPT_SHA:raise ValueError('Pinned123 baseline receipt changed')
    baseline=json.loads(BASE_RECEIPT.read_text(encoding='utf-8'));donor=ROOT/'build-native-sjuni/dependency-pcm-dispatch-v2'
    for destination in (args.author,args.reapply):
        destination=destination.resolve()
        if destination.exists() or not destination.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Need fresh private output checkout')
        run(['git','-c','core.autocrlf=true','clone','--shared','--no-checkout',str(donor),str(destination)])
        run(['git','-C',str(destination),'config','core.autocrlf','true']);run(['git','-C',str(destination),'checkout','--detach',PIN])
    author=args.author.resolve()
    for row in baseline['patches']:
        patch=ROOT/row['path']
        if sha(patch)!=row['sha256']:raise ValueError('Prior patch changed')
        run(['git','-C',str(author),'apply','--check',str(patch)]);run(['git','-C',str(author),'apply',str(patch)])
    for name,digest in baseline['source_sha256'].items():
        if sha(author/name)!=digest:raise ValueError('Author source differs from123 baseline')
    run(['git','-C',str(author),'add','-A']);modify(author)
    diff=subprocess.run(['git','-C',str(author),'diff','--binary','--no-ext-diff'],check=True,capture_output=True).stdout
    if not diff:raise ValueError('No focused change')
    PATCH.write_bytes(diff)
    result=run(['python',str(ROOT/'tools/native_reconstruction/audit_dependency_series.py'),'--checkout',str(args.reapply.resolve())])
    print(result.stdout.strip());print('Patch SHA256 '+sha(PATCH))
if __name__=='__main__':main()
