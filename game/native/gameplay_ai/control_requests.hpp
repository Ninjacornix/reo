#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <optional>
#include <span>
namespace reo::native::gameplay_ai {
// Native shared control registrations. Payload bytes are protocol values;
// neither registrations nor requests contain a guest address/function pointer.
struct ControlRegistration {
    std::uint8_t active{},kind{},phase{},owner_tag{};
    std::int16_t target{};
    std::array<std::uint8_t,4> payload{};
    std::array<std::uint16_t,4> counters{};
    friend bool operator==(const ControlRegistration&,const ControlRegistration&)=default;
};
struct ControlRequest {
    std::uint8_t registration{};
    std::array<std::uint8_t,4> payload{};
    friend bool operator==(const ControlRequest&,const ControlRequest&)=default;
};
enum class RegistrationStatus {created,exists,full};
enum class RequestStatus {queued,missing_registration,full};
struct RequestResult {RequestStatus status{RequestStatus::missing_registration};std::optional<std::uint8_t> registration;};
class ControlRequests final {
public:
    bool registered(std::uint32_t kind,std::uint32_t target)const noexcept; //681240
    RegistrationStatus register_control(std::uint32_t kind,std::uint32_t target)noexcept; //6812B0
    bool unregister_control(std::uint32_t kind,std::uint32_t target)noexcept; //681330
    // Lookup compares full kind/target arguments against stored byte/signed-half.
    // Selector-1 chooses FF; other selectors use low-byte+1 with byte wrap.
    std::optional<std::uint8_t> find(std::int32_t kind,std::int32_t target,std::int32_t selector=-1)const noexcept; //681710
    RequestResult request(std::int32_t kind,std::int32_t target,std::array<std::uint8_t,4>,std::int32_t selector=-1)noexcept; //681790
    std::span<const ControlRegistration,64> registrations()const noexcept{return registrations_;}
    // Real service/import boundaries can change canonical fields in place;
    // there is one shared registration array, not a second mutable projection.
    ControlRegistration* registration(std::size_t index)noexcept{return index<registrations_.size()?&registrations_[index]:nullptr;}
    std::span<const ControlRequest> pending()const noexcept{return {requests_.data(),count_};}
private:
    std::array<ControlRegistration,64> registrations_{};
    std::array<ControlRequest,64> requests_{};
    std::size_t count_{};
};
RequestResult publish_actor_control(ControlRequests&,std::uint8_t actor_slot,std::uint32_t value)noexcept; //815DF0
}
