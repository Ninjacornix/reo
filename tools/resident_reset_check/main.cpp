// Focused regression for reo_resident_live::resetVifControls (VIF1_FBRST bit0).
// Real PS2Runtime/PS2Memory/GS worker/resident session; the GPU backend is replaced
// through gs_backend_bridge::registerFactory by a recorder that applies operations
// in submission order, retires launches and serves control reads from its model.
// No game data, no Vulkan. Run: tools\resident_reset_check\run.bat
#include "ps2_runtime.h"
#include "gs_backend_route.h"
#include "resident_vif_live_hooks.h"
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <string>
#include <vector>

using namespace reo_resident_live;
namespace bridge = gs_backend_bridge;

namespace {
int failures = 0, checks = 0;
void check(bool ok, const char* what) {
    ++checks;
    if (!ok) {
        ++failures;
        std::printf("FAIL: %s\n", what);
    } else
        std::printf("ok:   %s\n", what);
}

struct Controls {
    uint32_t row[4]{}, col[4]{}, cycle = 0, mode = 0, mask = 0;
};
struct Event {
    char kind;
    size_t ops = 0;
    size_t controls = 0;
    size_t launches = 0;
    Barrier reason{};
    size_t retired = 0;
};

struct Recorder {
    std::mutex m;
    Controls model;
    std::vector<Event> events;
    std::vector<uint64_t> outstanding;
    std::vector<Controls> launchControls; // model at each Launch, in stream order
    uint64_t epoch = 0, generation = 0;
    void apply(const Operation& op) {
        auto* bytes = reinterpret_cast<uint8_t*>(&model);
        if (op.kind == Kind::Control || op.kind == Kind::ControlByteWrite) {
            if (op.controlByte + op.payload.size() > sizeof(model))
                throw std::runtime_error("control outside model");
            std::memcpy(bytes + op.controlByte, op.payload.data(), op.payload.size());
        } else if (op.kind == Kind::Launch) {
            outstanding.push_back(op.ordinal);
            launchControls.push_back(model);
        }
    }
} rec;

class RecordingBackend final : public bridge::Backend {
  public:
    bool init(const bridge::Init&, std::string&) override {
        return true;
    }
    void close() noexcept override {}
    void reset() override {}
    void rawGif(uint8_t, const uint8_t*, size_t) override {}
    void directRegister(uint8_t, uint64_t) override {}
    void privilegedWrite(uint32_t, uint8_t, uint64_t) override {}
    bridge::Frame capture(const bridge::Capture&) override {
        return {};
    }
    void exportVram(size_t, uint8_t* dst, size_t n) override {
        std::memset(dst, 0, n);
    }
    uint32_t readTransfer(uint8_t*, uint32_t) override {
        return 0;
    }
    bool clearContext(uint32_t, uint32_t, bool) override {
        return false;
    }
    void flush() override {}
    void residentEnqueue(const Batch& batch) override {
        std::lock_guard<std::mutex> l(rec.m);
        Event e{'Q', batch.operations.size()};
        for (const auto& op : batch.operations) {
            if (op.kind == Kind::Control || op.kind == Kind::ControlByteWrite)
                ++e.controls;
            if (op.kind == Kind::Launch)
                ++e.launches;
            rec.apply(op);
        }
        rec.epoch = batch.epoch;
        rec.generation = batch.bankGeneration;
        rec.events.push_back(e);
    }
    std::vector<Retired> residentRetire(Barrier reason, uint64_t epoch,
                                        uint64_t generation) override {
        std::lock_guard<std::mutex> l(rec.m);
        std::vector<Retired> out;
        for (auto ordinal : rec.outstanding) {
            Retired r{};
            r.epoch = epoch;
            r.bankGeneration = generation;
            r.ordinal = ordinal;
            r.ended = true;
            out.push_back(r);
        }
        rec.events.push_back({'R', 0, 0, 0, reason, out.size()});
        rec.outstanding.clear();
        return out;
    }
    void residentReadData(uint32_t, uint8_t* dst, uint32_t n) override {
        std::memset(dst, 0, n);
    }
    void residentReadControls(uint32_t offset, uint8_t* dst, uint32_t n) override {
        std::lock_guard<std::mutex> l(rec.m);
        std::memcpy(dst, reinterpret_cast<uint8_t*>(&rec.model) + offset, n);
    }
    void residentImportHandoff(Handoff& h) override {
        std::lock_guard<std::mutex> l(rec.m);
        std::memcpy(rec.model.row, h.row.data(), 16);
        std::memcpy(rec.model.col, h.column.data(), 16);
        rec.model.cycle = h.cycle;
        rec.model.mode = h.mode;
        rec.model.mask = h.mask;
        rec.events.push_back({'I'});
    }
    void residentExportHandoff(Handoff& h) override {
        std::lock_guard<std::mutex> l(rec.m);
        std::memcpy(h.row.data(), rec.model.row, 16);
        std::memcpy(h.column.data(), rec.model.col, 16);
        h.cycle = rec.model.cycle;
        h.mode = rec.model.mode;
        h.mask = rec.model.mask;
        rec.events.push_back({'E'});
    }
};

size_t countEvents(char kind, size_t from) {
    std::lock_guard<std::mutex> l(rec.m);
    size_t n = 0;
    for (size_t i = from; i < rec.events.size(); ++i)
        n += rec.events[i].kind == kind;
    return n;
}
size_t eventCount() {
    std::lock_guard<std::mutex> l(rec.m);
    return rec.events.size();
}
Event eventAt(size_t i) {
    std::lock_guard<std::mutex> l(rec.m);
    return rec.events.at(i);
}
bool modelZero() {
    std::lock_guard<std::mutex> l(rec.m);
    Controls z{};
    return std::memcmp(&z, &rec.model, sizeof(z)) == 0;
}
bool cpuMirrorZero(PS2Memory& mem) {
    const auto& v = mem.vif1_regs;
    for (int i = 0; i < 4; ++i)
        if (v.row[i] || v.col[i])
            return false;
    return !v.cycle && !v.mode && !v.mask;
}
constexpr uint32_t FBRST = 0x10003C10u, ROW0 = 0x10003D00u, COL0 = 0x10003D40u;
} // namespace

