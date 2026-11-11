#include "humanoid_motion_assets.hpp"
#include "actor_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <set>
#include <cstring>
#ifdef REO_HUMANOID_MOTION_ORIGINAL
std::string humanoid_original_identity(unsigned);
struct R5900Context;struct PS2Runtime;
bool humanoid_loader_original_port(std::uint8_t*,R5900Context*,PS2Runtime*);
void original_scene_motion_cleanup(std::vector<std::uint8_t>&);
#include "motion_bank_fixture.hpp"
#endif
namespace hm=reo::native::gameplay_world;
namespace anim=reo::native::animation;
namespace {
std::uint64_t native_checks{},common_loads{},character_loads{},snapshot_cases{},npc_bindings_cases{},loader_name_cases{};
std::uint64_t character_releases{},released_queries{},base_releases{};
std::uint64_t scene_family_releases{};
std::uint64_t initial_bank_cases{},initial_bank_queries{},initial_bank_overlays{};
std::uint64_t scene_table_releases{};
void verify(bool value,std::source_location at=std::source_location::current()){
    ++native_checks;if(!value)throw std::runtime_error("Humanoid motion check "+std::to_string(at.line()));
}
struct OwnedMotion {unsigned index{},character{},member{};std::string name;std::uint64_t offset{};std::vector<std::byte> bytes;};
std::vector<OwnedMotion> owned_motion;
void contracts(){
    const hm::HumanoidSceneMotionLoad unavailable;verify(!unavailable.banks&&std::all_of(unavailable.status.begin(),unavailable.status.end(),[](auto status){return status==hm::ScriptedMotionLoadStatus::not_found;}));
    const auto members=hm::file1_humanoid_motion_members();std::set<unsigned> ordinals;std::set<std::pair<unsigned,unsigned>> identities;
    for(const auto& entry:members){verify(ordinals.insert(entry.member).second&&identities.emplace(entry.index,entry.character).second&&!entry.name.empty());}
    verify(members.size()==98&&identities.count({0,255})&&identities.count({0,3})&&identities.count({0,5}));
    bool refused=false;try{hm::HumanoidMotionAssets unavailable({});}catch(const std::invalid_argument&){refused=true;}verify(refused);
    for(bool loaded:{false,true}){
        const auto cold=hm::HumanoidMotionAssets::initial_banks(loaded);
        verify(cold&&cold->base_loaded()==loaded&&!cold->scripted().mode_one&&!cold->scripted().track_two);
        for(unsigned i=0;i<8;++i)verify(cold->character(i)&&cold->character(i)->cleared()&&cold->character(i)->kind()==anim::MotionBankKind::strided);
        verify(cold->scripted().other_modes->cleared()&&cold->alternate_style()->cleared()&&cold->bank({hm::HumanoidMotionFamily::primary,0})->cleared());
    }
}
#ifdef REO_HUMANOID_MOTION_ORIGINAL
void compare_common(const hm::HumanoidMotionBanks& banks,std::vector<std::uint8_t>& memory){compare(*banks.scripted().other_modes,memory,0x4e8970);compare(*banks.alternate_style(),memory,0x4e6a20);}
void compare_character(const hm::HumanoidMotionBanks& banks,unsigned character,std::vector<std::uint8_t>& memory){compare(*banks.character(character),memory,0x4d7000+0x1f44*character);}
void original_base(std::vector<std::uint8_t>& memory){memory[0x4bae0f]=0;call(memory.data(),0x1d1a80,0);}
void original_overlay(std::vector<std::uint8_t>& memory,unsigned index,std::span<const std::uint8_t> characters){
    for(unsigned slot=0;slot<8;++slot){const auto at=0x4a5c30+0x10e0*slot;memory[at]=slot<characters.size();memory[at+0xb98]=slot<characters.size()?characters[slot]:0;}
    call(memory.data(),0x1d1b10,index+0x10000u);
}
#endif
void cold_initialization(const hm::HumanoidMotionAssets& assets){
    for(unsigned gate:{0u,1u,128u}){
        const auto cold=hm::HumanoidMotionAssets::initial_banks(gate!=0);
        verify(cold->base_loaded()==bool(gate)&&!cold->scripted().mode_one&&!cold->scripted().track_two);
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        std::vector<std::uint8_t> memory(0x2000000);constants(memory.data());owned_humanoid_formats(memory.data());put(memory.data(),0x32440c,raw_base);
        std::fill_n(memory.data()+0x4b0000,0x40000,0xa5);memory[0x4bae0f]=std::uint8_t(gate);
        call(memory.data(),0x1b2150,0);verify(memory[0x4bae0f]==gate);
        compare_common(*cold,memory);compare(*cold->bank({hm::HumanoidMotionFamily::primary,0}),memory,0x4ea8c0);
        for(unsigned i=0;i<8;++i)compare_character(*cold,i,memory);
#endif
        for(unsigned i=0;i<8;++i)for(unsigned key=0;key<1000;++key)for(unsigned track=0;track<5;++track){verify(!cold->character(i)->find(key,std::uint16_t(track)));++initial_bank_queries;}
        const auto loaded=assets.ensure_base(cold);verify(loaded->base_loaded()&&((loaded==cold)==bool(gate)));
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        call(memory.data(),0x1d1a80,0);verify(bool(memory[0x4bae0f])==loaded->base_loaded());compare_common(*loaded,memory);
        for(unsigned i=0;i<8;++i)compare_character(*loaded,i,memory);
#endif
        const std::array<std::uint8_t,2> selected{3,5};const auto overlaid=assets.overlay(1,selected,*loaded);
        verify(overlaid->follows(*loaded)&&overlaid->base_loaded()==loaded->base_loaded());
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        original_overlay(memory,1,selected);compare_common(*overlaid,memory);
        for(unsigned i=0;i<8;++i)compare_character(*overlaid,i,memory);
#endif
        for(unsigned i=0;i<8;++i)verify(i==3||i==5?!overlaid->character(i)->cleared():overlaid->character(i)==loaded->character(i));
        const auto families=assets.release_scene_families(*overlaid);verify(families->follows(*overlaid)&&!families->base_loaded());
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        call(memory.data(),0x1b1e50,0);compare_common(*families,memory);for(unsigned i=0;i<8;++i)compare_character(*families,i,memory);
#endif
        for(unsigned i=0;i<8;++i)verify(cold->character(i)->cleared()&&cold->character(i)->kind()==anim::MotionBankKind::strided);
        ++initial_bank_cases;++initial_bank_overlays;
    }
}
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);std::ifstream rows(manifest);verify(bool(rows));OwnedMotion item;std::size_t length{};
    while(rows>>item.index>>item.character>>item.member>>item.name>>item.offset>>length){verify(length&&length<32u*1024u*1024u);item.bytes.resize(length);source->read(item.offset,length,item.bytes.data());owned_motion.push_back(item);}
    verify(rows.eof()&&owned_motion.size()==100);hm::HumanoidMotionAssets assets(source);const auto base=assets.base();
    cold_initialization(assets);
    verify(base&&base->base_loaded()&&base->scripted().other_modes&&base->alternate_style()&&!base->scripted().mode_one&&!base->scripted().track_two&&assets.ensure_base(base)==base);
    bool refused=false;try{(void)base->npc_bindings();}catch(const std::runtime_error&){refused=true;}verify(refused);
    refused=false;try{(void)assets.ensure_base({});}catch(const std::invalid_argument&){refused=true;}verify(refused&&base->base_loaded());
    for(unsigned character=0;character<8;++character)verify(!base->character(character));
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    std::vector<std::uint8_t> memory(0x2000000);constants(memory.data());owned_humanoid_formats(memory.data());put(memory.data(),0x32440c,raw_base);
    original_base(memory);compare_common(*base,memory);const auto base_memory=memory;const auto base_tokens=tokens;
    call(memory.data(),0x1b2130,0x4ea8c0);compare(*base->bank({hm::HumanoidMotionFamily::primary,0}),memory,0x4ea8c0);
