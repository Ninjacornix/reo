void primary_routing_tests(const std::vector<std::vector<std::byte>>& banks,
                           const std::vector<std::vector<std::byte>>& skeletons,
                           std::vector<std::uint8_t>& ram){
    // Query-only complete5D1C70 comparisons use a declared packed-header
    // identity seam. Invalid counts never enter the original clearing loop.
    resources={0,skeleton_resource,0x900000};std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+bank_at,0x1f44,0);
    put(ram.data(),actor+0x514,bank_at);put(ram.data(),bank_at+1,std::uint8_t(1));
    for(unsigned category:{0u,1u,2u,255u})for(unsigned kind=0;kind<256;++kind){
        put(ram.data(),actor+2,std::uint8_t(category));put(ram.data(),actor+0x54d,std::uint8_t(kind));
        for(unsigned count:{0u,22u,36u,73u,74u,65535u}){
            put(ram.data(),bank_at+4,std::uint16_t(2));put(ram.data(),resources[2]+2,std::uint16_t(count));
            const auto original=call(ram.data(),0x5d1c70,actor,0);
            check(a::primary_motion_compatible(std::uint8_t(category),std::uint8_t(kind),count)==bool(GPR_U32(&original,2)),"complete primary compatibility count/category decision");++routing_queries;
        }
        put(ram.data(),bank_at+4,std::uint16_t(0));const auto missing=call(ram.data(),0x5d1c70,actor,0);
        check(a::primary_motion_compatible(std::uint8_t(category),std::uint8_t(kind),{})&&GPR_U32(&missing,2)==1,"absent token query preserves source true without granting configuration");++routing_queries;
    }
    struct Input {std::vector<std::byte> bytes;std::size_t count;bool controlled;};std::vector<Input> inputs;
    for(unsigned asset=2;asset<banks.size();++asset){
        a::MotionBank resource;resource.load_strided(banks[asset],200,0,"owned primary scene motion");
        for(unsigned key=0;key<100;++key){
            const auto block=resource.find(key,0);if(!block)continue;
            try{
                const auto count=block->clip()->tracks().size();if(count!=36&&count!=73)continue;
                inputs.push_back({std::vector<std::byte>(block->bytes().begin(),block->bytes().end()),count,false});
                if(count==36){
                    auto prefix=inputs.back().bytes;std::size_t end=20;
                    for(unsigned i=0;i<22;++i)end+=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(prefix.data()),unsigned(end+8));
                    prefix.resize(end);put(reinterpret_cast<std::uint8_t*>(prefix.data()),4,22u);put(reinterpret_cast<std::uint8_t*>(prefix.data()),8,std::uint32_t(end));
                    inputs.push_back({std::move(prefix),22,true});
                }
                break;
            }catch(const std::invalid_argument&){}
        }
    }
    check(inputs.size()>=3,"owned36/73-node inputs and explicitly controlled22-track prefix");
    for(const auto& input:inputs)for(const auto& raw_skeleton:skeletons){
        const auto skeleton=a::Skeleton::import_raw(raw_skeleton);const auto size=skeleton->nodes().size();
        const unsigned kind=size==73||size==80?1u:0u;
        if((size!=36&&size!=43&&size!=73&&size!=80)||!a::primary_motion_compatible(0,std::uint8_t(kind),input.count))continue;
        std::vector<std::byte> container(20+input.bytes.size());auto* data=reinterpret_cast<std::uint8_t*>(container.data());
        put(data,4,1u);put(data,8,1u);put(data,12,16u);put(data,16,20u);std::memcpy(data+20,input.bytes.data(),input.bytes.size());
        a::MotionBank resource;resource.load_strided(container,200,0,input.controlled?"controlled22-prefix":"owned36/73 clip");
        for(unsigned variant=0;variant<16;++variant){
            location="primary routing nodes="+std::to_string(size)+" clip="+std::to_string(input.count)+" variant="+std::to_string(variant);
            std::fill_n(ram.data()+nodes,size*400,0);std::fill_n(ram.data()+second,size*400,0);
            std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+work,0x1468,0);std::fill_n(ram.data()+bank_at,0x1f44,0);
            std::memcpy(ram.data()+0x400000,raw_skeleton.data(),raw_skeleton.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
            call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
            put(ram.data(),actor+0x34,work);put(ram.data(),actor+0x514,bank_at);put(ram.data(),actor+0x54d,std::uint8_t(kind));
            put(ram.data(),work,work+0x820);put(ram.data(),work+4,work+0xa20);put(ram.data(),work+0x816,std::uint16_t(size));
            for(unsigned i=0;i<size;++i){put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);}
            resources={0,skeleton_resource,0x900000};std::memcpy(ram.data()+0x500000,input.bytes.data(),input.bytes.size());call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);
            check(get<std::int16_t>(ram.data(),resources[2]+2)==int(input.count),"packed original clip header count corresponds to native authored tracks");
            put(ram.data(),bank_at+1,std::uint8_t(1));put(ram.data(),bank_at+4,std::uint16_t(2));
            auto model=std::make_shared<a::Instance>(skeleton);a::Playback owner(model);a::Vector delta{};a::RootMotionRef root_ref{delta.x,delta.y,delta.z};
            const auto authored=std::vector<std::uint16_t>(model->track_ids().begin(),model->track_ids().end());
            bool refused{};try{a::clear_primary_motion_tracks(*model,std::uint8_t(kind),a::primary_restore_tracks(std::uint8_t(kind)).size()+1);}catch(const std::out_of_range&){refused=true;}
            check(refused&&std::equal(authored.begin(),authored.end(),model->track_ids().begin()),"oversized original diagnostic profile refuses before native mutation");++routing_refusals;
            refused=false;try{a::restore_primary_motion_tracks(*model,2);}catch(const std::out_of_range&){refused=true;}
            check(refused&&std::equal(authored.begin(),authored.end(),model->track_ids().begin()),"adjacent kind2 function words are unavailable as a restore layout");++routing_refusals;
            const a::MotionClock clock{std::uint8_t(variant&1),0,1};put(ram.data(),0x3243cc,clock.mode);put(ram.data(),actor+0xba8,1.f);
            const auto clear=[&](){a::clear_primary_motion_tracks(*model,std::uint8_t(kind),input.count);call(ram.data(),0x5d1da0,actor,0);};
            const auto restore=[&](){a::restore_primary_motion_tracks(*model,std::uint8_t(kind));call(ram.data(),0x5d1ea0,actor);};
            clear();records(owner,ram,delta);
            const auto copy=std::make_shared<a::Instance>(*model);check(copy->track_ids()[input.count-1]==0&&owner.secondary_model()->track_ids()[input.count-1]==skeleton->nodes()[input.count-1].track,"temporary primary routing keeps secondary bank authored");
            const float blend=std::array{0.f,-6.f,10.f,.5f}[variant/4];
            const auto configured=owner.configure(resource,0,0,0,blend,clock,root_ref);const auto original=call(ram.data(),0x58b9a0,actor,bank_at,0,0,0,blend);
            check(configured==std::int32_t(GPR_U32(&original,2)),"primary relabeled configuration result");restore();records(owner,ram,delta);
            check(copy->track_ids()[input.count-1]==0&&model->track_ids()[input.count-1]==a::primary_restore_tracks(std::uint8_t(kind))[input.count-1],"independent copy retains its own routing across restoration");
            owner.activate(5);put(ram.data(),actor+0x524,std::uint8_t(5));call(ram.data(),0x58c7b0,actor);
            for(unsigned tick=0;tick<8;++tick){
                clear();const float step=tick==0?-1.f:1.f;
                const auto result=owner.advance_primary(0,step,clock.mode,root_ref);const auto reference=call(ram.data(),0x58c130,actor,0,0,0,step);
                check(result==std::int8_t(GPR_U32(&reference,2)),"primary relabeled advancement result");restore();records(owner,ram,delta);++routing_continuations;
            }
            if(size==43||size==80){const auto prefix=a::primary_restore_tracks(std::uint8_t(kind)).size();for(unsigned i=unsigned(prefix);i<size;++i)check(model->track_ids()[i]==skeleton->nodes()[i].track,"Yoko accessory routing tail remains authored");++routing_tail_cases;}
            if(input.controlled)++routing_controlled_prefixes;else ++routing_owned_cases;
        }
    }
    check(routing_owned_cases&&routing_controlled_prefixes&&routing_tail_cases,"owned primary and controlled22 routing with extra-node coverage");
}
