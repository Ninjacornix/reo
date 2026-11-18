#include "transfer_groups.hpp"
#include <cstdlib>
#include <functional>
#include <iostream>
#include <new>
#include <stdexcept>

static bool counting{};static unsigned allocations{},checks{},failures{};
void* operator new(std::size_t n){if(counting)++allocations;if(auto p=std::malloc(n?n:1))return p;throw std::bad_alloc();}
void* operator new[](std::size_t n){return ::operator new(n);}
#if defined(__GNUC__) || defined(__clang__)
__attribute__((noinline))
#endif
static void free_test_allocation(void* p)noexcept{std::free(p);}
void operator delete(void* p)noexcept{free_test_allocation(p);}void operator delete[](void* p)noexcept{free_test_allocation(p);}
void operator delete(void* p,std::size_t)noexcept{free_test_allocation(p);}void operator delete[](void* p,std::size_t)noexcept{free_test_allocation(p);}
void check(bool b){++checks;if(!b)++failures;}
namespace t=reo::native::adxt_transfer_groups;
namespace g=reo::native::adxt_service_group;
namespace clock_ns=reo::native::adxt_estimated_clock;
struct Guard final:t::ChunkGuard,g::Guards {
    int cri{},rna{},chunk{};unsigned chunk_enters{},chunk_leaves{};
    void enter()noexcept override{++chunk;++chunk_enters;}
    void leave()noexcept override{--chunk;++chunk_leaves;check(chunk>=0);}
    void enter(g::Domain d)noexcept override{if(d==g::Domain::cri)++cri;else ++rna;}
    void leave(g::Domain d)noexcept override{if(d==g::Domain::cri)--cri;else --rna;check(cri>=0 && rna>=0);}
};
struct Work final:g::ActiveWork {
    std::int8_t activity{1};unsigned calls{};std::function<void()> callback;bool* destroyed{};
    ~Work(){if(destroyed)*destroyed=true;}
    std::int8_t active()const noexcept override{return activity;}
    void service()noexcept override{++calls;if(callback)callback();}
};
int main(){
    auto clock=std::make_shared<clock_ns::Shared>();auto guard=std::make_shared<Guard>();
    auto dtx=std::make_shared<t::DtxGroup>(guard);auto dtr=std::make_shared<t::DtrGroup>(dtx);g::Group owner(clock,guard,dtr,dtx);
    check(!dtx->set(8,{}) && !dtr->set(32,{}));
    auto first=std::make_shared<Work>(),last=std::make_shared<Work>(),x0=std::make_shared<Work>(),x7=std::make_shared<Work>();
    first->callback=[&]{check(clock->service_busy==3 && guard->cri==1 && !guard->rna && !guard->chunk);check(dtr->set(31,last));};
    last->callback=[&]{check(!guard->chunk);check(dtx->set(7,x7));};
    x7->callback=[&]{check(clock->service_busy==3 && guard->cri==1 && guard->chunk==1);check(dtx->set(0,x0));check(owner.service()==g::Status::busy);};
    x0->callback=[&]{check(guard->chunk==1 && x7->calls==1);};
    check(dtr->set(0,first));allocations=0;counting=true;const auto status=owner.service();counting=false;
    check(status==g::Status::completed && allocations==0);check(first->calls==1 && last->calls==1 && x0->calls==1 && x7->calls==2);
    check(guard->chunk_enters==2 && guard->chunk_leaves==2 && !guard->cri && !guard->rna && !guard->chunk && !clock->service_busy);
    check(dtx->set(0,{}) && dtx->set(7,{}) && dtr->set(0,{}) && dtr->set(31,{}));
    bool destroyed=false;auto current=std::make_shared<Work>();current->destroyed=&destroyed;
    current->callback=[&]{check(dtx->set(0,{}));check(!destroyed);};check(dtx->set(0,current));current.reset();
    dtx->service();check(destroyed);
    auto bad=std::make_shared<Work>();bad->activity=-1;check(dtr->set(0,bad) && dtx->set(0,bad));
    dtr->service();check(!bad->calls);
    bool refused=false;try{t::DtxGroup invalid({});}catch(const std::invalid_argument&){refused=true;}check(refused);
    refused=false;try{t::DtrGroup invalid({});}catch(const std::invalid_argument&){refused=true;}check(refused);
    std::cout<<checks<<" transfer-group ownership checks, "<<failures<<" failures\n";return failures?1:0;
}
