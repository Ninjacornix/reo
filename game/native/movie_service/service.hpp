#pragma once
#include <array>
#include <cstdint>

namespace reo::native::movie_service {
struct State {
    std::uint32_t actual{},requested{},pending{},buffered{},threshold{};
    std::array<std::uint32_t,100> properties{};
    // Video status/completion, audio status/completion: different observations.
    std::array<std::uint32_t,4> cached{};
    std::array<std::uint32_t,2> shared{};
};
enum class Action {counter,broadcast,shared,extent,requested_count,start,end_transition,buffer_pause,statistics};
class Ports {
public:
    virtual ~Ports()=default;
    virtual std::uint64_t call(Action,std::uint64_t,State&)noexcept=0;
};
// One original pending-service visit on a serialized owner. No clock tick,
// display cadence, completion inference, unbounded work loop or I/O is added.
void service(State&,Ports&)noexcept;
[[nodiscard]] std::uint32_t completion(const State&)noexcept;
} // namespace reo::native::movie_service
