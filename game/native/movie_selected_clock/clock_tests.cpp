#include "clock.hpp"
#include <cstdio>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_selected_clock;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Selected movie clock check "+std::to_string(checks));}
struct Callback final:n::Query {
    n::Clock* owner{};bool* destroyed{};bool alive_after_remove{},nested_refused{};unsigned calls{};
    std::weak_ptr<Callback> self;
    ~Callback()override{if(destroyed)*destroyed=true;}
    n::Reply query(n::State,n::Words) noexcept override{
        ++calls;
        if(owner){
            // Refuse destructive self-removal in the negative build if the
            // caller failed to retain this invocation. This avoids a UAF.
            if(self.use_count()<2)return{};
            (void)owner->set_callback(4,{});alive_after_remove=destroyed && !*destroyed;
            nested_refused=owner->execute(n::Operation::selected,{9,11},{}).status==n::Status::busy;
        }
        n::Reply reply;reply.words={123,0};reply.status=7;return reply;
    }
};
struct Probe final:n::Probe {
    std::weak_ptr<Callback> callback;bool retained_at_leave{},alive_after_remove{},nested_refused{};
    void event(n::Event event,const n::Snapshot&,n::Words) noexcept override{
        if(event==n::Event::phase_leave){auto held=callback.lock();retained_at_leave=bool(held);
            if(held){alive_after_remove=held->alive_after_remove;nested_refused=held->nested_refused;}}
    }
};
struct External final:n::Query {
    n::Clock* owner{};std::weak_ptr<External> self;bool* destroyed{};bool* alive{};bool* busy{};
    ~External()override{*destroyed=true;}
    n::Reply query(n::State,n::Words) noexcept override{
        if(self.use_count()<2)return{}; // Safe refusal in the negative build.
        (void)owner->set_external({});*alive=!*destroyed;
        *busy=owner->execute(n::Operation::external,{},{}).status==n::Status::busy;
        n::Reply reply;reply.words={1000,48000};reply.status=0xFFFFFFF9u;return reply;
    }
};
int main(){try{
    {
        n::Config config;config.state.selector=4;bool destroyed=false;auto probe=std::make_shared<Probe>();config.probe=probe;n::Clock clock(config);
        auto callback=std::make_shared<Callback>();callback->self=callback;callback->destroyed=&destroyed;callback->owner=&clock;probe->callback=callback;
        check(clock.set_callback(4,callback)==n::Status::completed);callback.reset();
        const auto result=clock.execute(n::Operation::selected,{9,11},{});
        check(result.status==n::Status::completed && result.query_status_defined && result.query_status==7 && result.words.numerator==123 && result.words.denominator==0);
        check(probe->retained_at_leave && probe->alive_after_remove && probe->nested_refused && destroyed && probe->callback.expired());
        check(clock.snapshot().slots[4]==n::Kind::empty);
        check(clock.set_callback(7,{})==n::Status::invalid_input);
        check(clock.execute(static_cast<n::Operation>(99),{9,11},{}).status==n::Status::invalid_input);
    }
    {
        bool destroyed=false,alive=false,busy=false;n::Config config;config.state.counter.actual=4;
        config.state.counter.external_accumulator=100;config.state.previous_sample=900;n::Clock clock(config);
        auto callback=std::make_shared<External>();callback->owner=&clock;callback->self=callback;callback->destroyed=&destroyed;callback->alive=&alive;callback->busy=&busy;
        std::weak_ptr<External> weak=callback;check(clock.set_external(callback)==n::Status::completed);callback.reset();
        const auto result=clock.execute(n::Operation::external,{7,9},{});
        check(result.status==n::Status::completed && result.query_status==0xFFFFFFF9u && result.words.numerator==200 && result.words.denominator==48000);
        check(alive && busy && destroyed && weak.expired() && !clock.snapshot().external_present);
        check(clock.snapshot().state.previous_sample==1000 && clock.snapshot().state.external_denominator==48000);
    }
    {
        n::Config config;config.state.selector=1;config.state.counter.actual=4;config.state.counter.active_counter=77;config.frequency=0;n::Clock clock(config);
        const auto result=clock.execute(n::Operation::selected,{1,2},{});
        check(result.words.numerator==77 && result.words.denominator==0 && result.query_status==0);
    }
    {
        n::Config config;config.state.selector=3;config.state.counter.actual=4;n::Clock clock(config);
        const auto result=clock.execute(n::Operation::selected,{0x80000000u,0xFFFFFFFFu},{});
        check(result.words.numerator==0x80000000u && result.words.denominator==0xFFFFFFFFu);
    }
    {
        n::Config config;config.state.selector=7;bool refused=false;
        try{n::Clock clock(config);}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    std::printf("%u selected-clock ownership/boundary checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
