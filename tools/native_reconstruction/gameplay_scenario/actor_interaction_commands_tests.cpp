#include "game/native/gameplay_scenario/actor_interaction_commands.hpp"
#include "game/native/gameplay_world/actor_initial_state.hpp"
#include "game/native/gameplay_scenario/interpreter.hpp"
#include "original_fixture.hpp"
#include "original_declarations.inc"
#include <iostream>
#include <source_location>
#include <vector>
namespace s=reo::native::gameplay_scenario;namespace w=reo::native::gameplay_world;
namespace {
unsigned checks{},calls{},dispatches{},refusals{},authored{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Actor interaction check at "+std::to_string(at.line()));
}
template<class T>void put(std::span<std::byte> bytes,unsigned at,T value){std::memcpy(bytes.data()+at,&value,sizeof value);}
using Bytes=std::vector<std::uint8_t>;
struct Command{std::uint32_t opcode;std::vector<std::uint32_t> payload;};
std::shared_ptr<const s::Program> program(std::span<const Command> commands,s::DispatchProfile profile=s::DispatchProfile::ordinary,bool prefix=false){
    std::vector<std::byte> bytes(4);put(std::span(bytes),0,1u);
    if(prefix){const auto at=bytes.size();bytes.resize(at+16);put(std::span(bytes),unsigned(at),0x02000110u);put(std::span(bytes),unsigned(at+4),0u);put(std::span(bytes),unsigned(at+8),77u);put(std::span(bytes),unsigned(at+12),0u);}
    for(const auto& command:commands){unsigned extent=4,shift=0;while(extent<4+4*command.payload.size()){extent*=2;++shift;}
        const auto at=bytes.size();bytes.resize(at+extent);put(std::span(bytes),unsigned(at),command.opcode|(shift<<24));
        for(unsigned i=0;i<command.payload.size();++i)put(std::span(bytes),unsigned(at+4+4*i),command.payload[i]);}
    const auto at=bytes.size();bytes.resize(at+4);put(std::span(bytes),unsigned(at),0xau);
    return std::make_shared<const s::Program>(std::vector<std::vector<std::byte>>{bytes},profile);
}
struct Fixture {
    std::shared_ptr<w::Session> session=std::make_shared<w::Session>();
    w::World world{{{w::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session};s::FlagState flags;s::SceneResources resources;
    Bytes memory=Bytes(0x900000);
    Fixture(){
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();w::initialize_cleared_actor_defaults(*actor);
            actor->active=i%2;actor->category=std::uint8_t(i%3);actor->status=0x5e0;actor->ai_control=std::uint8_t(i%2);
            actor->transient_action=std::uint8_t(i%2);actor->transient_equipment=17;actor->control_request={19,0xabcd};
            actor->interaction_request=w::InteractionRequest{21,22,{12.5f,-31.25f,73},0xffffaaccu,7.5f,23};
            actor->position={9,8,7};actor->previous_position={6,5,4};actor->orientation={13,-14,15,16};actor->previous_orientation={17,18,19,20};
            actor->action_flags=0x5511;actor->surface_blend_weight=7;actor->root_motion_delta={11,12,13};actor->collision.pose_ready=true;
            check(world.spawn_primary(i,std::move(actor)).status==reo::native::gameplay_actors::EntityStatus::completed);}
        std::vector<std::byte> packet(4+32*32);put(std::span(packet),0,32u);
        for(unsigned i=0;i<32;++i){const auto at=4+i*32;put(std::span(packet),at,std::int32_t(123456*i-2000000));
            put(std::span(packet),at+4,std::int32_t(123-77*i));put(std::span(packet),at+20,std::int32_t(-444*i));
            put(std::span(packet),at+8,std::int16_t(i*1831));
            std::memcpy(memory.data()+0x4b8a70+i*32,packet.data()+at,32);}
        check(session->actor_placements.load_positions(packet));
        for(unsigned i=0;i<4;++i)check(session->actor_placements.queue(i,std::uint8_t(31+i),std::uint8_t(21+i)));
        session->actor_placements.selected_request=0x2a;
        auto state=flags.snapshot();for(unsigned i=0;i<16;++i){state.primary[0][i]=0x12340000u+i;state.primary[1][i]=0x56780000u+i;state.auxiliary[0][i]=0x9abc0000u+i;}flags.restore(state);
        for(unsigned i=1;i<=8;++i){s::SceneDescriptor item;item.active=std::uint8_t(i%2);item.attachment_id=std::uint16_t(i%3==0?10206:10207);check(bool(resources.load(i,item)));}
    }
    s::TickResult run(std::span<const Command> commands,bool offline=false,s::OfflineDispatch dispatch={0,0,0},bool prefix=false,s::SceneResources* scenes=nullptr){
        s::Interpreter interpreter;check(interpreter.install(0,program(commands,offline?s::DispatchProfile::offline_actor:s::DispatchProfile::ordinary,prefix))==s::Status::completed);
        s::Providers providers;providers.world=&world;providers.flags=providers.canonical_flags=&flags;providers.scene_resources=scenes?scenes:&resources;
        const s::TickContext context{true,false,world.selected_actor};++dispatches;
        return offline?interpreter.tick_offline_channel(0,context,dispatch,providers):interpreter.tick(0,context,providers);
    }
};
void actor_memory(Bytes& bytes,const w::Actor& actor,unsigned index){
    auto* m=bytes.data();const auto at=0x4a5c30+index*0x10e0;
    transform_write(m,at,std::uint8_t(actor.active?0x80:0));m[at+2]=actor.category;m[at+3]=actor.slot;m[at+0xff0]=actor.ai_control;
    m[at+0xab8]=actor.transient_action;m[at+0xad4]=actor.transient_equipment;m[at+0xad5]=actor.control_request.kind;
    transform_write(m,at+0xad6,actor.control_request.parameter);transform_write(m,at+0xba0,actor.status);
    const auto& request=*actor.interaction_request;m[at+0xab9]=request.kind;m[at+0xaba]=request.parameter;
    transform_write(m,at+0xabc,request.anchor.x);transform_write(m,at+0xac0,request.anchor.y);transform_write(m,at+0xac4,request.anchor.z);
    transform_write(m,at+0xac8,request.orientation);transform_write(m,at+0xacc,request.travel_distance);m[at+0xad0]=request.endpoint;
    std::memcpy(m+at+0x38,&actor.position,12);std::memcpy(m+at+0x44,&actor.previous_position,12);
    std::memcpy(m+at+0x90,actor.orientation.data(),8);std::memcpy(m+at+0xa0,actor.previous_orientation.data(),8);
    transform_write(m,at+0x548,actor.action_flags);transform_write(m,at+0xb90,actor.surface_blend_weight);
    std::memcpy(m+at+0x4e4,&actor.root_motion_delta,12);
    std::memcpy(m+at+0xc84,actor.inventory.carried.data(),4);std::memcpy(m+at+0xc88,actor.inventory.storage.data(),32);
}
void state_memory(Bytes& bytes,const Fixture& fixture){
    for(unsigned i=0;i<8;++i)actor_memory(bytes,*fixture.world.primary(i),i);
    const auto& requests=fixture.session->actor_placements.requests();
    for(unsigned i=0;i<4;++i){bytes[0x4b9d00+i*3]=requests[i].state;bytes[0x4b9d01+i*3]=requests[i].room;bytes[0x4b9d02+i*3]=requests[i].position;}
    bytes[0x4badc0]=fixture.session->actor_placements.selected_request;bytes[0x4baded]=fixture.world.selected_actor;
    std::memcpy(bytes.data()+0x4b9a80,fixture.flags.snapshot().primary.data(),3*64);
    std::memcpy(bytes.data()+0x4b9b40,fixture.flags.snapshot().auxiliary.data(),3*64);
    for(unsigned i=1;i<=8;++i){const auto item=*fixture.resources.get(*fixture.resources.slot(i));bytes[0x3c5630+i*60]=item.active;transform_write(bytes.data(),0x3c5630+i*60+6,item.attachment_id);}
}
void original(Fixture& fixture,const Command& command){
    constexpr unsigned payload=0x10000;
    for(unsigned i=0;i<command.payload.size();++i)transform_write(fixture.memory.data(),payload+4*i,command.payload[i]);
    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x880000);SET_GPR_U32(&context,31,0x100);SET_GPR_U32(&context,4,payload);
    switch(command.opcode){
    case 0x6c:context.pc=0x68f420;o2_0068F420_0x68f420(fixture.memory.data(),&context,&runtime);break;
    case 0x106:context.pc=0x692480;o2_00692480_0x692480(fixture.memory.data(),&context,&runtime);break;
    case 0x172:context.pc=0x694ad0;o2_00694AD0_0x694ad0(fixture.memory.data(),&context,&runtime);break;
    default:std::terminate();}
    check(context.pc==0x100&&GPR_U32(&context,2)==0);++calls;
}
void compare(Fixture& fixture,std::span<const Command> commands,bool offline=false){
    state_memory(fixture.memory,fixture);auto expected=fixture.memory;
    for(const auto& command:commands)original(fixture,command);
    const auto result=fixture.run(commands,offline);if(result.status!=s::Status::yielded)throw std::runtime_error("dispatch "+std::to_string(commands[0].opcode)+" status="+std::to_string(int(result.status)));
    state_memory(expected,fixture);
    for(unsigned i=0;i<8;++i)check(std::equal(expected.begin()+0x4a5c30+i*0x10e0,expected.begin()+0x4a5c30+(i+1)*0x10e0,fixture.memory.begin()+0x4a5c30+i*0x10e0));
    check(std::equal(expected.begin()+0x4b9a80,expected.begin()+0x4b9a80+6*64,fixture.memory.begin()+0x4b9a80));
    check(std::equal(expected.begin()+0x4b9d00,expected.begin()+0x4b9d00+12,fixture.memory.begin()+0x4b9d00));
    check(expected[0x4badc0]==fixture.memory[0x4badc0]);
    check(std::equal(expected.begin()+0x3c5630,expected.begin()+0x3c5630+9*60,fixture.memory.begin()+0x3c5630));
}
void placements(){
    for(bool offline:{false,true})for(unsigned selected=0;selected<4;++selected)for(unsigned selector=0;selector<8;++selector)
    for(const unsigned command:{0u,18u,20u,255u,0xf0u,0xf1u,0x1f0u,0x1f1u}){
        if((command&255)!=0xf0&&(command&255)!=0xf1&&selector>=5)continue;
        Fixture fixture;fixture.world.selected_actor=std::uint8_t(selected);
        const std::array commands{Command{0x6c,{selector|0x100u,command,31|0x200u,0x12345678u}}};compare(fixture,commands,offline);
        const auto actor=fixture.world.primary(selector==4?selected:selector);check(actor->transient_equipment==1&&actor->control_request.kind==0x78&&actor->control_request.parameter==0xabcd);
    }
}
void anchors(){
    constexpr std::uint32_t values[]{0,1,0x7fffffff,0x80000000u,0x80000001u,0xffffff00u,0xfffffffdu,0xffffffffu,3822,4294966196u};
    for(bool offline:{false,true})for(unsigned selected=0;selected<8;++selected)for(unsigned selector=0;selector<8;++selector)for(unsigned index=0;index<std::size(values);++index){
        Fixture fixture;fixture.world.selected_actor=std::uint8_t(selected);
        const std::array commands{Command{0x106,{selector,values[index],values[(index+1)%std::size(values)],values[(index+2)%std::size(values)],0xdead8000u|index}}};
        compare(fixture,commands,offline);
    }
    // A pose producer followed by immediate placement is admitted in one VM
    // program. Program entry must not demand a request produced by its first command.
    Fixture fixture;fixture.world.primary(0)->interaction_request.reset();fixture.world.primary(0)->transient_action=0;
    const std::array commands{Command{0x106,{0,3822,4294966196u,909,32768}},Command{0x6c,{0,0xf1,0,30}}};
    check(fixture.run(commands).status==s::Status::yielded);const auto actor=fixture.world.primary(0);
    check(actor->position.x==3822&&actor->position.y==4294966272.0f&&actor->orientation[1]==-32768&&actor->control_request.kind==30);
}
void inventories(){
    constexpr std::uint32_t flags[]{0,31,32,73,74,255,256,511};
    for(bool offline:{false,true})for(unsigned selected=0;selected<8;++selected)for(unsigned trial=0;trial<24;++trial)for(const auto flag:flags){
        Fixture fixture;fixture.world.selected_actor=std::uint8_t(selected);auto actor=fixture.world.primary(selected);
        actor->active=trial%5!=0;actor->ai_control=std::uint8_t(trial%4);actor->status=0x5e0;actor->category=std::uint8_t(trial%3);
        actor->inventory.carried.fill(0);actor->inventory.storage.fill(0);
        if(trial%3==0)actor->inventory.carried[3]=3;
        else if(trial%3==1)actor->inventory.storage[31]=6;
        else actor->inventory.carried[0]=2;
        const std::array commands{Command{0x172,{0xabcd0000u|std::uint32_t(trial%2?10206:10207),flag}}};compare(fixture,commands,offline);
    }
}
void boundaries(){
    Fixture fixture;fixture.world.selected_actor=0;auto actor=fixture.world.primary(0);s::Interpreter interpreter;s::Providers providers;
    providers.world=&fixture.world;providers.flags=providers.canonical_flags=&fixture.flags;
    const std::array inventory{Command{0x172,{10206,73}}};
    check(interpreter.install(0,program(inventory,s::DispatchProfile::ordinary,true))==s::Status::completed);actor->active=true;actor->ai_control=0;
    check(interpreter.tick(0,{},providers).status==s::Status::provider_unavailable);check(interpreter.counters()[0]==0);++refusals;
    actor->active=false;check(interpreter.tick(0,{},providers).status==s::Status::yielded);
    check(interpreter.install(0,program(inventory))==s::Status::completed);actor->active=true;actor->ai_control=1;
    check(interpreter.tick(0,{},providers).status==s::Status::yielded);
    for(const Command& command:{Command{0x172,{10206,512}},Command{0x172,{10206,0xffffffffu}},Command{0x106,{0x100,1,2,3,0}},Command{0x6c,{8,18,1,12}}}){
        bool rejected{};try{const std::array commands{command};(void)program(commands);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
    }
    for(const auto header:{0x01000172u,0x0200006cu,0x02000106u}){
        std::vector<std::byte> bytes(s::Program::record_bytes(header));put(std::span(bytes),0,header);bool rejected{};
        try{const s::Program truncated({bytes});}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
    }
    actor->interaction_request.reset();actor->transient_action=1;const auto before=actor->transient_equipment;
    for(const Command& command:{Command{0x106,{0,1,2,3,0}},Command{0x6c,{0,0xf0,1,12}},Command{0x6c,{0,0xf1,1,12}}}){
        const std::array commands{command};check(fixture.run(commands).status==s::Status::provider_unavailable);check(!actor->interaction_request&&actor->transient_equipment==before);++refusals;
    }
    actor->transient_action=0;const std::array unsupported_preset{Command{0x6c,{0,0xf0,32,12}}};bool rejected{};
    try{(void)program(unsupported_preset);}catch(const std::invalid_argument&){rejected=true;}check(rejected);++refusals;
    Fixture blank;auto no_pose=blank.world.primary(0);no_pose->interaction_request.reset();no_pose->transient_action=0;
    const std::array create{Command{0x106,{0,1,2,3,0xffffffffu}}};check(blank.run(create).status==s::Status::yielded);
    check(no_pose->interaction_request&&no_pose->interaction_request->orientation==0xffffffffu&&!no_pose->transient_action);
    const std::array no_anchor{Command{0x6c,{0,0xf1,0,12}}};check(interpreter.install(0,program(no_anchor,s::DispatchProfile::ordinary,true))==s::Status::completed);
    check(interpreter.tick(0,{},providers).status==s::Status::provider_unavailable);check(interpreter.counters()[0]==77);check(!actor->interaction_request&&actor->transient_equipment==before);++refusals;
}
void authored_records(){
    const std::array commands_from_owned_content{
#include "authored_commands.inc"
    };
    for(const auto& command:commands_from_owned_content){
        Fixture fixture;const std::array commands{command};compare(fixture,commands);++authored;
    }
}
}
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    switch(c->pc){
#include "original_lookup.inc"
    default:throw std::runtime_error("Unexpected interaction boundary "+std::to_string(c->pc));
    }
}
int main()try{
    placements();anchors();inventories();boundaries();authored_records();
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"dispatches\":"<<dispatches<<",\"refusals\":"<<refusals<<",\"authored_records\":"<<authored<<"}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
