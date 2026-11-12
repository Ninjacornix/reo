#include "cutscene_camera.hpp"
#include "cutscene_descriptor.hpp"
namespace reo::native::gameplay_scenario {
std::shared_ptr<const PreparedCameraTracks> prepare_camera_tracks(const CutsceneDescriptor& descriptor){
    std::vector<std::array<std::span<const std::byte>,2>> streams;
    streams.reserve(descriptor.camera_streams().size());
    for(const auto& pair:descriptor.camera_streams())streams.push_back({descriptor.section(pair[0]),descriptor.section(pair[1])});
    return PreparedCameraTracks::import(descriptor.section(descriptor.camera_selection()),streams);
}
}
