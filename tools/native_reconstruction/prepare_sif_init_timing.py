#!/usr/bin/env python3
"""Author opt-in bounded initializer stage timing from the audited 129 SDK.

No semantic/logging/lock-policy changes. No active dependency edits or game run.
"""
import argparse,difflib,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];SDK=ROOT/'build-native-sjuni/dependency-sound-rpc10-reapply-v1'
RECEIPT=SDK.with_name(SDK.name+'-receipt.json');PIN='692d86d3e19c51039e58749cedf86597810fcff672e95b62a451d3b14605514b'
PATCH=ROOT/'third_party/patches/ps2recomp/0129-time-sif-init-rpc-stages.patch'
NAME='ps2xRuntime/src/lib/Kernel/Syscalls/RPC.cpp'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
HELPER='''        // Owner-thread elapsed timing only. The report is emitted after RPC
        // locks and the sound-call lease unwind. Existing init/logging behavior
        // is unchanged; unknown host blocking/descheduling remains explicit.
        struct SifInitTiming {
            static uint64_t now() noexcept {
                return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                    std::chrono::steady_clock::now().time_since_epoch()).count());
            }
            static uint64_t threshold() noexcept {
                static const uint64_t value=[] {
                    const char* text=std::getenv("REO_CRI_SERVER_SLOW_MS");
                    if(!text || !*text || *text=='-')return uint64_t(0);
                    char* end=nullptr;const auto ms=std::strtoull(text,&end,10);
                    return end && !*end && ms && ms<=60000 ? uint64_t(ms)*1000000 : uint64_t(0);
                }();return value;
            }
            uint64_t points[5]{};bool admitted{},cold{};
            SifInitTiming() noexcept {if(threshold())points[0]=now();}
            void mark(unsigned index) noexcept {if(points[0])points[index]=now();}
            ~SifInitTiming() {
                if(!points[0])return;const auto end=now();
                if(end<points[0] || end-points[0]<threshold())return;
                static std::atomic<unsigned> reports{0};
                if(reports.load(std::memory_order_relaxed)>=64 || reports.fetch_add(1,std::memory_order_relaxed)>=64)return;
                const auto audio=points[1]?points[1]-points[0]:0;
                const auto locks=points[2]?points[2]-points[1]:0;
                const auto work=points[3]?points[3]-points[2]:0;
                const auto logging=points[4]?points[4]-points[3]:0;
                const auto last=points[4]?points[4]:points[1]?points[1]:points[0];
                std::fprintf(stderr,"[SIF-INIT-TIMING] begin_ns=%llu end_ns=%llu audio_call_ns=%llu lock_wait_ns=%llu work_ns=%llu logging_ns=%llu release_ns=%llu admitted=%u cold=%u\\n",
                    (unsigned long long)points[0],(unsigned long long)end,(unsigned long long)audio,
                    (unsigned long long)locks,(unsigned long long)work,(unsigned long long)logging,
                    (unsigned long long)(end-last),unsigned(admitted),unsigned(cold));
            }
        };

'''
def main():
    p=argparse.ArgumentParser();p.add_argument('--author',type=Path,required=True);a=p.parse_args();out=a.author.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni') or PATCH.exists():raise ValueError('Fresh author/unused patch required')
    if sha(RECEIPT)!=PIN:raise ValueError('Frozen 129 receipt changed')
    prior=json.loads(RECEIPT.read_bytes())
    for name,digest in prior['source_sha256'].items():
        if sha(SDK/name)!=digest:raise ValueError('Frozen source changed '+name)
    before=(SDK/NAME).read_text();body=before
    def replace(old,new):
        nonlocal body
        if body.count(old)!=1:raise ValueError('Unique source anchor missing '+old[:70])
        body=body.replace(old,new)
    replace('        constexpr uint32_t kSoundDriverStatusSize',HELPER+'        constexpr uint32_t kSoundDriverStatusSize')
    replace('''    void SifInitRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {''','''    void SifInitRpc(uint8_t *rdram, R5900Context *ctx, PS2Runtime *runtime)
    {
        SifInitTiming timing;''')
    # Anchor only the exact initializer interval, not other native sound guards.
    start=body.index('    void SifInitRpc(');end=body.index('    void SifBindRpc(',start);function=body[start:end]
    def f(old,new):
        nonlocal function
        if function.count(old)!=1:raise ValueError('Unique function anchor missing '+old)
        function=function.replace(old,new)
    f('auto audio=ps2_cri_audio::acquireSoundCall(runtime);','auto audio=ps2_cri_audio::acquireSoundCall(runtime);timing.mark(1);')
    f('ps2_cri_audio::SoundCallScope scope(audio);','timing.admitted=true;\n        ps2_cri_audio::SoundCallScope scope(audio);')
    f('std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);','std::scoped_lock lock(g_rpc_mutex, g_dtx_rpc_mutex);timing.mark(2);')
    f('            RUNTIME_LOG("[SifInitRpc] Initialized");','            timing.cold=true;timing.mark(3);\n            RUNTIME_LOG("[SifInitRpc] Initialized");timing.mark(4);')
    f('            RUNTIME_LOG("[SifInitRpc] re-init (DTX server state kept)" << std::endl);','            timing.mark(3);\n            RUNTIME_LOG("[SifInitRpc] re-init (DTX server state kept)" << std::endl);timing.mark(4);')
    body=body[:start]+function+body[end:];out.mkdir(parents=True);target=out/NAME;target.parent.mkdir(parents=True);target.write_text(body,encoding='utf-8',newline='\n')
    diff='diff --git a/'+NAME+' b/'+NAME+'\n'+''.join(difflib.unified_diff(before.splitlines(True),body.splitlines(True),fromfile='a/'+NAME,tofile='b/'+NAME));PATCH.write_text(diff,encoding='utf-8',newline='\n')
    (out/'receipt.json').write_text(json.dumps({'status':'authored opt-in SifInitRpc stage timing; qualification pending','prior_receipt_sha256':PIN,'before_sha256':sha(SDK/NAME),'after_sha256':sha(target),'patch_sha256':sha(PATCH),'author_sha256':sha(Path(__file__)),'active_checkout_modified':False,'game_run':False},indent=2)+'\n',encoding='utf-8',newline='\n');print('Authored initializer timing; no lock, reinit or existing logging policy changed')
if __name__=='__main__':main()
