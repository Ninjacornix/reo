#include "context.hpp"
#include <array>
#include <bit>
namespace reo::native::movie_timing_context {
namespace {
constexpr std::array<std::uint32_t,9> rates{29970,23976,24000,25000,29970,30000,50000,59940,60000};
Result completed(bool defined=true){Result result;result.status=Status::completed;result.return_defined=defined;return result;}
}
Result Context::audio_pause(std::uint32_t value)noexcept {
    auto& state=*audio_commands_;state.stage=AudioStage::pause;state.provider=controlled_audio_->pause(value);
    if(state.provider!=audio::ProviderStatus::completed)return{Status::provider_failure};
    state.stage=AudioStage::filter;
    if(audio_->set_pause(value)!=audio::Status::completed)return{Status::provider_failure};
    state.stage=AudioStage::none;auto result=completed();result.return_defined=false;return result;
}
Result Context::audio_control(Operation operation,std::uint32_t value)noexcept {
    if(!audio_commands_ || !buffering_ || !controlled_audio_)return{Status::invalid_input};
    auto& state=*audio_commands_;state.stage=AudioStage::none;state.provider=audio::ProviderStatus::completed;
    if(operation==Operation::audio_requested){
        state.requested_pause=value;
        if(value==0 && snapshot().facts.pause==1)return completed(false);
        return audio_pause(value);
    }
    if(operation==Operation::audio_temporary){
        if(value==0 && state.requested_pause==1)return completed(false);
        return audio_pause(value);
    }
    if(!state.channel || !buffering_->audio || !state.decoder)return completed();
    if(value==0){
        state.residual=0;
        if(state.requested_pause==1)return completed(false);
        return audio_pause(0);
    }
    if(value==1)return audio_pause(1);
    if(value!=2)return completed();
    state.stage=AudioStage::status;std::uint8_t phase{};state.provider=controlled_audio_->status(phase);
    if(state.provider!=audio::ProviderStatus::completed)return{Status::provider_failure};
    if(phase<2){state.stage=AudioStage::none;return completed();}
    state.stage=AudioStage::frequency;std::uint32_t frequency{};state.provider=controlled_audio_->sample_frequency(frequency);
    if(state.provider!=audio::ProviderStatus::completed)return{Status::provider_failure};
    const auto rate=snapshot().facts.rate;if(rate>=rates.size())return{Status::invalid_input};
    const auto product=std::int64_t{std::bit_cast<std::int32_t>(frequency)}*(rate?1000:0);
    const auto desired=static_cast<std::uint32_t>(product/rates[rate]);
    const auto quantity=desired+state.residual;std::uint32_t returned{};
    state.stage=AudioStage::discard;state.provider=controlled_audio_->discard(quantity,returned);
    if(state.provider!=audio::ProviderStatus::completed)return{Status::provider_failure};
    state.residual=quantity-returned;state.stage=AudioStage::filter;
    if(audio_->add_baseline({desired,frequency})!=audio::Status::completed)return{Status::numeric_failure};
    state.stage=AudioStage::none;return completed();
}
}
