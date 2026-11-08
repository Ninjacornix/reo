#pragma once
#include <cstdint>
class PS2Runtime;
namespace ps2_syscalls {
    enum class RnaMetadataStatusV1 : uint32_t {
        ok, control_refused, unselected, invalid_metadata, playing_legacy, failed
    };
    struct RnaMetadataResultV1 {
        RnaMetadataStatusV1 status{RnaMetadataStatusV1::control_refused};
        uint32_t rows{}, requests{}, bad_handle{};
    };
    RnaMetadataResultV1 refreshMutedRnaMetadataV1(PS2Runtime*) noexcept;
}
