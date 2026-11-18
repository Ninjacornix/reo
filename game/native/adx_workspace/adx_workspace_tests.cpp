#include "adx_workspace.hpp"

#include <algorithm>
#include <array>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <new>
#include <type_traits>
#include <utility>
#include <vector>

namespace { bool deny{}; unsigned attempts{}, checks{}; }
#if defined(__GNUC__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE __declspec(noinline)
#endif
NOINLINE void* operator new(std::size_t bytes) {
    if (deny) { ++attempts; throw std::bad_alloc(); }
    if (auto* p=std::malloc(bytes ? bytes : 1)) return p;
    throw std::bad_alloc();
}
NOINLINE void operator delete(void* p) noexcept { std::free(p); }
NOINLINE void operator delete(void* p,std::size_t) noexcept { std::free(p); }
NOINLINE void* operator new[](std::size_t n) { return ::operator new(n); }
NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
NOINLINE void operator delete[](void* p,std::size_t) noexcept { ::operator delete(p); }
NOINLINE void* operator new(std::size_t bytes,std::align_val_t value) {
    if (deny) { ++attempts; throw std::bad_alloc(); }
    const auto alignment=static_cast<std::size_t>(value);
    if (bytes>std::numeric_limits<std::size_t>::max()-alignment-sizeof(void*)) throw std::bad_alloc();
    auto* raw=std::malloc(bytes+alignment+sizeof(void*));
    if (!raw) throw std::bad_alloc();
    const auto address=(reinterpret_cast<std::uintptr_t>(raw)+sizeof(void*)+alignment-1)&~(alignment-1);
    auto* result=reinterpret_cast<void*>(address);
    reinterpret_cast<void**>(result)[-1]=raw;
    return result;
}
NOINLINE void operator delete(void* p,std::align_val_t) noexcept { if(p) std::free(reinterpret_cast<void**>(p)[-1]); }
NOINLINE void operator delete(void* p,std::size_t,std::align_val_t a) noexcept { ::operator delete(p,a); }
NOINLINE void* operator new[](std::size_t n,std::align_val_t a) { return ::operator new(n,a); }
NOINLINE void operator delete[](void* p,std::align_val_t a) noexcept { ::operator delete(p,a); }
NOINLINE void operator delete[](void* p,std::size_t,std::align_val_t a) noexcept { ::operator delete(p,a); }

