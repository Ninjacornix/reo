#pragma once
#include "mpeg2_stream.h"
#include "same_owner_movie_bridge.h"
#include "movie_session.h" // Literal MovieUpload / MovieDmaReceipt ABI.
#include <map>
#include <mutex>
#include <variant>
#include <cstdio>
#include <climits>
#include <cstdlib>

namespace reo_gpu_movie {
// Caller obtains these fields at the genuine original144500 entry, following
// original145D60/145E28 header parsing. Header offsets are committed ES offsets,
// never a masked physical MADR or the libmpeg picture counter.
struct OriginalDecodeEvent {
    uint64_t generation = 0, serial = 0, elementaryPictureBegin = 0;
    uint32_t inner = 0, width = 0, height = 0, kind = 0, structure = 0, temporalReference = 0;
    uint64_t headerSerial = 0, headerDmaSerial = 0, headerCursorBit = 0;
    uint32_t originalTemporalReference = 0, originalTemporalBase = 0;
    uint32_t referenceMetadata = 0;
};
struct NativeDecodeCompletion {
    uint64_t generation = 0, eventSerial = 0, picture = 0, elementaryEnd = 0;
    int64_t pts90k = 0;
    // Ready requires the actual producer fence, not host elapsed time. Original
    // integer controller consumes the compressed cursor and returns success.
    bool ready = false;
};
struct OriginalOutputEvent {
    uint64_t generation = 0, serial = 0;
    uint32_t inner = 0, descriptor = 0, destination = 0, width = 0, height = 0;
    uint32_t th0 = 0, th1 = 0;
    bool actualThresholds = false;
    uint32_t referenceMetadata = 0;
    int64_t playerPts90k = UnboundMoviePts;
    bool actualPlayerPts = false;
    bool originalTimeAbsent = false;
    int64_t referencePts90k = UnboundMoviePts;
    uint32_t clockEnabled = 0;
    int32_t lastClockPts = -1;
};
struct NativeOutputBinding {
    uint64_t generation = 0, eventSerial = 0, picture = 0;
    int64_t pts90k = 0;
    uint32_t descriptor = 0, destination = 0, width = 0, height = 0;
};
struct CompressedDmaCopy {
    uint64_t generation = 0, dmaSerial = 0, elementaryOffset = 0;
    uint32_t sourceAddress = 0, bytes = 0;
    // This is receipt of a real compressed-byte ownership copy. It never
    // claims VLD, CSC, decoded output, display or guest movie completion.
    bool bytesCopied = false;
};
class LiveMovieProducer {
    struct Input {
        uint64_t serial = 0, offset = 0;
        uint32_t source = 0;
        std::vector<uint8_t> bytes;
    };
    struct Timestamp {
        PesTimestamp value;
    };
    struct End {};
    using InputEvent = std::variant<Input, Timestamp, End>;
    struct Output {
        StreamPicture metadata;
        MovieTextureTicket ticket;
        uint64_t outputEvent = 0;
        uint32_t th0 = 0, th1 = 0, referenceMetadata = 0;
        std::map<uint32_t, uint32_t> consumedSpans;
    };
    struct Decode {
        OriginalDecodeEvent event;
        MovieTextureTicket ticket;
        uint64_t end = 0;
    };
    struct Upload {
        MovieDmaReceipt receipt;
        bool retired = false, final = false;
        Vulkan::Fence fence;
    };
    struct UploadBatch {
        NativeOutputBinding binding;
        MovieTextureTicket ticket;
        std::vector<uint64_t> serials;
        bool final = false;
    };
    MovieSessionOwner owner_;
    uint32_t inner_ = 0, width_ = 0, height_ = 0;
    SameOwnerMovieBridge bridge_;
    Mpeg2ElementaryStream parser_;
    std::mutex inputMutex_;
    std::deque<InputEvent> input_;
    size_t copiedPending_ = 0;
    uint64_t copiedOffset_ = 0, lastInputSerial_ = 0, commitSerial_ = 0;
    std::vector<uint8_t> transportHistory_;
    uint64_t historyBase_ = 0;
    bool committedInput_ = false, inputClosed_ = false, parsedEnd_ = false, closed_ = false,
         poisoned_ = false;
    // REO_GPU_MOVIE_LOG-only: why decode() returned not-ready (1 no parsed picture, 2 enqueue refused, 3 GPU not done).
    // Original file-end proof (EE side): every compressed byte the game will ever commit before its EOS marker.
    uint64_t finalInputAt_ = 0;
    bool finalFlushed_ = false;
    // Deadlock breaker: consecutive reason-1 polls with no new input while the game waits on one decode event.
    uint64_t starvedPolls_ = 0, starvedOffset_ = UINT64_MAX, flushedAt_ = UINT64_MAX;
    static constexpr uint64_t StarvedPollsBeforeFlush = 256;
    unsigned notReadyReason_ = 0;
    uint64_t notReadySerial_ = 0, notReadyCount_ = 0;
    // Output side (REO_GPU_MOVIE_LOG): 4 waits for a later anchor (display order), 5 GPU picture unfinished, 6 no
    // un-output decoded picture at all.
    unsigned outReason_ = 0;
    uint64_t outSerial_ = 0, outCount_ = 0;
    bool outputNotReady(unsigned reason, uint64_t serial, int64_t displayOrder) {
        static const bool log = [] {
            const char* v = std::getenv("REO_GPU_MOVIE_LOG");
            return v && *v && *v != '0';
        }();
        if (log) {
            const bool changed = reason != outReason_ || serial != outSerial_;
            ++outCount_;
            if (changed || (outCount_ & 4095u) == 0) {
                int64_t lo = INT64_MAX, hi = INT64_MIN;
                size_t unout = 0;
                for (const auto& [o, pic] : outputs_)
                    if (!pic.outputEvent) {
                        ++unout;
                        lo = std::min(lo, o);
                        hi = std::max(hi, o);
                    }
                std::fprintf(stderr,
                             "[GPU-MOVIE-OUT-NOTREADY] event=%llu reason=%u count=%llu "
                             "display=%lld anchor=%lld outputs=%zu unoutput=%zu lo=%lld hi=%lld "
                             "parserPicture=%u seqEnd=%u decodes=%zu\n",
                             (unsigned long long)serial, reason,
                             (unsigned long long)(changed ? 1 : outCount_), (long long)displayOrder,
                             (long long)currentAnchorOrder_, outputs_.size(), unout, (long long)lo,
                             (long long)hi, parser_.hasPicture() ? 1u : 0u,
                             parser_.sequenceEnded() ? 1u : 0u, decodes_.size());
            }
            if (changed) {
                outReason_ = reason;
                outSerial_ = serial;
                outCount_ = 1;
            }
        }
        return false;
    }
    bool notReady(unsigned reason, uint64_t serial) {
        static const bool log = [] {
            const char* v = std::getenv("REO_GPU_MOVIE_LOG");
            return v && *v && *v != '0';
        }();
        if (log) {
            const bool changed = reason != notReadyReason_ || serial != notReadySerial_;
            ++notReadyCount_;
            if (changed || (notReadyCount_ & 4095u) == 0) {
                size_t queued = 0;
                bool closed = false;
                {
                    std::lock_guard<std::mutex> lock(inputMutex_);
                    queued = input_.size();
                    closed = inputClosed_;
                }
                std::fprintf(
                    stderr,
                    "[GPU-MOVIE-NOTREADY] event=%llu reason=%u count=%llu parsedEnd=%u "
                    "inputClosed=%u committed=%u queued=%zu copiedOffset=%llu decodeSerial=%llu "
                    "outputs=%zu pending=%zu code=%02x rows=%u slices=%u lastRow=%u starved=%llu\n",
                    (unsigned long long)serial, reason,
                    (unsigned long long)(changed ? 1 : notReadyCount_), parsedEnd_ ? 1u : 0u,
                    closed ? 1u : 0u, committedInput_ ? 1u : 0u, queued,
                    (unsigned long long)copiedOffset_, (unsigned long long)decodeSerial_,
                    outputs_.size(), parser_.pendingBytes(), parser_.pendingCode(),
                    parser_.rowsMb(), parser_.currentSlices(), parser_.currentLastRow(),
                    (unsigned long long)starvedPolls_);
            }
            if (changed) {
                notReadyReason_ = reason;
                notReadySerial_ = serial;
                notReadyCount_ = 1;
            }
        }
        return false;
    }
    uint16_t oldAnchor_ = 0xffff, newAnchor_ = 0xffff;
    uint64_t decodeSerial_ = 0, lastOutputSerial_ = 0, lastUploadSerial_ = 0;
    int64_t currentAnchorOrder_ = std::numeric_limits<int64_t>::min(), stampAnchor_ = 0;
    std::map<int64_t, Output> outputs_;
    std::map<uint64_t, Decode> decodes_;
    std::map<uint64_t, NativeOutputBinding> bindings_;
    std::map<uint64_t, Upload> uploads_;
    std::optional<UploadBatch> uploadBatch_;
    static int64_t unwrap(uint64_t value, int64_t anchor) {
        constexpr int64_t span = int64_t(1) << 33, half = span / 2;
        int64_t result = (anchor & ~(span - 1)) + int64_t(value);
        if (result - anchor > half)
            result -= span;
        else if (anchor - result > half)
            result += span;
        return result;
    }
    void open() const {
        if (closed_ || poisoned_)
            throw std::logic_error("Live movie producer closed/failed");
    }
    void pollUploads() {
        for (auto& [serial, job] : uploads_)
            if (!job.retired && job.fence && job.fence->wait_timeout(0)) {
                if (!job.final || bridge_.retireConsumed(job.receipt.texture)) {
                    job.retired = true;
                    job.fence.reset();
                }
            }
    }

