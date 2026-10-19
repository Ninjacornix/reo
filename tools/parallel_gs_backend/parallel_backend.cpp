#include "parallel_backend.h"
#include "parent_first_entry.h"
#include "native_movie_owner.h"
#include "resident_vif_live_hooks.h"
#if defined(_WIN32)
#include "resident_dxgi_presenter1c.h"
#include "movie_runtime/movie_owner_service_fwd.h"
#endif
#include "resident_owner_images.h"
#include "stream_helpers.h"
#include "gs_interface.hpp"
#include "gs_util.hpp"
#include "resident_clear_context.hpp"
#include <fstream>
#include <deque>
#include <intrin.h>
#include <cstddef>
#include "context.hpp"
#include "device.hpp"
#include "command_buffer.hpp"
#include "fence.hpp"
#include "thread_id.hpp"
#include "pipeline_cache_store.h"
#include "hash.hpp"
#include <cstdio>
#include <memory>
#include <utility>
namespace reo_parallel_backend {
namespace {
using namespace ParallelGS;
using namespace Vulkan;
using namespace gs_backend_bridge;
constexpr size_t VramSize = 4u * 1024u * 1024u;
static_assert(sizeof(Util::Hash) == 8 && VK_UUID_SIZE == 16 &&
                  VK_MAX_PIPELINE_BINARY_KEY_SIZE_KHR == 32,
              "Pinned Granite pipeline cache codec changed");
// Route serializes all use, so a single command-pool index is sufficient.
// Preserve a host thread's preexisting Granite registration on handoff.
struct ThreadIndexScope {
    unsigned previous = Util::get_current_thread_index();
    ThreadIndexScope() {
        Util::register_thread_index(0);
    }
    ~ThreadIndexScope() {
        Util::register_thread_index(previous);
    }
};
class ParallelBackend final : public Backend, private SignalInterface {
    Config config_;
    Init init_;
    std::unique_ptr<Context> context_;
    std::unique_ptr<Device> device_;
    std::unique_ptr<reo_resident_live::SemanticOwner> residentGeometry_;
    bool residentResetReady_ = false;
    std::unique_ptr<GSInterface> gs_;
    std::unique_ptr<reo_gpu_clear_context::ClearContext> contextClear_;
    std::shared_ptr<reo_movie_owner::Target> movieOwner_;
    bool movieEnabled_ = false;
#if defined(_WIN32)
    std::unique_ptr<reo_gpu_present::ResidentDxgiPresenter> presenter_;
#endif
    reo_gpu_present::ResidentOwnerImages displayImages_;
    uint64_t normalDownloads_ = 0, outputReadbacks_ = 0;
    BufferHandle captureReadback_;
    size_t captureReadbackBytes_ = 0;
    cache_store::Identity cacheIdentity_{};
    std::filesystem::path cachePath_;
    bool cacheReady_ = false;
    GifBoundaryObserver observer_;
    ByteFifo fifo_;
    struct Event {
        uint8_t addr;
        uint64_t payload;
    };
    std::vector<Event> events_;
    // Resumable second-SIGNAL handling, following PCSX2's queued-SIGNAL and
    // CSR-acknowledgment behavior. When a SIGNAL event is completed while the
    // previous SIGNAL event flag (CSR bit 0) is still set, the GIF packet path
    // halts exactly at that event instead of failing: the pending SIGNAL and
    // every later event stay queued, freshly arriving packets are held with
    // their already-observed boundary list, and direct register writes are
    // held as raw lanes. The guest's CSR acknowledgment (W1C write on the
    // event lanes) releases the halt; held work then resumes strictly in the
    // original arrival order and each held event is delivered exactly once.
    // No state waits for the acknowledgment: while halted this backend never
    // blocks a call, it only buffers, so the CSR write can always reach it.
    struct PendingPacket {
        uint8_t path = 0;          // GIF path the packet arrived on
        std::vector<uint8_t> data; // unconsumed packet bytes (16B aligned length)
        std::vector<GifBoundaryObserver::Boundary> boundaries; // observed once at arrival
        size_t next = 0;                                       // first boundary not yet handled
        size_t consumed = 0;                                   // bytes already handed to paraLLEl
    };
    struct PendingRegister {
        uint8_t addr = 0;
        uint64_t value = 0;
    };
    struct PendingWork {
        bool isPacket = false; // false: direct register lane
        PendingPacket packet{};
        PendingRegister register_{};
    };
    std::deque<PendingWork> heldWork_; // arrival order across packets and registers
    bool gifHalted_ = false;           // paused at a queued second-SIGNAL event
    bool deliveringEvents_ = false;    // inside completeEvents() delivery loop
    bool live_ = false;
    void installMovieOwner() {
#if defined(_WIN32)
        if (movieEnabled_) {
            movieOwner_ = reo_gpu_movie::makeMovieOwnerService(
                *device_, *gs_, reo_resident_live::currentGsEpoch(),
                [this](uint32_t bytes) { observer_.consumeImage(3u, bytes); });
            reo_movie_owner::installActualOwner(movieOwner_);
        }
#endif
    }
    void retireMovieOwner() noexcept {
        if (movieOwner_) {
            reo_movie_owner::retireActualOwner(movieOwner_);
            movieOwner_->stop();
            movieOwner_.reset();
        }
    }
    void initializePipelineCache() {
        if (!config_.persistentPipelineCache)
            return;
        const auto& props = device_->get_gpu_properties();
        cacheIdentity_.format =
            device_->get_device_features().pipeline_binary_features.pipelineBinaries ? 1 : 0;
        cacheIdentity_.vendor = props.vendorID;
        cacheIdentity_.device = props.deviceID;
        cacheIdentity_.driver = props.driverVersion;
        cacheIdentity_.flags = config_.descriptorBuffer ? 1 : 0;
        std::memcpy(cacheIdentity_.uuid.data(), props.pipelineCacheUUID, 16);
        std::vector<uint8_t> payload;
        try {
            cachePath_ = config_.pipelineCacheFile.empty()
                             ? cache_store::defaultPath(cacheIdentity_)
                             : std::filesystem::u8path(config_.pipelineCacheFile);
            payload = cache_store::load(cachePath_, cacheIdentity_);
        } catch (...) {
            payload.clear();
            cachePath_.clear();
        }
        try {
            cacheReady_ = device_->init_pipeline_cache(payload.empty() ? nullptr : payload.data(),
                                                       payload.size(), false);
        } catch (...) {
            cacheReady_ = false;
        }
        if (!cacheReady_)
            try {
                cacheReady_ = device_->init_pipeline_cache(nullptr, 0, false);
            } catch (...) {
                cacheReady_ = false;
            }
        std::fprintf(stderr,
                     "[GS-PIPELINE-CACHE] submitted_bytes=%zu ready=%u format=%u disk_path=%u\n",
                     payload.size(), unsigned(cacheReady_), cacheIdentity_.format,
                     unsigned(!cachePath_.empty()));
    }
    void persistPipelineCache() noexcept {
        if (!cacheReady_ || cachePath_.empty())
            return;
        try {
            const size_t size = device_->get_pipeline_cache_size();
            bool saved = false;
            if (size && size <= cache_store::MaxPayload) {
                std::vector<uint8_t> payload(size);
                if (device_->get_pipeline_cache_data(payload.data(), payload.size()))
                    saved = cache_store::save(cachePath_, payload, cacheIdentity_);
            }
            std::fprintf(stderr, "[GS-PIPELINE-CACHE] save_bytes=%zu saved=%u\n", size,
                         unsigned(saved));
        } catch (...) {
            std::fprintf(stderr, "[GS-PIPELINE-CACHE] save_failed=1\n");
        }
    }
    void requireLive() const {
        if (!live_ || !gs_ || !device_)
            throw std::runtime_error("GPU backend is not live");
    }
    bool on_signal(uint64_t p) override {
        events_.push_back({0x60, p});
        return true;
    }
    bool on_finish(uint64_t p) override {
        events_.push_back({0x61, p});
        return true;
    }
    bool on_label(uint64_t p) override {
        events_.push_back({0x62, p});
        return true;
    }
    uint64_t& privWord(uint32_t offset) {
        auto& p = gs_->get_priv_register_state();
        return offset < 0x1000 ? p.qwords_lo[offset / 8] : p.qwords_hi[(offset - 0x1000) / 8];
    }
    Privileged copyPrivileged() {
        Privileged out{};
        for (size_t i = 0; i < out.size(); ++i)
            out[i] = privWord(privilegedOffsets[i]);
        return out;
    }
    bool refreshEventFront() {
        if (!config_.peekEventFrontState)
            return true;
        const auto front = config_.peekEventFrontState();
        if (!front)
            return false;
        privWord(0x1000) = (privWord(0x1000) & ~0x1Full) | ((*front)[15] & 0x1Full);
        privWord(0x1010) = (*front)[16];
        privWord(0x1080) = (*front)[18];
        return true;
    }
    // True while the guest-visible CSR SIGNAL event flag is still set. Uses the
    // same authority completeEvents publishes through, so the acknowledgment
    // cannot race the halt decision.
    bool csrSignalPending() {
        if (!refreshEventFront())
            return false; // owner front retired: no SIGNAL authority
        return (privWord(0x1000) & 1u) != 0u;
    }
    void completeEvents() {
        if (gifHalted_)
            return; // Frontier events stay queued; the CSR acknowledgment resumes them.
        if (deliveringEvents_)
            return; // Reentrant guard: a completion callback (which may
        // read back VRAM) must never re-enter event delivery - the caller that
        // erased nothing would redeliver the same event forever.
        if (events_.empty())
            return;
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        gs_->flush();
        // Correctness-first prefix fence. This is a host GPU wait only: no
        // guest execution or IO lock. A narrower timeline fence may replace it
        // only after its exact completion coverage has been demonstrated.
        device_->wait_idle();
        // Deliver in original event order. A SIGNAL while the previous SIGNAL
        // event flag is still set halts the packet path there: this and every
        // later event stay queued for the guest's CSR acknowledgment, which
        // resumes through releaseQueuedFrontier(). This replaces the former
        // port blocker with an owned, resumable barrier.
        size_t delivered = 0;
        bool dropRemaining = false;
        deliveringEvents_ = true; // cleared with the completion of delivery, exceptions included
        struct DeliveryGuard {
            bool& flag;
            ~DeliveryGuard() {
                flag = false;
            }
        } deliveryGuard{deliveringEvents_};
        while (delivered < events_.size()) {
            const Event event = events_[delivered];
            if (!refreshEventFront()) {
                // Owner execution front retired (epoch change/reset): the
                // remaining queue is stale by definition. Drop without
                // delivery so old events are never replayed into a new epoch.
                dropRemaining = true;
                break;
            }
            if (event.addr == 0x60 && (privWord(0x1000) & 1u)) {
                gifHalted_ = true;
                break;
            }
            auto& status = privWord(0x1000);
            auto& ids = privWord(0x1080);
            if (event.addr == 0x60) {
                const uint32_t mask = uint32_t(event.payload >> 32), id = uint32_t(event.payload);
                ids = (ids & 0xFFFFFFFF00000000ull) | ((uint32_t(ids) & ~mask) | (id & mask));
                status |= 1u;
            } else if (event.addr == 0x61)
                status |= 2u;
            else {
                const uint32_t mask = uint32_t(event.payload >> 32), id = uint32_t(event.payload);
                const uint32_t hi = (uint32_t(ids >> 32) & ~mask) | (id & mask);
                ids = (uint64_t(hi) << 32) | uint32_t(ids);
            }
            if (init_.completedEvent)
                init_.completedEvent(event.addr, event.payload);
            refreshEventFront();
            ++delivered;
        }
        if (dropRemaining)
            events_.clear();
        else if (delivered)
            events_.erase(events_.begin(), events_.begin() + std::ptrdiff_t(delivered));
    }
    // Called from the CSR acknowledgment path in privilegedWrite. The halt is
    // released only when the SIGNAL event flag now reads clear under the same
    // authority the delivery used. Nothing here waits: the caller is the guest
    // acknowledgment itself (or the reset path), already serialized on Route.
    void releaseQueuedFrontier() {
        if (!gifHalted_)
            return;
        if (!refreshEventFront()) {
            // Owner execution front retired while stalled (epoch change/stop):
            // the halt and every held item are stale for the new epoch. Drop
            // them without delivery so nothing is replayed across the epoch
            // boundary; RESET builds the fresh state from here.
            gifHalted_ = false;
            events_.clear();
            heldWork_.clear();
            return;
        }
        if (privWord(0x1000) & 1u)
            return; // pending SIGNAL still unacknowledged
        gifHalted_ = false;
        completeEvents(); // deliver the held SIGNAL and any already-queued events, exactly once
        if (gifHalted_)
            return; // a later queued SIGNAL engaged the halt again
        // Resume held work strictly in arrival order. While partially consumed,
        // a packet stays at the front of heldWork_ with its parser position
        // (consumed/next) intact, so a re-engaged halt resumes exactly there.
        while (!gifHalted_ && !heldWork_.empty()) {
            PendingWork& work = heldWork_.front();
            if (!work.isPacket) {
                PendingRegister item = work.register_;
                heldWork_.pop_front();
                if (residentGeometry_)
                    residentGeometry_->guardPublishedEffects();
                gs_->write_register(static_cast<RegisterAddr>(item.addr), item.value);
                if (item.addr == 0x53)
                    transferBoundary(item.value);
                else
                    completeEvents();
                continue;
            }
            PendingPacket& item = work.packet;
            if (item.consumed >= item.data.size()) {
                heldWork_.pop_front();
                continue;
            }
            if (residentGeometry_)
                residentGeometry_->guardPublishedEffects();
            std::vector<uint64_t> aligned(item.data.size() / 8);
            std::memcpy(aligned.data(), item.data.data(), item.data.size());
            const auto* input = reinterpret_cast<const uint8_t*>(aligned.data());
            while (item.next < item.boundaries.size()) {
                const auto& boundary = item.boundaries[item.next];
                if (boundary.end > item.consumed) {
                    gs_->gif_transfer(item.path - 1, input + item.consumed,
                                      boundary.end - item.consumed);
                    item.consumed = boundary.end;
                }
                ++item.next;
                if (boundary.addr == 0x53)
                    transferBoundary(boundary.value);
                else
                    completeEvents();
                if (gifHalted_)
                    return; // position preserved inside heldWork_.front()
            }
            if (item.consumed < item.data.size()) {
                gs_->gif_transfer(item.path - 1, input + item.consumed,
                                  item.data.size() - item.consumed);
                item.consumed = item.data.size();
            }
            completeEvents(); // trailing events of the held packet
            if (gifHalted_)
                return;            // position preserved; next release resumes the tail
            heldWork_.pop_front(); // packet fully processed
        }
    }
    // Absolute held-work report for the runtime accounting (see the route
    // header). Packet bytes parked behind the SIGNAL are counted; held
    // register lanes count as zero bytes, matching their zero queue charge.
    // Called under Route serialization, so the walk observes a stable hold.
    size_t heldGifBytes() const noexcept override {
        size_t bytes = 0;
        for (const auto& work : heldWork_)
            if (work.isPacket)
                bytes += work.packet.data.size();
        return bytes;
    }
    size_t heldGifCount() const noexcept override {
        // Parked packets/lanes PLUS the events still queued behind the halt.
        // A SIGNAL at a packet's final boundary parks no bytes (empty suffix)
        // yet must still report as outstanding work until it is delivered or
        // explicitly canceled; a zero-item report while an event awaits
        // acknowledgment would hide ownership from the runtime accounting.
        return heldWork_.size() + (gifHalted_ ? events_.size() : 0u);
    }
    void transferBoundary(uint64_t value) {
        if ((uint32_t(value) & 3u) != 1u) {
            fifo_.clear();
            return;
        }
        // The original GS TRXDIR has already completed GPU format conversion.
        // Retain its complete byte tail instead of repeating CPU unswizzle.
        fifo_.replace(gs_->resident_transfer_readback());
    }
    Frame download(const ScanoutResult& scanout, uint64_t tick, const Capture& capture) {
        if (!capture.forceHostReadback)
            ++normalDownloads_;
        Frame frame;
        frame.tick = tick;
        const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
        frame.displayFbp = uint32_t(capture.registers[circuit] & 0x1FF);
        frame.sourceFbp = frame.displayFbp;
        if (!scanout.image)
            return frame;
        const auto& ci = scanout.image->get_create_info();
        const bool bgra =
            ci.format == VK_FORMAT_B8G8R8A8_UNORM || ci.format == VK_FORMAT_B8G8R8A8_SRGB;
        if (!bgra && ci.format != VK_FORMAT_R8G8B8A8_UNORM && ci.format != VK_FORMAT_R8G8B8A8_SRGB)
            throw std::runtime_error("Unexpected GPU scanout format");
        if (ci.width > 4096 || ci.height > 4096)
            throw std::runtime_error("Oversized GPU scanout");
        frame.width = ci.width;
        frame.height = ci.height;
        frame.rgba.resize(size_t(ci.width) * ci.height * 4);
        if (!captureReadback_ || captureReadbackBytes_ < frame.rgba.size()) {
            BufferCreateInfo info{};
            info.domain = BufferDomain::CachedHost;
            info.size = frame.rgba.size();
            info.usage = VK_BUFFER_USAGE_TRANSFER_DST_BIT;
            auto allocated = device_->create_buffer(info);
            if (!allocated)
                throw std::runtime_error("GPU scanout readback allocation failed");
            captureReadback_ = std::move(allocated);
            captureReadbackBytes_ = frame.rgba.size();
        }
        // Previous capture returned only after its copy fence and CPU unmap;
        // serialized Route ownership makes this staging allocation reusable.
        const auto& buffer = captureReadback_;
        device_->wait_idle();
        auto cmd = device_->request_command_buffer();
        cmd->image_barrier(*scanout.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                           VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                           VK_ACCESS_2_MEMORY_WRITE_BIT | VK_ACCESS_2_MEMORY_READ_BIT,
                           VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_READ_BIT);
        VkBufferImageCopy copy{};
        copy.imageSubresource.aspectMask = VK_IMAGE_ASPECT_COLOR_BIT;
        copy.imageSubresource.layerCount = 1;
        copy.imageExtent = {ci.width, ci.height, 1};
        cmd->copy_image_to_buffer(*buffer, *scanout.image, 1, &copy);
        cmd->buffer_barrier(*buffer, VK_PIPELINE_STAGE_TRANSFER_BIT, VK_ACCESS_2_TRANSFER_WRITE_BIT,
                            VK_PIPELINE_STAGE_HOST_BIT, VK_ACCESS_2_HOST_READ_BIT);
        cmd->image_barrier(*scanout.image, VK_IMAGE_LAYOUT_TRANSFER_SRC_OPTIMAL,
                           VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_TRANSFER_BIT,
                           VK_ACCESS_2_TRANSFER_READ_BIT, VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT,
                           VK_ACCESS_2_SHADER_SAMPLED_READ_BIT);
        Fence fence;
        device_->submit(cmd, &fence);
        fence->wait();
        const auto* pixels =
            static_cast<const uint8_t*>(device_->map_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT));
        if (!pixels)
            throw std::runtime_error("GPU scanout readback mapping failed");
        std::memcpy(frame.rgba.data(), pixels, frame.rgba.size());
        device_->unmap_host_buffer(*buffer, MEMORY_ACCESS_READ_BIT);
        if (bgra)
            for (size_t i = 0; i < frame.rgba.size(); i += 4)
                std::swap(frame.rgba[i], frame.rgba[i + 2]);
        return frame;
    }

