#include "game/native/gameplay_world/cinematic_model_pass.hpp"
std::uint64_t cinematic_model_passes{},cinematic_model_publications{},cinematic_model_joints{},cinematic_model_commands{},cinematic_model_refusals{};
a::Matrix cinematic_basis(const g::Actor& value){const auto& b=value.collision.basis;return {{{b.x.x,b.x.y,b.x.z,0},{b.y.x,b.y.y,b.y.z,0},{b.z.x,b.z.y,b.z.z,0},{b.translation.x,b.translation.y,b.translation.z,1}}};}
void cinematic_model_export(const g::Actor& value,const CinematicEntry& entry,std::vector<std::uint8_t>& ram){
    cinematic_export_actor(value,entry,ram);const auto at=entry.at;
    put(ram.data(),at+0x50,cinematic_basis(value));put(ram.data(),at+0xb40,value.model_correction_skip);put(ram.data(),at+0xaa8,value.model_height_correction);
    for(unsigned i=0;i<value.model->nodes().size();++i){const auto& row=value.model->nodes()[i];const auto node=entry.node_base+400*i;
        put(ram.data(),node,row.world);put(ram.data(),node+0x40,row.local);
        std::memcpy(ram.data()+node+0x104,row.parameters.data(),sizeof row.parameters);std::memcpy(ram.data()+node+0x15c,row.caches.data(),sizeof row.caches);
    }
}
void cinematic_model_pass_tests(const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    check(skeletons.size()==4,"cinematic publication uses the four qualified owned skeletons");std::array<std::shared_ptr<const a::Skeleton>,4> definitions;
    for(unsigned i=0;i<4;++i)definitions[i]=a::Skeleton::import_raw(skeletons[i]);
    g::File1ModelCorrectionScales scales;
    for(unsigned seed=0;seed<256;++seed){
        location="cinematic model publication="+std::to_string(seed);
        auto profile=world_profile();profile.entities.capacity=32;g::World world(profile,std::make_shared<g::Session>());
        auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed,"cinematic publication has actual fixed actor storage");
        world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,4>{0,1,127,255}[seed%4]);put(ram.data(),0x4badf8,world.paused);
        const auto main=world.spawn_primary(0,std::make_unique<g::Actor>()).id;const auto auxiliary=world.auxiliary_actors().allocate(1).id;const auto linked=world.linked_models().allocate(true).id;
        for(const auto& id:{main,auxiliary,linked}){const auto value=world.resolve(id);value->active=true;value->position.x=91;}
        std::vector<CinematicEntry> entries;std::vector<std::shared_ptr<const a::JointSnapshot>> retained;std::vector<a::Matrix> retained_roots;
        for(unsigned slot=0;slot<8;++slot){
            const auto value=world.resolve(pool.identity_at(slot));const auto family=(seed+slot)%4;
            value->active=bool((seed>>slot)&1);value->visible=(seed+slot)%3==0;value->category=std::uint8_t(family<2?0:1);
            value->character=std::uint8_t(family<2?7:5);value->model_variant=std::uint16_t(family<2?0:family==2?54:88);value->model_pose_class=std::uint8_t(family==0?0:1);
            value->model=std::make_shared<a::Instance>(definitions[family]);value->scripted.emplace();
            value->model_correction_skip=std::bit_cast<std::int8_t>(std::uint8_t(seed+slot));value->model_height_correction=float(int((seed+slot)%9)-4)*.25f;
            value->position={float(slot),1000.f+float(seed%7),float(seed)};value->model_scale={1.25f,.75f+float(seed%5)*.125f,.875f};
            value->collision.basis={{0,0,-1},{0,1,0},{1,0,0},{50.f+float(slot),1024.f+float(seed%11),-30}};
            for(unsigned i=0;i<value->model->nodes().size();++i){auto local=value->model->local_translation(i);local.x+=float((i+seed)%3)*.25f;local.y+=float(i%5)*.5f;value->model->local_translation(i,local);}
            if(seed&16){const auto restored=g::restore_secondary_pose_links(*value);check(restored.status==g::SecondaryPoseLinksStatus::restored||restored.status==g::SecondaryPoseLinksStatus::unchanged,"cinematic publication can consume the admitted restored topology");}
            auto prior=t::identity();prior[3][1]=1100;value->model->rebuild(prior);retained.push_back(value->model->retain());retained_roots.push_back(retained.back()->joints[0]);
            const CinematicEntry entry{pool.identity_at(slot),0x600000+slot*0x10e0,0xa00000+slot*0x2000,0xc00000+slot*0x10000,{}};entries.push_back(entry);cinematic_model_export(*value,entry,ram);
        }
        // Actual authored motion command writes the SAME byte consulted by
        // paused height correction. No fixture synchronization of two fields.
        if(world.paused!=0){
            const auto value=world.resolve(entries[0].id);std::array<std::byte,36> event{};event[1]=std::byte{1};
            const auto write=[&](unsigned at,auto data){std::memcpy(event.data()+at,&data,sizeof data);};
            write(4,std::uint32_t(seed&4?1:0));write(8,std::uint32_t(0));write(24,std::int32_t(2));
            std::memcpy(ram.data()+0xf00000,event.data(),event.size());
            check(cue::apply_cutscene_actor_command(world,entries[0].id,event)==cue::CutsceneCommandStatus::completed,"actual authored motion command composed before cinematic publication");
            call(ram.data(),0x5eec50,entries[0].at,0xf00000);
            check(value->model_correction_skip==get<std::int8_t>(ram.data(),entries[0].at+0xb40),"source B40 command mode is canonical model correction state");++cinematic_model_commands;
        }
        put(ram.data(),0x38edd0,0x600000u);g::CinematicModelPass pass(world,scales);
        for(unsigned follow=0;follow<2;++follow){
            const auto result=pass.run();call(ram.data(),0x5ecb80,0);
            check(result.status==g::CinematicModelStatus::completed&&result.visited==8&&!world.busy(),"complete fixed cinematic model traversal releases its guard");
            unsigned published{};
            for(unsigned slot=0;slot<8;++slot){const auto value=world.resolve(entries[slot].id);const auto& entry=entries[slot];
                const auto basis=cinematic_basis(*value);check(std::memcmp(&basis,ram.data()+entry.at+0x50,64)==0,"cinematic basis remains distinct from actor position");
                for(unsigned i=0;i<value->model->nodes().size();++i){const auto& row=value->model->nodes()[i];const auto node=entry.node_base+400*i;
                    check(std::memcmp(&row.local,ram.data()+node+0x40,64)==0&&std::memcmp(&row.world,ram.data()+node,64)==0,"complete cinematic local/world matrix matches original");
                    check(std::memcmp(row.parameters.data(),ram.data()+node+0x104,sizeof row.parameters)==0&&std::memcmp(row.caches.data(),ram.data()+node+0x15c,sizeof row.caches)==0,"cinematic publication preserves animation parameters and caches");++cinematic_model_joints;
                }
                if(value->active){++published;const auto joint=value->model->world_translation(2);const auto view=value->collision.joint_two_position;check(view&&std::memcmp(&*view,&joint,12)==0,"derived native joint2 view comes from the published model");}
                check(retained[slot]&&std::memcmp(&retained[slot]->joints[0],&retained_roots[slot],64)==0,"retained earlier joint snapshot survives cinematic republication");
            }
            check(result.published==published,"active hidden actors count as publications");cinematic_model_publications+=published;++cinematic_model_passes;
        }
        for(const auto& id:{main,auxiliary,linked})check(world.resolve(id)->position.x==91&&!world.resolve(id)->collision.joint_two_position,"main auxiliary and linked populations are outside the model pass");
        check(world.close()==g::Status::completed&&pass.run().status==g::CinematicModelStatus::closed,"closed model pass refuses");
    }
    g::World world(world_profile(),std::make_shared<g::Session>());g::CinematicModelPass pass(world,scales);
    put(ram.data(),0x38edd0,0u);call(ram.data(),0x5ecb80,0);check(pass.run().visited==0,"absent temporary storage creates no actors");
    auto& pool=world.scene_primary_actors();check(pool.initialize()==g::ScenePrimaryStatus::completed,"failure fixture actual storage");
    const auto first=world.resolve(pool.identity_at(0)),second=world.resolve(pool.identity_at(1));first->active=second->active=true;first->model=std::make_shared<a::Instance>(definitions[0]);first->model_correction_skip=1;world.paused=1;
    bool failed{};try{(void)pass.run();}catch(const std::runtime_error&){failed=true;}
    check(failed&&!world.busy()&&first->model->retain()&&first->collision.joint_two_position&&!second->model,"missing later model preserves prior publication and releases guard");++cinematic_model_refusals;
    struct GuardScales final:g::ModelCorrectionScales{
        g::World& world;g::CinematicModelPass* pass{};mutable unsigned calls{};
        explicit GuardScales(g::World& w):world(w){}
        float character(std::uint8_t)const override{++calls;check(pass->run().status==g::CinematicModelStatus::busy&&world.close()==g::Status::busy&&world.scene_primary_actors().initialize()==g::ScenePrimaryStatus::busy,"model publication callback guards reentry close and temporary reset");throw std::runtime_error("deliberate metadata failure");}
        float variant(std::uint16_t)const override{return character(0);}
    } guarded(world);
    second->active=false;first->model_correction_skip=0;first->model_height_correction=1;first->position.y=-1000;g::CinematicModelPass guarded_pass(world,guarded);guarded.pass=&guarded_pass;
    failed=false;try{(void)guarded_pass.run();}catch(const std::runtime_error&){failed=true;}
    check(failed&&guarded.calls==1&&!world.busy()&&world.close()==g::Status::completed,"metadata failure releases all cinematic model guards");++cinematic_model_refusals;
}
