#define REO_TIMING_FIXTURE_SUPPORT_ONLY
#include "fixture.cpp"
#include "buffer_queues.hpp"
#include <bit>
int main(){
    std::string command;Data data;data.events.reserve(64);unsigned identity{};
    while(std::cin>>command){
        if(command!="begin" || !(std::cin>>identity))return 2;
        n::Config config;
        for(auto field:facts)if(!(std::cin>>config.facts.*field))return 3;
        auto guard=std::make_shared<n::selected::GuardState>();std::uint32_t hook{};
        if(!(std::cin>>config.frequency>>hook>>guard->depth>>guard->tag))return 4;
        n::Buffering buffering;
        for(auto field:{&n::Buffering::enabled,&n::Buffering::video,&n::Buffering::audio,&n::Buffering::stalled,&n::Buffering::component_one,&n::Buffering::video_done,&n::Buffering::audio_done,&n::Buffering::video_slot,&n::Buffering::audio_slot,&n::Buffering::pause_margin,&n::Buffering::resume_margin,&n::Buffering::absolute})if(!(std::cin>>buffering.*field))return 5;
        if(!(std::cin>>buffering.latest.numerator>>buffering.latest.denominator))return 6;
        std::array<std::shared_ptr<reo::native::sjuni::Pool>,8> queues;
        auto backing=std::make_shared<std::vector<std::vector<std::uint8_t>>>();
        std::array<std::uint32_t,8> counts{};
        for(unsigned slot=0;slot<8;++slot){
            auto& stream=buffering.streams[slot];std::uint32_t present{},size{};
            if(!(std::cin>>stream.enabled>>stream.ended>>stream.capacity>>present>>size) || size>8)return 7;
            auto queue=std::make_shared<reo::native::sjuni::Pool>(16,1);queues[slot]=queue;
            for(unsigned index=0;index<size;++index){std::uint32_t length{};if(!(std::cin>>length))return 8;counts[slot]+=length;backing->emplace_back(length);
                if(queue->put(1,{index+1,0,std::bit_cast<std::int32_t>(length)})!=reo::native::sjuni::Result::completed)return 9;}
            if(present)stream.queue=std::make_shared<n::UniBufferQueue>(queue,backing);
        }
        config.buffering=std::move(buffering);config.guard=guard;config.audio=std::make_shared<Audio>(data);config.helper=std::make_shared<Helper>(data);config.ports=std::make_shared<Ports>(data);if(hook)config.hooks=std::make_shared<Hooks>(data);
        auto owner=n::Context::create(std::move(config));data.owner=owner;data.events.clear();
        const auto emit=[&](int index,n::Result result){std::cout<<"row "<<identity<<' '<<index;print(owner->snapshot());std::cout<<' '<<unsigned(result.status)<<' '<<result.return_defined<<' '<<result.returned<<' '<<data.events.size();
            for(const auto& event:data.events){std::cout<<' '<<event.kind;for(auto value:event.arguments)std::cout<<' '<<value;print(event.view);}std::cout<<'\n';};
        n::Result initial;initial.status=n::Status::completed;emit(-1,initial);
        unsigned operations{};if(!(std::cin>>operations))return 10;
        for(unsigned index=0;index<operations;++index){
            n::Input input;if(!(std::cin>>command>>input.value>>data.sample.numerator>>data.sample.denominator>>data.counter>>data.frequency>>data.status))return 11;
            data.events.clear();const auto result=owner->execute(command=="refresh"?n::Operation::refresh:n::Operation::buffer,input);emit(static_cast<int>(index),result);
            for(unsigned slot=0;slot<8;++slot)if(static_cast<std::uint32_t>(queues[slot]->queued_bytes(1))!=counts[slot])return 12;
        }
    }
    return std::cin.eof()?0:13;
}