  public:
    reo_parallel_backend::ResidentDiagnostics diagnostics() const {
#if defined(_WIN32)
        const uint64_t presented = presenter_ ? presenter_->submittedFrames() : 0;
#else
        const uint64_t presented = 0;
#endif
        return {presented,
                normalDownloads_,
                outputReadbacks_,
                displayImages_.serial(),
                displayImages_.fenceWaits(),
                displayImages_.liveImages()};
    }
    Privileged snapshot() {
        ThreadIndexScope threadIndex;
        requireLive();
        return copyPrivileged();
    }
    explicit ParallelBackend(Config config) : config_(std::move(config)) {
#if defined(_WIN32)
        const auto* movie = std::getenv("REO_GPU_MOVIE");
        movieEnabled_ = movie && std::strcmp(movie, "1") == 0;
#endif
    }
    ~ParallelBackend() override {
        close();
    }
    bool init(const Init& value, std::string& error) override {
        ThreadIndexScope threadIndex;
        close();
        if (!config_.validatedDrawing) {
            error = "Clean GPU draw/replay gate is not approved";
            return false;
        }
        if (!config_.publishPrivilegedReset) {
            error = "Coherent guest privileged reset publication is not installed";
            return false;
        }
        if (!config_.peekEventFrontState && !config_.publishStatusAck) {
            error = "Ordered guest CSR acknowledgment publication is not installed";
            return false;
        }
        if (!value.vram || value.vramSize != VramSize) {
            error = "Expected 4 MiB GS VRAM";
            return false;
        }
        init_ = value;
        if (!Context::init_loader(nullptr)) {
            error = "Vulkan loader initialization failed";
            return false;
        }
        context_ = std::make_unique<Context>();
        context_->set_num_thread_indices(1);
        const unsigned flags =
            CONTEXT_CREATION_ENABLE_PUSH_DESCRIPTOR_BIT |
            CONTEXT_CREATION_ENABLE_DESCRIPTOR_HEAP_BIT |
            (config_.descriptorBuffer ? CONTEXT_CREATION_ENABLE_DESCRIPTOR_BUFFER_BIT : 0);
        if (!context_->init_instance_and_device(nullptr, 0, nullptr, 0, flags)) {
            error = "Vulkan device initialization failed";
            close();
            return false;
        }
        device_ = std::make_unique<Device>();
        device_->set_context(*context_);
        device_->init_frame_contexts(4);
        initializePipelineCache();
#if defined(_WIN32)
        if (config_.residentPresentation) {
            displayImages_.beginSession();
            if (!config_.presentationTarget || !config_.presentationEpochCurrent ||
                config_.presentationVertex.empty() || config_.presentationFragment.empty()) {
                error = "Resident presentation configuration is incomplete";
                close();
                return false;
            }
            presenter_ = std::make_unique<reo_gpu_present::ResidentDxgiPresenter>(
                *device_, config_.presentationVertex, config_.presentationFragment);
        }
#else
        if (config_.residentPresentation) {
            error = "Resident DXGI presentation requires Windows";
            close();
            return false;
        }
#endif
        gs_ = std::make_unique<GSInterface>();
        GSOptions options{};
        if (!gs_->init(device_.get(), options)) {
            error = "paraLLEl-GS initialization failed";
            close();
            return false;
        }
        std::memcpy(gs_->map_vram_write(0, VramSize), value.vram, VramSize);
        gs_->end_vram_write(0, VramSize);
        for (size_t i = 0; i < value.registers.size(); ++i)
            privWord(privilegedOffsets[i]) = value.registers[i];
        gs_->set_signal_interface(this);
        installMovieOwner();
        if (config_.residentGeometry.enabled) {
            if ((!config_.residentGeometry.fullProtocolCoverage &&
                 !config_.residentGeometry.authenticColdComponentEnrollment) ||
                !config_.residentGeometry.factory) {
                error = "Resident full VIF/GS protocol is not certified";
                close();
                return false;
            }
            residentGeometry_ = config_.residentGeometry.factory(*device_, *gs_);
            if (!residentGeometry_) {
                error = "Resident geometry owner factory returned null";
                close();
                return false;
            }
            if (config_.residentGeometry.authenticColdComponentEnrollment &&
                (config_.residentGeometry.fullProtocolCoverage ||
                 !residentGeometry_->authenticFirstEntryRequested())) {
                error = "Cold component factory lacks genuine deferred enrollment or claimed full "
                        "coverage";
                close();
                return false;
            }
        }
        reo_parent_natural::setActualFirstEntryEnrollmentRequested(
            residentGeometry_ && residentGeometry_->authenticFirstEntryRequested());
        live_ = true;
        error.clear();
        return true;
    }
    void close() noexcept override {
        ThreadIndexScope threadIndex;
        const bool saveCache = live_ && cacheReady_;
        live_ = false;
        reo_parent_natural::setActualFirstEntryEnrollmentRequested(false);
        retireMovieOwner();
        if (gs_)
            gs_->set_signal_interface(nullptr);
        try {
            if (gs_)
                gs_->flush();
            if (device_)
                device_->wait_idle();
        } catch (...) {
        }
        gifHalted_ = false;
        heldWork_.clear();
        events_.clear();
        fifo_.clear();
        observer_.reset();
        displayImages_.shutdown();
#if defined(_WIN32)
        if (presenter_ && config_.residentStoppedDiagnostic)
            try {
                config_.residentStoppedDiagnostic(displayImages_.liveImages(),
                                                  displayImages_.fenceWaits());
            } catch (...) {
            }
        presenter_.reset();
#endif
        try {
            if (residentGeometry_)
                residentGeometry_->drainBeforeEpochReset();
        } catch (...) {
        }
        residentGeometry_.reset();
        residentResetReady_ = false;
        contextClear_.reset();
        gs_.reset();
        try {
            if (device_)
                device_->wait_idle();
        } catch (...) {
        }
        // GS destruction drains compilation tasks before cache serialization.
        if (saveCache)
            persistPipelineCache();
        captureReadback_.reset();
        captureReadbackBytes_ = 0;
        cacheReady_ = false;
        cachePath_.clear();
        device_.reset();
        context_.reset();
        init_ = {};
    }
    void reset() override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_ && !residentResetReady_)
            throw std::runtime_error("GS reset lacks real resident retirement/epoch preparation");
        residentResetReady_ = false;
        // A GS RESET cancels the resumable-SIGNAL state FIRST: the halt, every
        // held packet suffix and held lane, and all queued events are
        // discarded before any operation capable of delivering them (the
        // former completeEvents() call here delivered queued events into the
        // fresh GS state). Nothing is replayed across the reset boundary.
        // Cancellation releases the retained ownership exactly once; the
        // runtime observes the emptied hold on its next held-work sample and
        // wakes its waiters from there.
        events_.clear();
        gifHalted_ = false;
        heldWork_.clear();
        displayImages_.retireEpoch();
#if defined(_WIN32)
        if (presenter_)
            presenter_->retireSource();
#endif
        retireMovieOwner();
        gs_->reset_context_state();
        observer_.reset();
        fifo_.clear();
        installMovieOwner();
    }
    void rawGif(uint8_t path, const uint8_t* data, size_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!bytes)
            return;
        // Observe exactly once per packet, even while halted: a retried suffix
        // resumes from the stored boundary list instead of advancing the
        // observer a second time.
        const auto boundaries = observer_.observe(path, data, bytes);
        if (gifHalted_) { // Hold the entire incoming packet with its observed boundaries.
            PendingWork work{};
            work.isPacket = true;
            work.packet.path = path;
            work.packet.data.assign(data, data + bytes);
            work.packet.boundaries.assign(boundaries.begin(), boundaries.end());
            heldWork_.push_back(std::move(work));
            return;
        }
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        std::vector<uint64_t> aligned(bytes / 8);
        std::memcpy(aligned.data(), data, bytes);
        const auto* input = reinterpret_cast<const uint8_t*>(aligned.data());
        size_t begin = 0;
        for (size_t index = 0; index < boundaries.size(); ++index) {
            const auto& boundary = boundaries[index];
            gs_->gif_transfer(path - 1, input + begin, boundary.end - begin);
            begin = boundary.end;
            if (boundary.addr == 0x53)
                transferBoundary(boundary.value);
            else
                completeEvents();
            if (gifHalted_) { // Hold the residue of this packet, resumable via the stored list.
                PendingWork work{};
                work.isPacket = true;
                work.packet.path = path;
                work.packet.data.assign(data + begin, data + bytes);
                work.packet.boundaries.reserve(boundaries.size() - index);
                for (size_t rest = index; rest < boundaries.size(); ++rest) {
                    GifBoundaryObserver::Boundary shifted{};
                    shifted.end = boundaries[rest].end - begin;
                    shifted.addr = boundaries[rest].addr;
                    shifted.value = boundaries[rest].value;
                    work.packet.boundaries.push_back(shifted);
                }
                work.packet.next = 1; // the halting boundary was fully handled just above
                work.packet.consumed = 0;
                heldWork_.push_back(std::move(work));
                return;
            }
        }
        if (begin < bytes)
            gs_->gif_transfer(path - 1, input + begin, bytes - begin);
        completeEvents();
    }
    void residentFirstEntry(
        const std::shared_ptr<const reo_parent_natural::ColdEntry>& capture) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("First graphics entry has no same-Device factory owner");
        residentGeometry_->enrollFirstGraphicsEntry(capture);
    }
    void residentParentControl(
        const std::function<void(reo_parent_natural::ControlTarget&)>& call) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_ || !call)
            throw std::runtime_error("No actual connected semantic parent owner");
        residentGeometry_->parentControl(call);
    }
    void residentEnqueue(const reo_resident_live::Batch& batch) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident geometry owner not configured");
        residentGeometry_->enqueue(batch);
    }
    std::vector<reo_resident_live::Retired> residentRetire(reo_resident_live::Barrier reason,
                                                           uint64_t epoch,
                                                           uint64_t generation) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident geometry retirement owner not configured");
        return residentGeometry_->retire(reason, epoch, generation);
    }
    void residentReadData(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident VU bank owner not configured");
        residentGeometry_->readData(offset, destination, bytes);
    }
    void residentReadControls(uint32_t offset, uint8_t* destination, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident VIF control owner not configured");
        residentGeometry_->readControls(offset, destination, bytes);
    }
    void residentImportHandoff(reo_resident_live::Handoff& handoff) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident handoff owner not configured");
        residentGeometry_->importHandoff(handoff);
    }
    void residentExportHandoff(reo_resident_live::Handoff& handoff) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident handoff owner not configured");
        residentGeometry_->exportHandoff(handoff);
    }
    void residentPrepareGsReset(uint64_t epoch) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_) {
            residentGeometry_->prepareGsReset(epoch);
            residentResetReady_ = true;
        }
    }
    void residentRetainFailedLaunch(
        std::vector<reo_resident_live::RetainedLaunchFailure>& out) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (!residentGeometry_)
            throw std::runtime_error("Resident retained-snapshot owner not configured");
        residentGeometry_->retainFailedLaunch(out);
    }
    void directRegister(uint8_t addr, uint64_t value) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (gifHalted_) { // Hold the raw lane; the release replays it in arrival order.
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            return;
        }
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        // Events queued by earlier packets complete first: the direct lane's
        // own event must never overtake them in guest-visible program order.
        completeEvents();
        if (gifHalted_) { // The backlog re-engaged the halt; keep the lane pending.
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            return;
        }
        // paraLLEl executes this write immediately, so a SIGNAL whose event
        // flag is still set must be held BEFORE the write: replaying the held
        // lane later enqueues its event exactly once.
        if (addr == 0x60 && csrSignalPending()) {
            PendingWork work{};
            work.register_.addr = addr;
            work.register_.value = value;
            heldWork_.push_back(std::move(work));
            gifHalted_ = true;
            return;
        }
        gs_->write_register(static_cast<RegisterAddr>(addr), value);
        if (addr == 0x53)
            transferBoundary(value);
        completeEvents();
    }
    void privilegedWrite(uint32_t offset, uint8_t width, uint64_t input) override {
        ThreadIndexScope threadIndex;
        requireLive();
        const uint32_t base = offset & ~15u, lane = offset & 15u;
        if (lane >= 8)
            return; // High half of 128-bit-spaced privileged register.
        if (std::find(privilegedOffsets.begin(), privilegedOffsets.end(), base) ==
            privilegedOffsets.end())
            return;
        if (base == 0x1000) {
            const uint64_t written = mergeLane(0, lane, width, input);
            if (written & (1u << 9)) {
                reset();
                auto& priv = gs_->get_priv_register_state();
                std::memset(&priv, 0, sizeof(priv));
                privWord(0x1010) = 0x7F00;
                privWord(0x1000) = 0x551B4000;
                config_.publishPrivilegedReset(copyPrivileged());
            }
            if (written & (1u << 8))
                flush();
            const uint64_t ack = written & 0x1Fu;
            if (config_.peekEventFrontState)
                refreshEventFront();
            else {
                privWord(0x1000) &= ~ack;
                if (ack)
                    config_.publishStatusAck(ack);
            }
            // Guest CSR acknowledgment (write-one-to-clear on the event lanes)
            // releases a queued second-SIGNAL halt; nothing waited for it, but
            // reaching here while halted means the guest is unblocked now.
            releaseQueuedFrontier();
            return;
        }
        if (base == 0x1010) {
            const uint64_t merged = mergeLane(privWord(base), lane, width, input);
            privWord(base) = (merged & 0x1F00u) | 0x6000u;
            return;
        }
        privWord(base) = mergeLane(privWord(base), lane, width, input);
    }
    Frame capture(const Capture& capture) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        // Display marker owns display fields. CSR/event IDs stay backend-owned;
        // only FIELD is consumed from the guest clock for scanout phase.
        for (size_t i = 0; i < 15; ++i)
            privWord(privilegedOffsets[i]) = capture.registers[i];
        VSyncInfo info{};
        info.phase = uint32_t(capture.registers[15] >> 13) & 1;
        info.dst_layout = VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL;
        info.dst_stage = VK_PIPELINE_STAGE_FRAGMENT_SHADER_BIT;
        info.dst_access = VK_ACCESS_2_SHADER_SAMPLED_READ_BIT;
        info.adapt_to_internal_horizontal_resolution = true;
        info.force_progressive = config_.forceProgressive;
        info.anti_blur = config_.antiBlur;
        gs_->flush();
        auto scanout = gs_->vsync(info);
