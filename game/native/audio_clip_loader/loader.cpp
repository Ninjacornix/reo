#include "loader.hpp"
#include "../tasks/serial_worker.hpp"
#include <array>
#include <atomic>
#include <climits>
#include <limits>
#include <mutex>
#include <stdexcept>
#include <string>

namespace reo::native::resources {
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView>,std::string);
}

namespace reo::native::audio_clip_loader {
struct Identity {};
namespace {
struct Record {
    std::shared_ptr<const adx_sequence::Clip> clip;
    std::uint64_t generation{1};
    Status status{Status::pending};
    adx_sequence::Status detail{adx_sequence::Status::invalid_input};
    bool active{}, exhausted{};
};
void retire(Record& record) noexcept {
    record.active = false;
    if (record.generation == std::numeric_limits<std::uint64_t>::max()) record.exhausted = true;
    else ++record.generation;
}
struct Shared {
    std::mutex mutex;
    std::shared_ptr<const Identity> identity = std::make_shared<Identity>();
    std::array<Record,64> slots;
    Snapshot report;
    std::atomic<std::uint64_t> accepted{};
    const std::uint32_t capacity;
    explicit Shared(Config c) : capacity(c.records) {}
};
Config checked(Config config) {
    if (!config.records || config.records > 64 || !config.pending_tasks || config.pending_tasks > 64)
        throw std::invalid_argument("Bounded native clip preparation required");
    return config;
}
}
struct Loader::State {
    std::shared_ptr<Shared> shared;
    tasks::SerialWorker worker;
    explicit State(Config config) : shared(std::make_shared<Shared>(checked(config))), worker(config.pending_tasks) {}
};
Loader::Loader(Config config) : state_(std::make_unique<State>(config)) {}
Loader::~Loader() { (void)join(); }
Request Loader::prepare(std::shared_ptr<const resources::ByteView> view) noexcept {
    if (!view || !view->size() || view->size() % 2048 || view->size() > INT_MAX)
        return {Status::invalid_input,{}};
    auto shared = state_->shared;
    std::uint32_t slot{};
    std::uint64_t generation{};
    {
        std::lock_guard lock(shared->mutex);
        if (shared->report.closing) return {Status::closed,{}};
        while (slot < shared->capacity && (shared->slots[slot].active || shared->slots[slot].exhausted)) ++slot;
        if (slot == shared->capacity) return {Status::capacity,{}};
        auto& record = shared->slots[slot];
        record.active = true; record.status = Status::pending; record.detail = adx_sequence::Status::invalid_input;
        generation = record.generation; ++shared->report.records;
    }
    Status status = Status::fault;
    try {
        const auto submitted = state_->worker.submit([shared,view=std::move(view),slot,generation] {
            {
                std::lock_guard lock(shared->mutex);
                const auto& record = shared->slots[slot];
                if (shared->report.closing || !record.active || record.generation != generation) {
                    ++shared->report.finished; ++shared->report.discarded; return;
                }
                ++shared->report.preparations;
            }
            adx_sequence::ClipResult prepared;
            try{
                // Production callers already supply a lazy resident wrapper
                // keyed by validated canonical source/range identity. Generic
                // finite callers get a fresh private identity, never a guessed
                // filename or provider-pointer alias. Wrappers are reused.
                static std::atomic<std::uint64_t> anonymous{};
                auto id=anonymous.load(std::memory_order_relaxed);
                while(id!=std::numeric_limits<std::uint64_t>::max() &&
                      !anonymous.compare_exchange_weak(id,id+1,std::memory_order_relaxed)){}
                if(id==std::numeric_limits<std::uint64_t>::max())throw std::length_error("Anonymous resident identity exhausted");
                auto resident=resources::retain_resident_view(view,":native-loader-anonymous:"+std::to_string(id));
                prepared=adx_sequence::Clip::prepare(std::move(resident));
            }catch(const std::bad_alloc&){prepared.status=adx_sequence::Status::no_memory;}
            catch(const std::length_error&){prepared.status=adx_sequence::Status::numeric_limit;}
            catch(...){prepared.status=adx_sequence::Status::source_failure;}
            {
                std::lock_guard lock(shared->mutex);
                ++shared->report.finished;
                auto& record = shared->slots[slot];
                if (shared->report.closing || !record.active || record.generation != generation) {
                    ++shared->report.discarded;
                } else {
                    record.detail = prepared.status;
                    record.status = prepared.status == adx_sequence::Status::completed ? Status::ready : Status::failed;
                    record.clip = std::move(prepared.clip); ++shared->report.published;
                }
            }
            // Discarded clips and all task captures release outside the result
            // mutex. A retained source may close a file or release another owner.
        },[](void* context) noexcept {
            static_cast<Shared*>(context)->accepted.fetch_add(1,std::memory_order_release);
        },shared.get());
        if (submitted == tasks::SubmitStatus::accepted) {
            Key key; key.owner_ = shared->identity; key.slot_ = slot; key.generation_ = generation;
            return {Status::accepted,key};
        }
        status = submitted == tasks::SubmitStatus::full ? Status::queue_full : Status::closed;
    } catch (const std::bad_alloc&) { status = Status::no_memory; }
    catch (...) { status = Status::fault; }
    {
        std::lock_guard lock(shared->mutex);
        retire(shared->slots[slot]); --shared->report.records;
    }
    return {status,{}};
}
Result Loader::poll(const Key& key) const noexcept {
    const auto shared = state_->shared;
    if (key.owner_.lock() != shared->identity || key.slot_ >= shared->capacity) return {};
    std::lock_guard lock(shared->mutex);
    if (shared->report.closing) return {Status::closed,adx_sequence::Status::invalid_input,{}};
    const auto& record = shared->slots[key.slot_];
    if (!record.active || record.generation != key.generation_) return {};
    return {record.status,record.detail,record.clip};
}
Status Loader::release(const Key& key) noexcept {
    const auto shared = state_->shared;
    if (key.owner_.lock() != shared->identity || key.slot_ >= shared->capacity) return Status::invalid_key;
    std::shared_ptr<const adx_sequence::Clip> released;
    {
        std::lock_guard lock(shared->mutex);
        if (shared->report.closing) return Status::closed;
        auto& record = shared->slots[key.slot_];
        if (!record.active || record.generation != key.generation_) return Status::invalid_key;
        released = std::move(record.clip); retire(record); --shared->report.records;
    }
    return Status::completed;
}
void Loader::request_stop() noexcept {
    const auto shared = state_->shared;
    std::array<std::shared_ptr<const adx_sequence::Clip>,64> released;
    {
        std::lock_guard lock(shared->mutex);
        shared->report.closing = true;
        for (std::uint32_t slot = 0; slot < shared->capacity; ++slot) {
            auto& record = shared->slots[slot];
            released[slot] = std::move(record.clip);
            if (record.active) retire(record);
        }
        shared->report.records = 0;
    }
    state_->worker.request_stop(tasks::StopMode::cancel_pending);
}
bool Loader::join() noexcept {
    request_stop();
    const auto joined = state_->worker.join();
    const auto shared = state_->shared;
    std::lock_guard lock(shared->mutex); shared->report.joined = joined;
    return joined;
}
Snapshot Loader::snapshot() const noexcept {
    const auto shared = state_->shared;
    std::lock_guard lock(shared->mutex);
    auto report = shared->report; report.accepted = shared->accepted.load(std::memory_order_acquire);
    report.worker_failures = state_->worker.failed_tasks(); return report;
}
}
