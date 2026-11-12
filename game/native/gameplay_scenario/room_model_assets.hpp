#pragma once
#include "content.hpp"
#include "../animation/model.hpp"
#include <array>
#include <optional>
#include <string>

namespace reo::native::gameplay_scenario {
struct RoomModelGroup {
    std::uint8_t first_model{},models{};
    std::optional<std::uint8_t> control;
    animation::Vector origin;
};
struct RoomModelPose {
    std::uint8_t slot{};
    animation::Matrix matrix;
};
// Immutable actual1D2CB0 import results. These are authored definitions, not a
// second mutable current/saved SceneModels bank or an admitted renderer owner.
class RoomModelAsset final {
public:
    static std::shared_ptr<const RoomModelAsset> import(std::string,content::Bytes);
    std::string_view name()const noexcept{return name_;}
    std::span<const RoomModelPose> poses()const noexcept{return poses_;}
    std::span<const RoomModelGroup> groups()const noexcept{return groups_;}
    std::uint16_t nodes()const noexcept{return nodes_;}
    std::uint16_t parts()const noexcept{return parts_;}
    const content::Bytes& bytes()const noexcept{return bytes_;}
private:
    std::string name_;
    content::Bytes bytes_;
    std::vector<RoomModelPose> poses_;
    std::vector<RoomModelGroup> groups_;
    std::uint16_t nodes_{};
    std::uint16_t parts_{};
};
}
