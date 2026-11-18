void whole_playback_tests(const std::vector<std::vector<std::byte>>& banks,
                          const std::vector<std::vector<std::byte>>& skeletons,
                          std::vector<std::uint8_t>& ram){
    auto inputs=banks;
    // Independent odd-end/loop fixtures expose metadata behavior absent from
    // the first matching retail clips. Curves remain native raw asset data.
    const auto count=unsigned(a::Skeleton::import_raw(skeletons.front())->nodes().size());
    for(const float restart:{2.5f,-2.5f}){
        std::vector<std::byte> raw(40+40*count);
        auto* data=reinterpret_cast<std::uint8_t*>(raw.data());
        put(data,0,0u);put(data,4,1u);put(data,8,1u);put(data,12,16u);put(data,16,20u);
        put(data,20,1u);put(data,24,count);put(data,28,std::uint32_t(raw.size()-20));
        put(data,32,1u);put(data,36,restart);
        for(unsigned i=0;i<count;++i){
            const auto at=40+40*i;
            put(data,at,0x80000000u);put(data,at+4,1u);put(data,at+8,40u);
            put(data,at+12,0x80210040u);put(data,at+16,2u);put(data,at+20,28u);
            put(data,at+24,0.f);put(data,at+28,0.f);put(data,at+32,float(i+1));put(data,at+36,5.f);
        }
        inputs.push_back(std::move(raw));
    }
    for(unsigned asset=2;asset<inputs.size();++asset){
        a::MotionBank resource;resource.load_strided(inputs[asset],200,0,"whole-model playback fixture");
        unsigned used{};
        for(unsigned key=0;key<100&&used<2;++key){
            const auto block=resource.find(key,0);if(!block)continue;
            std::shared_ptr<const a::Clip> clip;
            try{clip=block->clip();}catch(const std::invalid_argument&){continue;}
            std::shared_ptr<const a::Skeleton> skeleton;std::vector<std::byte> raw;
            for(const auto& bytes:skeletons){
                auto candidate=a::Skeleton::import_raw(bytes);
                if(candidate->nodes().size()==clip->tracks().size()){skeleton=candidate;raw=bytes;break;}
            }
            if(!skeleton)continue;
            auto released=resource;released.clear_scene_families();
            for(unsigned variant=0;variant<128;++variant){
                const bool reserved=key<5&&variant>=64;
                const auto& configured=reserved?released:resource;
                location="whole playback asset="+std::to_string(asset)+" key="+std::to_string(key)+" variant="+std::to_string(variant);
                std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);
                std::fill_n(ram.data()+second,skeleton->nodes().size()*400,0);
                std::fill_n(ram.data()+actor,0x10e0,0);std::fill_n(ram.data()+work,0x1468,0);
                std::fill_n(ram.data()+bank_at,0x1f44,0);
                std::memcpy(ram.data()+0x400000,raw.data(),raw.size());
                call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
                call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
                put(ram.data(),actor+0x34,work);put(ram.data(),work,work+0x820);
                put(ram.data(),work+4,work+0xa20);put(ram.data(),work+0x816,std::uint16_t(skeleton->nodes().size()));
                for(unsigned i=0;i<skeleton->nodes().size();++i){
                    put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);
                }
                resources={0,skeleton_resource,0x900000};
                std::memcpy(ram.data()+0x500000,block->bytes().data(),block->bytes().size());
                call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);
                //58C970 reads this raw halfword table directly, without the
                // Actor bank header used by other configuration frontends.
                put(ram.data(),bank_at+2*(200*(key/100)+key%100),std::uint16_t(2));
                const auto model=std::make_shared<a::Instance>(skeleton);a::Playback owner(model);
                a::Vector root{3,4,5};a::RootMotionRef root_ref{root.x,root.y,root.z};
                put(ram.data(),actor+0x4e4,root);
                a::PoseBlend::root_reference(*model,{1,2,3});put(ram.data(),actor+0x508,a::Vector{1,2,3});
                for(unsigned bank=0;bank<2;++bank)for(unsigned track=0;track<5;++track){
                    auto& channel=owner.channel(bank?a::ModelBank::secondary:a::ModelBank::primary,track);
                    channel.selector=std::uint16_t(100+track);channel.timing.flags=std::uint8_t(variant*17+track);
                    channel.blend_position=.25f;channel.blend_increment=.125f;channel.blend_remaining=17;
                    channel.skip_flags=0x83;channel.mode=0x97;channel.auxiliary=0x89abcdef;
                    export_channel(ram.data(),bank,track,channel);
                }
                const a::MotionClock clock{std::uint8_t(variant&1),std::uint8_t((variant/2)%4),.5f+float((variant/8)%4)*.25f};
                put(ram.data(),0x3243cc,clock.mode);put(ram.data(),actor+2,clock.category);put(ram.data(),actor+0xba8,clock.rate);
                const float frame=std::array{0.f,.5f,3.5f,clip->last_frame()}[variant/32];
                const float duration=std::array{0.f,-6.f,10.f,.5f}[(variant/8)%4];
                check(owner.configure_whole(configured,std::int32_t(key),frame,duration,clock,root_ref)==a::MotionBound::prepared,"whole configuration binds real clip");
                call(ram.data(),0x58c970,actor,bank_at,key,0,frame,duration);
                records(owner,ram,root);++whole_configuration_cases;
                if(reserved){
                    ++whole_reserved_configurations;
                    if(asset<banks.size()){
                        ++whole_reserved_owned_configurations;
                        if(key)++whole_reserved_nonzero_rows;
                    }
                }
                owner.activate(5);put(ram.data(),actor+0x524,std::uint8_t(5));call(ram.data(),0x58c7b0,actor);
                for(unsigned tick=0;tick<12;++tick){
                    const float step=std::array{-1.f,0.f,1.f,5.f,clip->last_frame()+1.f,1.f}[tick%6];
                    const auto actual=owner.advance_whole(step,clock.mode,root_ref);
                    const auto original=call(ram.data(),0x58cc80,actor,0,0,0,step);
                    check(actual==std::int8_t(GPR_U32(&original,2)),"whole advancement boundary result");
                    records(owner,ram,root);++whole_tick_cases;
                    if(reserved)++whole_reserved_ticks;
                }
                // A zero original token preserves every channel, pose and
                // root output. Use an actual absent row in this owned bank.
                unsigned missing=999;
                while(missing&&configured.slots()[200*(missing/100)+missing%100])--missing;
                check(!configured.slots()[200*(missing/100)+missing%100],"owned whole bank includes an absent row");
                check(owner.configure_whole(configured,std::int32_t(missing),7,6,clock,root_ref)==a::MotionBound::unchanged,"missing whole token preserves state");
                call(ram.data(),0x58c970,actor,bank_at,missing,0,7,6);records(owner,ram,root);++whole_missing_cases;
                bool refused{};
                try{(void)owner.configure_whole(resource,-1,0,0,clock,root_ref);}catch(const std::domain_error&){refused=true;}
                check(refused,"negative whole source row explicitly unavailable");records(owner,ram,root);++whole_boundary_refusals;
            }
            ++used;
        }
        check(used!=0,"actual whole-model bank has matching skeleton clips");
    }
    check(whole_reserved_owned_configurations&&whole_reserved_ticks&&whole_reserved_nonzero_rows,
          "retained real clips continue after scene cleanup, including a nonzero reserved row");
}
