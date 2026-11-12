unsigned auxiliary_light_allocations{},auxiliary_light_releases{},auxiliary_light_refusals{};
constexpr unsigned auxiliary_light_base=0x748350;
unsigned call_auxiliary_light(std::uint8_t* memory,unsigned pc,std::array<unsigned,2> args={}){
    R5900Context context;PS2Runtime runtime;context.pc=pc;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);
    for(unsigned i=0;i<args.size();++i)SET_GPR_U32(&context,4+i,args[i]);
    switch(pc){
    case 0x6b2bd0:o2_006B2BD0_0x6b2bd0(memory,&context,&runtime);break;
    case 0x6b2cc0:o2_006B2CC0_0x6b2cc0(memory,&context,&runtime);break;
    case 0x6b2c50:o2_006B2C50_0x6b2c50(memory,&context,&runtime);break;
    default:throw std::runtime_error("Invalid auxiliary pool test entry");
    }
    check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
void compare_auxiliary_lighting(std::uint8_t* memory){
    namespace s=reo::native::gameplay_scenario;
    s::Lighting lights;std::array<s::AuxiliaryLightHandle,64> ids;
    std::array<std::optional<s::NativeLight>,64> retained;
    std::memset(memory+auxiliary_light_base,0,64*56);memory[0x748340]=0;
    const auto compare=[&]{
        check(lights.auxiliary_count()==memory[0x748340]);
        for(unsigned i=0;i<64;++i){const auto& native=lights.auxiliary()[i];const auto raw=auxiliary_light_base+i*56;
            check(std::memcmp(&native,memory+raw,sizeof native)==0);
            const auto handle=lights.auxiliary_handle(std::uint8_t(i));check(bool(handle)==bool(native.active));
            if(handle)check(lights.auxiliary_slot(*handle)==i&&lights.light(*handle)->active);
        }
        check(lights.primary_count()==0);
    };
    const auto create=[&](unsigned n){
        l::Definition definition;auto* bytes=reinterpret_cast<std::byte*>(&definition);
        for(unsigned i=0;i<sizeof definition;++i)bytes[i]=std::byte(std::uint8_t(n*17u+i*31u));
        put(memory,0x100000,definition);const bool plain=n%5==0;const auto tag=std::uint8_t(plain?0:n*19u);
        const auto expected=call_auxiliary_light(memory,plain?0x6b2bd0:0x6b2cc0,{plain?0u:0x100000u,tag});
        const auto actual=lights.allocate_auxiliary(plain?nullptr:&definition,tag);check(bool(expected)==bool(actual));
        if(actual){const auto index=lights.auxiliary_slot(*actual);check(index&&expected==auxiliary_light_base+56**index);ids[*index]=*actual;retained[*index]=lights.light(*actual);++auxiliary_light_allocations;}
        else ++auxiliary_light_refusals;
        compare();
    };
    for(unsigned cycle=0;cycle<16;++cycle){
        for(unsigned i=0;i<64;++i)create(cycle*128+i);
        create(cycle*128+64);
        for(unsigned i=cycle%3;i<64;i+=3){
            check(call_auxiliary_light(memory,0x6b2c50,{auxiliary_light_base+56*i})==1&&lights.release(ids[i]));
            check(!lights.light(ids[i])&&retained[i]->active&&!lights.release(ids[i]));++auxiliary_light_releases;
            check(call_auxiliary_light(memory,0x6b2c50,{auxiliary_light_base+56*i})==0);
        }
        compare();const auto count=64u-lights.auxiliary_count();
        for(unsigned i=0;i<count;++i)create(cycle*128+65+i);
        for(unsigned i=0;i<64;++i)check(call_auxiliary_light(memory,0x6b2c50,{auxiliary_light_base+56*i})==1&&lights.release(ids[i]));
        compare();
    }
    create(7);const auto previous=ids[0];const auto snapshot=lights.light(previous);
    lights.reset_work();check(!lights.light(previous)&&snapshot->active&&lights.auxiliary_count()==0);
    std::memset(memory+auxiliary_light_base,0,64*56);memory[0x748340]=0;create(9);
    check(ids[0]!=previous&&!lights.light(previous));++auxiliary_light_refusals;
    s::Lighting foreign;const auto other=foreign.allocate_auxiliary(nullptr,0);check(other&&!lights.light(*other)&&!lights.release(*other));++auxiliary_light_refusals;
    l::Definition replacement;replacement.parameter=123;check(lights.replace(ids[0],replacement));
    put(memory,auxiliary_light_base+4,replacement);compare();
    check(!lights.replace(previous,replacement));++auxiliary_light_refusals;
    check(call_auxiliary_light(memory,0x6b2c50,{0})==0&&!lights.release(s::AuxiliaryLightHandle{}));++auxiliary_light_refusals;
}
