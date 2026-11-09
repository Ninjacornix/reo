namespace surface_metadata {
struct FootwearEntry {std::uint16_t variant;std::int8_t offset;};
#include "game/native/gameplay_world/footwear_profile.inc"
}
namespace surface_collision=reo::native::gameplay_collision;
namespace surface_contact=reo::native::gameplay_contact_world;
std::uint64_t surface_audio_cases{},footwear_cases{},surface_audio_commands{},surface_audio_mixed_frames{},surface_audio_refusals{};
struct SurfaceAudioRoom final:surface_contact::RoomInvocation {
    reo::native::gameplay_actors::EntityStore ids{{1}};
    surface_contact::RoomId id{ids.create(std::make_unique<reo::native::gameplay_actors::Entity>()).id};
    surface_collision::response::Grid empty;
    surface_collision::regions::World regions;
    surface_collision::room_objects::Owner objects;
    audio_world::CollisionRoom view;
    explicit SurfaceAudioRoom(std::uint16_t selector):regions(region_input(selector)),view{empty,empty,regions,objects,{},{},false,false}{}
    static surface_collision::regions::World region_input(std::uint16_t selector){
        std::vector<std::byte> raw(136);const auto put=[&]<class T>(unsigned at,T value){std::memcpy(raw.data()+at,&value,sizeof value);};put(0,1u);put(8,12u);put(12,1u);
        const std::array<surface_collision::regions::Vertex,8> vertices{{{-100,100,-100},{100,100,-100},{100,100,100},{-100,100,100},{-100,-100,-100},{100,-100,-100},{100,-100,100},{-100,-100,100}}};
        std::memcpy(raw.data()+16,vertices.data(),96);put(112,std::uint32_t(selector^0x0102u));put(116,std::uint32_t(selector));return surface_collision::regions::World::import(raw);
    }
    surface_contact::RoomId identity()const noexcept override{return id;}
    bool current(surface_contact::RoomId value)const noexcept override{return value==id&&bool(ids.acquire(value.entity));}
    std::uint16_t room_number()const noexcept override{return 0;}
    const audio_world::CollisionRoom& geometry()const override{return view;}
    std::shared_ptr<audio_scenario::SceneMatrixPrograms> programs()const override{return{};}
};
struct SurfaceAudioRooms final:surface_contact::RoomResources {
    std::shared_ptr<SurfaceAudioRoom> value;
    bool missing{};
    unsigned reads{};
    std::shared_ptr<surface_contact::RoomInvocation> retain(std::uint16_t room)override{++reads;return !missing&&room==0?value:nullptr;}
};
void compare_surface_audio(std::vector<std::uint8_t>& memory){
    std::ifstream owned(std::filesystem::path(audio_test_directory)/"owned_footwear.bin",std::ios::binary);std::array<std::uint8_t,416> properties{};owned.read(reinterpret_cast<char*>(properties.data()),properties.size());check(bool(owned));std::copy(properties.begin(),properties.end(),memory.begin()+0x7313c0);
    auto session=std::make_shared<audio_world::Session>();audio_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});auto world=std::make_shared<audio_world::World>(profile,session);
    const auto created=world->spawn_primary(0,std::make_unique<audio_world::Actor>());check(created.status==audio_world::actors::EntityStatus::completed);auto actor=world->primary(0);
    constexpr unsigned actor_at=0x4a5c30;PS2Runtime runtime;
    struct Appearance {std::uint16_t model;std::uint8_t character,outfit;};std::vector<Appearance> appearances;
    for(unsigned character=0;character<8;++character)for(unsigned outfit=0;outfit<3;++outfit)appearances.push_back({0,std::uint8_t(character),std::uint8_t(outfit)});
    for(const auto row:surface_metadata::variant_footwear)appearances.push_back({row.variant,255,255});
    const auto export_actor=[&](){memory[actor_at+2]=actor->category;memory[actor_at+3]=actor->slot;memory[actor_at+9]=actor->secondary;memory[actor_at+0x54f]=actor->motion_class;memory[actor_at+0xb98]=actor->character;memory[actor_at+0xbbc]=actor->appearance_variant;write(memory.data(),actor_at+0xbb4,actor->model_variant);std::memcpy(memory.data()+actor_at+0x38,&actor->position,12);};
    for(const auto appearance:appearances){actor->model_variant=appearance.model;actor->character=appearance.character;actor->appearance_variant=appearance.outfit;export_actor();auto c=context(0x1b8f40);SET_GPR_U32(&c,4,actor_at);sub_001B8F40_0x1b8f40(memory.data(),&c,&runtime);check(c.pc==0x1234&&audio_world::footwear_offset(*actor)==std::int8_t(GPR_U32(&c,2)));++footwear_cases;}
    auto engine=std::make_shared<b::Session>();b::Session reference;a::Owner owner(engine,session->random);const auto bytes=frontend_snd();check(owner.install(owner.begin_bank(3),bytes).status==a::Status::completed);
    const auto imported=a::import_snd(bytes,3);check(imported.status==a::Status::completed);const auto& parts=imported.value.parts;auto token=reference.begin_submission();check(token.status==b::Status::ok);auto capture=reference.capture(token.value,{parts[0].size,parts[1].size,parts[2].size});check(capture.status==b::Status::ok);
    const std::array<std::span<std::uint8_t>,3> targets{capture.value.hd(),capture.value.bd(),capture.value.tq()};for(unsigned i=0;i<3;++i)std::copy_n(bytes.begin()+parts[i].offset,parts[i].size,targets[i].begin());auto prepared=reference.prepare(token.value,std::move(capture.value));check(prepared.status==b::Status::ok&&reference.install(token.value,3,prepared.value)==b::Status::ok);
    std::copy(bytes.begin(),bytes.end(),memory.begin()+0x600000);auto import_context=context(0x1acfb0);SET_GPR_U32(&import_context,4,0x600000);SET_GPR_U32(&import_context,5,3);sub_001ACFB0_0x1acfb0(memory.data(),&import_context,&runtime);
    SurfaceAudioRooms rooms;audio_scenario::SceneResources resources;audio_scenario::ResourceTemplates templates;spatial.listener={};spatial.world_to_screen=reo::native::transform_math::identity();spatial.world_to_screen[3][0]=320;
    animation_audio::BasicAudio frontend(*world,owner,spatial,resources,templates,rooms);Gains gains;fail_at=UINT32_MAX;
    for(std::uint16_t selector:{std::uint16_t(0),std::uint16_t(1),std::uint16_t(0x0201),std::uint16_t(0x1000),std::uint16_t(0xffff),std::uint16_t(0x80)}){
        rooms.value=std::make_shared<SurfaceAudioRoom>(selector);original_audio_regions=&rooms.value->regions;
        check(original_audio_regions->select(surface_collision::Vec3{50,0,0})==(selector^0x0102u)&&original_audio_regions->select(surface_collision::Vec3{4800,0,0})==selector);
        for(const auto appearance:appearances)for(unsigned category=0;category<2;++category)for(unsigned kind=0;kind<5;++kind)for(unsigned position=0;position<3;++position){
            active_case="surface audio selector="+std::to_string(selector)+" model="+std::to_string(appearance.model)+" character="+std::to_string(appearance.character)+" outfit="+std::to_string(appearance.outfit)+" category="+std::to_string(category)+" kind="+std::to_string(kind)+" position="+std::to_string(position);
            const b::Command stop=b::StopAll{false};check(engine->apply({&stop,1}).status==b::Status::ok&&reference.apply({&stop,1}).status==b::Status::ok);
            actor->category=std::uint8_t(category);actor->slot=29;actor->model_variant=appearance.model;actor->character=appearance.character;actor->appearance_variant=appearance.outfit;actor->motion_class=position==2?0x2b:0;actor->secondary=position==2?0x6d:0;actor->position={position?4800.f:50.f,0,0};export_actor();
            const s::RandomState seed{std::uint16_t(kind*97),std::uint16_t(201+appearance.model+appearance.character),0};session->random.restore(seed);write(memory.data(),0x3244b0,seed.primary);write(memory.data(),0x3244b8,seed.secondary);memory[0x2b8de8]=seed.observed;
            original_events.clear();auto c=context(0x1b8d70);SET_GPR_U32(&c,4,actor_at);SET_GPR_U32(&c,5,kind);sub_001B8D70_0x1b8d70(memory.data(),&c,&runtime);check(c.pc==0x1234);
            for(const auto& e:original_events){const auto command=command_from_event(e);check(reference.apply({&command,1}).status==b::Status::ok);}
            frontend.surface(*actor,std::int8_t(kind));
            check(session->random.state().primary==read<std::uint16_t>(memory.data(),0x3244b0)&&session->random.state().secondary==read<std::uint16_t>(memory.data(),0x3244b8)&&session->random.state().observed==memory[0x2b8de8]);
            unsigned commands{};for(const auto& result:frontend.last_surface_results()){check(result.status==a::Status::completed||result.status==a::Status::skipped);commands+=unsigned(result.commands);}check(commands==original_events.size());
            const auto a=engine->snapshot(),e=reference.snapshot();check(a.request_age==e.request_age);
            for(unsigned i=0;i<16;++i){const auto& x=a.ports[3].requests[i];const auto& y=e.ports[3].requests[i];check(x.index==y.index&&x.group==y.group&&x.request_volume==y.request_volume&&x.request_pan==y.request_pan&&x.request_pitch==y.request_pitch&&x.sequence.active==y.sequence.active&&x.sequence.cursor==y.sequence.cursor&&x.sequence.program_offset==y.sequence.program_offset);}
            std::array<float,64> actual{},expected{};check(engine->mix_add(actual.data(),32,gains)==b::Status::ok&&reference.mix_add(expected.data(),32,gains)==b::Status::ok);check(actual==expected);surface_audio_commands+=original_events.size();surface_audio_mixed_frames+=32;++surface_audio_cases;
        }
    }
    actor->category=0;actor->character=0;actor->appearance_variant=0;actor->model_variant=0;
    for(unsigned failure=0;failure<4;++failure){
        rooms.missing=failure==0;rooms.value=std::make_shared<SurfaceAudioRoom>(0);
        if(failure==1)rooms.value->ids.retire(rooms.value->id.entity);
        actor->appearance_variant=failure==2?3:0;
        session->random.restore({0,123,0});auto expected=session->random;(void)expected.request(1);bool refused{};
        try{frontend.surface(*actor,failure==3?std::int8_t(-1):std::int8_t(0));}catch(const std::exception&){refused=true;}
        check(refused&&frontend.last_surface_results().empty());check(session->random.state()==(failure==3?s::RandomState{0,123,0}:expected.state()));++surface_audio_refusals;
    }
    original_audio_regions=nullptr;
}
