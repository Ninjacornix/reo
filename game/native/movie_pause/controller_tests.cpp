#include "controller.hpp"
#include <array>
#include <cstdio>
#include <stdexcept>
#include <string>
namespace n=reo::native::movie_pause;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Movie pause boundary check "+std::to_string(checks));}
struct Ports final:n::Ports {
    n::Controller* owner{};n::Reply reply;unsigned calls{};bool nested{};n::Result nested_result;
    n::Reply call(n::Call,n::View)noexcept override{
        ++calls;if(nested){nested=false;nested_result=owner->execute(n::Operation::nested,1);}return reply;
    }
};
struct Hooks final:reo::native::movie_selected_clock::GuardHooks {
    unsigned entered{},left{};
    void enter(std::uint32_t)noexcept override{++entered;}
    void leave(std::uint32_t)noexcept override{++left;}
};
int main(){try{
    for(auto operation:{n::Operation::step,n::Operation::pause,n::Operation::nested,n::Operation::forward}){
        n::Config config;config.state.rate=9;config.state.pause=1;auto provider=std::make_shared<Ports>();config.ports=provider;
        n::Controller owner(config);const auto before=owner.snapshot();
        check(owner.execute(operation,2).status==n::Status::invalid_rate && owner.snapshot().view.state==before.view.state && provider->calls==0);
    }
    {
        n::Config config;config.state.rate=0xFFFFFFFFu;auto provider=std::make_shared<Ports>();config.ports=provider;
        n::Controller owner(config);provider->owner=&owner;provider->nested=true;
        check(owner.execute(n::Operation::pause,1).status==n::Status::completed && provider->calls==1);
        check(provider->nested_result.status==n::Status::busy && owner.snapshot().view.state.depth==1);
        check(owner.execute(static_cast<n::Operation>(999),0).status==n::Status::invalid_input && provider->calls==1);
    }
    for(bool command_failure:{false,true}){
        auto provider=std::make_shared<Ports>();auto hooks=std::make_shared<Hooks>();n::Config config;config.ports=provider;config.hooks=hooks;
        provider->reply.provider=n::ProviderStatus::failed;provider->reply.status=1;provider->reply.updates.depth=7;provider->reply.updates.pending=99;
        n::Controller owner(config);const auto result=owner.execute(command_failure?n::Operation::pause:n::Operation::buffer,1);const auto after=owner.snapshot();
        check(result.status==n::Status::provider_failure && !result.return_defined && after.view.state.depth==7 && provider->calls==1);
        if(command_failure)check(after.view.state.pause==1 && after.view.state.pending==1 && hooks->entered==0);
        else check(after.view.state.buffering==0 && after.view.state.episodes==0 && after.view.state.pending==99 && hooks->entered==1 && hooks->left==1 && after.view.guard==n::Guard{});
    }
    {
        auto provider=std::make_shared<Ports>();std::weak_ptr<Ports> retained=provider;n::Config config;config.ports=provider;
        {
            n::Controller owner(config);config.ports.reset();provider.reset();check(!retained.expired());
            check(owner.execute(n::Operation::nested,0).status==n::Status::completed && owner.snapshot().view.state.depth==0xFFFFFFFFu);
        }
        check(retained.expired());
    }
    std::printf("%u movie pause admission/reentry/partial-effect/lifetime checks\n",checks);return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}}
