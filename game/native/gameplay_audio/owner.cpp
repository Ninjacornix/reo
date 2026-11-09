#include "owner.hpp"
#include <algorithm>
#include <stdexcept>

namespace reo::native::gameplay_audio {
namespace {
class SessionSink final : public CommandSink {
  public:
    explicit SessionSink(banks::Session& engine) : engine_(engine) {}
    bool apply(const banks::Command& command) noexcept override {
        return engine_.apply({&command, 1}).status == banks::Status::ok;
    }

  private:
    banks::Session& engine_;
};
} // namespace
Owner::Owner(std::shared_ptr<banks::Session> engine, gameplay_session::Random& random)
    : engine_(std::move(engine)), random_(&random) {
    if (!engine_)
        throw std::invalid_argument("Native audio owner requires a bank session");
}
BankTicket Owner::begin_bank(unsigned slot) noexcept {
    std::lock_guard lock(gate_);
    if (slot >= banks_.size() || banks_[slot].generation == UINT64_MAX)
        return {};
    auto& bank = banks_[slot];
    ++bank.generation;
    bank.requested = true;
    return BankTicket{domain_, slot, bank.generation};
}
BankResult Owner::install(BankTicket ticket, std::span<const std::uint8_t> bytes) noexcept {
    if (ticket.domain_ != domain_)
        return {Status::stale, banks::Status::stale_generation};
    const auto imported = import_snd(bytes, ticket.slot_);
    if (imported.status != Status::completed)
        return {imported.status};
    std::array<std::span<const std::uint8_t>, 3> parts;
    for (unsigned n = 0; n < 3; ++n)
        parts[n] = bytes.subspan(imported.value.parts[n].offset, imported.value.parts[n].size);
    return install_parts(ticket, imported.value.descriptors, parts);
}
BankResult Owner::install_parts(BankTicket ticket, const Descriptors& descriptors,
                                std::array<std::span<const std::uint8_t>, 3> parts) noexcept {
    if (ticket.domain_ != domain_)
        return {Status::stale, banks::Status::stale_generation};
    if (ticket.slot_ >= banks::port_count)
        return {Status::unavailable};
    {
        std::lock_guard lock(gate_);
        const auto& bank = banks_[ticket.slot_];
        if (!ticket.generation_ || bank.generation != ticket.generation_ || !bank.requested)
            return {Status::stale, banks::Status::stale_generation};
    }
    std::shared_ptr<const Descriptors> rows;
    try {
        rows = std::make_shared<const Descriptors>(descriptors);
    } catch (...) {
        return {Status::capacity, banks::Status::no_memory};
    }
    auto token = engine_->begin_submission();
    if (token.status != banks::Status::ok)
        return {Status::unavailable, token.status};
    auto capture =
        engine_->capture(token.value, {parts[0].size(), parts[1].size(), parts[2].size()});
    if (capture.status != banks::Status::ok)
        return {Status::unavailable, capture.status};
    std::array<std::span<std::uint8_t>, 3> targets{capture.value.hd(), capture.value.bd(),
                                                   capture.value.tq()};
    for (unsigned n = 0; n < 3; ++n)
        std::copy(parts[n].begin(), parts[n].end(), targets[n].begin());
    auto prepared = engine_->prepare(token.value, std::move(capture.value));
    if (prepared.status != banks::Status::ok)
        return {Status::invalid_asset, prepared.status};
    std::lock_guard lock(gate_);
    auto& bank = banks_[ticket.slot_];
    if (!ticket.generation_ || bank.generation != ticket.generation_ || !bank.requested)
        return {Status::stale, banks::Status::stale_generation};
    const auto status = engine_->install(token.value, ticket.slot_, prepared.value);
    if (status != banks::Status::ok)
        return {Status::unavailable, status};
    bank.descriptors = std::move(rows);
    bank.requested = false;
    return {Status::completed, status};
}
BankResult Owner::unload(unsigned slot) noexcept {
    if (slot >= banks::port_count)
        return {Status::invalid_input};
    std::lock_guard lock(gate_);
    auto& bank = banks_[slot];
    if (bank.generation == UINT64_MAX)
        return {Status::capacity};
    banks::Command command = banks::StopPort{slot, true};
    const auto result = engine_->apply({&command, 1});
    if (result.status != banks::Status::ok)
        return {Status::unavailable, result.status};
    ++bank.generation;
    bank.descriptors.reset();
    bank.requested = false;
    return {Status::completed, result.status};
}
Status Owner::state(unsigned slot) const noexcept {
    std::lock_guard lock(gate_);
    if (slot >= banks_.size())
        return Status::invalid_input;
    const auto& bank = banks_[slot];
    if (bank.requested)
        return Status::pending;
    if (!bank.descriptors || slot >= banks::port_count)
        return Status::unavailable;
    std::uint32_t sequences{};
    const auto loaded = engine_->port_state(slot, sequences);
    return loaded.status == banks::Status::ok && loaded.value ? Status::completed
                                                              : Status::unavailable;
}
Result Owner::request(Request request) noexcept {
    std::lock_guard lock(gate_);
    if (request.bank >= banks_.size())
        return {Status::invalid_input, -1, 0};
    const auto& bank = banks_[request.bank];
    if (bank.requested)
        return {Status::pending, -1, 0};
    if (!bank.descriptors)
        return {Status::unavailable, -1, 0};
    std::uint32_t sequences{};
    const auto loaded = engine_->port_state(request.bank, sequences);
    if (loaded.status != banks::Status::ok || !loaded.value)
        return {Status::unavailable, -1, 0};
    SessionSink sink(*engine_);
    return route(*bank.descriptors, false, 2, request, *random_, sink);
}
Result Owner::positional(Request request, Vector point, const SpatialContext& context,
                         unsigned selector) noexcept {
    // Positional rejection occurs before bank readiness and RNG in the source.
    const auto* table = attenuation(selector);
    if (!table)
        return {Status::invalid_input, -1, 0};
    const auto located = locate(point, context, *table);
    if (located.status != Status::completed)
        return {located.status, 0, 0};
    request.gain = located.gain;
    request.pan = located.pan;
    return this->request(request);
}
Result Owner::actor_cached_slot(std::uint32_t slot, std::uint32_t event, Vector point,
                                const SpatialContext& context) noexcept {
    if (slot > UINT32_MAX - 8)
        return {Status::invalid_input, -1, 0};
    return positional({slot + 8, event}, point, context, 1);
}
} // namespace reo::native::gameplay_audio
