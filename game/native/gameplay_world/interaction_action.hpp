#pragma once
#include "world.hpp"
#include "forward_contact.hpp"

namespace reo::native::gameplay_world {
enum class InteractionActionStatus { completed, unavailable };
struct InteractionActionResult { InteractionActionStatus status{InteractionActionStatus::unavailable}; bool original_result{}; };

// Reached consumers of original64E960. Optional return values distinguish a
// missing native capability from the guest function's own zero result.
class InteractionActionServices {
public:
    virtual ~InteractionActionServices()=default;
    virtual ForwardContactResult forward_contact(World&,Actor&,std::uint32_t include,
                                                std::uint32_t exclude,float offset)=0; //65F4A0
    virtual std::optional<bool> actor_query(World&,Actor&,std::uint8_t selector,
                                            std::uint8_t argument)=0; //663190
    virtual std::optional<std::int8_t> admit_actor(World&,Actor&)=0; //6AF9E0
    virtual bool prepare_alignment(World&,Actor&,std::uint32_t limit,float offset)=0; //666F50
    virtual bool activate(World&,Actor&)=0; //667370
    virtual bool notify(World&,Actor&,std::uint8_t)=0; //67E230
    virtual std::optional<bool> consume_request(World&,Actor&)=0; //64EF10, selector0
};

// Source-ordered interaction/contact action. Required consumers stop at their
// callsite, retaining writes already made by the original prefix.
InteractionActionResult process_interaction_action(World&,Actor&,InteractionActionServices&);
}
