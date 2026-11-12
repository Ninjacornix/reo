#include "dialogue_conditions.hpp"
#include "dialogue_inventory_traits.hpp"
#include "dialogue_partner_characters.hpp"
#include "primary_actor_records.hpp"
#include "auxiliary_actors.hpp"
#include <iostream>
#include <stdexcept>
namespace w=reo::native::gameplay_world;
namespace s=reo::native::gameplay_scenario;
namespace {
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Dialogue response contract "+std::to_string(checks));}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
}
int main()try{
    w::World world(profile(),std::make_shared<w::Session>());
    check(!w::Actor{}.speech.partner_characters);
    const auto initialized=w::initialize_primary_records(world);
    check(initialized.status==w::PrimaryRecordsStatus::completed&&initialized.initialized==8);
    const auto id=world.identity(0);auto actor=world.resolve(id);
    check(actor&&actor->slot==0&&actor->speech.partner_characters==std::array<std::int8_t,4>{});
    w::DialoguePool pool(world);
    check(pool.advance_flag_durations()==w::DialogueStatus::unavailable);
    check(w::evaluate_dialogue_condition(world,&pool,{255,0,0,0},{}).value==1);
    check(w::evaluate_dialogue_condition(world,&pool,{254,0,0,0},{}).value==0);
    check(w::evaluate_dialogue_condition(world,&pool,{0,0,0,0},id).status==w::DialogueStatus::unavailable);
    world.session().primary_population=8;
    check(pool.initialize_owned_state()==w::DialogueStatus::completed);
    check(pool.flag_duration(0)==0&&pool.advance_flag_durations()==w::DialogueStatus::completed&&pool.flag_duration(0)==0);
    check(w::evaluate_dialogue_condition(world,&pool,{0,0,0,0},id).value==1);
    check(w::evaluate_dialogue_condition(world,&pool,{15,0,0,0},id).status==w::DialogueStatus::unavailable);
    check(w::dialogue_inventory_trait(*actor,nullptr,nullptr,0)==false);
    actor->inventory.carried[0]=1;
    check(!w::dialogue_inventory_trait(*actor,nullptr,nullptr,0));
    check(w::dialogue_inventory_trait(*actor,nullptr,nullptr,255)==false);
    actor->inventory.storage[0]=2;
    check(w::dialogue_inventory_trait(*actor,nullptr,nullptr,5)==true);
    for(unsigned i=0;i<8;++i)world.primary(i)->character=std::uint8_t(i);
    const auto overflow=w::rebuild_dialogue_partner_characters(world,id);
    check(overflow.status==w::DialogueStatus::unsupported_profile&&overflow.written==4&&actor->speech.partner_characters==std::array<std::int8_t,4>{1,2,3,4});
    world.session().primary_population.reset();
    check(w::rebuild_dialogue_partner_characters(world,id).status==w::DialogueStatus::unavailable&&actor->speech.partner_characters==std::array<std::int8_t,4>{-1,-1,-1,-1});
    world.session().primary_population=3;
    check(w::rebuild_dialogue_partner_characters(world,id).written==2&&actor->speech.partner_characters==std::array<std::int8_t,4>{1,2,-1,-1});
    actor->speech.selection=w::SpeechSelection{0,1,0,0,0};
    const auto aux=world.auxiliary_actors().allocate();
    check(aux.status==w::AuxiliaryStatus::completed);
    world.resolve(aux.id)->active=false;
    check(w::evaluate_dialogue_condition(world,&pool,{12,0,0,1},id).status==w::DialogueStatus::unsupported_profile);
    check(world.close()==w::Status::completed);
    check(w::evaluate_dialogue_condition(world,&pool,{255,0,0,0},id).status==w::DialogueStatus::closed);
    check(w::rebuild_dialogue_partner_characters(world,id).status==w::DialogueStatus::closed);
    std::cout<<"Dialogue response contract passed "<<checks<<" checks\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
