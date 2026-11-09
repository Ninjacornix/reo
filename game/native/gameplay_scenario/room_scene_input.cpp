#include "room_scene_input.hpp"
#include <bit>
#include <stdexcept>

namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(std::span<const std::byte> bytes, std::size_t at) {
  if (at > bytes.size() || bytes.size() - at < 4)
    throw std::invalid_argument("Truncated room proxy word");
  std::uint32_t value{};
  for (unsigned i = 0; i < 4; ++i)
    value |= std::uint32_t(std::to_integer<std::uint8_t>(bytes[at + i]))
             << (8 * i);
  return value;
}
std::uint16_t half(std::span<const std::byte> bytes, std::size_t at) {
  if (at > bytes.size() || bytes.size() - at < 2)
    throw std::invalid_argument("Truncated room proxy halfword");
  return std::uint16_t(
      std::to_integer<std::uint8_t>(bytes[at]) |
      (std::uint32_t(std::to_integer<std::uint8_t>(bytes[at + 1])) << 8));
}
std::uint8_t byte(std::span<const std::byte> bytes, std::size_t at) {
  if (at >= bytes.size())
    throw std::invalid_argument("Truncated room proxy byte");
  return std::to_integer<std::uint8_t>(bytes[at]);
}
constexpr std::array<std::uint8_t, 14> priorities{2, 2, 2, 1, 1, 5, 2,
                                                  2, 4, 4, 2, 4, 1, 2};
} // namespace
RoomSceneInput::RoomSceneInput(std::span<const std::byte> input,
                               const content::ScriptBank &bank,
                               gameplay_collision::ImportContext context) {
  model_domain_=std::make_shared<AuthoredModelDomain>();
  if (bank.format() != content::BankFormat::room_section)
    throw std::invalid_argument("Room proxy requires room script section");
  const auto first = bank.object(0), second = bank.object(1);
  if (!first || !second || first->bound.bytes != 32 ||
      second->bound.bytes != 32 ||
      second->bound.offset != first->bound.offset + 32)
    throw std::invalid_argument(
        "Room proxy remap objects require proven 32-byte adjacency");
  for (unsigned table = 0; table < 2; ++table) {
    const auto data = bank.view(table ? *second : *first);
    for (unsigned i = 0; i < 32; ++i)
      maps_[table][i] = byte(data, i);
  }
  const auto count = word(input, 4);
  if (count > 128 || input.size() < 8 || count > (input.size() - 8) / 4)
    throw std::invalid_argument("Invalid room proxy offset directory");
  records_.reserve(count);
  for (std::uint32_t ordinal = 0; ordinal < count; ++ordinal) {
    const auto offset = word(input, 8 + 4 * ordinal);
    if (offset < 8 + 4 * count || offset > input.size() ||
        input.size() - offset < 0xb0)
      throw std::invalid_argument("Invalid room proxy record extent");
    const auto source = input.subspan(offset, 0xb0);
    const auto tag = word(source, 0), query = word(source, 4);
    if (tag >= priorities.size() || query > 255)
      throw std::invalid_argument("Unadmitted room proxy type/query width");
    RoomProxyDefinition d;
    auto &record = d.initial;
    record.authored_id = word(source, 0x30);
    record.counter = priorities[tag];
    record.enabled = 0;
    record.body = ControlOther{std::uint8_t(tag)};
    d.ordinal = std::uint8_t(ordinal + 1);
    gameplay_scene::CollisionShape shape;
    for (unsigned i = 0; i < 4; ++i)
      shape.bounds[i] = {std::bit_cast<std::int32_t>(word(source, 8 + 8 * i)),
                         std::bit_cast<std::int32_t>(word(source, 12 + 8 * i))};
    shape.lower = std::bit_cast<std::int32_t>(word(source, 0x28));
    shape.upper = std::bit_cast<std::int32_t>(word(source, 0x2c));
    shape.query_class = std::uint8_t(query);
    record.other_content = word(source, 0x38);
    record.other_resource_class = word(source, 0x48);
    const auto resolve = [&](unsigned map) {
      if (record.authored_id >= 32)
        throw std::invalid_argument(
            "Unadmitted room proxy authored remap index");
      return ModelReference::authored(maps_[map][record.authored_id],model_domain_);
    };
    switch (tag) {
    case 0: {
      const auto model = resolve(0);
      ControlTypeZero body;
      body.parameter = UINT32_MAX;
      body.half_parameter = UINT16_MAX;
      body.byte_parameter = byte(source, 0x62);
      body.refresh_parameter = byte(source, 0x61);
      body.destination =
          ControlRouteDestination{word(source, 0x34), word(source, 0x38)};
      body.matrix_program = ControlMatrixProgramResource{
          model, word(source, 0x44), word(source, 0x50)};
      record.body = body;
      record.enabled = 1;
      record.door = gameplay_scene::DoorDetails{};
      record.other_content.reset();
      d.model = RoomProxyModelSetup{model, byte(source, 0x4c),
                                    RoomProxyHelper::depth_extension};
      break;
    }
    case 1: {
      record.body = ControlTypeOne{UINT16_MAX};
      record.enabled = 1;
      shape.object.mode = std::bit_cast<std::int32_t>(word(source, 0x5c));
      shape.object.policy = byte(source, 0x6c);
      shape.object.selected_id = word(source, 0x70);
      d.type_one_initial_angle =
          (shape.object.mode == 0 || shape.object.mode == 7 ||
           shape.object.mode == 8)
              ? (word(source, 0x48) - 0x8000u) & 0xffffu
              : word(source, 0x58);
      break;
    }
    case 2: {
      const auto model = resolve(0);
      ControlTypeTwo body;
      body.selector = word(source, 0x40);
      body.parameter = UINT32_MAX;
      body.half_parameter = UINT16_MAX;
      body.byte_parameter = byte(source, 0x62);
      body.refresh_parameter = byte(source, 0x61);
      body.model_reference = ControlModelReference{model, word(source, 0x38)};
      body.matrix_resource_class = word(source, 0x48);
      record.body = body;
      record.enabled = (context.scenario == 1 && context.room == 1) ? 0 : 1;
      record.other_content.reset();
      record.other_resource_class.reset();
      d.model =
          RoomProxyModelSetup{model, byte(source, 0x44),
                              body.selector == 0 ? RoomProxyHelper::depth_sixty
                                                 : RoomProxyHelper::none};
      break;
    }
    case 3:
      record.body = ControlTypeThree{word(source, 0x34), UINT16_MAX};
      break;
    case 4:
      record.body = ControlTypeFour{word(source, 0x54), word(source, 0x34)};
      break;
    case 5: {
      ControlTypeFive body;
      body.reset_sentinel = UINT16_MAX;
      body.completion = UINT32_MAX;
      body.byte_parameter = UINT8_MAX;
      body.position = {std::bit_cast<float>(word(source, 0x34)),
                       std::bit_cast<float>(word(source, 0x38)),
                       std::bit_cast<float>(word(source, 0x3c))};
      body.effect_parameter = half(source, 0x44);
      record.body = body;
      break;
    }
    case 6:
      record.body = ControlTypeSix{word(source, 0x44)};
      record.enabled = 1;
      d.model = RoomProxyModelSetup{
          resolve(1), {}, RoomProxyHelper::reproject_middle};
      break;
    case 7: {
      record.body = ControlTypeSeven{word(source, 0x60)};
      record.enabled = 1;
      const auto mode = word(source, 0x3c);
      const auto slot = resolve(mode == 0x21 ? 0 : 1);
      std::optional<std::uint8_t> sound;
      if (mode == 2 || mode == 3 || mode == 4 || mode == 13 || mode == 14)
        sound = byte(source, 0x64);
      d.model = RoomProxyModelSetup{slot, sound, RoomProxyHelper::none};
      break;
    }
    case 9:
      record.body = ControlTypeNine{word(source, 0x34)};
      break;
    case 10:
      d.room_height = float(shape.upper);
      break;
    case 11:
      record.body = ControlTypeEleven{};
      break;
    case 13:
      record.body = ControlTypeThirteen{word(source, 0x34), half(source, 0x52)};
      break;
    default:
      break;
    }
    record.collision = shape;
    records_.push_back(std::move(d));
  }
}
const std::array<std::uint8_t, 32> &
RoomSceneInput::mapping(std::size_t index) const {
  if (index >= maps_.size())
    throw std::out_of_range("Invalid room proxy remap table");
  return maps_[index];
}
} // namespace reo::native::gameplay_scenario
