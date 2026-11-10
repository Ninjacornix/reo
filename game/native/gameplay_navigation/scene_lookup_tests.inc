std::uint64_t scene_lookup_cases{},scene_global_lookup_cases{},scene_lookup_refusals{};
n::SceneLookupResult compare_scene_lookup(const n::Bank& bank,n::ActorFacts facts,std::int32_t condition,const scene::Records& records,const n::SceneCandidates* candidates){
    const auto result=candidates?n::find_scene_candidate(bank,facts,7,condition,records,*candidates):n::find_global_scene_candidate(bank,facts,7,condition,records);
    if(result.status!=n::QueryStatus::completed){++scene_lookup_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    source_graph(*bank.room(7),7);
    constexpr unsigned first=0x1a00000,actor=0xf00000,list=0x1d00000;
    std::array<scene::RecordId,128> ids;unsigned count=0;
    for(auto node=records.first();node;node=node->next){
        const auto at=first+256*count;ids[count++]=node->id;put(memory,at+0x28,node->next?at+256:0);
        memory[at+0x3f]=node->value.condition_ordinal;memory[at+0x3c]=node->value.enabled;memory[at+0x3d]=255;
    }
    put(memory,0x3b5160,count?first:0);put(memory,actor+0x1e2,std::uint16_t(7));memory[actor+0xb98]=facts.character;memory[actor+3]=facts.slot;memory[actor+0xff0]=facts.ai_control;
    if(candidates)for(unsigned i=0;i<candidates->count;++i){
        const auto found=std::find(ids.begin(),ids.begin()+count,candidates->records[i]);check(found!=ids.begin()+count);put(memory,list+4*i,first+256*unsigned(found-ids.begin()));
    }
    const auto pointer=candidates?call(0x819ff0,{actor,list,std::uint32_t(candidates->count),std::uint32_t(condition)}):call(0x81a080,{actor,std::uint32_t(condition),0,0});
    if(pointer){check(pointer>=first&&pointer<first+256*count&&(pointer-first)%256==0&&result.record==ids[(pointer-first)/256]);}
    else check(!result.record);
    if(candidates)++scene_lookup_cases;else ++scene_global_lookup_cases;
#endif
    return result;
}
void scene_lookup_contracts(){
    auto bytes=synthetic();constexpr unsigned added=16*126;
    bytes.insert(bytes.begin()+synthetic_directory,added,0);put(bytes,synthetic_room+4,std::uint32_t(synthetic_directory+added-synthetic_room));put(bytes,synthetic_tail+4,std::uint32_t(128));
    const auto conditions=synthetic_tail+8;bytes[conditions+1]=1;bytes[conditions+6]=2;bytes[conditions+7]=7;bytes[conditions+16*127]=1;
    reo::native::gameplay_session::RoomVariants variants;check(variants.store(7,0));n::Bank bank(variants);
    scene::Records records;const auto zero=records.create(scene_record(0,1)),a=records.create(scene_record(0,2)),b=records.create(scene_record(0,3));check(zero&&a&&b);
    n::SceneCandidates candidates;candidates.status=n::QueryStatus::completed;candidates.records[0]=*zero;candidates.records[1]=*a;candidates.records[2]=*b;
    for(unsigned active=0;active<2;++active){
        bytes[conditions]=std::uint8_t(active);check(bank.bind(std::make_shared<const n::Asset>(imported(bytes))));
        for(unsigned ordinal=0;ordinal<256;++ordinal){
            records.acquire(*a)->value.condition_ordinal=std::uint8_t(ordinal);records.acquire(*a)->value.enabled=0;
            records.acquire(*b)->value.condition_ordinal=std::uint8_t(ordinal^0x80);records.acquire(*b)->value.collision->busy=true;records.touch();
            for(auto facts:std::array<n::ActorFacts,3>{{{7,2,0},{4,1,1},{7,5,1}}})for(std::int32_t condition:{0,1,127}){
                check(compare_scene_lookup(bank,facts,condition,records,nullptr).status==n::QueryStatus::completed);
                for(std::size_t count:{0u,1u,3u}){candidates.count=count;check(compare_scene_lookup(bank,facts,condition,records,&candidates).status==n::QueryStatus::completed);}
            }
        }
    }
    // Refusal is not a no-match result. Check original-first condition ordering,
    // unavailable collections, malformed counts and stale/foreign identities.
    check(n::find_global_scene_candidate(bank,{},7,-1,records).status==n::QueryStatus::unavailable);
    check(compare_scene_lookup(bank,{},128,records,nullptr).status==n::QueryStatus::unavailable);
    candidates.count=129;check(compare_scene_lookup(bank,{},0,records,&candidates).status==n::QueryStatus::unavailable);
    candidates.count=1;candidates.status=n::QueryStatus::unavailable;check(compare_scene_lookup(bank,{},0,records,&candidates).status==n::QueryStatus::unavailable);
    candidates.status=n::QueryStatus::completed;check(records.retire(*zero));check(compare_scene_lookup(bank,{},0,records,&candidates).status==n::QueryStatus::unavailable);
    scene::Records foreign;candidates.records[0]=*foreign.create(scene_record(0,0));check(compare_scene_lookup(bank,{},0,records,&candidates).status==n::QueryStatus::unavailable);
    candidates.count=0;check(compare_scene_lookup(bank,{},0,records,&candidates).status==n::QueryStatus::completed);
}
