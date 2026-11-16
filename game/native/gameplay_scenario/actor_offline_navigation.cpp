#include "actor_offline_navigation.hpp"
#include "scene_entry_requests.hpp"
#include "scene_matrix_programs.hpp"
#include "script_program.hpp"
#include "../gameplay_update/update.hpp"
#include "../gameplay_world/actor_resource_operations.hpp"
#include "../gameplay_world/actor_recovery.hpp"
#include "../gameplay_world/actor_forced_terminal.hpp"
#include "../gameplay_world/interaction_transitions.hpp"
#include "../gameplay_world/motion.hpp"
#include "../gameplay_navigation/local_routes.hpp"
#include "../gameplay_world/animation.hpp"
#include <algorithm>
#include <bit>
#include <cstring>
namespace reo::native::gameplay_scenario {
namespace w=gameplay_world;namespace n=gameplay_navigation;using Result=OfflineNavigationStatus;
namespace {
bool current(w::World& world,const w::Actor& actor)noexcept{const auto id=world.identity_of(actor);return id&&world.resolve(id).get()==&actor;}
std::optional<n::Position> node_position(const n::Bank& bank,std::uint32_t room,std::int32_t index)noexcept{
    const auto graph=bank.room(room);if(!graph||index<0||std::size_t(index)>=graph->nodes().size())return{};
    return graph->nodes()[std::size_t(index)].position;
}
std::optional<std::uint32_t> door_state(SceneControls& controls,SceneMatrixPrograms& matrices,FlagState& flags,std::uint16_t room,std::uint16_t selector)noexcept{
    const auto mask=1u<<(selector&31u);
    for(const auto pair:{std::pair{2u,1u},std::pair{0u,2u},std::pair{3u,3u}}){const auto value=flags.strided_half(room,pair.first);if(!value)return{};if(*value&mask)return pair.second;}
    const auto found=controls.first_route(std::uint8_t(selector));if(found.status!=ControlStatus::completed)return{};if(!found.id)return 0;
    const auto channel=matrices.inspect(selector);if(!channel)return{};
    switch(channel->contact.gate){case 0:return 4;case 1:return 5;case 2:return 6;default:return 0;}
}
std::optional<std::int8_t> normalize_node(const n::Bank& bank,std::uint32_t room,std::int32_t index)noexcept{
    const auto graph=bank.room(room);if(!graph||index<0||std::size_t(index)>=graph->nodes().size())return{};
    const auto& first=graph->nodes()[std::size_t(index)];if(first.neighbor_count<=0||first.neighbors[0]==-1)return std::int8_t(-1);
    const auto neighbor=first.neighbors[0];if(neighbor<0||std::size_t(neighbor)>=graph->nodes().size())return{};
    const auto& reverse=graph->nodes()[std::size_t(neighbor)];std::int8_t result=-1;
    for(std::int32_t i=0;i<reverse.neighbor_count;++i)if(std::uint8_t(reverse.actions[std::size_t(i)])==12)result=reverse.neighbors[std::size_t(i)];
    return result;
}
}
ActorOfflineNavigation::ActorOfflineNavigation(gameplay_update::Owner& update)noexcept:update_(update),world_(update.world()),scripts_(update.scripts()){}
bool ActorOfflineNavigation::bound_to(const w::World& world,const Interpreter& scripts)const noexcept{return &world_==&world&&&scripts_==&scripts;}
bool ActorOfflineNavigation::busy()const noexcept{return running_||(terminal_&&terminal_->busy());}
bool ActorOfflineNavigation::command_ready(std::uint32_t selector,std::uint32_t room,std::uint32_t node)const noexcept{
    if(closed_||!update_.open()||selector>=w::World::primary_capacity)return false;
    const auto actor=world_.primary(selector);if(!actor||!actor->active||!actor->ai_control)return true;
    const auto bank=world_.navigation_if_created();return actor->ai_execution&&actor->navigation_route&&bank&&node_position(*bank,room,std::bit_cast<std::int32_t>(node)).has_value();
}
Result ActorOfflineNavigation::bind_scene(SceneControls* controls,SceneModels* models,SceneMatrixPrograms* matrices,
    std::shared_ptr<const gameplay_collision::response::Grid> floors,const SceneControls* expected)noexcept{
    if(closed_)return controls||models||matrices||floors?Result::closed:Result::completed;
    if(running_||world_.busy()||update_.busy())return Result::busy;
    if(!update_.open())return Result::closed;
    if(bool(controls)!=bool(models)||bool(controls)!=bool(matrices)||(!controls&&floors))return Result::unavailable;
    if(matrices&&!matrices->bound_to(*controls,*models))return Result::unavailable;
    if(controls_==controls&&models_==models&&matrices_==matrices&&floors_==floors)return Result::completed;
    if(controls_!=expected)return Result::unavailable;
    controls_=controls;models_=models;matrices_=matrices;floors_=std::move(floors);return Result::completed;
}
Result ActorOfflineNavigation::bind_resource_operations(w::ActorResourceOperations* operations,w::ActorResourceOperations* expected,w::ActorForcedTerminal* terminal)noexcept{
    if(closed_)return operations?Result::closed:Result::completed;
    if(running_||world_.busy()||update_.busy())return Result::busy;
    return bind_roster_resources(operations,expected,terminal);
}
Result ActorOfflineNavigation::bind_roster_resources(w::ActorResourceOperations* operations,w::ActorResourceOperations* expected,w::ActorForcedTerminal* terminal)noexcept{
    if(closed_)return operations?Result::closed:Result::completed;
    if(!update_.open())return Result::closed;if(running_)return Result::busy;
    if(bool(operations)!=bool(terminal)||(operations&&!operations->bound_to(world_))||(terminal&&!terminal->bound_to(world_)))return Result::unavailable;
    if(terminal_&&terminal_->busy())return Result::busy;
    if(operations_==operations)return terminal_==terminal?Result::completed:Result::unavailable;if(operations_!=expected)return Result::unavailable;
    operations_=operations;terminal_=terminal;return Result::completed;
}
Result ActorOfflineNavigation::close()noexcept{
    if(closed_)return Result::completed;if(running_||world_.busy()||(terminal_&&terminal_->busy()))return Result::busy;
    closed_=true;controls_=nullptr;models_=nullptr;matrices_=nullptr;floors_.reset();operations_=nullptr;terminal_=nullptr;return Result::completed;
}
Result ActorOfflineNavigation::reset_actor_scripts(const w::Actor& actor)noexcept{
    if(actor.slot>=3)return Result::completed;
    const auto graph=world_.navigation().room(actor.room);if(!graph)return Result::script_failure;
    try{
        const auto encoded=graph->script_encoding();auto bytes=std::make_shared<std::vector<std::byte>>(encoded.size());
        std::memcpy(bytes->data(),encoded.data(),encoded.size());
        const auto admitted=content::admit_script_program(content::ScriptBank(bytes,content::BankFormat::room_section),DispatchProfile::offline_actor);
        if(admitted.status!=content::ScriptAdmission::admitted&&admitted.status!=content::ScriptAdmission::absent)return Result::script_failure;
        //700330 publishes8/12 and clears countdown, preserving saved
        //continuations and both ordinals. Its source3243E9 byte has writers only and no native consumer.
        constexpr std::array<unsigned,3> channels{1,2,3};
        for(unsigned i=0;i<2;++i){const auto channel=i?5u:channels[actor.slot];auto& target=scripts_.channels_[channel];
            const auto saved=target.saved;const auto saved_owner=target.saved_program?target.saved_program:(target.cursor_program?target.cursor_program:target.program);
            const auto ordinal=target.condition;const auto entry=admitted.entries[i];
            target={entry?admitted.program:nullptr,entry.value_or(Position{}),saved,0,i?12u:8u,ordinal,{},saved_owner};}
        return Result::completed;
    }catch(...){return Result::script_failure;}
}
Result ActorOfflineNavigation::reconstruct_actor(w::Actor& actor)noexcept{
    if(!actor.navigation_route||!actor.ai_execution)return Result::unavailable;
    auto& route=*actor.navigation_route;auto& bank=world_.navigation();const auto graph=bank.room(actor.room);
    if(!graph||route.current_node<0||std::size_t(route.current_node)>=graph->nodes().size())return Result::unavailable;
    const auto& node=graph->nodes()[std::size_t(route.current_node)];
    const auto at=12u+64u*std::uint32_t(std::uint8_t(route.current_node))+60u;
    if(at+4>graph->encoding().size())return Result::unavailable;std::uint32_t tag{};std::memcpy(&tag,graph->encoding().data()+at,4);
    if(node.condition==-1&&(tag==0||tag==1||tag==2||tag==0x80))return Result::completed;
    struct Candidate{std::int8_t node;float cost;};std::array<Candidate,128> candidates{};std::size_t count{};
    const n::ActorFacts facts{actor.character,actor.slot,actor.ai_control};
    for(std::size_t i=0;i<graph->nodes().size();++i){if(std::int32_t(i)==route.current_node||graph->nodes()[i].condition!=-1)continue;
        n::RouteOutput output;std::int16_t link{};const auto result=n::local_route(bank,actor.room,route.current_node,std::int32_t(i),facts,actor.status,update_.flags().strided_half(actor.room,0),1,output,link);
        if(result.status!=n::QueryStatus::completed)return Result::unavailable;
        if(result.selected!=-1){if(!result.cost_written||count==candidates.size())return Result::unavailable;candidates[count++]={std::int8_t(i),output.cost};}}
    if(!count)return Result::completed;
    for(std::size_t i=0;i+1<count;++i)for(std::size_t j=i+1;j<count;++j)if(!(candidates[i].cost<=candidates[j].cost))std::swap(candidates[i],candidates[j]);
    route.current_node=candidates[0].node;const auto point=graph->nodes()[std::size_t(route.current_node)].position;actor.position={point.x,point.y,point.z};
    gameplay_ai::set_goal(*actor.ai_execution,0);gameplay_ai::set_action(*actor.ai_execution,0);actor.motion_class=0;return Result::completed;
}
Result ActorOfflineNavigation::prepare_actor(w::Actor& actor,std::uint32_t mode)noexcept{
    if(!actor.navigation_route||!actor.ai_execution)return Result::unavailable;
    auto& route=*actor.navigation_route;auto& state=*actor.ai_execution;
    if(actor.room!=world_.room){const auto prior=route.selection_mode;route.selection_mode=1;if(prior==0){
        route.travel_ticks=450;if(!(actor.status&0x20u)){const auto result=reconstruct_actor(actor);if(result!=Result::completed)return result;}
        gameplay_ai::clear_action_phases(state);
        if(!(actor.status&0x20u)){const auto point=node_position(world_.navigation(),actor.room,route.current_node);if(!point)return Result::unavailable;actor.position={point->x,point->y,point->z};}
    }}else {const auto prior=route.selection_mode;route.selection_mode=0;if(prior==1){
        if(!mode){
            if(!(actor.status&0x20u)){const auto result=reconstruct_actor(actor);if(result!=Result::completed)return result;}
            if(!floors_)return Result::unavailable;const auto type=floors_->floor({actor.position.x,actor.position.y,actor.position.z},255).type;
            const auto motion=type==4?std::uint8_t(0x2d):actor.motion_class;std::uint8_t secondary{};
            switch(motion){case 0x31:secondary=0x81;break;case 0x27:secondary=0xcd;break;case 0x21:case 0x22:case 0x23:case 0x24:secondary=0x4a;break;case 0x1a:secondary=0x34;break;case 0x2d:case 0x2e:case 0x2f:secondary=0x74;break;default:break;}
            actor.primary=1;actor.secondary=secondary;actor.phase=actor.subphase=0;w::save_action_pose(actor);
        }else gameplay_ai::clear_action_phases(state);
    }}
    if(mode==1){const auto result=reset_actor_scripts(actor);if(result!=Result::completed)return result;
        if(route.completed==1)gameplay_ai::set_action(state,0);}
    route.refresh=1;state.action_marker=0;actor.response_lock=0;actor.status&=0xdbd7ffffu;actor.action_flags&=std::uint16_t(~1u);actor.surface_blend_weight=0;
    if(!actor.animation)return Result::unavailable;actor.animation->motion=0;return Result::completed;
}
Result ActorOfflineNavigation::enter_scene_actor(w::Actor& actor)noexcept{
    const auto id=world_.identity_of(actor);if(!id)return Result::unavailable;
    if(world_.mode==0&&(!operations_||!operations_->clear_claims()))return Result::resource_failure;
    //702740 requires ai_control. A synchronous earlier flag callback can
    //change it; the human-character2 inventory path remains explicitly reached.
    if(actor.character==2&&!actor.ai_control)return Result::unavailable;
    if(actor.transient_action){const auto result=w::consume_interaction_request(world_,id,1);
        if(result.status==w::InteractionTransitionStatus::unavailable)return Result::unavailable;
        if(update_.record_actor_message(id,gameplay_update::ActorMessageSelector::interaction_request)!=gameplay_update::PublicationStatus::completed)return Result::publication_failure;
        if(!current(world_,actor))return Result::unavailable;
        if(update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)!=gameplay_update::PublicationStatus::completed)return Result::publication_failure;
        return current(world_,actor)?Result::completed:Result::unavailable;
    }
    if(actor.primary<1||actor.primary>5||actor.motion_class==0x28){actor.auxiliary_status|=4u;return Result::completed;}
    if(actor.status&0x40000u){
        if(!terminal_||!terminal_->apply(world_,0))return Result::resource_failure;
        if(!current(world_,actor))return Result::unavailable;
        return update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)==gameplay_update::PublicationStatus::completed?
            Result::completed:Result::publication_failure;
    }
    try{
        if(actor.status&0x4a0u){if(!operations_)return Result::resource_failure;(void)operations_->transfer_inventory(id,0);
            actor.motion_class=0xa0;actor.primary=4;actor.secondary=8;actor.phase=actor.subphase=0;w::save_action_pose(actor);actor.status|=0x1000u;
            return update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)==gameplay_update::PublicationStatus::completed?Result::completed:Result::publication_failure;}
        if(actor.current==0&&!(actor.status&0x18u)){if(!operations_)return Result::resource_failure;w::ActorRecovery recovery(update_,*operations_);recovery.enter_zero_health(id,0);return current(world_,actor)?Result::completed:Result::unavailable;}
    }catch(...){return Result::resource_failure;}
    if(actor.auxiliary_status&1u){actor.auxiliary_status&=~1u;actor.primary=1;actor.secondary=actor.phase=actor.subphase=0;w::save_action_pose(actor);
        if(update_.record_actor_message(id,gameplay_update::ActorMessageSelector::snapshot)!=gameplay_update::PublicationStatus::completed)return Result::publication_failure;
    }else actor.auxiliary_status|=4u;
    return current(world_,actor)?Result::completed:Result::unavailable;
}
Result ActorOfflineNavigation::enter_route(w::Actor& actor,std::uint32_t inherited_kind,std::int32_t& selected_room)noexcept{
    selected_room=-1;if(actor.status&0x88u)return Result::completed;
    if(!actor.navigation_route)return Result::unavailable;auto& route=*actor.navigation_route;auto& bank=world_.navigation();const auto graph=bank.room(actor.room);if(!graph)return Result::unavailable;
    const auto nearest=n::nearest_node(*graph,{actor.position.x,actor.position.y,actor.position.z},0);if(nearest.status!=n::QueryStatus::completed)return Result::unavailable;
    const auto reversed=n::reverse_edge_action(*graph,nearest.node);if(reversed.status!=n::QueryStatus::completed)return Result::unavailable;
    const auto action=std::uint8_t(reversed.action);if(action!=8&&action!=9&&action!=4&&action!=5&&action!=11)return Result::completed;
    auto source_node=std::int32_t(route.current_node);
    if(action==11){if(actor.room==route.destination_room)source_node=route.destination_node;
        else{const auto asset=bank.asset();if(!asset||route.output.link<0||std::size_t(route.output.link)>=asset->links().size())return Result::unavailable;source_node=asset->links()[std::size_t(route.output.link)].node;}}
    const auto variant=bank.current_variant(actor.room);if(!variant)return Result::unavailable;
    const auto found=n::find_admitted_link(bank,{actor.character,actor.slot,actor.ai_control},actor.room,*variant,source_node,update_.flags().strided_half(actor.room,0));
    if(found.status!=n::QueryStatus::completed)return Result::unavailable;if(!found.index)return Result::completed;
    const auto asset=bank.asset();if(!asset||*found.index>=asset->links().size())return Result::unavailable;const auto& link=asset->links()[*found.index];
    const auto destination=std::bit_cast<std::int8_t>(link.operands[0]);auto destination_node=std::bit_cast<std::int8_t>(link.operands[2]);
    auto entry=std::int32_t(std::bit_cast<std::int8_t>(link.operands[4]));std::uint32_t kind=inherited_kind;
    switch(action){case 8:entry|=128;kind=4;break;case 9:kind=4;break;case 5:kind=2;break;
    case 4:if(std::int32_t(destination)==world_.room){if(!controls_||!matrices_)return Result::unavailable;
        const auto state=door_state(*controls_,*matrices_,update_.flags(),world_.room,std::uint16_t(entry));if(!state)return Result::unavailable;
        if(*state==2||*state==3||*state==5)return Result::completed;if(*state==1||*state==4)kind=1;else if(*state==6)kind=5;}
        break;
    case 11:{const auto normalized=normalize_node(bank,std::uint32_t(std::int32_t(destination)),destination_node);if(!normalized)return Result::unavailable;destination_node=*normalized;kind=6;break;}
    default:break;}
    route.current_node=destination_node;
    const auto destination_room=std::uint16_t(std::int16_t(destination));
    if(destination_room==world_.room){if(!controls_||!models_)return Result::unavailable;
        if(queue_scene_entry_request(world_,actor,*controls_,*models_,update_.flags(),std::uint8_t(entry),std::uint8_t(kind))!=SceneEntryRequestStatus::completed)return Result::unavailable;}
    if(!current(world_,actor))return Result::unavailable;
    actor.room=destination_room;auto result=prepare_actor(actor,1);if(result!=Result::completed)return result;
    if(std::uint8_t(kind)==6&&actor.room==route.destination_room)route.completed=1;
    if(actor.room==world_.room)result=enter_scene_actor(actor);
    else{const auto point=node_position(bank,actor.room,route.current_node);if(!point)return Result::unavailable;actor.position={point->x,point->y,point->z};result=reset_actor_scripts(actor);}
    if(result!=Result::completed)return result;route.previous_action=0;selected_room=destination;return Result::completed;
}
Result ActorOfflineNavigation::command(std::uint32_t selector,std::uint32_t room,std::uint32_t node)noexcept{
    if(closed_||!update_.open())return Result::closed;if(running_)return Result::busy;
    if(!command_ready(selector,room,node))return Result::unavailable;
    const auto actor=world_.primary(selector);if(!actor||!actor->active||!actor->ai_control)return Result::completed;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    actor->room=std::uint16_t(room);actor->navigation_route->current_node=std::bit_cast<std::int8_t>(std::uint8_t(node));
    const auto position=node_position(world_.navigation(),room,std::bit_cast<std::int32_t>(node));if(!position)return Result::unavailable;
    actor->position={position->x,position->y,position->z};gameplay_ai::set_goal(*actor->ai_execution,0);gameplay_ai::set_action(*actor->ai_execution,0);
    if(actor->room!=world_.room){actor->visible=false;actor->auxiliary_status&=0xffff3fffu;actor->color_fade=w::ColorFade{0xffffffffu,0,0};actor->motion_class=0;}
    actor->primary=1;actor->secondary=actor->phase=actor->subphase=0;w::save_action_pose(*actor);
    const auto graph=world_.navigation().room(room);if(!graph)return Result::unavailable;const auto action=n::reverse_edge_action(*graph,std::bit_cast<std::int32_t>(node));
    if(action.status!=n::QueryStatus::completed)return Result::unavailable;if(action.action==-1)return prepare_actor(*actor,1);
    actor->navigation_route->previous_action=std::uint16_t(action.action);actor->navigation_route->destination_node=std::bit_cast<std::int8_t>(std::uint8_t(node));
    actor->navigation_route->destination_room=std::uint16_t(room);
    std::int32_t selected{};const auto entered=enter_route(*actor,room,selected);if(entered!=Result::completed)return entered;
    return selected==-1?Result::completed:prepare_actor(*actor,1);
}
}
