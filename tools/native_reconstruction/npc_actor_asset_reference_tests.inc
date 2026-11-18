namespace {std::string original_path;unsigned original_reads{};}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    if(context->pc==0x1aa740){sub_001AA740_0x1aa740(memory,context,runtime);return;}
    if(context->pc==0x1cd710){sub_001CD710_0x1cd710(memory,context,runtime);return;}
    if(context->pc==0x1cd340){sub_001CD340_0x1cd340(memory,context,runtime);return;}
    if(context->pc==0x10a830){
        const auto format=reinterpret_cast<const char*>(memory+GPR_U32(context,5));
        const auto result=std::string_view(format).starts_with("%s%s")?
            std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),128,format,reinterpret_cast<const char*>(memory+GPR_U32(context,6)),reinterpret_cast<const char*>(memory+GPR_U32(context,7)),int(GPR_U32(context,8))):
            std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),128,format,reinterpret_cast<const char*>(memory+GPR_U32(context,6)),int(GPR_U32(context,7)),int(GPR_U32(context,8)));
        check(result>0&&result<128);SET_GPR_S32(context,2,result);
    }else if(context->pc==0x1aa480){
        original_path=reinterpret_cast<const char*>(memory+GPR_U32(context,4));++original_reads;SET_GPR_S32(context,2,0);
    }else throw std::runtime_error("Undeclared NPC filename port "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
void original_auxiliary_names(){
    std::vector<std::uint8_t> memory(0x2000000);owned_auxiliary_name_formats(memory.data());
    // Resident1D0800 narrows model ID to8bits and picks the slot namespace.
    // Execute the complete1CD710/1CD340 selector/formatter independently.
    for(unsigned identity=0;identity<65536;++identity)for(unsigned model_class:{0u,1u,2u,255u}){
        R5900Context context;PS2Runtime runtime;context.pc=0x1cd710;
        SET_GPR_U32(&context,4,(model_class==1?0x1600u:0x1400u)+8u*(identity%10));
        SET_GPR_U32(&context,5,std::uint8_t(identity));SET_GPR_U32(&context,6,1);SET_GPR_U32(&context,7,0);
        SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
        const auto path=std::string(reinterpret_cast<const char*>(memory.data()+GPR_U32(&context,2)))+".NBD";
        check(path=="DATA\\ROM\\MODEL\\NPC\\"+w::ActorAssets::npc_model_name(std::uint16_t(identity),std::uint8_t(model_class)));++auxiliary_names;
    }
}
void original_names(){
    std::vector<std::uint8_t> memory(0x2000000);owned_npc_name_formats(memory.data());constexpr unsigned actor=0x70000;
    const auto compare=[&](std::uint16_t variant,std::uint8_t definition,std::uint8_t character){
        memory[actor+3]=0;memory[actor+0x54d]=definition;memory[actor+0xb98]=character;transform_write(memory.data(),actor+0xbb4,variant);
        original_reads=0;original_path.clear();R5900Context context;PS2Runtime runtime;context.pc=0x1aa740;SET_GPR_U32(&context,4,3);SET_GPR_U32(&context,5,actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&original_reads==1);
        const auto native=w::ActorAssets::substituted_model_name(variant,definition,character);const auto prefix=definition==1?"COMMON\\PL\\":"COMMON\\NPC\\";
        check(original_path==std::string(prefix)+native);++name_cases;
    };
    for(unsigned variant=1;variant<65536;++variant)compare(std::uint16_t(variant),std::array<std::uint8_t,4>{0,1,2,255}[variant%4],std::uint8_t(variant*19));
    for(unsigned character=0;character<256;++character)for(unsigned variant:{1u,10u,11u,129u,65535u})compare(std::uint16_t(variant),1,std::uint8_t(character));
}
void original_primary_names(){
    std::vector<std::uint8_t> memory(0x2000000);owned_npc_name_formats(memory.data());constexpr unsigned actor=0x70000,work=0x80000;
    transform_write(memory.data(),actor+0x34,work);transform_write(memory.data(),actor+0xbb4,std::uint16_t(0));
    const auto compare=[&](std::uint8_t character,std::uint8_t appearance,std::uint8_t model_class,std::uint8_t slot){
        memory[actor+3]=slot;memory[actor+0xb98]=character;memory[actor+0xbbc]=appearance;memory[actor+0x54d]=model_class;
        transform_write(memory.data(),work+0x1460,0x12345678u);transform_write(memory.data(),work+0x1464,0xabcdef01u);
        original_reads=0;original_path.clear();R5900Context context;PS2Runtime runtime;context.pc=0x1aa740;
        SET_GPR_U32(&context,4,slot);SET_GPR_U32(&context,5,actor);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&original_reads==1&&GPR_U32(&context,29)==0x1f00000);
        check(original_path=="COMMON\\PL\\"+w::ActorAssets::primary_model_name(character,appearance,model_class));
        check(transform_read<std::uint32_t>(memory.data(),work+0x1460)==(slot>=20?0u:0x12345678u)&&transform_read<std::uint32_t>(memory.data(),work+0x1464)==(slot>=20?0u:0xabcdef01u));++primary_names;
    };
    for(unsigned character=0;character<256;++character)for(unsigned appearance=0;appearance<256;++appearance)for(unsigned model_class:{0u,1u,2u,255u})compare(std::uint8_t(character),std::uint8_t(appearance),std::uint8_t(model_class),std::uint8_t(appearance));
    for(unsigned model_class=0;model_class<256;++model_class)for(unsigned character=0;character<256;++character)compare(std::uint8_t(character),std::uint8_t(character*13),std::uint8_t(model_class),std::uint8_t(model_class));
}
