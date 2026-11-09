unsigned fog_imports{},fog_selections{},fog_frames{},fog_companions{};
void export_fog(std::uint8_t* memory,const s::FogState& state,std::uint32_t bias=0){
    put(memory,0x324010 - bias,state.near_distance);put(memory,0x324014 - bias,state.far_distance);
    std::memcpy(memory+0x324018 - bias,state.color.data(),3);std::memcpy(memory+0x32407c - bias,state.tail_color.data(),3);
    std::memcpy(memory+0x32408c - bias,state.secondary_colors[0].data(),4);std::memcpy(memory+0x324098 - bias,state.secondary_colors[1].data(),4);
    put(memory,0x3240cc - bias,state.parameters[0]);put(memory,0x3240ce - bias,state.parameters[1]);put(memory,0x3240c0 - bias,state.direction);
    std::memcpy(memory+0x323edc - bias,state.vectors[0].data(),16);std::memcpy(memory+0x323efc - bias,state.vectors[1].data(),16);std::memcpy(memory+0x323eec - bias,state.vectors[2].data(),16);
    put(memory,0x32404c - bias,state.words[0]);put(memory,0x324050 - bias,state.words[1]);memory[0x3240bf - bias]=state.option;memory[0x3240bd - bias]=std::bit_cast<std::uint8_t>(state.selected);std::memcpy(memory+0x3240d0 - bias,state.flash.data(),4);
}
void compare_fog_state(const std::uint8_t* memory,const s::Fog& fog){
    std::array<std::uint8_t,0x400> copy;std::memcpy(copy.data(),memory+0x323e00,copy.size());export_fog(copy.data(),fog.state(),0x323e00);if(std::memcmp(copy.data(),memory+0x323e00,copy.size())!=0)for(unsigned i=0;i<copy.size();++i)if(copy[i]!=memory[0x323e00+i])std::cerr<<"fog byte "<<std::hex<<0x323e00+i<<std::dec<<" native="<<unsigned(copy[i])<<" original="<<unsigned(memory[0x323e00+i])<<'\n';check(std::memcmp(copy.data(),memory+0x323e00,copy.size())==0);
}
void project_pulse(std::uint8_t* memory,std::uint32_t at,const s::FogPulse& work){
    memory[at+8]=work.phase;put(memory,at+0xc,work.counter);put(memory,at+0xe,work.duration);put(memory,at+0x10,work.delay);
    put(memory,at+0x44,work.saved_near);put(memory,at+0x48,work.saved_far);put(memory,at+0xa8,work.last_near);put(memory,at+0xac,work.last_far);
    put(memory,at+0xc0,work.velocity);put(memory,at+0xcc,work.accumulator);put(memory,at+0xd8,work.near_step);put(memory,at+0xdc,work.far_step);
}
void compare_pulse(const std::uint8_t* memory,std::uint32_t at,const s::FogPulse& work){
    std::array<std::uint8_t,0x250> copy;std::memcpy(copy.data(),memory+at,copy.size());project_pulse(copy.data(),0,work);if(std::memcmp(copy.data(),memory+at,copy.size())!=0)for(unsigned i=0;i<copy.size();++i)if(copy[i]!=memory[at+i])std::cerr<<"pulse byte "<<std::hex<<i<<std::dec<<" native="<<unsigned(copy[i])<<" original="<<unsigned(memory[at+i])<<'\n';check(std::memcmp(copy.data(),memory+at,copy.size())==0);
}
std::vector<std::vector<std::byte>> fog_assets(const char* path){
    std::ifstream source(path,std::ios::binary);std::uint32_t count{};source.read(reinterpret_cast<char*>(&count),4);check(count==229);std::vector<std::vector<std::byte>> result;
    for(unsigned i=0;i<count;++i){std::uint32_t bytes{};source.read(reinterpret_cast<char*>(&bytes),4);check(bytes>=8&&bytes<=4096);result.emplace_back(bytes);source.read(reinterpret_cast<char*>(result.back().data()),bytes);check(bool(source));}return result;
}
s::FogState initial_fog(unsigned seed){
    s::FogState state;state.near_distance=50+float(seed%31);state.far_distance=200+float(seed%59);state.color={91,82,73};state.tail_color={64,55,46};state.selected=-1;state.direction={.5f,.25f,-.75f};state.flash={7,6,5,4};state.words={0x12345678,0xabcdef01};
    for(unsigned i=0;i<3;++i)for(unsigned j=0;j<4;++j)state.vectors[i][j]=float(int(seed%7)+int(i*11+j)-30)/8;
    return state;
}
void compare_fog(std::uint8_t* memory,const std::vector<std::vector<std::byte>>& effect_corpus,const char* path){
    const auto assets=fog_assets(path);
    for(unsigned asset=0;asset<assets.size();++asset)for(unsigned cached:{0u,1u,255u}){
        general_context="fogasset="+std::to_string(asset)+" cache="+std::to_string(cached);std::fill_n(memory,0x2000000,0);owned_constants(memory);owned_math_constants(memory);const auto identity=m::identity();std::memcpy(memory+0x294e00,identity.data(),64);
        auto initial=initial_fog(asset);initial.selected=std::bit_cast<std::int8_t>(std::uint8_t(cached));s::Fog fog(initial);export_fog(memory,initial);
        std::memcpy(memory+0x100000,assets[asset].data(),assets[asset].size());call(memory,0x6b23e0,{0x100000});const auto version=get<std::uint32_t>(memory,0x100000);check(fog.import_fog(assets[asset])==(version==2?s::FogStatus::completed:s::FogStatus::unsupported_version));compare_fog_state(memory,fog);++fog_imports;
        for(unsigned index=0;index<256;++index){call(memory,0x6b2200,{index});check(fog.select(std::uint8_t(index))==s::FogStatus::completed);compare_fog_state(memory,fog);++fog_selections;}
    }
    // Full654D90 includes the actual final6B2200 restore and allocator retirement.
    for(unsigned profile=0;profile<32;++profile){
        general_context="fogpulse="+std::to_string(profile);std::fill_n(memory,0x2000000,0);owned_constants(memory);owned_math_constants(memory);put(memory,0x324444,child_pool);call(memory,0x651850);const auto identity=m::identity();std::memcpy(memory+0x294e00,identity.data(),64);
        const auto initial=initial_fog(profile);s::Fog fog(initial);export_fog(memory,initial);std::memcpy(memory+0x100000,assets[0].data(),assets[0].size());call(memory,0x6b23e0,{0x100000});check(fog.import_fog(assets[0])==s::FogStatus::completed);
        const auto result=call(memory,0x651a30,{0,0,1});const auto at=GPR_U32(&result,2);check(at!=0);memory[at]=1;memory[at+3]=0x1d;
        s::FogPulse work;if(profile&1){work.phase=10;work.accumulator={12,18,24};}project_pulse(memory,at,work);
        for(unsigned tick=0;tick<300;++tick){
            if(tick==11&&(profile&2)){work.phase=10;memory[at+8]=10;}
            if(tick==23&&(profile&4)){fog.state().near_distance=fog.state().near_distance+123.5f;fog.state().far_distance=fog.state().far_distance-17.25f;put(memory,0x324010,fog.state().near_distance);put(memory,0x324014,fog.state().far_distance);}
            if(tick==28&&(profile&8)){fog.state().flash[3]=128;memory[0x3240d3]=128;}
            call(memory,0x654d90,{at});const auto step=fog.advance(work);check(step.status==s::FogStatus::completed);compare_fog_state(memory,fog);++fog_frames;
            check(step.retire==(memory[at]==0));if(step.retire)break;compare_pulse(memory,at,work);check(tick+1<300);
        }
    }
    // The same168 work slots contain fog companions and resource visuals.
    auto bank=e::EffectBank::import(effect_corpus[0],effect_corpus[1]);
    for(unsigned occupied:{0u,167u,168u}){
        general_context="sharedfogcapacity="+std::to_string(occupied);s::Fog fog(initial_fog(1));check(fog.import_fog(assets[0])==s::FogStatus::completed);reo::native::gameplay_session::Random random;e::PeriodicVisuals owner(bank,random,fog);
        for(unsigned i=0;i<occupied;++i)check(owner.emit({36,{}}).status==s::EmissionStatus::completed);
        const auto status=owner.refresh_companion();check(status==(occupied==168?e::WorkStatus::pool_full:e::WorkStatus::completed));check(owner.size()==occupied+(occupied==168?0:1));
        if(occupied!=168){check(owner.refresh_companion()==e::WorkStatus::completed);check(owner.size()==occupied+1);++fog_companions;}
        owner.close();check(owner.refresh_companion()==e::WorkStatus::unavailable);
    }
    general_context.clear();
}
