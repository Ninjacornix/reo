#include "runtime_adapter.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include "../../../game/native/disc_stream/disc_stream.hpp"

#include <array>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <stdexcept>

#if defined(REO_GAME_FILE2)
#error "The native disc-stream scalar adapter is admitted only for File #1"
#endif

namespace reo_native_disc_stream {
namespace {
namespace ds = reo::native::disc_stream;
using Function = PS2Runtime::RecompiledFunction;
constexpr std::array<std::uint32_t,4> entries{0x139C30,0x139CC8,0x139FA8,0x139FE8};
constexpr std::array<std::uint32_t,4> return_branches{0x139CBC,0x139CF8,0x139FD8,0x13A02C};
constexpr std::uint32_t pool=0x21CC60, stride=0x48, slots=40, busy=0x207934;
std::array<Function,4> originals{};
std::atomic<PS2Runtime*> owner{nullptr};
std::atomic<std::uint8_t*> installed_memory{nullptr};
std::atomic<bool> healthy{false};
std::atomic<bool> trace_enabled{false};
std::array<std::atomic<std::uint64_t>,4> trace_counts{};
constexpr std::array<const char*,4> operation_names{"seek","tell","status","transferred"};
void trace_success(unsigned which,std::uint32_t address) noexcept {
    if(!trace_enabled.load(std::memory_order_relaxed))return;
    auto before=trace_counts[which].load(std::memory_order_relaxed);
    while(before!=std::numeric_limits<std::uint64_t>::max()&&
          !trace_counts[which].compare_exchange_weak(before,before+1,std::memory_order_relaxed)){}
    if(before==std::numeric_limits<std::uint64_t>::max())return;
    const auto count=before+1;
    if(count>4&&!std::has_single_bit(count))return;
    std::fprintf(stderr,"[NATIVE-DISC-STREAM] native op=%s calls=%llu slot=%u\n",
                 operation_names[which],static_cast<unsigned long long>(count),(address-pool)/stride);
}

constexpr reo_native_image_identity::Digest digest(const char (&hex)[65]) {
    reo_native_image_identity::Digest result{};
    const auto nibble=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(unsigned i=0;i<result.size();++i)
        result[i]=static_cast<std::uint8_t>((nibble(hex[2*i])<<4)|nibble(hex[2*i+1]));
    return result;
}
struct Range {std::uint32_t address,bytes;reo_native_image_identity::Digest hash;};
constexpr std::array<Range,9> identity_ranges{{
    {0x139C30,0x94,digest("4f4cb62e11a2600c598018b73001f312c6f5f9bf2371df8434547ee779a40fe2")},
    {0x139CC8,0x38,digest("03fc5c14423dfec9f4e98e4d2ffb9b919eef44bb03a327ad14631d3a5681cb74")},
    {0x139FA8,0x38,digest("e20658c06a7d2443db0154f288e64af892cf995993bde078183daa4625ddcfd5")},
    {0x139FE8,0x4C,digest("291747a87b1dd92b8852ae8fc1151051331be75833772dd8e95a5e505736e492")},
    {0x1399F8,0x34,digest("d9c1fc9405f3678366f1aef0b08d8b348922f3495c8640da45e62e7892cf7731")},
    {0x139A50,0x184,digest("7e4ebf230b61a70b33699c955a5b212847727737ee0b8b7d5f38468449a45823")},
    {0x139A30,0x1C,digest("6a8e97d13c4cc5e9f97573f1803dd6e310496a5eff62a995aba5d98e2c970cf7")},
    {0x139BD8,0x58,digest("60507a3768b2ec9034b0346366f2c58d482e6575cc7a255d43ea91ba538cf78b")},
    {0x21CBF8,0x68,digest("110e07237b9879134ef9aa44289116e0a63f2ff0392b117f842bebb325692d8a")}
}};
bool matches(const std::uint8_t* ram,const Range& range) {
    return reo_native_image_identity::sha256(ram+range.address,range.bytes)==range.hash;
}
bool identity(const std::uint8_t* ram) {
    if(!ram)return false;
    for(const auto& range:identity_ranges)if(!matches(ram,range))return false;
    return true;
}
std::uint32_t load32(const std::uint8_t* ram,std::uint32_t address) noexcept {
    std::uint32_t value;std::memcpy(&value,ram+address,4);return value;
}
bool canonical(const R5900Context* context,unsigned reg) noexcept {
    return GPR_U64(context,reg)==static_cast<std::uint64_t>(static_cast<std::int64_t>(
        std::bit_cast<std::int32_t>(GPR_U32(context,reg))));
}
bool overlap(std::uint32_t a,std::uint32_t bytes,std::uint32_t b,std::uint32_t size) noexcept {
    return std::uint64_t(a)<std::uint64_t(b)+size&&std::uint64_t(b)<std::uint64_t(a)+bytes;
}

// Diagnostics and every real external hook remain original responsibilities.
struct NoHooks final:ds::Hooks {
    [[noreturn]] static void unexpected(){throw std::logic_error("Unexpected scalar external hook");}
    void diagnostic(ds::Diagnostic)override{unexpected();}
    void enter()override{unexpected();} void leave()override{unexpected();}
    ds::RequestId create_request()override{unexpected();}
    void cache_range(ds::BufferId,std::uint32_t)override{unexpected();}
    bool prepare_disc(ds::RequestId,std::uint32_t,std::int32_t,ds::BufferId,
                      const std::array<std::uint8_t,4>&)override{unexpected();}
    void cd_sync()override{unexpected();} void server_gate()override{unexpected();}
    void server_service()override{unexpected();} void wait(ds::RequestId)override{unexpected();}
    void destroy(ds::RequestId)override{unexpected();}
    ds::RequestStatus request_status(ds::RequestId)override{unexpected();}
};

struct Prepared {
    std::uint32_t address{},frame{},ra{},cursor{};
    std::uint64_t saved_ra{};
    std::int32_t result{};
};
bool prepare(unsigned which,std::uint8_t* ram,const R5900Context* context,Prepared& prepared) {
    if(context->in_delay_slot||!canonical(context,4)||!canonical(context,29)||
       !canonical(context,31))return false;
    const auto address=GPR_U32(context,4),stack=GPR_U32(context,29),ra=GPR_U32(context,31);
    if(address<pool||address-pool>=stride*slots||(address-pool)%stride!=0||
       ram[address]!=1||stack<16||stack>PS2_RAM_SIZE||stack%16!=0||
       ra%4!=0||ra>=PS2_RAM_SIZE||load32(ram,busy)!=0)return false;
    const auto frame=stack-16;
    if(overlap(frame,16,pool,stride*slots)||overlap(frame,16,busy,4))return false;
    for(const auto& range:identity_ranges)
        if(overlap(frame,16,range.address,range.bytes)||
           (ra>=range.address&&std::uint64_t(ra)<std::uint64_t(range.address)+range.bytes))return false;
    const auto state=ram[address+2];
    // Quiescent first domain only. Pending or stale request-bearing slots stay
    // original, including getters; no SJ/host-target lease is inferred here.
    if(state>3||state==2||load32(ram,address+0x1C)!=0)return false;
    if(which==0&&(!canonical(context,5)||!canonical(context,6)))return false;
    if(!matches(ram,identity_ranges[which]))return false;
    ds::FileState file;
    file.status=static_cast<ds::FileStatus>(state);
    if(which==0||which==1)file.cursor=std::bit_cast<std::int32_t>(load32(ram,address+0xC));
    if(which==0) {
        file.sectors=std::bit_cast<std::int32_t>(load32(ram,address+8));
        if(file.status==ds::FileStatus::error||file.sectors<0||file.sectors==0x7FFFFFFF||
           file.cursor<0||file.cursor>file.sectors)return false;
    }
    if(which==3&&file.status==ds::FileStatus::ready)
        file.completed=std::bit_cast<std::int32_t>(load32(ram,address+0x14));
    NoHooks hooks;
    std::int32_t result{};
    switch(which) {
    case 0:result=ds::seek(&file,std::bit_cast<std::int32_t>(GPR_U32(context,5)),
                         std::bit_cast<std::int32_t>(GPR_U32(context,6)),hooks);break;
    case 1:result=ds::tell(&file,hooks);break;
    case 2:result=ds::status(&file,hooks);break;
    case 3:result=ds::transferred(&file,hooks);break;
    default:throw std::logic_error("Unknown scalar adapter operation");
    }
    prepared={address,frame,ra,static_cast<std::uint32_t>(file.cursor),GPR_U64(context,31),result};
    return true;
}
// No fallback catcher surrounds this allocation-free, hook-free commit.
void commit(unsigned which,std::uint8_t* ram,R5900Context* context,const Prepared& prepared) noexcept {
    // Retain the original dead-frame RA save as well as its live field writes.
    std::memcpy(ram+prepared.frame,&prepared.saved_ra,8);
    if(which==0) {
        const std::uint32_t completed=0;
        std::memcpy(ram+prepared.address+0x14,&completed,4);
        std::memcpy(ram+prepared.address+0xC,&prepared.cursor,4);
    }
    SET_GPR_S32(context,2,prepared.result);
    context->branch_pc=return_branches[which];
    context->pc=prepared.ra;
}

void dispatch(unsigned which,std::uint8_t* ram,R5900Context* context,PS2Runtime* runtime) {
    PS2Runtime::GuestExecutionScope execution(runtime);
    const auto original=originals[which];
    if(healthy.load(std::memory_order_acquire)&&owner.load(std::memory_order_acquire)==runtime&&
       context->pc==entries[which]&&ram&&installed_memory.load(std::memory_order_acquire)==ram&&
       runtime->memory().getRDRAM()==ram&&!runtime->isStopRequested()) {
        Prepared prepared;
        bool accepted=false;
        try {accepted=prepare(which,ram,context,prepared);}
        catch(...) {healthy.store(false,std::memory_order_release);}
        if(accepted){commit(which,ram,context,prepared);trace_success(which,prepared.address);return;}
    }
    // Captured before any wrapper publication; never recurse through lookup.
    original(ram,context,runtime);
}
void seek(std::uint8_t* r,R5900Context* c,PS2Runtime* p){dispatch(0,r,c,p);}
void tell(std::uint8_t* r,R5900Context* c,PS2Runtime* p){dispatch(1,r,c,p);}
void status(std::uint8_t* r,R5900Context* c,PS2Runtime* p){dispatch(2,r,c,p);}
void transferred(std::uint8_t* r,R5900Context* c,PS2Runtime* p){dispatch(3,r,c,p);}
constexpr std::array<Function,4> wrappers{seek,tell,status,transferred};
} // namespace

bool install(PS2Runtime& runtime) noexcept {
    const auto* enabled=std::getenv("REO_NATIVE_DISC_STREAM");
    if(!enabled||std::strcmp(enabled,"1"))return false;
    const auto* trace=std::getenv("REO_NATIVE_DISC_STREAM_TRACE");
    const bool requested_trace=trace&&!std::strcmp(trace,"1");
    try {
        PS2Runtime::GuestExecutionScope execution(&runtime);
        if(runtime.isStopRequested())return false;
        auto* prior=owner.load(std::memory_order_acquire);
        auto* ram=runtime.memory().getRDRAM();
        if(prior==&runtime) {
            if(requested_trace!=trace_enabled.load(std::memory_order_acquire))return false;
            bool same=healthy.load(std::memory_order_acquire)&&
                installed_memory.load(std::memory_order_acquire)==ram&&identity(ram);
            for(unsigned i=0;i<entries.size();++i)
                same=same&&runtime.hasFunction(entries[i])&&runtime.lookupFunction(entries[i])==wrappers[i];
            if(!same)healthy.store(false,std::memory_order_release);
            return same;
        }
        if(prior||!identity(ram))return false;
        std::array<Function,4> captured{};
        for(unsigned i=0;i<entries.size();++i) {
            if(!runtime.hasFunction(entries[i]))return false;
            captured[i]=runtime.lookupFunction(entries[i]);
            if(!captured[i]||captured[i]==wrappers[i])return false;
        }
        PS2Runtime* expected=nullptr;
        if(!owner.compare_exchange_strong(expected,&runtime,std::memory_order_acq_rel))return false;
        originals=captured;
        trace_enabled.store(requested_trace,std::memory_order_release);
        installed_memory.store(ram,std::memory_order_release);
        healthy.store(true,std::memory_order_release);
        for(unsigned i=0;i<entries.size();++i) {
            runtime.registerFunction(entries[i],wrappers[i]);
            ps2_stubs::registerStubOverride(entries[i],wrappers[i]);
        }
        std::fprintf(stderr,"[NATIVE-DISC-STREAM] quiescent scalar pilot installed; requests remain original\n");
        return true;
    } catch(...) {
        healthy.store(false,std::memory_order_release);
        return false;
    }
}
} // namespace reo_native_disc_stream
