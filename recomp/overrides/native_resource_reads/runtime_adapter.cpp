#include "runtime_adapter.h"

#if defined(_WIN32) && defined(REO_GAME_FILE1) && \
    defined(REO_BUILD_NATIVE_RESOURCE_READS) && REO_BUILD_NATIVE_RESOURCE_READS

#include "ps2_runtime.h"
#include "reo_hw_bridge.h"
#include "game/native/resources_windows/mounted_reader.hpp"
#include "../native_geometry/reo_vu_native_sha256.h"

#include <atomic>
#include <chrono>
#include <condition_variable>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <exception>
#include <limits>
#include <memory>
#include <mutex>
#include <optional>
#include <string>

#if !defined(PS2_RUNTIME_HAS_EXTERNAL_WORKERS) || !PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error Native resource reads require the matching public external-worker runtime patch
#endif

// This is the current thread's actual scope depth, not a synthetic context flag.
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;

namespace reo_native_resource_reads {
namespace {
namespace native = reo::native::resources::win32;
constexpr std::uint32_t packet = 0x207A00, client = 0x208AD0, end_block = 0x208A00;
constexpr std::size_t max_read_bytes = 8u * 1024u * 1024u;

std::uint64_t slow_threshold_ns() noexcept {
    const char* text=std::getenv("REO_CRI_SERVER_SLOW_MS");
    if(!text || !*text || *text=='-')return 0;
    char* end=nullptr;const auto value=std::strtoull(text,&end,10);
    return end && !*end && value && value<=60000 ? value*1000000u : 0;
}
std::uint64_t now_ns() noexcept {
    return static_cast<std::uint64_t>(std::chrono::duration_cast<std::chrono::nanoseconds>(
        std::chrono::steady_clock::now().time_since_epoch()).count());
}

std::uint32_t word(const std::uint8_t* memory, std::uint32_t address) noexcept {
    std::uint32_t result;
    std::memcpy(&result, memory + address, sizeof(result));
    return result;
}
constexpr reo_native_image_identity::Digest digest(const char (&hex)[65]) {
    reo_native_image_identity::Digest result{};
    const auto nibble = [](char c) { return c <= '9' ? c - '0' : c - 'a' + 10; };
    for (std::size_t i = 0; i < result.size(); ++i)
        result[i] = static_cast<std::uint8_t>((nibble(hex[2 * i]) << 4) | nibble(hex[2 * i + 1]));
    return result;
}
bool identity(const char* serial, const std::uint8_t* memory, std::size_t bytes) noexcept {
    return serial && !std::strcmp(serial, "SLUS-20765") && memory && bytes == PS2_RAM_SIZE &&
        reo_native_image_identity::sha256(memory + 0x101788, 0x1E0) ==
            digest("c520c3c1af9405a9b73a60c397b7ed6196d34ad5d54559371b74aed5be6d1baa") &&
        reo_native_image_identity::sha256(memory + 0x1004D8, 0xB8) ==
            digest("6126b560a34e355058f3b6426a7ef310855bb5aef6cd5922a852bc9628b75e47") &&
        reo_native_image_identity::sha256(memory + 0x100298, 0xA0) ==
            digest("b1a65fc9ecc2500db7dc938d41b512ab3eb727b2a06748e71d8edee262455fcf");
}
bool flag(const char* name, const char* expected) noexcept {
    const auto* value = std::getenv(name);
    return value && !std::strcmp(value, expected);
}
std::string hex(const native::Digest& value) {
    static constexpr char digits[] = "0123456789abcdef";
    std::string result(value.size() * 2, '0');
    for (std::size_t i = 0; i < value.size(); ++i) {
        result[2 * i] = digits[value[i] >> 4];
        result[2 * i + 1] = digits[value[i] & 15];
    }
    return result;
}

class Session;
thread_local const Session* reading_session = nullptr;

class Session final : public PS2Runtime::ExternalWorker {
public:
    Session(PS2Runtime& owner, std::uint8_t* memory, std::shared_ptr<native::MountedReader> source)
        : runtime(owner), ram(memory), reader(std::move(source)) {}
    void requestStop() noexcept override { stopping.store(true, std::memory_order_release); }
    bool join() noexcept override {
        if (reading_session == this) return false; // Check before any mutex/wait.
        requestStop();
        try {
            std::unique_lock lock(mutex);
            idle.wait(lock, [&] { return in_flight == 0; });
            return true;
        } catch (...) { return false; }
    }
    bool enter() noexcept {
        if (reading_session == this) return false; // No nested provider/RPC reentry.
        std::lock_guard lock(mutex);
        if (stopping.load(std::memory_order_acquire) || runtime.isStopRequested() ||
            in_flight == std::numeric_limits<std::size_t>::max()) return false;
        ++in_flight;
        return true;
    }
    void leave() noexcept {
        std::lock_guard lock(mutex);
        --in_flight;
        if (!in_flight) idle.notify_all();
    }
    PS2Runtime& runtime;
    std::uint8_t* const ram;
    const std::shared_ptr<native::MountedReader> reader;
    const std::uint64_t slow_ns=slow_threshold_ns();
    std::atomic<unsigned> slow_reports{0};
    std::atomic<bool> stopping{false};
    std::atomic<std::uint64_t> successes{0}, failures{0};
private:
    std::mutex mutex;
    std::condition_variable idle;
    std::size_t in_flight{};
};

struct ReadLease {
    Session& session;
    const Session* previous = reading_session;
    explicit ReadLease(Session& owner) noexcept : session(owner) { reading_session = &session; }
    ~ReadLease() { reading_session = previous; session.leave(); }
};

std::mutex registry_mutex;
std::weak_ptr<Session> active;
std::shared_ptr<Session> load_active() {
    std::lock_guard lock(registry_mutex);
    return active.lock();
}

bool overlaps(std::uint32_t address, std::uint64_t bytes,
              std::uint32_t begin, std::uint32_t end) noexcept {
    return address < end && std::uint64_t(address) + bytes > begin;
}
bool safe_destination(std::uint32_t destination, std::uint64_t bytes) noexcept {
    if (!destination || destination % 64 || destination >= PS2_RAM_SIZE || bytes > PS2_RAM_SIZE - destination)
        return false;
    // Protected packet/client/end metadata and the three individually pinned
    // text ranges. The request-control span conservatively includes SRD's
    // singleton, DVCI's forty 0x48-byte records and its mode/verbosity words.
    constexpr std::uint32_t ranges[][2] = {
        {packet, packet + 0x18}, {client, client + 0x28}, {end_block, end_block + 0x90},
        {0x101788, 0x101968}, {0x1004D8, 0x100590}, {0x100298, 0x100338},
        {0x21BB88, 0x21D8EC},
    };
    for (const auto& range : ranges)
        if (overlaps(destination, bytes, range[0], range[1])) return false;
    return true;
}
} // namespace

void configure(const char* serial, std::uint8_t* ram, std::size_t bytes,
               PS2Runtime& runtime, const std::filesystem::path& data_root) noexcept {
    if (!flag("REO_NATIVE_RESOURCE_READS", "1") || !flag("REO_GAME_PAK", "1") || !flag("REO_CD_ASYNC", "0"))
        return;
    if (!identity(serial, ram, bytes) || runtime.memory().getRDRAM() != ram || runtime.isStopRequested()) return;
    try {
        if (const auto current = load_active()) {
            if (&current->runtime != &runtime || current->ram != ram)
                std::fprintf(stderr, "[NATIVE-RESOURCE-READS] another runtime owns the configured reader; legacy retained\n");
            return;
        }
        std::optional<std::filesystem::path> overlay;
        if (const auto* value = _wgetenv(L"REO_ASSET_OVERLAY"); value && *value) overlay.emplace(value);
        auto opened = native::MountedReader::open_file1_windows(data_root, overlay, max_read_bytes);
        if (opened.status != native::MountStatus::ok || !opened.reader) {
            std::fprintf(stderr, "[NATIVE-RESOURCE-READS] mount unavailable status=%u system=%u detail=%s; legacy retained\n",
                         static_cast<unsigned>(opened.status), opened.system_error, opened.detail.c_str());
            return;
        }
        auto* bridge = ReoHwBridge::instance();
        if (!bridge || !bridge->nativeResourceLayoutMatches(opened.reader->mount())) {
            std::fprintf(stderr, "[NATIVE-RESOURCE-READS] legacy facade layout identity mismatch; legacy retained\n");
            return;
        }
        // Formatting/allocation is completed before lifecycle registration.
        const auto& actual = opened.reader->identity();
        const auto route = hex(actual.route_sha256), manifest = hex(actual.manifest_sha256);
        const auto overlay_hash = actual.overlay_plan_sha256 ? hex(*actual.overlay_plan_sha256) : std::string("none");
        auto session = std::make_shared<Session>(runtime, ram, std::move(opened.reader));
        bool registered = false, occupied = false;
        {
            std::lock_guard lock(registry_mutex);
            occupied = !active.expired();
            if (!occupied && runtime.registerExternalWorker(session)) {
                active = session;
                registered = true;
            }
        }
        if (!registered) {
            session->requestStop();
            if (!session->join()) std::terminate();
            std::fprintf(stderr, "[NATIVE-RESOURCE-READS] %s; legacy retained\n",
                         occupied ? "another setup won registration" : "runtime registration refused");
            return;
        }
        std::fprintf(stderr, "[NATIVE-RESOURCE-READS] mounted import=%u sources=%zu route=%s manifest=%s overlay=%s mode=synchronous-exact maxBytes=%zu\n",
                     actual.import_version, actual.sources.size(), route.c_str(), manifest.c_str(), overlay_hash.c_str(), max_read_bytes);
    } catch (const std::exception& error) {
        std::fprintf(stderr, "[NATIVE-RESOURCE-READS] setup unavailable: %s; legacy retained\n", error.what());
    } catch (...) {
        std::fprintf(stderr, "[NATIVE-RESOURCE-READS] setup unavailable; legacy retained\n");
    }
}

SharedMount retain_mount_before_run(PS2Runtime& runtime,const std::uint8_t* ram,std::size_t bytes)noexcept {
    try {
        if(!ram || bytes!=PS2_RAM_SIZE || runtime.memory().getRDRAM()!=ram ||
           ps2ActualGuestExecutionDepth(&runtime))return {};
        auto setup=runtime.acquirePreRunSetup();if(!setup)return {};
        const auto session=load_active();
        if(!session || &session->runtime!=&runtime || session->ram!=ram ||
           session->stopping.load(std::memory_order_acquire) || runtime.isStopRequested())return {};
        return SharedMount(session->reader,&session->reader->mount());
    }catch(...){return {};}
}

bool tryRead(std::uint8_t* ram, PS2Runtime* runtime,
             std::uint32_t send_buffer, std::uint32_t send_size,
             std::uint32_t receive_buffer, std::uint32_t receive_size, bool& ok) noexcept {
    bool attempted = false;
    try {
        const auto session = load_active();
        if (!session || !runtime || runtime != &session->runtime || ram != session->ram ||
            runtime->memory().getRDRAM() != ram || !ps2ActualGuestExecutionDepth(runtime) ||
            send_buffer != packet || send_size != 0x18 || receive_buffer || receive_size ||
            ram[packet + 0x0E] != 0 || word(ram, packet + 0x10) != end_block ||
            word(ram, packet + 0x14) != 0x208AC0 || word(ram, end_block) || word(ram, end_block + 4))
            return false;
        const auto lba = word(ram, packet), count = word(ram, packet + 4), destination = word(ram, packet + 8);
        const auto bytes = std::uint64_t(count) * 2048;
        if (!count || count > 0x4000 || bytes > max_read_bytes ||
            std::uint64_t(lba) + count > std::uint64_t(std::numeric_limits<std::uint32_t>::max()) + 1 ||
            !safe_destination(destination, bytes) || !session->enter()) return false;
        ReadLease lease(*session);
        attempted = true;
        const auto begin=session->slow_ns ? now_ns() : 0;
        const auto result = session->reader->read_sectors(lba, count,
            {reinterpret_cast<std::byte*>(ram + destination), static_cast<std::size_t>(bytes)});
        if(begin){
            const auto end=now_ns();
            if(end>=begin && end-begin>=session->slow_ns &&
                session->slow_reports.load(std::memory_order_relaxed)<64 &&
                session->slow_reports.fetch_add(1,std::memory_order_relaxed)<64)
                std::fprintf(stderr,"[NATIVE-RESOURCE-READS] slow begin_ns=%llu end_ns=%llu lba=%u sectors=%u destination=%08x disposition=%u resource=%u bytes=%zu\n",
                    static_cast<unsigned long long>(begin),static_cast<unsigned long long>(end),lba,count,destination,
                    static_cast<unsigned>(result.disposition),static_cast<unsigned>(result.resource_status),result.bytes);
        }
        if (result.disposition == native::ReaderDisposition::not_covered) return false;
        // From here on an I/O attempt is consumed. Even a provider/ABI failure
        // must not restart the legacy path or duplicate original completion.
        ok = result.disposition == native::ReaderDisposition::ok &&
             result.resource_status == reo::native::resources::Status::ok && result.bytes == bytes;
        if (ok) {
            const auto n = session->successes.fetch_add(1, std::memory_order_relaxed) + 1;
            if (n <= 4 || (n & (n - 1)) == 0)
                std::fprintf(stderr, "[NATIVE-RESOURCE-READS] payload successes=%llu lba=%u sectors=%u bytes=%zu\n",
                             static_cast<unsigned long long>(n), lba, count, result.bytes);
        } else if (session->failures.fetch_add(1, std::memory_order_relaxed) < 16) {
            std::fprintf(stderr, "[NATIVE-RESOURCE-READS] payload failed disposition=%u resource=%u bytes=%zu; no legacy retry\n",
                         static_cast<unsigned>(result.disposition), static_cast<unsigned>(result.resource_status), result.bytes);
        }
        return true;
    } catch (...) {
        if (attempted) {
            ok = false;
            std::fprintf(stderr, "[NATIVE-RESOURCE-READS] payload exception; no legacy retry\n");
            return true;
        }
        return false;
    }
}

} // namespace reo_native_resource_reads
#endif
