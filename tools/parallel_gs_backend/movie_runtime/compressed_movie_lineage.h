#pragma once
#include "reo_movie_game_addresses.h"
#include <cstdlib>
#include <cstdio>
// Original PES/header/ring ownership only. No decoded graphics or clock model.
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <cstdio>
#include <deque>
#include <limits>
#include <map>
#include <mutex>
#include <span>
#include <stdexcept>
#include <vector>
#include <variant>

namespace reo_gpu_movie {
struct OriginalPesHeader {
    uint64_t serial = 0, pts33 = 0, dts33 = 0;
    uint32_t record = 0, source = 0, headerBytes = 0, payloadBytes = 0;
    std::array<uint32_t, 7> originalRecord{};
    bool hasPts = false, hasDts = false;
};
struct OriginalPesRange {
    OriginalPesHeader header;
    uint64_t elementaryBegin = 0, elementaryEnd = 0;
    // Original guest packet/header identity is known. A raw asset/file offset
    // is deliberately not inferred from a guest address or the packet serial.
};
class OriginalCompressedLineage {
  public:
    using Timestamp = void (*)(void*, uint64_t, const OriginalPesRange&);
    using Committed = void (*)(void*, uint64_t, uint64_t, std::span<const uint8_t>);
    using End = void (*)(void*, uint64_t);
    using TransportTail = void (*)(void*, uint64_t, uint64_t, std::span<const uint8_t>);
    static constexpr uint32_t RamBytes = 0x2000000;
    static bool physical(uint32_t address, uint32_t bytes, uint32_t& result) {
        const uint32_t bank = address & 0xfe000000;
        if (bank && bank != 0x20000000 && bank != 0x80000000 && bank != 0xa0000000)
            return false;
        result = address & 0x1ffffff;
        return bytes <= RamBytes && result <= RamBytes - bytes;
    }
    static uint32_t read32(const uint8_t* ram, uint32_t address) {
        uint32_t at = 0, value = 0;
        if (!ram || !physical(address, 4, at))
            throw std::invalid_argument("Movie control pointer outside actual RDRAM");
        std::memcpy(&value, ram + at, 4);
        return value;
    }
    static uint64_t read64(const uint8_t* ram, uint32_t address) {
        uint32_t at = 0;
        uint64_t value = 0;
        if (!ram || !physical(address, 8, at))
            throw std::invalid_argument("Movie control pointer outside actual RDRAM");
        std::memcpy(&value, ram + at, 8);
        return value;
    }
    static uint32_t canonical(uint32_t address) {
        uint32_t at = 0;
        if (!physical(address, 1, at) || !at)
            throw std::invalid_argument("Invalid movie owner pointer");
        return at;
    }
    static OriginalPesHeader parseHeader(std::span<const uint8_t> bytes) {
        if (bytes.size() < 7 || bytes.size() > 264 || bytes[0] || bytes[1] || bytes[2] != 1 ||
            bytes[3] < 0xe0 || bytes[3] > 0xef)
            throw std::invalid_argument("Not an original bounded video PES header");
        const uint32_t packetBytes = (uint32_t(bytes[4]) << 8) | bytes[5];
        if (!packetBytes || uint64_t(packetBytes) + 6 < bytes.size())
            throw std::invalid_argument("Invalid original video PES length");
        OriginalPesHeader value;
        size_t at = 6;
        auto stamp = [&](unsigned prefix) {
            if (at + 5 > bytes.size() || bytes[at] >> 4 != prefix || !(bytes[at] & 1) ||
                !(bytes[at + 2] & 1) || !(bytes[at + 4] & 1))
                throw std::invalid_argument("Invalid original PES timestamp marker");
            const auto* p = bytes.data() + at;
            at += 5;
            return (uint64_t((p[0] >> 1) & 7) << 30) | (uint64_t(p[1]) << 22) |
                   (uint64_t(p[2] >> 1) << 15) | (uint64_t(p[3]) << 7) | (p[4] >> 1);
        };
        if ((bytes[at] & 0xc0) == 0x80) {
            if (bytes.size() < 9 || bytes.size() != 9 + size_t(bytes[8]))
                throw std::invalid_argument("Original MPEG-2 PES header consumption mismatch");
            const auto flags = bytes[7] >> 6;
            if (flags == 1)
                throw std::invalid_argument("Invalid original PES PTS/DTS flags");
            at = 9;
            if (flags >= 2) {
                value.pts33 = stamp(flags);
                value.hasPts = true;
            }
            if (flags == 3) {
                value.dts33 = stamp(1);
                value.hasDts = true;
            }
            at = bytes.size();
        } else {
            unsigned stuffing = 0;
            while (at < bytes.size() && bytes[at] == 255) {
                ++at;
                if (++stuffing > 32)
                    throw std::invalid_argument("Original MPEG-1 PES stuffing bound");
            }
            if (at >= bytes.size())
                throw std::invalid_argument("Truncated original MPEG-1 PES header");
            if ((bytes[at] & 0xc0) == 0x40)
                at += 2;
            if (at >= bytes.size())
                throw std::invalid_argument("Truncated original MPEG-1 STD header");
            const unsigned flags = bytes[at] >> 4;
            if (flags == 2 || flags == 3) {
                value.pts33 = stamp(flags);
                value.hasPts = true;
                if (flags == 3) {
                    value.dts33 = stamp(1);
                    value.hasDts = true;
                }
            } else if (bytes[at++] != 15)
                throw std::invalid_argument("Invalid original MPEG-1 PES timestamp flags");
            if (at != bytes.size())
                throw std::invalid_argument("Original MPEG-1 PES header consumption mismatch");
        }
        value.headerBytes = uint32_t(bytes.size());
        value.payloadBytes = packetBytes + 6 - value.headerBytes;
        return value;
    }

