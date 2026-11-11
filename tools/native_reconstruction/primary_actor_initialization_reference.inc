namespace {
unsigned primary_constraint_calls{};
#ifdef REO_PRIMARY_CUSTOM_INITIALIZATION_ORIGINAL
std::uint16_t primary_custom_random{};unsigned primary_custom_random_reads{};
#endif
constexpr unsigned primary_reference_actor=0x70000;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;
    switch(context->pc){
    case 0x66a750:o2_0066A750_0x66a750(memory,context,runtime);return;
    case 0x663170:o2_00663170_0x663170(memory,context,runtime);return;
    case 0x65fab0:o2_0065FAB0_0x65fab0(memory,context,runtime);return;
    case 0x6efaf0:o2_006EFAF0_0x6efaf0(memory,context,runtime);return;
#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
    case 0x5f1f70:o2_005F1F70_0x5f1f70(memory,context,runtime);return;
    case 0x5b4d50:o2_005B4D50_0x5b4d50(memory,context,runtime);return;
#endif
#ifdef REO_PRIMARY_CUSTOM_INITIALIZATION_ORIGINAL
    case 0x669860:o2_00669860_0x669860(memory,context,runtime);return;
    case 0x1aec80:check(GPR_U32(context,4)==0);SET_GPR_U32(context,2,primary_custom_random);++primary_custom_random_reads;break;
#endif
    case 0x5d6850:check(GPR_U32(context,4)==primary_reference_actor);++primary_constraint_calls;break;
    default:throw std::runtime_error("Undeclared primary initialization port "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
namespace {
std::vector<std::uint8_t>& primary_reference_memory(){static std::vector<std::uint8_t> memory=[](){std::vector<std::uint8_t> result(0x2000000);owned_primary_constants(result.data());return result;}();return memory;}
#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
void export_primary_equipment(std::vector<std::uint8_t>& memory,const g::PrimaryEquipmentContext& context){
    for(unsigned slot=0;slot<256;++slot){const auto id=context.resources.slot(slot);const auto descriptor=id?context.resources.get(*id):std::nullopt;check(bool(descriptor));memory[0x3c5630+60*slot]=descriptor->active;memory[0x3c5630+60*slot+0x2b]=descriptor->template_index;}
    for(unsigned index=0;index<129;++index)std::memcpy(memory.data()+0x74bb50+24*index,context.templates.state().templates[index].encoded.data(),24);
}
void compare_saved_query(unsigned slot,std::int8_t action,const g::PrimaryEquipmentContext& equipment){
    auto& memory=primary_reference_memory();export_primary_equipment(memory,equipment);R5900Context context;PS2Runtime runtime;context.pc=0x5b4d50;SET_GPR_U32(&context,4,slot);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&std::int8_t(GPR_U32(&context,2))==action);
}
#endif
void compare_setter(const g::Actor& actor,unsigned character,unsigned model_class){
    static std::vector<std::uint8_t> memory(0x2000000);constexpr auto at=primary_reference_actor;memory[at+0xbbc]=99;memory[at+0x553]=0;
    R5900Context context;PS2Runtime runtime;context.pc=0x663170;SET_GPR_U32(&context,4,at);SET_GPR_U32(&context,5,character);SET_GPR_U32(&context,6,model_class);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&actor.character==memory[at+0xb98]&&actor.model_pose_class==memory[at+0x54d]&&actor.appearance_variant==memory[at+0xbbc]&&actor.movement_enabled==memory[at+0x553]);
}
void compare_original(g::World& world,const g::Actor& actor,const g::Actor& before,unsigned character,bool restore){
    auto& memory=primary_reference_memory();
    constexpr auto at=primary_reference_actor;std::fill_n(memory.data()+at,0x10e0,0);
    const auto put=[&](unsigned offset,auto value){transform_write(memory.data(),at+offset,value);};
    put(0,std::uint8_t(before.active));put(1,std::uint8_t(before.visible));put(2,before.category);put(3,before.slot);put(0xff0,before.ai_control);put(0xb98,before.character);put(0x54d,before.model_pose_class);put(0xbb4,before.model_variant);put(0xbbc,before.appearance_variant);
    put(0x544,before.current);put(0x546,before.maximum);put(0xba0,before.status);put(0xba4,before.auxiliary_status);put(0xb9b,before.class_marker);put(0xb9c,before.previous_motion_class);put(0x1e2,before.room);put(0x38,before.position);put(0x90,before.orientation);
    put(0xd94,before.saved_action_position);put(0xda0,before.saved_action_yaw);put(0xd8,before.local_impulse);put(0xe4,before.world_impulse);put(0x4e4,before.root_motion_delta);put(0xd92,before.pending_notice);put(0xd90,std::uint16_t(0x1234));
    put(0xb4,before.model_scale);put(0xaa8,before.model_height_correction);put(0xf0,before.motion_multiplier);
    put(0xc7c,before.selected_resource);put(0xca8,before.resource_action);
    const auto work=0x4ae330+0x1468u*before.slot;put(0x34,work);transform_write(memory.data(),work+0x812,before.model_asset->part_count());
    memory[0x4badf8]=std::bit_cast<std::uint8_t>(world.paused);memory[0x4badfb]=primary_reference_notification.value_or(restore?1:0);memory[0x3243d8]=world.session().exit_requested;memory[0x3166a0]=0;primary_constraint_calls=0;
#ifdef REO_PRIMARY_SAVED_INITIALIZATION_ORIGINAL
    if(world.session().primary_initialization_snapshot){
        memory[0x3166a0]=1;check(primary_saved_context!=nullptr);export_primary_equipment(memory,*primary_saved_context);
        const auto& rows=*world.session().primary_initialization_snapshot;
        for(unsigned slot=0;slot<rows.size();++slot){const auto base=0x31a2d8+0x10c*slot;transform_write(memory.data(),base+2,rows[slot].health);memory[base+5]=rows[slot].class_marker;memory[base+0x26]=rows[slot].selected_resource;}
    }
#endif
#ifdef REO_PRIMARY_CUSTOM_INITIALIZATION_ORIGINAL
    primary_custom_random=world.session().random.state().secondary;primary_custom_random_reads=0;
#endif
    R5900Context context;PS2Runtime runtime;context.pc=0x66a750;SET_GPR_U32(&context,4,at);SET_GPR_U32(&context,5,character);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0xabcdef);
    original_transform_port(memory.data(),&context,&runtime);check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x1f00000);
#ifdef REO_PRIMARY_CUSTOM_INITIALIZATION_ORIGINAL
    check(primary_custom_random_reads==unsigned(!restore&&before.model_variant!=0));
#endif
    check(actor.active==bool(memory[at])&&actor.visible==bool(memory[at+1])&&actor.category==memory[at+2]&&actor.slot==memory[at+3]&&actor.ai_control==memory[at+0xff0]&&actor.character==memory[at+0xb98]);
    check(actor.current==transform_read<std::int16_t>(memory.data(),at+0x544)&&actor.maximum==transform_read<std::int16_t>(memory.data(),at+0x546)&&actor.status==transform_read<std::uint32_t>(memory.data(),at+0xba0));
    check(actor.class_marker==memory[at+0xb9b]&&actor.previous_motion_class==memory[at+0xb9c]&&actor.auxiliary_status==transform_read<std::uint32_t>(memory.data(),at+0xba4));
    check(std::memcmp(&actor.position,memory.data()+at+0x38,12)==0&&std::memcmp(actor.orientation.data(),memory.data()+at+0x90,8)==0&&std::memcmp(&actor.root_motion_delta,memory.data()+at+0x4e4,12)==0);
    check(actor.pending_notice==transform_read<std::uint16_t>(memory.data(),at+0xd92)&&actor.room==transform_read<std::uint16_t>(memory.data(),at+0x1e2)&&actor.appearance_variant==memory[at+0xbbc]);
    check(actor.selected_resource==memory[at+0xc7c]&&actor.resource_action==transform_read<std::uint16_t>(memory.data(),at+0xca8));
    check(actor.color_fade&&actor.color_fade->rgba==transform_read<std::uint32_t>(memory.data(),at+0xce8)&&actor.color_fade->step==transform_read<std::uint32_t>(memory.data(),at+0xcec)&&actor.color_fade->updates_left==transform_read<std::uint32_t>(memory.data(),at+0xcf0));
    if(restore){check(primary_constraint_calls==unsigned(!world.session().exit_requested)&&bool(actor.constraints)==(bool(before.constraints)||!world.session().exit_requested));return;}
    check(primary_constraint_calls==1&&actor.contact.authored_id==memory[at+6]&&actor.primary_state->model_group==memory[at+0x30]);
    check(actor.motion_style==memory[at+0xb99]&&actor.motion_subtype==memory[at+0xb9a]&&std::memcmp(&actor.model_scale,memory.data()+at+0xb4,12)==0&&actor.model_height_correction==transform_read<float>(memory.data(),at+0xaa8));
    check(actor.primary_state->statistic_multiplier==transform_read<float>(memory.data(),at+0xbc0)&&actor.contact.damage_scale==transform_read<float>(memory.data(),at+0xbc4)&&std::memcmp(actor.primary_state->model_adjustment.data(),memory.data()+at+0xa8,12)==0);
    check(actor.animation->channel_count==memory[at+0x524]&&actor.motion_multiplier==transform_read<float>(memory.data(),at+0xf0)&&std::memcmp(&actor.local_impulse,memory.data()+at+0xd8,12)==0&&std::memcmp(&actor.world_impulse,memory.data()+at+0xe4,12)==0);
    check(actor.collision.body_priority==memory[at+0x199]&&actor.primary_state->initialization_marker==transform_read<std::uint16_t>(memory.data(),at+0xd90));
    check(std::memcmp(&actor.collision.local_center,memory.data()+at+0x1ac,12)==0&&actor.collision.radius==transform_read<float>(memory.data(),at+0x1b8)&&std::memcmp(&actor.collision.previous_local_center,memory.data()+at+0x1bc,12)==0&&actor.collision.previous_radius==transform_read<float>(memory.data(),at+0x1c8));
    const auto body=transform_read<std::uint32_t>(memory.data(),at+0x1a8);check(actor.collision.body_definition&&actor.collision.body_definition->radius==float(transform_read<std::int16_t>(memory.data(),body+2)));
    const auto shape=transform_read<std::uint32_t>(memory.data(),at+0xcb8);check(actor.collision.interpolation_target&&std::memcmp(&actor.collision.interpolation_target->center,memory.data()+shape,12)==0&&actor.collision.interpolation_target->radius==transform_read<float>(memory.data(),shape+12));
    for(unsigned part=0;part<actor.primary_state->part_visibility.size();++part)check(actor.primary_state->part_visibility[part]==memory[at+0xf4+part]);
    const auto& hits=g::primary_actor_default(std::uint8_t(character)).hit_regions;const auto hit_at=transform_read<std::uint32_t>(memory.data(),at+0x1d8);
    for(unsigned i=0;i<hits.size();++i)check(std::memcmp(&hits[i].offset,memory.data()+hit_at+20*i,12)==0&&hits[i].radius==transform_read<float>(memory.data(),hit_at+20*i+12)&&hits[i].joint==transform_read<std::uint32_t>(memory.data(),hit_at+20*i+16));
    check(transform_read<std::uint32_t>(memory.data(),at+0x514)==0x4ea8c0&&transform_read<std::uint32_t>(memory.data(),at+0xd04)==0x4ea8c0);
    check(transform_read<std::uint32_t>(memory.data(),at+0x518)==(actor.motion_style?0x4e6a20u:0x4e8970u)&&transform_read<std::uint32_t>(memory.data(),at+0xd08)==transform_read<std::uint32_t>(memory.data(),at+0x518));
    check(transform_read<std::uint32_t>(memory.data(),at+0x51c)==0x4d7000u+0x1f44u*character&&transform_read<std::uint32_t>(memory.data(),at+0xd0c)==transform_read<std::uint32_t>(memory.data(),at+0x51c));
}
}
