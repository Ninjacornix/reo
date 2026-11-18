#include "contact_packets.hpp"
#include "packets_support.hpp"
#include <fstream>
#include <iterator>
unsigned operations{}, attachments{}, generations{};
struct Entry {
    d::PacketId id;
    std::uint32_t original{};
};
std::array<Entry, 64> mapping;
std::uint32_t original_id(d::PacketId id) {
    if (!id)
        return 0;
    for (const auto& e : mapping)
        if (e.id == id)
            return e.original;
    check(false, "active packet identity maps to original invocation");
    return 0;
}
void equal(d::Packets& owner) {
    auto* m = storage().data();
    unsigned count{};
    for (const auto& e : mapping)
        if (e.id) {
            ++count;
            auto packet = owner.acquire(e.id);
            check(bool(packet), "active native packet lookup");
            check(original_id(packet.previous()) == ref_read<std::uint32_t>(m, e.original) &&
                      original_id(packet.next()) == ref_read<std::uint32_t>(m, e.original + 4),
                  "original bidirectional neighbor order");
            check(packet.state().enabled == m[e.original + 0xc], "original enabled byte");
        }
    check(owner.size() == count && count == 64u - ref_read<std::uint16_t>(m, 0x3b54c0),
          "original fixed capacity accounting");
    check(original_id(owner.head()) == ref_read<std::uint32_t>(m, 0x3b54c8) &&
              original_id(owner.tail()) == ref_read<std::uint32_t>(m, 0x3b54d0),
          "original head/tail insertion and unlink");
}
void create(d::Packets& owner, bool prepend) {
    auto* m = storage().data();
    auto ctx = context(0x5da0d0);
    ctx.g[4].lo = prepend;
    PS2Runtime runtime;
    o2_005DA0D0_0x5da0d0(m, &ctx, &runtime);
    const auto original = std::uint32_t(ctx.g[2].lo);
    const auto native = owner.create(prepend);
    check((native.status == d::PacketStatus::completed) == bool(original),
          "actual original free-stack allocation admission");
    if (original) {
        for (auto& e : mapping)
            if (!e.id) {
                e = {native.id, original};
                break;
            }
        const auto lease = owner.acquire(native.id);
        const auto& state = lease.state();
        check(!state.delivery.source && !state.delivery.cached_related && !state.definition &&
                  state.enabled == 0 && state.startup == 0 && state.lifetime == 0 &&
                  state.cooldown == 0 && state.contacts == 0 && state.previous_valid == 0,
              "new native packet has cleared typed state");
    } else
        check(native.status == d::PacketStatus::full, "full source pool reports full");
    equal(owner);
    ++operations;
}
void release(d::Packets& owner, unsigned index) {
    auto* m = storage().data();
    auto& e = mapping[index];
    const auto old = e.id;
    auto lease = owner.acquire(old);
    lease.state().enabled = 0xa5;
    m[e.original + 0xc] = 0xa5;
    auto ctx = context(0x5da1c0);
    ctx.g[4].lo = e.original;
    PS2Runtime runtime;
    o2_005DA1C0_0x5da1c0(m, &ctx, &runtime);
    check(owner.release(old), "qualified active packet release");
    check(!owner.acquire(old) && lease.state().enabled == m[e.original + 0xc] &&
              !owner.release(old),
          "retirement keeps invocation lease and refuses repeated release");
    e = {};
    equal(owner);
    ++operations;
    ++generations;
}
int main(int argc, char** argv) {
    auto* m = storage().data();
    auto reset = context(0x5da040);
    PS2Runtime runtime;
    o2_005DA040_0x5da040(m, &reset, &runtime);
    d::Packets owner;
    equal(owner);
    for (unsigned i = 0; i < 65; ++i)
        create(owner, i % 2);
    std::mt19937 random(0x5da0d0);
    for (unsigned i = 0; i < 5000; ++i) {
        std::vector<unsigned> active;
        for (unsigned j = 0; j < 64; ++j)
            if (mapping[j].id)
                active.push_back(j);
        if (!active.empty() && random() % 3 == 0)
            release(owner, active[random() % active.size()]);
        else
            create(owner, random() % 2);
    }
    for (unsigned i = 0; i < 64; ++i)
        if (mapping[i].id)
            release(owner, i);
    d::Packets other;
    const auto foreign = other.create(true);
    check(!owner.acquire(foreign.id) && !owner.release(foreign.id),
          "foreign packet domain cannot attach");
    auto old = owner.create(true);
    auto lease = owner.acquire(old.id);
    lease.state().enabled = 191;
    owner.close();
    check(owner.closed() && owner.size() == 0 && !owner.head() && !owner.tail() &&
              lease.state().enabled == 0 && !owner.acquire(old.id) &&
              owner.create(true).status == d::PacketStatus::closed,
          "close retires domain and preserves safe leased state");
    check(argc == 3, "converted content plus independently owned overlay supplied");
    std::ifstream asset_file(argv[1], std::ios::binary), overlay_file(argv[2], std::ios::binary);
    std::vector<char> asset((std::istreambuf_iterator<char>(asset_file)), {}),
        overlay((std::istreambuf_iterator<char>(overlay_file)), {});
    check(overlay.size() == 1913088, "owned overlay size");
    std::memcpy(m + 0x570000, overlay.data(), overlay.size());
    const auto catalog = d::Catalog::import(std::as_bytes(std::span(asset)));
    Roster actors;
    actors.subjects[0].contact.related = actors.subjects[1].id;
    actors.write();
    for (unsigned bank = 0; bank < 3; ++bank) {
        d::Packets packets;
        reset = context(0x5da040);
        o2_005DA040_0x5da040(m, &reset, &runtime);
        mapping = {};
        std::vector<unsigned> active;
        for (unsigned ordinal = 0; ordinal < catalog.size(std::uint8_t(bank)); ++ordinal) {
            if (active.size() == 64) {
                for (const auto index : active)
                    release(packets, index);
                active.clear();
            }
            auto ctx = context(0x5da2c0);
            ctx.g[4].lo = address(0);
            ctx.g[5].lo = ordinal;
            ctx.g[6].lo = bank;
            o2_005DA2C0_0x5da2c0(m, &ctx, &runtime);
            const auto original = ref_read<std::uint32_t>(m, 0x3b54c8);
            const auto native = packets.attach(catalog, std::uint8_t(bank), std::int32_t(ordinal),
                                               actors.subjects[0].view());
            check(native.status == d::PacketStatus::completed, "native stock attachment admitted");
            unsigned slot{};
            while (mapping[slot].id)
                ++slot;
            mapping[slot] = {native.id, original};
            active.push_back(slot);
            const auto lease = packets.acquire(native.id);
            const auto& state = lease.state();
            check(state.delivery.source == actors.subjects[0].id &&
                      state.delivery.cached_related == actors.subjects[1].id &&
                      state.delivery.bank == bank && state.delivery.key == m[original + 0xd],
                  "attachment native owner/related/bank identities");
            check(state.enabled == m[original + 0xc] && state.startup == m[original + 0xe] &&
                      state.lifetime == m[original + 0xf] && state.mask == m[original + 0x19] &&
                      state.attachment_flags == m[original + 0x1a] && state.contacts == 0 &&
                      state.cooldown == 0 && state.previous_valid == 0,
                  "complete original attachment timing/control metadata");
            equal(packets);
            ++attachments;
        }
    }
    std::printf("{\"checks\":%u,\"pool_operations\":%u,\"stock_attachments\":%u,\"retirement_"
                "cases\":%u,\"game_launched\":false}\n",
                checks, operations, attachments, generations);
}
