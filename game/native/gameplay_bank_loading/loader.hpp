#pragma once
#include "../gameplay_audio/owner.hpp"
#include "../afs_source_range/afs_source_range.hpp"
#include <memory>
#include <optional>
#include <string_view>
namespace reo::native::gameplay_bank_loading {
struct LoadDomain;
class Loader;
class LoadTicket final {
public:
    LoadTicket()=default;
    explicit operator bool()const noexcept{return id_!=0;}
private:
    std::weak_ptr<const LoadDomain> domain_;
    std::uint64_t id_{};
    friend class Loader;
};
enum class LoadStatus {accepted,pending,completed,cached,invalid_input,full,closed,stale,not_found,source_failure,bank_failure,capacity};
struct Submitted {LoadStatus status{LoadStatus::invalid_input};LoadTicket ticket;};
struct LoadResult {LoadStatus status{LoadStatus::stale};gameplay_audio::BankResult bank;std::optional<unsigned> member;};
// Simulation/control owner thread only. Its existing AsyncReadOwner performs
// actual resource reads; a separate owned worker prepares and installs banks.
// service() never reads files, decodes samples or waits for either worker.
// Outstanding results retain bounded capacity until consumed/cancelled.
class Loader final {
public:
    Loader(std::shared_ptr<gameplay_audio::Owner>,std::shared_ptr<const afs_source_range::Archive>);
    ~Loader();
    Loader(const Loader&)=delete;
    Loader& operator=(const Loader&)=delete;
    bool bound_to(const gameplay_audio::Owner&)const noexcept;
    // Original queued name copy: first15 bytes, then append ".snd" for lookup.
    Submitted enqueue(std::string_view name,unsigned port)noexcept;
    void service()noexcept;
    LoadResult poll(const LoadTicket&)noexcept;
    bool cancel(const LoadTicket&)noexcept;
    void shutdown()noexcept;
    bool join()noexcept;
private:
    struct State;
    std::unique_ptr<State> state_;
    std::shared_ptr<const LoadDomain> domain_;
    std::optional<std::size_t> locate(const LoadTicket&)const noexcept;
};
}
