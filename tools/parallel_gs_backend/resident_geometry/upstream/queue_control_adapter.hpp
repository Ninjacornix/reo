#pragma once
#include "viewport_pipeline.hpp"
#include "protected_queue_capture.hpp"
#include <map>
#include <optional>
#include <utility>

namespace reo_gpu_upstream {

// These are integer control records. Neither type permits CPU-readable
// graphics matrices, scissor/GIF payload values, or a host-shadow RAW claim.
enum class QueueField : uint32_t {
    ProtectedCpuQueue = 1,
    ProtectedCpuLookup = 2,
    OwnerDmaHeaderControl = 3
};
struct QueueWord {
    uint32_t sourcePc, address, value;
    QueueField field;
};
enum class QueueOperation : uint32_t {
    GprLower64 = 1,
    Pc = 2,
    BranchPc = 3,
    DelaySlotFalse = 4,
    GpuMemoryWord = 5,
    ProtectedCpuWord = 6,
    OpaqueContextToGpuStack = 7,
    OpaqueGpuStackToContext = 8,
    ManagedRingOverwrite = 9
};
struct QueueJournalWord {
    QueueOperation op;
    uint32_t sourcePc, address, word0, word1;
};
static_assert(sizeof(QueueJournalWord) == 20);

class QueueHeaderLease final {
    friend class reo_gpu_palette_parent::Producer;
    friend class reo_parent_install::Service;
    friend class QueueControlAdapter;
    friend class QueueHeaderMetadataPipeline;
    friend class QueueJournalPipeline;
    const void* owner_;
    BanksHandle banks_;
    Stamp stamp_;
    uint64_t exactFence_, protectedCpuRevision_;
    Vulkan::BufferHandle actualCertifiedMetadata_;
    std::vector<QueueWord> words_;
    // The real issuer must verify the exact immutable GPU metadata buffer
    // after its true fence and source/key/field receipt, then construct here.
    QueueHeaderLease(const void* owner, BanksHandle banks, Stamp stamp, uint64_t fence,
                     uint64_t protectedCpuRevision, Vulkan::BufferHandle metadata,
                     std::vector<QueueWord> words)
        : owner_(owner), banks_(std::move(banks)), stamp_(stamp), exactFence_(fence),
          protectedCpuRevision_(protectedCpuRevision),
          actualCertifiedMetadata_(std::move(metadata)), words_(std::move(words)) {}

  public:
    QueueHeaderLease(const QueueHeaderLease&) = delete;
};
using QueueHeaderLeaseHandle = std::shared_ptr<const QueueHeaderLease>;

class ProtectedQueueSnapshot final {
    friend class reo_parent_install::Service;
    friend class QueueControlAdapter;
    friend class QueueHeaderMetadataPipeline;
    friend class ProtectedCounterImport;
    friend class QueueJournalPipeline;
    friend class reo_parent_natural::NativeTarget;
    const void* issuer_;
    const void* actualRuntime_;
    Stamp stamp_;
    uint64_t protectedCpuRevision_;
    int32_t actualTask_;
    ProtectedQueueCaptureHandle capture_;
    struct RingDestination {
        uint32_t sourcePc, address, base, capacity, index;
    };
    std::optional<RingDestination> ring_;
    std::vector<QueueWord> words_;
    // Only the actual CPU owner may capture queue counters/tables under its
    // legitimate protected task scope. No graphics header is admitted here.
    ProtectedQueueSnapshot(const void* issuer, const void* runtime, Stamp stamp, uint64_t revision,
                           int32_t task, std::vector<QueueWord> words,
                           ProtectedQueueCaptureHandle capture, std::optional<RingDestination> ring)
        : issuer_(issuer), actualRuntime_(runtime), stamp_(stamp), protectedCpuRevision_(revision),
          actualTask_(task), words_(std::move(words)), capture_(std::move(capture)),
          ring_(std::move(ring)) {}

  public:
    ProtectedQueueSnapshot(const ProtectedQueueSnapshot&) = delete;
};
using ProtectedQueueSnapshotHandle = std::shared_ptr<const ProtectedQueueSnapshot>;

class QueueControlCall final {
    friend class reo_parent_natural::NativeTarget;
    friend class reo_parent_install::Service;
    friend class QueueControlAdapter;
    friend class QueueHeaderMetadataPipeline;
    friend class QueueJournalPipeline;
    const void* issuer_;
    BanksHandle banks_;
    Stamp stamp_;
    int32_t actualTask_;
    CallHandle originalCall_;
    QueueResolverBindingHandle resolver_;
    Vulkan::BufferHandle immutableOriginalControl_;
    uint64_t exactControlFence_;
    std::array<uint64_t, 4> arguments_;
    uint64_t sp_, returnPc_;
    uint32_t originalJal_, continuation_;
    QueueControlCall(const void* issuer, BanksHandle banks, Stamp stamp, int32_t task,
                     CallHandle originalCall, Vulkan::BufferHandle original, uint64_t fence,
                     std::array<uint64_t, 4> args, uint64_t sp, uint64_t returnPc, uint32_t jal,
                     uint32_t continuation, QueueResolverBindingHandle resolver)
        : issuer_(issuer), banks_(std::move(banks)), stamp_(stamp), actualTask_(task),
          originalCall_(std::move(originalCall)), immutableOriginalControl_(std::move(original)),
          exactControlFence_(fence), arguments_(args), sp_(sp), returnPc_(returnPc),
          originalJal_(jal), continuation_(continuation), resolver_(std::move(resolver)) {}

