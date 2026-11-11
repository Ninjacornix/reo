#include "owned_npc_fixtures.inc"

namespace {
std::size_t npc_imports{},npc_import_refusals{},npc_primitive_calls{},npc_inventory_dispatches{};
std::size_t npc_command_dispatches{},npc_command_refusals{};

template<class Visitor> void visit_npc(const vm::NpcDescriptor& descriptor,Visitor visit) {
    visit(0,descriptor.active);visit(1,descriptor.room);visit(2,descriptor.category);visit(3,descriptor.variant);
    visit(4,descriptor.template_id);visit(6,descriptor.control_mode);visit(7,descriptor.flags);
    visit(8,descriptor.position.x);visit(12,descriptor.position.y);visit(16,descriptor.position.z);
    visit(0x14,descriptor.yaw);visit(0x16,descriptor.health);visit(0x1a,descriptor.mode2_half);
    visit(0x1e,descriptor.transition_state);visit(0x1f,descriptor.random_policy);
    visit(0x22,descriptor.behavior_flags);visit(0x28,descriptor.transition_timer);
    visit(0x30,descriptor.behavior_state);visit(0x34,descriptor.parameter);
    for(unsigned index=0;index<3;++index)visit(0x38+4*index,descriptor.control_parameters[index]);
    for(unsigned index=0;index<4;++index)visit(0x4c+index,descriptor.inventory[index]);
    visit(0x50,descriptor.selected_resource);
    visit(0x54,descriptor.mode0_values[0]);visit(0x56,descriptor.mode0_values[1]);
    visit(0x58,descriptor.mode_parameter);visit(0x5c,descriptor.mode2_value);visit(0x6c,descriptor.mode2_parameter);
}

void export_npcs(const vm::NpcDescriptors& descriptors,std::vector<std::uint8_t>& ram) {
    for(unsigned index=0;index<64;++index)
        visit_npc(descriptors.records()[index],[&](unsigned offset,auto value) {
            fixture_write(ram.data(),0x390210+120*index+offset,value);
        });
}
void compare_npcs(const vm::NpcDescriptors& descriptors,const std::vector<std::uint8_t>& ram) {
    for(unsigned index=0;index<64;++index)
        visit_npc(descriptors.records()[index],[&](unsigned offset,auto value) {
            check(std::memcmp(ram.data()+0x390210+120*index+offset,&value,sizeof(value))==0);
        });
}

void seed_npcs(vm::NpcDescriptors& descriptors,unsigned trial) {
    for(unsigned index=0;index<64;++index) {
        auto& descriptor=*descriptors.record(index);
        const auto seed=trial*31337u+index*97;
        descriptor.active=std::uint8_t((index+trial)%3);
        descriptor.room=std::uint8_t(seed);
        descriptor.category=std::uint8_t(seed>>3);
        descriptor.variant=std::uint8_t(seed>>5);
        descriptor.template_id=std::array<std::uint16_t,8>{0,0x64,0x1d,127,128,32767,65535,1}[(index+trial)%8];
        descriptor.control_mode=std::uint8_t(seed%3);
        descriptor.flags=std::uint8_t(seed);
        descriptor.position={float(seed%1024),-float(seed%2048),float(seed%4096)};
        descriptor.yaw=std::uint16_t(seed);
        descriptor.health=std::uint16_t(seed>>1);
        descriptor.mode2_half=std::uint16_t(seed>>2);
        descriptor.transition_state=std::uint8_t(seed>>7);
        descriptor.random_policy=std::array<std::int8_t,9>{0,1,2,3,4,5,-1,127,-128}[(index+trial/8)%9];
        descriptor.behavior_flags=std::uint16_t(seed);
        descriptor.transition_timer=std::bit_cast<std::int32_t>(seed*65521u);
        descriptor.behavior_state=std::bit_cast<std::int32_t>(seed*65519u);
        descriptor.parameter=std::uint8_t(seed>>8);
        descriptor.control_parameters={seed*3,seed*5,seed*7};
        descriptor.inventory={199,200,201,202};
        if(seed%5)descriptor.inventory[seed%4]=0;
        descriptor.selected_resource=std::uint8_t(seed>>6);
        descriptor.mode0_values={std::uint16_t(seed*5),std::uint16_t(seed*7)};
        descriptor.mode_parameter=std::uint8_t(seed>>4);
        descriptor.mode2_value=seed*65537u;
        descriptor.mode2_parameter=seed*65539u;
    }
}

void export_npc_controls(const reo::native::gameplay_ai::ControlRequests& controls,std::vector<std::uint8_t>& ram) {
    for(unsigned index=0;index<64;++index) {
        const auto& entry=controls.registrations()[index];
        const auto at=0x744af8+28*index;
        ram[at]=entry.active;ram[at+1]=entry.kind;ram[at+2]=entry.phase;ram[at+3]=entry.owner_tag;
        fixture_write(ram.data(),at+4,entry.target);
        std::memcpy(ram.data()+at+8,entry.payload.data(),4);
        std::memcpy(ram.data()+at+16,entry.counters.data(),8);
    }
}
void compare_npc_controls(const reo::native::gameplay_ai::ControlRequests& controls,const std::vector<std::uint8_t>& ram) {
    for(unsigned index=0;index<64;++index) {
        const auto& entry=controls.registrations()[index];
        const auto at=0x744af8+28*index;
        check(entry.active==ram[at]&&entry.kind==ram[at+1]&&entry.phase==ram[at+2]&&entry.owner_tag==ram[at+3]);
        check(entry.target==fixture_read<std::int16_t>(ram.data(),at+4));
        check(std::memcmp(entry.payload.data(),ram.data()+at+8,4)==0);
        check(std::memcmp(entry.counters.data(),ram.data()+at+16,8)==0);
    }
}

void invoke_npc_original(std::vector<std::uint8_t>& ram,PS2Runtime::Function function,
                         std::array<std::uint32_t,4> arguments={}) {
    R5900Context original;
    PS2Runtime runtime;
    for(unsigned index=0;index<4;++index)SET_GPR_S32(&original,4+index,std::bit_cast<std::int32_t>(arguments[index]));
    SET_GPR_U32(&original,29,0x7f0000);
    SET_GPR_U32(&original,31,0xdeadbeef);
    function(ram.data(),&original,&runtime);
    check(original.pc==0xdeadbeef);
}

std::vector<std::byte> synthetic_npcs(unsigned trial) {
    const auto groups=trial%5;
    if(!groups)return std::vector<std::byte>(8);
    std::vector<std::byte> result(groups*8);
    const auto write=[&](std::size_t at,std::uint32_t value) { std::memcpy(result.data()+at,&value,4); };
    for(unsigned group=0;group<groups;++group) {
        const unsigned count=(trial+group*19)%40;
        const auto base=result.size();
        write(8*group,std::uint32_t(base));
        result.resize(base+4+4*count);
        write(base,count);
        for(unsigned index=0;index<count;++index) {
            const auto offset=result.size();
            write(base+4+4*index,std::uint32_t(offset-base));
            result.resize(offset+84);
            for(unsigned word=0;word<21;++word)
                write(offset+4*word,trial*65537u+index*31337u+word*65521u);
            const auto mode=std::array{0u,1u,2u,3u,0x100u,0x101u,0x102u,0xffffffffu}[(trial+index)%8];
            write(offset+0xc,(index+trial)%3 ? 0x1du : 0x64u);
            write(offset+0x24,mode);
        }
    }
    return result;
}

void npc_import_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for(unsigned trial=0;trial<517;++trial) {
        assertion_context="NPC import trial="+std::to_string(trial);
        auto synthetic=synthetic_npcs(trial);
        const auto bytes=trial<512 ? std::span<const std::byte>(synthetic) : owned_npc_inputs[trial-512];
        vm::NpcDescriptors descriptors;
        seed_npcs(descriptors,trial);
        export_npcs(descriptors,ram);
        std::memcpy(ram.data()+0x90000,bytes.data(),bytes.size());
        fixture_write(ram.data(),0x32440c,0x90000u);
        ram[0x3243d7]=std::uint8_t(trial&1);
        npc_file_loads=0;
        invoke_npc_original(ram,sub_001D45F0_0x1d45f0);
        check(npc_file_loads==1);
        const auto before=std::vector<std::byte>(bytes.begin(),bytes.end());
        const auto imported=descriptors.import(bytes);
        check(imported&&*imported<=64);
        check(std::equal(before.begin(),before.end(),bytes.begin()));
        compare_npcs(descriptors,ram);
        ++npc_imports;
    }
    vm::NpcDescriptors descriptors;
    seed_npcs(descriptors,997);
    const auto baseline=descriptors;
    const auto refuse=[&](std::span<const std::byte> bytes) {
        check(!descriptors.import(bytes));
        export_npcs(baseline,ram);
        compare_npcs(descriptors,ram);
        ++npc_import_refusals;
    };
    for(unsigned size=0;size<4;++size)refuse(std::vector<std::byte>(size));
    std::vector<std::byte> invalid(16);
    std::uint32_t value=0xffffffffu;
    std::memcpy(invalid.data(),&value,4);
    refuse(invalid);
    value=8;std::memcpy(invalid.data(),&value,4);
    value=1;std::memcpy(invalid.data()+8,&value,4);
    value=0xffffffffu;std::memcpy(invalid.data()+12,&value,4);
    refuse(invalid);
    auto truncated=synthetic_npcs(11);
    truncated.resize(truncated.size()-1);
    refuse(truncated);
    export_npcs(descriptors,ram);
    invoke_npc_original(ram,o2_00683A90_0x683a90);
    descriptors.reset();
    compare_npcs(descriptors,ram);
    assertion_context.clear();
}

