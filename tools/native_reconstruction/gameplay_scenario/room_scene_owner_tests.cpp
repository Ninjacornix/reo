#include "game/native/gameplay_scenario/room_scene_owner.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <source_location>

namespace sc = reo::native::gameplay_scenario;
namespace scene = reo::native::gameplay_scene;
namespace c = reo::native::gameplay_collision;
namespace vm = sc;
std::uint64_t checks{}, original_calls{}, stock_records{}, stock_rooms{},
    installed_rooms{}, refused_rooms{}, helper84{}, helper85{}, reprojections{},
    inverse_calls{};
void check(bool value,
           std::source_location where = std::source_location::current()) {
  ++checks;
  if (!value)
    throw std::runtime_error("Room scene initializer mismatch at check " +
                             std::to_string(checks) + " line " +
                             std::to_string(where.line()));
}
template <class T> T fixture_read(const std::uint8_t *p, std::uint32_t at) {
  return transform_read<T>(p, at);
}
template <class T>
void fixture_write(std::uint8_t *p, std::uint32_t at, T value) {
  transform_write(p, at, value);
}
#include "control_export.inc"
void original_transform_port(std::uint8_t *ram, R5900Context *ctx,
                             PS2Runtime *) {
  const auto at = GPR_U32(ctx, 4), other = GPR_U32(ctx, 5), n = GPR_U32(ctx, 6);
  if (ctx->pc == 0x107c68) {
    check(at <= 0x2000000 && n <= 0x2000000 - at);
    std::memset(ram + at, int(other & 255), n);
  } else if (ctx->pc == 0x107ab0) {
    check(at <= 0x2000000 && n <= 0x2000000 - at && other <= 0x2000000 &&
          n <= 0x2000000 - other);
    std::memcpy(ram + at, ram + other, n);
  } else
    throw std::runtime_error("Unexpected original room dependency " +
                             std::to_string(ctx->pc));
  SET_GPR_U32(ctx, 2, at);
  ctx->pc = GPR_U32(ctx, 31);
}
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at) const {
  if (at == 0x5c5d30)
    ++helper84;
  else if (at == 0x5c6100)
    ++helper85;
  else if (at == 0x5c66c0)
    ++reprojections;
  else if (at == 0x191430)
    ++inverse_calls;
  switch (at) {
#include "original_lookup.inc"
  case 0x107ab0:
  case 0x107c68:
    return original_transform_port;
  default:
    throw std::runtime_error("Unadmitted room initializer dependency " +
                             std::to_string(at));
  }
}
std::uint32_t call(std::uint32_t at, std::uint8_t *ram, std::uint32_t arg = 0) {
  PS2Runtime rt;
  R5900Context ctx;
  SET_GPR_U32(&ctx, 29, 0x1fff000);
  SET_GPR_U32(&ctx, 31, 0x1ff0000);
  SET_GPR_U32(&ctx, 4, arg);
  rt.lookupFunction(at)(ram, &ctx, &rt);
  check(ctx.pc == 0x1ff0000);
  ++original_calls;
  return GPR_U32(&ctx, 2);
}
std::vector<std::uint8_t> ram(0x2000000);
sc::content::Bytes bytes(std::span<const std::byte> data) {
  return std::make_shared<const std::vector<std::byte>>(data.begin(),
                                                        data.end());
}
void put(std::vector<std::byte> &target, std::size_t at, std::uint32_t value) {
  for (unsigned i = 0; i < 4; ++i)
    target[at + i] = std::byte(value >> (8 * i));
}
struct World {
  std::shared_ptr<scene::Records> pool = std::make_shared<scene::Records>();
  sc::SceneControls controls{pool};
  c::ownership::Proxies proxies{pool};
  reo::native::gameplay_actors::EntityStore entities;
  sc::SceneModels models;
  sc::SceneModelBindings bindings;
  sc::FlagState flags;
  std::uint16_t room = 1;
  sc::SceneMatrixPrograms programs;
  sc::RoomSceneGlobals globals;
  explicit World(const sc::SceneModelState &state,
                 const sc::RoomModelRemap &remap, std::uint32_t capacity = 128)
      : pool(std::make_shared<scene::Records>(capacity)), models(state, remap),
        bindings(models, entities),
        programs(controls, models, bindings, flags, room) {}
};
sc::SceneModelState model_state(unsigned seed) {
  sc::SceneModelState state;
  for (unsigned i = 0; i < 128; ++i) {
    auto matrix = reo::native::transform_math::identity();
    reo::native::transform_math::reset_euler_axes(
        matrix, {0, std::uint16_t(seed * 1024), 0});
    const float scale = 0.5f + float(seed % 4) * 0.25f;
    for (unsigned col = 0; col < 3; ++col)
      for (unsigned lane = 0; lane < 3; ++lane)
        matrix[col][lane] = matrix[col][lane] * scale;
    matrix[3][0] = float(int(seed % 5) - 2) * 10;
    matrix[3][2] = float(int(seed % 7) - 3) * 10;
    state.poses[i] = matrix;
    state.sound_resources[i] = std::uint8_t(i ^ seed);
  }
  return state;
}
void original_setup(std::span<const std::byte> data,
                    const sc::RoomSceneInput &input,
                    const sc::SceneModelState &state,
                    c::ImportContext context) {
  std::fill(ram.begin(), ram.end(), 0);
  owned_room_constants(ram.data());
  const std::uint32_t container = 0x800000, maps = 0x810000;
  fixture_write(ram.data(), 0x324424, container);
  fixture_write(ram.data(), container + 0x8000, maps);
  std::memcpy(ram.data() + maps, input.mapping(0).data(), 32);
  std::memcpy(ram.data() + maps + 32, input.mapping(1).data(), 32);
  fixture_write(ram.data(), 0x3243da, context.scenario);
  fixture_write(ram.data(), 0x3243dc, context.room);
  for (unsigned i = 0; i < 128; ++i) {
    fixture_write(ram.data(), 0x49fa10 + 64 * i, state.poses[i]);
    ram[0x4a1d70 + i] = *state.sound_resources[i];
  }
  std::memcpy(ram.data() + 0x10000, data.data(), data.size());
  call(0x5c1120, ram.data());
  call(0x5c1390, ram.data(), 0x10000);
}
void compare(World &world, const sc::RoomSceneInput &input,
             const sc::RoomSceneOwner &owner) {
  auto at = fixture_read<std::uint32_t>(ram.data(), 0x3b5158);
  const auto order = world.proxies.ordered();
  check(order.size() == owner.identities().size());
  std::array<std::uint8_t, 196> projected;
  std::vector<std::pair<scene::RecordId, std::uint32_t>> identities;
  for (const auto &id : order) {
    check(at != 0);
    identities.emplace_back(id, at);
    const auto *proxy = world.proxies.get(id);
    check(proxy != nullptr);
    const auto &p = proxy->geometry;
    check(p.bounds == fixture_read<c::Quad>(ram.data(), at));
    check(p.lower == fixture_read<std::int32_t>(ram.data(), at + 0x20));
    check(p.upper == fixture_read<std::int32_t>(ram.data(), at + 0x24));
    check(p.kind == ram[at + 0x30] && p.query_class == ram[at + 0x31] &&
          p.priority == ram[at + 0x32] && p.active == (ram[at + 0x3c] != 0));
    const auto canonical=world.controls.records()->acquire(id);
    check(canonical&&canonical->value.condition_ordinal==ram[at+0x3f]);
    if(canonical->value.door_entry){const auto& entry=*canonical->value.door_entry;
      check(entry.side==fixture_read<std::uint32_t>(ram.data(),at+0x50));
      check(entry.yaw==fixture_read<std::uint32_t>(ram.data(),at+0x58));
    }
    if(canonical->value.object_entry){const auto& entry=*canonical->value.object_entry;
      check(entry.anchor==fixture_read<std::array<float,3>>(ram.data(),at+0x4c));
      check(entry.yaw==fixture_read<std::uint32_t>(ram.data(),at+0x58));
      check(entry.travel==fixture_read<std::uint32_t>(ram.data(),at+0x70));
      check(entry.endpoint==fixture_read<std::uint32_t>(ram.data(),at+0x78));
      check(entry.scenario_flag==fixture_read<std::uint16_t>(ram.data(),at+0x86));
    }
    if(canonical->value.ladder_entry){const auto& entry=*canonical->value.ladder_entry;
      check(entry.mode==fixture_read<std::uint32_t>(ram.data(),at+0x4c));
      check(entry.model.encoded()==fixture_read<std::uint32_t>(ram.data(),at+0x60));
    }
    if (p.kind < 14) {
      const auto record = world.controls.get(id);
      check(bool(record));
      std::memcpy(projected.data(), ram.data() + at, projected.size());
      export_control(projected.data(), 0, *record);
      if (std::memcmp(projected.data(), ram.data() + at, projected.size()))
        for (unsigned n = 0; n < projected.size(); ++n)
          if (projected[n] != ram[at + n])
            std::cerr << "tag " << unsigned(p.kind) << " offset " << n
                      << " native " << unsigned(projected[n]) << " original "
                      << unsigned(ram[at + n]) << "\n";
      check(std::memcmp(projected.data(), ram.data() + at, projected.size()) ==
            0);
      const auto *definition = owner.definition(id);
      check(definition && definition->ordinal == ram[at + 0x3f]);
      if (definition->type_one_initial_angle)
        check(*definition->type_one_initial_angle ==
              fixture_read<std::uint32_t>(ram.data(), at + 0x68));
      if (const auto *zero = std::get_if<sc::ControlTypeZero>(&record->body))
        check(zero->matrix_program->resource_class ==
              fixture_read<std::uint32_t>(ram.data(), at + 0x60));
      if (const auto *two = std::get_if<sc::ControlTypeTwo>(&record->body)) {
        check(*two->matrix_resource_class ==
              fixture_read<std::uint32_t>(ram.data(), at + 0x58));
        check(two->camera_anchor && *two->camera_anchor ==
              fixture_read<std::uint32_t>(ram.data(), at + 0x4c));
        check(two->camera_offset && *two->camera_offset == ram[at + 0x54]);
      }
    } else {
      check(bool(proxy->source));
      const auto parent = owner.definition(proxy->source);
      check(parent != nullptr);
    }
    at = fixture_read<std::uint32_t>(ram.data(), at + 0x2c);
  }
  check(at == 0);
  for (unsigned request = 0; request < 256; ++request) {
    const auto address = call(0x5819c0, ram.data(), request);
    const auto found = world.controls.first_route(std::uint8_t(request));
    check(found.status == sc::ControlStatus::completed);
    check(bool(found.id) == bool(address));
    if (found.id) {
      const auto known =
          std::find_if(identities.begin(), identities.end(),
                       [&](const auto &p) { return p.first == *found.id; });
      check(known != identities.end() && known->second == address);
    }
  }
  for (unsigned i = 0; i < 128; ++i)
    check(world.models.state().sound_resources[i] == ram[0x4a1d70 + i]);
  for (unsigned i = 0; i < 16; ++i)
    check(world.programs.inspect(i)->source_type == ram[0x4a3634 + 96 * i]);
  for (const auto &d : input.records())
    if (d.room_height)
      check(world.globals.height == fixture_read<float>(ram.data(), 0x49f78c));
}
void controlled() {
  std::vector<std::byte> script(128);
  put(script, 0, 64);
  put(script, 4, 96);
  for (unsigned i = 0; i < 32; ++i) {
    script[64 + i] = std::byte(i);
    script[96 + i] = std::byte(i);
  }
  sc::content::ScriptBank bank(bytes(script),
                               sc::content::BankFormat::room_section);
  for (unsigned seed = 0; seed < 64; ++seed) {
    std::vector<std::byte> data(64 + 14 * 0xb0);
    put(data, 4, 14);
    for (unsigned tag = 0; tag < 14; ++tag) {
      const auto at = 64 + tag * 0xb0;
      put(data, 8 + 4 * tag, std::uint32_t(at));
      for (unsigned i = 0; i < 0xb0; i += 4)
        put(data, at + i, (seed + 1) * 0x1020304u + i);
      put(data, at, tag);
      put(data, at + 4, tag % 7);
      const c::Quad bounds{c::Point{-100, -100}, c::Point{100, -100},
                           c::Point{100, 100}, c::Point{-100, 100}};
      std::memcpy(data.data() + at + 8, bounds.data(), 32);
      put(data, at + 0x28, 0);
      put(data, at + 0x2c, 200);
      put(data, at + 0x30, tag == 0 ? 0 : tag == 2 ? 1 : tag % 16);
      if (tag == 2)
        put(data, at + 0x40, seed % 2);
      if (tag == 1)
        put(data, at + 0x5c, std::array<unsigned, 4>{0, 7, 8, 9}[seed % 4]);
      if (tag == 7)
        put(data, at + 0x3c,
            std::array<unsigned, 7>{2, 3, 4, 13, 14, 0x21, 9}[seed % 7]);
    }
    const c::ImportContext context{1, std::uint16_t(seed % 2 + 1)};
    auto input =
        std::make_shared<const sc::RoomSceneInput>(data, bank, context);
    const auto state = model_state(seed);
    World world(state, {});
    const auto result = sc::RoomSceneOwner::install(
        input, world.controls, world.proxies, world.models, world.programs,
        world.globals);
    check(result.status == sc::RoomSceneStatus::completed && result.owner);
    original_setup(data, *input, state, context);
    compare(world, *input, *result.owner);
    const auto ids = world.proxies.ordered();
    result.owner->close();
    check(world.proxies.size() == 0);
    for (const auto &id : ids)
      check(!world.controls.get(id) && !result.owner->definition(id));
  }
}
std::uint32_t stream_word(std::ifstream &stream) {
  std::array<std::uint8_t, 4> b;
  stream.read(reinterpret_cast<char *>(b.data()), 4);
  check(bool(stream));
  return std::uint32_t(b[0]) | (std::uint32_t(b[1]) << 8) |
         (std::uint32_t(b[2]) << 16) | (std::uint32_t(b[3]) << 24);
}
void stock(const char *path) {
  std::ifstream stream(path, std::ios::binary);
  std::array<char, 4> magic;
  stream.read(magic.data(), 4);
  check(magic == std::array<char, 4>{'R', 'S', 'I', '1'});
  const auto rooms = stream_word(stream);
  check(rooms == 166);
  for (unsigned room_index = 0; room_index < rooms; ++room_index) {
    const auto scenario = stream_word(stream), room = stream_word(stream),
               n = stream_word(stream), m = stream_word(stream),
               names = stream_word(stream);
    check(n < 1024 * 1024 && m < 1024 * 1024 && names < 256);
    std::vector<std::byte> a(n), s(m);
    std::string name(names, '\0');
    stream.read(reinterpret_cast<char *>(a.data()), n);
    stream.read(reinterpret_cast<char *>(s.data()), m);
    stream.read(name.data(), names);
    check(bool(stream));
    const sc::content::ScriptBank bank(bytes(s),
                                       sc::content::BankFormat::room_section);
    const c::ImportContext context{std::uint16_t(scenario),
                                   std::uint16_t(room)};
    auto input = std::make_shared<const sc::RoomSceneInput>(a, bank, context);
    ++stock_rooms;
    stock_records += input->records().size();
    auto state = model_state(0);
    std::array<bool, 128> centered{};
    // Controlled external poses, NOT a claim that RDT alone constructs the
    // real scene models. Center the first referenced footprint per model.
    for (const auto &d : input->records())
      if (d.model && d.model->slot < 128 && !centered[d.model->slot]) {
        auto &pose = state.poses[d.model->slot];
        const auto &bounds = d.initial.collision->bounds;
        std::int64_t x{}, z{};
        for (const auto p : bounds) {
          x += p.x;
          z += p.z;
        }
        pose[3][0] = float(x / 4);
        pose[3][2] = float(z / 4);
        centered[d.model->slot] = true;
      }
    World world(state, {});
    world.globals.height = -37;
    const auto result = sc::RoomSceneOwner::install(
        input, world.controls, world.proxies, world.models, world.programs,
        world.globals);
    if (result.status != sc::RoomSceneStatus::completed) {
      check(result.status == sc::RoomSceneStatus::unadmitted_model ||
            result.status == sc::RoomSceneStatus::unsupported_numeric);
      check(!result.owner && world.proxies.size() == 0 &&
            world.globals.height == -37);
      for (unsigned i = 0; i < 128; ++i)
        check(world.models.state().sound_resources[i] ==
              state.sound_resources[i]);
      ++refused_rooms;
      std::cerr << "Explicit stock profile refusal " << name << " status "
                << unsigned(result.status) << "\n";
      continue;
    }
    ++installed_rooms;
    original_setup(a, *input, state, context);
    compare(world, *input, *result.owner);
    const auto ids = world.proxies.ordered();
    if (!ids.empty()) {
      check(world.proxies.retire(ids.front()));
      const auto replacement = world.pool->create({});
      check(bool(replacement));
      check(!result.owner->definition(ids.front()));
      result.owner->close();
      check(world.pool->acquire(*replacement) != nullptr);
      world.proxies.clear();
    }
    check(world.proxies.size() == 0);
  }
  check(stock_rooms == 166 && stock_records == 2144 && installed_rooms > 100 &&
        refused_rooms > 0);
  check(stream.peek() == std::char_traits<char>::eof());
}
void refusals() {
  std::vector<std::byte> script(128);
  put(script, 0, 64);
  put(script, 4, 96);
  for (unsigned i = 0; i < 32; ++i) {
    script[64 + i] = std::byte(i);
    script[96 + i] = std::byte(i);
  }
  std::vector<std::byte> data(12 + 0xb0);
  put(data, 4, 1);
  put(data, 8, 12);
  const c::Quad bounds{c::Point{-100, -100}, c::Point{100, -100},
                       c::Point{100, 100}, c::Point{-100, 100}};
  std::memcpy(data.data() + 20, bounds.data(), 32);
  put(data, 12 + 0x2c, 200);
  const auto parse = [&]() {
    return std::make_shared<const sc::RoomSceneInput>(
        data, sc::content::ScriptBank(bytes(script),
                                      sc::content::BankFormat::room_section));
  };
  const auto state = model_state(0);
  auto input = parse();
  const auto unchanged = [&](World &world) {
    check(world.globals.height == -19);
    for (unsigned i = 0; i < 128; ++i)
      check(world.models.state().sound_resources[i] ==
            state.sound_resources[i]);
    for (unsigned i = 0; i < 16; ++i)
      check(world.programs.inspect(i)->source_type == 0);
  };
  {
    World world(state, {}, 1);
    world.globals.height = -19;
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::pool_full && !r.owner &&
          world.pool->size() == 0);
    unchanged(world);
  }
  {
    World world(state, {});
    world.globals.height = -19;
    sc::SceneControls foreign;
    const auto r =
        sc::RoomSceneOwner::install(input, foreign, world.proxies, world.models,
                                    world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::owner_mismatch && !r.owner &&
          world.pool->size() == 0);
    unchanged(world);
  }
  {
    World world(state, {});
    world.globals.height = -19;
    check(bool(world.controls.append({})));
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::nonempty_pool && !r.owner &&
          world.pool->size() == 1);
    unchanged(world);
  }
  {
    World world(state, {});
    world.programs.close();
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::owner_mismatch && !r.owner &&
          world.pool->size() == 0);
  }
  {
    auto zero = state;
    zero.poses[0] = {};
    World world(zero, {});
    world.globals.height = -19;
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::unsupported_numeric && !r.owner &&
          world.pool->size() == 0);
    unchanged(world);
  }
  script[64] = std::byte(255);
  input = parse();
  {
    World world(state, {});
    world.globals.height = -19;
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::unadmitted_model && !r.owner &&
          world.pool->size() == 0);
    unchanged(world);
  }
  script[64] = std::byte(0);
  put(data, 12 + 0x30, 17);
  input = parse();
  {
    World world(state, {});
    world.globals.height = -19;
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::unadmitted_channel && !r.owner &&
          world.pool->size() == 0);
    unchanged(world);
  }
  put(data, 12, 7);
  put(data, 12 + 0x30, 0);
  put(data, 12 + 0x3c, 0x21);
  script[64] = std::byte(255);
  input = parse();
  {
    World world(state, {});
    world.globals.height = -19;
    const auto r = sc::RoomSceneOwner::install(input, world.controls,
                                               world.proxies, world.models,
                                               world.programs, world.globals);
    check(r.status == sc::RoomSceneStatus::completed && r.owner);
    check(r.owner->definition(r.owner->identities().front())->model->slot ==
          255);
    unchanged(world);
  }
  const auto rejected = [&]() {
    bool refused = false;
    try {
      (void)parse();
    } catch (const std::invalid_argument &) {
      refused = true;
    }
    check(refused);
  };
  put(data, 4, 129);
  rejected();
  put(data, 4, 1);
  put(data, 8, 0);
  rejected();
  put(data, 8, 12);
  put(data, 12, 14);
  rejected();
  put(data, 12, 0);
  put(data, 16, 256);
  rejected();
  put(data, 16, 0);
  put(script, 4, 100);
  rejected();
  put(script, 4, 96);
  data.resize(data.size() - 1);
  rejected();
}
int main(int argc, char **argv) {
  check(argc == 2);
  controlled();
  stock(argv[1]);
  refusals();
  std::cout << "{\"status\":\"passed\",\"checks\":" << checks
            << ",\"original_calls\":" << original_calls
            << ",\"controlled_rooms\":64,\"stock_rooms\":" << stock_rooms
            << ",\"stock_records\":" << stock_records
            << ",\"installed_stock_profile_rooms\":" << installed_rooms
            << ",\"refused_stock_profile_rooms\":" << refused_rooms
            << ",\"actual_helper84_calls\":" << helper84
            << ",\"actual_helper85_calls\":" << helper85
            << ",\"actual_reprojection_calls\":" << reprojections
            << ",\"actual_inverse_calls\":" << inverse_calls << "}\n";
}
