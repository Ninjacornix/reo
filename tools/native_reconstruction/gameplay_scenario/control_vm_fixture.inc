constexpr std::uint32_t control_node=0x580000,control_stride=256;
std::vector<std::uint8_t> original_control_refreshes;
void export_control(std::uint8_t* ram,std::uint32_t at,const vm::SceneControl& record){
    fixture_write(ram,at+0x40,record.authored_id);ram[at+0x3c]=record.enabled;ram[at+0x32]=record.counter;
    std::visit([&](const auto& v){using T=std::decay_t<decltype(v)>;
        if constexpr(std::is_same_v<T,vm::ControlTypeZero>){ram[at+0x30]=0;if(v.destination){fixture_write(ram,at+0x44,v.destination->room);fixture_write(ram,at+0x48,v.destination->edge);}fixture_write(ram,at+0x6c,v.parameter);fixture_write(ram,at+0x68,v.half_parameter);ram[at+0x72]=v.byte_parameter;ram[at+0x71]=v.refresh_parameter;}
        else if constexpr(std::is_same_v<T,vm::ControlTypeOne>){ram[at+0x30]=1;fixture_write(ram,at+0x86,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeTwo>){ram[at+0x30]=2;if(v.destination){fixture_write(ram,at+0x44,v.destination->room);fixture_write(ram,at+0x48,v.destination->edge);}fixture_write(ram,at+0x50,v.selector);fixture_write(ram,at+0x6c,v.parameter);fixture_write(ram,at+0x68,v.half_parameter);ram[at+0x72]=v.byte_parameter;ram[at+0x71]=v.refresh_parameter;}
        else if constexpr(std::is_same_v<T,vm::ControlTypeThree>){ram[at+0x30]=3;fixture_write(ram,at+0x44,v.mode);fixture_write(ram,at+0x58,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFour>){ram[at+0x30]=4;fixture_write(ram,at+0x64,v.mode);fixture_write(ram,at+0x44,v.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeFive>){ram[at+0x30]=5;fixture_write(ram,at+0x50,v.selector);fixture_write(ram,at+0x6a,v.duration);fixture_write(ram,at+0x6c,v.countdown);fixture_write(ram,at+0x74,v.completion);ram[at+0x58]=v.byte_parameter;fixture_write(ram,at+0x56,v.secondary_parameter);fixture_write(ram,at+0x52,v.reset_sentinel);ram[at+0x59]=v.reset_byte_a;ram[at+0x6e]=v.reset_byte_b;fixture_write(ram,at+0x44,v.position);fixture_write(ram,at+0x54,v.effect_parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeNine>){ram[at+0x30]=9;fixture_write(ram,at+0x44,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeThirteen>){ram[at+0x30]=13;fixture_write(ram,at+0x44,v.selector);fixture_write(ram,at+0x62,v.parameter);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeSix>){ram[at+0x30]=6;fixture_write(ram,at+0x54,v.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeSeven>){ram[at+0x30]=7;fixture_write(ram,at+0x70,v.selector);}
        else if constexpr(std::is_same_v<T,vm::ControlTypeEleven>)ram[at+0x30]=11;
        else ram[at+0x30]=v.type;
    },record.body);
}
struct ControlFixture final:vm::ControlEffects {
    vm::SceneControls owner;std::vector<vm::SceneControlId> ids;std::vector<std::uint8_t> refreshes;
    explicit ControlFixture(unsigned profile=0){
        const auto add=[&](vm::SceneControlBody body,std::uint32_t id=42){ids.push_back(*owner.append({id,0x80,std::move(body),std::uint8_t(profile*7)}));};
        add(vm::ControlTypeZero{1,2,3,4});add(vm::ControlTypeOne{5});add(vm::ControlTypeTwo{7,6,8,9,10});add(vm::ControlTypeTwo{0,6,8,9,10});
        for(unsigned i=0;i<5;++i)add(vm::ControlTypeThree{i,0xbeef});
        for(unsigned i=0;i<3;++i)add(vm::ControlTypeFour{i,i==2?42u:i});
        add(vm::ControlTypeFive{1,2,3,4,5,6,0x8172,0x91,0xa2,{1.25f,-9,17.5f},0xbeef});add(vm::ControlTypeNine{7});
        add(vm::ControlTypeThirteen{42,8},99);add(vm::ControlOther{17});add(vm::ControlTypeZero{8,9,10,11},43);
        add(vm::ControlTypeSix{42},99);add(vm::ControlTypeSeven{43},99);add(vm::ControlTypeEleven{},43);
        add(vm::ControlTypeFive{8,7,6,5,4,3,2,1,0});
        owner.enabled((profile&1)==0);refreshes.reserve(128);
    }
    void reset(vm::SceneControls& controls,const vm::SceneControlId& id)noexcept override{if(controls.reset_five(id)!=vm::ControlStatus::completed)std::terminate();}
    void refresh(vm::SceneControls&,const vm::SceneControlId&,std::uint8_t id)noexcept override{refreshes.push_back(id);}
    void export_original(std::vector<std::uint8_t>& ram){fixture_write<std::int16_t>(ram.data(),0x3b5150,owner.enabled()?-1:128);fixture_write(ram.data(),0x3b5160,control_node);
        for(std::size_t i=0;i<ids.size();++i){const auto at=control_node+std::uint32_t(i)*control_stride;std::fill(ram.begin()+at,ram.begin()+at+control_stride,0xa5);export_control(ram.data(),at,*owner.get(ids[i]));fixture_write<std::uint32_t>(ram.data(),at+0x28,i+1<ids.size()?at+control_stride:0);}
        original_control_refreshes.clear();original_control_refreshes.reserve(128);
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        std::array<std::uint8_t,256> projected;
        for(std::size_t i=0;i<ids.size();++i){const auto at=control_node+std::uint32_t(i)*control_stride;
            // Export typed fields into a bounded comparison copy; untouched
            // bytes and links retain the original byte guards.
            std::copy(ram.begin()+at,ram.begin()+at+control_stride,projected.begin());
            export_control(projected.data(),0,*owner.get(ids[i]));check(std::memcmp(projected.data(),ram.data()+at,control_stride)==0);
        }
        check(refreshes==original_control_refreshes);
    }
};
struct SavedControlFixture {
    vm::SavedControlRecords owner;
    SavedControlFixture(){
        std::vector<vm::SavedControl> records;
        for(unsigned type=0;type<16;++type)for(unsigned selector=0;selector<4;++selector)records.push_back({0x81,std::uint8_t(type),42,std::uint8_t(selector)});
        for(unsigned bank=0;bank<3;++bank)check(owner.restore(bank,records));
    }
    void export_original(std::vector<std::uint8_t>& ram){
        for(unsigned bank=0;bank<3;++bank){const auto at=0x780000u+bank*0x1000u;const auto records=owner.get(bank);
            fixture_write(ram.data(),0x83e5ec+bank*164u,at);fixture_write<std::int32_t>(ram.data(),0x83e5e8+bank*164u,std::int32_t(records.size()));
            for(std::size_t i=0;i<records.size();++i){ram[at+16*i]=records[i].enabled;ram[at+16*i+1]=records[i].type;ram[at+16*i+2]=records[i].authored_id;ram[at+16*i+3]=records[i].selector;}
        }
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        for(unsigned bank=0;bank<3;++bank){const auto at=0x780000u+bank*0x1000u;const auto records=owner.get(bank);
            for(std::size_t i=0;i<records.size();++i){check(ram[at+16*i]==records[i].enabled);check(ram[at+16*i+1]==records[i].type);check(ram[at+16*i+2]==records[i].authored_id);check(ram[at+16*i+3]==records[i].selector);}
        }
    }
};
