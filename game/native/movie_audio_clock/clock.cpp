#include "clock.hpp"
#include <bit>
#include <stdexcept>
#include <utility>

namespace reo::native::movie_audio_clock {
namespace {
std::uint64_t extend(std::uint32_t value) noexcept{return static_cast<std::uint64_t>(static_cast<std::int64_t>(std::bit_cast<std::int32_t>(value)));}
bool less(std::uint32_t left,std::uint32_t right) noexcept{return std::bit_cast<std::int32_t>(left)<std::bit_cast<std::int32_t>(right);}
bool eligible(std::uint32_t actual) noexcept{return actual==4 || actual==0xFFFFFFFCu || actual==6 || actual==0xFFFFFFFAu;}
}
Clock::Clock(State state,std::shared_ptr<AudioSource> audio,std::shared_ptr<HelperClock> helper)
    :state_(state),audio_(std::move(audio)),helper_(std::move(helper)){
    if(!audio_ || !helper_)throw std::invalid_argument("Owned audio and helper-clock providers required");
}
Status Clock::set_pause(std::uint32_t value) noexcept {
    if(busy_)return Status::busy;
    filter::pause(state_.filter,value);return Status::completed;
}
Status Clock::add_baseline(Words value) noexcept {
    if(busy_)return Status::busy;
    const auto result=filter::baseline(state_.filter,{extend(value.numerator),extend(value.denominator)});
    if(result==filter::Status::completed)return Status::completed;
    health_={Status::filter_failure,Stage::filter,ProviderStatus::completed,result};return Status::filter_failure;
}
Result Clock::execute(Operation operation,std::uint32_t actual,Words prior) noexcept {
    if(busy_)return{Status::busy,prior,false,false,0};
    if(static_cast<unsigned>(operation)>static_cast<unsigned>(Operation::envelope))return{Status::invalid_input,prior,false,false,0};
    busy_=true;struct Exit{bool& busy;~Exit(){busy=false;}}exit{busy_};
    health_={};
    const bool slot=operation==Operation::slot;
    Result result{Status::completed,prior,false,slot,0};
    if(slot && !eligible(actual)){result.words={0xFFFFFFFFu,1};result.written=true;return result;}
    if(slot && actual!=4){result.words=state_.cache;result.written=true;return result;}
    const auto audio=audio_;const auto helper=helper_;
    const auto failure=[&](Stage stage,ProviderStatus value){
        health_={Status::provider_failure,stage,value,filter::Status::completed};
        result.status=Status::provider_failure;result.return_defined=false;return result;
    };
    std::uint8_t raw_status{};
    auto status=audio->status(raw_status);
    if(status!=ProviderStatus::completed)return failure(Stage::audio_status,status);
    state_.diagnostic=static_cast<std::uint32_t>(static_cast<std::int32_t>(std::bit_cast<std::int8_t>(raw_status)));
    Words sample;status=audio->estimate(sample);
    if(status!=ProviderStatus::completed)return failure(Stage::audio_estimate,status);
    filter::Pair helper_sample;
    status=helper->counter(helper_sample.numerator);
    if(status!=ProviderStatus::completed)return failure(Stage::helper_counter,status);
    status=helper->frequency(helper_sample.denominator);
    if(status!=ProviderStatus::completed)return failure(Stage::helper_frequency,status);
    filter::Pair input{extend(sample.numerator),extend(sample.denominator)};
    const auto filtered=filter::process(state_.filter,input,helper_sample);
    if(filtered.status!=filter::Status::completed){
        health_={Status::filter_failure,Stage::filter,ProviderStatus::completed,filtered.status};
        result.status=Status::filter_failure;result.return_defined=false;return result;
    }
    state_.filter_observed|=filtered.observed;
    const Words words{static_cast<std::uint32_t>(filtered.output.numerator),static_cast<std::uint32_t>(filtered.output.denominator)};
    if(slot){if(less(state_.cache.numerator,words.numerator))state_.cache=words;result.words=state_.cache;}
    else result.words=words;
    result.written=true;return result;
}
selected::Reply Clock::query(selected::State snapshot,Words prior) noexcept {
    const auto value=execute(Operation::slot,snapshot.counter.actual,prior);
    selected::Reply reply;reply.words=value.words;reply.status=value.callback_status;
    reply.numerator=reply.denominator=value.status==Status::completed && value.written;
    reply.admitted=value.status==Status::completed;
    return reply;
}
}
