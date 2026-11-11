#include "game/native/gameplay_world/scripted_motion.hpp"
#include "game/native/gameplay_world/linked_models.hpp"
std::uint64_t scripted_motion_cases{},scripted_motion_ticks{},scripted_motion_refusals{},scripted_positive_tracks{};
void scripted_motion_tests(const std::vector<std::vector<std::byte>>& banks,
                           const std::vector<std::vector<std::byte>>& skeletons,
                           std::vector<std::uint8_t>& ram){
    struct Input {std::vector<std::byte> raw,skeleton;unsigned key{};};
    std::vector<Input> inputs;
    for(unsigned asset=2;asset<banks.size();++asset){
        a::MotionBank candidate;candidate.load_strided(banks[asset],200,0,"owned scripted input");
        bool matched{};
        for(unsigned key=0;key<100&&!matched;++key){
            const auto block=candidate.find(key,0);if(!block)continue;
            try{
                const auto clip=block->clip();
                for(const auto& raw:skeletons)if(a::Skeleton::import_raw(raw)->nodes().size()==clip->tracks().size()){
                    inputs.push_back({banks[asset],raw,key});matched=true;break;
                }
            }catch(const std::invalid_argument&){}
        }
        check(matched,"actual scene bank has a matching owned skeleton");
    }
    auto additive=std::make_shared<a::MotionBank>();
    additive->load_sparse(banks[0],8,0,"pc000 scripted additive");
    additive->load_sparse(banks[1],8,1,"pc001 scripted additive");
    std::shared_ptr<const a::Skeleton> player_skeleton;std::vector<std::byte> player_raw;
    for(const auto& raw:skeletons){auto candidate=a::Skeleton::import_raw(raw);
        if(candidate->nodes().size()==36){player_skeleton=candidate;player_raw=raw;}}
    check(bool(player_skeleton),"owned player skeleton for additive and multi-track cases");
    std::array<unsigned,3> counts{};
    for(const auto& node:player_skeleton->nodes())if(node.track<counts.size())++counts[node.track];
    unsigned additive_key{},primary_key{};
    for(unsigned key=1;key<1000&&(!additive_key||!primary_key);++key){
        try{
            const auto two=additive->find(key,2);
            if(!additive_key&&two&&two->clip()->tracks().size()==counts[2])additive_key=key;
            const auto zero=additive->find(key,0),one=additive->find(key,1);
            if(!primary_key&&zero&&one&&zero->clip()->tracks().size()==counts[0]&&one->clip()->tracks().size()==counts[1])primary_key=key;
        }catch(const std::invalid_argument&){}
    }
    check(additive_key&&primary_key,"owned PC motions supply real primary and positive additive tracks");
    // A two-track strided scene container, holding actual owned PC clip bytes,
    // exercises the wrapper's secondary-before-base update ordering.
    std::vector<std::byte> multi(32,std::byte{255});
    auto write_multi=[&](unsigned at,auto value){std::memcpy(multi.data()+at,&value,sizeof(value));};
    write_multi(0,0u);write_multi(4,2u);write_multi(8,4u);write_multi(12,16u);
    for(unsigned track=0;track<2;++track){
        const auto block=additive->find(primary_key,std::uint16_t(track));
        const auto offset=unsigned(multi.size());multi.insert(multi.end(),block->bytes().begin(),block->bytes().end());
        write_multi(24+4*track,offset);
    }
    inputs.push_back({std::move(multi),player_raw,1});
    constexpr std::uint32_t mode_one_at=0x4bc810,other_at=0x4e8970,additive_at=0x4bbb80;
    for(unsigned input=0;input<inputs.size();++input){
        const auto skeleton=a::Skeleton::import_raw(inputs[input].skeleton);
        auto mode_one=std::make_shared<a::MotionBank>(),other=std::make_shared<a::MotionBank>();
        mode_one->load_strided(inputs[input].raw,200,0,"mode-one scripted scene");
        other->load_strided(inputs[input].raw,200,0,"other-mode scripted scene");
        const auto key=inputs[input].key;
        for(unsigned variant=0;variant<256;++variant){
            location="scripted actor input="+std::to_string(input)+" variant="+std::to_string(variant);
            std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);
            std::fill_n(ram.data()+second,skeleton->nodes().size()*400,0);
            std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+work,0x1468,0);
            std::fill_n(ram.data()+additive_at,0x2000,0);std::fill_n(ram.data()+other_at,0x2000,0);
            std::memcpy(ram.data()+0x400000,inputs[input].skeleton.data(),inputs[input].skeleton.size());
            call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
            call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
            put(ram.data(),actor+0x34,work);put(ram.data(),work,work+0x820);put(ram.data(),work+4,work+0xa20);
            put(ram.data(),work+0x816,std::uint16_t(skeleton->nodes().size()));
            for(unsigned i=0;i<skeleton->nodes().size();++i){
                put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);
            }
            resources={0,skeleton_resource};
            const auto pack=[&](const std::shared_ptr<const a::MotionBlock>& block){
                const auto token=unsigned(resources.size()),packed=0x900000+0x80000*(token-2);
                resources.push_back(packed);check(block->bytes().size()<0x40000,"scripted clip packing arena bounded");
                std::memcpy(ram.data()+0x500000,block->bytes().data(),block->bytes().size());
                call(ram.data(),0x1a1fd0,0x18000,packed,0x500000);return std::uint16_t(token);
            };
            // Populate only consumed slots. The original global bank arrays
            // overlap; zeroing/copying a guessed full capacity would corrupt
            // another bank's initialized header.
            for(unsigned track=0;track<mode_one->track_count();++track){
                const auto block=mode_one->find(key,std::uint16_t(track));check(bool(block),"selected actual scene track exists");
                const auto token=pack(block);
                const auto slot=200*(key/100)+(key%100)*mode_one->track_count()+track;
                put(ram.data(),mode_one_at+4+2*slot,token);put(ram.data(),other_at+4+2*slot,token);
            }
            ram[mode_one_at]=mode_one->first_track();ram[mode_one_at+1]=mode_one->track_count();
            ram[other_at]=other->first_track();ram[other_at+1]=other->track_count();
            ram[additive_at]=additive->first_track();ram[additive_at+1]=additive->track_count();ram[additive_at+2]=std::uint8_t(additive->kind());
            const auto additive_token=pack(additive->find(additive_key,2));
            const auto row=additive->rows()[additive_key];
            put(ram.data(),additive_at+0xfa4+2*additive_key,row);put(ram.data(),additive_at+4+2*(row+2),additive_token);

            g::World world(world_profile(),std::make_shared<g::Session>());
            const auto id=world.linked_models().allocate(true).id;const auto current=world.resolve(id);
            check(bool(current),"scripted callback uses actual World linked actor");
            current->category=2;current->model=std::make_shared<a::Instance>(skeleton);
            current->animation=std::make_shared<a::Playback>(current->model);
            current->animation->resources_known=true;current->animation->channel_count=std::uint8_t((variant/8)%6);
            current->scripted.emplace();auto& control=*current->scripted;
            control.motion_rate_mode=std::bit_cast<std::int8_t>(std::uint8_t(variant));
            control.motion_selector=std::int8_t(key);control.motion_blend_duration=std::array{0.f,3.5f,-5.f,.25f}[(variant/2)%4];
            current->model_pose_class=std::uint8_t(variant%4==2?1:variant%3);
            if(variant%4==1)control.track_two_motion=-1;
            else if(variant%4==2||((variant%4==0)&&skeleton->nodes().size()==36))control.track_two_motion=std::int16_t(additive_key);
            current->contact_flags=0xa400;current->motion_class=5;current->motion_rate=2;
            current->auxiliary_status=0x89abcd00u|(variant%3==0?2u:0u);
            current->root_motion_delta={3,4,5};current->control_elapsed=0x12345678;
            world.session().clock_mode=std::uint8_t((variant/4)%2);
            put(ram.data(),actor+2,current->category);put(ram.data(),actor+0x524,current->animation->channel_count);
            put(ram.data(),actor+0x54a,current->contact_flags);put(ram.data(),actor+0x54d,current->model_pose_class);
            put(ram.data(),actor+0x54f,current->motion_class);put(ram.data(),actor+0xba8,current->motion_rate);
            put(ram.data(),actor+0xba4,current->auxiliary_status);put(ram.data(),actor+0x4e4,current->root_motion_delta);
            put(ram.data(),actor+0xb40,control.motion_rate_mode);put(ram.data(),actor+0xb43,control.motion_selector);
            put(ram.data(),actor+0xb44,control.motion_blend_duration);put(ram.data(),actor+0xb7c,control.track_two_motion);
            put(ram.data(),actor+0xd28,current->control_elapsed);put(ram.data(),0x3243cc,world.session().clock_mode);
            g::ScriptedActorMotion motion(world,{mode_one,other,additive});
            for(unsigned tick=0;tick<5;++tick){
                if(tick==4){current->phase=std::uint8_t(variant%2?2:255);ram[actor+0xa]=current->phase;}
                const auto pending=control.track_two_motion;
                motion.tick(id);call(ram.data(),0x67bff0,actor);
                check(current->phase==ram[actor+0xa]&&current->motion_class==ram[actor+0x54f]&&bits(current->motion_rate)==get<std::uint32_t>(ram.data(),actor+0xba8),"scripted phase/class/rate effects");
                check(current->contact_flags==get<std::uint16_t>(ram.data(),actor+0x54a)&&current->auxiliary_status==get<std::uint32_t>(ram.data(),actor+0xba4),"scripted control and consumed duration-reset mask");
                check(control.track_two_motion==get<std::int16_t>(ram.data(),actor+0xb7c)&&current->control_elapsed==0x12345678,"scripted pending track and independent primary control state");
                const auto selected=control.motion_rate_mode==1?mode_one:other;
                check(current->animation->resources[0]==selected&&get<std::uint32_t>(ram.data(),actor+0x514)==(control.motion_rate_mode==1?mode_one_at:other_at),"exact-one resource selection differs from nonzero rate selection");
                records(*current->animation,ram,{current->root_motion_delta.x,current->root_motion_delta.y,current->root_motion_delta.z});
                if(pending>0&&current->model_pose_class!=1)++scripted_positive_tracks;
                ++scripted_motion_ticks;
            }
            const auto lease=current;const auto flags=current->contact_flags;
            check(world.linked_models().reset()==g::LinkedStatus::completed,"scripted actor retirement");
            bool refused{};try{motion.tick(id);}catch(const std::runtime_error&){refused=true;}
            check(refused&&lease->contact_flags==flags,"retired callback refuses before old actor mutation");
            ++scripted_motion_refusals;++scripted_motion_cases;
        }
    }
    check(scripted_positive_tracks!=0,"actual owned positive track-two animation consumed");
    for(unsigned failure=0;failure<8;++failure){
        location="scripted actor refusal="+std::to_string(failure);
        g::World world(world_profile(),std::make_shared<g::Session>());
        const auto id=world.linked_models().allocate(true).id;const auto value=world.resolve(id);
        value->category=2;value->scripted.emplace();value->scripted->motion_selector=1;
        value->model=std::make_shared<a::Instance>(player_skeleton);
        value->animation=std::make_shared<a::Playback>(value->model);
        value->animation->resources_known=true;value->contact_flags=0xa400;
        g::ScriptedActorMotion motion(world,{});
        if(failure==0)value->scripted.reset();
        if(failure==1)value->category=0;
        if(failure==2)value->animation.reset();
        if(failure==3)value->animation=std::make_shared<a::Playback>(std::make_shared<a::Instance>(player_skeleton));
        if(failure==4)value->phase=1;
        if(failure==5){value->phase=1;value->animation->resources_known=false;}
        if(failure==6){value->phase=2;value->scripted->track_two_motion=1;}
        if(failure==7)check(world.close()==g::Status::completed,"scripted closed-world test setup");
        bool refused{};try{motion.tick(id);}catch(const std::runtime_error&){refused=true;}
        check(refused,"missing scripted actor/model/resource fails visibly");
        check(value->contact_flags==((failure<2||failure==7)?0xa400:0xa417),"scripted failure preserves the effects preceding unavailable evidence");
        ++scripted_motion_refusals;
    }
    // An unused phase needs neither a model nor a bank. A model-kind-one
    // pending track is also intentionally preserved without consuming a bank.
    g::World world(world_profile(),std::make_shared<g::Session>());
    const auto id=world.linked_models().allocate(true).id;const auto value=world.resolve(id);
    value->category=2;value->phase=255;value->scripted.emplace();
    g::ScriptedActorMotion motion(world,{});motion.tick(id);
    check(value->contact_flags==0x17&&!value->animation,"inactive scripted phase has no invented resource requirement");
    value->model_pose_class=1;value->scripted->track_two_motion=123;motion.tick(id);
    check(value->scripted->track_two_motion==123&&!value->animation,"model-kind-one pending track remains deferred");
}
