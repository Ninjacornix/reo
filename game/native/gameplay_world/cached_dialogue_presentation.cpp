#include "cached_dialogue_presentation.hpp"
namespace reo::native::gameplay_world {
CachedDialoguePresentation::CachedDialoguePresentation(World& world,gameplay_scenario::TextCache& cache,const DialogueVisibilityInputs& visibility)noexcept:world_(world),cache_(cache),visibility_(visibility){}
bool CachedDialoguePresentation::bound_to(const World& world)const noexcept{return &world_==&world&&!world_.closed();}
bool CachedDialoguePresentation::erase(std::span<const std::byte> text)noexcept{return bound_to(world_)&&cache_.erase(text)==gameplay_scenario::TextCacheStatus::completed;}
std::optional<bool> CachedDialoguePresentation::suppressed()noexcept{return bound_to(world_)?dialogue_suppressed(visibility_,world_.session().inventory_owner):std::nullopt;}
bool CachedDialoguePresentation::draw(std::int16_t x,std::uint16_t y,std::span<const std::byte> text,std::uint8_t alpha)noexcept{return bound_to(world_)&&cache_.dialogue(x,y,text,alpha).status==gameplay_scenario::TextCacheStatus::completed;}
} // namespace reo::native::gameplay_world
