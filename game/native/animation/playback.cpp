#include "playback.hpp"
#include <bit>
#include <cmath>
#include <stdexcept>
namespace reo::native::animation {
namespace {
float finite(float value) {
    if (!std::isfinite(value))
        throw std::domain_error("Native motion playback finite FP32 profile required");
    return value;
}
float plus(float x, float y) {
    return finite(x + y);
}
float minus(float x, float y) {
    return finite(x - y);
}
float times(float x, float y) {
    return finite(x * y);
}
float clock_factor(std::uint8_t mode) {
    return mode ? 2.f : 1.f;
}
std::int32_t integer(float value) {
    finite(value);
    if (value < -2147483648.f || value >= 2147483648.f)
        throw std::domain_error("Native motion integer conversion outside admitted range");
    return std::int32_t(std::trunc(value));
}
std::uint16_t narrowed_duration(float value) {
    const bool high = value >= 2147483648.f;
    const auto low = std::uint32_t(integer(high ? minus(value, 2147483648.f) : value));
    return std::uint16_t(high ? low | 0x80000000u : low);
}
void metadata(MotionChannel& channel, const Clip& clip) {
    channel.timing.end = clip.last_frame();
    channel.timing.restart = clip.looping() ? clip.loop_start() : 0;
    channel.timing.loop = std::int8_t(clip.looping());
    if (channel.timing.restart < 0)
        channel.timing.restart = 0;
    if (integer(channel.timing.end) & 1)
        channel.timing.end = minus(channel.timing.end, 1);
    if (channel.timing.loop & 1)
        channel.timing.loop = std::int8_t(integer(minus(float(channel.timing.loop), 1)));
}
Vector sum(Vector x, Vector y) {
    return {plus(x.x, y.x), plus(x.y, y.y), plus(x.z, y.z)};
}
Vector weighted(Vector x, Vector y, float weight) {
    const float other = minus(1, weight);
    return {plus(times(x.x, weight), times(y.x, other)),
            plus(times(x.y, weight), times(y.y, other)),
            plus(times(x.z, weight), times(y.z, other))};
}
} // namespace
float transition_weight(float x) {
    // Full1A4DB0 with the actual58C460 seven scalar arguments. Keep zero and
    // unit terms in source order; algebraic smoothstep substitution differs.
    finite(x);
    const float span = minus(1, 0), offset = minus(x, 0), inverse = finite(1.f / span);
    float f3 = times(offset, offset), f5 = times(inverse, inverse);
    const float f4 = times(times(3, f3), f5), f6 = times(f3, inverse);
    f3 = times(f5, times(f3, offset));
    f5 = times(times(2, f3), inverse);
    f3 = minus(f3, f6);
    const float left = plus(1, minus(f5, f4));
    const float tangent = plus(offset, minus(f3, f6));
    const float initial = times(0, left), target = plus(-f5, f4);
    return plus(plus(times(1, tangent), plus(initial, times(1, target))), times(0, f3));
}
float motion_complement(float weight) {
    transform_math::require_profile();
    finite(weight);
    // The original float->software-double->single chain discards subnormal
    // float inputs and truncates its final single mantissa. TwoSum recovers
    // the exact residual of1-weight under the qualified native RNE profile;
    // adjust one representable step only when rounding exceeded its magnitude.
    const auto exponent = (std::bit_cast<std::uint32_t>(weight) >> 23) & 255u;
    //111A90 deliberately drops the smaller operand for exponent gaps>=64.
    if (exponent <= 63)
        return 1;
    if (exponent >= 191)
        return -weight;
    float result = minus(1, weight);
    const float tail = minus(result, 1);
    const float error = plus(minus(1, minus(result, tail)), minus(-weight, tail));
    if ((result > 0 && error < 0) || (result < 0 && error > 0))
        result = std::nextafter(result, 0.f);
    return finite(result);
}
Playback::Playback(std::shared_ptr<Instance> primary, bool second) : primary_(std::move(primary)) {
    if (!primary_)
        throw std::invalid_argument("Native Playback requires its exact canonical primary model");
    if (second)
        secondary_ = PoseBlend::create_sibling(*primary_);
}
void Playback::replace_model(std::shared_ptr<Instance> model) {
    if (!model)
        throw std::invalid_argument("Native Playback replacement requires a canonical model");
    if (model == primary_)
        return;
    // Secondary presence is the original owner's policy, independent of the
    // replacement Skeleton's size. Do not copy old model-node clip bindings.
    auto secondary = secondary_ ? PoseBlend::create_sibling(*model) : nullptr;
    replace_model_prepared(std::move(model),std::move(secondary));
}
void Playback::replace_model_prepared(std::shared_ptr<Instance> model,std::shared_ptr<Instance> secondary) {
    if(!model||bool(secondary)!=bool(secondary_)||(secondary&&&secondary->skeleton()!=&model->skeleton()))
        throw std::invalid_argument("Native Playback prepared replacement has incompatible model banks");
    PoseBlend::root_reference(*model, PoseBlend::root_reference(*primary_));
    auto previous_primary = std::move(primary_);
    auto previous_secondary = std::move(secondary_);
    primary_ = std::move(model);
    secondary_ = std::move(secondary);
    // Previous owners retire only after both corresponding banks are visible.
}
MotionChannel& Playback::channel(ModelBank bank, std::size_t track) {
    return channels_[bank == ModelBank::primary ? 0 : 1].at(track);
}
const MotionChannel& Playback::channel(ModelBank bank, std::size_t track) const {
    return channels_[bank == ModelBank::primary ? 0 : 1].at(track);
}
MotionBound Playback::bind_plain(ModelBank bank, const MotionBank& resource, std::uint32_t key,
                                 std::uint16_t track, float frame) {
    auto& record = channel(bank, track);
    auto& model = bank == ModelBank::primary ? primary_ : secondary_;
    const auto block = resource.find(key, track);
    if (!block) {
        if (track == 2) {
            primary_->clear(track);
            record = {};
            return MotionBound::cleared;
        }
        return MotionBound::unchanged;
    }
    if (!model)
        return MotionBound::unchanged;
    const auto clip = block->clip();
    record = {};
    record.selector = std::uint16_t(key);
    record.timing.frame = finite(frame);
    metadata(record, *clip);
    model->bind(track, clip);
    model->sample(track, frame);
    return MotionBound::prepared;
}
int Playback::configure(const MotionBank& resource, std::int32_t key, std::uint16_t track,
                        float frame, float blend, MotionClock clock, RootMotionRef root) {
    auto& record = channel(ModelBank::primary, track);
    if ((std::uint32_t(key) & 0x4000) || key >= 2000)
        return 1;
    if (key < 0)
        throw std::domain_error("Native primary motion negative source row unavailable");
    const auto block = resource.find(std::uint32_t(key), track);
    if (!block) {
        if (track == 2) {
            primary_->clear(track);
            record = {};
        }
        return 1;
    }
    const auto clip = block->clip();
    record.selector = std::uint16_t(key);
    record.timing.frame = finite(frame);
    const float factor = clock_factor(clock.mode);
    blend = finite(blend / factor);
    record.blend_remaining = narrowed_duration(blend);
    record.timing.flags &= std::uint8_t(~0x18u);
    if (blend != 0) {
        if (blend < 0) {
            record.timing.flags |= 0x10;
            blend = -blend;
            record.blend_remaining = narrowed_duration(blend);
        }
        record.timing.flags |= 8;
        record.blend_increment = finite(1.f / plus(1, blend));
        record.blend_position = 0;
        if (secondary_)
            PoseBlend::capture_pose(*secondary_, *primary_, track);
        if (track == 0)
            saved_delta_ = root.get();
    }
    primary_->bind(track, clip);
    primary_->sample(track, frame);
    if (track == 0) {
        if (frame < factor) {
            PoseBlend::root_reference(*primary_, {});
            root.set(primary_->consume_root_translation());
        } else {
            const float step =
                times(factor, (clock.category == 0 || clock.category == 1) ? clock.rate : 1.f);
            root.set(primary_->translation_difference(1, minus(frame, step), frame));
            (void)primary_->consume_root_translation();
        }
        unblended_delta_ = root.get();
    }
    (void)blend_transition(track, root);
    metadata(record, *clip);
    return 0;
}
MotionBound Playback::configure_whole(const MotionBank& resource,std::int32_t key,float frame,
                                     float blend,MotionClock clock,RootMotionRef root) {
    if(resource.kind()==MotionBankKind::sparse||resource.first_track()!=0||resource.track_count()!=1)
        throw std::domain_error("Native whole-model motion requires a single-track strided bank");
    if(key<0)throw std::domain_error("Native whole-model motion negative source row unavailable");
    const auto block=resource.find(std::uint32_t(key),0);
    if(!block)return MotionBound::unchanged;
    const auto clip=block->clip();
    auto& record=channel(ModelBank::primary,0);
    record.selector=std::uint16_t(key);record.timing.frame=finite(frame);
    const float factor=clock_factor(clock.mode);
    blend=finite(blend/factor);record.blend_remaining=narrowed_duration(blend);
    // The complete whole-model path clears only bit8 and zeroes these root
    // outputs before saving them. It neither captures a secondary pose nor
    // invokes the per-track transition blender.
    record.timing.flags&=std::uint8_t(~8u);
    saved_delta_={};root.set({});
    if(blend!=0){
        if(blend<0){record.timing.flags|=0x10;blend=-blend;record.blend_remaining=narrowed_duration(blend);}
        record.timing.flags|=8;record.blend_increment=finite(1.f/plus(1,blend));record.blend_position=0;
    }
    PoseBlend::bind_all(*primary_,clip);primary_->sample_all(frame);
    if(frame==0){
        PoseBlend::root_reference(*primary_,{});
        root.set(primary_->consume_root_translation());
    }else{
        const float step=times(factor,(clock.category==0||clock.category==1)?clock.rate:1.f);
        root.set(primary_->translation_difference(1,minus(frame,step),frame));
        (void)primary_->consume_root_translation();
    }
    // Unlike58B9A0,58C970 does not adjust odd frame ends or clear a low
    // loop bit after querying the clip metadata.
    record.timing.end=clip->last_frame();
    record.timing.restart=clip->looping()?clip->loop_start():0;
    record.timing.loop=std::int8_t(clip->looping());
    if(record.timing.restart<0)record.timing.restart=0;
    return MotionBound::prepared;
}
std::int8_t Playback::advance_whole(float step,std::uint8_t mode,RootMotionRef root) {
    auto& record=channel(ModelBank::primary,0);
    const float before=record.timing.frame;
    if(mode)step=times(step,2);
    const auto result=std::int8_t(advance(record.timing,step));
    if(result>=2&&record.timing.frame!=0){
        primary_->sample_all(record.timing.frame);
        const auto tail=primary_->translation_difference(1,before,record.timing.end);
        const auto head=primary_->translation_difference(1,record.timing.restart,record.timing.frame);
        root.set(sum(head,tail));(void)primary_->consume_root_translation();
    }else{
        if(result>=2)PoseBlend::root_reference(*primary_,{});
        primary_->sample_all(record.timing.frame);
        root.set(primary_->consume_root_translation());
    }
    return result;
}
std::int8_t Playback::advance_plain(ModelBank bank, std::uint16_t track, float step,
                                    std::uint8_t mode) {
    auto& model = bank == ModelBank::primary ? primary_ : secondary_;
    if (!model)
        return -1;
    auto& record = channel(bank, track);
    if (mode)
        step = times(step, 2);
    const auto result = std::int8_t(advance(record.timing, step));
    model->sample(track, record.timing.frame);
    return result;
}
std::uint8_t Playback::blend_transition(std::uint16_t track, RootMotionRef root) {
    auto& record = channel(ModelBank::primary, track);
    if (!(record.timing.flags & 8) || record.blend_remaining == 0)
        return 0;
    record.blend_position = plus(record.blend_position, record.blend_increment);
    const float shaped = transition_weight(record.blend_position),
                other = motion_complement(shaped);
    if (secondary_)
        PoseBlend::blend(*primary_, *secondary_, track, shaped, other);
    if (!(record.timing.flags & 2) && track == 0)
        root.set(weighted((record.timing.flags & 0x10) ? unblended_delta_ : root.get(),
                          saved_delta_, record.blend_position));
    --record.blend_remaining;
    if (record.blend_remaining == 0)
        record.timing.flags &= std::uint8_t(~0x1au);
    return std::uint8_t(record.blend_remaining);
}
std::int8_t Playback::advance_primary(std::uint16_t track, float step, std::uint8_t mode,
                                      RootMotionRef root) {
    auto& record = channel(ModelBank::primary, track);
    const float before = record.timing.frame;
    if (mode)
        step = times(step, 2);
    const auto result = std::int8_t(advance(record.timing, step));
    if (result >= 2 && track == 0 && record.timing.frame != 0) {
        primary_->sample(track, record.timing.frame);
        const auto tail = primary_->translation_difference(1, before, record.timing.end);
        const auto head =
            primary_->translation_difference(1, record.timing.restart, record.timing.frame);
        root.set(sum(head, tail));
        (void)primary_->consume_root_translation();
    } else {
        if (result >= 2 && track == 0)
            PoseBlend::root_reference(*primary_, {});
        primary_->sample(track, record.timing.frame);
        if (track == 0)
            root.set(primary_->consume_root_translation());
    }
    (void)blend_transition(track, root);
    return result;
}
void Playback::blend_banks(std::uint16_t track, float p, float s) {
    if (secondary_)
        PoseBlend::blend(*primary_, *secondary_, track, p, s);
}
void Playback::activate(std::uint8_t count) {
    if (count > 5)
        throw std::out_of_range("Native active motion channel count unavailable");
    for (unsigned i = 0; i < count; ++i)
        channels_[0][i].timing.loop = channels_[1][i].timing.loop = 1;
}
void Playback::or_primary_flags82() noexcept {
    channels_[0][0].timing.flags |= 0x82;
}
void Playback::or_packed_primary_flags(std::uint8_t value) noexcept {
    channels_[0][0].timing.flags |= value & 15;
    channels_[0][1].timing.flags |= value >> 4;
}
void Playback::clear_primary(std::uint16_t track) {
    primary_->clear(track);
    channel(ModelBank::primary, track) = {};
}
void Playback::progress(std::uint8_t category, bool selected, std::uint32_t buttons) {
    if (category != 0)
        return;
    progress_flags =
        progress_threshold && !(channels_[0][0].timing.frame < float(progress_threshold)) ? 0x80
                                                                                          : 0;
    if (progress_threshold && selected && (buttons & 0xf3f))
        progress_flags |= 0x40;
}
std::int8_t Playback::advance_channels_after_prelude(std::uint8_t count, float step,
                                                     std::uint8_t mode, std::uint8_t category,
                                                     bool selected, std::uint32_t buttons,
                                                     RootMotionRef root) {
    if (count > 5)
        throw std::out_of_range("Native motion tick channel count unavailable");
    for (unsigned i = 1; i < count; ++i)
        if (!(channels_[0][i].skip_flags & 1))
            (void)advance_primary(std::uint16_t(i), step, mode, root);
    const auto result =
        (channels_[0][0].skip_flags & 1) ? std::int8_t(-1) : advance_primary(0, step, mode, root);
    progress(category, selected, buttons);
    return result;
}
std::int8_t Playback::advance_four_after_prelude(float step, float weight, std::uint8_t mode,
                                                 std::uint8_t category, bool selected,
                                                 std::uint32_t buttons) {
    (void)advance_plain(ModelBank::secondary, 1, step, mode);
    (void)advance_plain(ModelBank::secondary, 0, step, mode);
    (void)advance_plain(ModelBank::primary, 1, step, mode);
    const auto result = advance_plain(ModelBank::primary, 0, step, mode);
    channels_[0][0].blend_position = channels_[0][1].blend_position = weight;
    const float other = motion_complement(weight);
    blend_banks(1, weight, other);
    blend_banks(0, weight, other);
    progress(category, selected, buttons);
    return result;
}
} // namespace reo::native::animation
