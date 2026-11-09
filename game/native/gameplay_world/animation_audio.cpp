#include "animation_audio.hpp"
#include "footwear.hpp"
#include "../gameplay_audio/scenario_cues.hpp"
#include "../animation/model.hpp"
#include "../gameplay_contact_world/contacts.hpp"
#include <bit>
#include <stdexcept>
namespace reo::native::gameplay_world::animation_events {
BasicAudio::BasicAudio(World& world, gameplay_audio::Owner& owner,
                       const gameplay_audio::SpatialContext& spatial,
                       gameplay_scenario::SceneResources& resources,
                       const gameplay_scenario::ResourceTemplates& templates)
    : world_(world), owner_(owner), spatial_(spatial), resources_(resources),
      templates_(templates) {
    if (world_.closed() || !owner_.bound_to(world_.session().random))
        throw std::invalid_argument(
            "Native animation audio requires the canonical World RNG/owner");
}
BasicAudio::BasicAudio(World& world,gameplay_audio::Owner& owner,const gameplay_audio::SpatialContext& spatial,
    gameplay_scenario::SceneResources& resources,const gameplay_scenario::ResourceTemplates& templates,
    gameplay_contact_world::RoomResources& rooms):BasicAudio(world,owner,spatial,resources,templates){rooms_=&rooms;}
void BasicAudio::admit(const Actor& actor) const {
    if (world_.closed() || !owner_.bound_to(world_.session().random) || !world_.identity_of(actor))
        throw std::runtime_error(
            "Native animation audio actor/owner unavailable, foreign or retired");
}
void BasicAudio::request(const Actor& actor, std::uint32_t bank, std::uint32_t event) {
    last_ = owner_.positional({bank, event}, {actor.position.x, actor.position.y, actor.position.z},
                              spatial_, 1);
}
void BasicAudio::actor(Actor& actor, std::uint32_t event, bool alternate) {
    admit(actor);
    last_.reset();
    if (actor.category != (alternate ? 1 : 0))
        return;
    // Incoming source a2 owner is overwritten by1AC7F0/1ACB60 before any use;
    // it is not the separate t2 program-offset tag (zero on these routes).
    request(actor, alternate ? 13u : unsigned(actor.slot) + 4u, event);
}
void BasicAudio::resource(Actor& actor, std::uint16_t event) {
    admit(actor);
    last_.reset();
    if (actor.category != 0) {
        if (event == 0)
            this->actor(actor, 6, true);
        else if (event == 6)
            this->actor(actor, 8, true);
        else if (event == 0x19)
            this->actor(actor, 9, true);
        return;
    }
    const auto id = resources_.slot(actor.selected_resource);
    if (!id)
        throw std::runtime_error("Native animation audio resource slot unavailable");
    const auto descriptor = resources_.get(*id);
    if (!descriptor)
        throw std::runtime_error("Native animation audio resource identity stale");
    if (!descriptor->active || descriptor->template_index == 255)
        return;
    const auto index = descriptor->template_index;
    const auto& state = templates_.state();
    if (index >= state.templates.size())
        throw std::out_of_range("Native animation audio resource template profile");
    const auto selector = std::bit_cast<std::int8_t>(
        std::to_integer<std::uint8_t>(state.templates[index].encoded[14]));
    if (selector == -1)
        return;
    // The original selector only qualifies this request; it is not an event or
    // bank number. All other signed byte values take the same identity bank.
    request(actor, unsigned(actor.slot) + 8u, event);
}
void BasicAudio::surface(Actor& actor, std::int8_t kind) {
    admit(actor);
    last_.reset();
    surface_count_=0;
    std::uint16_t cue;
    switch(kind){
        case 0:case 1:cue=std::uint16_t(2*kind+(world_.session().random.request(1)&1));break;
        case 2:cue=4;break;
        case 3:cue=5;break;
        case 4:cue=std::uint16_t(6+(world_.session().random.request(1)&1));break;
        default:throw std::domain_error("Original surface kind depends on an unassigned caller register");
    }
    bool listener_position{};
    if(actor.category==0){cue=std::uint16_t(int(cue)+footwear_offset(actor));listener_position=actor.motion_class==0x2b&&actor.secondary==0x6d;}
    if(!rooms_)throw std::runtime_error("Native animation surface room owner unavailable");
    const auto room=rooms_->retain(world_.room);
    if(!room||!room->identity()||!room->current(room->identity())||room->room_number()!=world_.room)throw std::runtime_error("Native animation surface room lease unavailable");
    const gameplay_collision::Vec3 position{actor.position.x,actor.position.y,actor.position.z};
    const auto selector=room->geometry().regions.select(position);
    const gameplay_audio::Vector point=listener_position?spatial_.listener:gameplay_audio::Vector{position.x,position.y,position.z};
    const auto emit=[&](std::uint8_t tag){
        const auto result=owner_.positional({3,cue,UINT32_MAX,UINT32_MAX,tag},point,spatial_,1);
        surface_results_[surface_count_++]=result;last_=result;
    };
    emit(std::uint8_t(selector));
    if(selector>>8)emit(std::uint8_t(selector>>8));
}
void BasicAudio::node(Actor& actor, std::uint16_t kind) {
    admit(actor);
    last_.reset();
    if(!models_)throw std::runtime_error("Native animation node audio scene owner unavailable");
    const auto sound=models_->sound_resource(actor.scene_model);
    if(!sound)throw std::runtime_error("Native animation node audio scene model unavailable");
    unsigned cue=kind==0?11u:kind==1?13u:0u;
    if(*sound==1)cue+=8;
    if(!cue)return;
    const auto pose=actor.model?actor.model->retain():nullptr;
    if(!pose||pose->joints.size()<=15)throw std::runtime_error("Native animation node15 audio pose unavailable");
    const auto& node=pose->joints[15];
    last_=owner_.positional({1,cue},{node[3][0],node[3][1],node[3][2]},spatial_,1);
}
void BasicAudio::position(Actor& actor, std::uint32_t event) {
    admit(actor);
    last_.reset();
    auto& session=world_.session();
    if(!session.scenario)throw std::runtime_error("Native scenario audio identity unavailable");
    const auto cue=gameplay_audio::scenario_cue(*session.scenario,event);
    if(cue==255)return;
    request(actor,2,cue);
    session.last_scenario_audio=std::uint16_t(cue);
}
} // namespace reo::native::gameplay_world::animation_events
