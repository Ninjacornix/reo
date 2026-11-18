// Host runtime/context sentinels. Original frame/guard word behavior is tested
// independently by sjuni_continuation_contract.py and root hybrid comparisons.
#define main baseline_operations_entry
#include "harness.cpp"
#undef main

static unsigned entered = 0, left = 0;
static std::array<unsigned, 3> original_bodies{};
static bool yield_enter = false, yield_leave = false, leave_unchanged = false,
            enter_unchanged = false;
static void (*enter_mutation)(PS2Runtime&, R5900Context*) = nullptr;
static R5900Context after_enter;
static bool compare_original_context = false;
static std::uint32_t paused_sp = 0, paused_ra = 0;

void write64(PS2Runtime& r, std::uint32_t a, std::uint64_t v) {
    wr(r, a, std::uint32_t(v));
    wr(r, a + 4, std::uint32_t(v >> 32));
}
std::uint64_t load64(PS2Runtime& r, std::uint32_t a) {
    return rd(r, a) | (std::uint64_t(rd(r, a + 4)) << 32);
}
void dependency_text(std::ifstream& file, PS2Runtime& r) {
    for (const auto& range : reo_native_sjuni::guard_text) {
        file.read(reinterpret_cast<char*>(r.memory().getRDRAM() + range.address), range.bytes);
        if (file.gcount() != range.bytes)
            throw std::runtime_error("missing private guard identity bytes");
    }
}
void restore_get(std::uint8_t*, R5900Context* c, PS2Runtime* r) {
    const auto frame = GPR_U32(c, 29);
    for (unsigned i = 0; i < 4; ++i)
        c->gpr[16 + i] = load64(*r, frame + 0x20 + 8 * i);
    c->gpr[31] = load64(*r, frame + 0x40);
    c->gpr[29] = frame + 0x50;
    c->pc = GPR_U32(c, 31);
}
void enter_guard(std::uint8_t*, R5900Context* c, PS2Runtime* r) {
    ++entered;
    check(r->depth > 0);
    if (enter_mutation) {
        auto action = enter_mutation;
        enter_mutation = nullptr;
        action(*r, c);
    }
    for (unsigned i = 1; i < 26; ++i)
        if (i < 16 || i == 24 || i == 25)
            c->gpr[i] = 0xD15EA5E000000000ull + i;
    if (enter_unchanged) {
        after_enter = *c;
        return;
    }
    if (yield_enter) {
        yield_enter = false;
        paused_sp = GPR_U32(c, 29);
        paused_ra = GPR_U32(c, 31);
        c->gpr[29] -= 0x40;
        c->gpr[31] = 0x141608;
        c->pc = 0x12A980;
        return;
    }
    const auto depth = rd(*r, 0x22A5F0);
    if (!depth)
        wr(*r, 0x22A5F4, 1);
    wr(*r, 0x22A5F0, depth + 1);
    c->pc = GPR_U32(c, 31);
    after_enter = *c;
}
void leave_guard(std::uint8_t*, R5900Context* c, PS2Runtime* r) {
    ++left;
    check(r->depth > 0);
    const auto depth = rd(*r, 0x22A5F0);
    check(depth > 0);
    wr(*r, 0x22A5F0, depth - 1);
    if (depth == 1)
        wr(*r, 0x22A5F4, 0);
    if (yield_leave) {
        yield_leave = false;
        paused_sp = GPR_U32(c, 29);
        paused_ra = GPR_U32(c, 31);
        c->gpr[29] -= 0x20;
        c->gpr[31] = 0x1416B8;
        c->pc = 0x12AA10;
        return;
    }
    if (!leave_unchanged)
        c->pc = GPR_U32(c, 31);
}
template <unsigned P> void original_post(std::uint8_t* ram, R5900Context* c, PS2Runtime* r) {
    ++original_bodies[P];
    if (compare_original_context) {
        check(c->gpr == after_enter.gpr);
        check(c->pc == after_enter.pc);
        check(c->branch_pc == after_enter.branch_pc);
    }
    // Sentinel records fallback/restore/leave behavior, not a duplicate queue algorithm.
    const auto frame = GPR_U32(c, 29);
    if constexpr (P == 0) {
        c->gpr[31] = 0x140418;
        c->pc = 0x13F270;
        r->lookupFunction(0x13F270)(ram, c, r);
        if (c->pc == 0x13F270)
            c->pc = 0x140418;
        if (c->pc == 0x140418)
            restore_get(ram, c, r);
    } else {
        for (unsigned i = 0; i < 3; ++i)
            c->gpr[16 + i] = load64(*r, frame + 8 * i);
        c->gpr[31] = load64(*r, frame + 0x18);
        c->gpr[29] = frame + 0x20;
        c->pc = 0x13F270;
        r->lookupFunction(0x13F270)(ram, c, r);
        if (c->pc == 0x13F270)
            c->pc = GPR_U32(c, 31);
    }
}
template <unsigned P> void original_method(std::uint8_t* ram, R5900Context* c, PS2Runtime* r) {
    ++calls[P + 1];
    const auto stack = GPR_U32(c, 29), frame = stack - (P == 0 ? 0x50 : 0x20);
    const unsigned count = P == 0 ? 4 : 3;
    for (unsigned i = 0; i < count; ++i)
        write64(*r, frame + (P == 0 ? 0x20 : 0) + 8 * i, c->gpr[16 + i]);
    write64(*r, frame + (P == 0 ? 0x40 : 0x18), c->gpr[31]);
    c->gpr[16] = c->gpr[4];
    c->gpr[17] = c->gpr[P == 0 ? 7 : 6];
    c->gpr[18] = c->gpr[5];
    if constexpr (P == 0)
        c->gpr[19] = c->gpr[6];
    c->gpr[29] = frame;
    c->gpr[31] = reo_native_sjuni::post_entries[P];
    c->pc = 0x13F258;
    r->lookupFunction(0x13F258)(ram, c, r);
    if (c->pc == 0x13F258)
        c->pc = reo_native_sjuni::post_entries[P];
    if (c->pc == reo_native_sjuni::post_entries[P])
        original_post<P>(ram, c, r);
}
void guard_setup(PS2Runtime& r) {
    setup(r);
    wr(r, 0x2649E0, 0x12A968);
    wr(r, 0x2649E4, 0);
    wr(r, 0x2649E8, 0x12A9F0);
    wr(r, 0x2649EC, 0);
    wr(r, 0x22A5F0, 0);
    wr(r, 0x22A5F4, 0);
    entered = left = 0;
    original_bodies = {};
    calls = {};
    compare_original_context = false;
    enter_unchanged = false;
    yield_enter = yield_leave = leave_unchanged = false;
    enter_mutation = nullptr;
}
void seed(PS2Runtime& r) {
    wr(r, obj + 24, nodes);
    wr(r, obj + 20, nodes + 16);
    wr(r, nodes, 0);
    wr(r, nodes + 8, iop + 0x100);
    wr(r, nodes + 12, 64);
}
R5900Context guarded_context(unsigned p) {
    auto c = context(p + 1, 0, p == 0 ? 16 : desc);
    for (unsigned i = 16; i < 24; ++i)
        c.gpr[i] = 0xA11CE00000000000ull + i;
    return c;
}
void saved_context(const R5900Context& c, const R5900Context& before) {
    for (unsigned i = 16; i < 24; ++i)
        check(c.gpr[i] == before.gpr[i]);
    check(c.gpr[29] == before.gpr[29]);
    check(c.gpr[31] == before.gpr[31]);
    check(c.pc == std::uint32_t(before.gpr[31]));
}
void invoke(PS2Runtime& r, unsigned p, R5900Context& c) {
    r.lookupFunction(ep[p + 1])(r.memory().getRDRAM(), &c, &r);
    check(r.depth == 0);
}
void nested_put(PS2Runtime& r, R5900Context* outer) {
    wr(r, desc + 0x40, iop + 0x600);
    wr(r, desc + 0x44, 48);
    auto nested = guarded_context(1);
    nested.gpr[6] = desc + 0x40;
    nested.gpr[29] = GPR_U32(outer, 29) - 0x200;
    nested.gpr[31] = 0x1F0010;
    r.lookupFunction(ep[2])(r.memory().getRDRAM(), &nested, &r);
    check(nested.pc == 0x1F0010);
}
void invalid_post_input(PS2Runtime& r, R5900Context*) {
    wr(r, desc, 0);
    wr(r, desc + 4, 0);
}
void valid_post_input(PS2Runtime& r, R5900Context*) {
    wr(r, desc, iop + 0x300);
    wr(r, desc + 4, 48);
}

