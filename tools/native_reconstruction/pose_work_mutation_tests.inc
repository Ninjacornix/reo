unsigned mutation_cases{},mutation_callbacks{};
bool mutation_capture{},mutation_prepend{};unsigned mutation_original_calls{};
bool pose_mutation_port(std::uint8_t* memory,R5900Context* context){
    if(!mutation_capture||context->pc!=0x582e30)return false;
    ++mutation_original_calls;
    if(mutation_original_calls==1){
        // Nested original helpers need a lower stack than the live outer
        //5821F0/582B80 frames; resetting SP would overwrite their saved state.
        const auto nested=[&](unsigned pc,unsigned argument){
            R5900Context child;PS2Runtime runtime;child.pc=pc;const auto stack=GPR_U32(context,29)-0x1000;SET_GPR_U32(&child,29,stack);SET_GPR_U32(&child,31,0x1234);SET_GPR_U32(&child,4,argument);original_transform_port(memory,&child,&runtime);check(child.pc==0x1234&&GPR_U32(&child,29)==stack);return child;
        };
        const auto old=GPR_U32(context,4);nested(0x5820f0,old);const auto result=nested(0x581fe0,unsigned(mutation_prepend));check(GPR_U32(&result,2)==old);
        memory[old]=1;memory[old+4]=99;put(memory,old+0x12,std::int16_t(23));put(memory,old+0x14,0x582b80u);
    }
    return true;
}
struct MutatingPoseUpdates final:g::PoseWorkUpdates {
    g::World& world;std::array<g::actors::EntityId,64>& ids;bool prepend;unsigned called{};
    MutatingPoseUpdates(g::World& w,std::array<g::actors::EntityId,64>& values,bool first):world(w),ids(values),prepend(first){}
    bool bound_to(const g::World& value)const noexcept override{return &value==&world;}
    bool update(g::PoseWorkPool& pool,const g::actors::EntityId& id,std::uint8_t kind)override{
        check(kind==1);++called;
        check(world.close()==g::Status::busy&&pool.reset()==g::PoseWorkStatus::busy&&pool.update(this).status==g::PoseWorkStatus::busy);
        if(called==1){
            const auto retained=pool.resolve(id);check(bool(retained));check(pool.retire(id)==g::PoseWorkStatus::completed);
            const auto made=pool.allocate(prepend);check(made.status==g::PoseWorkStatus::completed&&made.id!=id&&!world.resolve(id)&&!retained->active);
            const auto actor=pool.resolve(made.id);actor->active=true;actor->pose_work->update_bound=true;actor->pose_work->kind=99;actor->pose_work->lifetime=23;
            const auto physical=pool.physical_slot(made.id);check(physical.has_value());ids[*physical]=made.id;
        }
        return true;
    }
};
void mutations(std::uint8_t* memory){
    auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{128,UINT64_MAX}},session);g::PoseWorkPool pool(world);
    for(unsigned prepend=0;prepend<2;++prepend)for(unsigned count=1;count<=64;++count){
        check(pool.reset()==g::PoseWorkStatus::completed);invoke(memory,0x581f50);std::array<g::actors::EntityId,64> ids;
        for(unsigned n=0;n<count;++n){
            const auto source=invoke(memory,0x581fe0,{1});const auto at=GPR_U32(&source,2);const auto made=pool.allocate();check(made.status==g::PoseWorkStatus::completed);ids[(at-base)/stride]=made.id;
            const auto actor=pool.resolve(made.id);actor->active=true;actor->pose_work->update_bound=true;actor->pose_work->kind=1;actor->pose_work->lifetime=9;
            memory[at]=1;memory[at+4]=1;put(memory,at+0x12,std::int16_t(9));put(memory,at+0x14,0x582b80u);
        }
        mutation_capture=true;mutation_prepend=prepend!=0;mutation_original_calls=0;invoke(memory,0x5821f0);mutation_capture=false;
        MutatingPoseUpdates updates(world,ids,prepend!=0);const auto report=pool.update(&updates);check(report.status==g::PoseWorkStatus::completed&&updates.called==mutation_original_calls&&report.called==mutation_original_calls);topology(pool,ids,memory);
        for(auto at:list(memory)){const auto actor=pool.resolve(ids[(at-base)/stride]);check(actor&&actor->active==bool(memory[at])&&actor->pose_work->kind==memory[at+4]&&actor->pose_work->lifetime==get<std::int16_t>(memory,at+0x12));}
        mutation_callbacks+=updates.called;++mutation_cases;
    }
}
