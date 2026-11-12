#pragma once
#include "../gameplay_world/resource_factory.hpp"
#include "../gameplay_world/inventory.hpp"
#include "../gameplay_world/resource_pose_updates.hpp"
#include "../gameplay_scenario/script_resource_parameters.hpp"
#include "../gameplay_scenario/script_resource_activation.hpp"
#include "../gameplay_effects/periodic_visuals.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
#include "session_resource_import.hpp"
namespace reo::native::gameplay_update {enum class Worker;class Owner;}
namespace reo::native::gameplay_application {
class NativeSession;
class SessionRooms;
class SessionResourceWorkers;
// Immutable capabilities supplied by their real asset importers. These are
// asset inputs, never mutable runtime descriptor/model/actor substitutes.
struct SessionResourceAssets {
    gameplay_scenario::ResourceTemplates templates;
    std::shared_ptr<const gameplay_world::ResourceStaticAssets> models;
    std::shared_ptr<const gameplay_effects::EffectBank> effects;
    std::shared_ptr<const gameplay_collision::delivery::Catalog> contacts;
    gameplay_scenario::content::Bytes item_file;
    std::uint16_t scenario{};
    std::string item_key,model_key;
    // Actual archive branch of the item/static-model asset readers. Selection
    // tables and live descriptor imports remain a separate startup operation.
    static std::shared_ptr<const SessionResourceAssets> load(
        const gameplay_scenario::content::ScenarioArchive&,std::uint16_t,
        std::string_view static_model_key,
        std::shared_ptr<const gameplay_effects::EffectBank>,
        std::shared_ptr<const gameplay_collision::delivery::Catalog>);
};
enum class SessionResourceStatus {completed,busy,closed,unavailable_room,unavailable_assets,resource_failure,pose_failure,unavailable_owner};
// One application's canonical logical resources, primary resource models,
// inventory facade and pose-work domain. The NativeSession owns this lifetime;
// construction is not a substitute for authored descriptor selection/import.
class SessionResources final {
    struct Impl;
public:
    ~SessionResources();
    SessionResources(const SessionResources&)=delete;
    SessionResources& operator=(const SessionResources&)=delete;
    bool bound_to(const NativeSession&)const noexcept;
    SessionResourceStatus close()noexcept;
    gameplay_scenario::SceneResources& descriptors()noexcept;
    const gameplay_scenario::ResourceTemplates& templates()const noexcept;
    gameplay_world::ResourceModels& models()noexcept;
    gameplay_world::ResourceFactory& factory()noexcept;
    gameplay_world::WorldInventory& inventory()noexcept;
    gameplay_world::WorldResourceAttachments& attachments()noexcept;
    gameplay_world::PoseWorkPool& pose_pool()noexcept;
    gameplay_world::ResourcePoseWork& pose_factory()noexcept;
    gameplay_collision::delivery::Packets& contact_packets()noexcept;
    gameplay_effects::PeriodicVisuals& visuals()noexcept;
    bool initialized()const noexcept;
private:
    SessionResources(NativeSession&,std::shared_ptr<const SessionResourceAssets>,std::shared_ptr<SessionRooms>);
    std::unique_ptr<Impl> impl_;
    void provide(gameplay_scenario::Providers&)noexcept;
    ResourceImportReport initialize()noexcept;
    SessionResourceStatus run_worker(gameplay_update::Worker,gameplay_update::Owner&);
    friend class NativeSession;
    friend class SessionResourceWorkers;
};
}
