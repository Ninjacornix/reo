#include <array>
#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <new>
static bool fail_allocation = false;
void* operator new(std::size_t n) {
    if (fail_allocation) {
        fail_allocation = false;
        throw std::bad_alloc();
    }
    if (auto* p = std::malloc(n ? n : 1))
        return p;
    throw std::bad_alloc();
}
void operator delete(void* p) noexcept {
    std::free(p);
}
void operator delete(void* p, std::size_t) noexcept {
    std::free(p);
}
#include "../runtime_adapter.cpp"
namespace bridge = reo::sjuni::bridge;
constexpr std::array<std::uint32_t, 7> ep{0x140288, 0x140300, 0x140438, 0x140590,
                                          0x1406D8, 0x140768, 0x1407A8};
static std::array<unsigned, 7> calls{};
template <unsigned I> void original(std::uint8_t*, R5900Context* c, PS2Runtime* p) {
    ++calls[I];
    assert(p->depth > 0);
    c->gpr[2] = 0xEEEE0000u + I;
    c->pc = GPR_U32(c, 31);
}
constexpr std::array<PS2Runtime::RecompiledFunction, 7> orig{
    original<0>, original<1>, original<2>, original<3>, original<4>, original<5>, original<6>};
constexpr std::uint32_t obj = 0x228C98, nodes = 0x221780, desc = 0x1800000, iop = 0x10000000,
                        sp = 0x1F00000;
