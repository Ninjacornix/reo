#include "scene_matrix_programs.hpp"
#include <bit>
#include <cmath>
#include <limits>
namespace reo::native::gameplay_scenario {
namespace {
std::uint16_t turn(float radians) {
    // Complete admitted finite191EF0 arithmetic. Its result is consumed as a
    // low halfword by the qualified axis builder, never as a host clock.
    float degrees = (180.0f * radians) / std::bit_cast<float>(0x40490fdbu);
    if (degrees < 0)
        degrees = degrees + 360.0f;
    const float scaled = std::bit_cast<float>(0x43360b61u) * degrees;
    if (!std::isfinite(scaled) || scaled < -2147483648.0f ||
        scaled >= 4294967296.0f)
        throw std::domain_error("Native scene turn profile");
    return std::uint16_t(std::int64_t(scaled));
}
ModelMatrix evaluate(const ModelMatrix &base, std::uint8_t mode, float value) {
    transform_math::require_profile();
    if (!std::isfinite(value))
        throw std::domain_error("Native scene curve finite profile");
    auto matrix = base;
    if (mode == 0) {
        auto rotation = transform_math::identity();
        transform_math::reset_euler_axes(rotation, {0, turn(value), 0});
        matrix = transform_math::identity();
        for (unsigned column = 0; column < 3; ++column)
            for (unsigned lane = 0; lane < 3; ++lane) {
                float component = base[0][lane] * rotation[column][0];
                component = component + base[1][lane] * rotation[column][1];
                component = component + base[2][lane] * rotation[column][2];
                if (!std::isfinite(component))
                    throw std::domain_error(
                        "Native scene basis finite profile");
                matrix[column][lane] = component;
            }
        matrix[3] = base[3];
    } else if (mode == 1 || mode == 3) {
        const auto delta = transform_math::direction(
            base, mode == 1 ? transform_math::Vector{value, 0, 0}
                            : transform_math::Vector{0, 0, value});
        matrix[3][0] = base[3][0] + delta.x;
        matrix[3][2] = base[3][2] + delta.z;
    } else if (mode == 2)
        matrix[3][1] = base[3][1] + value;
    for (unsigned lane = 0; lane < 3; ++lane)
        if (!std::isfinite(matrix[3][lane]))
            throw std::domain_error("Native scene position finite profile");
    return matrix;
}
} // namespace
SceneMatrixPrograms::SceneMatrixPrograms(
    SceneControls &controls, SceneModels &models, SceneModelBindings &bindings,
    FlagState &flags, const std::uint16_t &room, const State &initial)
    : controls_(controls), models_(models), bindings_(bindings), flags_(flags),
      room_(room), tables_(stock_scene_matrix_tables()) {
    for (unsigned i = 0; i < 16; ++i) {
        channels_[i] = std::make_shared<SceneMatrixChannel>(initial[i]);
        matrices_[i] =
            std::shared_ptr<ModelMatrix>(channels_[i], &channels_[i]->matrix);
    }
}
std::optional<gameplay_collision::delivery::ChannelView>
SceneMatrixPrograms::channel(std::uint8_t index) {
    if (closed_ || index >= 16)
        return {};
    return gameplay_collision::delivery::ChannelView{
        channels_[index]->contact.gate, channels_[index]->contact.active};
}
std::optional<SceneMatrixChannel>
SceneMatrixPrograms::inspect(std::size_t index) const noexcept {
    if (closed_ || index >= 16)
        return {};
    return *channels_[index];
}
SceneMatrixStatus
SceneMatrixPrograms::evaluate_first(std::size_t index) noexcept {
    if (closed_)
        return SceneMatrixStatus::closed;
    if (index >= 16)
        return SceneMatrixStatus::invalid_channel;
    auto &channel = *channels_[index];
    if (channel.curve >= 236 || channel.model_slot >= 128)
        return SceneMatrixStatus::unadmitted_profile;
    const auto &group = tables_.groups[channel.curve / 4];
    const auto keys = tables_.curves[group.curves[channel.curve % 4]];
    if (keys.size() < 2)
        return SceneMatrixStatus::unadmitted_profile;
    const auto base = models_.pose(channel.model_slot);
    if (!base)
        return SceneMatrixStatus::unadmitted_profile;
    const float difference = keys[1].value - keys[0].value;
    const float product =
        difference * float(std::int32_t(channel.time) - keys[0].time);
    const float divided = product / float(keys[1].time - keys[0].time);
    const float value = divided + keys[0].value;
    try {
        channel.matrix = evaluate(*base, channel.transform, value);
        return SceneMatrixStatus::completed;
    } catch (const std::exception &) {
        return SceneMatrixStatus::unsupported_numeric;
    }
}
SceneMatrixResult
SceneMatrixPrograms::select(std::uint32_t authored,
                            SceneMatrixSelection selection) noexcept {
    if (closed_)
        return {SceneMatrixStatus::closed};
    const auto index = std::uint8_t(authored);
    if (index >= 16)
        return {SceneMatrixStatus::invalid_channel};
    if (selection == SceneMatrixSelection::terminal) {
        const auto half = flags_.strided_half(room_, 2);
        if (!half)
            return {SceneMatrixStatus::unavailable_flags};
        if (!(*half & (std::uint16_t(1) << index)))
            return {};
    }
    const auto found = controls_.first_route(index);
    if (found.status != ControlStatus::completed)
        return {SceneMatrixStatus::unavailable_control};
    if (!found.id)
        return {};
    const auto record = controls_.get(*found.id);
    if (!record)
        return {SceneMatrixStatus::unavailable_control};
    std::uint8_t model{}, kind{};
    std::uint32_t descriptor{};
    std::uint8_t mode{};
    if (const auto *zero = std::get_if<ControlTypeZero>(&record->body)) {
        if (!zero->matrix_program)
            return {SceneMatrixStatus::unavailable_control, true};
        model = zero->matrix_program->model_slot;
        kind = zero->matrix_program->resource_class;
        descriptor = zero->matrix_program->descriptor;
        mode = zero->refresh_parameter;
    } else if (const auto *two = std::get_if<ControlTypeTwo>(&record->body)) {
        if (!two->model_reference || !two->matrix_resource_class)
            return {SceneMatrixStatus::unavailable_control, true};
        model = std::uint8_t(two->model_reference->model);
        kind = *two->matrix_resource_class;
        descriptor = two->model_reference->descriptor;
        mode = two->refresh_parameter;
    } else
        return {SceneMatrixStatus::unavailable_control, true};
    if (model >= 128)
        return {SceneMatrixStatus::unadmitted_profile, true};
    auto &channel = *channels_[index];
    auto program = channel.program;
    if (selection != SceneMatrixSelection::room_variant &&
        descriptor >= tables_.descriptors.size())
        return {SceneMatrixStatus::unadmitted_profile, true};
    const auto variant = descriptor < tables_.descriptors.size()
                             ? tables_.descriptors[descriptor]
                             : 0;
    switch (selection) {
    case SceneMatrixSelection::room_variant:
        if (kind == 0)
            program = 0x10;
        else if (kind == 1 || kind == 3)
            program = 0x1c;
        break;
    case SceneMatrixSelection::first:
        if (kind == 0)
            program = std::uint8_t(7 + variant);
        else if (kind == 1)
            program = 9;
        else if (kind == 3)
            program = 0x17;
        break;
    case SceneMatrixSelection::normal:
        if (kind == 0)
            program = std::uint8_t(0xc + 2u * mode + variant);
        else if (kind == 1)
            program = 0x18;
        else if (kind == 3)
            program = 0x19;
        break;
    case SceneMatrixSelection::expiry:
        if (kind == 0)
            program = std::uint8_t(0x1d + 2u * mode + variant);
        else if (kind == 1)
            program = 0x21;
        else if (kind == 3)
            program = 0x22;
        break;
    case SceneMatrixSelection::terminal:
        if (kind == 0)
            program = std::uint8_t(0x12 + 2u * mode + variant);
        else if (kind == 1)
            program = 0x1a;
        else if (kind == 2)
            program = 0x11;
        else if (kind == 3)
            program = 0x1b;
        else
            return {SceneMatrixStatus::completed, true, false};
        break;
    }
    if (program >= tables_.programs.size())
        return {SceneMatrixStatus::unadmitted_profile, true};
    const auto &definition = tables_.programs[program];
    if (!definition.count)
        return {SceneMatrixStatus::unadmitted_profile, true};
    const auto group = definition.groups[0];
    std::uint8_t offset{};
    if (selection == SceneMatrixSelection::room_variant) {
        const auto half = flags_.strided_half(room_, 3);
        if (!half)
            return {SceneMatrixStatus::unavailable_flags, true};
        if (*half & (std::uint16_t(1) << index))
            offset = 2;
    }
    if (selection == SceneMatrixSelection::terminal)
        try {
            transform_math::require_profile();
        } catch (const std::exception &) {
            return {SceneMatrixStatus::unsupported_numeric, true};
        }
    if (!bindings_.bind_pose(model, matrices_[index]))
        return {SceneMatrixStatus::binding_refused, true};
    channel.program = program;
    channel.model_slot = model;
    channel.progress = selection == SceneMatrixSelection::terminal ? 2 : 1;
    channel.playback = selection == SceneMatrixSelection::terminal ? 0 : 1;
    channel.cursor = 1;
    channel.transform = definition.transform;
    channel.contact.gate = tables_.metadata[group][0];
    channel.curve = std::uint8_t(4u * group + offset);
    if (selection == SceneMatrixSelection::terminal) {
        const auto status = evaluate_first(index);
        if (status != SceneMatrixStatus::completed)
            return {status, true, true};
    }
    return {SceneMatrixStatus::completed, true, true};
}
} // namespace reo::native::gameplay_scenario