#if defined(_WIN32)
        if (presenter_ && scanout.image) {
            if (!config_.presentationEpochCurrent(capture.epoch))
                return {};
            const auto target = config_.presentationTarget();
            Vulkan::Fence complete;
            const bool visible = target.hwnd && target.width && target.height;
            if (visible) {
                presenter_->attach(reinterpret_cast<HWND>(target.hwnd), target.width,
                                   target.height);
                if (!config_.presentationEpochCurrent(capture.epoch))
                    return {};
                complete = presenter_->present(scanout.image, false, target.linear);
            } else {
                // Minimize/attach suspension is not a backend failure. Retain
                // the newly rendered source after a genuine queue fence.
                auto command = device_->request_command_buffer();
                command->image_barrier(
                    *scanout.image, VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL,
                    VK_IMAGE_LAYOUT_READ_ONLY_OPTIMAL, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                    VK_ACCESS_2_MEMORY_WRITE_BIT, VK_PIPELINE_STAGE_ALL_COMMANDS_BIT,
                    VK_ACCESS_2_MEMORY_READ_BIT);
                device_->submit(command, &complete);
            }
            const auto serial =
                displayImages_.retain(scanout.image, std::move(complete), capture.epoch);
            if (visible && config_.diagnosticOutputRequested && config_.diagnosticOutput &&
                config_.diagnosticOutputRequested(capture.tick)) {
                auto bytes = presenter_->diagnosticShaderOutput();
                ++outputReadbacks_;
                config_.diagnosticOutput(capture.tick, bytes, target.width, target.height);
            }
            if (!capture.forceHostReadback) {
                const auto& image = scanout.image->get_create_info();
                Frame frame;
                frame.width = image.width;
                frame.height = image.height;
                frame.tick = capture.tick;
                const size_t circuit = (capture.registers[0] & 1u) ? 7 : 9;
                frame.displayFbp = uint32_t(capture.registers[circuit] & 0x1FF);
                frame.sourceFbp = frame.displayFbp;
                reo_gpu_present::Receipt receipt{};
                receipt.tick = frame.tick;
                receipt.epoch = capture.epoch;
                receipt.serial = serial;
                receipt.width = frame.width;
                receipt.height = frame.height;
                receipt.displayFbp = frame.displayFbp;
                receipt.sourceFbp = frame.sourceFbp;
                frame.resident = receipt;
                return frame;
            }
        }
