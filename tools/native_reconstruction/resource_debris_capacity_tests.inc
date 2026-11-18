void compare_resource_debris_capacity(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace debris_fixture;const auto assets=factory_load(static_path,16),banks=factory_load(template_path,5);
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        Fixture q(ram,assets[0],banks[0]);prepare(q.memory,corpus[asset],corpus[asset+1],0x1800000);const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);const auto original_model=call(q.memory,0x590c70);const auto model=q.models.create();check(model.status==g::ResourceModelStatus::completed&&GPR_U32(&original_model,2)==q.address(model.id));model.model->pose=m::identity();model.model->pose[3][0]=model.model->pose[3][2]=200;model.model->pose[3][1]=5;model.model->content_id=0x74;put(q.memory,q.address(model.id)+0x1c0,model.model->pose);put(q.memory,q.address(model.id)+0x36,model.model->content_id);
        for(unsigned occupied:{0u,167u,168u}){
            call(q.memory,0x651850);e::PeriodicVisuals visuals(bank,q.session->random);check(visuals.bind_resource_debris(q.world,q.models,q.factory));
            for(unsigned n=0;n<occupied;++n){put(q.memory,0x71000,m::Vector{});const auto source=call(q.memory,0x6525d0,{0,0x71000,0,36+n%3,0,0x1a193,0x6535c0});check(GPR_U32(&source,2)&&visuals.emit({std::uint16_t(36+n%3),{}}).status==s::EmissionStatus::completed);}
            const auto child_count=visuals.piece_count();const auto child_free=get<std::uint16_t>(q.memory,0x3b5820);call(q.memory,0x5df340,{q.address(model.id),0,36});const auto made=visuals.create_resource_debris_piece(model.id,0,36);
            check(made.status==(occupied==168?e::WorkStatus::pool_full:e::WorkStatus::completed)&&bool(made.id)==(occupied<168)&&visuals.size()==168u-get<std::uint16_t>(q.memory,0x3b5828)&&visuals.piece_count()==child_count&&get<std::uint16_t>(q.memory,0x3b5820)==child_free);if(made.id){const auto state=visuals.resource_debris_state(made.id);check(bool(state));compare_state(*state,q.memory,get<unsigned>(q.memory,0x3b5848));if(child_count==256)++debris_child_full;}++debris_capacity;
            call(q.memory,0x5df2a0,{q.address(model.id)});const auto dispatched=visuals.create_resource_debris(model.id);check(dispatched.status!=e::WorkStatus::unavailable&&dispatched.attempted==2&&visuals.size()==168u-get<std::uint16_t>(q.memory,0x3b5828)&&visuals.piece_count()==child_count&&get<std::uint16_t>(q.memory,0x3b5820)==child_free);++debris_capacity;
            if(visuals.size()==168){const auto before=visuals.size();call(q.memory,0x5df340,{0,0,36});check(visuals.create_resource_debris_piece({},0,36).status==e::WorkStatus::pool_full&&visuals.size()==before);++debris_capacity;}
            visuals.close();
        }
        {
            e::PeriodicVisuals visuals(bank,q.session->random);check(visuals.bind_resource_debris(q.world,q.models,q.factory));const auto old_pose=model.model->pose;
            check(visuals.create_resource_debris_piece({},0,36).status==e::WorkStatus::unavailable&&visuals.size()==0);++debris_refusals;
            check(visuals.create_resource_debris_piece(model.id,4,36).status==e::WorkStatus::unavailable&&visuals.size()==0);++debris_refusals;
            model.model->pose[0][0]=std::numeric_limits<float>::infinity();check(visuals.create_resource_debris_piece(model.id,0,36).status==e::WorkStatus::unavailable&&visuals.size()==0);model.model->pose=old_pose;++debris_refusals;
            g::ResourceModels foreign;check(!visuals.debris_bound_to(q.world,foreign,q.factory));e::PeriodicVisuals rejected(bank,q.session->random);check(!rejected.bind_resource_debris(q.world,foreign,q.factory));++debris_refusals;
            const auto made=visuals.create_resource_debris_piece(model.id,0,36);check(made.status==e::WorkStatus::completed);q.world.room=2;check(visuals.update({}).status==e::VisualStatus::completed);const auto initialized=visuals.resource_debris_state(made.id);check(initialized&&initialized->phase==1);const auto prior_frame=visuals.retain();check(prior_frame&&prior_frame->visuals.size()==1);check(visuals.update({}).status==e::VisualStatus::invalid_profile&&!visuals.retain());const auto prefix=visuals.resource_debris_state(made.id);check(prefix&&prefix->delay==4&&prefix->position.y==initialized->position.y+5&&prefix->previous_position.y==initialized->position.y);q.world.room=1;++debris_refusals;
            visuals.close();check(prior_frame->visuals[0].id==made.id&&prior_frame->visuals[0].debris->phase==1&&prior_frame->visuals[0].debris->delay==5&&!visuals.resource_debris_state(made.id));
        }
        {
            auto factory=std::make_unique<g::ResourceFactory>(q.models,q.frames,q.templates,q.assets);check(factory->bind_scene(q.collisions,q.floors,1));e::PeriodicVisuals visuals(bank,q.session->random);check(visuals.bind_resource_debris(q.world,q.models,*factory));const auto made=visuals.create_resource_debris_piece(model.id,0,36);check(made.status==e::WorkStatus::completed);factory.reset();check(visuals.update({}).status==e::VisualStatus::completed&&visuals.update({}).status==e::VisualStatus::invalid_profile&&!visuals.retain());++debris_refusals;visuals.close();
        }
        {
            e::ResourceDebrisState state;state.phase=3;bool refused{};try{(void)e::advance_resource_debris(state,q.session->random);}catch(const std::domain_error&){refused=true;}check(refused);++debris_refusals;
            state.phase=0;state.initial_position.x=std::numeric_limits<float>::quiet_NaN();refused=false;try{(void)e::advance_resource_debris(state,q.session->random);}catch(const std::domain_error&){refused=true;}check(refused);++debris_refusals;
        }
    }
    check(debris_child_full>0);
}
