#include "game/native/gameplay_scenario/cutscene_actor_tracks.hpp"
std::uint64_t cutscene_track_cases{},cutscene_track_ticks{},cutscene_track_original_commands{},cutscene_terminal_streams{};
void cutscene_track_tests(std::vector<std::uint8_t>& ram){
    constexpr std::uint32_t streams_at=0xd00000,controller=0x80000;
    for(unsigned seed=0;seed<=256;++seed){
        location="cutscene tracks="+std::to_string(seed);
        g::World world(world_profile(),std::make_shared<g::Session>());
        const auto id=world.linked_models().allocate(true).id;const auto value=world.resolve(id);
        value->scripted.emplace();value->category=2;value->primary=3;value->movement_enabled=239;
        value->scripted->cue_phase=7;value->scripted->request_flags=0x89abcdef;
        world.session().clock_mode=std::uint8_t(seed);cue::CutsceneActorTracks tracks(world);
        const auto count=seed%17;
        const std::uint16_t base=seed%6==0?65535:seed%6==1?65534:seed%6==2?32768:std::uint16_t(seed*73);
        std::vector<cue::CutsceneActorTrackGroup> groups(count);
        std::memset(ram.data()+actor,0,0xd90);put(ram.data(),actor+2,value->category);put(ram.data(),actor+8,value->primary);
        put(ram.data(),actor+0x553,value->movement_enabled);put(ram.data(),actor+0xb38,value->scripted->cue_phase);put(ram.data(),actor+0xb3c,value->scripted->request_flags);
        put(ram.data(),0x38ecb6,std::int16_t(count));put(ram.data(),0x7434c8,controller);
        put(ram.data(),0x3243cc,world.session().clock_mode);std::memset(ram.data()+0x38fb60,0,16*32);
        for(unsigned group=0;group<count;++group){
            auto& binding=groups[group];binding.kind=std::array<std::int8_t,7>{2,0,1,-1,3,127,-128}[group%7];
            binding.actor=group==0&&seed%7==0?g::actors::EntityId{}:id;
            put(ram.data(),0x38eca0+0x8c*group+0x138,binding.kind);
            put(ram.data(),0x38eca0+0x8c*group+0x13c,binding.actor?actor:0u);
            // The eighth pointer-sized cell is not an eighth command stream.
            put(ram.data(),0x38fb60+32*group+28,0xdeadbeefu);
            for(unsigned stream=0;stream<7;++stream){
                if((seed+group+stream)%5==0)continue;
                std::array<std::byte,108> bytes{};
                const auto write=[&](unsigned at,auto v){std::memcpy(bytes.data()+at,&v,sizeof v);};
                bytes[1]=bytes[37]=std::byte{4};
                write(2,std::uint16_t(base+(group+stream)%3));write(38,std::uint16_t(base+(group+stream)%2));
                write(20,0xabc00000u+17*group+stream+seed);write(56,0xdef00000u+29*group+stream+seed);
                write(74,std::uint16_t(65535));
                const bool terminal_only=base<65000&&(seed+group+stream)%4==0;
                if(terminal_only){write(2,std::uint16_t(65535));binding.streams[stream]=cue::CutsceneActorStream::import(std::span(bytes).first(36));++cutscene_terminal_streams;}
                else binding.streams[stream]=cue::CutsceneActorStream::import(bytes);
                const auto address=streams_at+0x1000*group+0x100*stream;
                std::memcpy(ram.data()+address,bytes.data(),bytes.size());put(ram.data(),0x38fb60+32*group+4*stream,address);
            }
        }
        check(tracks.install(groups)==cue::CutsceneTrackStatus::completed,"actual native bounded scene actor bindings");
        const std::uint8_t scene=0;
        for(std::uint32_t frame:{std::uint32_t(base),std::uint32_t(base),std::uint32_t(base)+1,std::uint32_t(base)+2,std::uint32_t(base)+4,std::uint32_t(base),std::uint32_t(base)+65536,std::uint32_t(base)+1}){
            std::vector<std::uint32_t> previous;
            for(unsigned group=0;group<count;++group)for(unsigned stream=0;stream<7;++stream)previous.push_back(get<std::uint32_t>(ram.data(),0x38fb60+32*group+4*stream));
            const auto native=tracks.tick(frame,scene);put(ram.data(),controller+8,frame);
            const auto calls_before=helper_calls;call(ram.data(),0x5eeb00,0);
            const auto actual_commands=helper_calls-calls_before-1;
            check(native.status==cue::CutsceneTrackStatus::completed&&native.commands==actual_commands,"actual original stream dispatch count, including null actors");
            unsigned visited{},matched{},ended{};std::size_t index{};
            for(unsigned group=0;group<count;++group){
                check(get<std::uint32_t>(ram.data(),0x38fb60+32*group+28)==0xdeadbeef,"actual seven-stream extent preserves header cell");
                for(unsigned stream=0;stream<7;++stream){
                    const auto before=previous[index++],after=get<std::uint32_t>(ram.data(),0x38fb60+32*group+4*stream);
                    visited+=before!=0;matched+=before!=after;ended+=before!=0&&after==0;
                    const auto cursor=tracks.cursor(group,stream);
                    const auto expected=cursor?streams_at+0x1000*group+0x100*stream+36*std::uint32_t(*cursor):0u;
                    check(expected==after,"all original exact/halved frame positions, one record per stream and terminal advancement");
                }
            }
            check(native.visited==visited&&native.matched==matched&&native.ended==ended&&native.skipped==matched-actual_commands,"measured native scene traversal result");
            check(value->active==bool(ram[actor])&&value->primary==ram[actor+8]&&value->scripted->cue_phase==get<std::int8_t>(ram.data(),actor+0xb38)&&value->scripted->request_flags==get<std::uint32_t>(ram.data(),actor+0xb3c)&&value->movement_enabled==ram[actor+0x553],"actual native actor command effects after stream order");
            check(!world.busy()&&!tracks.busy()&&world.session().feedback_phase==0,"joined scene invocation never commits the game clock");
            cutscene_track_original_commands+=actual_commands;++cutscene_track_ticks;
        }
        ++cutscene_track_cases;
    }
}
