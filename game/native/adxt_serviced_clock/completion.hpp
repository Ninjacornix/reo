#pragma once
#include "../adxt_estimated_clock/estimated_clock.hpp"
#include <memory>

namespace reo::native::adxt_serviced_clock {
namespace clock=adxt_estimated_clock;
enum class Status { completed,busy,unsupported_fp,invalid_queue,zero_divisor,service_failure };
enum class ServiceStatus { completed,busy,failed };
// Injected binding obligation: actual matching group service, followed by fresh
// actual target state/queues. Metadata identity alone does not prove a factory.
class Service {
public:
    virtual ~Service()=default;
    [[nodiscard]] virtual const clock::Shared* clock_identity()const noexcept=0;
    [[nodiscard]] virtual clock::integer::Observation observation()const noexcept=0;
    virtual void discard_diagnostic()noexcept=0;
    virtual ServiceStatus run_and_refresh(clock::Stream&,clock::integer::Observation&)noexcept=0;
};
class Completion final {
public:
    Completion(std::shared_ptr<clock::Shared>,clock::Stream,std::shared_ptr<Service>);
    [[nodiscard]] Status discard(std::uint32_t original_tick)noexcept;
    [[nodiscard]] clock::Stream snapshot()const noexcept{return stream_;}
private:
    std::shared_ptr<clock::Shared> shared_;clock::Stream stream_;std::shared_ptr<Service> service_;
};
} // namespace reo::native::adxt_serviced_clock
