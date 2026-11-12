#include "game/native/gameplay_world/cinematic_objects.hpp"
std::uint64_t cinematic_object_reservations{},cinematic_object_pose_cases{},cinematic_object_passes{},cinematic_object_publications{},cinematic_object_ticks{},cinematic_object_refusals{};
void cinematic_object_pose_tests(std::vector<std::uint8_t>& ram){
    constexpr unsigned object=0x600000,key=0xc00000;std::array<std::byte,72> bytes{};
    const auto write=[&](unsigned at,auto data){std::memcpy(bytes.data()+at,&data,sizeof data);};
    write(2,std::uint16_t(17));write(4,a::Vector{1.25f,-3.5f,9.75f});write(24,a::Vector{-6,9,12});write(40,a::Vector{8,3,-4});write(38,std::uint16_t(65535));
    const auto compare=[&](std::int32_t frame){
        const auto pose=g::CinematicObjectPose::read(bytes);a::Vector position{97,98,99};t::Angles angles{1,2,3};
        put(ram.data(),object+0x20,position);put(ram.data(),object+0x18,angles);put(ram.data(),object+0x1178,key);put(ram.data(),0x38eca8,frame);std::memcpy(ram.data()+key,bytes.data(),bytes.size());
        g::evaluate_cinematic_object_pose(pose,frame,position,angles);call(ram.data(),0x5712d0,object);
        check(std::memcmp(&position,ram.data()+object+0x20,12)==0&&std::memcmp(angles.data(),ram.data()+object+0x18,6)==0,"complete original object timeline pose and angle conversion");++cinematic_object_pose_cases;
    };
    for(unsigned raw=0;raw<65536;++raw){location="object single pose="+std::to_string(raw);write(16,std::bit_cast<std::int16_t>(std::uint16_t(raw)));write(18,std::bit_cast<std::int16_t>(std::uint16_t(raw^0xffff)));write(20,std::bit_cast<std::int16_t>(std::uint16_t(raw*113)));compare(0);}
    for(unsigned variant=0;variant<2048;++variant){
        location="object interpolated pose="+std::to_string(variant);const auto start=std::uint16_t(variant%3?17:60000),end=std::uint16_t(variant%7?variant%3?91:5:start);
        write(2,start);write(38,end);
        for(unsigned axis=0;axis<3;++axis){const auto degree=std::int16_t(int(variant*37+axis*113)%20000-10000);write(16+axis*2,degree);write(52+axis*2,variant%2?degree:std::int16_t(degree/3));}
        compare(std::array<std::int32_t,8>{-100,0,17,54,91,65535,60001,70000}[variant%8]);
    }
    // Exercise the explicit >=2^31 conversion branch with a finite, in-range
    // unsigned result; signed-negative exceptional conversion is not admitted.
    write(2,std::uint16_t(0));write(38,std::uint16_t(1));
    for(unsigned axis=0;axis<3;++axis){write(16+axis*2,std::int16_t(0));write(52+axis*2,std::int16_t(300));}compare(65535);
    bool refused{};try{(void)g::CinematicObjectPose::read(std::span(bytes).first(39));}catch(const std::invalid_argument&){refused=true;}check(refused,"object pose refuses missing next header");++cinematic_object_refusals;
    refused=false;try{(void)g::CinematicObjectPose::read(std::span(bytes).first(57));}catch(const std::invalid_argument&){refused=true;}check(refused,"interpolated object pose refuses missing next values");++cinematic_object_refusals;
    write(38,std::uint16_t(65535));check(g::CinematicObjectPose::read(std::span(bytes).first(40)).end==65535,"terminal object key needs only next sentinel header");
}
void cinematic_object_reservation_tests(std::vector<std::uint8_t>& ram){
    g::World absent(world_profile(),std::make_shared<g::Session>());auto& missing=absent.cinematic_objects();put(ram.data(),0x38edd4,0u);
    const auto original_absent=call(ram.data(),0x5f1390,0);check(missing.reserve_inactive().status==g::CinematicObjectStatus::uninitialized&&GPR_U32(&original_absent,2)==0,"absent object reservation base is explicit unavailable storage");
    std::uint32_t random=0x7f013e;
    for(unsigned seed=0;seed<4096;++seed){location="object reservation="+std::to_string(seed);g::World world(world_profile(),std::make_shared<g::Session>());world.paused=1;auto& pool=world.cinematic_objects();
        check(pool.initialize()==g::CinematicObjectStatus::completed,"reservation uses actual separate object storage");put(ram.data(),0x4badf8,world.paused);call(ram.data(),0x571010,0x600000);
        for(unsigned slot=0;slot<16;++slot){random=random*1664525u+1013904223u;const auto value=pool.resolve(pool.identity_at(slot));value->active=(random>>28)&1;value->reserved=(random>>27)&1;const auto at=0x600000+slot*0x11a0;ram[at]=value->active;put(ram.data(),at+0x1198,std::uint32_t(value->reserved));}
        for(unsigned repeat=0;repeat<4;++repeat){const auto result=pool.reserve_inactive();const auto source=call(ram.data(),0x5f1390,0);const auto pointer=GPR_U32(&source,2);
            if(pointer){check(result.status==g::CinematicObjectStatus::completed&&result.slot&&pointer==0x600000+unsigned(*result.slot)*0x11a0&&pool.resolve(result.id)&&!pool.resolve(result.id)->active&&pool.resolve(result.id)->reserved,"actual first inactive/unreserved object reservation without activation");}
            else check(result.status==g::CinematicObjectStatus::full&&!result.id&&!result.slot,"full object reservation preserves exact capacity");
            for(unsigned slot=0;slot<16;++slot){const auto value=pool.resolve(pool.identity_at(slot));const auto at=0x600000+slot*0x11a0;check(bool(ram[at])==value->active&&bool(get<std::uint32_t>(ram.data(),at+0x1198))==value->reserved,"all object reservation/activity states match original");}
            ++cinematic_object_reservations;
        }
        check(world.close()==g::Status::completed,"reserved object bank closes");
    }
}
void cinematic_object_tests(const std::vector<std::vector<std::byte>>& banks,const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    cinematic_object_pose_tests(ram);
    cinematic_object_reservation_tests(ram);
    struct Input{a::MotionBank motions;std::shared_ptr<const a::Skeleton> skeleton;std::vector<std::byte> raw;unsigned key;std::shared_ptr<const a::MotionBlock> block;};std::vector<Input> inputs;
    for(unsigned bank=2;bank<banks.size();++bank){a::MotionBank motions;motions.load_strided(banks[bank],200,0,"owned cinematic object scene motion");bool found{};
        for(unsigned key=0;key<100&&!found;++key){const auto block=motions.find(key,0);if(!block)continue;std::shared_ptr<const a::Clip> clip;try{clip=block->clip();}catch(const std::invalid_argument&){continue;}
            for(const auto& raw:skeletons){const auto skeleton=a::Skeleton::import_raw(raw);if(skeleton->nodes().size()==clip->tracks().size()){inputs.push_back({motions,skeleton,raw,key,block});found=true;break;}}
        }
        check(found,"owned scene supplies matching object model/clip fixture");
    }
    constexpr unsigned base=0x600000;
    for(unsigned input=0;input<inputs.size();++input)for(unsigned variant=0;variant<128;++variant){
        location="object bank="+std::to_string(input)+" variant="+std::to_string(variant);const auto& data=inputs[input];g::World world(world_profile(),std::make_shared<g::Session>());auto& pool=world.cinematic_objects();
        check(pool.initialize()==g::CinematicObjectStatus::unchanged&&!pool.initialized(),"pause-zero initialization preserves absent storage");
        world.paused=std::bit_cast<std::int8_t>(std::array<std::uint8_t,3>{1,127,255}[variant%3]);put(ram.data(),0x4badf8,world.paused);
        check(pool.initialize()==g::CinematicObjectStatus::completed&&pool.initialized(),"separate sixteen-object storage initialized");
        std::fill_n(ram.data()+base,16*0x11a0,0xa5);call(ram.data(),0x571010,base);
        for(unsigned i=0;i<16;++i){const auto value=pool.resolve(pool.identity_at(i));const auto at=base+i*0x11a0;
            check(value&&value->category==ram[at+2]&&!value->active&&!value->visible&&!value->phase&&!value->flags&&!value->reserved&&!value->model&&!value->pose,"actual cleared category-ten record");
        }
        const auto old=pool.identity_at(0);const auto old_lease=pool.resolve(old);old_lease->active=true;old_lease->position.x=99;
        check(pool.initialize()==g::CinematicObjectStatus::completed&&!pool.resolve(old)&&old_lease->position.x==99,"generation reset revokes prior identities while invocation leases survive");
        call(ram.data(),0x571010,base);
        world.session().clock_mode=std::uint8_t(variant%4);ram[0x3243cc]=world.session().clock_mode;
        resources={0,skeleton_resource,0x900000};std::memcpy(ram.data()+0x400000,data.raw.data(),data.raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
        std::memcpy(ram.data()+0x500000,data.block->bytes().data(),data.block->bytes().size());call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);
        const auto encoded=data.key;put(ram.data(),0x4baef4+2*(200*(encoded/100)+encoded%100),std::uint16_t(2));
        std::vector<std::array<std::byte,72>> poses(16);
        for(unsigned slot=0;slot<16;++slot){const auto at=base+slot*0x11a0;const auto node_base=0xa00000+slot*0x10000;const auto value=pool.resolve(pool.identity_at(slot));
            value->active=(variant+slot)%5!=0;value->visible=(variant+slot)%3==0;value->phase=std::uint8_t((variant+slot)%7==0?2:(variant+slot)%7==1?255:0);value->animation_phase=std::uint8_t((variant+slot)%4);value->motion=encoded;value->flags=(variant+slot)%2?1:4;
            value->model=std::make_shared<a::Instance>(data.skeleton);value->model->relabel_prefix(value->model->nodes().size(),0);
            value->position={10,20,30};value->angles={std::uint16_t(variant*113),std::uint16_t(slot*71),std::uint16_t(variant*17)};
            value->timing={0,data.block->clip()->last_frame(),0,0,std::uint8_t(variant)};
            ram[at]=value->active;ram[at+1]=value->visible;ram[at+4]=value->phase;ram[at+5]=value->animation_phase;
            put(ram.data(),at+0x18,value->angles);put(ram.data(),at+0x20,value->position);put(ram.data(),at+0x30,value->basis);put(ram.data(),at+0x117c,value->motion);put(ram.data(),at+0x118c,value->flags);
            put(ram.data(),at+0x1150,value->timing.frame);put(ram.data(),at+0x1154,value->timing.end);put(ram.data(),at+0x1158,value->timing.restart);ram[at+0x115c]=std::uint8_t(value->timing.loop);ram[at+0x115d]=value->timing.flags;
            std::fill_n(ram.data()+node_base,value->model->nodes().size()*400,0);call(ram.data(),0x193380,node_base,1);put(ram.data(),at+0x70,at+0x890);for(unsigned i=0;i<value->model->nodes().size();++i){put(ram.data(),at+0x890+4*i,node_base+400*i);put(ram.data(),node_base+400*i+0xc6,std::uint16_t(0));}
            // Bind an initial clip so source/native tick-only entries use the
            // same admitted prior animation. Requested entries rebind it.
            a::bind_scalar_frame(*value->model,value->timing,data.block->clip(),0);call(ram.data(),0x58c810,node_base,at+0x1150,2,0,0);
            // Source packing does not promise initialized unused world matrices.
            // Give both sides the same explicit prior publication so inactive
            // and held-state records have defined model state to preserve.
            value->model->rebuild(t::identity());put(ram.data(),0x270000,t::identity());call(ram.data(),0x193240,node_base,0x270000);
            if((variant+slot)%3){auto& bytes=poses[slot];const auto write=[&](unsigned off,auto v){std::memcpy(bytes.data()+off,&v,sizeof v);};
                write(2,std::uint16_t(17));write(38,std::uint16_t((variant+slot)%2?91:65535));write(4,a::Vector{10,20,30});write(24,a::Vector{-8,4,13});write(40,a::Vector{40,-20,10});
                write(16,std::array<std::int16_t,3>{30,-60,90});write(52,std::array<std::int16_t,3>{-100,100,45});value->pose=g::CinematicObjectPose::read(bytes);
                const auto pose_at=0xc00000+slot*0x100;std::memcpy(ram.data()+pose_at,bytes.data(),bytes.size());put(ram.data(),at+0x1178,pose_at);
            }
        }
        for(unsigned tick=0;tick<4;++tick){const auto frame=std::int32_t(variant%3==0?-50:variant%3==1?54:150);put(ram.data(),0x38eca8,frame);
            const auto result=pool.run(data.motions,frame);call(ram.data(),0x571080,0);check(result.status==g::CinematicObjectStatus::completed&&result.visited==16&&!world.busy(),"complete fixed object pass and released guard");
            unsigned called{},published{};
            for(unsigned slot=0;slot<16;++slot){const auto value=pool.resolve(pool.identity_at(slot));const auto at=base+slot*0x11a0,node_base=0xa00000+slot*0x10000;
                if(value->active){++called;if(value->phase==1)++published;}
                check(value->phase==ram[at+4]&&value->animation_phase==ram[at+5]&&value->flags==get<std::uint32_t>(ram.data(),at+0x118c),"object initialization animation stage and exact flag toggles");
                check(std::memcmp(&value->position,ram.data()+at+0x20,12)==0&&std::memcmp(value->angles.data(),ram.data()+at+0x18,6)==0&&std::memcmp(&value->basis,ram.data()+at+0x30,64)==0,"object pose and rotation/translation matrix");
                check(bits(value->timing.frame)==get<std::uint32_t>(ram.data(),at+0x1150)&&bits(value->timing.end)==get<std::uint32_t>(ram.data(),at+0x1154)&&bits(value->timing.restart)==get<std::uint32_t>(ram.data(),at+0x1158)&&value->timing.loop==get<std::int8_t>(ram.data(),at+0x115c)&&value->timing.flags==ram[at+0x115d],"object scalar playback timing record");
                for(unsigned i=0;i<value->model->nodes().size();++i){const auto& node=value->model->nodes()[i];const auto addr=node_base+400*i;if(std::memcmp(&node.local,ram.data()+addr+0x40,64)||std::memcmp(&node.world,ram.data()+addr,64)||std::memcmp(node.parameters.data(),ram.data()+addr+0x104,40)||std::memcmp(node.caches.data(),ram.data()+addr+0x15c,20))std::cerr<<"object mismatch tick="<<tick<<" slot="<<slot<<" joint="<<i<<" local="<<std::memcmp(&node.local,ram.data()+addr+0x40,64)<<" world="<<std::memcmp(&node.world,ram.data()+addr,64)<<" params="<<std::memcmp(node.parameters.data(),ram.data()+addr+0x104,40)<<" caches="<<std::memcmp(node.caches.data(),ram.data()+addr+0x15c,20)<<'\n';check(std::memcmp(&node.local,ram.data()+addr+0x40,64)==0&&std::memcmp(&node.world,ram.data()+addr,64)==0&&std::memcmp(node.parameters.data(),ram.data()+addr+0x104,40)==0&&std::memcmp(node.caches.data(),ram.data()+addr+0x15c,20)==0,"object actual native animated model and recursive publication");}
            }
            check(result.called==called&&result.published==published,"object service and publication counts");cinematic_object_publications+=published;++cinematic_object_passes;++cinematic_object_ticks;
        }
        world.paused=0;put(ram.data(),0x4badf8,world.paused);const auto id=pool.identity_at(0);check(pool.initialize()==g::CinematicObjectStatus::unchanged&&pool.identity_at(0)==id&&pool.run(data.motions,0).status==g::CinematicObjectStatus::unchanged,"zero-pause preserves current object bank and does no service");call(ram.data(),0x571010,base);call(ram.data(),0x571080,0);
        const auto retained=pool.resolve(id);check(world.close()==g::Status::completed&&!pool.resolve(id)&&pool.run(data.motions,0).status==g::CinematicObjectStatus::closed&&retained,"World closure revokes object identities while retained model lease survives");
    }
    for(const bool through_world:{false,true}){
        g::World guarded(world_profile(),std::make_shared<g::Session>());guarded.paused=1;auto& storage=guarded.cinematic_objects();check(storage.initialize()==g::CinematicObjectStatus::completed,"destructor-guard object storage");
        bool called{},guarded_close{};const auto id=storage.identity_at(0);
        storage.resolve(id)->model=std::shared_ptr<a::Instance>(new a::Instance(inputs.front().skeleton),[&](a::Instance* model){called=true;guarded_close=guarded.close()==g::Status::busy&&storage.close()==g::CinematicObjectStatus::busy;delete model;});
        if(through_world)check(guarded.close()==g::Status::completed,"World closes actual object models");else check(storage.close()==g::CinematicObjectStatus::completed,"explicit object close");
        check(called&&guarded_close&&!guarded.busy()&&!storage.resolve(id)&&guarded.close()==g::Status::completed,"model destructors see revoked identities and protected World/object closure");
    }
    g::World world(world_profile(),std::make_shared<g::Session>());world.paused=1;auto& pool=world.cinematic_objects();check(pool.run(inputs.front().motions,0).status==g::CinematicObjectStatus::unchanged,"uninitialized object bank is a measured no-work pass");check(pool.initialize()==g::CinematicObjectStatus::completed,"object failure storage");
    const auto first=pool.resolve(pool.identity_at(0));first->active=true;const auto failed=pool.run(inputs.front().motions,0);check(failed.status==g::CinematicObjectStatus::unavailable&&failed.failed==pool.identity_at(0)&&first->phase==1&&!world.busy(),"missing object model reports required failure after phase prelude");++cinematic_object_refusals;
    first->model=std::make_shared<a::Instance>(inputs.front().skeleton);first->flags=1;first->motion=UINT32_MAX;const auto absent=pool.run(inputs.front().motions,0);check(absent.status==g::CinematicObjectStatus::unavailable&&first->flags==1&&!world.busy(),"out-of-bounds literal object motion table index refuses without bank-header fallback");++cinematic_object_refusals;
    first->motion=inputs.front().key;first->model->relabel_prefix(first->model->nodes().size(),0);first->pose=g::CinematicObjectPose{0,1,{1,2,3},{4,5,6},{7,8,9},{0,0,0},{300,300,300}};
    bool threw{};try{(void)pool.run(inputs.front().motions,INT32_MAX);}catch(const std::out_of_range&){threw=true;}check(threw&&!world.busy()&&first->flags==3&&pool.close()==g::CinematicObjectStatus::completed&&world.close()==g::Status::completed,"unadmitted numeric pose failure retains flags/binding prefix and releases guard");++cinematic_object_refusals;
}
