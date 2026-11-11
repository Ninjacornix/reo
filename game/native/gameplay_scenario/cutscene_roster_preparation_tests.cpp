#include "cutscene_roster_preparation.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <source_location>
#include <stdexcept>
#include <vector>
#ifdef REO_CUTSCENE_ROSTER_ORIGINAL
#include "roster_reference.hpp"
#endif
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},cases{},original_cases{},unavailable{},special_cases{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Scene roster preparation check ")+at.file_name()+":"+std::to_string(at.line()));
}
bool same(const s::CutsceneRosterState& a,const s::CutsceneRosterState& b){return a.roster.characters==b.roster.characters&&a.roster.eligible_count==b.roster.eligible_count&&a.source_slots==b.source_slots&&a.source_statuses==b.source_statuses&&a.preferred_one_based==b.preferred_one_based;}
#ifdef REO_CUTSCENE_ROSTER_ORIGINAL
std::vector<std::uint8_t> memory(0x2000000);unsigned cleanup_calls{};
void compare(const s::CutsceneRosterFrame& frame,const s::CutsceneRosterState& before,const s::CutsceneRosterPrepared& result){
    auto* m=memory.data();std::memset(m+0x38eca0,0,0x1800);std::memset(m+0x4a5c30,0,8*0x10e0);std::memcpy(m+0x38ed90,before.roster.characters.data(),8);std::memcpy(m+0x38ed88,before.source_slots.data(),8);std::memcpy(m+0x38ece8,before.source_statuses.data(),32);
    transform_write(m,0x38edcc,unsigned(before.roster.eligible_count));transform_write(m,0x38ecdc,before.preferred_one_based);transform_write(m,0x38ecd4,frame.mode);transform_write(m,0x4baea0,*frame.authored_population);transform_write(m,0x3243da,*frame.scenario);transform_write(m,0x32440c,0x800000u);transform_write(m,0x324444,0x600000u);
    for(unsigned i=0;i<8;++i){const auto at=0x4a5c30+i*0x10e0;m[at+1]=0x7f;if(frame.actors[i]){const auto& a=*frame.actors[i];transform_write(m,at+0xba0,a.status);transform_write(m,at+0x1e2,a.room);m[at+0xb98]=a.character;m[at+3]=a.slot;}}
    for(unsigned i=0;i<4;++i)m[0x4b9d01+3*i]=frame.placement_rooms[i].value_or(0);
    R5900Context c;PS2Runtime runtime;c.pc=0x5ed340;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);cleanup_calls=0;o2_005ED340_0x5ed340(m,&c,&runtime);
    check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000&&cleanup_calls>0);
    check(result.state.roster.eligible_count==transform_read<unsigned>(m,0x38edcc)&&result.state.preferred_one_based==transform_read<unsigned>(m,0x38ecdc));
    for(unsigned i=0;i<8;++i){check(result.state.roster.characters[i]==m[0x38ed90+i]&&result.state.source_slots[i]==m[0x38ed88+i]&&result.state.source_statuses[i]==transform_read<unsigned>(m,0x38ece8+4*i));check(result.hide_primaries[i]==(m[0x4a5c30+i*0x10e0+1]==0));}
    ++original_cases;
}
#else
void compare(const s::CutsceneRosterFrame&,const s::CutsceneRosterState&,const s::CutsceneRosterPrepared&){}
#endif
void run(const s::CutsceneRosterFrame& frame,const s::CutsceneRosterState& before){
    const auto result=s::prepare_cutscene_roster(frame,before);++cases;
    if(result.status!=s::CutsceneRosterStatus::completed){check(same(result.state,before)&&std::ranges::none_of(result.hide_primaries,[](bool b){return b;}));++unavailable;return;}
    check(result.state.roster.eligible_count<=8);compare(frame,before,result);
}
s::CutsceneRosterState previous(unsigned seed,unsigned preferred){
    s::CutsceneRosterState state;state.preferred_one_based=preferred;state.roster.eligible_count=7;
    for(unsigned i=0;i<8;++i){state.roster.characters[i]=std::uint8_t(seed+37*i);state.source_slots[i]=std::uint8_t(seed+43*i);state.source_statuses[i]=0x87654321u+seed*13+i;}
    return state;
}
void generated(){
    constexpr std::array<std::int32_t,10> modes{-1,0,1,2,3,4,5,6,7,128};constexpr std::array<std::uint16_t,4> rooms{0x13,0x21,0,0x101};constexpr std::array<std::uint8_t,8> characters{0,1,2,7,128,255,17,254};constexpr std::array<std::uint32_t,6> bad_statuses{0x20,0x40,0x80,0x100,0x400,0x5e0};
    for(unsigned population=0;population<=8;++population)for(const auto mode:modes)for(unsigned preferred=0;preferred<=8;++preferred)for(unsigned mask=0;mask<256;++mask)for(unsigned special=0;special<2;++special){
        s::CutsceneRosterFrame frame;frame.authored_population=population;frame.scenario=std::uint16_t(special?0x23:0x22);frame.mode=mode;
        for(unsigned i=0;i<8;++i)frame.actors[i]=s::CutsceneRosterActor{(mask&(1u<<i)?bad_statuses[(mask+i)%6]:0x80000000u),rooms[(mask+i)%4],characters[i],std::uint8_t((i+mask)%8)};
        frame.placement_rooms={0x13,0x21,0,0x80};run(frame,previous(mask,preferred));
    }
    // Special branch can append the same actor twice, or append a room13
    // actor excluded by the ordinary status mask. Preserve those source rules.
    for(bool excluded:{false,true}){
        s::CutsceneRosterFrame frame;frame.authored_population=excluded?2:1;frame.scenario=0x23;frame.mode=6;frame.actors[0]=s::CutsceneRosterActor{excluded?0x5e0u:0u,0x13,3,0};frame.actors[1]=s::CutsceneRosterActor{0,0x21,7,1};
        const auto before=previous(123,excluded?2:1);const auto result=s::prepare_cutscene_roster(frame,before);check(result.status==s::CutsceneRosterStatus::completed&&result.state.roster.eligible_count==2&&result.state.roster.characters[1]==3&&result.state.source_statuses[1]==(excluded?0x5e0u:0u));run(frame,before);++special_cases;
    }
    s::CutsceneRosterFrame frame;frame.authored_population=0;frame.scenario=0;const auto before=previous(1,0);run(frame,before);
    frame.authored_population.reset();run(frame,before);frame.authored_population=9;run(frame,before);frame.authored_population=1;run(frame,before);frame.actors[0]=s::CutsceneRosterActor{};frame.scenario.reset();run(frame,before);frame.scenario=0;run(frame,previous(1,9));
}
}
#ifdef REO_CUTSCENE_ROSTER_ORIGINAL
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    ++cleanup_calls;
    switch(c->pc){
    case 0x107c68:{const auto at=GPR_U32(c,4),size=GPR_U32(c,6);check(at==0x600000&&size==0x10000&&GPR_U32(c,5)==0);std::memset(m+at,0,size);SET_GPR_U32(c,2,at);break;}
    case 0x1cd120:case 0x1b14a0:case 0x1b2b90:case 0x6519a0:case 0x1b13b0:case 0x1b1690:case 0x1925a0:case 0x1b1e50:case 0x1b1bb0:case 0x5f1290:case 0x5ebb10:case 0x5ebc20:case 0x1b2c30:case 0x67c250:break;
    default:throw std::runtime_error("Undeclared scene roster preparation port "+std::to_string(c->pc));
    }c->pc=GPR_U32(c,31);
}
#endif
int main(){try{generated();std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"cases\":"<<cases<<",\"original_cases\":"<<original_cases<<",\"unavailable\":"<<unavailable<<",\"special_cases\":"<<special_cases<<",\"game_run\":false}\n";return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
