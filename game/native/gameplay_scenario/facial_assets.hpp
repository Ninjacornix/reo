#pragma once
#include <array>
#include <cstddef>
#include <cstdint>
#include <memory>
#include <vector>
namespace reo::assets {struct Source;}
namespace reo::native::gameplay_scenario {
enum class FacialMatrixKind {player,npc};
struct FacialAssetBytes {
    std::shared_ptr<const std::vector<std::byte>> storage;
    std::uint32_t logical_bytes{};
};
// Immutable File1 default-catalogue face namespace. The18 MAT and33 LIP
// ordinals are the actual compiled1342-key catalogue's complete matching
// subsets. Unknown typed names genuinely miss; reads include real sectors.
class File1FacialAssets final {
public:
    explicit File1FacialAssets(std::shared_ptr<const reo::assets::Source>);
    FacialAssetBytes matrix(FacialMatrixKind,std::uint16_t character)const;
    FacialAssetBytes lip(std::uint16_t scenario,std::uint16_t cue,
                         std::uint16_t voice,std::uint32_t speaker)const;
private:
    struct Range {std::uint64_t offset{};std::uint32_t logical{},storage{};};
    std::shared_ptr<const reo::assets::Source> source_;
    std::array<Range,51> ranges_;
    FacialAssetBytes read(std::size_t)const;
};
} // namespace reo::native::gameplay_scenario
