#pragma once
#include "static_stream_abi.hpp"
#include "resident_vif_commands.h"
#include "tools/parallel_gs_backend/resident_geometry/enrollment/sha256.hpp"
#include <cstring>
#include <limits>
#include <stdexcept>
#include <vector>
namespace reo_gpu_static_group {
namespace source = reo_gpu_static_stream;
class TypedBuilder {
    std::shared_ptr<const reo_resident_live::Program> program_;
    std::vector<source::Job> jobs_;
    std::vector<source::Raw> raws_;
    std::vector<std::array<uint32_t, 4>> payloads_;
    std::vector<std::array<uint32_t, 64>> echoes_;
    std::vector<uint64_t> ordinals_;
    uint32_t begin_ = 0;
    uint64_t codeGeneration_ = 0;

  public:
    explicit TypedBuilder(std::shared_ptr<const reo_resident_live::Program> program)
        : program_(std::move(program)) {
        if (!program_ || !program_->bindingId)
            throw std::invalid_argument("Missing immutable static registry identity");
        const std::vector<uint8_t> bytes(program_->exactImage.begin(), program_->exactImage.end());
        if (reo_gpu_catalog::sha256(bytes) !=
            "5273fa3e9893df4b3833a22b1d7deec2f99a2d2af0c10f2aa0ff5b43d3b2fc25")
            throw std::invalid_argument("Static typed builder requires full exact image");
    }
    void clear() {
        jobs_.clear();
        raws_.clear();
        payloads_.clear();
        echoes_.clear();
        ordinals_.clear();
        begin_ = 0;
        codeGeneration_ = 0;
    }
    uint32_t jobs() const {
        return uint32_t(jobs_.size());
    }
    uint32_t rows() const {
        return uint32_t(raws_.size());
    }
    const std::vector<uint64_t>& ordinals() const {
        return ordinals_;
    }
    bool room(uint32_t rows, uint32_t calls = 0) const {
        return rows <= source::MaxRawWrites - raws_.size() &&
               calls <= source::MaxJobs - jobs_.size();
    }
    static uint32_t rawRows(const reo_resident_live::Operation& op, uint32_t cycle, uint32_t mode) {
        using reo_resident_live::Kind;
        if (op.kind == Kind::DataWrite)
            return op.controlByte < 16384 && !(op.controlByte & 15) && !(op.payload.size() & 15) &&
                           !op.payload.empty() && op.payload.size() <= 4096 &&
                           op.controlByte + op.payload.size() <= 16384
                       ? uint32_t(op.payload.size() / 16)
                       : 0;
        if (op.kind != Kind::Unpack)
            return 0;
        const uint32_t cl = (cycle & 255) ? cycle & 255 : 1,
                       wl = ((cycle >> 8) & 255) ? (cycle >> 8) & 255 : 1;
        const uint32_t count = ((op.command >> 16) & 255) ? (op.command >> 16) & 255 : 256;
        return ((op.command >> 24) & 127) == 0x6c && (mode & 3) == 0 && cl == wl &&
                       op.latchedTops < 1024 && op.payload.size() == count * 16
                   ? count
                   : 0;
    }
    bool raw(const reo_resident_live::Operation& op, uint32_t cycle, uint32_t mode) {
        const auto n = rawRows(op, cycle, mode);
        if (!n || !room(n))
            return false;
        const bool unpack = op.kind == reo_resident_live::Kind::Unpack;
        uint32_t top = unpack ? op.command & 1023 : op.controlByte / 16;
        if (unpack && (op.command & 32768))
            top = (top + op.latchedTops) & 1023;
        for (uint32_t q = 0; q < n; ++q) {
            source::Raw r{};
            r.beforeJob = jobs();
            r.qword = (top + q) & 1023;
            r.ordinal = rows();
            r.payloadOffset = r.ordinal * 4;
            r.kind =
                uint32_t(unpack ? source::RawKind::VIFV432Mode0 : source::RawKind::AlignedQword);
            std::array<uint32_t, 4> p{};
            std::memcpy(p.data(), op.payload.data() + q * 16, 16);
            raws_.push_back(r);
            payloads_.push_back(p);
        }
        return true;
    }
    bool covers(const reo_resident_live::Operation& op, bool checkGeneration = true) const {
        using namespace reo_resident_live;
        if (op.kind != Kind::Launch || !op.program || !op.program->complete() ||
            !op.program->accepts(op.startPC, op.resume) ||
            op.program->bindingId != program_->bindingId ||
            op.program->exactImage != program_->exactImage || op.codeGeneration == 0 ||
            !op.program->literalSourcePreserved || op.maxPairs != 65536 || op.top >= 1024 ||
            op.itop >= 1024 || !op.ordinal || !op.payload.empty() ||
            (checkGeneration && codeGeneration_ && codeGeneration_ != op.codeGeneration))
            return false;
        if (!op.resume && op.startPC == 0)
            return op.effect.type == LiteralEffect::Type::None;
        if (!op.resume && op.startPC != 88 && op.startPC != 296 && op.startPC != 1320)
            return false;
        if (op.effect.type == LiteralEffect::Type::MaterialAD)
            return op.effect.echo[0] == 2 && op.effect.echo[1] == 6;
        return op.effect.type == LiteralEffect::Type::Strip && op.orderedStream &&
               op.orderedStream->exactRawTop && op.orderedStream->exactRawTag &&
               op.orderedStream->selector == 1 && op.orderedStream->inputCount > 0 &&
               op.orderedStream->inputCount <= 49 && op.effect.echo[0] == 1 &&
               (op.effect.echo[4] & 32767) == op.orderedStream->inputCount;
    }
    bool launch(const reo_resident_live::Operation& op, uint32_t materialEpoch) {
        if (!covers(op) || !room(0, 1) ||
            (!ordinals_.empty() && op.ordinal != ordinals_.back() + 1))
            return false;
        source::Job j{};
        j.entryPC = op.startPC;
        j.operation = op.resume ? 4 : 0;
        j.TOP = op.top;
        j.ITOP = op.itop;
        j.rawBegin = begin_;
        j.rawEnd = rows();
        j.ordinal = jobs();
        j.materialEpoch = materialEpoch;
        std::array<uint32_t, 64> e{};
        if (op.effect.type == reo_resident_live::LiteralEffect::Type::MaterialAD) {
            j.kindHint = 2;
            std::memcpy(e.data(), op.effect.echo.data(), 128);
            e[1] = 6;
        } else if (op.effect.type == reo_resident_live::LiteralEffect::Type::Strip) {
            j.kindHint = 1;
            std::memcpy(e.data(), op.effect.echo.data(), 128);
            e[1] = 247;
        }
        jobs_.push_back(j);
        echoes_.push_back(e);
        ordinals_.push_back(op.ordinal);
        begin_ = rows();
        codeGeneration_ = op.codeGeneration;
        return true;
    }
    std::vector<uint32_t>
    literalTape(uint32_t generation,
                source::SourceClass sourceClass = source::SourceClass::LiteralTypedVIF) const {
        if (jobs_.empty() || !generation)
            throw std::invalid_argument("Empty/stale literal typed group");
        source::Header h{};
        h.jobs = jobs();
        h.rawWrites = rows();
        h.rawOffset = 16 + h.jobs * 16;
        h.payloadOffset = h.rawOffset + h.rawWrites * 8;
        h.payloadWords = h.rawWrites * 4;
        h.echoOffset = (h.payloadOffset + h.payloadWords + 63) & ~63u;
        h.echoWords = h.jobs * 64;
        h.totalWords = h.echoOffset + h.echoWords;
        h.generation = generation;
        h.sourceClass = uint32_t(sourceClass);
        std::vector<uint32_t> tape(h.totalWords);
        std::memcpy(tape.data(), &h, sizeof(h));
        for (uint32_t j = 0; j < h.jobs; ++j) {
            auto item = jobs_[j];
            item.echoOffset = h.echoOffset + j * 64;
            std::memcpy(tape.data() + 16 + j * 16, &item, 64);
            std::memcpy(tape.data() + item.echoOffset, echoes_[j].data(), 256);
        }
        for (uint32_t r = 0; r < h.rawWrites; ++r) {
            std::memcpy(tape.data() + h.rawOffset + r * 8, &raws_[r], 32);
            std::memcpy(tape.data() + h.payloadOffset + r * 4, payloads_[r].data(), 16);
        }
        return tape;
    }
};
} // namespace reo_gpu_static_group