void npc_primitive_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    for(unsigned trial=0;trial<4096;++trial) {
        assertion_context="NPC primitives trial="+std::to_string(trial);
        ActorFixture actors(trial,0);
        auto& session=*actors.session;
        auto& descriptors=session.npc_descriptors;
        seed_npcs(descriptors,trial);
        actors.export_original(ram);
        session.scenario=std::uint16_t(trial%3);
        fixture_write(ram.data(),0x3243da,*session.scenario);
        export_npcs(descriptors,ram);
        // Start from real canonical registrations, including duplicate and full cases.
        for(unsigned index=0;index<64;++index) {
            auto& entry=*session.ai_control_requests.registration(index);
            entry.active=std::uint8_t(trial%5==0 || (trial+index)%3==0);
            entry.kind=std::uint8_t(index%3);
            entry.target=std::int16_t(index);
            entry.phase=std::uint8_t(trial+index);
            entry.owner_tag=std::uint8_t(index*3);
            entry.payload={1,2,3,4};
            entry.counters={5,6,7,8};
            const auto at=0x744af8+28*index;
            ram[at]=entry.active;ram[at+1]=entry.kind;ram[at+2]=entry.phase;ram[at+3]=entry.owner_tag;
            fixture_write(ram.data(),at+4,entry.target);
            std::memcpy(ram.data()+at+8,entry.payload.data(),4);
            std::memcpy(ram.data()+at+16,entry.counters.data(),8);
        }
        const auto id=std::array<std::int32_t,9>{0,0x64,0x1d,127,128,32767,65535,-1,0x10064}[trial%9];
        const std::array<std::uint32_t,3> parameters{trial*65537u,0xffff0000u+trial,trial^0x89abcdefu};
        invoke_npc_original(ram,o2_00684010_0x684010,{std::uint32_t(id),parameters[0],parameters[1],parameters[2]});
        check(descriptors.enable(session,id,parameters));
        compare_npcs(descriptors,ram);
        actors.compare_original(ram);
        for(unsigned index=0;index<64;++index) {
            const auto& entry=session.ai_control_requests.registrations()[index];
            const auto at=0x744af8+28*index;
            check(entry.active==ram[at]&&entry.kind==ram[at+1]&&entry.phase==ram[at+2]&&entry.owner_tag==ram[at+3]);
            check(entry.target==fixture_read<std::int16_t>(ram.data(),at+4));
            check(std::memcmp(entry.payload.data(),ram.data()+at+8,4)==0);
            check(std::memcmp(entry.counters.data(),ram.data()+at+16,8)==0);
        }
        const std::array<float,3> position{float(trial),-float(trial),float(trial*3)};
        std::memcpy(ram.data()+0x80000,position.data(),12);
        invoke_npc_original(ram,o2_006841E0_0x6841e0,{std::uint32_t(id),trial*313u,0x80000u,trial*65521u});
        descriptors.position(id,std::uint8_t(trial*313u),{position[0],position[1],position[2]},std::uint16_t(trial*65521u));
        compare_npcs(descriptors,ram);
        const auto health=std::array<std::int32_t,6>{-1,0,1,32767,65535,0x7fffffff}[trial%6];
        const auto mask=(trial&255u)|((trial/256u)<<28);
        invoke_npc_original(ram,o2_006842B0_0x6842b0,{std::uint32_t(id),std::uint32_t(health),mask,0});
        descriptors.health_flags(id,health,mask);
        compare_npcs(descriptors,ram);
        invoke_npc_original(ram,o2_00684450_0x684450,{std::uint32_t(id),0,0,0});
        descriptors.disable(id);
        compare_npcs(descriptors,ram);
        npc_primitive_calls+=4;
    }
    assertion_context.clear();
}

