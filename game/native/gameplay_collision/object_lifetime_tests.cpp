#include "object_lifetime.hpp"
#include "ownership_reference.hpp"
#include "../gameplay_scenario/scene_model_bindings.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <set>
#include <sstream>
#include <cfenv>
namespace c = reo::native::gameplay_collision;
namespace r = c::room_objects;
namespace a = reo::native::gameplay_actors;
unsigned checks{}, rooms{}, created{}, updates{}, disables{}, retained_tops{}, dynamic_checks{},
    pool_full_cases{};
float maximum_error{};
namespace model=reo::native::gameplay_scenario;
bool use_real_model_provider{};
model::RoomModelRemap real_model_map;
unsigned real_binding_rooms{},real_binding_instances{},real_model_refusal_cases{},real_numeric_refusal_cases{};
std::vector<std::uint8_t> memory(0x800000);
std::set<unsigned> initialized_centers;
void check(bool value, const char* why) {
    ++checks;
    if (!value) {
        std::fprintf(stderr, "object lifetime check%u failed: %s\n", checks, why);
        std::exit(1);
    }
}
std::vector<std::byte> load(const char* path) {
    std::ifstream f(path, std::ios::binary);
    const std::vector<char> bytes{std::istreambuf_iterator<char>(f), {}};
    const auto span = std::as_bytes(std::span(bytes));
    return {span.begin(), span.end()};
}
std::uint32_t invoke(std::uint32_t pc, std::uint32_t a0 = 0, std::uint32_t a1 = 0) {
    R5900Context ctx;
    ctx.pc = pc;
    ctx.g[29].lo = 0x7f0000;
    ctx.g[31].lo = 0x1234;
    ctx.g[4].lo = a0;
    ctx.g[5].lo = a1;
    PS2Runtime runtime;
    runtime.lookupFunction(pc)(memory.data(), &ctx, &runtime);
    return std::uint32_t(ctx.g[2].lo);
}
void equal(c::Vec3 p, c::Vec3 q) {
    for (const auto pair : {std::pair{p.x, q.x}, std::pair{p.y, q.y}, std::pair{p.z, q.z}}) {
        const auto error = std::abs(pair.first - pair.second);
        maximum_error = std::max(maximum_error, error);
        if (error > 0.001f)
            std::fprintf(stderr, "native%g original%g\n", double(pair.first), double(pair.second));
        check(error <= 0.001f, "original instance/object XYZ and basis");
    }
}
struct Bindings : r::ModelBindings {
    mutable std::vector<std::pair<unsigned, unsigned>> events;
    std::array<bool, 256> marked{};
    std::array<c::actors::Basis, 256> saved;
    std::unique_ptr<model::SceneModels> models;
    std::unique_ptr<model::SceneModelBindings> real;
    void initialize(a::EntityStore& scene){
        if(!use_real_model_provider)return;
        model::SceneModelState state;for(unsigned i=0;i<128;++i){state.poses[i]=reo::native::transform_math::identity();state.styles[i]=0x8a123456u+i;state.visibility[i]=std::uint8_t(i*7);}
        models=std::make_unique<model::SceneModels>(state,real_model_map);real=std::make_unique<model::SceneModelBindings>(*models,scene);
        ref_write(memory.data(),0x324424,0x680000u);ref_write(memory.data(),0x688004,0x689000u);std::memcpy(memory.data()+0x689000,real_model_map.data(),32);
        std::memcpy(memory.data()+0x49f790,state.visibility.data(),128);std::memcpy(memory.data()+0x49f810,state.styles.data(),512);std::memcpy(memory.data()+0x49fa10,state.poses.data(),8192);
        std::memset(memory.data()+0x4a1b60,0,16);std::memset(memory.data()+0x4a1b70,0,512);
    }
    bool healthy()const noexcept override{return !real||real->healthy();}
    bool admit(std::uint8_t slot,r::ModelOperation op)noexcept override{return !real||real->admit(slot,op);}
    std::uint8_t resolve(std::uint8_t slot) const noexcept override {
        if(real)return real->resolve(slot);
        events.emplace_back(0, slot);
        return lifetime_fixture::missing_model ? 255 : std::uint8_t(slot + 3);
    }
    void mark(std::uint8_t slot) noexcept override {
        if(real){real->mark(slot);return;}
        marked[slot] = true;
    }
    void bind(std::uint8_t slot, a::EntityId id) noexcept override {
        if(real){real->bind(slot,id);return;}
        events.emplace_back(1, slot);
    }
    void unbind(std::uint8_t slot) noexcept override {
        if(real){real->unbind(slot);return;}
        events.emplace_back(2, slot);
    }
    void retain_pose(std::uint8_t slot, const c::actors::Basis& basis) noexcept override {
        if(real){real->retain_pose(slot,basis);return;}
        saved[slot] = basis;
    }
    void retain_pose_full(std::uint8_t slot,const c::actors::Basis& basis,const std::array<float,4>& w)noexcept override{
        if(real)real->retain_pose_full(slot,basis,w);else retain_pose(slot,basis);
    }
};
void binding_events(Bindings& bindings) {
    if(bindings.real){
        check(bindings.real->healthy(),"real native model owner remains healthy");const auto& s=bindings.models->state();const auto mask=bindings.real->mask();
        check(std::memcmp(s.visibility.data(),memory.data()+0x49f790,128)==0,"actual source model mark bytes");check(std::memcmp(s.styles.data(),memory.data()+0x49f810,512)==0,"actual source mark/style alias");check(std::memcmp(mask.data(),memory.data()+0x4a1b60,16)==0,"actual source binding masks");
        for(unsigned i=0;i<128;++i){const auto at=0x49fa10+64*i;const auto& m=s.poses[i];
            for(unsigned col=0;col<4;++col){equal({m[col][0],m[col][1],m[col][2]},ref_read<c::Vec3>(memory.data(),at+16*col));check(std::bit_cast<std::uint32_t>(m[col][3])==ref_read<std::uint32_t>(memory.data(),at+16*col+12),"actual source retained W bits");}
            check(bool(bindings.real->target(std::uint8_t(i)))==bool(ref_read<std::uint32_t>(memory.data(),0x4a1b70+4*i)),"actual source registered target presence");
        }
        return;
    }
    check(bindings.events == lifetime_fixture::events, "source model lookup/bind/unbind order");
    for (const auto& event : bindings.events)
        if (event.first == 2) {
            const auto at = 0x49fa10 + 64 * event.second;
            equal(bindings.saved[event.second].x, ref_read<c::Vec3>(memory.data(), at));
            equal(bindings.saved[event.second].y, ref_read<c::Vec3>(memory.data(), at + 16));
            equal(bindings.saved[event.second].z, ref_read<c::Vec3>(memory.data(), at + 32));
            equal(bindings.saved[event.second].translation,
                  ref_read<c::Vec3>(memory.data(), at + 48));
        }
    bindings.events.clear();
    lifetime_fixture::events.clear();
    for (unsigned i = 0; i < 256; ++i)
        check(bindings.marked[i] == bool(memory[0x49f790 + i]),
              "source mark including FF sentinel index");
}
std::set<std::uint32_t> live_proxies() {
    std::set<std::uint32_t> result;
    auto pointer = ref_read<std::uint32_t>(memory.data(), 0x3b5160);
    while (pointer) {
        check(result.size() < 128 && result.insert(pointer).second,
              "admitted original proxy list has bounded ownership");
        pointer = ref_read<std::uint32_t>(memory.data(), pointer + 0x28);
    }
    return result;
}
void compare(const r::Owner& owner, const r::InteractionOwner& interactions,
             r::InteractionOwner::Lifetime& life, const c::ownership::Proxies& proxies) {
    const auto live = live_proxies();
    check(live.size() == proxies.size(), "actual native/source shared proxy counts");
    for (const auto& id : owner.objects()) {
        const auto& o = *owner.get(id);
        const auto slot = *interactions.source_ordinal(id);
        const auto at = 0x3c4580 + 60 * unsigned(slot);
        if (initialized_centers.count(slot))
            equal(o.center, ref_read<c::Vec3>(memory.data(), at + 8));
        check(o.x == std::bit_cast<std::int8_t>(memory[at + 0x18]) &&
                  o.z == std::bit_cast<std::int8_t>(memory[at + 0x19]) &&
                  o.requests == std::bit_cast<std::int8_t>(memory[at + 0x1c]) &&
                  o.direction == memory[at + 0x1d] &&
                  o.control_flags == ref_read<std::uint32_t>(memory.data(), at + 0x24),
              "canonical object motion and transition fields");
        const auto raw = ref_read<std::uint32_t>(memory.data(), at + 0x28);
        check(bool(o.instance) == bool(raw), "original attached instance presence");
        if (o.instance) {
            const auto instance = life.acquire(o.instance);
            check(bool(instance) && instance->object == id,
                  "native scene domain and logical object identity resolve instance lease");
            equal(instance->scale, ref_read<c::Vec3>(memory.data(), raw + 0x22c));
            equal(instance->position, ref_read<c::Vec3>(memory.data(), raw + 0x200));
            equal(instance->basis.translation, ref_read<c::Vec3>(memory.data(), raw + 0x1f0));
            check(instance->active == bool(memory[raw]) &&
                      instance->visible == bool(memory[raw + 1]) &&
                      instance->category == memory[raw + 2] &&
                      instance->subtype == memory[raw + 4] &&
                      instance->type == ref_read<std::uint16_t>(memory.data(), raw + 0x36) &&
                      instance->flags == ref_read<std::uint32_t>(memory.data(), raw + 0x23c) &&
                      instance->object_ordinal == memory[raw + 0x240] &&
                      instance->model_slot == memory[raw + 0x242] &&
                      instance->material == memory[raw + 0x241] &&
                      instance->yaw == ref_read<std::uint16_t>(memory.data(), raw + 0x21e),
                  "full original native instance constructor fields");
            equal(instance->basis.x, ref_read<c::Vec3>(memory.data(), raw + 0x1c0));
            equal(instance->basis.y, ref_read<c::Vec3>(memory.data(), raw + 0x1d0));
            equal(instance->basis.z, ref_read<c::Vec3>(memory.data(), raw + 0x1e0));
            for(unsigned lane=0;lane<4;++lane)
                check(std::bit_cast<std::uint32_t>(instance->pose_w[lane])==ref_read<std::uint32_t>(memory.data(),raw+0x1cc+16*lane),"canonical external model W lane");
        }
        for (unsigned part = 0; part < 4; ++part) {
            const auto raw_proxy = ref_read<std::uint32_t>(memory.data(), at + 0x2c + part * 4);
            check(bool(o.proxies[part]) == bool(raw_proxy),
                  "source retains released handle fields");
            const auto* native = proxies.get(o.proxies[part]);
            check(bool(native) == bool(live.count(raw_proxy)),
                  "native stale proxy IDs reject retired source records");
            if (!native)
                continue;
            const auto& p = native->geometry;
            check(p.bounds == ref_read<c::Quad>(memory.data(), raw_proxy) &&
                      p.lower == ref_read<std::int32_t>(memory.data(), raw_proxy + 0x20) &&
                      p.upper == ref_read<std::int32_t>(memory.data(), raw_proxy + 0x24),
                  "actual original proxy quads/heights after lifecycle mutation");
            check(p.kind == memory[raw_proxy + 0x30] && p.query_class == memory[raw_proxy + 0x31] &&
                      p.priority == memory[raw_proxy + 0x32] &&
                      p.active == bool(memory[raw_proxy + 0x3c]) &&
                      p.busy == bool(memory[raw_proxy + 0x3d]),
                  "actual source proxy metadata");
            if (o.instance)
                check(native->owner == o.instance && native->owner_snapshot &&
                          *native->owner_snapshot == memory[raw_proxy + 0x44],
                      "opaque instance owner separate from physical object ordinal");
        }
    }
}
void dynamic(r::InteractionOwner::Lifetime& life) {
    const auto count = ref_read<std::uint32_t>(memory.data(), 0x743ea0);
    const auto& d = life.dynamic();
    check(d.count == count, "actual dynamic rebuild contact count");
    for (unsigned i = 0; i < count; ++i) {
        const auto t = ref_read<c::response::Triangle>(memory.data(), 0x7437a0 + 56 * i);
        check(d.storage[i].flags == t.flags, "original rebuilt dynamic flags");
        equal(d.storage[i].normal, t.normal);
        for (unsigned v = 0; v < 3; ++v)
            equal(d.storage[i].vertices[v], t.vertices[v]);
        check(d.storage[i].plane_d == t.plane_d, "original rebuilt dynamic plane");
    }
    ++dynamic_checks;
}
void room(const char* type_path, const char* sto_path, unsigned room, const char* grid_path,
          const char* wall_path, const char* floor_path, unsigned variant) {
    auto types = load(type_path), sto = load(sto_path);
    const auto grid = load(grid_path);
    auto* tb = reinterpret_cast<std::uint8_t*>(types.data());
    auto* sb = reinterpret_cast<std::uint8_t*>(sto.data());
    const auto count = ref_read<std::uint32_t>(tb, 4), offset = ref_read<std::uint32_t>(tb, 8),
               models = ref_read<std::uint32_t>(tb, 12),
               placements = ref_read<std::uint32_t>(sb, 4);
    if (variant) {
        for (unsigned i = 0; i < count; ++i) {
            tb[offset + 8 * i + 1] = 2;
            tb[offset + 8 * i + 2] = 1;
        }
        for (unsigned i = 0; i < placements; ++i)
            sb[8 + 16 * i + 6] = 15;
    }
    initialized_centers.clear();
    auto owner = r::Owner::import(types, sto);
    r::InteractionOwner interactions(owner);
    const auto walls = c::response::Grid::import(load(wall_path)),
               floors = c::response::Grid::import(load(floor_path));
    geometry_fixture::walls = &walls;
    lifetime_fixture::floors = &floors;
    invoke(0x6acf80);
    invoke(0x5c1120);
    invoke(0x590be0);
    std::memset(memory.data() + 0x49f790, 0, 256);
    std::memcpy(memory.data() + 0x74b1c0, tb + offset, count * 8);
    std::memcpy(memory.data() + 0x74b180, tb + models, count * 2);
    for (unsigned i = 0; i < placements; ++i) {
        std::memcpy(memory.data() + 0x1000, sb + 8 + 16 * i, 16);
        check(invoke(0x6ad0f0, 0x1000) != 0, "source placement allocation");
    }
    ref_write(memory.data(), 0x3243dc, std::uint16_t(room));
    std::memcpy(memory.data() + 0x20000, grid.data(), grid.size());
    invoke(0x6ad860, 0x20000);
    check(owner.install_grid(std::uint16_t(room), grid),
          "actual grid ready before instance construction");
    a::EntityStore scene({64});
    c::ownership::Proxies proxies;
    Bindings bindings;
    bindings.initialize(scene);
    r::InteractionOwner::Lifetime life(interactions, scene, proxies, bindings, walls, floors);
    lifetime_fixture::missing_model = variant == 2;
    std::vector<r::ObjectId> chosen;
    for (const auto& id : owner.objects()) {
        const auto& o = *owner.get(id);
        if (o.room != room)
            continue;
        const auto slot = *interactions.source_ordinal(id);
        const auto at = 0x3c4580 + 60 * unsigned(slot);
        const auto result = life.create(id);
        const auto original = invoke(0x6adab0, at);
        check(bool(result.instance) == bool(original),
              "actual native/source constructor admission");
        if (original) {
            check(result.status == r::InstanceStatus::complete && result.missing_proxies == 0,
                  "native instance/proxy resources admitted");
            chosen.push_back(id);
            initialized_centers.insert(slot);
            ++created;
            if(bindings.real)++real_binding_instances;
        }
        binding_events(bindings);
        compare(owner, interactions, life, proxies);
    }
#ifdef REO_ROOM_OBJECT_COMMANDS_TEST
    test_room_object_commands(owner,interactions,life,proxies);
#endif
    for (const auto& id : chosen) {
        const auto slot = *interactions.source_ordinal(id);
        const auto at = 0x3c4580 + 60 * unsigned(slot);
        auto instance = life.acquire(owner.get(id)->instance);
        const auto raw = ref_read<std::uint32_t>(memory.data(), at + 0x28);
        for (unsigned turn = 0; turn < 4; ++turn) {
            interactions.request_primary(id, std::uint16_t(turn * 0x4000));
            invoke(0x6b0510, slot, turn * 0x4000);
            memory[0x745d50] = 0;
            const auto native = life.update(owner.get(id)->instance);
            invoke(0x6aebe0, raw);
            check(native.geometry_changed == bool(memory[0x745d50]),
                  "exact source geometry-completion publication");
            compare(owner, interactions, life, proxies);
            ++updates;
            instance->position.x += 7;
            instance->position.y += 2;
            ref_write(memory.data(), raw + 0x200, instance->position);
            (void)life.update(owner.get(id)->instance);
            invoke(0x6aebe0, raw);
            compare(owner, interactions, life, proxies);
            ++updates;
            check(life.reset_requests(slot) == r::InstanceStatus::complete,
                  "native reset source admission");
            invoke(0x6b1010, slot);
            compare(owner, interactions, life, proxies);
            dynamic(life);
        }
    }
    // First disable is defined; repeated raw releases after this point can reuse
    // stale pointers, so subsequent native generation safety is not mislabeled
    // as a controlled original-pointer equivalence test.
    for (const auto& id : chosen) {
        const auto* o = owner.get(id);
        if (o->external_id == 0)
            continue;
        bool first = true;
        for (const auto& candidate : owner.objects()) {
            if (candidate == id)
                break;
            if (owner.get(candidate)->external_id == o->external_id) {
                first = false;
                break;
            }
        }
        if (!first)
            continue;
        const auto old = o->instance;
        const auto top = o->proxies[3];
        if(bindings.real){const auto live=life.acquire(o->instance);const auto raw=ref_read<std::uint32_t>(memory.data(),0x3c4580+60*unsigned(*interactions.source_ordinal(id))+0x28);
            for(unsigned lane=0;lane<4;++lane){const auto bits=0x7fc01234u+unsigned(*interactions.source_ordinal(id))*4+lane;live->pose_w[lane]=std::bit_cast<float>(bits);ref_write(memory.data(),raw+0x1cc+16*lane,bits);}
        }
        check(life.disable(std::int8_t(o->external_id)) == r::InstanceStatus::complete,
              "native disable admission");
        invoke(0x6ae390, o->external_id);
        binding_events(bindings);
        compare(owner, interactions, life, proxies);
        dynamic(life);
        check(!life.acquire(old), "retired instance ID no longer resolves");
        if (top && proxies.get(top)) {
            check(proxies.get(top)->owner == old, "source top proxy retains retired owner token");
            ++retained_tops;
        }
        ++disables;
    }

    unsigned other_instances{};
    for (const auto& id : owner.objects()) {
        const auto* o = owner.get(id);
        if (o->instance || (o->control_flags & 4))
            continue;
        const auto slot = *interactions.source_ordinal(id);
        check(scene.size() == 64 - std::size_t(ref_read<std::uint16_t>(memory.data(), 0x3b5700)),
              "shared native and original64-instance admission count");
        while (scene.size() < 64) {
            check(bool(scene.create(std::make_unique<a::Entity>()).id) && invoke(0x590c70, 1) != 0,
                  "declared unrelated scene occupancy fills actual64pool");
            ++other_instances;
        }
        const auto result = life.create(id);
        check(result.status == r::InstanceStatus::pool_full && !result.instance &&
                  invoke(0x6adab0, 0x3c4580 + 60 * slot) == 0,
              "source64pool exhaustion does not publish room instance");
        ++pool_full_cases;
        break;
    }
    if(bindings.real){
        // Required model failures refuse before publication and remain visible
        // to explicit teardown even after every ordinary instance was retired.
        for(const auto& id:owner.objects()){const auto* o=owner.get(id);if(o->instance||o->external_id==0||o->room!=room||(o->control_flags&4)||!(o->control_flags&8))continue;
            const auto authored=std::uint8_t(owner.type(o->type)->model_slot);if(authored>=32)continue;
            const auto flags=o->control_flags;const auto count_before=scene.size();const auto rounding=std::fegetround();check(std::fesetround(FE_TOWARDZERO)==0,"test-only numeric refusal input");
            const auto numeric=life.enable(std::int8_t(o->external_id));check(std::fesetround(rounding)==0,"restore test-only rounding mode");
            check(numeric.status==r::InstanceStatus::numeric_refused&&!o->instance&&o->control_flags==flags&&scene.size()==count_before&&bindings.real->healthy(),"numeric refusal precedes flags/allocation and preserves model owner");++real_numeric_refusal_cases;
            auto map=bindings.models->remap();map[authored]=128;bindings.models->room_remap(map);
            check(life.enable(std::int8_t(o->external_id)).status==r::InstanceStatus::model_refused,"real model failure reaches room-object caller");
            check(!o->instance&&o->control_flags==flags&&scene.size()==count_before,"model refusal precedes flags/allocation");++real_model_refusal_cases;break;
        }
        const bool failed=!bindings.real->healthy();check(life.close_checked()==(failed?r::InstanceStatus::model_refused:r::InstanceStatus::complete),"checked close preserves model failure and drains");++real_binding_rooms;
    }else life.close();
    check(proxies.size() == 0 && scene.size() == other_instances,
          "explicit native scene close releases retained proxies and instances");
    check(life.create({}).status == r::InstanceStatus::closed,
          "closed lifetime rejects new publication");
    ++rooms;
}
#ifndef REO_OBJECT_LIFETIME_TEST_ENTRY
#define REO_OBJECT_LIFETIME_TEST_ENTRY main
#endif
int REO_OBJECT_LIFETIME_TEST_ENTRY(int argc, char** argv) {
    check(argc == 4, "owned room/profile/geometry arguments");
    const auto tables = load(argv[3]);
    std::memcpy(memory.data() + 0x719900, tables.data(), tables.size());
    const auto profiles = load(argv[2]);
    std::memcpy(memory.data() + 0x723740, profiles.data(), profiles.size());
    for (unsigned i = 0; i < 4; ++i)
        memory[0x719900 + i] = std::uint8_t(i * 2);
    ref_write(memory.data(), 0x38b280, 0.0054931640625f);
    ref_write(memory.data(), 0x241c88, 3.1415927410125732f);
    ref_write(memory.data(), 0x241c78, -6.2831854820251465f);
    for (unsigned i = 0; i < 4; ++i)
        ref_write(memory.data(), 0x719910 + i * 4, 0x6aebe0u);
    std::ifstream manifest(argv[1]);
    std::string line;
    while (std::getline(manifest, line)) {
        std::istringstream f(line);
        std::array<std::string, 6> fields;
        for (unsigned i = 0; i < 6; ++i)
            std::getline(f, fields[i], '\t');
        if (fields[0].empty())
            continue;
        for (unsigned variant = 0; variant < 3; ++variant)
            room(fields[0].c_str(), fields[1].c_str(), unsigned(std::stoi(fields[2])),
                 fields[3].c_str(), fields[4].c_str(), fields[5].c_str(), variant);
    }
    check(rooms == 21 && created > 0 && updates > 0 && disables > 0 && retained_tops > 0 &&
              pool_full_cases > 0,
          "stock and synthetic lifecycle paths covered");
    std::printf("{\"checks\":%u,\"rooms\":%u,\"created\":%u,\"updates\":%u,\"disables\":%u,"
                "\"retained_tops\":%u,\"dynamic_checks\":%u,\"pool_full_cases\":%u,\"maximum_"
                "error\":%.9g,\"game_launched\":false}\n",
                checks, rooms, created, updates, disables, retained_tops, dynamic_checks,
                pool_full_cases, double(maximum_error));
    return 0;
}
