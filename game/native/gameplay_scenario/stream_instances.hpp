#pragma once
#include "stream_channels.hpp"
#include "game/native/adxt_control_owner/owner.hpp"
#include "game/native/afs_source_range/afs_source_range.hpp"
#include <memory>
#include <optional>
#include <string>
#include <unordered_map>

namespace reo::native::audio_clip_loader {class Loader;}
namespace reo::native::gameplay_scenario {
class StreamVoiceQueue;
class ActorVoiceArchiveAssets;
struct StreamQueueObservation {StreamStatus status{StreamStatus::unbound};std::uint32_t preparing{},queued{},registered_assets{};std::uint64_t accepted{},submitted{};bool source_submitted{},decoder_ended{},failed{};};
struct StreamAsset {StreamStatus status{StreamStatus::missing_asset};std::shared_ptr<const resources::ByteView> view;};
// Immutable archive indexes prepared by the native resource owner before use.
// Resolution is metadata-only; the source worker loads a retained member body.
class StreamAssetCatalog final {
public:
    StreamAssetCatalog();
    StreamAssetCatalog(const StreamAssetCatalog&)=delete;
    StreamAssetCatalog& operator=(const StreamAssetCatalog&)=delete;
    bool add(std::uint32_t archive,std::shared_ptr<const afs_source_range::Archive>,std::string validated_identity);
    bool add_actor_voice_archives(const ActorVoiceArchiveAssets&)noexcept;
    void seal()noexcept{sealed_=true;}
    bool sealed()const noexcept{return sealed_;}
    StreamAsset resolve(StreamRequest)const noexcept;
    std::shared_ptr<const afs_source_range::Archive> actor_voice_archive(std::uint8_t character)const noexcept;
private:
    struct Entry {std::shared_ptr<const afs_source_range::Archive> archive;std::string identity;};
    std::unordered_map<std::uint32_t,Entry> archives_;
    std::uint64_t scope_id_{};
    bool sealed_{};
    bool actor_voice_assets_{};
};
struct StreamInstanceConfig {adxt_instances::Construction construction;adxt_phased_player::Config player;};
class StreamInstances;
struct StreamInstancesOpen {StreamStatus status{StreamStatus::fault};std::unique_ptr<StreamInstances> value;};
// Sole engine controller for three freshly constructed native instances. Source
// workers share only the canonical Owner's serialized Instances admission.
// The caller supplies an explicit mixer permutation; no physical/channel order
// is inferred. The factory requires an initially empty native Owner.
class StreamInstances final:public StreamBackend {
public:
    static StreamInstancesOpen create(std::shared_ptr<adxt_control_owner::Owner>,std::array<StreamInstanceConfig,3>,
        std::shared_ptr<const StreamAssetCatalog>,std::array<std::uint8_t,3> mixer_order,std::shared_ptr<audio_clip_loader::Loader> voice_loader={})noexcept;
    ~StreamInstances();
    StreamInstances(const StreamInstances&)=delete;StreamInstances& operator=(const StreamInstances&)=delete;
    StreamValue phase(std::uint8_t)noexcept override;
    StreamStatus start(std::uint8_t,StreamRequest,std::uint32_t tick)noexcept override;
    StreamStatus stop(std::uint8_t)noexcept override;
    StreamStatus pause(std::uint8_t,bool,std::uint32_t tick)noexcept override;
    StreamStatus attenuation(std::uint8_t,std::int32_t)noexcept override;
    StreamStatus service(std::uint32_t tick)noexcept override;
    StreamValue instance_available(std::uint8_t)noexcept override;
    StreamValue start_ready(std::uint8_t)noexcept override;
    StreamStatus start_inhibit(std::uint8_t,bool)noexcept override;
    StreamStatus prepare_cues(std::uint8_t,std::span<const StreamCue>,std::uint32_t)noexcept override;
    StreamStatus activate_actor_archive(std::uint8_t slot,std::uint8_t character)noexcept override;
    StreamStatus clear_actor_archives()noexcept override;
    StreamValue actor_archive_marker(std::uint8_t slot)noexcept override;
    StreamSourceResult actor_voice_source(std::uint8_t slot,std::int32_t member)noexcept override;
    StreamQueueObservation inspect_queue(std::uint8_t)noexcept;
    // Signal native destruction; pending retirements continue under the shared
    // Owner/service worker. This does not join or stop an unrelated outer owner.
    StreamStatus close()noexcept;
    adxt_instances::Observation inspect(std::uint8_t)noexcept;
private:
    StreamInstances(std::shared_ptr<adxt_control_owner::Owner>,std::array<StreamInstanceConfig,3>,std::shared_ptr<const StreamAssetCatalog>,std::shared_ptr<audio_clip_loader::Loader>);
    StreamStatus retire_queue(std::uint8_t,adxt_instances::Instances&)noexcept;
    StreamStatus service_queues(adxt_instances::Instances&,std::uint32_t)noexcept;
    StreamValue queued_phase(std::uint8_t,bool ready)noexcept;
    std::shared_ptr<adxt_control_owner::Owner> owner_;
    std::array<StreamInstanceConfig,3> config_;
    std::array<adxt_instances::Key,3> keys_{};
    std::array<bool,3> constructed_{},started_{};
    std::shared_ptr<const StreamAssetCatalog> catalog_;
    std::shared_ptr<audio_clip_loader::Loader> voice_loader_;
    std::array<std::shared_ptr<StreamVoiceQueue>,3> voice_queues_;
    struct ActorArchive {std::uint8_t marker{};std::shared_ptr<const afs_source_range::Archive> archive;};
    // Source1BA440/1BA330 own five ordinary selections. The separate index5
    // NPC/common marker is not inferred or initialized by these functions.
    std::array<std::optional<ActorArchive>,5> actor_archives_;
    bool closed_{};
};
} // namespace reo::native::gameplay_scenario
