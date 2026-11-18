namespace {std::uint16_t original_statistic_random{};unsigned original_random_reads{};}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;
    switch(context->pc){
    case 0x669860:o2_00669860_0x669860(memory,context,runtime);return;
    case 0x603110:o2_00603110_0x603110(memory,context,runtime);return;
    case 0x6dd7f0:o2_006DD7F0_0x6dd7f0(memory,context,runtime);return;
    case 0x1aec80:check(GPR_U32(context,4)==0);SET_GPR_U32(context,2,original_statistic_random);++original_random_reads;break;
    default:throw std::runtime_error("Undeclared custom statistic port "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
namespace {
std::vector<std::uint8_t>& custom_memory(){static std::vector<std::uint8_t> memory=[](){std::vector<std::uint8_t> result(0x2000000);owned_primary_constants(result.data());return result;}();return memory;}
R5900Context invoke_custom(unsigned address,unsigned argument){
    R5900Context context;PS2Runtime runtime;context.pc=address;SET_GPR_U32(&context,4,argument);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);original_transform_port(custom_memory().data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);return context;
}
void compare_index(std::uint16_t identity,std::optional<std::size_t> index){
    const auto first=invoke_custom(0x603110,identity),second=invoke_custom(0x6dd7f0,identity);
    check(GPR_U32(&first,2)==index.value_or(999)&&GPR_U32(&second,2)==(index?unsigned(*index):0xffffffffu));
}
void compare_statistics(const g::Actor& actor,const g::Actor& before,std::uint16_t random){
    auto& memory=custom_memory();constexpr unsigned at=0x70000;const auto put=[&](unsigned offset,auto value){transform_write(memory.data(),at+offset,value);};
    put(0xbb4,before.model_variant);put(0x544,before.current);put(0x546,before.maximum);put(0xbbe,before.gauge_rate_variant);put(0xb99,before.motion_style);put(0xb9a,before.motion_subtype);put(0xbc0,before.primary_state->statistic_multiplier);put(0xbc4,before.contact.damage_scale);put(0xb4,before.model_scale);put(0xaa8,before.model_height_correction);
    original_statistic_random=random;original_random_reads=0;(void)invoke_custom(0x669860,at);
    check(original_random_reads==unsigned(before.model_variant!=0));
    check(actor.current==transform_read<std::int16_t>(memory.data(),at+0x544)&&actor.maximum==transform_read<std::int16_t>(memory.data(),at+0x546));
    check(actor.gauge_rate_variant==memory[at+0xbbe]&&actor.motion_style==memory[at+0xb99]&&actor.motion_subtype==memory[at+0xb9a]);
    check(std::memcmp(&actor.model_scale,memory.data()+at+0xb4,12)==0&&actor.model_height_correction==transform_read<float>(memory.data(),at+0xaa8));
    check(actor.primary_state->statistic_multiplier==transform_read<float>(memory.data(),at+0xbc0)&&actor.contact.damage_scale==transform_read<float>(memory.data(),at+0xbc4));
}
}
