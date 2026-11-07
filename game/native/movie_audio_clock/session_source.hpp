#pragma once
#include "clock.hpp"
#include "../adxt_control_session/control_session.hpp"

namespace reo::native::movie_audio_clock {
class ServiceTick {
public:
    virtual ~ServiceTick()=default;
    // Actual original service-tick domain, supplied by its owner. A display
    // count, helper-counter sample or invented fixed-rate increment is invalid.
    virtual ProviderStatus read(std::uint32_t&) noexcept=0;
};
// Retains the actual session, opaque stream generation and service-tick owner.
// It never opens a device, services a group or retires the stream implicitly.
class SessionSource final:public AudioSource {
public:
    SessionSource(std::shared_ptr<adxt_control_session::Session>,adxt_control_session::Key,std::shared_ptr<ServiceTick>);
    ProviderStatus status(std::uint8_t&) noexcept override;
    ProviderStatus estimate(Words&) noexcept override;
private:
    std::shared_ptr<adxt_control_session::Session> session_;
    adxt_control_session::Key key_;
    std::shared_ptr<ServiceTick> tick_;
};
}
