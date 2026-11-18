std::array<float,13> lighting_words(const vm::LightDescriptor& d){
    std::array<float,13> a{};std::copy(d.vector0.begin(),d.vector0.end(),a.begin());std::copy(d.vector1.begin(),d.vector1.end(),a.begin()+4);
    std::copy(d.position.begin(),d.position.end(),a.begin()+8);a[11]=d.attenuation;a[12]=d.parameter;return a;
}
struct LightingFixture {
    vm::Lighting owner;
    reo::native::gameplay_lighting::Pool access{owner};
    LightingFixture(){std::vector<std::byte> b(24+4*(116+32*52));const auto write=[&](std::size_t at,std::uint32_t v){for(unsigned k=0;k<4;++k)b[at+k]=std::byte((v>>(8*k))&255);};write(0,4);write(4,4);
        for(unsigned i=0;i<4;++i){const auto at=24+i*(116+32*52);write(8+4*i,at);write(at,i+1);write(at+4,32);
            for(unsigned j=0;j<32;++j){for(unsigned k=0;k<13;++k)write(at+116+52*j+4*k,0x3f000000u+0x1000u*k+j*0x100u);
                if(j%3==0)write(at+116+52*j+44,0);
                if(j%7==0)write(at+116+52*j+44,0x7fc12345);}}
        check(owner.import_lig(b)==vm::LightingImport::completed);
    }
    void export_original(std::vector<std::uint8_t>& ram){ram[0x3240be]=std::uint8_t(owner.selected());
        for(std::size_t i=0;i<4;++i){const auto& b=owner.banks()[i];const auto at=0x3dc1e0+std::uint32_t(i*0x6f4);fixture_write(ram.data(),at,b.kind);fixture_write(ram.data(),at+2,b.count);
            const auto base=lighting_words(b.base);for(unsigned k=0;k<13;++k)fixture_write(ram.data(),at+4+4*k,std::bit_cast<std::uint32_t>(base[k]));
            for(std::size_t k=0;k<14;++k)fixture_write(ram.data(),at+56+std::uint32_t(4*k),b.environment_words[k]);
            for(std::size_t j=0;j<32;++j){const auto d=lighting_words(b.entries[j]);for(unsigned k=0;k<13;++k)fixture_write(ram.data(),at+112+std::uint32_t(j*52)+4*k,std::bit_cast<std::uint32_t>(d[k]));}}
    }
    void compare_original(const std::vector<std::uint8_t>& ram){check(std::uint8_t(owner.selected())==ram[0x3240be]);check(owner.primary_count()==ram[0x747538]);
        check(access.bound_to(owner)&&access.size()==owner.primary_count());
        const auto frame=access.snapshot();check(frame.size()==owner.primary_count());
        for(const auto& entry:frame){const auto slot=access.physical_slot(entry.id);check(bool(slot));const auto at=0x747540+56u**slot;const auto values=lighting_words(entry.value.descriptor);check(entry.value.active==ram[at]&&entry.value.tag==ram[at+1]&&entry.value.mode==ram[at+2]);for(unsigned k=0;k<13;++k){check(std::bit_cast<std::uint32_t>(values[k])==fixture_read<std::uint32_t>(ram.data(),at+4+4*k));}}
        for(std::size_t i=0;i<4;++i)check(owner.banks()[i].enabled_mask==fixture_read<std::uint32_t>(ram.data(),0x3dc1e0+std::uint32_t(i*0x6f4)+0x6f0));
        for(std::size_t i=0;i<64;++i){const auto at=0x747540+std::uint32_t(i*56);const auto& p=owner.primary()[i];check(p.active==ram[at]);check(p.tag==ram[at+1]);check(p.mode==ram[at+2]);check(p.reserved==ram[at+3]);const auto d=lighting_words(p.descriptor);
            for(unsigned k=0;k<13;++k)check(std::bit_cast<std::uint32_t>(d[k])==fixture_read<std::uint32_t>(ram.data(),at+4+4*k));}
        for(unsigned i=0;i<32;++i)check(fixture_read<std::uint32_t>(ram.data(),0x7474b0+4*i)==(owner.bindings()[i]==255?0u:0x747540u+56u*owner.bindings()[i]));
    }
};
