#pragma once
#include "mpeg2_stream.h"
#include "same_owner_movie_bridge.h"
#include <map>

namespace reo_gpu_movie {
// Literal fields decoded from the original ordered GIF upload control words.
// Interpretation and source/DMA authority belong to the caller, which must
// preserve that upload's completion until the returned real fence retires.
struct MovieUpload {
    uint64_t generation = 0, picture = 0, dmaSerial = 0;
    int64_t pts90k = 0;
    uint32_t sofdec = 0, work = 0, outputDescriptor = 0, guestDestination = 0;
    uint32_t dbp = 0, dbw = 0, dpsm = 0, x = 0, y = 0, width = 0, height = 0;
    // Literal original IMAGE source span. Layout1 is original IPU 16x16
    // macroblock RGBA order; frame dimensions describe the resident texture.
    uint32_t sourceByteOffset = 0, sourceBytes = 0, sourceLayout = 0, frameWidth = 0,
             frameHeight = 0;
    uint32_t gifPath = 0;
};
struct MovieSessionOwner {
    uint64_t generation = 0;
    uint32_t sofdec = 0, work = 0;
};
struct MovieDmaReceipt {
    uint64_t generation = 0, picture = 0, dmaSerial = 0;
    MovieTextureTicket texture{};
    bool finalSourceCoverage = false;
};
class MovieSession {
    MovieSessionOwner owner_;
    Mpeg2ElementaryStream elementary_;
    MpegProgramStream program_{elementary_};
    std::unique_ptr<SameOwnerMovieBridge> bridge_;
    // Original upload requests use presentation order. Hardware submissions
    // use coded order. Holding a later reference picture must never publish it
    // before earlier B pictures or advance the original player/audio clock.
    std::map<int64_t, MovieTextureTicket> outputs_;
    struct Outstanding {
        MovieDmaReceipt receipt;
        bool completed = false;
    };
    std::map<uint64_t, Outstanding> outstanding_;
    uint16_t previousAnchor_ = 0xffff, currentAnchor_ = 0xffff;
    int64_t unwrapBase_ = 0, lastDts_ = 0;
    bool haveDts_ = false, closed_ = false, poisoned_ = false, inputEnded_ = false;
    enum class Transport { None, Program, Elementary };
    Transport transport_ = Transport::None;
    uint64_t decoded_ = 0, consumed_ = 0;
    int64_t latestAnchorPts_ = std::numeric_limits<int64_t>::min(),
            lastConsumedPts_ = std::numeric_limits<int64_t>::min();
    static int64_t unwrap(uint64_t raw, int64_t anchorTime) {
        constexpr int64_t span = int64_t(1) << 33, half = span / 2;
        int64_t value = (anchorTime & ~(span - 1)) + int64_t(raw);
        if (value - anchorTime > half)
            value -= span;
        else if (anchorTime - value > half)
            value += span;
        return value;
    }
    void open() const {
        if (closed_ || poisoned_)
            throw std::logic_error("Movie session is closed/failed");
    }
    void select(Transport transport) {
        if (transport_ != Transport::None && transport_ != transport)
            throw std::logic_error("Movie transport changed within a generation");
        transport_ = transport;
    }
    void pollConsumers() {
        for (auto& [serial, job] : outstanding_)
            if (!job.completed)
                job.completed = bridge_->retireConsumed(job.receipt.texture);
    }

