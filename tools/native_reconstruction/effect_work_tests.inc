unsigned general_created{},general_frames{},general_missing{},general_profiles{};
std::set<std::tuple<unsigned,unsigned,std::int16_t>> unknown_effect_profiles;
void compare_general_work(std::uint8_t* memory,const std::vector<std::vector<std::byte>>& corpus){
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        const auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        for(unsigned logical:{0x28u,0x29u,0x2au,0x2bu,0x2cu,0x2du,0x2eu,0x2fu,0x30u,0x31u,0x32u,0x37u,0x46u,0x49u,0x4bu,0x50u,0x79u})
        for(unsigned kind=0;kind<3;++kind)for(unsigned profile=0;profile<4;++profile){
            general_context="asset="+std::to_string(asset)+" effect="+std::to_string(logical)+" kind="+std::to_string(kind)+" profile="+std::to_string(profile);
            std::fill_n(memory,0x2000000,0);prepare(memory,corpus[asset],corpus[asset+1]);
            //195E50-initialized identity cache is an explicit source prerequisite.
            const auto identity=m::identity();std::memcpy(memory+0x294e00,identity.data(),64);
            reo::native::gameplay_session::Random random;random.restore({std::uint16_t(logical*19+profile),std::uint16_t(0x193b^kind),std::uint8_t(profile)});
            put(memory,0x3244b0,random.state().primary);put(memory,0x3244b8,random.state().secondary);put(memory,0x2b8de8,random.state().observed);
            e::PeriodicVisuals owner(bank,random);e::WorkRequest request;request.effect=std::uint16_t(logical);request.variant=profile&1?-1:0;request.update=static_cast<e::WorkUpdate>(kind);
            request.position=m::Vector{float(logical)-40.f,-7.25f,float(profile)*3.5f};request.flags=profile==3?0x9a993:profile==2?0x1a993:0x1a193;request.child_mask=profile==1?0x5:0;
            auto basis=m::identity();basis[0]={0.5f,0.125f,-0.25f,0};basis[1]={0.25f,1.5f,0.375f,0};basis[2]={-0.125f,0.25f,0.75f,0};basis[3]={-13,7.25f,3.75f,1};if(profile&1)request.basis=basis;
            if(bank->geometry().resolve(std::int16_t(logical))){
                auto trial=random;auto variant=request.variant;if(variant==-1){variant=bank->tracks().variants(request.effect);if(variant>0)variant=std::int16_t(trial.request(1)%std::uint16_t(variant));}
                try{bank->bind(request.effect,variant);}catch(const std::exception& error){++general_profiles;if(unknown_effect_profiles.emplace(asset,logical,variant).second)std::cerr<<"Unadmitted effect asset="<<asset<<" logical="<<logical<<" variant="<<variant<<" reason="<<error.what()<<'\n';owner.close();continue;}
            }
            put(memory,0x70000,*request.position);std::memcpy(memory+0x70100,basis.data(),64);
            const std::array<std::uint32_t,3> callbacks{0x653010,0x6531d0,0x653e80};
            const auto original=call(memory,0x6525d0,{request.basis?0x70100u:0u,0x70000,request.child_mask,logical,std::uint32_t(std::int32_t(request.variant)),request.flags,callbacks[kind]});
            const auto at=GPR_U32(&original,2);auto native=owner.create(request);
            if(!at){check(native.status==e::WorkStatus::resource_missing);++general_missing;owner.close();continue;}
            check(native.status==e::WorkStatus::completed&&native.edit);++general_created;
            check(owner.size()==1&&owner.piece_count()==memory[at+0x31]);
            if(kind==2){
                const float scale=1.f+float(profile)/4.f;check(native.edit->uniform_scale(scale));put(memory,at+0xb4,scale);put(memory,at+0xb8,scale);put(memory,at+0xbc,scale);
                check(native.edit->third_angle(std::int16_t(0x3719+profile)));put(memory,at+0x94,std::int16_t(0x3719+profile));
                const auto attributes=std::uint16_t(profile&1?2:4);check(native.edit->set_attributes(attributes));put(memory,at+0x23e,attributes);
                const m::Vector modulation{.25f,.75f,1.25f};const float multiplier=.625f;put(memory,0x4bac84,modulation);put(memory,0x4bac90,multiplier);call(memory,0x5ead70,{at});check(native.edit->feedback(modulation,multiplier));
            }
            check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);
            for(unsigned tick=0;tick<4096;++tick){
                const m::Vector camera{12,-3,27};auto view=m::identity();view[0]={.5f,.125f,-.25f,0};view[1]={.25f,1.5f,.375f,0};view[2]={-.125f,.25f,.75f,0};view[3]={-13,7.25f,3.75f,1};std::memcpy(memory+0x3240e0,view.data(),64);put(memory,0x324138,camera);
                call(memory,callbacks[kind],{at});const auto report=owner.update_with_view(camera,view);check(report.status==e::VisualStatus::completed);++general_frames;
                const auto frame=owner.retain();check(bool(frame));
                if(memory[at]==0){check(owner.size()==0&&owner.piece_count()==0&&frame->visuals.empty());check(!native.edit->uniform_scale(9)&&!native.edit->set_attributes(9));break;}
                check(owner.size()==1&&frame->visuals.size()==1);const auto& output=frame->visuals[0];check(output.visible==(memory[at+1]!=0));check(output.pieces.size()==memory[at+0x31]);
                for(std::size_t i=0;i<output.pieces.size();++i){
                    const auto& piece=output.pieces[i];const auto child=get<std::uint32_t>(memory,at+0x134+4*std::uint32_t(i));
                    if(!output.visible)continue;
                    check(piece.visible==(memory[at+0xf4+i]!=0));
                    if(!piece.visible)continue;
                    check(piece.flags==get<std::uint32_t>(memory,child+4));check(piece.root==get<std::uint16_t>(memory,child+2)&&piece.material==memory[child+1]);
                    if(std::memcmp(&piece.parameters.translation,memory+child+0x24,12)!=0){const auto* values=&piece.parameters.translation.x;for(unsigned j=0;j<3;++j)std::cerr<<"position "<<j<<" native="<<std::bit_cast<std::uint32_t>(values[j])<<" original="<<get<std::uint32_t>(memory,child+0x24+4*j)<<'\n';std::cerr<<"tick="<<tick<<" child="<<i<<" at="<<at<<" basis="<<get<std::uint32_t>(memory,at+0x1f0)<<" group="<<get<std::uint16_t>(memory,at+0x206)<<" variant="<<request.variant<<'\n';for(unsigned j=0;j<16;++j)std::cerr<<get<float>(memory,at+0x50+4*j)<<' ';std::cerr<<'\n';}
                    check(std::memcmp(&piece.parameters.translation,memory+child+0x24,12)==0);
                    check(std::memcmp(piece.parameters.rotation.data(),memory+child+0x30,6)==0);
                    check(std::memcmp(&piece.parameters.scale,memory+child+0x38,12)==0);
                    check(std::memcmp(&piece.parameters208,memory+child+0xc,12)==0);
                    const auto* mesh=output.bank->geometry().material(piece.root,piece.material);check(mesh!=nullptr);for(std::size_t j=0;j<mesh->indices.size();++j)check(std::bit_cast<std::uint32_t>(piece.material_values[j])==get<std::uint32_t>(memory,child+0x50+std::uint32_t(4*j)));
                }
                check(random.state().primary==get<std::uint16_t>(memory,0x3244b0)&&random.state().secondary==get<std::uint16_t>(memory,0x3244b8)&&random.state().observed==memory[0x2b8de8]);check(tick+1<4096);
            }
            const auto retained=native.edit;owner.close();check(!retained->third_angle(77));
        }
    }
}
