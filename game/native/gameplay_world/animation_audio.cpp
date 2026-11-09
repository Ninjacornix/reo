#include "animation_audio.hpp"
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
void BasicAudio::surface(Actor& actor, std::int8_t) {
    admit(actor);
    last_.reset();
    throw std::runtime_error("Native animation surface-audio region/variant owner not implemented");
}
void BasicAudio::node(Actor& actor, std::uint16_t) {
    admit(actor);
    last_.reset();
    throw std::runtime_error("Native animation node/surface audio profile not implemented");
}
void BasicAudio::position(Actor& actor, std::uint32_t) {
    admit(actor);
    last_.reset();
    throw std::runtime_error(
        "Native animation scenario-remapped audio/cache owner not implemented");
}
} // namespace reo::native::gameplay_world::animation_events
