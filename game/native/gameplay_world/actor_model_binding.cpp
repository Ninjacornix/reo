#include "actor_assets.hpp"
#include "../animation/playback.hpp"
#include <utility>

namespace reo::native::gameplay_world {
bool bind_actor_model_asset(World& world,const actors::EntityId& id,
                            std::shared_ptr<const ActorModelAsset> asset) {
    const auto actor = world.resolve(id);
    if (!actor || !asset) return false;
    auto model = asset->make_instance();
    auto playback = model ? std::make_shared<animation::Playback>(model) : nullptr;
    actor->model = std::move(model);
    actor->animation = std::move(playback);
    actor->constraints.reset();
    actor->model_asset = std::move(asset);
    actor->collision.joint_two_position.reset();
    actor->collision.pose_ready = false;
    return true;
}
}
