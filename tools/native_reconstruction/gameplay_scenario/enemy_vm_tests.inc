#include <fstream>

namespace {
std::size_t enemy_route_queries{},enemy_route_refusals{},enemy_imports{},enemy_owned_imports{},enemy_import_refusals{};

template<class Visitor> void visit_enemy(const vm::EnemyDescriptor& descriptor,Visitor visit) {
    visit(0,descriptor.ordinal);visit(1,descriptor.actor_slot);visit(2,descriptor.family);
    visit(3,descriptor.variant);visit(4,descriptor.condition);visit(5,descriptor.parameter4);
    visit(6,descriptor.spawned);
    for(unsigned index=0;index<2;++index)visit(8+4*index,descriptor.orientation[index]);
    for(unsigned index=0;index<3;++index)visit(0x10+4*index,descriptor.position[index]);
    visit(0x1c,descriptor.health);visit(0x1e,descriptor.maximum);
    visit(0x20,descriptor.parameters34_to40[6]);
    visit(0x22,descriptor.room);visit(0x26,descriptor.owner_mode);visit(0x27,descriptor.ordinal);
    visit(0x29,descriptor.parameter1f);visit(0x2a,descriptor.parameter20);visit(0x2b,descriptor.parameter5);
    visit(0x2d,descriptor.parameter23);
    for(unsigned index=0;index<10;++index)visit(0x2f+index,descriptor.auxiliary_ids[index]);
    visit(0x3a,descriptor.parameter21);visit(0x3c,descriptor.route_wait);
    visit(0x40,descriptor.route_position);visit(0x41,descriptor.parameter24);visit(0x42,descriptor.route_seed);
    visit(0x43,descriptor.parameter25);visit(0x44,descriptor.parameter26);visit(0x45,descriptor.runtime_flags);
    visit(0x46,descriptor.parameter31);visit(0x47,descriptor.parameter32);
    for(unsigned index=0;index<13;++index) {
        if(index==6)continue;
        visit(index<6?0x48+index:0x47+index,descriptor.parameters34_to40[index]);
    }
    for(unsigned index=0;index<2;++index)visit(0x55+index,descriptor.parameters42_to43[index]);
    for(unsigned index=0;index<3;++index)visit(0x57+index,descriptor.linked_ids[index]);
    visit(0x5a,descriptor.parameter48);visit(0x5b,descriptor.choice_mask);
    visit(0x5c,descriptor.mapped_parameter);visit(0x5d,descriptor.route_selector);
}

void export_enemy_routes(const vm::EnemyRoutes& routes,std::vector<std::uint8_t>& ram) {
    for(unsigned group=0;group<2;++group) {
        fixture_write(ram.data(),0x4ba820+2*group,routes.classes[group]);
        for(unsigned room=0;room<128;++room)
            fixture_write(ram.data(),0x4ba620+256*group+2*room,routes.room_banks[group][room]);
    }
}
void export_enemies(const vm::EnemyDescriptors& descriptors,std::vector<std::uint8_t>& ram) {
    std::memset(ram.data()+0x74f250,0,96*256);
    for(unsigned index=0;index<256;++index)
        visit_enemy(descriptors.records()[index],[&](unsigned offset,auto value) {
            fixture_write(ram.data(),0x74f250+96*index+offset,value);
        });
    ram[0x4bae8e]=descriptors.count();
    std::memcpy(ram.data()+0x3b5050,descriptors.expiry().data(),256);
    std::memcpy(ram.data()+0x755250,descriptors.room_counts().data(),128);
    std::memcpy(ram.data()+0x7552d0,descriptors.room_starts().data(),128);
    const auto& assignments=descriptors.assignments();
    std::memcpy(ram.data()+0x4ba82c,assignments.counts.data(),4);
    std::memcpy(ram.data()+0x4ba830,assignments.flags.data(),4);
    std::memcpy(ram.data()+0x4b9680,assignments.slots.data(),1024);
}
void compare_enemies(const vm::EnemyDescriptors& descriptors,const std::vector<std::uint8_t>& ram) {
    for(unsigned index=0;index<256;++index)
        visit_enemy(descriptors.records()[index],[&](unsigned offset,auto value) {
            if(std::memcmp(ram.data()+0x74f250+96*index+offset,&value,sizeof(value))!=0)
                assertion_context+=" record="+std::to_string(index)+" field="+std::to_string(offset);
            check(std::memcmp(ram.data()+0x74f250+96*index+offset,&value,sizeof(value))==0);
        });
    check(ram[0x4bae8e]==descriptors.count());
    check(std::memcmp(ram.data()+0x3b5050,descriptors.expiry().data(),256)==0);
    check(std::memcmp(ram.data()+0x755250,descriptors.room_counts().data(),128)==0);
    check(std::memcmp(ram.data()+0x7552d0,descriptors.room_starts().data(),128)==0);
    const auto& assignments=descriptors.assignments();
    check(std::memcmp(ram.data()+0x4ba82c,assignments.counts.data(),4)==0);
    check(std::memcmp(ram.data()+0x4ba830,assignments.flags.data(),4)==0);
    check(std::memcmp(ram.data()+0x4b9680,assignments.slots.data(),1024)==0);
}

void enemy_route_tests() {
    std::vector<std::uint8_t> ram(0x900000);
    owned_enemy_constants(ram.data());
    vm::EnemyRoutes routes;
    routes.classes={0,1};
    for(unsigned trial=0;trial<32768;++trial) {
        assertion_context="Enemy route trial="+std::to_string(trial);
        const auto scenario=std::array<std::uint16_t,8>{0,1,2,6,28,35,41,43}[trial%8];
        const auto room=std::uint8_t((trial/8)%128);
        const auto family=std::array<std::uint8_t,8>{0,1,2,127,128,255,0,1}[(trial/1024)%8];
        const auto bank=std::array<std::uint16_t,8>{0,1,2,3,4,5,7,65535}[(trial/16)%8];
        const auto selector=std::array<std::uint8_t,8>{0,1,2,3,4,5,127,255}[(trial/128)%8];
        routes.classes={0,std::uint16_t((trial/8192)%2 ? 0 : 1)};
        routes.room_banks[0][room]=bank;
        routes.room_banks[1][room]=bank;
        export_enemy_routes(routes,ram);
        const auto result=routes.position(scenario,family,room,selector);
        if(!result.available) { ++enemy_route_refusals;continue; }
        fixture_write(ram.data(),0x3243da,scenario);
        ram[0x70002]=family;ram[0x70022]=room;ram[0x7005d]=selector;ram[0x70040]=0x71;
        invoke_npc_original(ram,o2_006BC210_0x6bc210,{0x70000,0,0,0});
        check(result.position==std::bit_cast<std::int8_t>(ram[0x70040]));
        ++enemy_route_queries;
    }
    routes.room_banks[0][0]=0;
    check(!routes.position({},0,0,0).available);
    check(routes.position({},255,255,255).available);
    assertion_context.clear();
}

std::vector<std::byte> synthetic_enemies(unsigned trial) {
    const unsigned count=trial%300;
    std::vector<std::byte> bytes(16+96*(count+1));
    const auto write=[&](std::size_t at,std::uint32_t value) { std::memcpy(bytes.data()+at,&value,4); };
    write(0,16u+trial%4);
    for(unsigned index=0;index<count;++index) {
        const auto base=16+96*index;
        for(unsigned field=0;field<96;++field)bytes[base+field]=std::byte(trial*17u+index*31u+field*71u);
        bytes[base+2]=std::byte((index+trial)%62);
        bytes[base+0x1c]=std::byte((index*7+trial)%128);
        bytes[base+0x1d]=std::byte((index+trial)%4);
        bytes[base+0x1e]=std::byte((index+trial)%4);
        bytes[base+0x33]=std::byte((index+trial)%10);
        bytes[base+0x49]=std::byte{15};
        bytes[base+0x4b]=std::byte((index+trial)%6);
        const std::array<std::uint32_t,8> positions{0,1,0xffffffffu,0x7fffffffu,0x80000000u,0x7fffffc0u,0x80000041u,trial*65537u};
        for(unsigned axis=0;axis<3;++axis)write(base+0x10+4*axis,positions[(index+axis)%8]);
    }
    bytes[16+96*count+2]=std::byte{255};
    return bytes;
}

bool enemy_import_case(std::span<const std::byte> bytes,unsigned trial,bool offline,std::uint16_t scenario,
                       std::uint8_t row,std::uint8_t observed,bool fresh) {
    std::vector<std::uint8_t> ram(0x900000);
    owned_enemy_constants(ram.data());
    ActorFixture actors(trial,0,offline);
    auto& session=*actors.session;
    session.scenario=scenario;
    auto random=session.random.state();random.observed=observed;session.random.restore(random);
    if(!fresh) {
        session.enemy_routes.classes={std::uint16_t(trial%62),std::uint16_t((trial+1)%62)};
        for(auto& rooms:session.enemy_routes.room_banks)
            rooms.fill(trial%3 ? 0u : 65535u);
    }
    auto& descriptors=session.enemy_descriptors;
    descriptors.record(255)->variant=0xfe;
    descriptors.assignments().counts={0x1234,0xabcd};
    descriptors.assignments().flags={3,5,7,9};
    descriptors.assignments().slots.fill(0x71);
    for(unsigned index=0;index<64;++index) {
        auto& registration=*session.ai_control_requests.registration(index);
        registration.active=std::uint8_t((trial+index)%5==0);
        registration.kind=std::uint8_t(index%3);
        registration.target=std::int16_t(index);
        registration.phase=std::uint8_t(index+trial);
        registration.owner_tag=std::uint8_t(index*7);
        registration.payload={1,3,5,7};registration.counters={2,4,6,8};
    }
    actors.export_original(ram);
    fixture_write(ram.data(),0x3243da,scenario);
    ram[0x4bae8a]=row;
    export_enemy_routes(session.enemy_routes,ram);
    export_enemies(descriptors,ram);
    export_npc_controls(session.ai_control_requests,ram);
    check(bytes.size()<=0x10000);
    std::memcpy(ram.data()+0x90000,bytes.data(),bytes.size());
    fixture_write(ram.data(),0x32440c,0x90000u);
    const auto baseline=descriptors;
    const auto baseline_controls=session.ai_control_requests;
    const auto baseline_random=session.random.state();
    const auto result=descriptors.import(bytes,session,offline,row);
    if(result.status!=vm::EnemyImportStatus::completed) {
        check(result.status==vm::EnemyImportStatus::unavailable || result.status==vm::EnemyImportStatus::full ||
              result.status==vm::EnemyImportStatus::malformed);
        export_enemies(baseline,ram);
        compare_enemies(descriptors,ram);
        check(session.random.state()==baseline_random);
        export_npc_controls(baseline_controls,ram);
        compare_npc_controls(session.ai_control_requests,ram);
        ++enemy_import_refusals;
        return false;
    }
    npc_file_loads=0;
    invoke_npc_original(ram,o2_006BAA40_0x6baa40);
    check(npc_file_loads==1);
    compare_enemies(descriptors,ram);
    compare_npc_controls(session.ai_control_requests,ram);
    const auto state=session.random.state();
    check(state.primary==fixture_read<std::uint16_t>(ram.data(),0x3244b0));
    check(state.secondary==fixture_read<std::uint16_t>(ram.data(),0x3244b8));
    check(state.observed==ram[0x2b8de8]);
    ++enemy_imports;
    return true;
}

void enemy_import_tests(const char* owned_path) {
    for(unsigned trial=0;trial<1024;++trial) {
        assertion_context="Synthetic enemy import trial="+std::to_string(trial);
        const auto bytes=synthetic_enemies(trial);
        const auto scenario=std::array<std::uint16_t,6>{1,2,6,28,35,41}[trial%6];
        (void)enemy_import_case(bytes,trial,(trial&1)!=0,scenario,std::uint8_t(trial),std::uint8_t(trial*31),false);
    }
    std::ifstream input(owned_path,std::ios::binary);
    check(bool(input));
    const auto read=[&](std::size_t size) {
        std::vector<std::byte> bytes(size);
        input.read(reinterpret_cast<char*>(bytes.data()),std::streamsize(size));
        check(bool(input));return bytes;
    };
    const auto header=read(4);
    check(fixture_read<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(header.data()),0)==10);
    for(unsigned member=0;member<10;++member) {
        const auto metadata=read(12);
        const auto raw=reinterpret_cast<const std::uint8_t*>(metadata.data());
        const auto scenario=fixture_read<std::uint32_t>(raw,0),offline=fixture_read<std::uint32_t>(raw,4);
        const auto size=fixture_read<std::uint32_t>(raw,8);
        check(size<=0x10000&&scenario<=65535&&offline<=1);
        const auto bytes=read(size);
        for(unsigned row=0;row<4;++row)for(unsigned observed=0;observed<4;++observed) {
            assertion_context="Owned enemy member="+std::to_string(member)+" row="+std::to_string(row)+" observed="+std::to_string(observed);
            check(enemy_import_case(bytes,member*16+row*4+observed,offline!=0,std::uint16_t(scenario),
                                    std::uint8_t(row),std::uint8_t(observed),true));
            ++enemy_owned_imports;
        }
    }
    check(input.peek()==std::char_traits<char>::eof());
    for(unsigned size=0;size<4;++size)
        check(!enemy_import_case(std::vector<std::byte>(size),0,false,1,0,0,true));
    auto truncated=synthetic_enemies(11);truncated.resize(truncated.size()-96);
    check(!enemy_import_case(truncated,0,false,1,0,0,true));
    assertion_context.clear();
}
}
