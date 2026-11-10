struct ActorFixture {
    std::shared_ptr<reo::native::gameplay_world::Session> session=std::make_shared<reo::native::gameplay_world::Session>();
    reo::native::gameplay_world::World world;
    vm::ActionChoices choices;
    static auto profile(){reo::native::gameplay_world::Profile p;p.layouts.push_back({});return p;}
    explicit ActorFixture(unsigned profile=0,std::uint8_t selected=0,bool offline=false):world(ActorFixture::profile(),session){
        world.mode=offline?0:std::uint8_t(profile%3+1);world.selected_actor=selected;
        std::array<std::uint8_t,128> variants;for(unsigned i=0;i<variants.size();++i)variants[i]=std::uint8_t(i*17+profile);session->room_variants.restore(variants);
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<reo::native::gameplay_world::Actor>();
            actor->category=std::uint8_t((profile/4)%3);actor->slot=std::uint8_t((profile/12+i)%8);actor->character=std::uint8_t((profile/3+i)%9);
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);
        }
        session->random.restore({0x1234,0xabcd,std::uint8_t(profile*11)});
        vm::ActionChoiceState state;state.table_row=std::uint8_t(profile%4);state.count=std::uint8_t((profile/4)%10);
        for(unsigned i=0;i<8;++i)state.used[i]=std::uint16_t(i+1);
        check(choices.restore(state));
    }
    void export_original(std::vector<std::uint8_t>& ram){
        for(unsigned i=0;i<128;++i)ram[0x4b9d20+i]=*session->room_variants.get(i);
        ram[0x3243f2]=world.mode;ram[0x4baded]=world.selected_actor;
        for(unsigned i=0;i<8;++i){const auto a=world.primary(i);const auto at=0x4a5c30+i*0x10e0u;ram[at+2]=a->category;ram[at+3]=a->slot;ram[at+0xb98]=a->character;}
        const auto state=session->random.state();fixture_write(ram.data(),0x3244b0,state.primary);fixture_write(ram.data(),0x3244b8,state.secondary);ram[0x2b8de8]=state.observed;
        const auto& c=choices.state();ram[0x4bae8a]=c.table_row;ram[0x4b9d19]=c.count;
        for(unsigned i=0;i<8;++i)fixture_write(ram.data(),0x4bac72+i*2,c.used[i]);
        constexpr std::array<std::uint8_t,16> table{0,0,1,1,0,0,1,1,2,2,3,3,2,2,3,3};std::memcpy(ram.data()+0x717820,table.data(),table.size());
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        for(unsigned i=0;i<128;++i)check(ram[0x4b9d20+i]==session->room_variants.get(i));
        check(ram[0x3243f2]==world.mode);check(ram[0x4baded]==world.selected_actor);
        for(unsigned i=0;i<8;++i){const auto a=world.primary(i);const auto at=0x4a5c30+i*0x10e0u;check(ram[at+2]==a->category);check(ram[at+3]==a->slot);check(ram[at+0xb98]==a->character);}
        const auto r=session->random.state();check(fixture_read<std::uint16_t>(ram.data(),0x3244b0)==r.primary);check(fixture_read<std::uint16_t>(ram.data(),0x3244b8)==r.secondary);check(ram[0x2b8de8]==r.observed);
        const auto& c=choices.state();check(ram[0x4bae8a]==c.table_row);check(ram[0x4b9d19]==c.count);
        for(unsigned i=0;i<8;++i)check(fixture_read<std::uint16_t>(ram.data(),0x4bac72+i*2)==c.used[i]);
    }
};
