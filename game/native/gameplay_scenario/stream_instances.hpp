#pragma once
#include "stream_channels.hpp"
#include "game/native/adxt_control_owner/owner.hpp"
#include "game/native/afs_source_range/afs_source_range.hpp"
#include <memory>
#include <string>
#include <unordered_map>

namespace reo::native::gameplay_scenario {
struct StreamAsset {StreamStatus status{StreamStatus::missing_asset};std::shared_ptr<const resources::ByteView> view;};
// Immutable archive indexes prepared by the native resource owner before use.
// Resolution is metadata-only; the source worker loads a retained member body.
class StreamAssetCatalog final {
public:
    StreamAssetCatalog();
    StreamAssetCatalog(const StreamAssetCatalog&)=delete;
    StreamAssetCatalog& operator=(const StreamAssetCatalog&)=delete;
    bool add(std::uint32_t archive,std::shared_ptr<const afs_source_range::Archive>,std::string validated_identity);
    void seal()noexcept{sealed_=true;}
    bool sealed()const noexcept{return sealed_;}
    StreamAsset resolve(StreamRequest)const noexcept;
private:
    struct Entry {std::shared_ptr<const afs_source_range::Archive> archive;std::string identity;};
    std::unordered_map<std::uint32_t,Entry> archives_;
    std::uint64_t scope_id_{};
    bool sealed_{};
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
        std::shared_ptr<const StreamAssetCatalog>,std::array<std::uint8_t,3> mixer_order)noexcept;
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
    // Signal native destruction; pending retirements continue under the shared
    // Owner/service worker. This does not join or stop an unrelated outer owner.
    StreamStatus close()noexcept;
    adxt_instances::Observation inspect(std::uint8_t)noexcept;
private:
    StreamInstances(std::shared_ptr<adxt_control_owner::Owner>,std::array<StreamInstanceConfig,3>,std::shared_ptr<const StreamAssetCatalog>);
    std::shared_ptr<adxt_control_owner::Owner> owner_;
    std::array<StreamInstanceConfig,3> config_;
    std::array<adxt_instances::Key,3> keys_{};
    std::array<bool,3> constructed_{},started_{};
    std::shared_ptr<const StreamAssetCatalog> catalog_;
    bool closed_{};
};
} // namespace reo::native::gameplay_scenario
