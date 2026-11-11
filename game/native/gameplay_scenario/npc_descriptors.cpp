#include "npc_descriptors.hpp"
#include "scene_resources.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>
#include <bit>

namespace reo::native::gameplay_scenario {
namespace {
bool contains(std::span<const std::byte> bytes,std::size_t offset,std::size_t size) noexcept {
    return offset<=bytes.size() && size<=bytes.size()-offset;
}
std::uint32_t word(std::span<const std::byte> bytes,std::size_t offset) noexcept {
    return std::to_integer<std::uint32_t>(bytes[offset]) |
        std::to_integer<std::uint32_t>(bytes[offset+1])<<8 |
        std::to_integer<std::uint32_t>(bytes[offset+2])<<16 |
        std::to_integer<std::uint32_t>(bytes[offset+3])<<24;
}
void clear_transition(NpcDescriptor& descriptor) noexcept {
    descriptor.transition_state=0;
    descriptor.transition_timer=0;
}
}

std::optional<std::size_t> NpcDescriptors::import(std::span<const std::byte> bytes) noexcept {
    if (!contains(bytes,0,4)) return {};
    const auto groups=word(bytes,0)>>3;
    if (groups>bytes.size()/8) return {};
    auto staged=records_;
    std::size_t written=0;
    for (std::size_t group=0;group<groups;++group) {
        const std::size_t base=word(bytes,8*group);
        if (!contains(bytes,base,4)) return {};
        const auto count=std::min<std::size_t>(word(bytes,base),capacity-written);
        if (!contains(bytes,base+4,4*count)) return {};
        for (std::size_t index=0;index<count;++index) {
            const std::size_t relative=word(bytes,base+4+4*index);
            if (relative>bytes.size()-base || !contains(bytes,base+relative,84)) return {};
            const auto source=bytes.subspan(base+relative,84);
            auto& descriptor=staged[written++];
            descriptor.active=std::uint8_t(word(source,0));
            descriptor.room=std::uint8_t(word(source,4));
            descriptor.category=std::uint8_t(word(source,8));
            descriptor.variant=std::uint8_t(word(source,0x20));
            descriptor.template_id=std::uint16_t(word(source,0xc));
            const auto mode=descriptor.template_id==0x1d ? word(source,0x24) : 0;
            descriptor.control_mode=std::uint8_t(mode);
            descriptor.position={std::bit_cast<float>(word(source,0x10)),
                                 std::bit_cast<float>(word(source,0x14)),
                                 std::bit_cast<float>(word(source,0x18))};
            descriptor.yaw=std::uint16_t(word(source,0x1c));
            descriptor.health=std::uint16_t(word(source,0x48));
            descriptor.behavior_flags=std::uint16_t(word(source,0x4c));
            descriptor.transition_state=0;
            descriptor.parameter=std::uint8_t(word(source,0x50));
            descriptor.transition_timer=-1;
            descriptor.behavior_state=-1;
            switch (mode) {
            case 0:
                descriptor.mode0_values={std::uint16_t(word(source,0x2c)),std::uint16_t(word(source,0x30))};
                descriptor.mode_parameter=std::uint8_t(word(source,0x28));
                descriptor.random_policy=std::bit_cast<std::int8_t>(std::uint8_t(word(source,0x34)));
                break;
            case 1:
                descriptor.mode_parameter=std::uint8_t(word(source,0x28));
                break;
            case 2:
                descriptor.mode2_value=word(source,0x34);
                descriptor.mode2_parameter=word(source,0x44);
                descriptor.mode_parameter=std::uint8_t(word(source,0x28));
                descriptor.mode2_half=std::uint16_t(descriptor.mode2_value);
                break;
            default: break;
            }
        }
    }
    records_=staged;
    return written;
}

void NpcDescriptors::enable(gameplay_world::Session& session,std::int32_t id,
                            std::array<std::uint32_t,3> parameters) noexcept {
    for (std::size_t index=0;index<capacity;++index) {
        auto& descriptor=records_[index];
        const bool eligible=descriptor.random_policy==0 ||
            std::int32_t(descriptor.random_policy)-1==std::int32_t(session.random.request(2)&3u);
        if (id!=descriptor.template_id || !eligible) continue;
        descriptor.flags|=1;
        descriptor.control_parameters=parameters;
        clear_transition(descriptor);
        if (descriptor.control_mode && !(descriptor.template_id==0x64 && session.scenario==1))
            (void)session.ai_control_requests.register_control(1,std::uint32_t(index));
        return;
    }
}

void NpcDescriptors::position(std::int32_t id,std::uint8_t room,transform_math::Vector value,
                              std::uint16_t yaw) noexcept {
    for (auto& descriptor:records_) {
        if (id!=descriptor.template_id || (descriptor.flags&1)) continue;
        descriptor.room=room;
        descriptor.position=value;
        descriptor.yaw=yaw;
        clear_transition(descriptor);
        return;
    }
}

void NpcDescriptors::health_flags(std::int32_t id,std::int32_t health,std::uint32_t mask) noexcept {
    for (auto& descriptor:records_) {
        if (id!=descriptor.template_id || (descriptor.flags&1)) continue;
        if (health>=0) descriptor.health=std::uint16_t(health);
        if (mask&0x80000000u) descriptor.flags&=std::uint8_t(~(mask&0x0fffffffu));
        else if (mask&0x40000000u) descriptor.flags|=std::uint8_t(mask);
        else if (mask&0x20000000u) descriptor.flags=std::uint8_t(mask);
        descriptor.behavior_flags=std::uint16_t((descriptor.behavior_flags&~0x30u) |
            (descriptor.flags&0x10u) | ((descriptor.flags&0x40u)>>1));
        clear_transition(descriptor);
        return;
    }
}

void NpcDescriptors::disable(std::int32_t id) noexcept {
    for (auto& descriptor:records_) {
        if (id!=descriptor.template_id) continue;
        descriptor.flags&=std::uint8_t(~1u);
        return;
    }
}

bool NpcDescriptors::grant(SceneResources& resources,const ResourceTemplates& templates,
                           std::int16_t id,std::int16_t content,std::int16_t quantity) noexcept {
    if (id<0 || content<0) return true;
    const auto allocation=resources.allocate_owned(std::uint16_t(id+4),std::uint16_t(content),quantity,templates);
    if (allocation.status!=SceneStatus::completed) return allocation.status==SceneStatus::full;
    for (auto& descriptor:records_) {
        if (!descriptor.active || descriptor.template_id!=id) continue;
        const auto free=std::find(descriptor.inventory.begin(),descriptor.inventory.end(),0);
        if (free==descriptor.inventory.end()) continue;
        *free=allocation.slot;
        return true;
    }
    return true;
}

bool NpcDescriptors::select(SceneResources& resources,std::int8_t id,std::int16_t content) noexcept {
    if (id<0 || content<0) return true;
    for (auto& descriptor:records_) {
        if (!descriptor.active || descriptor.template_id!=id) continue;
        for (const auto slot:descriptor.inventory) {
            if (!slot) continue;
            const auto item=resources.get(*resources.slot(slot));
            if (!item) return false;
            if (item->attachment_id!=content) continue;
            descriptor.selected_resource=slot;
            return true;
        }
    }
    return true;
}
}
