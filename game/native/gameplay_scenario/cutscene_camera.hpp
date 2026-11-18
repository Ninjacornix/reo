#pragma once
#include "camera_curves.hpp"
#include "fog.hpp"
#include <memory>
#include <span>
#include <vector>

namespace reo::native::gameplay_scenario {
struct CutscenePlaybackState;
class CutsceneDescriptor;
struct CameraSelectionKey {std::uint16_t frame{};std::int16_t camera{};std::uint8_t fog{};};
class PreparedCameraTracks final {
public:
    static std::shared_ptr<const PreparedCameraTracks> import(std::span<const std::byte> selection,
        std::span<const std::array<std::span<const std::byte>,2>> streams);
    const auto& selection()const noexcept{return selection_;}
    const auto& streams()const noexcept{return streams_;}
private:
    std::vector<CameraSelectionKey> selection_;
    std::vector<std::array<std::vector<CameraKey>,2>> streams_;
};
std::shared_ptr<const PreparedCameraTracks> prepare_camera_tracks(const CutsceneDescriptor&);
enum class CutsceneCameraStatus {completed,unavailable,no_memory};
struct CameraKeyLocation {std::size_t group{},stream{},record{};friend bool operator==(const CameraKeyLocation&,const CameraKeyLocation&)=default;};
// The sole controller state is borrowed, including its simulation frame and
// selection/end bytes. Authored stream cursors live here; camera parameters
// are borrowed from the same owner as ordinary gameplay camera evaluation.
class CutsceneCamera final {
public:
    CutsceneCamera(CutscenePlaybackState&,Fog&,CameraParameters&) noexcept;
    CutsceneCamera(const CutsceneCamera&)=delete;
    CutsceneCamera& operator=(const CutsceneCamera&)=delete;
    CutsceneCameraStatus install(std::shared_ptr<const PreparedCameraTracks>) noexcept;
    CutsceneCameraStatus select(std::uint8_t clock_mode) noexcept;
    bool sample() noexcept;
    void clear_bindings()noexcept{bindings_={};}
    CameraParameters& parameters()noexcept{return parameters_;}
    const CameraParameters& parameters()const noexcept{return parameters_;}
    bool bound_to(const CutscenePlaybackState& state)const noexcept{return &state_==&state;}
    std::optional<std::size_t> selection_cursor()const noexcept{return selection_;}
    std::optional<std::size_t> cursor(std::size_t group,std::size_t stream)const noexcept;
    const auto& bindings()const noexcept{return bindings_;}
private:
    CutscenePlaybackState& state_;Fog& fog_;CameraParameters& parameters_;
    std::shared_ptr<const PreparedCameraTracks> tracks_;
    std::optional<std::size_t> selection_;
    std::vector<std::array<std::optional<std::size_t>,2>> positions_;
    std::array<std::optional<CameraKeyLocation>,2> bindings_;
};
} // namespace reo::native::gameplay_scenario
