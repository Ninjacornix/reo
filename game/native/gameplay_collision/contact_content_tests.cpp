#include "contact_content.hpp"
#include "content_support.hpp"
#include <fstream>
#include <iterator>
unsigned definitions{}, active{}, geometries{}, stock_values{}, random_rows{}, stock_multipliers{};
std::vector<std::byte> file(const char* name) {
    std::ifstream input(name, std::ios::binary);
    std::vector<char> raw((std::istreambuf_iterator<char>(input)), {});
    std::vector<std::byte> result(raw.size());
    std::memcpy(result.data(), raw.data(), raw.size());
    return result;
}
void template_equal(const d::Template& t, const std::uint8_t* p) {
    check(t.base == ref_read<std::int16_t>(p, 2) &&
              t.route_amount == ref_read<std::int16_t>(p, 0x14),
          "owned signed descriptor scalars");
    check(t.damage_kind == p[4] && t.priority == p[6] && t.auxiliary_a == p[7] &&
              t.auxiliary_b == p[8] && t.max_contacts == p[0xa] && t.cooldown == p[0xb] &&
              t.flags == p[0xd] && t.actor_sound == p[0xf] && t.kind == p[0x11] &&
              t.response_code == p[0x12] && t.value_id == p[0x13] && t.query_flags == p[0x16] &&
              t.response_flags == p[0x17] && t.progression == p[0x18] && t.scene_sound == p[0x19] &&
              t.probability == p[0x1a],
          "owned descriptor named response fields");
}
void vector_equal(c::Vec3 actual, c::Vec3 expected) {
    check(std::bit_cast<std::uint32_t>(actual.x) == std::bit_cast<std::uint32_t>(expected.x) &&
              std::bit_cast<std::uint32_t>(actual.y) == std::bit_cast<std::uint32_t>(expected.y) &&
              std::bit_cast<std::uint32_t>(actual.z) == std::bit_cast<std::uint32_t>(expected.z),
          "owned shape float bits");
}
void joint_equal(const std::optional<std::uint16_t>& native, std::uint16_t original) {
    check(native ? *native == original : original == 65535, "owned shape root/joint selection");
}
void geometry_equal(const d::Definition& d, std::uint32_t selector) {
    const auto* m = storage().data();
    const auto tag = ref_read<std::uint32_t>(m, selector),
               pointer = ref_read<std::uint32_t>(m, selector + 4);
    if (!pointer && !d.lifetime) {
        check(std::holds_alternative<std::monostate>(d.geometry),
              "zero-lifetime null geometry remains inactive");
        return;
    }
    check(d.geometry.index() == tag, "owned shape selector kind");
    if (tag == 1) {
        const auto& g = std::get<d::SegmentShape>(d.geometry);
        vector_equal(g.origin, ref_read<c::Vec3>(m, pointer));
        vector_equal(g.direction, ref_read<c::Vec3>(m, pointer + 12));
        check(g.range == ref_read<std::uint16_t>(m, pointer + 24), "owned segment range");
        joint_equal(g.joint, ref_read<std::uint16_t>(m, pointer + 26));
    } else if (tag == 2) {
        const auto& g = std::get<d::SweepShape>(d.geometry);
        vector_equal(g.center, ref_read<c::Vec3>(m, pointer));
        check(g.radius == ref_read<std::uint16_t>(m, pointer + 12), "owned sweep radius");
        joint_equal(g.joint, ref_read<std::uint16_t>(m, pointer + 14));
    } else if (tag == 3) {
        const auto& g = std::get<d::MarginShape>(d.geometry);
        vector_equal(g.origin, ref_read<c::Vec3>(m, pointer));
        vector_equal(g.direction, ref_read<c::Vec3>(m, pointer + 12));
        check(g.margin == ref_read<std::uint16_t>(m, pointer + 24) &&
                  g.range == ref_read<std::uint16_t>(m, pointer + 26),
              "owned margin/range");
        joint_equal(g.joint, ref_read<std::uint16_t>(m, pointer + 28));
    } else if (tag == 4) {
        const auto& g = std::get<d::AngularShape>(d.geometry);
        vector_equal(g.origin, ref_read<c::Vec3>(m, pointer));
        vector_equal(g.direction, ref_read<c::Vec3>(m, pointer + 12));
        check(g.extent == ref_read<std::uint16_t>(m, pointer + 24) &&
                  g.range == ref_read<std::uint16_t>(m, pointer + 26),
              "owned angular extent/range");
        joint_equal(g.joint, ref_read<std::uint16_t>(m, pointer + 28));
    }
    ++geometries;
}
int main(int argc, char** argv) {
    check(argc == 3, "converted asset and independent owned overlay supplied");
    auto asset = file(argv[1]), overlay = file(argv[2]);
    check(overlay.size() == 1913088, "owned source overlay size");
    auto* m = storage().data();
    std::memcpy(m + 0x570000, overlay.data(), overlay.size());
    auto catalog = d::Catalog::import(asset);
    const std::array<unsigned, 3> counts{512, 139, 5};
    for (unsigned bank = 0; bank < 3; ++bank)
        check(catalog.size(std::uint8_t(bank)) == counts[bank], "full physical bank extent");
    const auto& tables = catalog.tables();
    for (unsigned i = 0; i < 100; ++i)
        check(std::bit_cast<std::uint32_t>(tables.probabilities[i]) ==
                  ref_read<std::uint32_t>(m, 0x719a6c + 68 * i),
              "owned strided probability float bits");
    for (unsigned i = 0; i < 128; ++i) {
        check(tables.weights[i] == ref_read<std::int16_t>(m, 0x7346e0 + 2 * i),
              "owned integer weighting table");
        for (unsigned bin = 0; bin < 3; ++bin) {
            const auto v = (*tables.flat)[i].bins[bin];
            check(v.amount == ref_read<std::int16_t>(m, 0x73bb00 + 12 * i + 4 * bin) &&
                      v.kind == m[0x73bb02 + 12 * i + 4 * bin],
                  "owned flat distance values");
        }
    }
    for (unsigned category = 0; category < 256; ++category) {
        const auto& t = tables.categories[category];
        check(t.admitted == (category < 72), "physical category admission window is explicit");
        if (category >= 72)
            continue;
        const auto pointer = ref_read<std::uint32_t>(m, 0x73b9e0 + 4 * category);
        check(bool(t.entries) == bool(pointer),
              "owned null/category pointer converted into owned values");
        if (!t.entries)
            continue;
        for (unsigned i = 0; i < 128; ++i)
            for (unsigned bin = 0; bin < 3; ++bin) {
                const auto v = (*t.entries)[i].bins[bin];
                check(v.amount == ref_read<std::int16_t>(m, pointer + 12 * i + 4 * bin) &&
                          v.kind == m[pointer + 12 * i + 4 * bin + 2],
                      "owned category distance values");
            }
    }
    for (const auto& [key, values] : tables.random) {
        for (unsigned difficulty = 0; difficulty < 4; ++difficulty)
            for (unsigned roll = 0; roll < 8; ++roll) {
                check(values.damage[difficulty][roll] ==
                              ref_read<std::uint16_t>(m, 0x72bea0 + 64 * key + 16 * difficulty +
                                                             2 * roll) &&
                          values.progression[difficulty][roll] ==
                              ref_read<std::uint16_t>(m, 0x72d460 + 64 * key + 16 * difficulty +
                                                             2 * roll),
                      "exact requested owned random value windows");
            }
        ++random_rows;
    }
    check(!tables.random.contains(-2400) && !tables.random.contains(9999),
          "no original instruction/out-of-data bytes imported as response values");
    Roster roster;
    roster.subjects[0].contact.related = roster.subjects[1].id;
    roster.subjects[1].character = 1;
    PS2Runtime runtime;
    const auto initialize = [&] {
        auto ctx = context(0x5da040);
        o2_005DA040_0x5da040(m, &ctx, &runtime);
    };
    for (unsigned bank = 0; bank < 3; ++bank)
        for (unsigned ordinal = 0; ordinal < counts[bank]; ++ordinal) {
            initialize();
            roster.write();
            auto attached = context(0x5da2c0);
            attached.g[4].lo = address(0);
            attached.g[5].lo = ordinal;
            attached.g[6].lo = bank;
            o2_005DA2C0_0x5da2c0(m, &attached, &runtime);
            const auto packet = ref_read<std::uint32_t>(m, 0x3b54c8);
            check(packet >= 0x3e72f0 && packet < 0x3e82f0,
                  "actual original attachment allocated physical packet");
            const auto definition = catalog.find(std::uint8_t(bank), std::int32_t(ordinal));
            check(bool(definition), "native definition admitted");
            check(definition->startup == m[packet + 0xe] &&
                      definition->lifetime == m[packet + 0xf] &&
                      definition->mask == m[packet + 0x19] &&
                      definition->attachment_flags == m[packet + 0x1a] &&
                      definition->key == m[packet + 0xd],
                  "native content agrees with complete original bank attachment");
            check(ref_read<std::uint32_t>(m, packet + 8) == address(0) &&
                      ref_read<std::uint32_t>(m, packet + 0x2c) == address(1) &&
                      m[packet + 0x2a] == bank,
                  "original attachment owner/related/bank identity");
            const auto descriptor = ref_read<std::uint32_t>(m, packet + 0x14);
            template_equal(definition->response, m + descriptor);
            geometry_equal(*definition, ref_read<std::uint32_t>(m, packet + 0x10));
            ++definitions;
            if (!definition->lifetime)
                continue;
            ++active;
            auto& first = roster.subjects[0];
            auto& second = roster.subjects[1];
            second.actor.category = 0;
            second.character = 1;
            second.contact.damage_scale = 1.25f;
            for (unsigned category = 0; category < 72; ++category)
                for (float distance : {199.999f, 200.0f, 600.0f}) {
                    first.actor.slot = std::uint8_t(category);
                    first.position = {};
                    second.position = {distance, 0, 0};
                    roster.write();
                    for (bool flat : {false, true}) {
                        auto ctx = context(flat ? 0x5a8a50 : 0x5a87a0);
                        ctx.g[4].lo = address(0);
                        ctx.g[5].lo = address(1);
                        ctx.g[6].lo = descriptor;
                        ctx.g[7].lo = 0x32000;
                        ctx.f[12] = 2;
                        if (flat)
                            o2_005A8A50_0x5a8a50(m, &ctx, &runtime);
                        else
                            o2_005A87A0_0x5a87a0(m, &ctx, &runtime);
                        const auto actual =
                            flat ? d::flat_value(first.view(), second.view(), definition->response,
                                                 2, tables)
                                 : d::category_value(first.view(), second.view(),
                                                     definition->response, 2, tables);
                        check(actual.status == d::Status::completed &&
                                  actual.value.amount ==
                                      std::bit_cast<std::int16_t>(std::uint16_t(ctx.g[2].lo)) &&
                                  actual.value.kind == m[0x32000],
                              "owned converted tables drive complete original contact value "
                              "calculators");
                        ++stock_values;
                    }
                }
            for (unsigned variant = 0; variant < 4; ++variant) {
                first.actor.auxiliary_status = variant % 2 ? 0x800 : 0;
                first.contact.probability_bonus = float(int(variant) * 20 - 10);
                roster.write();
                Feedback feedback(roster);
                feedback.result = 1;
                ref_write(m, 64, 1u);
                delivery_oracle::feedback.clear();
                s::Random random;
                random.seed(std::uint8_t(ordinal));
                ref_write(m, 0x3244b0, std::uint16_t(ordinal & 255));
                auto ctx = context(0x6683e0);
                ctx.g[4].lo = address(0);
                ctx.g[5].lo = packet;
                o2_006683E0_0x6683e0(m, &ctx, &runtime);
                d::Packet native;
                native.source = first.id;
                native.key = definition->key;
                native.response = definition->response;
                check(d::multiplier(first.view(), native, tables, random, feedback) == ctx.f[0] &&
                          random.state().primary == ref_read<std::uint16_t>(m, 0x3244b0) &&
                          feedback.trace == delivery_oracle::feedback,
                      "owned converted probability keys preserve original RNG and feedback");
                ++stock_multipliers;
            }
        }
    auto lease = catalog.find(0, 1);
    const auto base = lease->response.base;
    std::fill(asset.begin(), asset.end(), std::byte(0));
    check(lease->response.base == base,
          "converted definitions do not borrow encoded asset storage");
    catalog = {};
    check(lease->response.base == base && !catalog.find(0, 1), "definition lease outlives catalog");
    bool rejected{};
    try {
        (void)catalog.tables();
    } catch (const std::logic_error&) {
        rejected = true;
    }
    check(rejected, "absent content is explicit");
    const auto original = file(argv[1]);
    for (std::size_t length : {0u, 7u, 12u, 31u, 39u, 500u, 2000u, 20000u}) {
        rejected = false;
        try {
            (void)d::Catalog::import(std::span(original).first(length));
        } catch (const std::invalid_argument&) {
            rejected = true;
        }
        check(rejected, "partial converted archive is refused before publication");
    }
    auto trailing = original;
    trailing.push_back(std::byte(0));
    rejected = false;
    try {
        (void)d::Catalog::import(trailing);
    } catch (const std::invalid_argument&) {
        rejected = true;
    }
    check(rejected, "unversioned trailing data refuses");
    std::printf("{\"checks\":%u,\"definitions\":%u,\"active_definitions\":%u,\"geometry_records\":%"
                "u,\"stock_value_cases\":%u,\"stock_multiplier_cases\":%u,\"random_rows\":%u,"
                "\"game_launched\":false}\n",
                checks, definitions, active, geometries, stock_values, stock_multipliers,
                random_rows);
}
