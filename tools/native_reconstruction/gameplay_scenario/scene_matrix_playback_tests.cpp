#include "game/native/gameplay_scenario/scene_matrix_programs.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include "owned_constants.hpp"
#include <iostream>
#include <source_location>
#include <vector>
namespace vm = reo::native::gameplay_scenario;
std::size_t checks{}, calls{}, frames{}, emitted{}, refusals{}, boundary_cases{};
std::string context;
void check(bool value, const std::source_location at=std::source_location::current()) {
    ++checks;
    if(!value) throw std::runtime_error(context+" check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
struct Sound {
    std::array<std::uint32_t,3> position;
    std::uint8_t style;
    std::uint16_t event;
    friend bool operator==(const Sound&,const Sound&)=default;
};
std::vector<Sound> original_sounds;
int mutate_slot=-1;
void original_sound(std::uint8_t* ram,R5900Context* ctx,PS2Runtime*) {
    const auto at=GPR_U32(ctx,4);
    original_sounds.push_back({{fixture_read<std::uint32_t>(ram,at),fixture_read<std::uint32_t>(ram,at+4),fixture_read<std::uint32_t>(ram,at+8)},std::uint8_t(GPR_U32(ctx,5)),std::uint16_t(GPR_U32(ctx,6))});
    if(mutate_slot>=0){const auto base=0x49fa10+std::uint32_t(mutate_slot)*64+48;fixture_write(ram,base,fixture_read<float>(ram,base)+17.f);}
}
PS2Runtime::Function PS2Runtime::lookupFunction(std::uint32_t at) const {
    if(at==0x6b60e0) return original_sound;
    switch(at) {
#include "original_lookup.inc"
    default:throw std::runtime_error("Unexpected original playback call "+std::to_string(at));
    }
}
void original_transform_port(std::uint8_t*,R5900Context*,PS2Runtime*) {throw std::runtime_error("Unexpected fallback");}
struct Sounds final:vm::SceneMatrixSoundSink {
    bool ready{true},accept{true};std::vector<Sound> requests;
    vm::SceneModels* models{};std::uint32_t slot{};
    bool admitted()const noexcept override{return ready;}
    bool emit(reo::native::transform_math::Vector p,std::uint8_t style,std::uint16_t event)override {
        requests.push_back({{std::bit_cast<std::uint32_t>(p.x),std::bit_cast<std::uint32_t>(p.y),std::bit_cast<std::uint32_t>(p.z)},style,event});
        if(models){auto base=*models->pose(slot);base[3][0]=base[3][0]+17.f;check(models->pose(slot,base)==vm::ModelStatus::completed);}
        return accept;
    }
};
constexpr std::uint32_t channel_base=0x4a3620;
void project(std::uint8_t* m,std::uint32_t at,const vm::SceneMatrixChannel& c) {
    m[at+1]=c.contact.gate;m[at+2]=c.interaction;m[at+3]=c.progress;m[at+4]=c.playback;m[at+6]=c.model_slot;m[at+7]=c.program;m[at+8]=c.cursor;m[at+9]=c.curve;m[at+10]=c.transform;m[at+11]=c.contact.active;
    fixture_write(m,at+12,c.time);fixture_write(m,at+14,c.segment);fixture_write(m,at+16,c.sound_cursor);m[at+20]=c.source_type;std::memcpy(m+at+32,c.matrix.data(),64);
}
void compare(const std::vector<std::uint8_t>& ram,const vm::SceneMatrixPrograms& native) {
    for(unsigned i=0;i<16;++i) {
        std::array<std::uint8_t,96> copy;const auto at=channel_base+i*96;
        std::memcpy(copy.data(),ram.data()+at,96);project(copy.data(),0,*native.inspect(i));
        check(std::memcmp(copy.data(),ram.data()+at,96)==0);
    }
}
vm::SceneModelState model_state(unsigned seed) {
    vm::SceneModelState state;
    for(unsigned i=0;i<128;++i) {
        state.styles[i]=0x98765400u|(seed+i)%256;
        state.sound_resources[i]=std::uint8_t(seed*17+i*13);
        auto& m=state.poses[i];
        for(unsigned c=0;c<4;++c)for(unsigned r=0;r<3;++r)m[c][r]=float(int((seed+i*13+c*17+r*19)%129)-64)/16;
        for(unsigned c=0;c<4;++c)m[c][3]=std::bit_cast<float>(0x7fc00123u+i+c);
    }
    return state;
}
int main() try {
    std::vector<std::uint8_t> ram(0x2000000);owned_matrix_constants(ram.data());
    const auto& tables=vm::stock_scene_matrix_tables();
    for(unsigned curve=0;curve<236;++curve)for(unsigned mode:{0u,1u,2u,3u,255u})for(bool twice:{false,true}) {
        const auto seed=curve*11+mode;const unsigned index=seed%16,slot=seed%128;
        context="curve="+std::to_string(curve)+" mode="+std::to_string(mode)+" twice="+std::to_string(twice);
        auto state=model_state(seed);vm::SceneModels models(state,{});reo::native::gameplay_actors::EntityStore entities({64});vm::SceneModelBindings bindings(models,entities);vm::SceneControls controls;vm::FlagState flags;std::uint16_t room{};
        vm::SceneMatrixPrograms::State channels{};auto& channel=channels[index];channel.playback=1;channel.progress=1;channel.curve=std::uint8_t(curve);channel.transform=std::uint8_t(mode);channel.model_slot=std::uint8_t(slot);channel.time=-300;channel.segment=-19;channel.sound_cursor=55;
        channel.matrix=reo::native::transform_math::identity();channel.matrix[3][0]=-88;
        vm::SceneMatrixPrograms native(controls,models,bindings,flags,room,channels);Sounds sound;
        mutate_slot=-1;if(curve==0&&mode==2&&twice){mutate_slot=int(slot);sound.models=&models;sound.slot=slot;}
        check(native.source_type(16,255)==vm::SceneMatrixStatus::invalid_channel);
        for(unsigned i=0;i<16;++i){std::fill(ram.begin()+channel_base+i*96,ram.begin()+channel_base+(i+1)*96,0xA5);project(ram.data(),channel_base+i*96,channels[i]);}
        for(unsigned i=0;i<128;++i)std::memcpy(ram.data()+0x49fa10+i*64,state.poses[i].data(),64);
        for(unsigned i=0;i<128;++i)ram[0x4a1d70+i]=*state.sound_resources[i];
        ram[0x3243cc]=twice?255:0;original_sounds.clear();
        const auto keys=tables.curves[tables.groups[curve/4].curves[curve%4]];
        const auto limit=unsigned(keys.back().time+4);
        for(unsigned frame=0;frame<limit;++frame) {
            R5900Context ctx;PS2Runtime runtime;ctx.pc=0x6b4ba0;SET_GPR_U32(&ctx,4,index);SET_GPR_U32(&ctx,29,0x1e00000);SET_GPR_U32(&ctx,31,0x150000);
            o2_006B4BA0_0x6b4ba0(ram.data(),&ctx,&runtime);++calls;
            const auto result=native.advance(index,twice,&sound);check(result.status==vm::SceneMatrixStatus::completed);++frames;emitted+=result.sounds;compare(ram,native);check(sound.requests==original_sounds);
            if(native.inspect(index)->playback==0) break;
            check(frame+1<limit);
        }
        check(native.inspect(index)->progress==2);
    }
    for(unsigned bits=0;bits<65536;++bits) {
        context="signed-time="+std::to_string(bits);
        const auto state=model_state(bits%129);vm::SceneModels models(state,{});reo::native::gameplay_actors::EntityStore entities({64});vm::SceneModelBindings bindings(models,entities);vm::SceneControls controls;vm::FlagState flags;std::uint16_t room{};
        vm::SceneMatrixPrograms::State channels{};auto& c=channels[7];c.playback=2;c.curve=32;c.model_slot=11;c.transform=2;c.time=std::bit_cast<std::int16_t>(std::uint16_t(bits));c.sound_cursor=-1;
        vm::SceneMatrixPrograms native(controls,models,bindings,flags,room,channels);
        for(unsigned i=0;i<16;++i){std::fill(ram.begin()+channel_base+i*96,ram.begin()+channel_base+(i+1)*96,0xA5);project(ram.data(),channel_base+i*96,channels[i]);}
        for(unsigned i=0;i<128;++i)std::memcpy(ram.data()+0x49fa10+i*64,state.poses[i].data(),64);
        ram[0x3243cc]=0;R5900Context ctx;PS2Runtime runtime;ctx.pc=0x6b4ba0;SET_GPR_U32(&ctx,4,7);SET_GPR_U32(&ctx,29,0x1e00000);SET_GPR_U32(&ctx,31,0x150000);o2_006B4BA0_0x6b4ba0(ram.data(),&ctx,&runtime);++calls;
        const auto result=native.advance(7,false,nullptr);check(result.status==vm::SceneMatrixStatus::completed);compare(ram,native);++boundary_cases;
    }
    for(unsigned variant=0;variant<9;++variant) {
        context="negative="+std::to_string(variant);
        auto state=model_state(9);if(variant==8)state.sound_resources[0].reset();vm::SceneModels models(state,{});reo::native::gameplay_actors::EntityStore entities({64});vm::SceneModelBindings bindings(models,entities);vm::SceneControls controls;vm::FlagState flags;std::uint16_t room{};
        vm::SceneMatrixPrograms::State channels{};auto& c=channels[0];c.playback=1;c.curve=0;c.model_slot=0;c.time=77;c.segment=31;
        if(variant==3)c.playback=2,c.segment=-1;
        if(variant==4)c.playback=2,c.segment=0,c.sound_cursor=300;
        if(variant==5)c.curve=255;
        if(variant==6)c.model_slot=255;
        vm::SceneMatrixPrograms native(controls,models,bindings,flags,room,channels);Sounds sound;const auto before=*native.inspect(0);if(variant==1)sound.ready=false;if(variant==2)sound.accept=false;
        if(variant==7)native.close();
        auto result=native.advance(0,false,variant==0?nullptr:&sound);
        if(variant==2)for(unsigned i=0;result.status==vm::SceneMatrixStatus::completed&&i<1024;++i)result=native.advance(0,false,&sound);
        check(result.status!=vm::SceneMatrixStatus::completed);++refusals;
        if(variant<2) {const auto after=*native.inspect(0);check(before.time==after.time&&before.playback==after.playback&&before.segment==after.segment);}
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_playback_calls\":"<<calls<<",\"native_frames\":"<<frames<<",\"signed_time_cases\":"<<boundary_cases<<",\"sound_requests\":"<<emitted<<",\"profile_refusals\":"<<refusals<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