#endif
    verify(base->bank({hm::HumanoidMotionFamily::primary,0})->cleared()&&base->bank({hm::HumanoidMotionFamily::primary,0})->kind()==anim::MotionBankKind::strided&&!base->bank({hm::HumanoidMotionFamily::primary,0})->find(0,0));
    const std::array<std::uint8_t,8> all{0,1,2,3,4,5,6,7};
    for(const auto& row:owned_motion){
        if(row.character!=255)continue;
        const auto banks=assets.overlay(std::uint16_t(row.index),all,*base);verify(banks&&banks->scripted().other_modes!=base->scripted().other_modes&&banks->alternate_style()!=base->alternate_style());
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        memory=base_memory;tokens=base_tokens;original_overlay(memory,row.index,all);compare_common(*banks,memory);
        for(auto character:all)compare_character(*banks,character,memory);
#endif
        for(auto character:all){verify(banks->character(character)&&banks->character(character)->kind()==anim::MotionBankKind::sparse);++character_loads;}
        verify(!base->character(0)&&!base->scripted().mode_one);++common_loads;++snapshot_cases;
    }
    const std::array<std::uint8_t,8> release_all{0,1,2,3,4,5,6,7};const auto all_ready=assets.overlay(1,release_all,*base);
    const auto all_released=assets.release_base(*all_ready);verify(!all_released->base_loaded()&&all_ready->base_loaded()&&all_released->follows(*all_ready));
    for(auto character:release_all){verify(all_released->character(character)!=all_ready->character(character)&&all_released->character(character)->first_track()==all_ready->character(character)->first_track()&&all_released->character(character)->track_count()==all_ready->character(character)->track_count());}
    ++base_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    memory=base_memory;tokens=base_tokens;original_overlay(memory,1,release_all);call(memory.data(),0x1b1df0,0);compare_common(*all_released,memory);for(auto character:release_all)compare_character(*all_released,character,memory);