void npc_inventory_vm_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    vm::ResourceTemplates templates;
    std::memcpy(ram.data()+0x74b6e0,templates.state().selectors.data(),templates.state().selectors.size());
    for(unsigned trial=0;trial<2048;++trial) {
        assertion_context="NPC inventory trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        ActorFixture actors(trial,0,offline);
        auto& descriptors=actors.session->npc_descriptors;
        seed_npcs(descriptors,trial);
        actors.export_original(ram);
        export_npcs(descriptors,ram);
        fixture_write(ram.data(),0x75a4b0,(trial>>4)%5);
        fixture_write(ram.data(),0x75a4c0,(trial>>6)%3);
        ram[0x3243e8]=1;
        vm::SceneResources resources;
        std::memset(ram.data()+0x3c5630,0,256*60);
        for(unsigned index=0;index<256;++index) {
            vm::SceneDescriptor descriptor;
            descriptor.active=std::uint8_t(trial%13==0 || (index+trial)%11==0);
            descriptor.attachment_id=std::uint16_t(index%3?11:254);
            descriptor.instance_index=std::uint8_t(index);
            check(resources.load(index,descriptor).has_value());
            const auto at=0x3c5630+60*index;
            ram[at]=descriptor.active;ram[at+2]=descriptor.instance_index;ram[at+0x2b]=descriptor.template_index;
            fixture_write(ram.data(),at+6,descriptor.attachment_id);
        }
        fixture_write(ram.data(),0x743128,std::uint32_t(resources.active_count()));
        const auto id=std::array<std::uint32_t,8>{0,0x64,0x1d,127,128,32767,65535,0x10064}[(trial/2)%8];
        const auto content=std::array{0u,11u,254u,65535u}[(trial/16)%4];
        std::vector<std::byte> script;
        emit(script,1);
        emit(script,0x3a,{id,content,trial*65521u});
        emit(script,0x3d,{id,content});
        emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0,0x10000u);
        fixture_write(ram.data(),0x4bacf8,0u);
        fixture_write(ram.data(),0x4bad28,0u);
        vm::Interpreter native;
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},profile))==vm::Status::completed);
        vm::Providers providers;
        providers.world=&actors.world;providers.flags=&flags;providers.canonical_flags=&flags;
        providers.scene_resources=&resources;providers.resource_templates=&templates;
        const vm::TickContext context{true,false,0};
        if(offline) {
            original_offline_call(ram,0,false);
            check(native.tick_offline_channel(0,context,{(trial>>4)%5,(trial>>6)%3,0},providers).status==vm::Status::yielded);
        } else {
            invoke_npc_original(ram,o2_0068C660_0x68c660);
            ++invocations;
            check(native.tick(0,context,providers).status==vm::Status::yielded);
        }
        compare_npcs(descriptors,ram);
        check(resources.active_count()==fixture_read<std::uint32_t>(ram.data(),0x743128));
        for(unsigned index=0;index<256;++index) {
            const auto descriptor=resources.get(*resources.slot(index));
            const auto at=0x3c5630+60*index;
            check(descriptor->active==ram[at]&&descriptor->kind==ram[at+3]);
            check(descriptor->attachment_id==fixture_read<std::uint16_t>(ram.data(),at+6));
            check(descriptor->ownership_tag==fixture_read<std::uint16_t>(ram.data(),at+0x28));
            check(descriptor->parameter==fixture_read<std::int16_t>(ram.data(),at+0x24));
            check(descriptor->flags==fixture_read<std::uint32_t>(ram.data(),at+0x18));
            check(descriptor->template_index==ram[at+0x2b]);
        }
        ++npc_inventory_dispatches;
    }
    assertion_context.clear();
}

