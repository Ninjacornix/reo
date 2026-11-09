#include "impact_populations.hpp"
#include "population_support.hpp"
#include <fstream>
namespace e = reo::native::gameplay_effects;
namespace transforms = reo::native::transform_math;
namespace po = population_oracle;
unsigned population_cases{}, attempts{}, successful{}, sounds{}, companions{}, refusals{};
float maximum_error{};
void equal(c::Vec3 a, c::Vec3 b, const char* why) {
    for (const auto pair : {std::pair{a.x, b.x}, std::pair{a.y, b.y}, std::pair{a.z, b.z}}) {
        const auto error = std::abs(pair.first - pair.second);
        maximum_error = std::max(maximum_error, error);
        if (!(error < 0.00001f))
            std::fprintf(stderr, "%s %g != %g\n", why, double(pair.first), double(pair.second));
        check(error < 0.00001f, why);
    }
}
struct Edit final : e::WorkEdit {
    a::EntityId identity() const noexcept override {
        return {};
    }
    float scale{1}, scalar{};
    std::int16_t angle{};
    std::uint16_t attributes{0x8000};
    transforms::Vector modulation;
    bool uniform_scale(float f) noexcept override {
        scale = f;
        return true;
    }
    bool third_angle(std::int16_t v) noexcept override {
        angle = v;
        return true;
    }
    bool set_attributes(std::uint16_t v) noexcept override {
        attributes = v;
        return true;
    }
    bool add_attributes(std::uint16_t v) noexcept override {
        attributes |= v;
        return true;
    }
    bool feedback(transforms::Vector v, float f) noexcept override {
        modulation = v;
        scalar = f;
        attributes |= 0x100;
        return true;
    }
};
struct Backend final : e::WorkBackend {
    struct Creation {
        e::WorkRequest request;
        std::shared_ptr<Edit> edit;
    };
    std::vector<Creation> creations;
    s::Random& random;
    unsigned pattern{}, refreshes{};
    bool present{}, available{}, supported{true};
    std::uint8_t active{7}, phase{9}, type{4}, timer{3};
    std::uint32_t update{0x123456};
    explicit Backend(s::Random& r) : random(r) {}
    bool admitted() const noexcept override {
        return supported;
    }
    e::WorkCreated create(const e::WorkRequest& request) noexcept override {
        const bool failed = ((pattern >> creations.size()) & 1) != 0;
        auto edit = failed ? nullptr : std::make_shared<Edit>();
        creations.push_back({request, edit});
        if (edit && request.variant == -1)
            (void)random.request(1);
        return {edit ? e::WorkStatus::completed
                     : (pattern & 4 ? e::WorkStatus::resource_missing : e::WorkStatus::pool_full),
                edit};
    }
    e::WorkStatus refresh_companion() noexcept override {
        ++refreshes;
        if (present) {
            timer = 10;
            return e::WorkStatus::completed;
        }
        if (!available)
            return e::WorkStatus::pool_full;
        active = 1;
        phase = 0;
        type = 0x1d;
        update = 0x654d90;
        return e::WorkStatus::completed;
    }
};
struct Parameters final : d::ImpactParameters {
    transforms::Vector values;
    float value{};
    std::vector<po::Sound> calls;
    transforms::Vector modulation() const override {
        return values;
    }
    float scalar() const override {
        return value;
    }
    bool sound(std::uint8_t slot, c::Vec3 point, std::uint16_t event) override {
        calls.push_back({slot, point, event});
        return true;
    }
};
int main(int argc, char** argv) {
    check(argc == 2, "explicit private owned table input");
    std::ifstream file(argv[1], std::ios::binary);
    std::vector<std::uint8_t> data((std::istreambuf_iterator<char>(file)), {});
    check(data.size() == 0x128 + 256, "complete bounded table windows");
    auto* m = storage().data();
    std::memcpy(m + 0x70b5e0, data.data(), 0x128);
    std::memcpy(m + 0x7123a0, data.data() + 0x128, 256);
    Roster roster;
    std::mt19937 rng(0x5dd9d0);
    for (unsigned n = 0; n < 32768; ++n) {
        const auto key = std::uint8_t(n);
        const bool surface = (n / 256) % 2;
        const unsigned pattern = (n / 512) % 8;
        const s::RandomState seed{std::uint16_t(rng()), std::uint16_t(rng()), std::uint8_t(rng())};
        s::Random random(seed);
        Backend backend(random);
        backend.pattern = pattern;
        backend.present = n % 3 == 0;
        backend.available = n % 5 != 0;
        Parameters parameters;
        parameters.values = {float(n % 11), -float(n % 13), float(n % 17)};
        parameters.value = float(n % 29) / 10;
        roster.subjects[1].actor.slot = std::uint8_t(rng());
        roster.write();
        ref_write(m, 0x3244b0, seed.primary);
        ref_write(m, 0x3244b8, seed.secondary);
        m[0x2b8de8] = seed.observed;
        ref_write(m, 0x4bac84, parameters.values);
        ref_write(m, 0x4bac90, parameters.value);
        transforms::Matrix matrix{};
        for (unsigned column = 0; column < 4; ++column)
            for (unsigned row = 0; row < 4; ++row)
                matrix[column][row] = float(int(rng() % 25) - 12) / 4;
        matrix[0][3] = matrix[1][3] = matrix[2][3] = 0;
        matrix[3][3] = 1;
        ref_write(m, 0x32000, matrix);
        const auto optional_matrix =
            surface && n % 3 == 0 ? std::optional<transforms::Matrix>{} : matrix;
        c::Vec3 point{float(n % 101), float(n % 73), -float(n % 211)};
        ref_write(m, 0x32100, point);
        po::creations.clear();
        po::sounds.clear();
        po::attempt = 0;
        po::pattern = pattern;
        po::companion_lookup = po::companion_allocations = 0;
        po::companion_present = backend.present;
        po::companion_available = backend.available;
        std::memset(m + po::companion, 0, 0x300);
        m[po::companion] = backend.active;
        m[po::companion + 1] = backend.phase;
        m[po::companion + 3] = backend.type;
        m[po::companion + 8] = backend.timer;
        ref_write(m, po::companion + 0x14, backend.update);
        const auto entry = surface ? 0x5dd9d0u : 0x5dd6f0u;
        auto ctx = context(entry);
        SET_GPR_U32(&ctx, 4, address(1));
        SET_GPR_U32(&ctx, 5, optional_matrix ? 0x32000 : 0);
        SET_GPR_U32(&ctx, 6, 0x32100);
        SET_GPR_U32(&ctx, 7, key);
        PS2Runtime runtime;
        if (surface)
            o2_005DD9D0_0x5dd9d0(m, &ctx, &runtime);
        else
            o2_005DD6F0_0x5dd6f0(m, &ctx, &runtime);
        d::ContactVisuals native(backend, random, parameters);
        const auto status = surface ? native.surface(*roster.find(roster.subjects[1].id),
                                                     optional_matrix, point, key)
                                    : native.oriented(matrix, point, key);
        check(status == d::Status::completed,
              "all stock selectors and natural allocation misses complete");
        equal(point, ref_read<c::Vec3>(m, 0x32100), "point mutation timing and axis-only offset");
        check(backend.creations.size() == po::creations.size(),
              "independent creation count despite allocation failures");
        for (unsigned i = 0; i < backend.creations.size(); ++i) {
            const auto& actual = backend.creations[i];
            const auto& original = po::creations[i];
            const auto& a = actual.request;
            const auto& b = original.request;
            check(a.variant == b.variant && a.effect == b.effect && a.mode == b.mode &&
                      a.flags == b.flags && a.update == b.update,
                  "exact flags/variants/effect/updater/order");
            check(a.basis == b.basis && bool(a.position) == bool(b.position),
                  "optional basis copy remains distinct from actor identity");
            if (a.position)
                equal({a.position->x, a.position->y, a.position->z},
                      {b.position->x, b.position->y, b.position->z},
                      "creation sees current mutable point");
            check(bool(actual.edit) == bool(original.at), "declared natural constructor result");
            if (actual.edit) {
                const auto& edit = *actual.edit;
                check(edit.angle == ref_read<std::int16_t>(m, original.at + 0x94) &&
                          edit.attributes == ref_read<std::uint16_t>(m, original.at + 0x23e),
                      "exact third angle and SET versus OR attributes");
                equal({edit.scale, edit.scale, edit.scale},
                      {ref_read<float>(m, original.at + 0xb4),
                       ref_read<float>(m, original.at + 0xb8),
                       ref_read<float>(m, original.at + 0xbc)},
                      "uniform scale and conditional RNG");
                const auto modulation = ref_read<c::Vec3>(m, original.at + 0x280);
                equal({edit.modulation.x, edit.modulation.y, edit.modulation.z}, modulation,
                      "actual5EAD70 feedback child propagation seam");
                check(edit.scalar == ref_read<float>(m, original.at + 0xa8),
                      "canonical current feedback scalar");
                ++successful;
            }
            ++attempts;
        }
        check(random.state().primary == ref_read<std::uint16_t>(m, 0x3244b0) &&
                  random.state().secondary == seed.secondary &&
                  random.state().observed == seed.observed,
              "actual original RNG including constructor seam interleaving");
        check(backend.refreshes == po::companion_lookup,
              "companion attempted even when selected effect allocation fails");
        check(backend.active == m[po::companion] && backend.phase == m[po::companion + 1] &&
                  backend.type == m[po::companion + 3] && backend.timer == m[po::companion + 8] &&
                  backend.update == ref_read<std::uint32_t>(m, po::companion + 0x14),
              "same-owner companion create or refresh fields");
        check(parameters.calls.size() == po::sounds.size(),
              "notification despite natural allocation failure; rejected selector skips");
        for (unsigned i = 0; i < parameters.calls.size(); ++i) {
            const auto& a = parameters.calls[i];
            const auto& b = po::sounds[i];
            check(a.slot == b.slot && a.event == b.event, "full authored actor slot/event");
            equal(a.point, b.point, "sound position basis translation plus mutated point");
            ++sounds;
        }
        companions += backend.refreshes;
        ++population_cases;
    }
    s::Random random;
    Backend missing(random);
    missing.supported = false;
    Parameters parameters;
    d::ContactVisuals unavailable(missing, random, parameters);
    transforms::Matrix matrix{};
    c::Vec3 point{1, 2, 3};
    check(unavailable.oriented(matrix, point, 1) == d::Status::unadmitted_content &&
              missing.creations.empty() && point.x == 1 && point.z == 3,
          "unknown backend refuses before mutation");
    ++refusals;
    check(unavailable.oriented(matrix, point, 0) == d::Status::completed &&
              unavailable.surface(*roster.find(roster.subjects[1].id), {}, point, 255) ==
                  d::Status::completed,
          "authored no-op selectors do not require an effect backend");
    ++refusals;
    std::printf(
        "{\"checks\":%u,\"population_cases\":%u,\"attempts\":%u,\"successful\":%u,\"sounds\":%u,"
        "\"companions\":%u,\"refusals\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",
        checks, population_cases, attempts, successful, sounds, companions, refusals,
        double(maximum_error));
}
