#include "game/native/gameplay_world/interaction_transitions.hpp"
#include "game/native/gameplay_world/interaction_transition_profile.inc"
unsigned interaction_transition_cases{},interaction_transition_refusals{},interaction_transition_owner_cases{};
void compare_actor_interaction_transitions(std::uint8_t* m,const char* table_path){
    namespace g=reo::native::gameplay_world;namespace u=reo::native::gameplay_update;constexpr unsigned raw=0x4a5c30;
    std::ifstream input(table_path,std::ios::binary);input.read(reinterpret_cast<char*>(m+0x711890),200);check(bool(input));check(std::memcmp(g::interaction_transition_states.data(),m+0x711890,200)==0);
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));const auto a=world.primary(0);
    const auto run=[&](unsigned kind,unsigned n,unsigned selector,unsigned category,unsigned primary,unsigned status){
        a->transient_action=std::uint8_t(n);a->interaction_request=g::InteractionRequest{std::uint8_t(kind),std::uint8_t(n),{1,2,3},4,5,6};a->primary=std::uint8_t(primary);a->secondary=17;a->phase=18;a->subphase=19;a->category=std::uint8_t(category);a->slot=std::uint8_t(n>>8);a->status=status;a->position={std::bit_cast<float>(n*65521u),std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u)};a->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n*17));a->saved_action_position={-1,-2,-3};a->saved_action_yaw=-4;
        m[raw+0xab8]=a->transient_action;m[raw+0xab9]=std::uint8_t(kind);m[raw+0xaba]=std::uint8_t(n);m[raw+2]=a->category;m[raw+3]=a->slot;m[raw+8]=a->primary;m[raw+9]=17;m[raw+10]=18;m[raw+11]=19;put(m,raw+0xba0,status);put(m,raw+0x38,a->position);put(m,raw+0x92,a->orientation[1]);put(m,raw+0xd94,a->saved_action_position);put(m,raw+0xda0,a->saved_action_yaw);
        a->room=std::uint16_t(n%2);put(m,raw+0x1e2,a->room);put(m,0x3243dc,world.room);m[0x3243f2]=world.mode;m[0x4baded]=world.selected_actor;
        const auto result=g::consume_interaction_request(world,id,selector);
        if(result.status==g::InteractionTransitionStatus::unavailable){check(a->transient_action==0&&a->primary==std::uint8_t(primary)&&a->secondary==17&&a->phase==18&&a->subphase==19&&a->saved_action_position.x==-1&&a->saved_action_yaw==-4);++interaction_transition_refusals;return;}
        const auto source=call(m,0x64ef10,{raw,selector});check(source==unsigned(result.original_result)&&a->transient_action==m[raw+0xab8]&&a->primary==m[raw+8]&&a->secondary==m[raw+9]&&a->phase==m[raw+10]&&a->subphase==m[raw+11]);check(std::memcmp(&a->saved_action_position,m+raw+0xd94,12)==0&&a->saved_action_yaw==get<std::int16_t>(m,raw+0xda0)&&a->status==get<unsigned>(m,raw+0xba0));check(a->interaction_request->kind==m[raw+0xab9]&&a->interaction_request->parameter==m[raw+0xaba]);++interaction_transition_cases;
    };
    for(unsigned selector:{0u,1u})for(unsigned category=0;category<4;++category)for(unsigned kind=0;kind<50;++kind)for(unsigned n=0;n<256;++n)run(kind,n,0xabcd0000u|selector,category,category==0&&selector==0?1:n,n%2?0x80u:0u);
    for(unsigned n=0;n<65536;++n)run(n&255u,n,n>>8,n%4,n&255u,n%3?0u:0x80u);
    a->transient_action=1;a->interaction_request.reset();check(g::consume_interaction_request(world,id,1).status==g::InteractionTransitionStatus::unavailable&&!a->transient_action);++interaction_transition_refusals;
    a->transient_action=0;check(g::consume_interaction_request(world,id,UINT32_MAX).status==g::InteractionTransitionStatus::idle);++interaction_transition_cases;
    a->transient_action=1;check(g::consume_interaction_request(world,{},1).status==g::InteractionTransitionStatus::unavailable&&a->transient_action==1);++interaction_transition_refusals;
    actor_action_fixture::Notifications notifications;u::Owner owner(world,notifications);a->interaction_request=g::InteractionRequest{1,0,{1,2,3},4,5,6};a->primary=1;a->category=0;a->status=0;check(owner.consume_actor_interaction_request(id,0).status==g::InteractionTransitionStatus::completed&&a->secondary==0x18&&!a->transient_action);++interaction_transition_owner_cases;
    a->transient_action=1;a->interaction_request->parameter=2;check(owner.consume_actor_interaction_request(id,0).original_result&&a->secondary==0x17);++interaction_transition_owner_cases;
    check(owner.close()==u::Status::completed);a->transient_action=1;check(owner.consume_actor_interaction_request(id,1).status==g::InteractionTransitionStatus::unavailable&&a->transient_action==1);++interaction_transition_owner_cases;
    check(world.close()==g::Status::completed&&g::consume_interaction_request(world,id,1).status==g::InteractionTransitionStatus::unavailable);++interaction_transition_refusals;
}
