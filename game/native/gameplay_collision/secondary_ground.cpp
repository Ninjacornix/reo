#include "secondary_ground.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::gameplay_collision::ground {
std::int8_t ProbeRef::read() const noexcept {
    return byte_ ? *byte_ : std::bit_cast<std::int8_t>(
        std::uint8_t(std::bit_cast<std::uint32_t>(*word_) >> 8));
}
void ProbeRef::write(std::int8_t value) const noexcept {
    if (byte_) { *byte_ = value; return; }
    auto bits = std::bit_cast<std::uint32_t>(*word_);
    bits = (bits & ~0xff00u) | (std::uint32_t(std::bit_cast<std::uint8_t>(value)) << 8);
    *word_ = std::bit_cast<float>(bits);
}
transform_math::Angles RotationRef::angles() const noexcept {
    return {std::uint16_t(x), std::uint16_t(y), std::uint16_t(z)};
}
void refresh(View actor, const response::Grid& floors) noexcept {
    const auto floor = floors.floor(Vec3(actor.position));
    actor.height = floor.height;
    actor.surface = floor.type;
    actor.material = floor.material;
    actor.attributes = floor.attributes;
    actor.normal = floor.normal;
    if (actor.surface == 1)
        actor.height = floors.floor(Vec3(actor.position), 1).height;
    if ((actor.auxiliary_status & 0xff00u) == 0)
        actor.position.y = actor.height;
}
std::int8_t classify(Vec3 point, std::uint16_t yaw, const response::Grid& floors) noexcept {
    if (floors.floor(point, 1).type != 1)
        return 0;
    const auto up = floors.floor(point).normal;
    const float x = up.x == 0 ? 9.999999747378752e-05f : up.x;
    float degrees = (180.0f * std::atan2(x, up.z)) / 3.1415927410125732f;
    if (degrees < 0)
        degrees += 360;
    const auto heading = std::uint16_t(std::uint32_t(std::trunc(182.04444885253906f * degrees)));
    const auto delta = std::bit_cast<std::int16_t>(std::uint16_t(yaw - heading));
    const auto absolute = std::uint16_t(std::abs(int(delta)));
    return absolute < 0x3000 ? -1 : absolute < 0x5000 ? 0 : 1;
}
ProbeStatus probe(View actor, std::int8_t& state, const response::Grid& floors) {
    refresh(actor, floors);
    if (state < -1 || state > 1)
        return ProbeStatus::uninitialized_source_probe;
    auto point = Vec3(actor.position);
    if (state != 1) {
        auto matrix = transform_math::identity();
        transform_math::reset_euler_axes(matrix, actor.rotation.angles());
        const auto offset = transform_math::direction(matrix, {0, 0, state == -1 ? -18.0f : 18.0f});
        point.x += offset.x;
        point.z += offset.z;
    }
    state = classify(point, std::uint16_t(actor.rotation.y), floors);
    actor.surface = std::uint8_t(state != 0);
    return ProbeStatus::completed;
}
Report update(std::span<Entry> ordered, const response::Grid& floors, Walls& walls) {
    for (std::size_t i = 0; i < ordered.size(); ++i) {
        if (!ordered[i].id)
            throw std::invalid_argument("Secondary ground actor needs a live native identity");
        for (std::size_t j = 0; j < i; ++j)
            if (ordered[i].id == ordered[j].id)
                throw std::invalid_argument("Duplicate secondary ground actor identity");
    }
    Report report;
    for (auto& entry : ordered) {
        ++report.visited;
        if (entry.controls & 0x20) {
            ++report.displaced;
            entry.view.position.x += entry.displacement.x;
            entry.view.position.y += entry.displacement.y;
            entry.view.position.z += entry.displacement.z;
        } else {
            ++report.wall_queries;
            walls.correct(entry.id, entry.view);
        }
        ProbeRef* state{};
        if (entry.subtype == 1)
            state = &entry.states.kind_one;
        else if (entry.subtype == 0x29)
            state = &entry.states.kind_twenty_nine;
        else if (entry.subtype == 0x2d)
            state = &entry.states.kind_twenty_d;
        if (!state)
            refresh(entry.view, floors);
        else {
            if (!state->available())
                throw std::runtime_error("Secondary ground probe source unavailable");
            auto value = state->read();
            if (probe(entry.view, value, floors) == ProbeStatus::completed) {
                state->write(value);
                ++report.classified;
            } else
                ++report.unknown_probes;
        }
    }
    return report;
}
} // namespace reo::native::gameplay_collision::ground
