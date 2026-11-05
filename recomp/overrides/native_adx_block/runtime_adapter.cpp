#include "runtime_adapter.h"
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_ADX_BLOCK) && REO_BUILD_NATIVE_ADX_BLOCK
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include "game/native/adx_block/adx_block.hpp"
#include <array>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>

#if !defined(PS2_RUNTIME_HAS_EXTERNAL_WORKERS) || !PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error Native ADX admission requires the matching external-worker lifecycle API
#endif

// Bind only the actual original generated function, never another override.
void sub_001276D8_0x1276d8(std::uint8_t*, R5900Context*, PS2Runtime*);
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;

namespace reo_native_adx_block {
namespace {
namespace adx=reo::native::adx_block;
using Function=PS2Runtime::RecompiledFunction;
constexpr std::uint32_t entry=0x1276D8, text_bytes=0x1DC, table=0x239BE8, table_bytes=64;
constexpr std::array<unsigned,9> saved_registers{16,17,18,19,20,21,22,23,30};
Function original{};
std::atomic<PS2Runtime*> owner{nullptr};
std::atomic<std::uint8_t*> installed_memory{nullptr};
std::atomic<bool> healthy{false}, trace_enabled{false};
std::atomic<std::uint64_t> trace_count{0};

constexpr reo_native_image_identity::Digest digest(const char (&value)[65]) {
    reo_native_image_identity::Digest result{};
    const auto digit=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(std::size_t i=0;i<result.size();++i)
        result[i]=static_cast<std::uint8_t>((digit(value[2*i])<<4)|digit(value[2*i+1]));
    return result;
}
bool identity(const std::uint8_t* ram) noexcept {
    return ram&&reo_native_image_identity::sha256(ram+entry,text_bytes)==
        digest("f68258d902ba372da0e477288c3a3b98a396a07b3c43bb28e55fb5805348b115")&&
        reo_native_image_identity::sha256(ram+table,table_bytes)==
        digest("67ec51eb0fd90d668661957e826ec5f7834c84c2e7a586f9cf185e0ec7d4808f");
}
bool flag(const char* name) noexcept {const auto* v=std::getenv(name);return v&&!std::strcmp(v,"1");}
bool canonical(const R5900Context* c,unsigned n) noexcept {
    return GPR_U64(c,n)==static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(GPR_U32(c,n))));
}
bool half_argument(const R5900Context* c,unsigned n) noexcept {
    const auto value=std::bit_cast<std::int32_t>(GPR_U32(c,n));
    return canonical(c,n)&&value>=-32768&&value<=32767;
}
struct Range {std::uint32_t at,bytes;};
bool overlaps(Range a,Range b) noexcept {
    return std::uint64_t(a.at)<std::uint64_t(b.at)+b.bytes&&std::uint64_t(b.at)<std::uint64_t(a.at)+a.bytes;
}
bool normal(Range r,unsigned alignment) noexcept {
    return r.at&&r.at%alignment==0&&r.at<PS2_RAM_SIZE&&r.bytes<=PS2_RAM_SIZE-r.at;
}
template<class T>T load(const std::uint8_t* ram,std::uint32_t address) noexcept {
    T value;std::memcpy(&value,ram+address,sizeof(value));return value;
}
struct Prepared {
    std::uint32_t output{},history{},key{},frame{},ra{};
    std::array<std::uint64_t,9> saves{};
    adx::Result result;
};
bool prepare(std::uint8_t* ram,const R5900Context* c,Prepared& out) {
    if(c->in_delay_slot||!canonical(c,29)||!canonical(c,31))return false;
    for(unsigned n=4;n<=11;++n)if(!canonical(c,n))return false;
    if(!half_argument(c,8)||!half_argument(c,9)||!half_argument(c,11))return false;
    const auto count=std::bit_cast<std::int32_t>(GPR_U32(c,5));
    const auto sp=GPR_U32(c,29),ra=GPR_U32(c,31);
    if(count<1||count>16||sp<80||sp%16||sp>PS2_RAM_SIZE-2||!normal({ra,4},4))return false;
    const auto n=static_cast<std::uint32_t>(count);
    // The original reads a signed halfword at caller SP+0. Its following six
    // argument bytes and the final eight bytes of the80-byte frame are untouched.
    const std::array<Range,8> ranges{{{GPR_U32(c,4),18*n},{GPR_U32(c,6),64*n},
        {GPR_U32(c,7),4},{GPR_U32(c,10),2},{sp-80,80},{sp,2},{entry,text_bytes},{table,table_bytes}}};
    for(unsigned i=0;i<6;++i)if(!normal(ranges[i],i==4?16:2))return false;
    for(unsigned i=0;i<ranges.size();++i) {
        if(overlaps({ra,4},ranges[i]))return false;
        for(unsigned j=0;j<i;++j)if(overlaps(ranges[i],ranges[j]))return false;
    }
    if(!identity(ram))return false;
    const adx::State initial{{load<std::int16_t>(ram,ranges[2].at),load<std::int16_t>(ram,ranges[2].at+2)},
                             load<std::uint16_t>(ram,ranges[3].at)};
    const adx::Parameters parameters{static_cast<std::int16_t>(GPR_U32(c,8)),
        static_cast<std::int16_t>(GPR_U32(c,9)),static_cast<std::int16_t>(GPR_U32(c,11)),load<std::int16_t>(ram,sp)};
    auto result=adx::decode_keyed_mono({ram+ranges[0].at,ranges[0].bytes},count,initial,parameters,{32*n});
    if(result.status!=adx::Status::ok||result.blocks_decoded>n||result.pcm.size()!=32*result.blocks_decoded||
       result.encoded_bytes_consumed!=18*result.blocks_decoded||result.encoded_bytes_inspected>ranges[0].bytes||
       result.kernel_return!=static_cast<std::int32_t>(result.blocks_decoded)||
       result.history_committed!=(result.stop==adx::Stop::requested_count)||
       (result.history_committed&&result.blocks_decoded!=n))return false;
    out.output=ranges[1].at;out.history=ranges[2].at;out.key=ranges[3].at;out.frame=sp-80;out.ra=ra;
    for(unsigned i=0;i<saved_registers.size();++i)out.saves[i]=GPR_U64(c,saved_registers[i]);
    out.result=std::move(result);
    return true;
}
void commit(std::uint8_t* ram,R5900Context* c,const Prepared& p) noexcept {
    // No allocation/hooks/fallback catcher after the first guest write.
    std::memcpy(ram+p.frame,p.saves.data(),p.saves.size()*sizeof(std::uint64_t));
    if(!p.result.pcm.empty())std::memcpy(ram+p.output,p.result.pcm.data(),p.result.pcm.size()*sizeof(std::int16_t));
    if(p.result.blocks_decoded)std::memcpy(ram+p.key,&p.result.state.key,2);
    if(p.result.history_committed) {
        std::memcpy(ram+p.history,&p.result.state.history.newest,2);
        std::memcpy(ram+p.history+2,&p.result.state.history.previous,2);
    }
    SET_GPR_S32(c,2,p.result.kernel_return);
    c->branch_pc=0x1278AC;c->pc=p.ra;
}
void trace(const Prepared& p) noexcept {
    if(!trace_enabled.load(std::memory_order_relaxed))return;
    auto before=trace_count.load(std::memory_order_relaxed);
    while(before!=std::numeric_limits<std::uint64_t>::max()&&
          !trace_count.compare_exchange_weak(before,before+1,std::memory_order_relaxed)){}
    if(before==std::numeric_limits<std::uint64_t>::max())return;
    const auto count=before+1;if(count>4&&!std::has_single_bit(count))return;
    std::fprintf(stderr,"[NATIVE-ADX-BLOCK] native op=keyed-mono calls=%llu blocks=%u marker=%u\n",
        static_cast<unsigned long long>(count),p.result.blocks_decoded,p.result.stop==adx::Stop::marker?1u:0u);
}
void dispatch(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime) {
    // Check the authentic scope BEFORE adding our recursive serialization scope.
    const bool entered_from_guest=runtime&&ps2ActualGuestExecutionDepth(runtime)!=0;
    PS2Runtime::GuestExecutionScope scope(runtime);
    if(entered_from_guest&&runtime&&c&&healthy.load(std::memory_order_acquire)&&owner.load(std::memory_order_acquire)==runtime&&
       ram&&installed_memory.load(std::memory_order_acquire)==ram&&runtime->memory().getRDRAM()==ram&&
       !runtime->isStopRequested()&&c->pc==entry&&runtime->hasFunction(entry)&&runtime->lookupFunction(entry)==dispatch) {
        Prepared prepared;bool accepted=false;
        try {accepted=prepare(ram,c,prepared);}catch(...) {}
        if(accepted){commit(ram,c,prepared);trace(prepared);return;}
    }
    original(ram,c,runtime);
}
// A no-thread lifecycle token enforces the runtime's real pre-run registration
// gate and permanently disables this one-shot owner when stop begins.
class Lifetime final:public PS2Runtime::ExternalWorker {
public:
    void requestStop() noexcept override {healthy.store(false,std::memory_order_release);}
    bool join() noexcept override {return true;}
};
} // namespace

