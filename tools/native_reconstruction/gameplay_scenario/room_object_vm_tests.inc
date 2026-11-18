#include "game/native/gameplay_scenario/room_object_commands.hpp"
// The dispatcher-only fixture admits no model instances or proxies. Complete
// live consumers are independently exercised by room_object_lifetime_tests.
void o2_00616F60_0x616f60(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted model in dispatcher-only room-object fixture");}
void o2_006ADBA0_0x6adba0(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted proxy in dispatcher-only room-object fixture");}
namespace {
namespace ro=reo::native::gameplay_collision::room_objects;
namespace collision=reo::native::gameplay_collision;
std::size_t room_object_dispatches{};
struct RoomObjectsFixture {
    ro::Owner owner;
    ro::InteractionOwner interactions;
    reo::native::gameplay_actors::EntityStore entities;
    collision::ownership::Proxies proxies;
    struct Bindings final:ro::ModelBindings {
        std::uint8_t resolve(std::uint8_t)const noexcept override{throw_if_called();return 0;}
        static void throw_if_called()noexcept{std::terminate();}
        void mark(std::uint8_t)noexcept override{throw_if_called();}
        void bind(std::uint8_t,reo::native::gameplay_actors::EntityId)noexcept override{throw_if_called();}
        void unbind(std::uint8_t)noexcept override{throw_if_called();}
        void retain_pose(std::uint8_t,const collision::actors::Basis&)noexcept override{throw_if_called();}
    } bindings;
    collision::response::Grid walls{},floors{};
    ro::InteractionOwner::Lifetime lifetime;
    vm::RoomObjectCommands commands;
    static ro::Owner make(unsigned profile){
        std::vector<std::byte> types(24),sto(8+4*16),grid(0x934);
        const auto put=[](std::vector<std::byte>& b,unsigned at,std::uint32_t value){for(unsigned i=0;i<4;++i)b[at+i]=std::byte((value>>(8*i))&255);};
        put(types,4,1);put(types,8,16);put(types,12,0);types[17]=std::byte{1};
        put(sto,0,2);put(sto,4,4);
        for(unsigned i=0;i<4;++i){const auto at=8+16*i;sto[at]=std::byte{1};sto[at+1]=std::byte(i<2?3:i==2?31:0);sto[at+3]=std::byte(1+2*i);sto[at+4]=std::byte(1+i);sto[at+5]=std::byte(i);sto[at+6]=std::byte{15};put(sto,at+12,(profile&3)*0x10u|((profile&4)?2u:0u));}
        put(grid,0,std::bit_cast<std::uint32_t>(-125.0f));put(grid,4,std::bit_cast<std::uint32_t>(7.5f));put(grid,8,std::bit_cast<std::uint32_t>(62.5f));put(grid,12,16);put(grid,16,12);
        for(unsigned i=0;i<8;++i)put(grid,0x914+4*i,1u|((i%2?15u:1u)<<16)|((i%2?11u:1u)<<24));
        auto result=ro::Owner::import(types,sto);check(result.install_grid(1,grid));return result;
    }
    explicit RoomObjectsFixture(unsigned profile):owner(make(profile)),interactions(owner),entities({64}),lifetime(interactions,entities,proxies,bindings,walls,floors),commands(owner,lifetime){}
    void export_original(std::vector<std::uint8_t>& ram){
        std::memset(ram.data()+0x3c4580,0,32*60);std::memset(ram.data()+0x74b1c0,0,32*8);ram[0x74b1c1]=1;
        owned_object_constants(ram.data());fixture_write(ram.data(),0x3c4d00,owner.grid()->origin);fixture_write(ram.data(),0x3c4d0c,owner.grid()->width);fixture_write(ram.data(),0x3c4d0e,owner.grid()->depth);
        for(const auto& id:owner.objects()){const auto* o=owner.get(id);const auto slot=*interactions.source_ordinal(id);const auto at=0x3c4580+60*slot;ram[at]=1;ram[at+1]=o->room;ram[at+2]=o->external_id;ram[at+3]=slot;fixture_write(ram.data(),at+4,o->type);fixture_write(ram.data(),at+8,o->center);fixture_write(ram.data(),at+0x14,o->rotation);ram[at+0x16]=std::uint8_t(o->initial_x);ram[at+0x17]=std::uint8_t(o->initial_z);ram[at+0x18]=std::uint8_t(o->x);ram[at+0x19]=std::uint8_t(o->z);ram[at+0x1a]=o->allowed_directions;ram[at+0x1f]=std::uint8_t(o->width);ram[at+0x20]=std::uint8_t(o->height);ram[at+0x21]=std::uint8_t(o->depth);ram[at+0x22]=o->parameter;fixture_write(ram.data(),at+0x24,o->control_flags);}
        for(unsigned i=0;i<8;++i){const auto id=owner.mapped(i);ram[0x3c5613+4*i]=id?*interactions.source_ordinal(*id):255;}
    }
    void compare_original(const std::vector<std::uint8_t>& ram){
        for(const auto& id:owner.objects()){const auto* o=owner.get(id);const auto at=0x3c4580+60**interactions.source_ordinal(id);check(ram[at]==1);check(ram[at+1]==o->room);check(ram[at+2]==o->external_id);check(fixture_read<std::uint16_t>(ram.data(),at+4)==o->type);check(fixture_read<std::uint32_t>(ram.data(),at+0x24)==o->control_flags);check(ram[at+0x18]==std::uint8_t(o->x)&&ram[at+0x19]==std::uint8_t(o->z));check(std::memcmp(ram.data()+at+8,&o->center,sizeof(o->center))==0);}
    }
};
void room_objects_vm_tests(){
    std::vector<std::uint8_t> ram(0x900000);vm::FlagState flags;
    for(bool offline:{false,true})for(unsigned profile=0;profile<8;++profile)for(const auto op:{0xc2u,0xc3u,0xc4u,0xc5u,0xc6u,0xc7u})for(unsigned selector=0;selector<8;++selector)for(unsigned category=0;category<(offline?5u:1u);++category)for(unsigned relation=0;relation<(offline?3u:1u);++relation){
        assertion_context="room-object opcode="+std::to_string(op)+" profile="+std::to_string(profile)+" selector="+std::to_string(selector)+" offline="+std::to_string(offline)+" category="+std::to_string(category)+" relation="+std::to_string(relation);
        RoomObjectsFixture room(profile);room.export_original(ram);install_original_tables(ram);ram[0x3243e8]=1;ram[0x4baded]=0;fixture_write(ram.data(),0x75a4b0,category);fixture_write(ram.data(),0x75a4c0,relation);flags.restore(initial_flags());export_flags(ram,flags.snapshot());
        std::vector<std::byte> b;emit(b,0x110,{0,11});
        if(op==0xc2||op==0xc3){const unsigned arg[]={0,1,3,31,127,128,255,0x12345603};emit(b,op,{selector,arg[profile]});emit(b,0x110,{0,23});emit(b,0xe4);emit(b,0x110,{0,47});emit(b,0xe5);}
        else if(op==0xc4){const unsigned external[]={0,3,31,32,127,128,255,0x12345603};const unsigned x[]={0,1,15,16,127,128,255,0x12340007};emit(b,op,{external[selector],x[profile],profile==7?0x87654302u:profile});}
        else {const unsigned external[]={0,3,31,32,127,128,255,0x12345603};emit(b,op,{external[selector]});}
        emit(b,0x110,{1,99});const auto end=emit(b,0xa);vm::Interpreter native;
        if(offline)install_offline_program(native,ram,0,b);
        else{std::memcpy(ram.data()+0x10000,b.data(),b.size());fixture_write<std::uint32_t>(ram.data(),0x4bace0,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bad28,0x10000+end);fixture_write<std::uint32_t>(ram.data(),0x4bad40,0x90000);fixture_write<std::uint32_t>(ram.data(),0x90000,0x10000);fixture_write<std::uint32_t>(ram.data(),0x4bacf8,0);fixture_write<std::uint32_t>(ram.data(),0x4bad10,0);auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b});check(native.restore_channel(0,{program,{0,0},{0,end},0,0,0})==vm::Status::completed);}
        for(unsigned i=0;i<4;++i)fixture_write<std::uint32_t>(ram.data(),0x4bada8+4*i,0);
        if(offline)original_offline_call(ram,0,false);else{R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,29,0x7f0000);SET_GPR_U32(&c,31,0xdeadbeef);o2_0068C660_0x68c660(ram.data(),&c,&runtime);check(c.pc==0xdeadbeef);++invocations;}
        vm::Providers providers;providers.flags=&flags;providers.canonical_flags=&flags;providers.room_objects=&room.commands;const auto result=offline?native.tick_offline_channel(0,{true,false,0},{category,relation,0},providers):native.tick(0,{},providers);
        check(result.status==vm::Status::yielded);compare_offline_channels(native,ram);room.compare_original(ram);++room_object_dispatches;
    }
    {ro::Owner empty;vm::RoomObjectCommands uninitialized(empty);check(!uninitialized.ready(false));
        std::vector<std::byte> types(16),placements(8);types[0]=std::byte{};placements[0]=std::byte{2};auto imported=ro::Owner::import(types,placements);vm::RoomObjectCommands initialized(imported);check(initialized.ready(false));check(!initialized.ready(false,true));
        for(const auto op:{0xc2u,0xc3u,0xc5u}){std::vector<std::byte>b;emit(b,0x110,{0,88});emit(b,op,{0,0});const auto end=emit(b,0xa);vm::Interpreter native;const auto program=std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b});check(native.restore_channel(0,{program,{0,0},{0,end},0,0,0})==vm::Status::completed);vm::Providers p;p.room_objects=&uninitialized;check(native.tick(0,{},p).status==vm::Status::provider_unavailable);check(native.counters()[0]==0);p.room_objects=&initialized;const auto result=native.tick(0,{},p);if(op==0xc5){check(result.status==vm::Status::yielded);check(native.counters()[0]==88);}else{check(result.status==vm::Status::provider_unavailable);check(native.counters()[0]==0);}}
    }
    for(const auto op:{0xc2u,0xc3u})for(const auto index:{8u,127u,128u,255u}){bool refused=false;try{std::vector<std::byte>b;emit(b,op,{index,0});vm::Program p({b});}catch(const std::invalid_argument&){refused=true;}check(refused);}
    for(const auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
        RoomObjectsFixture room(0),foreign(0);std::vector<std::byte> b;emit(b,0x110,{0,88});emit(b,0xc4,{3,2,2});emit(b,0xa);vm::Interpreter native;check(native.install(0,std::make_shared<const vm::Program>(std::vector<std::vector<std::byte>>{b},profile))==vm::Status::completed);vm::Providers p;p.flags=&flags;p.canonical_flags=&flags;
        const auto tick=[&]{return profile==vm::DispatchProfile::ordinary?native.tick(0,{},p):native.tick_offline_channel(0,{},{0,0,0},p);};check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
        vm::RoomObjectCommands missing(room.owner),wrong(room.owner,foreign.lifetime);p.room_objects=&missing;check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);p.room_objects=&wrong;check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);room.lifetime.close();p.room_objects=&room.commands;check(tick().status==vm::Status::provider_unavailable);check(native.counters()[0]==0);
    }
}
}
