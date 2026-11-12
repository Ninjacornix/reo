#pragma once
#include "model_attachments.hpp"
#include "auxiliary_actors.hpp"
namespace reo::native::gameplay_world {
enum class ActorModelPassStatus {completed,busy,closed,unavailable};
struct ActorModelsPublished {
    ActorModelPassStatus status{ActorModelPassStatus::completed};
    std::size_t visited{},published{};
    actors::EntityId failed{};
};
// Actual3769F0 eight primary slots and376AE0 auxiliary linked-list pass.
// Both consume canonical Actor/model/resource ownership at their own frame
// positions. Visibility and camera filtering are not gates in either body.
class ActorModelPasses final {
public:
    ActorModelPasses(World&,const ModelCorrectionScales&,WorldResourceAttachments&,
                     std::shared_ptr<const gameplay_collision::response::Grid> = {});
    ~ActorModelPasses();
    ActorModelPasses(const ActorModelPasses&)=delete;
    ActorModelPasses& operator=(const ActorModelPasses&)=delete;
    ActorModelsPublished primary();
    ActorModelsPublished auxiliary();
    ActorModelPassStatus close()noexcept;
private:
    World& world_;
    const ModelCorrectionScales& scales_;
    WorldResourceAttachments& attachments_;
    std::shared_ptr<const gameplay_collision::response::Grid> floors_;
    bool running_{},closed_{};
};
}