  public:
    using Recorder = MovieSession::Recorder;
    LiveMovieProducer(MovieSessionOwner owner, uint32_t inner, Vulkan::Device& gs,
                      ID3D11Device* decoder, uint32_t width, uint32_t height,
                      const std::vector<uint32_t>& shader)
        : owner_(owner), inner_(inner), width_(width), height_(height),
          bridge_(gs, decoder, owner.generation, width, height, shader) {
        if (!owner.generation || !owner.sofdec || !owner.work || !inner)
            throw std::invalid_argument("Missing actual original movie owner");
    }
    ~LiveMovieProducer() {
        cancel();
    }
    // Actual source-preserving170DB0 commit, after original171BE0 copied the
    // selected PES bytes and acquired the original semaphore. This supplies a
    // complete picture to hardware without waiting for CPU BDEC to consume it.
    // It is an owned compressed copy; it never manufactures a B400 DMA serial,
    // advances a guest channel or returns a decoder completion.
    bool commitElementary(uint64_t generation, uint64_t elementaryOffset,
                          std::span<const uint8_t> compressed) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        if (closed_ || inputClosed_ || generation != owner_.generation ||
            elementaryOffset != copiedOffset_ || compressed.empty() ||
            compressed.size() > 512 * 1024 ||
            elementaryOffset > std::numeric_limits<uint64_t>::max() - compressed.size())
            throw std::invalid_argument("Original compressed commit lifetime/range mismatch");
        if (copiedPending_ + compressed.size() > 512 * 1024 || input_.size() >= 1024)
            return false;
        if (lastInputSerial_ && !committedInput_)
            throw std::logic_error("Native movie input provenance changed after DMA feeding");
        committedInput_ = true;
        Input input;
        input.serial = ++commitSerial_;
        input.offset = elementaryOffset;
        input.bytes.assign(compressed.begin(), compressed.end());
        input_.emplace_back(std::move(input));
        copiedPending_ += compressed.size();
        copiedOffset_ += compressed.size();
        transportHistory_.insert(transportHistory_.end(), compressed.begin(), compressed.end());
        if (transportHistory_.size() > 2 * 1024 * 1024) {
            const auto trim = transportHistory_.size() - 2 * 1024 * 1024;
            transportHistory_.erase(transportHistory_.begin(), transportHistory_.begin() + trim);
            historyBase_ += trim;
        }
        return true;
    }
    void commitTransportTail(uint64_t generation, uint64_t offset, std::span<const uint8_t> bytes) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        if (closed_ || !inputClosed_ || !committedInput_ || generation != owner_.generation ||
            offset != copiedOffset_ || bytes.empty() || bytes.size() > 1024 * 1024 ||
            offset > std::numeric_limits<uint64_t>::max() - bytes.size())
            throw std::invalid_argument(
                "Original EOF transport-only tail has no exact lifetime/range");
        // Actual original171984 publishes these untouched raw ring bytes after
        // EOS. Retain only for real B400 receipt/replay. No parser input, PTS,
        // decoder invocation, output or completion is inferred from them.
        copiedOffset_ += bytes.size();
        transportHistory_.insert(transportHistory_.end(), bytes.begin(), bytes.end());
        if (transportHistory_.size() > 2 * 1024 * 1024) {
            const auto trim = transportHistory_.size() - 2 * 1024 * 1024;
            transportHistory_.erase(transportHistory_.begin(), transportHistory_.begin() + trim);
            historyBase_ += trim;
        }
    }
    // CPU DMA/control thread. Runtime validates the original channel/tag/source
    // provenance, supplies EXACT transferred compressed bytes and updates its
    // real MADR/QWC only for the returned count. The bounded queue owns those
    // bytes before this function acknowledges the input copy. It performs no
    // decoded-picture work. Original IPU/header parsing may retain its separate
    // compressed view until seekCompressedAfterDecode reaches the proven end.
    bool copyB400(uint64_t generation, uint64_t serial, uint64_t elementaryOffset,
                  uint32_t sourceAddress, std::span<const uint8_t> compressed,
                  CompressedDmaCopy& receipt) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        // IPU prefetch at/after the committed end (lineage-mapped stale ring bytes): acknowledge, never ES input.
        if (committedInput_ && !closed_ && generation == owner_.generation &&
            serial > lastInputSerial_ && elementaryOffset >= copiedOffset_ && !compressed.empty() &&
            !(compressed.size() & 15) && compressed.size() <= 512 * 1024) {
            lastInputSerial_ = serial;
            receipt = {
                generation, serial, elementaryOffset, sourceAddress, uint32_t(compressed.size()),
                true};
            return true;
        }
        if (closed_ || generation != owner_.generation || !serial || serial <= lastInputSerial_ ||
            elementaryOffset > copiedOffset_ || elementaryOffset < historyBase_ ||
            compressed.empty() || (compressed.size() & 15) || compressed.size() > 512 * 1024 ||
            elementaryOffset > std::numeric_limits<uint64_t>::max() - compressed.size())
            throw std::invalid_argument("Original B400 compressed DMA identity/range is invalid");
        // Original171160 can restore/re-DMA already-owned FIFO bytes. Verify
        // their exact original logical range and never append them twice.
        const size_t overlap =
            size_t(std::min<uint64_t>(copiedOffset_ - elementaryOffset, compressed.size()));
        if (overlap &&
            std::memcmp(transportHistory_.data() + size_t(elementaryOffset - historyBase_),
                        compressed.data(), overlap))
            throw std::invalid_argument("Restored original compressed DMA bytes changed");
        auto fresh = compressed.subspan(overlap);
        // Final partial quadword straddling the committed end (lineage resolve proved the prefix): the tail is
        // ring memory past the stream, not ES bytes. Do not append it; a later real commit may still land there.
        if (committedInput_ && !fresh.empty() && overlap && fresh.size() < 16)
            fresh = fresh.subspan(fresh.size());
        if (committedInput_ && !fresh.empty())
            throw std::invalid_argument("Original B400 outran genuine selected ES ring commits");
        if (inputClosed_ && !fresh.empty())
            throw std::invalid_argument("Original B400 appended after actual compressed EOF");
        if (copiedPending_ + fresh.size() > 512 * 1024 || input_.size() >= 1024)
            return false;
        if (!fresh.empty()) {
            Input input;
            input.serial = serial;
            input.offset = copiedOffset_;
            input.source = sourceAddress + uint32_t(overlap);
            input.bytes.assign(fresh.begin(), fresh.end());
            input_.emplace_back(std::move(input));
            copiedPending_ += fresh.size();
            copiedOffset_ += fresh.size();
            transportHistory_.insert(transportHistory_.end(), fresh.begin(), fresh.end());
            if (transportHistory_.size() > 2 * 1024 * 1024) {
                const auto trim = transportHistory_.size() - 2 * 1024 * 1024;
                transportHistory_.erase(transportHistory_.begin(),
                                        transportHistory_.begin() + trim);
                historyBase_ += trim;
            }
        }
        lastInputSerial_ = serial;
        receipt = {generation, serial, elementaryOffset, sourceAddress, uint32_t(compressed.size()),
                   true};
        return true;
    }
    // Actual original PES demux timestamp range, serialized BEFORE matching
    // bytes. No estimate from VSYNC, CPU time, TR, fps or outer+8 is accepted.
    void demuxTimestamp(uint64_t generation, const PesTimestamp& timestamp) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        if (closed_ || inputClosed_ || generation != owner_.generation || input_.size() >= 1024)
            throw std::logic_error("Movie timestamp source lifetime/order");
        input_.emplace_back(Timestamp{timestamp});
    }
    // EE side: original171920 file-end flag is set and ring+0x48 committed this many ES bytes. The original writes
    // only its 16-byte sequence-end marker after the ring drains; no further picture bytes can follow.
    void finalInput(uint64_t generation, uint64_t committed) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        if (closed_ || generation != owner_.generation || finalInputAt_)
            return;
        finalInputAt_ = committed;
        const char* v = std::getenv("REO_GPU_MOVIE_LOG");
        if (v && *v && *v != '0')
            std::fprintf(
                stderr,
                "[GPU-MOVIE-EOF] file-end generation=%llu committed=%llu copied=%llu queued=%zu\n",
                (unsigned long long)generation, (unsigned long long)committed,
                (unsigned long long)copiedOffset_, input_.size());
    }
    void inputEnd(uint64_t generation) {
        std::lock_guard<std::mutex> lock(inputMutex_);
        if (closed_ || inputClosed_ || generation != owner_.generation)
            throw std::logic_error("Movie input EOF lifetime");
        inputClosed_ = true;
        input_.emplace_back(End{});
    }
    // GS owner thread. Process only enough copied transport to obtain the next
    // full picture. The original decoder server controls actual decode events;
    // this method does not pre-decode or advance its counters on the host.
    void pumpInput() {
        open();
        pollUploads();
        try {
            while (!parser_.hasPicture() && !parsedEnd_) {
                std::optional<InputEvent> event;
                {
                    std::lock_guard<std::mutex> lock(inputMutex_);
                    if (input_.empty())
                        break;
                    event.emplace(std::move(input_.front()));
                    input_.pop_front();
                    if (auto* input = std::get_if<Input>(&*event))
                        copiedPending_ -= input->bytes.size();
                }
                if (auto* input = std::get_if<Input>(&*event))
                    parser_.feed(input->offset, input->bytes);
                else if (auto* timestamp = std::get_if<Timestamp>(&*event))
                    parser_.timestamp(timestamp->value);
                else {
                    parser_.end();
                    parsedEnd_ = true;
                }
            }
            // Original file end reached and all of it fed: complete the last picture (real HW IPU needs no next start code).
            if (finalFlushed_ && parser_.accepted() != flushedAt_)
                finalFlushed_ = false; // more input: the flush was not the end
            if (!parser_.hasPicture() && !parsedEnd_ && flushedAt_ != parser_.accepted()) {
                bool drained = false, starved = false;
                {
                    std::lock_guard<std::mutex> lock(inputMutex_);
                    drained = input_.empty() && finalInputAt_ && finalInputAt_ == copiedOffset_ &&
                              parser_.accepted() == copiedOffset_;
                    (void)starved;
                } // timing-based fallback removed: the real cause was the unprocessed sequence_end_code
                if (drained || starved) {
                    parser_.flushFinalUnit();
                    finalFlushed_ = true;
                    flushedAt_ = parser_.accepted();
                    starvedPolls_ = 0;
                    static const bool log = [] {
                        const char* v = std::getenv("REO_GPU_MOVIE_LOG");
                        return v && *v && *v != '0';
                    }();
                    if (log)
                        std::fprintf(stderr,
                                     "[GPU-MOVIE-EOF] final-flush generation=%llu bytes=%llu "
                                     "picture=%u proof=%s\n",
                                     (unsigned long long)owner_.generation,
                                     (unsigned long long)copiedOffset_,
                                     parser_.hasPicture() ? 1u : 0u,
                                     drained ? "demux-end" : "starved-final-row");
                }
            }
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    // Real numerical144500 replacement. Repeating a pending serial only polls
    // its same real producer; it never starts another decode or skips a frame.
    bool decode(const OriginalDecodeEvent& event, uint32_t th0, uint32_t th1,
                NativeDecodeCompletion& completion) {
        open();
        pumpInput();
        if (event.generation != owner_.generation || event.inner != inner_ || !event.serial ||
            !event.headerSerial || !event.referenceMetadata ||
            event.headerCursorBit != (event.elementaryPictureBegin + 4) * 8 ||
            event.width != width_ || event.height != height_ || event.structure != 3 || th0 > 511 ||
            th1 > 511)
            throw std::invalid_argument("Original decode event/source identity mismatch");
        auto pending = decodes_.find(event.serial);
        if (pending == decodes_.end()) {
            if (event.serial <= decodeSerial_)
                throw std::invalid_argument("Stale/replayed original decode event");
            if (!parser_.hasPicture()) {
                if (starvedOffset_ != copiedOffset_) {
                    starvedOffset_ = copiedOffset_;
                    starvedPolls_ = 0;
                } else
                    ++starvedPolls_;
                return notReady(1, event.serial);
            }
            const auto& p = parser_.picture();
            if (p.begin != event.elementaryPictureBegin || p.kind != event.kind ||
                p.temporalReference != event.temporalReference || p.width != event.width ||
                p.height != event.height || p.parameters.bPicStructure != event.structure) {
                char detail[1024];
                std::snprintf(
                    detail, sizeof(detail),
                    "Original header and exact PES picture do not join: event=%llu header=%llu "
                    "dma=%llu cursor_bit=%llu actual_begin=%llu expected_picture=%llu "
                    "expected_begin=%llu expected_end=%llu actual_kind=%u expected_kind=%u "
                    "actual_tr=%u expected_tr=%u original_tr=%u original_base=%u actual_size=%ux%u "
                    "expected_size=%ux%u actual_structure=%u expected_structure=%u pts_present=%u "
                    "pts_valid=%u pts=%llu pes_begin=%llu pes_end=%llu",
                    static_cast<unsigned long long>(event.serial),
                    static_cast<unsigned long long>(event.headerSerial),
                    static_cast<unsigned long long>(event.headerDmaSerial),
                    static_cast<unsigned long long>(event.headerCursorBit),
                    static_cast<unsigned long long>(event.elementaryPictureBegin),
                    static_cast<unsigned long long>(p.ordinal),
                    static_cast<unsigned long long>(p.begin),
                    static_cast<unsigned long long>(p.end), event.kind, unsigned(p.kind),
                    event.temporalReference, unsigned(p.temporalReference),
                    event.originalTemporalReference, event.originalTemporalBase, event.width,
                    event.height, p.width, p.height, event.structure,
                    unsigned(p.parameters.bPicStructure), p.timestamp ? 1u : 0u,
                    p.timestamp && p.timestamp->hasPts ? 1u : 0u,
                    static_cast<unsigned long long>(p.timestamp ? p.timestamp->pts33 : 0),
                    static_cast<unsigned long long>(p.timestamp ? p.timestamp->elementaryBegin : 0),
                    static_cast<unsigned long long>(p.timestamp ? p.timestamp->elementaryEnd : 0));
                throw std::invalid_argument(detail);
            }
            const bool hasPts = p.timestamp && p.timestamp->hasPts;
            const auto pts =
                hasPts ? unwrap(p.timestamp->pts33, p.timestamp->hasDts
                                                        ? unwrap(p.timestamp->dts33, stampAnchor_)
                                                        : stampAnchor_)
                       : UnboundMoviePts;
            // Original146188 has already extended the picture's TR through
            // the genuine GOP base. This is ordering metadata, never a PTS.
            const int64_t displayOrder = int32_t(event.originalTemporalReference);
            if (outputs_.count(displayOrder))
                throw std::runtime_error("Repeated original picture display index");
            const bool anchor = p.kind != 3;
            const uint16_t target = anchor ? (newAnchor_ == 0 ? 1 : 0) : 2;
            auto submission = p.submission();
            submission.picture.wDecodedPictureIndex = target;
            submission.picture.wForwardRefPictureIndex =
                p.kind == 1 ? 0xffff : (anchor ? newAnchor_ : oldAnchor_);
            submission.picture.wBackwardRefPictureIndex = p.kind == 3 ? newAnchor_ : 0xffff;
            if ((p.kind == 2 && newAnchor_ == 0xffff) ||
                (p.kind == 3 && (oldAnchor_ == 0xffff || newAnchor_ == 0xffff)))
                throw std::runtime_error(
                    "Native original decode requires an absent real reference");
            MoviePictureIdentity identity{};
            identity.generation = owner_.generation;
            identity.picture = p.ordinal;
            identity.compressedBegin = p.begin;
            identity.compressedEnd = p.end;
            identity.sofdec = owner_.sofdec;
            identity.work = owner_.work;
            identity.pts90k = pts;
            identity.truePictureBoundaries = true;
            identity.truePlayerPts = hasPts;
            identity.originalHeaderSerial = event.headerSerial;
            identity.originalReferenceMetadata = event.referenceMetadata;
            identity.originalDisplayIndex = int32_t(displayOrder);
            identity.pendingPlayerPts = !hasPts;
            if (submission.picture.wForwardRefPictureIndex != 0xffff)
                identity.forwardGeneration =
                    bridge_.surfaceGeneration(submission.picture.wForwardRefPictureIndex);
            if (submission.picture.wBackwardRefPictureIndex != 0xffff)
                identity.backwardGeneration =
                    bridge_.surfaceGeneration(submission.picture.wBackwardRefPictureIndex);
            MovieTextureTicket ticket;
            if (!bridge_.enqueue(identity, submission, th0, th1, ticket))
                return notReady(2, event.serial);
            // Retain only compressed controls/metadata, never a guest YUV/RGBA
            // allocation. The hardware driver has copied compressed commands.
            Output output;
            output.metadata = p;
            output.metadata.compressed.clear();
            output.metadata.slices.clear();
            output.ticket = ticket;
            output.th0 = th0;
            output.th1 = th1;
            output.referenceMetadata = event.referenceMetadata;
            outputs_.emplace(displayOrder, std::move(output));
            pending = decodes_.emplace(event.serial, Decode{event, ticket, p.end}).first;
            if (anchor) {
                oldAnchor_ = newAnchor_;
                newAnchor_ = target;
                currentAnchorOrder_ = displayOrder;
            }
            if (hasPts)
                stampAnchor_ = pts;
            decodeSerial_ = event.serial;
            parser_.pop();
        } else {
            const auto& prior = pending->second.event;
            if (prior.inner != event.inner ||
                prior.elementaryPictureBegin != event.elementaryPictureBegin ||
                prior.kind != event.kind || prior.temporalReference != event.temporalReference)
                throw std::invalid_argument("Pending original decode event changed");
        }
        const auto& job = pending->second;
        if (!bridge_.ready(job.ticket))
            return notReady(3, event.serial);
        completion = {owner_.generation, event.serial,      job.ticket.picture,
                      job.end,           job.ticket.pts90k, true};
        return true;
    }
    // CPU/controller acknowledgement AFTER its source-scoped compressed IPU
    // cursor advance and genuine original144500 return. No field/counter is
    // approximated here; original146650/146C60/146C38/148328/148608 still run.
    void acknowledgeDecode(const NativeDecodeCompletion& completion) {
        open();
        auto found = decodes_.find(completion.eventSerial);
        if (!completion.ready || completion.generation != owner_.generation ||
            found == decodes_.end() || found->second.ticket.picture != completion.picture ||
            found->second.end != completion.elementaryEnd || !bridge_.ready(found->second.ticket))
            throw std::invalid_argument("Unretired/stale original decode acknowledgement");
        decodes_.erase(found);
    }
    // Real1477A0 replacement. The original integer caller follows this return
    // with146C38 and its exact bias/counter/callback side effects. This only
    // binds the actual ready resident image to that original descriptor/dest.
    bool output(const OriginalOutputEvent& event, NativeOutputBinding& result) {
        open();
        pumpInput();
        if (event.generation != owner_.generation || event.inner != inner_ || !event.serial ||
            !event.descriptor || !event.destination || !event.referenceMetadata ||
            !event.actualPlayerPts || (event.playerPts90k < 0 && !event.originalTimeAbsent) ||
            event.originalTimeAbsent !=
                originalMovieTimeAbsent(event.playerPts90k, event.referencePts90k,
                                        event.clockEnabled, event.lastClockPts) ||
            event.width != width_ || event.height != height_ || !event.actualThresholds ||
            event.th0 > 511 || event.th1 > 511) {
            char detail[512];
            std::snprintf(detail, sizeof(detail),
                          "Original CSC output event identity/timestamp mismatch: generation=%llu "
                          "expected_generation=%llu event=%llu inner=%08x expected_inner=%08x "
                          "ref=%08x descriptor=%08x dest=%08x pts=%lld observed=%u absent=%u "
                          "ref_pts=%lld clock_enabled=%u last_clock=%d size=%ux%u "
                          "expected_size=%ux%u th=%u,%u actual_th=%u",
                          static_cast<unsigned long long>(event.generation),
                          static_cast<unsigned long long>(owner_.generation),
                          static_cast<unsigned long long>(event.serial), event.inner, inner_,
                          event.referenceMetadata, event.descriptor, event.destination,
                          static_cast<long long>(event.playerPts90k),
                          event.actualPlayerPts ? 1u : 0u, event.originalTimeAbsent ? 1u : 0u,
                          static_cast<long long>(event.referencePts90k), event.clockEnabled,
                          event.lastClockPts, event.width, event.height, width_, height_, event.th0,
                          event.th1, event.actualThresholds ? 1u : 0u);
            throw std::invalid_argument(detail);
        }
        auto existing = bindings_.find(event.serial);
        if (existing != bindings_.end()) {
            result = existing->second;
            if (result.descriptor != event.descriptor || result.destination != event.destination)
                throw std::invalid_argument("Original output event changed");
            return true;
        }
        if (event.serial <= lastOutputSerial_)
            throw std::invalid_argument("Stale original output event");
        for (auto& [displayOrder, picture] : outputs_) {
            if (picture.outputEvent)
                continue;
            // Reorder guard: a newest anchor normally waits for the next anchor's decode (MPEG display order). But the
            // original CSC event names its picture by referenceMetadata: when it explicitly selects this anchor before
            // issuing the next decode, the original player has already decided it displays next. Waiting here instead
            // deadlocks the player (title loop CSC event 632: anchor 315 requested, next picture parsed, no decode).
            if (!((parsedEnd_ || finalFlushed_ || parser_.sequenceEnded()) &&
                  !parser_.hasPicture()) &&
                displayOrder >= currentAnchorOrder_ &&
                picture.referenceMetadata != event.referenceMetadata)
                return outputNotReady(4, event.serial, displayOrder);
            if (picture.referenceMetadata != event.referenceMetadata)
                throw std::runtime_error(
                    "Original CSC reference does not select the next decoded picture");
            if (!bridge_.ready(picture.ticket))
                return outputNotReady(5, event.serial, displayOrder);
            if (picture.th0 != event.th0 || picture.th1 != event.th1)
                throw std::runtime_error("Original SETH changed between VLD production and genuine "
                                         "CSC output; retained conversion must be rescheduled");
            //146DD8 has executed genuine146C60 before entering1477A0. It
            // supplies explicit PES PTS or its real integer clock result for
            // un-stamped pictures. No FPS/host/TR timestamp is substituted.
            bridge_.bindOriginalPlayerTime(picture.ticket, event.referenceMetadata,
                                           event.playerPts90k, event.originalTimeAbsent);
            result = {owner_.generation,
                      event.serial,
                      picture.ticket.picture,
                      picture.ticket.pts90k,
                      event.descriptor,
                      event.destination,
                      width_,
                      height_};
            picture.outputEvent = event.serial;
            bindings_.emplace(event.serial, result);
            lastOutputSerial_ = event.serial;
            return true;
        }
        return outputNotReady(6, event.serial, INT64_MIN);
    }
    // Ordered ORIGINAL IMAGE replacement on GS owner. Caller proves the source
    // address/descriptor plus literal BITBLT/TRX control and real DMA serial.
    bool upload(const NativeOutputBinding& binding, const MovieUpload& transfer,
                const Recorder& record, MovieDmaReceipt& receipt, bool batched = false) {
        open();
        pollUploads();
        auto joined = bindings_.find(binding.eventSerial);
        auto found = std::find_if(outputs_.begin(), outputs_.end(), [&](const auto& output) {
            return output.second.ticket.picture == binding.picture;
        });
        if (batched != bool(uploadBatch_) ||
            (batched &&
             (uploadBatch_->binding.generation != binding.generation ||
              uploadBatch_->binding.picture != binding.picture ||
              uploadBatch_->binding.eventSerial != binding.eventSerial || uploadBatch_->final)))
            throw std::logic_error("Original IMAGE batch lifetime/picture changed");

        // Bounded per-condition diagnostic: each precondition that would cause
        // the join to fail prints the specific discrepancy with expected vs.
        // actual values, plus the live upload binding picture/serial/PTS.
        // Preserves the original 26-rejection set; only re-orders and labels.
        {
            const uint32_t srcBytes16Ok = (transfer.sourceBytes & 15u) == 0u;
            const uint32_t srcOffset16Ok = (transfer.sourceByteOffset & 15u) == 0u;
            const uint64_t srcBytesCap = uint64_t(transfer.width) * uint64_t(transfer.height) * 4u;
            const uint64_t srcFrameBytes = uint64_t(width_) * uint64_t(height_) * 4u;
            const bool reconCoverageWithOwn = (found != outputs_.end());
            const auto fail = [&](const char* why, const char* detail) {
                char buf[768];
                std::snprintf(
                    buf, sizeof(buf),
                    "Original IMAGE source/destination/PTS/DMA join failed: %s "
                    "binding{eventSerial=%llu picture=%llu pts90k=%lld descriptor=%08x "
                    "destination=%08x} "
                    "transfer{generation=%llu picture=%llu pts90k=%lld outputDescriptor=%08x "
                    "guestDestination=%08x "
                    "sofdec=%08x work=%08x dmaSerial=%llu frameWidth=%u frameHeight=%u "
                    "sourceLayout=%u "
                    "sourceBytes=%u sourceByteOffset=%u width=%u height=%u dbp=%u dbw=%u x=%u y=%u "
                    "dpsm=%u} "
                    "owner{generation=%llu sofdec=%08x work=%08x lastUploadSerial=%llu "
                    "uploaded=%zu bindings=%zu} "
                    "joined=%d outputFound=%d recordNull=%d %s",
                    why, static_cast<unsigned long long>(binding.eventSerial),
                    static_cast<unsigned long long>(binding.picture),
                    static_cast<long long>(binding.pts90k), binding.descriptor, binding.destination,
                    static_cast<unsigned long long>(transfer.generation),
                    static_cast<unsigned long long>(transfer.picture),
                    static_cast<long long>(transfer.pts90k), transfer.outputDescriptor,
                    transfer.guestDestination, transfer.sofdec, transfer.work,
                    static_cast<unsigned long long>(transfer.dmaSerial), transfer.frameWidth,
                    transfer.frameHeight, transfer.sourceLayout, transfer.sourceBytes,
                    transfer.sourceByteOffset, transfer.width, transfer.height, transfer.dbp,
                    transfer.dbw, transfer.x, transfer.y, transfer.dpsm,
                    static_cast<unsigned long long>(owner_.generation), owner_.sofdec, owner_.work,
                    static_cast<unsigned long long>(lastUploadSerial_), uploads_.size(),
                    bindings_.size(), int(joined != bindings_.end()), int(reconCoverageWithOwn),
                    int(!record), detail);
                auto firstFound = reconCoverageWithOwn ? found->second.outputEvent : uint64_t(0);
                std::fprintf(stderr, "[MOVIE-UPLOAD-DIAG] %s outputEventOnOutput=%llu\n", buf,
                             static_cast<unsigned long long>(firstFound));
                throw std::invalid_argument(buf);
            };
#define FAIL(why, detail) fail((why), (detail))
            if (joined == bindings_.end())
                FAIL("binding.eventSerial not in bindings_",
                     "expected one of the live binding event serials");
            if (!reconCoverageWithOwn)
                FAIL("binding.picture not found in outputs_",
                     "no decoded picture matches this binding's picture");
            if (reconCoverageWithOwn && found->second.outputEvent != binding.eventSerial)
                FAIL("output picture's outputEvent != binding.eventSerial",
                     "the picture's CSC event ordinal was not the one bound for this upload");
            if (binding.generation != owner_.generation)
                FAIL("binding.generation != owner_.generation",
                     "binding is from a previous/next session generation");
            if (transfer.generation != owner_.generation)
                FAIL("transfer.generation != owner_.generation",
                     "transfer is from a previous/next session generation");
            if (transfer.sofdec != owner_.sofdec)
                FAIL("transfer.sofdec != owner_.sofdec",
                     "transfer routed to a different SOFDEC task");
            if (transfer.work != owner_.work)
                FAIL("transfer.work != owner_.work", "transfer routed to a different WORK area");
            if (transfer.picture != binding.picture)
                FAIL("transfer.picture != binding.picture",
                     "transfer picture ordinal does not match the binding");
            if (transfer.pts90k != binding.pts90k)
                FAIL("transfer.pts90k != binding.pts90k",
                     "transfer PTS does not match the binding");
            if (transfer.outputDescriptor != binding.descriptor)
                FAIL("transfer.outputDescriptor != binding.descriptor",
                     "IMAGE GIF descriptor changed between CSC output and upload");
            if (transfer.guestDestination != binding.destination)
                FAIL("transfer.guestDestination != binding.destination",
                     "guest destination DBP/DBW changed between CSC output and upload");
            if (!transfer.dmaSerial)
                FAIL("transfer.dmaSerial == 0", "DMA path received an empty serial");
            if (transfer.dmaSerial <= lastUploadSerial_)
                FAIL("transfer.dmaSerial <= lastUploadSerial_",
                     "DMA serial is stale or duplicate of an earlier upload");
            if (uploads_.count(transfer.dmaSerial))
                FAIL("uploads_ already contains transfer.dmaSerial",
                     "duplicate upload record for the same DMA serial");
            if (transfer.frameWidth != width_)
                FAIL("transfer.frameWidth != width_",
                     "IMAGE width changed between decode and upload");
            if (transfer.frameHeight != height_)
                FAIL("transfer.frameHeight != height_",
                     "IMAGE height changed between decode and upload");
            if (transfer.dpsm != 0)
                FAIL("transfer.dpsm != 0", "expected PSMCT32 (dpsm==0) for original IMAGE");
            if (transfer.sourceLayout != 1 && transfer.sourceLayout != 2)
                FAIL("transfer.sourceLayout not in {1,2}",
                     "expected the original IPU 16x16 layout1 (1) or layout2 (2)");
            if (!transfer.sourceBytes)
                FAIL("transfer.sourceBytes == 0", "no bounded source bytes supplied");
            if (!srcBytes16Ok)
                FAIL("(transfer.sourceBytes & 15) != 0",
                     "source byte length must be 16-byte aligned for IPU copies");
            if (!srcOffset16Ok)
                FAIL("(transfer.sourceByteOffset & 15) != 0",
                     "source byte offset must be 16-byte aligned for IPU copies");
            if (uint64_t(transfer.sourceBytes) > srcBytesCap)
                FAIL("sourceBytes > width*height*4",
                     "the upload covers more than the picture's full PSMCT32 size");
            if (uint64_t(transfer.sourceByteOffset) + transfer.sourceBytes > srcFrameBytes)
                FAIL("sourceByteOffset+sourceBytes > movie-frame bytes",
                     "the upload exceeds the producer's framed memory size");
            if (transfer.dbp >= 16384)
                FAIL("transfer.dbp >= 16384", "guest DBP exceeds the 16K GS VRAM page space");
            if (!transfer.dbw)
                FAIL("transfer.dbw == 0", "guest DBW cannot be zero");
            if (transfer.dbw > 63)
                FAIL("transfer.dbw > 63",
                     "guest DBW exceeds the maximum 64-column framebuffer stride");
            if (transfer.x > 2047)
                FAIL("transfer.x > 2047", "guest X exceeds GS coord space");
            if (transfer.y > 2047)
                FAIL("transfer.y > 2047", "guest Y exceeds GS coord space");
            if (transfer.width > 2048 - transfer.x)
                FAIL("transfer.width + transfer.x > 2048",
                     "guest width + x overflow GS coord space");
            if (transfer.height > 2048 - transfer.y)
                FAIL("transfer.height + transfer.y > 2048",
                     "guest height + y overflow GS coord space");
            if (!record)
                FAIL("record == nullptr", "the recorder supplied is null");
#undef FAIL
        }
        // The real original source selection and GS FIFO order select this
        // exact retained binding. The guest can discard earlier queued frames;
        // decode/display-map order is not an additional presentation command.
        auto coverage = found->second.consumedSpans;
        const uint32_t begin = transfer.sourceByteOffset, end = begin + transfer.sourceBytes;
        auto next = coverage.lower_bound(begin);
        if ((next != coverage.end() && next->first < end) ||
            (next != coverage.begin() && std::prev(next)->second > begin))
            throw std::invalid_argument(
                "Original movie IMAGE source fragment overlaps consumed bytes");
        auto inserted = coverage.emplace(begin, end).first;
        if (inserted != coverage.begin()) {
            auto previous = std::prev(inserted);
            if (previous->second == inserted->first) {
                previous->second = inserted->second;
                coverage.erase(inserted);
                inserted = previous;
            }
        }
        next = std::next(inserted);
        if (next != coverage.end() && inserted->second == next->first) {
            inserted->second = next->second;
            coverage.erase(next);
        }
        const bool final = coverage.size() == 1 && coverage.begin()->first == 0 &&
                           coverage.begin()->second == uint64_t(width_) * height_ * 4;
        auto recorder = [&](Vulkan::CommandBuffer& cmd, const Vulkan::ImageView& image,
                            const MoviePictureIdentity&) { record(cmd, image, transfer); };
        Vulkan::Fence fence;
        if (batched)
            bridge_.recordConsumerBatch(found->second.ticket, final, recorder);
        else
            fence = bridge_.consumePart(found->second.ticket, final, recorder);
        receipt = {owner_.generation, binding.picture, transfer.dmaSerial, found->second.ticket,
                   final};
        uploads_.emplace(transfer.dmaSerial, Upload{receipt, false, final, std::move(fence)});
        lastUploadSerial_ = transfer.dmaSerial;
        if (batched) {
            uploadBatch_->serials.push_back(transfer.dmaSerial);
            uploadBatch_->final = final;
            found->second.consumedSpans = std::move(coverage);
        } else if (final) {
            outputs_.erase(found);
            bindings_.erase(joined);
        } else
            found->second.consumedSpans = std::move(coverage);
        return true;
    }
    void releaseOriginalFrame(const NativeOutputBinding& binding) {
        open();
        pollUploads();
        auto joined = bindings_.find(binding.eventSerial);
        auto found = std::find_if(outputs_.begin(), outputs_.end(), [&](const auto& output) {
            return output.second.ticket.picture == binding.picture;
        });
        if (joined == bindings_.end() || found == outputs_.end() ||
            binding.generation != owner_.generation ||
            found->second.outputEvent != binding.eventSerial ||
            joined->second.picture != binding.picture || joined->second.pts90k != binding.pts90k ||
            joined->second.destination != binding.destination ||
            joined->second.descriptor != binding.descriptor || uploadBatch_)
            throw std::invalid_argument(
                "Original queue release lacks its exact retained native output binding");
        // Cache real outstanding partial receipts before freeing their ticket.
        // A later acknowledgement reads this cached completion, not freed state.
        for (auto& [serial, job] : uploads_)
            if (job.receipt.picture == binding.picture && !job.retired) {
                if (!job.fence || job.final)
                    throw std::logic_error(
                        "Original queue release crossed a staged/final IMAGE receipt");
                job.fence->wait();
                job.retired = true;
                job.fence.reset();
            }
        bridge_.releaseOriginalFrame(found->second.ticket);
        outputs_.erase(found);
        bindings_.erase(joined);
    }
    void beginUploadBatch(const NativeOutputBinding& binding) {
        open();
        pollUploads();
        auto joined = bindings_.find(binding.eventSerial);
        auto found = std::find_if(outputs_.begin(), outputs_.end(), [&](const auto& output) {
            return output.second.ticket.picture == binding.picture;
        });
        if (uploadBatch_ || joined == bindings_.end() || found == outputs_.end() ||
            binding.generation != owner_.generation || joined->second.picture != binding.picture ||
            joined->second.pts90k != binding.pts90k ||
            found->second.outputEvent != binding.eventSerial) {
            char detail[768];
            const auto front = outputs_.begin();
            std::snprintf(
                detail, sizeof(detail),
                "Original IMAGE batch lacks retained output binding: generation=%llu "
                "expected_generation=%llu picture=%llu event=%llu pts=%lld descriptor=%08x "
                "destination=%08x joined=%u found=%u found_event=%llu retained=%llu "
                "front_picture=%llu front_event=%llu front_order=%lld batch_active=%u",
                static_cast<unsigned long long>(binding.generation),
                static_cast<unsigned long long>(owner_.generation),
                static_cast<unsigned long long>(binding.picture),
                static_cast<unsigned long long>(binding.eventSerial),
                static_cast<long long>(binding.pts90k), binding.descriptor, binding.destination,
                joined != bindings_.end() ? 1u : 0u, found != outputs_.end() ? 1u : 0u,
                static_cast<unsigned long long>(found != outputs_.end() ? found->second.outputEvent
                                                                        : 0),
                static_cast<unsigned long long>(outputs_.size()),
                static_cast<unsigned long long>(
                    front != outputs_.end() ? front->second.ticket.picture : 0),
                static_cast<unsigned long long>(front != outputs_.end() ? front->second.outputEvent
                                                                        : 0),
                static_cast<long long>(front != outputs_.end() ? front->first : 0),
                uploadBatch_ ? 1u : 0u);
            throw std::invalid_argument(detail);
        }
        bridge_.beginConsumerBatch(found->second.ticket);
        uploadBatch_ = UploadBatch{binding, found->second.ticket};
    }
    std::vector<MovieDmaReceipt> endUploadBatch(const NativeOutputBinding& binding) {
        open();
        if (!uploadBatch_ || uploadBatch_->binding.generation != binding.generation ||
            uploadBatch_->binding.picture != binding.picture ||
            uploadBatch_->binding.eventSerial != binding.eventSerial ||
            uploadBatch_->serials.empty())
            throw std::logic_error("Original IMAGE batch has no exact recorded span");
        auto fence = bridge_.endConsumerBatch(uploadBatch_->ticket);
        std::vector<MovieDmaReceipt> receipts;
        receipts.reserve(uploadBatch_->serials.size());
        for (const auto serial : uploadBatch_->serials) {
            auto job = uploads_.find(serial);
            if (job == uploads_.end() || job->second.fence || job->second.retired)
                throw std::logic_error("Original IMAGE batch receipt changed before submission");
            job->second.fence = fence;
            receipts.push_back(job->second.receipt);
        }
        if (uploadBatch_->final) {
            auto found = std::find_if(outputs_.begin(), outputs_.end(), [&](const auto& output) {
                return output.second.ticket.picture == binding.picture;
            });
            if (found == outputs_.end())
                throw std::logic_error("Final IMAGE batch lost its produced picture");
            outputs_.erase(found);
            bindings_.erase(binding.eventSerial);
        }
        uploadBatch_.reset();
        // Every staged receipt references this actual submission. Cache all
        // completions before the final receipt can free the resident ticket.
        fence->wait();
        pollUploads();
        for (const auto& receipt : receipts)
            if (!uploadComplete(receipt))
                throw std::runtime_error(
                    "Original IMAGE batch real fence failed to retire all fragments");
        return receipts;
    }
    bool uploadComplete(const MovieDmaReceipt& receipt) {
        open();
        pollUploads();
        auto found = uploads_.find(receipt.dmaSerial);
        if (receipt.generation != owner_.generation || found == uploads_.end() ||
            found->second.receipt.picture != receipt.picture ||
            found->second.receipt.texture.slotSerial != receipt.texture.slotSerial)
            throw std::invalid_argument("Foreign/stale original IMAGE receipt");
        if (!found->second.retired)
            return false;
        uploads_.erase(found);
        return true;
    }
    void waitUploadComplete(const MovieDmaReceipt& receipt) {
        open();
        auto found = uploads_.find(receipt.dmaSerial);
        if (receipt.generation != owner_.generation || found == uploads_.end() ||
            found->second.receipt.picture != receipt.picture ||
            found->second.receipt.texture.slotSerial != receipt.texture.slotSerial)
            throw std::invalid_argument("Foreign original IMAGE fence wait");
        if (!found->second.retired) {
            if (!found->second.fence)
                throw std::logic_error("Original IMAGE lost its actual consumer fence");
            found->second.fence->wait();
        }
        if (!uploadComplete(receipt))
            throw std::runtime_error("Original IMAGE actual consumer fence did not retire");
    }
    void cancel() noexcept {
        if (closed_)
            return;
        bridge_.shutdown();
        std::lock_guard<std::mutex> lock(inputMutex_);
        input_.clear();
        copiedPending_ = 0;
        outputs_.clear();
        decodes_.clear();
        bindings_.clear();
        uploads_.clear();
        uploadBatch_.reset();
        closed_ = true;
    }
};
} // namespace reo_gpu_movie