int main() try {
    _putenv("REO_GS_BACKEND=parallel");
    _putenv("REO_GS_THREAD=1");
    _putenv("REO_VIF1_GPU_RESIDENT=1");
    bridge::registerFactory([] { return std::make_unique<RecordingBackend>(); });

    auto program = std::make_shared<Program>();
    program->bindingId = 1;
    program->startPCs = {0, 8};
    program->admittedFreshPCs = {0};
    program->gpuAdmitted = true;
    program->completeSetup = program->completeGeometry = program->completeClipping = true;
    program->completeCarry = program->orderedEffects = program->exactTermination = true;
    auto registry = std::make_shared<Registry>();
    registry->allowIncrementalFallback = true;
    registry->perProgramAdmission = true; // live gpuinc48 shape
    registry->programs = {program};
    registry->literalEffect = [](const Program&, const LiteralCommands&, bool, uint32_t, uint32_t,
                                 LiteralEffect&) { return true; };
    registerBeforeBoot(registry);

    PS2Runtime runtime;
    check(runtime.memory().initialize(), "RAM initializes");
    check(runtime.syncCoreSubsystems(), "GS/VIF/resident session bound");
    PS2Memory& mem = runtime.memory();
    VU1State& vu = runtime.vu1().state();
    check(enabled(mem), "resident session enabled");

    // 1. Outstanding launches, each with different controls, then FBRST.
    mem.writeIORegister(ROW0, 0x11u);
    check(launch(mem, vu, false, 0, 0), "first admitted launch runs on GPU (import crossing)");
    check(resident(mem), "session GPU-owned after import");
    mem.writeIORegister(ROW0, 0x22u);
    check(launch(mem, vu, false, 0, 0), "second admitted launch runs on GPU");
    size_t mark = eventCount();
    mem.writeIORegister(FBRST, 1u);
    check(countEvents('R', mark) == 1, "FBRST after outstanding launches retires exactly once");
    {
        std::lock_guard<std::mutex> l(rec.m);
        check(rec.launchControls.size() == 2 && rec.launchControls[0].row[0] == 0x11u &&
                  rec.launchControls[1].row[0] == 0x22u,
              "earlier launches keep their own controls (reset executes after them)");
        bool resetBeforeRetire = false;
        for (size_t i = mark; i + 1 < rec.events.size(); ++i)
            if (rec.events[i].kind == 'Q' && rec.events[i].controls == 5 &&
                rec.events[i + 1].kind == 'R' && rec.events[i + 1].reason == Barrier::VifFlush &&
                rec.events[i + 1].retired == 2)
                resetBeforeRetire = true;
        check(resetBeforeRetire, "5 zero controls submitted before the single VifFlush retirement "
                                 "covering both launches");
    }
    check(modelZero(), "device controls zero after reset");
    check(cpuMirrorZero(mem), "CPU vif1_regs mirror zero after reset");

    // 2. Immediate control read: no further submission, value zero.
    mark = eventCount();
    uint32_t value = 0xffffffffu;
    check(readControlMmio(mem, ROW0, value) && value == 0u,
          "immediate ROW read after reset observes zero");
    check(countEvents('Q', mark) == 0,
          "immediate read submits no control-only batch (resets already shipped)");

    // 3. Dirty control-only work, then FBRST: one batch, one retirement.
    mem.writeIORegister(COL0, 0x33u);
    mark = eventCount();
    mem.writeIORegister(FBRST, 1u);
    check(countEvents('Q', mark) == 1 && countEvents('R', mark) == 1,
          "dirty control + reset = one batch, one retirement");
    check(eventCount() >= 2 && eventAt(mark).controls == 6,
          "the batch carries the pending COL write then the 5 resets");
    check(modelZero() && cpuMirrorZero(mem), "zero after dirty-control reset");

    // 4. Repeated resets.
    mark = eventCount();
    for (int i = 0; i < 3; ++i)
        mem.writeIORegister(FBRST, 1u);
    check(countEvents('R', mark) == 3 && countEvents('Q', mark) == 3,
          "three resets: three ordered batches, three retirements, no throw");
    check(modelZero() && cpuMirrorZero(mem), "zero after repeated resets");

    // 5. Near capacity: pending one op short of reset room must not overflow.
    for (uint32_t i = 0; i < MaxOperations - 2; ++i)
        mem.writeIORegister(ROW0, i + 1);
    mark = eventCount();
    bool threw = false;
    try {
        mem.writeIORegister(FBRST, 1u);
    } catch (const std::exception& e) {
        threw = true;
        std::printf("  threw: %s\n", e.what());
    }
    check(!threw, "reset with a nearly full pending batch does not overflow");
    check(countEvents('Q', mark) == 2 && eventAt(mark).ops == MaxOperations - 2 &&
              eventAt(mark + 1).controls == 5,
          "full prefix submitted intact first, then the resets (no operation discarded)");
    check(modelZero() && cpuMirrorZero(mem), "zero after near-capacity reset");

    // 6. CPU fallback after reset: unadmitted entry exports GPU controls into the CPU mirror.
    mem.writeIORegister(ROW0, 0x44u);
    mem.writeIORegister(FBRST, 1u);
    mark = eventCount();
    check(!launch(mem, vu, false, 8, 0), "unadmitted entry falls back to CPU");
    check(countEvents('E', mark) == 1 && !resident(mem),
          "fallback exports and returns ownership to CPU");
    check(cpuMirrorZero(mem), "CPU fallback observes the reset controls, not the pre-reset ROW");

    std::printf("\n%d/%d checks passed\n", checks - failures, checks);
    return failures ? 1 : 0;
} catch (const std::exception& e) {
    std::printf("EXCEPTION: %s\n%d/%d checks passed before it\n", e.what(), checks - failures,
                checks);
    return 2;
}
