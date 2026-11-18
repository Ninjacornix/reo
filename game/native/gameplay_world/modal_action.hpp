#pragma once
#include "interaction_transitions.hpp"
#include "interaction_registration.hpp"

namespace reo::native::gameplay_world {

enum class ModalActionStatus { completed, unavailable };
struct ModalActionResult { ModalActionStatus status{ModalActionStatus::unavailable}; bool original_result{}; };

// Required concrete consumers of 663190, 5F4FD0 and 67FF80. The native policy
// owns their source order and actor mutations; a refused required consumer
// stops at that point with the already-applied prefix retained.
class ModalActionServices : public InteractionRegistrationPublication {
public:
    virtual ~ModalActionServices()=default;
    virtual bool query_actor(World&,Actor&,std::uint8_t selector,std::uint8_t mode)=0;
    virtual bool close_inventory(World&,Actor&)=0;
};
class ModalActionPublication {
public:
    virtual ~ModalActionPublication()=default;
    virtual bool publish_interaction_request(World&,Actor&)=0;
};

// Complete native policy for 64F110 up to the explicitly supplied original
// query/close consumers and typed 67FF80/1AFDD0 publication owner.
ModalActionResult consume_modal_action(World&,Actor&,ModalActionServices&,
                                       ModalActionPublication&);

} // namespace reo::native::gameplay_world
