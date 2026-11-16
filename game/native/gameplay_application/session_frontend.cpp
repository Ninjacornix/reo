#include "session_frontend.hpp"
#include "../gameplay_presentation/background.hpp"
#include "../gameplay_presentation/graphics_state.hpp"
#include "../gameplay_presentation/frontend_assets.hpp"
#include "session_audio.hpp"
#include "../gameplay_scenario/text_cache.hpp"
#include "../gameplay_world/world.hpp"
#include <algorithm>

namespace reo::native::gameplay_application {
SessionFrontend::SessionFrontend(gameplay_world::World& world,gameplay_presentation::BackgroundState& background,
                                 gameplay_presentation::GraphicsState& graphics,gameplay_scenario::TextCache& cache,
                                 std::shared_ptr<const reo::assets::Source> source)noexcept:
    world_(world),background_(background),graphics_(graphics),text_cache_(cache),source_(std::move(source)){}
SessionFrontend::~SessionFrontend()=default;
FrontendResult SessionFrontend::begin()noexcept{
    if(closed_)return{FrontendStatus::closed,stage_};
    if(running_||world_.busy())return{FrontendStatus::busy,stage_};
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    if(stage_==FrontendStage::task_pool){
        FrontendColdPool pool;
        for(std::uint16_t i=0;i<pool.next.size();++i)pool.next[i]=i+1<pool.next.size()?std::uint16_t(i+1):FrontendColdPool::end;
        for(std::uint16_t i=0;i<pool.free_indices.size();++i)pool.free_indices[i]=i;
        pool.head=0;pool.count=256;pool_=pool;
        // 1B2340 visits and clears the freshly empty records. With the real
        // cold BSS and 1B22C0 prefix, it has no additional non-stack effect.
        stage_=FrontendStage::background;
    }
    if(stage_==FrontendStage::background){
        if(!background_.select(0))return{FrontendStatus::unavailable,stage_};
        stage_=FrontendStage::graphics_color;
    }
    if(stage_==FrontendStage::graphics_color){
        // 1AF770 is an original no-op. Selector 0x0E updates the actual
        // material-color state, distinct from 1AF6A0's selector 0x14.
        // These four native setters cannot fail or reenter. Keep their
        // original order and share this exact prefix with the draw fixture.
        graphics_.initialize_frontend_prefix();stage_=FrontendStage::graphics_fog;
    }
    if(stage_==FrontendStage::graphics_fog){
        graphics_.initialize_frontend_fog();graphics_.initialize_frontend_draw_controls();stage_=FrontendStage::callbacks;
    }
    if(stage_==FrontendStage::callbacks){
        //1B7EE0: fresh slots A/B enter C and are activated on a later service.
        callback_state_={12,12};callback_initialized_={};stage_=FrontendStage::common_sound;
    }
    if(stage_==FrontendStage::common_sound){
        if(!audio_||!audio_->bound_to(world_)||audio_->load_common().status!=SessionAudioLoadStatus::completed)
            return{FrontendStatus::unavailable,stage_};
        stage_=FrontendStage::textures;
    }
    try{
        if(stage_==FrontendStage::textures){
            if(!assets_)assets_=std::make_unique<gameplay_presentation::FrontendAssets>(source_);
            common_textures_=assets_->load_common_textures();stage_=FrontendStage::font;
        }
        if(stage_==FrontendStage::font){
            auto font=std::make_unique<gameplay_presentation::FontFace>(assets_->load_font());
            //1B4A20 clears the canonical queue only after the font producer.
            text_cache_.reset();font_=std::move(font);stage_=FrontendStage::complete;
        }
    }catch(...){return{FrontendStatus::unavailable,stage_};}
    return{FrontendStatus::completed,stage_};
}
FrontendStatus SessionFrontend::advance_display_callbacks()noexcept{
    if(closed_||world_.closed())return FrontendStatus::closed;
    if(running_||world_.busy())return FrontendStatus::busy;
    if(stage_<FrontendStage::common_sound)return FrontendStatus::unavailable;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    for(unsigned i=0;i<callback_state_.size();++i){
        if(callback_state_[i]==12){callback_state_[i]=8;continue;}
        if(callback_state_[i]!=8)continue;
        if(i==1){gameplay_scenario::advance_display_fade(fade_,callback_initialized_[i]);continue;}
        if(!callback_initialized_[i]){callback_initialized_[i]=1;bars_={};bars_.top={0,0,640,64,0};bars_.bottom={0,384,640,64,0};continue;}
        if(bars_.phase!=1&&bars_.phase!=2)continue;
        if(bars_.remaining>0)--bars_.remaining;
        if(bars_.phase==2&&bars_.remaining==0){bars_.phase=0;continue;}
        if(!bars_.total)return FrontendStatus::unavailable;
        const auto numerator=bars_.phase==1?std::int64_t(bars_.total)-bars_.remaining:bars_.remaining;
        const auto alpha=std::uint8_t((255*numerator)/bars_.total);
        bars_.top.color=(bars_.top.color&0xffffffu)|(std::uint32_t(alpha)<<24);bars_.bottom.color=bars_.top.color;
    }
    return FrontendStatus::completed;
}
FrontendStatus SessionFrontend::close()noexcept{
    if(closed_)return FrontendStatus::completed;
    if(running_||world_.busy())return FrontendStatus::busy;
    font_.reset();common_textures_.reset();assets_.reset();source_.reset();audio_=nullptr;pool_.reset();closed_=true;return FrontendStatus::completed;
}
}
