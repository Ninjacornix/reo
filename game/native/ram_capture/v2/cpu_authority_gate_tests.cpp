#include "cpu_authority_gate.hpp"
#include <atomic>
#include <chrono>
#include <cstdlib>
#include <future>
#include <iostream>
#include <new>
#include <stdexcept>
#include <utility>
using namespace reo::native::ram_capture::v2;
namespace {std::atomic<bool> deny_allocations{};std::atomic<unsigned> denied{};unsigned checks{};}
#if defined(__GNUC__)
#define TEST_NOINLINE __attribute__((noinline))
#else
#define TEST_NOINLINE __declspec(noinline)
#endif
TEST_NOINLINE void* operator new(std::size_t n){if(deny_allocations){++denied;throw std::bad_alloc();}if(auto* p=std::malloc(n?n:1))return p;throw std::bad_alloc();}
TEST_NOINLINE void operator delete(void* p)noexcept{std::free(p);}
TEST_NOINLINE void operator delete(void* p,std::size_t)noexcept{std::free(p);}
TEST_NOINLINE void* operator new[](std::size_t n){return ::operator new(n);}
TEST_NOINLINE void operator delete[](void* p)noexcept{::operator delete(p);}
TEST_NOINLINE void operator delete[](void* p,std::size_t)noexcept{::operator delete(p);}
void check(bool x,const char* message){++checks;if(!x)throw std::runtime_error(message);}
#define CHECK(...) check(static_cast<bool>(__VA_ARGS__),#__VA_ARGS__)
template<class F>void until(F f){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(3);while(!f()&&std::chrono::steady_clock::now()<end)std::this_thread::yield();CHECK(f());}
void basics(){Coordinator gate;int backing{};
    CHECK(gate.try_cpu_group(nullptr).status==Status::invalid_backing);CHECK(gate.begin_cpu_writer(nullptr).status==Status::invalid_backing);
    CHECK(gate.wait_cpu_group(nullptr).status==Status::invalid_backing);
    CHECK(gate.begin_graphics(nullptr).status==Status::invalid_backing);CHECK(!gate.observe(&backing).known);
    std::array<CpuGroup,maximum_groups> pins;for(auto& pin:pins){auto r=gate.try_cpu_group(&backing);CHECK(r.status==Status::ok);pin=std::move(r.value);}
    CHECK(gate.try_cpu_group(&backing).status==Status::capacity);CHECK(gate.begin_cpu_writer(&backing).status==Status::self_wait);
    CHECK(gate.wait_cpu_group(&backing).status==Status::self_wait);
    CHECK(gate.begin_graphics(&backing).status==Status::self_wait);CHECK(gate.withdraw_cpu_capture()==Status::self_wait);CHECK(!gate.observe(&backing).cpu_capture_disabled);
    pins[0]=std::move(pins[1]);CHECK(pins[0]&&!pins[1]&&gate.observe(&backing).cpu_groups==maximum_groups-1);for(auto& pin:pins)pin.release();
    auto writer=gate.begin_cpu_writer(&backing);CHECK(writer.status==Status::ok);CHECK(gate.try_cpu_group(&backing).status==Status::writer_busy);
    CHECK(gate.begin_cpu_writer(&backing).status==Status::self_wait);CHECK(gate.begin_graphics(&backing).status==Status::self_wait);
    CHECK(gate.wait_cpu_group(&backing).status==Status::self_wait);
    auto moved=std::move(writer.value);CHECK(moved&&!writer.value);moved.release();CHECK(gate.observe(&backing).writers_active==0);
}
void writer_barrier(){Coordinator gate;int backing{};auto pin=gate.try_cpu_group(&backing);CHECK(pin.status==Status::ok);
    std::atomic<unsigned> effects{};std::promise<void> finish;auto end=finish.get_future().share();
    auto worker=std::async(std::launch::async,[&]{auto writer=gate.begin_cpu_writer(&backing);if(writer.status!=Status::ok)throw std::runtime_error("writer");++effects;end.wait();++effects;});
    until([&]{return gate.observe(&backing).writers_waiting==1;});CHECK(effects==0);CHECK(gate.try_cpu_group(&backing).status==Status::writer_busy);
    pin.value.release();until([&]{return effects==1;});CHECK(gate.observe(&backing).writers_active==1&&gate.observe(&backing).cpu_groups==0);
    CHECK(gate.try_cpu_group(&backing).status==Status::writer_busy);finish.set_value();worker.get();CHECK(effects==2&&gate.observe(&backing).writers_active==0);
    CHECK(gate.try_cpu_group(&backing).status==Status::ok);
}
void writer_exclusion(){Coordinator gate;int backing{};std::promise<void> release;auto end=release.get_future().share();std::atomic<unsigned> effects{};
    auto one=std::async(std::launch::async,[&]{auto w=gate.begin_cpu_writer(&backing);if(!w.value)throw std::runtime_error("firstwriter");++effects;end.wait();});
    until([&]{return effects==1;});auto two=std::async(std::launch::async,[&]{auto w=gate.begin_cpu_writer(&backing);if(!w.value)throw std::runtime_error("secondwriter");++effects;});
    until([&]{return gate.observe(&backing).writers_waiting==1;});CHECK(effects==1);release.set_value();one.get();two.get();CHECK(effects==2);
}
void graphics_waits_writers(){Coordinator gate;int backing{};auto pin=gate.try_cpu_group(&backing);CHECK(bool(pin.value));
    std::promise<void> release_writer,release_graphics;auto writer_end=release_writer.get_future().share(),graphics_end=release_graphics.get_future().share();std::atomic<bool> writing{},graphics{};
    auto w=std::async(std::launch::async,[&]{auto r=gate.begin_cpu_writer(&backing);if(!r.value)throw std::runtime_error("writer");writing=true;writer_end.wait();});
    until([&]{return gate.observe(&backing).writers_waiting==1;});
    auto g=std::async(std::launch::async,[&]{auto r=gate.begin_graphics(&backing);if(!r.value)throw std::runtime_error("graphics");graphics=true;graphics_end.wait();});
    until([&]{return gate.observe(&backing).graphics_waiting==1;});CHECK(!writing&&!graphics&&gate.try_cpu_group(&backing).status==Status::graphics_owned);
    pin.value.release();until([&]{return writing.load();});CHECK(!graphics);release_writer.set_value();w.get();until([&]{return graphics.load();});
    {auto r=gate.begin_cpu_writer(&backing);CHECK(r.status==Status::ok);} // Legal despite graphics activity.
    release_graphics.set_value();g.get();CHECK(gate.observe(&backing).graphics_active==0&&gate.observe(&backing).graphics_ever);
    CHECK(gate.try_cpu_group(&backing).status==Status::graphics_owned);
}
void withdrawal(){Coordinator gate;std::array<int,maximum_backings+1> banks{};auto pin=gate.try_cpu_group(&banks[0]);CHECK(bool(pin.value));
    for(std::size_t i=1;i<maximum_backings;++i){auto p=gate.try_cpu_group(&banks[i]);CHECK(p.status==Status::ok);}
    CHECK(gate.begin_cpu_writer(&banks.back()).status==Status::capacity);std::atomic<bool> wrote{};
    auto writer=std::async(std::launch::async,[&]{auto r=gate.begin_cpu_writer(&banks.back());if(r.status!=Status::capacity)throw std::runtime_error("capacity");if(gate.withdraw_cpu_capture()!=Status::ok)throw std::runtime_error("withdrawal");wrote=true;});
    until([&]{return gate.observe(&banks[0]).cpu_capture_disabled;});CHECK(!wrote&&gate.observe(&banks[0]).cpu_groups==1);
    CHECK(gate.try_cpu_group(&banks[0]).status==Status::unavailable);CHECK(gate.try_cpu_group(&banks.back()).status==Status::unavailable);
    pin.value.release();writer.get();CHECK(wrote&&gate.observe(&banks[0]).cpu_groups==0);CHECK(gate.withdraw_cpu_capture()==Status::ok);
}
void metadata_no_alloc(){Coordinator gate;int backing{};bool read=false,write=false,graphics=false,withdraw=false;
    deny_allocations=true;{auto p=gate.try_cpu_group(&backing);read=bool(p.value);}{auto p=gate.begin_cpu_writer(&backing);write=bool(p.value);}
    {auto p=gate.wait_cpu_group(&backing);read=read&&bool(p.value);}
    {auto p=gate.begin_graphics(&backing);graphics=bool(p.value);}withdraw=gate.withdraw_cpu_capture()==Status::ok;deny_allocations=false;
    CHECK(read&&write&&graphics&&withdraw&&denied==0);
}
void ticket_order(){Coordinator gate;int backing{};auto pin=gate.try_cpu_group(&backing);CHECK(bool(pin.value));std::atomic<unsigned> order{};
    std::array<std::promise<void>,3> releases;std::array<std::shared_future<void>,3> release;
    for(unsigned i=0;i<3;++i)release[i]=releases[i].get_future().share();
    auto first=std::async(std::launch::async,[&]{auto w=gate.begin_cpu_writer(&backing);if(!w.value)throw std::runtime_error("older writer");unsigned expected=0;if(!order.compare_exchange_strong(expected,1))throw std::runtime_error("older writer overtaken");release[0].wait();});
    until([&]{return gate.observe(&backing).writers_waiting==1;});
    auto second=std::async(std::launch::async,[&]{auto r=gate.wait_cpu_group(&backing);if(!r.value)throw std::runtime_error("first reader");unsigned expected=1;if(!order.compare_exchange_strong(expected,2))throw std::runtime_error("reader order");release[1].wait();});
    until([&]{return gate.observe(&backing).readers_waiting==1;});CHECK(gate.observe(&backing).cpu_groups==1);
    auto third=std::async(std::launch::async,[&]{auto w=gate.begin_cpu_writer(&backing);if(!w.value)throw std::runtime_error("later writer");unsigned expected=2;if(!order.compare_exchange_strong(expected,3))throw std::runtime_error("later writer overtook reader");release[2].wait();});
    until([&]{return gate.observe(&backing).writers_waiting==2;});
    auto fourth=std::async(std::launch::async,[&]{auto r=gate.wait_cpu_group(&backing);if(!r.value)throw std::runtime_error("later reader");unsigned expected=3;if(!order.compare_exchange_strong(expected,4))throw std::runtime_error("later reader starved writer");});
    until([&]{return gate.observe(&backing).readers_waiting==2;});CHECK(order==0&&gate.try_cpu_group(&backing).status==Status::writer_busy);
    pin.value.release();until([&]{return order==1;});CHECK(gate.observe(&backing).cpu_groups==0);releases[0].set_value();first.get();
    until([&]{return order==2;});CHECK(gate.observe(&backing).cpu_groups==1);releases[1].set_value();second.get();
    until([&]{return order==3;});CHECK(gate.observe(&backing).cpu_groups==0);releases[2].set_value();third.get();fourth.get();CHECK(order==4);
    CHECK(gate.observe(&backing).readers_waiting==0&&gate.observe(&backing).writers_waiting==0);
}
void pending_reader_cancellation(){
    for(bool graphics:{false,true}){Coordinator gate;int backing{};auto writer=gate.begin_cpu_writer(&backing);CHECK(bool(writer.value));
        auto reader=std::async(std::launch::async,[&]{auto r=gate.wait_cpu_group(&backing);if(r.value)throw std::runtime_error("cancelled reader got group");return r.status;});
        until([&]{return gate.observe(&backing).readers_waiting==1;});CHECK(gate.observe(&backing).cpu_groups==0);
        if(graphics){auto owner=std::async(std::launch::async,[&]{auto g=gate.begin_graphics(&backing);if(!g.value)throw std::runtime_error("graphics");});
            until([&]{return gate.observe(&backing).graphics_waiting==1;});CHECK(reader.get()==Status::graphics_owned);CHECK(gate.observe(&backing).readers_waiting==0);
            writer.value.release();owner.get();CHECK(gate.wait_cpu_group(&backing).status==Status::graphics_owned);
        }else{CHECK(gate.withdraw_cpu_capture()==Status::ok);CHECK(reader.get()==Status::unavailable);CHECK(gate.observe(&backing).readers_waiting==0);
            writer.value.release();CHECK(gate.wait_cpu_group(&backing).status==Status::unavailable);}
    }
}
void reader_wait_capacity(){Coordinator gate;int backing{};auto writer=gate.begin_cpu_writer(&backing);CHECK(bool(writer.value));
    std::array<std::future<Status>,maximum_groups> readers;
    for(auto& task:readers)task=std::async(std::launch::async,[&]{return gate.wait_cpu_group(&backing).status;});
    until([&]{return gate.observe(&backing).readers_waiting==maximum_groups;});CHECK(gate.observe(&backing).cpu_groups==0);
    auto extra=std::async(std::launch::async,[&]{return gate.wait_cpu_group(&backing).status;});CHECK(extra.get()==Status::capacity);
    CHECK(gate.withdraw_cpu_capture()==Status::ok);for(auto& task:readers)CHECK(task.get()==Status::unavailable);
    CHECK(gate.observe(&backing).readers_waiting==0);writer.value.release();
}
int main()try{basics();writer_barrier();writer_exclusion();graphics_waits_writers();withdrawal();metadata_no_alloc();ticket_order();pending_reader_cancellation();reader_wait_capacity();std::cout<<checks<<" cooperating writer assertions passed\n";return 0;}
catch(const std::exception& e){deny_allocations=false;std::cerr<<e.what()<<'\n';return 1;}
