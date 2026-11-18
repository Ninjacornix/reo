struct ControllerLightRoom final:reo::native::gameplay_contact_world::RoomInvocation {
    w::World& world;const reo::native::gameplay_collision::response::Grid& floor;
    reo::native::gameplay_actors::EntityStore identities{{1}};
    reo::native::gameplay_contact_world::RoomId id;
    reo::native::gameplay_collision::regions::World regions;
    reo::native::gameplay_collision::room_objects::Owner objects;
    w::CollisionRoom geometry_;
    ControllerLightRoom(w::World& value,const reo::native::gameplay_collision::response::Grid& grid):world(value),floor(grid),geometry_{floor,floor,regions,objects,{},{},false,false}{
        const auto made=identities.create(std::make_unique<reo::native::gameplay_actors::Entity>());check(bool(made.id));id={made.id};
    }
    reo::native::gameplay_contact_world::RoomId identity()const noexcept override{return id;}
    bool current(reo::native::gameplay_contact_world::RoomId value)const noexcept override{return value==id&&bool(identities.acquire(id.entity))&&!world.closed();}
    std::uint16_t room_number()const noexcept override{return world.room;}
    const w::CollisionRoom& geometry()const override{return geometry_;}
    std::shared_ptr<s::SceneMatrixPrograms> programs()const override{throw std::runtime_error("Light-only fixture has no matrix-program request");}
};
struct ControllerLightRooms final:reo::native::gameplay_contact_world::RoomResources {
    s::CutscenePlayback& playback;w::World& world;std::shared_ptr<ControllerLightRoom> room;
    std::unique_ptr<s::CutsceneLights> attempt;
    ControllerLightRooms(s::CutscenePlayback& value,w::World& owner,const reo::native::gameplay_collision::response::Grid& grid):playback(value),world(owner),room(std::make_shared<ControllerLightRoom>(owner,grid)){}
    std::shared_ptr<reo::native::gameplay_contact_world::RoomInvocation> retain(std::uint16_t number)override{
        check(playback.busy()&&playback.tick().status==s::CutscenePlaybackStatus::busy&&playback.advance().status==s::CutscenePlaybackStatus::busy);
        check(playback.unbind_lights()==s::CutscenePlaybackStatus::busy&&playback.bind_lights(attempt)==s::CutscenePlaybackStatus::busy);
        check(world.close()==w::Status::busy&&!world.closed());++light_floor_guards;
        return number==world.room?room:nullptr;
    }
};
void compare_light_controller(w::World& world,s::FlagState& flags,s::StreamChannels& channels,
                              Services& services,s::CutscenePlayback& playback,std::vector<std::uint8_t>& memory,
                              const reo::native::gameplay_collision::response::Grid& floor){
    ControllerLightRooms rooms(playback,world,floor);s::Lighting lights,foreign_lights;s::Fog fog({});std::array<std::byte,4> unsupported{};check(fog.import_fog(unsupported)==s::FogStatus::unsupported_version);
    s::CutscenePlaybackState foreign;
    auto wrong=std::make_unique<s::CutsceneLights>(world,foreign,foreign_lights,fog,rooms);
    check(playback.bind_lights(wrong)==s::CutscenePlaybackStatus::unavailable&&wrong);wrong.reset();
    auto native=std::make_unique<s::CutsceneLights>(world,playback.state(),lights,fog,rooms);auto* borrowed=native.get();
    check(playback.bind_lights(native)==s::CutscenePlaybackStatus::completed&&!native&&playback.lights()==borrowed);
    rooms.attempt=std::make_unique<s::CutsceneLights>(world,playback.state(),foreign_lights,fog,rooms);
    check(playback.bind_lights(rooms.attempt)==s::CutscenePlaybackStatus::unavailable&&rooms.attempt);
    std::optional<reo::native::gameplay_collision::Vec3> point;
    for(const auto& triangle:floor.triangles()){
        reo::native::gameplay_collision::Vec3 candidate;for(const auto& vertex:triangle.vertices){candidate.x+=vertex.x/3;candidate.y+=vertex.y/3;candidate.z+=vertex.z/3;}candidate.y+=10;
        if(floor.floor(candidate,255).triangle){point=candidate;break;}
    }
    check(bool(point));std::array<std::vector<std::byte>,2> records{std::vector<std::byte>(144),std::vector<std::byte>(96)};
    const auto write=[&](unsigned stream,unsigned offset,auto value){std::memcpy(records[stream].data()+offset,&value,sizeof value);};
    for(unsigned key=0;key<2;++key){const unsigned offset=48*key;write(0,offset+1,std::int8_t(1));write(0,offset+2,std::uint16_t(key*10));write(0,offset+8,*point);write(0,offset+20,*point);write(0,offset+32,100.f+100.f*float(key));write(0,offset+44,1.f+float(key));for(unsigned lane=0;lane<3;++lane){write(0,offset+36+lane,std::uint8_t(20+20*key+lane));write(0,offset+40+lane,std::uint8_t(50+30*key+lane));}}
    write(0,98,std::uint16_t(65535));write(1,1,std::int8_t(1));write(1,6,std::int16_t(1));write(1,50,std::uint16_t(65535));
    const std::array<std::array<std::span<const std::byte>,2>,1> spans{{{records[0],records[1]}}};const auto tracks=s::PreparedLightTracks::import(spans);
    light_floor=&floor;compare_bound_lights=true;
    const auto compare_lights=[&]{check(lights.primary_count()==memory[0x747538]&&lights.auxiliary_count()==memory[0x748340]);check(std::memcmp(lights.primary().data(),memory.data()+0x747540,64*56)==0&&std::memcmp(lights.auxiliary().data(),memory.data()+0x748350,64*56)==0);};
    for(unsigned clock=0;clock<32;++clock){
        case_id=110000+clock;lights.reset_work();std::fill_n(memory.data()+0x747540,64*56,0);std::fill_n(memory.data()+0x748350,64*56,0);memory[0x747538]=memory[0x748340]=0;memory[0x3240be]=255;memory[0x3240bd]=std::uint8_t(fog.state().selected);std::fill_n(memory.data()+0x3dc1e0,4*0x6f4,0);std::fill_n(memory.data()+0x3dbbe0,16*96,0);
        invoke(memory.data(),0x6b3830);check(borrowed->initialize()==s::CutsceneLightsStatus::completed);invoke(memory.data(),0x6b38d0);check(borrowed->install(tracks)==s::CutsceneLightsStatus::completed);compare_lights();
        auto& state=playback.state();state={};state.phase=1;state.subphase=3;state.end_frame=1000;state.light_groups=1;world.mode=0;world.session().single_roster_setup=1;world.session().clock_mode=std::uint8_t(clock);inputs={1,2,1,1,0,false,false,0};
        std::memcpy(memory.data()+0xc60000,records[0].data(),records[0].size());std::memcpy(memory.data()+0xc60100,records[1].data(),records[1].size());put(memory.data(),0x38ff90,0xc60000u);put(memory.data(),0x38ff94,0xc60100u);
        for(unsigned tick=0;tick<16;++tick){project(memory.data(),state,world,flags,channels);native_events.clear();source_events.clear();invoke(memory.data(),0x5ee680);services.playback=&playback;
            check(playback.tick().status==s::CutscenePlaybackStatus::completed);services.playback=nullptr;compare(memory.data(),state,world,channels);compare_lights();++light_ticks;}
        // The controller also borrows the worker's actual activity flag when
        // a caller visits the owned worker directly between controller ticks.
        put(memory.data(),0x38eca8,state.frame);invoke(memory.data(),0x6b3bb0);check(borrowed->sample(0).status==s::CutsceneLightsStatus::completed);compare_lights();
    }
    compare_bound_lights=false;light_floor=nullptr;
    check(playback.unbind_lights()==s::CutscenePlaybackStatus::completed&&!playback.lights());check(playback.unbind_lights()==s::CutscenePlaybackStatus::completed);rooms.attempt.reset();
}
