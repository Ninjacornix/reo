std::uint64_t topology_clear_cycles{};
std::vector<a::NodeLinkPatch> topology_recipe(const std::vector<std::uint8_t>& ram,unsigned address){
    std::vector<a::NodeLinkPatch> result;
    for(unsigned i=0;ram[address+3*i]!=255;++i){
        check(i<32&&ram[address+3*i+1]<3,"bounded owned three-byte link recipe");
        result.push_back({ram[address+3*i],static_cast<a::NodeLink>(ram[address+3*i+1]),
                          ram[address+3*i+2]==255?std::optional<std::size_t>{}:ram[address+3*i+2]});
    }
    return result;
}
void compare_topology(const a::Instance& model,const std::vector<std::uint8_t>& ram){
    for(unsigned i=0;i<model.links().size();++i){
        const auto& row=model.links()[i];
        for(auto [link,offset]:{std::pair{row.parent,0xc8u},std::pair{row.child,0xd0u},std::pair{row.sibling,0xccu}})
            check((link?nodes+400*unsigned(*link):0u)==get<std::uint32_t>(ram.data(),nodes+400*i+offset),"actual parent/child/sibling link targets");
    }
    std::vector<std::size_t> order;
    const auto walk=[&](auto&& self,unsigned node)->void{
        order.push_back((node-nodes)/400);
        for(unsigned field:{0xd0u,0xccu})if(const auto link=get<std::uint32_t>(ram.data(),node+field))self(self,link);
    };walk(walk,nodes);
    check(std::equal(order.begin(),order.end(),model.traversal().begin(),model.traversal().end()),"live source DFS order including detached branches");
}
std::vector<std::byte> topology_clip(const std::vector<std::vector<std::byte>>& banks,std::size_t count){
    for(unsigned asset=2;asset<banks.size();++asset){
        a::MotionBank bank;bank.load_strided(banks[asset],200,0,"owned topology curve source");
        for(unsigned key=0;key<100;++key){
            const auto block=bank.find(key,0);if(!block)continue;
            const auto clip=block->clip();if(clip->tracks().size()<count)continue;
            auto raw=std::vector<std::byte>(block->bytes().begin(),block->bytes().end());
            std::size_t end=20;for(std::size_t i=0;i<count;++i)end+=get<std::uint32_t>(reinterpret_cast<const std::uint8_t*>(raw.data()),unsigned(end+8));
            raw.resize(end);put(reinterpret_cast<std::uint8_t*>(raw.data()),4,std::uint32_t(count));put(reinterpret_cast<std::uint8_t*>(raw.data()),8,std::uint32_t(end));return raw;
        }
    }
    throw std::runtime_error("Owned topology curve source cardinality unavailable");
}
void node_topology_tests(const std::vector<std::vector<std::byte>>& banks,
                         const std::vector<std::vector<std::byte>>& skeletons,std::vector<std::uint8_t>& ram){
    for(const auto& raw:skeletons){
        const auto skeleton=a::Skeleton::import_raw(raw);const auto count=skeleton->nodes().size();if(count!=43&&count!=80)continue;
        location="live topology nodes="+std::to_string(count);
        std::fill_n(ram.data()+nodes,count*400,0);std::fill_n(ram.data()+second,count*400,0);std::fill_n(ram.data()+work,0x1468,0);
        std::memcpy(ram.data()+0x400000,raw.data(),raw.size());call(ram.data(),0x1a2e00,0x10000,skeleton_resource,0x400000);
        call(ram.data(),0x193380,nodes,1);call(ram.data(),0x193380,second,1);
        for(unsigned i=0;i<count;++i){put(ram.data(),work+0x820+4*i,nodes+400*i);put(ram.data(),work+0xa20+4*i,second+400*i);put(ram.data(),nodes+400*i+0xc6,std::uint16_t(0));put(ram.data(),second+400*i+0xc6,std::uint16_t(0));}
        a::Instance model(skeleton),other(skeleton),untouched(skeleton);model.relabel_prefix(count,0);other.relabel_prefix(count,0);
        const auto authored=std::vector<a::NodeLinks>(model.links().begin(),model.links().end());
        auto parent=t::identity();parent[3]={10,20,30,1};put(ram.data(),0x280000,parent);
        model.rebuild(parent);call(ram.data(),0x193240,nodes,0x280000);compare_nodes(model,ram,true);
        const auto retained=model.retain();check(bool(retained),"retained pre-topology immutable joint lease");
        resources={0,skeleton_resource,0x900000,0xa00000};
        for(unsigned phase=0;phase<8;++phase){
            location="live topology nodes="+std::to_string(count)+" phase="+std::to_string(phase);
            const auto recipe=(count==43?0x70f628u:0x70f630u)+(phase%2?0x38u:0u);
            const auto patches=topology_recipe(ram,recipe);model.patch_links(patches);call(ram.data(),0x61b1a0,work+0x820,recipe);
            compare_topology(model,ram);check(!model.retain()&&retained->joints.size()==count,"topology change invalidates current publication and preserves retained snapshot");
            check(untouched.traversal().size()==count&&std::equal(authored.begin(),authored.end(),untouched.links().begin()),"shared Skeleton and independent sibling topology are unchanged");++topology_patches;
            // A controlled isomorphic permutation makes paired-node indices
            // differ. Real Yoko detach/reconnect recipes still drive the
            // destination; this extra source-bank layout is not a stock asset.
            const auto permute=[](std::size_t index){return index==1?std::size_t(2):index==2?std::size_t(1):index;};
            std::vector<a::NodeLinkPatch> other_patches;
            for(unsigned i=0;i<count;++i){
                unsigned kind{};for(auto target:{model.links()[i].parent,model.links()[i].child,model.links()[i].sibling}){
                    const auto mapped=target?std::optional<std::size_t>(permute(*target)):std::optional<std::size_t>{};
                    const auto at=0x290100+3*unsigned(other_patches.size());ram[at]=std::uint8_t(permute(i));ram[at+1]=std::uint8_t(kind);ram[at+2]=mapped?std::uint8_t(*mapped):255;
                    other_patches.push_back({permute(i),static_cast<a::NodeLink>(kind++),mapped});
                }
            }
            ram[0x290100+3*other_patches.size()]=255;other.patch_links(other_patches);call(ram.data(),0x61b1a0,work+0xa20,0x290100);
            const auto prefix=topology_clip(banks,model.traversal().size());const auto clip=a::Clip::import_raw(prefix);
            std::memcpy(ram.data()+0x500000,prefix.data(),prefix.size());call(ram.data(),0x1a1fd0,0x18000,resources[2],0x500000);
            call(ram.data(),0x1a1fd0,0x18000,resources[3],0x500000);
            a::PoseBlend::bind_all(other,clip);call(ram.data(),0x192a00,second,3);other.sample_all(2.f);call(ram.data(),0x193220,second,0,0,0,2.f);
            a::PoseBlend::bind_all(model,clip);call(ram.data(),0x192a00,nodes,2);
            for(float frame:{0.f,1.25f}){
                location="live topology nodes="+std::to_string(count)+" phase="+std::to_string(phase)+" frame="+std::to_string(frame)+" sample";
                model.sample_all(frame);call(ram.data(),0x193220,nodes,0,0,0,frame);compare_nodes(model,ram,false);++topology_samples;
                location+=" blend";a::PoseBlend::blend(model,other,0,.25f,.75f);call(ram.data(),0x192690,nodes,second,0,0,.25f,.75f);compare_nodes(model,ram,false);++topology_blends;
                model.rebuild(parent);call(ram.data(),0x193240,nodes,0x280000);compare_nodes(model,ram,true);
            }
            std::optional<std::size_t> skipped;
            for(const auto& row:model.links())if(row.child&&row.sibling&&model.links()[*row.sibling].child){skipped=row.sibling;break;}
            check(bool(skipped),"real hierarchy supplies an ancestor sibling with descendants");
            std::vector<std::uint16_t> labels(count,0),other_labels(count,0);labels[*skipped]=1;other_labels[permute(*skipped)]=1;
            model.relabel_prefix(labels);other.relabel_prefix(other_labels);
            put(ram.data(),nodes+400*unsigned(*skipped)+0xc6,std::uint16_t(1));put(ram.data(),second+400*unsigned(permute(*skipped))+0xc6,std::uint16_t(1));
            location+=" ancestor-sibling skip";a::PoseBlend::blend(model,other,0,.25f,.75f);call(ram.data(),0x192690,nodes,second,0,0,.25f,.75f);compare_nodes(model,ram,false);++topology_mixed_blends;
            model.relabel_prefix(count,0);other.relabel_prefix(count,0);put(ram.data(),nodes+400*unsigned(*skipped)+0xc6,std::uint16_t(0));put(ram.data(),second+400*unsigned(permute(*skipped))+0xc6,std::uint16_t(0));
            auto independent=std::make_shared<a::Instance>(model);const auto previous_size=model.traversal().size();
            independent->patch_links(std::array{a::NodeLinkPatch{0,a::NodeLink::child,{}}});
            check(model.traversal().size()==previous_size&&independent->traversal().size()==1,"independent copied runtime topology");++topology_copies;
            const auto before_blend=model.retain();const auto local_before=model.nodes()[0].local;bool missing_pair{};
            try{a::PoseBlend::blend(model,*independent,0,.25f,.75f);}catch(const std::invalid_argument&){missing_pair=true;}
            check(missing_pair&&model.retain()==before_blend&&model.nodes()[0].local==local_before,"missing paired branch refuses before any blend publication");++topology_pair_refusals;
            if(phase%2==0){
                const unsigned detached=count==43?36:73;const auto old=model.links()[detached].parent;
                model.patch_links(std::array{a::NodeLinkPatch{detached,a::NodeLink::parent,2}});
                ram[0x290000]=std::uint8_t(detached);ram[0x290001]=0;ram[0x290002]=2;ram[0x290003]=255;call(ram.data(),0x61b1a0,work+0x820,0x290000);compare_topology(model,ram);++topology_parent_cases;
                model.patch_links(std::array{a::NodeLinkPatch{detached,a::NodeLink::parent,old}});
                ram[0x290002]=old?std::uint8_t(*old):255;call(ram.data(),0x61b1a0,work+0x820,0x290000);compare_topology(model,ram);++topology_parent_cases;
                // The clear visits the current tree only. Previously bound
                // detached nodes must keep their bindings when reconnected.
                model.clear(0);call(ram.data(),0x192b30,nodes,0);
                model.sample_all(1.75f);call(ram.data(),0x193220,nodes,0,0,0,1.75f);compare_nodes(model,ram,false);
                const auto publish=recipe+0x38u;model.patch_links(topology_recipe(ram,publish));call(ram.data(),0x61b1a0,work+0x820,publish);
                model.sample_all(1.75f);call(ram.data(),0x193220,nodes,0,0,0,1.75f);compare_nodes(model,ram,false);
                model.patch_links(patches);call(ram.data(),0x61b1a0,work+0x820,recipe);compare_topology(model,ram);
                ++topology_clear_cycles;
            }
        }
        model.rebuild(parent);const auto snapshot=model.retain();const auto before=std::vector<a::NodeLinks>(model.links().begin(),model.links().end());const auto order=std::vector<std::size_t>(model.traversal().begin(),model.traversal().end());
        for(const auto& invalid:std::vector<std::vector<a::NodeLinkPatch>>{
                {{count,a::NodeLink::child,0}},{{0,a::NodeLink::child,count}},{{0,static_cast<a::NodeLink>(99),0}},
                {{0,a::NodeLink::sibling,0}},{{0,a::NodeLink::child,1},{0,a::NodeLink::sibling,1}},{{0,a::NodeLink::parent,1}},
                {{0,a::NodeLink::child,{}},{count-1,a::NodeLink::child,count-1}}}){
            bool refused{};try{model.patch_links(invalid);}catch(const std::exception&){refused=true;}
            check(refused&&model.retain()==snapshot&&std::equal(before.begin(),before.end(),model.links().begin())&&std::equal(order.begin(),order.end(),model.traversal().begin()),"invalid topology refuses atomically, including unreachable cycles");++topology_refusals;
        }
    }
    check(topology_patches==16&&topology_samples==32&&topology_blends==32&&topology_clear_cycles==8,"both actual Yoko model topology and detached-binding clear cycles execute");
}
