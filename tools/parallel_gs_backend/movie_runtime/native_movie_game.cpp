#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "native_movie_game.h"
#include "original_graphics_route.h"
#include "original_transport_route.h"
#include "native_movie_transport.h"
#include "movie_owner_service.h"
#include "gs_priv_atomic.h"
#include "movie_join_observer.h"
#include "native_movie_image.h"
#include <set>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <exception>

void sub_00171D10_0x171d10(uint8_t*, R5900Context*, PS2Runtime*);
void reo_movie_native_171d10(uint8_t*, R5900Context*, PS2Runtime*);
namespace reo_gpu_movie {
namespace {
using Operation = reo_gpu_movie_graphics::Operation;
using Result = reo_gpu_movie_graphics::Result;
constexpr uint32_t NativeWaitPC = 0x01feeef0;
// Optional control-only diagnostics. Never sample resident pixels, guest audio,
// or fabricate a completion. Fence lines are emitted after the real wait.
bool diagnosticsEnabled() {
    static const bool enabled = [] {
        const auto* value = std::getenv("REO_GPU_MOVIE_LOG");
        return value && *value && *value != '0';
    }();
    return enabled;
}
struct DiagnosticCounts {
    std::atomic<uint64_t> claim{0}, decode{0}, output{0}, image{0}, batch{0}, release{0};
    std::atomic<bool> failure{false};
} diagnostic;
uint64_t diagnosticEvent(std::atomic<uint64_t>& counter) {
    if (!diagnosticsEnabled())
        return 0;
    const auto event = counter.fetch_add(1, std::memory_order_relaxed) + 1;
    return event <= 3 || event % 120 == 0 ? event : 0;
}
void diagnosticFailure(const char* boundary, const char* detail) noexcept {
    if (diagnosticsEnabled() && !diagnostic.failure.exchange(true, std::memory_order_relaxed))
        std::fprintf(stderr, "[GPU-MOVIE] failure boundary=%s detail=%s\n", boundary, detail);
}
template <class Work>
decltype(auto) observed(const char* boundary, PS2Runtime* runtime, Work&& work) {
    try {
        return work();
    } catch (const std::exception& error) {
        diagnosticFailure(boundary, error.what());
        if (runtime)
            runtime->requestStop();
        throw;
    } catch (...) {
        diagnosticFailure(boundary, "non-standard exception");
        if (runtime)
            runtime->requestStop();
        throw;
    }
}

struct NumericalResult {
    bool ready = false;
    NativeDecodeCompletion decode;
    NativeOutputBinding output;
};
struct Pending {
    Operation operation{};
    uint64_t serial = 0;
    uint32_t returnPC = 0, stack = 0;
    OriginalDecodeEvent decode;
    OriginalOutputEvent output;
    uint32_t th0 = 0, th1 = 0;
    std::shared_ptr<NumericalResult> result;
    std::shared_ptr<reo_movie_owner::Request> request;
};
struct PreparedImageLifetime {
    NativeMovieImageSource source;
    std::set<uint64_t> pendingSourceEvents;
    bool releasePending = false;
};
struct Game {
    PS2Runtime* runtime = nullptr;
    OriginalCompressedLineage lineage;
    std::unique_ptr<NativeMovieTransport> transport;
    MovieSessionOwner owner;
    uint64_t epoch = 0, nextGeneration = 0, nextEvent = 0;
    uint32_t inner = 0;
    // Tombstones survive cancellation, actual GS RESET and failed ownership.
    // An operation already claimed by GPU may never return to CPU graphics.
    std::set<uint32_t> claimedInner;
    R5900Context* context = nullptr;
    uint32_t stack = 0, descriptor = 0, destination = 0, requestReturn = 0;
    bool requestActive = false;
    std::unique_ptr<Pending> pending;
    std::mutex imagesMutex;
    std::map<uint32_t, NativeMovieImageSource> images;
    std::set<uint32_t> retiredImageBases;
    std::map<uint32_t, std::shared_ptr<PreparedImageLifetime>> imageLifetimes;
    // Bounded wait diagnostics (REO_GPU_MOVIE_LOG only): distinguishes an
    // unexecuted owner request from a callback repeatedly returning "not
    // ready", and from a transport commit that cannot advance. Never fabricates
    // a completion; values are sampled, not acted upon.
    uint64_t waitSerial = 0;
    unsigned waitBranch = 0;
    uint64_t waitCount = 0;
    uint64_t submitCount = 0; // total owner submissions across the session
} game;
MovieOwnerServiceTarget& service(reo_movie_owner::Target& target) {
    auto* value = dynamic_cast<MovieOwnerServiceTarget*>(&target);
    if (!value)
        throw std::runtime_error("Actual GS owner target is not the native movie service");
    return *value;
}
template <class Work> void callOwner(Game& value, const Work& work) {
    // Immutable controls are copied into the genuine GS FIFO. Waiting releases
    // all recursive guest ownership and never holds Runtime's IO register lock.
    PS2Runtime::GuestExecutionReleaseScope release(value.runtime);
    auto request = reo_movie_owner::request(value.epoch, 0, false, work);
    request->wait();
}
void healthy(const Game& value) {
    if (!value.transport || !value.owner.generation || value.epoch != gsPrivCurrentEpoch() ||
        !reo_movie_owner::actualOwnerAvailable())
        throw std::runtime_error("Claimed GPU movie lost its actual GS owner/epoch");
}
const char* opName(Operation op) {
    return op == Operation::Decode144500 ? "decode"
           : op == Operation::Csc1477A0  ? "csc"
           : op == Operation::Copy1469A8 ? "copy"
                                         : "?";
}
// Bounded, state-change-only diagnostic for the numerical movie wait. Emits on
// a branch/serial change and every 240th repeat of the same branch, so a
// multi-second stall produces a handful of lines instead of a per-preemption
// flood. The owner callback logs (submit) pair with requestReady to tell an
// unexecuted request apart from one whose decode/output made no progress.
void waitMark(Game& value, uint64_t serial, unsigned branch, const Pending& pending) {
    if (!diagnosticsEnabled())
        return;
    const bool changed = value.waitSerial != serial || value.waitBranch != branch;
    const bool interval = !changed && (value.waitCount % 240u) == 0u;
    if (!changed && !interval) {
        ++value.waitCount;
        return;
    }
    uint64_t picture = 0, elementaryEnd = 0;
    int64_t pts90k = 0;
    if (pending.operation == Operation::Decode144500) {
        const auto& c = pending.result->decode;
        picture = c.picture;
        pts90k = c.pts90k;
        elementaryEnd = c.elementaryEnd;
    } else {
        const auto& b = pending.result->output;
        picture = b.picture;
        pts90k = b.pts90k;
    }
    const uint64_t compressed = value.transport ? value.transport->compressedInputBit() : 0;
    const char* phase = branch == 1   ? "request-not-ready(owner-callback-unexecuted-or-pending)"
                        : branch == 2 ? "result-not-ready(owner-no-numerical-progress)"
                                      : "transport-commit-failed";
    std::fprintf(stderr,
                 "[GPU-MOVIE-WAIT] op=%s event=%llu epoch=%llu generation=%llu branch=%u(%s) "
                 "repeats=%llu submits=%llu picture=%llu pts90k=%lld elementaryEnd=%llu "
                 "compressedBit=%llu requestReady=%u\n",
                 opName(pending.operation), static_cast<unsigned long long>(serial),
                 static_cast<unsigned long long>(value.epoch),
                 static_cast<unsigned long long>(value.owner.generation), branch, phase,
                 static_cast<unsigned long long>(changed ? 1 : value.waitCount + 1),
                 static_cast<unsigned long long>(value.submitCount),
                 static_cast<unsigned long long>(picture), static_cast<long long>(pts90k),
                 static_cast<unsigned long long>(elementaryEnd),
                 static_cast<unsigned long long>(compressed), pending.request->ready() ? 1u : 0u);
    value.waitSerial = serial;
    value.waitBranch = branch;
    value.waitCount = 1;
}
void waitClear(Game& value) {
    value.waitSerial = 0;
    value.waitBranch = 0;
    value.waitCount = 0;
}
void submit(Game& value, Pending& pending) {
    auto result = std::make_shared<NumericalResult>();
    pending.result = result;
    const auto operation = pending.operation;
    const auto decode = pending.decode;
    const auto output = pending.output;
    const auto th0 = pending.th0, th1 = pending.th1;
    const auto serial = pending.serial;
    const auto epoch = value.epoch;
    const auto generation = value.owner.generation;
    ++value.submitCount;
    const auto submitSerial = value.submitCount;
    PS2Runtime::GuestExecutionReleaseScope release(value.runtime);
    pending.request = reo_movie_owner::request(
        value.epoch, 0, false,
        [result, operation, decode, output, th0, th1, serial, epoch, generation,
         submitSerial](reo_movie_owner::Target& target) {
            if (diagnosticsEnabled())
                std::fprintf(stderr,
                             "[GPU-MOVIE-OWNER] begin op=%s event=%llu epoch=%llu generation=%llu "
                             "submit=%llu\n",
                             opName(operation), static_cast<unsigned long long>(serial),
                             static_cast<unsigned long long>(epoch),
                             static_cast<unsigned long long>(generation),
                             static_cast<unsigned long long>(submitSerial));
            auto& movie = service(target);
            if (operation == Operation::Decode144500)
                result->ready = movie.decode(decode, th0, th1, result->decode);
            else
                result->ready = movie.output(output, result->output);
            if (diagnosticsEnabled())
                std::fprintf(
                    stderr, "[GPU-MOVIE-OWNER] end op=%s event=%llu submit=%llu ready=%u\n",
                    opName(operation), static_cast<unsigned long long>(serial),
                    static_cast<unsigned long long>(submitSerial), result->ready ? 1u : 0u);
        });
}
bool finish(uint8_t* ram, R5900Context* ctx, Game& value) {
    healthy(value);
    if (!value.pending)
        throw std::logic_error("Native movie wait lacks its owned numerical event");
    auto& pending = *value.pending;
    if (value.context != ctx || pending.stack != GPR_U32(ctx, 29) ||
        GPR_U32(ctx, 31) != pending.returnPC)
        throw std::runtime_error("Native movie numerical wait changed original context/stack/RA");
    if (!pending.request->ready()) {
        waitMark(value, pending.serial, 1, pending);
        return false;
    }
    {
        PS2Runtime::GuestExecutionReleaseScope release(value.runtime);
        pending.request->wait();
    }
    if (!pending.result->ready) {
        waitMark(value, pending.serial, 2, pending);
        value.transport->observeFileEnd(ram);
        submit(value, pending);
        return false;
    }
    if (pending.operation == Operation::Decode144500) {
        const auto completion = pending.result->decode;
        if (!value.transport->advanceCompletedDecode(ram, completion)) {
            waitMark(value, pending.serial, 3, pending);
            return false;
        }
        callOwner(value, [completion](reo_movie_owner::Target& target) {
            service(target).acknowledgeDecode(completion);
        });
        // Exact successful full-picture144500 integer return. The genuine
        // outer148170/146650/146C60/146C38/controller instructions still run.
        SET_GPR_S32(ctx, 2, 1);
        if (const auto count = diagnosticEvent(diagnostic.decode))
            std::fprintf(stderr,
                         "[GPU-MOVIE] decode n=%llu epoch=%llu generation=%llu picture=%llu "
                         "pts90k=%lld end=%llu original_ra=%08x\n",
                         static_cast<unsigned long long>(count),
                         static_cast<unsigned long long>(value.epoch),
                         static_cast<unsigned long long>(completion.generation),
                         static_cast<unsigned long long>(completion.picture),
                         static_cast<long long>(completion.pts90k),
                         static_cast<unsigned long long>(completion.elementaryEnd),
                         pending.returnPC);
    } else {
        const auto& binding = pending.result->output;
        NativeMovieImageSource source{value.epoch,         binding.generation, binding.picture,
                                      binding.eventSerial, binding.pts90k,     value.owner.sofdec,
                                      value.owner.work,    binding.descriptor, binding.destination,
                                      binding.width,       binding.height};
        const auto destination = OriginalCompressedLineage::canonical(binding.destination);
        std::lock_guard<std::mutex> lock(value.imagesMutex);
        uint32_t checked = 0;
        if (!OriginalCompressedLineage::physical(
                binding.destination, uint32_t(uint64_t(binding.width) * binding.height * 4),
                checked) ||
            checked != destination)
            throw std::runtime_error(
                "Original movie output frame range is outside actual RDRAM ownership");
        if (value.images.count(destination) && !value.retiredImageBases.count(destination))
            throw std::runtime_error(
                "Original movie output destination reused before actual IMAGE fence retirement");
        value.images[destination] = source;
        value.retiredImageBases.erase(destination);
        auto lifetime = std::make_shared<PreparedImageLifetime>();
        lifetime->source = source;
        value.imageLifetimes[destination] = std::move(lifetime);
        if (const auto count = diagnosticEvent(diagnostic.output))
            std::fprintf(stderr,
                         "[GPU-MOVIE] output n=%llu epoch=%llu generation=%llu picture=%llu "
                         "pts90k=%lld descriptor=%08x destination=%08x width=%u height=%u\n",
                         static_cast<unsigned long long>(count),
                         static_cast<unsigned long long>(value.epoch),
                         static_cast<unsigned long long>(binding.generation),
                         static_cast<unsigned long long>(binding.picture),
                         static_cast<long long>(binding.pts90k), binding.descriptor,
                         binding.destination, binding.width, binding.height);
        // Original146DD8 ignores1477A0/1469A8's scratch return and executes the
        // real146C38 bias update next. Do not substitute a fabricated clock.
    }
    ctx->pc = pending.returnPC;
    value.pending.reset();
    waitClear(value);
    return true;
}
bool owns(void* pointer, PS2Runtime* runtime, R5900Context* ctx) {
    auto& value = *static_cast<Game*>(pointer);
    if (runtime != value.runtime)
        return false;
    uint32_t inner = 0;
    const auto input = GPR_U32(ctx, 4);
    if (OriginalCompressedLineage::physical(input, 1, inner) && value.claimedInner.count(inner))
        return true;
    return value.requestActive && value.context == ctx;
}
Result receive(void* pointer, Operation operation, uint8_t* ram, R5900Context* ctx,
               PS2Runtime* runtime, uint32_t returnPC) {
    return observed("receive", runtime, [&]() -> Result {
        auto& value = *static_cast<Game*>(pointer);
        healthy(value);
        if (runtime != value.runtime || !value.requestActive || value.context != ctx ||
            value.pending || OriginalCompressedLineage::canonical(GPR_U32(ctx, 4)) != value.inner)
            throw std::runtime_error(
                "Owned movie numerical event lacks genuine original request ownership");
        if (operation == Operation::Copy1469A8)
            throw std::runtime_error("Owned planar movie output needs its actual non-RGBA "
                                     "consumer; CPU graphics fallback prohibited");
        auto pending = std::make_unique<Pending>();
        pending->operation = operation;
        pending->serial = ++value.nextEvent;
        pending->returnPC = returnPC;
        pending->stack = GPR_U32(ctx, 29);
        if (operation == Operation::Decode144500) {
            pending->decode = value.transport->decodeEvent(ram, pending->serial, value.inner);
            value.transport->thresholds(pending->th0, pending->th1);
            if (returnPC != 0x146594)
                throw std::runtime_error(
                    "Owned movie decode lacks original1464F0 reference selection");
            pending->decode.referenceMetadata =
                OriginalCompressedLineage::canonical(GPR_U32(ctx, 17));
            // Literal initial integer stores at original144528 and14453C. These
            // decoder bookkeeping words do not contain guest decoded pixels.
            uint32_t zero = 0;
            std::memcpy(ram + value.inner + 0x828, &zero, 4);
            std::memcpy(ram + value.inner + 0x82c, &zero, 4);
        } else {
            if (OriginalCompressedLineage::canonical(
                    OriginalCompressedLineage::read32(ram, value.inner + 0xf0)) !=
                OriginalCompressedLineage::canonical(value.destination))
                throw std::runtime_error("Original CSC request destination changed");
            pending->output = {value.owner.generation,
                               pending->serial,
                               value.inner,
                               value.descriptor,
                               value.destination,
                               OriginalCompressedLineage::read32(ram, value.owner.work + 0xc),
                               OriginalCompressedLineage::read32(ram, value.owner.work + 0x10)};
            value.transport->thresholds(pending->output.th0, pending->output.th1);
            pending->output.actualThresholds = true;
            if (returnPC != 0x146eac)
                throw std::runtime_error(
                    "Owned movie CSC lacks genuine146DD8 timestamp publication");
            pending->output.referenceMetadata =
                OriginalCompressedLineage::canonical(GPR_U32(ctx, 5));
            const auto published = OriginalCompressedLineage::canonical(
                OriginalCompressedLineage::read32(ram, value.inner + 0x870));
            pending->output.playerPts90k =
                int64_t(OriginalCompressedLineage::read64(ram, published + 0x10));
            pending->output.actualPlayerPts = true;
            pending->output.referencePts90k = int64_t(
                OriginalCompressedLineage::read64(ram, pending->output.referenceMetadata + 0x18));
            pending->output.clockEnabled =
                OriginalCompressedLineage::read32(ram, value.inner + 0x8c);
            pending->output.lastClockPts =
                int32_t(OriginalCompressedLineage::read32(ram, value.inner + 0x98));
            pending->output.originalTimeAbsent = originalMovieTimeAbsent(
                pending->output.playerPts90k, pending->output.referencePts90k,
                pending->output.clockEnabled, pending->output.lastClockPts);
            if (diagnosticsEnabled() && diagnostic.output.load(std::memory_order_relaxed) < 3)
                std::fprintf(stderr,
                             "[GPU-MOVIE] output-time event=%llu ref=%08x pts=%lld ref_pts=%lld "
                             "clock_enabled=%u last_clock=%d absent=%u\n",
                             static_cast<unsigned long long>(pending->output.serial),
                             pending->output.referenceMetadata,
                             static_cast<long long>(pending->output.playerPts90k),
                             static_cast<long long>(pending->output.referencePts90k),
                             pending->output.clockEnabled, pending->output.lastClockPts,
                             pending->output.originalTimeAbsent ? 1u : 0u);
        }
        value.pending = std::move(pending);
        submit(value, *value.pending);
        ctx->pc = NativeWaitPC;
        return Result::Yielded;
    });
}
void wait(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    observed("wait", runtime, [&]() {
        if (runtime != game.runtime || !game.pending)
            throw std::runtime_error("Unowned native movie wait continuation");
        if (!finish(ram, ctx, game)) {
            ctx->pc = NativeWaitPC;
            runtime->shouldPreemptGuestExecution();
        }
    });
}
void pictureHeader(void* pointer, PS2Runtime& runtime, R5900Context& ctx, uint32_t inner) {
    auto& value = *static_cast<Game*>(pointer);
    if (value.transport)
        value.transport->pictureHeader(runtime, ctx, inner);
}
void ringReset(void* pointer, PS2Runtime& runtime, uint32_t ring) {
    auto& value = *static_cast<Game*>(pointer);
    if (&runtime != value.runtime || !value.transport)
        return;
    if (value.requestActive || value.pending)
        throw std::runtime_error(
            "Original movie ring reset interrupted active native numerical output");
    value.transport->detach();
    const auto generation = value.owner.generation;
    if (value.epoch == gsPrivCurrentEpoch() && reo_movie_owner::actualOwnerAvailable())
        callOwner(value, [generation](reo_movie_owner::Target& target) {
            service(target).close(generation);
        });
    value.transport.reset();
    value.owner = {};
    value.inner = 0;
    std::lock_guard<std::mutex> lock(value.imagesMutex);
    value.images.clear();
    value.retiredImageBases.clear();
    value.imageLifetimes.clear();
}
class PreparedOriginalImage final : public reo_native_movie::PreparedImage {
    PS2Runtime* runtime_;
    const NativeMovieImageSource source_;
    const uint64_t sourceEvent_;
    const std::shared_ptr<PreparedImageLifetime> lifetime_;
    void releasePreparation(uint64_t event) noexcept {
        std::lock_guard<std::mutex> lock(game.imagesMutex);
        lifetime_->pendingSourceEvents.erase(event);
    }
    NativeOutputBinding binding() const {
        return {source_.generation, source_.outputEventSerial, source_.picture, source_.pts90k,
                source_.descriptor, source_.destination,       source_.width,   source_.height};
    }

