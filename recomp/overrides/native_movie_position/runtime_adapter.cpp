#include "runtime_adapter.h"
#if defined(REO_GAME_FILE1) && defined(REO_BUILD_NATIVE_MOVIE_POSITION) && REO_BUILD_NATIVE_MOVIE_POSITION
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "ps2_stubs.h"
#include "../native_geometry/reo_vu_native_sha256.h"
#include "game/native/movie_position/movie_position.hpp"
#include <array>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <limits>
#include <memory>

#if !defined(PS2_RUNTIME_HAS_EXTERNAL_WORKERS) || !PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error Native movie-position admission needs the matching runtime lifecycle API
#endif
void sub_0016F338_0x16f338(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_00171530_0x171530(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_00171E58_0x171e58(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_0015BA80_0x15ba80(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_0010FB18_0x10fb18(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_0016EC90_0x16ec90(std::uint8_t*, R5900Context*, PS2Runtime*);
void sub_0016F438_0x16f438(std::uint8_t*, R5900Context*, PS2Runtime*);
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;

namespace reo_native_movie_position {
namespace {
namespace position = reo::native::movie_position;
using Function = PS2Runtime::RecompiledFunction;
constexpr std::uint32_t entry=0x16F338, caller_return=0x16EDF8;
constexpr std::uint32_t player_registry=0x22F18C;
struct Range { std::uint32_t at, bytes; };
struct Image { Range range; const char* hash; Function function; };
constexpr std::array<Image,9> images{{
    {{entry,252},"a9da933b0444e36ca9216439b9987a8c43b35329f1a8018707f1760a43940747",sub_0016F338_0x16f338},
    {{0x171530,16},"fe86d348b236afbb16ed45b2d5206cf8b37db1ce50cd27246e3da791ec753591",sub_00171530_0x171530},
    {{0x171E58,12},"520d116b70df02845b4cf1f537ef3f05d6c8133d5189643ff392dfc7aae8dd0f",sub_00171E58_0x171e58},
    {{0x15BA80,108},"10fceefc065a3b476f69b6420d7135bb0882e6baf7e106ffe21d58398767edd5",sub_0015BA80_0x15ba80},
    {{0x10FB18,1684},"b062fd51648ef4ea2270b845c3cd6b1760a55bfc7f1f3de9fe5e34c703fd0aae",sub_0010FB18_0x10fb18},
    {{0x16EC90,644},"facb86b966516db2a28fe015cae1ea1415e6f3e636fa71ebc36bd5d9866192a5",sub_0016EC90_0x16ec90},
    {{0x16F438,168},"f6b0bb2dbaeb06cec0e4f8d76d95b4ac65f0bd147a30e44b5387ed1e5b531082",sub_0016F438_0x16f438},
    {{0x240AF0,36},"a667ab0a5ce47cd7b60cc99ae7013e555d1042649698fecaa52ad08eb3b25f6b",nullptr},
    {{0x2381A0,256},"14a5d850c255623f9472e3c650abce0c78d32f0276b315b3a276a0462d97a1ac",nullptr}
}};
Function original{};
std::atomic<PS2Runtime*> owner{nullptr};
std::atomic<std::uint8_t*> installed_memory{nullptr};
std::atomic<bool> healthy{false}, trace_enabled{false};
std::atomic<std::uint64_t> trace_count{0};

bool flag(const char* name) noexcept {
    const auto* value=std::getenv(name); return value&&!std::strcmp(value,"1");
}
reo_native_image_identity::Digest digest(const char* value) noexcept {
    reo_native_image_identity::Digest result{};
    const auto digit=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(std::size_t i=0;i<result.size();++i)
        result[i]=static_cast<std::uint8_t>((digit(value[2*i])<<4)|digit(value[2*i+1]));
    return result;
}
bool identity(const std::uint8_t* ram) noexcept {
    if(!ram||PS2_RAM_SIZE!=32u*1024u*1024u||ps2RamBackingBytes!=32u*1024u*1024u)return false;
    for(const auto& image:images)
        if(reo_native_image_identity::sha256(ram+image.range.at,image.range.bytes)!=digest(image.hash))return false;
    return true;
}
void dispatch(std::uint8_t*,R5900Context*,PS2Runtime*);
bool bindings(PS2Runtime& runtime,bool installed) {
    for(const auto& image:images)if(image.function) {
        const auto expected=installed&&image.range.at==entry?dispatch:image.function;
        if(!runtime.hasFunction(image.range.at)||runtime.lookupFunction(image.range.at)!=expected)return false;
    }
    return true;
}
bool normal(Range range,unsigned alignment=4) noexcept {
    return range.at&&range.at%alignment==0&&range.at<PS2_RAM_SIZE&&range.bytes<=PS2_RAM_SIZE-range.at;
}
bool overlaps(Range a,Range b) noexcept {
    return std::uint64_t(a.at)<std::uint64_t(b.at)+b.bytes&&std::uint64_t(b.at)<std::uint64_t(a.at)+a.bytes;
}
bool canonical(const R5900Context* context,unsigned reg) noexcept {
    return GPR_U64(context,reg)==static_cast<std::uint64_t>(static_cast<std::int64_t>(
        std::bit_cast<std::int32_t>(GPR_U32(context,reg))));
}
template<class T>T load(const std::uint8_t* ram,std::uint32_t address) noexcept {
    T value;std::memcpy(&value,ram+address,sizeof(value));return value;
}
template<class T>void store(std::uint8_t* ram,std::uint32_t address,T value) noexcept {
    std::memcpy(ram+address,&value,sizeof(value));
}
struct Prepared {
    std::uint32_t main{},descriptor{},frame{},ra{};
    std::array<std::uint64_t,5> saves{};
    bool side{};
    position::Publication publication;
};
bool prepare(const std::uint8_t* ram,const R5900Context* context,Prepared& out) noexcept {
    if(context->in_delay_slot)return false;
    for(unsigned reg:{4u,5u,19u,29u,31u})if(!canonical(context,reg))return false;
    const auto main=GPR_U32(context,4),descriptor=GPR_U32(context,5),sp=GPR_U32(context,29);
    if(GPR_U32(context,31)!=caller_return||GPR_U32(context,19)!=main||sp<64||sp%16)return false;
    // Main's accessed prefix and its normally embedded main+1F00 video backend
    // are disjoint. Requiring the entire2B80 object disjoint would reject that
    // real constructor layout. Private descriptor containment is qualified below.
    const Range prefix{main,0x1B34},picture{descriptor,0x80},frame{sp-64,64},caller{sp,0x90};
    if(!normal(prefix)||!normal(picture)||!normal(frame,16)||!normal(caller,16))return false;
    const auto inner=load<std::uint32_t>(ram,main+0x1B30);
    const Range backend{inner,0xA0C};
    if(!normal(backend)||load<std::uint32_t>(ram,sp+0x30)!=descriptor)return false;
    // Original private records are embedded at backend+13C, stride80, before
    // getter fields9D8/A08. Qualify that defined embedding rather than treating
    // the descriptor as an arbitrary alias into the backend object.
    const auto count=load<std::int32_t>(ram,inner+0x138);
    const std::uint64_t first=std::uint64_t(inner)+0x13C;
    if(count<1||count>16||descriptor<first||(descriptor-first)%0x80||
       (descriptor-first)/0x80>=static_cast<std::uint32_t>(count))return false;
    const std::array<Range,4> data{prefix,backend,frame,caller};
    for(unsigned i=0;i<data.size();++i) {
        for(unsigned j=0;j<i;++j)if(overlaps(data[i],data[j]))return false;
        for(const auto& image:images)if(overlaps(data[i],image.range))return false;
        if(overlaps(data[i],{player_registry,32}))return false;
    }
    bool registered=false;
    for(unsigned i=0;i<8;++i)registered|=load<std::uint32_t>(ram,player_registry+4*i)==main;
    if(!registered||load<std::uint32_t>(ram,main+0x48)==0)return false;
    const auto index=load<std::uint32_t>(ram,descriptor+0x3C);
    if(index>=9)return false;
    const bool side=load<std::uint32_t>(ram,inner+0x9D8)!=0;
    const position::Input input{load<std::int32_t>(ram,main+0xD74),load<std::int32_t>(ram,main+0xD78),
        load<std::int32_t>(ram,main+0xDC4),load<std::int32_t>(ram,main+0xDE0),side,
        side?load<std::int32_t>(ram,inner+0xA08):0,load<std::int32_t>(ram,main+0xDDC),
        side?load<std::int32_t>(ram,0x240AF0+index*4):0};
    const position::Latest latest{load<std::int32_t>(ram,main+0xF00),load<std::int32_t>(ram,main+0xF04)};
    out.main=main;out.descriptor=descriptor;out.frame=sp-48;out.ra=caller_return;out.side=side;
    for(unsigned i=0;i<4;++i)out.saves[i]=GPR_U64(context,16+i);
    out.saves[4]=GPR_U64(context,31);
    out.publication=position::publish(input,latest); // exactly once, before guest effects
    return true;
}
void commit(std::uint8_t* ram,R5900Context* context,const Prepared& value) noexcept {
    // Reproduce saved slots, including the real nested helper RA; holes remain.
    std::memcpy(ram+value.frame,value.saves.data(),value.saves.size()*8);
    if(value.side)store<std::uint64_t>(ram,value.frame-16,0x16F3E8);
    const auto& publication=value.publication;
    store(ram,value.descriptor+0x10,publication.descriptor.denominator);
    store(ram,value.descriptor+0xC,publication.descriptor.position);
    store(ram,value.descriptor+0x20,publication.descriptor.source_position);
    store(ram,value.descriptor+0x24,publication.descriptor.offset_position);
    if(publication.latest_advanced) {
        store(ram,value.main+0xF00,publication.latest.numerator);
        store(ram,value.main+0xF04,publication.latest.denominator);
    }
    SET_GPR_S32(context,2,publication.final_value);
    context->branch_pc=0x16F42C;context->pc=value.ra;
}
void trace() noexcept {
    if(!trace_enabled.load(std::memory_order_relaxed))return;
    auto prior=trace_count.load(std::memory_order_relaxed);
    while(prior!=std::numeric_limits<std::uint64_t>::max()&&
          !trace_count.compare_exchange_weak(prior,prior+1,std::memory_order_relaxed)){}
    if(prior==std::numeric_limits<std::uint64_t>::max())return;
    const auto count=prior+1;if(count>4&&!std::has_single_bit(count))return;
    std::fprintf(stderr,"[NATIVE-MOVIE-POSITION] native op=publish calls=%llu\n",static_cast<unsigned long long>(count));
}
void dispatch(std::uint8_t* ram,R5900Context* context,PS2Runtime* runtime) {
    const bool from_guest=runtime&&ps2ActualGuestExecutionDepth(runtime)!=0;
    PS2Runtime::GuestExecutionScope scope(runtime);
    if(from_guest&&runtime&&context&&healthy.load(std::memory_order_acquire)&&
       owner.load(std::memory_order_acquire)==runtime&&ram&&installed_memory.load(std::memory_order_acquire)==ram&&
       runtime->memory().getRDRAM()==ram&&!runtime->isStopRequested()&&context->pc==entry&&
       bindings(*runtime,true)&&identity(ram)) {
        Prepared value;
        if(prepare(ram,context,value)){commit(ram,context,value);trace();return;}
    }
    original(ram,context,runtime);
}
class Lifetime final:public PS2Runtime::ExternalWorker {
public:
    void requestStop() noexcept override {healthy.store(false,std::memory_order_release);}
    bool join() noexcept override {return true;}
};
} // namespace
bool install(PS2Runtime& runtime) noexcept {
    if(!flag("REO_NATIVE_MOVIE_POSITION"))return false;
    const bool requested_trace=flag("REO_NATIVE_MOVIE_POSITION_TRACE");
    try {
        PS2Runtime::GuestExecutionScope scope(&runtime);
        if(runtime.isStopRequested())return false;
        auto* ram=runtime.memory().getRDRAM();auto* prior=owner.load(std::memory_order_acquire);
        if(prior==&runtime) {
            const bool same=healthy.load(std::memory_order_acquire)&&installed_memory.load(std::memory_order_acquire)==ram&&
                identity(ram)&&requested_trace==trace_enabled.load(std::memory_order_acquire)&&bindings(runtime,true);
            if(!same)healthy.store(false,std::memory_order_release);
            return same;
        }
        if(prior||!identity(ram)||!bindings(runtime,false))return false;
        auto token=std::make_shared<Lifetime>();PS2Runtime* expected=nullptr;
        if(!owner.compare_exchange_strong(expected,&runtime,std::memory_order_acq_rel))return false;
        original=sub_0016F338_0x16f338;installed_memory.store(ram,std::memory_order_release);
        trace_enabled.store(requested_trace,std::memory_order_release);
        if(!runtime.registerExternalWorker(std::move(token)))return false;
        runtime.registerFunction(entry,dispatch);ps2_stubs::registerStubOverride(entry,dispatch);
        healthy.store(true,std::memory_order_release);
        std::fputs("[NATIVE-MOVIE-POSITION] synchronous known-caller publication pilot installed\n",stderr);
        return true;
    }catch(...) {healthy.store(false,std::memory_order_release);return false;}
}
} // namespace reo_native_movie_position
#endif