#endif
    const auto family_cleared=assets.release_scene_families(*all_ready);verify(family_cleared->follows(*all_ready)&&!family_cleared->base_loaded()&&all_ready->base_loaded());
    const auto verify_scene_bank=[&](const auto& bank,const auto& previous){
        verify(bank&&previous&&bank!=previous&&bank->zero_header_known()&&bank->first_track()==0&&bank->track_count()==0&&bank->kind()==previous->kind());
        for(unsigned i=0;i<2000;++i){verify(bank->rows()[i]==0);verify(bank->slots()[i]==(i<5?previous->slots()[i]:nullptr));}
    };
    verify_scene_bank(family_cleared->scripted().other_modes,all_ready->scripted().other_modes);verify_scene_bank(family_cleared->alternate_style(),all_ready->alternate_style());for(auto character:release_all)verify_scene_bank(family_cleared->character(character),all_ready->character(character));++scene_family_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    memory=base_memory;tokens=base_tokens;original_overlay(memory,1,release_all);call(memory.data(),0x1b1e50,0);compare_common(*family_cleared,memory);for(auto character:release_all)compare_character(*family_cleared,character,memory);
#endif
    const auto twice_cleared=assets.release_scene_families(*family_cleared);verify(twice_cleared->follows(*family_cleared)&&!twice_cleared->base_loaded());++scene_family_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    call(memory.data(),0x1b1e50,0);compare_common(*twice_cleared,memory);for(auto character:release_all)compare_character(*twice_cleared,character,memory);
#endif
    const auto unknown_cleared=assets.release_scene_families(*base);verify(!unknown_cleared->character(0)&&unknown_cleared->follows(*base)&&unknown_cleared->bank({hm::HumanoidMotionFamily::primary,0})==base->bank({hm::HumanoidMotionFamily::primary,0}));++scene_family_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    memory=base_memory;tokens=base_tokens;call(memory.data(),0x1b1e50,0);compare_common(*unknown_cleared,memory);
#endif
    const std::array<std::uint8_t,2> npcs{3,5};const auto ready=assets.overlay(1,npcs,*base);
    refused=false;try{(void)ready->npc_bindings();}catch(const std::runtime_error&){refused=true;}verify(refused);
    const auto scene=assets.scene(1,2,*ready);verify(scene.status[0]==hm::ScriptedMotionLoadStatus::loaded&&scene.status[2]==hm::ScriptedMotionLoadStatus::loaded&&scene.status[1]==hm::ScriptedMotionLoadStatus::not_found);
    verify(!scene.banks->base_loaded()&&ready->base_loaded());
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    memory=base_memory;tokens=base_tokens;original_overlay(memory,1,npcs);compare_common(*ready,memory);compare_character(*ready,3,memory);compare_character(*ready,5,memory);
    call(memory.data(),0x1d1cc0,1,2);verify(memory[0x4bae0f]==0);compare_common(*scene.banks,memory);compare(*scene.banks->scripted().mode_one,memory,0x4bc810);
