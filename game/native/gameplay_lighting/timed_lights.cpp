#include "timed_lights.hpp"
#include "../transform_math/transform_math.hpp"
#include <algorithm>
#include <bit>
#include <new>
namespace reo::native::gameplay_lighting {
namespace {
constexpr float value(std::uint32_t bits){return std::bit_cast<float>(bits);}
std::int16_t decrement(std::int16_t v)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(std::uint16_t(v)-1u));}
}
Definition timed_definition(const std::array<float,3>& position)noexcept{
    Definition d;d.vector0={1,0.5f,0,0};d.position=position;
    d.attenuation=value(0x3d4ccccd);d.parameter=150;return d;
}
bool advance_timed_light(TimedState& state,Definition& light,std::uint8_t mode){
    if(state.phase==3)return true;
    if(state.phase==0){
        state.phase=1;state.remaining=mode?22:44;state.wobble=mode?15:30;
        state.fade_remaining=mode?10:20;state.fade_duration=state.fade_remaining;
    }
    if(state.phase==1){
        state.wobble=decrement(state.wobble);if(state.wobble<0)state.wobble=mode?15:30;
        //370080 masks the input byte, multiplies by the authored pi/4 and
        // tail-calls192190/18F340 (sine), not an RNG helper.
        const auto index=std::uint16_t(state.wobble)&7u;
        const float angle=float(index)*value(0x3f490fdb);
        const float wave=transform_math::sin_cos(angle).sine;
        const float offset=value(0x3e99999a)*wave;
        light.vector0[0]=value(0x3f59999a)+offset;
        light.vector0[1]=value(0x3ed9999a)+offset;
        state.remaining=decrement(state.remaining);
        if(state.remaining<0){state.saved={light.vector0[0],light.vector0[1]};++state.phase;}
    }else if(state.phase==2){
        state.fade_remaining=decrement(state.fade_remaining);
        if(state.fade_remaining<0){++state.phase;return false;}
        const float ratio=float(state.fade_remaining)/float(state.fade_duration);
        light.vector0[0]=state.saved[0]*ratio;light.vector0[1]=state.saved[1]*ratio;
    }
    return false;
}
struct TimedLights::Shared {
    gameplay_world::World& world;gameplay_tasks::Scheduler& tasks;Pool& pool;
    struct Entry {gameplay_tasks::Handle handle;std::shared_ptr<TimedState> state;LightId light;};
    std::vector<Entry> entries;
    TimedStatus fault{TimedStatus::completed};bool closed{};
    Shared(gameplay_world::World& w,gameplay_tasks::Scheduler& t,Pool& p):world(w),tasks(t),pool(p){entries.reserve(gameplay_tasks::Scheduler::capacity);}
};
class TimedLights::Work final:public gameplay_tasks::Task {
    std::shared_ptr<Shared> owner_;gameplay_actors::EntityId actor_;
public:
    std::shared_ptr<TimedState> state;
    LightId light;
    Work(std::shared_ptr<Shared> owner,gameplay_actors::EntityId actor,std::shared_ptr<TimedState> s):owner_(std::move(owner)),actor_(std::move(actor)),state(std::move(s)){}
    ~Work()override{if(light)(void)owner_->pool.retire(light);}
    void update(gameplay_tasks::Scheduler& tasks,const gameplay_tasks::Handle& handle)noexcept override{
        const auto actor=owner_->world.resolve(actor_);
        if(owner_->closed||!actor||actor->primary!=2||actor->secondary!=11){(void)tasks.erase(handle);return;}
        const auto current=owner_->pool.retain(light);
        if(!current){owner_->fault=TimedStatus::light_unavailable;(void)tasks.erase(handle);return;}
        try{
            auto next=current->descriptor;
            if(advance_timed_light(*state,next,owner_->world.session().clock_mode)){(void)tasks.erase(handle);return;}
            if(owner_->pool.replace(light,next)!=Status::completed){owner_->fault=TimedStatus::light_unavailable;(void)tasks.erase(handle);}
        }catch(...){owner_->fault=TimedStatus::light_unavailable;(void)tasks.erase(handle);}
    }
};
TimedLights::TimedLights(gameplay_world::World& w,gameplay_tasks::Scheduler& t,Pool& p):shared_(std::make_shared<Shared>(w,t,p)){}
TimedLights::~TimedLights(){close();}
bool TimedLights::bound_to(const gameplay_world::World& w,const gameplay_tasks::Scheduler& t,const Pool& p)const noexcept{
    return !shared_->closed && &shared_->world==&w && &shared_->tasks==&t && &shared_->pool==&p;
}
TimedStatus TimedLights::failure()const noexcept{return shared_->fault;}
TimedCreated TimedLights::create(const gameplay_actors::EntityId& id,const std::array<float,3>& position)noexcept{
    auto& owner=*shared_;
    if(owner.closed||owner.world.closed()||owner.tasks.closed()||owner.pool.closed())return{TimedStatus::closed,gameplay_tasks::Status::closed,{},{}};
    const auto actor=owner.world.resolve(id);if(!actor)return{TimedStatus::actor_unavailable,gameplay_tasks::Status::invalid,{},{}};
    if(actor->primary!=2||actor->secondary!=11)return{TimedStatus::skipped,gameplay_tasks::Status::invalid,{},{}};
    if(!actor->lighting_tag)return{TimedStatus::tag_unavailable,gameplay_tasks::Status::invalid,{},{}};
    try{
        std::erase_if(owner.entries,[&](const auto& e){return !owner.tasks.contains(e.handle);});
        auto state=std::make_shared<TimedState>();auto work=std::make_shared<Work>(shared_,id,state);
        const auto task=owner.tasks.create(work);
        if(task.status!=gameplay_tasks::Status::completed){
            const auto result=task.status==gameplay_tasks::Status::full?TimedStatus::task_full:task.status==gameplay_tasks::Status::no_memory?TimedStatus::no_memory:TimedStatus::task_unavailable;
            return{result,task.status,{},{}};
        }
        const auto light=owner.pool.create(timed_definition(position),*actor->lighting_tag,0);
        if(light.status!=Status::completed){(void)owner.tasks.erase(task.handle);return{light.status==Status::full?TimedStatus::light_full:TimedStatus::light_unavailable,task.status,{},{}};}
        work->light=light.id;owner.entries.push_back({task.handle,std::move(state),light.id});
        return{TimedStatus::completed,task.status,task.handle,light.id};
    }catch(const std::bad_alloc&){return{TimedStatus::no_memory,gameplay_tasks::Status::no_memory,{},{}};}
}
std::optional<TimedSnapshot> TimedLights::snapshot(const gameplay_tasks::Handle& task)const noexcept{
    if(!shared_->tasks.contains(task))return{};
    for(const auto& e:shared_->entries)if(e.handle==task)return TimedSnapshot{*e.state,e.light};
    return{};
}
void TimedLights::close()noexcept{
    auto& owner=*shared_;if(owner.closed)return;owner.closed=true;
    for(const auto& e:owner.entries)(void)owner.tasks.erase(e.handle);
    owner.entries.clear();
}
}
