#define REO_TIMING_FIXTURE_SUPPORT_ONLY
#include "fixture.cpp"
#include "buffer_queues.hpp"
struct Controlled final:n::audio::ControlledSource {
    Data& data;explicit Controlled(Data& value):data(value){}
    n::audio::ProviderStatus status(std::uint8_t& value)noexcept override{value=static_cast<std::uint8_t>(data.status);return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus estimate(n::Words& value)noexcept override{data.event(0);value=data.sample;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus sample_frequency(std::uint32_t& value)noexcept override{data.event(10);value=data.sample_frequency;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus pause(std::uint32_t value)noexcept override{data.event(8,{value,0,0,0});data.device_pause=value&255u;return n::audio::ProviderStatus::completed;}
    n::audio::ProviderStatus discard(std::uint32_t value,std::uint32_t& returned)noexcept override{data.event(9,{value,0,0,0});returned=0;return n::audio::ProviderStatus::completed;}
};
void print_audio(const n::View& view,std::uint32_t device){print(view);const auto control=*view.audio_commands;std::cout<<' '<<control.requested_pause<<' '<<control.residual<<' '<<device;}
int main(){
    std::string command;Data data;data.events.reserve(128);unsigned identity{};
    while(std::cin>>command){
        if(command!="begin" || !(std::cin>>identity))return 2;
        n::Config config;for(auto field:facts)if(!(std::cin>>config.facts.*field))return 3;
        auto guard=std::make_shared<n::selected::GuardState>();std::uint32_t hook{};
        if(!(std::cin>>config.frequency>>hook>>guard->depth>>guard->tag))return 4;
        n::Buffering buffer;buffer.absolute=999;buffer.stalled=1;buffer.video_slot=1;buffer.audio_slot=3;std::uint32_t mode{};n::AudioCommands controls;
        if(!(std::cin>>buffer.audio>>buffer.enabled>>buffer.latest.numerator>>buffer.latest.denominator>>controls.channel>>controls.decoder>>controls.requested_pause>>controls.residual>>mode))return 5;
        auto queue=std::make_shared<reo::native::sjuni::Pool>(8);auto regions=std::make_shared<std::array<std::uint8_t,1>>();
        for(auto& stream:buffer.streams){stream.capacity=100;stream.queue=std::make_shared<n::UniBufferQueue>(queue,regions);}
        config.buffering=buffer;config.audio_commands=controls;config.audio_filter_mode=mode;config.guard=guard;
        config.audio=std::make_shared<Controlled>(data);config.helper=std::make_shared<Helper>(data);config.ports=std::make_shared<Ports>(data);if(hook)config.hooks=std::make_shared<Hooks>(data);
        auto owner=n::Context::create(std::move(config));data.owner=owner;data.device_pause=0;data.events.clear();
        const auto emit=[&](int index,n::Result result){std::cout<<"row "<<identity<<' '<<index;print_audio(owner->snapshot(),data.device_pause);std::cout<<' '<<unsigned(result.status)<<' '<<result.return_defined<<' '<<(result.return_defined?result.returned:0)<<' '<<data.events.size();
            for(const auto& event:data.events){std::cout<<' '<<event.kind;for(auto word:event.arguments)std::cout<<' '<<word;print_audio(event.view,event.device_pause);}std::cout<<'\n';};
        n::Result initial;initial.status=n::Status::completed;emit(-1,initial);unsigned operations{};if(!(std::cin>>operations))return 6;
        for(unsigned index=0;index<operations;++index){
            n::Input input;if(!(std::cin>>command>>input.value>>data.sample.numerator>>data.sample.denominator>>data.counter>>data.frequency>>data.status>>data.sample_frequency))return 7;
            std::optional<n::Operation> op;for(const auto& entry:{std::pair{"audio_requested",n::Operation::audio_requested},{"audio_temporary",n::Operation::audio_temporary},{"audio_command",n::Operation::audio_command},{"selected",n::Operation::selected},{"refresh",n::Operation::refresh},{"tick",n::Operation::tick},{"buffer",n::Operation::buffer},{"pause",n::Operation::pause}})if(command==entry.first)op=entry.second;
            if(!op)return 8;
            data.events.clear();emit(static_cast<int>(index),owner->execute(*op,input));
        }
    }
    return std::cin.eof()?0:9;
}
