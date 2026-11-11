namespace {
bool humanoid_names_only{};
bool humanoid_scene_cleanup{};
std::vector<std::string> humanoid_original_reads;
}
std::string humanoid_original_identity(unsigned ordinal){
    const auto found=std::find_if(owned_motion.begin(),owned_motion.end(),[&](const auto& row){return row.member==ordinal;});
    if(found==owned_motion.end())throw std::runtime_error("Original motion block provenance unavailable");
    if(found->character==253||found->character==254)return "File1 ROM member "+std::to_string(ordinal)+": motion/demo/r001/"+(found->character==253?"d02.bin":"hd02.bin");
    return "File1 ROM member "+std::to_string(ordinal)+": motion/player/"+found->name;
}
bool humanoid_loader_original_port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    if(humanoid_scene_cleanup){
        const auto at=context->pc;
        if(at==0x107c68){
            const auto destination=GPR_U32(context,4),length=GPR_U32(context,6);
            bool known=destination==0x600000&&length==0x10000&&GPR_U32(context,31)==0x5ed3b4;
            for(unsigned index=0;index<10;++index){
                const auto bank=index==0?0x4e8970u:index==1?0x4e6a20u:0x4d7000u+0x1f44*(index-2);
                for(unsigned family=0;family<3;++family){
                    const auto profile=0x234410+8*family;
                    known|=GPR_U32(context,31)==0x1b1c74&&destination==bank+0xfa4+2*get<std::uint16_t>(memory,profile)&&length==2u*get<std::uint16_t>(memory,profile+2);
                }
            }
            verify(known&&GPR_U32(context,5)==0);return false;
        }
        if(at==0x1cd120){verify(GPR_U32(context,4)==12||GPR_U32(context,4)==16);context->pc=GPR_U32(context,31);return true;}
        if(at==0x1b14a0){verify(GPR_U32(context,4)==raw_base+0x2ff000);context->pc=GPR_U32(context,31);return true;}
        if(at==0x6519a0||at==0x5ebb10||at==0x67c250){verify(GPR_U32(context,4)==0);context->pc=GPR_U32(context,31);return true;}
        if(at==0x5f1290||at==0x1b2c30){context->pc=GPR_U32(context,31);return true;}
    }
    const auto address=context->pc;
    if(humanoid_names_only&&(address==0x1d19d0||address==0x1d1940)){
        verify(address==0x1d19d0?GPR_U32(context,6)<=1:GPR_U32(context,7)==1);
    }else if(address==0x1b2ce0){
        // Pair-cursor work reset is observed.1B1DF0 and its partial family
        // release bodies now execute completely instead of being ported away.
    }else if(address==0x10a830){
        const auto result=std::snprintf(reinterpret_cast<char*>(memory+GPR_U32(context,4)),128,reinterpret_cast<const char*>(memory+GPR_U32(context,5)),int(GPR_U32(context,6)),int(GPR_U32(context,7)));
        verify(result>0&&result<128);SET_GPR_S32(context,2,result);
    }else if(address==0x1cc8f0){
        const auto path=std::string(reinterpret_cast<const char*>(memory+GPR_U32(context,4)));
        const bool player=path.starts_with("data\\rom\\motion\\player\\"),demo=path.starts_with("data\\rom\\motion\\demo\\");
        verify((player||demo)&&GPR_U32(context,5)==raw_base&&GPR_U32(context,6)==(player?0x20001u:1u));
        humanoid_original_reads.push_back(path);
        if(humanoid_names_only)SET_GPR_U32(context,2,0);
        else{
            auto name=path.substr(path.find_last_of('\\')+1);for(auto& character:name)if(character>='a'&&character<='z')character-=char('a'-'A');
            const auto row=std::find_if(owned_motion.begin(),owned_motion.end(),[&](const auto& entry){return entry.name==name&&((player&&entry.character<=7)||(player&&entry.character==255)||(demo&&path.starts_with("data\\rom\\motion\\demo\\r001\\")&&entry.character>=253&&entry.character<=254));});
            if(row==owned_motion.end()){verify(demo);SET_GPR_U32(context,2,0);}
            else{verify(row->bytes.size()<0x400000);std::memcpy(memory+raw_base,row->bytes.data(),row->bytes.size());current_asset=row->member;SET_GPR_U32(context,2,row->bytes.size());}
        }
    }else return false;
    context->pc=GPR_U32(context,31);return true;
}
void original_scene_motion_cleanup(std::vector<std::uint8_t>& memory){
    put(memory.data(),0x324444,0x600000u);put(memory.data(),raw_base+0x2ff808,0u);
    put(memory.data(),0x4baea0,0u);put(memory.data(),0x38edcc,0u);put(memory.data(),0x38edd4,0u);
    put(memory.data(),0x38ecdc,0u);put(memory.data(),0x38ecb8,std::int16_t(0));put(memory.data(),0x38ecb6,std::int16_t(0));put(memory.data(),0x324200,std::int16_t(0));
    humanoid_scene_cleanup=true;struct Reset{~Reset(){humanoid_scene_cleanup=false;}}reset;
    call(memory.data(),0x5ed340,0);
}
void original_humanoid_names(){
    std::vector<std::uint8_t> memory(0x2000000);constants(memory.data());owned_humanoid_formats(memory.data());put(memory.data(),0x32440c,raw_base);humanoid_names_only=true;
    for(unsigned flag=0;flag<256;++flag){
        memory[0x4bae0f]=std::uint8_t(flag);humanoid_original_reads.clear();call(memory.data(),0x1d1a80,0);
        verify(humanoid_original_reads.size()==unsigned(flag==0)&&memory[0x4bae0f]==(flag?flag:1));
        if(flag==0)verify(humanoid_original_reads[0]=="data\\rom\\motion\\player\\pc_000.bin");
        ++loader_name_cases;
    }
    for(unsigned index=0;index<65536;++index){
        humanoid_original_reads.clear();original_overlay(memory,index,{});std::array<char,96> expected{};
        std::snprintf(expected.data(),expected.size(),"data\\rom\\motion\\player\\pc_%03u.bin",index);
        verify(humanoid_original_reads.size()==1&&humanoid_original_reads[0]==expected.data());++loader_name_cases;
    }
    for(unsigned character=0;character<256;++character){
        const std::uint8_t selected=std::uint8_t(character);humanoid_original_reads.clear();original_overlay(memory,0,std::span(&selected,1));std::array<char,96> expected{};
        std::snprintf(expected.data(),expected.size(),"data\\rom\\motion\\player\\pl%02u_pc_000.bin",character);
        verify(humanoid_original_reads.size()==2&&humanoid_original_reads[0]=="data\\rom\\motion\\player\\pc_000.bin"&&humanoid_original_reads[1]==expected.data());++loader_name_cases;
    }
    humanoid_names_only=false;
}
