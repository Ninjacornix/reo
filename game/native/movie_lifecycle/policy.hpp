#pragma once
#include <array>
#include <cstdint>
#include <span>
#include <string_view>
namespace reo::native::movie_lifecycle {
struct State {
    std::uint32_t actual{},requested{},pending{},pause{},depth{},reuse{};
    std::array<std::uint32_t,100> current{},saved{};
    // Verification-independent owner identities: zero free, one this owner.
    std::array<std::uint32_t,8> registry{};
    std::uint32_t components{};
};
struct Construction {
    bool source_available{true};std::uint32_t workspace_bytes{0x2ba0},components{511};
    std::array<std::uint32_t,100> defaults{};
    bool hooks{true};
};
enum class Operation {create,start,stop,destroy,rebuild,reset};
struct Reply {std::uint32_t status{},snapshot{};bool snapshot_written{};};
class Ports {
public:
    virtual ~Ports()=default;
    // Child construction/cleanup and virtual methods are explicit retained
    // native provider boundaries. Callback effects remain visible on failure.
    virtual Reply call(std::string_view,std::span<const std::uint32_t>,State&)noexcept=0;
};
struct Result {std::uint32_t returned{};bool defined{true};};
// Numeric orchestration only; physical native ownership is in Session/Graph.
class Policy final {
public:
    Policy(State state,Construction config,Ports& ports):state_(state),config_(config),ports_(ports){}
    [[nodiscard]] Result execute(Operation)noexcept;
    [[nodiscard]] const State& state()const noexcept{return state_;}
    [[nodiscard]] State& callback_state()noexcept{return state_;}
private:
    State state_;Construction config_;Ports& ports_;bool defined_{true};
    Reply call(std::string_view,std::span<const std::uint32_t> = {})noexcept;
    Reply command(unsigned,unsigned,std::span<const std::uint32_t> = {})noexcept;
    std::uint32_t error(std::uint32_t)noexcept;
    std::uint32_t broadcast(unsigned)noexcept;
    bool construct()noexcept;
    std::uint32_t rebuild()noexcept;
    std::uint32_t reset()noexcept;
    std::uint32_t stop()noexcept;
    std::uint32_t destroy_children()noexcept;
};
}
