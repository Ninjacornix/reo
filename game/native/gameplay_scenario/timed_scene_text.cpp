#include "timed_scene_text.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <bit>
#include <exception>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::int16_t text_id(std::uint16_t id)noexcept{return std::bit_cast<std::int16_t>(id);}
bool supported_lines(const SceneTextLines& lines)noexcept{
    return std::all_of(lines.lines.begin(),lines.lines.end(),[](auto text){return text.size()<=128;});
}
}
struct TimedSceneText::Shared:std::enable_shared_from_this<Shared> {
    struct Pending final:gameplay_tasks::Task {
        std::weak_ptr<Shared> owner;TimedTextRequest request;std::uint8_t stage{};bool published{};
        Pending(std::weak_ptr<Shared> value,TimedTextRequest input):owner(std::move(value)),request(input){}
        void update(gameplay_tasks::Scheduler& tasks,const gameplay_tasks::Handle& handle)noexcept override{
            const auto state=owner.lock();
            if(!state||state->closed){(void)tasks.erase(handle);return;}
            state->update(*this,handle);
        }
    };
    gameplay_world::World& world;SceneTextBank& bank;gameplay_tasks::Scheduler& tasks;
    TextCache& cache;const gameplay_world::InventoryUi& inventory;
    const gameplay_session::ApplicationLifecycle& lifecycle;
    std::array<std::weak_ptr<Pending>,gameplay_tasks::Scheduler::capacity> owned;
    std::array<gameplay_tasks::Handle,gameplay_tasks::Scheduler::capacity> handles;
    gameplay_tasks::Handle current;std::optional<std::uint8_t> priority;
    TimedTextStatus fault{TimedTextStatus::completed};bool running{},closed{};
    Shared(gameplay_world::World& w,SceneTextBank& b,gameplay_tasks::Scheduler& t,TextCache& c,
        const gameplay_world::InventoryUi& i,const gameplay_session::ApplicationLifecycle& l):
        world(w),bank(b),tasks(t),cache(c),inventory(i),lifecycle(l){}
    bool bound()const noexcept{return !closed&&!world.closed()&&bank.bound_to(world.session())&&inventory.bound_to(world);}
    bool erase(const TimedTextRequest& input)noexcept{
        const auto lines=bank.message_lines(text_id(input.id),input.text_kind);if(!lines||!cache.initialized())return false;
        for(const auto text:lines->lines)if(cache.erase(text)!=TextCacheStatus::completed)return false;
        return true;
    }
    bool draw_ready(const TimedTextRequest& input)const noexcept{
        if(!cache.initialized()||!lifecycle.inventory_filter_enabled())return false;
        const auto lines=bank.message_lines(text_id(input.id),input.text_kind);const auto cues=bank.message_cues(text_id(input.id),input.text_kind);
        if(!lines||!supported_lines(*lines)||!cues)return false;
        return std::all_of(cues->begin(),cues->end(),[](auto cue){return cue==0xffffu||(cue&0x7fffu)<AuxiliaryScene::timer_count;});
    }
    bool ready(TimedTextRequest input)const noexcept{
        if(!bound()||running||tasks.closed()||fault!=TimedTextStatus::completed)return false;
        const auto active=bank.priority().active();if(!active)return false;
        if(*active){
            if(!priority)return false;
            if(*priority<input.priority)return true; //57018C rejects the new lower priority before reading text.
            if(const auto old=std::find(handles.begin(),handles.end(),current);old!=handles.end()&&tasks.contains(current)){
                const auto task=owned[std::size_t(old-handles.begin())].lock();
                if(!task||!bank.message_lines(text_id(task->request.id),task->request.text_kind)||!cache.initialized())return false;
            }
        }
        // The actual EVB startup queues132 before1D4020 loads its bank.
        // Decode/cache/UI capabilities are checked by the later real callback.
        return text_id(input.id)>=0&&(input.text_kind==0||
            (input.text_kind==2&&bank.message_lines(text_id(input.id),input.text_kind).has_value()))&&
            lifecycle.inventory_filter_enabled().has_value();
    }
    bool draw(Pending& task)noexcept{
        if(!draw_ready(task.request))return false;
        const auto lines=bank.message_lines(text_id(task.request.id),task.request.text_kind);const auto cues=bank.message_cues(text_id(task.request.id),task.request.text_kind);
        const auto filtered=*lifecycle.inventory_filter_enabled();
        std::optional<bool> suppressed=false;
        if(filtered&&task.request.priority<6)suppressed=inventory.dialogue_suppressed();
        if(!suppressed)return false;
        if(!*suppressed){
            std::int32_t y=380;
            for(const auto text:lines->lines){
                task.published=true;
                const auto result=cache.request(task.request.priority,64,y,task.request.duration,24,text,0);
                if(result.status!=TextCacheStatus::completed)return false;
                y=std::bit_cast<std::int32_t>(std::uint32_t(y)+22u);
            }
        }
        //6B9F30 invokes6BA190 after the complete multiline draw, including a
        // suppressed draw. These bits share the existing auxiliary timer owner.
        for(const auto cue:*cues)if(cue!=0xffffu)
            if(!world.session().auxiliary_scene.set_timer(cue&0x7fffu,bool(cue&0x8000u)))return false;
        return true;
    }
    bool immediate_line(std::span<const std::byte> text,std::int32_t x,std::int32_t y,std::uint32_t duration)noexcept{
        if(!cache.initialized()||text.size()>128)return false;
        const auto filtered=lifecycle.inventory_filter_enabled();if(!filtered)return false;
        if(*filtered){const auto suppressed=inventory.dialogue_suppressed();if(!suppressed)return false;if(*suppressed)return true;}
        return cache.request(0,x,y,std::uint16_t(duration),24,text,0).status==TextCacheStatus::completed;
    }
    bool yes_no(std::uint32_t duration)noexcept{
        const auto yes=bank.choice_text(0);if(!yes||!immediate_line(*yes,392,408,duration))return false;
        const auto no=bank.choice_text(1);return no&&immediate_line(*no,464,408,duration);
    }
    void update(Pending& task,const gameplay_tasks::Handle& handle)noexcept{
        if(fault!=TimedTextStatus::completed)return;
        if(running){fault=TimedTextStatus::busy;return;}
        running=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running};
        const auto active=bank.priority().active();
        if(!bound()||!active){fault=TimedTextStatus::unavailable;return;}
        if(!*active||world.session().inventory_owner){
            //6B68B4 hardcodes the room-message bank (kind0), even when this
            // task drew a system message. Replacement5701C4 instead retains
            // its kind. System cache records then await the real expire pass.
            auto cancelled=task.request;cancelled.text_kind=0;
            if(!erase(cancelled)){fault=TimedTextStatus::unavailable;return;}
            bank.priority().reset_active();task.stage=2;
        }
        if(task.stage==2){
            if(tasks.erase(handle)!=gameplay_tasks::Status::completed)fault=TimedTextStatus::unavailable;
            return;
        }
        if(task.stage==0){
            if(task.request.delay){task.request.delay=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(task.request.delay)-1u));return;}
            if(!draw(task)){fault=TimedTextStatus::unavailable;return;}
            ++task.stage;
        }
        if(task.stage==1){
            task.request.duration=std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(task.request.duration)-1u));
            if(task.request.duration<=0){++task.stage;bank.priority().reset_active();}
        }
    }
};
TimedSceneText::TimedSceneText(gameplay_world::World& world,SceneTextBank& bank,gameplay_tasks::Scheduler& tasks,
    TextCache& cache,const gameplay_world::InventoryUi& inventory,const gameplay_session::ApplicationLifecycle& lifecycle):
    state_(std::make_shared<Shared>(world,bank,tasks,cache,inventory,lifecycle)){
    if(!state_->bound()||tasks.closed())throw std::invalid_argument("Canonical timed scene text owners unavailable or foreign");
}
TimedSceneText::~TimedSceneText(){if(close()==TimedTextStatus::busy)std::terminate();}
bool TimedSceneText::bound_to(const gameplay_world::World& world)const noexcept{return &world==&state_->world&&state_->bound();}
bool TimedSceneText::busy()const noexcept{return state_->running||!state_->tasks.idle();}
bool TimedSceneText::ready(std::uint16_t id)const noexcept{return state_->ready(TimedTextRequest{id});}
TimedTextStatus TimedSceneText::request(std::uint16_t id)noexcept{return request(TimedTextRequest{id});}
TimedTextStatus TimedSceneText::request(TimedTextRequest input)noexcept{
    auto& state=*state_;
    if(state.closed)return TimedTextStatus::closed;
    if(state.running)return TimedTextStatus::busy;
    input.text_kind=std::uint8_t(input.text_kind); //5701F8 masks before task storage.
    if(!state.ready(input))return TimedTextStatus::unavailable;
    state.running=true;struct Reset{bool& value;~Reset(){value=false;}}reset{state.running};
    const auto active=*state.bank.priority().active();
    if(active){
        if(*state.priority<input.priority)return TimedTextStatus::completed;
        const auto old=std::find(state.handles.begin(),state.handles.end(),state.current);
        if(old!=state.handles.end()&&state.tasks.contains(state.current)){
            const auto task=state.owned[std::size_t(old-state.handles.begin())].lock();
            if(task){
                if(!state.erase(task->request))return TimedTextStatus::unavailable;
                task->stage=2;state.bank.priority().reset_active();
            }
        }
    }
    try{
        const auto free=std::find_if(state.handles.begin(),state.handles.end(),[&](const auto& handle){return !state.tasks.contains(handle);});
        if(free==state.handles.end())return TimedTextStatus::completed;
        auto task=std::make_shared<Shared::Pending>(state_,input);
        const auto created=state.tasks.create(task);
        if(created.status==gameplay_tasks::Status::full)return TimedTextStatus::completed;
        if(created.status==gameplay_tasks::Status::no_memory)return TimedTextStatus::no_memory;
        if(created.status!=gameplay_tasks::Status::completed)return TimedTextStatus::unavailable;
        const auto slot=std::size_t(free-state.handles.begin());state.handles[slot]=created.handle;state.owned[slot]=task;
        state.current=created.handle;state.priority=input.priority;state.bank.priority().publish_active(1);
        return TimedTextStatus::completed;
    }catch(...){return TimedTextStatus::no_memory;}
}
TimedTextSnapshot TimedSceneText::snapshot()const noexcept{
    const auto& state=*state_;std::size_t count{};
    for(const auto& handle:state.handles)count+=state.tasks.contains(handle);
    return{state.bank.priority().active(),state.priority,count,state.fault};
}
TimedTextStatus TimedSceneText::show_yes_no(std::uint32_t duration)noexcept{
    auto& state=*state_;if(state.closed)return TimedTextStatus::closed;
    if(state.running)return TimedTextStatus::busy;
    if(!state.bound())return TimedTextStatus::unavailable;
    state.running=true;struct Reset{bool& value;~Reset(){value=false;}}reset{state.running};
    return state.yes_no(duration)?TimedTextStatus::completed:TimedTextStatus::unavailable;
}
TimedTextStatus TimedSceneText::show_choice_prompt(std::uint32_t message,std::uint32_t duration)noexcept{
    auto& state=*state_;if(state.closed)return TimedTextStatus::closed;
    if(state.running)return TimedTextStatus::busy;
    if(!state.bound())return TimedTextStatus::unavailable;
    state.running=true;struct Reset{bool& value;~Reset(){value=false;}}reset{state.running};
    const auto question=state.bank.choice_question(message);if(!question)return TimedTextStatus::unavailable;
    if(question->enabled){
        std::int32_t y=380;
        for(const auto& line:question->lines){
            if(line&&!state.immediate_line(*line,80,y,duration))return TimedTextStatus::unavailable;
            y+=28;
        }
        if(message>32767)return TimedTextStatus::unavailable;
        const auto cues=state.bank.message_cues(std::int16_t(message));if(!cues)return TimedTextStatus::unavailable;
        for(const auto cue:*cues)if(cue!=0xffffu)
            if(!state.world.session().auxiliary_scene.set_timer(cue&0x7fffu,bool(cue&0x8000u)))return TimedTextStatus::unavailable;
    }
    return state.yes_no(duration)?TimedTextStatus::completed:TimedTextStatus::unavailable;
}
TimedTextStatus TimedSceneText::close()noexcept{
    auto& state=*state_;if(state.closed)return TimedTextStatus::completed;
    if(busy()||state.world.busy())return TimedTextStatus::busy;
    TimedTextStatus result=TimedTextStatus::completed;
    for(unsigned i=0;i<state.handles.size();++i)if(state.tasks.contains(state.handles[i])){
        const auto task=state.owned[i].lock();
        // Native graph teardown retires unpublished work without fabricating
        //6B6880's asset-reading cancellation callback before catalog delivery.
        if(task&&task->published&&!state.erase(task->request))result=TimedTextStatus::unavailable;
        if(state.tasks.erase(state.handles[i])!=gameplay_tasks::Status::completed)result=TimedTextStatus::unavailable;
    }
    if(state.bank.priority().active())state.bank.priority().reset_active();
    state.closed=true;return result;
}
}
