#include "cutscene_primary_selection.hpp"
#include <algorithm>
#include <fstream>
#include <iostream>
#include <source_location>
#include <vector>
#ifdef REO_CUTSCENE_SELECTION_ORIGINAL
#include "selection_reference.hpp"
#endif
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},compared{},full_cases{},choices{},descriptor_cases{},preference_refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Cutscene primary selection check ")+at.file_name()+":"+std::to_string(at.line()));
}
s::CutscenePrimaryRoster roster_of(std::span<const std::uint8_t> characters){
    check(characters.size()<=8);s::CutscenePrimaryRoster result;result.characters.fill(255);std::ranges::copy(characters,result.characters.begin());result.population=std::uint8_t(characters.size());return result;
}
#ifdef REO_CUTSCENE_SELECTION_ORIGINAL
std::vector<std::uint8_t> memory(0x2000000);
std::vector<s::CutscenePrimaryChoice> observed;
std::vector<std::uint8_t> observed_retirements;
constexpr unsigned temporary_base=0xb1f000;
void compare(std::span<const s::CutscenePrimaryHeader> headers,const s::CutscenePrimaryRoster& roster,unsigned preferred,std::array<bool,8> occupied,const s::CutsceneActorReservations& previous,const s::CutscenePrimarySelection& result,std::span<const std::array<std::byte,36>> original_headers){
    auto* m=memory.data();std::memset(m+0x38ec00,0,0x1500);std::memset(m+temporary_base,0,8*0x10e0);
    transform_write(m,0x38ecb6,std::int16_t(headers.size()));transform_write(m,0x38edcc,unsigned(roster.population));transform_write(m,0x38ecdc,preferred);transform_write(m,0x38edd0,temporary_base);
    std::memcpy(m+0x38ed90,roster.characters.data(),8);std::memset(m+0x4a5c30,0,8*0x10e0);
    for(unsigned i=0;i<8;++i){m[0x4a5c30+i*0x10e0+3]=std::uint8_t(i);m[0x4a5c30+i*0x10e0+0xb98]=std::uint8_t(60+i);}
    for(unsigned i=0;i<8;++i){m[temporary_base+0x10e0*i]=occupied[i];m[temporary_base+0x10e0*i+3]=std::uint8_t(i);}
    for(unsigned i=0;i<headers.size();++i){const auto& h=headers[i];const unsigned at=0x200000+0x100*i;std::memset(m+at,0,36);transform_write(m,0x38fb60+32*i+28,at);transform_write(m,at+2,std::uint16_t(h.enabled?0:65535));transform_write(m,at+4,h.kind);transform_write(m,at+6,h.character);transform_write(m,at+10,h.encoded_class);}
    if(!original_headers.empty()){check(original_headers.size()==headers.size());for(unsigned i=0;i<headers.size();++i)std::memcpy(m+0x200000+0x100*i,original_headers[i].data(),36);}
    std::memset(m+0x7434d0,0x88,64);std::memcpy(m+0x7434f0,previous.requested().data(),previous.requested().size());std::memcpy(m+0x7434d0,previous.reserved().data(),previous.reserved().size());m[0x743518]=std::uint8_t(previous.requested().size());m[0x743510]=std::uint8_t(previous.reserved().size());
    R5900Context c;PS2Runtime runtime;c.pc=0x5f0dc0;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);observed.clear();observed_retirements.clear();o2_005F0DC0_0x5f0dc0(m,&c,&runtime);
    check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000&&std::ranges::equal(result.selected(),observed));
    check(result.reservations.requested().size()==m[0x743518]&&result.reservations.reserved().size()==m[0x743510]);
    for(unsigned i=0;i<8;++i)check(result.roster.characters[i]==m[0x38ed90+i]);
    std::vector<std::uint8_t> expected_retirements;for(const auto& choice:result.selected())if(choice.cloned_roster_slot&&choice.model_class==1)expected_retirements.push_back(*choice.cloned_roster_slot);
    check(observed_retirements==expected_retirements);
    for(unsigned i=0;i<result.reservations.requested().size();++i)check(result.reservations.requested()[i]==m[0x7434f0+i]);
    for(unsigned i=0;i<result.reservations.reserved().size();++i)check(result.reservations.reserved()[i]==m[0x7434d0+i]);
    ++compared;
}
#else
void compare(std::span<const s::CutscenePrimaryHeader>,const s::CutscenePrimaryRoster&,unsigned,std::array<bool,8>,const s::CutsceneActorReservations&,const s::CutscenePrimarySelection&,std::span<const std::array<std::byte,36>>){}
#endif
void run_state(std::span<const s::CutscenePrimaryHeader> headers,const s::CutscenePrimaryRoster& roster_state,unsigned preferred,std::array<bool,8> occupied={},std::span<const std::array<std::byte,36>> original_headers={}){
    s::CutsceneActorReservations previous;const std::array<std::uint8_t,3> saved{0,128,7};check(previous.initialize(saved)==s::CutsceneReservationStatus::completed);check(previous.reserve(254)==s::CutsceneReservationStatus::completed);
    const auto result=s::select_cutscene_primaries(headers,roster_state,preferred,occupied,previous);check(result.status==s::CutscenePrimarySelectionStatus::completed||result.status==s::CutscenePrimarySelectionStatus::full);
    for(const auto& choice:result.selected()){check(choice.group<headers.size()&&choice.temporary_slot<8&&!occupied[choice.temporary_slot]);occupied[choice.temporary_slot]=true;++choices;}
    if(result.status==s::CutscenePrimarySelectionStatus::full){check(result.failed_group&&std::ranges::all_of(occupied,[](bool b){return b;}));++full_cases;return;}
    // Pass the original occupancy, not the locally checked final state.
    for(const auto& choice:result.selected())occupied[choice.temporary_slot]=false;
    compare(headers,roster_state,preferred,occupied,previous,result,original_headers);
}
void run(std::span<const s::CutscenePrimaryHeader> headers,std::span<const std::uint8_t> roster,unsigned preferred,std::array<bool,8> occupied={},std::span<const std::array<std::byte,36>> original_headers={}){
    run_state(headers,roster_of(roster),preferred,occupied,original_headers);
}
const std::array<std::array<std::uint8_t,4>,4> rosters{{{0,1,2,3},{3,1,1,0},{255,0,128,7},{128,255,129,254}}};
void generated(){
    for(unsigned seed=0;seed<1024;++seed){
        std::array<s::CutscenePrimaryHeader,8> headers{};const unsigned count=seed%9;
        for(unsigned i=0;i<count;++i){const auto code=(seed>>(i%5))^i;headers[i].enabled=(code&8)==0;const std::array<std::int16_t,4> kinds{0,3,1,7};headers[i].kind=kinds[code&3];const std::array<std::int16_t,8> characters{0,1,2,3,255,128,-1,-128};headers[i].character=characters[(code>>2)&7];headers[i].encoded_class=std::int16_t((code>>4)&3);}
        std::array<bool,8> occupied{};for(unsigned i=0;i<8;++i)occupied[i]=bool(seed&(1u<<i));
        for(const auto& roster:rosters)for(unsigned preferred=0;preferred<=4;++preferred)run(std::span(headers).first(count),roster,preferred,occupied);
    }
    // Source ordering: a later required fallback can prevent an earlier
    // optional fallback, even when a roster character is initially available.
    const std::array<s::CutscenePrimaryHeader,3> order{{{true,3,1,0},{true,3,0,1},{true,3,1,0}}};
    const auto result=s::select_cutscene_primaries(order,roster_of(rosters[0]),2);check(result.count==2&&result.choices[0].group==1&&result.choices[0].character==1&&result.choices[1].group==2&&result.choices[1].character==0);
    for(unsigned preference:{5u,255u,0xffffffffu}){const auto rejected=s::select_cutscene_primaries(std::span(order).subspan(1,1),roster_of(rosters[0]),preference);check(rejected.status==s::CutscenePrimarySelectionStatus::invalid_preference&&rejected.failed_group==0);++preference_refusals;}
    const std::array<s::CutscenePrimaryHeader,33> too_many{};check(s::select_cutscene_primaries(too_many,{},0).status==s::CutscenePrimarySelectionStatus::invalid_count);
    s::CutscenePrimaryRoster too_many_roster;too_many_roster.population=9;check(s::select_cutscene_primaries({},too_many_roster,0).status==s::CutscenePrimarySelectionStatus::invalid_count);
    // The requested/reserved byte rules deliberately permit repeated128 from
    // an unsigned roster query. Do not silently normalize it into a set.
    const std::array<s::CutscenePrimaryHeader,3> high{{{true,3,0,0},{true,3,0,0},{true,3,0,0}}};const std::array<std::uint8_t,1> signed_roster{128};const auto repeated=s::select_cutscene_primaries(high,roster_of(signed_roster),0);check(repeated.count==1&&repeated.choices[0].character==128&&repeated.roster.characters[0]==255);
    run(high,signed_roster,0);auto retained_high=high;for(auto& h:retained_high)h.encoded_class=1;run(retained_high,signed_roster,0);
    const auto retained_result=s::select_cutscene_primaries(retained_high,roster_of(signed_roster),0);check(retained_result.count==3&&retained_result.choices[0].character==128&&retained_result.choices[1].character==128&&retained_result.choices[2].character==128);
    const std::array<s::CutscenePrimaryHeader,2> duplicate{{{true,0,1,0},{true,0,1,0}}};const std::array<std::uint8_t,3> duplicate_roster{1,1,0};run(duplicate,duplicate_roster,0);
    const auto duplicate_result=s::select_cutscene_primaries(duplicate,roster_of(duplicate_roster),0);check(duplicate_result.count==2&&duplicate_result.choices[0].cloned_roster_slot==0&&duplicate_result.choices[1].cloned_roster_slot==1&&duplicate_result.roster.characters[0]==255&&duplicate_result.roster.characters[1]==255);
    auto hidden=roster_of(rosters[0]);hidden.characters[6]=17;const std::array<s::CutscenePrimaryHeader,1> hidden_header{{{true,0,17,0}}};run_state(hidden_header,hidden,0);
    const auto hidden_result=s::select_cutscene_primaries(hidden_header,hidden,0);check(hidden_result.count==1&&hidden_result.choices[0].cloned_roster_slot==6&&hidden_result.roster.characters[6]==255&&hidden.characters[6]==17);
    const std::array<s::CutscenePrimaryHeader,5> population_headers{{{true,3,1,0},{true,0,2,1},{true,3,0,0},{true,3,1,1},{true,3,0,1}}};
    for(unsigned population=0;population<=8;++population){
        s::CutscenePrimaryRoster state;state.population=std::uint8_t(population);state.characters={3,2,128,1,255,0,7,128};
        for(unsigned preferred=0;preferred<=population;++preferred){run_state(population_headers,state,preferred);std::array<bool,8> alternating{true,false,true,false,true,false,true,false};run_state(population_headers,state,preferred,alternating);}
    }
}
void descriptors(const char* package){
    std::ifstream stream(package,std::ios::binary);check(bool(stream));const auto read=[&](){std::uint32_t value{};stream.read(reinterpret_cast<char*>(&value),4);check(bool(stream));return value;};const auto count=read();check(count==548);
    for(unsigned n=0;n<count;++n){const auto size=read();check(size<=s::CutsceneDescriptor::maximum_bytes);std::vector<std::byte> bytes(size);stream.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(stream));const auto descriptor=s::CutsceneDescriptor::import(bytes);const auto headers=s::cutscene_primary_headers(*descriptor);
        std::array<std::array<std::byte,36>,32> raw_headers{};
        check(headers.count==descriptor->actor_groups().size());for(unsigned i=0;i<headers.count;++i){const auto raw=descriptor->section(descriptor->actor_groups()[i][7]);check(raw.size()>=36);std::memcpy(raw_headers[i].data(),raw.data(),36);}
        for(const auto& roster:rosters)for(unsigned preferred=0;preferred<=4;++preferred){run(headers.view(),roster,preferred,{},std::span(raw_headers).first(headers.count));++descriptor_cases;}
    }
    check(stream.peek()==std::char_traits<char>::eof());
}
}
#ifdef REO_CUTSCENE_SELECTION_ORIGINAL
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
    case 0x5f0c60:o2_005F0C60_0x5f0c60(m,c,r);return;
    case 0x5f0cf0:o2_005F0CF0_0x5f0cf0(m,c,r);return;
    case 0x5f0d90:o2_005F0D90_0x5f0d90(m,c,r);return;
    case 0x5f1330:o2_005F1330_0x5f1330(m,c,r);return;
    case 0x5f1400:{const auto actor=GPR_U32(c,4),descriptor=GPR_U32(c,5);check(actor>=temporary_base&&actor<temporary_base+8*0x10e0&&(actor-temporary_base)%0x10e0==0);check(descriptor>=0x38eca0+0x138&&(descriptor-(0x38eca0+0x138))%140==0);const auto group=(descriptor-(0x38eca0+0x138))/140;check(group<32);
        // Preserve source construction semantics in a nonoverlapping metadata
        // arena, matching native typed storage rather than old array aliases.
        const unsigned safe=0x300000+32*group;std::memset(m+safe,0x55,32);SET_GPR_U32(c,5,safe);o2_005F1400_0x5f1400(m,c,r);
        std::optional<std::uint8_t> cloned;if(m[safe+1]!=255){check(m[safe+1]<8);cloned=m[safe+1];}
        check(m[safe]==0&&m[safe+2]==std::uint8_t(!cloned||m[safe+3]==1)&&transform_read<unsigned>(m,safe+4)==actor);
        observed.push_back({std::uint8_t(group),m[actor+3],m[actor+0xb98],m[safe+3],cloned});return;}
    case 0x5ec270:{const auto slot=GPR_U32(c,4);check(slot<8&&GPR_U32(c,5)==0x4a5c30+slot*0x10e0);observed_retirements.push_back(std::uint8_t(slot));break;}
    case 0x107c68:{const auto at=GPR_U32(c,4),size=GPR_U32(c,6),value=GPR_U32(c,5);check(at<0x2000000&&size<=0x2000000-at&&((size==32&&value==0x88)||(size==80&&value==0)));std::memset(m+at,int(value),size);SET_GPR_U32(c,2,at);break;}
    case 0x107ab0:{const auto at=GPR_U32(c,4),from=GPR_U32(c,5),size=GPR_U32(c,6);check(at<0x2000000&&size<=0x2000000-at&&from<0x2000000&&size<=0x2000000-from&&(size<=32||size==0x10e0));std::memcpy(m+at,m+from,size);SET_GPR_U32(c,2,at);break;}
    default:throw std::runtime_error("Undeclared primary choice source port");
    }c->pc=GPR_U32(c,31);
}
#endif
int main(int argc,char** argv){try{generated();if(argc==2)descriptors(argv[1]);std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"compared\":"<<compared<<",\"full_cases\":"<<full_cases<<",\"choices\":"<<choices<<",\"descriptor_cases\":"<<descriptor_cases<<",\"preference_refusals\":"<<preference_refusals<<",\"game_run\":false}\n";return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
