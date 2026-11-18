#include "game/native/gameplay_world/dialogue_bank_bindings.hpp"
#include "game/native/gameplay_world/primary_actor_records.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include <cstring>
#include <iostream>
#include <stdexcept>
namespace w=reo::native::gameplay_world;namespace s=reo::native::gameplay_scenario;
namespace {
std::vector<std::uint8_t> memory(0x2000000);std::uint64_t checks{},publications{},skipped{},leases{},prefixes{},source_calls{};bool stop_mapping{};
struct InvalidMapping {};
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue physical bank binding "+std::to_string(checks));}
template<class T>void put(unsigned at,T value){std::memcpy(memory.data()+at,&value,sizeof value);}
template<class T>T get(unsigned at){T value;std::memcpy(&value,memory.data()+at,sizeof value);return value;}
w::Profile profile(){w::Profile p;p.layouts.push_back({});return p;}
unsigned cue_base(unsigned physical){return 0x800000+0x20000*physical;}
unsigned text_base(unsigned physical){return 0xa00000+0x10000*physical;}
void original(unsigned base,unsigned mode,unsigned physical){R5900Context state;PS2Runtime runtime;state.pc=0x6b7350;SET_GPR_U32(&state,4,base);SET_GPR_U32(&state,5,mode);SET_GPR_U32(&state,6,physical);SET_GPR_U32(&state,31,0xabcdef);original_transform_port(memory.data(),&state,&runtime);check(state.pc==0xabcdef);}
void compare(const w::DialogueBankBindings& native){
 const auto view=native.logical();
 for(unsigned i=0;i<8;++i){const auto physical=native.physical_for_character(i);check(physical&&*physical==memory[0x74f0f4+i]);const auto bank=native.physical(*physical);check(bank&&view[i].cues==bank->cues&&view[i].texts==bank->texts);}
 check(!native.physical_for_character(8)&&!native.physical(5));
 for(unsigned i=0;i<5;++i){const auto bank=native.physical(i);check(bank);const auto first=get<unsigned>(0x74f0cc+4*i),second=get<unsigned>(0x74f0b8+4*i),text=get<unsigned>(0x74f0e0+4*i);check(bool(first)==bool(bank->cues)&&bool(second)==bool(bank->cues)&&bool(text)==bool(bank->texts));
  if(bank->cues){const auto bytes=bank->cues->backing();check(first==cue_base(i)+get<unsigned>(cue_base(i)+16)&&second==cue_base(i)+get<unsigned>(cue_base(i)+20)&&std::memcmp(bytes->data(),memory.data()+cue_base(i),bytes->size())==0);}
  if(bank->texts){const auto bytes=bank->texts->backing();check(text==text_base(i)&&std::memcmp(bytes->data(),memory.data()+text_base(i),bytes->size())==0);}
 }
 check(view[8].cues==native.physical(4)->cues&&view[8].texts==native.physical(4)->texts);
}
}
void observed_binding_write(std::uint8_t* ram,const R5900Context* context,std::uint32_t at,std::uint8_t value){if(stop_mapping&&context->pc==0x6b73d8)throw InvalidMapping{};ram[at]=value;}
void original_transform_port(std::uint8_t* ram,R5900Context* state,PS2Runtime* runtime){++source_calls;o2_006B7350_0x6b7350(ram,state,runtime);}
int main(int argc,char** argv)try{
 check(argc==2);auto source=std::make_shared<const reo::assets::Source>(argv[1]);s::content::ScenarioArchive archive(source);std::array<s::DialogueBank,3> assets{s::prepare_dialogue_bank(archive,1,0,0),s::prepare_dialogue_bank(archive,1,0,1),s::prepare_dialogue_bank(archive,1,0,8)};
 w::World world(profile(),std::make_shared<w::Session>());check(w::initialize_primary_records(world).status==w::PrimaryRecordsStatus::completed);
 for(unsigned seed=0;seed<8192;++seed){w::DialogueBankBindings native;std::fill(memory.begin()+0x74e6c0,memory.begin()+0x74f0fc,0);compare(native);
  for(unsigned step=0;step<10;++step){const unsigned physical=(step+seed%5)%5,character=((seed>>(step%8))+physical)&7,asset=(seed+step)%3;const bool texts=step&1;
   world.primary(physical==4?0:physical)->character=std::uint8_t(character);if(physical<4)memory[0x4a67c8+0x10e0*physical]=world.primary(physical)->character;
   const auto old=native.logical();const auto old_owner=old[character].cues;const auto old_bytes=old_owner?old_owner->backing():nullptr;std::array<std::byte,32> retained_prefix{};if(old_bytes)std::memcpy(retained_prefix.data(),old_bytes->data(),retained_prefix.size());
   if((seed+step)%7==0){++skipped;compare(native);continue;}
   const auto& input=assets[asset];check(input.cues&&input.texts);const auto bytes=texts?input.texts->backing():input.cues->backing();const auto base=texts?text_base(physical):cue_base(physical);std::memcpy(memory.data()+base,bytes->data(),bytes->size());
   const auto result=texts?native.publish_texts(physical,std::uint8_t(character),input.texts,input.text_identity):native.publish_cues(physical,std::uint8_t(character),input.cues,input.cue_identity);original(base,texts?((seed&1)?1u:0xffffffffu):0u,physical);check(result.status==w::DialogueBankBindingStatus::completed&&result.physical_published&&result.character_mapped==(physical!=4));compare(native);++publications;
   if(old_owner){check(old_owner->backing()==old_bytes&&std::memcmp(old_owner->backing()->data(),retained_prefix.data(),retained_prefix.size())==0);++leases;}
  }
  // The physical pointer write precedes the out-of-range character map write.
  const unsigned physical=seed%4;memory[0x4a67c8+0x10e0*physical]=255;const auto bytes=assets[0].cues->backing();std::memcpy(memory.data()+cue_base(physical),bytes->data(),bytes->size());const auto result=native.publish_cues(physical,255,assets[0].cues,assets[0].cue_identity);stop_mapping=true;bool stopped{};try{original(cue_base(physical),0,physical);}catch(const InvalidMapping&){stopped=true;}stop_mapping=false;check(stopped&&result.status==w::DialogueBankBindingStatus::unsupported_profile&&result.physical_published&&!result.character_mapped);compare(native);++prefixes;
 }
 w::DialogueBankBindings guards;check(guards.publish_cues(5,0,assets[0].cues,{}).status==w::DialogueBankBindingStatus::unsupported_profile);check(guards.publish_cues(0,0,{},{}).status==w::DialogueBankBindingStatus::unavailable);check(guards.publish_cues(0,{},assets[0].cues,{}).status==w::DialogueBankBindingStatus::unavailable&&guards.physical(0)->cues==assets[0].cues);check(guards.publish_texts(4,{},assets[0].texts,{}).status==w::DialogueBankBindingStatus::completed);
 std::cout<<"{\"checks\":"<<checks<<",\"complete_publications\":"<<publications<<",\"missing_half_loads_preserved\":"<<skipped<<",\"invalid_character_write_prefixes\":"<<prefixes<<",\"retained_bank_leases\":"<<leases<<",\"source_calls\":"<<source_calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