#endif
        return download(scanout, capture.tick, capture);
    }
    void exportVram(size_t offset, uint8_t* dst, size_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (offset > VramSize || bytes > VramSize - offset || (!dst && bytes))
            throw std::out_of_range("VRAM readback range");
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        if (bytes)
            std::memcpy(dst, gs_->map_vram_read(offset, bytes), bytes);
    }
    uint32_t readTransfer(uint8_t* dst, uint32_t bytes) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        return fifo_.read(dst, bytes);
    }
    bool clearContext(uint32_t context, uint32_t rgba, bool active) override {
        ThreadIndexScope threadIndex;
        requireLive();
        if (residentGeometry_)
            residentGeometry_->guardPublishedEffects();
        completeEvents();
        const auto& r = gs_->resident_command_register_state();
        const auto& c = r.ctx[active ? uint32_t(r.prim.desc.CTXT) : (context ? 1 : 0)];
        const uint32_t psm = c.frame.desc.PSM;
        if (!c.frame.desc.FBW ||
            (psm != PSMCT32 && psm != PSMCT24 && psm != PSMCT16 && psm != PSMCT16S))
            return false;
        if (!contextClear_) {
            const auto directory =
                std::filesystem::path(__FILE__).parent_path() / "resident_gs/shaders";
            const std::array<const char*, 3> names{"clear_setup.spv", "clear_bounds.spv",
                                                   "clear_write.spv"};
            std::array<std::vector<uint32_t>, 3> modules;
            for (size_t k = 0; k < names.size(); ++k) {
                std::ifstream file(directory / names[k], std::ios::binary | std::ios::ate);
                if (!file)
                    throw std::runtime_error("Missing pinned GPU context clear shader");
                const auto bytes = file.tellg();
                if (bytes < 20 || bytes > 65536 || (uint64_t(bytes) & 3u))
                    throw std::runtime_error("GPU clear shader size differs");
                modules[k].resize(size_t(bytes) / 4u);
                file.seekg(0);
                file.read(reinterpret_cast<char*>(modules[k].data()), bytes);
                if (!file)
                    throw std::runtime_error("GPU clear shader read failed");
            }
            contextClear_ =
                std::make_unique<reo_gpu_clear_context::ClearContext>(*device_, modules);
        }
        auto command = device_->request_command_buffer(CommandBuffer::Type::Generic);
        try {
            if (!gs_->record_resident_context_clear(*command, *contextClear_, context, rgba,
                                                    active)) {
                device_->submit_discard(command);
                return false;
            }
            device_->submit(command);
            return true;
        } catch (...) {
            if (command)
                device_->submit_discard(command);
            throw;
        }
    }

    void flush() override {
        ThreadIndexScope threadIndex;
        requireLive();
        gs_->flush();
        completeEvents();
    }
};
} // namespace
gs_backend_bridge::Factory makeFactory(Config config) {
    return [config = std::move(config)] { return std::make_unique<ParallelBackend>(config); };
}
ResidentDiagnostics residentDiagnostics(gs_backend_bridge::Backend& value) {
    auto* backend = dynamic_cast<ParallelBackend*>(&value);
    if (!backend)
        throw std::invalid_argument("Not the actual parallel backend");
    return backend->diagnostics();
}
gs_backend_bridge::Privileged snapshotPrivileged(gs_backend_bridge::Backend& backend) {
    auto* concrete = dynamic_cast<ParallelBackend*>(&backend);
    if (!concrete)
        throw std::invalid_argument("Not a concrete paraLLEl-GS backend");
    return concrete->snapshot();
}
} // namespace reo_parallel_backend
