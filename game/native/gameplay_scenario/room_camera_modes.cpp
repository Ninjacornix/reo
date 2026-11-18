#include "room_camera_modes.hpp"
#include "room_scene_input.hpp"
#include "room_scene_owner.hpp"
#include "scene_controls.hpp"
#include "scene_model_bindings.hpp"
#include "sequence_control.hpp"
#include "lighting.hpp"
#include "fog.hpp"
#include "../gameplay_world/world.hpp"
#include "../gameplay_collision/response.hpp"
#include "../animation/model.hpp"
#include "../transform_math/direction_basis.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <exception>
#include <limits>
#include <stdexcept>
#include <vector>

namespace reo::native::gameplay_scenario {
namespace {
using Vector=transform_math::Vector;
using Matrix=transform_math::Matrix;
using Actor=gameplay_world::Actor;
Vector add(Vector a,Vector b)noexcept{return {a.x+b.x,a.y+b.y,a.z+b.z};}
Vector sub(Vector a,Vector b)noexcept{return {a.x-b.x,a.y-b.y,a.z-b.z};}
Vector translation(const Matrix& m)noexcept{return {m[3][0],m[3][1],m[3][2]};}
// 191430 normalizes each source axis twice, in that order; even a rotation
// matrix can differ by a float bit from its simple transpose.
Matrix source_inverse(const Matrix& m){
    Matrix out=transform_math::identity();std::array<float,3> q{};
    for(unsigned i=0;i<3;++i){const float x=m[i][0]*m[i][0],y=m[i][1]*m[i][1],z=m[i][2]*m[i][2];
        const float xy=x+y,length=xy+z;q[i]=length>0.f?1.f/std::sqrt(length):std::numeric_limits<float>::max();}
    for(unsigned col=0;col<3;++col)for(unsigned row=0;row<3;++row){
        const float normalized=q[row]*m[row][col];out[col][row]=normalized*q[row];
    }
    for(unsigned row=0;row<3;++row){
        const float x=(q[row]*m[row][0])*(-m[3][0]);
        const float y=(q[row]*m[row][1])*(-m[3][1]);
        const float z=(q[row]*m[row][2])*(-m[3][2]);
        out[3][row]=((x+y)+z)*q[row];
    }
    return out;
}
std::int16_t wrapped(std::int32_t n)noexcept{return std::bit_cast<std::int16_t>(std::uint16_t(n));}
constexpr std::array<Vector,4> eye_offsets{{{50,85,150},{-50,85,150},{50,85,-150},{-50,85,-150}}};
constexpr std::array<Vector,4> aim_offsets{{{50,0,0},{-50,0,0},{50,0,0},{-50,0,0}}};
constexpr std::array<Vector,4> light_offsets{{{73,170,133},{-73,170,133},{73,170,-133},{-73,170,-133}}};
constexpr std::array<std::int32_t,5> curve_time{0,2,4,6,-1};
constexpr std::array<std::uint32_t,5> curve_bits{0,0x3f8595c4u,0xbf8595c4u,0,0};
struct ProxyFields {std::uint32_t model{};std::uint8_t offset{};};
}
struct RoomCameraModes::Shared {
    gameplay_world::World& world;gameplay_tasks::Scheduler& tasks;SequenceControl& sequence;
    CameraParameters& camera;Lighting& lights;RoomSceneOwner& scene;SceneControls& controls;SceneModels& models;
    SceneModelBindings& bindings;std::shared_ptr<const RoomSceneInput> input;
    std::shared_ptr<const gameplay_collision::response::Grid> floors;
    std::vector<gameplay_tasks::Handle> handles;
    CameraModeStatus result{CameraModeStatus::completed};bool closed{},running{};
    Shared(gameplay_world::World& w,gameplay_tasks::Scheduler& t,SequenceControl& s,CameraParameters& c,
        Lighting& l,RoomSceneOwner& so,SceneControls& sc,SceneModels& sm,SceneModelBindings& sb,
        std::shared_ptr<const RoomSceneInput> in,std::shared_ptr<const gameplay_collision::response::Grid> f):
        world(w),tasks(t),sequence(s),camera(c),lights(l),scene(so),controls(sc),models(sm),bindings(sb),input(std::move(in)),floors(std::move(f)){
        handles.reserve(gameplay_tasks::Scheduler::capacity);
    }
    std::shared_ptr<Actor> actor()const noexcept{return world.primary(sequence.snapshot().actor);}
    std::optional<std::uint8_t> lookup(const Actor& a)const noexcept{
        if(!input||!scene.bound_to(*input,controls))return{};const auto id=a.scene_model.encoded();if(id>255)return{};
        const auto& table=input->mapping(0);for(unsigned i=0;i<16;++i)if(table[i]==id)return std::uint8_t(i);
        return std::uint8_t(255);
    }
    gameplay_scene::Records::Lease proxy(std::uint8_t id,std::optional<std::uint8_t> selector)const noexcept{
        if(!controls.enabled())return{};
        for(auto node=controls.records()->first();node;node=node->next){const auto& r=node->value;
            if(r.authored_id!=id)continue;
            if(std::holds_alternative<ControlTypeZero>(r.body))return node;
            if(const auto* two=std::get_if<ControlTypeTwo>(&r.body);two&&(!selector||two->selector==*selector))return node;
        }
        return{};
    }
    std::optional<std::uint8_t> offset(const gameplay_scene::Record& r)const noexcept{
        if(const auto* zero=std::get_if<ControlTypeZero>(&r.body))
            return zero->matrix_program?std::optional(std::uint8_t(zero->matrix_program->descriptor)):std::nullopt;
        if(const auto* two=std::get_if<ControlTypeTwo>(&r.body))return two->camera_offset;
        return{};
    }
    std::optional<ProxyFields> light_proxy(const Actor& a)const noexcept{
        const auto id=lookup(a);if(!id||!a.interaction_subselector)return{};
        const auto selector=*a.interaction_subselector;
        const auto node=proxy(*id,selector==255?std::nullopt:std::optional(selector));if(!node)return{};
        const auto& r=node->value;
        if(selector==255){
            const auto ix=offset(r);if(!ix)return{};
            if(const auto* zero=std::get_if<ControlTypeZero>(&r.body)){
                if(!zero->matrix_program)return{};return ProxyFields{zero->matrix_program->model_slot.encoded(),*ix};
            }
            if(const auto* two=std::get_if<ControlTypeTwo>(&r.body)){
                if(!two->camera_anchor)return{};return ProxyFields{*two->camera_anchor,*ix};
            }
        }else{
            if(const auto* zero=std::get_if<ControlTypeZero>(&r.body)){
                if(!zero->destination)return{};return ProxyFields{zero->destination->room,std::uint8_t(zero->destination->edge)};
            }
            if(const auto* two=std::get_if<ControlTypeTwo>(&r.body)){
                if(!two->model_reference)return{};return ProxyFields{two->model_reference->model.encoded(),std::uint8_t(two->model_reference->descriptor)};
            }
        }
        return{};
    }
    std::optional<Matrix> model(std::uint32_t slot){if(slot>=128)return{};return bindings.live_pose(std::uint8_t(slot));}
    void fail(CameraModeStatus value)noexcept{if(result==CameraModeStatus::completed)result=value;}
};
class RoomCameraModes::Work final:public gameplay_tasks::Task {
public:
    enum class Kind {tracking,light,vertical};
    std::shared_ptr<Shared> owner;Kind kind;std::uint8_t variant{},phase{};
    std::int16_t cursor{},segment{},counter{},duration{};float amplitude{};
    Matrix inverse{};Vector target{};LightHandle light;
    Work(std::shared_ptr<Shared> s,Kind k):owner(std::move(s)),kind(k){}
    ~Work()override{if(light)(void)owner->lights.release(light);}
    void retire(gameplay_tasks::Scheduler& scheduler,const gameplay_tasks::Handle& handle)noexcept{
        if(light){if(!owner->lights.release(light))owner->fail(CameraModeStatus::unavailable);light={};}
        (void)scheduler.erase(handle);
    }
    void update(gameplay_tasks::Scheduler& scheduler,const gameplay_tasks::Handle& handle)noexcept override{
        if(owner->closed){retire(scheduler,handle);return;}
        try{
            const auto mode=owner->sequence.snapshot().phase;
            if(kind==Kind::vertical){
                if(mode!=5){retire(scheduler,handle);return;}
                if(phase==0){counter=wrapped(std::int32_t(counter)-1);if(counter>=0)return;cursor=segment=counter=0;++phase;}
                if(phase!=1)return;
                if(variant!=0||segment<0||segment>=3){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}
                const auto i=std::size_t(segment);const auto first=std::bit_cast<float>(curve_bits[i]),last=std::bit_cast<float>(curve_bits[i+1]);
                const float value=((last-first)*float(std::int32_t(cursor)-curve_time[i])/float(curve_time[i+1]-curve_time[i])+first)*amplitude;
                owner->camera.pose.eye.y+=value;owner->camera.pose.aim.y+=value;cursor=wrapped(std::int32_t(cursor)+1);
                if(duration!=-1){counter=wrapped(std::int32_t(counter)+1);if(counter>=duration){retire(scheduler,handle);return;}}
                if(cursor>curve_time[i+1]){segment=wrapped(std::int32_t(segment)+1);if(curve_time[i+2]==-1)cursor=segment=0;}
                return;
            }
            if(!mode||(kind==Kind::tracking&&mode==4)){retire(scheduler,handle);return;}
            const auto actor=owner->actor();if(!actor){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}
            if(kind==Kind::tracking){
                if(variant==1&&(phase==0||phase==1)){
                    const bool entering=phase==0;if(entering)++phase;
                    if(!actor->model||actor->model->nodes().size()<=3){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}
                    const auto point=actor->model->world_translation(3);
                    auto rotation=transform_math::identity();transform_math::reset_euler_axes(rotation,{0,std::uint16_t(actor->orientation[1]),0});
                    const Vector offset{0,60,actor->class_marker==2?-78.f:-90.f};
                    if(entering){target=add(point,{0,10,0});inverse=source_inverse(rotation);owner->camera.pose.aim=target;
                        owner->camera.lens=60;owner->camera.pose.roll=0;}
                    else{auto local=transform_math::direction(inverse,sub(point,target));local.x=local.y=0;owner->camera.pose.aim=add(target,transform_math::direction(rotation,local));}
                    owner->camera.pose.eye=add(owner->camera.pose.aim,transform_math::direction(rotation,offset));
                }else if(variant==2&&phase==0){
                    ++phase;
                    const auto id=owner->lookup(*actor);const auto node=id?owner->proxy(*id,std::nullopt):nullptr;
                    const auto index=node?owner->offset(node->value):std::nullopt;
                    const auto slot=actor->scene_model.slot();auto matrix=slot?owner->model(*slot):std::nullopt;
                    if(!index||*index>=eye_offsets.size()||!matrix){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}
                    auto center=translation(*matrix);center.y+=95.f*actor->model_scale.y;
                    owner->camera.pose.eye=add(center,transform_math::direction(*matrix,eye_offsets[*index]));
                    owner->camera.pose.aim=add(center,transform_math::direction(*matrix,aim_offsets[*index]));
                    owner->camera.lens=60;owner->camera.pose.roll=0;
                }
                auto& session=owner->world.session();session.resource_hide_selected=0;session.resource_hide_others=1;session.resource_hide_remaining={1,1};
                return;
            }
            if(phase!=0)return;
            const auto fields=owner->light_proxy(*actor);auto matrix=fields?owner->model(fields->model):std::nullopt;
            if(!fields||fields->offset>=light_offsets.size()||!matrix||!owner->floors){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}
            const auto position=add(translation(*matrix),transform_math::direction(*matrix,light_offsets[fields->offset]));
            const auto floor=owner->floors->floor({position.x,position.y,position.z},255);
            LightDescriptor definition;definition.vector0={.35f,.35f,.35f,0};definition.position={position.x,position.y,position.z};
            definition.attenuation=std::bit_cast<float>(0x3ba3d70au);definition.parameter=250;
            if(const auto slot=owner->lights.allocate(&definition,floor.material,4)){
                const auto owned=owner->lights.handle(*slot);if(!owned){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);return;}light=*owned;
            }
            ++phase;
        }catch(...){owner->fail(CameraModeStatus::unavailable);retire(scheduler,handle);}
    }
};
RoomCameraModes::RoomCameraModes(gameplay_world::World& world,gameplay_tasks::Scheduler& tasks,SequenceControl& sequence,
    CameraParameters& camera,Lighting& lights,RoomSceneOwner& scene,SceneControls& controls,SceneModels& models,SceneModelBindings& bindings,
    std::shared_ptr<const RoomSceneInput> input,std::shared_ptr<const gameplay_collision::response::Grid> floors):
    shared_(std::make_shared<Shared>(world,tasks,sequence,camera,lights,scene,controls,models,bindings,std::move(input),std::move(floors))){
    if(world.closed()||tasks.closed()||!bindings.bound_to(models)||!shared_->input||!scene.bound_to(*shared_->input,controls)||!shared_->floors)
        throw std::invalid_argument("Canonical room camera owners required");
}
RoomCameraModes::~RoomCameraModes(){if(close()==CameraModeStatus::busy)std::terminate();}
CameraModeStatus RoomCameraModes::status()const noexcept{return shared_->closed?CameraModeStatus::closed:shared_->result;}
bool RoomCameraModes::bound_to(const gameplay_world::World& world)const noexcept{
    return !shared_->closed&&!shared_->world.closed()&&&shared_->world==&world;
}
CameraModeStatus RoomCameraModes::close()noexcept{
    auto& s=*shared_;if(s.closed)return CameraModeStatus::completed;if(s.running||!s.tasks.idle())return CameraModeStatus::busy;
    s.closed=true;for(const auto& handle:s.handles)if(s.tasks.contains(handle))(void)s.tasks.erase(handle);s.handles.clear();return CameraModeStatus::completed;
}
CameraModeStatus RoomCameraModes::update(std::size_t loaded,Fog& fog,CameraDisplayBinding& display)noexcept{
    auto& s=*shared_;if(s.closed||s.world.closed()||s.tasks.closed())return CameraModeStatus::closed;
    if(s.running||!s.tasks.idle())return CameraModeStatus::busy;if(s.result!=CameraModeStatus::completed)return s.result;
    s.running=true;struct Reset{bool& running;~Reset(){running=false;}}reset{s.running};
    try{
        std::erase_if(s.handles,[&](const auto& h){return !s.tasks.contains(h);});
        auto state=s.sequence.snapshot();
        const auto commit=[&]{if(!s.sequence.restore(state))throw std::runtime_error("Camera sequence profile unavailable");};
        const auto normal=[&]{commit();RoomCamera ordinary(s.sequence,s.camera);const auto result=ordinary.update(s.world,s.models,loaded,fog,display);
            state=s.sequence.snapshot();return result==RoomCameraStatus::completed?CameraModeStatus::completed:result==RoomCameraStatus::unsupported_numeric?CameraModeStatus::unsupported_numeric:CameraModeStatus::unavailable;};
        const auto spawn=[&](Work::Kind kind,std::uint8_t variant,std::int16_t delay,std::int16_t duration,float amplitude){
            try{auto task=std::make_shared<Work>(shared_,kind);task->variant=variant;task->counter=delay;task->duration=duration;task->amplitude=amplitude;
                const auto created=s.tasks.create(task);if(created.status!=gameplay_tasks::Status::completed)return false;s.handles.push_back(created.handle);return true;
            }catch(const std::bad_alloc&){return false;}
        };
        if(state.phase==1||state.phase==2){
            const auto actor=s.world.primary(state.actor);if(!actor)return CameraModeStatus::unavailable;
            const bool eligible=actor->motion_class==10||(state.phase==1&&actor->motion_class==58);
            if(state.phase==1){
                if(state.restart_byte==0){if(!eligible)return normal();++state.restart_byte;}
                if(state.restart_byte==1){if(!eligible){state.phase=0;return normal();}
                    if(spawn(Work::Kind::tracking,1,0,0,0)){(void)spawn(Work::Kind::light,0,0,0,0);state.condition_id=255;++state.restart_byte;}
                    else state.phase=0;
                }else if(state.restart_byte==2&&!eligible){state.phase=0;return normal();}
            }else{
                if(state.restart_byte==0){++state.restart_byte;const auto status=normal();if(status!=CameraModeStatus::completed)return status;}
                if(state.restart_byte==1&&eligible){
                    if(spawn(Work::Kind::tracking,2,0,0,0)){(void)spawn(Work::Kind::light,0,0,0,0);state.condition_id=255;++state.restart_byte;}
                    else state.phase=0;
                }else if(state.restart_byte==2&&!eligible){state.phase=0;return normal();}
            }
            commit();display.publish(s.camera);return CameraModeStatus::completed;
        }
        if(state.phase==3){
            if(state.selection){if(state.selected_id>=state.active.size())return CameraModeStatus::unavailable;
                state.active[state.selected_id]=0;state.selected_id=255;state.selection=0;state.phase=0;return normal();}
            display.publish(s.camera);state.phase=0;commit();return CameraModeStatus::completed;
        }
        if(state.phase==4){
            if(!state.selection){state.phase=0;state.condition_id=255;return normal();}
            s.world.selected_frame_marker=1;
            if(state.selection!=0xffff&&state.selection!=0xfffe)--state.selection;
            if(state.selection!=0xfffe){const auto actor=s.world.primary(state.actor);
                if(!actor){commit();return CameraModeStatus::unavailable;}
                if(actor->status&0x20000u)state.selection=0;
            }
            if(!state.selection){if(state.selected_id>=state.active.size()){commit();return CameraModeStatus::unavailable;}
                state.active[state.selected_id]=0;state.selected_id=255;state.phase=0;}
            return normal();
        }
        if(state.phase==5){
            if(state.restart_byte==0){
                if(spawn(Work::Kind::vertical,state.mode,std::bit_cast<std::int16_t>(state.parameter_a),std::bit_cast<std::int16_t>(state.parameter_b),state.fraction))++state.restart_byte;
                else state.phase=0;
            }
            return normal();
        }
        return normal();
    }catch(...){return CameraModeStatus::unavailable;}
}
}
