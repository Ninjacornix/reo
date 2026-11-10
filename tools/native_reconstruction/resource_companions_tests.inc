#include "game/native/gameplay_effects/resource_companion_actions.hpp"
unsigned companion_live_cases{},companion_live_frames{},companion_live_pieces{},companion_live_missing{},companion_live_unavailable{},companion_live_lights{},companion_live_audio{};
unsigned companion_factory_cases{},companion_factory_refusals{};
unsigned companion_capacity_cases{};
void compare_resource_companions(const std::vector<std::vector<std::byte>>& corpus,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;
    auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned content:{0x72u,0x3200u,0x1cu,0x1du,0x135u,0x75u})for(unsigned profile=0;profile<8;++profile){
        std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);put(memory,0x294e00,m::identity());
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);auto session=std::make_shared<g::Session>();session->random.restore({std::uint16_t(profile*991),217,std::uint8_t(profile)});
        g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);auto actor=std::make_unique<g::Actor>();actor->active=true;actor->selected_resource=3;actor->primary=2;actor->secondary=11;actor->surface_material=17;const auto actor_id=world.spawn_primary(0,std::move(actor)).id;check(bool(actor_id));
        s::SceneResources resources;s::ResourceTemplates templates;g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);auto& value=*model.model;
        auto engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);a::SpatialContext spatial;spatial.world_to_screen=m::identity();g::animation_events::BasicAudio frontend(world,audio,spatial,resources,templates);
        s::Lighting lighting;l::Pool lights(lighting);t::Scheduler tasks;l::TimedLights timed(world,tasks,lights);e::NativeResourceCompanionActions actions(world,resources,models,templates,frontend,timed);
        e::PeriodicVisuals owner(bank,session->random);check(owner.bind_resource_companions(world,resources,models,templates,actions));check(owner.companions_bound_to(world,resources,models,templates));
        s::SceneResources foreign;check(!owner.companions_bound_to(world,foreign,models,templates));
        value.active=value.visible=true;value.content_id=std::uint16_t(content);value.resource_slot=3;value.position={12,-2,37};value.axis_scale={.25f,2,3};value.pose=m::identity();value.pose[0][0]=2;value.pose[1][0]=.5f;value.pose[3][0]=42;value.draw_tag=profile&1?0x8fff:255;value.flags=profile&1?0x100:0;
        s::SceneDescriptor descriptor;descriptor.active=1;descriptor.template_index=0;descriptor.instance_index=3;descriptor.ownership_tag=profile?1:0;check(bool(resources.load(3,descriptor)));
        constexpr unsigned raw=0x130000,actor_raw=0x4a5c30;
        const auto sync=[&](){
            memory[raw]=std::uint8_t(value.active);memory[raw+1]=std::uint8_t(value.visible);memory[raw+0x240]=value.resource_slot;put(memory,raw+0x36,value.content_id);put(memory,raw+0x23c,value.flags);put(memory,raw+0x238,value.draw_tag);put(memory,raw+0x200,value.position);put(memory,raw+0x22c,value.axis_scale);put(memory,raw+0x1c0,value.pose);
            const auto actor_value=world.resolve(actor_id);memory[actor_raw+8]=actor_value->primary;memory[actor_raw+9]=actor_value->secondary;put(memory,0x3c5630+3*60+40,descriptor.ownership_tag);
            const auto rng=session->random.state();put(memory,0x3244b0,rng.primary);put(memory,0x3244b8,rng.secondary);memory[0x2b8de8]=rng.observed;
        };sync();
        const std::int8_t argument=profile==7?0:1;
        const auto created=owner.create_resource_companions(model.id,argument);
        if(created.status==e::WorkStatus::unavailable){++companion_live_unavailable;owner.close();call(memory,0x652ce0);continue;}
        // The source3200 argument0 path writes before its null guard. Its
        // known missing-resource case is measured safely with argument1;
        // native argument0 still returns absence without a null-address write.
        call(memory,0x5df450,{raw,content==0x3200&&!created.created?1u:std::uint32_t(std::uint8_t(argument))});
        check(owner.size()==168u-get<std::uint16_t>(memory,0x3b5828));
        std::array<unsigned,2> originals{};auto cursor=get<unsigned>(memory,0x3b5848);
        for(unsigned i=2;i>0;--i)if(created.identities[i-1]){check(cursor);originals[i-1]=cursor;check(get<unsigned>(memory,cursor+0x24)==raw);cursor=get<unsigned>(memory,cursor+0x20);}
        check(!cursor);
        if(!created.created){++companion_live_missing;owner.close();call(memory,0x652ce0);continue;}
        for(unsigned i=0;i<2;++i)if(created.identities[i]){const auto state=owner.resource_companion_state(created.identities[i]);check(state&&state->content==content&&state->remaining==get<std::int16_t>(memory,originals[i]+14)&&state->age==get<std::int16_t>(memory,originals[i]+16)&&state->attributes==get<std::uint16_t>(memory,originals[i]+0x23c));}
        for(unsigned tick=0;tick<180;++tick){
            if(profile==2){world.resolve(actor_id)->primary=tick<10||tick>=40?1:2;}
            if(profile==3&&tick==45)value.visible=false;
            if(profile==4&&tick==40){check(models.retire(model.id)==g::ResourceModelStatus::completed);}
            if(profile==5&&tick==35)value.resource_slot=4;
            sync();const m::Vector camera{10,20,30};put(memory,0x324138,camera);const auto before_light=companion_light_requests,before_cue=companion_cue_requests;
            companion_live_capture=true;try{for(unsigned i=2;i>0;--i)if(originals[i-1]&&memory[originals[i-1]])call(memory,0x654720,{originals[i-1]});}catch(...){companion_live_capture=false;throw;}companion_live_capture=false;
            const auto report=owner.update(camera);if(report.status!=e::VisualStatus::completed)throw std::runtime_error("Companion live native unavailable asset="+std::to_string(asset)+" content="+std::to_string(content)+" profile="+std::to_string(profile)+" tick="+std::to_string(tick));
            if(companion_light_requests!=before_light){check(actions.last_light()&&actions.last_light()->status==l::TimedStatus::completed);++companion_live_lights;}
            if(companion_cue_requests!=before_cue){check(actions.last_audio()&&actions.last_audio()->commands==0);++companion_live_audio;}
            const auto frame=owner.retain();check(bool(frame));unsigned live{},pieces{};
            for(unsigned i=2;i>0;--i){if(!originals[i-1])continue;const auto at=originals[i-1];const auto state=owner.resource_companion_state(created.identities[i-1]);check(bool(state)==bool(memory[at]));if(!state)continue;
                check(live<frame->visuals.size());const auto& output=frame->visuals[live++];check(output.id==created.identities[i-1]&&output.visible==bool(memory[at+1]));if(output.category)check(*output.category==memory[at+3]);
                check(state->phase==memory[at+8]&&state->remaining==get<std::int16_t>(memory,at+14)&&state->age==get<std::int16_t>(memory,at+16));
                check(std::memcmp(&state->position,memory+at+0x44,12)==0&&std::memcmp(&state->basis,memory+at+0x50,64)==0);check(std::bit_cast<unsigned>(state->alpha)==get<unsigned>(memory,at+0x214));
                check(output.pieces.size()==memory[at+0x31]);pieces+=unsigned(output.pieces.size());
                for(unsigned j=0;j<output.pieces.size();++j){const auto& piece=output.pieces[j];const auto child=get<unsigned>(memory,at+0x134+4*j);if(!output.visible)continue;
                    check(piece.visible==bool(memory[at+0xf4+j]));if(!piece.visible)continue;check(piece.root==get<std::uint16_t>(memory,child+2)&&piece.material==memory[child+1]);
                    const auto details=" asset="+std::to_string(asset)+" content="+std::to_string(content)+" profile="+std::to_string(profile)+" tick="+std::to_string(tick)+" child="+std::to_string(j);
                    if(piece.flags!=get<unsigned>(memory,child+4))throw std::runtime_error("Companion child flags"+details+" actual="+std::to_string(piece.flags)+" expected="+std::to_string(get<unsigned>(memory,child+4)));
                    if(std::memcmp(&piece.parameters.translation,memory+child+0x24,12)){
                        const auto p=get<m::Vector>(memory,child+0x24);throw std::runtime_error("Companion translation"+details+" actual="+std::to_string(piece.parameters.translation.x)+","+std::to_string(piece.parameters.translation.y)+","+std::to_string(piece.parameters.translation.z)+" expected="+std::to_string(p.x)+","+std::to_string(p.y)+","+std::to_string(p.z));
                    }
                    if(std::memcmp(piece.parameters.rotation.data(),memory+child+0x30,6))throw std::runtime_error("Companion rotation"+details);
                    if(std::memcmp(&piece.parameters.scale,memory+child+0x38,12))throw std::runtime_error("Companion scale"+details);
                    const auto* mesh=output.bank->geometry().material(piece.root,piece.material);check(mesh);for(unsigned k=0;k<mesh->indices.size();++k){check(std::bit_cast<unsigned>(piece.material_values[k])==get<unsigned>(memory,child+0x50+4*k));}++companion_live_pieces;
                }
            }
            check(frame->visuals.size()==live&&owner.size()==live&&owner.piece_count()==pieces);check(tasks.run(t::Pass::update).status==t::Status::completed);
            check(session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(memory,0x3244b0),get<std::uint16_t>(memory,0x3244b8),memory[0x2b8de8]});++companion_live_frames;
        }
        owner.close();call(memory,0x652ce0);++companion_live_cases;
    }
}
void compare_companion_factory(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;
    const auto assets=factory_load(static_path,16),template_banks=factory_load(template_path,5);auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2)for(unsigned primary=0;primary<4;++primary){
        std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1],0x1800000);put(memory,0x294e00,m::identity());
        const auto& bytes=assets[primary];const auto cache=g::ResourceStaticAssets::import_nbd(bytes);unsigned offset{},length{};std::memcpy(&offset,bytes.data()+0x24,4);std::memcpy(&length,bytes.data()+0x28,4);std::memcpy(memory+0x1000000,bytes.data()+offset,length);put(memory,0x32440c,0x400000u);call(memory,0x1d3100,{0x70000,0x1000000});
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        for(const auto& template_bytes:template_banks){
            s::ResourceTemplates templates;check(templates.load(template_bytes));std::fill_n(memory+0x74bb50,129*24,0);std::fill_n(memory+0x74b940,129*4,0);std::fill_n(memory+0x74c770,128*4,0);std::fill_n(memory+0x74c970,384*2,0);std::fill_n(memory+0x74b6e0,600,255);put(memory,0x74ccf0,std::uint16_t(0));std::memcpy(memory+0x100000,template_bytes.data(),template_bytes.size());call(memory,0x5921d0,{0x100000});
            for(unsigned content:{0x72u,0x3200u,0x1cu,0x1du,0x135u,0x75u}){
                auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);s::SceneResources resources;g::ResourceModels models;
                auto engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);a::SpatialContext spatial;spatial.world_to_screen=m::identity();g::animation_events::BasicAudio frontend(world,audio,spatial,resources,templates);
                s::Lighting lighting;l::Pool lights(lighting);t::Scheduler tasks;l::TimedLights timed(world,tasks,lights);e::NativeResourceCompanionActions actions(world,resources,models,templates,frontend,timed);
                e::PeriodicVisuals visuals(bank,session->random);check(visuals.bind_resource_companions(world,resources,models,templates,actions));g::ResourceFrames frames(world,resources,models,nullptr,{},&templates);g::ResourceFactory factory(models,frames,templates,cache);check(factory.bind_companions(visuals));
                const auto index=cache->find(std::int16_t(content));const auto selector=std::bit_cast<std::uint8_t>(templates.selector(std::int16_t(content)));const unsigned callback=selector==255?0:std::to_integer<unsigned>(templates.state().templates[selector].encoded[20]);
                if(callback>3||(index>=0&&!cache->roots()[unsigned(index)].admitted_parts)){check(factory.create(std::uint16_t(content),1).status==g::ResourceModelStatus::unavailable);++companion_factory_refusals;continue;}
                call(memory,0x590be0);call(memory,0x651850);put(memory,0x3244b0,std::uint16_t(0));put(memory,0x3244b8,std::uint16_t(0));memory[0x2b8de8]=0;
                const auto original=call(memory,0x591230,{content,1});const auto raw=GPR_U32(&original,2);const auto result=factory.create(std::uint16_t(content),1);
                check(raw&&result.status==g::ResourceModelStatus::completed&&result.model);check(result.model->content_id==get<std::uint16_t>(memory,raw+0x36)&&result.model->asset_index==get<std::int16_t>(memory,raw+0x242)&&result.model->visible==bool(memory[raw+1]));
                check(visuals.size()==168u-get<std::uint16_t>(memory,0x3b5828)&&visuals.piece_count()==256u-get<std::uint16_t>(memory,0x3b5820));check(session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(memory,0x3244b0),get<std::uint16_t>(memory,0x3244b8),memory[0x2b8de8]});
                check(models.retire(result.id)==g::ResourceModelStatus::completed);visuals.close();++companion_factory_cases;
            }
        }
        call(memory,0x652ce0);
    }
}
void compare_companion_capacity(const std::vector<std::vector<std::byte>>& corpus,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;namespace a=reo::native::gameplay_audio;namespace b=reo::native::audio_banks::v2;namespace l=reo::native::gameplay_lighting;namespace t=reo::native::gameplay_tasks;
    auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);if(!bank->geometry().resolve(0x40)||!bank->geometry().resolve(0x3f))continue;
        for(unsigned occupied:{167u,168u}){
            std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);put(memory,0x294e00,m::identity());auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);
            auto actor=std::make_unique<g::Actor>();actor->primary=2;actor->secondary=11;actor->surface_material=31;const auto actor_id=world.spawn_primary(0,std::move(actor)).id;
            s::SceneResources resources;s::ResourceTemplates templates;g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);model.model->active=true;model.model->content_id=0x1d;model.model->pose=m::identity();
            auto engine=std::make_shared<b::Session>();a::Owner audio(engine,session->random);a::SpatialContext spatial;spatial.world_to_screen=m::identity();g::animation_events::BasicAudio frontend(world,audio,spatial,resources,templates);
            s::Lighting lighting;l::Pool lights(lighting);t::Scheduler tasks;l::TimedLights timed(world,tasks,lights);e::NativeResourceCompanionActions actions(world,resources,models,templates,frontend,timed);e::PeriodicVisuals visuals(bank,session->random);
            check(visuals.bind_resource_companions(world,resources,models,templates,actions));g::ResourceModels foreign_models;s::SceneResources foreign_resources;check(!actions.bound_to(world,foreign_resources,models,templates)&&!visuals.companions_bound_to(world,resources,foreign_models,templates));
            for(unsigned i=0;i<occupied;++i){put(memory,0x71000,m::Vector{});const auto source=call(memory,0x6525d0,{0,0x71000,0,36+i%3,0,0x1a193,0x6535c0});check(GPR_U32(&source,2)&&visuals.emit({std::uint16_t(36+i%3),{}}).status==s::EmissionStatus::completed);}
            constexpr unsigned raw=0x130000;memory[raw]=1;put(memory,raw+0x36,std::uint16_t(0x1d));put(memory,raw+0x1c0,m::identity());call(memory,0x5df450,{raw,1});const auto made=visuals.create_resource_companions(model.id,1);
            check(made.status==e::WorkStatus::pool_full&&made.attempted==2&&made.created==168-occupied);check(bool(made.identities[0])==(occupied==167)&&!made.identities[1]);check(visuals.size()==168&&visuals.size()==168u-get<std::uint16_t>(memory,0x3b5828)&&visuals.piece_count()==256u-get<std::uint16_t>(memory,0x3b5820));
            model.model->content_id=0x3200;const auto safe=visuals.create_resource_companions(model.id,0);check(safe.status==(bank->geometry().resolve(0x7f)?e::WorkStatus::pool_full:e::WorkStatus::resource_missing)&&!safe.created&&visuals.size()==168);
            for(unsigned i=0;i<64;++i){check(lighting.allocate(nullptr,std::uint8_t(i),1).has_value());}
            check(actions.light(actor_id,{1,2,3})&&actions.last_light()&&actions.last_light()->status==l::TimedStatus::light_full&&tasks.size()==0&&lights.size()==64);
            visuals.close();call(memory,0x652ce0);++companion_capacity_cases;
        }
    }
    check(companion_capacity_cases>0);
}
