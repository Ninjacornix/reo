#include "adx_header.hpp"

#include <algorithm>
#include <bit>
#include <cfenv>
#include <cmath>
#include <immintrin.h>
#include <limits>
#include <stdexcept>

namespace reo::native::adx_header {
namespace {
constexpr std::array<std::int16_t,1024> key_table{
#include "key_table.inc"
};
std::uint16_t be16(std::span<const std::uint8_t> input,std::size_t offset) noexcept {
    return static_cast<std::uint16_t>((std::uint32_t(input[offset])<<8)|input[offset+1]);
}
std::uint32_t be32(std::span<const std::uint8_t> input,std::size_t offset) noexcept {
    return (std::uint32_t(input[offset])<<24)|(std::uint32_t(input[offset+1])<<16)|
           (std::uint32_t(input[offset+2])<<8)|input[offset+3];
}
std::int16_t signed16(std::uint16_t value) noexcept { return std::bit_cast<std::int16_t>(value); }
std::int8_t signed8(std::uint8_t value) noexcept { return std::bit_cast<std::int8_t>(value); }
bool magic(std::span<const std::uint8_t> input) noexcept { return input.size()>=2 && be16(input,0)==0x8000; }
bool offset_at_least(std::span<const std::uint8_t> input,std::int32_t minimum) noexcept {
    return input.size()>=4 && signed16(be16(input,2))>=minimum;
}
bool rate_profile(std::uint32_t rate,std::int16_t filter) noexcept {
    return filter==500 && (rate==24000 || rate==44100 || rate==48000);
}
float bits(std::uint32_t raw) noexcept { return std::bit_cast<float>(raw); }
std::int32_t convert_word(float value) noexcept {
    // Exact raw-word CVT.W.S rule from pinned ps2_fpu_convert.h, independently
    // expressed here; no host rounding cast, environment change or runtime header.
    const auto raw=std::bit_cast<std::uint32_t>(value),exponent=(raw>>23)&255u;
    if(exponent>0x9D) return std::bit_cast<std::int32_t>((raw&0x80000000u)?0x80000000u:0x7FFFFFFFu);
    if(exponent<127) return 0;
    const auto power=exponent-127,significand=(raw&0x7FFFFFu)|0x800000u;
    const auto magnitude=power>=23 ? significand<<(power-23) : significand>>(23-power);
    return std::bit_cast<std::int32_t>((raw&0x80000000u)?0u-magnitude:magnitude);
}
class FpStatus final {
public:
    FpStatus() noexcept : mxcsr_(_mm_getcsr()),valid_(std::fegetenv(&environment_)==0) {}
    ~FpStatus() { if(valid_) { (void)std::fesetenv(&environment_);_mm_setcsr(mxcsr_); } }
    [[nodiscard]] bool valid() const noexcept { return valid_; }
private:
    std::fenv_t environment_{};
    std::uint32_t mxcsr_{};
    bool valid_{};
};
float cosine_profile(float angle) noexcept {
    // Actual120F68 low-angle branch (y=+0 from1223D0), retaining binary32
    // statement order. The admitted three rate/filter pairs all take this arm.
    const float square=angle*angle;
    float polynomial=square*bits(0xAD47D74E);
    polynomial=polynomial+bits(0x310F74F5);
    polynomial=square*polynomial;
    polynomial=polynomial+bits(0xB493F27B);
    polynomial=square*polynomial;
    polynomial=polynomial+bits(0x37D00D00);
    polynomial=square*polynomial;
    polynomial=polynomial+bits(0xBAB60B60);
    polynomial=square*polynomial;
    polynomial=polynomial+bits(0x3D2AAAAA);
    float correction=square*polynomial;
    correction=square*correction;
    const float product=angle*0.0f;
    const float half_square=square*0.5f;
    correction=correction-product;
    const float remainder=half_square-correction;
    return 1.0f-remainder;
}
std::array<std::int16_t,2> calculate_coefficients(std::uint32_t rate,std::int16_t filter) noexcept {
    // Original126510 single-precision operation order and constants. No
    // transcendental shortcut: cosine_profile is the actual kernel polynomial.
    const float root_two=std::sqrt(2.0f);
    float angle=static_cast<float>(filter);
    angle=angle*bits(0x40C90FDA);
    const float sample_rate=static_cast<float>(static_cast<std::int32_t>(rate));
    angle=angle/sample_rate;
    const float cosine=cosine_profile(angle);
    const float numerator=root_two-cosine;
    const float denominator=root_two-1.0f;
    const float difference=numerator-denominator;
    const float sum=numerator+denominator;
    const float radicand=sum*difference;
    const float root=std::sqrt(radicand);
    const float remainder=numerator-root;
    const float ratio=remainder/denominator;
    const float negative=-ratio;
    const float twice=ratio+ratio;
    const float second=negative*ratio;
    const float first_scaled=twice*bits(0x45800000);
    const float second_scaled=second*bits(0x45800000);
    return {signed16(static_cast<std::uint16_t>(convert_word(first_scaled))),
            signed16(static_cast<std::uint16_t>(convert_word(second_scaled)))};
}
Key derive(std::span<const std::uint8_t> bytes,KeyContext& context) noexcept {
    if(!context.module_references) ++context.module_references;
    Key result{};
    for(std::size_t pass=0;pass<3;++pass) {
        std::int32_t state=key_table[(pass+1)*256];
        for(auto byte:bytes) {
            const auto factor=key_table[static_cast<std::size_t>(std::int32_t(signed8(byte))+128)];
            const auto product=std::int32_t(factor)*state; // Exact positive table keeps this in signed32.
            state=key_table[static_cast<std::size_t>(product%1024)];
        }
        result[pass]=static_cast<std::uint16_t>(state);
    }
    return result;
}
bool known_other_format(std::span<const std::uint8_t> input) noexcept {
    if(input.size()<18) return false;
    const auto value=be32(input,0);
    // Actual resident selector signatures, excluded before tag0-only state edits.
    return value==0x53505344 || (value==0x52494646 && be32(input,8)==0x57415645) ||
        (value==0x464F524D && be32(input,8)==0x41494646) || value==0x2E736E64 || value==0x2E736400 ||
        be16(input,0)==0x0B77 || be16(input,16)==0x0B77;
}
} // namespace

std::int32_t parse_base(std::span<const std::uint8_t> input,Base& output) noexcept {
    if(input.size()<16) return -1;
    if(!magic(input)) return -2;
    output.header_bytes=signed16(static_cast<std::uint16_t>(be16(input,2)+4));
    output.encoding=signed8(input[4]);output.block_bytes=signed8(input[5]);output.bits=signed8(input[6]);output.channels=signed8(input[7]);
    output.frequency=be32(input,8);output.total_samples=be32(input,12);
    output.samples_per_block=output.bits ? (8*std::int32_t(output.block_bytes)-16)/std::int32_t(output.bits) : 0;
    return 0;
}
std::int32_t parse_version(std::span<const std::uint8_t> input,Version& output) noexcept {
    if(input.size()<20) return -1;
    if(!magic(input)) return -2;
    if(!offset_at_least(input,16)) return -1;
    output={input[18],input[19]};return 0;
}
std::int32_t parse_filter(std::span<const std::uint8_t> input,std::int16_t& output) noexcept {
    if(input.size()<18) return -1;
    if(!magic(input)) return -2;
    if(!offset_at_least(input,14)) return -1;
    output=signed16(be16(input,16));return 0;
}
std::int32_t parse_history(std::span<const std::uint8_t> input,Histories& output) noexcept {
    Version version;
    if(parse_version(input,version)<0) return -1;
    if(version.number<4) { output={};return 0; }
    if(input.size()<32) return -1;
    if(!magic(input)) return -2;
    if(!offset_at_least(input,28)) return -1;
    output.first={signed16(be16(input,24)),signed16(be16(input,28))};
    output.second={signed16(be16(input,26)),signed16(be16(input,30))};return 0;
}
std::int32_t parse_loop(std::span<const std::uint8_t> input,Loop& output) noexcept {
    output.enabled=0;
    Version version;const auto status=parse_version(input,version);if(status) return status;
    const std::size_t required=version.number==4 ? 60u : 48u,base=version.number==4 ? 32u : 20u;
    if(input.size()<required) return -1;
    if(!magic(input)) return -2;
    if(!offset_at_least(input,static_cast<std::int32_t>(required)-4)) return -1;
    output.count=signed16(be16(input,base));output.enabled=be16(input,base+2);
    if(output.enabled!=1) return -2;
    output.index=be16(input,base+6);
    for(std::size_t n=0;n<4;++n) output.positions[n]=be32(input,base+8+4*n);
    return 0;
}
std::int32_t parse_ainf(std::span<const std::uint8_t> input,Ainf& output) noexcept {
    output.value=0;
    Version version;const auto status=parse_version(input,version);if(status) return status;
    const std::size_t required=version.number==4 ? 72u : 60u,base=version.number==4 ? 32u : 20u;
    if(input.size()<required) return -1;
    if(!magic(input)) return -2;
    if(!offset_at_least(input,static_cast<std::int32_t>(required)-4)) return -1;
    if(be32(input,base+4)!=0x41494E46) return -2;
    output.value=be32(input,base+8);std::copy_n(input.begin()+static_cast<std::ptrdiff_t>(base+12),16,output.payload.begin());
    output.code=be16(input,base+28);output.halves={be16(input,base+32),be16(input,base+34)};return 0;
}
Key select_key(std::uint8_t version,std::uint8_t control,std::uint32_t samples,Key& configured,KeyContext& context) noexcept {
    if(version<4) return {};
    if(control>=16) {
        constexpr char hex[]="0123456789ABCDEF";std::array<std::uint8_t,8> bytes{};
        for(std::size_t n=0;n<8;++n) bytes[n]=static_cast<std::uint8_t>(hex[(samples>>(28-4*n))&15]);
        return derive(bytes,context);
    }
    if(control<8) return {};
    if(configured==Key{}) configured=context.fallback;
    return configured;
}
bool supported_fp_environment() noexcept {
    return std::fegetround()==FE_TONEAREST && (_mm_getcsr()&~0x3Fu)==0x1F80u;
}
Status coefficients(std::uint32_t rate,std::int16_t filter,std::array<std::int16_t,2>& output) noexcept {
    static_assert(sizeof(float)==4 && std::numeric_limits<float>::is_iec559);
    if(!rate_profile(rate,filter)) return Status::unsupported_profile;
    if(!supported_fp_environment()) return Status::unsupported_fp_environment;
    FpStatus restore;if(!restore.valid()) return Status::unsupported_fp_environment;
    output=calculate_coefficients(rate,filter);return Status::completed;
}
ParseResult decode_header(std::span<const std::uint8_t> input,DecoderState& state,KeyContext& context) noexcept {
    if(input.size()>4096) return {Status::invalid_input,0,false};
    if(!magic(input)) {
        // Original non-ADX validators can inspect through byte17 even if the
        // caller supplied only16. Do not infer those unread bytes from native
        // storage: that short non-ADX domain is explicitly unsupported.
        if(input.size()<18 || known_other_format(input)) return {Status::unsupported_profile,0,false};
        return {Status::completed,-1,false};
    }
    // Admission/private math staging precedes state/context effects. There are no
    // callbacks in this pure function. Actual coefficient/history stores retain
    // their source sequence below, including a later full-header fit defer.
    Base base;Version version;std::int16_t filter{};Histories history;std::array<std::int16_t,2> staged{};
    const auto base_status=parse_base(input,base);
    const bool ordinary=base_status==0 && base.encoding<5;
    const bool ready_math=ordinary && parse_version(input,version)==0 && parse_filter(input,filter)==0 && parse_history(input,history)==0;
    if(ready_math) {
        if(base.encoding!=3 || (base.channels!=1 && base.channels!=2) || base.block_bytes!=18 ||
           (base.bits!=4 && base.bits!=0) || (version.number!=3 && version.number!=4)) return {Status::unsupported_profile,0,false};
        const auto status=coefficients(base.frequency,filter,staged);
        if(status!=Status::completed) return {status,0,false};
    }
    state.header_phase=1;
    if(parse_base(input,state.base)<0) return {};
    if(state.base.encoding>=5) return {Status::completed,-1,true};
    if(parse_version(input,version)<0) return {};
    state.predictor.key=select_key(version.number,version.control,state.base.total_samples,state.configured_key,context);
    if(parse_filter(input,state.filter)<0) return {};
    if(parse_history(input,history)<0) return {};
    state.predictor.coefficients=staged;
    state.predictor.history={history.first[0],history.second[0],history.first[1],history.second[1]};
    (void)parse_loop(input,state.loop);(void)parse_ainf(input,state.ainf);
    state.format_tag=0;state.active_channels=state.base.channels;state.active_block_bytes=state.base.block_bytes;
    state.active_samples_per_block=state.base.samples_per_block;state.active_pcm=state.borrowed_pcm;state.output_cursor=0;
    return {Status::completed,state.base.header_bytes,false};
}

class HeaderOwner::Scope final {
public:
    explicit Scope(HeaderOwner& owner) noexcept : owner_(owner),entered_(!owner.busy_) { if(entered_) owner_.busy_=true; }
    ~Scope() { if(entered_) owner_.busy_=false; }
    explicit operator bool() const noexcept { return entered_; }
private:HeaderOwner& owner_;bool entered_;
};
HeaderOwner::HeaderOwner(std::shared_ptr<adxt_refill::EncodedSource> source,std::shared_ptr<KeyContext> keys,Snapshot initial,Hooks hooks)
    :source_(std::move(source)),keys_(std::move(keys)),state_(initial),hooks_(hooks) {
    if(!source_ || !keys_ || initial.lease_held) throw std::invalid_argument("Retained source/key context required");
}
Snapshot HeaderOwner::snapshot() const noexcept { auto result=state_;result.lease_held=held_.has_value();return result; }
Status HeaderOwner::finish(std::int32_t bytes) noexcept {
    if(!held_) return Status::completed;
    if(source_->finish_data(*held_,bytes)!=adxt_refill::Status::completed) return Status::source_failure;
    held_.reset();return Status::completed;
}
Status HeaderOwner::return_held() noexcept {
    Scope scope(*this);if(!scope) return Status::reentrant_call;return finish(0);
}
Status HeaderOwner::service() noexcept {
    Scope scope(*this);if(!scope) return Status::reentrant_call;
    if(held_) return Status::lease_held;
    if(state_.outer_state!=1) return Status::inactive;
    const auto maximum=std::min<std::int32_t>(4096,source_->snapshot().ring.capacity);
    auto borrowed=source_->borrow_data(maximum);
    if(borrowed.status!=adxt_refill::Status::completed) return Status::source_failure;
    held_.emplace(std::move(borrowed.lease));const auto count=held_->bytes();
    if(count<0 || count>4096) { (void)finish(0);return Status::source_failure; }
    if(count<16) return finish(0);
    if(held_->read_into(std::span(staging_).first(static_cast<std::size_t>(count)))!=adxt_refill::Status::completed) {
        (void)finish(0);return Status::source_failure;
    }
    const auto parsed=decode_header(std::span<const std::uint8_t>(staging_).first(static_cast<std::size_t>(count)),state_.decoder,*keys_);
    if(parsed.ahx_diagnostic && hooks_.diagnostic) hooks_.diagnostic(hooks_.context,Diagnostic::ahx_without_plugin,snapshot());
    if(parsed.status!=Status::completed) {
        const auto returned=finish(0);return returned==Status::completed ? parsed.status : returned;
    }
    if(parsed.source_result==0 || parsed.source_result>count) return finish(0);
    if(parsed.source_result<0) {
        const auto returned=finish(0);if(returned!=Status::completed) return returned;
        if(hooks_.diagnostic) hooks_.diagnostic(hooks_.context,Diagnostic::unsupported_header,snapshot());
        state_.outer_state=4;return Status::completed;
    }
    state_.accepted_header_bytes=static_cast<std::uint32_t>(parsed.source_result);
    const auto returned=finish(parsed.source_result);if(returned!=Status::completed) return returned;
    state_.outer_state=2;return Status::completed;
}
} // namespace reo::native::adx_header
