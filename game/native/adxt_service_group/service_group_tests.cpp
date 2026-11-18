#include "service_group.hpp"
#include <array>
#include <cstdlib>
#include <functional>
#include <iostream>
#include <new>
#include <stdexcept>

static bool count_allocations{};static unsigned allocations{},checks{},failures{};
void* operator new(std::size_t n){if(count_allocations)++allocations;if(auto p=std::malloc(n?n:1))return p;throw std::bad_alloc();}
void* operator new[](std::size_t n){return ::operator new(n);}
void operator delete(void* p)noexcept{std::free(p);}void operator delete[](void* p)noexcept{std::free(p);}
void operator delete(void* p,std::size_t)noexcept{std::free(p);}void operator delete[](void* p,std::size_t)noexcept{std::free(p);}
void check(bool b){++checks;if(!b)++failures;}
namespace g=reo::native::adxt_service_group;
namespace clock_ns=reo::native::adxt_estimated_clock;
struct Guard final:g::Guards {
    int cri{},rna{};unsigned enters{},leaves{};
    void enter(g::Domain d)noexcept override{++enters;if(d==g::Domain::cri)++cri;else ++rna;}
    void leave(g::Domain d)noexcept override{++leaves;if(d==g::Domain::cri)--cri;else --rna;check(cri>=0 && rna>=0);}
};
struct Work final:g::ActiveWork {
    std::int8_t activity{1};unsigned calls{};std::function<void()> callback;
    std::int8_t active()const noexcept override{return activity;}
    void service()noexcept override{++calls;if(callback)callback();}
};
struct Stream final:g::Stream {
    std::int8_t activity{1},state{3};unsigned phases{},ends{},errors{};bool* destroyed{};
    std::function<void(g::Phase)> callback;std::function<void()> tail;
    ~Stream(){if(destroyed)*destroyed=true;}
    std::int8_t active()const noexcept override{return activity;}
    std::int8_t phase()const noexcept override{return state;}
    void service_phase(g::Phase p)noexcept override{++phases;if(callback)callback(p);}
    void propagate_input_end()noexcept override{++ends;if(tail)tail();}
    void propagate_error()noexcept override{++errors;}
};
struct Session {
    std::shared_ptr<clock_ns::Shared> clock=std::make_shared<clock_ns::Shared>();
    std::shared_ptr<Guard> guard=std::make_shared<Guard>();
    std::shared_ptr<Work> dtr=std::make_shared<Work>(),dtx=std::make_shared<Work>();
    g::Group owner{clock,guard,dtr,dtx};
};
int main(){
    {
        Session s;check(!s.owner.set_decoder(16,{}) && !s.owner.set_stream(17,{}) && !s.owner.set_rna(0xFFFFFFFF,{}));
        check(s.owner.service()==g::Status::completed);check(s.clock->service_busy==0 && !s.guard->cri && !s.guard->rna);
        check(s.dtr->calls==1 && s.dtx->calls==1 && s.guard->enters==3 && s.guard->leaves==3);
        for(auto busy:{1u,2u,3u,0xFFFFFFFFu}){s.clock->service_busy=busy;check(s.owner.service()==g::Status::busy);check(s.clock->service_busy==busy && s.dtr->calls==1 && s.dtx->calls==1);}
    }
    {
        Session s;auto d=std::make_shared<Work>(),rna=std::make_shared<Work>();auto stream=std::make_shared<Stream>();
        d->callback=[&]{check(s.clock->service_busy==1 && s.guard->cri==1 && !s.guard->rna);check(s.owner.service()==g::Status::busy);check(s.clock->service_busy==1);};
        stream->callback=[&](g::Phase p){check(p==g::Phase::playing && s.clock->service_busy==2);stream->state=4;stream->activity=0;};
        stream->tail=[&]{check(stream->phases==1 && stream->ends==1 && !stream->errors);};
        rna->callback=[&]{check(s.clock->service_busy==3 && s.guard->cri==1 && s.guard->rna==1);check(s.owner.service()==g::Status::busy);};
        s.dtr->callback=[&]{check(s.clock->service_busy==3 && s.guard->cri==1 && !s.guard->rna);};
        s.dtx->callback=[&]{check(s.dtr->calls==1 && s.clock->service_busy==3);};
        check(s.owner.set_decoder(15,d) && s.owner.set_stream(1,stream) && s.owner.set_rna(7,rna));
        allocations=0;count_allocations=true;const auto result=s.owner.service();count_allocations=false;
        check(result==g::Status::completed && allocations==0);check(d->calls==1 && rna->calls==1 && stream->phases==1 && stream->ends==1 && stream->errors==1);
    }
    {
        Session s;auto first=std::make_shared<Work>(),old=std::make_shared<Work>(),replacement=std::make_shared<Work>();
        first->callback=[&]{check(s.owner.set_decoder(15,replacement));};
        check(s.owner.set_decoder(0,first) && s.owner.set_decoder(15,old));check(s.owner.service()==g::Status::completed);
        check(first->calls==1 && old->calls==0 && replacement->calls==1);
    }
    {
        Session s;bool destroyed=false;unsigned final_tail{};
        auto stream=std::make_shared<Stream>();stream->destroyed=&destroyed;
        stream->callback=[&](g::Phase){check(s.owner.set_stream(0,{}));check(!destroyed);};
        stream->tail=[&]{check(!destroyed);++final_tail;};check(s.owner.set_stream(0,stream));stream.reset();
        check(s.owner.service()==g::Status::completed);check(destroyed && final_tail==1);
    }
    {
        Session s;auto bad=std::make_shared<Work>();bad->activity=-1;auto stream=std::make_shared<Stream>();stream->state=-1;
        check(s.owner.set_decoder(0,bad) && s.owner.set_rna(0,bad) && s.owner.set_stream(0,stream));
        check(s.owner.service()==g::Status::completed);check(!bad->calls && !stream->phases && stream->ends==1 && stream->errors==1);
        stream->state=5;check(s.owner.service()==g::Status::completed);check(!stream->phases && stream->ends==2 && stream->errors==2);
    }
    {
        bool refused=false;try{g::Group bad({},std::make_shared<Guard>(),std::make_shared<Work>(),std::make_shared<Work>());}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    std::cout<<checks<<" audio group ownership checks, "<<failures<<" failures\n";return failures?1:0;
}
