#include "game/native/gameplay_world/weapon_target.hpp"
#include "game/native/gameplay_world/target_metrics.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/animation/model.hpp"
#include <fstream>
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace col=reo::native::gameplay_collision;
namespace math=reo::native::transform_math;
namespace {
unsigned checks{},cases{},sample{},entry{};
constexpr unsigned actor_at=0x10000,done=0x1234;
void check(bool value){++checks;if(!value)throw std::runtime_error("weapon target check "+std::to_string(checks)+" sample "+std::to_string(sample)+" entry "+std::to_string(entry));}
template<class Buffer,class T>void put(Buffer& target,unsigned at,T value){check(at+sizeof(T)<=target.size());std::memcpy(target.data()+at,&value,sizeof value);}
std::shared_ptr<const a::Skeleton> skeleton(){
    std::vector<std::byte> raw(28+12*84);put(raw,4,13u);put(raw,8,std::uint32_t(raw.size()));put(raw,16,1u);put(raw,20,16u);
    for(unsigned i=0;i<12;++i){const unsigned at=28+i*84,node=at+12;put(raw,at,1u);put(raw,at+4,1u);put(raw,at+8,84u);put(raw,node,i);
        put(raw,node+8,i==0?1u:0xffffffffu);put(raw,node+12,i>0&&i<11?i+1:0xffffffffu);
        for(unsigned lane=0;lane<3;++lane)put(raw,node+0x10+4*lane,1.f);
    }return a::Skeleton::import_raw(raw);
}
col::response::Grid grid(){
    std::vector<std::byte> raw(48);put(raw,8,10000u);put(raw,12,10000u);put(raw,16,1u);put(raw,20,1u);put(raw,32,32u);put(raw,36,40u);put(raw,40,36u);put(raw,44,0xffffffffu);return col::response::Grid::import(raw);
}
void model(w::Actor& actor,const std::shared_ptr<const a::Skeleton>& data){actor.model=std::make_shared<a::Instance>(data);auto basis=math::identity();basis[3]={actor.position.x,actor.position.y,actor.position.z,1};actor.model->rebuild(basis);}
void project_actor(std::vector<std::uint8_t>& ram,const w::Actor& actor,unsigned at,unsigned model_at){
    ram[at+2]=actor.category;ram[at+3]=actor.slot;ram[at+0xb98]=actor.character;ram[at+0xff0]=actor.ai_control;
    put(ram,at+0x38,actor.position);put(ram,at+0x92,actor.orientation[1]);put(ram,at+0xca8,actor.resource_action);
    if(actor.targeting){put(ram,at+0xc94,actor.targeting->flags);ram[at+0x551]=actor.targeting->model_point.value_or(255);}
    put(ram,at+0x34,model_at);
    if(actor.model)for(unsigned i=0;i<actor.model->nodes().size();++i){const auto node=model_at+0x900+i*64;put(ram,model_at+0x820+4*i,node);put(ram,node+0x30,actor.model->world_translation(i));}
}
void mode_port(std::uint8_t* ram,R5900Context* c,PS2Runtime*){SET_GPR_U32(c,2,ram[0x3243f2]==0);c->pc=GPR_U32(c,31);}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    switch(at){case 0x1b02d0:return mode_port;case 0x1920a0:return sub_001920A0_0x1920a0;default:throw std::runtime_error("Unexpected target dependency "+std::to_string(at));}
}
int main(int argc,char** argv)try{
    check(argc==2);std::vector<std::uint8_t> ram(0x800000);std::ifstream image(argv[1],std::ios::binary);check(bool(image));image.read(reinterpret_cast<char*>(ram.data()+0x570000),0x800000-0x570000);
    const auto data=skeleton();const auto walls=grid();const w::TargetMetricRoom room{walls,walls,{}, {}};PS2Runtime runtime;
    w::World world({{{1,2,4}},1,{128,UINT64_MAX}},std::make_shared<w::Session>());world.mode=0;world.room=7;
    for(unsigned i=0;i<8;++i){auto actor=std::make_unique<w::Actor>();actor->slot=std::uint8_t(i);actor->active=i==0;actor->room=7;actor->position={500,100,500};model(*actor,data);check(bool(world.spawn_primary(i,std::move(actor)).id));}
    auto auxiliary_id=world.auxiliary_actors().allocate().id;auto auxiliary=world.resolve(auxiliary_id);check(bool(auxiliary));auxiliary->category=1;auxiliary->slot=*world.auxiliary_actors().physical_slot(auxiliary_id);auxiliary->active=true;auxiliary->room=7;auxiliary->position={500,100,500};model(*auxiliary,data);
    std::array<w::actors::EntityId,4> targets;
    for(auto& id:targets){id=world.linked_models().allocate(false).id;auto target=world.resolve(id);check(bool(target));target->active=true;target->room=7;target->targeting=w::TargetingState{0,false,0};}
    for(unsigned layout=0;layout<32;++layout){
        for(unsigned i=0;i<targets.size();++i){auto target=world.resolve(targets[i]);target->character=std::uint8_t(i+10);
            target->position={float(500+(layout%4)*50),float(100+int((layout+i)%5)*100-100),float(500+(i+1)*100)};
            target->targeting->flags=(layout&(1u<<i))?1u:0u;model(*target,data);
        }
        check(world.target_metrics().rebuild(room).status==w::TargetMetricStatus::completed);
        const auto& metrics=*world.target_metrics().state();
        for(unsigned family=0;family<2;++family){auto actor=family?auxiliary:world.primary(0);
            const auto& rows=family?metrics.auxiliary_linked[actor->slot]:metrics.primary_linked[actor->slot];
            const auto& order=family?metrics.auxiliary_linked_order[actor->slot]:metrics.primary_linked_order[actor->slot];
            const auto row_at=(family?0x3b3220:0x3b41c0)+400*actor->slot;
            const auto order_at=(family?0x3b2a80:0x3b2e10)+50*actor->slot;std::memcpy(ram.data()+order_at,order.data(),order.size());
            for(unsigned i=0;i<50;++i)if(rows[i]){const auto at=row_at+8*i;put(ram,at,rows[i]->pair.distance);put(ram,at+4,rows[i]->pair.bearing);ram[at+6]=rows[i]->wall;ram[at+7]=rows[i]->floor;}
            for(const auto& id:targets){const auto slot=*world.linked_models().physical_slot(id);const auto target=world.resolve(id);const auto at=0x42eb00+0xd90*slot;project_actor(ram,*target,at,0x120000+0x1000*slot);ram[at+6]=slot;}
            for(unsigned variant=0;variant<512;++variant){sample=layout*1024+family*512+variant;world.mode=std::uint8_t((variant>>7)%3);ram[0x3243f2]=world.mode;
                actor->ai_control=std::uint8_t((variant>>4)&1);actor->ai_target=(variant&8)?targets[(variant>>5)%4]:w::actors::EntityId{};
                actor->character=std::uint8_t(variant%8);actor->resource_action=std::uint16_t(variant%64);actor->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(variant*991));
                project_actor(ram,*actor,actor_at,0x180000);
                put(ram,actor_at+0x1068,*actor->ai_target?0x42eb00u+0xd90u*(*world.linked_models().physical_slot(*actor->ai_target)):0u);
                for(const auto address:{0x65ed70u,0x65f060u}){entry=address;++cases;
                    actor->aim_target_pitch=-17;actor->aim_target_yaw=18;actor->aim_target_roll=-19;actor->aim_pitch_adjustment=20;actor->aim_target_index=21;
                    put(ram,actor_at+0xcd4,*actor->aim_target_pitch);put(ram,actor_at+0xcd6,*actor->aim_target_yaw);put(ram,actor_at+0xcd8,*actor->aim_target_roll);put(ram,actor_at+0xbc8,*actor->aim_pitch_adjustment);ram[actor_at+0xcdc]=*actor->aim_target_index;
                    R5900Context c{};c.g[4].lo=actor_at;c.g[29].lo=0x30000;c.g[31].lo=done;c.f[12]=float((variant%9)*100);
                    w::actors::EntityId result;
                    if(address==0x65ed70){o2_0065ED70_0x65ed70(ram.data(),&c,&runtime);result=w::select_weapon_target(world,*actor,float((variant%9)*100));}
                    else{o2_0065F060_0x65f060(ram.data(),&c,&runtime);w::prepare_weapon_target(world,*actor,true);result=*actor->weapon_target;}
                    check(c.pc==done);const auto expected=result?0x42eb00u+0xd90u*(*world.linked_models().physical_slot(result)):0u;check(GPR_U32(&c,2)==expected);
                    check(ref_read<std::int16_t>(ram.data(),actor_at+0xcd4)==*actor->aim_target_pitch);check(ref_read<std::int16_t>(ram.data(),actor_at+0xcd6)==*actor->aim_target_yaw);
                    check(ref_read<std::int16_t>(ram.data(),actor_at+0xcd8)==*actor->aim_target_roll);check(ref_read<std::int16_t>(ram.data(),actor_at+0xbc8)==*actor->aim_pitch_adjustment);check(ram[actor_at+0xcdc]==*actor->aim_target_index);
                }
            }
        }
    }
    std::printf("{\"checks\":%u,\"cases\":%u,\"game_run\":false}\n",checks,cases);return 0;
}catch(const std::exception& e){std::fprintf(stderr,"%s\n",e.what());return 1;}
