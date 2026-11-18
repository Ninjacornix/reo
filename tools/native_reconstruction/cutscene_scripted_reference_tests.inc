// Full5F0610 body, restricted to kind2/terminal/ignored headers. The two
// primary setup calls and6BA5C0 are declared observations. Native real asset
// creation and Update-track binding run separately in this executable.
namespace {
std::vector<u::ScriptedActorRequest> requested;
std::vector<unsigned> setup_calls;
std::uint32_t reference_actor(unsigned ordinal){return 0x900000+ordinal*0x1000;}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x5f0610){o2_005F0610_0x5f0610(memory,context,runtime);return;}
    if(context->pc==0x5f0dc0||context->pc==0x5f0c00){setup_calls.push_back(context->pc);}
    else if(context->pc==0x6ba5c0){
        requested.push_back({GPR_U32(context,4),GPR_U32(context,5),GPR_U32(context,6),GPR_U32(context,7)});
        const auto actor=reference_actor(unsigned(requested.size()-1));std::memset(memory+actor,0,0x1000);
        for(unsigned axis=0;axis<3;++axis)transform_write(memory,actor+0xb4+4*axis,float(axis+2));
        SET_GPR_U32(context,2,actor);
    }else throw std::runtime_error("Undeclared cutscene construction port "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
void original_requests(){
    std::vector<std::uint8_t> memory(0x2000000);
    const auto compare=[&](std::span<const Header> headers){
        requested.clear();setup_calls.clear();std::memset(memory.data()+0x38ec00,0xa5,0x1700);
        transform_write(memory.data(),0x38ecb6,std::int16_t(headers.size()));transform_write(memory.data(),0x38ecb8,std::int16_t(0));
        for(unsigned group=0;group<headers.size();++group){const auto at=0x800000+36*group;std::memcpy(memory.data()+at,headers[group].data(),36);transform_write(memory.data(),0x38fb60+32*group+28,at);}
        R5900Context context;PS2Runtime runtime;context.pc=0x5f0610;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);
        check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000&&setup_calls==std::vector<unsigned>({0x5f0dc0,0x5f0c00}));
        const auto native=u::cutscene_scripted_requests(*descriptor(headers));unsigned ordinal{};
        for(unsigned group=0;group<headers.size();++group){
            if(!native[group])continue;
            check(ordinal<requested.size());const auto& expected=requested[ordinal];const auto& request=*native[group];
            check(request.model_group==expected.model_group&&request.type==expected.type&&request.variant==expected.variant&&request.definition_index==expected.definition_index);
            const auto at=reference_actor(ordinal);check(memory[0x38edd8+0x8c*group]==2&&transform_read<std::uint32_t>(memory.data(),0x38eddc+0x8c*group)==at);
            std::uint32_t profile{},visibility{};std::memcpy(&profile,headers[group].data()+20,4);std::memcpy(&visibility,headers[group].data()+24,4);
            check(memory[at+0xba6]==1&&memory[at+0xb8b]==std::uint8_t(profile));
            for(unsigned axis=0;axis<3;++axis)check(transform_read<float>(memory.data(),at+0xb4+4*axis)==(std::uint8_t(profile)?float(axis+2):1.f));
            for(unsigned part=0;part<32;++part)check(memory[at+0xf4+part]==((visibility>>part)&1));
            ++ordinal;++original_spawns;
        }
        check(ordinal==requested.size()&&transform_read<std::uint32_t>(memory.data(),0x38ecd8)==ordinal);++original_cases;
    };
    for(unsigned code=0;code<65536;++code){
        Header header{};const auto kind=std::int16_t(2);const auto encoded=std::uint16_t(code),definition=std::uint16_t(code*17);const auto profile=code*73u,visibility=code*2654435761u;
        std::memcpy(header.data()+4,&kind,2);std::memcpy(header.data()+6,&encoded,2);std::memcpy(header.data()+10,&definition,2);std::memcpy(header.data()+20,&profile,4);std::memcpy(header.data()+24,&visibility,4);compare(std::span(&header,1));
    }
    for(unsigned seed=0;seed<=256;++seed){
        std::vector<Header> headers(seed%17);
        for(unsigned group=0;group<headers.size();++group){
            const auto kind=std::int16_t(group%4==0?-1:group%4==1?4:2),code=std::int16_t(5500+group),definition=std::int16_t(seed*31+group);const auto timestamp=std::uint16_t((seed+group)%7==0?65535:0);
            const auto profile=seed*73u,visibility=seed*2654435761u+group;
            std::memcpy(headers[group].data()+2,&timestamp,2);std::memcpy(headers[group].data()+4,&kind,2);std::memcpy(headers[group].data()+6,&code,2);std::memcpy(headers[group].data()+10,&definition,2);std::memcpy(headers[group].data()+20,&profile,4);std::memcpy(headers[group].data()+24,&visibility,4);
        }
        compare(headers);
    }
}
