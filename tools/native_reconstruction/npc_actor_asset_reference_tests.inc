namespace {std::string original_path;unsigned original_reads{};}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x1aa740){sub_001AA740_0x1aa740(memory,context,runtime);return;}
    if(context->pc==0x10a830){
        const auto result=std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),128,reinterpret_cast<const char*>(memory+GPR_U32(context,5)),reinterpret_cast<const char*>(memory+GPR_U32(context,6)),int(GPR_U32(context,7)));
        check(result>0&&result<128);SET_GPR_S32(context,2,result);
    }else if(context->pc==0x1aa480){
        original_path=reinterpret_cast<const char*>(memory+GPR_U32(context,4));++original_reads;SET_GPR_S32(context,2,0);
    }else throw std::runtime_error("Undeclared NPC filename port "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
void original_names(){
    std::vector<std::uint8_t> memory(0x2000000);owned_npc_name_formats(memory.data());constexpr unsigned actor=0x70000;
    const auto compare=[&](std::uint16_t variant,std::uint8_t definition,std::uint8_t character){
        memory[actor+3]=0;memory[actor+0x54d]=definition;memory[actor+0xb98]=character;transform_write(memory.data(),actor+0xbb4,variant);
        original_reads=0;original_path.clear();R5900Context context;PS2Runtime runtime;context.pc=0x1aa740;SET_GPR_U32(&context,4,3);SET_GPR_U32(&context,5,actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&original_reads==1);
        const auto native=w::ActorAssets::npc_model_name(variant,definition,character);const auto prefix=definition==1?"COMMON\\PL\\":"COMMON\\NPC\\";
        check(original_path==std::string(prefix)+native);++name_cases;
    };
    for(unsigned variant=1;variant<65536;++variant)compare(std::uint16_t(variant),std::array<std::uint8_t,4>{0,1,2,255}[variant%4],std::uint8_t(variant*19));
    for(unsigned character=0;character<256;++character)for(unsigned variant:{1u,10u,11u,129u,65535u})compare(std::uint16_t(variant),1,std::uint8_t(character));
}
