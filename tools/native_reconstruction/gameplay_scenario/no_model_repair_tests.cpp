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

struct CapturedSound {std::array<std::uint32_t,3> position;std::uint8_t resource;std::uint16_t event;friend bool operator==(const CapturedSound&,const CapturedSound&)=default;};
std::vector<CapturedSound> source_sounds;
void source_sound(std::uint8_t* p,R5900Context* ctx,PS2Runtime*){
 const auto at=GPR_U32(ctx,4);source_sounds.push_back({{fixture_read<std::uint32_t>(p,at),fixture_read<std::uint32_t>(p,at+4),fixture_read<std::uint32_t>(p,at+8)},std::uint8_t(GPR_U32(ctx,5)),std::uint16_t(GPR_U32(ctx,6))});ctx->pc=GPR_U32(ctx,31);
}
struct CapturedSounds final:sc::SceneMatrixSoundSink {
 std::vector<CapturedSound> values;bool admitted()const noexcept override{return true;}
 bool emit(reo::native::transform_math::Vector p,std::uint8_t resource,std::uint16_t event)override{values.push_back({{std::bit_cast<std::uint32_t>(p.x),std::bit_cast<std::uint32_t>(p.y),std::bit_cast<std::uint32_t>(p.z)},resource,event});return true;}
};
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at) const {
  if(at==0x6b60e0)return source_sound;
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
std::uint32_t call(std::uint32_t at, std::uint8_t *ram, std::uint32_t arg = 0,std::uint32_t arg1=0,std::uint32_t arg2=0) {
  PS2Runtime rt;
  R5900Context ctx;
  SET_GPR_U32(&ctx, 29, 0x1fff000);
  SET_GPR_U32(&ctx, 31, 0x1ff0000);
  SET_GPR_U32(&ctx, 4, arg);SET_GPR_U32(&ctx,5,arg1);SET_GPR_U32(&ctx,6,arg2);
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
                 const sc::RoomModelRemap &remap, std::uint32_t capacity = 128, const sc::SceneMatrixPrograms::State& channels = {})
      : pool(std::make_shared<scene::Records>(capacity)), models(state, remap),
        bindings(models, entities),
        programs(controls, models, bindings, flags, room, channels) {}
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
  fixture_write(ram.data(), container + 0x8000, maps);fixture_write(ram.data(),container+0x8004,maps+32);
  std::memcpy(ram.data() + maps, input.mapping(0).data(), 32);
  std::memcpy(ram.data() + maps + 32, input.mapping(1).data(), 32);
  fixture_write(ram.data(), 0x3243da, context.scenario);
  fixture_write(ram.data(), 0x3243dc, context.room);
  for (unsigned i = 0; i < 128; ++i) {
    fixture_write(ram.data(), 0x49fa10 + 64 * i, state.poses[i]);
    ram[0x4a1d70 + i] = *state.sound_resources[i];fixture_write(ram.data(),0x49f810+4*i,state.styles[i]);
  }
  std::memcpy(ram.data() + 0x10000, data.data(), data.size());
  call(0x5c1120, ram.data());
  for(unsigned r=0;r<128;++r)for(unsigned e=0;e<24;++e)fixture_write<std::uint16_t>(ram.data(),0x4a1df0+48*r+2*e,0x1234);
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
      if (const auto *two = std::get_if<sc::ControlTypeTwo>(&record->body))
        check(*two->matrix_resource_class ==
              fixture_read<std::uint32_t>(ram.data(), at + 0x58));
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

std::uint64_t repaired_rooms{}, absent_records{}, repair_selectors{}, repair_frames{}, intentional_counter_differences{}, intentional_binding_differences{}, intentional_visibility_differences{}, adjustment_alias_writes{};
void project_channel(std::uint8_t* p,std::uint32_t at,const sc::SceneMatrixChannel& c){
 p[at+1]=c.contact.gate;p[at+2]=c.interaction;p[at+3]=c.progress;p[at+4]=c.playback;p[at+6]=std::uint8_t(c.model_slot.encoded());p[at+7]=c.program;p[at+8]=c.cursor;p[at+9]=c.curve;p[at+10]=c.transform;p[at+11]=c.contact.active;
 fixture_write(p,at+12,c.time);fixture_write(p,at+14,c.segment);fixture_write(p,at+16,c.sound_cursor);p[at+20]=c.source_type;std::memcpy(p+at+32,c.matrix.data(),64);
}
void compare_channels(World& world){for(unsigned i=0;i<16;++i){const auto at=0x4a3620+96*i;std::array<std::uint8_t,96> p;std::memcpy(p.data(),ram.data()+at,96);project_channel(p.data(),0,*world.programs.inspect(i));if(std::memcmp(p.data(),ram.data()+at,96)){std::cerr<<"channel "<<i<<"\n";for(unsigned j=0;j<96;++j)if(p[j]!=ram[at+j])std::cerr<<j<<":"<<unsigned(p[j])<<"/"<<unsigned(ram[at+j])<<" ";std::cerr<<"\n";}check(std::memcmp(p.data(),ram.data()+at,96)==0);}}
void repair_stock(const char* path){
 std::ifstream stream(path,std::ios::binary);std::array<char,4> magic;stream.read(magic.data(),4);check(magic==std::array<char,4>{'R','S','I','1'});const auto count=stream_word(stream);check(count==166);
 for(unsigned ri=0;ri<count;++ri){
  const auto scenario=stream_word(stream),room=stream_word(stream),n=stream_word(stream),m=stream_word(stream),names=stream_word(stream);check(n<1048576&&m<1048576&&names<256);
  std::vector<std::byte>a(n),s(m);std::string name(names,'\0');stream.read(reinterpret_cast<char*>(a.data()),n);stream.read(reinterpret_cast<char*>(s.data()),m);stream.read(name.data(),names);check(bool(stream));
  const sc::content::ScriptBank bank(bytes(s),sc::content::BankFormat::room_section);const c::ImportContext ctx{std::uint16_t(scenario),std::uint16_t(room)};auto input=std::make_shared<const sc::RoomSceneInput>(a,bank,ctx);auto state=model_state(0);std::array<bool,128>centered{};
  for(const auto&d:input->records())if(d.model&&d.model->slot.slot()&&!centered[*d.model->slot.slot()]){const auto slot=*d.model->slot.slot();auto& pose=state.poses[slot];std::int64_t x{},z{};for(const auto p:d.initial.collision->bounds){x+=p.x;z+=p.z;}pose[3][0]=float(x/4);pose[3][2]=float(z/4);centered[slot]=true;}
  World world(state,{});world.room=std::uint16_t(room);c::delivery::RoomCounters counters;counters.reset(0x1234);const auto before=counters.snapshot();
  auto result=sc::RoomSceneOwner::install(input,world.controls,world.proxies,world.models,world.programs,world.globals,sc::NoModelRepair::authored_absent);
  if(result.status!=sc::RoomSceneStatus::completed)std::cerr<<"repair admission "<<name<<" status "<<unsigned(result.status)<<"\n";
  check(result.status==sc::RoomSceneStatus::completed&&result.owner);original_setup(a,*input,state,ctx);compare(world,*input,*result.owner);check(counters.snapshot()==before);++installed_rooms;++stock_rooms;stock_records+=input->records().size();
  std::optional<sc::ModelReference> absent;std::vector<unsigned> channels;
  for(const auto&d:input->records())if(d.model&&d.model->slot.absent()&&(d.model->sound_resource||d.model->helper!=sc::RoomProxyHelper::none)){absent=d.model->slot;++absent_records;const auto k=scene::kind(d.initial.body);if((k==0||k==2)&&std::find(channels.begin(),channels.end(),d.initial.authored_id)==channels.end())channels.push_back(d.initial.authored_id);}
  if(!absent)continue;
  ++repaired_rooms;std::cerr<<"repair case "<<name<<"\n";check(world.models.admits(*absent));check(!world.models.admits(sc::ModelReference(255)));check(!world.models.pose(std::uint32_t(255)));check(world.models.pose(*absent)==sc::ModelMatrix{});
  check(world.models.state().absent_sound_resource.has_value());const auto sound=*world.models.state().absent_sound_resource;check(sound==ram[0x4a1e6f]);check(fixture_read<std::uint16_t>(ram.data(),0x4a1e6e)==std::uint16_t(0x34u|(std::uint16_t(sound)<<8)));++intentional_counter_differences;
  for(unsigned r=0;r<128;++r)for(unsigned e=0;e<24;++e){check(counters.get(r,e)==0x1234);if(r!=2||e!=15)check(fixture_read<std::uint16_t>(ram.data(),0x4a1df0+48*r+2*e)==0x1234);}
  auto target=std::make_shared<sc::ModelMatrix>(reo::native::transform_math::identity());const auto retained=target.use_count();const auto mask=world.bindings.mask();check(world.bindings.bind_pose(*absent,target));check(*target==sc::ModelMatrix{}&&target.use_count()==retained&&world.bindings.mask()==mask);check(!world.bindings.target(*absent));check(counters.snapshot()==before);
  call(0x5d8280,ram.data(),255,0x900000);check(fixture_read<std::uint32_t>(ram.data(),0x4a1b7c)==0x80000000u);check(fixture_read<std::uint32_t>(ram.data(),0x4a1f6c)==0x900000);check(fixture_read<sc::ModelMatrix>(ram.data(),0x900000)==sc::ModelMatrix{});++intentional_binding_differences;call(0x5d8300,ram.data(),255);check(fixture_read<std::uint32_t>(ram.data(),0x4a1f6c)==0);check(world.bindings.mask()==mask);
  // Actual original visibility toggles style31.bit31 through map1 FF. The
  // validated native NoModel is deliberately not a real visibility slot.
  unsigned authored=0;while(authored<32&&input->mapping(1)[authored]!=255)++authored;check(authored<32);std::array<std::byte,8>payload{};payload[0]=std::byte(authored);std::memcpy(ram.data()+0x910000,payload.data(),payload.size());const auto styles=world.models.state().styles;call(0x690640,ram.data(),0x910000);world.models.visibility(authored,true);check(world.models.state().styles==styles);check((fixture_read<std::uint32_t>(ram.data(),0x49f810+31*4)&0x80000000u)!=0);++intentional_visibility_differences;
  check(world.models.admits_adjustment(authored));for(unsigned preset=0;preset<8;++preset){
   original_setup(a,*input,state,ctx);std::array<std::uint8_t,64> prior;std::memcpy(prior.data(),ram.data()+0x4a39d0,64);fixture_write<std::uint32_t>(ram.data(),0x910000,authored);fixture_write<std::uint32_t>(ram.data(),0x910004,preset);call(0x690700,ram.data(),0x910000);if(std::memcmp(prior.data(),ram.data()+0x4a39d0,64))++adjustment_alias_writes;
   check(world.models.adjust(authored,preset)==sc::ModelStatus::completed);check(world.models.pose(*absent)==sc::ModelMatrix{});check(counters.snapshot()==before);
  }
  // All five actual source selectors, then the complete selected first curve.
  for(unsigned selection=0;selection<5;++selection)for(const auto index:channels){
   World playback(state,{});playback.room=std::uint16_t(room);auto own=sc::RoomSceneOwner::install(input,playback.controls,playback.proxies,playback.models,playback.programs,playback.globals,sc::NoModelRepair::authored_absent);check(bool(own.owner));original_setup(a,*input,state,ctx);check(playback.flags.strided(room,index,2,true,false));fixture_write<std::uint16_t>(ram.data(),0x4b9e24+12*room,std::uint16_t(1u<<index));
   const auto address=std::array<std::uint32_t,5>{0x6b5760,0x6b5920,0x6b5ab0,0x6b5c60,0x6b5e10}[selection];call(address,ram.data(),selection==1?0:index,selection==1?index:0);const auto selected=playback.programs.select(index,sc::SceneMatrixSelection(selection));check(selected.status==sc::SceneMatrixStatus::completed&&selected.matched&&selected.changed);compare_channels(playback);++repair_selectors;
   CapturedSounds sounds;source_sounds.clear();unsigned frame=0;for(;frame<1024&&playback.programs.inspect(index)->playback;++frame){call(0x6b4ba0,ram.data(),index);const auto advanced=playback.programs.advance(index,false,&sounds);check(advanced.status==sc::SceneMatrixStatus::completed);compare_channels(playback);check(sounds.values==source_sounds);++repair_frames;}check(frame<1024);check(playback.bindings.mask()==std::array<std::uint32_t,4>{});check(counters.snapshot()==before);
  }
  auto foreign=std::make_shared<const sc::RoomSceneInput>(a,bank,ctx);for(const auto&d:foreign->records())if(d.model&&d.model->slot.absent())check(!world.models.admits(d.model->slot));
  auto remap=input->mapping(1);remap[authored]=0;world.models.room_remap(remap);check(!world.models.admits(*absent));world.models.room_remap(input->mapping(1));check(!world.models.admits(*absent));world.bindings.unbind(*absent);check(world.bindings.healthy());
  // A fresh install obtains a new live lease; closing it invalidates retained
  // references without preserving the room owner by reference ownership.
  World lifetime(state,{});auto live=sc::RoomSceneOwner::install(input,lifetime.controls,lifetime.proxies,lifetime.models,lifetime.programs,lifetime.globals,sc::NoModelRepair::authored_absent);check(lifetime.models.admits(*absent));live.owner->close();check(!lifetime.models.pose(*absent)&&!lifetime.models.sound_resource(*absent));lifetime.bindings.unbind(*absent);check(lifetime.bindings.healthy());
  for(unsigned dirty=0;dirty<3;++dirty){sc::SceneMatrixPrograms::State initial{};if(dirty==0)initial[9].matrix[3][0]=1;else if(dirty==1)initial[10].source_type=1;World denied(state,{},128,initial);std::shared_ptr<sc::ModelMatrix> real;if(dirty==2){real=std::make_shared<sc::ModelMatrix>();check(denied.bindings.bind_pose(std::uint8_t(3),real));}auto no=sc::RoomSceneOwner::install(input,denied.controls,denied.proxies,denied.models,denied.programs,denied.globals,sc::NoModelRepair::authored_absent);check(no.status==sc::RoomSceneStatus::unadmitted_model&&!no.owner&&denied.pool->size()==0&&!denied.models.state().absent_sound_resource);}
 }
 check(stock_rooms==166&&stock_records==2144&&installed_rooms==166&&repaired_rooms==3&&absent_records==5&&repair_selectors==20);check(stream.peek()==std::char_traits<char>::eof());
}
int main(int argc,char**argv)try{check(argc==2);controlled();refusals();repair_stock(argv[1]);std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_calls\":"<<original_calls<<",\"stock_rooms\":"<<stock_rooms<<",\"stock_records\":"<<stock_records<<",\"installed_rooms\":"<<installed_rooms<<",\"repaired_rooms\":"<<repaired_rooms<<",\"authored_absent_records\":"<<absent_records<<",\"selector_cases\":"<<repair_selectors<<",\"playback_frames\":"<<repair_frames<<",\"counter_deviation_cases\":"<<intentional_counter_differences<<",\"binding_deviation_cases\":"<<intentional_binding_differences<<",\"visibility_deviation_cases\":"<<intentional_visibility_differences<<",\"source_b4_alias_changed_cases\":"<<adjustment_alias_writes<<",\"game_launched\":false,\"installed_in_game\":false}\n";}catch(const std::exception&e){std::cerr<<e.what()<<'\n';return 1;}
