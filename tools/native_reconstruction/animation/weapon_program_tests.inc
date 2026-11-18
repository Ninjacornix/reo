std::uint64_t weapon_banks{},weapon_selector_cases{},weapon_curves{},weapon_curve_cases{},weapon_refusals{},weapon_event_cases{};
void compare_weapon_programs(std::vector<std::uint8_t>& ram,const char* path,std::shared_ptr<const a::Skeleton> skeleton){
    namespace vm=reo::native::gameplay_scenario;
    std::ifstream file(path,std::ios::binary);unsigned count{};file.read(reinterpret_cast<char*>(&count),4);check(count==16,"all owned WMD assets");
    g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());check(world.spawn_primary(0,std::make_unique<g::Actor>()).status==g::actors::EntityStatus::completed,"canonical resource actor");auto actor=world.primary(0);vm::SceneResources resources;g::WorldResourcePrograms programs(world,resources);
    auto target=std::make_shared<g::ResourceModel>(reo::native::transform_math::identity(),reo::native::transform_math::identity(),a::Vector{},0);
    constexpr unsigned live=0x500000;
    const auto reset=[&](){target->program={};target->program.phase=7;target->program.elapsed=123;target->program.completed.fill(0x5a);ram[live+9]=7;transform_write(ram.data(),live+0x10,std::int16_t(123));std::fill_n(ram.data()+live+0x38,7,0x5a);transform_write(ram.data(),live+0x24,0u);transform_write(ram.data(),live+0x28,0u);};
    const auto compare_state=[&](){const auto& state=target->program;check(state.phase==ram[live+9]&&state.elapsed==transform_read<std::int16_t>(ram.data(),live+0x10),"actual WMD phase/time");check(std::memcmp(state.completed.data(),ram.data()+live+0x38,7)==0,"all seven actual completion bytes");};
    std::vector<std::shared_ptr<const a::WeaponProgramBank>> banks;
    for(unsigned bank_index=0;bank_index<count;++bank_index){
        unsigned size{};file.read(reinterpret_cast<char*>(&size),4);check(size<=2048,"owned WMD extent");std::array<std::byte,2048> raw{};file.read(reinterpret_cast<char*>(raw.data()),size);check(bool(file),"complete owned WMD bytes");const auto bank=a::WeaponProgramBank::import(std::span(raw).first(size));banks.push_back(bank);actor->weapon_programs=bank;
        for(unsigned slot=0;slot<4;++slot)std::memcpy(ram.data()+0x749180+2048*slot,raw.data(),2048);
        std::set<std::pair<std::uint32_t,std::int32_t>> seen;
        const auto word=[&]<class T>(unsigned at){T value;check(at<=2048-sizeof(T),"bounded raw WMD oracle field");std::memcpy(&value,raw.data()+at,sizeof value);return value;};
        for(unsigned selected=0;selected<10;++selected){
            const auto& selection=bank->selection(selected);const auto offset=word.operator()<std::uint32_t>(4*selected);if(!offset){check(selection.kind==a::WeaponSelectionKind::empty,"source zero selection is distinct from unavailable");continue;}if(selection.kind!=a::WeaponSelectionKind::program)continue;
            for(unsigned part=0;part<6;++part){const auto part_at=word.operator()<std::uint32_t>(offset+4*part);const auto& native_part=selection.program->parts[part];check(bool(native_part)==bool(part_at),"raw WMD part presence");if(!part_at)continue;
                for(unsigned axis=0;axis<6;++axis){const auto curve_at=word.operator()<std::uint32_t>(part_at+8*axis);const auto& curve=native_part->curves[axis];check(bool(curve)==bool(curve_at),"raw WMD scalar presence");if(!curve_at)continue;const auto keys=word.operator()<std::int32_t>(part_at+8*axis+4);check(curve->keys().size()==std::size_t(keys),"raw WMD key count");
                    for(int key=0;key<keys;++key){check(std::bit_cast<std::uint32_t>(curve->keys()[std::size_t(key)].value)==word.operator()<std::uint32_t>(curve_at+8*key)&&curve->keys()[std::size_t(key)].time==word.operator()<std::int32_t>(curve_at+8*key+4),"independent owned WMD key/value bytes");}
                    if(!seen.emplace(curve_at,keys).second)continue;
                    ++weapon_curves;
                    for(unsigned bits=0;bits<65536;++bits){const auto time=std::bit_cast<std::int16_t>(std::uint16_t(bits));transform_write(ram.data(),0x600000,0u);const auto original=original_call(ram.data(),0x6b4a30,0x749180+curve_at,std::uint32_t(std::int32_t(time)),std::uint32_t(keys),0x600000);const auto result=curve->sample(time);check(std::bit_cast<std::uint32_t>(result.value)==std::bit_cast<std::uint32_t>(original.f[0])&&result.finished==bool(transform_read<std::uint32_t>(ram.data(),0x600000)),"complete6B4A30 signed-time sample/finish");++weapon_curve_cases;}
                }
            }
        }
        for(unsigned category:{0u,1u,2u,255u})for(unsigned slot=0;slot<4;++slot)for(unsigned style:{0u,1u,2u,255u})for(unsigned mode:{0u,1u,2u,3u,4u,UINT32_MAX})for(int parameter:{0,1,-1})for(unsigned resource:{0u,3u})for(bool present:{false,true}){
            location="WMD bank="+std::to_string(bank_index)+" category="+std::to_string(category)+" slot="+std::to_string(slot)+" style="+std::to_string(style)+" mode="+std::to_string(mode)+" parameter="+std::to_string(parameter)+" resource="+std::to_string(resource)+" present="+std::to_string(present);reset();
            actor->category=std::uint8_t(category);actor->slot=std::uint8_t(slot);actor->motion_style=std::uint8_t(style);actor->selected_resource=std::uint8_t(resource);vm::SceneDescriptor descriptor;descriptor.parameter=std::int16_t(parameter);descriptor.primary=present?target:nullptr;check(bool(resources.load(resource,descriptor)),"actual resource table load");
            const auto table=0x3c5630+60*resource;transform_write(ram.data(),table+28,present?live:0u);transform_write(ram.data(),table+36,descriptor.parameter);ram[actor_at+2]=actor->category;ram[actor_at+3]=actor->slot;ram[actor_at+0xb99]=actor->motion_style;ram[actor_at+0xc7c]=actor->selected_resource;
            original_call(ram.data(),0x6b4420,actor_at,mode);const unsigned index=(mode==0?(parameter?0u:8u):mode==1?2u:mode==2?4u:6u)+(style?1:0);const bool unsupported=resource&&present&&category==0&&bank->selection(index).kind==a::WeaponSelectionKind::unavailable;bool refused{};try{programs.select(*actor,mode);}catch(const std::runtime_error&){refused=true;}
            check(refused==unsupported,"unavailable WMD cell is an explicit reached refusal");if(refused){++weapon_refusals;continue;}compare_state();
            if(resource&&present&&category==0){const auto& state=target->program;check(state.source==bank&&state.selection_index==index,"one canonical actor program source");const auto relative=word.operator()<std::uint32_t>(4*index);check(transform_read<std::uint32_t>(ram.data(),live+0x28)==0x749180+2048*slot&&transform_read<std::uint32_t>(ram.data(),live+0x24)==(relative?0x749180+2048*slot+relative:0u),"actual selected relative source program");check(bool(state.selected)==bool(relative),"native selected program presence");}
            ++weapon_selector_cases;
        }
        ++weapon_banks;
    }
    // Reached real NativeConsumer events use the new owner, including kind5's
    // auxiliary-bit clear after a successful selection. These use bank wp05,
    // whose required selector trees are admitted independently above.
    actor->weapon_programs=banks[4];actor->category=0;actor->slot=0;actor->motion_style=0;actor->selected_resource=3;actor->model=std::make_shared<a::Instance>(skeleton);actor->animation=std::make_shared<a::Playback>(actor->model);vm::SceneDescriptor descriptor;descriptor.parameter=1;descriptor.primary=target;check(bool(resources.load(3,descriptor)),"event concrete resource");transform_write(ram.data(),0x3c5630+60*3+28,live);transform_write(ram.data(),0x3c5630+60*3+36,std::int16_t(1));
    // Restore independently extracted wp05 bytes into the original actor slot.
    std::ifstream again(path,std::ios::binary);again.seekg(4);for(unsigned i=0;i<=4;++i){unsigned size{};again.read(reinterpret_cast<char*>(&size),4);if(i==4){std::fill_n(ram.data()+0x749180,2048,0);again.read(reinterpret_cast<char*>(ram.data()+0x749180),size);}else again.seekg(size,std::ios::cur);}
    e::File1Metadata metadata;e::NativeConsumer consumer(world,metadata,nullptr,nullptr,nullptr,&resources,&programs);
    for(unsigned kind:{2u,3u,4u,5u})for(unsigned bit:{0u,0x100000u}){
        location="real WMD event kind="+std::to_string(kind)+" bit="+std::to_string(bit);reset();actor->auxiliary_status=bit;actor->animation->channel(a::ModelBank::primary,1).timing={0,10,0,0,0};ram[actor_at+2]=0;ram[actor_at+3]=0;ram[actor_at+0xc7c]=3;ram[actor_at+0xb99]=0;transform_write(ram.data(),actor_at+0xba4,bit);transform_write(ram.data(),actor_at+0x204,0.f);transform_write(ram.data(),actor_at+0x208,10.f);transform_write(ram.data(),actor_at+0x20c,0.f);ram[actor_at+0x210]=ram[actor_at+0x211]=0;ram[0x3243cc]=0;
        original_call(ram.data(),0x596470,0,actor_at,kind,0,1.f);consumer.apply(*actor,{e::EventKind::resource_program,0,kind,0,0},1.f);compare_state();check(actor->auxiliary_status==transform_read<std::uint32_t>(ram.data(),actor_at+0xba4),"kind5 actual auxiliary clear order");++weapon_event_cases;
    }
    actor->selected_resource=3;actor->weapon_programs.reset();bool refused{};try{programs.select(*actor,1);}catch(const std::runtime_error&){refused=true;}check(refused,"missing WMD source refuses");++weapon_refusals;
    g::Actor foreign;refused=false;try{programs.select(foreign,0);}catch(const std::runtime_error&){refused=true;}check(refused,"foreign WMD actor refuses");++weapon_refusals;
}
