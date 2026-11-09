#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <span>
#include <vector>

namespace reo::native::animation {
struct Key {float value{},time{},incoming{},outgoing{};std::uint32_t kind{};};
class Curve {
public:
    static Curve import(std::uint8_t format,std::uint8_t channel,std::span<const std::byte> keys,std::size_t count);
    float sample(float frame,std::int16_t& cache)const;
    std::uint8_t channel()const noexcept{return channel_;}
    std::uint8_t format()const noexcept{return format_;}
    std::span<const Key> keys()const noexcept{return keys_;}
private:
    std::uint8_t format_{},channel_{};
    std::vector<Key> keys_;
};
struct Track {bool quantized{};std::vector<Curve> curves;};
class Clip {
public:
    // Imports the original raw curve set directly into owned immutable native
    // values. Resource handles, mutable source memoization and packing arenas
    // are not retained or executed in native playback.
    static std::shared_ptr<const Clip> import_raw(std::span<const std::byte>);
    std::span<const Track> tracks()const noexcept{return tracks_;}
    float first_frame()const noexcept{return first_;}
    float last_frame()const noexcept{return last_;}
    bool looping()const noexcept{return looping_;}
    float loop_start()const noexcept{return loop_start_;}
private:
    std::vector<Track> tracks_;
    float first_{},last_{},loop_start_{};
    bool looping_{};
};
using Parameters=std::array<float,10>;
using Caches=std::array<std::int16_t,10>;
void sample_parameters(const Track&,float frame,Parameters&,Caches&);
float interpolate_linear(float time,float value0,float time0,float value1,float time1);
float interpolate_cubic(float time,float value0,float time0,float outgoing0,float value1,float time1,float incoming1);
} // namespace reo::native::animation
