// Complete1D1CC0 caller execution. File reads, sprintf and construction calls
// are declared observation ports; the native archive/parser/real-consumer
// checks run separately in this same executable. No original I/O is performed.
namespace {
unsigned loader_scenario{},loader_clip{},loader_mask{},loader_reads{},loader_builds{};
std::vector<unsigned> loader_destinations;
std::array<std::uint32_t,3> loader_banks{0x4bc810,0x4bbb80,0x4e8970};
std::array<std::string,3> expected_loader_paths;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    switch(context->pc){
    case 0x1d1cc0:sub_001D1CC0_0x1d1cc0(memory,context,runtime);return;
    case 0x10a830:{
        check(loader_reads<3&&GPR_U32(context,6)==loader_scenario&&GPR_U32(context,7)==loader_clip);
        const auto format=GPR_U32(context,5),output=GPR_U32(context,4);
        check(format==std::array<std::uint32_t,3>{0x256430,0x256460,0x256490}[loader_reads]);
        const auto n=std::snprintf(reinterpret_cast<char*>(memory+output),128,reinterpret_cast<const char*>(memory+format),int(loader_scenario),int(loader_clip));
        check(n>0&&n<128);SET_GPR_S32(context,2,n);break;
    }
    case 0x1cc8f0:{
        check(loader_reads<3&&memory[0x4bae0f]==0&&GPR_U32(context,5)==0x380000&&GPR_U32(context,6)==1);
        check(std::string(reinterpret_cast<char*>(memory+GPR_U32(context,4)))==expected_loader_paths[loader_reads]);
        SET_GPR_S32(context,2,(loader_mask&(1u<<loader_reads))?128+loader_reads:0);
        ++loader_reads;break;
    }
    case 0x1d1960:{
        const auto index=loader_reads-1;
        check(loader_reads>0&&loader_reads<=3&&GPR_U32(context,4)==0x380000&&GPR_U32(context,5)==loader_banks[index]);
        check(GPR_U32(context,6)==128+index&&GPR_U32(context,7)==200&&GPR_U32(context,8)==0);
        loader_destinations.push_back(index);++loader_builds;break;
    }
    default:throw std::runtime_error("Undeclared original scripted loader port "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
void original_loader_routes(){
    std::vector<std::uint8_t> memory(0x600000);owned_loader_formats(memory.data());
    for(unsigned scenario:{0u,1u,41u,999u})for(unsigned clip:{0u,2u,30u,99u})for(unsigned mask=0;mask<8;++mask){
        loader_scenario=scenario;loader_clip=clip;loader_mask=mask;loader_reads=loader_builds=0;loader_destinations.clear();
        std::vector<unsigned> expected;
        for(unsigned kind=0;kind<3;++kind){
            std::array<char,128> text{};const auto prefix=kind==2?"hd":"d";
            std::snprintf(text.data(),text.size(),"data\\rom\\motion\\demo\\r%03u\\%s%02u%s.bin",scenario,prefix,clip,kind==1?"face":"");
            expected_loader_paths[kind]=text.data();if(mask&(1u<<kind))expected.push_back(kind);
        }
        transform_write(memory.data(),0x32440c,0x380000u);memory[0x4bae0f]=99;
        R5900Context context;PS2Runtime runtime;context.pc=0x1d1cc0;
        SET_GPR_U32(&context,4,scenario);SET_GPR_U32(&context,5,clip);
        SET_GPR_U32(&context,29,0x500000);SET_GPR_U32(&context,31,0xabcdef);
        original_transform_port(memory.data(),&context,&runtime);
        check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x500000&&memory[0x4bae0f]==0);
        check(loader_reads==3&&loader_builds==expected.size()&&loader_destinations==expected);++original_loader_cases;
    }
    check(original_loader_cases==128);
}
