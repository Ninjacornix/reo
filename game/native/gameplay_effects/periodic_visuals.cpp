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
};
PeriodicVisuals::PeriodicVisuals(std::shared_ptr<const EffectBank> bank):bank_(std::move(bank)){
    if(!bank_)throw std::invalid_argument("Native periodic visuals require admitted owned assets");
}
PeriodicVisuals::~PeriodicVisuals(){close();}
std::shared_ptr<const EffectFrame> PeriodicVisuals::retain()const noexcept{
    std::lock_guard lock(publication_);return published_;
}
void PeriodicVisuals::publish(std::shared_ptr<const EffectFrame> frame)noexcept{
    // Destruction of an old frame/resource lease occurs after unlocking.
    {std::lock_guard lock(publication_);published_.swap(frame);}
}
bool PeriodicVisuals::admitted()const noexcept{return !closed_&&failure_==VisualStatus::completed;}
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
VisualReport PeriodicVisuals::update(transform_math::Vector camera)noexcept{
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
}
}
