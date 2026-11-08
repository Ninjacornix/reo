#pragma once
#include "../movie_audio_clock/session_source.hpp"
#include "../adxt_control_owner/owner.hpp"
#include "../adxt_instances/source_key.hpp"
#include <atomic>

namespace reo::native::movie_instance_audio {
namespace audio=movie_audio_clock;
namespace owner=adxt_control_owner;
namespace instances=adxt_instances;
struct Capture {
    audio::ProviderStatus status{audio::ProviderStatus::invalid_key};
    std::shared_ptr<audio::ControlledSource> source;
};
// Movie queries/controls borrow the existing canonical owner. Neither an
// underlying Session nor its mutable keys escape. The source token expires on
// stop/replacement even while the stable public ADXT instance survives.
class Source final:public audio::ControlledSource,public std::enable_shared_from_this<Source> {
public:
    [[nodiscard]] static Capture capture(std::shared_ptr<owner::Owner>,const instances::Key&,
                                        std::shared_ptr<audio::ServiceTick>)noexcept;
    audio::ProviderStatus status(std::uint8_t&)noexcept override;
    audio::ProviderStatus estimate(audio::Words&)noexcept override;
    audio::ProviderStatus sample_frequency(std::uint32_t&)noexcept override;
    audio::ProviderStatus pause(std::uint32_t)noexcept override;
    audio::ProviderStatus discard(std::uint32_t,std::uint32_t&)noexcept override;
private:
    enum class Operation {status,estimate,frequency,pause,discard};
    Source(std::shared_ptr<owner::Owner>,instances::SourceKey,std::shared_ptr<audio::ServiceTick>);
    audio::ProviderStatus execute(Operation,std::uint32_t,audio::Words*,std::uint32_t*,std::uint8_t*)noexcept;
    std::shared_ptr<owner::Owner> owner_;
    instances::SourceKey key_;
    std::shared_ptr<audio::ServiceTick> tick_;
    std::atomic_flag busy_=ATOMIC_FLAG_INIT;
};
}
