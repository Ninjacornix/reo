#pragma once
#include "reo_movie_game_addresses.h"
// Source-jointed original continuation observer. No decoded picture is read,
// no guest register/memory is changed and no instant completion is invented.
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <algorithm>
#include <array>
#include <chrono>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <filesystem>
#include <fstream>
#include <mutex>

void reo_movie_join_observed_caller(uint8_t*, R5900Context*, PS2Runtime*);
void reo_movie_commit_observed(uint8_t*, R5900Context*, PS2Runtime*);
void reo_movie_initialize_observed(uint8_t*, R5900Context*, PS2Runtime*);
namespace reo_movie_join {
using Function = void (*)(uint8_t*, R5900Context*, PS2Runtime*);
constexpr uint32_t RamBytes = 0x2000000u, MaxRequests = 128, MaxCommits = 256,
                   MaxTransport = 8u * 1024u * 1024u;
inline constexpr std::array<uint32_t, 5> CommitAliases{REO_MA(0x170D90), REO_MA(0x170DB0), REO_MA(0x170E00), REO_MA(0x170E20),
                                                       REO_MA(0x170E48)};
inline constexpr std::array<uint32_t, 3> InitializeAliases{REO_MA(0x170AE8), REO_MA(0x170B3C), REO_MA(0x170B48)};
inline constexpr std::array<uint32_t, 9> CallerAliases{
    REO_MA(0x171D10), REO_MA(0x171D4C), REO_MA(0x171D90), REO_MA(0x171DA8), REO_MA(0x171DB0), REO_MA(0x171DFC), REO_MA(0x171E10), REO_MA(0x171E1C), REO_MA(0x171E24)};
inline bool resolve(uint32_t address, uint32_t size, uint32_t& physical) {
    const uint32_t bank = address & 0xFE000000u;
    if (bank != 0 && bank != 0x20000000u && bank != 0x80000000u && bank != 0xA0000000u)
        return false;
    physical = address & 0x1FFFFFFu;
    return size <= RamBytes && physical <= RamBytes - size;
}
inline bool valid(uint32_t p, uint32_t size) {
    uint32_t physical = 0;
    return resolve(p, size, physical) && physical != 0;
}
inline uint32_t read(const uint8_t* ram, uint32_t address) {
    uint32_t at = 0, value = 0;
    if (ram && resolve(address, 4, at))
        std::memcpy(&value, ram + at, 4);
    return value;
}
inline uint64_t read64(const uint8_t* ram, uint32_t address) {
    uint32_t at = 0;
    uint64_t value = 0;
    if (ram && resolve(address, 8, at))
        std::memcpy(&value, ram + at, 8);
    return value;
}
inline bool sameAddress(uint32_t a, uint32_t b) {
    uint32_t aa = 0, bb = 0;
    return resolve(a, 4, aa) && resolve(b, 4, bb) && aa == bb;
}
inline uint64_t nowNs() {
    return uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(
                        std::chrono::steady_clock::now().time_since_epoch())
                        .count());
}
struct Request {
    PS2Runtime* runtime = nullptr;
    R5900Context* context = nullptr;
    uint32_t index = 0, episode = 0xffffffffu, stack = 0, sofdec = 0, work = 0, outer = 0,
             inner = 0, descriptor = 0, destination = 0;
    uint32_t width = 0, height = 0, macroblocks = 0, returnPC = 0, mode = 0, counterBefore = 0,
             counterAfter = 0, result = 0;
    uint32_t innerRequestMode = 0, innerDestination = 0, innerMacroblocks = 0, busyBefore = 0,
             busyAtReturn = 0;
    uint64_t issueNs = 0, returnNs = 0, transportBytesAtIssue = 0;
    std::array<uint32_t, 4> issueClockWords{}, returnClockWords{};
    std::array<uint32_t, 9> descriptorWords{};
    bool active = false, completed = false, pointersSupported = false, dimensionsSupported = false;
};
struct Capture {
    std::mutex mutex;
    bool enabled = false;
    std::array<Request, MaxRequests> requests{};
    std::array<uint32_t, 4> episodeRequests{};
    uint32_t unknownEpisodeRequests = 0;
    uint32_t count = 0, commits = 0, rejectedPointers = 0, unmatchedReturns = 0,
             transportEpisodes = 0;
    uint32_t ring = 0, episode = 0, transportBytes = 0;
    uint64_t expectedCommitted = 0;
    bool transportGapped = false;
    std::filesystem::path directory;
    std::ofstream metadata, compressed;
    Function originalCommit = nullptr, originalInitialize = nullptr;
};
inline Capture capture;
inline void logRequest(const char* kind, const Request& r) {
    auto& s = capture;
    if (!s.metadata)
        return;
    s.metadata << "{\"kind\":\"" << kind << "\",\"index\":" << r.index
               << ",\"episode\":" << r.episode << ",\"stack\":" << r.stack
               << ",\"sofdec\":" << r.sofdec << ",\"work\":" << r.work << ",\"outer\":" << r.outer
               << ",\"inner\":" << r.inner << ",\"descriptor\":" << r.descriptor
               << ",\"destination\":" << r.destination << ",\"width\":" << r.width
               << ",\"height\":" << r.height << ",\"macroblocks\":" << r.macroblocks
               << ",\"mode\":" << r.mode << ",\"return_PC\":" << r.returnPC
               << ",\"issue_ns\":" << r.issueNs << ",\"return_ns\":" << r.returnNs
               << ",\"picture_counter_before\":" << r.counterBefore
               << ",\"picture_counter_after\":" << r.counterAfter << ",\"result\":" << r.result
               << ",\"inner_request_mode\":" << r.innerRequestMode
               << ",\"inner_destination\":" << r.innerDestination
               << ",\"inner_macroblocks\":" << r.innerMacroblocks
               << ",\"busy_before\":" << r.busyBefore
               << ",\"busy_at_real_return\":" << r.busyAtReturn
               << ",\"transport_committed_bytes_at_issue\":" << r.transportBytesAtIssue
               << ",\"pointers_supported\":" << (r.pointersSupported ? "true" : "false")
               << ",\"dimensions_supported\":" << (r.dimensionsSupported ? "true" : "false")
               << ",\"PTS_known\":false,\"decoded_pixels_read\":false,\"guest_writes\":false}\n";
    s.metadata.flush();
    s.metadata << "{\"kind\":\"request_raw_clock_descriptor\",\"index\":" << r.index
               << ",\"at_real_return\":" << (r.completed ? "true" : "false")
               << ",\"Sofdec_F00_F04_F08_F0C_words\":[";
    const auto& words = r.completed ? r.returnClockWords : r.issueClockWords;
    for (unsigned i = 0; i < 4; ++i) {
        if (i)
            s.metadata << ',';
        s.metadata << words[i];
    }
    s.metadata << "],\"descriptor_00_through_20_words\":[";
    for (unsigned i = 0; i < 9; ++i) {
        if (i)
            s.metadata << ',';
        s.metadata << r.descriptorWords[i];
    }
    s.metadata << "],\"clock_units_or_PTS_mapping_claimed\":false}\n";
    s.metadata.flush();
}
// Injected after the original171DF8/171E0C delay slot, immediately before the
// original147D30/147D78 call. All request arguments are now genuine/complete.
inline void issued(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, uint32_t returnPC) {
    auto& s = capture;
    if (!s.enabled)
        return;
    std::lock_guard<std::mutex> lock(s.mutex);
    if (s.count >= MaxRequests)
        return;
    Request r;
    const auto work = GPR_U32(ctx, 18);
    if (valid(work, 0xAA0) && s.ring && sameAddress(work + 0xA48, s.ring)) {
        if (s.episode >= s.episodeRequests.size() || s.episodeRequests[s.episode] >= 32)
            return;
        r.episode = s.episode;
        ++s.episodeRequests[s.episode];
    } else {
        if (s.unknownEpisodeRequests >= 8)
            return;
        ++s.unknownEpisodeRequests;
    }
    r.index = s.count++;
    r.runtime = runtime;
    r.context = ctx;
    r.stack = GPR_U32(ctx, 29);
    r.sofdec = GPR_U32(ctx, 21);
    r.work = GPR_U32(ctx, 18);
    r.descriptor = GPR_U32(ctx, 20);
    r.outer = GPR_U32(ctx, 4);
    r.destination = GPR_U32(ctx, 5);
    r.macroblocks = GPR_U32(ctx, 6);
    r.returnPC = returnPC;
    r.issueNs = nowNs();
    r.active = true;
    r.pointersSupported = valid(r.sofdec, 0x1B34) && valid(r.work, 0xAA0) && valid(r.outer, 0x44) &&
                          valid(r.descriptor, 0x24) &&
                          sameAddress(read(ram, r.sofdec + 0x1B30), r.work) &&
                          sameAddress(r.outer, r.work + 0xA00);
    if (r.pointersSupported) {
        r.width = read(ram, r.work + 0xC);
        r.height = read(ram, r.work + 0x10);
        r.mode = read(ram, r.sofdec + 0x38);
        r.inner = read(ram, r.outer + 0x40);
        r.pointersSupported =
            valid(r.inner, 0x10A4) && sameAddress(read(ram, r.descriptor + 0x20), r.destination);
        r.dimensionsSupported = r.width && r.height && r.width <= 1920 && r.height <= 1088 &&
                                !(r.width & 1) && !(r.height & 1);
        r.busyBefore = read(ram, r.work + 0x9EC);
        for (unsigned i = 0; i < 4; ++i)
            r.issueClockWords[i] = read(ram, r.sofdec + 0xF00 + 4 * i);
        for (unsigned i = 0; i < 9; ++i)
            r.descriptorWords[i] = read(ram, r.descriptor + 4 * i);
        r.transportBytesAtIssue = read64(ram, r.work + 0xA48 + 0x48);
        if (valid(r.inner, 0x10A4))
            r.counterBefore = read(ram, r.inner + 0x130);
    }
    if (!r.pointersSupported)
        ++s.rejectedPointers;
    for (auto& old : s.requests)
        if (old.active && old.runtime == runtime && old.context == ctx && old.stack == r.stack) {
            old.active = false;
            logRequest("superseded_uncompleted", old);
        }
    s.requests[r.index] = r;
    logRequest("request", r);
}
// Injected immediately after the actual171DFC/171E10 label. This covers both
// synchronous nested returns and real scheduled generated-function resumptions.
// It runs BEFORE original code clears work+9EC or saves IPU state.
inline void returned(const uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime, uint32_t pc) {
    auto& s = capture;
    if (!s.enabled)
        return;
    std::lock_guard<std::mutex> lock(s.mutex);
    Request* found = nullptr;
    for (auto& r : s.requests)
        if (r.active && r.runtime == runtime && r.context == ctx && r.stack == GPR_U32(ctx, 29) &&
            r.returnPC == pc && sameAddress(r.sofdec, GPR_U32(ctx, 21)) &&
            sameAddress(r.work, GPR_U32(ctx, 18)) && sameAddress(r.descriptor, GPR_U32(ctx, 20))) {
            found = &r;
            break;
        }
    if (!found) {
        ++s.unmatchedReturns;
        return;
    }
    auto& r = *found;
    r.active = false;
    r.completed = true;
    r.returnNs = nowNs();
    r.result = GPR_U32(ctx, 2);
    if (r.pointersSupported) {
        r.counterAfter = read(ram, r.inner + 0x130);
        r.innerRequestMode = read(ram, r.inner + 0xC8);
        r.innerDestination = read(ram, r.inner + 0xF0);
        r.innerMacroblocks = read(ram, r.inner + 0xFC);
        r.busyAtReturn = read(ram, r.work + 0x9EC);
        for (unsigned i = 0; i < 4; ++i)
            r.returnClockWords[i] = read(ram, r.sofdec + 0xF00 + 4 * i);
    }
    logRequest("real_picture_return", r);
}
// This site follows the actual zeroing of ring+48, including a yielded init
// continuation. Each episode starts at a proven source offset zero.
inline void initialized(const uint8_t* ram, R5900Context*, PS2Runtime*, uint32_t ring) {
    auto& s = capture;
    if (!s.enabled)
        return;
    std::lock_guard<std::mutex> lock(s.mutex);
    if (s.compressed.is_open())
        s.compressed.close();
    s.transportGapped = true;
    s.ring = 0;
    if (!valid(ring, 0x58) || s.transportEpisodes >= 4)
        return;
    s.ring = ring;
    s.episode = s.transportEpisodes++;
    s.transportBytes = 0;
    s.expectedCommitted = 0;
    const auto file = s.directory / ("compressed-ring-" + std::to_string(s.episode) + ".bin");
    s.compressed.open(file, std::ios::binary | std::ios::out);
    s.transportGapped = !s.compressed;
    if (s.metadata) {
        s.metadata << "{\"kind\":\"ring_initialized\",\"episode\":" << s.episode
                   << ",\"ring\":" << ring << ",\"base\":" << read(ram, ring)
                   << ",\"capacity_bytes\":" << read(ram, ring + 0x18)
                   << ",\"source_offset\":0,\"hook_after_original_counter_zero\":true,\"guest_"
                      "writes\":false}\n";
        s.metadata.flush();
    }
}
// Source-preserving170D90 hook after original114660 semaphore acquisition,
// before the original SW/SD bookkeeping. A0/A1 have already changed, so use
// the original saved S0 ring and S1 byte count. This also handles real yields.
inline void commitBytes(const uint8_t* ram, R5900Context*, PS2Runtime*, uint32_t ring,
                        uint32_t bytes) {
    auto& s = capture;
    if (!s.enabled)
        return;
    std::lock_guard<std::mutex> lock(s.mutex);
    if (s.commits >= MaxCommits) {
        s.transportGapped = true;
        return;
    }
    const bool supported = valid(ring, 0x58);
    const auto base = supported ? read(ram, ring) : 0, chunks = supported ? read(ram, ring + 8) : 0;
    const auto capacity = supported ? read(ram, ring + 0x18) : 0;
    const auto readChunks = supported ? read(ram, ring + 0xC) : 0,
               pendingChunks = supported ? read(ram, ring + 0x10) : 0;
    const auto partial = supported ? read(ram, ring + 0x14) : 0;
    const auto committed = supported ? read64(ram, ring + 0x48) : 0;
    const bool validRing = ram && supported && chunks && chunks <= 512 &&
                           capacity == uint64_t(chunks) * 2048 && readChunks < chunks &&
                           pendingChunks <= chunks && partial <= capacity && bytes <= capacity &&
                           valid(base, capacity);
    // Signed/width/geometry math is not involved: this is the original transport
    // ring cursor expression, independently present in170CA0.
    const uint32_t offset =
        validRing ? uint32_t(((uint64_t(readChunks) + pendingChunks) * 2048 + partial) % capacity)
                  : 0;
    const bool sameRing = s.ring && sameAddress(ring, s.ring);
    const bool sourceContinuous = committed == s.expectedCommitted;
    const uint32_t archiveOffset = s.transportBytes;
    uint32_t physical = 0;
    const bool append = validRing && sameRing && !s.transportGapped && sourceContinuous &&
                        s.compressed && s.transportBytes <= MaxTransport &&
                        bytes <= MaxTransport - s.transportBytes &&
                        resolve(base, capacity, physical);
    uint32_t capturedBytes = 0;
    if (append) {
        const uint32_t first = std::min(bytes, capacity - offset);
        s.compressed.write(reinterpret_cast<const char*>(ram + physical + offset), first);
        if (bytes > first)
            s.compressed.write(reinterpret_cast<const char*>(ram + physical), bytes - first);
        s.compressed.flush();
        if (s.compressed) {
            capturedBytes = bytes;
            s.transportBytes += bytes;
            s.expectedCommitted += bytes;
        }
    }
    // Never concatenate later bytes across a refused/truncated source interval.
    // A different ring cannot taint the active ring's previously captured data.
    if (sameRing && capturedBytes != bytes)
        s.transportGapped = true;
    if (s.metadata) {
        s.metadata << "{\"kind\":\"compressed_commit_locked\",\"n\":" << s.commits++
                   << ",\"episode\":" << s.episode << ",\"ring\":" << ring << ",\"base\":" << base
                   << ",\"capacity_bytes\":" << capacity << ",\"write_offset\":" << offset
                   << ",\"committed_before\":" << committed << ",\"new_bytes_argument\":" << bytes
                   << ",\"captured_bytes\":" << capturedBytes
                   << ",\"archive_offset\":" << archiveOffset
                   << ",\"archive_contiguous\":" << (!s.transportGapped ? "true" : "false")
                   << ",\"valid_ring\":" << (validRing ? "true" : "false")
                   << ",\"source_continuous\":" << (sourceContinuous ? "true" : "false")
                   << ",\"picture_boundary_claim\":false,\"PTS_known\":false,\"decoded_pixels_"
                      "read\":false,\"guest_writes\":false}\n";
        s.metadata.flush();
    } else
        ++s.commits;
}
// Literal-delegate fixture helpers only. Production binds source-preserving
// whole originals below, so it never observes the bytes before acquisition.
inline void initializeRing(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    auto& s = capture;
    const auto original = s.originalInitialize;
    if (!original)
        std::terminate();
    const auto ring = GPR_U32(ctx, 4);
    original(ram, ctx, runtime);
    initialized(ram, ctx, runtime, ring);
}
inline void commitRing(uint8_t* ram, R5900Context* ctx, PS2Runtime* runtime) {
    auto& s = capture;
    const auto original = s.originalCommit;
    if (!original)
        std::terminate();
    if (ctx->pc == REO_MA(0x170D90))
        commitBytes(ram, ctx, runtime, GPR_U32(ctx, 4), GPR_U32(ctx, 5));
    original(ram, ctx, runtime);
}
inline bool install(PS2Runtime& runtime) {
    const char* destination = std::getenv("REO_GPU_MOVIE_JOIN_DIR");
    if (!destination || !*destination || capture.enabled)
        return false;
    auto& s = capture;
    const auto original = runtime.lookupFunction(CallerAliases[0]);
    if (!original || original == reo_movie_join_observed_caller)
        return false;
    for (auto pc : CallerAliases)
        if (runtime.lookupFunction(pc) != original)
            return false;
    const auto commit = runtime.lookupFunction(REO_MA(0x170D90)),
               initialize = runtime.lookupFunction(REO_MA(0x170AE8));
    if (!commit || !initialize || commit == reo_movie_commit_observed ||
        initialize == reo_movie_initialize_observed)
        return false;
    for (auto pc : CommitAliases)
        if (runtime.lookupFunction(pc) != commit)
            return false;
    for (auto pc : InitializeAliases)
        if (runtime.lookupFunction(pc) != initialize)
            return false;
    const std::filesystem::path directory(destination);
    if (std::filesystem::exists(directory) || !std::filesystem::create_directories(directory))
        return false;
    s.directory = directory;
    s.metadata.open(directory / "movie-join.jsonl", std::ios::out);
    if (!s.metadata)
        return false;
    s.originalCommit = commit;
    s.originalInitialize = initialize;
    s.enabled = true;
    for (auto pc : CallerAliases)
        runtime.registerFunction(pc, reo_movie_join_observed_caller);
    for (auto pc : CommitAliases)
        runtime.registerFunction(pc, reo_movie_commit_observed);
    for (auto pc : InitializeAliases)
        runtime.registerFunction(pc, reo_movie_initialize_observed);
    std::fprintf(stderr,
                 "[GPU-MOVIE-JOIN] enabled source-preserving caller continuations32 per "
                 "episode/128 total, compressed commits256/8MiB; readonly; no replacement\n");
    return true;
}
} // namespace reo_movie_join