static unsigned checks = 0;
void check(bool ok) {
    ++checks;
    if (!ok) {
        std::fprintf(stderr, "FAIL check %u\n", checks);
        std::exit(1);
    }
}
bridge::Memory memory(PS2Runtime& r) {
    return bridge::Memory(
        std::span<std::byte>(reinterpret_cast<std::byte*>(r.memory().getRDRAM()), PS2_RAM_SIZE));
}
void wr(PS2Runtime& r, std::uint32_t a, std::uint32_t v) {
    check(memory(r).write32(a, v));
}
std::uint32_t rd(PS2Runtime& r, std::uint32_t a) {
    std::uint32_t v = 0;
    check(memory(r).read32(a, v));
    return v;
}
void setup(PS2Runtime& r) {
    for (unsigned i = 0; i < 12; ++i)
        wr(r, obj + 4 * i, 0);
    wr(r, obj, 0x228C60);
    wr(r, obj + 4, 0x101);
    wr(r, obj + 8, 0x23DA78);
    wr(r, obj + 12, nodes);
    wr(r, obj + 16, 16);
    wr(r, obj + 20, nodes);
    wr(r, obj + 40, 0x140000);
    wr(r, obj + 44, obj);
    for (unsigned i = 0; i < 16; ++i) {
        wr(r, nodes + 16 * i, i < 15 ? nodes + 16 * (i + 1) : 0);
        wr(r, nodes + 16 * i + 4, 0xCAFE0000u + i);
        wr(r, nodes + 16 * i + 8, 0);
        wr(r, nodes + 16 * i + 12, 0);
    }
    wr(r, 0x221488, obj);
    wr(r, 0x221448, iop);
    wr(r, 0x22143C, 0x41000);
    wr(r, 0x2649E0, 0);
    wr(r, 0x2649E8, 0);
}
R5900Context context(unsigned i, std::uint32_t q = 0, std::uint32_t a2 = 0,
                     std::uint32_t a3 = desc) {
    R5900Context c;
    for (unsigned n = 0; n < 32; ++n)
        c.gpr[n] = 0x10000000u + n;
    c.gpr[0] = 0;
    c.pc = ep[i];
    c.gpr[4] = obj;
    c.gpr[5] = q;
    c.gpr[6] = a2;
    c.gpr[7] = a3;
    c.gpr[29] = sp;
    c.gpr[31] = 0x1F0000;
    c.gpr[2] = 0x12345678;
    return c;
}
void run(PS2Runtime& r, unsigned i, R5900Context& c, bool native) {
    const auto before = c;
    const auto count = calls[i];
    r.lookupFunction(ep[i])(r.memory().getRDRAM(), &c, &r);
    check(calls[i] == count + (native ? 0 : 1));
    check(c.pc == 0x1F0000);
    check(r.depth == 0);
    if (native) {
        for (unsigned n = 0; n < 32; ++n)
            if (n != 2)
                check(c.gpr[n] == before.gpr[n]);
        for (unsigned n = 0; n < 16; ++n)
            check(rd(r, nodes + 16 * n + 4) == 0xCAFE0000u + n);
    }
}
int main(int argc, char** argv) {
    check(argc >= 2);
    const std::string scenario = argc > 2 ? argv[2] : "operations";
    PS2Runtime r;
    for (unsigned i = 0; i < 7; ++i)
        r.registerFunction(ep[i], orig[i]);
    r.registerFunction(0x1404A0, orig[6]);
    _putenv_s("REO_NATIVE_SJUNI", "");
    check(!reo_native_sjuni::install(r));
    check(r.lookupFunction(ep[0]) == orig[0]);
    _putenv_s("REO_NATIVE_SJUNI", "1");
    check(!reo_native_sjuni::install(r));
    std::ifstream file(argv[1], std::ios::binary);
    check(bool(file));
    file.read(reinterpret_cast<char*>(r.memory().getRDRAM() + 0x140000), 0x840);
    check(file.gcount() == 0x840);
    r.functions.erase(ep[6]);
    check(!reo_native_sjuni::install(r));
    check(r.lookupFunction(ep[0]) == orig[0]);
    r.registerFunction(ep[6], orig[6]);
    if (scenario == "partial-install") {
        r.registrations_before_throw = 2;
        check(!reo_native_sjuni::install(r));
        r.registrations_before_throw = ~0u;
        check(ps2_stubs::installed == 2);
        auto partial = context(0);
        run(r, 0, partial, false);
        check(r.lookupFunction(ep[2]) == orig[2]);
        std::puts("partial registration fallback passed");
        return 0;
    }
    check(reo_native_sjuni::install(r));
    check(ps2_stubs::installed == 7);
    if (scenario == "changed-binding") {
        r.registerFunction(ep[0], orig[0]);
        check(!reo_native_sjuni::install(r));
        check(r.lookupFunction(ep[0]) == orig[0]);
        auto changed = context(1);
        run(r, 1, changed, false);
        std::puts("changed binding refusal passed");
        return 0;
    }
    if (scenario == "changed-memory") {
        auto retained = std::move(r.mem.bytes);
        r.mem.bytes = std::vector<std::uint8_t>(PS2_RAM_SIZE);
        std::memcpy(r.memory().getRDRAM() + 0x140000, retained.data() + 0x140000, 0x840);
        check(!reo_native_sjuni::install(r));
        auto changed = context(1);
        run(r, 1, changed, false);
        std::puts("changed RAM refusal passed");
        return 0;
    }
    if (scenario == "changed-text") {
        r.memory().getRDRAM()[0x140000] ^= 1;
        check(!reo_native_sjuni::install(r));
        auto changed = context(1);
        run(r, 1, changed, false);
        std::puts("changed loaded text refusal passed");
        return 0;
    }
    check(reo_native_sjuni::install(r));
    check(ps2_stubs::installed == 7);
    check(r.lookupFunction(0x1404A0) == orig[6]);
    setup(r);
    wr(r, desc, iop + 0x100);
    wr(r, desc + 4, 64);
    auto c = context(2, 0, desc);
    run(r, 2, c, true);
    check(c.gpr[2] == 0x12345678);
    check(rd(r, obj + 24) == nodes);
    check(rd(r, nodes + 8) == iop + 0x100);
    check(rd(r, nodes + 12) == 64);
    c = context(0);
    run(r, 0, c, true);
    check(c.gpr[2] == 64);
    c = context(1, 0, 32);
    run(r, 1, c, true);
    check(c.gpr[2] == 0x12345678);
    check(rd(r, desc) == iop + 0x100);
    check(rd(r, desc + 4) == 32);
    check(rd(r, nodes + 8) == iop + 0x120);
    c = context(3, 0, desc);
    run(r, 3, c, true);
    check(rd(r, nodes + 12) == 64);
    check(rd(r, nodes + 8) == iop + 0x100);
    c = context(4, 0, 128);
    run(r, 4, c, true);
    check(c.gpr[2] == 0);
    check(rd(r, desc) == 64);
    c = context(5);
    run(r, 5, c, true);
    check(c.gpr[2] == 1);
    c = context(6);
    run(r, 6, c, true);
    check(c.gpr[2] == 15);
    wr(r, 0x2649E0, 0x12A968);
    c = context(1, 0, 16);
    run(r, 1, c, false);
    check(rd(r, nodes + 12) == 64);
    c = context(0);
    run(r, 0, c, true);
    check(c.gpr[2] == 64);
    wr(r, 0x2649E0, 0);
    wr(r, desc, 0xA5A5A5A5);
    c = context(4, 4, 0);
    run(r, 4, c, false);
    check(rd(r, desc) == 0xA5A5A5A5);
    c = context(1, 0, 16, nodes);
    run(r, 1, c, false);
    check(rd(r, nodes + 12) == 64);
    c = context(1, 0, 16, sp - 4);
    run(r, 1, c, false);
    c = context(0);
    c.gpr[29] = nodes + 80;
    run(r, 0, c, false);
    c = context(0);
    c.gpr[5] = 0x100000000ull;
    run(r, 0, c, false);
    wr(r, 0x22143C, 0);
    c = context(0);
    run(r, 0, c, false);
    wr(r, 0x22143C, 0x41000);
    wr(r, nodes, nodes);
    c = context(0);
    run(r, 0, c, false);
    wr(r, nodes, 0);
    c = context(2);
    c.pc = 0x1404A0;
    {
        PS2Runtime::GuestExecutionScope outer(&r);
        const auto count = calls[2];
        r.lookupFunction(ep[2])(r.memory().getRDRAM(), &c, &r);
        check(calls[2] == count + 1);
        check(c.pc == 0x1F0000);
    }
    check(r.depth == 0);
    setup(r);
    wr(r, obj + 20, 0);
    wr(r, obj + 24, nodes);
    for (unsigned i = 0; i < 16; ++i) {
        wr(r, nodes + 16 * i, i < 15 ? nodes + 16 * (i + 1) : 0);
        wr(r, nodes + 16 * i + 8, iop + 0x100 + 64 * i);
        wr(r, nodes + 16 * i + 12, 32);
    }
    wr(r, obj + 40, 0xDEADBEEF);
    wr(r, desc, iop + 0x3000);
    wr(r, desc + 4, 16);
    c = context(2, 0, desc);
    run(r, 2, c, false);
    check(rd(r, nodes + 15 * 16 + 12) == 32);
    wr(r, desc, iop + 0x100 + 64 * 15 + 32);
    c = context(2, 0, desc);
    run(r, 2, c, true);
    check(rd(r, nodes + 15 * 16 + 12) == 48);
    c = context(6);
    run(r, 6, c, true);
    check(c.gpr[2] == 0);
    wr(r, desc, iop + 0xF0);
    wr(r, desc + 4, 16);
    c = context(3, 0, desc);
    run(r, 3, c, true);
    check(rd(r, nodes + 8) == iop + 0xF0);
    check(rd(r, nodes + 12) == 48);
    // Allocation failure occurs only in private admission/transaction state.
    c = context(0);
    const auto before = rd(r, nodes + 12);
    fail_allocation = true;
    run(r, 0, c, false);
    check(rd(r, nodes + 12) == before);
    c = context(0);
    run(r, 0, c, false);
    r.registerFunction(ep[0], orig[0]);
    check(!reo_native_sjuni::install(r));
    check(r.lookupFunction(ep[0]) == orig[0]);
    std::printf("native runtime adapter synthetic checks passed: %u\n", checks);
}