  private:
    struct Packet {
        OriginalPesHeader header;
        uint64_t begin = 0;
        uint32_t committed = 0;
        bool assigned = false, stamped = false;
    };
    struct Selection {
        uint64_t packet = 0;
        uint32_t source = 0, bytes = 0, stack = 0;
        bool eof = false;
    };
    struct Bytes {
        uint64_t offset = 0;
        std::vector<uint8_t> bytes;
    };
    struct Provisional {
        uint32_t ring = 0, record = 0, start = 0, stack = 0;
        uint64_t serial = 0;
        Bytes copy;
        bool eof = false;
        uint32_t markerLapBytes = 0;
    };
    struct Eof {};
    struct Tail {
        uint64_t offset = 0;
        std::vector<uint8_t> bytes;
    };
    using Event = std::variant<OriginalPesRange, Bytes, Eof, Tail>;
    struct Ring {
        uint64_t epoch = 0, committed = 0;
        uint32_t base = 0, capacity = 0;
        std::vector<uint64_t> elementary;
        std::vector<uint8_t> valid;
        std::deque<Event> events;
        size_t pendingBytes = 0;
        uint32_t markerLapBytes = 0;
        bool eof = false, tailPublished = false;
    };
    mutable std::mutex mutex_;
    std::map<uint32_t, Packet> packets_;
    std::map<uint32_t, Ring> rings_;
    std::map<uintptr_t, Selection> selected_;
    std::map<uintptr_t, Provisional> provisional_;
    uint64_t nextPacket_ = 0, nextEpoch_ = 0, generation_ = 0;
    uint32_t ring_ = 0, sofdec_ = 0, work_ = 0;
    void* timestampOwner_ = nullptr;
    Timestamp timestamp_ = nullptr;
    Committed copied_ = nullptr;
    End end_ = nullptr;
    TransportTail tail_ = nullptr;
    static constexpr uint64_t Unknown = std::numeric_limits<uint64_t>::max();
    mutable uint32_t pastEndAt_ = 0;
    mutable uint64_t pastEndOffset_ = 0, pastEndCommitted_ = 0; // resolve-only, under mutex_
    static bool eofLog() {
        static const bool v = [] {
            const char* e = std::getenv("REO_GPU_MOVIE_LOG");
            return e && *e && *e != '0';
        }();
        return v;
    }
    void flush(uint32_t ring, Ring& value) {
        if (!generation_ || ring_ != ring)
            return;
        while (!value.events.empty()) {
            auto& event = value.events.front();
            if (auto* range = std::get_if<OriginalPesRange>(&event))
                timestamp_(timestampOwner_, generation_, *range);
            else if (auto* bytes = std::get_if<Bytes>(&event)) {
                copied_(timestampOwner_, generation_, bytes->offset, bytes->bytes);
                value.pendingBytes -= bytes->bytes.size();
            } else if (auto* tail = std::get_if<Tail>(&event)) {
                tail_(timestampOwner_, generation_, tail->offset, tail->bytes);
                value.pendingBytes -= tail->bytes.size();
            } else
                end_(timestampOwner_, generation_);
            value.events.pop_front();
        }
    }

