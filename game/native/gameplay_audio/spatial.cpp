#include "spatial.hpp"
#include <algorithm>
#include <bit>
#include <cmath>

namespace reo::native::gameplay_audio {
const Attenuation* attenuation(unsigned selector) noexcept {
    static constexpr Attenuation constant127{127, 127, 127, 127, 127, 127, 127, 127, 127,
                                             127, 127, 127, 127, 127, 127, 127, 127};
    static constexpr Attenuation falling{127, 127, 111, 95, 79, 63, 55, 47, 39,
                                         31,  23,  15,  8,  0,  0,  0,  0};
    static constexpr Attenuation constant120{120, 120, 120, 120, 120, 120, 120, 120, 120,
                                             120, 120, 120, 120, 120, 120, 120, 120};
    switch (selector) {
        case 0:
            return &constant127;
        case 1:
        case 2:
            return &falling;
        case 3:
            return &constant120;
        default:
            return nullptr;
    }
}
SpatialResult locate(Vector point, const SpatialContext& context,
                     const Attenuation& table) noexcept {
    const float dx = point.x - context.listener.x, dy = point.y - context.listener.y,
                dz = point.z - context.listener.z;
    const float distance = std::sqrt((dx * dx + dy * dy) + dz * dz);
    if (!(distance < 4800.0f))
        return {};
    if (distance <= 100.0f)
        return {Status::completed, table[0], 63};
    const auto& m = context.world_to_screen;
    float x = ((m[0][0] * point.x + m[1][0] * point.y) + m[2][0] * point.z) + m[3][0];
    const float w = ((m[0][3] * point.x + m[1][3] * point.y) + m[2][3] * point.z) + m[3][3];
    if (!std::isfinite(x) || !std::isfinite(w) || w == 0)
        return {Status::numeric_domain};
    x *= 1.0f / w;
    if (!std::isfinite(x))
        return {Status::numeric_domain};
    x = std::clamp(x, 0.0f, 640.0f);
    if (w < 0)
        x = 640.0f - x;
    const auto pan = static_cast<std::uint32_t>(x / 5.039370059967041f);
    const auto band = static_cast<unsigned>(std::floor(distance / 300.0f));
    const auto difference = std::bit_cast<std::int32_t>(table[band] - table[band + 1]);
    const float change =
        ((distance - 300.0f * static_cast<float>(band)) / 300.0f) * static_cast<float>(difference);
    if (!std::isfinite(change) || change < -2147483648.0f || change >= 2147483648.0f)
        return {Status::numeric_domain};
    const auto gain = table[band] - static_cast<std::uint32_t>(static_cast<std::int32_t>(change));
    if (!gain)
        return {};
    return {Status::completed, gain, pan};
}
Result positional(const Descriptors& rows, bool requested, std::uint8_t phase, Request request,
                  Vector point, const SpatialContext& context, unsigned selector,
                  gameplay_session::Random& random, CommandSink& sink) noexcept {
    const auto* table = attenuation(selector);
    if (!table)
        return {Status::invalid_input, -1, 0};
    const auto result = locate(point, context, *table);
    if (result.status != Status::completed)
        return {result.status, 0, 0};
    request.gain = result.gain;
    request.pan = result.pan;
    return route(rows, requested, phase, request, random, sink);
}
} // namespace reo::native::gameplay_audio
