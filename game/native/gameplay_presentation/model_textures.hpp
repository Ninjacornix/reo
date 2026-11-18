#pragma once
#include "texture.hpp"
#include "../gameplay_scenario/scenario_archive.hpp"
namespace reo::native::gameplay_presentation {
// Resolve actual NBD model-local texture ordinals through the room's TID AFS
// directory or the character's embedded TEX payload, respectively.
std::vector<Texture> room_textures(const gameplay_scenario::content::ScenarioArchive&,std::uint16_t scenario,std::span<const std::byte> nbd);
std::vector<Texture> character_textures(std::span<const std::byte> nbd);
}
