#pragma once
#include "resource_templates.hpp"
#include "scene_resources.hpp"
#include "../gameplay_world/inventory_state.hpp"
#include <algorithm>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
inline void compact_inventory(gameplay_world::InventorySlots& inventory,std::uint8_t character,
                              const SceneResources& resources,const ResourceTemplates& templates) {
    const auto descriptor = [&](std::uint8_t id) {
        const auto value = resources.get(*resources.slot(id));
        if (!value) throw std::runtime_error("Native inventory descriptor unavailable");
        return *value;
    };
    const auto priority = [&](std::uint8_t id) {
        const auto value = descriptor(id);
        return value.active && value.template_index != 255 &&
            (templates.flags(value.template_index) & 0x20000u);
    };
    std::array<std::uint8_t,4> ordered{};
    unsigned count{};
    for (bool selected : {true,false})
        for (auto item : inventory.carried)
            if (item && priority(item) == selected) {
                if (count >= ordered.size()) throw std::runtime_error("Native carried inventory exceeded its canonical capacity");
                ordered[count++] = item;
            }
    for (unsigned i = 0; i < ordered.size(); ++i)
        if (ordered[i])
            for (unsigned j = i + 1; j < ordered.size(); ++j)
                if (ordered[i] == ordered[j]) ordered[j] = 0;
    inventory.carried.fill(0);
    unsigned output{};
    for (auto item : ordered)
        if (item) inventory.carried[output++] = item;
    if (character == 7) {
        std::array<std::array<std::uint8_t,9>,3> groups{};
        std::array<unsigned,3> used{};
        std::uint8_t other{};
        for (unsigned i = 1; i < 29; ++i) {
            const auto item = inventory.storage[i];
            if (!item) continue;
            const auto content = descriptor(item).attachment_id;
            if (content >= 300 && content <= 302) {
                const auto group = unsigned(content - 300);
                if (used[group] == 9) throw std::runtime_error("Native character7 inventory bucket exceeds admitted nine-item profile");
                groups[group][used[group]++] = item;
            } else other = item;
        }
        for (unsigned group = 0; group < groups.size(); ++group)
            std::copy(groups[group].begin(),groups[group].end(),inventory.storage.begin() + 1 + group * 9);
        inventory.storage[28] = other;
        return;
    }
    std::array<std::uint8_t,32> storage{};
    storage[0] = inventory.storage[0];
    output = 1;
    for (bool selected : {true,false})
        for (unsigned i = 1; i < storage.size(); ++i) {
            const auto item = inventory.storage[i];
            if (item && priority(item) == selected) {
                if (output >= storage.size()) throw std::runtime_error("Native storage inventory exceeded its canonical capacity");
                storage[output++] = item;
            }
        }
    inventory.storage = storage;
}
}
