#include "game/native/gameplay_world/resource_actor_contact_pose.hpp"
unsigned channel_owner_cases{},channel_owner_frames{},channel_owner_peak{},channel_owner_refusals{};
namespace channel_owner_fixture {
namespace g=reo::native::gameplay_world;
void state(const std::uint8_t* memory,unsigned at,const e::ActorContactState& state){
    if(!(state.phase==memory[at+8]&&state.pose_phase==memory[at+9]&&state.mode==memory[at+4]&&state.clone==bool(memory[at+5])&&state.visible==bool(memory[at+1])&&state.parent_left==bool(memory[at+0x1e0])))
        throw std::runtime_error("Channel state phase="+std::to_string(state.phase)+"/"+std::to_string(memory[at+8])+" pose="+std::to_string(state.pose_phase)+"/"+std::to_string(memory[at+9])+" mode="+std::to_string(state.mode)+"/"+std::to_string(memory[at+4])+" clone="+std::to_string(state.clone)+"/"+std::to_string(memory[at+5])+" visible="+std::to_string(state.visible)+"/"+std::to_string(memory[at+1])+" latch="+std::to_string(state.parent_left)+"/"+std::to_string(memory[at+0x1e0]));
    check(state.cycle==get<std::int16_t>(memory,at+0xc)&&state.remaining==get<std::int16_t>(memory,at+0xe)&&state.age==get<std::int16_t>(memory,at+0x10)&&state.clone_timer==get<std::int16_t>(memory,at+0x12));
    check(std::memcmp(&state.position,memory+at+0x38,12)==0&&std::memcmp(&state.base_position,memory+at+0x44,12)==0);
    check(bool(state.basis)==bool(get<unsigned>(memory,at+0x1f0)));if(state.basis)check(std::memcmp(&*state.basis,memory+at+0x50,64)==0);
}
std::vector<unsigned> active(const std::uint8_t* memory){std::vector<unsigned> result;for(auto at=get<unsigned>(memory,0x3b5848);at;at=get<unsigned>(memory,at+0x20)){check(result.size()<168);result.push_back(at);}return result;}
}
void compare_actor_contact_owner(const std::vector<std::vector<std::byte>>& corpus,std::uint8_t* memory){
    using namespace channel_owner_fixture;contact_fixture::channel_capture=false;
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);auto session=std::make_shared<g::Session>();
        g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);auto actor=std::make_unique<g::Actor>();actor->slot=0;actor->selected_resource=3;actor->contact_style_discriminator=0;
        const auto parent=world.spawn_primary(0,std::move(actor)).id;check(bool(parent));const auto live=world.resolve(parent);
        g::ResourceModels models;const auto model=models.create();check(model.status==g::ResourceModelStatus::completed);
        s::SceneResources resources;s::SceneDescriptor descriptor;descriptor.active=1;descriptor.instance_index=3;descriptor.primary=model.model;check(bool(resources.load(3,descriptor)));
        g::ResourceActorContactPoses poses(world,resources);
        for(unsigned mode:{0u,4u})for(unsigned variant=0;variant<4;++variant)for(unsigned clone=0;clone<2;++clone)for(unsigned pose=0;pose<4;++pose){
            std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);put(memory,0x294e00,m::identity());
            auto basis=m::identity();m::compose_euler_radians(basis,{float(pose)*.17f,-.5f,.3f});basis[3]={37,-91,51,1};
            const std::optional<m::Matrix> optional_basis=pose&1?std::optional(basis):std::nullopt;const m::Vector point{7,-15,21};put(memory,0x21000,point);put(memory,0x22000,basis);
            live->primary=2;live->secondary=2;live->resource_action=std::uint16_t((mode*7+variant*3+pose)%64);
            memory[0x20008]=2;memory[0x20009]=2;memory[0x20c7c]=3;put(memory,0x20ca8,live->resource_action);put(memory,0x3c564c+3*60,0x23000u);
            model.model->pose=basis;model.model->position={float(mode)-3,7,float(variant)-11};put(memory,0x231c0,basis);put(memory,0x23200,model.model->position);
            e::PeriodicVisuals owner(bank,session->random);check(owner.bind_actor_contacts(world,poses));
            const unsigned full_variant=variant|(clone?0x80000000u:0u);call(memory,0x571ec0,{0x20000,optional_basis?0x22000u:0u,0x21000,mode,full_variant});
            const auto made=owner.create_actor_contact(parent,optional_basis,point,mode,full_variant);const auto initial=active(memory);
            check(initial.size()<=1&&initial.size()==owner.size());
            if(initial.empty()){check(made.status==e::WorkStatus::resource_missing);owner.close();++channel_owner_cases;continue;}
            check(made.status==e::WorkStatus::completed&&made.id);state(memory,initial.front(),*owner.actor_contact_state(made.id));
            for(unsigned tick=0;tick<300&&owner.size();++tick){
                if(tick==17+pose*3){live->secondary=12;memory[0x20009]=12;}
                // Canonical weapon poses change before the timed rebind. This
                // verifies actual572290, optional basis persistence and clones.
                model.model->pose[0][0]=basis[0][0]+float(tick)*.015625f;model.model->position.x=float(tick)-13;
                put(memory,0x231c0,model.model->pose);put(memory,0x23200,model.model->position);
                for(auto at:active(memory))call(memory,0x572030,{at});
                const auto report=owner.update({12,-3,27});check(report.status==e::VisualStatus::completed);++channel_owner_frames;
                const auto frame=owner.retain();const auto original=active(memory);check(frame&&frame->visuals.size()==original.size()&&owner.size()==original.size());channel_owner_peak=std::max(channel_owner_peak,unsigned(owner.size()));
                for(std::size_t i=0;i<original.size();++i){const auto at=original[i];const auto& output=frame->visuals[i];check(output.category==9&&output.actor_contact.has_value());state(memory,at,*output.actor_contact);
                    check(output.visible==bool(memory[at+1])&&output.pieces.size()==memory[at+0x31]);
                    if(!output.visible)continue;
                    for(std::size_t j=0;j<output.pieces.size();++j){const auto& piece=output.pieces[j];check(piece.visible==bool(memory[at+0xf4+j]));if(piece.visible)contact_fixture::compare_piece(piece,get<unsigned>(memory,at+0x134+unsigned(4*j)),memory,*bank);}
                }
                check(tick+1<300);
            }
            check(!owner.size()&&!owner.piece_count()&&!owner.actor_contact_state(made.id));owner.close();++channel_owner_cases;
        }
        // Actual adapter sends styles3/7 into the concrete same-pool owner.
        for(unsigned style:{3u,7u}){
            e::PeriodicVisuals owner(bank,session->random);check(owner.bind_actor_contacts(world,poses));g::ContactWeaponEffects effects(world,owner,&owner);
            check(effects.contact_style(parent,m::identity(),{},std::uint8_t(style)));check(owner.size()==(bank->geometry().resolve(style==3?19:13)?1u:0u));owner.close();
        }
        e::PeriodicVisuals owner(bank,session->random);check(owner.bind_actor_contacts(world,poses));
        const unsigned selected_mode=bank->geometry().resolve(19)?0u:bank->geometry().resolve(13)?4u:3u;
        const auto selected_profile=e::actor_contact_profile(selected_mode,0);check(selected_profile.has_value());
        const bool present=bool(bank->geometry().resolve(std::int16_t(selected_profile->resource)));
        if(present){
            for(unsigned i=0;i<168;++i)check(owner.create_actor_contact(parent,{}, {},selected_mode,0).status==e::WorkStatus::completed);
            check(owner.create_actor_contact(parent,{}, {},selected_mode,0).status==e::WorkStatus::pool_full);
        }else check(owner.create_actor_contact(parent,{}, {},selected_mode,0).status==e::WorkStatus::resource_missing);
        check(owner.create_actor_contact(parent,{}, {},8,0).status==e::WorkStatus::unavailable);
        check(world.retire_primary(0)==g::actors::EntityStatus::completed);check(owner.update({}).status==e::VisualStatus::completed&&!owner.size());owner.close();channel_owner_refusals+=3;
    }
}
