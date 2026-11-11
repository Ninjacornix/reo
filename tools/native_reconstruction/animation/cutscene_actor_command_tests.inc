#include "game/native/gameplay_scenario/cutscene_actor_commands.hpp"
#include <cstdio>
namespace cue=reo::native::gameplay_scenario;
namespace cue_fixture {
struct CueVariantScale{std::uint16_t id;std::uint32_t bits;};
#include "game/native/gameplay_scenario/cutscene_command_scales.inc"
}
std::uint64_t cutscene_command_cases{},cutscene_degree_cases{},cutscene_command_refusals{},cutscene_speech_cases{},cutscene_command_mutations{};
bool cue_observing{},cue_mutate_after_voice{};
std::vector<std::string> original_cue_speech;
void cutscene_command_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    check(cue_observing,"declared original cutscene voice/facial observation only");
    if(context->pc==0x10a830){
        check(GPR_U32(context,5)==0x73ed70,"exact owned voice formatting literal");
        const auto count=std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),128,reinterpret_cast<const char*>(memory+0x73ed70),
            std::int32_t(GPR_U32(context,6)),std::int32_t(GPR_U32(context,7)),std::int32_t(GPR_U32(context,8)),std::int32_t(GPR_U32(context,9)));
        check(count>0&&count<128,"bounded cutscene voice fixture output");SET_GPR_S32(context,2,count);
    }else if(context->pc==0x1adb30){
        check(GPR_U32(context,4)==2,"actual original scene voice channel");
        original_cue_speech.push_back(std::string(reinterpret_cast<const char*>(memory+GPR_U32(context,5))));
        if(cue_mutate_after_voice){memory[0x38ecd0]=7;put(memory,0xc00000+6,std::uint16_t(0xfedc));put(memory,0xc00000+8,std::uint16_t(0xbeef));}
    }else if(context->pc==0x67c590){
        check(GPR_U32(context,4)==actor,"actual original facial actor identity");
        original_cue_speech.push_back(std::to_string(GPR_U32(context,5))+":"+std::to_string(GPR_U32(context,6))+":"+std::to_string(GPR_U32(context,7)));
    }else throw std::runtime_error("Undeclared cutscene command observation port");
    context->pc=GPR_U32(context,31);
}
void cutscene_command_tests(std::vector<std::uint8_t>& ram){
    check(cue_fixture::cue_player_scales.size()==8,"owned command player scale profile");
    struct Speech final:cue::CutsceneSpeech {
        const std::uint8_t* memory{};std::vector<std::string> calls;bool fail{};
        std::array<std::byte,36>* mutable_event{};std::uint8_t* mutable_scene{};
        bool queue_voice(const cue::CutsceneSpeechRequest& request)override{
            std::array<char,128> path{};
            std::snprintf(path.data(),path.size(),reinterpret_cast<const char*>(memory+0x73ed70),int(request.scenario),int(request.scene),int(request.voice),int(request.character));
            calls.emplace_back(path.data());
            if(mutable_event&&mutable_scene){*mutable_scene=7;const std::uint16_t voice=0xfedc,face=0xbeef;
                std::memcpy(mutable_event->data()+6,&voice,2);std::memcpy(mutable_event->data()+8,&face,2);}
            return !fail;
        }
        bool animate_face(const cue::CutsceneSpeechRequest& request)override{
            calls.push_back(std::to_string(request.facial)+":"+std::to_string(request.scene)+":"+std::to_string(std::uint16_t(request.voice)));return !fail;
        }
    }speech;speech.memory=ram.data();
    g::World world(world_profile(),std::make_shared<g::Session>());world.paused=1;
    const auto id=world.linked_models().allocate(true).id,target=world.linked_models().allocate(true).id;
    const auto value=world.resolve(id);
    const std::array related{target,g::actors::EntityId{},id};
    constexpr std::uint32_t record_at=0xc00000;
    std::array<std::byte,36> event{};
    const auto event_write=[&](unsigned at,auto v){std::memcpy(event.data()+at,&v,sizeof(v));};
    const auto project=[&]{
        std::memset(ram.data()+actor,0,0xd90);const auto& s=*value->scripted;
        put(ram.data(),actor,std::uint8_t(value->active));put(ram.data(),actor+1,std::uint8_t(value->visible));
        put(ram.data(),actor+2,value->category);put(ram.data(),actor+3,value->slot);put(ram.data(),actor+8,value->primary);
        put(ram.data(),actor+0x38,value->position);std::memcpy(ram.data()+actor+0x90,value->orientation.data(),8);
        put(ram.data(),actor+0xb4,value->model_scale);put(ram.data(),actor+0x54d,value->model_pose_class);
        put(ram.data(),actor+0x553,value->movement_enabled);put(ram.data(),actor+0xbb4,value->model_variant);
        put(ram.data(),actor+0xb98,value->character);put(ram.data(),actor+0xb99,value->motion_style);
        put(ram.data(),actor+0xb38,s.cue_phase);put(ram.data(),actor+0xb3c,s.request_flags);
        put(ram.data(),actor+0xb40,s.motion_rate_mode);put(ram.data(),actor+0xb41,s.scale_lock);put(ram.data(),actor+0xb42,s.request_phase);put(ram.data(),actor+0xb43,s.motion_selector);put(ram.data(),actor+0xb44,s.motion_blend_duration);
        put(ram.data(),actor+0xb8b,s.scale_profile);put(ram.data(),actor+0xb48,s.relation_mode);put(ram.data(),actor+0xb4c,0u);
        put(ram.data(),actor+0xb50,s.relation_options);put(ram.data(),actor+0xb54,s.relation_offset);put(ram.data(),actor+0xb60,s.relation_parameter);
        put(ram.data(),actor+0xb64,s.command_angles);put(ram.data(),actor+0xc50,s.command_angle_copy);
        put(ram.data(),actor+0xb6c,s.movement_angles);put(ram.data(),actor+0xb70,s.forward_step);put(ram.data(),actor+0xb74,s.yaw_step);put(ram.data(),actor+0xb78,s.movement_remaining);
        put(ram.data(),0x4badf8,world.paused);put(ram.data(),0x3243da,*world.scenario);put(ram.data(),0x38ecd0,std::uint8_t(219));
        put(ram.data(),0x38eddc,0xa00000u);put(ram.data(),0x38eddc+0x8c,0u);put(ram.data(),0x38eddc+2*0x8c,actor);
        std::memcpy(ram.data()+record_at,event.data(),event.size());
    };
    const auto compare=[&]{
        const auto& s=*value->scripted;
        check(ram[actor]==value->active&&ram[actor+1]==value->visible&&ram[actor+8]==value->primary&&get<std::int8_t>(ram.data(),actor+0xb38)==s.cue_phase&&get<std::uint32_t>(ram.data(),actor+0xb3c)==s.request_flags,"actual cutscene command common prefix and kind gates");
        check(std::memcmp(&value->position,ram.data()+actor+0x38,12)==0&&std::memcmp(value->orientation.data(),ram.data()+actor+0x90,8)==0,"actual cutscene command position/degrees");
        check(std::memcmp(&value->model_scale,ram.data()+actor+0xb4,12)==0&&s.scale_profile==ram[actor+0xb8b],"actual command scale table, distinct NPC base and unit gate");
        check(s.motion_rate_mode==get<std::int8_t>(ram.data(),actor+0xb40)&&s.scale_lock==get<std::int8_t>(ram.data(),actor+0xb41)&&s.request_phase==ram[actor+0xb42]&&s.motion_selector==get<std::int8_t>(ram.data(),actor+0xb43)&&bits(s.motion_blend_duration)==get<std::uint32_t>(ram.data(),actor+0xb44),"motion mode, byte normalization, branch-preserved controls and signed blend conversion");
        check(s.relation_mode==get<std::int32_t>(ram.data(),actor+0xb48)&&s.relation_options==get<std::uint32_t>(ram.data(),actor+0xb50)&&std::memcmp(s.relation_offset.data(),ram.data()+actor+0xb54,12)==0&&s.relation_parameter==get<std::uint32_t>(ram.data(),actor+0xb60),"relationship native state");
        const auto expected=s.related_actor==target?0xa00000u:s.related_actor==id?actor:0u;
        check(expected==get<std::uint32_t>(ram.data(),actor+0xb4c),"relationship carries canonical identities, including known null");
        check(value->movement_enabled==ram[actor+0x553]&&std::memcmp(s.command_angles.data(),ram.data()+actor+0xb64,6)==0&&s.command_angle_copy==get<std::int16_t>(ram.data(),actor+0xc50),"command angles and movement control");
        check(std::memcmp(s.movement_angles.data(),ram.data()+actor+0xb6c,4)==0&&bits(s.forward_step)==get<std::uint32_t>(ram.data(),actor+0xb70)&&s.yaw_step==get<std::uint32_t>(ram.data(),actor+0xb74)&&s.movement_remaining==get<std::uint32_t>(ram.data(),actor+0xb78),"actual counted movement producer");
    };
    const auto run=[&](unsigned kind,unsigned seed){
        location="cutscene command="+std::to_string(kind)+" seed="+std::to_string(seed);
        value->active=false;value->visible=false;value->primary=3;value->scripted.emplace();
        auto& s=*value->scripted;s.cue_phase=7;s.request_flags=0x89abcdef;s.motion_rate_mode=17;s.scale_lock=23;s.request_phase=45;s.motion_selector=-55;s.motion_blend_duration=6.5f;s.scale_profile=17;
        value->position={-1,-2,-3};value->orientation={-10,-20,-30,-40};value->model_scale={2,3,4};value->movement_enabled=99;
        value->category=std::uint8_t(seed%4);value->slot=1;value->model_pose_class=std::uint8_t((seed>>5)%2);
        value->model_variant=cue_fixture::cue_variant_scales[(seed/4)%cue_fixture::cue_variant_scales.size()].id;
        value->character=value->category==0?std::uint8_t((seed/4)%8):std::uint8_t(seed);value->motion_style=std::uint8_t((seed/3)%3);
        world.scenario=std::uint16_t(seed*101);
        event.fill(std::byte{});event[1]=std::byte(kind);
        if(kind==0){event_write(4,float(seed)*.25f);event_write(8,-float(seed)*.5f);event_write(12,float(seed)*.75f);
            for(unsigned i=0;i<3;++i)event_write(16+2*i,std::bit_cast<std::int16_t>(std::uint16_t(seed+17389*i)));
        }else if(kind==1){event_write(4,seed&8?0u:0xabcdef01u);event_write(8,seed*173u);event_write(12,seed*23u);event_write(16,seed*31u);event_write(20,seed&4?1u:0u);event_write(24,std::int32_t(seed*137)-100000);event_write(28,seed&16?255u:0u);
        }else if(kind==2){event_write(4,std::bit_cast<std::int16_t>(std::uint16_t(seed*500)));event_write(6,std::int16_t(seed%3));event_write(8,seed*173u);
            for(unsigned i=0;i<3;++i)event_write(12+4*i,float(seed)*.25f+float(i));
            event_write(24,seed*999u);
        }else if(kind==3){event_write(6,std::bit_cast<std::int16_t>(std::uint16_t(seed*700)));event_write(8,std::uint16_t(seed*177));
        }else if(kind==4)event_write(20,seed*173u);
        else if(kind==5)for(unsigned i=0;i<3;++i)event_write(4+2*i,std::bit_cast<std::int16_t>(std::uint16_t(seed*700+17389*i)));
        else if(kind==6){event_write(4,float(seed)*.25f);event_write(8,-float(seed)*100.25f-.75f);event_write(12,float(seed)*150.25f+.75f);event_write(20,seed*0x1020304u);event_write(24,seed*0x10001u);}
        project();speech.calls.clear();original_cue_speech.clear();cue_observing=true;
        const auto result=cue::apply_cutscene_actor_command(world,id,event,related,219,&speech);
        call(ram.data(),0x5eec50,actor,record_at);cue_observing=false;
        check(result==cue::CutsceneCommandStatus::completed,"native complete command result");compare();
        check(speech.calls==original_cue_speech,"exact ordered voice/facial arguments through declared providers");
        if(kind==3)++cutscene_speech_cases;
        ++cutscene_command_cases;
    };
    for(unsigned raw=0;raw<65536;++raw){run(0,raw);++cutscene_degree_cases;}
    for(unsigned seed=0;seed<4096;++seed)run(1,seed);
    for(unsigned kind=2;kind<7;++kind)for(unsigned seed=0;seed<256;++seed)run(kind,seed);
    for(unsigned kind=7;kind<256;++kind)run(kind,kind*97);
    run(3,17);project();std::uint8_t scene=219;speech.mutable_event=&event;speech.mutable_scene=&scene;
    speech.calls.clear();original_cue_speech.clear();cue_observing=cue_mutate_after_voice=true;
    check(cue::apply_cutscene_actor_command(world,id,event,related,scene,&speech)==cue::CutsceneCommandStatus::completed,"native voice-to-face same-call mutation result");
    call(ram.data(),0x5eec50,actor,record_at);cue_observing=cue_mutate_after_voice=false;speech.mutable_event=nullptr;speech.mutable_scene=nullptr;
    check(scene==7&&speech.calls==original_cue_speech&&speech.calls[1]=="48879:7:65244","face reloads source scene and event values after voice provider");
    ++cutscene_command_mutations;++cutscene_command_cases;
    event.fill(std::byte{});event[1]=std::byte{3};
    check(cue::apply_cutscene_actor_command(world,id,event)==cue::CutsceneCommandStatus::unavailable&&value->active&&value->primary==6,"missing real voice/face provider refuses after common prefix");++cutscene_command_refusals;
    speech.fail=true;speech.calls.clear();
    check(cue::apply_cutscene_actor_command(world,id,event,related,219,&speech)==cue::CutsceneCommandStatus::unavailable&&speech.calls.size()==2,"failed voice still attempts required face operation in order");++cutscene_command_refusals;
    speech.fail=false;world.scenario.reset();speech.calls.clear();
    check(cue::apply_cutscene_actor_command(world,id,event,related,219,&speech)==cue::CutsceneCommandStatus::unavailable&&speech.calls.empty(),"unknown scenario never invents a voice identity");++cutscene_command_refusals;
    world.scenario=0;
    check(cue::apply_cutscene_actor_command(world,{}, {})==cue::CutsceneCommandStatus::completed,"known null actor does not read malformed record");call(ram.data(),0x5eec50,0,0);
    check(cue::apply_cutscene_actor_command(world,id,std::span(event).first(35))==cue::CutsceneCommandStatus::malformed,"bounded authored command extent");++cutscene_command_refusals;
    event[1]=std::byte{2};event_write(6,std::int16_t(-1));
    check(cue::apply_cutscene_actor_command(world,id,event,related)==cue::CutsceneCommandStatus::unavailable,"negative relation selector never reads neighboring scene state");++cutscene_command_refusals;
    event[1]=std::byte{6};event_write(12,std::numeric_limits<float>::infinity());bool refused{};
    try{(void)cue::apply_cutscene_actor_command(world,id,event);}catch(const std::domain_error&){refused=true;}
    check(refused,"unadmitted movement conversion refuses nonfinite input");++cutscene_command_refusals;
    check(world.close()==g::Status::completed&&cue::apply_cutscene_actor_command(world,id,event)==cue::CutsceneCommandStatus::closed,"closed command World refuses");++cutscene_command_refusals;
}