int main(int argc, char** argv) {
    check(argc >= 2);
    const std::string mode = argc > 2 ? argv[2] : "guarded";
    _putenv_s("REO_NATIVE_SJUNI", "1");
    _putenv_s("REO_NATIVE_SJUNI_GUARDED", "1");
    _putenv_s("REO_NATIVE_SJUNI_TRACE", mode == "trace-on" ? "1" : "");
    PS2Runtime r;
    for (unsigned i = 0; i < 7; ++i)
        r.registerFunction(ep[i], orig[i]);
    r.registerFunction(ep[1], original_method<0>);
    r.registerFunction(ep[2], original_method<1>);
    r.registerFunction(ep[3], original_method<2>);
    r.registerFunction(0x13F258, enter_guard);
    r.registerFunction(0x13F270, leave_guard);
    r.registerFunction(0x140418, restore_get);
    r.registerFunction(0x140360, original_post<0>);
    r.registerFunction(0x1404A0, original_post<1>);
    r.registerFunction(0x1405F8, original_post<2>);
    std::ifstream file(argv[1], std::ios::binary);
    check(bool(file));
    file.read(reinterpret_cast<char*>(r.memory().getRDRAM() + 0x140000), 0x840);
    check(file.gcount() == 0x840);
    dependency_text(file, r);
    std::uint32_t absent = mode == "missing-primary"    ? ep[0]
                           : mode == "missing-enter"    ? 0x13F258
                           : mode == "missing-leave"    ? 0x13F270
                           : mode == "missing-epilogue" ? 0x140418
                           : mode == "missing-post"     ? 0x1404A0
                                                        : 0;
    if (absent) {
        r.functions.erase(absent);
        check(r.lookupFunction(absent) != nullptr);
        check(!reo_native_sjuni::install(r));
        check(ps2_stubs::installed == 0);
        check(r.lookupFunction(ep[1]) == original_method<0>);
        std::puts("guarded missing-address admission rejected before installation");
        return 0;
    }
    if (mode == "bad-guard-hash") {
        r.memory().getRDRAM()[0x12A968] ^= 1;
        check(!reo_native_sjuni::install(r));
        check(ps2_stubs::installed == 0);
        return 0;
    }
    check(reo_native_sjuni::install(r));
    check(ps2_stubs::installed == 11);
    check(reo_native_sjuni::install(r));
    for (unsigned p = 0; p < 3; ++p) {
        guard_setup(r);
        if (p != 1)
            seed(r);
        wr(r, desc, p == 2 ? iop + 0xF0 : iop + 0x100);
        wr(r, desc + 4, p == 2 ? 16 : 32);
        auto c = guarded_context(p), before = c;
        invoke(r, p, c);
        saved_context(c, before);
        check(entered == 1 && left == 1 && original_bodies[p] == 0);
        check(rd(r, 0x22A5F0) == 0);
        check(rd(r, 0x22A5F4) == 0);
        check(rd(r, nodes + 12) == (p == 0 ? 48 : p == 1 ? 32 : 80));
        if (p == 0) {
            check(rd(r, desc) == iop + 0x100);
            check(rd(r, desc + 4) == 16);
        }
        for (unsigned i = 0; i < 16; ++i)
            check(rd(r, nodes + 16 * i + 4) == 0xCAFE0000u + i);
    }
    // Real enter runs once; latest valid descriptor is used despite poisoned a0..a3.
    guard_setup(r);
    wr(r, desc, iop + 0x100);
    wr(r, desc + 4, 16);
    enter_mutation = valid_post_input;
    auto c = guarded_context(1), before = c;
    invoke(r, 1, c);
    saved_context(c, before);
    check(rd(r, nodes + 8) == iop + 0x300);
    check(rd(r, nodes + 12) == 48);
    check(entered == 1 && left == 1 && original_bodies[1] == 0);
    // Nested entry changes actual queue before outer post-enter import.
    guard_setup(r);
    enter_mutation = nested_put;
    c = guarded_context(0);
    before = c;
    invoke(r, 0, c);
    saved_context(c, before);
    check(entered == 2 && left == 2);
    check(original_bodies[0] == 0 && original_bodies[1] == 0);
    check(rd(r, desc) == iop + 0x600);
    check(rd(r, nodes + 12) == 32);
    // Invalidated post-enter input MUST run original post body, not canonical ignore/reenter.
    guard_setup(r);
    wr(r, desc, iop + 0x100);
    wr(r, desc + 4, 16);
    enter_mutation = invalid_post_input;
    compare_original_context = true;
    c = guarded_context(1);
    before = c;
    invoke(r, 1, c);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[1] == 1);
    check(rd(r, obj + 24) == 0);
    // Unknown hook pair and a returning no-PC-update enter are unchanged fallback.
    guard_setup(r);
    wr(r, desc, iop + 0x100);
    wr(r, desc + 4, 16);
    wr(r, 0x2649E0, 0x123450);
    compare_original_context = true;
    c = guarded_context(1);
    before = c;
    invoke(r, 1, c);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[1] == 1);
    guard_setup(r);
    wr(r, desc, iop + 0x100);
    wr(r, desc + 4, 16);
    enter_unchanged = true;
    c = guarded_context(1);
    before = c;
    // Simulate original enter completed without setting PC, including its guard-depth effect.
    wr(r, 0x22A5F0, 1);
    wr(r, 0x22A5F4, 1);
    invoke(r, 1, c);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[1] == 1);
    // Enter yield leaves its interior context untouched; post wrapper resumes once.
    guard_setup(r);
    seed(r);
    yield_enter = true;
    c = guarded_context(0);
    before = c;
    invoke(r, 0, c);
    check(c.pc == 0x12A980 && c.gpr[29] == sp - 0x50 - 0x40);
    check(entered == 1 && left == 0);
    check(rd(r, nodes + 12) == 64);
    c.gpr[29] = paused_sp;
    c.gpr[31] = paused_ra;
    c.pc = paused_ra;
    wr(r, 0x22A5F0, 1);
    wr(r, 0x22A5F4, 1);
    r.lookupFunction(c.pc)(r.memory().getRDRAM(), &c, &r);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[0] == 0);
    check(rd(r, nodes + 12) == 48);
    // Unsupported resumed post preserves complete context into captured original.
    guard_setup(r);
    seed(r);
    yield_enter = true;
    c = guarded_context(0);
    before = c;
    invoke(r, 0, c);
    c.gpr[29] = paused_sp;
    c.gpr[31] = paused_ra;
    c.pc = paused_ra;
    wr(r, 0x22A5F0, 1);
    wr(r, 0x22A5F4, 1);
    wr(r, 0x22143C, 0);
    after_enter = c;
    compare_original_context = true;
    r.lookupFunction(c.pc)(r.memory().getRDRAM(), &c, &r);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[0] == 1);
    check(rd(r, nodes + 12) == 64);
    // Virtual caller-SP admission rejects an output inside the actual saved frame.
    guard_setup(r);
    seed(r);
    compare_original_context = true;
    c = guarded_context(0);
    c.gpr[7] = sp - 0x50 + 0x20;
    before = c;
    invoke(r, 0, c);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[0] == 1);
    check(rd(r, nodes + 12) == 64);
    // A completion binding removed after install is rejected before queue commit.
    guard_setup(r);
    seed(r);
    r.functions.erase(0x140418);
    compare_original_context = true;
    c = guarded_context(0);
    before = c;
    invoke(r, 0, c);
    saved_context(c, before);
    check(entered == 1 && left == 1 && original_bodies[0] == 1);
    check(rd(r, nodes + 12) == 64);
    r.registerFunction(0x140418, restore_get);
    // All three native frames complete correctly when leave returns without updating PC.
    for (unsigned p = 0; p < 3; ++p) {
        guard_setup(r);
        if (p != 1)
            seed(r);
        wr(r, desc, p == 2 ? iop + 0xF0 : iop + 0x100);
        wr(r, desc + 4, 16);
        leave_unchanged = true;
        c = guarded_context(p);
        before = c;
        invoke(r, p, c);
        saved_context(c, before);
        check(entered == 1 && left == 1 && original_bodies[p] == 0);
    }
    // All three leave yields resume existing original completion, never native body again.
    for (unsigned p = 0; p < 3; ++p) {
        guard_setup(r);
        if (p != 1)
            seed(r);
        wr(r, desc, p == 2 ? iop + 0xF0 : iop + 0x100);
        wr(r, desc + 4, 16);
        yield_leave = true;
        c = guarded_context(p);
        before = c;
        invoke(r, p, c);
        check(c.pc == 0x12AA10);
        check(entered == 1 && left == 1 && original_bodies[p] == 0);
        c.gpr[29] = paused_sp;
        c.gpr[31] = paused_ra;
        c.pc = paused_ra;
        if (p == 0)
            r.lookupFunction(c.pc)(r.memory().getRDRAM(), &c, &r);
        saved_context(c, before);
        check(entered == 1 && left == 1);
    }
    // Unrelated guard caller is delegated once, with no SJUNI completion/leave.
    guard_setup(r);
    c = context(0);
    c.pc = 0x13F258;
    c.gpr[31] = 0x171000;
    r.lookupFunction(c.pc)(r.memory().getRDRAM(), &c, &r);
    check(c.pc == 0x171000 && entered == 1 && left == 0);
    check(rd(r, obj + 24) == 0);
    if (mode == "trace-on") {
        guard_setup(r);
        for (unsigned i = 0; i < 17; ++i) {
            c = context(0);
            r.lookupFunction(ep[0])(r.memory().getRDRAM(), &c, &r);
            check(c.pc == 0x1F0000 && c.gpr[2] == 0 && calls[0] == 0);
        }
        check(reo_native_sjuni::trace_counts[0].load() == 17);
        check(reo_native_sjuni::trace_counts[8].load() > 0);
    } else {
        for (const auto& count : reo_native_sjuni::trace_counts)
            if (count.load() != 0)
                throw std::logic_error("trace-disabled guarded operation updated counter");
    }
    std::printf("guarded runtime adapter synthetic checks passed: %u\n", checks);
    return 0;
}
