#include "game/native/gameplay_world/auxiliary_actors.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
unsigned auxiliary_pool_cases{},auxiliary_pool_lookups{},auxiliary_pool_reuses{},auxiliary_pool_refusals{},auxiliary_pool_lifetimes{};
namespace auxiliary_pool_fixture {
namespace g=reo::native::gameplay_world;
constexpr unsigned base=0x417090,stride=0x1170;
unsigned address(const g::AuxiliaryActorPool& pool,const g::actors::EntityId& id){if(!id)return 0;const auto slot=pool.physical_slot(id);check(bool(slot));return base+stride**slot;}
void compare(std::uint8_t* memory,const g::World& world,const g::AuxiliaryActorPool& pool){
    check(pool.remaining()==get<std::uint16_t>(memory,0x3b59e0));check(address(pool,pool.head())==get<unsigned>(memory,0x3b59f0)&&address(pool,pool.tail())==get<unsigned>(memory,0x3b59e8));
    unsigned count{},previous{};auto raw=get<unsigned>(memory,0x3b59f0);
    for(auto id=pool.head();id;id=pool.next(id)){
        check(++count<=10&&raw==address(pool,id));const auto actor=world.resolve(id);check(bool(actor));check(actor->slot==memory[raw+3]&&actor->contact.authored_id==memory[raw+6]&&actor->active==bool(memory[raw])&&actor->model_variant==get<std::uint16_t>(memory,raw+0xbb4));
        check(previous==get<unsigned>(memory,raw+0x20)&&address(pool,pool.previous(id))==previous&&address(pool,pool.next(id))==get<unsigned>(memory,raw+0x1c));previous=raw;raw=get<unsigned>(memory,raw+0x1c);
    }
    check(!raw&&count==10-pool.remaining());const auto flags=pool.attachment_flags();for(unsigned i=0;i<4;++i)check(flags[i]==bool(memory[0x3b59d8+i]));
}
void cleared(std::uint8_t* memory,unsigned raw,const g::Actor& actor){
    check(!actor.active&&!actor.visible&&!actor.status&&!actor.current&&!actor.maximum&&actor.gauge_value==0&&actor.interaction_resource==0&&actor.aim_pitch_adjustment==0&&actor.aim_target_pitch==0&&actor.aim_target_index==0);
    check(!get<unsigned>(memory,raw+0xba0)&&!get<unsigned>(memory,raw+0xbac)&&!get<std::uint16_t>(memory,raw+0x544)&&!get<std::uint16_t>(memory,raw+0x546));
    check(actor.motion_rate==0&&actor.model_scale.x==0&&actor.model_scale.y==0&&actor.model_scale.z==0&&actor.surface_kind==0&&actor.surface_material==0&&actor.surface_normal.y==0&&actor.contact.damage_scale==0&&actor.contact.source_related==reo::native::gameplay_collision::delivery::Identity{0,0}&&!actor.alignment_target);
}
}
void compare_auxiliary_actor_pool(std::uint8_t* memory){
    using namespace auxiliary_pool_fixture;
    g::World world({{{1,2,4}},1,{96,UINT64_MAX}},std::make_shared<g::Session>());auto& pool=world.auxiliary_actors();check(&pool==&world.auxiliary_actors());
    std::array<g::actors::EntityId,10> ids;
    for(unsigned epoch=0;epoch<256;++epoch){
        call(memory,0x682c60);check(pool.reset()==g::AuxiliaryStatus::completed);compare(memory,world,pool);
        for(unsigned i=0;i<6;++i){const auto original=call(memory,0x683b10);const auto actual=pool.claim_attachment();check(original==(actual.slot?unsigned(*actual.slot):255u)&&actual.status==(i<4?g::AuxiliaryStatus::completed:g::AuxiliaryStatus::full));compare(memory,world,pool);++auxiliary_pool_cases;}
        for(unsigned i=0;i<10;++i){
            const unsigned insert=(i+epoch)%3?i*1664525u+epoch:0u;const auto original=call(memory,0x682d10,{insert});const auto actual=pool.allocate(insert);check(actual.status==g::AuxiliaryStatus::completed&&original==address(pool,actual.id));ids[i]=actual.id;const auto actor=world.resolve(actual.id);cleared(memory,original,*actor);
            actor->slot=std::uint8_t(epoch+i*17);actor->active=(epoch+i)%3!=0;actor->model_variant=std::uint16_t((epoch*17+i)%7);actor->current=999;memory[original+3]=actor->slot;memory[original]=actor->active?std::uint8_t(epoch|1u):0;put(memory,original+0xbb4,actor->model_variant);put(memory,original+0x544,actor->current);compare(memory,world,pool);++auxiliary_pool_cases;
        }
        check(call(memory,0x682d10,{epoch})==0&&pool.allocate(epoch).status==g::AuxiliaryStatus::full);++auxiliary_pool_refusals;
        for(unsigned wanted:{0u,1u,2u,3u,4u,5u,6u,7u,65535u,65536u,UINT32_MAX})for(bool active:{false,true}){check(call(memory,active?0x682f80:0x666640,{wanted})==address(pool,pool.find(wanted,active)));++auxiliary_pool_lookups;}
        for(unsigned index:{0u,9u,4u,1u,8u,5u,2u,7u,3u,6u}){
            const auto old=ids[index];const auto raw=address(pool,old);const auto retained=world.resolve(old);const auto byte=retained->slot;
            check(world.retire_linked(old)==g::actors::EntityStatus::invalid);++auxiliary_pool_refusals;
            check(call(memory,0x682e30,{raw})==1&&pool.release(old)==g::AuxiliaryStatus::completed&&!world.resolve(old)&&!pool.physical_slot(old)&&retained->current==999);compare(memory,world,pool);
            check(pool.release(old)==g::AuxiliaryStatus::invalid_identity);++auxiliary_pool_refusals;
            const auto original=call(memory,0x682d10,{epoch});const auto fresh=pool.allocate(epoch);check(fresh.status==g::AuxiliaryStatus::completed&&fresh.id!=old&&address(pool,fresh.id)==original&&original==raw);const auto replacement=world.resolve(fresh.id);check(replacement&&replacement!=retained&&replacement->slot==byte&&replacement->current==0&&retained->current==999);cleared(memory,raw,*replacement);compare(memory,world,pool);++auxiliary_pool_reuses;
            check(call(memory,0x682e30,{raw})==1&&pool.release(fresh.id)==g::AuxiliaryStatus::completed);compare(memory,world,pool);++auxiliary_pool_cases;
        }
    }
    call(memory,0x682c60);check(pool.reset()==g::AuxiliaryStatus::completed);
    constexpr std::array<unsigned,10> variants{0,1,65535,32767,32768,255,256,1,65534,4096};
    for(unsigned i=0;i<10;++i){const auto original=call(memory,0x682d10,{i%2});const auto actual=pool.allocate(i%2);check(actual.status==g::AuxiliaryStatus::completed&&address(pool,actual.id)==original);const auto actor=world.resolve(actual.id);actor->model_variant=std::uint16_t(variants[i]);actor->active=i%3!=0;memory[original]=actor->active?255:0;put(memory,original+0xbb4,actor->model_variant);}
    for(unsigned wanted=0;wanted<65536;++wanted)for(bool active:{false,true}){check(call(memory,active?0x682f80:0x666640,{wanted})==address(pool,pool.find(wanted,active)));check(call(memory,active?0x682f80:0x666640,{wanted|0x10000u})==0&&!pool.find(wanted|0x10000u,active));auxiliary_pool_lookups+=2;}
    call(memory,0x682c60);check(pool.reset()==g::AuxiliaryStatus::completed);compare(memory,world,pool);
    // The50-model domain has independent capacity and membership, while both
    // owners allocate their Actor objects in the same canonical World store.
    auto& models=world.linked_models();for(unsigned i=0;i<50;++i)check(models.allocate(i%2).status==g::LinkedStatus::completed);for(unsigned i=0;i<10;++i)check(pool.allocate(i%2).status==g::AuxiliaryStatus::completed);check(!models.remaining()&&!pool.remaining()&&models.allocate(false).status==g::LinkedStatus::full&&pool.allocate().status==g::AuxiliaryStatus::full);check(!pool.physical_slot(models.head()));++auxiliary_pool_lifetimes;
    check(pool.reset()==g::AuxiliaryStatus::completed&&models.remaining()==0&&models.reset()==g::LinkedStatus::completed);++auxiliary_pool_lifetimes;
    // Native stale/foreign identities and entity-budget failures are explicit;
    // the original unchecked free-list corruption paths are not exercised.
    g::World other({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto foreign=other.auxiliary_actors().allocate();check(foreign.status==g::AuxiliaryStatus::completed&&pool.release(foreign.id)==g::AuxiliaryStatus::invalid_identity&&pool.release({})==g::AuxiliaryStatus::invalid_identity);++auxiliary_pool_refusals;
    g::World limited({{{1,2,4}},1,{1,1}},std::make_shared<g::Session>());auto& limited_pool=limited.auxiliary_actors();const auto one=limited_pool.allocate();check(one.status==g::AuxiliaryStatus::completed&&limited_pool.allocate().status==g::AuxiliaryStatus::world_unavailable&&limited_pool.remaining()==9);check(limited_pool.release(one.id)==g::AuxiliaryStatus::completed&&limited_pool.allocate().status==g::AuxiliaryStatus::world_unavailable&&limited_pool.remaining()==10);++auxiliary_pool_refusals;
    const auto final=pool.allocate();check(final.status==g::AuxiliaryStatus::completed);unsigned callbacks{};g::AuxiliaryStatus during_allocate{},during_reset{},during_claim{};g::Status during_close{};
    {const auto actor=world.resolve(final.id);actor->model=std::shared_ptr<reo::native::animation::Instance>(static_cast<reo::native::animation::Instance*>(nullptr),[&](auto*)noexcept{++callbacks;during_allocate=pool.allocate().status;during_reset=pool.reset();during_claim=pool.claim_attachment().status;during_close=world.close();});}
    check(pool.reset()==g::AuxiliaryStatus::completed&&callbacks==1&&during_allocate==g::AuxiliaryStatus::busy&&during_reset==g::AuxiliaryStatus::busy&&during_claim==g::AuxiliaryStatus::busy&&during_close==g::Status::busy&&!world.closed()&&!world.resolve(final.id));++auxiliary_pool_lifetimes;
    const auto live=pool.allocate();check(live.status==g::AuxiliaryStatus::completed&&world.close()==g::Status::completed&&!world.resolve(live.id)&&pool.allocate().status==g::AuxiliaryStatus::closed&&!pool.find(0)&&pool.close()==g::AuxiliaryStatus::completed);bool refused=false;try{(void)world.auxiliary_actors();}catch(const std::runtime_error&){refused=true;}check(refused);++auxiliary_pool_lifetimes;
}
