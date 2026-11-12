#include "periodic_visuals.hpp"
#include "../gameplay_contact_world/contacts.hpp"
#include "../gameplay_world/resource_models.hpp"
#include "../gameplay_world/resource_factory.hpp"
#include "../gameplay_collision/trace.hpp"
#include "resource_flight_queries.hpp"
#include <algorithm>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>
namespace reo::native::gameplay_effects {
namespace {
bool finite(transform_math::Vector value){return std::isfinite(value.x)&&std::isfinite(value.y)&&std::isfinite(value.z);}
std::int16_t add(std::int16_t value,std::int16_t delta){return std::bit_cast<std::int16_t>(std::uint16_t(std::int32_t(value)+delta));}
transform_math::Matrix inverse_camera(const transform_math::Matrix& camera){
    transform_math::require_profile();auto result=transform_math::identity();std::array<float,3> reciprocal;
    for(unsigned c=0;c<3;++c){
        const float xx=camera[c][0]*camera[c][0],yy=camera[c][1]*camera[c][1],zz=camera[c][2]*camera[c][2];
        const float xy=xx+yy,length=std::sqrt(xy+zz);
        if(!std::isfinite(length)||length==0)throw std::domain_error("Native effect camera basis unavailable");
        reciprocal[c]=1.f/length;
    }
    for(unsigned c=0;c<3;++c)for(unsigned r=0;r<3;++r)result[c][r]=reciprocal[r]*camera[r][c];
    const transform_math::Vector negative{0.f-camera[3][0],0.f-camera[3][1],0.f-camera[3][2]};
    const auto offset=transform_math::direction(result,negative);
    result[3][0]=offset.x;result[3][1]=offset.y;result[3][2]=offset.z;
    for(unsigned c=0;c<4;++c)for(unsigned r=0;r<3;++r){result[c][r]=result[c][r]*reciprocal[r];if(!std::isfinite(result[c][r]))throw std::domain_error("Native effect camera finite profile");}
    return result;
}
}
std::shared_ptr<const EffectBank> EffectBank::import(std::span<const std::byte> nbd,std::span<const std::byte> efdata){
    auto bank=std::shared_ptr<EffectBank>(new EffectBank);bank->geometry_=Geometry::import_nbd(nbd);bank->tracks_=Tracks::import(efdata);bank->materials_=MaterialTracks::import(efdata,*bank->geometry_);
    for(std::uint16_t i=0;i<3;++i){
        const auto logical=std::uint16_t(36+i);const auto root=bank->geometry_->resolve(std::int16_t(logical));const auto selected=bank->tracks_->resolve(logical,0);
        if(!root||!selected)throw std::invalid_argument("Required periodic effect resource/group unavailable");
        const auto* group=bank->tracks_->group(*selected);if(!group||group->parts.size()>16)throw std::invalid_argument("Periodic effect child extent unavailable");
        auto& binding=bank->periodic_[i];binding.group=*selected;binding.pieces.reserve(group->parts.size());
        for(const auto& part:group->parts){
            const auto child_root=bank->geometry_->resolve(part.resource);
            if(!child_root)throw std::invalid_argument("Required periodic child geometry unavailable");
            const auto* mesh=bank->geometry_->material(*child_root,part.material);
            if(part.selector&&(part.selector>group->parts.size()||!mesh||!bank->materials_->complete(*mesh)))throw std::invalid_argument("Required periodic material/transform profile unavailable");
            const auto ordinal=mesh?std::size_t(mesh-bank->geometry_->meshes().data()):0;
            binding.pieces.push_back({*child_root,ordinal,part.material,part.selector});
        }
    }
    return bank;
}
const VisualBinding* EffectBank::periodic(std::uint16_t descriptor)const noexcept{
    return descriptor>=36&&descriptor<=38?&periodic_[descriptor-36]:nullptr;
}
VisualBinding EffectBank::bind(std::uint16_t descriptor,std::int16_t variant)const{
    const auto root=geometry_->resolve(std::bit_cast<std::int16_t>(descriptor));
    const auto selected=tracks_->resolve(descriptor,variant);
    if(!root||!selected)throw std::invalid_argument("Native effect resource/group unavailable");
    const auto* group=tracks_->group(*selected);
    if(!group||group->parts.size()>16)throw std::invalid_argument("Native effect child extent unavailable");
    VisualBinding binding;binding.group=*selected;binding.pieces.reserve(group->parts.size());
    for(const auto& part:group->parts){
        const auto child_root=geometry_->resolve(part.resource);
        if(!child_root)throw std::invalid_argument("Native effect child geometry unavailable");
        const auto* mesh=geometry_->material(*child_root,part.material);
        if(part.selector&&(part.selector>group->parts.size()||!mesh||!materials_->complete(*mesh)))
            throw std::invalid_argument("Native effect material/transform profile unavailable");
        const auto ordinal=mesh?std::size_t(mesh-geometry_->meshes().data()):0;
        binding.pieces.push_back({*child_root,ordinal,part.material,part.selector});
    }
    return binding;
}
transform_math::Vector toward_camera(transform_math::Vector position,transform_math::Vector camera,float distance){
    transform_math::require_profile();
    if(!finite(position)||!finite(camera)||!std::isfinite(distance))throw std::domain_error("Native effect finite camera profile required");
    const transform_math::Vector direction{camera.x-position.x,camera.y-position.y,camera.z-position.z};
    const float x=direction.x*direction.x,y=direction.y*direction.y,z=direction.z*direction.z;
    const float xy=x+y,squared=xy+z;const float length=std::sqrt(squared);
    const float reciprocal=length==0?std::numeric_limits<float>::max():1.f/length;
    const transform_math::Vector normal{direction.x*reciprocal,direction.y*reciprocal,direction.z*reciprocal};
    const float dx=normal.x*distance,dy=normal.y*distance,dz=normal.z*distance;
    const transform_math::Vector result{position.x+dx,position.y+dy,position.z+dz};
    if(!finite(direction)||!std::isfinite(squared)||!finite(normal)||!finite(result))throw std::domain_error("Native effect camera arithmetic exceeds finite profile");
    return result;
}
struct PeriodicVisuals::Node final:gameplay_scenario::PeriodicVisual {
    struct Trail {InheritedTrailState state;InheritedTrailRequest binding;};
    struct ProjectileTrail {ProjectileTrailState state;gameplay_world::World* world{};std::shared_ptr<gameplay_world::Actor> parent;gameplay_actors::EntityId parent_id;std::uint8_t variant{};std::size_t root{};};
    std::optional<ProjectileTrail> projectile;
    struct SurfaceFollower {SurfaceFollowerVisual state;gameplay_world::World* world{};std::shared_ptr<gameplay_world::Actor> parent;gameplay_actors::EntityId parent_id;};
    std::optional<SurfaceFollower> surface_follower;

