#include "game/native/gameplay_scenario/cutscene_object_tracks.hpp"
std::uint64_t object_track_cases{},object_track_ticks{},object_track_commands{},object_track_refusals{};
void cutscene_object_track_tests(const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    constexpr unsigned base=0x600000,events=0xc00000,controller=0x80000,parent_at=0x900000,parent_work=0x910000,parent_nodes=0x920000;
    for(unsigned seed=0;seed<256;++seed){
        location="object streams="+std::to_string(seed);g::World world(world_profile(),std::make_shared<g::Session>());world.paused=1;auto& pool=world.cinematic_objects();check(pool.initialize()==g::CinematicObjectStatus::completed,"object streams actual fixed pool");
        put(ram.data(),0x4badf8,world.paused);call(ram.data(),0x571010,base);const auto skeleton=a::Skeleton::import_raw(skeletons[seed%4]);
        const auto actor_id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto actor_value=world.resolve(actor_id);actor_value->category=2;actor_value->model=std::make_shared<a::Instance>(skeleton);actor_value->model_scale={1.25f,.75f,2.5f};
        auto root=t::identity();root[3]={20,-30,40,1};actor_value->model->rebuild(root);ram[parent_at]=0;ram[parent_at+1]=0;ram[parent_at+2]=2;put(ram.data(),parent_at+0x34,parent_work);put(ram.data(),parent_at+0xb4,actor_value->model_scale);
        for(unsigned node=0;node<skeleton->nodes().size();++node){put(ram.data(),parent_work+0x820+4*node,parent_nodes+400*node);put(ram.data(),parent_nodes+400*node,actor_value->model->nodes()[node].world);}
        put(ram.data(),0x38eca0+0x13c,parent_at);world.session().clock_mode=std::uint8_t(seed);ram[0x3243cc]=world.session().clock_mode;put(ram.data(),0x7434c8,controller);
        const auto count=seed%17;std::vector<cue::CutsceneObjectTrackGroup> groups(count);const auto frame_base=std::uint16_t(seed%5==0?65534:seed%5==1?32768:seed*73);
        put(ram.data(),0x38ecb8,std::int16_t(count));std::fill_n(ram.data()+0x38f7b0,16*28,0);
        for(unsigned slot=0;slot<16;++slot){const auto value=pool.resolve(pool.identity_at(slot));const auto at=base+slot*0x11a0;const auto node_base=0xa00000+slot*0x10000;
            value->model=std::make_shared<a::Instance>(skeleton);auto basis=t::identity();basis[3]={float(10+slot),float(20-slot),30,1};value->model->rebuild(basis);
            value->position={1,2,3};value->angles={123,456,789};value->basis=t::identity();value->flags=0x89abc000;value->motion=0x10203040;
            put(ram.data(),at+0x20,value->position);put(ram.data(),at+0x18,value->angles);put(ram.data(),at+0x30,value->basis);put(ram.data(),at+0x118c,value->flags);put(ram.data(),at+0x117c,value->motion);
            put(ram.data(),at+0x70,at+0x890);for(unsigned node=0;node<skeleton->nodes().size();++node){put(ram.data(),at+0x890+4*node,node_base+400*node);put(ram.data(),node_base+400*node,value->model->nodes()[node].world);}
            const a::Vector scale{1.25f,.75f,2.5f};put(ram.data(),at+0xb4,scale);
            if(slot>=count)continue;
            auto& binding=groups[slot];binding.object=pool.identity_at(slot);binding.attachment_scale=scale;
            for(unsigned stream=0;stream<7;++stream){if((seed+slot+stream)%5==0)continue;
                std::array<std::byte,108> bytes{};const auto write=[&](unsigned at,auto v){std::memcpy(bytes.data()+at,&v,sizeof v);};const auto kind=std::array<unsigned,6>{0,1,2,3,128,255}[(seed+stream)%6];
                for(unsigned event=0;event<2;++event){const auto off=event*36;bytes[off+1]=std::byte(kind);write(off+2,std::uint16_t(frame_base+(slot+stream+event)%3));
                    if(kind==0){write(off+4,a::Vector{float(10+event+slot),-20.f+float(stream),30.f+float(seed)});write(off+16,std::array<std::int16_t,3>{std::int16_t(seed*113),std::int16_t(-int(slot)*500),std::int16_t(stream*17)});write(off+24,a::Vector{3,4,5});}
                    if(kind==1)write(off+4,0x89abc000u+std::uint32_t(seed+event));
                    if(kind==2)write(off+4,0xffffffffu-std::uint32_t(seed*71+event));
                    if(kind==3){write(off+4,std::uint32_t((seed+slot+event)%7?1+(seed+stream+event)%skeleton->nodes().size():0));write(off+8,std::uint32_t(seed&1));write(off+12,a::Vector{.25f,-.5f,1.25f});write(off+24,t::Angles{std::uint16_t(seed*113),std::uint16_t(slot*73),std::uint16_t(stream*57)});write(off+32,0u);}
                }
                write(74,std::uint16_t(65535));const bool terminal_only=frame_base<65000&&(seed+slot+stream)%4==0;
                if(terminal_only){write(2,std::uint16_t(65535));binding.streams[stream]=cue::CutsceneActorStream::import(std::span(bytes).first(36));}
                else binding.streams[stream]=cue::CutsceneActorStream::import(bytes);
                const auto at_stream=events+0x1000*slot+0x100*stream;std::memcpy(ram.data()+at_stream,bytes.data(),bytes.size());put(ram.data(),0x38f7b0+slot*28+stream*4,at_stream);
            }
        }
        cue::CutsceneObjectTracks tracks(world);bool duplicate{};try{cue::CutsceneObjectTracks invalid(world);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate,"one object stream owner per World");const std::array actor_bindings{actor_id};check(tracks.install(groups,actor_bindings)==cue::CutsceneTrackStatus::completed,"actual object stream bindings and required controlled parent metadata");
        for(const auto frame:{std::uint32_t(frame_base),std::uint32_t(frame_base),std::uint32_t(frame_base)+1,std::uint32_t(frame_base)+2,std::uint32_t(frame_base)+3,std::uint32_t(frame_base)+4,std::uint32_t(frame_base)+65536,std::uint32_t(frame_base)+1}){
            put(ram.data(),controller+8,std::uint16_t(frame));const auto result=tracks.tick(frame);call(ram.data(),0x5ef120,0);check(result.status==cue::CutsceneTrackStatus::completed&&!world.busy(),"complete object stream dispatch and released World guard");
            for(unsigned slot=0;slot<count;++slot){const auto value=pool.resolve(pool.identity_at(slot));const auto at=base+slot*0x11a0;
                check(bool(ram[at])==value->active&&bool(ram[at+1])==value->visible,"object activity and semantic visibility byte");
                check(std::memcmp(&value->position,ram.data()+at+0x20,12)==0&&std::memcmp(value->angles.data(),ram.data()+at+0x18,6)==0&&std::memcmp(&value->basis,ram.data()+at+0x30,64)==0,"object commands actual position angle and attachment matrix");
                check(value->flags==get<std::uint32_t>(ram.data(),at+0x118c)&&value->motion==get<std::uint32_t>(ram.data(),at+0x117c),"object command flags and full unsigned motion request");
                const auto pose_at=get<std::uint32_t>(ram.data(),at+0x1178);check(bool(pose_at)==bool(value->pose),"object pose retains the source command association");
                if(pose_at){const auto& pose=*value->pose;check(pose.start==get<std::uint16_t>(ram.data(),pose_at+2)&&pose.end==get<std::uint16_t>(ram.data(),pose_at+38)&&std::memcmp(&pose.first,ram.data()+pose_at+4,12)==0&&std::memcmp(pose.first_degrees.data(),ram.data()+pose_at+16,6)==0,"actual retained source pose key");if(pose.end!=65535)check(std::memcmp(&pose.control,ram.data()+pose_at+24,12)==0&&std::memcmp(&pose.last,ram.data()+pose_at+40,12)==0&&std::memcmp(pose.last_degrees.data(),ram.data()+pose_at+52,6)==0,"actual retained source next/control key");}
                for(unsigned stream=0;stream<7;++stream){const auto position=tracks.cursor(slot,stream);const auto pointer=get<std::uint32_t>(ram.data(),0x38f7b0+slot*28+stream*4);check(pointer==(position?events+0x1000*slot+0x100*stream+36*unsigned(*position):0u),"at most one event per stream and exact original terminal/cursor advancement");}
            }
            object_track_commands+=result.commands;++object_track_ticks;
        }
        check(tracks.close()==cue::CutsceneTrackStatus::completed&&world.close()==g::Status::completed&&tracks.tick(0).status==cue::CutsceneTrackStatus::closed,"object stream joined closure");++object_track_cases;
    }
    // Native refusal/ownership cases deliberately avoid invalid original dereferences.
    g::World world(world_profile(),std::make_shared<g::Session>());world.paused=1;auto& pool=world.cinematic_objects();check(pool.initialize()==g::CinematicObjectStatus::completed,"object stream failure pool");
    cue::CutsceneObjectTracks tracks(world);std::array<std::byte,72> bytes{};bytes[1]=std::byte{3};std::uint16_t terminal=65535;std::memcpy(bytes.data()+38,&terminal,2);std::uint32_t one=1;std::memcpy(bytes.data()+4,&one,4);std::memcpy(bytes.data()+8,&one,4);
    cue::CutsceneObjectTrackGroup group;group.object=pool.identity_at(0);group.streams[0]=cue::CutsceneActorStream::import(bytes);std::array groups{group};
    check(tracks.install(groups)==cue::CutsceneTrackStatus::completed,"metadata is required only by actual parent consumption");const auto failed=tracks.tick(0);check(failed.status==cue::CutsceneTrackStatus::unavailable&&tracks.failed()&&tracks.cursor(0,0)==0&&!world.busy()&&tracks.tick(0).status==cue::CutsceneTrackStatus::failed,"missing object parent metadata is a sticky visible failure without advancing cursor");++object_track_refusals;
    std::vector<cue::CutsceneObjectTrackGroup> too_many(17);check(tracks.install(too_many)==cue::CutsceneTrackStatus::invalid_input&&tracks.cursor(0,0)==0,"object stream capacity refusal preserves prior binding");++object_track_refusals;
    std::memset(bytes.data()+4,0,4);groups[0].streams[0]=cue::CutsceneActorStream::import(bytes);check(tracks.install(groups)==cue::CutsceneTrackStatus::completed&&tracks.tick(0).status==cue::CutsceneTrackStatus::completed&&!tracks.cursor(0,0),"zero node attachment command needs no parent model or scale");
    const auto parent_id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto parent=world.resolve(parent_id);parent->model=std::make_shared<a::Instance>(a::Skeleton::import_raw(skeletons[0]));const std::array actor_bindings{parent_id};
    std::uint32_t encoded=257,actor_kind=0;std::memcpy(bytes.data()+4,&encoded,4);std::memcpy(bytes.data()+8,&actor_kind,4);groups[0].streams[0]=cue::CutsceneActorStream::import(bytes);
    check(tracks.install(groups,actor_bindings)==cue::CutsceneTrackStatus::completed,"actual actor parent binding for full ordinal failure");bool threw{};try{(void)tracks.tick(0);}catch(const std::out_of_range&){threw=true;}
    check(threw&&tracks.failed()&&!world.busy()&&tracks.cursor(0,0)==0,"attachment exception preserves cursor and releases World/stream guards");++object_track_refusals;
    encoded=1;std::memcpy(bytes.data()+4,&encoded,4);groups[0].streams[0]=cue::CutsceneActorStream::import(bytes);check(tracks.install(groups,actor_bindings)==cue::CutsceneTrackStatus::completed&&world.retire_primary(0)==g::actors::EntityStatus::completed,"actual actor parent retirement before command");
    check(tracks.tick(0).status==cue::CutsceneTrackStatus::unavailable&&tracks.failed()&&!world.busy()&&tracks.cursor(0,0)==0&&parent->model,"stale parent identity refuses despite retained model");++object_track_refusals;
    encoded=0;std::memcpy(bytes.data()+4,&encoded,4);groups[0].streams[0]=cue::CutsceneActorStream::import(bytes);check(tracks.install(groups)==cue::CutsceneTrackStatus::completed&&pool.initialize()==g::CinematicObjectStatus::completed,"object generation reset requires stream handoff");
    check(tracks.tick(0).status==cue::CutsceneTrackStatus::unavailable&&!world.busy()&&tracks.cursor(0,0)==0,"stale object stream binding cannot operate on a new physical occupant");++object_track_refusals;
    groups[0].object=pool.identity_at(0);
    auto stream=cue::CutsceneActorStream::import(bytes);bool destroyed{},protected_close{};
    groups[0].streams[0]=std::shared_ptr<const cue::CutsceneActorStream>(stream.get(),[keep=stream,&destroyed,&protected_close,&world,&tracks](const cue::CutsceneActorStream*){(void)keep;destroyed=true;protected_close=world.close()==g::Status::busy&&tracks.close()==cue::CutsceneTrackStatus::busy;});
    check(tracks.install(groups)==cue::CutsceneTrackStatus::completed,"destructor guard installs retained stream");groups[0].streams[0].reset();check(tracks.close()==cue::CutsceneTrackStatus::completed&&destroyed&&protected_close&&!world.busy(),"stream destruction protects World and track owner closure");
    cue::CutsceneObjectTracks replacement(world);check(tracks.close()==cue::CutsceneTrackStatus::completed,"old closed object owner cannot unbind replacement");bool duplicate{};try{cue::CutsceneObjectTracks invalid(world);}catch(const std::invalid_argument&){duplicate=true;}check(duplicate&&replacement.close()==cue::CutsceneTrackStatus::completed&&world.close()==g::Status::completed,"replacement remains bound until actual closure");
}
