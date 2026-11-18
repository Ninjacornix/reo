#include "ps2_syscalls.h"
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <stdexcept>
#include <thread>
#include <tuple>
#include <type_traits>
#include <vector>

#if !PS2_RUNTIME_HAS_DTX_LAYOUT_SNAPSHOT
#error Exact new header required
#endif
static_assert(sizeof(PS2DtxCompatLayout)==7*sizeof(std::uint32_t));
static_assert(std::is_trivially_copyable_v<PS2DtxCompatLayout>);
static_assert(std::is_same_v<decltype(ps2_syscalls::dtxCompatLayoutSnapshot()),PS2DtxCompatLayout>);
std::atomic<unsigned> assertions{};
void check(bool value){const auto n=++assertions;if(!value)throw std::runtime_error("snapshot assertion "+std::to_string(n));}
struct ObservedMutex {
    std::mutex actual,observation;
    std::condition_variable changed;
    std::uint64_t attempts{};
    std::thread::id owner;
    void announce(){std::lock_guard lock(observation);++attempts;changed.notify_all();}
    void lock(){announce();actual.lock();owner=std::this_thread::get_id();}
    bool try_lock(){announce();if(!actual.try_lock())return false;owner=std::this_thread::get_id();return true;}
    void unlock(){owner={};actual.unlock();}
    bool held_by_this_thread() const{return owner==std::this_thread::get_id();}
    std::uint64_t current_attempts(){std::lock_guard lock(observation);return attempts;}
    bool wait_for_attempt(std::uint64_t previous){
        std::unique_lock lock(observation);
        return changed.wait_for(lock,std::chrono::seconds(2),[&]{return attempts>previous;});
    }
};
namespace ps2_syscalls {
#ifdef REAL_MUTEX
std::mutex g_rpc_mutex,g_dtx_rpc_mutex;
#else
ObservedMutex g_rpc_mutex,g_dtx_rpc_mutex;
#endif
PS2DtxCompatLayout g_dtxCompatLayout;
std::atomic<unsigned> reset_calls{};
// The actual reset body is not migrated or executed in this isolated test.
// Its call boundary is observed; patch/source checks independently prove it
// unchanged. A getter call must never cross this boundary.
void resetDtxRpcStateUnlocked(){
#ifndef REAL_MUTEX
    check(g_rpc_mutex.held_by_this_thread()&&g_dtx_rpc_mutex.held_by_this_thread());
#endif
    ++reset_calls;
}
#include "exact_methods.inc"
}
namespace a=ps2_syscalls;
auto fields(const PS2DtxCompatLayout& v){return std::tie(v.rpcSid,v.urpcObjBase,v.urpcObjLimit,v.urpcObjStride,v.urpcFnTableBase,v.urpcObjTableBase,v.dispatcherFuncAddr);}
bool same(const PS2DtxCompatLayout& x,const PS2DtxCompatLayout& y){return fields(x)==fields(y);}
const PS2DtxCompatLayout layout_a{0x80000a81u,0x001e0000u,0x001eff00u,0x20u,0x0020a000u,0x0020b000u,0x0013ef00u};
const PS2DtxCompatLayout layout_b{0x80000a82u,0x001d0000u,0x001d1000u,0x40u,0x0030a000u,0x0030b000u,0x0023ef00u};
#ifndef REAL_MUTEX
template<class Call>void blocked_by(ObservedMutex& held,Call call){
    held.lock();const auto previous=held.current_attempts();std::atomic<bool> done{};
    std::thread worker([&]{call();done=true;});
    const bool attempted=held.wait_for_attempt(previous);
    const bool completed_while_held=done.load();
    held.unlock();worker.join();
    check(attempted&&!completed_while_held&&done.load());
}
#endif
int main(){try{
    check(layout_a.isConfigured()&&layout_a.hasUrpcObjectRange()&&layout_a.hasUrpcTables());
    check(layout_b.isConfigured()&&layout_b.hasUrpcObjectRange()&&layout_b.hasUrpcTables());
    check(same(a::dtxCompatLayoutSnapshot(),PS2DtxCompatLayout{}));check(a::reset_calls==0);
    auto caller_input=layout_a;a::setDtxCompatLayout(caller_input);caller_input=layout_b;
    check(same(a::dtxCompatLayoutSnapshot(),layout_a));check(a::reset_calls==1);
    auto saved=a::dtxCompatLayoutSnapshot();auto independent=saved;independent=layout_b;
    check(same(independent,layout_b)&&same(a::dtxCompatLayoutSnapshot(),layout_a));
    a::setDtxCompatLayout(layout_b);check(a::reset_calls==2);
    check(same(saved,layout_a)&&same(a::dtxCompatLayoutSnapshot(),layout_b));
    a::clearDtxCompatLayout();check(a::reset_calls==3);
    auto cleared=a::dtxCompatLayoutSnapshot();check(same(cleared,PS2DtxCompatLayout{}));
    check(!cleared.isConfigured()&&!cleared.hasUrpcObjectRange()&&!cleared.hasUrpcTables()&&cleared.urpcObjStride==0x20);
    check(same(saved,layout_a)&&a::reset_calls==3);
#ifndef REAL_MUTEX
    for(auto* mutex:{&a::g_rpc_mutex,&a::g_dtx_rpc_mutex}){
        blocked_by(*mutex,[]{(void)a::dtxCompatLayoutSnapshot();});
        blocked_by(*mutex,[]{a::setDtxCompatLayout(layout_a);});
        blocked_by(*mutex,[]{a::clearDtxCompatLayout();});
    }
#endif
    a::setDtxCompatLayout(layout_a);const auto before=a::reset_calls.load();
    std::atomic<bool> begin{},bad{};
    std::vector<std::thread> readers;
    for(unsigned n=0;n<4;++n)readers.emplace_back([&]{
        while(!begin.load())std::this_thread::yield();
        for(unsigned i=0;i<10000;++i){auto snapshot=a::dtxCompatLayoutSnapshot();if(!same(snapshot,layout_a)&&!same(snapshot,layout_b))bad=true;}
    });
    std::thread writer([&]{while(!begin.load())std::this_thread::yield();for(unsigned i=0;i<50000;++i)a::setDtxCompatLayout(i%2?layout_a:layout_b);});
    begin=true;for(auto& reader:readers)reader.join();writer.join();
    check(!bad&&a::reset_calls==before+50000);
    check(same(saved,layout_a));
    const auto no_effect=a::reset_calls.load();for(unsigned i=0;i<1000;++i)(void)a::dtxCompatLayoutSnapshot();
    check(a::reset_calls==no_effect);
    std::cout<<"{\"assertions\":"<<assertions<<",\"stress_reads\":40000,\"stress_sets\":50000,\"getter_only_reads\":1000,\"torn\":false,\"reset_calls\":"<<a::reset_calls<<"}\n";
    return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