#endif
    {
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        const auto previous_memory=memory;const auto previous_tokens=tokens;
#endif
        auto current_scene=scene.banks;
        for(unsigned pass=0;pass<2;++pass){
            const auto cleaned=assets.release_scene_tables(*current_scene);
            verify(cleaned->follows(*current_scene)&&!cleaned->base_loaded()&&!cleaned->scripted().track_two&&cleaned->bank({hm::HumanoidMotionFamily::primary,0})==current_scene->bank({hm::HumanoidMotionFamily::primary,0}));
            verify(cleaned->scripted().mode_one->cleared()&&cleaned->scripted().other_modes->cleared()&&cleaned->scripted().mode_one->zero_header_known()&&cleaned->scripted().mode_one->kind()==current_scene->scripted().mode_one->kind());
            verify(current_scene->scripted().mode_one->kind()==anim::MotionBankKind::strided&&scene.banks->scripted().mode_one->track_count()==1);
#ifdef REO_HUMANOID_MOTION_ORIGINAL
            original_scene_motion_cleanup(memory);compare_common(*cleaned,memory);compare(*cleaned->scripted().mode_one,memory,0x4bc810);compare_character(*cleaned,3,memory);compare_character(*cleaned,5,memory);
#endif
            current_scene=cleaned;++scene_table_releases;
        }
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        memory=previous_memory;tokens=previous_tokens;
#endif
    }
    const auto bindings=scene.banks->npc_bindings();verify(bindings.primary==scene.banks->scripted().mode_one&&bindings.style[0]==scene.banks->scripted().other_modes&&bindings.style[1]==scene.banks->alternate_style());
    verify(scene.banks->scripted().other_modes!=ready->scripted().other_modes&&scene.banks->scripted().other_modes->kind()==anim::MotionBankKind::strided&&ready->scripted().other_modes->kind()==anim::MotionBankKind::sparse);
    verify(bindings.actor_type[3]==ready->character(3)&&bindings.actor_type[5]==ready->character(5)&&scene.banks->alternate_style()==ready->alternate_style());++snapshot_cases;
    const auto restored=assets.ensure_base(scene.banks);verify(restored->base_loaded()&&restored->scripted().other_modes->kind()==anim::MotionBankKind::sparse&&restored->scripted().mode_one==scene.banks->scripted().mode_one&&restored->character(3)!=scene.banks->character(3)&&assets.ensure_base(restored)==restored&&!scene.banks->base_loaded());++snapshot_cases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    call(memory.data(),0x1d1a80,0);verify(memory[0x4bae0f]==1);compare_common(*restored,memory);compare(*restored->scripted().mode_one,memory,0x4bc810);compare_character(*restored,3,memory);compare_character(*restored,5,memory);
#endif
    const auto overlaid=assets.overlay(2,npcs,*restored);verify(overlaid->base_loaded()&&overlaid->scripted().mode_one==restored->scripted().mode_one);++snapshot_cases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    original_overlay(memory,2,npcs);compare_common(*overlaid,memory);compare_character(*overlaid,3,memory);compare_character(*overlaid,5,memory);
#endif
    hm::Profile profile;profile.layouts.push_back({});hm::World world(profile,std::make_shared<hm::Session>());hm::NpcActorConstruction factory(world);hm::ActorAssets models(source);
    for(const auto& [id,model_class]:{std::pair{103u,0u},std::pair{88u,1u}}){const auto prepared=factory.prepare(id,model_class,models,bindings);const auto result=factory.create(*prepared);verify(result.status==hm::NpcConstructionStatus::completed);const auto actor=world.resolve(result.id);verify(actor&&actor->animation->resources[0]==bindings.primary&&actor->animation->resources[1]==bindings.style[actor->motion_style?1:0]&&actor->animation->resources[2]==bindings.actor_type[actor->character]);++npc_bindings_cases;}
    const auto missing=assets.scene(999,999,*overlaid);verify(!missing.banks->base_loaded()&&missing.status[0]==hm::ScriptedMotionLoadStatus::not_found&&missing.banks->scripted().mode_one==overlaid->scripted().mode_one&&missing.banks->scripted().other_modes==overlaid->scripted().other_modes);++snapshot_cases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    call(memory.data(),0x1d1cc0,999,999);verify(memory[0x4bae0f]==0);compare_common(*missing.banks,memory);compare(*missing.banks->scripted().mode_one,memory,0x4bc810);
#endif
    const auto before=ready->scripted().other_modes;
    for(const auto invalid:std::array<std::uint8_t,2>{8,255}){refused=false;try{(void)assets.overlay(1,std::span(&invalid,1),*ready);}catch(const std::out_of_range&){refused=true;}verify(refused&&ready->scripted().other_modes==before);}
    refused=false;try{(void)assets.overlay(65535,npcs,*ready);}catch(const std::out_of_range&){refused=true;}verify(refused&&ready->scripted().other_modes==before);
    const auto base_released=assets.release_base(*missing.banks);verify(base_released->follows(*missing.banks)&&!base_released->base_loaded()&&base_released->scripted().mode_one==missing.banks->scripted().mode_one&&base_released->scripted().track_two==missing.banks->scripted().track_two&&base_released->bank({hm::HumanoidMotionFamily::primary,0})==missing.banks->bank({hm::HumanoidMotionFamily::primary,0}));++base_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    call(memory.data(),0x1b1df0,0);verify(memory[0x4bae0f]==0);compare_common(*base_released,memory);compare_character(*base_released,3,memory);compare_character(*base_released,5,memory);
