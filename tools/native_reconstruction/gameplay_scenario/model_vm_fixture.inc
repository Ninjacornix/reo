struct ModelFixture {
    vm::SceneModels owner;
    static vm::SceneModelState state(unsigned profile){
        vm::SceneModelState s;
        for(unsigned slot=0;slot<128;++slot){s.visibility[slot]=std::uint8_t(slot*17+profile);s.styles[slot]=0x12345678u^(slot*87654321u+profile);
            auto& m=s.poses[slot];m=reo::native::transform_math::identity();
            for(unsigned c=0;c<3;++c)for(unsigned r=0;r<3;++r)m[c][r]+=float(int((slot*13+c*7+r*3+profile)%21)-10)/32.0f;
            m[3][0]=float(slot+profile);m[3][1]=-float(slot);m[3][2]=float(profile)/4;
            for(unsigned i=0;i<4;++i)m[i][3]=std::bit_cast<float>(0x7fc00123u+slot+i);
        }
        return s;
    }
    static vm::RoomModelRemap remap(unsigned profile){vm::RoomModelRemap map;for(unsigned i=0;i<32;++i)map[i]=std::uint8_t((i*3+profile)%128);if(profile>=128)map[3]=255;return map;}
    explicit ModelFixture(unsigned profile=0):owner(state(profile),remap(profile)){}
    void export_original(std::vector<std::uint8_t>& ram){
        const auto& s=owner.state();std::memcpy(ram.data()+0x49f790,s.visibility.data(),128);std::memcpy(ram.data()+0x49f810,s.styles.data(),512);std::memcpy(ram.data()+0x49fa10,s.poses.data(),8192);
        fixture_write<std::uint32_t>(ram.data(),0x324424,0x680000);fixture_write<std::uint32_t>(ram.data(),0x688004,0x689000);std::memcpy(ram.data()+0x689000,owner.remap().data(),32);
        owned_model_constants(ram.data());const auto identity=reo::native::transform_math::identity();std::memcpy(ram.data()+0x294e00,identity.data(),64);
        check(std::memcmp(ram.data()+0x7174f0,vm::stock_model_transform_presets().data(),192)==0);
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        const auto& s=owner.state();check(std::memcmp(ram.data()+0x49f790,s.visibility.data(),128)==0);check(std::memcmp(ram.data()+0x49f810,s.styles.data(),512)==0);
        for(unsigned slot=0;slot<128;++slot)check(std::memcmp(ram.data()+0x49fa10+64*slot,s.poses[slot].data(),64)==0);
    }
};
