struct SequenceFixture {
    vm::SequenceControl owner;
    explicit SequenceFixture(unsigned profile){
        constexpr std::array<std::int8_t,6> counts{-128,-1,0,1,3,32};vm::SequenceControlState s;
        s.count=counts[profile%counts.size()];s.restart_byte=0x7f;s.condition_id=std::uint8_t(profile);s.selected_id=201;s.selection=0xbeef;s.phase=std::uint8_t(profile%8);s.mode=0xcc;
        s.parameter_a=0x1234;s.parameter_b=0x5678;s.fraction=std::bit_cast<float>(0x7fc12345u);
        for(std::size_t i=0;i<s.active.size();++i)s.active[i]=std::uint8_t(i*13+17);
        check(owner.restore(s));
    }
    void export_original(std::vector<std::uint8_t>& ram){const auto& s=owner.snapshot();
        ram[0x3dddb1]=std::uint8_t(s.count);ram[0x3dddb2]=s.restart_byte;ram[0x3dddb3]=s.condition_id;ram[0x3dddb5]=s.selected_id;fixture_write(ram.data(),0x3dddb6,s.selection);
        ram[0x3dddd5]=s.phase;ram[0x3dddd7]=s.mode;fixture_write(ram.data(),0x3ddddc,s.parameter_a);fixture_write(ram.data(),0x3dddde,s.parameter_b);fixture_write(ram.data(),0x3ddde0,std::bit_cast<std::uint32_t>(s.fraction));
        for(std::size_t i=0;i<s.active.size();++i)ram[0x3ddde4+i*0x198]=s.active[i];
    }
    void compare_original(const std::vector<std::uint8_t>& ram){const auto& s=owner.snapshot();
        check(ram[0x3dddb1]==std::uint8_t(s.count));check(ram[0x3dddb2]==s.restart_byte);check(ram[0x3dddb3]==s.condition_id);check(ram[0x3dddb5]==s.selected_id);check(fixture_read<std::uint16_t>(ram.data(),0x3dddb6)==s.selection);
        check(ram[0x3dddd5]==s.phase);check(ram[0x3dddd7]==s.mode);check(fixture_read<std::uint16_t>(ram.data(),0x3ddddc)==s.parameter_a);check(fixture_read<std::uint16_t>(ram.data(),0x3dddde)==s.parameter_b);check(fixture_read<std::uint32_t>(ram.data(),0x3ddde0)==std::bit_cast<std::uint32_t>(s.fraction));
        for(std::size_t i=0;i<s.active.size();++i)check(ram[0x3ddde4+i*0x198]==s.active[i]);
    }
};
