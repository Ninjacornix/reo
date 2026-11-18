unsigned reception_speech_cases{},reception_presence_cases{},reception_speech_refusals{};
namespace actor_speech_reception_fixture {
namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;
constexpr unsigned base=0x4a5c30,packet=0x70000,view=0x80000;
void seed(std::uint8_t* m,unsigned at,g::Actor& a,unsigned n){
    actor_reception_fixture::seed_actor(m,at,a,n);a.room=std::uint16_t(n*17);put(m,at+0x1e2,a.room);
    a.speech={g::SpeechSelection{n*31u,-123,-4,5,-6},-777,std::int8_t(7)};
    const auto& s=*a.speech.selection;put(m,at+0xdb4,s.sequence);put(m,at+0xdb8,*a.speech.gauge_notice);put(m,at+0xdc2,s.target_identifier);
    m[at+0xdc7]=std::uint8_t(s.target_context);m[at+0xdc1]=std::uint8_t(s.response_state);m[at+0xdc0]=std::uint8_t(s.pending);m[at+0xda9]=7;
}
void same(std::uint8_t* m,unsigned at,const g::Actor& a){
    actor_reception_fixture::compare_actor(m,at,a);check(a.speech.selection&&a.speech.variant&&a.speech.gauge_notice);const auto& s=*a.speech.selection;
    check(s.sequence==get<unsigned>(m,at+0xdb4)&&*a.speech.gauge_notice==get<std::int32_t>(m,at+0xdb8)&&s.target_identifier==get<std::int16_t>(m,at+0xdc2));
    check(std::uint8_t(s.target_context)==m[at+0xdc7]&&std::uint8_t(s.response_state)==m[at+0xdc1]&&std::uint8_t(s.pending)==m[at+0xdc0]&&std::uint8_t(*a.speech.variant)==m[at+0xda9]);
}
void encode(std::uint8_t* m,const u::ActorSpeechMessage& s){std::fill_n(m+packet,20,0);m[packet]=11;put(m,packet+4,s.sequence);put(m,packet+8,s.target_identifier);put(m,packet+10,s.target_context);put(m,packet+12,s.pending);put(m,packet+13,s.gauge_notice);put(m,packet+14,s.variant);put(m,packet+16,s.response_state);}
void same_presence(std::uint8_t* m,const g::InventoryPresence& presence){
    for(unsigned i=0;i<4;++i){const auto peer=presence.peer(i);if(peer){check(peer->room==m[view+0x74+i]&&peer->updates_left==get<unsigned>(m,view+0x78+4*i));check(std::bit_cast<unsigned>(peer->position.x)==get<unsigned>(m,view+0x88+4*i)&&std::bit_cast<unsigned>(peer->position.y)==get<unsigned>(m,view+0x98+4*i)&&std::bit_cast<unsigned>(peer->position.z)==get<unsigned>(m,view+0xa8+4*i));}else{check(m[view+0x74+i]==0xcc&&get<unsigned>(m,view+0x78+4*i)==0xccccccccu&&get<unsigned>(m,view+0x88+4*i)==0xccccccccu&&get<unsigned>(m,view+0x98+4*i)==0xccccccccu&&get<unsigned>(m,view+0xa8+4*i)==0xccccccccu);}}
}
}
void compare_actor_speech_reception(std::vector<std::uint8_t>& ram){
    using namespace actor_speech_reception_fixture;auto* m=ram.data();std::fill(ram.begin(),ram.end(),0);owned_constants(m);
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());for(unsigned i=0;i<8;++i){auto a=std::make_unique<g::Actor>();a->slot=std::uint8_t(i);check(bool(world.spawn_primary(i,std::move(a)).id));m[base+i*0x10e0+3]=std::uint8_t(i);}
    g::InventoryPresence presence(world);u::ActorReception receiver(world,nullptr,nullptr,&presence);
    const auto setup_view=[&](bool active){presence.close();if(active)check(presence.activate());std::fill_n(m+view,0x100,0xcc);put(m,0x755768,active?view:0u);};
    const auto run=[&](unsigned n,bool gates){
        const unsigned index=n%8,selected=(n>>3)%8,at=base+index*0x10e0;const auto a=world.primary(index);seed(m,at,*a,n);world.selected_actor=std::uint8_t(selected);world.room=std::uint16_t(n%3?a->room:a->room+1);world.mode=std::uint8_t(n>>8);world.paused=std::bit_cast<std::int8_t>(std::uint8_t(n));world.session().message_phase=std::bit_cast<std::int8_t>(std::uint8_t(gates?n:1+n%2));world.primary(selected)->status=n%17?0u:4u;put(m,base+selected*0x10e0+0xba0,world.primary(selected)->status);m[0x4baded]=world.selected_actor;m[0x3243fb]=std::uint8_t(world.session().message_phase);m[0x3243f2]=world.mode;put(m,0x3243dc,world.room);
        setup_view(index<4&&n%3!=0);const u::ActorSpeechMessage speech{u::MessageRoute::mode_one,index+1,n*1664525u,std::bit_cast<std::int16_t>(std::uint16_t(n*31u)),std::bit_cast<std::int16_t>(std::uint16_t(n)),std::bit_cast<std::int32_t>(n*1013904223u),std::bit_cast<std::int8_t>(std::uint8_t(n*17)),std::bit_cast<std::int8_t>(std::uint8_t(n>>8)),n%5?std::int8_t(0):std::bit_cast<std::int8_t>(std::uint8_t(n))};encode(m,speech);
        const auto echo=n%3;call(m,0x67ed50,{index+1,packet,echo});check(receiver.receive(speech,echo!=0).status==u::ReceptionStatus::completed);same(m,at,*a);same_presence(m,presence);++reception_speech_cases;
    };
    for(unsigned n=0;n<65536;++n){run(n,false);run(n,true);}
    // Compare the actual cache producer independently of speech, including raw
    // floating-point payloads, all room halfwords and local/inactive gates.
    for(unsigned n=0;n<65536;++n){const unsigned index=n%4;const auto a=world.primary(index);seed(m,base+index*0x10e0,*a,n);world.selected_actor=std::uint8_t((n>>2)%8);m[0x4baded]=world.selected_actor;setup_view(n%3!=0);call(m,0x6dfee0,{index});check(presence.refresh(index)==g::PresenceStatus::completed);same_presence(m,presence);++reception_presence_cases;}
    world.selected_actor=1;world.primary(1)->status=0;world.session().message_phase=1;world.room=10;const auto a=world.primary(0);a->room=11;a->speech={};a->pending_notice=123;a->selected_resource=0;a->root_motion_delta={1,2,3};presence.close();const u::ActorSpeechMessage speech{u::MessageRoute::mode_one,1,12,-13,-14,-15,-16,-17,0};
    check(receiver.receive(speech,true).status==u::ReceptionStatus::completed&&a->speech.variant==0&&!a->speech.selection&&!a->speech.gauge_notice&&a->root_motion_delta.x==0);++reception_speech_refusals;
    u::ActorReception absent(world);a->pending_notice=123;a->speech={};a->root_motion_delta={1,2,3};check(absent.receive(speech,true).status==u::ReceptionStatus::unavailable&&!a->pending_notice&&!a->speech.variant&&a->root_motion_delta.x==1);++reception_speech_refusals;
    check(presence.activate());for(unsigned index=4;index<8;++index){auto invalid=speech;invalid.channel=index+1;const auto other=world.primary(index);other->speech={};other->pending_notice=123;check(receiver.receive(invalid,true).status==u::ReceptionStatus::unavailable&&!other->pending_notice&&!other->speech.variant);}++reception_speech_refusals;
    check(presence.refresh(1)==g::PresenceStatus::completed&&!presence.peer(1)&&presence.refresh(UINT32_MAX)==g::PresenceStatus::unavailable);++reception_speech_refusals;
    check(world.retire_primary(0)==g::actors::EntityStatus::completed&&presence.refresh(0)==g::PresenceStatus::unavailable);++reception_speech_refusals;
    g::World foreign({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());bool refused=false;try{u::ActorReception invalid(foreign,nullptr,nullptr,&presence);}catch(const std::invalid_argument&){refused=true;}check(refused);++reception_speech_refusals;
    check(world.close()==g::Status::completed&&!presence.active()&&!presence.peer(0)&&presence.refresh(0)==g::PresenceStatus::unavailable&&!presence.activate()&&receiver.receive(speech,true).status==u::ReceptionStatus::unavailable);++reception_speech_refusals;
}
