#include "game/native/gameplay_world/primary_locomotion.hpp"
#include "game/native/gameplay_world/primary_turn.hpp"
#include "game/native/transform_math/heading.hpp"
#include <cstdio>
#include <fstream>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace r=reo::native::gameplay_collision::response;
namespace c=reo::native::gameplay_collision;
namespace t=reo::native::transform_math;
namespace {
unsigned checks{},cases{};
constexpr unsigned at=0x10000,work=0x20000,pointers=0x30000,second=0x31000,nodes=0x40000,second_nodes=0x50000,done=0x1234;
std::vector<std::uint8_t> ram(0x800000);
std::shared_ptr<a::Instance> reference_model;
const r::Grid* floors{};float matched=8.75f,last=120;std::int16_t turn{};
using Call=std::array<unsigned,4>;std::vector<Call> original_calls,native_calls;
unsigned bits(float x){return std::bit_cast<unsigned>(x);}
void check(bool value){++checks;if(!value)throw std::runtime_error("locomotion action check "+std::to_string(checks)+" case "+std::to_string(cases));}
template<class T>void put(unsigned p,T value){ref_write(ram.data(),p,value);}
template<class T>T get(unsigned p){return ref_read<T>(ram.data(),p);}
template<class T>void write(std::vector<std::byte>& b,unsigned p,T value){std::memcpy(b.data()+p,&value,sizeof value);}
std::shared_ptr<const a::Skeleton> skeleton(){
    std::vector<std::byte> raw(280);write(raw,4,4u);write(raw,8,280u);write(raw,16,1u);write(raw,20,16u);
    for(unsigned i=0;i<3;++i){const auto p=28+84*i;write(raw,p,1u);write(raw,p+4,1u);write(raw,p+8,84u);write(raw,p+20,i<2?int(i+1):-1);write(raw,p+24,-1);for(unsigned n=0;n<3;++n)write(raw,p+28+4*n,1.f);}
    return a::Skeleton::import_raw(raw);
}
r::Grid grid(unsigned type,float nx=0,float nz=0){
    const auto y=[&](float x,float z){return -nx*x-nz*z;};
    const r::Triangle triangle{type,{{{0,y(0,0),0},{2000,y(2000,0),0},{0,y(0,2000),2000}}},{nx,1,nz},0};
    std::vector<std::byte> raw(112);write(raw,8,2000u);write(raw,12,2000u);write(raw,16,1u);write(raw,20,1u);write(raw,32,32u);write(raw,36,48u);write(raw,40,40u);write(raw,48,0u);write(raw,52,0xffffffffu);std::memcpy(raw.data()+56,&triangle,56);return r::Grid::import(raw);
}
std::shared_ptr<const a::Clip> clip(){
    std::vector<std::byte> raw(140);write(raw,0,1u);write(raw,4,3u);write(raw,8,140u);write(raw,12,1u);write(raw,16,2.f);
    for(unsigned i=0;i<3;++i){const auto p=20+40*i;write(raw,p,0x80000000u);write(raw,p+4,1u);write(raw,p+8,40u);write(raw,p+12,0x80210040u);write(raw,p+16,2u);write(raw,p+20,28u);write(raw,p+24,0.f);write(raw,p+28,0.f);write(raw,p+32,float(i+1)*20);write(raw,p+36,20.f);}
    return a::Clip::import_raw(raw);
}
void channel(unsigned p,const a::MotionChannel& value){
    put(p,value.timing.frame);put(p+4,value.timing.end);put(p+8,value.timing.restart);put(p+12,value.timing.loop);put(p+13,value.timing.flags);put(p+14,value.selector);put(p+16,value.blend_increment);put(p+20,value.blend_position);put(p+24,value.blend_remaining);put(p+26,value.skip_flags);put(p+27,value.mode);put(p+28,value.auxiliary);
}
void export_actor(const w::Actor& actor){
    std::fill_n(ram.data()+at,0x2000,0);put(at+0x34,work);put(work,pointers);put(work+4,second);put(work+0x816,std::uint16_t(3));put(work+0x828,nodes+800);put(work+0xa24,second_nodes+400);
    for(unsigned i=0;i<3;++i){put(pointers+4*i,nodes+400*i);put(second+4*i,second_nodes+400*i);put(nodes+400*i+0x78,actor.model->local_translation(i).z);}
    ram[at+8]=actor.primary;ram[at+9]=actor.secondary;ram[at+10]=actor.phase;ram[at+11]=actor.subphase;
    put(at+0x38,actor.position);put(at+0x92,actor.orientation[1]);put(at+0x4e4,actor.root_motion_delta);put(at+0x520,actor.animation->motion);put(at+0x548,actor.action_flags);ram[at+0x54f]=actor.motion_class;
    put(at+0xba0,actor.status);put(at+0xba4,actor.auxiliary_status);put(at+0xba8,actor.motion_rate);put(at+0xbc0,actor.primary_state->statistic_multiplier);put(at+0xca8,actor.resource_action);ram[at+0xb98]=actor.character;ram[at+0xb9b]=actor.class_marker;put(at+0xce4,actor.locomotion->root_sample_z);ram[at+0xd10]=actor.locomotion->marker;
    put(at+0xd94,actor.saved_action_position);put(at+0xda0,actor.saved_action_yaw);
    for(unsigned b=0;b<2;++b)for(unsigned i=0;i<5;++i)channel(at+(b?0x364:0x1e4)+32*i,actor.animation->channel(b?a::ModelBank::secondary:a::ModelBank::primary,i));
    original_calls.clear();native_calls.clear();
}
void compare(const w::Actor& actor){
    check(actor.primary==ram[at+8]&&actor.secondary==ram[at+9]&&actor.phase==ram[at+10]&&actor.subphase==ram[at+11]);
    check(actor.orientation[1]==get<std::int16_t>(at+0x92));check(bits(actor.root_motion_delta.z)==get<unsigned>(at+0x4ec));
    check(actor.animation->motion==get<std::int16_t>(at+0x520));check(actor.action_flags==get<std::uint16_t>(at+0x548));check(actor.motion_class==ram[at+0x54f]);
    check(actor.auxiliary_status==get<unsigned>(at+0xba4));check(bits(actor.motion_rate)==get<unsigned>(at+0xba8));check(actor.locomotion->marker==ram[at+0xd10]);check(bits(actor.locomotion->root_sample_z)==get<unsigned>(at+0xce4));
    check(bits(actor.model->local_translation(2).z)==get<unsigned>(nodes+800+0x78));
    for(unsigned b=0;b<2;++b)for(unsigned i=0;i<5;++i){const auto& value=actor.animation->channel(b?a::ModelBank::secondary:a::ModelBank::primary,i);const auto p=at+(b?0x364:0x1e4)+32*i;
        check(bits(value.timing.frame)==get<unsigned>(p)&&bits(value.timing.end)==get<unsigned>(p+4)&&bits(value.timing.restart)==get<unsigned>(p+8));check(std::uint8_t(value.timing.loop)==ram[p+12]&&value.timing.flags==ram[p+13]&&value.selector==get<std::uint16_t>(p+14));
        check(bits(value.blend_increment)==get<unsigned>(p+16)&&bits(value.blend_position)==get<unsigned>(p+20)&&value.blend_remaining==get<std::uint16_t>(p+24)&&value.skip_flags==ram[p+26]&&value.mode==ram[p+27]&&value.auxiliary==get<unsigned>(p+28));
    }
    check(std::memcmp(&actor.saved_action_position,ram.data()+at+0xd94,12)==0&&actor.saved_action_yaw==get<std::int16_t>(at+0xda0));
    check(original_calls==native_calls);
}
struct Actions final:w::ActionAnimation {
    void select(w::Actor& actor,unsigned key,float initial,float blend)override{native_calls.push_back({0x5d4cf0,key,bits(initial),bits(blend)});actor.animation->motion=std::int16_t(key);}
    void activate(w::Actor& actor)override{native_calls.push_back({0x58c7b0,0,0,0});actor.animation->activate(5);}
    std::int8_t tick(w::Actor&,float rate)override{native_calls.push_back({0x58c300,0,bits(rate),0});return 0;}
    void or_flags(w::Actor& actor)override{actor.animation->or_primary_flags82();}
    float matched_frame(w::Actor&,unsigned key,std::uint16_t track)override{native_calls.push_back({0x5d4b10,key,track,0});return matched;}
    float last_frame(w::Actor&,unsigned key,std::uint16_t track)override{native_calls.push_back({0x5d4930,key,track,0});return last;}
};
void port(std::uint8_t* memory,R5900Context* ctx,PS2Runtime*){
    const auto p=GPR_U32(ctx,4);
    switch(ctx->pc){
    case 0x1921b0:{const auto value=t::sin_cos(ctx->f[12]);ref_write(memory,p,value.sine);ref_write(memory,GPR_U32(ctx,5),value.cosine);break;}
    case 0x192180:ctx->f[0]=t::quadrant_angle(ctx->f[12],ctx->f[13]);break;
    case 0x1919d0:{const auto value=t::direction(ref_read<t::Matrix>(memory,GPR_U32(ctx,6)),ref_read<t::Vector>(memory,GPR_U32(ctx,5)));ref_write(memory,p,value);break;}
    case 0x616f20:{const auto floor=floors->floor(ref_read<c::Vec3>(memory,p),std::uint8_t(GPR_U32(ctx,6)));memory[GPR_U32(ctx,5)]=floor.type;ctx->f[0]=floor.height;break;}
    case 0x616fa0:{const auto point=ref_read<c::Vec3>(memory,p);const auto floor=floors->floor(point);auto matrix=t::identity();matrix[1]={floor.normal.x,floor.normal.y,floor.normal.z,0};matrix[3]={point.x,floor.height,point.z,1};ref_write(memory,GPR_U32(ctx,5),matrix);break;}
    case 0x107c68:check(GPR_U32(ctx,5)==0&&GPR_U32(ctx,6)==32);std::memset(memory+p,0,32);break;
    case 0x5d4b10:case 0x5d4930:original_calls.push_back({ctx->pc,GPR_U32(ctx,5),GPR_U32(ctx,6),0});ctx->f[0]=ctx->pc==0x5d4b10?matched:last;break;
    case 0x5d4cf0:original_calls.push_back({ctx->pc,GPR_U32(ctx,5),bits(ctx->f[12]),bits(ctx->f[13])});ref_write(memory,p+0x520,std::uint16_t(GPR_U32(ctx,5)));break;
    case 0x58c7b0:original_calls.push_back({ctx->pc,0,0,0});for(unsigned b=0;b<2;++b)for(unsigned i=0;i<5;++i)memory[p+(b?0x364:0x1e4)+32*i+12]=1;break;
    case 0x58c300:original_calls.push_back({ctx->pc,0,bits(ctx->f[12]),0});SET_GPR_U32(ctx,2,0);break;
    case 0x193230:{check(bool(reference_model));reference_model->sample(std::uint16_t(GPR_U32(ctx,5)),ctx->f[12]);for(unsigned i=0;i<3;++i)ref_write(memory,second_nodes+400*i+0x40,reference_model->nodes()[i].local);break;}
    case 0x1925c0:{check(bool(reference_model));const auto delta=reference_model->translation_difference(1,ctx->f[12],ctx->f[13]);ref_write(memory,p,delta);break;}
    case 0x65f580:SET_GPR_S32(ctx,2,turn);break;
    default:throw std::runtime_error("Unexpected locomotion port "+std::to_string(ctx->pc));
    }ctx->pc=GPR_U32(ctx,31);
}
R5900Context invoke(unsigned entry,unsigned arg=0){R5900Context ctx{};ctx.pc=entry;ctx.g[4].lo=at;ctx.g[5].lo=arg;ctx.g[29].lo=0x100000;ctx.g[31].lo=done;PS2Runtime runtime;runtime.lookupFunction(entry)(ram.data(),&ctx,&runtime);check(ctx.pc==done);return ctx;}
w::Actor actor(const std::shared_ptr<const a::Skeleton>& definition){w::Actor result;result.model=std::make_shared<a::Instance>(definition);result.animation=std::make_shared<a::Playback>(result.model);result.primary_state=w::PrimaryActorState{};result.primary_state->statistic_multiplier=.75f;result.locomotion=w::PrimaryLocomotionState{};result.primary=1;result.position={500,1000,500};return result;}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned value)const{
    switch(value){
#define ENTRY(at) case 0x##at:return o2_00##at##_0x##at
    case 0x666bb0:return o2_00666BB0_0x666bb0;case 0x5d6910:return o2_005D6910_0x5d6910;case 0x66bdb0:return o2_0066BDB0_0x66bdb0;case 0x5d43c0:return o2_005D43C0_0x5d43c0;case 0x5d7bc0:return o2_005D7BC0_0x5d7bc0;case 0x5d7890:return o2_005D7890_0x5d7890;case 0x66c160:return o2_0066C160_0x66c160;case 0x66c4b0:return o2_0066C4B0_0x66c4b0;case 0x66c840:return o2_0066C840_0x66c840;case 0x6673c0:return o2_006673C0_0x6673c0;case 0x667370:return o2_00667370_0x667370;case 0x6673a0:return o2_006673A0_0x6673a0;case 0x58c7f0:return o2_0058C7F0_0x58c7f0;
#undef ENTRY
    case 0x66c040:return o2_0066C040_0x66c040;case 0x58bf50:return o2_0058BF50_0x58bf50;
    case 0x191bc0:return sub_00191BC0_0x191bc0;case 0x191ef0:return sub_00191EF0_0x191ef0;case 0x1920a0:return sub_001920A0_0x1920a0;
    default:return port;
    }
}
int main(int argc,char** argv)try{
    check(argc==3);std::ifstream ovl(argv[1],std::ios::binary);ovl.read(reinterpret_cast<char*>(ram.data()+0x570000),1913088);check(bool(ovl));
    std::ifstream elf(argv[2],std::ios::binary);const std::vector<std::uint8_t> bytes{std::istreambuf_iterator<char>(elf),{}};check(bytes.size()>52);
    const auto phoff=ref_read<unsigned>(bytes.data(),28);const auto phsize=ref_read<std::uint16_t>(bytes.data(),42),phcount=ref_read<std::uint16_t>(bytes.data(),44);
    for(unsigned i=0;i<phcount;++i){const auto p=phoff+phsize*i;if(ref_read<unsigned>(bytes.data(),p)!=1)continue;const auto off=ref_read<unsigned>(bytes.data(),p+4),address=ref_read<unsigned>(bytes.data(),p+8),size=ref_read<unsigned>(bytes.data(),p+16);if(!size)continue;check(address+size<ram.size());std::memcpy(ram.data()+address,bytes.data()+off,size);}
    const auto definition=skeleton();Actions actions;w::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<w::Session>());
    for(unsigned surface:{0u,1u})for(float nx:{-.5f,0.f,.5f})for(float nz:{-.5f,0.f,.5f}){const auto value=grid(surface,nx,nz);floors=&value;
        for(unsigned yaw=0;yaw<65536;yaw+=1021){++cases;auto subject=actor(definition);subject.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(yaw));export_actor(subject);const auto actual=invoke(0x5d6910);check(GPR_U32(&actual,2)==w::locomotion_floor_variant(subject,value));}
    }
    const auto flat=grid(0);floors=&flat;
    for(unsigned character=0;character<8;++character)for(unsigned selector:{0x65u,0x67u,0x68u})for(unsigned flags:{0u,2u,0x20u})for(unsigned frame=0;frame<8;++frame)for(unsigned clock:{0u,1u}){++cases;auto subject=actor(definition);subject.character=std::uint8_t(character);auto& channel=subject.animation->channel(a::ModelBank::primary,0);channel.selector=std::uint16_t(selector);channel.timing={float(frame),20,5,1,std::uint8_t(flags)};subject.model->local_translation(2,{1,2,float(frame*3)});subject.root_motion_delta.z=float(int(frame)-3);subject.locomotion->root_sample_z=4;put(0x3243cc,std::uint8_t(clock));export_actor(subject);invoke(0x5d7bc0);w::finish_locomotion_step(subject,std::uint8_t(clock));compare(subject);}
    for(unsigned health:{0u,1u,3u})for(unsigned character=0;character<8;++character)for(unsigned from:{0x2003u,0x2005u,0x2010u})for(unsigned to:{0x2003u,0x2005u,0x2013u})for(unsigned frame=0;frame<152;++frame){++cases;auto subject=actor(definition);subject.character=std::uint8_t(character);subject.class_marker=std::uint8_t(health);subject.animation->motion=std::int16_t(from);subject.animation->channel(a::ModelBank::primary,0).timing.frame=float(frame)+.25f;export_actor(subject);const auto expected=invoke(0x5d7890,to);const auto result=w::locomotion_transition_frame(subject,std::uint16_t(to),actions);check(bits(result)==bits(expected.f[0]));check(original_calls==native_calls);}
    for(unsigned surface:{0u,1u}){const auto value=grid(surface,.1f,.2f);floors=&value;
        for(unsigned state=3;state<=11;++state)for(unsigned phase:{0u,1u,2u,3u,255u})for(unsigned motion:{0x2003u,0x2004u,0x2005u,0x2012u,0x2050u})for(unsigned kind:{0u,1u,2u,3u,4u})for(unsigned flags:{0u,4u,0x80u}){++cases;auto subject=actor(definition);subject.secondary=std::uint8_t(state);subject.phase=std::uint8_t(phase);subject.motion_class=std::uint8_t(kind);subject.animation->motion=std::int16_t(motion);subject.character=1;subject.auxiliary_status=flags;subject.status=flags==0x80?0x80u:0;subject.motion_rate=.8f;subject.saved_action_position={8,9,10};subject.saved_action_yaw=123;subject.action_flags=7;subject.orientation[1]=14000;subject.root_motion_delta={1,2,3};
            auto& channel=subject.animation->channel(a::ModelBank::primary,0);channel.timing={65.5f,150,20,1,0};channel.selector=0x65;channel.blend_increment=.1f;channel.blend_position=.7f;channel.blend_remaining=3;channel.skip_flags=9;channel.mode=7;channel.auxiliary=0x1234;
            turn=w::primary_turn_step(world,subject);put(0x3243cc,world.session().clock_mode);export_actor(subject);invoke(state<6?0x66c160:state<9?0x66c4b0:0x66c840);w::update_locomotion_action(world,subject,value,actions);compare(subject);
        }
    }
    const auto asset=clip();const auto slope=grid(1,.1f,.2f);floors=&slope;
    for(unsigned clock:{0u,1u})for(float rate:{.3f,1.f,1.7f})for(float end:{18.f,27.f,41.f})for(float frame:{0.f,1.5f,7.f,19.f,25.f})for(unsigned flags:{0u,8u}){++cases;
        auto subject=actor(definition);auto& playback=*subject.animation;playback.secondary_model()->bind(0,asset);reference_model=std::make_shared<a::Instance>(*playback.secondary_model());
        playback.channel(a::ModelBank::primary,0).timing={2,40,1,1,std::uint8_t(flags)};playback.channel(a::ModelBank::secondary,0).timing={frame,end,2,1,0};subject.motion_rate=rate;
        export_actor(subject);put(0x3243cc,std::uint8_t(clock));invoke(0x66c040);w::advance_floor_locomotion(subject,std::uint8_t(clock),slope);
        const auto& timing=playback.channel(a::ModelBank::secondary,0).timing;check(bits(timing.frame)==get<unsigned>(at+0x364)&&timing.flags==ram[at+0x371]&&std::uint8_t(timing.loop)==ram[at+0x370]);
        const auto delta=playback.saved_delta();if(std::memcmp(&delta,ram.data()+at+0x4fc,12)!=0)std::fprintf(stderr,"delta actual %g %g %g expected %g %g %g\n",delta.x,delta.y,delta.z,get<float>(at+0x4fc),get<float>(at+0x500),get<float>(at+0x504));check(std::memcmp(&delta,ram.data()+at+0x4fc,12)==0);
        if(flags)for(unsigned i=0;i<3;++i){if(std::memcmp(&playback.secondary_model()->nodes()[i].local,ram.data()+second_nodes+400*i+0x40,64)!=0)std::fprintf(stderr,"model mismatch node %u\n",i);check(std::memcmp(&playback.secondary_model()->nodes()[i].local,ram.data()+second_nodes+400*i+0x40,64)==0);}
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"injured_transition_table_qualified\":false,\"nonzero_blend_qualified\":true,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
