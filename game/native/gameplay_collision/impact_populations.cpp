#include "impact_populations.hpp"
#include <bit>
namespace reo::native::gameplay_collision::delivery {
namespace {
namespace effects = gameplay_effects;
// Immutable stock authored selectors. Qualification verifies every value
// against owned File1 content; they are numeric resource IDs, not visual names.
constexpr std::array<std::int16_t, 68> oriented_styles{
    -1, 40,  40, 40, 40, 40, 40, 40, 40, 40, 40, 40, 43, 43, 40,  40, 40, 40, 70, 40, 80, 40, 70,
    75, 121, 70, 73, 40, 40, 75, 40, -1, -1, -1, -1, -1, -1, -1,  -1, -1, 50, -1, -1, -1, -1, -1,
    -1, -1,  -1, -1, -1, 40, -1, -1, -1, -1, -1, -1, 75, -1, 121, 70, -1, -1, -1, -1, -1, -1};
constexpr std::array<std::int8_t, 68> surface_styles{
    46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 46, 47, 48, 48, 46, 47, 46, 46, 46, 47, 46, 46, 49,
    49, 49, 49, 49, 46, 46, 46, 46, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1,
    -1, -1, -1, -1, -1, 46, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1, -1};
std::int16_t variant(std::uint16_t effect) {
    switch (effect) {
        case 0x2e:
        case 0x31:
            return 252;
        case 0x2f:
        case 0x30:
            return 254;
        case 0x37:
            return 255;
        default:
            return 0;
    }
}
bool admitted(effects::WorkStatus value) {
    return value != effects::WorkStatus::unavailable;
}
effects::WorkRequest request(const std::optional<transform_math::Matrix>& matrix, Vec3 point,
                             std::int16_t palette, std::uint16_t effect, std::uint32_t flags,
                             effects::WorkUpdate update) {
    return {matrix, transform_math::Vector{point.x, point.y, point.z}, palette, effect, 0, flags,
            update};
}
bool usable(const effects::WorkCreated& result) {
    return admitted(result.status) &&
           (result.status != effects::WorkStatus::completed || bool(result.edit));
}
} // namespace
ContactVisuals::ContactVisuals(effects::WorkBackend& works, gameplay_session::Random& random,
                               ImpactParameters& parameters)
    : works_(works), random_(random), parameters_(parameters) {}
Status ContactVisuals::oriented(const transform_math::Matrix& basis, Vec3& point,
                                std::uint8_t key) {
    if (key >= oriented_styles.size() || oriented_styles[key] == -1)
        return Status::completed;
    if (!works_.admitted())
        return Status::unadmitted_content;
    const auto selected = std::uint16_t(oriented_styles[key]);
    const auto create = [&](std::uint16_t id, const std::optional<transform_math::Matrix>& matrix,
                            std::int16_t palette, std::uint32_t flags, effects::WorkUpdate update) {
        return works_.create(request(matrix, point, palette, id, flags, update));
    };
    using Update = effects::WorkUpdate;
    if (selected == 0x46 || selected == 0x4b)
        return usable(create(selected, {}, 0, 0x9a993, Update::ordinary))
                   ? Status::completed
                   : Status::unadmitted_content;
    if (selected == 0x79) {
        if (!usable(create(0x79, {}, 0, 0x1a993, Update::ordinary)))
            return Status::unadmitted_content;
        return usable(create(0x2a, {}, 0, 0x1a993, Update::ordinary)) ? Status::completed
                                                                      : Status::unadmitted_content;
    }
    if (selected == 0x50) {
        const auto created = create(selected, {}, 0, 0x1a993, Update::scaled);
        if (!usable(created) ||
            (created.edit && (!created.edit->uniform_scale(2) || !created.edit->set_attributes(4))))
            return Status::unadmitted_content;
        return Status::completed;
    }
    if (selected == 0x49) {
        if (!usable(create(selected, {}, 0, 0x1a993, Update::ordinary)))
            return Status::unadmitted_content;
        return admitted(works_.refresh_companion()) ? Status::completed
                                                    : Status::unadmitted_content;
    }
    if (selected == 0x32)
        return usable(create(selected, basis, -1, 0x1a193, Update::oriented))
                   ? Status::completed
                   : Status::unadmitted_content;
    // Original191A40 transforms direction(0,0,-1), then adds
    // before any allocation. In particular, failed allocations keep the nudge.
    point.x = point.x + ((basis[0][0] * 0 + basis[1][0] * 0) + basis[2][0] * -1);
    point.y = point.y + ((basis[0][1] * 0 + basis[1][1] * 0) + basis[2][1] * -1);
    point.z = point.z + ((basis[0][2] * 0 + basis[1][2] * 0) + basis[2][2] * -1);
    auto created = create(selected, basis, -1, 0x1a193, Update::scaled);
    if (!usable(created))
        return Status::unadmitted_content;
    if (created.edit) {
        const auto angle = std::bit_cast<std::int16_t>(random_.request(1));
        if (!created.edit->third_angle(angle) || !created.edit->set_attributes(2))
            return Status::unadmitted_content;
    }
    if (!usable(create(selected + 1, basis, -1, 0x1a193, Update::ordinary)))
        return Status::unadmitted_content;
    return usable(create(selected + 2, basis, 0, 0x1a193, Update::ordinary))
               ? Status::completed
               : Status::unadmitted_content;
}
Status ContactVisuals::surface(View owner, const std::optional<transform_math::Matrix>& basis,
                               Vec3& point, std::uint8_t key) {
    if (key >= surface_styles.size() || surface_styles[key] == -1)
        return Status::completed;
    if (!works_.admitted())
        return Status::unadmitted_content;
    using Update = effects::WorkUpdate;
    const auto selected = std::uint16_t(surface_styles[key]);
    const auto finish = [&](const effects::WorkCreated& created) {
        return usable(created) && (!created.edit || created.edit->feedback(parameters_.modulation(),
                                                                           parameters_.scalar()));
    };
    if (selected == 0x30) {
        const auto created =
            works_.create(request(basis, point, variant(0x37), 0x37, 0x1a193, Update::ordinary));
        if (!finish(created))
            return Status::unadmitted_content;
    }
    if (selected == 0x2f) {
        point.x = point.x + (float(random_.request(1) & 63) - 32.0f);
        point.z = point.z + (float(random_.request(1) & 63) - 32.0f);
    }
    const auto created =
        works_.create(request(basis, point, variant(selected), selected, 0x1a193,
                              selected == 0x2f ? Update::scaled : Update::ordinary));
    if (!usable(created))
        return Status::unadmitted_content;
    if (created.edit && selected == 0x2f) {
        const auto scale = 1.0f + float(int(random_.request(1) & 31) - 16) / 100.0f;
        if (!created.edit->uniform_scale(scale) || !created.edit->set_attributes(4))
            return Status::unadmitted_content;
    }
    if (!finish(created))
        return Status::unadmitted_content;
    const auto translation = basis ? (*basis)[3] : std::array<float, 4>{};
    const Vec3 location{translation[0] + point.x, translation[1] + point.y,
                        translation[2] + point.z};
    return parameters_.sound(owner.actor.slot, location, 0x13) ? Status::completed
                                                               : Status::unadmitted_content;
}
} // namespace reo::native::gameplay_collision::delivery
