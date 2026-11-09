#include "periodic_visuals.hpp"
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
    std::optional<transform_math::Matrix> basis;
    VisualBinding binding;
    std::optional<gameplay_scenario::FogPulse> pulse;
};
struct PeriodicVisuals::Editing {PeriodicVisuals* owner;};
class PeriodicVisuals::Edit final:public WorkEdit {
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
        node_->flags|=0x40;node_->parameters208=value;node_->feedback_scale=scalar;node_->attributes|=0x100;
        for(const auto slot:node_->pieces){auto& output=owner->pieces_[slot].output;output.flags|=0x40;output.parameters208=value;}
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
WorkCreated PeriodicVisuals::create(const WorkRequest& request)noexcept{
    if(!admitted()||busy_)return{};
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
                const auto& binding=node->binding;const auto& group=*node->bank->tracks().group(binding.group);
                std::optional<transform_math::Matrix> inverse;
                if(!scaled&&(node->flags&0x80000)){if(!view)throw std::invalid_argument("Native camera matrix required for effect");inverse=inverse_camera(*view);}
                for(std::size_t i=0;i<node->pieces.size();++i){
                    auto& output=pieces_[node->pieces[i]].output;const auto& part=binding.pieces[i];output.visible=part.selector!=0;
                    if(!output.visible)continue;
                    Parameters sampled;sample_transform(group.parts[part.selector-1].channels,node->age,sampled);
                    const auto& mesh=node->bank->geometry().meshes()[part.mesh];
                    if(scaled&&(node->attributes&8))std::fill_n(output.material_values.begin(),mesh.indices.size(),1.f);
                    else{
                        node->bank->materials().sample(mesh,node->age,output.material_values);
                        if(scaled&&(node->attributes&0x100))for(std::size_t j=0;j<mesh.indices.size();++j)output.material_values[j]=output.material_values[j]*node->feedback_scale;
                    }
                    if(scaled&&(node->attributes&1))sampled.translation={sampled.translation.x+node->additional_offset.x,sampled.translation.y+node->additional_offset.y,sampled.translation.z+node->additional_offset.z};
                    if(node->basis){
                        sampled.translation=transform_math::direction(*node->basis,sampled.translation);
                    }
                    if(inverse)sampled.translation=transform_math::direction(*inverse,sampled.translation);
                    sampled.translation={node->initial_position.x+sampled.translation.x,node->initial_position.y+sampled.translation.y,node->initial_position.z+sampled.translation.z};
                    if(scaled){
                        if(node->attributes&2)for(unsigned j=0;j<3;++j)sampled.rotation[j]=add(sampled.rotation[j],node->angles[j]);
                        if(node->attributes&4)sampled.scale={sampled.scale.x*node->uniform.x,sampled.scale.y*node->uniform.y,sampled.scale.z*node->uniform.z};
                        if(!(output.flags&0x40))output.parameters208={1,1,1};
                        if(node->attributes&0x20)sampled.translation=toward_camera(sampled.translation,camera,node->camera_offset);
                    }else output.parameters208=node->parameters208;
                    if(!finite(sampled.translation)||!finite(sampled.scale))throw std::domain_error("Native effect transform finite profile");
                    output.parameters={sampled.scale,sampled.translation,{sampled.rotation[0],sampled.rotation[1],sampled.rotation[2]}};
                    if(node->update==WorkUpdate::oriented&&i==1)output.parameters.rotation[2]=node->oriented_angle;
                    ++report.pieces;
                }
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
        for(const auto& id:order_){const auto node=std::static_pointer_cast<Node>(entities_.acquire(id));VisualOutput output;output.id=id;output.bank=node->bank;output.visible=node->visible;output.pieces.reserve(node->pieces.size());for(const auto slot:node->pieces)output.pieces.push_back(pieces_[slot].output);frame->visuals.push_back(std::move(output));}
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
}
}