    std::optional<Trail> trail;
    std::shared_ptr<const EffectBank> bank;
    std::uint16_t descriptor{};
    std::uint8_t phase{};
    std::int16_t age{};
    bool visible{},live{true};
    std::vector<std::uint16_t> pieces;
    bool periodic{true};
    WorkUpdate update{WorkUpdate::ordinary};
    std::uint8_t lifecycle{};
    std::uint32_t flags{};
    std::uint16_t attributes{};
    std::int16_t oriented_angle{};
    std::array<std::int16_t,3> angles{};
    transform_math::Vector uniform{1,1,1},parameters208{1,1,1};
    transform_math::Vector additional_offset;
    float feedback_scale{},camera_offset{};
    float opacity{1}; // actual652F00 default;652F90 also establishes1.
    std::optional<std::uint8_t> particle_mode;
    std::optional<transform_math::Matrix> basis;
    VisualBinding binding;
    std::optional<gameplay_scenario::FogPulse> pulse;
    std::optional<SurfaceState> surface;
    std::optional<ResourceCompanionState> resource_companion;
    std::optional<ResourceDebrisState> resource_debris;
    std::optional<ResourceFlightState> resource_flight;
    gameplay_actors::EntityId flight_parent;
    std::optional<ActorContactState> actor_contact;
    gameplay_actors::EntityId channel_parent;
    std::shared_ptr<gameplay_world::ResourceModel> resource_model;
    std::optional<std::uint8_t> category;
    gameplay_actors::EntityId surface_actor;
};
class PeriodicVisuals::ProjectileOperations final:public ProjectileTrailEmission {
public:
    explicit ProjectileOperations(PeriodicVisuals& owner):owner_(owner){}
    WorkStatus emit(const WorkRequest& request)override{return owner_.create_impl(request,true).status;}
private:PeriodicVisuals& owner_;
};
struct PeriodicVisuals::CompanionRuntime {
    gameplay_world::World& world;gameplay_scenario::SceneResources& resources;gameplay_world::ResourceModels& models;const gameplay_scenario::ResourceTemplates& templates;ResourceCompanionActions& actions;
};
struct PeriodicVisuals::DebrisRuntime {
    gameplay_world::World& world;gameplay_world::ResourceModels& models;
    std::weak_ptr<gameplay_world::ResourceFactoryToken> factory;
};
struct PeriodicVisuals::SurfaceRuntime {
    std::shared_ptr<gameplay_world::World> world;
    gameplay_contact_world::RoomResources* rooms;
    Modulation* modulation;
    SurfaceProfile profile;
};
struct PeriodicVisuals::FlightRuntime {
    gameplay_world::World& world;gameplay_contact_world::RoomResources& rooms;
    FlightAudio& audio;
};
struct PeriodicVisuals::ChannelRuntime {
    gameplay_world::World& world;ActorContactPoses& poses;
};
class PeriodicVisuals::ChannelOperations final:public ActorContactOperations {
public:
    PeriodicVisuals& owner;Node& node;transform_math::Vector camera;const std::optional<transform_math::Matrix>& view;VisualReport& report;
    ChannelOperations(PeriodicVisuals& o,Node& n,transform_math::Vector c,const std::optional<transform_math::Matrix>& v,VisualReport& r):owner(o),node(n),camera(c),view(v),report(r){}
    bool rebind(ActorContactState& state)override{return owner.channels_&&owner.channels_->poses.rebind(node.channel_parent,state);}
    WorkStatus clone(const ActorContactState& state,std::uint32_t variant)override{
        return owner.create_actor_contact_impl(node.channel_parent,state.basis,state.base_position,state.mode,variant,true).status;
    }
    bool sample(const ActorContactState& state)override{
        node.basis=state.basis;node.initial_position=state.base_position;
        owner.sample_children(node,state.age,camera,view,report);return true;
    }
};
class PeriodicVisuals::SurfaceSink final:public SurfaceVisuals {
    PeriodicVisuals& owner_;
public:
    explicit SurfaceSink(PeriodicVisuals& owner):owner_(owner){}
    bool bound_to(const gameplay_session::Random& random)const noexcept override{return owner_.bound_to(random);}
    WorkStatus emit_surface(const SurfaceEmission& request)noexcept override{return owner_.emit_surface_impl(request,true);}
};
struct PeriodicVisuals::Editing {PeriodicVisuals* owner;};
class PeriodicVisuals::Edit final:public WorkEdit,public ParticleEdit {
    std::weak_ptr<Editing> owner_;std::shared_ptr<Node> node_;gameplay_actors::EntityId id_;
    PeriodicVisuals* active()const noexcept {
        const auto token=owner_.lock();if(!token||!node_->live)return nullptr;
        auto* owner=token->owner;
        return owner&&!owner->closed_&&!owner->busy_&&owner->entities_.acquire(id_)==node_?owner:nullptr;
    }
public:
    Edit(std::weak_ptr<Editing> owner,std::shared_ptr<Node> node,gameplay_actors::EntityId id):owner_(std::move(owner)),node_(std::move(node)),id_(std::move(id)){}
    gameplay_actors::EntityId identity()const noexcept override{return id_;}
    bool uniform_scale(float value)noexcept override {if(!active()||!std::isfinite(value))return false;node_->uniform={value,value,value};return true;}
    bool third_angle(std::int16_t value)noexcept override {if(!active())return false;node_->angles[2]=value;return true;}
    bool add_attributes(std::uint16_t value)noexcept override {if(!active())return false;node_->attributes|=value;return true;}
    bool set_attributes(std::uint16_t value)noexcept override {if(!active())return false;node_->attributes=value;return true;}
    bool feedback(transform_math::Vector value,float scalar)noexcept override {
        auto* owner=active();if(!owner||!finite(value)||!std::isfinite(scalar))return false;
        node_->flags|=0x40;node_->parameters208=value;node_->opacity=1;node_->feedback_scale=scalar;node_->attributes|=0x100;
        for(const auto slot:node_->pieces){auto& output=owner->pieces_[slot].output;output.flags|=0x40;output.parameters208=value;}
        return true;
    }
    bool configure_particle(std::uint8_t mode,std::int16_t delay,const std::array<float,6>& policy)noexcept override{
        if(!active()||node_->periodic||!std::all_of(policy.begin(),policy.end(),[](float v){return std::isfinite(v);}))return false;
        node_->category=13;node_->particle_mode=mode;node_->delay=delay;
        if(policy[0]!=1.f){node_->attributes=4;node_->uniform={policy[0],policy[0],policy[0]};}
        else node_->attributes=0; // Source does not reset old scale values here.
        return policy[1]==0.f||feedback({policy[2],policy[3],policy[4]},policy[5]);
    }
};
class PeriodicVisuals::TrailOperations final:public InheritedTrailOperations {
    PeriodicVisuals& owner_;Node& node_;Node::Trail& trail_;
    transform_math::Vector camera_;const std::optional<transform_math::Matrix>& view_;VisualReport& report_;
    bool current()const noexcept{
        const auto& b=trail_.binding;
        return b.world&&!b.world->closed()&&owner_.bound_to(b.world->session().random)&&b.world->resolve(b.parent)&&b.world->resolve(b.motion);
    }
public:
    TrailOperations(PeriodicVisuals& owner,Node& node,transform_math::Vector camera,const std::optional<transform_math::Matrix>& view,VisualReport& report)
        :owner_(owner),node_(node),trail_(*node.trail),camera_(camera),view_(view),report_(report){}
    std::optional<float> floor(transform_math::Vector point)override{
        const auto& b=trail_.binding;if(!current()||!b.rooms)return{};
        const auto number=b.world->room;const auto room=b.rooms->retain(number);const auto id=room?room->identity():gameplay_contact_world::RoomId{};
        if(!room||!id||room->room_number()!=number||!room->current(id)||!current()||b.world->room!=number)return{};
        const auto sampled=room->geometry().floors.floor({point.x,point.y,point.z},255);
        return current()&&b.world->room==number&&room->current(id)?std::optional(sampled.height):std::nullopt;
    }
    bool contact_cue(transform_math::Vector point)override{
        const auto& b=trail_.binding;return current()&&b.actions&&b.actions->bound_to(*b.world)&&b.actions->cue(b.parent,point)&&current();
    }
    bool contact_burst(transform_math::Vector point)override{
        const auto& b=trail_.binding;return current()&&b.actions&&b.actions->bound_to(*b.world)&&b.actions->burst(b.parent,point)&&current();
    }
    WorkCreated impact(const WorkRequest& request)override{return current()?owner_.create_impl(request,true):WorkCreated{};}
    bool configure_impact(const WorkCreated& created,transform_math::Vector color,transform_math::Vector scale)override{
        if(!current()||!created.edit||!finite(color)||!finite(scale))return false;
        const auto node=std::static_pointer_cast<Node>(owner_.entities_.acquire(created.edit->identity()));
        if(!node||!node->live||node->periodic)return false;
        node->flags|=0x40;node->parameters208=color;node->opacity=1;node->uniform=scale;
        for(const auto slot:node->pieces){auto& piece=owner_.pieces_[slot].output;piece.flags|=0x40;piece.parameters208=color;}
        return true;
    }
    bool sample(const InheritedTrailState& state)override{
        if(!current())return false;
        node_.initial_position=state.previous_position;node_.uniform=state.scale;
        node_.angles={state.angles[0],state.angles[1],state.angles[2]};
        node_.attributes=state.attributes;node_.feedback_scale=state.feedback_scale;
        owner_.sample_children(node_,state.age,camera_,view_,report_);
        for(unsigned i=0;i<node_.pieces.size();++i){
            auto& piece=owner_.pieces_[node_.pieces[i]].output;
            const auto& mesh=node_.bank->geometry().meshes()[node_.binding.pieces[i].mesh];
            for(std::size_t channel=0;channel<mesh.indices.size();++channel)piece.parameters.rotation[2]=add(piece.parameters.rotation[2],state.rotation_offset);
        }
        return true;
    }
};
PeriodicVisuals::PeriodicVisuals(std::shared_ptr<const EffectBank> bank):bank_(std::move(bank)){
    if(!bank_)throw std::invalid_argument("Native periodic visuals require admitted owned assets");
    editing_=std::make_shared<Editing>(Editing{this});
}
PeriodicVisuals::PeriodicVisuals(std::shared_ptr<const EffectBank> bank,gameplay_session::Random& random):PeriodicVisuals(std::move(bank)){random_=&random;}
PeriodicVisuals::PeriodicVisuals(std::shared_ptr<const EffectBank> bank,gameplay_session::Random& random,gameplay_scenario::Fog& fog):PeriodicVisuals(std::move(bank),random){fog_=&fog;}
PeriodicVisuals::~PeriodicVisuals(){close();}
std::shared_ptr<const EffectFrame> PeriodicVisuals::retain()const noexcept{
    std::lock_guard lock(publication_);return published_;
}
void PeriodicVisuals::publish(std::shared_ptr<const EffectFrame> frame)noexcept{
    // Destruction of an old frame/resource lease occurs after unlocking.
    {std::lock_guard lock(publication_);published_.swap(frame);}
}
bool PeriodicVisuals::admitted()const noexcept{return !closed_&&failure_==VisualStatus::completed;}
bool PeriodicVisuals::bound_to(const gameplay_session::Random& random)const noexcept{return admitted()&&random_==&random;}
bool PeriodicVisuals::bound_to(const gameplay_world::World& world)const noexcept{
    if(!admitted()||world.closed()||!surfaces_||surfaces_->world.get()!=&world||!bound_to(world.session().random))return false;
    const auto count=world.session().primary_population;
    if(!count||*count>gameplay_world::World::primary_capacity)return false;
    for(std::uint32_t i=0;i<*count;++i)if(!world.primary(i))return false;
    return true;
}
bool PeriodicVisuals::bind_surfaces(std::shared_ptr<gameplay_world::World> world,gameplay_contact_world::RoomResources& rooms,Modulation& modulation,SurfaceProfile profile)noexcept{
    if(!world||surfaces_||busy_||!admitted()||!bound_to(world->session().random)||(debris_&&&debris_->world!=world.get())||(flights_&&&flights_->world!=world.get())||(channels_&&&channels_->world!=world.get()))return false;
    try{surfaces_=std::make_unique<SurfaceRuntime>(SurfaceRuntime{std::move(world),&rooms,&modulation,std::move(profile)});return true;}
    catch(const std::bad_alloc&){return false;}
}
bool PeriodicVisuals::configure_surface(std::uint32_t selector,const std::array<std::uint32_t,4>& words)noexcept{
    if(selector!=1)return admitted()&&!busy_;
    if(busy_||!surfaces_||!bound_to(*surfaces_->world))return false;
    (void)surfaces_->modulation->configure(selector,words);
    return create_surface_work().status!=WorkStatus::unavailable;
}
PeriodicVisuals::SurfaceCreated PeriodicVisuals::create_surface_work()noexcept{
    SurfaceCreated result;
    if(busy_||!surfaces_||!bound_to(*surfaces_->world))return result;
    result.status=WorkStatus::completed;
    const auto count=*surfaces_->world->session().primary_population;
    for(std::uint32_t i=0;i<count;++i){
        ++result.attempted;
        if(entities_.size()==168){result.status=WorkStatus::pool_full;continue;}
        gameplay_actors::EntityId id;
        try{
            auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->surface.emplace();node->surface_actor=surfaces_->world->identity(i);
            const auto created=entities_.create(std::move(node));
            if(created.status!=gameplay_actors::EntityStatus::completed){result.status=created.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable;if(result.status==WorkStatus::unavailable)return result;continue;}
            id=created.id;order_.push_front(id);result.identities[i]=id;++result.created;
        }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;result.status=WorkStatus::unavailable;return result;}
    }return result;
}
std::optional<SurfaceState> PeriodicVisuals::surface_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node?node->surface:std::optional<SurfaceState>{};
}
bool PeriodicVisuals::companions_bound_to(const gameplay_world::World& world,const gameplay_scenario::SceneResources& resources,const gameplay_world::ResourceModels& models,const gameplay_scenario::ResourceTemplates& templates)const noexcept{
    return admitted()&&companions_ && &companions_->world==&world && &companions_->resources==&resources && &companions_->models==&models&&bound_to(world.session().random)&&&companions_->templates==&templates&&companions_->actions.bound_to(world,resources,models,templates);
}
bool PeriodicVisuals::bind_resource_companions(gameplay_world::World& world,gameplay_scenario::SceneResources& resources,gameplay_world::ResourceModels& models,const gameplay_scenario::ResourceTemplates& templates,ResourceCompanionActions& actions)noexcept{
    if(busy_||companions_||!bound_to(world.session().random)||!actions.bound_to(world,resources,models,templates)||(debris_&&(&debris_->world!=&world||&debris_->models!=&models))||(flights_&&&flights_->world!=&world)||(channels_&&&channels_->world!=&world))return false;
    try{companions_=std::make_unique<CompanionRuntime>(CompanionRuntime{world,resources,models,templates,actions});return true;}
    catch(const std::bad_alloc&){return false;}
}
std::optional<ResourceCompanionState> PeriodicVisuals::resource_companion_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node?node->resource_companion:std::nullopt;
}
PeriodicVisuals::CompanionsCreated PeriodicVisuals::create_resource_companions(const gameplay_actors::EntityId& model_id,std::int8_t argument)noexcept{
    CompanionsCreated result;
    if(busy_||!companions_||!companions_bound_to(companions_->world,companions_->resources,companions_->models,companions_->templates))return result;
    const auto model=companions_->models.retain(model_id);if(!model||!model->current())return result;
    struct Request {std::uint16_t effect;std::uint32_t child_mask;transform_math::Vector offset;std::uint8_t subtype;std::uint16_t attributes;};
    const auto value=[](std::uint32_t bits){return std::bit_cast<float>(bits);};
    std::array<Request,2> requests{};std::size_t count=1;
    switch(model->content_id){
    case 0x72:requests[0]={0x27,0,{0,value(0x4195999a),0},0,1};break;
    case 0x3200:requests[0]={0x7f,0xffff,{0,-1,0},6,1};break;
    case 0x1c:requests[0]={0x44,0,{0,value(0x4121999a),value(0x40b66666)},3,0xe};break;
    case 0x1d:requests[0]={0x40,0,{0,value(0x41233333),3.5f},4,0x15};requests[1]={0x3f,32,{0,value(0x4121999a),value(0x40b66666)},3,0x4e};count=2;break;
    case 0x135:requests[0]={0x43,0,{0,value(0x4121999a),value(0x40b66666)},3,0xe};break;
    case 0x75:requests[0]={0x91,0,{value(0xc258999a),value(0xc01851ec),0},5,0xa5};break;
    default:result.status=WorkStatus::completed;return result;
    }
    auto basis=transform_math::identity();for(unsigned c=0;c<3;++c)for(unsigned r=0;r<3;++r)basis[c][r]=model->pose[c][r];
    result.status=WorkStatus::completed;
    for(std::size_t i=0;i<count;++i){
        ++result.attempted;const auto& request=requests[i];
        //5DF450 passes a2 as the child-enable mask and t0 as variant0.
        const auto made=create_impl({basis,request.offset,0,request.effect,request.child_mask,0x1a193,WorkUpdate::scaled},false);
        if(made.status!=WorkStatus::completed){result.status=made.status;if(made.status==WorkStatus::unavailable)return result;continue;}
        const auto node=std::static_pointer_cast<Node>(entities_.acquire(made.edit->identity()));
        node->resource_model=model;node->resource_companion.emplace();auto& state=*node->resource_companion;
        state.content=model->content_id;state.position=request.offset;state.basis=basis;state.subtype=request.subtype;state.attributes=request.attributes;
        state.remaining=state.loop_lifetime=node->remaining;
        if(model->content_id==0x3200&&!argument){state.age=state.remaining;state.remaining=2;}
        if(model->content_id==0x75)state.camera_offset=10;
        if(i+1==count)node->category=0x1c;
        result.identities[i]=made.edit->identity();++result.created;
    }
    return result;
}
bool PeriodicVisuals::bind_resource_debris(gameplay_world::World& world,gameplay_world::ResourceModels& models,gameplay_world::ResourceFactory& factory)noexcept{
    if(!admitted()||busy_||debris_||world.closed()||!models.open()||!bound_to(world.session().random)||!factory.bound_to(world,models))return false;
    if((companions_&&(&companions_->world!=&world||&companions_->models!=&models))||(surfaces_&&surfaces_->world.get()!=&world)||(flights_&&&flights_->world!=&world)||(channels_&&&channels_->world!=&world))return false;
    try{debris_=std::make_unique<DebrisRuntime>(DebrisRuntime{world,models,factory.token_});return true;}catch(...){return false;}
}
bool PeriodicVisuals::debris_bound_to(const gameplay_world::World& world,const gameplay_world::ResourceModels& models,const gameplay_world::ResourceFactory& factory)const noexcept{
    if(!admitted()||!debris_||world.closed()||!models.open()||&debris_->world!=&world||&debris_->models!=&models||!bound_to(world.session().random))return false;
    const auto token=debris_->factory.lock();return token&&token->owner==&factory&&factory.bound_to(world,models);
}
std::optional<ResourceDebrisState> PeriodicVisuals::resource_debris_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node?node->resource_debris:std::nullopt;
}
PeriodicVisuals::DebrisPiece PeriodicVisuals::create_resource_debris_piece(const gameplay_actors::EntityId& model_id,std::uint32_t part,std::uint32_t full_effect)noexcept{
    if(!admitted()||busy_||!debris_||debris_->world.closed()||!bound_to(debris_->world.session().random))return{};
    const auto effect=std::uint16_t(full_effect);
    if(!bank_->geometry().resolve(std::bit_cast<std::int16_t>(effect)))return{WorkStatus::resource_missing,{}};
    if(entities_.size()==168)return{WorkStatus::pool_full,{}};
    if(effect>=512)return{};
    const auto token=debris_->factory.lock();if(!token||!token->owner||!debris_bound_to(debris_->world,debris_->models,*token->owner))return{};
    const auto model=debris_->models.retain(model_id);if(!model||!model->current()||part>=4)return{};
    gameplay_actors::EntityId id;
    try{
        auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->descriptor=effect;node->category=0x1b;node->flags=0x8193;node->resource_debris.emplace();auto& state=*node->resource_debris;
        state.part=std::uint8_t(part);state.effect=effect;
        for(unsigned c=0;c<3;++c)for(unsigned r=0;r<3;++r){const auto v=model->pose[c][r];if(!std::isfinite(v))throw std::domain_error("Native resource debris finite model basis required");state.basis[c][r]=v;}
        static constexpr std::array<transform_math::Vector,4> offsets{{{-60,0,0},{-40,0,0},{0,0,0},{0,0,0}}};
        const auto offset=transform_math::direction(model->pose,offsets[part]);state.initial_position={model->pose[3][0]+offset.x,model->pose[3][1]+offset.y,model->pose[3][2]+offset.z};
        if(!finite(state.initial_position))throw std::domain_error("Native resource debris finite model position required");
        const auto created=entities_.create(std::move(node));if(created.status!=gameplay_actors::EntityStatus::completed)return{created.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable,{}};
        id=created.id;order_.push_front(id);return{WorkStatus::completed,id};
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return{};}catch(...){if(id)retire_node(id);return{};}
}
PeriodicVisuals::CompanionsCreated PeriodicVisuals::create_resource_debris(const gameplay_actors::EntityId& model_id)noexcept{
    CompanionsCreated result;if(!admitted()||busy_||!debris_)return result;
    const auto model=debris_->models.retain(model_id);if(!model||!model->current())return result;
    struct Request{unsigned part,effect;};std::array<Request,2> requests{};unsigned count=1;
    switch(model->content_id){case 0x6e:requests[0]={0,0xbf};break;case 0x6a:case 0x6f:requests[0]={1,0xc0};break;case 0x74:requests[0]={2,0x5a};requests[1]={3,0x5b};count=2;break;default:result.status=WorkStatus::completed;return result;}
    result.status=WorkStatus::completed;
    for(unsigned i=0;i<count;++i){++result.attempted;const auto made=create_resource_debris_piece(model_id,requests[i].part,requests[i].effect);if(made.status!=WorkStatus::completed){result.status=made.status;if(made.status==WorkStatus::unavailable)return result;continue;}result.identities[i]=made.id;++result.created;}
    return result;
}
PeriodicVisuals::ProjectileTrailCreated PeriodicVisuals::create_projectile_trail(gameplay_world::World& world,const gameplay_actors::EntityId& parent_id,std::uint8_t variant)noexcept{
    if(closed_||busy_||!admitted()||world.closed()||!bound_to(world.session().random))return{};
    const auto parent=world.resolve(parent_id);if(!parent||!parent->pose_work||parent->pose_work->kind!=15)return{};
    const auto root=bank_->geometry().resolve(0x12);if(!root)return{WorkStatus::resource_missing,{}};
    if(entities_.size()==168)return{WorkStatus::pool_full,{}};
    gameplay_actors::EntityId id;
    try{
        auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->descriptor=0x12;node->category=6;node->flags=0x8193;node->visible=false;
        node->projectile.emplace();auto& state=*node->projectile;state.world=&world;state.parent=parent;state.parent_id=parent_id;state.variant=variant;state.root=*root;state.state.basis=parent->pose_work->basis;
        const auto made=entities_.create(std::move(node));if(made.status!=gameplay_actors::EntityStatus::completed)return{made.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable,{}};
        id=made.id;order_.push_front(id);return{WorkStatus::completed,id};
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return{};}
    catch(const std::exception&){if(id)retire_node(id);failure_=VisualStatus::invalid_profile;return{};}
}
std::optional<ProjectileTrailOutput> PeriodicVisuals::projectile_trail_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(!node||!node->projectile)return{};
    return ProjectileTrailOutput{node->projectile->state,node->projectile->root,node->flags};
}
PeriodicVisuals::SurfaceFollowerCreated PeriodicVisuals::create_surface_follower_visual(gameplay_world::World& world,const gameplay_actors::EntityId& parent_id)noexcept{
    if(closed_||busy_||!admitted()||world.closed()||!bound_to(world.session().random))return{};
    const auto parent=parent_id?world.resolve(parent_id):nullptr;if(parent_id&&!parent)return{};
    if(entities_.size()==168)return{WorkStatus::pool_full,{}};
    gameplay_actors::EntityId id;
    try{
        auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->category=7;node->visible=false;
        node->surface_follower.emplace();auto& binding=*node->surface_follower;binding.world=&world;binding.parent=parent;binding.parent_id=parent_id;
        const auto made=entities_.create(std::move(node));if(made.status!=gameplay_actors::EntityStatus::completed)return{made.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable,{}};
        id=made.id;order_.push_front(id);return{WorkStatus::completed,id};
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return{};}
    catch(const std::exception&){if(id)retire_node(id);failure_=VisualStatus::invalid_profile;return{};}
}
std::optional<SurfaceFollowerVisual> PeriodicVisuals::surface_follower_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node&&node->surface_follower?std::optional(node->surface_follower->state):std::nullopt;
}
bool PeriodicVisuals::position_surface_follower_visual(const gameplay_actors::EntityId& id,transform_math::Vector point)noexcept{
    if(closed_||busy_||!finite(point))return false;
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(!node||!node->surface_follower)return false;
    node->surface_follower->state.position=point;return true;
}
WorkCreated PeriodicVisuals::create(const WorkRequest& request)noexcept{
    return create_impl(request,false);
}
std::optional<ParticleSnapshot> PeriodicVisuals::particle_state(const gameplay_actors::EntityId& id)const noexcept{
    if(closed_)return{};
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(!node||!node->particle_mode||!node->category)return{};
    ParticleSnapshot result;result.category=*node->category;result.mode=*node->particle_mode;result.delay=node->delay;result.attributes=node->attributes;result.scale=node->uniform;result.parameters208=node->parameters208;result.opacity=node->opacity;result.feedback_scale=node->feedback_scale;result.flags=node->flags;result.child_count=node->pieces.size();
    if(node->trail){const auto& state=node->trail->state;result.delay=state.delay;result.attributes=state.attributes;result.scale=state.scale;result.feedback_scale=state.feedback_scale;}
    for(std::size_t i=0;i<node->pieces.size();++i){const auto& piece=pieces_[node->pieces[i]].output;result.children[i]={piece.flags,piece.parameters208};}
    return result;
}
std::optional<InheritedTrailState> PeriodicVisuals::inherited_trail_state(const gameplay_actors::EntityId& id)const noexcept{
    if(closed_)return{};
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node&&node->trail?std::optional(node->trail->state):std::nullopt;
}
InheritedTrailBatch PeriodicVisuals::create_inherited_trails(const InheritedTrailRequest& request)noexcept{
    InheritedTrailBatch result;
    if(busy_||!admitted()||!request.world||request.world->closed()||!request.rooms||!bound_to(request.world->session().random)||(request.actions&&!request.actions->bound_to(*request.world)))return result;
    const auto parent=request.world->resolve(request.parent),motion=request.world->resolve(request.motion);
    if(!parent)return result;
    std::optional<unsigned> policy;
    switch(parent->slot){case 7:policy=3;break;case 10:case 30:policy=0;break;case 19:policy=1;break;case 29:policy=2;break;default:result.status=WorkStatus::completed;return result;}
    if(!motion||!motion->pose_work)return result;
    const auto position=request.point.value_or(transform_math::Vector{motion->position.x,motion->position.y,motion->position.z});
    if(!finite(position)||!finite(motion->pose_work->velocity)||!finite(motion->pose_work->acceleration))return result;
    constexpr std::array<std::uint16_t,4> resources{0x86,0x86,0x7c,0x86};
    constexpr std::array<unsigned,4> spacing{2,1,3,2};
    constexpr std::array<std::array<float,6>,4> parameters{{{{.6f,1,.95f,1,.7f,1}},{{.5f,1,.6f,.6f,.45f,.8f}},{{1,0,1,1,1,1}},{{.6f,1,.6f,.6f,.45f,.8f}}}};
    result.status=WorkStatus::completed;
    for(unsigned i=0;i<5;++i){
        ++result.attempted;WorkRequest work;work.position=position;work.effect=resources[*policy];work.update=WorkUpdate::scaled;
        const auto made=create_impl(work,false);
        if(made.status!=WorkStatus::completed){result.status=made.status;if(made.status==WorkStatus::unavailable)return result;continue;}
        const auto edit=std::dynamic_pointer_cast<ParticleEdit>(made.edit);if(!edit||!edit->configure_particle(1,std::bit_cast<std::int16_t>(std::uint16_t(request.delay)),parameters[*policy])){result.status=WorkStatus::unavailable;return result;}
        const auto node=std::static_pointer_cast<Node>(entities_.acquire(made.edit->identity()));if(!node){result.status=WorkStatus::unavailable;return result;}
        InheritedTrailState state;state.ordinal=std::uint8_t(i);state.parent_type=parent->slot;state.position=position;state.previous_position=node->initial_position;state.velocity=motion->pose_work->velocity;state.acceleration=motion->pose_work->acceleration;state.angles=motion->orientation;state.scale=node->uniform;state.feedback_scale=node->feedback_scale;state.attributes=node->attributes;state.delay=add(node->delay,int(spacing[*policy]*i));state.remaining=node->remaining;state.age=node->age;
        node->trail=Node::Trail{state,request};result.identities[i]=made.edit->identity();++result.created;
    }
    return result;
}
bool PeriodicVisuals::bind_resource_flights(gameplay_world::World& world,gameplay_contact_world::RoomResources& rooms,FlightAudio& audio)noexcept{
    if(!admitted()||busy_||flights_||world.closed()||!bound_to(world.session().random)||!audio.bound_to(world))return false;
    if((surfaces_&&surfaces_->world.get()!=&world)||(companions_&&&companions_->world!=&world)||(debris_&&&debris_->world!=&world)||(channels_&&&channels_->world!=&world))return false;
    try{flights_=std::make_unique<FlightRuntime>(FlightRuntime{world,rooms,audio});return true;}catch(...){return false;}
}
bool PeriodicVisuals::flights_bound_to(const gameplay_world::World& world)const noexcept{
    return admitted()&&flights_&&&flights_->world==&world&&!world.closed()&&bound_to(world.session().random)&&flights_->audio.bound_to(world);
}
std::optional<ResourceFlightState> PeriodicVisuals::resource_flight_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node?node->resource_flight:std::nullopt;
}
PeriodicVisuals::DebrisPiece PeriodicVisuals::create_resource_flight(const gameplay_actors::EntityId& parent,const transform_math::Matrix& basis,std::uint32_t style)noexcept{
    if(busy_||!flights_||!flights_bound_to(flights_->world))return{};
    gameplay_actors::EntityId id;
    try{
        const auto profile=resource_flight_profile(style);if(!profile)return{WorkStatus::completed,{}};
        if(!flights_->world.resolve(parent))return{};
        if(!bank_->geometry().resolve(std::bit_cast<std::int16_t>(profile->effect)))return{WorkStatus::resource_missing,{}};
        if(entities_.size()==168)return{WorkStatus::pool_full,{}};
        const auto state=prepare_resource_flight(basis,style);if(!state)return{};
        auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->descriptor=profile->effect;
        node->category=7;node->flags=0x8193;node->resource_flight=*state;node->flight_parent=parent;
        const auto made=entities_.create(std::move(node));
        if(made.status!=gameplay_actors::EntityStatus::completed)return{made.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable,{}};
        id=made.id;order_.push_front(id);return{WorkStatus::completed,id};
    }catch(...){if(id)retire_node(id);return{};}
}
bool PeriodicVisuals::bind_actor_contacts(gameplay_world::World& world,ActorContactPoses& poses)noexcept{
    if(!admitted()||busy_||channels_||world.closed()||!bound_to(world.session().random)||!poses.bound_to(world))return false;
    if((surfaces_&&surfaces_->world.get()!=&world)||(companions_&&&companions_->world!=&world)||(debris_&&&debris_->world!=&world)||(flights_&&&flights_->world!=&world)||(channels_&&&channels_->world!=&world))return false;
    try{channels_=std::make_unique<ChannelRuntime>(ChannelRuntime{world,poses});return true;}catch(...){return false;}
}
bool PeriodicVisuals::channels_bound_to(const gameplay_world::World& world)const noexcept{
    return admitted()&&channels_&&&channels_->world==&world&&!world.closed()&&bound_to(world.session().random)&&channels_->poses.bound_to(world);
}
WorkStatus PeriodicVisuals::actor_channel(const gameplay_actors::EntityId& parent,const std::optional<transform_math::Matrix>& basis,transform_math::Vector point,std::uint32_t mode,std::uint32_t variant){return create_actor_contact(parent,basis,point,mode,variant).status;}
PeriodicVisuals::DebrisPiece PeriodicVisuals::create_actor_contact(const gameplay_actors::EntityId& parent,const std::optional<transform_math::Matrix>& basis,transform_math::Vector point,std::uint32_t mode,std::uint32_t variant)noexcept{return create_actor_contact_impl(parent,basis,point,mode,variant,false);}
std::optional<ActorContactState> PeriodicVisuals::actor_contact_state(const gameplay_actors::EntityId& id)const noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));return node?node->actor_contact:std::nullopt;
}
PeriodicVisuals::DebrisPiece PeriodicVisuals::create_actor_contact_impl(const gameplay_actors::EntityId& parent,const std::optional<transform_math::Matrix>& basis,transform_math::Vector point,std::uint32_t mode,std::uint32_t variant,bool internal)noexcept{
    if(!channels_||!channels_bound_to(channels_->world)||(busy_&&!internal)||!channels_->world.resolve(parent))return{};
    const auto profile=actor_contact_profile(mode,variant);if(!profile)return{};
    const auto made=create_impl({basis,point,profile->variant,profile->resource,profile->child_mask,0x1a193,WorkUpdate::ordinary},internal);
    if(made.status!=WorkStatus::completed||!made.edit)return{made.status,{}};
    const auto id=made.edit->identity();const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(!node)return{};
    ActorContactState state;state.mode=std::uint8_t(mode);state.clone=(variant&0x80000000u)!=0;/*652470 clears cycle after571EC0 stores the caller variant.*/state.remaining=node->remaining;state.basis=basis;state.base_position=point;
    node->category=9;node->channel_parent=parent;node->actor_contact=state;return{WorkStatus::completed,id};
}
WorkCreated PeriodicVisuals::create_impl(const WorkRequest& request,bool internal)noexcept{
    if(!admitted()||(busy_&&!internal))return{};
    if(!bank_->geometry().resolve(std::bit_cast<std::int16_t>(request.effect)))return{WorkStatus::resource_missing,{}};
    if(request.effect>=512)return{};
    if(!request.position||!finite(*request.position)||(request.flags!=0x1a193&&request.flags!=0x1a993&&request.flags!=0x9a993))return{};
    if(request.update==WorkUpdate::oriented&&!random_)return{};
    if(request.variant==-1&&bank_->tracks().variants(request.effect)>0&&!random_)return{};
    if(entities_.size()==168)return{WorkStatus::pool_full,{}};
    gameplay_actors::EntityId id;
    try{
        auto node=std::make_unique<Node>();node->periodic=false;node->bank=bank_;node->descriptor=request.effect;
        node->initial_position=*request.position;node->basis=request.basis;node->flags=request.flags|0xa000u;node->update=request.update;
        const auto created=entities_.create(std::move(node));
        if(created.status!=gameplay_actors::EntityStatus::completed)return{created.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable,{}};
        id=created.id;auto value=std::static_pointer_cast<Node>(entities_.acquire(id));order_.push_front(id);
        auto variant=request.variant;
        if(variant==-1){variant=bank_->tracks().variants(request.effect);if(variant>0)variant=std::int16_t(random_->request(1)%std::uint16_t(variant));}
        value->binding=bank_->bind(request.effect,variant);
        value->remaining=bank_->tracks().group(value->binding.group)->lifetime;value->pieces.reserve(value->binding.pieces.size());
        for(std::size_t i=0;i<value->binding.pieces.size();++i){
            const auto& part=value->binding.pieces[i];
            const auto free=std::find_if(pieces_.begin(),pieces_.end(),[](const auto& piece){return !piece.active;});if(free==pieces_.end())break;
            const auto slot=std::uint16_t(free-pieces_.begin());free->output={};free->output.root=part.root;free->output.mesh=part.mesh;free->output.material=part.material;
            free->output.flags=value->flags;if(!(request.child_mask&(std::uint32_t(1)<<i)))free->output.flags|=0x800;
            free->active=true;value->pieces.push_back(slot);++piece_count_;
        }
        return{WorkStatus::completed,std::make_shared<Edit>(editing_,std::move(value),id)};
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return{};}
    catch(const std::exception&){if(id)retire_node(id);return{};}
}
WorkStatus PeriodicVisuals::emit_surface(const SurfaceEmission& request)noexcept{return emit_surface_impl(request,false);}
WorkStatus PeriodicVisuals::emit_surface_impl(const SurfaceEmission& request,bool internal)noexcept{
    if(!finite(request.scale)||!finite(request.color)||!std::isfinite(request.intensity)||
       request.work.update!=WorkUpdate::scaled)return WorkStatus::unavailable;
    const auto created=create_impl(request.work,internal);if(created.status!=WorkStatus::completed)return created.status;
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(created.edit->identity()));
    if(!node)return WorkStatus::unavailable;
    node->uniform=request.scale;node->attributes=request.attributes;
    if(request.second_angle)node->angles[1]=*request.second_angle;
    node->flags|=0x40;node->parameters208=request.color;node->feedback_scale=request.intensity;node->attributes|=0x100;
    for(const auto slot:node->pieces){auto& output=pieces_[slot].output;output.flags|=0x40;output.parameters208=request.color;}
    return WorkStatus::completed;
}
WorkStatus PeriodicVisuals::refresh_companion()noexcept{
    if(!admitted()||busy_||!fog_||!fog_->ready())return WorkStatus::unavailable;
    for(const auto& id:order_){const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(node&&node->pulse){node->pulse->phase=10;return WorkStatus::completed;}}
    if(entities_.size()==168)return WorkStatus::pool_full;
    gameplay_actors::EntityId id;
    try{
        auto node=std::make_unique<Node>();node->periodic=false;node->pulse.emplace();node->bank=bank_;
        const auto created=entities_.create(std::move(node));
        if(created.status!=gameplay_actors::EntityStatus::completed)return created.status==gameplay_actors::EntityStatus::full?WorkStatus::pool_full:WorkStatus::unavailable;
        id=created.id;order_.push_front(id);return WorkStatus::completed;
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return WorkStatus::unavailable;}
}
gameplay_scenario::EmissionResult PeriodicVisuals::emit(const gameplay_scenario::PeriodicEmission& request)noexcept{
    using gameplay_scenario::EmissionStatus;
    if(!admitted()||busy_||request.flags!=0x1a193||!finite(request.position))return{EmissionStatus::unavailable,{}};
    const auto* binding=bank_->periodic(request.descriptor);if(!binding)return{EmissionStatus::unavailable,{}};
    if(entities_.size()==168)return{EmissionStatus::pool_full,{}};
    gameplay_actors::EntityId id;
    try{
        auto value=std::make_unique<Node>();value->bank=bank_;value->descriptor=request.descriptor;value->initial_position=request.position;
        value->remaining=bank_->tracks().group(binding->group)->lifetime;value->pieces.reserve(binding->pieces.size());
        const auto created=entities_.create(std::move(value));
        if(created.status!=gameplay_actors::EntityStatus::completed)return{created.status==gameplay_actors::EntityStatus::full?EmissionStatus::pool_full:EmissionStatus::unavailable,{}};
        id=created.id;auto node=std::static_pointer_cast<Node>(entities_.acquire(id));
        // Original mode1 inserts at the head. Allocation failures after entity
        // admission roll back that new owner before exposing it to its caller.
        order_.push_front(id);
        for(const auto& part:binding->pieces){
            const auto free=std::find_if(pieces_.begin(),pieces_.end(),[](const auto& piece){return !piece.active;});
            if(free==pieces_.end())break;
            const auto slot=std::uint16_t(free-pieces_.begin());
            free->output={};free->output.root=part.root;free->output.mesh=part.mesh;free->output.material=part.material;free->output.flags=request.flags|0xa800u;
            free->active=true;node->pieces.push_back(slot);++piece_count_;
        }
        return{EmissionStatus::completed,std::move(node)};
    }catch(const std::bad_alloc&){if(id)retire_node(id);failure_=VisualStatus::no_memory;return{EmissionStatus::unavailable,{}};}
    catch(const std::exception&){if(id)retire_node(id);failure_=VisualStatus::invalid_profile;return{EmissionStatus::unavailable,{}};}
}
bool PeriodicVisuals::retire_node(gameplay_actors::EntityId id)noexcept{
    const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));if(!node)return false;
    node->live=false;node->visible=false;
    for(const auto slot:node->pieces){pieces_[slot].active=false;--piece_count_;}
    order_.remove(id);return entities_.retire(id)==gameplay_actors::EntityStatus::completed;
}
bool PeriodicVisuals::retire(const gameplay_actors::EntityId& id)noexcept{return !closed_&&!busy_&&retire_node(id);}
VisualReport PeriodicVisuals::update(transform_math::Vector camera)noexcept{return update_impl(camera,{});}
VisualReport PeriodicVisuals::update_with_view(transform_math::Vector camera,const transform_math::Matrix& view)noexcept{return update_impl(camera,view);}
void PeriodicVisuals::sample_children(Node& node,std::int16_t sample_time,transform_math::Vector camera,const std::optional<transform_math::Matrix>& view,VisualReport& report){
    const auto* companion=node.resource_companion?&*node.resource_companion:nullptr;
    const bool scaled=companion||node.update==WorkUpdate::scaled;
    const auto attributes=companion?companion->child_attributes:node.attributes;
    const auto material_scale=companion?companion->material_scale:node.feedback_scale;
    const auto additional_offset=companion?transform_math::Vector{}:node.additional_offset;
    const auto basis=companion?std::optional(companion->basis):node.basis;
    const auto position=companion?companion->position:node.initial_position;
    const auto angles=companion?companion->angles:node.angles;
    const auto uniform=companion?companion->scale:node.uniform;
    const auto camera_offset=companion?companion->camera_offset:node.camera_offset;
    const auto& binding=node.binding;const auto& group=*node.bank->tracks().group(binding.group);
    std::optional<transform_math::Matrix> inverse;
    if(!scaled&&(node.flags&0x80000)){if(!view)throw std::invalid_argument("Native camera matrix required for effect");inverse=inverse_camera(*view);}
    for(std::size_t i=0;i<node.pieces.size();++i){
        auto& output=pieces_[node.pieces[i]].output;const auto& part=binding.pieces[i];output.visible=part.selector!=0;
        if(!output.visible)continue;
        Parameters sampled;sample_transform(group.parts[part.selector-1].channels,sample_time,sampled);
        const auto& mesh=node.bank->geometry().meshes()[part.mesh];
        if(scaled&&(attributes&8))std::fill_n(output.material_values.begin(),mesh.indices.size(),1.f);
        else{
            node.bank->materials().sample(mesh,sample_time,output.material_values);
            if(scaled&&(attributes&0x100))for(std::size_t j=0;j<mesh.indices.size();++j)output.material_values[j]=output.material_values[j]*material_scale;
        }
        if(scaled&&(attributes&1))sampled.translation={sampled.translation.x+additional_offset.x,sampled.translation.y+additional_offset.y,sampled.translation.z+additional_offset.z};
        if(basis){
            sampled.translation=transform_math::direction(*basis,sampled.translation);
        }
        if(inverse)sampled.translation=transform_math::direction(*inverse,sampled.translation);
        sampled.translation={position.x+sampled.translation.x,position.y+sampled.translation.y,position.z+sampled.translation.z};
        if(scaled){
            if(attributes&2)for(unsigned j=0;j<3;++j)sampled.rotation[j]=add(sampled.rotation[j],angles[j]);
            if(attributes&4)sampled.scale={sampled.scale.x*uniform.x,sampled.scale.y*uniform.y,sampled.scale.z*uniform.z};
            if(!(output.flags&0x40))output.parameters208={1,1,1};
            if(attributes&0x20)sampled.translation=toward_camera(sampled.translation,camera,camera_offset);
        }else output.parameters208=node.parameters208;
        if(!finite(sampled.translation)||!finite(sampled.scale))throw std::domain_error("Native effect transform finite profile");
        output.parameters={sampled.scale,sampled.translation,{sampled.rotation[0],sampled.rotation[1],sampled.rotation[2]}};
        if(node.update==WorkUpdate::oriented&&i==1)output.parameters.rotation[2]=node.oriented_angle;
        ++report.pieces;
    }
}
VisualReport PeriodicVisuals::update_impl(transform_math::Vector camera,const std::optional<transform_math::Matrix>& view)noexcept{
    VisualReport report;if(closed_){report.status=VisualStatus::closed;return report;}
    if(busy_){report.status=VisualStatus::busy;return report;}
    if(failure_!=VisualStatus::completed){report.status=failure_;return report;}
    if(!finite(camera)){report.status=VisualStatus::invalid_camera;return report;}
    busy_=true;struct Release{bool& flag;~Release(){flag=false;}}release{busy_};
    try{
        for(auto cursor=order_.begin();cursor!=order_.end();){
            const auto id=*cursor++;const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));
            if(!node)throw std::logic_error("Native periodic visual identity unexpectedly stale");
            ++report.visited;
            if(node->surface_follower){
                auto& binding=*node->surface_follower;
                if(!binding.world||binding.world->closed()||!bound_to(binding.world->session().random))throw std::domain_error("Native surface follower World unavailable");
                std::optional<transform_math::Vector> parent;
                if(binding.parent)parent=transform_math::Vector{binding.parent->position.x,binding.parent->position.y,binding.parent->position.z};
                const bool retire=advance_surface_follower_visual(binding.state,parent);node->visible=binding.state.visible;node->flags=binding.state.flags;
                if(retire){retire_node(id);++report.retired;}continue;
            }
            if(node->projectile){
                auto& binding=*node->projectile;ProjectileOperations operations(*this);ProjectileTrailMotion input;
                if(binding.state.phase==0||binding.state.phase==1){
                    if(!binding.world||binding.world->closed()||!bound_to(binding.world->session().random)||!binding.parent)throw std::domain_error("Native projectile trail World unavailable");
                    const auto& parent=*binding.parent;input.active=parent.active;
                    if(parent.active&&!parent.pose_work)throw std::domain_error("Native projectile trail pose unavailable");
                    if(parent.pose_work){input.kind=parent.pose_work->kind;input.basis=parent.pose_work->basis;}
                    input.position={parent.position.x,parent.position.y,parent.position.z};
                }
                const auto step=advance_projectile_trail(binding.state,input,binding.variant,operations);node->visible=binding.state.visible;
                if(!step.available)throw std::domain_error("Native projectile trail emission unavailable");
                if(step.retire){retire_node(id);++report.retired;}continue;
            }
            if(node->trail){
                auto& binding=node->trail->binding;
                if(!binding.world||binding.world->closed()||!bound_to(binding.world->session().random))throw std::domain_error("Native inherited trail World unavailable");
                const auto parent=binding.world->resolve(binding.parent),motion=binding.world->resolve(binding.motion);
                if(!parent||!motion){retire_node(id);++report.retired;continue;}
                if(!motion->pose_work)throw std::domain_error("Native inherited trail motion unavailable");
                TrailOperations operations(*this,*node,camera,view,report);
                const InheritedTrailMotion input{motion->pose_work->kind,motion->primary,motion->subphase,{motion->position.x,motion->position.y,motion->position.z}};
                const auto step=advance_inherited_trail(node->trail->state,input,operations,*random_);node->visible=node->trail->state.visible;
                if(!step.available)throw std::domain_error("Native inherited trail consumer unavailable");
                if(step.retire){retire_node(id);++report.retired;}continue;
            }
            if(node->actor_contact){
                if(!channels_||!channels_bound_to(channels_->world))throw std::logic_error("Native actor contact owners unavailable");
                const auto parent=channels_->world.resolve(node->channel_parent);
                if(!parent){retire_node(id);++report.retired;continue;}
                ChannelOperations operations(*this,*node,camera,view,report);const auto step=advance_actor_contact(*node->actor_contact,parent->primary,parent->secondary,operations);node->visible=node->actor_contact->visible;
                if(!step.available)throw std::domain_error("Native actor contact consumer unavailable");
                if(step.retire){retire_node(id);++report.retired;}continue;
            }
            if(node->resource_flight){
                if(!flights_||!flights_bound_to(flights_->world))throw std::logic_error("Native resource flight owners unavailable");
                const auto parent=flights_->world.resolve(node->flight_parent);
                if(!parent){retire_node(id);++report.retired;continue;}
                CurrentRoomFlightQueries queries(flights_->world,flights_->rooms);const auto step=advance_resource_flight(*node->resource_flight,queries,*random_);
                node->visible=node->resource_flight->visible;
                if(!step.available)throw std::domain_error("Native resource flight query unavailable");
                if(step.retire){retire_node(id);++report.retired;continue;}
                if(step.cue_position&&!flights_->audio.cue(node->flight_parent,*step.cue_position))throw std::domain_error("Native resource flight audio unavailable");
                continue;
            }
            if(node->resource_debris){
                if(!debris_||debris_->world.closed()||!bound_to(debris_->world.session().random))throw std::logic_error("Native resource debris owners unavailable");
                auto& state=*node->resource_debris;const auto step=advance_resource_debris(state,*random_);node->visible=state.visible;
                if(step.retire){retire_node(id);++report.retired;continue;}
                if(step.query_floor){
                    const auto token=debris_->factory.lock();if(!token||!token->owner)throw std::domain_error("Native resource debris room owner retired");
                    const auto floor=token->owner->room_floor(debris_->world.room);if(!floor)throw std::domain_error("Native resource debris current room floor unavailable");
                    const auto result=gameplay_collision::trace::floor(*floor,{state.previous_position.x,state.previous_position.y,state.previous_position.z},{state.position.x,state.position.y,state.position.z});
                    if(result.status==gameplay_collision::trace::SamplingStatus::capacity||result.status==gameplay_collision::trace::SamplingStatus::nonprogress)throw std::domain_error("Native resource debris floor query unavailable");
                    complete_resource_debris_floor(state,bool(result.hit));node->visible=state.visible;
                }
                continue;
            }
            if(node->resource_companion){
                if(!companions_||!companions_bound_to(companions_->world,companions_->resources,companions_->models,companions_->templates)||!node->resource_model)throw std::logic_error("Native resource companion owners unavailable");
                const auto& model=*node->resource_model;
                const auto descriptor_id=companions_->resources.slot(model.resource_slot);
                const auto descriptor=descriptor_id?companions_->resources.get(*descriptor_id):std::nullopt;
                if(!descriptor)throw std::domain_error("Native resource companion descriptor unavailable");
                std::shared_ptr<gameplay_world::Actor> actor;gameplay_actors::EntityId actor_id;
                if(descriptor->ownership_tag>0&&descriptor->ownership_tag<5){
                    const auto index=descriptor->ownership_tag-1;actor=companions_->world.primary(index);actor_id=companions_->world.identity(index);
                    if(!actor)throw std::domain_error("Native resource companion primary actor unavailable");
                }
                const ResourceCompanionModel frame{model.active,model.visible,model.content_id,model.resource_slot,model.flags,model.draw_tag,model.position,model.axis_scale,model.pose};
                const auto step=advance_resource_companion(*node->resource_companion,frame,actor?std::optional(ResourceCompanionActor{actor->primary,actor->secondary}):std::nullopt,*random_);
                node->visible=node->resource_companion->visible;
                if(step.spawn_gameplay&&!companions_->actions.light(actor_id,node->resource_companion->position))throw std::domain_error("Native resource companion timed light unavailable");
                if(step.resource_cue&&!companions_->actions.cue(actor_id,*step.resource_cue))throw std::domain_error("Native resource companion audio unavailable");
                if(step.retire){retire_node(id);++report.retired;continue;}
                if(step.render)sample_children(*node,step.sample_time,camera,view,report);
                if(step.fade_children){
                    for(std::size_t i=0;i<node->pieces.size();++i){
                        const auto& part=node->binding.pieces[i];const auto* mesh=node->bank->geometry().material(part.root,part.material);
                        if(!mesh)throw std::domain_error("Native resource companion fade material unavailable");
                        auto& values=pieces_[node->pieces[i]].output.material_values;
                        for(std::size_t j=0;j<mesh->indices.size();++j){const float next=values[j]-node->resource_companion->fade_delta;values[j]=next<0?0.f:next>1?1.f:next;}
                    }
                }
                continue;
            }
            if(node->surface){
                if(!surfaces_)throw std::logic_error("Native surface work owner unavailable");
                const auto actor=surfaces_->world->resolve(node->surface_actor);
                // Native generation retirement replaces unsafe slot-pointer reuse.
                if(!actor){retire_node(id);++report.retired;continue;}
                const auto gate=prepare_surface(*node->surface,*surfaces_->modulation,*actor,surfaces_->world->room);
                if(gate==SurfaceGate::retire){retire_node(id);++report.retired;continue;}
                if(gate==SurfaceGate::skip)continue;
                const auto room=surfaces_->rooms->retain(surfaces_->world->room);
                if(!room||!room->current(room->identity())||room->room_number()!=surfaces_->world->room)throw std::domain_error("Native surface room lease unavailable");
                SurfaceSink sink(*this);const auto step=advance_surface(*node->surface,surfaces_->profile,*surfaces_->modulation,*actor,surfaces_->world->room,room->geometry().floors,*random_,sink);
                if(step.status!=SurfaceStatus::completed)throw std::domain_error("Native surface work profile unavailable");
                if(step.retire){retire_node(id);++report.retired;}continue;
            }
            if(node->pulse){
                if(!fog_)throw std::logic_error("Native fog effect owner unavailable");
                const auto step=fog_->advance(*node->pulse);
                if(step.status!=gameplay_scenario::FogStatus::completed)throw std::domain_error("Native fog effect profile unavailable");
                if(step.retire){retire_node(id);++report.retired;}continue;
            }
            if(!node->periodic){
                const bool scaled=node->update==WorkUpdate::scaled;
                if(node->lifecycle==0){
                    node->lifecycle=1;node->visible=scaled;
                    if(scaled){node->position=node->initial_position;if(node->attributes&0x80){if(!random_)throw std::logic_error("Native effect random owner unavailable");node->angles[1]=std::bit_cast<std::int16_t>(random_->request(1));node->attributes|=2;}}
                    else if(node->update==WorkUpdate::ordinary)node->flags|=0x8000;
                }
                if(!scaled){
                    if(node->lifecycle!=1)continue;
                    if(node->phase==0){
                        node->delay=add(node->delay,-1);if(node->delay>=0)continue;
                        node->visible=true;node->phase=1;node->position=node->initial_position;
                        if(node->update==WorkUpdate::oriented){if(!random_)throw std::logic_error("Native oriented effect random owner unavailable");node->oriented_angle=std::bit_cast<std::int16_t>(std::uint16_t((random_->request(1)&15u)<<12));}
                    }
                    if(node->phase!=1)continue;
                    node->remaining=add(node->remaining,-2);
                }
                if(node->remaining<0){retire_node(id);++report.retired;continue;}
                sample_children(*node,node->age,camera,view,report);
                if(scaled)node->remaining=add(node->remaining,-2);
                node->age=add(node->age,2);continue;
            }
            if(node->phase==0){node->delay=add(node->delay,-1);if(node->delay>0){node->visible=false;continue;}++node->phase;node->visible=true;}
            node->remaining=add(node->remaining,-2);if(node->remaining<0){retire_node(id);++report.retired;continue;}
            const auto* binding=node->bank->periodic(node->descriptor);const auto& group=*node->bank->tracks().group(binding->group);
            for(std::size_t i=0;i<node->pieces.size();++i){
                auto& output=pieces_[node->pieces[i]].output;const auto& part=binding->pieces[i];output.visible=part.selector!=0;
                if(!output.visible)continue;
                Parameters sampled;sample_transform(group.parts[part.selector-1].channels,node->age,sampled);
                sampled.translation={node->initial_position.x+sampled.translation.x,node->initial_position.y+sampled.translation.y,node->initial_position.z+sampled.translation.z};
                sampled.translation=toward_camera(sampled.translation,camera,node->scale);
                node->bank->materials().sample(node->bank->geometry().meshes()[part.mesh],node->age,output.material_values);
                output.parameters={sampled.scale,sampled.translation,{sampled.rotation[0],sampled.rotation[1],sampled.rotation[2]}};++report.pieces;
            }
            node->age=add(node->age,2);
        }
        if(revision_==UINT64_MAX)throw std::overflow_error("Native effect frame revision exhausted");
        auto frame=std::make_shared<EffectFrame>();frame->revision=revision_+1;frame->visuals.reserve(order_.size());
        for(const auto& id:order_){const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));VisualOutput output;output.id=id;output.bank=node->bank;output.visible=node->visible;output.category=node->category;output.debris=node->resource_debris;output.flight=node->resource_flight;output.actor_contact=node->actor_contact;if(node->surface_follower)output.surface_follower=node->surface_follower->state;if(node->projectile)output.projectile_trail=ProjectileTrailOutput{node->projectile->state,node->projectile->root,node->flags};output.pieces.reserve(node->pieces.size());for(const auto slot:node->pieces)output.pieces.push_back(pieces_[slot].output);frame->visuals.push_back(std::move(output));}
        revision_=frame->revision;publish(std::move(frame));return report;
    }catch(const std::bad_alloc&){failure_=VisualStatus::no_memory;}
    catch(const std::exception&){failure_=VisualStatus::invalid_profile;}
    publish({});report.status=failure_;return report;
}
void PeriodicVisuals::close()noexcept{
    if(closed_||busy_)return;
    while(!order_.empty())retire_node(order_.front());
    closed_=true;entities_.shutdown();publish({});
    editing_->owner=nullptr;
    surfaces_.reset();
    companions_.reset();
    debris_.reset();
    flights_.reset();
    channels_.reset();
}
}
