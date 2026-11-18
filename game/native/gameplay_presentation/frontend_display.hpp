#pragma once
#include "background.hpp"
#include "texture.hpp"
#include "windows_vblank.hpp"
#include <cstdint>
#include <vector>
namespace reo::native::gameplay_world {class World;}
namespace reo::native::gameplay_presentation {
// Window-bound pre-room CPU presentation. The window, canonical background
// and real monitor clock outlive this owner. Its pending surface represents
// actual native drawing, and is submitted before the following loading quad.
class FrontendDisplay final {
public:
    FrontendDisplay(gameplay_world::World&,void* window,WindowsVBlank&,const BackgroundState&);
    bool bound_to(const void* window,const WindowsVBlank& clock)const noexcept;
    bool bound_to(const gameplay_world::World&)const noexcept;
    bool drain()noexcept;
    //18D6C0 equivalent for this synchronous native renderer: publish any
    // staged surface and wait for GDI completion. Retained immutable assets
    // have no movable guest heap tokens or DMA-chain pointers to relocate.
    bool quiesce(const gameplay_world::World&)noexcept;
    bool loading_pass(const Texture&)noexcept;
    std::uint64_t loading_passes()const noexcept{return loading_passes_;}
    std::uint64_t resource_barriers()const noexcept{return resource_barriers_;}
    bool pending_surface()const noexcept{return pending_;}
private:
    bool submit()noexcept;
    gameplay_world::World& world_;
    void* window_{};
    WindowsVBlank& clock_;
    const BackgroundState& background_;
    std::vector<std::uint32_t> pixels_;
    std::uint64_t loading_passes_{},resource_barriers_{};
    bool initialized_{},pending_{},running_{};
};
}
