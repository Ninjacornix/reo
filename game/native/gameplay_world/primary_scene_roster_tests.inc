namespace {
void owned_roster_world(){
    namespace s=reo::native::gameplay_scenario;
    for(unsigned population=0;population<=8;++population){
        g::World world(profile(),std::make_shared<g::Session>());world.session().primary_population=population;world.scenario=std::uint16_t(population%2?0x23:0x22);
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<g::Actor>();actor->slot=std::uint8_t(i);actor->character=std::uint8_t(i+17);actor->room=std::uint16_t(i%3?0x21:0x13);actor->status=i%4==3?0x20:0;check(world.spawn_primary(i,std::move(actor)).status==g::actors::EntityStatus::completed);}
        for(unsigned i=0;i<4;++i)check(world.session().actor_placements.queue(i,std::uint8_t(i%2?0x21:0x13),0));
        for(std::int32_t mode:{-1,0,4,5,6})for(unsigned preferred=0;preferred<=8;++preferred){
            for(unsigned i=0;i<8;++i)world.primary(i)->visible=true;
            s::CutsceneRosterState state;state.roster.eligible_count=7;state.preferred_one_based=preferred;
            for(unsigned i=0;i<8;++i){state.roster.characters[i]=std::uint8_t(101+i);state.source_slots[i]=std::uint8_t(51+i);state.source_statuses[i]=0x87654321+i;}
            const auto before=state;const auto result=s::CutsceneRosterPreparation::apply(world,state,mode);
            if(result!=s::CutsceneRosterStatus::completed){check(result==s::CutsceneRosterStatus::unavailable&&state.roster.characters==before.roster.characters&&state.roster.eligible_count==before.roster.eligible_count&&state.preferred_one_based==before.preferred_one_based);for(unsigned i=0;i<8;++i)check(world.primary(i)->visible);++roster_world_refusals;}
            else{check(state.roster.eligible_count<=8&&!world.busy());for(unsigned i=0;i<8;++i)check(world.primary(i)->visible==(i>=population));compare_roster_world(world,before,state,mode);++roster_world_cases;}
        }
    }
    g::World incomplete(profile(),std::make_shared<g::Session>());s::CutsceneRosterState state;state.roster.characters.fill(73);const auto before=state;
    check(s::CutsceneRosterPreparation::apply(incomplete,state,0)==s::CutsceneRosterStatus::unavailable&&state.roster.characters==before.roster.characters);++roster_world_refusals;
    incomplete.session().primary_population=1;incomplete.scenario=1;check(s::CutsceneRosterPreparation::apply(incomplete,state,0)==s::CutsceneRosterStatus::unavailable);++roster_world_refusals;
    check(incomplete.close()==g::Status::completed&&s::CutsceneRosterPreparation::apply(incomplete,state,0)==s::CutsceneRosterStatus::closed);++roster_world_refusals;
}
}
