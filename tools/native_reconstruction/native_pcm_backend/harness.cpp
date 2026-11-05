#include "recomp/overrides/native_pcm/runtime_adapter.h"
#include "Kernel/Syscalls/Helpers/CriAudio.h"
#include "ps2_runtime.h"
#include "fake_audio.h"
#include <algorithm>
#include <array>
#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <limits>
#include <deque>
#include <thread>
#include <unordered_map>
#include <unordered_set>
#include "exact_runtime_methods.inc"

namespace pcm = reo_native_pcm;
#define CHECK(x) do { if (!(x)) { std::cerr << "Failed line " << __LINE__ << ": " #x "\n"; std::abort(); } } while (0)
constexpr std::uint32_t left = 0x001e0000, right = 0x001e0020;
std::atomic<unsigned> bank_mixes{0}, bank_resets{0}, route_resets{0}, host_polls{0};
float reoAudioMasterGain() { return 0.5f; }
float reoAudioStreamGain(std::uint32_t) { return 1.0f; }
void reoAudioResetStreams() { ++route_resets; }
void reoAudioPoll() { ++host_polls; }
namespace ps2_reo_sound {
void mix(float* output, unsigned frames) {
    ++bank_mixes;
    if (output) for (unsigned i = 0; i < frames * 2; ++i) output[i] += 0.125f;
}
void reset() { ++bank_resets; }
void reportAudioPaths() {}
}
namespace ps2_syscalls {
// Only the reset functions' surrounding RPC containers are mocked. Their
// actual clear/set/snapshot bodies are extracted from qualified124 source.
std::mutex g_rpc_mutex, g_dtx_rpc_mutex;
PS2DtxCompatLayout g_dtxCompatLayout;
std::deque<int> g_pcmPending, g_sjxReplies;
std::unordered_set<int> g_pcmRings;
std::unordered_map<int,int> g_dtx_remote_by_id, g_dtx_transfer_by_id,
    g_dtx_sjx_by_handle, g_dtx_ps2rna_by_handle, g_dtx_sjrmt_by_handle;
std::uint32_t g_dtx_next_urpc_obj{};
#include "exact_rpc_methods.inc"
}
struct Services final : pcm::HostServices {
    std::atomic<std::int64_t> now{0};
    std::atomic<unsigned> reports{0}, resets{0}, routes{0};
    std::atomic<bool> pause_poll{false}, pause_mix{false};
    bool bad_gain = false;
    fake_audio::Event entered, finish;
    std::int64_t now_ns() noexcept override { return now; }
    void poll_settings() noexcept override {
        if (pause_poll) { entered.signal(); finish.wait(); }
    }
    float stream_gain(std::uint32_t) noexcept override {
        return bad_gain ? std::numeric_limits<float>::quiet_NaN() : 1.0f;
    }
    void mix_banks(float* output, std::uint32_t frames) noexcept override {
        if (pause_mix) { entered.signal(); finish.wait(); }
        if (output) for (unsigned i = 0; i < frames * 2; ++i) output[i] += 0.125f;
    }
    float master_gain() noexcept override { return 0.5f; }
    void reset_stream_routes() noexcept override { ++routes; }
    void reset_banks() noexcept override { ++resets; }
    void report_fault(const pcm::Diagnostic& d) noexcept override { CHECK(d.fault != pcm::Fault::none); ++reports; }
};
pcm::ProfileProof proof() {
    const auto p = pcm::ProfileProof::from_observed_file1(0x90000200,0x1e0000,0x1eff00,0x20,0,0,0);
    CHECK(p); return *p;
}
std::shared_ptr<pcm::Backend> build(PS2Runtime& runtime, const std::shared_ptr<Services>& services,
                                  const pcm::ProfileProof& checked = proof()) {
    auto result = pcm::create_candidate(checked, services);
    if (result.status != pcm::BuildStatus::ready) std::cerr << "build_status=" << unsigned(result.status) << '\n';
    CHECK(result.status == pcm::BuildStatus::ready && result.backend);
    CHECK(ps2_cri_audio::installBackendBeforeRunV1(runtime, result.backend->registration()) ==
          ps2_cri_audio::BackendInstallStatusV1::installed);
    return result.backend;
}
void queue_stereo() {
    const std::array<std::int16_t,8> l{16384,16384,16384,16384,16384,16384,16384,16384};
    const std::array<std::int16_t,8> r{8192,8192,8192,8192,8192,8192,8192,8192};
    std::uint64_t end = 0;
    CHECK(ps2_cri_audio::queue(left,reinterpret_cast<const std::uint8_t*>(l.data()),sizeof(l),end) && end == 16);
    CHECK(ps2_cri_audio::queue(right,reinterpret_cast<const std::uint8_t*>(r.data()),sizeof(r),end) && end == 16);
    ps2_cri_audio::configure(0,left,right,2,48000,256,true);
}
void lifecycle(PS2Runtime& runtime, const pcm::ProfileProof& checked = proof(), bool seal_run = false) {
    fake_audio::ready = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services,checked);
    if (seal_run) {
        runtime.beginExternalWorkerRun();
        CHECK(!runtime.acquirePreRunSetup());
    }
    ps2_cri_audio::ensureHostOutput(); // bank-only output before first PCM
    CHECK(fake_audio::loads == 1 && fake_audio::plays == 1);
    queue_stereo();
    float output[2]{9,9};
    ps2_cri_audio::render(output,1);
    CHECK(output[0] == 0.3125f && output[1] == 0.1875f);
    CHECK(ps2_cri_audio::queuedSamples(left) == 7 && ps2_cri_audio::consumed(left) == 2);
    fake_audio::pump(output,1);
    CHECK(output[0] == 0.3125f && ps2_cri_audio::consumed(left) == 4);
    ps2_cri_audio::drain(0); ps2_cri_audio::release(0); ps2_cri_audio::discard(left);
    CHECK(ps2_cri_audio::consumed(left) == 16 && ps2_cri_audio::consumed(0) == 0);
    ps2_cri_audio::reset();
    CHECK(services->routes == 1 && services->resets == 0);
    CHECK(fake_audio::loads == 1); // reset retains live stream
    ps2_cri_audio::shutdown();
    CHECK(services->resets == 1 && services->routes == 2);
    CHECK(fake_audio::stops == 1 && fake_audio::unloads == 1);
    CHECK(runtime.join());
    ps2_cri_audio::shutdown();
    CHECK(services->resets == 1 && backend->diagnostic().fault == pcm::Fault::none);
    // Backend's own refusal clears bounded buffers. The existing dispatch's
    // stopped invoke_void suppresses delivery; that facade policy is unchanged.
    const auto registration = backend->registration();
    output[0] = output[1] = 9;
    registration.api.render(registration.owner.get(),output,1);
    CHECK(output[0] == 0 && output[1] == 0);
}
void boot_setup(PS2Runtime& runtime) {
    ps2_syscalls::clearDtxCompatLayout(&runtime);
    PS2DtxCompatLayout requested;
    requested.rpcSid = 0x90000200;
    requested.urpcObjBase = 0x1e0000;
    requested.urpcObjLimit = 0x1eff00;
    ps2_syscalls::setDtxCompatLayout(requested,&runtime);
    CHECK(route_resets == 2 && runtime.m_preRunSetupCount == 0);
    CHECK(ps2_cri_audio::backendStatusV1().selection == ps2_cri_audio::BackendSelectionV1::unselected);
    const auto configured = ps2_syscalls::dtxCompatLayoutSnapshot();
    const auto checked = pcm::ProfileProof::from_observed_file1(configured.rpcSid,
        configured.urpcObjBase,configured.urpcObjLimit,configured.urpcObjStride,
        configured.urpcFnTableBase,configured.urpcObjTableBase,configured.dispatcherFuncAddr);
    CHECK(checked);
    lifecycle(runtime,*checked,true); // Actual complete binding/table/callback/join.
}
void headless(PS2Runtime& runtime) {
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    queue_stereo();
    services->now = 1'000'000;
    CHECK(ps2_cri_audio::queuedSamples(left) == 8); // non-ticking query
    CHECK(ps2_cri_audio::consumed(left) == 16);
    CHECK(ps2_cri_audio::queuedSamples(left) == 0 && fake_audio::loads == 0);
    CHECK(ps2_cri_audio::consumed(0) == 0);
    runtime.stop(); CHECK(runtime.join());
    CHECK(services->resets == 1 && backend->diagnostic().fault == pcm::Fault::none);
    std::weak_ptr<pcm::Backend> weak = backend;
    backend.reset(); runtime.workers.clear();
    CHECK(weak.expired()); // Host/output/renderer ownership contains no cycle.
}
void paused_producer(PS2Runtime& runtime) {
    fake_audio::ready = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    services->pause_poll = true;
    const std::array<std::uint8_t,2> bytes{};
    std::uint64_t end = 0;
    std::thread producer([&] { CHECK(ps2_cri_audio::queue(left,bytes.data(),2,end)); });
    services->entered.wait();
    runtime.stop(); // Must return while the admitted producer remains paused.
    fake_audio::Event joining;
    std::atomic<bool> joined = false;
    std::thread control([&] { joining.signal(); CHECK(runtime.join()); joined = true; });
    joining.wait(); CHECK(!joined && services->resets == 0);
    services->finish.signal();
    producer.join(); control.join();
    CHECK(end == 2 && services->resets == 1 && fake_audio::unloads == 1);
    CHECK(backend->diagnostic().fault == pcm::Fault::none);
}
void paused_callback(PS2Runtime& runtime) {
    fake_audio::ready = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    queue_stereo();
    services->pause_mix = true;
    float output[2]{};
    std::thread callback([&] { fake_audio::pump(output,1); });
    services->entered.wait();
    runtime.stop();
    fake_audio::Event joining;
    std::atomic<bool> joined = false;
    std::thread control([&] { joining.signal(); CHECK(runtime.join()); joined = true; });
    joining.wait(); CHECK(!joined && services->resets == 0 && fake_audio::unloads == 0);
    services->finish.signal();
    callback.join(); control.join();
    CHECK(output[0] == 0.3125f && services->resets == 1 && fake_audio::unloads == 1);
    CHECK(backend->diagnostic().fault == pcm::Fault::none);
}
void rejected_domain(PS2Runtime& runtime, std::string_view mode) {
    fake_audio::ready = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    if (mode == "alias") ps2_cri_audio::configure(0,left,left,2,48000,256,true);
    else if (mode == "outside") (void)ps2_cri_audio::consumed(0x1e0001);
    else if (mode == "huge") {
        float sentinel = 7;
        ps2_cri_audio::render(&sentinel,std::numeric_limits<unsigned>::max());
        CHECK(sentinel == 7); // No fill/read/loop before the cap refusal.
    } else {
        queue_stereo(); services->bad_gain = true;
        float output[2]{9,9};
        fake_audio::pump(output,1);
        CHECK(output[0] == 0 && output[1] == 0 && services->reports == 0);
        (void)ps2_cri_audio::consumed(left); // Deferred outside-callback report.
    }
    CHECK(backend->diagnostic().hard_failures == 1 && services->reports == 1);
    std::uint64_t end = 77; const std::uint8_t bytes[2]{};
    CHECK(!ps2_cri_audio::queue(left,bytes,2,end) && end == 77);
    runtime.stop(); CHECK(runtime.join());
    CHECK(services->resets == 1 && services->reports == 1);
}
void queue_capacity(PS2Runtime& runtime) {
    fake_audio::ready = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    const std::array<std::uint8_t,0x4000> bytes{};
    std::uint64_t end = 0;
    for (unsigned i = 0; i < 11; ++i) CHECK(ps2_cri_audio::queue(left,bytes.data(),bytes.size(),end));
    const auto before = end;
    CHECK(!ps2_cri_audio::queue(left,bytes.data(),bytes.size(),end) && end == before);
    CHECK(!ps2_cri_audio::queue(0,bytes.data(),2,end) && end == before);
    // Facade rejects key0 before delivering it to the backend table.
    CHECK(backend->diagnostic().queue_rejections == 1 && backend->diagnostic().hard_failures == 0);
    runtime.stop(); CHECK(runtime.join());
}
void startup_callback(PS2Runtime& runtime) {
    fake_audio::ready = true; fake_audio::callback_on_play = true;
    auto services = std::make_shared<Services>();
    auto backend = build(runtime,services);
    ps2_cri_audio::ensureHostOutput(); // Callback enters before start() returns.
    CHECK(fake_audio::plays == 1 && backend->diagnostic().hard_failures == 0);
    runtime.stop(); CHECK(runtime.join());
}
void gating(PS2Runtime& runtime, std::string_view mode) {
    CHECK(!pcm::ProfileProof::from_observed_file1(0x90000200,0x1e0000,0x1eff00,0x10,0,0,0));
    CHECK(!pcm::ProfileProof::from_observed_file1(0x90000201,0x1e0000,0x1eff00,0x20,0,0,0));
    if (mode == "disabled") {
        CHECK(!pcm::install(runtime,proof()));
        CHECK(pcm::create_candidate(proof(),std::make_shared<Services>()).status == pcm::BuildStatus::disabled);
    } else if (mode == "boot_reset") {
        ps2_cri_audio::reset(); // Current profile setter's public facade route.
        CHECK(!pcm::install(runtime,proof()));
        CHECK(ps2_cri_audio::backendStatusV1().selection == ps2_cri_audio::BackendSelectionV1::legacy);
    } else {
        if (mode == "identity") runtime.memory().bytes[0x1392f8] ^= 1;
        else ps2RamBackingBytes = 64u * 1024u * 1024u;
        CHECK(!pcm::install(runtime,proof()));
    }
    CHECK(runtime.workers.empty() && fake_audio::loads == 0);
}
int main(int argc,char** argv) {
    CHECK(argc == 3);
    PS2Runtime runtime;
    std::ifstream fixture(argv[2],std::ios::binary);
    fixture.read(reinterpret_cast<char*>(runtime.memory().getRDRAM()+0x1392f8),0x40);
    fixture.read(reinterpret_cast<char*>(runtime.memory().getRDRAM()+0x135078),0xf8);
    CHECK(fixture.good());
    const std::string_view mode = argv[1];
    if (mode == "lifecycle") lifecycle(runtime);
    else if (mode == "boot_setup") boot_setup(runtime);
    else if (mode == "headless") headless(runtime);
    else if (mode == "producer") paused_producer(runtime);
    else if (mode == "callback") paused_callback(runtime);
    else if (mode == "capacity") queue_capacity(runtime);
    else if (mode == "startup") startup_callback(runtime);
    else if (mode == "alias" || mode == "outside" || mode == "huge" || mode == "gain") rejected_domain(runtime,mode);
    else if (mode == "install") {
        fake_audio::ready = true;
        CHECK(pcm::install(runtime,proof()));
        ps2_cri_audio::ensureHostOutput();
        CHECK(fake_audio::loads == 1); queue_stereo();
        float output[2]{}; fake_audio::pump(output,1);
        CHECK(output[0] == 0.3125f && bank_mixes > 0);
        runtime.stop(); CHECK(runtime.join()); CHECK(bank_resets == 1);
    } else gating(runtime,mode);
    std::cout << "native_pcm_backend: " << mode << " passed (fake device/runtime)\n";
}
