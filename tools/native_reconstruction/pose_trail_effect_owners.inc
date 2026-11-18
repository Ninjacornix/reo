#include "game/native/gameplay_effects/periodic_visuals.hpp"
#include <fstream>
namespace trail_owned_fixture {
e::PeriodicVisuals* reference{};std::shared_ptr<const e::EffectBank> bank;std::optional<e::WorkCreated> created;
std::vector<std::vector<std::byte>> corpus(const char* path){std::ifstream in(path,std::ios::binary);unsigned count{};in.read(reinterpret_cast<char*>(&count),4);check(count==12);std::vector<std::vector<std::byte>> out;for(unsigned i=0;i<count;++i){unsigned size{};in.read(reinterpret_cast<char*>(&size),4);check(size&&size<10000000);out.emplace_back(size);in.read(reinterpret_cast<char*>(out.back().data()),size);check(bool(in));}return out;}
}
unsigned owned_cases{},owned_frames{},owned_configurations{},owned_missing{},owned_unavailable{},owned_guards{};
bool trail_owned_port(std::uint8_t* memory,R5900Context* context){
    using namespace trail_owned_fixture;if(!reference)return false;
    if(context->pc!=0x6525c0)return false;
    e::WorkRequest q;check(!GPR_U32(context,4));q.position=get<m::Vector>(memory,GPR_U32(context,5));q.child_mask=GPR_U32(context,6);q.effect=std::uint16_t(GPR_U32(context,7));q.variant=std::int16_t(GPR_U32(context,8));q.flags=GPR_U32(context,9);expected.push_back(q);created=reference->create(q);
    if(created->status!=e::WorkStatus::completed){SET_GPR_U32(context,2,0);return true;}
    check(bool(created->edit));std::memset(memory+raw_work,0,0x240);put(memory,raw_work+0xb4,m::Vector{1,1,1});put(memory,raw_work+0x208,std::array<float,4>{1,1,1,1});put(memory,raw_work+0x200,q.flags|0xa000u);const auto count=bank->bind(q.effect,q.variant).pieces.size();check(count<=16);memory[raw_work+0x31]=std::uint8_t(count);
    for(unsigned i=0;i<count;++i){const auto at=0x40000+0x100*i;put(memory,raw_work+0x134+4*i,at);put(memory,at+4,q.flags|0xa000u|((q.child_mask&(1u<<i))?0u:0x800u));put(memory,at+12,m::Vector{1,1,1});}
    SET_GPR_U32(context,2,raw_work);return true;
}
void trail_effect_owners(std::uint8_t* memory,const char* path){
    using namespace trail_owned_fixture;const auto assets=corpus(path);
    for(unsigned asset=0;asset<assets.size();asset+=2){bank=e::EffectBank::import(assets[asset],assets[asset+1]);
        for(unsigned water=0;water<2;++water)for(unsigned type:{0u,7u,0xau,0x13u,0x1du,0x1eu})for(unsigned mode:{0u,2u,3u}){
            auto native_session=std::make_shared<g::Session>(),original_session=std::make_shared<g::Session>();g::Profile p;p.layouts.push_back({});p.entities.capacity=16;g::World world(p,native_session);world.room=7;const auto parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id,motion=world.spawn_primary(1,std::make_unique<g::Actor>()).id;check(parent&&motion);world.resolve(parent)->slot=std::uint8_t(type);world.resolve(motion)->position={10,5,10};e::PeriodicVisuals native(bank,native_session->random),original(bank,original_session->random);g::MappedPoseTrailEffects effects(world,native,rooms);rooms.room=std::make_shared<Room>(water?0x81:0);rooms.reads=0;expected.clear();expected_configs.clear();created.reset();original_queries=0;original_mode=mode;
            const m::Vector point{20,7,20};memory[parent_at+3]=std::uint8_t(type);put(memory,motion_at+0x38,m::Vector{10,5,10});put(memory,point_at,point);R5900Context context;PS2Runtime runtime;context.pc=0x578620;SET_GPR_U32(&context,4,parent_at);SET_GPR_U32(&context,5,motion_at);SET_GPR_U32(&context,6,mode);SET_GPR_U32(&context,7,point_at);SET_GPR_U32(&context,8,3);SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x1234);reference=&original;original_transform_port(memory,&context,&runtime);reference=nullptr;check(context.pc==0x1234&&GPR_U32(&context,29)==0x1f00000);
            const bool actual=effects.emit_at(parent,motion,std::uint8_t(mode),point,3);check(actual==(!created||created->status!=e::WorkStatus::unavailable));check(native.size()==original.size()&&native.piece_count()==original.piece_count()&&rooms.reads==original_queries);
            if(created&&created->status==e::WorkStatus::completed){
                check(native.size()==1&&expected_configs.size()==1);const auto frame=native.retain();check(!frame);const auto native_id=created->edit->identity();(void)native_id;
                // Obtain the native generation from its actual immutable frame;
                // publish after configuration, then compare against raw source
                // output and a separate visual owner projected from that output.
                const auto ref_edit=std::dynamic_pointer_cast<e::ParticleEdit>(created->edit);check(bool(ref_edit));const auto parameters=get<m::Vector>(memory,raw_work+0x208);const auto scale=get<float>(memory,raw_work+0xb4);const bool feedback=get<unsigned>(memory,raw_work+0x200)&0x40;const std::array<float,6> source_policy{scale,feedback?1.f:0.f,parameters.x,parameters.y,parameters.z,get<float>(memory,raw_work+0xa8)};check(ref_edit->configure_particle(memory[raw_work+4],get<std::int16_t>(memory,raw_work+12),source_policy));
                for(unsigned tick=0;tick<12;++tick){const auto a=native.update({0,1,0}),b=original.update({0,1,0});check(a.status==e::VisualStatus::completed&&b.status==e::VisualStatus::completed&&a.visited==b.visited&&a.retired==b.retired&&a.pieces==b.pieces);const auto actual_frame=native.retain(),expected_frame=original.retain();check(actual_frame&&expected_frame&&actual_frame->visuals.size()==expected_frame->visuals.size());
                    for(unsigned i=0;i<actual_frame->visuals.size();++i){const auto& av=actual_frame->visuals[i];const auto& bv=expected_frame->visuals[i];check(av.visible==bv.visible&&av.category==bv.category&&av.pieces.size()==bv.pieces.size());const auto as=native.particle_state(av.id),bs=original.particle_state(bv.id);check(as&&bs&&as->mode==bs->mode&&as->delay==bs->delay&&as->attributes==bs->attributes&&as->flags==bs->flags&&std::memcmp(&as->scale,&bs->scale,12)==0&&std::memcmp(&as->parameters208,&bs->parameters208,12)==0&&as->feedback_scale==bs->feedback_scale);if(tick==0){check(as->category==memory[raw_work+3]&&as->mode==memory[raw_work+4]&&as->attributes==get<std::uint16_t>(memory,raw_work+0x23e)&&std::memcmp(&as->scale,memory+raw_work+0xb4,12)==0&&std::memcmp(&as->parameters208,memory+raw_work+0x208,12)==0);}
                        for(unsigned j=0;j<av.pieces.size();++j){const auto& ap=av.pieces[j];const auto& bp=bv.pieces[j];check(ap.root==bp.root&&ap.mesh==bp.mesh&&ap.material==bp.material&&ap.flags==bp.flags&&ap.visible==bp.visible&&ap.material_values==bp.material_values&&std::memcmp(&ap.parameters208,&bp.parameters208,12)==0&&std::memcmp(&ap.parameters.scale,&bp.parameters.scale,12)==0&&std::memcmp(&ap.parameters.translation,&bp.parameters.translation,12)==0&&ap.parameters.rotation==bp.parameters.rotation);}
                    }++owned_frames;
                }++owned_configurations;
            }else if(created&&created->status==e::WorkStatus::resource_missing)++owned_missing;
            else if(created&&created->status==e::WorkStatus::unavailable)++owned_unavailable;
            check(native_session->random.state()==original_session->random.state());++owned_cases;
        }
    }
    check(owned_cases==216&&owned_frames>0&&owned_configurations>0&&owned_missing>0);
    // Distinct mode1 callbacks remain required when that path is reached.
    auto session=std::make_shared<g::Session>();g::Profile p;p.layouts.push_back({});p.entities.capacity=16;g::World world(p,session);world.room=7;const auto parent=world.spawn_primary(0,std::make_unique<g::Actor>()).id,motion=world.spawn_primary(1,std::make_unique<g::Actor>()).id;world.resolve(parent)->slot=7;world.resolve(motion)->position={10,5,10};e::PeriodicVisuals native(bank,session->random);g::MappedPoseTrailEffects effects(world,native,rooms);check(!effects.emit(parent,motion,1)&&native.size()==0);++owned_guards;check(effects.emit({}, {},4));world.resolve(parent)->slot=0;check(effects.emit(parent,{},0));native.close();check(!effects.bound_to(world)&&!effects.emit(parent,motion,0));++owned_guards;
}
