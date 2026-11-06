#!/usr/bin/env python3
"""Reproduce0126 from full126-v5, preserving every existing checkout."""
import argparse,difflib,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent
BASE=ROOT/'build-native-sjuni/dependency-ram-reapply-v5'
PROOF=ROOT/'build-native-sjuni/dependency-ram-reapply-v5-receipt.json'
PIN='2de11297c268e453888341b7f3ed44012ae51bdd10c9baa39a168e5cade97ec0'
PATCH=ROOT/'third_party/patches/ps2recomp/0126-seal-selected-gs-sound-ram-profile.patch'
LIB='ps2xRuntime/src/lib/'
FILES=[LIB+n for n in ('gs_backend_route.h','gs_backend_route.cpp','ps2_gs_gpu.cpp','ps2_runtime.cpp')]
NEW=[LIB+'gs_sound_ram_profile.h']
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def read(p):return p.read_text(encoding='utf-8')
def write(p,s):p.parent.mkdir(parents=True,exist_ok=True);p.write_text(s,encoding='utf-8',newline='\n')
def replace(t,n,a,b):
    s=read(t/n)
    if s.count(a)!=1:raise ValueError('Nonunique source anchor '+n+': '+a[:80])
    write(t/n,s.replace(a,b))
def modify(t):
    write(t/NEW[0],read(HERE/'gs_sound_ram_profile.h'))
    n=LIB+'gs_backend_route.h'
    replace(t,n,'struct GSRegisters;','''struct GSRegisters;
class PS2Runtime;class GS;
#define PS2_RUNTIME_HAS_GS_SOUND_RAM_PROFILE 1''')
    replace(t,n,'class Route {','''enum class SoundRamProfileStatusV1:std::uint8_t;
using SoundRamProfileProbeV1=bool (*)(Backend&) noexcept;
class FactorySnapshotV1;class SoundRamSelectionLeaseV1;
struct SoundRamProfileIdentityV1;struct SoundRamProfileResultV1;
class Route {''')
    replace(t,n,'    void stop() noexcept;','''    void stop() noexcept;
    // Explicit recoverable control, before any selected backend effect.
    SoundRamProfileStatusV1 tryStopV1() noexcept;
    bool startRegisteredV1(Choice,const Init&,FactorySnapshotV1,std::string&);''')
    replace(t,n,'private:\n    template<class F> bool execute','''private:
    friend class SoundRamSelectionLeaseV1;
    friend SoundRamProfileResultV1 acquireSoundRamProfileBeforeRunV1(PS2Runtime&) noexcept;
    SoundRamProfileResultV1 acquireProfileV1(SoundRamProfileIdentityV1,std::uint64_t=0) noexcept;
    SoundRamProfileStatusV1 reserveProfileControlV1(bool,std::uint64_t);
    void finishProfileControlV1(std::uint64_t,SoundRamProfileProbeV1) noexcept;
    bool startProfileV1(Choice,const Init&,Factory,std::uint64_t,SoundRamProfileProbeV1,std::string&);
    // Protected by short factory registry metadata lock, never held over GPU.
    std::uint64_t profilePinsV1_{},profileIncarnationV1_{},profileFactoryGenerationV1_{};
    bool profileTransitionV1_{};SoundRamProfileProbeV1 profileProbeV1_{};
    template<class F> bool execute''')
    n=LIB+'gs_backend_route.cpp';replace(t,n,'#include "gs_backend_route.h"','#include "gs_backend_route.h"\n#include "gs_sound_ram_profile.h"')
    replace(t,n,'std::mutex factoryMutex;','''// Process-lifetime fixed metadata storage: the global GS Route can be
// destroyed after this translation unit's ordinary static objects.
std::mutex& factoryMutex() noexcept {
    alignas(std::mutex) static unsigned char storage[sizeof(std::mutex)];
    static std::mutex* value=::new(static_cast<void*>(storage))std::mutex;
    return *value;
}''')
    replace(t,n,'Factory factory;','')
    start=read(t/n).index('void registerFactory(Factory value)');end=read(t/n).index('State Route::state()',start)
    s=read(t/n);s=s[:start]+read(HERE/'profile_control.inc')+'''
void registerFactory(Factory value){
    const auto status=tryRegisterFactoryV1(std::move(value));
    if(status!=SoundRamProfileStatusV1::ok)throw std::logic_error("GS factory registration refused by retained sound selection");
}
Factory registeredFactory(){auto snapshot=registeredFactoryV1();return snapshot.entry_?snapshot.entry_->factory:Factory{};}
void Route::stop() noexcept {
    // Legacy void stop cannot report a recoverable refusal. Continuing into
    // backing destruction would be unsafe; supported control uses tryStopV1.
    if(tryStopV1()!=SoundRamProfileStatusV1::ok)std::terminate();
}
'''+s[end:];write(t/n,s)
    n=LIB+'ps2_gs_gpu.cpp';replace(t,n,'#include "gs_backend_route.h"','#include "gs_backend_route.h"\n#include "gs_sound_ram_profile.h"\n#include "ps2_runtime.h"')
    replace(t,n,'void ps2GsJoinWorker()\n{','''void ps2GsJoinWorker()
{
    // Audio external-worker drain must release its selection before GS join.
    // Never stop a working owner and then discover a retained backing lease.
    auto profileControl=gs_backend_bridge::acquireGlobalGsControlV1();
    if(profileControl.status!=gs_backend_bridge::SoundRamProfileStatusV1::ok)std::terminate();''')
    replace(t,n,'    g_backendRoute.stop();','''    if(g_backendRoute.tryStopV1()!=gs_backend_bridge::SoundRamProfileStatusV1::ok)std::terminate();''')
    replace(t,n,'void GS::init(uint8_t *vram, uint32_t vramSize, GSRegisters *privRegs)\n{','''void GS::init(uint8_t *vram, uint32_t vramSize, GSRegisters *privRegs)
{
    auto profileControl=gs_backend_bridge::acquireGlobalGsControlV1();
    if(profileControl.status!=gs_backend_bridge::SoundRamProfileStatusV1::ok)throw std::logic_error("GS init refused by retained sound selection/control");''')
    replace(t,n,'g_backendRoute.start(gpuRequested','g_backendRoute.startRegisteredV1(gpuRequested')
    replace(t,n,'initial, gs_backend_bridge::registeredFactory(), reason);','initial, gs_backend_bridge::registeredFactoryV1(), reason);')
    marker='namespace gs_backend_bridge {\nuint64_t debugControlQueuedCount()'
    replace(t,n,marker,read(HERE/'gs_gateway.inc')+'\n'+marker)
    n=LIB+'ps2_runtime.cpp';replace(t,n,'#include "ps2_runtime.h"','#include "ps2_runtime.h"\n#include "gs_sound_ram_profile.h"')
    replace(t,n,'bool PS2Runtime::initialize(const char *title, size_t ramBackingBytes)\n{','''bool PS2Runtime::initialize(const char *title, size_t ramBackingBytes)
{
    // The SDK has one process GS/backing geometry. A foreign initializer must
    // not replace global RAM geometry before it reaches GS::init's guard.
    auto profileControl=gs_backend_bridge::acquireGlobalGsControlV1();
    if(profileControl.status!=gs_backend_bridge::SoundRamProfileStatusV1::ok)return false;''')
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--author',type=Path,required=True);a=p.parse_args();t=a.author.resolve()
    if t.exists()or not t.is_relative_to(ROOT/'build-native-sjuni'):raise ValueError('Fresh isolated author required')
    if sha(PROOF)!=PIN:raise ValueError('Full126 proof changed')
    q=json.loads(read(PROOF));assert q['status']=='passed'and q['applied_count']==126
    for n,d in q['source_sha256'].items():
        if sha(BASE/n)!=d:raise ValueError('Full126 source drift '+n)
    for e in q['patches']:
        if sha(ROOT/e['path'])!=e['sha256']:raise ValueError('Prior patch drift')
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
