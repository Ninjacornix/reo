#include "primary_actor_records.hpp"
#include "actor_initial_state.hpp"
#include <new>
namespace reo::native::gameplay_world {
PrimaryRecordsInitialized initialize_primary_records(World& world)noexcept{
    if(world.closed())return{PrimaryRecordsStatus::closed};
    if(world.busy())return{PrimaryRecordsStatus::busy};
    for(const auto& id:world.primary_)if(id)return{PrimaryRecordsStatus::not_empty};
    world.updating_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{world.updating_};
    std::array<actors::EntityId,World::primary_capacity> next{};
    const auto rollback=[&](){for(const auto& id:next)if(id)(void)world.entities_.retire(id);};
    try{
        for(auto& id:next){
            auto actor=std::make_unique<Actor>();initialize_cleared_actor_defaults(*actor);actor->head_reaction.emplace();
            actor->ai_execution.emplace();actor->navigation_route.emplace();
            // Native route query defaults use -1 for a failed link; the actual
            // ordinary bootstrap clears that short to0. A cleared10AC profile
            // pointer remains absent rather than selecting authored profile0.
            actor->navigation_route->output.link=0;
            const auto created=world.entities_.create(std::move(actor));
            if(created.status!=actors::EntityStatus::completed){rollback();return{created.status==actors::EntityStatus::no_memory?PrimaryRecordsStatus::no_memory:PrimaryRecordsStatus::entity_capacity};}
            id=created.id;
        }
        world.primary_.swap(next);return{PrimaryRecordsStatus::completed,World::primary_capacity};
    }catch(const std::bad_alloc&){rollback();return{PrimaryRecordsStatus::no_memory};}
    catch(...){rollback();return{PrimaryRecordsStatus::entity_capacity};}
}
}
