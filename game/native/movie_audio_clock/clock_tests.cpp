#include "clock.hpp"
#include <array>
#include <cstdio>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_audio_clock;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Movie audio clock check "+std::to_string(checks));}
struct Control {
    std::array<unsigned,8> events{};unsigned count{},fail{},reenter{};n::Clock* owner{};
    n::Words sample{1600,48000};std::uint64_t frequency{576000};
    n::ProviderStatus record(unsigned event)noexcept{
        if(count>=events.size())return n::ProviderStatus::fault;
        events[count++]=event;
        if(event==1 && reenter){
            reenter=0;
            const auto before=owner->snapshot().state;
            const auto result=owner->execute(n::Operation::slot,4,{777,888});
            if(result.status!=n::Status::busy || result.written || result.words.numerator!=777 || owner->snapshot().state.diagnostic!=before.diagnostic)return n::ProviderStatus::fault;
        }
        return event==fail?n::ProviderStatus::closed:n::ProviderStatus::completed;
    }
};
struct Audio final:n::AudioSource {
    Control& c;explicit Audio(Control& value):c(value){}
    n::ProviderStatus status(std::uint8_t& value)noexcept override{value=255;return c.record(1);}
    n::ProviderStatus estimate(n::Words& value)noexcept override{
        if(c.owner->snapshot().state.diagnostic!=0xFFFFFFFFu)return n::ProviderStatus::fault;
        value=c.sample;return c.record(2);
    }
};
struct Helper final:n::HelperClock {
    Control& c;explicit Helper(Control& value):c(value){}
    n::ProviderStatus counter(std::uint64_t& value)noexcept override{value=19200;return c.record(3);}
    n::ProviderStatus frequency(std::uint64_t& value)noexcept override{value=c.frequency;return c.record(4);}
};
int main(){try{
    for(unsigned failure=0;failure<=4;++failure){
        Control c;c.fail=failure;c.reenter=1;auto audio=std::make_shared<Audio>(c);auto helper=std::make_shared<Helper>(c);
        std::weak_ptr<Audio> wa=audio;std::weak_ptr<Helper> wh=helper;
        {
            n::State state;state.diagnostic=123;n::Clock owner(state,audio,helper);c.owner=&owner;audio.reset();helper.reset();
            check(!wa.expired() && !wh.expired());
            const auto result=owner.execute(n::Operation::slot,4,{777,888});
            check(c.count==(failure?failure:4));
            for(unsigned e=0;e<c.count;++e)check(c.events[e]==e+1);
            const auto after=owner.snapshot();
            if(failure){
                check(result.status==n::Status::provider_failure && !result.written && !result.return_defined && result.words.numerator==777 && result.words.denominator==888);
                check(after.state.filter==state.filter && after.state.cache.numerator==0 && after.state.cache.denominator==1);
                check(after.state.diagnostic==(failure==1?123u:0xFFFFFFFFu));
                check(unsigned(after.health.stage)==failure && after.health.provider==n::ProviderStatus::closed);
            }else check(result.status==n::Status::completed && result.written && result.return_defined && result.callback_status==0);
        }
        check(wa.expired() && wh.expired());
    }
    {
        Control c;c.frequency=0;auto audio=std::make_shared<Audio>(c);auto helper=std::make_shared<Helper>(c);
        n::Clock owner({},audio,helper);c.owner=&owner;const auto before=owner.snapshot();
        const auto result=owner.execute(n::Operation::slot,4,{777,888});const auto after=owner.snapshot();
        check(result.status==n::Status::filter_failure && !result.written && after.state.filter==before.state.filter && after.state.cache.numerator==0);
        check(after.state.diagnostic==0xFFFFFFFFu && after.health.filter==n::filter::Status::division_by_zero);
    }
    {
        Control c;auto audio=std::make_shared<Audio>(c);auto helper=std::make_shared<Helper>(c);n::State state;state.cache={99,123};
        auto owner=std::make_shared<n::Clock>(state,audio,helper);c.owner=owner.get();
        n::selected::Config config;config.state.selector=2;config.state.counter.actual=static_cast<std::uint32_t>(-4);
        n::selected::Clock selected(config);check(selected.set_callback(2,owner)==n::selected::Status::completed);
        const auto value=selected.execute(n::selected::Operation::selected,{77,88},{});
        check(value.words.numerator==99 && value.words.denominator==123 && c.count==0 && value.query_status==0);
        n::selected::State inactive;inactive.counter.actual=3;const auto reply=owner->query(inactive,{77,88});
        check(reply.numerator && reply.denominator && reply.words.numerator==0xFFFFFFFFu && reply.words.denominator==1 && c.count==0);
        check(owner->execute(static_cast<n::Operation>(999),4,{77,88}).status==n::Status::invalid_input && c.count==0);
    }
    std::printf("%u movie audio provider/order/lifetime/admission checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
