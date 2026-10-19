#pragma once
#include "stream_pipeline.hpp"
#include "resident_vif_commands.h"
namespace reo_gpu_array_bridge {
class Builder {
    Input input_;

  public:
    const Input& input() const {
        return input_;
    }
    void clear() {
        input_ = Input{};
    }
    bool hasCommands() const {
        return !input_.commands.empty();
    }
    size_t jobs() const {
        return input_.jobs.size();
    }
    size_t commands() const {
        return input_.commands.size();
    }
    size_t rows() const {
        return input_.rawRows.size();
    }
    bool room(uint32_t rawQwords, uint32_t launches = 0) const {
        return input_.commands.size() + rawQwords + launches <= stream::MaxCommands &&
               input_.rawRows.size() + rawQwords + 1024u <= stream::MaxRawRows &&
               input_.jobs.size() + launches <= stream::MaxJobs;
    }
    static uint32_t rawWriteRows(const reo_resident_live::Operation& op, uint32_t cycle,
                                 uint32_t mode) {
        using namespace reo_resident_live;
        if (op.kind == Kind::DataWrite)
            return !(op.controlByte & 15u) && !(op.payload.size() & 15u)
                       ? uint32_t(op.payload.size() / 16u)
                       : 0;
        if (op.kind != Kind::Unpack)
            return 0;
        const uint32_t opcode = (op.command >> 24) & 127u;
        const uint32_t cl = (cycle & 255u) ? cycle & 255u : 1u,
                       wl = ((cycle >> 8) & 255u) ? (cycle >> 8) & 255u : 1u;
        const uint32_t count = ((op.command >> 16) & 255u) ? (op.command >> 16) & 255u : 256u;
        // Exact original raw V4-32 writes. Compressed/masked/add/difference
        // formats close the epoch and run the existing GPU UNPACK instead.
        return opcode == 0x6cu && (mode & 3u) == 0u && cl == wl && op.payload.size() == count * 16u
                   ? count
                   : 0;
    }
    void rawWrite(const reo_resident_live::Operation& op, uint32_t cycle, uint32_t mode) {
        const uint32_t count = rawWriteRows(op, cycle, mode);
        if (!count || !room(count))
            throw std::invalid_argument("Unproved/oversized typed raw qword write");
        uint32_t destination = op.kind == reo_resident_live::Kind::DataWrite ? op.controlByte / 16u
                                                                             : op.command & 1023u;
        if (op.kind == reo_resident_live::Kind::Unpack && (op.command & 32768u))
            destination = (destination + op.latchedTops) & 1023u;
        for (uint32_t q = 0; q < count; ++q) {
            std::array<uint8_t, 16> row{};
            std::memcpy(row.data(), op.payload.data() + q * 16u, 16);
            const uint32_t arena = uint32_t(input_.rawRows.size()) + 1024u;
            input_.rawRows.push_back(row);
            input_.commands.push_back(
                {uint32_t(stream::CommandKind::RawQword), (destination + q) & 1023u, arena, 0});
        }
    }
    void launch(const reo_resident_live::Operation& op) {
        if (!op.orderedStream || !op.orderedStream->exactRawTop || !op.orderedStream->exactRawTag ||
            (op.orderedStream->selector != 1 && op.orderedStream->selector != 2) ||
            op.orderedStream->inputCount != 39 || !op.resume || !room(0, 1))
            throw std::invalid_argument("Missing exact original launch source facts");
        const uint32_t index = uint32_t(input_.jobs.size());
        input_.jobs.push_back({0x3ff8u, 65536u, op.top, op.itop, 4u, op.effect.vertexCapacity,
                               op.orderedStream->selector, 0u});
        stream::Echo echo{};
        std::memcpy(&echo, op.effect.echo.data(), sizeof(op.effect.echo));
        input_.echoes.push_back(echo);
        input_.commands.push_back({uint32_t(stream::CommandKind::Launch), index, 0, 0});
    }
};
} // namespace reo_gpu_array_bridge
