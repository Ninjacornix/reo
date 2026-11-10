#include "game/native/transform_math/heading.hpp"
#include "game/native/transform_math/transform_math.hpp"
#include <cfenv>
#include <limits>
unsigned contact_alignment_cases{},heading_cases{},contact_alignment_rejections{},contact_alignment_refusals{},contact_alignment_owner_cases{};
namespace contact_alignment_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;namespace math=reo::native::transform_math;
constexpr unsigned raw=0x4a5c30;
float original_float(std::uint8_t* memory,unsigned pc,float y,float x=0){
    R5900Context context;context.pc=pc;context.f[12]=y;context.f[13]=x;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return context.f[0];
}
bool same(float a,float b){return std::bit_cast<unsigned>(a)==std::bit_cast<unsigned>(b);}
void equal_float(float a,float b,const char* what,unsigned input,unsigned second=0){
    if(!same(a,b))throw std::runtime_error(std::string(what)+" input "+std::to_string(input)+","+std::to_string(second)+" original "+std::to_string(std::bit_cast<unsigned>(a))+" native "+std::to_string(std::bit_cast<unsigned>(b)));
    check(true);
}
unsigned original_prepare(std::uint8_t* memory,unsigned limit,float offset){
    R5900Context context;context.pc=0x666f50;context.f[12]=offset;SET_GPR_U32(&context,4,raw);SET_GPR_U32(&context,5,limit);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return GPR_U32(&context,2);
}
template<class F>void refuses(F f){bool rejected=false;try{f();}catch(const std::domain_error&){rejected=true;}check(rejected);++contact_alignment_refusals;}
}
void compare_actor_contact_alignment(std::uint8_t* memory,const char* constants){
    using namespace contact_alignment_fixture;
    std::ifstream input(constants,std::ios::binary);check(bool(input));
    for(unsigned i=0;i<5;++i){unsigned at{},bytes{};input.read(reinterpret_cast<char*>(&at),4);input.read(reinterpret_cast<char*>(&bytes),4);check(bytes<=76&&at<0x2000000-bytes);input.read(reinterpret_cast<char*>(memory+at),bytes);check(bool(input));}
    check(input.peek()==std::char_traits<char>::eof());
    const auto atan=[&](unsigned bits){const float value=std::bit_cast<float>(bits);if(!std::isfinite(value))return;equal_float(original_float(memory,0x122140,value),math::arctangent(value),"atan",bits);++heading_cases;};
    const auto quadrant=[&](unsigned yb,unsigned xb){const float y=std::bit_cast<float>(yb),x=std::bit_cast<float>(xb);if(!std::isfinite(y)||!std::isfinite(x))return;equal_float(original_float(memory,0x120908,y,x),math::quadrant_angle(y,x),"quadrant",yb,xb);++heading_cases;};
    const std::array<unsigned,24> bounds{0,1,0x7fffff,0x800000,0x30ffffff,0x31000000,0x3edfffff,0x3ee00000,0x3f2fffff,0x3f300000,0x3f7fffff,0x3f800000,0x3f800001,0x3f97ffff,0x3f980000,0x401bffff,0x401c0000,0x507fffff,0x50800000,0x7f7fffff,0x00800001,0x20000000,0x60000000,0x40490fdb};
    for(auto bound:bounds)for(unsigned sign:{0u,0x80000000u}){
        for(int delta=-8;delta<=8;++delta){const auto b=bound+unsigned(delta);if(b<0x7f800000u)atan(b|sign);}
        for(auto other:bounds)for(unsigned other_sign:{0u,0x80000000u})quadrant(bound|sign,other|other_sign);
    }
    for(unsigned n=0;n<262144;++n){atan(n*1664525u+1013904223u);quadrant(n*1664525u+1013904223u,n*22695477u+1);}
    // Every low-half turn exercises the actual separate source sine/cosine
    // implementations, rather than substituting a paired-trig helper port.
    for(unsigned n=0;n<65536;++n){
        R5900Context sine,cosine;PS2Runtime runtime;
        for(auto* c:{&sine,&cosine}){SET_GPR_U32(c,4,n);SET_GPR_U32(c,31,0x100);}
        sine.pc=0x3700c0;cosine.pc=0x370100;original_transform_port(memory,&sine,&runtime);original_transform_port(memory,&cosine,&runtime);check(sine.pc==0x100&&cosine.pc==0x100);
        const auto wave=math::sin_cos(std::bit_cast<float>(0x38c90fdbu)*float(n));equal_float(sine.f[0],wave.sine,"turn sine",n);equal_float(cosine.f[0],wave.cosine,"turn cosine",n);++heading_cases;
    }
    g::Actor actor;
    const auto run=[&](unsigned n,float nx,float nz,unsigned limit,float offset){
        actor.projectile_contact.normal={nx,0,nz};actor.projectile_contact.point={float(std::int16_t(n)),33,float(std::int16_t(n*17))};actor.position={100,std::bit_cast<float>(n*65521u),300};actor.orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n*65521));actor.alignment_target=g::AlignmentTarget{{-11,-22,-33},-444};
        put(memory,raw+0x534,actor.projectile_contact.normal);put(memory,raw+0x528,actor.projectile_contact.point);put(memory,raw+0x38,actor.position);put(memory,raw+0x92,actor.orientation[1]);put(memory,raw+0xc34,actor.alignment_target->position);put(memory,raw+0xc4c,actor.alignment_target->yaw);
        const auto prepared=original_prepare(memory,limit,offset);check(prepared<=1&&g::prepare_contact_alignment(actor,limit,offset)==bool(prepared));
        const auto& target=*actor.alignment_target;equal_float(get<float>(memory,raw+0xc34),target.position.x,"alignment X",n);equal_float(get<float>(memory,raw+0xc38),target.position.y,"alignment Y",n);equal_float(get<float>(memory,raw+0xc3c),target.position.z,"alignment Z",n);check(target.yaw==get<std::int16_t>(memory,raw+0xc4c));check(actor.position.x==100&&actor.position.z==300&&actor.orientation[1]==std::bit_cast<std::int16_t>(std::uint16_t(n*65521)));++contact_alignment_cases;if(!prepared)++contact_alignment_rejections;
    };
    for(unsigned n=0;n<65536;++n){const float x=float(std::int16_t(n)),z=float(std::int16_t(n*17));for(unsigned limit:{0u,1u,0x7fffu,0x8000u,0xffffu,0x10000u,0x10001u,0x80000001u})run(n,x,z,limit,float(int(n%97)-48));}
    for(unsigned n=0;n<bounds.size();++n)for(auto xb:bounds)for(unsigned sign:{0u,0x80000000u})run(n,std::bit_cast<float>(bounds[n]|sign),std::bit_cast<float>(xb),0,n%2?0.f:-0.f);
    // Native refusals preserve the previously prepared target, and do not
    // silently route exceptional values through a legacy arithmetic path.
    actor.projectile_contact.point={1,2,3};actor.projectile_contact.normal={1,0,1};actor.position={4,5,6};
    for(float invalid:{std::numeric_limits<float>::infinity(),-std::numeric_limits<float>::infinity(),std::numeric_limits<float>::quiet_NaN()}){
        refuses([&]{math::arctangent(invalid);});refuses([&]{math::quadrant_angle(invalid,1);});refuses([&]{math::direction_turn(1,invalid);});
        const auto old=*actor.alignment_target;refuses([&]{g::prepare_contact_alignment(actor,0,invalid);});check(std::memcmp(&old.position,&actor.alignment_target->position,12)==0&&old.yaw==actor.alignment_target->yaw);
    }
    const auto rounding=std::fegetround();check(std::fesetround(FE_DOWNWARD)==0);refuses([&]{math::arctangent(1);});check(std::fegetround()==FE_DOWNWARD);check(std::fesetround(rounding)==0);
    const auto mxcsr=_mm_getcsr();_mm_setcsr(mxcsr|0x8040u);refuses([&]{math::quadrant_angle(1,1);});check((_mm_getcsr()&0x8040u)==0x8040u);_mm_setcsr(mxcsr);
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;auto live=world.primary(0);live->projectile_contact.point={10,20,30};live->projectile_contact.normal={1,0,-1};live->position={100,200,300};live->orientation[1]=123;
    actor_action_fixture::Notifications notifications;actor_alignment_fixture::AlignmentSink sink(world);u::Owner owner(world,notifications,e::RuleBook::file1(),&sink);world.session().message_phase=1;world.selected_actor=0;world.mode=1;
    check(owner.prepare_actor_contact_alignment(id,0,17)==true);const auto target=*live->alignment_target;check(live->position.y==200&&live->orientation[1]==123);++contact_alignment_owner_cases;
    check(owner.prepare_actor_contact_alignment(id,0xffffffffu,17)==false&&live->alignment_target->yaw==target.yaw);++contact_alignment_owner_cases;
    sink.available=false;check(owner.record_actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::message_unavailable&&std::memcmp(&target.position,&live->alignment_target->position,12)==0);++contact_alignment_owner_cases;sink.available=true;
    check(owner.record_actor_message(id,u::ActorMessageSelector::alignment)==u::PublicationStatus::completed&&sink.alignments.size()==2&&sink.alignments.back().target.yaw==target.yaw&&std::memcmp(&target.position,&sink.alignments.back().target.position,12)==0);++contact_alignment_owner_cases;
    check(!owner.prepare_actor_contact_alignment({},0,1).has_value());++contact_alignment_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&!owner.prepare_actor_contact_alignment(id,0,1).has_value());++contact_alignment_refusals;
    check(owner.close()==u::Status::completed&&!owner.prepare_actor_contact_alignment(id,0,1).has_value());++contact_alignment_refusals;
}
