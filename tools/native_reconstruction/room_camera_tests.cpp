#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include "game/native/gameplay_scenario/room_camera.hpp"
#include "game/native/gameplay_scenario/room_camera_records.hpp"
#include "game/native/gameplay_scenario/sequence_control.hpp"
#include "game/native/gameplay_scenario/scene_models.hpp"
#include "game/native/gameplay_scenario/fog.hpp"
#include "game/native/gameplay_world/world.hpp"
#include <fstream>
#include <iostream>
#include <source_location>

namespace s=reo::native::gameplay_scenario;
namespace w=reo::native::gameplay_world;
namespace t=reo::native::transform_math;
namespace {
constexpr unsigned base=0x3dddb0,input=0x1000000,returned=0x1000;
std::size_t checks{},calls{},updates{},publications{},volumes{},owned{},refusals{};
std::array<unsigned,10> types{};std::string current;
void check(bool value,std::source_location where=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(current+" line "+std::to_string(where.line()));
}
template<class T>T read(const std::vector<std::uint8_t>& memory,unsigned at){return transform_read<T>(memory.data(),at);}
template<class T>void put(std::vector<std::byte>& data,unsigned at,T value){check(at+sizeof value<=data.size());std::memcpy(data.data()+at,&value,sizeof value);}
void same(float a,float b,std::source_location where=std::source_location::current()){
    ++checks;if(std::bit_cast<unsigned>(a)!=std::bit_cast<unsigned>(b))throw std::runtime_error(current+" float line "+std::to_string(where.line())+" native "+std::to_string(a)+" original "+std::to_string(b));
}
void same(t::Vector a,t::Vector b){same(a.x,b.x);same(a.y,b.y);same(a.z,b.z);}
void same(const t::Matrix& a,const t::Matrix& b){for(unsigned c=0;c<4;++c)for(unsigned r=0;r<4;++r)same(a[c][r],b[c][r]);}
struct Event {unsigned operation{};s::CameraViewport viewport;s::CameraProjectionMatrices projection;t::Matrix view;};
std::vector<Event> events;
struct Sink final:s::CameraDisplaySink {
    std::size_t cursor{};
    void viewport(const s::CameraViewport& viewport,const s::CameraProjectionMatrices& matrices)override{
        check(cursor<events.size());const auto& expected=events[cursor++];check(expected.operation==24);
        check(std::memcmp(&viewport,&expected.viewport,sizeof viewport)==0);
        same(matrices.perspective,expected.projection.perspective);same(matrices.scaled,expected.projection.scaled);
        same(matrices.first_composite,expected.projection.first_composite);same(matrices.second_composite,expected.projection.second_composite);++publications;
    }
    void view(const t::Matrix& matrix)override{check(cursor<events.size());const auto& expected=events[cursor++];check(expected.operation==22);same(matrix,expected.view);++publications;}
};
void invoke(std::vector<std::uint8_t>& memory,unsigned address,unsigned a0=0,unsigned a1=0){
    R5900Context ctx;PS2Runtime runtime;ctx.pc=address;SET_GPR_U32(&ctx,29,0x700000);SET_GPR_U32(&ctx,31,returned);
    SET_GPR_U32(&ctx,4,a0);SET_GPR_U32(&ctx,5,a1);original_transform_port(memory.data(),&ctx,&runtime);check(ctx.pc==returned);
}
w::Profile profile(){w::Profile result;result.layouts.push_back({});return result;}
struct Fixture {
    std::vector<std::uint8_t> memory=std::vector<std::uint8_t>(0x2000000);
    w::World world{profile(),std::make_shared<w::Session>()};
    s::SequenceControl sequences;s::CameraParameters parameters;
    s::CameraProjectionContext projection{320,224,640,448,t::identity(),t::identity()};
    s::CameraDisplayState display;Sink sink;std::int8_t mode{};
    s::CameraDisplayBinding binding{mode,projection,display,sink};
    s::Fog fog{s::FogState{}};s::SceneModels models{s::SceneModelState{},s::RoomModelRemap{}};
    std::shared_ptr<const s::RoomCameraRecords> asset;std::vector<std::uint8_t> imported;
    Fixture(std::span<const std::byte> bytes){
        asset=s::RoomCameraRecords::import(bytes);owned_constants(memory.data());
        std::memcpy(memory.data()+input,bytes.data(),bytes.size());invoke(memory,0x5be3e0,input,unsigned(bytes.size()));
        imported.assign(memory.begin()+base,memory.begin()+base+0x3334);
        for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->active=true;actor->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(actor)).id));}
        transform_write(memory.data(),0x294e00,t::identity());
        transform_write(memory.data(),0x2941a8,projection.horizontal_extent);transform_write(memory.data(),0x2941b0,projection.vertical_extent);
        transform_write(memory.data(),0x2941c8,projection.width);transform_write(memory.data(),0x2941d0,projection.height);
        transform_write(memory.data(),0x70003f80,projection.first_transform);transform_write(memory.data(),0x294dc0,projection.second_transform);
    }
    void reset(unsigned selected,unsigned count){
        sequences.install_camera_records(asset,std::uint8_t(selected));parameters={};display={};
        std::memcpy(memory.data()+base,imported.data(),imported.size());transform_write(memory.data(),base+0x24,std::uint8_t(selected));
        mode=std::bit_cast<std::int8_t>(std::uint8_t(count));transform_write(memory.data(),0x3243cf,mode);
        std::fill_n(memory.data()+0x324120,0x70,0);transform_write(memory.data(),0x49f762,std::uint16_t(count));
        fog=s::Fog(s::FogState{});std::array<std::byte,4> ignored{};check(fog.import_fog(ignored)==s::FogStatus::unsupported_version);
        transform_write(memory.data(),0x3240bd,std::uint8_t(255));
        for(unsigned i=0;i<128;++i){const auto value=std::uint8_t(i^0xaa);models.mark_slot_byte(std::uint8_t(i),value);memory[0x49eef0+0x8a0+i]=value;}
        world.session().resource_hide_selected=17;world.session().resource_hide_others=19;world.session().resource_hide_remaining={23,29};
        for(unsigned i=0;i<4;++i)memory[0x4b9d10+i]=std::array<std::uint8_t,4>{17,19,23,29}[i];
    }
    void position(t::Vector point){
        const auto selected=sequences.snapshot().actor;world.primary(selected)->position={point.x,point.y,point.z};
        transform_write(memory.data(),0x4a5c30+0x10e0u*selected+0x38,point);
    }
    void select(std::uint8_t index){check(sequences.select(index,1));transform_write(memory.data(),base+5,index);transform_write(memory.data(),base+6,std::uint16_t(1));memory[base+0x25]=4;memory[base+0x34+0x198u*index]=1;}
    void compare(){
        const auto& state=sequences.snapshot();
        if(state.condition_id!=memory[base+3]||state.selection_changed!=memory[base+4]||state.progress!=memory[base+0x26])
            throw std::runtime_error("selection native="+std::to_string(state.condition_id)+","+std::to_string(state.selection_changed)+","+std::to_string(state.progress)+
                " original="+std::to_string(memory[base+3])+","+std::to_string(memory[base+4])+","+std::to_string(memory[base+0x26]));
        ++checks;
        for(unsigned i=0;i<2;++i){same(state.camera_progress[i],read<float>(memory,base+8+4*i));same(state.camera_target[i],read<float>(memory,base+16+4*i));}
        check(read<unsigned>(memory,base+24)==(state.previous_camera?base+0x34+0x198u*(*state.previous_camera):0));
        check(state.view_masks.first==read<unsigned>(memory,base+0x1c)&&state.view_masks.second==read<unsigned>(memory,base+0x20));
        for(unsigned i=0;i<32;++i)same(state.camera_anchors[i],read<t::Vector>(memory,base+0x34+0x198*i+0x1c));
        for(unsigned i=0;i<128;++i)check(models.state().visibility[i]==memory[0x49eef0+0x8a0+i]);
        check(world.session().resource_hide_selected==memory[0x4b9d10]&&world.session().resource_hide_others==memory[0x4b9d11]);
        check(world.session().resource_hide_remaining[0]==memory[0x4b9d12]&&world.session().resource_hide_remaining[1]==memory[0x4b9d13]);
        check(std::uint8_t(fog.state().selected)==memory[0x3240bd]);
        same(parameters.pose.eye,read<t::Vector>(memory,0x324138));same(parameters.pose.aim,read<t::Vector>(memory,0x324144));
        same(parameters.offset,read<t::Vector>(memory,0x324150));same(parameters.pose.up,read<t::Vector>(memory,0x32415c));same(parameters.secondary_up,read<t::Vector>(memory,0x324168));
        same(parameters.distance,read<float>(memory,0x324174));same(parameters.far_plane,read<float>(memory,0x324178));
        same(parameters.near_plane,read<float>(memory,0x32417c));same(parameters.lens,read<float>(memory,0x324180));
        check(parameters.pitch==read<unsigned>(memory,0x324184)&&parameters.yaw==read<unsigned>(memory,0x324188)&&parameters.pose.roll==read<unsigned>(memory,0x32418c));
    }
    bool safe_follow()const{
        const auto selected=memory[base+5];const auto record=base+0x34+0x198u*selected;
        if(memory[record+1]!=8)return true;
        auto root=read<unsigned>(memory,record+0x184);if(!root)return false;
        if(read<unsigned>(memory,base+24)!=root)return true;
        // Independently bound the source pointer chase before executing the
        // original; invalid guest pointers are explicit native refusals.
        const auto actor=read<t::Vector>(memory,0x4a5c30+0x10e0u*memory[base+0x24]+0x38);
        const auto ratio=asset->boundary_ratio(selected,0,actor);check(bool(ratio));
        const auto desired=read<float>(memory,record+0x180)+*ratio;
        const auto previous=read<float>(memory,base+8),value=previous+(desired-previous)/6.f;
        if(!std::isfinite(value)||value<0||value>255)return false;
        for(unsigned i=0;i<unsigned(value);++i){const auto next=memory[root+0x166];if(next>=32)return false;root=base+0x34+0x198u*next;}
        return true;
    }
    void tick(unsigned count){
        events.clear();sink.cursor=0;invoke(memory,0x5bed30);
        s::RoomCamera camera(sequences,parameters);check(camera.update(world,models,count,fog,binding)==s::RoomCameraStatus::completed);
        check(sink.cursor==events.size());compare();++updates;
    }
    void volume(unsigned index,t::Vector point){
        position(point);R5900Context ctx;PS2Runtime runtime;ctx.pc=0x5bfca0;SET_GPR_U32(&ctx,29,0x700000);SET_GPR_U32(&ctx,31,returned);
        SET_GPR_U32(&ctx,4,index);SET_GPR_U32(&ctx,5,base+0x34+0x198u*index);original_transform_port(memory.data(),&ctx,&runtime);check(ctx.pc==returned);
        const auto native=asset->contains(std::uint8_t(index),point);check(bool(native)&&*native==bool(GPR_U32(&ctx,2)));++volumes;
    }
};
t::Vector center(const s::RoomCameraRecord& record){
    t::Vector result{};for(const auto& vertex:record.volume){result.x+=float(vertex[0])/8;result.y+=float(vertex[1])/8;result.z+=float(vertex[2])/8;}result.y-=10;return result;
}
void authored(std::span<const std::byte> bytes,unsigned ordinal){
    Fixture f(bytes);
    for(unsigned i=0;i<f.asset->count();++i){
        current="room"+std::to_string(ordinal)+"/record"+std::to_string(i);f.reset((ordinal+i)%8,69);
        const auto& record=f.asset->records()[i];++types[record.type];
        const auto point=center(record);f.volume(i,point);f.volume(i,record.anchor);f.volume(i,{point.x+10000,point.y+2000,point.z-10000});
        f.position(point);f.select(std::uint8_t(i));
        if(record.type==8&&!record.sequence_root){++refusals;continue;}
        f.tick(69);
        if(record.type!=8||f.safe_follow()){f.position({point.x+0.25f,point.y+1,point.z-0.125f});if(f.safe_follow())f.tick(69);}
    }
    // Actual source selection uses all active authored volumes, including the
    // zero-count/no-match fallback. Every room participates in this route.
    current="room"+std::to_string(ordinal)+"/selection";f.reset(ordinal%8,128);f.sequences.enable_all();
    for(unsigned i=0;i<f.asset->count();++i)f.memory[base+0x34+0x198*i]=1;
    f.position({0,0,0});
    // Type8 requires its loader-established root; malformed/unreached records
    // remain native refusals and are counted explicitly above.
    f.tick(128);++owned;
}
std::vector<std::byte> synthetic(){
    constexpr unsigned count=10,header=8+4*count;std::vector<std::byte> bytes(header+count*0x130);put(bytes,4,std::uint16_t(count));
    // Source boundary preparation projects the first four floor corners into
    // X/Z; upper corners follow in the same order. Both boundaries are finite.
    const std::array<s::CameraIntegerPoint,8> box{{{-100,100,-100},{100,100,-100},{100,100,100},{-100,100,100},{-100,-100,-100},{100,-100,-100},{100,-100,100},{-100,-100,100}}};
    for(unsigned i=0;i<count;++i){const auto at=header+0x130*i;put(bytes,8+4*i,at);put(bytes,at,i);
        put(bytes,at+0x1c,30.f);put(bytes,at+0x20,60.f);put(bytes,at+0x14,0xfffffff0u);put(bytes,at+0x18,0x80000001u);
        for(unsigned v=0;v<8;++v)put(bytes,at+0x24+12*v,box[v]);
        for(unsigned pair=0;pair<4;++pair)for(unsigned end=0;end<2;++end)put(bytes,at+0x84+24*pair+12*end,s::CameraIntegerPoint{int(end*50),int(50+pair*100),int(500+end*40)});
        put(bytes,at+0xfc,255u);put(bytes,at+0x100,255u);put(bytes,at+0x12c,i==9?255u:i);
        put(bytes,at+0x104,t::Vector{23,99,543});put(bytes,at+0x110,t::Vector{13,219,533});
        put(bytes,at+0x11c,0xaabbccddu);put(bytes,at+0x120,0x11223344u);put(bytes,at+0x124,0xau);
        for(unsigned j=0;j<16;++j)bytes[at+0xe4+j]=std::byte(0x96^j);
    }
    return bytes;
}
void boundaries(){
    auto bytes=synthetic();Fixture f(bytes);
    f.reset(0,128);f.volume(2,{0,0,0});check(f.asset->contains(2,{0,0,0})==true);
    for(unsigned type=0;type<10;++type){current="synthetic/type"+std::to_string(type);f.reset(type%8,type%2?0:128);f.position({0,0,0});f.select(std::uint8_t(type));f.tick(type%2?0:128);}
    current="hysteresis";f.reset(7,128);f.position({0,0,0});f.select(9);f.tick(128);f.select(2);
    for(unsigned tick=0;tick<12;++tick){f.tick(128);if(tick<8)check(f.sequences.snapshot().condition_id==9);}
    for(unsigned tick=0;tick<260;++tick){f.position({float(tick)-130,0,0});f.tick(128);}check(f.sequences.snapshot().progress==255);
    // Other consumers may change these flags between unchanged selections;
    // the source republishes them even when fog/visibility masks stay put.
    f.world.session().resource_hide_selected=17;f.world.session().resource_hide_others=19;
    f.world.session().resource_hide_remaining={23,29};
    for(unsigned i=0;i<4;++i)f.memory[0x4b9d10+i]=std::array<std::uint8_t,4>{17,19,23,29}[i];
    f.tick(128);
    current="automatic-priority-selection";f.reset(3,128);f.position({0,0,0});f.sequences.enable_all();
    for(unsigned i=0;i<10;++i)f.memory[base+0x34+0x198*i]=1;f.tick(128);
    current="no-match-retains-camera";auto no_match=f.sequences.snapshot();no_match.selection=0;no_match.active.fill(0);check(f.sequences.restore(no_match));
    for(unsigned i=0;i<32;++i)f.memory[base+0x34+0x198*i]=0;
    transform_write(f.memory.data(),base+6,std::uint16_t(0));f.tick(128);check(events.size()==2);
    for(unsigned priority:{7u,255u}){
        auto equal=synthetic();for(unsigned i=2;i<=4;++i)put(equal,48+0x130*i+0x12c,priority);
        Fixture tie(equal);current="tie/"+std::to_string(priority);tie.reset(4,128);tie.position({0,0,0});tie.select(3);tie.tick(128);
        auto state=tie.sequences.snapshot();state.selection=0;state.active.fill(0);for(unsigned i=2;i<=4;++i)state.active[i]=1;check(tie.sequences.restore(state));
        transform_write(tie.memory.data(),base+6,std::uint16_t(0));for(unsigned i=0;i<32;++i)tie.memory[base+0x34+0x198*i]=std::uint8_t(i>=2&&i<=4);
        tie.tick(128);check(tie.sequences.snapshot().condition_id==(priority==255?4:3));
        state=tie.sequences.snapshot();state.active[3]=0;state.active[4]=0;check(tie.sequences.restore(state));tie.memory[base+0x34+0x198*3]=0;tie.memory[base+0x34+0x198*4]=0;
        tie.tick(128);check(tie.sequences.snapshot().condition_id==2);
    }
    {
        auto sequence=synthetic();for(unsigned i=2;i<=4;++i){const auto at=48+0x130*i;
            put(sequence,at,8u);put(sequence,at+0xfc,i==2?255u:i-1);put(sequence,at+0x100,i==4?255u:i+1);put(sequence,at+0xf8,i-2);}
        Fixture linked(sequence);current="linked-sequence";linked.reset(6,128);linked.select(2);
        for(unsigned tick=0;tick<42;++tick){linked.position({tick<2?-150.f:tick<20?150.f:350.f,0,0});linked.tick(128);}
        check(linked.sequences.snapshot().previous_camera==2&&linked.sequences.snapshot().camera_progress[0]>2);
    }
    current="uninitialized";auto state=f.sequences.snapshot();state.initialized=0;state.selection_changed=1;check(f.sequences.restore(state));f.memory[base]=0;f.memory[base+4]=1;f.tick(128);check(events.empty());
    current="profile-refusals";state.initialized=1;state.selected_id=32;state.selection=1;check(f.sequences.restore(state));s::RoomCamera camera(f.sequences,f.parameters);
    check(camera.update(f.world,f.models,128,f.fog,f.binding)==s::RoomCameraStatus::unavailable);++refusals;
    state.selected_id=0;state.actor=8;state.condition_id=255;check(f.sequences.restore(state));
    check(camera.update(f.world,f.models,128,f.fog,f.binding)==s::RoomCameraStatus::unavailable);++refusals;
    check(!f.asset->contains(32,{}));++refusals;
}
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1af780:{Event e;e.operation=GPR_U32(context,4);check(e.operation==24||e.operation==22);
        if(e.operation==24){e.viewport=transform_read<s::CameraViewport>(memory,0x324120);
            e.projection={transform_read<t::Matrix>(memory,0x70003f00),transform_read<t::Matrix>(memory,0x294d00),transform_read<t::Matrix>(memory,0x294d40),transform_read<t::Matrix>(memory,0x294d80)};
        }else e.view=transform_read<t::Matrix>(memory,0x3240e0);
        events.push_back(e);context->pc=GPR_U32(context,31);return;
    }
    case 0x107ab0:case 0x107c68:{const auto dest=GPR_U32(context,4),source=GPR_U32(context,5),size=GPR_U32(context,6);
        check(dest<=0x2000000&&size<=0x2000000-dest);
        if(context->pc==0x107ab0){check(source<=0x2000000&&size<=0x2000000-source);std::memcpy(memory+dest,memory+source,size);}else std::memset(memory+dest,int(source&255),size);
        SET_GPR_U32(context,2,dest);context->pc=GPR_U32(context,31);return;
    }
    default:throw std::runtime_error("Unadmitted room camera helper "+std::to_string(context->pc));
    }
}
int main(int argc,char** argv)try{
    check(argc==2);std::ifstream stream(argv[1],std::ios::binary);check(bool(stream));unsigned count{};stream.read(reinterpret_cast<char*>(&count),4);check(count==166);
    for(unsigned i=0;i<count;++i){unsigned size{};stream.read(reinterpret_cast<char*>(&size),4);std::vector<std::byte> bytes(size);stream.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(stream));authored(bytes,i);}
    boundaries();for(unsigned type=1;type<10;++type)check(types[type]>0);
    std::cout<<"{\"checks\":"<<checks<<",\"original_calls\":"<<calls<<",\"owned_rooms\":"<<owned<<",\"updates\":"<<updates<<",\"publications\":"<<publications<<",\"volume_cases\":"<<volumes<<",\"refusals\":"<<refusals<<",\"game_run\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<current<<": "<<error.what()<<'\n';return 1;}
