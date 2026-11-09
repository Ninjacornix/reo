unsigned surface_frames{},surface_emissions{},modulation_cases{};
unsigned surface_factory_cases{},surface_owner_frames{};
namespace surface_world=reo::native::gameplay_world;
namespace surface_rooms=reo::native::gameplay_contact_world;
struct SurfaceRoom final:surface_rooms::RoomInvocation {
    reo::native::gameplay_actors::EntityStore identities{{1}};
    surface_rooms::RoomId id{identities.create(std::make_unique<reo::native::gameplay_actors::Entity>()).id};
    reo::native::gameplay_collision::response::Grid floor;
    reo::native::gameplay_collision::regions::World regions;
    reo::native::gameplay_collision::room_objects::Owner objects;
    surface_world::CollisionRoom view;
    explicit SurfaceRoom(reo::native::gameplay_collision::response::Grid grid):floor(std::move(grid)),view{floor,floor,regions,objects,{},{},false,false}{}
    surface_rooms::RoomId identity()const noexcept override{return id;}
    bool current(surface_rooms::RoomId other)const noexcept override{return other==id&&bool(identities.acquire(other.entity));}
    std::uint16_t room_number()const noexcept override{return 7;}
    const surface_world::CollisionRoom& geometry()const override{return view;}
    std::shared_ptr<s::SceneMatrixPrograms> programs()const override{return{};} // Surface query does not consume matrix programs.
};
struct SurfaceRooms final:surface_rooms::RoomResources {
    std::shared_ptr<SurfaceRoom> room;
    unsigned reads{};
    explicit SurfaceRooms(std::shared_ptr<SurfaceRoom> value):room(std::move(value)){}
    std::shared_ptr<surface_rooms::RoomInvocation> retain(std::uint16_t number)override{++reads;return number==7?room:nullptr;}
};
std::shared_ptr<surface_world::World> surface_world_owner(unsigned count){
    surface_world::Profile profile;profile.layouts.push_back({0x100,0x10,0x20});profile.entities.capacity=16;
    auto session=std::make_shared<surface_world::Session>();session->primary_population=count;session->room=7;
    auto world=std::make_shared<surface_world::World>(profile,session);
    for(unsigned i=0;i<count;++i){auto actor=std::make_unique<surface_world::Actor>();actor->slot=std::uint8_t(29+i);actor->room=7;check(world->spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
    return world;
}
std::vector<std::vector<std::byte>> surface_skeletons(){
    const auto path=std::filesystem::path(surface_test_directory)/"owned_skeletons.bin";
    std::ifstream source(path,std::ios::binary);std::uint32_t count{};source.read(reinterpret_cast<char*>(&count),4);check(count==2);
    std::vector<std::vector<std::byte>> result;
    for(unsigned i=0;i<count;++i){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x100000);result.emplace_back(size);source.read(reinterpret_cast<char*>(result.back().data()),size);check(bool(source));}return result;
}
struct SurfaceSink final:e::SurfaceVisuals {
    e::PeriodicVisuals& visuals;std::vector<e::WorkStatus> statuses;
    explicit SurfaceSink(e::PeriodicVisuals& owner):visuals(owner){}
    bool bound_to(const reo::native::gameplay_session::Random& random)const noexcept override{return visuals.bound_to(random);}
    e::WorkStatus emit_surface(const e::SurfaceEmission& value)noexcept override{const auto status=visuals.emit_surface(value);statuses.push_back(status);return status;}
};
void compare_surface_work(std::uint8_t* memory,const std::vector<std::vector<std::byte>>& corpus){
    std::uint32_t seed=0x690490;
    const auto next=[&](){seed=seed*1664525u+1013904223u;return seed;};
    const std::array<std::uint32_t,16> edges{0,1,999,1000,1001,0x7fffffff,0x80000000,0x80000001,0xffffffff,0xfffffffe,0x7fffff80,0x80000080,16777215,16777216,16777217,0x12345678};
    for(unsigned i=0;i<16400;++i){
        const auto flags=std::uint16_t(next());const std::uint32_t selector=i<16?i:(i%7?1:next());
        std::array<std::uint32_t,4> words;for(unsigned j=0;j<4;++j)words[j]=i<edges.size()?edges[(i+j)%edges.size()]:next();
        const e::ModulationState initial{flags,{.25f,2.f,-1.f},.75f};e::Modulation native(initial);
        put(memory,0x4b9d1a,flags);put(memory,0x4bac84,initial.color);put(memory,0x4bac90,initial.intensity);
        put(memory,0x4baea0,0u);put(memory,0x70000,selector);std::memcpy(memory+0x70004,words.data(),16);
        const auto ret=call(memory,0x690490,{0x70000});check(GPR_U32(&ret,2)==0);
        check(native.configure(selector,words)==(selector==1));check(native.state().flags==get<std::uint16_t>(memory,0x4b9d1a));
        check(std::memcmp(&native.state().color,memory+0x4bac84,12)==0&&std::bit_cast<std::uint32_t>(native.state().intensity)==get<std::uint32_t>(memory,0x4bac90));
        native.reset();check(native.state().flags==0&&native.state().color.x==0&&native.state().color.y==0&&native.state().color.z==0&&native.state().intensity==0);++modulation_cases;
    }
    const auto profile=e::SurfaceProfile::import(std::as_bytes(std::span(surface_records)),surface_first_mask,surface_second_mask);
    const auto skeletons=surface_skeletons();
    using WorldActor=reo::native::gameplay_world::Actor;
    constexpr std::uint32_t actor_at=0x4a5c30,actor_model=0x220000,actor_nodes=0x230000;
    std::vector<std::byte> raw(128);const auto write=[&]<class T>(std::size_t at,T value){std::memcpy(raw.data()+at,&value,sizeof value);};
    write(8,4096u);write(12,4096u);write(16,1u);write(20,1u);write(32,32u);write(36,64u);write(40,40u);write(48,0u);write(52,0xffffffffu);
    using Triangle=reo::native::gameplay_collision::response::Triangle;
    const Triangle water{0x001a0381,{{{0,0,0},{4000,0,0},{0,0,4000}}},{0,1,0},-20};write(72,water);
    const auto floor=reo::native::gameplay_collision::response::Grid::import(raw);
    check(floor.floor({500,200,500},0x81).type==0x81&&floor.floor({500,200,500}).type==255);
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned case_id=0;case_id<16;++case_id){
        general_context="surface asset="+std::to_string(asset)+" case="+std::to_string(case_id);
        std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);owned_math_constants(memory);owned_surface_constants(memory);put(memory,0x294e00,m::identity());
        std::memcpy(memory+0xc00000,raw.data(),raw.size());call(memory,0x616310,{0xc00000});
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        reo::native::gameplay_session::Random random;random.restore({std::uint16_t(case_id*1931),std::uint16_t(0x93b1^case_id),std::uint8_t(case_id)});
        put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);put(memory,0x2b8de8,random.state().observed);
        e::PeriodicVisuals visuals(bank,random);SurfaceSink sink(visuals);
        WorldActor actor;actor.room=7;actor.position={500,0,500};actor.collision.pose_ready=true;
        actor.model=std::make_shared<reo::native::animation::Instance>(reo::native::animation::Skeleton::import_raw(skeletons[case_id%2]));
        for(const auto& row:profile.joints())check(row.joint<actor.model->nodes().size());
        put(memory,actor_at+0x34,actor_model);for(unsigned i=0;i<actor.model->nodes().size();++i)put(memory,actor_model+0x820+i*4,actor_nodes+i*400);
        put(memory,0x4baea0,1u);call(memory,0x5dfa90);const auto work=get<std::uint32_t>(memory,0x3b5848);check(work&&memory[work+3]==0x17&&get<std::uint32_t>(memory,work+0x24)==actor_at);
        e::SurfaceState state;state.phase=std::uint8_t(case_id%3);put(memory,work+8,state.phase);
        for(unsigned i=0;i<11;++i){state.first[i]=std::bit_cast<std::int8_t>(std::uint8_t(case_id*19+i*11));state.second[i]=std::bit_cast<std::int8_t>(std::uint8_t(case_id*31+i*7));state.previous[i]={float(i*3),float(int(i%5)-2)*20.f,float(i*5)};}
        std::memcpy(memory+work+0x114,state.previous.data(),132);std::memcpy(memory+work+0x198,state.first.data(),11);std::memcpy(memory+work+0x1a3,state.second.data(),11);
        e::Modulation modulation({std::uint16_t(case_id%4?1:0),{.3f,.7f,1.2f},.625f});
        for(unsigned tick=0;tick<96;++tick){
            general_context="surface asset="+std::to_string(asset)+" case="+std::to_string(case_id)+" tick="+std::to_string(tick);
            actor.room=std::uint16_t(tick%17==0?8:7);actor.collision.pose_ready=tick%19!=0;
            actor.position.x=tick%23==0?5000.f:500.f;
            auto parent=m::identity();
            if(case_id&1){
                for(std::size_t i=0;i<actor.model->nodes().size();++i)actor.model->local_translation(i,{});
                parent[3]={500.f+float(tick%7)*9.f,20.f+float(int((tick*7)%100)-50),500.f,1};
            }else for(unsigned i=0;i<11;++i){const auto& row=profile.joints()[i];const m::Vector local{500.f+float(i)*13.f+float(tick%7)*9.f,20.f+float(int((tick+i*7)%100)-50),500.f+float(i)*11.f};actor.model->local_translation(row.joint,local);}
            actor.model->rebuild(parent);
            for(unsigned i=0;i<actor.model->nodes().size();++i)put(memory,actor_nodes+i*400+0x30,actor.model->world_translation(i));
            put(memory,actor_at+0x1e2,actor.room);memory[actor_at+0x198]=actor.collision.pose_ready;put(memory,actor_at+0x38,actor.position);put(memory,0x3243dc,std::uint16_t(7));
            put(memory,0x4b9d1a,modulation.state().flags);put(memory,0x4bac84,modulation.state().color);put(memory,0x4bac90,modulation.state().intensity);
            call(memory,0x5ea970,{work});const auto result=e::advance_surface(state,profile,modulation,actor,7,floor,random,sink);
            check(result.status==e::SurfaceStatus::completed&&result.retire==(memory[work]==0));
            check(state.phase==memory[work+8]);
            if(std::memcmp(state.previous.data(),memory+work+0x114,132)!=0){for(unsigned i=0;i<11;++i){const auto original=get<m::Vector>(memory,work+0x114+i*12);const auto native=state.previous[i];std::cerr<<"joint "<<i<<" native "<<native.x<<','<<native.y<<','<<native.z<<" source "<<original.x<<','<<original.y<<','<<original.z<<'\n';}}
            check(std::memcmp(state.previous.data(),memory+work+0x114,132)==0);
            if(std::memcmp(state.first.data(),memory+work+0x198,11)!=0||std::memcmp(state.second.data(),memory+work+0x1a3,11)!=0){for(unsigned i=0;i<11;++i)std::cerr<<"counter "<<i<<" native "<<int(state.first[i])<<','<<int(state.second[i])<<" source "<<int(get<std::int8_t>(memory,work+0x198+i))<<','<<int(get<std::int8_t>(memory,work+0x1a3+i))<<'\n';}
            check(std::memcmp(state.first.data(),memory+work+0x198,11)==0&&std::memcmp(state.second.data(),memory+work+0x1a3,11)==0);
            check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);
            std::vector<std::uint32_t> particles;for(auto at=get<std::uint32_t>(memory,0x3b5848);at;at=get<std::uint32_t>(memory,at+0x20))if(at!=work)particles.push_back(at);
            check(particles.size()==result.created&&particles.size()==visuals.size());
            for(const auto at:particles){call(memory,0x653e80,{at});}
            check(visuals.update({10,20,30}).status==e::VisualStatus::completed);
            const auto frame=visuals.retain();check(frame&&frame->visuals.size()==particles.size());
            for(std::size_t i=0;i<particles.size();++i){const auto at=particles[i];const auto& output=frame->visuals[i];check(output.pieces.size()==memory[at+0x31]&&output.visible==(memory[at+1]!=0));
                for(std::size_t j=0;j<output.pieces.size();++j){const auto& p=output.pieces[j];const auto child=get<std::uint32_t>(memory,at+0x134+4*std::uint32_t(j));check(p.visible==(memory[at+0xf4+j]!=0));if(!p.visible)continue;
                    check(p.flags==get<std::uint32_t>(memory,child+4));check(std::memcmp(&p.parameters.translation,memory+child+0x24,12)==0&&std::memcmp(p.parameters.rotation.data(),memory+child+0x30,6)==0&&std::memcmp(&p.parameters.scale,memory+child+0x38,12)==0);check(std::memcmp(&p.parameters208,memory+child+0xc,12)==0);
                    const auto* mesh=bank->geometry().material(p.root,p.material);check(mesh!=nullptr);for(std::size_t k=0;k<mesh->indices.size();++k)check(std::bit_cast<std::uint32_t>(p.material_values[k])==get<std::uint32_t>(memory,child+0x50+std::uint32_t(k*4)));
                }
                call(memory,0x652d60,{at});call(memory,0x651d00,{at});check(visuals.retire(output.id));
            }
            surface_emissions+=unsigned(particles.size());++surface_frames;
            if(result.retire)break;
        }
        visuals.close();
    }
    // Full source factory and real shared-pool capacity, including inactive
    // registered primaries. The room lease is never queried while poses are off.
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned count=0;count<=8;++count)for(unsigned filled:{0u,160u,167u,168u}){
        general_context="surface factory asset="+std::to_string(asset)+" count="+std::to_string(count)+" filled="+std::to_string(filled);
        std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);owned_surface_constants(memory);
        auto world=surface_world_owner(count);const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);e::PeriodicVisuals visuals(bank,world->session().random);
        SurfaceRooms rooms(std::make_shared<SurfaceRoom>(floor));e::Modulation modulation({1,{.25f,.5f,.75f},1});
        check(visuals.bind_surfaces(world,rooms,modulation,profile)&&visuals.bound_to(*world));
        check(!visuals.bind_surfaces(world,rooms,modulation,profile));
        for(unsigned i=0;i<filled;++i){put(memory,0x70000,m::Vector{});const auto created=call(memory,0x6525d0,{0,0x70000,0,36,0,0x1a193,0x6535c0});check(GPR_U32(&created,2)!=0);check(visuals.emit({36,{}}).status==s::EmissionStatus::completed);}
        put(memory,0x4baea0,count);call(memory,0x5dfa90);const auto result=visuals.create_surface_work();
        check(result.attempted==count&&result.created==std::min(count,168-filled));check(result.status==(count>168-filled?e::WorkStatus::pool_full:e::WorkStatus::completed));
        unsigned source_count{};for(auto at=get<std::uint32_t>(memory,0x3b5848);at;at=get<std::uint32_t>(memory,at+0x20))if(memory[at+3]==0x17){const auto slot=memory[at+4];check(slot<count&&bool(result.identities[slot]));check(get<std::uint32_t>(memory,at+0x24)==actor_at+slot*0x10e0);check(visuals.surface_state(result.identities[slot]).has_value());++source_count;}
        check(source_count==result.created&&visuals.size()==filled+result.created);check(visuals.update({}).status==e::VisualStatus::completed&&rooms.reads==0);++surface_factory_cases;
        world->session().primary_population.reset();check(!visuals.bound_to(*world)&&visuals.create_surface_work().status==e::WorkStatus::unavailable);
        world->session().primary_population=9;check(!visuals.bound_to(*world));
        world->session().primary_population=count;
        visuals.close();world->close();check(!visuals.bound_to(*world));
    }
    // Actual World actor/model -> room lease -> shared watcher -> real scaled
    // children, in one source-order pass. Newly inserted head work waits until
    // the next pass; the retained frame includes its initially hidden state.
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        general_context="surface coupled asset="+std::to_string(asset);
        std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);owned_surface_constants(memory);owned_math_constants(memory);put(memory,0x294e00,m::identity());
        std::memcpy(memory+0xc00000,raw.data(),raw.size());call(memory,0x616310,{0xc00000});
        auto world=surface_world_owner(1);auto actor=world->primary(0);actor->position={500,0,500};actor->collision.pose_ready=true;
        actor->model=std::make_shared<reo::native::animation::Instance>(reo::native::animation::Skeleton::import_raw(skeletons[0]));
        for(std::size_t i=0;i<actor->model->nodes().size();++i)actor->model->local_translation(i,{});
        put(memory,actor_at+0x34,actor_model);for(unsigned i=0;i<actor->model->nodes().size();++i)put(memory,actor_model+0x820+4*i,actor_nodes+400*i);
        auto& random=world->session().random;put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);put(memory,0x2b8de8,random.state().observed);
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);e::PeriodicVisuals visuals(bank,random);
        SurfaceRooms rooms(std::make_shared<SurfaceRoom>(floor));e::Modulation modulation({1,{.2f,.4f,.6f},.75f});
        check(visuals.bind_surfaces(world,rooms,modulation,profile));
        put(memory,0x4baea0,1u);call(memory,0x5dfa90);const auto watcher=get<std::uint32_t>(memory,0x3b5848);const auto made=visuals.create_surface_work();check(made.created==1);const auto watcher_id=made.identities[0];
        for(unsigned tick=0;tick<64;++tick){
            general_context="surface coupled asset="+std::to_string(asset)+" tick="+std::to_string(tick);
            auto basis=m::identity();basis[3]={500.f+float(tick%11)*9.f,20.f+float(int((tick*7)%80)-40),500.f,1};actor->model->rebuild(basis);
            for(unsigned i=0;i<actor->model->nodes().size();++i)put(memory,actor_nodes+400*i+0x30,actor->model->world_translation(i));
            put(memory,actor_at+0x38,actor->position);put(memory,actor_at+0x1e2,actor->room);memory[actor_at+0x198]=actor->collision.pose_ready;put(memory,0x3243dc,world->room);
            put(memory,0x4b9d1a,modulation.state().flags);put(memory,0x4bac84,modulation.state().color);put(memory,0x4bac90,modulation.state().intensity);
            for(auto at=get<std::uint32_t>(memory,0x3b5848);at;){const auto next_at=get<std::uint32_t>(memory,at+0x20);call(memory,get<std::uint32_t>(memory,at+0x14),{at});at=next_at;}
            check(visuals.update({}).status==e::VisualStatus::completed);
            const auto state=visuals.surface_state(watcher_id);check(state.has_value());check(state->phase==memory[watcher+8]&&std::memcmp(state->previous.data(),memory+watcher+0x114,132)==0&&std::memcmp(state->first.data(),memory+watcher+0x198,11)==0&&std::memcmp(state->second.data(),memory+watcher+0x1a3,11)==0);
            check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);
            const auto frame=visuals.retain();check(frame&&frame->visuals.size()==visuals.size());std::size_t ordinal{},piece_count{};
            for(auto at=get<std::uint32_t>(memory,0x3b5848);at;at=get<std::uint32_t>(memory,at+0x20),++ordinal){check(ordinal<frame->visuals.size());const auto& output=frame->visuals[ordinal];check(output.visible==(memory[at+1]!=0));if(at==watcher){check(output.id==watcher_id&&output.pieces.empty());continue;}
                check(output.pieces.size()==memory[at+0x31]);piece_count+=output.pieces.size();if(!output.visible)continue;
                for(std::size_t j=0;j<output.pieces.size();++j){const auto& p=output.pieces[j];const auto child=get<std::uint32_t>(memory,at+0x134+4*std::uint32_t(j));check(p.visible==(memory[at+0xf4+j]!=0));if(!p.visible)continue;
                    check(p.flags==get<std::uint32_t>(memory,child+4));check(std::memcmp(&p.parameters.translation,memory+child+0x24,12)==0&&std::memcmp(p.parameters.rotation.data(),memory+child+0x30,6)==0&&std::memcmp(&p.parameters.scale,memory+child+0x38,12)==0&&std::memcmp(&p.parameters208,memory+child+0xc,12)==0);
                    const auto* mesh=bank->geometry().material(p.root,p.material);check(mesh!=nullptr);for(std::size_t k=0;k<mesh->indices.size();++k)check(std::bit_cast<std::uint32_t>(p.material_values[k])==get<std::uint32_t>(memory,child+0x50+std::uint32_t(k*4)));
                }
            }
            check(ordinal==frame->visuals.size()&&piece_count==visuals.piece_count());check(visuals.size()==std::size_t(168-get<std::uint16_t>(memory,0x3b5828))&&visuals.piece_count()==std::size_t(256-get<std::uint16_t>(memory,0x3b5820)));++surface_owner_frames;
        }
        check(rooms.reads==64);const auto old=world->identity(0);check(world->retire_primary(0)==reo::native::gameplay_actors::EntityStatus::completed);
        auto replacement=std::make_unique<surface_world::Actor>();replacement->room=7;check(world->spawn_primary(0,std::move(replacement)).id!=old);
        check(visuals.update({}).status==e::VisualStatus::completed&&!visuals.surface_state(watcher_id)&&rooms.reads==64);
        visuals.close();
    }
}