  public:
    PreparedOriginalImage(PS2Runtime& runtime, uint64_t event, NativeMovieImageSource source,
                          std::shared_ptr<PreparedImageLifetime> lifetime)
        : runtime_(&runtime), source_(source), sourceEvent_(event), lifetime_(std::move(lifetime)) {
        if (!event || !source.sourceBytes || !lifetime_)
            throw std::invalid_argument(
                "Original IMAGE fragment has no actual source receipt/lifetime");
    }
    ~PreparedOriginalImage() override {
        releasePreparation(sourceEvent_);
    }
    uint64_t epoch() const noexcept override {
        return source_.epoch;
    }
    uint32_t bytes() const noexcept override {
        return source_.sourceBytes;
    }
    // Windows Release64: conservatively retain the pending uint64 tree node,
    // three links/color/padding and allocator overhead with this fragment.
    size_t retainedBytes() const noexcept override {
        return sizeof(*this) + 96;
    }
    bool canBatchWith(const reo_native_movie::PreparedImage& other) const noexcept override {
        if (&other == this)
            return true;
        const auto* value = dynamic_cast<const PreparedOriginalImage*>(&other);
        if (!value)
            return false;
        const auto& right = value->source_;
        return runtime_ == value->runtime_ && value->sourceEvent_ > sourceEvent_ &&
               source_.epoch == right.epoch && source_.generation == right.generation &&
               source_.picture == right.picture &&
               source_.outputEventSerial == right.outputEventSerial &&
               source_.pts90k == right.pts90k && source_.sofdec == right.sofdec &&
               source_.work == right.work && source_.descriptor == right.descriptor &&
               source_.destination == right.destination && source_.width == right.width &&
               source_.height == right.height && source_.sourceLayout == right.sourceLayout;
    }
    void beginBatch(reo_movie_owner::Target& target) override {
        observed("beginBatch", runtime_, [&] {
            if (target.epoch() != source_.epoch || !reo_movie_owner::onActualOwnerThread())
                throw std::runtime_error("Original movie batch crossed its GS owner/epoch");
            service(target).beginImageBatch(binding());
        });
    }
    void consume(reo_movie_owner::Target& target) override {
        consumeImpl(target, false);
    }
    void consumeBatched(reo_movie_owner::Target& target) override {
        consumeImpl(target, true);
    }
    void endBatch(reo_movie_owner::Target& target) override {
        observed("endBatch", runtime_, [&] {
            if (target.epoch() != source_.epoch || !reo_movie_owner::onActualOwnerThread())
                throw std::runtime_error(
                    "Original movie batch completion crossed its GS owner/epoch");
            const auto receipts = service(target).endImageBatch(binding());
            bool final = false;
            for (const auto& receipt : receipts) {
                final |= receipt.finalSourceCoverage;
                releasePreparation(receipt.dmaSerial);
            }
            if (final)
                retireNativeMovieImage(*runtime_, source_);
            if (diagnosticsEnabled()) {
                const auto images =
                    diagnostic.image.fetch_add(receipts.size(), std::memory_order_relaxed) +
                    receipts.size();
                if (const auto count = diagnosticEvent(diagnostic.batch))
                    std::fprintf(stderr,
                                 "[GPU-MOVIE] batch-fence n=%llu epoch=%llu generation=%llu "
                                 "picture=%llu pts90k=%lld fragments=%llu image_total=%llu "
                                 "first_source_event=%llu final_coverage=%u\n",
                                 static_cast<unsigned long long>(count),
                                 static_cast<unsigned long long>(source_.epoch),
                                 static_cast<unsigned long long>(source_.generation),
                                 static_cast<unsigned long long>(source_.picture),
                                 static_cast<long long>(source_.pts90k),
                                 static_cast<unsigned long long>(receipts.size()),
                                 static_cast<unsigned long long>(images),
                                 static_cast<unsigned long long>(sourceEvent_), final ? 1u : 0u);
            }
        });
    }

