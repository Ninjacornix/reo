#pragma once
#include "response.hpp"
namespace reo::native::gameplay_collision::sweep {
using Triangle=response::Triangle;
struct Input { Vec3 start, end; float radius{}, movement_length{}; };
Input input(Vec3 start,Vec3 end,float radius) noexcept;
enum class Kind : std::uint8_t { face, edge };
struct StoredContact {
    Triangle triangle;
    Kind kind{};
    std::uint8_t side{};
    Vec3 start, point, plane_point;
};
enum class Status { ok, indeterminate_projection, original_exclusion_overflow, source_face_recovered };
struct Resolution {
    Vec3 correction;
    std::array<std::uint8_t,6> selected{};
    std::uint8_t selected_count{}, contact_count{};
    Status status{Status::ok};
};
class Contacts {
public:
    explicit Contacts(Input query) noexcept:input_(query){}
    bool collect(const Triangle&) noexcept;
    Resolution resolve(Vec3 initial={})const noexcept;
    std::span<const StoredContact> records()const noexcept{return std::span(records_).first(count_);}
    const std::optional<Vec3>& reported_point()const noexcept{return reported_point_;}
    const std::optional<Vec3>& reported_normal()const noexcept{return reported_normal_;}
    Status status()const noexcept{return status_;}
private:
    Input input_;
    std::array<StoredContact,6> records_{};
    std::uint8_t count_{};
    Status status_{Status::ok};
    std::optional<Vec3> reported_point_,reported_normal_;
};
struct Result { Resolution resolution; bool inside_grid{}; std::optional<Vec3> reported_point, reported_normal; };
Result query(const response::Grid&,Input,const response::Filter&,std::span<const Triangle> dynamic={});
}
