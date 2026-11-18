#include "game/native/gameplay_world/resource_frames.hpp"
unsigned resource_pulse_frames{},resource_pulse_emissions{},resource_pulse_refusals{};
void compare_resource_pulses(const std::vector<std::vector<std::byte>>& corpus,std::vector<std::uint8_t>& ram){
    namespace g=reo::native::gameplay_world;
    auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        std::fill(ram.begin(),ram.end(),0);prepare(memory,corpus[asset],corpus[asset+1]);
        auto bank=e::EffectBank::import(corpus[asset],corpus[asset+1]);
        auto session=std::make_shared<g::Session>();g::World world({{g::input::Remap{1,2,4}},1,{16,UINT64_MAX}},session);
        e::PeriodicVisuals owner(bank,session->random);std::vector<Live> live;live.reserve(168);CapturingEmitter emitter(owner,live,memory);
        s::SceneResources resources;g::ResourceModels models;g::ResourceFrames frames(world,resources,models,&emitter);const auto created_model=models.create();check(created_model.status==g::ResourceModelStatus::completed);
        auto& value=*created_model.model;call(memory,0x590be0);const auto allocated_model=call(memory,0x590c70);const auto raw=GPR_U32(&allocated_model,2);
        const auto sync=[&](){
            value.active=true;value.visible=false;memory[raw]=1;memory[raw+1]=0;
            put(memory,raw+0x23c,value.flags);put(memory,raw+0x36,value.content_id);memory[raw+8]=value.pulse_phase;
            put(memory,raw+0xe,value.pulse_timer);put(memory,raw+0x12,value.pulse_packed);put(memory,raw+0x200,value.position);put(memory,raw+0x218,value.pulse_distance);
            for(unsigned i=0;i<3;++i)put(memory,raw+0x21c+2*i,value.angles[i]);
            const auto rng=session->random.state();put(memory,0x3244b0,rng.primary);put(memory,0x3244b8,rng.secondary);memory[0x2b8de8]=rng.observed;
        };
        const auto update=[&](bool drain){
            const auto previous=live.size();call(memory,0x5932f0,{raw});frames.common(created_model.id,value);++resource_pulse_frames;
            check(value.flags==get<std::uint32_t>(memory,raw+0x23c)&&value.visible==bool(memory[raw+1]));
            check(value.pulse_phase==memory[raw+8]&&value.pulse_timer==get<std::int16_t>(memory,raw+0xe)&&value.pulse_packed==get<std::int16_t>(memory,raw+0x12));
            const auto rng=session->random.state();check(rng.primary==get<std::uint16_t>(memory,0x3244b0)&&rng.secondary==get<std::uint16_t>(memory,0x3244b8)&&rng.observed==memory[0x2b8de8]);
            if(live.size()!=previous){check(live.size()==previous+1);const auto& newest=live.front();check(std::memcmp(&newest.visual->position,memory+newest.original+0x38,12)==0);check(newest.visual->scale==get<float>(memory,newest.original+0xf0)&&newest.visual->delay==get<std::int16_t>(memory,newest.original+0xc));++resource_pulse_emissions;}
            if(!drain)return;
            put(memory,0x324138,m::Vector{10,20,30});for(const auto& item:live)call(memory,0x6535c0,{item.original});
            live.erase(std::remove_if(live.begin(),live.end(),[&](const auto& item){return !memory[item.original];}),live.end());
            check(owner.update({10,20,30}).status==e::VisualStatus::completed);compare(owner,live,memory);
            const auto frame=owner.retain();for(unsigned i=0;i<live.size();++i){call(memory,0x652d60,{live[i].original});call(memory,0x651d00,{live[i].original});check(owner.retire(frame->visuals[i].id));}live.clear();
        };
        for(unsigned profile=0;profile<36;++profile){
            value.flags=0x800;value.content_id=std::array<std::uint16_t,6>{0,0x27a6,0x12c,0x12d,0x12e,7}[profile%6];value.position={float(profile)*1.25f,-4,17};value.pulse_phase=std::uint8_t((profile/6)%3);value.pulse_timer=std::array<std::int16_t,6>{0,1,3,-1,32767,-32768}[profile%6];value.pulse_packed=std::bit_cast<std::int16_t>(std::uint16_t(profile*1337));value.pulse_distance=profile&1?0:30;value.angles={123,23456,std::uint16_t(profile&2?0:12345)};sync();
            for(unsigned tick=0;tick<120;++tick)update(true);
        }
        if(asset==0)for(unsigned bits=0;bits<65536;++bits){
            value.flags=0x800;value.content_id=0;value.pulse_phase=0;value.pulse_timer=0;value.pulse_packed=std::bit_cast<std::int16_t>(std::uint16_t(bits*17));value.pulse_distance=bits&1?-30.f:30.f;value.position={12,-9,3};value.angles={0,std::uint16_t(bits),std::uint16_t(bits*197u+31u)};sync();update(true);
        }
        // Actual shared168/256 capacity: no synthetic successful allocation.
        for(unsigned serial=0;serial<180;++serial){value.flags=0x800;value.content_id=0;value.pulse_phase=0;value.pulse_timer=0;value.pulse_packed=std::int16_t(serial);value.pulse_distance=0;sync();update(false);}
        check(owner.size()==168&&live.size()==168);check(owner.piece_count()==256);value.flags=0x800;value.pulse_phase=0;value.pulse_timer=0;sync();update(true);
        // A required emission cannot silently use an unbound visual RNG.
        g::ResourceFrames missing(world,resources,models);value.flags=0x800;value.pulse_phase=0;value.pulse_timer=0;bool refused{};try{missing.common(created_model.id,value);}catch(const std::runtime_error&){refused=true;}check(refused);++resource_pulse_refusals;
        reo::native::gameplay_session::Random foreign_random;e::PeriodicVisuals foreign(bank,foreign_random);g::ResourceFrames wrong(world,resources,models,&foreign);value.flags=0x800;value.pulse_phase=0;value.pulse_timer=0;refused=false;try{wrong.common(created_model.id,value);}catch(const std::runtime_error&){refused=true;}check(refused);++resource_pulse_refusals;
        owner.close();call(memory,0x652ce0);
    }
}