  public:
    // Runs immediately after original 170B48 zeroes ring+48. Keep candidate
    // rings before native activation so initial original header DMA is owned.
    void initialized(const uint8_t* ram, uint32_t ring) {
        ring = canonical(ring);
        const auto base = canonical(read32(ram, ring)), capacity = read32(ram, ring + 0x18),
                   chunks = read32(ram, ring + 8);
        uint32_t at = 0;
        if (!chunks || chunks > 512 || capacity != uint64_t(chunks) * 2048 ||
            !physical(base, capacity, at) || read64(ram, ring + 0x48))
            throw std::invalid_argument("Original ring initialization geometry/counter mismatch");
        std::lock_guard<std::mutex> lock(mutex_);
        if (generation_ && ring_ == ring)
            throw std::logic_error("Active native movie ring reinitialized before cancellation");
        if (!rings_.count(ring) && rings_.size() >= 8)
            throw std::runtime_error("Original movie candidate ring bound");
        Ring value;
        value.epoch = ++nextEpoch_;
        value.base = base;
        value.capacity = capacity;
        value.elementary.assign(capacity, Unknown);
        value.valid.assign(capacity, 0);
        rings_[ring] = std::move(value);
    }
    // Raw header is read only after original1570D8 has parsed it and supplied
    // its exact consumed byte count. Original integer record remains untouched.
    void pesParsed(const uint8_t* ram, uint32_t record, uint32_t source, uint32_t consumed) {
        uint32_t at = 0, recordAt = 0;
        if (!physical(source, consumed, at) || !physical(record, 32, recordAt))
            throw std::invalid_argument("Original PES source/record outside RDRAM");
        if (consumed < 7 || consumed > 264)
            return;
        if (ram[at] || ram[at + 1] || ram[at + 2] != 1 || ram[at + 3] < 0xe0 || ram[at + 3] > 0xef)
            return;
        auto header = parseHeader({ram + at, consumed});
        header.record = recordAt;
        header.source = at;
        for (unsigned i = 0; i < 7; ++i)
            header.originalRecord[i] = read32(ram, record + 4 * i);
        if (header.originalRecord[0] != ram[at + 3] || header.originalRecord[1] != 1 ||
            header.payloadBytes != read32(ram, record + 0x1c))
            throw std::invalid_argument("Raw PES header does not match genuine original record");
        std::lock_guard<std::mutex> lock(mutex_);
        header.serial = ++nextPacket_;
        if (!packets_.count(recordAt) && packets_.size() >= 64)
            throw std::runtime_error("Original movie PES record bound");
        auto prior = packets_.find(recordAt);
        if (prior != packets_.end() && prior->second.assigned &&
            prior->second.committed != prior->second.header.payloadBytes)
            throw std::runtime_error(
                "Original selected video packet replaced before full ring commit");
        packets_[recordAt] = Packet{header};
    }
    // Genuine 171880 entry, tail-called by171AC8 with original16AAF8 return.
    // S1 is the saved original Sofdec; source/count are literal A1/A2. The
    // record lookup is through that Sofdec's controller[0] demux handle, not a global
    // last timestamp or a physical-address-to-stream-offset guess.
    void selectedCopy(const uint8_t* ram, uintptr_t context, uint32_t stack, uint32_t ring,
                      uint32_t source, uint32_t bytes, uint32_t sofdec, uint32_t originalReturn) {
        ring = canonical(ring);
        sofdec = canonical(sofdec);
        if (originalReturn != REO_MA(0x16aaf8) || canonical(read32(ram, sofdec + 0x1b30)) + 0xa48 != ring)
            throw std::invalid_argument("Original selected video ring/caller mismatch");
        // Original16B814 stores the controller at Sofdec+1AEC. Original
        // 16A354..16A35C and16A6AC..16A6B4 then load controller[0] before
        // calling the genuine demux parser/accessor. These are distinct owners.
        const auto controller = canonical(read32(ram, sofdec + 0x1aec));
        const auto demux = canonical(read32(ram, controller));
        const auto record = demux + 0xa0;
        uint32_t sourceAt = 0;
        if (!physical(source, bytes, sourceAt))
            throw std::invalid_argument("Original selected payload outside RDRAM");
        std::lock_guard<std::mutex> lock(mutex_);
        auto found = packets_.find(record);
        auto ringIt = rings_.find(ring);
        if (found == packets_.end() || ringIt == rings_.end()) {
            char detail[240];
            std::snprintf(detail, sizeof(detail),
                          "Selected video lacks original PES/ring lineage: sofdec=%08x "
                          "controller=%08x demux=%08x record=%08x ring=%08x source=%08x bytes=%u "
                          "packet_known=%u ring_known=%u",
                          sofdec, controller, demux, record, ring, sourceAt, bytes,
                          found != packets_.end() ? 1u : 0u, ringIt != rings_.end() ? 1u : 0u);
            throw std::runtime_error(detail);
        }
        auto& packet = found->second;
        for (unsigned i = 0; i < 7; ++i)
            if (read32(ram, record + 4 * i) != packet.header.originalRecord[i])
                throw std::invalid_argument("Original selected PES control record changed");
        if (bytes > packet.header.payloadBytes - packet.committed ||
            read32(ram, record + 0x1c) != packet.header.payloadBytes - packet.committed)
            throw std::invalid_argument("Original selected PES remaining length mismatch");
        if (!packet.assigned) {
            packet.begin = ringIt->second.committed;
            packet.assigned = true;
        }
        if (packet.begin + packet.committed != ringIt->second.committed)
            throw std::invalid_argument("Original PES to ES commit continuity lost");
        auto old = selected_.find(context);
        if (old != selected_.end() || provisional_.count(context))
            throw std::logic_error(
                "Original selected copy reentered before its real commit/SJ result");
        selected_[context] = {packet.header.serial, sourceAt, bytes, stack};
        if (generation_ && ring_ == ring && sofdec_ != sofdec)
            throw std::invalid_argument("Native movie Sofdec owner changed");
    }
    void selectedEnd(const uint8_t* ram, uintptr_t context, uint32_t stack, uint32_t ring,
                     uint32_t source, uint32_t bytes, uint32_t originalReturn) {
        ring = canonical(ring);
        uint32_t sourceAt = 0;
        if (originalReturn != REO_MA(0x171978) || canonical(source) != REO_MA(0x240918) || bytes != 16 ||
            !physical(source, bytes, sourceAt) || read32(ram, ring - 0xa48 + 0x9d8 + 0x18) != 1)
            throw std::invalid_argument("Original movie EOF padding source/caller mismatch");
        std::lock_guard<std::mutex> lock(mutex_);
        if (!rings_.count(ring) || selected_.count(context))
            throw std::logic_error("Original EOF copy lacks quiescent ring ownership");
        selected_[context] = {0, sourceAt, bytes, stack, true};
        if (eofLog())
            std::fprintf(stderr,
                         "[GPU-MOVIE-EOF] selected-end ring=%08x bound_ring=%08x generation=%llu "
                         "committed=%llu\n",
                         ring, ring_, (unsigned long long)generation_,
                         (unsigned long long)rings_.at(ring).committed);
    }
    // At170DB0 after original semaphore acquisition, before its bookkeeping.
    // Compare exact bytes the original171BE0 copied; only then publish their
    // latest physical ring ownership. Actual B400 consumes this map later.
    void committed(const uint8_t* ram, uintptr_t context, uint32_t ring, uint32_t bytes) {
        ring = canonical(ring);
        std::lock_guard<std::mutex> lock(mutex_);
        auto ri = rings_.find(ring);
        if (ri == rings_.end())
            return;
        auto& value = ri->second;
        auto selection = selected_.find(context);
        if (selection == selected_.end()) {
            // Original171920 adds its explicit16-byte sequence-end padding.
            // It has no PES timestamp and is joined separately below.
            if (bytes == 0)
                return;
            throw std::runtime_error("Original video ring commit lacks selected PES source");
        }
        auto packet = std::find_if(packets_.begin(), packets_.end(), [&](const auto& p) {
            return p.second.header.serial == selection->second.packet;
        });
        if ((!selection->second.eof &&
             (packet == packets_.end() ||
              bytes > packet->second.header.payloadBytes - packet->second.committed)) ||
            bytes > selection->second.bytes || read64(ram, ring + 0x48) != value.committed) {
            char detail[320];
            std::snprintf(detail, sizeof(detail),
                          "Original video commit/source length or counter mismatch: ring=%08x "
                          "actual=%llu expected=%llu bytes=%u selected=%u packet=%llu found=%u "
                          "committed=%u payload=%u source=%08x eof=%u",
                          ring, static_cast<unsigned long long>(read64(ram, ring + 0x48)),
                          static_cast<unsigned long long>(value.committed), bytes,
                          selection->second.bytes,
                          static_cast<unsigned long long>(selection->second.packet),
                          packet != packets_.end() ? 1u : 0u,
                          packet != packets_.end() ? packet->second.committed : 0u,
                          packet != packets_.end() ? packet->second.header.payloadBytes : 0u,
                          selection->second.source, selection->second.eof ? 1u : 0u);
            throw std::invalid_argument(detail);
        }
        if (canonical(read32(ram, ring)) != value.base ||
            read32(ram, ring + 0x18) != value.capacity)
            throw std::invalid_argument("Original ring storage changed");
        const auto read = read32(ram, ring + 0xc), pending = read32(ram, ring + 0x10),
                   partial = read32(ram, ring + 0x14), chunks = read32(ram, ring + 8);
        if (read >= chunks || pending > chunks || partial > value.capacity ||
            bytes > value.capacity)
            throw std::invalid_argument("Original ring commit cursor is invalid");
        const uint32_t offset =
            uint32_t(((uint64_t(read) + pending) * 2048 + partial) % value.capacity);
        for (uint32_t i = 0; i < bytes; ++i) {
            const auto target = (offset + i) % value.capacity;
            if (ram[value.base + target] != ram[selection->second.source + i])
                throw std::invalid_argument("Original ring copy differs from selected PES payload");
        }
        if (value.pendingBytes + bytes > 2 * 1024 * 1024 || value.events.size() >= 4096)
            throw std::runtime_error("Original compressed movie ownership queue bound");
        Bytes copy;
        copy.offset = value.committed;
        copy.bytes.assign(ram + selection->second.source, ram + selection->second.source + bytes);
        // The copy has physically overwritten free storage already. Prior ES
        // lineage can no longer describe these bytes while admission is pending.
        for (uint32_t i = 0; i < bytes; ++i)
            value.valid[(offset + i) % value.capacity] = 0;
        if (!selection->second.eof) {
            // 170DB0 is provisional: original16AB10 still has to admit the SJ
            // metadata/data. Failure calls171B38->170DE0 and subtracts this
            // exact guest counter increment. Never feed speculative bytes or
            // PTS to the GPU parser and then try to rewind decoded pictures.
            if (bytes) {
                if (provisional_.count(context))
                    throw std::logic_error("Original video has two unsettled commits");
                provisional_.emplace(
                    context, Provisional{ring, packet->first, offset, selection->second.stack,
                                         packet->second.header.serial, std::move(copy)});
            }
            selected_.erase(selection);
            return;
        }
        if (bytes != 16 || pending || partial > value.capacity - bytes ||
            provisional_.count(context))
            throw std::runtime_error(
                "Original movie EOF padding was partial or not at its proven drained ring event");
        provisional_.emplace(context, Provisional{ring, 0, offset, selection->second.stack, 0,
                                                  std::move(copy), true, partial + bytes});
        selected_.erase(selection);
    }
    // Literal16AEA0 returned to16AB1C after its original integer/SJ work. A
    // successful return1 publishes the actual staged compressed ownership;
    // other returns leave the original171B38/170DE0 rollback instructions live.
    void selectedResult(const uint8_t* ram, uintptr_t context, uint32_t stack, uint32_t result) {
        std::lock_guard<std::mutex> lock(mutex_);
        auto pending = provisional_.find(context);
        if (pending == provisional_.end())
            return;
        auto& stage = pending->second;
        auto ring = rings_.find(stage.ring);
        auto packet = packets_.find(stage.record);
        if (stage.eof || ring == rings_.end() || packet == packets_.end() ||
            packet->second.header.serial != stage.serial || stage.stack != stack)
            throw std::runtime_error(
                "Original video SJ result lost its staged source/context ownership");
        auto& value = ring->second;
        auto& selected = packet->second;
        const auto bytes = uint32_t(stage.copy.bytes.size());
        const auto actual = read64(ram, stage.ring + 0x48);
        if (stage.copy.offset != value.committed || actual != value.committed + bytes) {
            char detail[240];
            std::snprintf(detail, sizeof(detail),
                          "Original video SJ result counter mismatch: ring=%08x actual=%llu "
                          "expected=%llu staged=%u result=%u",
                          stage.ring, static_cast<unsigned long long>(actual),
                          static_cast<unsigned long long>(value.committed + bytes), bytes, result);
            throw std::runtime_error(detail);
        }
        if (result == 1) {
            if (!selected.stamped && selected.header.hasPts) {
                value.events.emplace_back(
                    OriginalPesRange{selected.header, selected.begin,
                                     selected.begin + selected.header.payloadBytes});
                selected.stamped = true;
            }
            for (uint32_t i = 0; i < bytes; ++i) {
                const auto at = (stage.start + i) % value.capacity;
                if (ram[value.base + at] != stage.copy.bytes[i])
                    throw std::runtime_error(
                        "Original SJ result observed an overwritten provisional source");
                value.elementary[at] = value.committed + i;
                value.valid[at] = 1;
            }
            value.committed += bytes;
            selected.committed += bytes;
            value.pendingBytes += bytes;
            value.events.emplace_back(std::move(stage.copy));
        } else {
            // Original rollback changes counters, not the bytes already copied
            // into free ring storage. That storage has no accepted ES lineage.
            for (uint32_t i = 0; i < bytes; ++i)
                value.valid[(stage.start + i) % value.capacity] = 0;
            if (!selected.committed)
                selected.assigned = false;
        }
        const auto selectedRing = stage.ring;
        provisional_.erase(pending);
        flush(selectedRing, value);
    }
    // Original171984 forces partial=capacity after the real16-byte EOS marker.
    // Original170E60 then publishes that full ring lap, including untouched
    // storage after EOS. Preserve these actual transport bytes for B400/DMA;
    // they are never appended to the ended ES parser or assigned a PES PTS.
    void endPaddingPublished(const uint8_t* ram, uint32_t ring) {
        ring = canonical(ring);
        std::lock_guard<std::mutex> lock(mutex_);
        auto found = rings_.find(ring);
        if (eofLog())
            std::fprintf(
                stderr,
                "[GPU-MOVIE-EOF] end-padding ring=%08x known=%u bound_ring=%08x generation=%llu\n",
                ring, found != rings_.end() ? 1u : 0u, ring_, (unsigned long long)generation_);
        if (found == rings_.end())
            return;
        auto& value = found->second;
        auto marker =
            std::find_if(provisional_.begin(), provisional_.end(), [&](const auto& entry) {
                return entry.second.ring == ring && entry.second.eof;
            });
        if (eofLog())
            std::fprintf(stderr,
                         "[GPU-MOVIE-EOF] end-padding marker=%u eof=%u tail=%u selected_eof=%u "
                         "committed=%llu\n",
                         marker != provisional_.end() ? 1u : 0u, value.eof ? 1u : 0u,
                         value.tailPublished ? 1u : 0u,
                         unsigned(std::count_if(selected_.begin(), selected_.end(),
                                                [](const auto& e) { return e.second.eof; })),
                         (unsigned long long)value.committed);
        if (marker != provisional_.end()) {
            // No16AEA0 admission belongs to171920's literal sequence-end copy.
            // Its real return171978 and171984 partial=capacity publication are
            // the authentic post-copy/counter event which releases this marker.
            auto& stage = marker->second;
            const auto bytes = uint32_t(stage.copy.bytes.size());
            if (bytes != 16 || stage.copy.offset != value.committed ||
                read64(ram, ring + 0x48) != value.committed + bytes ||
                read32(ram, ring + 0x14) != value.capacity || read32(ram, ring + 0x10))
                throw std::runtime_error(
                    "Original EOF marker lacks its genuine post-copy/control return");
            for (uint32_t i = 0; i < bytes; ++i) {
                const auto at = (stage.start + i) % value.capacity;
                if (ram[value.base + at] != stage.copy.bytes[i])
                    throw std::runtime_error(
                        "Original EOF marker storage changed before publication");
                value.elementary[at] = value.committed + i;
                value.valid[at] = 1;
            }
            value.committed += bytes;
            value.pendingBytes += bytes;
            value.events.emplace_back(std::move(stage.copy));
            value.markerLapBytes = stage.markerLapBytes;
            value.eof = true;
            value.events.emplace_back(Eof{});
            provisional_.erase(marker);
        }
        const auto read = read32(ram, ring + 0xc);
        if (!value.eof || value.tailPublished || !value.markerLapBytes ||
            value.markerLapBytes > value.capacity || read32(ram, ring + 0x14) != value.capacity ||
            read32(ram, ring + 0x10) || read >= value.capacity / 2048 ||
            read64(ram, ring + 0x48) != value.committed)
            throw std::runtime_error(
                "Original EOF full-ring publication has no exact marker/control lineage");
        const uint32_t padding = value.capacity - value.markerLapBytes,
                       start = (read * 2048 + value.markerLapBytes) % value.capacity;
        if (value.pendingBytes + padding > 2 * 1024 * 1024)
            throw std::runtime_error("Original EOF transport ownership bound");
        Tail event;
        event.offset = value.committed;
        event.bytes.resize(padding);
        for (uint32_t i = 0; i < padding; ++i) {
            const uint32_t at = (start + i) % value.capacity;
            event.bytes[i] = ram[value.base + at];
            value.elementary[at] = value.committed + i;
            value.valid[at] = 1;
        }
        if (padding) {
            value.events.emplace_back(std::move(event));
            value.pendingBytes += padding;
        }
        value.tailPublished = true;
        flush(ring, value);
    }
    void bind(const uint8_t* ram, uint64_t generation, uint32_t sofdec, uint32_t work, void* owner,
              Timestamp timestamp, Committed copied, End end, TransportTail tail) {
        sofdec = canonical(sofdec);
        work = canonical(work);
        const auto ring = work + 0xa48;
        if (!generation || !owner || !timestamp || !copied || !end || !tail ||
            canonical(read32(ram, sofdec + 0x1b30)) != work)
            throw std::invalid_argument("Missing actual original movie lifetime");
        std::lock_guard<std::mutex> lock(mutex_);
        if (generation_ || !rings_.count(ring))
            throw std::logic_error(
                "Movie native binding requires observed original initialization");
        generation_ = generation;
        ring_ = ring;
        sofdec_ = sofdec;
        work_ = work;
        timestampOwner_ = owner;
        timestamp_ = timestamp;
        copied_ = copied;
        end_ = end;
        tail_ = tail;
        flush(ring, rings_.at(ring));
    }
    bool resolve(uint64_t generation, uint32_t source, uint32_t bytes, uint64_t& offset) const {
        uint32_t at = 0;
        if (!bytes || (bytes & 15) || !physical(source, bytes, at))
            return false;
        std::lock_guard<std::mutex> lock(mutex_);
        if (!generation_ || generation != generation_)
            return false;
        const auto found = rings_.find(ring_);
        if (found == rings_.end())
            return false;
        const auto& value = found->second;
        if (at < value.base || bytes > value.capacity || at - value.base > value.capacity - bytes)
            return false;
        // IPU DMA prefetch continuing past the stream end (see straddle below): stale ring bytes in ring order.
        if (pastEndAt_ && at == pastEndAt_ && value.committed == pastEndCommitted_) {
            offset = pastEndOffset_;
            pastEndOffset_ += bytes;
            pastEndAt_ = at + bytes >= value.base + value.capacity ? value.base : at + bytes;
            return true;
        }
        const auto start = at - value.base;
        if (!value.valid[start])
            return false;
        const auto first = value.elementary[start];
        for (uint32_t i = 1; i < bytes; ++i)
            if (!value.valid[start + i] || value.elementary[start + i] != first + i) {
                // Real DMA moves whole quadwords: the final ES byte need not be 16-aligned. Accept a quadword whose valid
                // prefix ends exactly at the current committed end (rest = ring bytes past the stream, never ES data).
                if (first + i != value.committed)
                    return false;
                for (uint32_t j = i; j < bytes; ++j)
                    if (value.valid[start + j] && value.elementary[start + j] == first + j)
                        return false;
                pastEndCommitted_ = value.committed;
                pastEndOffset_ = first + bytes;
                pastEndAt_ = at + bytes >= value.base + value.capacity ? value.base : at + bytes;
                break;
            }
        offset = first;
        return true;
    }
    void unbind(uint64_t generation) {
        std::lock_guard<std::mutex> lock(mutex_);
        if (generation != generation_)
            throw std::invalid_argument("Stale movie transport detach");
        generation_ = 0;
        ring_ = sofdec_ = work_ = 0;
        timestamp_ = nullptr;
        copied_ = nullptr;
        end_ = nullptr;
        tail_ = nullptr;
        timestampOwner_ = nullptr;
        pastEndAt_ = 0;
        pastEndOffset_ = pastEndCommitted_ = 0;
    }
};
} // namespace reo_gpu_movie
