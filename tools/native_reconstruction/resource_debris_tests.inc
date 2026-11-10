unsigned debris_cases{},debris_frames{},debris_missing{},debris_floor_queries{},debris_refusals{},debris_capacity{},debris_child_full{};
void debris_floor_port(std::uint8_t* memory,R5900Context* context){
    using namespace reo::native::gameplay_collision;check(placement_floors);const auto start=get<Vec3>(memory,GPR_U32(context,4)),end=get<Vec3>(memory,GPR_U32(context,5));const auto result=trace::floor(*placement_floors,start,end);check(result.status!=trace::SamplingStatus::capacity&&result.status!=trace::SamplingStatus::nonprogress);
    if(result.hit){put(memory,GPR_U32(context,6),result.hit->point);put(memory,GPR_U32(context,7),result.hit->normal);memory[GPR_U32(context,10)]=std::uint8_t(result.hit->type);}SET_GPR_U32(context,2,unsigned(bool(result.hit)));++debris_floor_queries;
}
namespace debris_fixture {
using namespace delayed_fixture;
void compare_state(const e::ResourceDebrisState& state,const std::uint8_t* memory,unsigned raw){
    check(state.phase==memory[raw+8]&&state.visible==bool(memory[raw+1])&&state.part==memory[raw+4]&&state.effect==get<std::uint16_t>(memory,raw+0x204)&&state.delay==get<std::int16_t>(memory,raw+12));
    check(std::memcmp(&state.basis,memory+raw+0x50,64)==0&&std::memcmp(&state.initial_position,memory+raw+0xd8,12)==0&&std::memcmp(&state.position,memory+raw+0x38,12)==0&&std::memcmp(&state.previous_position,memory+raw+0x44,12)==0);
    check(std::memcmp(state.angles.data(),memory+raw+0x90,6)==0&&std::memcmp(state.angular_velocity.data(),memory+raw+0x98,6)==0&&std::memcmp(&state.velocity,memory+raw+0xc0,12)==0&&std::memcmp(&state.acceleration,memory+raw+0xcc,12)==0&&std::bit_cast<unsigned>(state.alpha)==get<unsigned>(memory,raw+0x214)&&std::bit_cast<unsigned>(state.fade_step)==get<unsigned>(memory,raw+0xf0));
}
void export_state(const e::ResourceDebrisState& state,std::uint8_t* memory,unsigned raw){
    memory[raw+8]=state.phase;memory[raw+1]=std::uint8_t(state.visible);memory[raw+4]=state.part;put(memory,raw+0x204,state.effect);put(memory,raw+12,state.delay);put(memory,raw+0x50,state.basis);put(memory,raw+0xd8,state.initial_position);put(memory,raw+0x38,state.position);put(memory,raw+0x44,state.previous_position);put(memory,raw+0x90,state.angles);put(memory,raw+0x98,state.angular_velocity);put(memory,raw+0xc0,state.velocity);put(memory,raw+0xcc,state.acceleration);put(memory,raw+0x214,state.alpha);put(memory,raw+0xf0,state.fade_step);
}
}
void compare_resource_debris(const std::vector<std::vector<std::byte>>& corpus,const char* static_path,const char* template_path,std::vector<std::uint8_t>& ram){
    using namespace debris_fixture;const auto assets=factory_load(static_path,16),banks=factory_load(template_path,5);
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        Fixture q(ram,assets[0],banks[0]);prepare(q.memory,corpus[asset],corpus[asset+1],0x1800000);const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        for(unsigned method=0;method<9;++method)for(unsigned profile=0;profile<8;++profile){
            std::cerr<<"debris case "<<asset<<","<<method<<","<<profile<<"\n";
            call(q.memory,0x651850);const auto original_model=call(q.memory,0x590c70);auto model=q.models.create();check(model.status==g::ResourceModelStatus::completed&&GPR_U32(&original_model,2)==q.address(model.id));const auto raw_model=q.address(model.id);model.model->content_id=std::array<std::uint16_t,5>{0x6e,0x6a,0x6f,0x74,42}[method%5];put(q.memory,raw_model+0x36,model.model->content_id);
            model.model->pose=m::identity();model.model->pose[0][0]=profile&1?2.f:1.f;model.model->pose[1][0]=profile&2?.25f:0.f;model.model->pose[3][0]=profile==2?5000.f:200.f;model.model->pose[3][1]=profile==1?-20.f:profile==4?100.f:5.f;model.model->pose[3][2]=profile==2?5000.f:200.f;put(q.memory,raw_model+0x1c0,model.model->pose);
            e::PeriodicVisuals visuals(bank,q.session->random);check(visuals.bind_resource_debris(q.world,q.models,q.factory)&&visuals.debris_bound_to(q.world,q.models,q.factory));q.session->random.restore({std::uint16_t(profile*991),217,std::uint8_t(profile)});put(q.memory,0x3244b0,q.session->random.state().primary);put(q.memory,0x3244b8,q.session->random.state().secondary);q.memory[0x2b8de8]=q.session->random.state().observed;
            e::PeriodicVisuals::CompanionsCreated created;
            if(method<5){call(q.memory,0x5df2a0,{raw_model});created=visuals.create_resource_debris(model.id);}
            else{const auto part=method-5,effect=std::array<unsigned,4>{0xbf,0xc0,0x5a,0x5b}[part];call(q.memory,0x5df340,{raw_model,part,0xabcd0000u|effect});const auto made=visuals.create_resource_debris_piece(model.id,part,0xabcd0000u|effect);created.status=made.status;created.attempted=1;if(made.id){created.created=1;created.identities[0]=made.id;}}
            check(created.status!=e::WorkStatus::unavailable&&visuals.size()==created.created&&visuals.size()==168u-get<std::uint16_t>(q.memory,0x3b5828)&&!visuals.piece_count()&&get<std::uint16_t>(q.memory,0x3b5820)==256);if(!created.created)++debris_missing;
            std::array<unsigned,2> source{};auto cursor=get<unsigned>(q.memory,0x3b5848);for(unsigned i=2;i>0;--i)if(created.identities[i-1]){check(cursor);source[i-1]=cursor;const auto state=visuals.resource_debris_state(created.identities[i-1]);check(bool(state));compare_state(*state,q.memory,cursor);cursor=get<unsigned>(q.memory,cursor+0x20);}check(!cursor);
            for(unsigned tick=0;tick<100&&visuals.size();++tick){
                if(profile==3&&tick==5){call(q.memory,0x590d80,{raw_model});check(q.models.retire(model.id)==g::ResourceModelStatus::completed);}
                for(unsigned i=2;i>0;--i)if(source[i-1]&&q.memory[source[i-1]])call(q.memory,0x58fbc0,{source[i-1]});
                const auto report=visuals.update({});check(report.status==e::VisualStatus::completed);const auto frame=visuals.retain();check(bool(frame));unsigned live{};
                for(unsigned i=2;i>0;--i){if(!source[i-1])continue;const auto state=visuals.resource_debris_state(created.identities[i-1]);check(bool(state)==bool(q.memory[source[i-1]]));if(!state)continue;compare_state(*state,q.memory,source[i-1]);check(live<frame->visuals.size());const auto& output=frame->visuals[live++];check(output.id==created.identities[i-1]&&output.visible==state->visible&&output.category==0x1b&&output.debris&&output.pieces.empty());compare_state(*output.debris,q.memory,source[i-1]);}
                check(frame->visuals.size()==live&&visuals.size()==168u-get<std::uint16_t>(q.memory,0x3b5828)&&visuals.piece_count()==0&&get<std::uint16_t>(q.memory,0x3b5820)==256);check(q.session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(q.memory,0x3244b0),get<std::uint16_t>(q.memory,0x3244b8),q.memory[0x2b8de8]});++debris_frames;
            }
            check(!visuals.size());visuals.close();if(model.model->current()){call(q.memory,0x590d80,{raw_model});check(q.models.retire(model.id)==g::ResourceModelStatus::completed);}++debris_cases;
        }
        // Complete16-bit RNG/angle/delay domains through complete update bodies.
        if(!asset){constexpr unsigned raw=0x120000;
            for(unsigned n=0;n<65536;++n){e::ResourceDebrisState state;state.initial_position={200,5,200};state.alpha=std::array<float,5>{-.1f,0,.05f,1,2}[n%5];export_state(state,q.memory,raw);q.session->random.restore({std::uint16_t(n),std::uint16_t(n*257u),std::uint8_t(n)});put(q.memory,0x3244b0,q.session->random.state().primary);put(q.memory,0x3244b8,q.session->random.state().secondary);q.memory[0x2b8de8]=q.session->random.state().observed;call(q.memory,0x58fbc0,{raw});const auto initial=e::advance_resource_debris(state,q.session->random);check(!initial.retire&&!initial.query_floor);compare_state(state,q.memory,raw);check(q.session->random.state()==reo::native::gameplay_session::RandomState{get<std::uint16_t>(q.memory,0x3244b0),get<std::uint16_t>(q.memory,0x3244b8),q.memory[0x2b8de8]});++debris_cases;
                state.delay=std::bit_cast<std::int16_t>(std::uint16_t(n));state.angles={std::bit_cast<std::int16_t>(std::uint16_t(n)),std::bit_cast<std::int16_t>(std::uint16_t(n*257u)),std::bit_cast<std::int16_t>(std::uint16_t(n*65521u))};state.position={200,float(int(n%33)-16),200};state.velocity.y=float(int(n%9)-4);export_state(state,q.memory,raw);call(q.memory,0x58fd10,{raw});const auto step=e::advance_resource_debris(state,q.session->random);check(!step.retire&&step.query_floor);const auto hit=reo::native::gameplay_collision::trace::floor(*q.floors,{state.previous_position.x,state.previous_position.y,state.previous_position.z},{state.position.x,state.position.y,state.position.z});e::complete_resource_debris_floor(state,bool(hit.hit));compare_state(state,q.memory,raw);++debris_frames;
            }
        }
    }
}

#include "tools/native_reconstruction/resource_debris_capacity_tests.inc"
