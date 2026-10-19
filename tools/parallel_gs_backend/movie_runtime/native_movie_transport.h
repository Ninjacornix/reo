#pragma once
#pragma push_macro("EXCEPTION_BREAKPOINT")
#undef EXCEPTION_BREAKPOINT
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#pragma pop_macro("EXCEPTION_BREAKPOINT")
#include "compressed_movie_lineage.h"
#include "original_transport_route.h"
#include "live_movie_producer.h"
#include "ipu/ps2_ipu_native.h"

namespace reo_gpu_movie {
// EE/control-side binding to the actual Runtime compressed IPU channel. The
// LiveMovieProducer is constructed/destroyed and decoded on the real GS owner;
// only its bounded compressed-copy/timestamp methods run on this thread.
class NativeMovieTransport {
    static LiveMovieProducer& retained(const std::shared_ptr<LiveMovieProducer>& value) {
        if (!value)
            throw std::invalid_argument("Missing retained native compressed input endpoint");
        return *value;
    }
    PS2Runtime& runtime_;
    OriginalCompressedLineage& lineage_;
    std::shared_ptr<LiveMovieProducer> retainedProducer_;
    LiveMovieProducer& producer_;
    MovieSessionOwner owner_;
    uint32_t inner_ = 0;
    bool attached_ = false;
    uint64_t attachEndSerial_ = 0;
    uint64_t pictureBegin_ = 0, headerSerial_ = 0, headerDmaSerial_ = 0;
    static bool resolve(void* self, uint32_t source, uint32_t bytes, uint64_t& offset) {
        auto& value = *static_cast<NativeMovieTransport*>(self);
        return value.lineage_.resolve(value.owner_.generation, source, bytes, offset);
    }
    static bool accept(void* self, uint64_t generation, uint64_t serial, uint64_t offset,
                       uint32_t source, const uint8_t* bytes, uint32_t count) {
        auto& value = *static_cast<NativeMovieTransport*>(self);
        CompressedDmaCopy receipt;
        return value.producer_.copyB400(generation, serial, offset, source, {bytes, count},
                                        receipt) &&
               receipt.bytesCopied;
    }
    static void timestamp(void* self, uint64_t generation, const OriginalPesRange& original) {
        auto& value = *static_cast<NativeMovieTransport*>(self);
        PesTimestamp stamp;
        stamp.elementaryBegin = original.elementaryBegin;
        stamp.elementaryEnd = original.elementaryEnd;
        stamp.pts33 = original.header.pts33;
        stamp.dts33 = original.header.dts33;
        stamp.hasPts = original.header.hasPts;
        stamp.hasDts = original.header.hasDts;
        // This GAME seam has authentic guest header/source/serial provenance,
        // but no asset-relative PS byte offset. Do not fabricate that offset.
        stamp.packetOffset = 0;
        value.producer_.demuxTimestamp(generation, stamp);
    }
    static void committed(void* self, uint64_t generation, uint64_t offset,
                          std::span<const uint8_t> bytes) {
        auto& value = *static_cast<NativeMovieTransport*>(self);
        if (!value.producer_.commitElementary(generation, offset, bytes))
            throw std::runtime_error(
                "Original compressed movie feed exhausted its bounded owner queue");
    }
    static void end(void* self, uint64_t generation) {
        static_cast<NativeMovieTransport*>(self)->producer_.inputEnd(generation);
    }
    static void tail(void* self, uint64_t generation, uint64_t offset,
                     std::span<const uint8_t> bytes) {
        static_cast<NativeMovieTransport*>(self)->producer_.commitTransportTail(generation, offset,
                                                                                bytes);
    }

