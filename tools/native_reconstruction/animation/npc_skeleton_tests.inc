std::uint64_t npc_skeleton_cases{},npc_skeleton_nodes{},npc_stale_lengths{},npc_skeleton_refusals{};
void npc_skeleton_tests(const char* path,std::vector<std::uint8_t>& ram){
    const auto assets=load(path);
    for(unsigned index=0;index<assets.size();++index){
        location="owned NPC skeleton="+std::to_string(index);const auto& raw=assets[index];resources={0,skeleton_resource};
        const auto skeleton=a::Skeleton::import_raw(raw,0,a::SkeletonExtent::bounded_records);
        std::fill_n(ram.data()+nodes,skeleton->nodes().size()*400,0);
        std::memcpy(ram.data()+0x400000,raw.data(),raw.size());
        call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);call(ram.data(),0x193380,nodes,1);
        put(ram.data(),0x270000,t::identity());call(ram.data(),0x193240,nodes,0x270000);
        a::Instance model(skeleton);model.rebuild(t::identity());compare_nodes(model,ram,true);
        std::uint32_t declared;std::memcpy(&declared,raw.data()+8,4);
        if(declared!=raw.size()){
            ++npc_stale_lengths;bool refused=false;try{(void)a::Skeleton::import_raw(raw);}catch(const std::invalid_argument&){refused=true;}check(refused,"strict generic extent profile remains separate");
        }
        const auto refused=[&](std::span<const std::byte> malformed){bool bad=false;try{(void)a::Skeleton::import_raw(malformed,0,a::SkeletonExtent::bounded_records);}catch(const std::invalid_argument&){bad=true;}check(bad,"bounded NPC record walk refuses missing bytes");++npc_skeleton_refusals;};
        refused(std::span(raw).first(11));refused(std::span(raw).first(raw.size()-1));
        npc_skeleton_nodes+=skeleton->nodes().size();++npc_skeleton_cases;
    }
    check(npc_stale_lengths==7,"all seven actual stale-header NPC skeletons compared");
}
