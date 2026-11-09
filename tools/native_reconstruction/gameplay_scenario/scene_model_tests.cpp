#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include "game/native/gameplay_scenario/scene_models.hpp"
#include "original_models.cpp"
#include <cfenv>
#include <fstream>
#include <iostream>
#include <limits>
#include <source_location>
#include <vector>
namespace vm=reo::native::gameplay_scenario;
namespace math=reo::native::transform_math;
namespace {
std::size_t checks{},calls{},ports{},room_cases{},flag_cases{},matrix_cases{};
void check(bool value,const std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Scene model check "+std::to_string(checks)+" "+at.file_name()+":"+std::to_string(at.line()));
}
std::uint32_t next(std::uint32_t& seed){seed=seed*1664525u+1013904223u;return seed;}
float scalar(std::uint32_t& seed){return float(std::int32_t(next(seed)%8193)-4096)/256.0f;}
vm::SceneModelState initial(std::uint32_t seed){
    vm::SceneModelState state;
    for(auto& byte:state.visibility)byte=std::uint8_t(next(seed));
    for(auto& word:state.styles)word=next(seed);
    for(auto& matrix:state.poses){for(auto& column:matrix){for(unsigned j=0;j<3;++j)column[j]=scalar(seed);column[3]=std::bit_cast<float>(next(seed));}}
    return state;
}
void export_state(std::vector<std::uint8_t>& ram,const vm::SceneModels& owner){
    const auto& s=owner.state();std::memcpy(ram.data()+0x49f790,s.visibility.data(),s.visibility.size());std::memcpy(ram.data()+0x49f810,s.styles.data(),s.styles.size()*4);std::memcpy(ram.data()+0x49fa10,s.poses.data(),s.poses.size()*64);
    transform_write<std::uint32_t>(ram.data(),0x324424,0x900000);transform_write<std::uint32_t>(ram.data(),0x908004,0x910000);std::memcpy(ram.data()+0x910000,owner.remap().data(),32);
}
void compare(const std::vector<std::uint8_t>& ram,const vm::SceneModels& owner){
    const auto& s=owner.state();check(std::memcmp(ram.data()+0x49f790,s.visibility.data(),s.visibility.size())==0);check(std::memcmp(ram.data()+0x49f810,s.styles.data(),s.styles.size()*4)==0);
    for(unsigned i=0;i<128;++i)check(std::memcmp(ram.data()+0x49fa10+i*64,s.poses[i].data(),64)==0);
}
std::uint32_t call(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::uint32_t a0=0x10000,std::uint32_t a1=0){
    R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,a0);SET_GPR_U32(&c,5,a1);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xdeadbeef);fn(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++calls;return GPR_U32(&c,2);
}
}
void original_transform_port(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime){
    ++ports;
    switch(c->pc){
    case 0x18f570:return sub_0018F570_0x18f570(ram,c,runtime);
    case 0x18fdf0:return sub_0018FDF0_0x18fdf0(ram,c,runtime);
    case 0x190a10:return sub_00190A10_0x190a10(ram,c,runtime);
    case 0x1913e0:return sub_001913E0_0x1913e0(ram,c,runtime);
    case 0x191530:return sub_00191530_0x191530(ram,c,runtime);
    case 0x1919d0:return sub_001919D0_0x1919d0(ram,c,runtime);
    case 0x581830:return o2_00581830_0x581830(ram,c,runtime);
    default:throw std::runtime_error("Unqualified scene model original dependency "+std::to_string(c->pc));
    }
}
int main()try{
    math::require_profile();std::vector<std::uint8_t> ram(0x2000000);owned_constants(ram.data());const auto identity=math::identity();std::memcpy(ram.data()+0x294e00,identity.data(),64);
    std::ifstream input("owned_room_sections.bin",std::ios::binary);check(bool(input));std::uint32_t count{};input.read(reinterpret_cast<char*>(&count),4);check(count==166);
    for(unsigned room=0;room<count;++room){std::uint32_t bytes{};input.read(reinterpret_cast<char*>(&bytes),4);auto section=std::make_shared<std::vector<std::byte>>(bytes);input.read(reinterpret_cast<char*>(section->data()),bytes);check(bool(input));
        const vm::content::ScriptBank bank(section,vm::content::BankFormat::room_section);const auto remap=vm::import_room_model_remap(bank);vm::SceneModels owner(initial(room+1),remap);export_state(ram,owner);
        for(unsigned id=0;id<256;++id)check(call(o2_00581830_0x581830,ram,0xabc00000u|id)==owner.resolve(0xabc00000u|id));
        ++room_cases;
    }
    static_assert(sizeof(vm::ModelTransformPreset)==24);
    const auto presets=vm::stock_model_transform_presets();check(presets.size()==8);check(std::memcmp(ram.data()+0x7174f0,presets.data(),presets.size()*24)==0);
    for(unsigned shift=0;shift<8;++shift){vm::RoomModelRemap remap;for(unsigned i=0;i<32;++i)remap[i]=std::uint8_t(shift*32+i);
        for(unsigned id=0;id<256;++id){vm::SceneModels owner(initial(shift*256+id+1),remap);export_state(ram,owner);transform_write(ram.data(),0x10000,0xabc00000u|id);
            check(call(o2_00690600_0x690600,ram)==0);owner.visibility(0xabc00000u|id,false);compare(ram,owner);
            check(call(o2_00690640_0x690640,ram)==0);owner.visibility(0xabc00000u|id,true);compare(ram,owner);++flag_cases;
            const auto saved=owner.state();
            if(id<32&&remap[id]<128){const auto word=0x815a2345u^id;call(o2_005D8350_0x5d8350,ram,id,word);check(owner.style(id,word)==vm::ModelStatus::completed);compare(ram,owner);}
            else{check(owner.style(id,123)==(id>=32?vm::ModelStatus::invalid_authored_id:vm::ModelStatus::invalid_pose_slot));check(std::memcmp(&saved,&owner.state(),sizeof saved)==0);}
            call(o2_005D8390_0x5d8390,ram);owner.reset_styles();compare(ram,owner);
        }
    }
    for(unsigned slot=0;slot<128;++slot)for(unsigned preset=0;preset<8;++preset){vm::RoomModelRemap remap{};remap[7]=std::uint8_t(slot);vm::SceneModels owner(initial(slot*8+preset+1),remap);export_state(ram,owner);transform_write<std::uint32_t>(ram.data(),0x10000,7);transform_write<std::uint32_t>(ram.data(),0x10004,preset);
        check(call(o2_00690700_0x690700,ram)==0);check(owner.adjust(7,preset)==vm::ModelStatus::completed);compare(ram,owner);++matrix_cases;
    }
    vm::RoomModelRemap remap{};vm::SceneModels owner(initial(1),remap);const auto before=owner.state();check(owner.adjust(0,8)==vm::ModelStatus::invalid_preset);check(std::memcmp(&before,&owner.state(),sizeof before)==0);
    auto bad=owner.state().poses[0];bad[0][0]=std::numeric_limits<float>::quiet_NaN();check(owner.pose(0,bad)==vm::ModelStatus::completed);const auto nonfinite=owner.state();check(owner.adjust(0,0)==vm::ModelStatus::unsupported_numeric);check(std::memcmp(&nonfinite,&owner.state(),sizeof nonfinite)==0);
    check(!owner.pose(128));check(owner.pose(128,identity)==vm::ModelStatus::invalid_pose_slot);remap[0]=255;owner.room_remap(remap);check(owner.adjust(0,0)==vm::ModelStatus::invalid_pose_slot);
    for(unsigned kind=0;kind<3;++kind){auto bytes=std::make_shared<std::vector<std::byte>>(96);if(kind!=0){const std::uint32_t offset=kind==1?65:64;std::memcpy(bytes->data()+4,&offset,4);}bool refused=false;
        try{vm::content::ScriptBank bank(bytes,kind==2?vm::content::BankFormat::scenario_evb:vm::content::BankFormat::room_section);(void)vm::import_room_model_remap(bank);}catch(const std::invalid_argument&){refused=true;}check(refused);
    }
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"original_invocations\":"<<calls<<",\"original_helper_calls\":"<<ports<<",\"owned_rooms\":"<<room_cases<<",\"flag_cases\":"<<flag_cases<<",\"matrix_cases\":"<<matrix_cases<<"}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
