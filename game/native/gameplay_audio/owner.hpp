#pragma once
#include "import.hpp"
#include "spatial.hpp"
#include <memory>
#include <mutex>

namespace reo::native::gameplay_audio {
class BankTicket final {
  public:
    BankTicket() = default;
    explicit operator bool() const noexcept {
        return bool(domain_);
    }
    unsigned slot() const noexcept {
        return slot_;
    }

  private:
    friend class Owner;
    BankTicket(std::shared_ptr<const void> domain, unsigned slot, std::uint64_t generation)
        : domain_(std::move(domain)), slot_(slot), generation_(generation) {}
    std::shared_ptr<const void> domain_;
    unsigned slot_{16};
    std::uint64_t generation_{};
};
struct BankResult {
    Status status{Status::unavailable};
    banks::Status engine{banks::Status::invalid_input};
};
// The canonical gameplay owner must serialize RNG/update calls as for World.
// Only this owner installs/unloads its fourteen bank ports. Device mixing can
// continue independently through the existing thread-safe native Session.
class Owner final {
  public:
    Owner(std::shared_ptr<banks::Session>, gameplay_session::Random&);
    bool bound_to(const gameplay_session::Random& value) const noexcept {
        return &value == random_;
    }
    BankTicket begin_bank(unsigned slot) noexcept;
    // Buffer is immutable and retained for the duration of this synchronous
    // control-side capture/prepare. Runtime never loads banks in a hot callback.
    BankResult install(BankTicket, std::span<const std::uint8_t>) noexcept;
    // Named/staged loading supplies separately owned HD/BD/TQ parts. It must
    // not treat the staged SND header's unused direct extents as embedded data.
    BankResult install_parts(BankTicket, const Descriptors&,
                             std::array<std::span<const std::uint8_t>, 3>) noexcept;
    BankResult unload(unsigned slot) noexcept;
    BankResult stop(unsigned slot) noexcept;
    BankResult cancel(BankTicket) noexcept;
    bool current(BankTicket)const noexcept;
    Status state(unsigned slot) const noexcept;
    Result request(Request) noexcept;
    Result positional(Request, Vector, const SpatialContext&, unsigned selector = 1) noexcept;
    Result actor_cached_slot(std::uint32_t slot, std::uint32_t event, Vector,
                             const SpatialContext&) noexcept;

  private:
    struct Bank {
        std::uint64_t generation{};
        std::uint64_t installed_generation{};
        bool requested{};
        std::shared_ptr<const Descriptors> descriptors;
    };
    std::shared_ptr<banks::Session> engine_;
    std::shared_ptr<const void> domain_{std::make_shared<const unsigned>(0)};
    gameplay_session::Random* random_;
    mutable std::mutex gate_;
    std::array<Bank, 16> banks_;
};
} // namespace reo::native::gameplay_audio
