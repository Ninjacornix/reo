#pragma once
// Compressed transport and DXVA command construction only. This parser never
// evaluates macroblock contents, coefficients, motion vectors or pixel values.
#include "mpeg2_vld_core.h"
#include <array>
#include <deque>
#include <optional>
#include <span>
#include <stdexcept>
#include <string_view>

namespace reo_gpu_movie {
struct PesTimestamp {
    uint64_t elementaryBegin = 0, elementaryEnd = 0, packetOffset = 0;
    uint64_t pts33 = 0, dts33 = 0;
    bool hasPts = false, hasDts = false;
};
struct StreamPicture {
    uint64_t begin = 0, end = 0, ordinal = 0, gop = 0;
    uint16_t temporalReference = 0;
    uint8_t kind = 0;
    uint32_t width = 0, height = 0;
    bool progressive = false, closedGop = false, brokenLink = false;
    std::optional<PesTimestamp> timestamp;
    DXVA_PictureParameters parameters{};
    DXVA_QmatrixData quantizers{};
    std::vector<DXVA_SliceInfo> slices;
    std::vector<uint8_t> compressed;
    PictureSubmission submission() const {
        PictureSubmission value{};
        value.picture = parameters;
        value.quantizers = quantizers;
        value.slices = slices.data();
        value.sliceCount = UINT(slices.size());
        value.compressed = compressed.data();
        value.compressedBytes = UINT(compressed.size());
        return value;
    }
};
class MpegHeaderBits {
    std::span<const uint8_t> bytes_;
    size_t bit_ = 0;

