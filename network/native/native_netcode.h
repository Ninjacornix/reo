// SPDX-License-Identifier: GPL-3.0-only
#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <deque>
#include <map>
#include <memory>
#include <mutex>
#include <string>
#include <vector>
#include "world_sync.h"

namespace reo_network::native {
constexpr uint32_t Batch = 1, MotionStream = 2, CriticalEvents = 4, WorldChecks = 8;
constexpr size_t WireHeader = 32, MaxPacket = 1200;
enum class Mode : uint32_t { Legacy, Ready, Enhanced };
struct Motion {
    uint8_t slot = 0;
    uint16_t room = 0, yaw = 0;
    std::array<float, 3> xyz{};
};
struct Status {
    uint32_t session = 0, room = 0, epoch = 0, features = 0;
    Mode mode = Mode::Legacy;
    std::array<uint32_t, 4> members{};
    uint64_t received = 0;
};
uint64_t nowUs();
// Thread boundary only contains value objects. Guest RAM is touched by the guest
// owner through the game adapter, never by the RPC/transport worker.
class State {
  public:
    void reset();
    void status(const Status& value);
    Status status() const;
    bool enhanced(uint64_t now) const;
    void local(const Motion* value, uint64_t now = nowUs());
    bool local(Motion& value, uint64_t now) const;
    bool receive(uint32_t source, uint32_t sequence, uint64_t sent, uint64_t now, const Motion& value);
    bool target(uint8_t slot, uint16_t room, uint64_t now, Motion& value) const;
    double jitterMs() const;
    double bufferMs() const;
    void promoted();
    uint64_t promotedCount() const;
    void worldLocal(const WorldDigest* value,uint64_t now);
    bool worldLocal(WorldDigest& value,uint64_t now) const;
    bool worldReceive(uint32_t source,uint32_t sequence,const WorldDigest& value,uint64_t now);
    bool worldOutgoingRequest(uint16_t& room,uint8_t& authority);
    void worldIncomingRequest(uint32_t source,uint16_t room,uint8_t authority,uint64_t now);
    bool worldPendingRequest(uint16_t& room,uint8_t& authority);
    void worldStats(const WorldStats& stats);
  private:
    struct Sample { Motion motion; uint64_t sent, arrived; };
    struct Track {
        uint32_t source = 0, sequence = 0;
        bool numbered = false;
        std::deque<Sample> samples;
        double offset = 0, jitter = 0;
    };
    mutable std::mutex mutex_;
    Status status_{};
    Motion local_{};
    bool validLocal_ = false;
    uint64_t localAt_ = 0;
    uint64_t promoted_ = 0;
    WorldDigest world_{};
    WorldStats worldStats_{};
    bool worldValid_=false, worldRequest_=false;
    uint64_t worldAt_=0, worldRequestAt_=0, worldMismatches_=0, worldRequests_=0;
    struct WorldPeer { uint32_t sequence=0; bool numbered=false; unsigned differences=0; };
    std::array<WorldPeer,4> worldPeers_{};
    std::deque<std::pair<uint16_t,uint8_t>> worldPending_;
    friend class Channel;
    std::array<Track, 4> tracks_{};
};
State& runtime();
std::shared_ptr<State> sharedRuntime();
uint64_t nowUs();

// Stateless wire helpers are shared with the socket fixture and impairment tests.
std::vector<uint8_t> encode(uint8_t kind, uint32_t sid, uint32_t room, uint32_t epoch,
                            uint32_t sequence, uint64_t stamp, const std::vector<uint8_t>& body = {});
class Channel {
  public:
    explicit Channel(State& state, uint64_t nonce);
    void reset();
    void observeSend(const uint8_t* bytes, size_t length, uint64_t now);
    void observeReceive(const uint8_t* bytes, size_t length, uint64_t now);
    bool consume(const uint8_t* bytes, size_t length, uint64_t now);
    std::vector<std::vector<uint8_t>> poll(uint64_t now);
    std::string metrics(uint64_t now) const;
    bool bound() const { return session_ != 0; }
    bool waiting() const { return loginPending_; }
    uint32_t session() const { return session_; }
  private:
    State& state_;
    uint64_t nonce_, helloAt_ = 0, motionAt_ = 0, worldAt_ = 0;
    uint32_t session_ = 0, sequence_ = 0, statusSequence_ = 0;
    bool statusNumbered_ = false;
    bool loginPending_ = false;
    unsigned attempts_ = 0;
    double rtt_ = 0;
    uint64_t sent_ = 0, received_ = 0, stale_ = 0, retries_ = 0;
    uint64_t worldSent_=0, worldReceived_=0;
    struct Pending { uint64_t first, last; bool retried; };
    std::map<uint32_t, Pending> pending_;
};
} // namespace reo_network::native
