#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
namespace reo_gpu_ordered_mesh {
// New private ABI. The independently proved cold array ABI is unchanged.
constexpr uint32_t MaxJobs = 128, MaxCommands = 32768, MaxRawRows = 65536;
constexpr uint32_t StateWords = 158, StateSlotWords = 192, ResultSlotWords = 64;
constexpr uint32_t ResidentStateBase = 0, EpochStateBase = 192;
constexpr uint32_t PreparedStateBase = EpochStateBase + MaxJobs * StateSlotWords;
constexpr uint32_t TerminalStateBase = PreparedStateBase + MaxJobs * StateSlotWords;
constexpr uint32_t StateCapacityWords = TerminalStateBase + MaxJobs * StateSlotWords;
constexpr uint32_t ResidentMapBase = 0, SnapshotMapBase = 1024;
constexpr uint32_t HeaderBase = SnapshotMapBase + MaxJobs * 1024;
constexpr uint32_t HistoryRefsBase = HeaderBase + MaxJobs * 28;
constexpr uint32_t AuxiliaryBase = HistoryRefsBase + MaxJobs * 6;
// Appended private GPU-only provenance index. Original reference offsets stay
// identical, including terminal/history/gather/export consumers. Leaf128 is the
// final bank query, so256 leaves cover MaxJobs+1 without aliasing the root.
constexpr uint32_t SparseTreeBase = AuxiliaryBase + MaxJobs * 16;
constexpr uint32_t SparseLeaves = 256, SparseNodes = SparseLeaves * 2;
constexpr uint32_t SparseTreeWords = SparseNodes * 1024;
constexpr uint32_t MapCapacityWords = SparseTreeBase + SparseTreeWords;
constexpr uint32_t SparseEventsPerJob = 124 + 6;
constexpr uint32_t SparseClearGrid = (SparseTreeWords + 63) / 64;
constexpr uint32_t sparseScatterGrid(uint32_t commandCount, uint32_t jobCount) {
    return (commandCount + jobCount * SparseEventsPerJob + 63) / 64;
}
constexpr uint32_t sparseQueryGrid(uint32_t jobCount) {
    return 16 * (jobCount + 1);
}
static_assert(SparseTreeBase == 138496 && SparseTreeWords == 524288 && MapCapacityWords == 662784);
constexpr uint32_t JobMetaBase = 16, CommandBase = JobMetaBase + MaxJobs * 8;
constexpr uint32_t CommandCapacityWords = CommandBase + MaxCommands * 4;
enum class CommandKind : uint32_t { RawQword = 0, Launch = 1 };
struct Command {
    uint32_t kind, addressOrJob, rawRow, reserved;
};
// entryPC is a fresh API argument only; resume4 reads GPU resident/predicted PC.
// selector is raw literal metadata and is checked again by the GPU. capacity
// is a GPU bound; the first bounded stream family requires count39/mode2.
struct Job {
    uint32_t entryPC, maxPairs, top, itop, operation, capacity, selector, reserved;
};
struct Push {
    uint32_t jobCount, jobCapacity, commandCount, rawRowCount;
};
struct alignas(16) Echo {
    std::array<uint32_t, 4> kindCountFlags{};
    std::array<std::array<uint32_t, 4>, 7> qwords{};
    std::array<std::array<uint32_t, 4>, 8> padding{};
};
static_assert(sizeof(Command) == 16 && sizeof(Job) == 32 && sizeof(Push) == 16 &&
              sizeof(Echo) == 256);
// Encoded references avoid a16KiB byte-bank snapshot per mesh. Geometry reads
// immutable raw rows. Snapshot metadata retains references to preceding output
// rows for exact ordered history/terminal carry. No host geometry is produced.
constexpr uint32_t OutputReference = 0x40000000u, InvalidReference = 0xffffffffu;
constexpr uint32_t makeOutputReference(uint32_t job, uint32_t row) {
    return OutputReference | (job << 8) | row;
}
constexpr std::array<size_t, 8> BufferBytes{
    size_t(StateCapacityWords) * 4, size_t(MaxRawRows) * 16,
    size_t(MaxJobs) * 16640,        size_t(64 + MaxJobs * ResultSlotWords) * 4,
    size_t(MaxJobs) * 32768,        size_t(MapCapacityWords) * 4,
    size_t(MaxJobs) * 256,          size_t(CommandCapacityWords) * 4};
// Status field0 is sticky globally; per-job status is at64+job*64. Success may
// publish only after source/alias/count/carry/ordered effect certificates pass.
enum class Status : uint32_t {
    Pending = 0x100,
    Success = 0,
    RawBounds = 40,
    Envelope = 41,
    CountOrSelector = 42,
    OwnAlias = 43,
    PriorGeometryRead = 44,
    UnsupportedPC = 45,
    SourceMismatch = 46,
    UnprovedCarry = 47
};
struct Proofs {
    bool typedLiveWrites = false, orderedRegisterCarry = false, historyAndClip = false;
    bool terminalAliasing = false, fullOrderedEffects = false, ownerRetirement = false;
    bool complete() const noexcept {
        return typedLiveWrites && orderedRegisterCarry && historyAndClip && terminalAliasing &&
               fullOrderedEffects && ownerRetirement;
    }
};
} // namespace reo_gpu_ordered_mesh