void npc_command_vm_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    install_original_tables(ram);
    vm::FlagState flags;
    constexpr std::array<std::uint32_t,7> opcodes{0x80,0x81,0x88,0x89,0x8a,0x8b,0x8c};
    for(unsigned trial=0;trial<3584;++trial) {
        const auto opcode=opcodes[trial%7];
        assertion_context="NPC command trial="+std::to_string(trial);
        const bool offline=(trial&1)!=0;
        const auto category=(trial/14)%5,relation=(trial/70)%3;
        ActorFixture actors(trial,0,offline);
        auto& session=*actors.session;
        auto& descriptors=session.npc_descriptors;
        seed_npcs(descriptors,trial);
        session.scenario=std::uint16_t(trial%3);
        for(unsigned index=0;index<8;++index)
            session.missing_characters.values[index]=std::uint8_t(trial/7+index*31);
        const auto id=std::array<std::uint32_t,16>{0,0x64,0x1d,127,128,199,1,7,200,201,202,203,204,205,206,207}[(trial/7)%16];
        const auto resolved=session.missing_characters.resolve(id);
        check(resolved.has_value());
        descriptors.record(trial%64)->template_id=*resolved;
        // Registration removal, duplicates, full tables and preserved payloads
        // all use the same actual Session registration storage.
        for(unsigned index=0;index<64;++index) {
            auto& entry=*session.ai_control_requests.registration(index);
            entry.active=std::uint8_t((trial+index)%5!=0);
            entry.kind=std::uint8_t(index%3);
            entry.target=std::int16_t(index);
            entry.phase=std::uint8_t(index+trial);
            entry.owner_tag=std::uint8_t(index*7);
            entry.payload={1,3,5,7};entry.counters={2,4,6,8};
        }
        actors.export_original(ram);
        export_npcs(descriptors,ram);
        export_npc_controls(session.ai_control_requests,ram);
        std::memcpy(ram.data()+0x4badb8,session.missing_characters.values.data(),8);
        fixture_write(ram.data(),0x3243da,*session.scenario);
        fixture_write(ram.data(),0x75a4b0,category);
        fixture_write(ram.data(),0x75a4c0,relation);
        ram[0x3243e8]=1;
        const bool half_id=opcode>=0x89;
        const auto encoded_id=half_id ? id|(trial*65521u<<16) : id;
        const auto argument=std::array{0u,1u,0xffffffffu,0x7fffffffu,0x80000000u}[(trial/112)%5];
        std::vector<std::byte> script;
        emit(script,1);
        if(opcode==0x88)emit(script,opcode,{encoded_id,argument,trial*65537u,trial^0xffffffffu});
        else if(opcode==0x89)emit(script,opcode,{encoded_id,argument,trial*65521u,0u-trial*65537u,trial*31337u,trial*65519u});
        else if(opcode==0x8a||opcode==0x8c)emit(script,opcode,{encoded_id,argument});
        else emit(script,opcode,{encoded_id});
        emit(script,0xa);
        std::memcpy(ram.data()+0x10000,script.data(),script.size());
        fixture_write(ram.data(),0x4bace0,0x10000u);
        fixture_write(ram.data(),0x4bacf8,0u);
        fixture_write(ram.data(),0x4bad28,0u);
        vm::Interpreter native;
        const auto profile=offline?vm::DispatchProfile::offline_actor:vm::DispatchProfile::ordinary;
        check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{script},profile))==vm::Status::completed);
        vm::Providers providers;
        providers.world=&actors.world;providers.flags=&flags;providers.canonical_flags=&flags;
        const vm::TickContext context{true,false,0};
        if(offline) {
            original_offline_call(ram,0,false);
            check(native.tick_offline_channel(0,context,{category,relation,0},providers).status==vm::Status::yielded);
        } else {
            invoke_npc_original(ram,o2_0068C660_0x68c660);
            ++invocations;
            check(native.tick(0,context,providers).status==vm::Status::yielded);
        }
        compare_npcs(descriptors,ram);
        compare_npc_controls(session.ai_control_requests,ram);
        actors.compare_original(ram);
        ++npc_command_dispatches;
    }
    for(const auto opcode:opcodes) {
        for(const auto id:{208u,65535u}) {
            std::vector<std::byte> script;
            emit(script,opcode,{id,0,0,0,0,0});
            bool refused=false;
            try { (void)vm::Program({script}); }
            catch(const std::invalid_argument&) { refused=true; }
            check(refused);
            ++npc_command_refusals;
        }
    }
    for(const auto opcode:{0x80u,0x81u,0x88u}) {
        std::vector<std::byte> script;
        emit(script,opcode,{0x800000c8u,0,0,0});
        bool refused=false;
        try { (void)vm::Program({script}); }
        catch(const std::invalid_argument&) { refused=true; }
        check(refused);
        ++npc_command_refusals;
    }
    {
        ActorFixture actors;
        auto& session=*actors.session;
        auto& descriptor=*session.npc_descriptors.record(0);
        descriptor.template_id=0x64;descriptor.control_mode=1;descriptor.flags=0x10;
        descriptor.control_parameters={1,2,3};
        session.scenario.reset();
        const auto baseline=session.npc_descriptors;
        check(!session.npc_descriptors.enable(session,0x64,{4,5,6}));
        export_npcs(baseline,ram);
        compare_npcs(session.npc_descriptors,ram);
        ++npc_command_refusals;
        check(!session.missing_characters.resolve(0xffffffffu));
        ++npc_command_refusals;
    }
    assertion_context.clear();
}
}
