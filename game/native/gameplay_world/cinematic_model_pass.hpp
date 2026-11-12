#pragma once
#include "model_poses.hpp"
namespace reo::native::gameplay_world {
enum class CinematicModelStatus {completed,busy,closed};
struct CinematicModelsPublished {
    CinematicModelStatus status{CinematicModelStatus::completed};
    std::size_t visited{},published{};
};
//5ECB80's separate temporary-player model pass. Borrowed World/scales must
// outlive this synchronous consumer. No render submission or clock tick occurs.
class CinematicModelPass final {
public:
    CinematicModelPass(World& world,const ModelCorrectionScales& scales):world_(world),scales_(scales){}
    ~CinematicModelPass();
    CinematicModelPass(const CinematicModelPass&)=delete;
    CinematicModelPass& operator=(const CinematicModelPass&)=delete;
    // Failures retain earlier publications and release the traversal guard.
    CinematicModelsPublished run();
private:
    World& world_;
    const ModelCorrectionScales& scales_;
    bool running_{};
};
}
