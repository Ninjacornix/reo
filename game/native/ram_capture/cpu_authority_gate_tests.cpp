#include "cpu_authority_gate.hpp"
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <new>
#include <stdexcept>
#include <utility>
using namespace reo::native::ram_capture;
using namespace std::chrono_literals;
namespace {std::atomic<bool> deny_allocations{false};std::atomic<unsigned> denied_allocations{0};}
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t n) {
    if(deny_allocations){++denied_allocations;throw std::bad_alloc();}
    if(auto* p=std::malloc(n?n:1))return p;
    throw std::bad_alloc();
}
TEST_NOINLINE void operator delete(void* p)noexcept{std::free(p);}
TEST_NOINLINE void operator delete(void* p,std::size_t)noexcept{std::free(p);}
TEST_NOINLINE void* operator new[](std::size_t n){return ::operator new(n);}
TEST_NOINLINE void operator delete[](void* p)noexcept{::operator delete(p);}
TEST_NOINLINE void operator delete[](void* p,std::size_t)noexcept{::operator delete(p);}
namespace {
unsigned checks{};
void check(bool value,const char* why){++checks;if(!value)throw std::runtime_error(why);}
#define CHECK(...) check(static_cast<bool>(__VA_ARGS__),#__VA_ARGS__)
template<class Predicate>void until(Predicate predicate){
    auto deadline=std::chrono::steady_clock::now()+2s;
    while(!predicate() && std::chrono::steady_clock::now()<deadline)std::this_thread::yield();
    CHECK(predicate());
}
struct Unblock {
    CpuGroup& group;std::promise<void>* signal{};bool signaled{};
    void finish(){group.release();if(signal && !signaled){signal->set_value();signaled=true;}}
    ~Unblock(){finish();}
};
void basics_and_bounds(){
    Coordinator gate;std::array<int,maximum_backings+1> backing{};
    CHECK(gate.try_cpu_group(nullptr).status==Status::invalid_backing);
    CHECK(gate.begin_graphics(nullptr).status==Status::invalid_backing);
    CHECK(!gate.observe(backing.data()).known);
    std::array<CpuGroup,maximum_groups> groups;
    for(auto& group:groups){auto r=gate.try_cpu_group(backing.data());CHECK(r.status==Status::ok);group=std::move(r.value);}
    CHECK(gate.observe(backing.data()).cpu_groups==maximum_groups);
    CHECK(gate.try_cpu_group(backing.data()).status==Status::capacity);
    CHECK(gate.begin_graphics(backing.data()).status==Status::self_wait);
    CHECK(!gate.observe(backing.data()).graphics_ever);
    groups[0]=std::move(groups[1]); // Replaced pin retires once, moved source empty.
    CHECK(groups[0] && !groups[1] && gate.observe(backing.data()).cpu_groups==maximum_groups-1);
    for(auto& group:groups)group.release();
    CHECK(gate.observe(backing.data()).cpu_groups==0);
    for(std::size_t i=1;i<maximum_backings;++i){auto r=gate.try_cpu_group(&backing[i]);CHECK(r.status==Status::ok);}
    CHECK(gate.try_cpu_group(&backing.back()).status==Status::capacity);
    CHECK(gate.begin_graphics(&backing.back()).status==Status::capacity);
}
void sticky_graphics_and_moves(){
    Coordinator gate;int backing{};
    std::array<GraphicsActivity,maximum_groups> activities;
    for(auto& activity:activities){auto r=gate.begin_graphics(&backing);CHECK(r.status==Status::ok);activity=std::move(r.value);}
    CHECK(gate.observe(&backing).graphics_active==maximum_groups);
    CHECK(gate.begin_graphics(&backing).status==Status::capacity);
    activities[0]=std::move(activities[1]);
    CHECK(activities[0] && !activities[1] && gate.observe(&backing).graphics_active==maximum_groups-1);
    for(auto& activity:activities)activity.release();
    CHECK(gate.observe(&backing).graphics_active==0);
    CHECK(gate.try_cpu_group(&backing).status==Status::graphics_owned);
}
void group_blocks_initial_graphics(){
    Coordinator gate;int backing{};auto pin=gate.try_cpu_group(&backing);CHECK(pin.status==Status::ok);
    std::atomic<bool> constructor_effect{false};std::promise<void> destroy;auto finish=destroy.get_future().share();
    auto graphics=std::async(std::launch::async,[&]{
        auto activity=gate.begin_graphics(&backing);
        if(activity.status!=Status::ok)throw std::runtime_error("graphics admission");
        constructor_effect=true;finish.wait();
    });
    Unblock unblock{pin.value,&destroy};
    until([&]{return gate.observe(&backing).graphics_waiting==1;});
    CHECK(!constructor_effect && graphics.wait_for(20ms)==std::future_status::timeout);
    CHECK(gate.try_cpu_group(&backing).status==Status::graphics_owned); // Waiter closes new admission first.
    pin.value.release();until([&]{return constructor_effect.load();});
    CHECK(gate.observe(&backing).graphics_active==1);
    unblock.finish();graphics.get();
    CHECK(gate.observe(&backing).graphics_active==0 && gate.try_cpu_group(&backing).status==Status::graphics_owned);
}
void one_group_covers_three_parts(){
    Coordinator gate;std::array<std::array<unsigned,64>,3> source{},captured{};
    for(auto& part:source)part.fill(7);
    auto pin=gate.try_cpu_group(source.data());CHECK(pin.status==Status::ok);
    captured[0]=source[0];
    auto writer=std::async(std::launch::async,[&]{auto activity=gate.begin_graphics(source.data());
        if(activity.status!=Status::ok)throw std::runtime_error("writer admission");
        for(auto& part:source)part.fill(9);
    });
    Unblock unblock{pin.value};
    until([&]{return gate.observe(source.data()).graphics_waiting==1;});
    captured[1]=source[1];captured[2]=source[2];
    CHECK(writer.wait_for(20ms)==std::future_status::timeout);
    pin.value.release();writer.get();
    CHECK(std::all_of(captured.begin(),captured.end(),[](const auto& part){return std::all_of(part.begin(),part.end(),[](unsigned v){return v==7;});}));
    CHECK(source[2][0]==9); // Graphics runs after copy, before any decoder work.
}
struct ServiceTail {
    Coordinator& gate;const void* backing;std::atomic<bool>& observed;
    ~ServiceTail(){observed=gate.observe(backing).graphics_active==1;}
};
struct ServiceShape {
    GraphicsActivity activity; // First declared, destroyed AFTER tail.
    ServiceTail tail;
    ServiceShape(Coordinator& gate,const void* backing,std::atomic<bool>& observed)
        :activity([&]{auto r=gate.begin_graphics(backing);if(r.status!=Status::ok)throw std::runtime_error("service gate");return std::move(r.value);}()),
         tail{gate,backing,observed}{}
};
void lifetime_and_pending_publication(){
    Coordinator gate;int backing{};std::atomic<bool> tail_saw_guard{false};
    {ServiceShape service(gate,&backing,tail_saw_guard);
        // No opaque span has been published. A queued graphics result alone
        // is sufficient to forbid this conservative CPU-authoritative profile.
        CHECK(gate.try_cpu_group(&backing).status==Status::graphics_owned);
    }
    CHECK(tail_saw_guard && gate.observe(&backing).graphics_active==0);
    CHECK(gate.try_cpu_group(&backing).status==Status::graphics_owned);
}
void allocation_free_metadata(){
    Coordinator gate;int backing{};bool cpu=false,graphics=false;
    deny_allocations=true;
    {auto r=gate.try_cpu_group(&backing);cpu=r.status==Status::ok;}
    {auto r=gate.begin_graphics(&backing);graphics=r.status==Status::ok;}
    deny_allocations=false;
    CHECK(cpu && graphics && denied_allocations==0);
}
}
int main()try {
    basics_and_bounds();sticky_graphics_and_moves();group_blocks_initial_graphics();one_group_covers_three_parts();
    lifetime_and_pending_publication();allocation_free_metadata();
    std::cout<<checks<<" RAM capture gate assertions passed\n";return 0;
}catch(const std::exception& error){deny_allocations=false;std::cerr<<error.what()<<'\n';return 1;}