  public:
    using Recorder =
        std::function<void(Vulkan::CommandBuffer&, const Vulkan::ImageView&, const MovieUpload&)>;
    MovieSession(MovieSessionOwner owner, Vulkan::Device& activeGs, ID3D11Device* decoderDevice,
                 uint32_t width, uint32_t height, const std::vector<uint32_t>& shader)
        : owner_(owner) {
        if (!owner.generation || !owner.sofdec || !owner.work)
            throw std::invalid_argument("Movie owner identity is absent");
        bridge_ = std::make_unique<SameOwnerMovieBridge>(activeGs, decoderDevice, owner.generation,
                                                         width, height, shader);
    }
    MovieSession(const MovieSession&) = delete;
    ~MovieSession() {
        cancel();
    }
    // Choose exactly one input transport for a session. The ES variant receives
    // the actual original demuxer's PTS ranges separately, before bytes arrive.
    // Neither method touches guest bookkeeping, PCM, playback clocks or DMA.
    void feedProgram(uint64_t offset, std::span<const uint8_t> bytes) {
        open();
        select(Transport::Program);
        try {
            program_.feed(offset, bytes);
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    void feedElementary(uint64_t offset, std::span<const uint8_t> bytes) {
        open();
        select(Transport::Elementary);
        try {
            elementary_.feed(offset, bytes);
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    void feedTimestamp(const PesTimestamp& timestamp) {
        open();
        select(Transport::Elementary);
        try {
            elementary_.timestamp(timestamp);
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    void endProgram() {
        open();
        select(Transport::Program);
        try {
            program_.end();
            inputEnded_ = true;
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    void endElementary() {
        open();
        select(Transport::Elementary);
        try {
            elementary_.end();
            inputEnded_ = true;
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    // Owner thread only. False means real three-image backpressure; the same
    // front control remains intact and no decoded/reference state advances.
    bool decodeOne(uint32_t th0, uint32_t th1) {
        open();
        pollConsumers();
        if (!elementary_.hasPicture())
            return false;
        const auto& picture = elementary_.picture();
        if (!picture.timestamp || !picture.timestamp->hasPts)
            throw std::runtime_error("Movie picture lacks its exact original demux PES timestamp");
        if (th0 > 511 || th1 > 511)
            throw std::invalid_argument("Invalid original IPU threshold controls");
        const auto& timestamp = *picture.timestamp;
        const int64_t dts = timestamp.hasDts ? (haveDts_ ? unwrap(timestamp.dts33, lastDts_)
                                                         : int64_t(timestamp.dts33))
                                             : 0;
        if (timestamp.hasDts && haveDts_ && dts < lastDts_)
            throw std::runtime_error(
                "Movie decode timestamps moved backwards without a new generation");
        const auto pts = unwrap(timestamp.pts33, timestamp.hasDts ? dts : unwrapBase_);
        if (outputs_.count(pts) || pts <= lastConsumedPts_)
            throw std::runtime_error("Duplicate/stale presentation timestamp");
        auto submission = picture.submission();
        const bool anchor = picture.kind != 3;
        const uint16_t target = anchor ? (currentAnchor_ == 0 ? 1 : 0) : 2;
        submission.picture.wDecodedPictureIndex = target;
        submission.picture.wForwardRefPictureIndex =
            picture.kind == 1 ? 0xffff : (anchor ? currentAnchor_ : previousAnchor_);
        submission.picture.wBackwardRefPictureIndex = picture.kind == 3 ? currentAnchor_ : 0xffff;
        // Initial/open-GOP B pictures need the previous genuine session anchor.
        // A caller must preserve the session across GOPs or join original seek
        // discard decisions. This API never quietly drops a requested picture.
        if ((picture.kind == 2 && currentAnchor_ == 0xffff) ||
            (picture.kind == 3 && (previousAnchor_ == 0xffff || currentAnchor_ == 0xffff)))
            throw std::runtime_error("MPEG picture requires an unavailable original reference");
        MoviePictureIdentity identity{};
        identity.generation = owner_.generation;
        identity.picture = picture.ordinal;
        identity.compressedBegin = picture.begin;
        identity.compressedEnd = picture.end;
        identity.pts90k = pts;
        identity.sofdec = owner_.sofdec;
        identity.work = owner_.work;
        identity.truePictureBoundaries = true;
        identity.truePlayerPts = true;
        if (submission.picture.wForwardRefPictureIndex != 0xffff)
            identity.forwardGeneration =
                bridge_->surfaceGeneration(submission.picture.wForwardRefPictureIndex);
        if (submission.picture.wBackwardRefPictureIndex != 0xffff)
            identity.backwardGeneration =
                bridge_->surfaceGeneration(submission.picture.wBackwardRefPictureIndex);
        MovieTextureTicket ticket;
        try {
            if (!bridge_->enqueue(identity, submission, th0, th1, ticket))
                return false;
            outputs_.emplace(pts, ticket);
            if (anchor) {
                previousAnchor_ = currentAnchor_;
                currentAnchor_ = target;
                latestAnchorPts_ = pts;
            }
            if (timestamp.hasDts) {
                lastDts_ = dts;
                haveDts_ = true;
            }
            unwrapBase_ = pts;
            ++decoded_;
            elementary_.pop();
            return true;
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    // A reference picture is displayable once a later reference has arrived,
    // or at genuine input EOF. B pictures before the current reference are
    // displayable immediately. This is a watermark, not a substitute clock.
    std::optional<MovieTextureTicket> nextPresentation() const {
        open();
        if (outputs_.empty())
            return {};
        const auto& [pts, ticket] = *outputs_.begin();
        if (!(inputEnded_ && !elementary_.hasPicture()) && pts >= latestAnchorPts_)
            return {};
        return ticket;
    }
    // The original frontend decides when a particular PTS is due. This method
    // takes no host time and never changes the audio clock or frame cadence.
    bool consumeAtUpload(const MovieUpload& upload, const Recorder& record,
                         MovieDmaReceipt& receipt) {
        open();
        const auto next = nextPresentation();
        if (!next || next->pts90k != upload.pts90k)
            return false;
        if (!record || upload.generation != owner_.generation || upload.picture != next->picture ||
            upload.sofdec != owner_.sofdec || upload.work != owner_.work ||
            !upload.outputDescriptor || !upload.guestDestination || !upload.dmaSerial ||
            outstanding_.count(upload.dmaSerial) || !upload.width || !upload.height ||
            upload.width != elementary_.width() || upload.height != elementary_.height() ||
            upload.dbp >= 16384 || !upload.dbw || upload.dbw > 63 || upload.dpsm != 0 ||
            upload.x > 2047 || upload.y > 2047 || upload.width > 2048 - upload.x ||
            upload.height > 2048 - upload.y)
            throw std::invalid_argument("Original movie IMAGE/DMA consumer identity is incomplete");
        try {
            bridge_->consume(*next, [&](Vulkan::CommandBuffer& cmd, const Vulkan::ImageView& image,
                                        const MoviePictureIdentity& identity) {
                if (identity.generation != upload.generation ||
                    identity.picture != upload.picture || identity.pts90k != upload.pts90k)
                    throw std::logic_error("Movie producer/consumer identity changed");
                record(cmd, image, upload);
            });
            receipt = {owner_.generation, next->picture, upload.dmaSerial, *next};
            outstanding_.emplace(upload.dmaSerial, Outstanding{receipt});
            lastConsumedPts_ = upload.pts90k;
            outputs_.erase(upload.pts90k);
            ++consumed_;
            return true;
        } catch (...) {
            poisoned_ = true;
            throw;
        }
    }
    bool dmaComplete(const MovieDmaReceipt& receipt) {
        open();
        if (receipt.generation != owner_.generation)
            throw std::invalid_argument("Stale movie DMA generation");
        auto found = outstanding_.find(receipt.dmaSerial);
        if (found == outstanding_.end() || found->second.receipt.picture != receipt.picture ||
            found->second.receipt.texture.slotSerial != receipt.texture.slotSerial ||
            found->second.receipt.texture.slot != receipt.texture.slot)
            throw std::invalid_argument("Stale or foreign movie DMA receipt");
        // Poll and remove the real consumer receipt BEFORE the slot may be
        // reused by decodeOne. No blank FIFO callbacks or fabricated fences.
        if (!found->second.completed && !bridge_->retireConsumed(receipt.texture))
            return false;
        outstanding_.erase(found);
        return true;
    }
    uint64_t decodedPictures() const {
        return decoded_;
    }
    uint64_t consumedPictures() const {
        return consumed_;
    }
    bool hasCompressedPicture() const {
        return elementary_.hasPicture();
    }
    bool drained() const {
        return inputEnded_ && !elementary_.hasPicture() && outputs_.empty() && outstanding_.empty();
    }
    void cancel() noexcept {
        if (closed_)
            return;
        if (bridge_)
            bridge_->shutdown();
        outputs_.clear();
        outstanding_.clear();
        closed_ = true;
    }
};
} // namespace reo_gpu_movie