  public:
    explicit MpegHeaderBits(std::span<const uint8_t> bytes) : bytes_(bytes) {}
    uint32_t get(unsigned n) {
        if (n > 32 || bit_ + n > bytes_.size() * 8)
            throw std::runtime_error("Truncated MPEG control header");
        uint32_t value = 0;
        for (unsigned i = 0; i < n; ++i, ++bit_)
            value = (value << 1) | ((bytes_[bit_ / 8] >> (7 - bit_ % 8)) & 1);
        return value;
    }
    size_t position() const {
        return bit_;
    }
    unsigned firstMacroblock() {
        static constexpr std::string_view codes[]{
            "1",           "011",         "010",         "0011",        "0010",
            "00011",       "00010",       "0000111",     "0000110",     "00001011",
            "00001010",    "00001001",    "00001000",    "00000111",    "00000110",
            "0000010111",  "0000010110",  "0000010101",  "0000010100",  "0000010011",
            "0000010010",  "00000100011", "00000100010", "00000100001", "00000100000",
            "00000011111", "00000011110", "00000011101", "00000011100", "00000011011",
            "00000011010", "00000011001", "00000011000"};
        unsigned total = 0;
        for (unsigned groups = 0; groups < 128; ++groups) {
            char code[12]{};
            bool escape = false;
            for (unsigned length = 1; length <= 11; ++length) {
                code[length - 1] = char('0' + get(1));
                const std::string_view probe(code, length);
                for (unsigned i = 0; i < std::size(codes); ++i)
                    if (probe == codes[i])
                        return total + i + 1;
                if (probe == "00000001000") {
                    total += 33;
                    escape = true;
                    break;
                }
                if (probe == "00000001111") {
                    escape = true;
                    break;
                }
            }
            if (!escape)
                break;
        }
        throw std::runtime_error("Invalid first MPEG macroblock address");
    }
};

// The exact source offset is mandatory even after wrapping a guest ring. A
// discontinuity poisons the parser; later data cannot hide a missing interval.
class Mpeg2ElementaryStream {
    static constexpr size_t MaxPending = 2 * 1024 * 1024, MaxQueued = 32;
    std::vector<uint8_t> pending_;
    bool resync_ = false, orphanSlices_ = false, sequenceEnded_ = false;
    uint64_t resyncDropped_ =
        0; // set by flushFinalUnit: bytes before the next start code are a cut slice tail
    uint64_t pendingBase_ = 0, accepted_ = 0, ordinal_ = 0, gop_ = 0;
    bool failed_ = false, eof_ = false, sequence_ = false, sequenceExtension_ = false;
    bool progressiveSequence_ = false, closedGop_ = false, brokenLink_ = false;
    uint32_t width_ = 0, height_ = 0;
    std::array<std::array<uint16_t, 64>, 4> matrices_{};
    std::optional<StreamPicture> current_;
    std::deque<StreamPicture> complete_;
    std::deque<PesTimestamp> stamps_;
    static constexpr uint8_t Zigzag[64]{
        0,  1,  8,  16, 9,  2,  3,  10, 17, 24, 32, 25, 18, 11, 4,  5,  12, 19, 26, 33, 40, 48,
        41, 34, 27, 20, 13, 6,  7,  14, 21, 28, 35, 42, 49, 56, 57, 50, 43, 36, 29, 22, 15, 23,
        30, 37, 44, 51, 58, 59, 52, 45, 38, 31, 39, 46, 53, 60, 61, 54, 47, 55, 62, 63};
    static constexpr uint8_t Intra[64]{
        8,  16, 19, 22, 26, 27, 29, 34, 16, 16, 22, 24, 27, 29, 34, 37, 19, 22, 26, 27, 29, 34,
        34, 38, 22, 22, 26, 27, 29, 34, 37, 40, 22, 26, 27, 29, 32, 35, 40, 48, 26, 27, 29, 32,
        35, 40, 48, 58, 26, 27, 29, 34, 38, 46, 56, 69, 27, 29, 35, 38, 46, 56, 69, 83};
    void quantizers(StreamPicture& picture) {
        for (unsigned m = 0; m < 4; ++m) {
            picture.quantizers.bNewQmatrix[m] = 1;
            for (unsigned i = 0; i < 64; ++i)
                picture.quantizers.Qmatrix[m][i] = matrices_[m][i];
        }
    }
    void finish(uint64_t end) {
        if (!current_)
            return;
        auto& p = *current_;
        if (p.slices.empty() || !sequenceExtension_ || !p.progressive ||
            p.parameters.bPicStructure != 3)
            throw std::runtime_error("Unsupported incomplete/interlaced MPEG picture");
        if (complete_.size() >= MaxQueued)
            throw std::runtime_error("MPEG control queue requires draining");
        const auto widthMb = width_ / 16, total = widthMb * (height_ / 16);
        for (size_t i = 0; i < p.slices.size(); ++i) {
            auto& slice = p.slices[i];
            const unsigned begin = slice.wVerticalPosition * widthMb + slice.wHorizontalPosition;
            const auto stop = i + 1 < p.slices.size()
                                  ? p.slices[i + 1].wVerticalPosition * widthMb +
                                        p.slices[i + 1].wHorizontalPosition
                                  : total;
            if (begin >= stop || stop > total || stop - begin > 65535)
                throw std::runtime_error("Unordered MPEG slice control");
            slice.wNumberMBsInSlice = WORD(stop - begin);
        }
        p.end = end;
        // Each PES timestamp belongs only to its first picture start. Never
        // attach a nearest timestamp or the following packet's timestamp.
        while (!stamps_.empty() && stamps_.front().elementaryEnd <= p.begin)
            stamps_.pop_front();
        for (auto& stamp : stamps_)
            if (stamp.elementaryBegin <= p.begin && p.begin < stamp.elementaryEnd) {
                p.timestamp = stamp;
                stamp.hasPts = false;
                break;
            }
        complete_.push_back(std::move(p));
        current_.reset();
    }
    void unit(std::span<const uint8_t> data, uint64_t begin, uint64_t end) {
        if (data.size() < 4)
            throw std::runtime_error("Truncated MPEG start code");
        const auto code = data[3];
        MpegHeaderBits bits(data.subspan(4));
        if (code == 0x00 || code == 0xb3 || code == 0xb8 || code == 0xb7)
            finish(begin);
        if (code == 0x00 || code == 0xb3 || code == 0xb8 || code == 0xb7)
            orphanSlices_ = false;
        if (code == 0xb7)
            sequenceEnded_ = true;
        else if (code == 0xb3 || code == 0x00)
            sequenceEnded_ = false;
        if (code == 0xb3) {
            const auto width = bits.get(12), height = bits.get(12);
            bits.get(4);
            const auto rate = bits.get(4);
            bits.get(18);
            if (!bits.get(1) || !rate || rate > 8 || !width || !height || (width & 15) ||
                (height & 15) || width > 1920 || height > 1088)
                throw std::runtime_error("Unsupported MPEG sequence geometry/control");
            if (sequence_ && (width != width_ || height != height_))
                throw std::runtime_error("Movie sequence change requires a new decoder session");
            width_ = width;
            height_ = height;
            bits.get(10);
            bits.get(1);
            if (bits.get(1)) {
                for (auto& value : matrices_[0])
                    value = uint16_t(bits.get(8));
            } else
                for (unsigned i = 0; i < 64; ++i)
                    matrices_[0][i] = Intra[Zigzag[i]];
            if (bits.get(1)) {
                for (auto& value : matrices_[1])
                    value = uint16_t(bits.get(8));
            } else
                matrices_[1].fill(16);
            matrices_[2] = matrices_[0];
            matrices_[3] = matrices_[1];
            sequence_ = true;
            sequenceExtension_ = false;
        } else if (code == 0xb8) {
            bits.get(25);
            closedGop_ = bits.get(1) != 0;
            brokenLink_ = bits.get(1) != 0;
            ++gop_;
        } else if (code == 0) {
            if (!sequence_)
                throw std::runtime_error("MPEG picture precedes sequence");
            StreamPicture p;
            p.begin = begin;
            p.ordinal = ++ordinal_;
            p.gop = gop_;
            p.width = width_;
            p.height = height_;
            p.closedGop = closedGop_;
            p.brokenLink = brokenLink_;
            p.temporalReference = uint16_t(bits.get(10));
            p.kind = uint8_t(bits.get(3));
            bits.get(16);
            if (p.kind < 1 || p.kind > 3)
                throw std::runtime_error("Unsupported MPEG picture type");
            auto& pp = p.parameters;
            pp.wForwardRefPictureIndex = pp.wBackwardRefPictureIndex = 0xffff;
            pp.wPicWidthInMBminus1 = WORD(width_ / 16 - 1);
            pp.wPicHeightInMBminus1 = WORD(height_ / 16 - 1);
            pp.bMacroblockWidthMinus1 = pp.bMacroblockHeightMinus1 = 15;
            pp.bBlockWidthMinus1 = pp.bBlockHeightMinus1 = pp.bBPPminus1 = 7;
            pp.bPicStructure = 3;
            pp.bPicIntra = BYTE(p.kind == 1);
            pp.bPicBackwardPrediction = BYTE(p.kind == 3);
            pp.bChromaFormat = 1;
            pp.bPicScanFixed = 1;
            // MPEG-2 coding extension replaces these MPEG-1 header fcodes.
            if (p.kind == 2 || p.kind == 3) {
                bits.get(1);
                bits.get(3);
            }
            if (p.kind == 3) {
                bits.get(1);
                bits.get(3);
            }
            quantizers(p);
            current_ = std::move(p);
        } else if (code == 0xb5) {
            const auto extension = bits.get(4);
            if (extension == 1) {
                bits.get(8);
                progressiveSequence_ = bits.get(1) != 0;
                const auto chroma = bits.get(2), wx = bits.get(2), hx = bits.get(2);
                if (!sequence_ || chroma != 1 || wx || hx || !progressiveSequence_)
                    throw std::runtime_error("Unsupported MPEG sequence extension");
                sequenceExtension_ = true;
            } else if (extension == 3) {
                for (auto& matrix : matrices_)
                    if (bits.get(1))
                        for (auto& value : matrix)
                            value = uint16_t(bits.get(8));
                if (current_)
                    quantizers(*current_);
            } else if (extension == 8) {
                if (!current_)
                    throw std::runtime_error("Picture coding extension lacks a picture");
                auto& p = *current_;
                auto& pp = p.parameters;
                pp.wBitstreamFcodes = WORD(bits.get(16));
                const auto dc = bits.get(2), structure = bits.get(2), top = bits.get(1),
                           frameDct = bits.get(1), conceal = bits.get(1), qscale = bits.get(1);
                const auto intraVlc = bits.get(1), alternate = bits.get(1), repeat = bits.get(1),
                           chroma420 = bits.get(1), progressive = bits.get(1);
                pp.bPicStructure = BYTE(structure);
                pp.bPicScanMethod = BYTE(alternate);
                p.progressive = progressive != 0;
                pp.wBitstreamPCEelements =
                    WORD((dc << 14) | (structure << 12) | (top << 11) | (frameDct << 10) |
                         (conceal << 9) | (qscale << 8) | (intraVlc << 7) | (alternate << 6) |
                         (repeat << 5) | (chroma420 << 4) | (progressive << 3));
            }
        } else if (code >= 1 && code <= 0xaf) {
            if (!current_ && orphanSlices_) {
                resyncDropped_ += data.size();
                return;
            } // tail of a prematurely flushed picture
            if (!current_ || !sequenceExtension_)
                throw std::runtime_error("MPEG slice lacks complete picture controls");
            auto& p = *current_;
            if (p.slices.size() >= 4096 || p.compressed.size() + data.size() > MaxPending)
                throw std::runtime_error("Oversized MPEG picture");
            DXVA_SliceInfo slice{};
            slice.wQuantizerScaleCode = WORD(bits.get(5));
            if (!slice.wQuantizerScaleCode)
                throw std::runtime_error("Zero MPEG quantizer scale");
            while (bits.get(1))
                bits.get(8);
            slice.wMBbitOffset = WORD(32 + bits.position());
            const auto first = bits.firstMacroblock();
            if (!first || first > width_ / 16)
                throw std::runtime_error("MPEG first macroblock outside slice row");
            slice.wHorizontalPosition = WORD(first - 1);
            slice.wVerticalPosition = WORD(code - 1);
            if (slice.wHorizontalPosition >= width_ / 16 || slice.wVerticalPosition >= height_ / 16)
                throw std::runtime_error("MPEG slice outside sequence geometry");
            slice.dwSliceBitsInBuffer = DWORD(data.size() * 8);
            slice.dwSliceDataLocation = DWORD(p.compressed.size());
            p.slices.push_back(slice);
            p.compressed.insert(p.compressed.end(), data.begin(), data.end());
        }
        (void)end;
    }
    void parse(bool final) {
        // Start-code search resumes three bytes before the previous boundary,
        // preserving prefixes divided by arbitrary DMA/PES/ring chunk sizes.
        size_t previous = 0;
        bool have = false;
        for (size_t at = 0; at + 4 <= pending_.size(); ++at)
            if (pending_[at] == 0 && pending_[at + 1] == 0 && pending_[at + 2] == 1) {
                if (have)
                    unit(std::span<const uint8_t>(pending_).subspan(previous, at - previous),
                         pendingBase_ + previous, pendingBase_ + at);
                else if (at && resync_) {
                    resyncDropped_ += at;
                    pending_.erase(pending_.begin(), pending_.begin() + at);
                    pendingBase_ += at;
                    at = 0;
                } else if (at)
                    throw std::runtime_error("MPEG elementary stream lacks initial start code");
                resync_ = false;
                previous = at;
                have = true;
                at += 2;
            }
        if (final) {
            if (have)
                unit(std::span<const uint8_t>(pending_).subspan(previous), pendingBase_ + previous,
                     pendingBase_ + pending_.size());
            else if (!pending_.empty())
                throw std::runtime_error("Truncated final MPEG unit");
            finish(accepted_);
            pending_.clear();
            pendingBase_ = accepted_;
        } else if (have && previous) {
            pending_.erase(pending_.begin(), pending_.begin() + previous);
            pendingBase_ += previous;
        }
        // sequence_end_code (00 00 01 B7) carries no payload: it is a complete 4-byte unit by itself. Process it now
        // instead of waiting for a following start code that never comes (the last picture of a movie is otherwise
        // never finished; the original IPU decoder needs no such lookahead, so the game deadlocks on it).
        if (!final && pending_.size() >= 4 && !pending_[0] && !pending_[1] && pending_[2] == 1 &&
            pending_[3] == 0xb7) {
            unit(std::span<const uint8_t>(pending_).subspan(0, 4), pendingBase_, pendingBase_ + 4);
            pending_.erase(pending_.begin(), pending_.begin() + 4);
            pendingBase_ += 4;
        }
    }