namespace a=reo::native::adx_workspace;
namespace {
void check(bool value,const char* what) {
    ++checks;
    if(!value) { std::fprintf(stderr,"FAILED: %s\n",what);std::exit(1); }
}
std::array<std::uint8_t,18> block(std::uint16_t header=0,std::uint8_t payload=0x11) {
    std::array<std::uint8_t,18> data;data.fill(payload);
    data[0]=static_cast<std::uint8_t>(header>>8);data[1]=static_cast<std::uint8_t>(header);return data;
}
template<std::size_t N> void put(std::array<std::uint8_t,N>& into,std::size_t offset,std::array<std::uint8_t,18> data) {
    std::copy(data.begin(),data.end(),into.begin()+static_cast<std::ptrdiff_t>(offset));
}
a::Result run(a::Route route,std::span<const std::uint8_t> encoded,std::int32_t count,
              a::PcmOutput output,a::State state={},a::Parameters parameters={}) {
    deny=true;
    auto admission=a::prepare_into(route,encoded,count,output);
    check(admission.status==a::Status::admitted && admission.prepared.has_value(),"admitted under global allocation denial");
    auto result=a::execute(std::move(*admission.prepared),state,parameters);
    deny=false;
    check(attempts==0,"no ordinary/array/aligned allocation attempted");
    return result;
}

void base_and_order() {
    auto input=block(1,0);
    for(unsigned i=0;i<16;++i) input[2+i]=static_cast<std::uint8_t>(((2*i%16)<<4)|((2*i+1)%16));
    std::array<std::int16_t,36> pcm;pcm.fill(0x1357);
    const a::State state{{123,-456},{777,-888},0};
    const auto result=run(a::Route::mono,input,1,{std::span(pcm).subspan(2,32),{}},state);
    const std::array<std::int16_t,16> expected{0,2,4,6,8,10,12,14,-16,-14,-12,-10,-8,-6,-4,-2};
    for(std::size_t n=0;n<32;++n) check(pcm[2+n]==expected[n%16],"big endian scale and high-before-low signed nibbles");
    check(result.kernel_return==1 && result.samples_per_plane==32 && result.complete_channel_blocks==1,"mono scalar result");
    check(result.state.left==a::History{-2,-4} && result.state.right==state.right,"mono only commits left history");
    check(result.left_history_committed && !result.right_history_committed,"mono commit flags");
    check(pcm[0]==0x1357 && pcm[1]==0x1357 && pcm[34]==0x1357 && pcm[35]==0x1357,"guards untouched");
    check(state==a::State{{123,-456},{777,-888},0},"state passed by value");
}

void markers() {
    std::array<std::uint8_t,56> input{};put(input,0,block());put(input,18,block(0,0x22));put(input,36,block(0x8000));
    std::array<std::int16_t,66> left,right;left.fill(123);right.fill(456);
    const a::State state{{19,-21},{-23,27},0};const a::Parameters p{0,0,1,1};
    auto r=run(a::Route::mono,std::span(input).first(38),999,{left,{}},state,p);
    check(r.stop==a::Stop::mono_marker && r.samples_per_plane==64 && r.kernel_return==2,"mono marker keeps completed prefix");
    check(r.encoded_bytes_consumed==36 && r.encoded_bytes_inspected==38,"mono inspected marker excluded from consumed bytes");
    check(!r.left_history_committed && r.state.left==state.left && r.state.key==2,"marker key survives, history does not commit");
    check(left[64]==123 && left[65]==123,"prefix-only writes");
    for(auto route:{a::Route::stereo,a::Route::downmix_7_over_10}) {
        left.fill(123);right.fill(456);
        r=run(route,std::span(input).first(38),999,{left,right},state,p);
        check(r.stop==a::Stop::left_marker && r.samples_per_plane==32 && r.kernel_return==2,"left marker completes pair prefix");
        check(r.state.left==state.left && r.state.right==state.right && r.state.key==2,"left marker selective state");
        put(input,36,block());input[54]=0x80;input[55]=0;
        r=run(route,input,999,{left,right},state,p);
        check(r.stop==a::Stop::right_marker && r.encoded_bytes_inspected==56 && r.encoded_bytes_consumed==36,"right marker inspection");
        check(r.state.key==3 && !r.left_history_committed && !r.right_history_committed,"extra left key step, neither history committed");
        put(input,36,block(0x8000));
    }
    const std::array<std::uint8_t,2> marker{0x80,0};
    r=run(a::Route::mono,marker,std::numeric_limits<std::int32_t>::max(),{{},{}},state,p);
    check(r.samples_per_plane==0 && r.state==state,"two-byte first marker bounded huge request");
    std::array<std::uint8_t,20> right_marker{};put(right_marker,0,block());right_marker[18]=0x80;
    r=run(a::Route::stereo,right_marker,std::numeric_limits<std::int32_t>::max(),{{},{}},state,p);
    check(r.kernel_return==0 && r.state.key==1 && r.state.left==state.left,"20-byte right marker bounded huge request");
}

void signed_counts_and_mix() {
    const a::State state{{1,2},{3,4},65535};
    for(auto route:{a::Route::mono,a::Route::stereo,a::Route::downmix_7_over_10}) {
        for(auto count:{std::numeric_limits<std::int32_t>::min(),-3,-1,0}) {
            const auto r=run(route,{},count,{{},{}},state);
            check(r.kernel_return==count && r.state==state && r.left_history_committed,"all negative counts retain exact return/state");
            check(r.right_history_committed==(route!=a::Route::mono),"negative stereo histories commit unchanged values");
        }
    }
    auto r=run(a::Route::stereo,{},1,{{},{}},state);
    check(r.kernel_return==1 && r.complete_channel_blocks==0,"positive odd one has zero pair work but exact return");
    std::array<std::uint8_t,36> input{};put(input,0,block(0,0xFF));put(input,18,block(0,0xEE));
    std::array<std::int16_t,32> left,right;
    r=run(a::Route::downmix_7_over_10,input,3,{left,right});
    check(r.kernel_return==3 && r.complete_channel_blocks==2,"odd stereo request preserved");
    check(std::all_of(left.begin(),left.end(),[](auto v){return v==-2;}) && left==right,"negative downmix division truncates toward zero");
    put(input,0,block(0x1FFF,0x77));put(input,18,block(0x1FFF,0x77));
    r=run(a::Route::downmix_7_over_10,input,2,{left,right});
    check(left[0]==32767 && right[31]==32767,"channel clipping before mixed clipping");
}

void no_effect_refusals() {
    std::array<std::uint8_t,54> input{};put(input,0,block());put(input,18,block());put(input,36,block());
    std::array<std::int16_t,100> output;output.fill(2345);
    const auto original=output;
    for(std::size_t n=0;n<18;++n) {
        deny=true;auto a=a::prepare_into(a::Route::mono,std::span(input).first(n),1,{output,{}});deny=false;
        check(a.status==a::Status::short_input && !a.prepared,"short input before effects");check(output==original,"short input keeps output");
    }
    for(std::size_t n=0;n<32;++n) {
        deny=true;auto a=a::prepare_into(a::Route::mono,input,1,{std::span(output).first(n),{}});deny=false;
        check(a.status==a::Status::short_output && !a.prepared,"short output before effects");check(output==original,"short output keeps suffix");
    }
    auto overlap=a::prepare_into(a::Route::stereo,input,2,{std::span(output).first(32),std::span(output).subspan(16,32)});
    check(overlap.status==a::Status::overlapping_storage && output==original,"partial output overlap refused");
    auto bytes=std::span<const std::uint8_t>(reinterpret_cast<const std::uint8_t*>(output.data()),18);
    auto encoded_overlap=a::prepare_into(a::Route::mono,bytes,1,{output,{}});
    check(encoded_overlap.status==a::Status::overlapping_storage && output==original,"encoded/output byte overlap refused before read");
    auto bad=a::prepare_into(static_cast<a::Route>(99),input,1,{output,{}});
    check(bad.status==a::Status::unsupported_route,"invalid route before effects");
    auto empty_right=a::prepare_into(a::Route::mono,input,0,{output,std::span(output).first(0)});
    check(empty_right.status==a::Status::admitted,"empty same-address view is not overlapping storage");
    auto mono_right=a::prepare_into(a::Route::mono,input,0,{output,std::span(output).first(1)});
    check(mono_right.status==a::Status::physical_span,"mono unclaimed right output excluded");
    check(output==original && attempts==0,"all refusal paths remain allocation free and leave output");
}

void physical_and_real_requests() {
    std::array<std::uint8_t,a::maximum_encoded_bytes> input{};
    for(std::size_t at=0;at+18<=input.size();at+=18) put(input,at,block());
    std::array<std::int16_t,a::maximum_pcm_samples_per_plane> left,right;
    auto r=run(a::Route::mono,std::span(input).first(4662),259,{left,{}});
    check(r.samples_per_plane==8288 && r.encoded_bytes_consumed==4662,"mono exact physical output edge");
    r=run(a::Route::stereo,std::span(input).first(8208),457,{left,right});
    check(r.samples_per_plane==7296 && r.kernel_return==457,"stereo physical input edge and odd return");
    for(auto frames:{640,1152,1216,2240,2432}) for(auto route:{a::Route::mono,a::Route::stereo,a::Route::downmix_7_over_10}) {
        const auto channels=route==a::Route::mono?1:2;
        const auto blocks=frames/32*channels;
        const auto count=static_cast<std::size_t>(blocks)*18;
        const auto output=a::PcmOutput{left,channels==1?std::span<std::int16_t>{}:std::span(right)};
        r=run(route,std::span(input).first(count),blocks,output);
        check(r.samples_per_plane==static_cast<std::size_t>(frames) && r.kernel_return==blocks,"complete real configured request geometry");
    }
    std::array<std::uint8_t,a::maximum_encoded_bytes+1> too_big{};
    auto a=a::prepare_into(a::Route::mono,too_big,0,{{},{}});
    check(a.status==a::Status::physical_span,"physical byte ceiling even at zero work");
    auto b=a::prepare_into(a::Route::mono,input,std::numeric_limits<std::int32_t>::max(),{left,{}});
    check(b.status==a::Status::short_output,"huge count bounded by physical output, no unbounded scan");
}
} // namespace

