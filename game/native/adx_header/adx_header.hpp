#pragma once
#include "../adxt_refill/adxt_refill.hpp"

#include <array>
#include <cstdint>
#include <memory>
#include <optional>
#include <span>

namespace reo::native::adx_header {

enum class Status { completed, unsupported_profile, unsupported_fp_environment,
    invalid_input, inactive, reentrant_call, source_failure, lease_held };
enum class Diagnostic { ahx_without_plugin, unsupported_header };
using Key = std::array<std::uint16_t,3>;
struct KeyContext { std::uint32_t module_references{}; Key fallback{}; friend bool operator==(const KeyContext&,const KeyContext&)=default; };
struct Base {
    std::int16_t header_bytes{};
    std::int8_t encoding{}, bits{}, block_bytes{}, channels{};
    std::uint32_t frequency{}, total_samples{};
    std::int32_t samples_per_block{};
    friend bool operator==(const Base&,const Base&)=default;
};
struct Version { std::uint8_t number{}, control{}; };
struct Histories { std::array<std::int16_t,2> first{},second{}; friend bool operator==(const Histories&,const Histories&)=default; };
struct Loop {
    std::int32_t count{};
    std::uint16_t enabled{}, index{};
    std::array<std::uint32_t,4> positions{};
    friend bool operator==(const Loop&,const Loop&)=default;
};
struct Ainf {
    std::uint32_t value{};
    std::array<std::uint8_t,16> payload{};
    std::uint16_t code{};
    std::array<std::uint16_t,2> halves{};
    friend bool operator==(const Ainf&,const Ainf&)=default;
};
struct PcmGeometry {
    // Metadata copied at header publication. No pointer/storage ownership claim.
    std::int32_t capacity_samples{}, spacing_samples{};
    std::uint32_t binding_role{};
    friend bool operator==(const PcmGeometry&,const PcmGeometry&)=default;
};
struct Predictor {
    std::array<std::int16_t,4> history{};
    std::array<std::int16_t,2> coefficients{};
    Key key{};
    friend bool operator==(const Predictor&,const Predictor&)=default;
};
struct DecoderState {
    std::uint16_t header_phase{};
    Base base;
    std::int16_t filter{},format_tag{};
    Key configured_key{};
    Predictor predictor;
    Loop loop;
    Ainf ainf;
    PcmGeometry borrowed_pcm{},active_pcm{};
    std::int32_t output_channels{},active_channels{},active_block_bytes{},active_samples_per_block{},output_cursor{};
    friend bool operator==(const DecoderState&,const DecoderState&)=default;
};
struct ParseResult {
    Status status{Status::completed};
    std::int32_t source_result{}; // Original 0 defer, negative reject, positive header length.
    bool ahx_diagnostic{};
};

// Pure integer helper cuts: exact selective writes and signed source returns.
// Immutable physical span is the supplied/readable extent. No guest aliases.
[[nodiscard]] std::int32_t parse_base(std::span<const std::uint8_t>,Base&) noexcept;
[[nodiscard]] std::int32_t parse_version(std::span<const std::uint8_t>,Version&) noexcept;
[[nodiscard]] std::int32_t parse_filter(std::span<const std::uint8_t>,std::int16_t&) noexcept;
[[nodiscard]] std::int32_t parse_history(std::span<const std::uint8_t>,Histories&) noexcept;
[[nodiscard]] std::int32_t parse_loop(std::span<const std::uint8_t>,Loop&) noexcept;
[[nodiscard]] std::int32_t parse_ainf(std::span<const std::uint8_t>,Ainf&) noexcept;
[[nodiscard]] Key select_key(std::uint8_t version,std::uint8_t control,std::uint32_t samples,
                             Key& configured,KeyContext&) noexcept;

[[nodiscard]] bool supported_fp_environment() noexcept;
// Fixed first profile only: rate24000/44100/48000 and filter500. No host cosine
// or coefficient lookup. Unsupported ambient modes refuse, never get changed.
// On every returned path preserve caller FP environment/status, not guest FCR.
[[nodiscard]] Status coefficients(std::uint32_t rate,std::int16_t filter,
                                  std::array<std::int16_t,2>& output) noexcept;
// Pure ADX selector/configuration. Unsupported profile/FP environment refuses
// before DecoderState/KeyContext effects. Admitted source defer/reject keeps its
// selective effects. AHX plugin state is absent, so type>=5 follows rejection.
[[nodiscard]] ParseResult decode_header(std::span<const std::uint8_t>,DecoderState&,KeyContext&) noexcept;

struct Snapshot {
    DecoderState decoder;
    std::uint8_t outer_state{1};
    bool end_flag{};
    std::uint32_t accepted_header_bytes{};
    bool lease_held{};
};
struct Hooks {
    void* context{};
    void (*diagnostic)(void*,Diagnostic,const Snapshot&) noexcept {};
};
class HeaderOwner final {
public:
    HeaderOwner(std::shared_ptr<adxt_refill::EncodedSource>,std::shared_ptr<KeyContext>,
                Snapshot initial={},Hooks={});
    ~HeaderOwner()=default; // Never return source credit from an arbitrary destructor.
    HeaderOwner(const HeaderOwner&)=delete;
    HeaderOwner& operator=(const HeaderOwner&)=delete;
    HeaderOwner(HeaderOwner&&)=delete;
    HeaderOwner& operator=(HeaderOwner&&)=delete;
    [[nodiscard]] Snapshot snapshot() const noexcept;
    [[nodiscard]] Status service() noexcept;
    // Explicit recovery after a failed source credit operation. No rollback to
    // original code. Caller remains in the same serialized owner/source domain.
    [[nodiscard]] Status return_held() noexcept;
private:
    class Scope;
    std::shared_ptr<adxt_refill::EncodedSource> source_;
    std::shared_ptr<KeyContext> keys_;
    Snapshot state_;
    Hooks hooks_;
    std::array<std::uint8_t,4096> staging_{};
    std::optional<adxt_refill::DataLease> held_;
    bool busy_{};
    [[nodiscard]] Status finish(std::int32_t) noexcept;
};
} // namespace reo::native::adx_header
