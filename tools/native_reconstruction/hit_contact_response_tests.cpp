#include "game/native/gameplay_world/hit_contact_response.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/animation/playback.hpp"
#include "game/native/transform_math/transform_math.hpp"
#include <cstdio>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace math=reo::native::transform_math;
namespace {
std::vector<std::uint8_t> ram(0x800000);
unsigned checks{},cases{},math_calls{};
constexpr unsigned base=0x4a5c30,aux=0x417090,linked=0x42eb00;
void check(bool ok,std::source_location at=std::source_location::current()){++checks;if(!ok)throw std::runtime_error("Hit contact case "+std::to_string(cases)+" line "+std::to_string(at.line()));}
template<class T>void put(unsigned at,T value){ref_write(ram.data(),at,value);}
template<class T>T get(unsigned at){return ref_read<T>(ram.data(),at);}
std::shared_ptr<const a::Skeleton> skeleton(){
    std::vector<std::byte> bytes(112);
    const auto write=[&](unsigned at,auto v){std::memcpy(bytes.data()+at,&v,sizeof(v));};
    write(4,2u);write(8,112u);write(16,1u);write(20,16u);
    write(28,1u);write(32,1u);write(36,84u);write(40,0u);write(48,0xffffffffu);write(52,0xffffffffu);
    for(unsigned i=0;i<3;++i)write(56+4*i,1.f);
    return a::Skeleton::import_raw(bytes);
}
void project(unsigned at,const w::Actor& actor){
    ram[at+2]=actor.category;ram[at+0xb98]=actor.character;ram[at+0x54f]=actor.motion_class;ram[at+0x140]=actor.response_class;
    ram[at+0x148]=actor.source_kind;ram[at+0x149]=actor.source_slot;ram[at+0x14a]=actor.contact.source_related.category;ram[at+0x14b]=actor.contact.source_related.token;
    ram[at+0x14c]=actor.contact.auxiliary_a;ram[at+0x143]=actor.response_flags;put(at+0x138,actor.damage_word);put(at+0xba0,actor.status);
    put(at+0x38,actor.position);put(at+0x92,actor.orientation[1]);put(at+0xa8,actor.candidate_direction);put(at+0x12c,actor.contact.direction);
    put(at+0x520,std::int16_t(actor.animation?actor.animation->motion:0));
}
void port(std::uint8_t*,R5900Context* c,PS2Runtime*){
    const auto address=GPR_U32(c,4);auto value=get<w::Position>(address);++math_calls;
    switch(c->pc){
    case 0x191d80:{const float r=1.f/std::sqrt((value.x*value.x+value.y*value.y)+value.z*value.z);value={value.x*r,value.y*r,value.z*r};put(address,value);break;}
    case 0x191bc0:{const auto sc=math::sin_cos(c->f[12]);const float x=value.x;value.x=sc.cosine*x+sc.sine*value.z;value.z=-sc.sine*x+sc.cosine*value.z;put(address,value);break;}
    case 0x191df0:{const auto other=get<w::Position>(GPR_U32(c,5));c->f[0]=(value.x*other.x+value.y*other.y)+value.z*other.z;break;}
    default:throw std::runtime_error("Undeclared hit contact math port");
    }
    c->pc=GPR_U32(c,31);
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{switch(at){/* ORIGINAL_LOOKUP */default:return port;}}
int main()try{
    w::World world({{{1,2,4}},1,{32,UINT64_MAX}},std::make_shared<w::Session>());PS2Runtime runtime;
    for(unsigned i=0;i<2;++i){auto actor=std::make_unique<w::Actor>();actor->category=0;actor->slot=i;check(bool(world.spawn_primary(i,std::move(actor)).id));}
    const auto aux_id=world.auxiliary_actors().allocate().id,linked_id=world.linked_models().allocate(false).id;
    check(bool(aux_id)&&bool(linked_id));
    auto target=world.primary(0),partner=world.primary(1),npc=world.resolve(aux_id),enemy=world.resolve(linked_id);
    const auto aux_slot=*world.auxiliary_actors().physical_slot(aux_id),enemy_slot=*world.linked_models().physical_slot(linked_id);
    const unsigned aux_address=aux+aux_slot*0x1170u,enemy_address=linked+enemy_slot*0xd90u;
    npc->category=1;enemy->category=2;
    target->model=std::make_shared<a::Instance>(skeleton());target->animation=std::make_shared<a::Playback>(target->model);
    world.session().enemy_descriptors.record(7)->actor_slot=*world.linked_models().physical_slot(linked_id);
    ram[0x74f250+7*96+1]=*world.linked_models().physical_slot(linked_id);
    put(0x712bb8,w::Position{0,0,1});put(0x740470,std::bit_cast<float>(0x40c90fdbu));
    for(unsigned trial=0;trial<64;++trial)for(unsigned kind:{0u,1u,2u,9u,255u}){
        ++cases;
        target->category=trial==1?1:0;target->character=trial==2?0:1;
        target->motion_class=trial==3||trial==4?0:0x41;target->animation->motion=trial==4?0x1048:0x1049;
        target->response_class=trial==5?2:0;target->source_kind=kind;target->source_slot=kind==0?1:kind==2?7:aux_slot;
        target->contact.source_related={std::uint8_t((trial/4)%4),std::uint8_t((trial/4)%4==0?1:aux_slot)};
        target->contact.recorded_source=(trial&1)?aux_id:w::actors::EntityId{};
        target->contact.auxiliary_a=std::uint8_t((trial%4)*85);
        target->position={5,10,20};target->candidate_direction={0,0,(trial&2)?-1.f:1.f};target->contact.direction={1,2,(trial&1)?-3.f:3.f};
        target->damage_word=trial%7==0?-1:trial%7==1?0:211;target->response_flags=0x40;
        world.session().gameplay_flags=trial&8?2:0;
        for(const auto& other:{partner,npc,enemy}){other->position={5,float(trial&1?30:10),float(trial&4?5:40)};other->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(trial*1091));other->status=trial&16?0x80:0;}
        project(base,*target);project(base+4320,*partner);project(aux_address,*npc);project(enemy_address,*enemy);
        put(base+0x11c,(trial&1)?aux_address:0u);ram[0x4bae96]=world.session().gameplay_flags;
        R5900Context c{};c.pc=0x6689e0;c.g[4].lo=base;c.g[29].lo=0x50000;c.g[31].lo=0x1234;
        runtime.lookupFunction(c.pc)(ram.data(),&c,&runtime);check(c.pc==0x1234);
        w::finish_hit_contact(world,*target);
        if(target->damage_word!=get<std::int32_t>(base+0x138)||target->response_flags!=ram[base+0x143])
            std::fprintf(stderr,"trial %u kind %u native %d/%u original %d/%u dot %g\n",trial,kind,target->damage_word,unsigned(target->response_flags),get<std::int32_t>(base+0x138),unsigned(ram[base+0x143]),double(c.f[0]));
        check(target->damage_word==get<std::int32_t>(base+0x138)&&target->response_flags==ram[base+0x143]);
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"math_ports\":%u,\"game_run\":false}\n",checks,cases,math_calls);
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