int main() {
    static_assert(!std::is_default_constructible_v<a::Prepared> && !std::is_copy_constructible_v<a::Prepared>);
    static_assert(std::is_nothrow_move_constructible_v<a::Prepared>);
    base_and_order();markers();signed_counts_and_mix();no_effect_refusals();physical_and_real_requests();
    {
        std::vector<std::uint8_t> input(a::maximum_source_encoded_bytes+1,0x12);
        input[0]=input[1]=0;std::array<std::int16_t,32> expected{},actual{};
        const auto baseline=run(a::Route::mono,std::span(input).first(18),1,{expected,{}});
        for(std::size_t length:{53248u,272384u,static_cast<unsigned>(a::maximum_source_encoded_bytes)}){
            check(a::prepare_into(a::Route::mono,std::span(input).first(length),1,{actual,{}}).status==a::Status::physical_span,"legacy span ceiling retained");
            deny=true;auto admitted=a::prepare_into(a::Route::mono,std::span(input).first(length),1,{actual,{}},a::SpanProfile::bounded_source);
            check(admitted.status==a::Status::admitted && admitted.prepared.has_value(),"explicit source span admitted");
            const auto value=a::execute(std::move(*admitted.prepared),{},{});deny=false;
            check(actual==expected && value.state==baseline.state && value.samples_per_plane==32 && value.encoded_bytes_consumed==18 && value.encoded_bytes_inspected==18,"large tail does not change one original block");
        }
        check(a::prepare_into(a::Route::mono,input,0,{{},{}},a::SpanProfile::bounded_source).status==a::Status::physical_span,"extended span bound retained before zero work");
        check(a::prepare_into(a::Route::mono,{},0,{{},{}},static_cast<a::SpanProfile>(99)).status==a::Status::physical_span,"unknown span profile refused");
    }
    std::printf("ADX workspace passed %u assertions; allocation attempts=%u\n",checks,attempts);
}
