#include "routing.hpp"
#include <algorithm>
#include <bit>
#include <cmath>

namespace reo::native::gameplay_audio {
namespace {
float unsigned_float(std::uint32_t value) noexcept {
    if (value < 0x80000000u)
        return static_cast<float>(value);
    const float half = static_cast<float>((value >> 1) | (value & 1));
    return half + half;
}
std::uint32_t unsigned_truncate(float value) noexcept {
    if (value < 2147483648.0f)
        return static_cast<std::uint32_t>(value);
    return static_cast<std::uint32_t>(value - 2147483648.0f) | 0x80000000u;
}
std::uint8_t present_byte(std::uint32_t value, std::uint8_t missing) noexcept {
    const auto byte = static_cast<std::uint8_t>(value);
    return byte < 128 ? byte : missing;
}
} // namespace
Result route(const Descriptors& rows, bool requested, std::uint8_t phase, Request request,
             gameplay_session::Random& random, CommandSink& sink) noexcept {
    if (requested && phase != 2)
        return {Status::pending, -1, 0};
    Result result{Status::completed, 0, 0};
    std::array<bool, 128> visited{};
    std::uint32_t gain = request.gain, pan = request.pan;
    while (request.event < rows.size()) {
        if (visited[request.event])
            return {Status::cycle, -1, result.commands};
        visited[request.event] = true;
        const auto& row = rows[request.event];
        const auto port = static_cast<std::uint8_t>(request.bank & 127);
        const auto index = static_cast<std::uint8_t>(request.event & 127);
        const auto group =
            static_cast<std::uint8_t>((row.group & 127) | ((row.replace_group & 1) << 7));
        banks::Command command;
        if (row.type == 0) {
            if (row.pan != 255 || pan == UINT32_MAX)
                pan = row.pan;
            int pitch_delta = 0;
            if (row.pitch_variation) {
                const int sign = (random.request(1) & 1) ? 1 : -1;
                pitch_delta = sign * (random.request(1) % row.pitch_variation) * 32;
            }
            const auto pitch =
                static_cast<std::uint16_t>((row.pitch + 0x2000 + pitch_delta) & 0x3fff);
            const int sign = (random.request(1) & 1) ? 1 : -1;
            const int varied =
                row.gain +
                (row.gain_variation ? sign * (random.request(1) % row.gain_variation) : 0);
            const auto clamped = static_cast<unsigned>(std::clamp(varied, 0, 127));
            if (!request.change && gain == UINT32_MAX)
                gain = clamped;
            else {
                const float scaled = static_cast<float>(clamped) * (unsigned_float(gain) / 128.0f);
                // Finite unsigned source profile; high-bit conversion preserves
                // the original two-step rounding, including caller gain -1.
                if (!std::isfinite(scaled) || scaled < 0 || scaled >= 4294967296.0f)
                    return {Status::numeric_domain, -1, result.commands};
                gain = unsigned_truncate(scaled);
            }
            if (request.change)
                command = banks::ChangeRequest{
                    port, index, group, present_byte(gain, 255), present_byte(pan, 255), pitch};
            else
                command = banks::StartRequest{
                    port,  index,      group, present_byte(gain, 127), present_byte(pan, 64),
                    pitch, request.tag};
        } else if (row.type == 1)
            command = banks::CancelRequest{port, index, group};
        else
            return result;
        // The original collapses a producer failure to return0. Keep that
        // legacy return while exposing failure explicitly to native callers.
        if (!sink.apply(command))
            return {Status::command_failed, 0, result.commands};
        ++result.commands;
        if (row.next == 255 || (!request.change && row.next == request.event))
            return result;
        request.event = row.next;
    }
    return result;
}
} // namespace reo::native::gameplay_audio