bool install(PS2Runtime& runtime) noexcept {
    if(!flag("REO_NATIVE_ADX_BLOCK"))return false;
    const bool requested_trace=flag("REO_NATIVE_ADX_BLOCK_TRACE");
    try {
        PS2Runtime::GuestExecutionScope scope(&runtime);
        if(runtime.isStopRequested())return false;
        auto* ram=runtime.memory().getRDRAM();auto* prior=owner.load(std::memory_order_acquire);
        if(prior==&runtime) {
            const bool same=healthy.load(std::memory_order_acquire)&&installed_memory.load(std::memory_order_acquire)==ram&&
                identity(ram)&&requested_trace==trace_enabled.load(std::memory_order_acquire)&&
                runtime.hasFunction(entry)&&runtime.lookupFunction(entry)==dispatch;
            if(!same)healthy.store(false,std::memory_order_release);
            return same;
        }
        if(prior||!identity(ram)||!runtime.hasFunction(entry))return false;
        const auto captured=runtime.lookupFunction(entry);
        if(captured!=sub_001276D8_0x1276d8)return false;
        auto token=std::make_shared<Lifetime>();
        PS2Runtime* expected=nullptr;
        if(!owner.compare_exchange_strong(expected,&runtime,std::memory_order_acq_rel))return false;
        original=captured;installed_memory.store(ram,std::memory_order_release);
        trace_enabled.store(requested_trace,std::memory_order_release);
        if(!runtime.registerExternalWorker(std::move(token)))return false;
        runtime.registerFunction(entry,dispatch);
        ps2_stubs::registerStubOverride(entry,dispatch);
        healthy.store(true,std::memory_order_release);
        std::fprintf(stderr,"[NATIVE-ADX-BLOCK] synchronous keyed mono pilot installed count=1..16\n");
        return true;
    }catch(...) {healthy.store(false,std::memory_order_release);return false;}
}
} // namespace reo_native_adx_block
#endif
