#define REO_TIMING_FIXTURE_SUPPORT_ONLY
#include "fixture.cpp"
#include "video_frames.hpp"
struct ReadySurface final:n::FrameSurface {
    n::FrameStatus ready()noexcept override{return n::FrameStatus::completed;}
    n::FrameStatus submit()noexcept override{return n::FrameStatus::completed;}
    n::FrameStatus retire()noexcept override{return n::FrameStatus::completed;}
    void drain()noexcept override{}
};
void clock_words(const n::View& view,bool full){auto words=n::testing::project(view);if(!full)words.erase(words.begin()+296,words.begin()+298);for(auto word:words)std::cout<<' '<<word;}
int main(){
    std::string command;Data data;data.events.reserve(128);unsigned identity{};
    while(std::cin>>command){
        bool full{};n::Config config;auto guard=std::make_shared<n::selected::GuardState>();std::uint32_t hooks{},end{},count{};
        if(command!="begin" || !(std::cin>>identity>>full))return 2;
        for(auto field:facts)if(!(std::cin>>config.facts.*field))return 3;
        if(!(std::cin>>config.frequency>>hooks>>guard->depth>>guard->tag>>end>>count) || count>16)return 4;
        std::vector<n::Picture> pictures(count);for(auto& picture:pictures)if(!(std::cin>>picture.state>>picture.references>>picture.time.numerator>>picture.time.denominator))return 5;
        config.audio=std::make_shared<Audio>(data);config.helper=std::make_shared<Helper>(data);config.ports=std::make_shared<Ports>(data);config.guard=guard;if(hooks)config.hooks=std::make_shared<Hooks>(data);
        auto owner=n::Context::create(std::move(config));data.owner=owner;auto pool=std::make_unique<n::PicturePool>(pictures);std::shared_ptr<n::VideoFrames> frames;std::vector<n::FrameKey> keys;
        if(full){frames=n::VideoFrames::create(owner,count);for(const auto& picture:pictures){auto slot=frames->reserve();if(slot.status!=n::FrameStatus::completed)return 6;keys.push_back(slot.key);if(frames->publish(slot.key,picture.time,std::make_shared<ReadySurface>(),picture.state==4)!=n::FrameStatus::completed)return 7;}if(frames->end(end)!=n::FrameStatus::completed)return 8;}
        const auto emit=[&](int index,std::int64_t returned,std::uint32_t flag){std::cout<<"row "<<identity<<' '<<index;clock_words(owner->snapshot(),full);
            const auto state=full?frames->snapshot():n::FrameSnapshot{};
            const auto emit_picture=[&](const n::Picture& p){std::cout<<' '<<p.state<<' '<<p.references<<' '<<0<<' '<<p.time.numerator<<' '<<p.time.denominator;};
            if(full){for(unsigned i=0;i<count;++i)emit_picture(state.pictures[i]);for(unsigned i=0;i<count;++i)std::cout<<' '<<state.borrowed[i];std::cout<<' '<<state.current;}
            else for(const auto& picture:pool->pictures())emit_picture(picture);
            std::size_t events{};for(const auto& event:data.events)events+=full || (event.kind!=6 && event.kind!=7);
            std::cout<<' '<<returned<<' '<<flag<<' '<<events;
            for(const auto& event:data.events){if(!full && (event.kind==6 || event.kind==7))continue;std::cout<<' '<<event.kind;for(auto word:event.arguments)std::cout<<' '<<word;clock_words(event.view,full);}std::cout<<'\n';};
        data.events.clear();emit(-1,0,0);unsigned operations{};if(!(std::cin>>operations))return 9;
        for(unsigned index=0;index<operations;++index){int slot{};n::Input input;n::Updates patch;
            if(!(std::cin>>command>>slot>>input.value>>data.sample.numerator>>data.sample.denominator>>data.counter>>data.frequency>>data.status) || !read_updates(patch))return 10;
            if(owner->observe(patch)!=n::Status::completed)return 11;
            data.events.clear();std::int64_t returned{};std::uint32_t flag{};
            if(command=="get"){
                auto value=frames->acquire();returned=-1;if(value.status==n::FrameStatus::completed){const auto state=frames->snapshot();returned=state.current;}
                else if(value.status!=n::FrameStatus::held && value.status!=n::FrameStatus::empty)return 12;
            }else if(command=="public_release"){if(frames->release(keys.at(slot))!=n::FrameStatus::completed)return 13;}
            else if(command=="skip"){const auto value=frames->skip_if_due();if(value.status!=n::FrameStatus::completed && value.status!=n::FrameStatus::empty)return 14;returned=value.decision;}
            else if(command=="pause" || command=="tick"){const auto result=owner->execute(command=="pause"?n::Operation::pause:n::Operation::tick,input);if(result.status!=n::Status::completed)return 15;returned=result.returned;}
            else if(command=="reserve")returned=pool->reserve();
            else if(command=="front"){
                if(full){const auto value=frames->peek();returned=-1;flag=value.last;for(unsigned i=0;i<keys.size();++i)if(value.status==n::FrameStatus::completed && value.key==keys[i])returned=i;}
                else{const auto value=pool->select(end);returned=value.first;flag=value.last;}
            }
            else if(command=="advance"){const auto value=pool->can_advance(*owner);if(value.status!=n::Status::completed)return 16;returned=value.returned!=0;}
            else if(command=="release")pool->release(slot);
            else if(command=="demote")pool->demote(slot);
            else return 17;
            emit(static_cast<int>(index),returned,flag);
        }
    }
    return std::cin.eof()?0:18;
}
