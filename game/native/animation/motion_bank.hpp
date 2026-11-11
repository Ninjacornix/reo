#pragma once
#include "curves.hpp"
#include <string>
namespace reo::native::animation {
// Immutable owned asset block. No original resource token or source mutation is
// retained. Clip decoding is lazy so unused unsupported curves are not executed.
class MotionBlock final {
public:
    std::size_t source_offset()const noexcept{return source_offset_;}
    std::span<const std::byte> bytes()const noexcept{return bytes_;}
    const std::string& source_identity()const noexcept{return source_identity_;}
    std::shared_ptr<const Clip> clip()const;
private:
    friend class MotionBank;
    MotionBlock(std::span<const std::byte>,std::size_t,std::string);
    std::vector<std::byte> bytes_;
    std::size_t source_offset_{};
    std::string source_identity_;
    mutable std::shared_ptr<const Clip> clip_;
};
enum class MotionBankKind:std::uint8_t {strided=0,sparse=1,strided_500=2};
class MotionBank final {
public:
    static constexpr std::size_t capacity=2000;
    //1B2130's initial zero bank differs from1B1BC0 release: release preserves
    // the kind byte. A known cleared bank has valid absent tokens, while a
    // merely default-constructed bank has not admitted a header profile yet.
    static MotionBank cleared_bank(MotionBankKind = MotionBankKind::strided);
    void clear()noexcept;
    // Complete1B1C20 with owned234410 profiles0/1/2. Partial retirement
    // preserves the header/type and all rows/tokens outside that family.
    void clear_family(std::uint8_t);
    //1B1E50's per-bank effect: release families0,1,2 and zero the range
    // header, preserving type and reserved token slots0..4. A zero header
    // can still resolve those tokens; it does not imply an empty bank.
    void clear_scene_families();
    bool cleared()const noexcept{return cleared_;}
    bool zero_header_known()const noexcept{return zero_header_known_;}
    // Actual1D16C0/1D19D0 sparse construction. table_offset is8 or168 for
    // the two adjacent player banks. modes0/1/2 retain original5/1000/5 cursors.
    void load_sparse(std::span<const std::byte>,std::size_t table_offset,
                     std::uint8_t mode,std::string identity);
    // Actual1D1500/1D1960/1D1990 finite strided assets. Source lookup still
    // uses its literal200 quotient stride even when construction uses500.
    void load_strided(std::span<const std::byte>,std::size_t stride,
                       std::size_t bias,std::string identity);
    std::shared_ptr<const MotionBlock> find(std::uint32_t encoded_key,std::uint16_t track)const;
    std::uint8_t first_track()const noexcept{return first_;}
    std::uint8_t track_count()const noexcept{return width_;}
    MotionBankKind kind()const noexcept{return kind_;}
    auto slots()const noexcept{return std::span<const std::shared_ptr<const MotionBlock>,capacity>(slots_);}
    auto rows()const noexcept{return std::span<const std::uint16_t,capacity>(rows_);}
private:
    std::uint8_t first_{},width_{};
    MotionBankKind kind_{MotionBankKind::sparse};
    bool cleared_{},zero_header_known_{};
    std::array<std::shared_ptr<const MotionBlock>,capacity> slots_{};
    std::array<std::uint16_t,capacity> rows_{};
};
} // namespace reo::native::animation