#endif
    const auto scene_families=assets.release_scene_families(*base_released);verify(scene_families->follows(*base_released)&&scene_families->scripted().mode_one==base_released->scripted().mode_one&&scene_families->scripted().track_two==base_released->scripted().track_two&&!scene_families->character(0)&&!scene_families->base_loaded());++scene_family_releases;
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    {const auto held_memory=memory;const auto held_tokens=tokens;call(memory.data(),0x1b1e50,0);compare_common(*scene_families,memory);compare_character(*scene_families,3,memory);compare_character(*scene_families,5,memory);compare(*scene_families->scripted().mode_one,memory,0x4bc810);memory=held_memory;tokens=held_tokens;}
#endif
    auto current=base_released;
    for(unsigned character=0;character<8;++character){
        const auto old=current->character(character);const auto released=assets.release_character(std::uint8_t(character),*current);const auto bank=released->character(character);
        verify(released->follows(*current)&&released->base_loaded()==current->base_loaded()&&bank&&bank->cleared()&&bank->track_count()==0&&bank->kind()==(old?old->kind():anim::MotionBankKind::strided));
        verify(released->scripted().mode_one==current->scripted().mode_one&&released->scripted().other_modes==current->scripted().other_modes&&released->alternate_style()==current->alternate_style());
        for(unsigned other=0;other<8;++other)if(other!=character)verify(released->character(other)==current->character(other));
#ifdef REO_HUMANOID_MOTION_ORIGINAL
        call(memory.data(),0x5ec0e0,character);compare_character(*released,character,memory);
#endif
        for(unsigned key=0;key<(bank->kind()==anim::MotionBankKind::sparse?2000u:1000u);++key)for(unsigned track=0;track<5;++track){verify(!bank->find(key,std::uint16_t(track)));++released_queries;}
        if(old)verify(!old->cleared()&&std::any_of(old->slots().begin(),old->slots().end(),[](const auto& block){return bool(block);}));
        current=released;++character_releases;
    }
    const auto reloaded=assets.overlay(1,npcs,*current);verify(!reloaded->character(3)->cleared()&&!reloaded->character(5)->cleared()&&current->character(3)->cleared()&&current->character(5)->cleared());
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    original_overlay(memory,1,npcs);compare_common(*reloaded,memory);compare_character(*reloaded,3,memory);compare_character(*reloaded,5,memory);
#endif
    for(auto character:std::array<std::uint8_t,2>{8,255}){refused=false;try{(void)assets.release_character(character,*current);}catch(const std::out_of_range&){refused=true;}verify(refused&&current->character(3)->cleared());}
    verify(world.close()==hm::Status::completed);
}
}
#ifdef REO_HUMANOID_MOTION_ORIGINAL
#include "humanoid_motion_loader_reference.inc"
#endif
int main(int argc,char** argv)try{
    contracts();if(argc==3)owned(argv[1],argv[2]);else verify(argc==1);
#ifdef REO_HUMANOID_MOTION_ORIGINAL
    original_humanoid_names();
    const auto original_checks=checks,original_bank_cases=bank_cases,original_calls=calls;
#else
    const auto original_checks=0,original_bank_cases=0,original_calls=0;
#endif
    std::cout<<"{\"scene_table_releases\":"<<scene_table_releases<<",\"initial_bank_cases\":"<<initial_bank_cases<<",\"initial_bank_queries\":"<<initial_bank_queries<<",\"initial_bank_overlays\":"<<initial_bank_overlays<<",\"scene_family_releases\":"<<scene_family_releases<<",\"base_releases\":"<<base_releases<<",\"native_checks\":"<<native_checks<<",\"original_checks\":"<<original_checks<<",\"original_bank_cases\":"<<original_bank_cases<<",\"original_calls\":"<<original_calls<<",\"common_loads\":"<<common_loads<<",\"character_loads\":"<<character_loads<<",\"snapshot_cases\":"<<snapshot_cases<<",\"npc_bindings_cases\":"<<npc_bindings_cases<<",\"loader_name_cases\":"<<loader_name_cases<<",\"character_releases\":"<<character_releases<<",\"released_queries\":"<<released_queries<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