  public:
    QueueControlCall(const QueueControlCall&) = delete;
};
using QueueControlCallHandle = std::shared_ptr<const QueueControlCall>;

class QueueControlAdapter final {
    friend class reo_parent_install::Service;

  public:
    class Plan final {
        friend class QueueControlAdapter;
        friend class reo_parent_install::Service;
        friend class QueueJournalPipeline;
        const void* issuer_;
        QueueControlCallHandle call_;
        QueueHeaderLeaseHandle headers_;
        ProtectedQueueSnapshotHandle counters_;
        std::vector<QueueJournalWord> ordered_;
        uint64_t returnValue_;
        uint32_t instructions_;
        Plan(const void* issuer, QueueControlCallHandle call, QueueHeaderLeaseHandle headers,
             ProtectedQueueSnapshotHandle counters, std::vector<QueueJournalWord> journal,
             uint64_t returned, uint32_t instructions)
            : issuer_(issuer), call_(std::move(call)), headers_(std::move(headers)),
              counters_(std::move(counters)), ordered_(std::move(journal)), returnValue_(returned),
              instructions_(instructions) {}

      public:
        const std::vector<QueueJournalWord>& ordered() const noexcept {
            return ordered_;
        }
        uint32_t returned() const noexcept {
            return static_cast<uint32_t>(returnValue_);
        }
        uint64_t returned64() const noexcept {
            return returnValue_;
        }
        uint32_t instructions() const noexcept {
            return instructions_;
        }
    };
    using PlanHandle = std::shared_ptr<const Plan>;

