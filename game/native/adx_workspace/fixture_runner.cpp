#include "adx_workspace.hpp"

#include <algorithm>
#include <array>
#include <bit>
#include <cstdlib>
#include <iostream>
#include <limits>
#include <new>
#include <optional>
#include <string>
#include <utility>
#include <vector>

namespace { bool deny{}; unsigned allocations{}; }
#if defined(__GNUC__)
#define NOINLINE __attribute__((noinline))
#else
#define NOINLINE __declspec(noinline)
#endif
NOINLINE void* operator new(std::size_t n) {
    if(deny) { ++allocations;throw std::bad_alloc(); }
    if(auto* p=std::malloc(n?n:1)) return p;
    throw std::bad_alloc();
}
NOINLINE void operator delete(void* p) noexcept { std::free(p); }
NOINLINE void operator delete(void* p,std::size_t) noexcept { std::free(p); }
NOINLINE void* operator new[](std::size_t n) { return ::operator new(n); }
NOINLINE void operator delete[](void* p) noexcept { ::operator delete(p); }
NOINLINE void operator delete[](void* p,std::size_t) noexcept { ::operator delete(p); }

namespace a=reo::native::adx_workspace;
const char* status(a::Status s) {
    switch(s) {
    case a::Status::admitted:return "admitted";
    case a::Status::unsupported_route:return "unsupported_route";
    case a::Status::physical_span:return "physical_span";
    case a::Status::invalid_storage:return "invalid_storage";
    case a::Status::overlapping_storage:return "overlapping_storage";
    case a::Status::short_input:return "short_input";
    case a::Status::short_output:return "short_output";
    }
    return "invalid_status";
}
const char* stop(a::Stop s) {
    switch(s) {
    case a::Stop::requested_count:return "requested_count";
    case a::Stop::mono_marker:return "mono_marker";
    case a::Stop::left_marker:return "left_marker";
    case a::Stop::right_marker:return "right_marker";
    }
    return "invalid_stop";
}
void plane(std::span<const std::int16_t> values) {
    std::cout<<'[';
    for(std::size_t n=0;n<values.size();++n) {if(n)std::cout<<',';std::cout<<values[n];}
    std::cout<<']';
}
int main() {
    std::ios::sync_with_stdio(false);
    unsigned count;if(!(std::cin>>count)||count>2000)return 2;
    constexpr auto sentinel=std::bit_cast<std::int16_t>(std::uint16_t{0xA5A5});
    for(unsigned index=0;index<count;++index) {
        std::string name;unsigned route;long long request;std::size_t bytes,capacity;
        std::array<int,4> history;std::array<int,2> coefficients;unsigned key;int multiplier,addend;
        if(!(std::cin>>name>>route>>request>>bytes>>capacity))return 3;
        for(auto& v:history)std::cin>>v;
        std::cin>>key;for(auto& v:coefficients)std::cin>>v;
        std::cin>>multiplier>>addend;
        if(route>2||bytes>32768||capacity>a::maximum_pcm_samples_per_plane+1||
           request<std::numeric_limits<std::int32_t>::min()||request>std::numeric_limits<std::int32_t>::max())return 4;
        std::vector<std::uint8_t> input(bytes);
        for(auto& value:input) {unsigned v;if(!(std::cin>>v)||v>255)return 5;value=static_cast<std::uint8_t>(v);}
        const auto original=input;
        std::array<std::int16_t,a::maximum_pcm_samples_per_plane+17> left,right;
        left.fill(sentinel);right.fill(sentinel);
        const auto left_span=std::span(left).subspan(8,capacity);
        const auto right_span=route==0?std::span<std::int16_t>{}:std::span(right).subspan(8,capacity);
        const a::State initial{{static_cast<std::int16_t>(history[0]),static_cast<std::int16_t>(history[1])},
            {static_cast<std::int16_t>(history[2]),static_cast<std::int16_t>(history[3])},static_cast<std::uint16_t>(key)};
        const a::Parameters parameters{static_cast<std::int16_t>(coefficients[0]),static_cast<std::int16_t>(coefficients[1]),
            static_cast<std::int16_t>(multiplier),static_cast<std::int16_t>(addend)};
        deny=true;
        auto admission=a::prepare_into(static_cast<a::Route>(route),input,static_cast<std::int32_t>(request),{left_span,right_span});
        std::optional<a::Result> result;
        if(admission.status==a::Status::admitted)result.emplace(a::execute(std::move(*admission.prepared),initial,parameters));
        deny=false;
        const auto untouched=[=](auto begin,auto end){return std::all_of(begin,end,[=](auto v){return v==sentinel;});};
        const bool guards=untouched(left.begin(),left.begin()+8)&&untouched(left.begin()+static_cast<std::ptrdiff_t>(8+capacity),left.end())&&
            untouched(right.begin(),right.begin()+8)&&untouched(right.begin()+static_cast<std::ptrdiff_t>(8+capacity),right.end());
        std::cout<<"{\"name\":\""<<name<<"\",\"status\":\""<<status(admission.status)<<"\",\"allocation_attempts\":"<<allocations
                 <<",\"guards\":"<<(guards?"true":"false")<<",\"encoded_unchanged\":"<<(input==original?"true":"false")<<",\"left_pcm\":";
        plane(left_span);std::cout<<",\"right_pcm\":";plane(right_span);
        if(result) {
            const auto& r=*result;
            std::cout<<",\"kernel_return\":"<<r.kernel_return<<",\"stop\":\""<<stop(r.stop)<<"\",\"history\":["
                <<r.state.left.newest<<','<<r.state.left.previous<<','<<r.state.right.newest<<','<<r.state.right.previous
                <<"],\"key\":"<<r.state.key<<",\"left_history_committed\":"<<(r.left_history_committed?"true":"false")
                <<",\"right_history_committed\":"<<(r.right_history_committed?"true":"false")
                <<",\"complete_channel_blocks\":"<<r.complete_channel_blocks<<",\"samples_per_plane\":"<<r.samples_per_plane
                <<",\"encoded_bytes_consumed\":"<<r.encoded_bytes_consumed<<",\"encoded_bytes_inspected\":"<<r.encoded_bytes_inspected;
        }
        std::cout<<"}\n";
    }
}
