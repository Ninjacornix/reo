#include "game/native/gameplay_scene/record_pool.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <iostream>
#include <vector>

using namespace reo::native::gameplay_scene;
std::uint64_t checks{}, calls{};
void check(bool value) { ++checks; if (!value) throw std::runtime_error("Shared record pool mismatch"); }
void original_transform_port(std::uint8_t* ram, R5900Context* c, PS2Runtime*) {
    check(c->pc == 0x107c68);
    const auto at = GPR_U32(c, 4), length = GPR_U32(c, 6);
    check(at <= 0x2000000 && length <= 0x2000000 - at);
    std::memset(ram + at, int(GPR_U32(c, 5) & 255), length);
    c->pc = GPR_U32(c, 31);
}
std::uint32_t original(std::uint32_t at, std::uint8_t* ram, std::uint32_t arg) {
    R5900Context c; PS2Runtime runtime;
    SET_GPR_U32(&c, 29, 0x1fff000); SET_GPR_U32(&c, 4, arg); SET_GPR_U32(&c, 31, 0x1ff0000);
    if (at == 0x5c1120) o2_005C1120_0x5c1120(ram, &c, &runtime);
    else if (at == 0x5c11b0) o2_005C11B0_0x5c11b0(ram, &c, &runtime);
    else o2_005C12A0_0x5c12a0(ram, &c, &runtime);
    check(c.pc == 0x1ff0000); ++calls; return GPR_U32(&c, 2);
}
int main() {
    std::vector<std::uint8_t> ram(0x2000000);
    struct Live { RecordId id; std::uint32_t address, label; };
    std::uint32_t random = 0x5c1390;
    const auto next = [&] { random = random * 1664525u + 1013904223u; return random; };
    for (unsigned episode = 0; episode < 32; ++episode) {
        RecordPool<std::uint32_t> pool; std::vector<Live> live;
        original(0x5c1120, ram.data(), 0);
        for (unsigned step = 0; step < 2048; ++step) {
            if (live.empty() || (next() % 5 != 0 && live.size() < 128)) {
                const auto placement = next() & 1;
                const auto label = episode * 2048 + step + 1;
                const auto id = pool.create(label, placement ? Placement::oldest : Placement::newest);
                const auto at = original(0x5c11b0, ram.data(), placement);
                check(bool(id) == bool(at));
                if (id) { live.push_back({*id, at, label}); transform_write(ram.data(), at + 0x40, label); }
            } else {
                const auto index = next() % live.size(); auto retired = live[index];
                auto lease = pool.acquire(retired.id); check(bool(lease));
                const auto continuation = lease->next;
                check(pool.retire(retired.id)); check(!pool.acquire(retired.id));
                check(original(0x5c12a0, ram.data(), retired.address) == 1);
                check(lease->value == retired.label && lease->next == continuation);
                check(!pool.retire(retired.id));
                live.erase(live.begin() + index);
            }
            check(pool.size() == live.size());
            check(transform_read<std::uint16_t>(ram.data(), 0x3b5150) == 128 - live.size());
            const auto order = pool.ordered(); check(order.size() == live.size());
            auto at = transform_read<std::uint32_t>(ram.data(), 0x3b5158);
            for (const auto& id : order) {
                const auto node = pool.acquire(id); check(node && at);
                check(node->value == transform_read<std::uint32_t>(ram.data(), at + 0x40));
                at = transform_read<std::uint32_t>(ram.data(), at + 0x2c);
            }
            check(!at); at = transform_read<std::uint32_t>(ram.data(), 0x3b5160);
            for (auto node = pool.first(); node; node = node->next) {
                check(at && node->value == transform_read<std::uint32_t>(ram.data(), at + 0x40));
                at = transform_read<std::uint32_t>(ram.data(), at + 0x28);
            }
            check(!at);
        }
        std::vector<RecordId> old; for (const auto& item : live) old.push_back(item.id);
        pool.clear(); check(pool.size() == 0 && pool.ordered().empty() && !pool.first());
        for (const auto& id : old) check(!pool.acquire(id));
        auto once = pool.create(9); check(bool(once));
        RecordPool<std::uint32_t> foreign; check(!foreign.acquire(*once));
    }
    RecordPool<std::uint32_t> exhausted(1, 1);
    auto id = exhausted.create(7); auto retained = exhausted.acquire(*id);
    check(exhausted.retire(*id) && !exhausted.create(8) && retained->value == 7);
    RecordPool<std::uint32_t> capacity; for (unsigned i = 0; i < 128; ++i) check(bool(capacity.create(i)));
    check(!capacity.create(129));
    auto first = capacity.first(); auto second = first->next; auto third = second->next;
    check(capacity.retire(second->id)); check(first->next == third);
    check(capacity.retire(first->id)); check(first->next == third);
    const auto rev = capacity.revision(); capacity.touch(); check(capacity.revision() != rev);
    std::cout << "{\"checks\":" << checks << ",\"original_calls\":" << calls << ",\"status\":\"passed\"}\n";
}