  private:
    const void* actualService_;
    BanksHandle banks_;
    QueueControlAdapter(const void* service, BanksHandle banks)
        : actualService_(service), banks_(std::move(banks)) {
        if (!service || !banks_)
            throw std::invalid_argument("Queue adapter lacks actual Service/banks");
    }
    static bool equalStamp(const Stamp& a, const Stamp& b) {
        return a.session == b.session && a.epoch == b.epoch &&
               a.bankGeneration == b.bankGeneration && a.ordinal == b.ordinal;
    }
    struct State {
        const QueueControlCall& call;
        const QueueHeaderLease& headers;
        const ProtectedQueueSnapshot& counters;
        std::array<uint64_t, 32> r{};
        std::array<bool, 32> known{};
        std::vector<QueueJournalWord> ordered;
        std::map<uint32_t, uint32_t> stagedMemory;
        uint32_t pc = 0x18cfb0u, lastSourcePc = 0x18cfb0u, instructions = 0;
        State(const QueueControlCall& c, const QueueHeaderLease& h, const ProtectedQueueSnapshot& q)
            : call(c), headers(h), counters(q) {
            known[0] = true;
            for (unsigned k = 0; k < 4; ++k) {
                r[4 + k] = call.arguments_[k];
                known[4 + k] = true;
            }
            r[29] = call.sp_;
            r[31] = call.returnPc_;
            known[29] = known[31] = true;
        }
        void append(QueueOperation op, uint32_t at, uint32_t x = 0, uint32_t y = 0) {
            if (ordered.size() >= 4096)
                throw std::invalid_argument("Queue exact staged journal exhausted");
            ordered.push_back({op, lastSourcePc, at, x, y});
        }
        void tick(uint32_t site) {
            pc = lastSourcePc = site;
            if (++instructions > 8192)
                throw std::invalid_argument(
                    "Queue control source did not return within bounded admitted domain");
            append(QueueOperation::Pc, 128u * 4u, pc);
        }
        uint64_t g64(unsigned n) const {
            if (n == 0)
                return 0;
            if (n >= 32 || !known[n])
                throw std::invalid_argument("Queue attempted CPU read of opaque context register");
            return r[n];
        }
        uint32_t g32(unsigned n) const {
            return static_cast<uint32_t>(g64(n));
        }
        void set64(unsigned n, uint64_t x) {
            if (n) {
                r[n] = x;
                known[n] = true;
                append(QueueOperation::GprLower64, n * 16u, static_cast<uint32_t>(x),
                       static_cast<uint32_t>(x >> 32));
            }
        }
        void set32(unsigned n, uint32_t x) {
            set64(n, static_cast<uint64_t>(static_cast<int64_t>(static_cast<int32_t>(x))));
        }
        void branch(uint32_t source) {
            append(QueueOperation::BranchPc, 344u * 4u, source);
            append(QueueOperation::DelaySlotFalse, 343u * 4u);
        }
        static QueueField readField(uint32_t site) {
            if (site == 0x18d0a8u || site == 0x18d0e0u)
                return QueueField::OwnerDmaHeaderControl;
            if (site == 0x18d09cu || site == 0x1a1330u || site == 0x1a1354u || site == 0x1a1360u)
                return QueueField::ProtectedCpuLookup;
            return QueueField::ProtectedCpuQueue;
        }
        static bool actualReadSite(uint32_t site) {
            switch (site) {
                case 0x18cfe4u:
                case 0x18cfe8u:
                case 0x18cff8u:
                case 0x18d00cu:
                case 0x18d010u:
                case 0x18d020u:
                case 0x18d038u:
                case 0x18d03cu:
                case 0x18d05cu:
                case 0x18d068u:
                case 0x18d09cu:
                case 0x18d0a8u:
                case 0x18d0e0u:
                case 0x1a1330u:
                case 0x1a1354u:
                case 0x1a1360u:
                    return true;
                default:
                    return false;
            }
        }
        uint32_t read32(uint32_t address) {
            if (!actualReadSite(pc) || (address & 3u))
                throw std::invalid_argument("Queue source-qualified integer read differs");
            if (auto i = stagedMemory.find(address); i != stagedMemory.end())
                return i->second;
            QueueField field = readField(pc);
            const auto& values =
                field == QueueField::OwnerDmaHeaderControl ? headers.words_ : counters.words_;
            std::optional<uint32_t> found;
            for (const auto& w : values)
                if (w.sourcePc == pc && w.address == address && w.field == field) {
                    if (found)
                        throw std::invalid_argument("Queue integer field lease is ambiguous");
                    found = w.value;
                }
            if (!found)
                throw std::invalid_argument(
                    "Queue lacks exact owner header or protected control coverage before mutation");
            return *found;
        }
        uint64_t read64(uint32_t address) {
            if (pc != 0x18d140u || address != static_cast<uint32_t>(call.sp_) - 16u)
                throw std::invalid_argument("Queue original RA spill range differs");
            auto lo = stagedMemory.find(address), hi = stagedMemory.find(address + 4u);
            if (lo == stagedMemory.end() || hi == stagedMemory.end())
                throw std::invalid_argument("Queue original scalar RA spill is absent");
            return uint64_t(lo->second) | (uint64_t(hi->second) << 32);
        }
        void write32(uint32_t address, uint32_t value) {
            if (address & 3u)
                throw std::invalid_argument("Queue control write is unaligned");
            if (pc == 0x18d034u) {
                const auto& ring = counters.ring_;
                if (!ring || ring->sourcePc != pc || ring->address != address || !ring->capacity ||
                    ring->index >= ring->capacity || ring->base + ring->index * 4u != address)
                    throw std::invalid_argument(
                        "Queue lacks exact managed native ring destination before mutation");
                stagedMemory[address] = value;
                append(QueueOperation::ManagedRingOverwrite, address, value, 0u);
                return;
            }
            QueueOperation op;
            switch (pc) {
                case 0x18d0d0u:
                case 0x18d0dcu:
                case 0x18d108u:
                    op = QueueOperation::GpuMemoryWord;
                    break;
                case 0x18d01cu:
                case 0x18d02cu:
                case 0x18d034u:
                case 0x18d048u:
                case 0x18d04cu:
                case 0x18d058u:
                case 0x18d118u:
                case 0x18d120u:
                case 0x18d124u:
                case 0x18d128u:
                case 0x18d134u:
                case 0x18d13cu:
                    op = QueueOperation::ProtectedCpuWord;
                    break;
                default:
                    throw std::invalid_argument(
                        "Queue unknown write source cannot obtain authority");
            }
            const auto field = op == QueueOperation::GpuMemoryWord
                                   ? QueueField::OwnerDmaHeaderControl
                                   : QueueField::ProtectedCpuQueue;
            const auto& values =
                op == QueueOperation::GpuMemoryWord ? headers.words_ : counters.words_;
            std::optional<uint32_t> certifiedBefore;
            for (const auto& w : values)
                if (w.sourcePc == pc && w.address == address && w.field == field) {
                    if (certifiedBefore)
                        throw std::invalid_argument("Queue write field lease is ambiguous");
                    certifiedBefore = w.value;
                }
            if (!certifiedBefore)
                throw std::invalid_argument(
                    "Queue missing exact write field coverage before mutation");
            const auto prior = stagedMemory.find(address);
            const uint32_t expected =
                prior == stagedMemory.end() ? *certifiedBefore : prior->second;
            stagedMemory[address] = value;
            append(op, address, value, expected);
        }
        void write64(uint32_t address, uint64_t value) {
            if (pc != 0x18cfb8u || address != static_cast<uint32_t>(call.sp_) - 16u ||
                (address & 7u))
                throw std::invalid_argument("Queue original RA spill range differs");
            stagedMemory[address] = uint32_t(value);
            stagedMemory[address + 4u] = uint32_t(value >> 32);
            append(QueueOperation::GpuMemoryWord, address, uint32_t(value));
            append(QueueOperation::GpuMemoryWord, address + 4u, uint32_t(value >> 32));
        }
        void saveOpaque(unsigned n, uint32_t address) {
            const uint32_t expected = static_cast<uint32_t>(call.sp_) - 96u + (n - 16u) * 16u;
            if (n < 16 || n > 20 || address != expected)
                throw std::invalid_argument("Queue opaque original stack save range differs");
            append(QueueOperation::OpaqueContextToGpuStack, address, n * 16u, 16u);
        }
        void restoreOpaque(unsigned n, uint32_t address) {
            const uint32_t expected = static_cast<uint32_t>(call.sp_) - 96u + (n - 16u) * 16u;
            if (n < 16 || n > 20 || address != expected)
                throw std::invalid_argument("Queue opaque original stack restore range differs");
            known[n] = false;
            append(QueueOperation::OpaqueGpuStackToContext, n * 16u, address, 16u);
        }
        void run();
    };
    PlanHandle plan(const QueueControlCallHandle& call, const QueueHeaderLeaseHandle& headers,
                    const ProtectedQueueSnapshotHandle& counters) {
        if (!call || !headers || !counters || call->issuer_ != actualService_ ||
            counters->issuer_ != actualService_ || call->banks_ != banks_ ||
            headers->banks_ != banks_ || headers->owner_ != banks_->issuer() ||
            !call->immutableOriginalControl_ || !headers->actualCertifiedMetadata_ ||
            !call->exactControlFence_ || !headers->exactFence_ || !counters->actualRuntime_ ||
            !counters->protectedCpuRevision_ || call->actualTask_ < 1 ||
            call->actualTask_ != counters->actualTask_ ||
            headers->protectedCpuRevision_ != counters->protectedCpuRevision_ ||
            !equalStamp(call->stamp_, headers->stamp_) ||
            !equalStamp(call->stamp_, counters->stamp_))
            throw std::invalid_argument("Queue call/lease/counter ownership differs");
        if (!call->resolver_ || call->resolver_->issuer_ != actualService_ ||
            call->resolver_->call_ != call->originalCall_ ||
            call->resolver_->actualTask_ != call->actualTask_ ||
            call->resolver_->runtime_ != counters->actualRuntime_)
            throw std::invalid_argument("Queue lacks genuine retained runtime resolver binding");
        const auto& s = call->stamp_;
        const auto& b = banks_->stamp();
        if (!s.ordinal || s.session != b.session || s.epoch != b.epoch ||
            s.bankGeneration != b.bankGeneration)
            throw std::invalid_argument("Queue source bank identity is stale");
        if (call->arguments_[0] != 0u || call->arguments_[3] != 0x29f6f0u ||
            call->returnPc_ != call->continuation_ ||
            !((call->originalJal_ == 0x197748u && call->continuation_ == 0x197750u) ||
              (call->originalJal_ == 0x198370u && call->continuation_ == 0x198378u) ||
              (call->originalJal_ == 0x197b90u && call->continuation_ == 0x197b98u &&
               call->originalCall_ && call->originalCall_->entry() == 0x197900u)) ||
            (call->sp_ & 15u) || call->sp_ < 96u || call->sp_ > RamBytes)
            throw std::invalid_argument("Queue genuine viewport/color control call domain differs");
        State state(*call, *headers, *counters);
        state.run();
        return std::shared_ptr<const Plan>(new Plan(actualService_, call, headers, counters,
                                                    std::move(state.ordered), state.g64(2u),
                                                    state.instructions));
    }

  public:
    static constexpr bool ActualGpuHeaderLeaseIssuerImplemented = false;
    static constexpr bool ActualProtectedSnapshotIssuerImplemented = false;
    static constexpr bool ActualOrderedCommitImplemented = false;
    static constexpr bool NaturalSourceClosureImplemented = false;
};
} // namespace reo_gpu_upstream
#include "queue_control_body.inc"