  public:
    void timestamp(const PesTimestamp& stamp) {
        if (failed_ || eof_ || !stamp.hasPts || stamp.pts33 > 0x1ffffffffull ||
            stamp.elementaryBegin >= stamp.elementaryEnd ||
            (stamp.hasDts && stamp.dts33 > 0x1ffffffffull) || stamps_.size() >= 4096 ||
            (!stamps_.empty() && stamp.elementaryBegin < stamps_.back().elementaryBegin))
            throw std::invalid_argument("Invalid MPEG PES timestamp range");
        stamps_.push_back(stamp);
    }
    void feed(uint64_t sourceOffset, std::span<const uint8_t> bytes) {
        if (failed_ || eof_)
            throw std::logic_error("Movie elementary stream is closed/failed");
        if (sourceOffset != accepted_ || bytes.size() > MaxPending ||
            pending_.size() + bytes.size() > MaxPending) {
            failed_ = true;
            throw std::runtime_error("MPEG input gap or input backpressure exceeded");
        }
        try {
            pending_.insert(pending_.end(), bytes.begin(), bytes.end());
            accepted_ += bytes.size();
            parse(false);
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    void end() {
        if (failed_ || eof_)
            throw std::logic_error("Movie elementary stream is closed/failed");
        try {
            parse(true);
            eof_ = true;
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    // Complete the buffered final unit as if its following start code had arrived, WITHOUT closing the stream.
    // Caller must prove no further picture bytes can exist (original file-end + every committed byte fed).
    // A later sequence-end unit/end() then finds no current picture and only closes the stream.
    void flushFinalUnit() {
        if (failed_ || eof_)
            throw std::logic_error("Movie elementary stream is closed/failed");
        try {
            if (pending_.size() < 4 || pending_[0] || pending_[1] || pending_[2] != 1)
                return;
            unit(std::span<const uint8_t>(pending_), pendingBase_, pendingBase_ + pending_.size());
            finish(accepted_);
            pending_.clear();
            pendingBase_ = accepted_;
            resync_ = true;
            orphanSlices_ = true;
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    // True when the buffered (unterminated) unit is a slice of the LAST macroblock row: the picture structurally
    // has its final row. Used only to break the end-of-movie deadlock; slice data itself cannot be proven complete here.
    // A sequence_end_code was parsed and no new sequence/picture began: no further picture can precede EOF.
    bool sequenceEnded() const {
        return sequenceEnded_;
    }
    size_t pendingBytes() const {
        return pending_.size();
    }
    unsigned pendingCode() const {
        return pending_.size() >= 4 && !pending_[0] && !pending_[1] && pending_[2] == 1
                   ? pending_[3]
                   : 0x100u;
    }
    unsigned rowsMb() const {
        return height_ / 16;
    }
    unsigned currentSlices() const {
        return current_ ? unsigned(current_->slices.size()) : 0u;
    }
    unsigned currentLastRow() const {
        return current_ && !current_->slices.empty()
                   ? unsigned(current_->slices.back().wVerticalPosition)
                   : 0xffffu;
    }
    bool finalRowSlicePending() const {
        if (failed_ || eof_ || !height_ || pending_.size() < 5 || pending_[0] || pending_[1] ||
            pending_[2] != 1)
            return false;
        const unsigned code = pending_[3];
        return code >= 1 && code <= 0xaf && code == height_ / 16;
    }
    bool hasPicture() const {
        return !complete_.empty();
    }
    const StreamPicture& picture() const {
        if (complete_.empty())
            throw std::logic_error("No complete MPEG picture");
        return complete_.front();
    }
    void pop() {
        if (complete_.empty())
            throw std::logic_error("No MPEG picture to retire");
        complete_.pop_front();
    }
    uint64_t accepted() const {
        return accepted_;
    }
    uint32_t width() const {
        return width_;
    }
    uint32_t height() const {
        return height_;
    }
    bool ended() const {
        return eof_;
    }
    bool failed() const {
        return failed_;
    }
};

// PES parsing is independent of decoding. The audio/private stream packets
// remain on their existing CRI route; this class emits selected video bytes.
class MpegProgramStream {
    Mpeg2ElementaryStream& video_;
    uint8_t stream_;
    std::vector<uint8_t> pending_;
    uint64_t accepted_ = 0, base_ = 0;
    bool ended_ = false, failed_ = false, programEnd_ = false;
    static uint64_t stamp(std::span<const uint8_t> bytes, unsigned prefix) {
        if (bytes.size() < 5 || bytes[0] >> 4 != prefix || !(bytes[0] & 1) || !(bytes[2] & 1) ||
            !(bytes[4] & 1))
            throw std::runtime_error("Invalid PES timestamp marker");
        return (uint64_t((bytes[0] >> 1) & 7) << 30) | (uint64_t(bytes[1]) << 22) |
               (uint64_t(bytes[2] >> 1) << 15) | (uint64_t(bytes[3]) << 7) | (bytes[4] >> 1);
    }
    void packet(std::span<const uint8_t> bytes) {
        const auto code = bytes[3];
        if (code != stream_)
            return;
        size_t at = 6;
        PesTimestamp time;
        time.packetOffset = base_;
        if ((bytes[at] & 0xc0) == 0x80) {
            if (bytes.size() < 9)
                throw std::runtime_error("Truncated MPEG-2 PES header");
            const auto flags = bytes[7] >> 6;
            const size_t headerEnd = 9 + bytes[8];
            if (headerEnd > bytes.size() || flags == 1)
                throw std::runtime_error("Invalid MPEG-2 PES header");
            if (flags >= 2) {
                if (headerEnd < 14)
                    throw std::runtime_error("Truncated PES PTS");
                time.pts33 = stamp(bytes.subspan(9), flags);
                time.hasPts = true;
            }
            if (flags == 3) {
                if (headerEnd < 19)
                    throw std::runtime_error("Truncated PES DTS");
                time.dts33 = stamp(bytes.subspan(14), 1);
                time.hasDts = true;
            }
            at = headerEnd;
        } else {
            unsigned stuffing = 0;
            while (at < bytes.size() && bytes[at] == 255) {
                ++at;
                if (++stuffing > 32)
                    throw std::runtime_error("Excessive MPEG-1 PES stuffing");
            }
            if (at >= bytes.size())
                throw std::runtime_error("Truncated MPEG-1 PES header");
            if ((bytes[at] & 0xc0) == 0x40)
                at += 2;
            if (at >= bytes.size())
                throw std::runtime_error("Truncated MPEG-1 PES STD header");
            const auto kind = bytes[at] >> 4;
            if (kind == 2 || kind == 3) {
                time.pts33 = stamp(bytes.subspan(at), kind);
                time.hasPts = true;
                at += 5;
                if (kind == 3) {
                    time.dts33 = stamp(bytes.subspan(at), 1);
                    time.hasDts = true;
                    at += 5;
                }
            } else if (bytes[at++] != 15)
                throw std::runtime_error("Invalid MPEG-1 PES timestamp header");
        }
        if (at > bytes.size())
            throw std::runtime_error("PES header exceeds packet");
        time.elementaryBegin = video_.accepted();
        time.elementaryEnd = time.elementaryBegin + bytes.size() - at;
        if (time.hasPts && at < bytes.size())
            video_.timestamp(time);
        video_.feed(time.elementaryBegin, bytes.subspan(at));
    }
    void parse() {
        while (!pending_.empty()) {
            if (programEnd_) {
                for (auto value : pending_)
                    if (value != 0 && value != 255)
                        throw std::runtime_error("Data follows MPEG program end");
                base_ += pending_.size();
                pending_.clear();
                return;
            }
            if (pending_.size() < 4)
                return;
            if (pending_[0] || pending_[1] || pending_[2] != 1)
                throw std::runtime_error("Invalid MPEG program stream prefix");
            const auto code = pending_[3];
            size_t count = 0;
            if (code == 0xb9) {
                count = 4;
                programEnd_ = true;
            } else if (code == 0xba) {
                if (pending_.size() < 5)
                    return;
                if (pending_[4] >> 4 == 2)
                    count = 12;
                else if ((pending_[4] & 0xc0) == 0x40) {
                    if (pending_.size() < 14)
                        return;
                    count = 14 + (pending_[13] & 7);
                } else
                    throw std::runtime_error("Unsupported MPEG pack header");
            } else {
                if (pending_.size() < 6)
                    return;
                count = 6 + (size_t(pending_[4]) << 8) + pending_[5];
                if (count == 6)
                    throw std::runtime_error("Unbounded PES packets are unsupported");
            }
            if (pending_.size() < count)
                return;
            if (code != 0xba && code != 0xb9)
                packet(std::span<const uint8_t>(pending_).first(count));
            pending_.erase(pending_.begin(), pending_.begin() + count);
            base_ += count;
        }
    }

  public:
    explicit MpegProgramStream(Mpeg2ElementaryStream& video, uint8_t stream = 0xe0)
        : video_(video), stream_(stream) {
        if (stream < 0xe0 || stream > 0xef)
            throw std::invalid_argument("Not a video PES stream");
    }
    void feed(uint64_t sourceOffset, std::span<const uint8_t> bytes) {
        if (ended_ || failed_)
            throw std::logic_error("Movie program stream is closed/failed");
        if (sourceOffset != accepted_ || pending_.size() + bytes.size() > 2 * 1024 * 1024) {
            failed_ = true;
            throw std::runtime_error("Program stream gap/input backpressure exceeded");
        }
        try {
            pending_.insert(pending_.end(), bytes.begin(), bytes.end());
            accepted_ += bytes.size();
            parse();
        } catch (...) {
            failed_ = true;
            throw;
        }
    }
    void end() {
        if (ended_ || failed_)
            throw std::logic_error("Movie program stream is closed/failed");
        if (!pending_.empty()) {
            failed_ = true;
            throw std::runtime_error("Truncated MPEG program packet");
        }
        video_.end();
        ended_ = true;
    }
};
} // namespace reo_gpu_movie
