#include "game/native/gameplay_world/actor_model_passes.hpp"
#include <algorithm>
std::uint64_t primary_model_pass_cases{},auxiliary_model_pass_cases{},actor_model_pass_refusals{},actor_model_pass_leases{};
void compare_actor_model_passes(const std::vector<std::vector<std::byte>>& skeletons,
                                std::vector<std::uint8_t>& ram){
    // The controlled traversal fixture shares one real model between actors.
    // This exposes traversal order through its final publication. Independent
    // model/ground/attachment bodies run again below in the parent fixture.
    for(const auto& raw:skeletons)for(unsigned domain=0;domain<2;++domain)for(unsigned test=0;test<256;++test){
        auto skeleton=a::Skeleton::import_raw(raw);auto model=std::make_shared<a::Instance>(skeleton);
        std::memcpy(ram.data()+0x400000,raw.data(),raw.size());
        call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
        std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);
        call(ram.data(),0x193380,nodes,1);
        for(unsigned i=0;i<skeleton->nodes().size();++i)put(ram.data(),work+0x820+4*i,nodes+400*i);
        std::fill_n(ram.data()+actor_address,8*0x10e0,0);
        std::fill_n(ram.data()+0x500000,10*0x1170,0);
        g::World world(profile(),std::make_shared<g::Session>());world.paused=1;
        put(ram.data(),0x4badf8,world.paused);
        scene::ResourceTemplates catalog;scene::SceneResources resources;
        g::WorldResourceAttachments attachments(world,resources,catalog);Scales scales;
        g::ActorModelPasses passes(world,scales,attachments);
        std::vector<std::pair<g::actors::EntityId,unsigned>> actors;
        const unsigned count=domain?test%11:8;
        const unsigned mask=domain?((test*317u)^0x2a5u):test;
        const auto configure=[&](g::Actor& actor,unsigned slot){
            actor.active=bool(mask&(1u<<slot));actor.visible=bool((test+slot)&1);
            actor.model=model;actor.model_correction_skip=1;actor.contact_flags=test&1?0x12:0;
            actor.position={float(31*int(slot)-70),float(17*int(slot)-90),float(19*slot+test)};
            actor.model_scale={1.f+float(slot)*.125f,.75f+float(slot)*.0625f,.9f};
            actor.character=std::uint8_t(slot%8);actor.category=std::uint8_t(slot%3);
            actor.selected_resource=actor.secondary_resource=0;
        };
        if(domain==0){
            std::array<std::uint8_t,0x10e0> first{};
            for(unsigned i=0;i<count;++i){
                const auto made=world.spawn_primary(i,std::make_unique<g::Actor>());
                check(made.status==g::actors::EntityStatus::completed,"register all actual primary model slots");
                auto actor=world.resolve(made.id);configure(*actor,i);export_actor(ram.data(),*actor);ram[actor_address+1]=std::uint8_t(actor->visible);
                if(i==0)std::copy_n(ram.data()+actor_address,first.size(),first.begin());
                else std::memcpy(ram.data()+actor_address+0x10e0*i,ram.data()+actor_address,0x10e0);
                actors.push_back({made.id,actor_address+0x10e0*i});
            }
            std::copy(first.begin(),first.end(),ram.begin()+actor_address);
        }else{
            auto& pool=world.auxiliary_actors();
            for(unsigned i=0;i<count;++i){
                const auto made=pool.allocate((test+i)&1);
                check(made.status==g::AuxiliaryStatus::completed,"allocate actual auxiliary model list");
                auto actor=world.resolve(made.id);configure(*actor,i);export_actor(ram.data(),*actor);ram[actor_address+1]=std::uint8_t(actor->visible);
                const auto at=0x500000+0x1170*unsigned(*pool.physical_slot(made.id));
                std::memcpy(ram.data()+at,ram.data()+actor_address,0x10e0);actors.push_back({made.id,at});
            }
            const auto address=[&](const g::actors::EntityId& id){for(const auto& entry:actors)if(entry.first==id)return entry.second;return 0u;};
            put(ram.data(),0x3b59f0,address(pool.head()));
            for(auto id=pool.head();id;id=pool.next(id))put(ram.data(),address(id)+0x1c,address(pool.next(id)));
        }
        const auto expected=std::count_if(actors.begin(),actors.end(),[&](const auto& entry){return world.resolve(entry.first)->active;});
        for(unsigned continuation=0;continuation<2;++continuation){
            const auto old=model->retain();const auto old_joints=old?old->joints:std::vector<a::Matrix>{};
            const auto result=domain?passes.auxiliary():passes.primary();
            check(result.status==g::ActorModelPassStatus::completed&&result.visited==count&&result.published==std::size_t(expected),"actual model pass traversal counts and active gate");
            call(ram.data(),domain?0x376ae0:0x3769f0,0);
            compare_nodes(*model,ram,expected!=0);
            for(const auto& entry:actors){
                const auto actor=world.resolve(entry.first);const auto basis=actor_matrix(*actor);
                check(std::memcmp(&basis,ram.data()+entry.second+0x50,64)==0,"every original actor basis after the complete pass");
                actor->position.x+=13.f;put(ram.data(),entry.second+0x38,actor->position);
            }
            if(old){check(old->joints==old_joints,"retained model pass snapshot remains independent");++actor_model_pass_leases;}
            check(!world.busy()&&!world.auxiliary_actors().busy(),"both model traversal guards released");
        }
        check(passes.close()==g::ActorModelPassStatus::completed&&passes.primary().status==g::ActorModelPassStatus::closed,"closed model pass admission");
        check(world.close()==g::Status::completed,"actual model pass World retirement");
        if(domain)++auxiliary_model_pass_cases;else ++primary_model_pass_cases;
    }
    {
        g::World world(profile(),std::make_shared<g::Session>()),foreign(profile(),std::make_shared<g::Session>());
        Scales scales;scene::ResourceTemplates catalog;scene::SceneResources resources;
        g::WorldResourceAttachments wrong(foreign,resources,catalog);bool refused{};
        try{g::ActorModelPasses invalid(world,scales,wrong);}catch(const std::invalid_argument&){refused=true;}
        check(refused,"foreign actor model resource owner refused before a pass");++actor_model_pass_refusals;
        g::WorldResourceAttachments attachments(world,resources,catalog);g::ActorModelPasses passes(world,scales,attachments);
        const auto actor=world.spawn_primary(0,std::make_unique<g::Actor>());world.resolve(actor.id)->active=true;
        refused=false;try{(void)passes.primary();}catch(const std::runtime_error&){refused=true;}
        check(refused&&!world.busy(),"model failure preserves prefix and releases traversal guards");++actor_model_pass_refusals;
        check(world.close()==g::Status::completed&&passes.auxiliary().status==g::ActorModelPassStatus::closed,"closed canonical model World refused");++actor_model_pass_refusals;
    }
    {
        g::World world(profile(),std::make_shared<g::Session>());
        scene::ResourceTemplates catalog;scene::SceneResources resources;
        g::WorldResourceAttachments attachments(world,resources,catalog);
        struct GuardedScales final:g::ModelCorrectionScales {
            g::World& world;g::ActorModelPasses* passes{};mutable unsigned calls{};
            explicit GuardedScales(g::World& value):world(value){}
            float character(std::uint8_t)const override{
                ++calls;
                check(world.close()==g::Status::busy,"model callback cannot close canonical World during traversal");
                check(passes->primary().status==g::ActorModelPassStatus::busy&&passes->auxiliary().status==g::ActorModelPassStatus::busy&&passes->close()==g::ActorModelPassStatus::busy,"model callback cannot reenter or close its pass");
                return 1.f;
            }
            float variant(std::uint16_t)const override{return character(0);}
        } scales(world);
        g::ActorModelPasses passes(world,scales,attachments);scales.passes=&passes;
        const auto made=world.spawn_primary(0,std::make_unique<g::Actor>());auto actor=world.resolve(made.id);
        actor->active=true;actor->contact_flags=0x12;actor->model_height_correction=1;
        actor->model=std::make_shared<a::Instance>(a::Skeleton::import_raw(skeletons.front()));
        auto parent=t::identity();parent[3][1]=1000;actor->model->rebuild(parent);
        check(passes.primary().status==g::ActorModelPassStatus::completed&&scales.calls>0&&!world.busy(),"actual correction callback runs under the model guard");
        ++actor_model_pass_refusals;
    }
}