  public:
    NativeMovieTransport(PS2Runtime& runtime, OriginalCompressedLineage& lineage,
                         LiveMovieProducer& producer, MovieSessionOwner owner, uint32_t inner)
        : runtime_(runtime), lineage_(lineage), producer_(producer), owner_(owner),
          inner_(OriginalCompressedLineage::canonical(inner)) {}
    NativeMovieTransport(PS2Runtime& runtime, OriginalCompressedLineage& lineage,
                         std::shared_ptr<LiveMovieProducer> producer, MovieSessionOwner owner,
                         uint32_t inner)
        : runtime_(runtime), lineage_(lineage), retainedProducer_(std::move(producer)),
          producer_(retained(retainedProducer_)), owner_(owner),
          inner_(OriginalCompressedLineage::canonical(inner)) {}
    // Must run at original171D10 quiescence, before its first owned numerical
    // entry. Observed pre-attach selected compressed commits are replayed first.
    void attach(const uint8_t* ram) {
        if (attached_)
            throw std::logic_error("Native movie transport already attached");
        attachEndSerial_ = reo_gpu_movie_transport::demuxEndSerial.load(std::memory_order_acquire);
        lineage_.bind(ram, owner_.generation, owner_.sofdec, owner_.work, this, timestamp,
                      committed, end, tail);
        try {
            ps2_ipu_native::attach(runtime_, {&runtime_, this, owner_.generation, resolve, accept});
            attached_ = true;
        } catch (...) {
            lineage_.unbind(owner_.generation);
            throw;
        }
    }
    void detach() {
        if (!attached_)
            return;
        ps2_ipu_native::detach(runtime_, this, owner_.generation);
        lineage_.unbind(owner_.generation);
        attached_ = false;
    }
    // Actual145D60 entry is AFTER original145C40 consumed exactly32 start-code
    // bits and BEFORE original145D60 consumes10 temporal-reference bits.
    void pictureHeader(PS2Runtime& runtime, R5900Context& context, uint32_t inner) {
        if (!attached_ || &runtime != &runtime_ ||
            OriginalCompressedLineage::canonical(inner) != inner_)
            return;
        ps2_ipu_native::Cursor cursor;
        if (!ps2_ipu_native::cursor(runtime_, this, owner_.generation, cursor) ||
            cursor.elementaryBit < 32 || (cursor.elementaryBit & 7) || context.pc != 0x145d60)
            throw std::runtime_error(
                "Original parsed picture lacks exact native compressed cursor lineage");
        pictureBegin_ = (cursor.elementaryBit - 32) / 8;
        headerDmaSerial_ = cursor.dmaSerial;
        ++headerSerial_;
    }
    OriginalDecodeEvent decodeEvent(const uint8_t* ram, uint64_t serial, uint32_t inner) const {
        if (!attached_ || !headerSerial_ || !serial ||
            OriginalCompressedLineage::canonical(inner) != inner_)
            throw std::runtime_error("Native decode lacks actual original picture header event");
        OriginalDecodeEvent event;
        event.generation = owner_.generation;
        event.serial = serial;
        event.elementaryPictureBegin = pictureBegin_;
        event.inner = inner_;
        event.width = OriginalCompressedLineage::read32(ram, owner_.work + 0xc);
        event.height = OriginalCompressedLineage::read32(ram, owner_.work + 0x10);
        event.kind = OriginalCompressedLineage::read32(ram, inner_ + 0x168);
        event.structure = OriginalCompressedLineage::read32(ram, inner_ + 0x18c);
        event.originalTemporalReference = OriginalCompressedLineage::read32(ram, inner_ + 0x1c4);
        event.originalTemporalBase = OriginalCompressedLineage::read32(ram, inner_ + 0x864);
        event.temporalReference =
            (event.originalTemporalReference - event.originalTemporalBase) & 1023;
        event.headerSerial = headerSerial_;
        event.headerDmaSerial = headerDmaSerial_;
        event.headerCursorBit = (pictureBegin_ + 4) * 8;
        return event;
    }
    // Invoke only for the actual same event's GPU producer completion. Caller
    // keeps its scheduled wait if original compressed DMA cannot reach the
    // proven end yet. No BDEC/CSC executes. Software peek cache is invalidated
    // so the original header helpers request a real FDEC0 at the new position.
    bool advanceCompletedDecode(uint8_t* ram, const NativeDecodeCompletion& completion) {
        if (!attached_ || !completion.ready || completion.generation != owner_.generation ||
            !completion.elementaryEnd ||
            completion.elementaryEnd > std::numeric_limits<uint64_t>::max() / 8)
            throw std::invalid_argument("Native compressed advance lacks genuine GPU completion");
        if (!ps2_ipu_native::advanceTo(runtime_, this, owner_.generation,
                                       completion.elementaryEnd * 8))
            return false;
        uint32_t zero = 0;
        std::memcpy(ram + inner_ + 0x854, &zero, 4);
        return true;
    }
    // Original171920 (demux end-of-program callback) writes its EOS marker only once ring+0x10 drains, which needs
    // the last picture decoded. Once that callback has run for this movie, report the final committed count so the
    // producer can finish the last picture (real IPU needs no following start code) and break the deadlock.
    void observeFileEnd(const uint8_t* ram) {
        if (!attached_ ||
            reo_gpu_movie_transport::demuxEndSerial.load(std::memory_order_acquire) <=
                attachEndSerial_ ||
            reo_gpu_movie_transport::demuxEndWork.load(std::memory_order_relaxed) !=
                OriginalCompressedLineage::canonical(owner_.work))
            return;
        const uint32_t ring = owner_.work + 0xa48;
        const uint64_t committed =
            uint64_t(OriginalCompressedLineage::read32(ram, ring + 0x48)) |
            (uint64_t(OriginalCompressedLineage::read32(ram, ring + 0x4c)) << 32);
        producer_.finalInput(owner_.generation, committed);
    }
    uint64_t generation() const {
        return owner_.generation;
    }
    uint64_t headerSerial() const {
        return headerSerial_;
    }
    uint64_t headerDmaSerial() const {
        return headerDmaSerial_;
    }
    // Bounded diagnostic only: the current compressed-input bit position (0
    // when unattached or not parseable). Never advances the IPU cursor.
    uint64_t compressedInputBit() {
        if (!attached_)
            return 0;
        ps2_ipu_native::Cursor cursor;
        if (!ps2_ipu_native::cursor(runtime_, this, owner_.generation, cursor))
            return 0;
        return cursor.elementaryBit;
    }
    void thresholds(uint32_t& th0, uint32_t& th1) {
        if (!attached_)
            throw std::logic_error("Unbound native movie thresholds");
        ps2_ipu_native::thresholds(runtime_, this, owner_.generation, th0, th1);
    }
};
} // namespace reo_gpu_movie
