#include "hit_regions.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_collision::hit_regions {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||4>bytes.size()-at)throw std::invalid_argument("Truncated native hit-region definition");
    std::uint32_t result{};for(unsigned i=0;i<4;++i)result|=std::uint32_t(std::to_integer<unsigned char>(bytes[at+i]))<<(8*i);return result;
}
float number(std::span<const std::byte> bytes,std::size_t at){return std::bit_cast<float>(word(bytes,at));}
}
std::vector<Definition> import_definitions(std::span<const std::byte> bytes){
    std::vector<Definition> result;
    for(std::size_t at=0;;at+=20){const auto radius=number(bytes,at+12);if(radius==-1)return result;
        if(result.size()==255)throw std::invalid_argument("Native hit-region count exceeds original byte domain");
        result.push_back({{number(bytes,at),number(bytes,at+4),number(bytes,at+8)},radius,word(bytes,at+16)});
    }
}
void Regions::set(std::optional<std::vector<Definition>> definitions){
    if(definitions&&definitions->size()>255)throw std::invalid_argument("Native hit-region count exceeds original byte domain");
    definitions_=std::move(definitions);
}
Status Regions::refresh(Transform mode,const actors::Basis& root,std::span<const actors::Basis> joints){
    if(!definitions_)return Status::complete;
    if(definitions_->size()>255)return Status::invalid_count;
    if(mode==Transform::model_joints)for(const auto& d:*definitions_)if(d.joint>=joints.size())return Status::missing_joint;
    std::vector<Sphere> next;next.reserve(definitions_->size());
    for(const auto& d:*definitions_){const auto& basis=mode==Transform::model_joints?joints[d.joint]:root;next.push_back({basis.point(d.offset),d.radius});}
    spheres_=std::move(next);return Status::complete;
}
bool Queue::add(gameplay_actors::EntityId id)noexcept{if(!id||count_==entries_.size())return false;entries_[count_++]=id;return true;}
bool prepare_hit(gameplay_actors::HitActor& actor,ContactState& state,gameplay_actors::EntityId id,bool present,Queue& queue)noexcept{
    actor.damage_word=0;actor.progression_amount=0;state.priority=0;actor.pending_hit=0;state.serial=0;
    if(state.cooldown){if(state.cooldown!=255)--state.cooldown;return false;}
    return present&&queue.add(id);
}
}
