#include "game/native/animation/scalar_playback.hpp"
void scalar_playback_tests(const std::vector<std::vector<std::byte>>& banks,const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    std::vector<std::vector<std::byte>> clips;
    for(unsigned asset=2;asset<banks.size();++asset){a::MotionBank resource;resource.load_strided(banks[asset],200,0,"scalar original scene input");unsigned used{};
        for(unsigned key=0;key<100&&used<2;++key){const auto block=resource.find(key,0);if(!block)continue;
            try{const auto clip=block->clip();if(std::none_of(skeletons.begin(),skeletons.end(),[&](const auto& raw){return a::Skeleton::import_raw(raw)->nodes().size()==clip->tracks().size();}))continue;}
            catch(const std::invalid_argument&){continue;}
            clips.emplace_back(block->bytes().begin(),block->bytes().end());++used;
        }
        check(used>0,"scalar playback has actual owned scene clip input");
    }
    // Controlled odd endpoints and negative loop starts retain original curves.
    const auto count=unsigned(a::Skeleton::import_raw(skeletons.front())->nodes().size());
    for(const auto loop:{0u,1u})for(const auto restart:{2.5f,-2.5f}){
        std::vector<std::byte> raw(20+40*count);auto* data=reinterpret_cast<std::uint8_t*>(raw.data());
        put(data,0,1u);put(data,4,count);put(data,8,unsigned(raw.size()));put(data,12,loop);put(data,16,restart);
        for(unsigned i=0;i<count;++i){const auto at=20+40*i;put(data,at,0x80000000u);put(data,at+4,1u);put(data,at+8,40u);put(data,at+12,0x80210040u);put(data,at+16,2u);put(data,at+20,28u);put(data,at+24,0.f);put(data,at+28,0.f);put(data,at+32,float(i+1));put(data,at+36,5.f);}
        clips.push_back(std::move(raw));
    }
    constexpr unsigned timing=0x280000;
    const auto export_record=[&](const a::FrameRecord& record){put(ram.data(),timing,record.frame);put(ram.data(),timing+4,record.end);put(ram.data(),timing+8,record.restart);put(ram.data(),timing+12,record.loop);put(ram.data(),timing+13,record.flags);};
    const auto compare_record=[&](const a::FrameRecord& record){check(bits(record.frame)==get<std::uint32_t>(ram.data(),timing)&&bits(record.end)==get<std::uint32_t>(ram.data(),timing+4)&&bits(record.restart)==get<std::uint32_t>(ram.data(),timing+8)&&record.loop==get<std::int8_t>(ram.data(),timing+12)&&record.flags==ram[timing+13],"complete standalone scalar timing record");};
    for(unsigned input=0;input<clips.size();++input){const auto clip=a::Clip::import_raw(clips[input]);std::shared_ptr<const a::Skeleton> skeleton;std::vector<std::byte> raw;
        for(const auto& candidate:skeletons){const auto decoded=a::Skeleton::import_raw(candidate);if(decoded->nodes().size()==clip->tracks().size()){skeleton=decoded;raw=candidate;break;}}
        check(bool(skeleton),"bounded matching scalar model");
        for(unsigned variant=0;variant<256;++variant){
            location="scalar input="+std::to_string(input)+" variant="+std::to_string(variant);
            std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);std::memcpy(ram.data()+0x400000,raw.data(),raw.size());
            call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);
            a::Instance model(skeleton);model.relabel_prefix(model.nodes().size(),0);for(unsigned i=0;i<model.nodes().size();++i)put(ram.data(),nodes+400*i+0xc6,std::uint16_t(0));
            resources={0,skeleton_resource,0x900000};std::memcpy(ram.data()+0x500000,clips[input].data(),clips[input].size());call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);
            a::FrameRecord record{3,7,2,-1,std::uint8_t(variant)};export_record(record);
            const auto start=std::array<float,4>{0.f,.5f,clip->last_frame(),clip->last_frame()+.25f}[variant%4];
            a::bind_scalar_frame(model,record,clip,start);call(ram.data(),0x58c810,nodes,timing,2,0,start);compare_record(record);compare_nodes(model,ram,false);
            check(record.flags==variant&&record.end==clip->last_frame()&&record.loop==std::int8_t(clip->looping()),"scalar binding preserves flags odd endpoint and raw loop policy");
            if(int(record.end)&1){++scalar_odd_endpoints;}
            ++scalar_bindings;
            const auto clock=std::uint8_t(variant>>2);ram[0x3243cc]=clock;
            for(const auto step:{-.5f,0.f,.5f,clip->last_frame()+1.f}){
                model.rebuild(t::identity());const auto retained=model.retain();const bool early=record.loop==0&&!(record.frame<record.end);
                const auto result=a::advance_scalar_frame(model,record,step,clock);const auto original=call(ram.data(),0x58c8a0,nodes,timing,0,0,step);
                check(result==std::bit_cast<std::int8_t>(std::uint8_t(GPR_U32(&original,2))),"complete scalar tick status and clock factor");compare_record(record);compare_nodes(model,ram,false);
                if(early){check(model.retain()==retained,"already complete scalar record skips sampling");++scalar_early_returns;}else check(!model.retain(),"scalar tick samples track zero even when advance returns completion");++scalar_ticks;
            }
        }
    }
    a::Instance model(a::Skeleton::import_raw(skeletons.front()));a::FrameRecord record{0,1,0,0,255};
    bool refused{};try{a::bind_scalar_frame(model,record,{},0);}catch(const std::invalid_argument&){refused=true;}
    check(refused&&record.flags==255,"unadmitted absent clip is explicit failure");++scalar_refusals;
    for(const auto nan_at:{0u,1u}){record={1,1,0,0,255};if(nan_at)record.end=std::bit_cast<float>(0x7fc00001u);else record.frame=std::bit_cast<float>(0x7fc00001u);export_record(record);
        const auto result=a::advance_scalar_frame(model,record,.5f,1);const auto original=call(ram.data(),0x58c8a0,nodes,timing,0,0,.5f);check(result==1&&GPR_U32(&original,2)==1,"unordered early-completion comparison performs no model or numeric work");compare_record(record);++scalar_early_returns;
    }
}
