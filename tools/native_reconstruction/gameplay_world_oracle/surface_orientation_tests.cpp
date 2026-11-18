#include "game/native/gameplay_world/surface_orientation.hpp"
#include "game/native/gameplay_world/surface_orientation_math.hpp"
#include "reference.hpp"
#include <iostream>
#include <vector>
namespace g=reo::native::gameplay_world;
namespace t=reo::native::transform_math;
namespace s=g::surface_math;
namespace c=reo::native::gameplay_collision;
#include "owned_constants.hpp"
#include "orientation_constants.hpp"
#include "functions.h"
constexpr std::uint32_t base=0x10000;
std::uint64_t checks{},turn_cases{},orientation_cases{},basis_cases{},failure_cases{},grid_pose_cases{},frame_cases{},helper_calls{},floor_calls{},not_requested{},rejected{},adjusted{};
void check(bool yes,const std::string& why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
bool bits(float a,float b){return std::bit_cast<std::uint32_t>(a)==std::bit_cast<std::uint32_t>(b);}
bool same(s::Vector a,s::Vector b){return bits(a.x,b.x)&&bits(a.y,b.y)&&bits(a.z,b.z);}
std::uint32_t random_word(std::uint32_t& x){x^=x<<13;x^=x>>17;x^=x<<5;return x;}
g::Profile profile(){return{{g::input::Remap{0x100,0x20,0x10}},4,{16,UINT64_MAX}};}
t::Matrix matrix(const c::actors::Basis& b){return{{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
auto basis(const t::Matrix& m){return c::actors::Basis{{m[0][0],m[0][1],m[0][2]},{m[1][0],m[1][1],m[1][2]},{m[2][0],m[2][1],m[2][2]},{m[3][0],m[3][1],m[3][2]}};}
g::Actor import_actor(const std::uint8_t* p){
 g::Actor a;a.category=get<std::uint8_t>(p,base+2);a.status=get<std::uint32_t>(p,base+0xba0);a.action_flags=get<std::uint16_t>(p,base+0x548);a.position=get<g::Position>(p,base+0x38);a.orientation=get<std::array<std::int16_t,4>>(p,base+0x90);a.collision.basis=basis(get<t::Matrix>(p,base+0x50));a.candidate_direction=get<g::Position>(p,base+0xa8);a.surface_normal=get<g::Position>(p,base+0x178);a.surface_blend_weight=get<float>(p,base+0xb90);a.surface_blend_rate=get<float>(p,base+0xb94);a.local_impulse=get<g::Position>(p,base+0xd8);a.world_impulse=get<g::Position>(p,base+0xe4);return a;
}
void export_actor(std::uint8_t* p,const g::Actor& a){
 put(p,base+2,a.category);put(p,base+0xba0,a.status);put(p,base+0x548,a.action_flags);put(p,base+0x38,a.position);put(p,base+0x90,a.orientation);put(p,base+0x50,matrix(a.collision.basis));put(p,base+0xa8,a.candidate_direction);put(p,base+0x178,a.surface_normal);put(p,base+0xb90,a.surface_blend_weight);put(p,base+0xb94,a.surface_blend_rate);put(p,base+0xd8,a.local_impulse);put(p,base+0xe4,a.world_impulse);
}
using Observation=std::array<std::uint32_t,30>;
Observation observed(const std::uint8_t* memory){
 Observation r{};std::size_t at{};for(auto [offset,count]:{std::pair{0x38u,3u},{0x178u,3u},{0xa8u,3u},{0x50u,16u},{0xb90u,2u}})for(unsigned i=0;i<count;++i)r[at++]=get<std::uint32_t>(memory,base+offset+4*i);r[at++]=get<std::uint16_t>(memory,base+0x548);r[at++]=get<std::uint8_t>(memory,base+2);r[at++]=get<std::uint32_t>(memory,base+0xba0);return r;
}
Observation observed(const g::Actor& a){
 Observation r{};std::size_t at{};const auto vec=[&](const auto& v){r[at++]=std::bit_cast<std::uint32_t>(v.x);r[at++]=std::bit_cast<std::uint32_t>(v.y);r[at++]=std::bit_cast<std::uint32_t>(v.z);};vec(a.position);vec(a.surface_normal);vec(a.candidate_direction);for(const auto& col:matrix(a.collision.basis))for(float v:col)r[at++]=std::bit_cast<std::uint32_t>(v);r[at++]=std::bit_cast<std::uint32_t>(a.surface_blend_weight);r[at++]=std::bit_cast<std::uint32_t>(a.surface_blend_rate);r[at++]=a.action_flags;r[at++]=a.category;r[at++]=a.status;return r;
}
struct Probe {s::Vector point;Observation actor;};
bool operator==(const Probe& a,const Probe& b){return same(a.point,b.point)&&a.actor==b.actor;}
unsigned provider_seed{},original_floor_index{};int throw_at=-1;
std::array<float,3> heights{};
const c::response::Grid* grid_source{};
std::vector<Probe> original_observations;
void effect(g::Actor& a,unsigned i){
 if(i==0&&(provider_seed&1)){a.position={97.5f,12.75f,-31.25f};a.surface_normal={.125f,.75f,-.25f};a.surface_blend_weight=.375f;}
 if(i==1&&(provider_seed&2)){a.candidate_direction={.5f,.25f,1};a.collision.basis.x={.75f,.125f,-.25f};a.collision.basis.translation={98,97,96};}
 if(i==2&&(provider_seed&4)){a.action_flags^=0x40;a.surface_blend_rate=-.25f;}
}
struct Floors final:g::SurfaceOrientationFloors {
 g::Actor* expected{};unsigned index{};std::vector<Probe> observations;
 c::response::Floor sample(g::World&,g::Actor& a,c::Vec3 p)override{
  check(&a==expected,"floor sees canonical actor identity");const unsigned i=index++;check(i<3,"bounded three native probes");observations.push_back({{p.x,p.y,p.z},observed(a)});effect(a,i);++floor_calls;
  if(int(i)==throw_at)throw std::runtime_error("required native floor failure");
  auto r=grid_source?grid_source->floor(p,255):c::response::Floor{};if(!grid_source)r.height=heights[i];return r;
 }
};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
 ++helper_calls;
 if(context->pc==0x617000){
  check(GPR_U32(context,8)==255&&GPR_U32(context,11)==0,"actual616F20 wrapper FF/mode0 ABI");const auto p=get<s::Vector>(memory,GPR_U32(context,4));const unsigned i=original_floor_index++;check(i<3,"bounded three source probes");original_observations.push_back({p,observed(memory)});auto a=import_actor(memory);effect(a,i);export_actor(memory,a);
  if(int(i)==throw_at)throw std::runtime_error("reference native floor seam failure");
  auto r=grid_source?grid_source->floor({p.x,p.y,p.z},255):c::response::Floor{};if(!grid_source)r.height=heights[i];put(memory,GPR_U32(context,5),r.normal);put(memory,GPR_U32(context,7),r.type);put(memory,GPR_U32(context,9),r.material);put(memory,GPR_U32(context,10),r.attributes);context->f[0]=r.height;context->pc=GPR_U32(context,31);return;
 }
 switch(context->pc){
#include "original_dispatch.hpp"
 default:throw std::runtime_error("undeclared surface original helper "+std::to_string(context->pc));
 }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_surface.cpp"
#pragma GCC diagnostic pop
unsigned execute(std::uint8_t* ram,bool pose=false){
 R5900Context context;context.pc=pose?0x65e4a0:0x6657b0;SET_GPR_U32(&context,4,base);SET_GPR_U32(&context,29,0x30000);SET_GPR_U32(&context,31,0xabcdef);PS2Runtime runtime;
 if(pose)o2_0065E4A0_0x65e4a0(ram,&context,&runtime);else o2_006657B0_0x6657b0(ram,&context,&runtime);
 check(context.pc==0xabcdef&&GPR_U32(&context,29)==0x30000,"complete original returns synchronously");return GPR_U32(&context,2);
}
void call(std::uint8_t* ram,std::uint32_t address,std::uint32_t output,std::uint32_t a1=0,std::uint32_t a2=0,float f12=0,float f13=0){
 R5900Context ctx;ctx.pc=address;SET_GPR_U32(&ctx,4,output);SET_GPR_U32(&ctx,5,a1);SET_GPR_U32(&ctx,6,a2);SET_GPR_U32(&ctx,29,0x30000);SET_GPR_U32(&ctx,31,0xabcdef);ctx.f[12]=f12;ctx.f[13]=f13;PS2Runtime rt;original_transform_port(ram,&ctx,&rt);check(ctx.pc==0xabcdef,"original helper return");
}
c::response::Grid make_grid(float slope,std::uint32_t flags){
 std::vector<std::uint8_t> bytes(256);const auto word=[&](unsigned at,std::uint32_t v){std::memcpy(bytes.data()+at,&v,4);};word(8,1000);word(12,1000);word(16,1);word(20,1);word(32,32);word(36,56);word(40,36);word(48,56);word(52,UINT32_MAX);
 const c::response::Triangle a{flags,{{{0,0,0},{1000,slope*1000,0},{0,0,1000}}},{-slope,1,0},0},b{flags,{{{1000,slope*1000,0},{1000,slope*1000,1000},{0,0,1000}}},{-slope,1,0},0};std::memcpy(bytes.data()+64,&a,56);std::memcpy(bytes.data()+120,&b,56);return c::response::Grid::import(std::as_bytes(std::span(bytes)));
}
struct Frame final:g::Services {
 unsigned local_delegations{},pose_delegations{},later{};g::Actor* expected{};
 void begin_offline_frame(g::World&)override{}
 void run(g::Stage stage,g::World&,g::Actor& a)override{check(&a==expected,"World keeps canonical actor");local_delegations+=stage==g::Stage::update_local_motion;pose_delegations+=stage==g::Stage::update_pose;}
 bool remote_motion(g::World&,g::Actor&)override{return false;}
 bool find_grid(g::World&,g::Actor&,std::int8_t&)override{++later;return false;}
 void switch_grid(g::World&,std::int32_t,std::int32_t)override{}
 float grid_response(g::World&,std::uint8_t)override{return 0;}
};
struct QueriedPose final:g::MotionTransformServices {
 Floors& floors;explicit QueriedPose(Floors& f):floors(f){}
 void orient_surface(g::World& w,g::Actor& a)override{(void)g::update_surface_orientation(w,a,floors);}
};
int main()try{
 const auto old_mxcsr=_mm_getcsr();struct Reset{unsigned old;~Reset(){_mm_setcsr(old);}}reset{old_mxcsr};_mm_setcsr(0x1f80);
 std::vector<std::uint8_t> actual(0x2000000,0xa5),expected(actual);owned_constants(expected.data());orientation_constants(expected.data());put(expected.data(),0x294e00,t::identity());std::uint32_t random=0x6657b0;
 const auto number=[&]{return float(std::int32_t(random_word(random)%2049)-1024)*.125f;};g::World world(profile(),std::make_shared<g::Session>());
 for(unsigned turn=0;turn<65536;++turn){
  s::Vector v{1.25f,-3.5f,-40.f};put(expected.data(),0x50000,v);call(expected.data(),0x191bc0,0x50000,0,0,(std::bit_cast<float>(0x40c90fdbu)*float(turn))/65536.f);check(same(s::rotate_probe(v,std::uint16_t(turn)),get<s::Vector>(expected.data(),0x50000)),"direct probe rotation turn "+std::to_string(turn));
  R5900Context ctx;ctx.pc=0x370100;SET_GPR_U32(&ctx,4,turn);SET_GPR_U32(&ctx,31,0xabcdef);PS2Runtime rt;o0_00370100_0x370100(expected.data(),&ctx,&rt);check(ctx.pc==0xabcdef&&bits(s::turn_cosine(std::uint16_t(turn)),ctx.f[0]),"cosine helper turn "+std::to_string(turn));++turn_cases;
 }
 for(unsigned i=0;i<4096;++i){
  s::Vector n{number(),number(),number()},h{number(),number(),number()};if(i<3){n=i==0?s::Vector{}:s::Vector{0,1,0};h=i==2?s::Vector{}:n;}
  put(expected.data(),0x50000,n);put(expected.data(),0x50010,h);put(expected.data(),0x50100,t::identity());call(expected.data(),0x191740,0x50100,0x50000,0x50010);const auto next=s::normal_basis(n,h);check(std::memcmp(&next,expected.data()+0x50100,sizeof next)==0,"normal basis helper "+std::to_string(i));
  auto old=t::identity();for(auto& col:old)for(unsigned lane=0;lane<3;++lane)col[lane]=number();const float a=float(int(i%17)-8)*.125f,b=float(int(i%13)-6)*.25f;put(expected.data(),0x50200,old);put(expected.data(),0x50300,next);call(expected.data(),0x191900,i&1?0x50200:0x50400,0x50200,0x50300,a,b);const auto blended=s::blend_basis(old,next,a,b);check(std::memcmp(&blended,expected.data()+(i&1?0x50200:0x50400),sizeof blended)==0,"blend basis helper "+std::to_string(i));++basis_cases;
 }
 const auto compare=[&](g::Actor& actor,unsigned seed,bool fails=false){
  std::fill(actual.begin()+base,actual.begin()+base+0x10e0,0xa5);export_actor(actual.data(),actor);std::copy_n(actual.data()+base,0x10e0,expected.data()+base);provider_seed=seed;original_floor_index=0;original_observations.clear();Floors floors;floors.expected=&actor;bool nf{},of{};unsigned native_result=99,original_result=99;
  try{native_result=unsigned(g::update_surface_orientation(world,actor,floors));}catch(const std::runtime_error&){nf=true;}
  export_actor(actual.data(),actor);try{original_result=execute(expected.data());}catch(const std::runtime_error&){of=true;}
  check(nf==fails&&of==fails,"declared floor failure parity");check(floors.observations==original_observations,"source ordered floor point/canonical state differs");
  if(std::memcmp(actual.data()+base,expected.data()+base,0x10e0)!=0){for(unsigned j=0;j<0x10e0;++j)if(actual[base+j]!=expected[base+j])throw std::runtime_error("6657B0 actor mismatch seed "+std::to_string(seed)+" offset "+std::to_string(j));}
  ++checks;check(fails||native_result==original_result,"original 0/1 return meaning");if(fails){++failure_cases;return;}++orientation_cases;if(native_result==1){++not_requested;check(floors.index==0,"unrequested work has no probes");}else{check(floors.index==3,"requested work makes all three probes");if(actor.action_flags&1)++adjusted;else ++rejected;}
 };
 for(unsigned i=0;i<8192;++i){
  g::Actor a;a.category=std::uint8_t(i);a.status=random_word(random);a.action_flags=std::uint16_t(i%5?random_word(random)|1:random_word(random)&~1u);a.position={number(),number(),number()};a.orientation={0,std::int16_t(random_word(random)),0,0};a.candidate_direction={number(),number(),number()};a.surface_normal={number(),float(int(i%21)-10)*.125f,number()};a.surface_blend_weight=float(int(i%29)-7)*.125f;a.surface_blend_rate=float(int(i%7)-3)*.125f;auto m=t::identity();for(auto& col:m)for(unsigned k=0;k<3;++k)col[k]=number();a.collision.basis=basis(m);heights={number(),number(),number()};compare(a,i);
 }
 // Ordered 80-unit boundaries, threshold adjacent values, all 256 categories.
 for(unsigned i=0;i<256;++i){g::Actor a;a.category=std::uint8_t(i);a.status=8;a.action_flags=1;a.surface_blend_weight=.5f;a.surface_blend_rate=-0.f;a.candidate_direction={0,0,1};a.surface_normal={0,s::turn_cosine(0x100),0};heights={0,i&1?80.f:std::nextafter(80.f,INFINITY),i&2?-80.f:std::nextafter(-80.f,-INFINITY)};compare(a,0);a.surface_normal.y=std::nextafter(a.surface_normal.y,INFINITY);heights={0,0,0};compare(a,0);a.surface_normal.y=std::nextafter(s::turn_cosine(0x100),-INFINITY);compare(a,0);}
 for(unsigned sequence=0;sequence<16;++sequence){g::Actor a;a.category=std::uint8_t(sequence);a.status=8;a.action_flags=std::uint16_t(sequence&1);a.surface_blend_rate=sequence&2?-.125f:.125f;a.surface_blend_weight=.5f;a.candidate_direction={0,0,1};a.surface_normal={0,.75f,0};a.orientation[1]=std::int16_t(sequence*4093);for(unsigned tick=0;tick<20;++tick){heights={0,float(int(tick%5)-2)*8.f,float(int(tick%7)-3)*8.f};compare(a,0);if(tick==10)a.surface_blend_rate=-.125f;}}
 for(int failure=0;failure<3;++failure){g::Actor a;a.action_flags=1;a.surface_normal={0,.75f,0};a.candidate_direction={0,0,1};a.surface_blend_rate=.25f;heights={0,0,0};throw_at=failure;compare(a,7,true);}throw_at=-1;
 // A skipped branch must not inspect unsupported, unused numerical state.
 {g::Actor a;a.category=255;a.action_flags=0;a.surface_blend_weight=NAN;a.position={NAN,INFINITY,NAN};Floors f;f.expected=&a;check(g::update_surface_orientation(world,a,f)==g::SurfaceOrientationResult::not_requested&&f.index==0,"no request preserves unconsumed numeric state");}
 {g::Actor a;a.action_flags=1;a.surface_blend_weight=INFINITY;Floors f;f.expected=&a;bool failed{};try{g::update_surface_orientation(world,a,f);}catch(const std::domain_error&){failed=true;}check(failed&&f.index==0,"unsupported nonfinite state fails visibly before floor calls");}
 const std::array grids{make_grid(.2f,0x12340903),make_grid(-.125f,0x56780701),make_grid(0,0x00800081),make_grid(2.f,0x12340903)};
 for(unsigned i=0;i<64;++i){
  grid_source=&grids[i%4];provider_seed=0;original_floor_index=0;original_observations.clear();g::Actor a;a.position={i&1?995.f:500.f,1000.f,i&2?995.f:500.f};a.orientation={std::int16_t(i*71),std::int16_t(i*1021),std::int16_t(i*53),0};a.action_flags=1;a.surface_normal={-.2f,.8f,0};a.surface_blend_weight=.5f;a.surface_blend_rate=.125f;a.local_impulse={.25f,.5f,-.75f};a.world_impulse={.125f,1,-.25f};
  std::fill(actual.begin()+base,actual.begin()+base+0x10e0,0xa5);export_actor(actual.data(),a);std::copy_n(actual.data()+base,0x10e0,expected.data()+base);g::GridSurfaceOrientation provider(*grid_source);g::rebuild_actor_pose(world,a,provider);export_actor(actual.data(),a);execute(expected.data(),true);check(std::memcmp(actual.data()+base,expected.data()+base,0x10e0)==0,"full original pose plus surface plus real native grid");check(original_floor_index==3&&a.collision.pose_ready&&bits(a.position.x,a.collision.basis.translation.x),"completed pose publishes post-surface translation");++grid_pose_cases;
 }
 grid_source=&grids[0];provider_seed=0;
 for(bool fail:{false,true}){
  g::World owned(profile(),std::make_shared<g::Session>());owned.room=1;auto actor=std::make_unique<g::Actor>();actor->active=true;actor->room=1;actor->slot=0;actor->position={500,1000,500};actor->root_motion_delta={2,0,0};actor->local_impulse={3,0,0};actor->world_impulse={4,0,0};actor->action_flags=1;actor->surface_normal={0,.8f,0};actor->surface_blend_rate=.125f;
  check(owned.spawn_primary(0,std::move(actor)).status==g::actors::EntityStatus::completed,"native World surface actor admission");auto lease=owned.primary(0);Frame frame;frame.expected=lease.get();Floors floors;floors.expected=lease.get();QueriedPose pose(floors);g::MotionTransformFrameServices transforms(frame,pose);throw_at=fail?1:-1;bool failed{};g::Result result{};
  try{result=owned.update_primary(transforms);}catch(const std::runtime_error&){failed=true;}
  check(failed==fail&&frame.local_delegations==0&&frame.pose_delegations==0,"real World consumes native motion/pose/surface component");
  if(fail)check(!lease->collision.pose_ready&&frame.later==0&&floors.index==2&&lease->position.x==509,"floor failure stops later World stages and retains source preceding position/impulse effects");
  else check(result.status==g::Status::completed&&result.updated==1&&lease->collision.pose_ready&&frame.later==1&&floors.index==3&&lease->position.x==509,"real World completes surface pose before later grid stage");
  check(owned.close()==g::Status::completed,"World synchronous guard releases after surface success/failure");++frame_cases;
 }
 throw_at=-1;
 check(not_requested>0&&rejected>0&&adjusted>0,"all return/reject/adjust branches covered");
 std::cout<<"{\"checks\":"<<checks<<",\"turn_cases\":"<<turn_cases<<",\"basis_cases\":"<<basis_cases<<",\"orientation_cases\":"<<orientation_cases<<",\"not_requested\":"<<not_requested<<",\"rejected\":"<<rejected<<",\"adjusted\":"<<adjusted<<",\"failure_cases\":"<<failure_cases<<",\"grid_pose_cases\":"<<grid_pose_cases<<",\"frame_cases\":"<<frame_cases<<",\"original_helper_calls\":"<<helper_calls<<",\"native_floor_calls\":"<<floor_calls<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
