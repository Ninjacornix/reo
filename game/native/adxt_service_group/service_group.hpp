#pragma once
#include "../adxt_estimated_clock/estimated_clock.hpp"
#include <array>
#include <cstdint>
#include <memory>

namespace reo::native::adxt_service_group {
inline constexpr std::uint32_t slots=16;
enum class Domain { cri,rna };
enum class Phase { ready=1,buffering=2,playing=3,draining=4 };
enum class Status { completed,busy };
class Guards {
public:
    virtual ~Guards()=default;
    virtual void enter(Domain)noexcept=0;
    virtual void leave(Domain)noexcept=0;
};
class Work {
public:
    virtual ~Work()=default;
    virtual void service()noexcept=0;
};
class ActiveWork:public Work {
public:
    [[nodiscard]] virtual std::int8_t active()const noexcept=0;
};
class Stream {
public:
    virtual ~Stream()=default;
    [[nodiscard]] virtual std::int8_t active()const noexcept=0;
    [[nodiscard]] virtual std::int8_t phase()const noexcept=0;
    virtual void service_phase(Phase)noexcept=0;
    virtual void propagate_input_end()noexcept=0;
    virtual void propagate_error()noexcept=0;
};
// One externally serialized control owner. Table edits by child callbacks are
// visible to later indices; strong local leases retain the current child.
// Guards synchronize without invoking user callbacks. No service allocation,
// source join, time synthesis or device callback is performed by this owner.
class Group final {
public:
    Group(std::shared_ptr<adxt_estimated_clock::Shared>,std::shared_ptr<Guards>,
          std::shared_ptr<Work> dtr,std::shared_ptr<Work> dtx);
    Group(const Group&)=delete;Group& operator=(const Group&)=delete;
    [[nodiscard]] bool set_decoder(std::uint32_t,std::shared_ptr<ActiveWork>)noexcept;
    [[nodiscard]] bool set_stream(std::uint32_t,std::shared_ptr<Stream>)noexcept;
    [[nodiscard]] bool set_rna(std::uint32_t,std::shared_ptr<ActiveWork>)noexcept;
    [[nodiscard]] Status service()noexcept;
private:
    std::shared_ptr<adxt_estimated_clock::Shared> clock_;
    std::shared_ptr<Guards> guards_;std::shared_ptr<Work> dtr_,dtx_;
    std::array<std::shared_ptr<ActiveWork>,slots> decoders_{},rna_{};
    std::array<std::shared_ptr<Stream>,slots> streams_{};
};
} // namespace reo::native::adxt_service_group
