std::uint64_t scene_candidate_cases{},scene_actor_cases{},scene_candidate_refusals{};
namespace scene=reo::native::gameplay_scene;
scene::Record scene_record(std::uint8_t kind,std::uint8_t priority,reo::native::gameplay_collision::Quad bounds={{{-100,-100},{100,-100},{100,100},{-100,100}}}){
    scene::Record record;record.enabled=1;record.counter=priority;
    record.body=reo::native::gameplay_scenario::ControlOther{kind};record.collision.emplace();
    record.collision->bounds=bounds;record.collision->lower=-20;record.collision->upper=40;return record;
}
n::SceneCandidates compare_scene_candidates(const scene::Records& records,n::Position actor,n::Position query,float radius=50,bool wrapper=false,std::uint8_t motion=0,std::uint16_t yaw=0,float center_z=0){
    const auto result=wrapper?n::collect_actor_scene_candidates(records,actor,motion,yaw,center_z):n::collect_scene_candidates(records,actor,query,radius);
    if(result.status!=n::QueryStatus::completed){++scene_candidate_refusals;return result;}
#ifdef REO_NAVIGATION_ORIGINAL
    constexpr unsigned first=0x1a00000,actor_at=0xf00000,query_at=0x1b00000,out=0x1d00000,stack=0x1f00000;
    std::array<scene::RecordId,128> identities;unsigned count=0;
    for(auto node=records.first();node;node=node->next){
        const auto at=first+256*count;const auto& record=node->value;identities[count++]=node->id;
        put(memory,at+0x28,node->next?at+256:0);memory[at+0x3c]=record.enabled;memory[at+0x32]=record.counter;
        memory[at+0x30]=scene::kind(record.body);
        check(record.collision.has_value());const auto& shape=*record.collision;memory[at+0x3d]=shape.busy;
        for(unsigned i=0;i<4;++i){put(memory,at+8*i,shape.bounds[i].x);put(memory,at+8*i+4,shape.bounds[i].z);}
        put(memory,at+0x20,shape.lower);put(memory,at+0x24,shape.upper);
    }
    put(memory,0x3b5160,count?first:0);put(memory,actor_at+0x38,actor.x);put(memory,actor_at+0x3c,actor.y);put(memory,actor_at+0x40,actor.z);
    put(memory,actor_at+0x1b4,center_z);put(memory,actor_at+0x1b8,999.f); // deliberately distinct radius
    memory[actor_at+0x54f]=motion;put(memory,actor_at+0x92,yaw);
    put(memory,query_at,query.x);put(memory,query_at+4,query.y);put(memory,query_at+8,query.z);
    R5900Context context;PS2Runtime runtime;context.pc=wrapper?0x819bc0:0x819da0;
    SET_GPR_U32(&context,4,actor_at);SET_GPR_U32(&context,5,wrapper?out:query_at);SET_GPR_U32(&context,6,out);
    SET_GPR_U32(&context,29,stack);SET_GPR_U32(&context,31,0x100);context.f[12]=radius;
    original_transform_port(memory.data(),&context,&runtime);
    check(context.pc==0x100&&GPR_U32(&context,29)==stack&&GPR_U32(&context,2)==result.count&&result.visited==records.size());
    for(unsigned i=0;i<result.count;++i){const auto pointer=word(memory,out+4*i);check(pointer>=first&&pointer<first+256*count&&(pointer-first)%256==0&&result.records[i]==identities[(pointer-first)/256]);}
    if(wrapper){check(std::memcmp(&result.sampled_position,memory.data()+stack-16,12)==0);++scene_actor_cases;}else ++scene_candidate_cases;
#endif
    return result;
}
void scene_candidate_contracts(){
    scene::Records records;
    check(compare_scene_candidates(records,{},{},50).count==0);
    const auto oldest=records.create(scene_record(0,0)),middle=records.create(scene_record(0,2)),newest=records.create(scene_record(0,1));
    check(oldest&&middle&&newest);
    const auto order=compare_scene_candidates(records,{},{},0);check(order.count==3&&order.records[0]==*newest&&order.records[1]==*middle&&order.records[2]==*oldest);
    // Original excludes the final record even when its priority is the lowest.
    // Geometry, active/busy gates, all kind bytes and asymmetric height rules.
    records.clear();const auto only=records.create(scene_record(0,3));check(bool(only));
    for(unsigned kind=0;kind<256;++kind)for(auto query:std::array<n::Position,7>{{{0,-221,0},{0,-220,0},{0,-20,0},{0,40,0},{0,41,0},{125,0,0},{151,0,0}}})for(unsigned flags=0;flags<4;++flags){
        auto node=records.acquire(*only);node->value.body=reo::native::gameplay_scenario::ControlOther{std::uint8_t(kind)};
        node->value.enabled=std::uint8_t(flags&1);node->value.collision->busy=(flags&2)!=0;records.touch();
        check(compare_scene_candidates(records,{0,0,0},query,50).status==n::QueryStatus::completed);
    }
    // Complete turn domain through original polynomial/reduction, with actual
    // query XYZ checked independently of whether the geometry matches.
    auto node=records.acquire(*only);node->value=scene_record(0x80,3);records.touch();
    for(unsigned yaw=0;yaw<65536;++yaw)for(float center:{-12.5f,37.f}){
        check(compare_scene_candidates(records,{11.25f,4,-9.5f},{},50,true,0,std::uint16_t(yaw),center).status==n::QueryStatus::completed);
    }
    for(unsigned motion=0;motion<256;++motion){
        check(compare_scene_candidates(records,{1,2,3},{},50,true,std::uint8_t(motion),24567,17).status==n::QueryStatus::completed);
    }
    // Canonical mutation/reuse and full pool order. Reused identity cannot be
    // confused with the retired occupant after collection.
    const auto stale=*only;check(records.retire(stale)&&!records.acquire(stale));
    for(unsigned i=0;i<128;++i)check(bool(records.create(scene_record(std::uint8_t(i%3==0?0x81:0),std::uint8_t((i*43)%256)))));
    check(compare_scene_candidates(records,{},{},50).count==128);
    const auto retained=n::collect_scene_candidates(records,{},{},50).records[0];check(records.retire(retained)&&!records.acquire(retained));
    check(bool(records.create(scene_record(0x85,0))));check(compare_scene_candidates(records,{125,0,0},{},0).count==127);
    records.clear();auto missing=scene_record(0,0);missing.collision.reset();check(bool(records.create(std::move(missing))));
    check(compare_scene_candidates(records,{},{},50).status==n::QueryStatus::unavailable);
    records.clear();const auto nan=std::numeric_limits<float>::quiet_NaN();
    check(compare_scene_candidates(records,{},{nan,0,0},50).status==n::QueryStatus::unavailable);
    check(compare_scene_candidates(records,{},{},nan).status==n::QueryStatus::unavailable);
    check(compare_scene_candidates(records,{},{},50,true,0,0,nan).status==n::QueryStatus::unavailable);
    check(compare_scene_candidates(records,{},{},50,true,0x1a,0,nan).status==n::QueryStatus::completed);
    check(compare_scene_candidates(records,{},{2147483648.f,0,0},0).status==n::QueryStatus::unavailable);
}
