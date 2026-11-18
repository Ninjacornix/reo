#include "runtime_adapter.h"
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_ADX_STEREO) && REO_BUILD_NATIVE_ADX_STEREO
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include "game/native/adx_stereo/adx_stereo.hpp"
#include <array>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>

#if !defined(PS2_RUNTIME_HAS_EXTERNAL_WORKERS) || !PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error Native ADX stereo requires the matching external-worker lifecycle API
#endif
void sub_00127C80_0x127c80(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_001278B8_0x1278b8(std::uint8_t*, R5900Context*, PS2Runtime*);
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;

namespace reo_native_adx_stereo {
namespace {
namespace adx=reo::native::adx_stereo;
using Function=PS2Runtime::RecompiledFunction;
constexpr std::uint32_t normal_entry=0x127C80,downmix_entry=0x1278B8,table=0x239BE8;
constexpr std::array<unsigned,9> saved_registers{16,17,18,19,20,21,22,23,30};
Function normal_original{},downmix_original{};
std::atomic<PS2Runtime*> owner{nullptr};
std::atomic<std::uint8_t*> installed_memory{nullptr};
std::atomic<bool> healthy{false},trace_enabled{false};
std::array<std::atomic<std::uint64_t>,2> trace_count{};

constexpr reo_native_image_identity::Digest digest(const char (&value)[65]) {
    reo_native_image_identity::Digest result{};
    const auto digit=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(std::size_t i=0;i<result.size();++i)
        result[i]=static_cast<std::uint8_t>((digit(value[2*i])<<4)|digit(value[2*i+1]));
    return result;
}
bool identity(const std::uint8_t* ram) noexcept {
    return ram&&reo_native_image_identity::sha256(ram+normal_entry,840)==
        digest("4a4e6da9bbda1a2a0b83c2f7bb31e777aeeb912c751b0a8a0694ce16c366f9ff")&&
        reo_native_image_identity::sha256(ram+downmix_entry,964)==
        digest("fece7d5c5d7dc0148717351d200c67d845e0242f5e7b93c01cfc19db7c2687ab")&&
        reo_native_image_identity::sha256(ram+table,64)==
        digest("67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f");
}
bool flag(const char* name) noexcept {const auto* v=std::getenv(name);return v&&!std::strcmp(v,"1");}
bool canonical(const R5900Context* c,unsigned n) noexcept {
    return GPR_U64(c,n)==static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(GPR_U32(c,n))));
}
bool half_argument(const R5900Context* c,unsigned n) noexcept {
    const auto v=std::bit_cast<std::int32_t>(GPR_U32(c,n));
    return canonical(c,n)&&v>=-32768&&v<=32767;
}
struct Range {std::uint32_t at,bytes;};
bool overlaps(Range a,Range b) noexcept {
    return std::uint64_t(a.at)<std::uint64_t(b.at)+b.bytes&&std::uint64_t(b.at)<std::uint64_t(a.at)+a.bytes;
}
bool normal(Range r,unsigned alignment) noexcept {
    return r.at&&r.at%alignment==0&&r.at<PS2_RAM_SIZE&&r.bytes<=PS2_RAM_SIZE-r.at;
}
template<class T>T load(const std::uint8_t* ram,std::uint32_t address) noexcept {
    T result;std::memcpy(&result,ram+address,sizeof(result));return result;
}
template<class T>void store(std::uint8_t* ram,std::uint32_t address,T value) noexcept {
    std::memcpy(ram+address,&value,sizeof(value));
}
struct Prepared {
    std::uint32_t left_output{},right_output{},left_history{},right_history{},key{},frame{},ra{};
    std::array<std::uint64_t,9> saves{};
    std::array<std::uint32_t,7> frame_words{};
    adx::Result result;
};
bool prepare(std::uint8_t* ram,const R5900Context* c,adx::Mode mode,Prepared& out) {
    if(c->in_delay_slot||!canonical(c,29)||!canonical(c,31))return false;
    for(unsigned n=4;n<=11;++n)if(!canonical(c,n))return false;
    if(!half_argument(c,10)||!half_argument(c,11))return false;
    const auto count=std::bit_cast<std::int32_t>(GPR_U32(c,5));
    const auto sp=GPR_U32(c,29),ra=GPR_U32(c,31);
    if(count<1||count>512||sp<112||sp%16||!normal({sp,18},2)||!normal({ra,4},4))return false;
    const auto pairs=static_cast<std::uint32_t>(count/2);
    const auto key=load<std::uint32_t>(ram,sp);
    // Count one performs no encoded/output access. Two-byte anchors retain a
    // conservative non-null/aligned/disjoint admission domain for that case.
    const auto input_size=pairs?36*pairs:2u,output_size=pairs?64*pairs:2u;
    const std::array<Range,11> ranges{{{GPR_U32(c,4),input_size},{GPR_U32(c,6),output_size},
        {GPR_U32(c,8),output_size},{GPR_U32(c,7),4},{GPR_U32(c,9),4},{key,2},
        {sp-112,112},{sp,18},{normal_entry,840},{downmix_entry,964},{table,64}}};
    for(unsigned i=0;i<8;++i)if(!normal(ranges[i],i==6?16:2))return false;
    for(unsigned i=0;i<ranges.size();++i) {
        if(overlaps({ra,4},ranges[i]))return false;
        for(unsigned j=0;j<i;++j)if(overlaps(ranges[i],ranges[j]))return false;
    }
    if(!identity(ram))return false;
    const adx::State initial{{load<std::int16_t>(ram,ranges[3].at),load<std::int16_t>(ram,ranges[3].at+2)},
        {load<std::int16_t>(ram,ranges[4].at),load<std::int16_t>(ram,ranges[4].at+2)},load<std::uint16_t>(ram,key)};
    const auto mult=load<std::int16_t>(ram,sp+8),add=load<std::int16_t>(ram,sp+16);
    const adx::Parameters parameters{static_cast<std::int16_t>(GPR_U32(c,10)),
        static_cast<std::int16_t>(GPR_U32(c,11)),mult,add};
    auto result=adx::decode_keyed_stereo({ram+ranges[0].at,ranges[0].bytes},count,initial,parameters,mode,{32*pairs});
    if(result.status!=adx::Status::ok||result.pairs_decoded>pairs||
       result.left_pcm.size()!=32*result.pairs_decoded||result.right_pcm.size()!=result.left_pcm.size()||
       result.encoded_bytes_consumed!=36*result.pairs_decoded||result.encoded_bytes_inspected>ranges[0].bytes||
       result.histories_committed!=(result.stop==adx::Stop::requested_count)||
       (result.histories_committed&&(result.pairs_decoded!=pairs||result.kernel_return!=count))||
       (!result.histories_committed&&result.kernel_return!=static_cast<std::int32_t>(2*result.pairs_decoded)))return false;
    out.left_output=ranges[1].at;out.right_output=ranges[2].at;
    out.left_history=ranges[3].at;out.right_history=ranges[4].at;out.key=key;out.frame=sp-112;out.ra=ra;
    out.frame_words={static_cast<std::uint32_t>(count),out.left_history,out.right_history,
        static_cast<std::uint32_t>(static_cast<std::int32_t>(mult)),static_cast<std::uint32_t>(static_cast<std::int32_t>(add)),
        mode==adx::Mode::separate_channels?result.pairs_decoded:pairs,pairs};
    for(unsigned i=0;i<saved_registers.size();++i)out.saves[i]=GPR_U64(c,saved_registers[i]);
    out.result=std::move(result);
    return true;
}
void commit(std::uint8_t* ram,R5900Context* c,const Prepared& p,adx::Mode mode) noexcept {
    // Commit has no allocations, callbacks, suspension points or fallback path.
    const auto words=mode==adx::Mode::separate_channels?7u:6u;
    for(unsigned i=0;i<words;++i)store(ram,p.frame+4*i,p.frame_words[i]);
    for(unsigned i=0;i<p.saves.size();++i)store(ram,p.frame+0x20+8*i,p.saves[i]);
    if(!p.result.left_pcm.empty()) {
        std::memcpy(ram+p.left_output,p.result.left_pcm.data(),p.result.left_pcm.size()*2);
        std::memcpy(ram+p.right_output,p.result.right_pcm.data(),p.result.right_pcm.size()*2);
    }
    if(p.result.pairs_decoded||p.result.stop==adx::Stop::right_marker)store(ram,p.key,p.result.state.key);
    if(p.result.histories_committed) {
        store(ram,p.left_history+2,p.result.state.left.previous);store(ram,p.left_history,p.result.state.left.newest);
        store(ram,p.right_history+2,p.result.state.right.previous);store(ram,p.right_history,p.result.state.right.newest);
    }
    SET_GPR_S32(c,2,p.result.kernel_return);
    c->branch_pc=mode==adx::Mode::separate_channels?0x127FC0:0x127C74;
    c->pc=p.ra;
}
void trace(const Prepared& p,adx::Mode mode) noexcept {
    if(!trace_enabled.load(std::memory_order_relaxed))return;
    auto& counter=trace_count[mode==adx::Mode::separate_channels?0:1];
    auto before=counter.load(std::memory_order_relaxed);
    while(before!=std::numeric_limits<std::uint64_t>::max()&&
          !counter.compare_exchange_weak(before,before+1,std::memory_order_relaxed)){}
    if(before==std::numeric_limits<std::uint64_t>::max())return;
    const auto count=before+1;if(count>4&&!std::has_single_bit(count))return;
    std::fprintf(stderr,"[NATIVE-ADX-STEREO] native op=%s calls=%llu pairs=%u marker=%u\n",
        mode==adx::Mode::separate_channels?"stereo":"downmix",static_cast<unsigned long long>(count),
        p.result.pairs_decoded,static_cast<unsigned>(p.result.stop));
}
void normal_dispatch(std::uint8_t*,R5900Context*,PS2Runtime*);
void downmix_dispatch(std::uint8_t*,R5900Context*,PS2Runtime*);
bool bindings(PS2Runtime& runtime) {
    return runtime.hasFunction(normal_entry)&&runtime.lookupFunction(normal_entry)==normal_dispatch&&
           runtime.hasFunction(downmix_entry)&&runtime.lookupFunction(downmix_entry)==downmix_dispatch;
}
void dispatch(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime,adx::Mode mode,Function original) {
    const bool entered_from_guest=runtime&&ps2ActualGuestExecutionDepth(runtime)!=0;
    PS2Runtime::GuestExecutionScope scope(runtime);
    const auto entry=mode==adx::Mode::separate_channels?normal_entry:downmix_entry;
    if(entered_from_guest&&runtime&&c&&healthy.load(std::memory_order_acquire)&&owner.load(std::memory_order_acquire)==runtime&&
       ram&&installed_memory.load(std::memory_order_acquire)==ram&&runtime->memory().getRDRAM()==ram&&
       !runtime->isStopRequested()&&c->pc==entry&&bindings(*runtime)) {
        Prepared prepared;bool accepted=false;
        try{accepted=prepare(ram,c,mode,prepared);}catch(...){}
        if(accepted){commit(ram,c,prepared,mode);trace(prepared,mode);return;}
    }
    original(ram,c,runtime);
}
void normal_dispatch(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime) {
    dispatch(ram,c,runtime,adx::Mode::separate_channels,normal_original);
}
void downmix_dispatch(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime) {
    dispatch(ram,c,runtime,adx::Mode::downmix_7_over_10,downmix_original);
}
class Lifetime final:public PS2Runtime::ExternalWorker {
public:
    void requestStop() noexcept override {healthy.store(false,std::memory_order_release);}
    bool join() noexcept override {return true;}
};
} // namespace
bool install(PS2Runtime& runtime) noexcept {
    if(!flag("REO_NATIVE_ADX_STEREO"))return false;
    const bool requested_trace=flag("REO_NATIVE_ADX_STEREO_TRACE");
    try {
        PS2Runtime::GuestExecutionScope scope(&runtime);
        if(runtime.isStopRequested())return false;
        auto* ram=runtime.memory().getRDRAM();auto* prior=owner.load(std::memory_order_acquire);
        if(prior==&runtime) {
            const bool same=healthy.load(std::memory_order_acquire)&&installed_memory.load(std::memory_order_acquire)==ram&&
                identity(ram)&&requested_trace==trace_enabled.load(std::memory_order_acquire)&&bindings(runtime);
            if(!same)healthy.store(false,std::memory_order_release);
            return same;
        }
        if(prior||!identity(ram)||!runtime.hasFunction(normal_entry)||!runtime.hasFunction(downmix_entry))return false;
        const auto normal_captured=runtime.lookupFunction(normal_entry),downmix_captured=runtime.lookupFunction(downmix_entry);
        if(normal_captured!=sub_00127C80_0x127c80||downmix_captured!=sub_001278B8_0x1278b8)return false;
        auto token=std::make_shared<Lifetime>();PS2Runtime* expected=nullptr;
        if(!owner.compare_exchange_strong(expected,&runtime,std::memory_order_acq_rel))return false;
        normal_original=normal_captured;downmix_original=downmix_captured;
        installed_memory.store(ram,std::memory_order_release);trace_enabled.store(requested_trace,std::memory_order_release);
        if(!runtime.registerExternalWorker(std::move(token)))return false;
        runtime.registerFunction(normal_entry,normal_dispatch);ps2_stubs::registerStubOverride(normal_entry,normal_dispatch);
        runtime.registerFunction(downmix_entry,downmix_dispatch);ps2_stubs::registerStubOverride(downmix_entry,downmix_dispatch);
        healthy.store(true,std::memory_order_release);
        std::fprintf(stderr,"[NATIVE-ADX-STEREO] synchronous stereo/downmix pilot installed count=1..512\n");
        return true;
    }catch(...){healthy.store(false,std::memory_order_release);return false;}
}
} // namespace reo_native_adx_stereo
#endif
