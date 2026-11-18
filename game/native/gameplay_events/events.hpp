#pragma once
#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <vector>
namespace reo::native::gameplay_events {
struct Domain;
class Events;
class EventId final {
public:
    EventId()=default;
    explicit operator bool()const noexcept{return bool(domain_);}
    friend bool operator==(const EventId&,const EventId&)=default;
private:
    std::shared_ptr<const Domain> domain_;
    std::uint64_t serial_{};std::uint8_t slot_{};
    friend class Events;
};
struct Event {
    std::uint32_t timestamp{};
    std::uint16_t id{},room{},first{},second{};
    std::uint8_t type{},priority{};
    friend bool operator==(const Event&,const Event&)=default;
};
struct View {EventId id;Event value;};
enum class Status {completed,priority_rejected,full,unavailable,serial_exhausted,closed};
struct Created {Status status{Status::unavailable};EventId id;};
// Canonical128-record cooperative event evidence owner. Simulation-thread only;
// immutable snapshots may be retained after retirement/reset. Not an audio API.
class Events final {
public:
    explicit Events(std::uint64_t max_serial=UINT64_MAX);
    Events(const Events&)=delete;Events& operator=(const Events&)=delete;
    //37BFB0 and37C060. Time/room are supplied by the actual update owner;
    // this pool does not create a second gameplay clock.
    Created simple(std::uint32_t event,std::uint32_t update_counter);
    Created typed(std::uint32_t event,std::uint32_t first,std::uint32_t second,
        std::uint32_t update_counter,std::uint16_t room);
    bool retire(const EventId&)noexcept;
    bool prune()noexcept;
    Status reset()noexcept;
    void close()noexcept;
    bool open()const noexcept{return !closed_;}
    std::size_t available()const noexcept{return free_count_;}
    std::int8_t threshold()const noexcept{return threshold_;}
    std::optional<std::uint8_t> physical_slot(const EventId&)const noexcept;
    std::optional<Event> get(const EventId&)const noexcept;
    std::vector<View> snapshot()const;
private:
    struct Node {Event value;std::uint64_t serial{};std::optional<std::uint8_t> next,previous;bool active{};};
    std::shared_ptr<const Domain> domain_;
    std::array<Node,128> slots_{};
    std::array<std::uint8_t,128> free_{};
    std::size_t free_count_{128};
    std::optional<std::uint8_t> head_,tail_;
    std::uint64_t serial_{},max_serial_;
    std::int8_t threshold_{};
    bool closed_{};
    EventId identity(std::uint8_t)const noexcept;
    Created allocate(Event)noexcept;
};
}
