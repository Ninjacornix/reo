#pragma once
#include "instances.hpp"

namespace reo::native::adxt_instances {
// These two unforgeable weak identities cover both the stable public instance
// and its replaceable source. The Session's source-slot generation exhausts
// rather than wrapping. A diagnostic start counter is not source authority.
class SourceKey final {
public:
    SourceKey()=default;
private:
    friend class Instances;
    Key instance_;
    control::Key source_;
};
struct SourceCapture {
    Status status{Status::invalid_key};
    SourceKey key;
};
}