  private:
    void consumeImpl(reo_movie_owner::Target& target, bool batched) {
        observed(batched ? "consumeBatched" : "consume", runtime_, [&]() {
            if (target.epoch() != source_.epoch || !reo_movie_owner::onActualOwnerThread())
                throw std::runtime_error("Original movie IMAGE crossed actual GS owner/epoch");
            NativeOutputBinding binding{
                source_.generation, source_.outputEventSerial, source_.picture, source_.pts90k,
                source_.descriptor, source_.destination,       source_.width,   source_.height};
            MovieUpload upload;
            upload.generation = source_.generation;
            upload.picture = source_.picture;
            // Historical MovieUpload field name: this token is the actual ordered
            // FIFO IMAGE source-event receipt. Runtime separately owns the genuine
            // guest DMA serial, MADR/QWC and deferred channel publication.
            upload.dmaSerial = sourceEvent_;
            upload.pts90k = source_.pts90k;
            upload.sofdec = source_.sofdec;
            upload.work = source_.work;
            upload.outputDescriptor = source_.descriptor;
            upload.guestDestination = source_.destination;
            upload.sourceByteOffset = source_.sourceByteOffset;
            upload.sourceBytes = source_.sourceBytes;
            upload.sourceLayout = source_.sourceLayout;
            upload.frameWidth = source_.width;
            upload.frameHeight = source_.height;
            upload.gifPath = 3;
            auto& owner = service(target);
            MovieDmaReceipt receipt;
            if (!owner.uploadImageSource(binding, upload, receipt, batched))
                throw std::runtime_error(
                    "Original IMAGE overtook an earlier retained native movie source");
            if (batched)
                return; // End owns the one real submit/fence/receipt retirement.
            owner.waitUploadComplete(receipt);
            releasePreparation(sourceEvent_);
            if (receipt.finalSourceCoverage)
                retireNativeMovieImage(*runtime_, source_);
            if (const auto count = diagnosticEvent(diagnostic.image))
                std::fprintf(stderr,
                             "[GPU-MOVIE] image-fence n=%llu epoch=%llu generation=%llu "
                             "picture=%llu pts90k=%lld source_event=%llu source=%08x offset=%u "
                             "bytes=%u final_coverage=%u\n",
                             static_cast<unsigned long long>(count),
                             static_cast<unsigned long long>(source_.epoch),
                             static_cast<unsigned long long>(source_.generation),
                             static_cast<unsigned long long>(source_.picture),
                             static_cast<long long>(source_.pts90k),
                             static_cast<unsigned long long>(sourceEvent_), source_.sourceAddress,
                             source_.sourceByteOffset, source_.sourceBytes,
                             receipt.finalSourceCoverage ? 1u : 0u);
        });
    }
};
reo_native_movie::Ownership
lookupImage(PS2Runtime& runtime, uint64_t event, uint32_t source, uint32_t bytes,
            std::shared_ptr<reo_native_movie::PreparedImage>& prepared) {
    NativeMovieImageSource identity;
    switch (lookupNativeMovieImage(runtime, source, bytes, identity)) {
        case NativeMovieImageOwnership::Unowned:
            return reo_native_movie::Ownership::Unowned;
        case NativeMovieImageOwnership::Stale:
            return reo_native_movie::Ownership::Stale;
        case NativeMovieImageOwnership::Owned: {
            // Close the metadata lookup/release race before handing the real
            // Runtime FIFO an immutable fragment. A release intent forbids a
            // new preparation; existing ones must complete earlier in FIFO.
            std::shared_ptr<PreparedImageLifetime> lifetime;
            {
                std::lock_guard<std::mutex> lock(game.imagesMutex);
                const auto base = OriginalCompressedLineage::canonical(identity.destination);
                const auto found = game.imageLifetimes.find(base);
                if (found == game.imageLifetimes.end() ||
                    found->second->source.epoch != identity.epoch ||
                    found->second->source.generation != identity.generation ||
                    found->second->source.picture != identity.picture ||
                    found->second->source.outputEventSerial != identity.outputEventSerial ||
                    game.retiredImageBases.count(base) || found->second->releasePending)
                    return reo_native_movie::Ownership::Stale;
                lifetime = found->second;
                if (!event || !lifetime->pendingSourceEvents.insert(event).second)
                    throw std::runtime_error("Repeated original IMAGE preparation receipt");
            }
            try {
                prepared =
                    std::make_shared<PreparedOriginalImage>(runtime, event, identity, lifetime);
            } catch (...) {
                std::lock_guard<std::mutex> lock(game.imagesMutex);
                lifetime->pendingSourceEvents.erase(event);
                throw;
            }
            return reo_native_movie::Ownership::Owned;
        }
    }
    throw std::logic_error("Invalid original native IMAGE ownership result");
}
} // namespace
void nativeMovieQuiescent(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    observed("nativeMovieQuiescent", runtime, [&]() {
        auto& value = game;
        if (value.runtime != runtime)
            return;
        const auto sofdec = OriginalCompressedLineage::canonical(GPR_U32(ctx, 21)),
                   work = OriginalCompressedLineage::canonical(GPR_U32(ctx, 18));
        const auto inner = OriginalCompressedLineage::canonical(
            OriginalCompressedLineage::read32(ram, work + 0xa00 + 0x40));
        if (OriginalCompressedLineage::canonical(
                OriginalCompressedLineage::read32(ram, sofdec + 0x1b30)) != work)
            throw std::runtime_error("Original quiescent movie work owner mismatch");
        if (value.transport) {
            healthy(value);
            if (value.owner.sofdec != sofdec || value.owner.work != work || value.inner != inner)
                throw std::runtime_error(
                    "Live GPU movie owner replaced without genuine ring lifetime reset");
            return;
        }
        value.epoch = gsPrivCurrentEpoch();
        if (!reo_movie_owner::actualOwnerAvailable())
            throw std::runtime_error("Requested native movie has no actual GS owner service");
        const auto width = OriginalCompressedLineage::read32(ram, work + 0xc),
                   height = OriginalCompressedLineage::read32(ram, work + 0x10);
        value.owner = {++value.nextGeneration, sofdec, work};
        value.inner = inner;
        value.claimedInner.insert(inner);
        if (const auto count = diagnosticsEnabled()
                                   ? diagnostic.claim.fetch_add(1, std::memory_order_relaxed) + 1
                                   : 0)
            std::fprintf(stderr,
                         "[GPU-MOVIE] claim n=%llu epoch=%llu generation=%llu sofdec=%08x "
                         "work=%08x inner=%08x mode=%u width=%u height=%u\n",
                         static_cast<unsigned long long>(count),
                         static_cast<unsigned long long>(value.epoch),
                         static_cast<unsigned long long>(value.owner.generation), sofdec, work,
                         inner, OriginalCompressedLineage::read32(ram, sofdec + 0x38), width,
                         height);
        if (OriginalCompressedLineage::read32(ram, sofdec + 0x38) != 2)
            throw std::runtime_error("Native movie requires the original RGBA CSC output mode2");
        std::shared_ptr<LiveMovieProducer> producer;
        const auto owner = value.owner;
        callOwner(value, [&producer, owner, inner, width, height](reo_movie_owner::Target& target) {
            producer = service(target).openShared(owner, inner, width, height);
        });
        if (!producer)
            throw std::runtime_error("Actual GS movie service did not retain its input endpoint");
        auto transport = std::make_unique<NativeMovieTransport>(*runtime, value.lineage,
                                                                std::move(producer), owner, inner);
        transport->attach(ram);
        value.transport = std::move(transport);
    });
}
void nativeMovieReleaseFrame(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, uint32_t sofdec,
                             uint32_t frame, uint32_t originalReturnPC) {
    observed("release-frame", runtime, [&] {
        auto& value = game;
        if (runtime != value.runtime || !value.transport ||
            OriginalCompressedLineage::canonical(sofdec) != value.owner.sofdec)
            return;
        healthy(value);
        //15D920 discards a peeked late frame.15E3C0 releases the selected
        // frame after the original client returns it. No host drop policy.
        if (!ctx || ctx->pc != 0x174080 || GPR_U32(ctx, 2) != 0 ||
            (originalReturnPC != 0x15d920 && originalReturnPC != 0x15e3c0))
            throw std::runtime_error(
                "Original movie release lacks its successful174080 branch and audited caller");
        uint32_t physical = 0;
        if (!OriginalCompressedLineage::physical(frame, 0x40, physical))
            throw std::runtime_error("Original movie release frame metadata is outside RDRAM");
        const auto destination = OriginalCompressedLineage::canonical(
            OriginalCompressedLineage::read32(ram, physical + 0x20));
        NativeMovieImageSource source;
        std::shared_ptr<PreparedImageLifetime> lifetime;
        {
            std::lock_guard<std::mutex> lock(value.imagesMutex);
            const auto found = value.images.find(destination);
            const auto state = value.imageLifetimes.find(destination);
            if (found == value.images.end() || state == value.imageLifetimes.end()) {
                char detail[384];
                std::snprintf(detail, sizeof(detail),
                              "Original queue release lacks GPU frame destination binding: "
                              "caller=%08x frame=%08x destination=%08x epoch=%llu generation=%llu "
                              "known_destinations=%llu",
                              originalReturnPC, frame, destination,
                              static_cast<unsigned long long>(value.epoch),
                              static_cast<unsigned long long>(value.owner.generation),
                              static_cast<unsigned long long>(value.images.size()));
                throw std::runtime_error(detail);
            }
            source = found->second;
            lifetime = state->second;
            if (source.epoch != value.epoch || source.generation != value.owner.generation ||
                lifetime->source.outputEventSerial != source.outputEventSerial)
                throw std::runtime_error("Original queue release selected a stale GPU frame");
            if (value.retiredImageBases.count(destination))
                return; // Already retired by its real final IMAGE fence.
            if (lifetime->releasePending)
                throw std::runtime_error(
                    "Original queue release reentered before resident retirement");
            lifetime->releasePending = true;
        }
        const NativeOutputBinding binding{
            source.generation, source.outputEventSerial, source.picture, source.pts90k,
            source.descriptor, source.destination,       source.width,   source.height};
        callOwner(value, [lifetime, binding](reo_movie_owner::Target& target) {
            {
                std::lock_guard<std::mutex> lock(game.imagesMutex);
                const auto base = OriginalCompressedLineage::canonical(binding.destination);
                const auto found = game.images.find(base);
                if (found == game.images.end() || found->second.epoch != lifetime->source.epoch ||
                    found->second.generation != binding.generation ||
                    found->second.picture != binding.picture ||
                    found->second.outputEventSerial != binding.eventSerial)
                    throw std::runtime_error(
                        "Original queue release binding changed before its actual FIFO turn");
                // An earlier real final IMAGE may complete while EE waits for
                // this control request. Its real fence already freed the ticket;
                // never call release on that now-erased producer binding.
                if (game.retiredImageBases.count(base))
                    return;
                if (!lifetime->pendingSourceEvents.empty()) {
                    char detail[384];
                    std::snprintf(
                        detail, sizeof(detail),
                        "Original queue release overtook retained IMAGE preparation without "
                        "preceding real FIFO completion: picture=%llu event=%llu destination=%08x "
                        "pending_count=%llu first_source_event=%llu",
                        static_cast<unsigned long long>(binding.picture),
                        static_cast<unsigned long long>(binding.eventSerial), binding.destination,
                        static_cast<unsigned long long>(lifetime->pendingSourceEvents.size()),
                        static_cast<unsigned long long>(*lifetime->pendingSourceEvents.begin()));
                    throw std::runtime_error(detail);
                }
            }
            service(target).releaseOriginalFrame(binding);
        });
        // This is original queue disposal, never an IMAGE/DMA completion. The
        // untouched following174080..17409C instructions still clear+dispatch
        // its genuine event6 callback and publish actual integer queue state.
        {
            std::lock_guard<std::mutex> lock(value.imagesMutex);
            const auto found = value.images.find(destination);
            if (found == value.images.end() ||
                found->second.outputEventSerial != source.outputEventSerial)
                throw std::runtime_error(
                    "Original frame binding changed during its resident release");
            value.retiredImageBases.insert(destination);
        }
        if (const auto count = diagnosticEvent(diagnostic.release))
            std::fprintf(stderr,
                         "[GPU-MOVIE] release-frame n=%llu epoch=%llu generation=%llu picture=%llu "
                         "output_event=%llu caller=%08x frame=%08x destination=%08x reason=%s\n",
                         static_cast<unsigned long long>(count),
                         static_cast<unsigned long long>(source.epoch),
                         static_cast<unsigned long long>(source.generation),
                         static_cast<unsigned long long>(source.picture),
                         static_cast<unsigned long long>(source.outputEventSerial),
                         originalReturnPC, frame, source.destination,
                         originalReturnPC == 0x15d920 ? "original-discard"
                                                      : "original-client-return");
    });
}
void nativeMovieIssued(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime,
                       uint32_t returnPC) {
    auto& value = game;
    if (value.runtime != runtime)
        return;
    healthy(value);
    if (value.pending || value.requestActive ||
        OriginalCompressedLineage::canonical(GPR_U32(ctx, 18)) != value.owner.work ||
        OriginalCompressedLineage::canonical(GPR_U32(ctx, 21)) != value.owner.sofdec)
        throw std::runtime_error("Original movie picture request reentered or changed owner");
    value.context = ctx;
    value.stack = GPR_U32(ctx, 29);
    value.descriptor = GPR_U32(ctx, 20);
    value.destination = GPR_U32(ctx, 5);
    value.requestReturn = returnPC;
    if (OriginalCompressedLineage::canonical(
            OriginalCompressedLineage::read32(ram, value.descriptor + 0x20)) !=
        OriginalCompressedLineage::canonical(value.destination))
        throw std::runtime_error("Original movie descriptor/destination does not join request");
    value.requestActive = true;
}
void nativeMovieReturned(const uint8_t*, R5900Context* ctx, PS2Runtime* runtime,
                         uint32_t returnPC) {
    auto& value = game;
    if (value.runtime != runtime)
        return;
    if (value.pending || !value.requestActive || value.context != ctx ||
        value.stack != GPR_U32(ctx, 29) || value.requestReturn != returnPC)
        throw std::runtime_error(
            "Original native movie returned before its real numerical producer");
    value.requestActive = false;
}
bool installNativeMovieGame(PS2Runtime& runtime) {
    if (game.runtime || runtime.hasFunction(NativeWaitPC))
        return false;
    constexpr uint32_t aliases[]{0x171d10, 0x171d4c, 0x171d90, 0x171da8, 0x171db0,
                                 0x171dfc, 0x171e10, 0x171e1c, 0x171e24};
    for (auto pc : aliases) {
        const auto original = runtime.lookupFunction(pc);
        if (original != sub_00171D10_0x171d10 && original != reo_movie_join_observed_caller)
            return false;
    }
    if (!reo_gpu_movie_transport::install(runtime, game.lineage, &game, pictureHeader, ringReset))
        return false;
    if (!reo_gpu_movie_graphics::install(runtime, &game, owns, receive))
        throw std::runtime_error("Native movie graphics registry could not be claimed atomically");
    game.runtime = &runtime;
    reo_native_movie::installImageProvider(runtime, lookupImage);
    runtime.registerFunction(NativeWaitPC, wait);
    for (auto pc : aliases)
        runtime.registerFunction(pc, reo_movie_native_171d10);
    return true;
}
NativeMovieImageOwnership lookupNativeMovieImage(PS2Runtime& runtime, uint32_t source,
                                                 uint32_t bytes, NativeMovieImageSource& result) {
    auto& value = game;
    if (value.runtime != &runtime)
        return NativeMovieImageOwnership::Unowned;
    uint32_t physical = 0;
    if (!OriginalCompressedLineage::physical(source, bytes, physical))
        return NativeMovieImageOwnership::Unowned;
    std::lock_guard<std::mutex> lock(value.imagesMutex);
    const uint64_t requestedEnd = uint64_t(physical) + bytes;
    const auto next = value.images.lower_bound(physical);
    if (next != value.images.end() && next->first > physical && next->first < requestedEnd)
        return NativeMovieImageOwnership::Stale;
    auto found = value.images.upper_bound(physical);
    if (found == value.images.begin())
        return NativeMovieImageOwnership::Unowned;
    --found;
    const auto& image = found->second;
    const auto offset = uint64_t(physical) - found->first,
               total = uint64_t(image.width) * image.height * 4;
    if (offset >= total)
        return NativeMovieImageOwnership::Unowned;
    if (image.epoch != gsPrivCurrentEpoch() || value.retiredImageBases.count(found->first) ||
        (value.imageLifetimes.count(found->first) &&
         value.imageLifetimes.at(found->first)->releasePending) ||
        !bytes || (bytes & 15) || (offset & 15) || bytes > total - offset)
        return NativeMovieImageOwnership::Stale;
    result = image;
    result.sourceAddress = source;
    result.sourceByteOffset = uint32_t(offset);
    result.sourceBytes = bytes;
    result.sourceLayout = 2;
    return NativeMovieImageOwnership::Owned;
}
void retireNativeMovieImage(PS2Runtime& runtime, const NativeMovieImageSource& image) {
    auto& value = game;
    if (value.runtime != &runtime)
        throw std::runtime_error("Foreign native movie IMAGE retirement");
    std::lock_guard<std::mutex> lock(value.imagesMutex);
    const auto destination = OriginalCompressedLineage::canonical(image.destination);
    auto found = value.images.find(destination);
    if (found == value.images.end() || found->second.generation != image.generation ||
        found->second.outputEventSerial != image.outputEventSerial ||
        found->second.picture != image.picture || found->second.epoch != image.epoch)
        throw std::runtime_error("Stale original movie IMAGE fence retirement");
    value.retiredImageBases.insert(destination);
}
} // namespace reo_gpu_movie
