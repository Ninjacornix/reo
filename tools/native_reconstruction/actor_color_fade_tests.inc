#include "game/native/gameplay_world/color_fade.hpp"
unsigned color_fade_cases{},color_fade_refusals{},offline_resume_cases{},offline_resume_refusals{},color_fade_finish_cases{},color_fade_frame_cases{};
namespace actor_color_fade_fixture {
namespace g=reo::native::gameplay_world;
constexpr unsigned raw=0x4a5c30;
void write(std::uint8_t* m,const g::Actor& a){check(bool(a.color_fade));put(m,raw+0xba4,a.auxiliary_status);put(m,raw+0xce8,a.color_fade->rgba);put(m,raw+0xcec,a.color_fade->step);put(m,raw+0xcf0,a.color_fade->updates_left);}
void same(std::uint8_t* m,const g::Actor& a){check(a.auxiliary_status==get<unsigned>(m,raw+0xba4));if(a.color_fade)check(a.color_fade->rgba==get<unsigned>(m,raw+0xce8)&&a.color_fade->step==get<unsigned>(m,raw+0xcec)&&a.color_fade->updates_left==get<unsigned>(m,raw+0xcf0));}
}
void compare_actor_color_fades(std::uint8_t* m){
    using namespace actor_color_fade_fixture;
    g::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<g::Session>());const auto id=world.spawn_primary(0,std::make_unique<g::Actor>()).id;check(bool(id));const auto a=world.primary(0);
    const auto start=[&](g::FadeDirection direction,unsigned alpha,unsigned updates){
        a->auxiliary_status=alpha*1664525u;a->color_fade=g::ColorFade{alpha*17u,alpha*31u,alpha*13u};write(m,*a);call(m,direction==g::FadeDirection::increase?0x6656e0:0x665730,{raw,alpha,updates});check(g::start_color_fade(world,id,direction,alpha,updates)==g::FadeStatus::completed);same(m,*a);++color_fade_cases;
    };
    const auto advance=[&](g::FadeDirection direction){call(m,direction==g::FadeDirection::increase?0x665640:0x665690,{raw});check(g::advance_color_fade(world,id,direction)==g::FadeStatus::completed);same(m,*a);++color_fade_cases;};
    for(const auto direction:{g::FadeDirection::increase,g::FadeDirection::decrease}){
        for(unsigned alpha=0;alpha<256;++alpha)for(unsigned updates=1;updates<=1024;++updates)start(direction,alpha,updates);
        for(unsigned n=0;n<65536;++n){start(direction,n*1664525u,(n*65521u)|1u);a->auxiliary_status=n*1013904223u;a->color_fade=g::ColorFade{n*1664525u,n*22695477u,n%17?n*65521u:n%3};write(m,*a);advance(direction);}
        for(unsigned alpha=0;alpha<256;++alpha)for(unsigned updates:{1u,2u,3u,7u,15u,30u,60u,255u,256u,257u,1024u}){start(direction,alpha,updates);for(unsigned tick=0;tick<updates+1;++tick)advance(direction);}
    }
    for(unsigned n=0;n<65536;++n){
        a->auxiliary_status=n*1664525u;a->color_fade=g::ColorFade{n*1013904223u,n*22695477u,n%7?n*65521u:n%3};write(m,*a);call(m,0x6655f0,{raw});check(g::finish_color_fade(world,id)==g::FadeStatus::completed);same(m,*a);++color_fade_finish_cases;
    }
    // Reach the native consumer at its real World frame point, once per actor
    // traversal; the underlying frame provider does not receive this stage.
    actor_activity_fixture::Frame frame;g::ColorFadeFrameServices fading(frame);a->active=true;a->category=0;a->slot=0;a->room=world.room;a->status=0;a->pending_notice=0;world.mode=1;world.selected_actor=0;
    for(unsigned n=0;n<4096;++n){a->auxiliary_status=n%4==0?0u:n%4==1?0x4000u:n%4==2?0x8000u:0xc000u;a->color_fade=g::ColorFade{n*1664525u,n*22695477u,n%7};write(m,*a);call(m,0x6655f0,{raw});const auto result=world.update_primary(fading);check(result.status==g::Status::completed&&result.updated==1&&!frame.completed);same(m,*a);++color_fade_frame_cases;}
    a->auxiliary_status=0x4000;a->color_fade.reset();bool missing=false;try{(void)world.update_primary(fading);}catch(const std::runtime_error&){missing=true;}check(missing&&!frame.completed);++color_fade_refusals;a->active=false;
    a->auxiliary_status=0x12345678;a->color_fade=g::ColorFade{1,2,3};for(const auto direction:{g::FadeDirection::increase,g::FadeDirection::decrease}){check(g::start_color_fade(world,id,direction,123,0)==g::FadeStatus::unavailable&&a->auxiliary_status==0x12345678&&a->color_fade->rgba==1&&a->color_fade->step==2&&a->color_fade->updates_left==3);++color_fade_refusals;}
    check(g::start_color_fade(world,id,g::FadeDirection(99),1,2)==g::FadeStatus::unavailable&&g::advance_color_fade(world,id,g::FadeDirection(99))==g::FadeStatus::unavailable);++color_fade_refusals;a->color_fade.reset();check(g::advance_color_fade(world,id,g::FadeDirection::increase)==g::FadeStatus::unavailable);++color_fade_refusals;
    unsigned n{};
    for(unsigned mode:{0u,1u,2u,255u})for(unsigned category:{0u,1u})for(unsigned slot:{0u,1u,3u,255u})for(unsigned same_room:{0u,1u})for(unsigned parameter:{0u,1u,128u,255u})for(unsigned status:{0u,8u,0x80u,0x88u,0x10000u,0x10008u,0x10080u}){
        ++n;world.mode=std::uint8_t(mode);world.room=123;a->room=same_room?123:456;a->category=std::uint8_t(category);a->slot=std::uint8_t(slot);a->interaction_request=g::InteractionRequest{1,std::uint8_t(parameter),{1,2,3},4,5,6};a->status=status;a->auxiliary_status=n*1664525u|0xc000u;a->visible=n%2!=0;a->response_lock=22;a->primary=2;a->secondary=3;a->phase=4;a->subphase=5;a->position={std::bit_cast<float>(n*65521u),std::bit_cast<float>(n*1664525u),std::bit_cast<float>(n*1013904223u)};a->orientation[1]=std::bit_cast<std::int16_t>(std::uint16_t(n));a->saved_action_position={-1,-2,-3};a->saved_action_yaw=-4;a->color_fade=g::ColorFade{n*17u,n*31u,n*13u};write(m,*a);if(n%5==0)a->color_fade.reset();
        m[0x3243f2]=world.mode;put(m,0x3243dc,world.room);m[raw+1]=std::uint8_t(a->visible);m[raw+2]=a->category;m[raw+3]=a->slot;put(m,raw+0x1e2,a->room);m[raw+0xaba]=std::uint8_t(parameter);put(m,raw+0xba0,status);m[raw+0xbd0]=22;m[raw+8]=2;m[raw+9]=3;m[raw+10]=4;m[raw+11]=5;put(m,raw+0x38,a->position);put(m,raw+0x92,a->orientation[1]);put(m,raw+0xd94,a->saved_action_position);put(m,raw+0xda0,a->saved_action_yaw);
        if(!g::resume_offline_interaction(world,id)){check(mode==0&&category==0&&slot&&parameter&&!(status&0x88u)&&a->response_lock==0&&a->primary==2&&a->saved_action_position.x==-1);++offline_resume_refusals;continue;}
        call(m,0x668f20,{raw});check(a->status==get<unsigned>(m,raw+0xba0)&&a->response_lock==m[raw+0xbd0]&&std::uint8_t(a->visible)==m[raw+1]&&a->primary==m[raw+8]&&a->secondary==m[raw+9]&&a->phase==m[raw+10]&&a->subphase==m[raw+11]);check(std::memcmp(&a->saved_action_position,m+raw+0xd94,12)==0&&a->saved_action_yaw==get<std::int16_t>(m,raw+0xda0));same(m,*a);++offline_resume_cases;
    }
    world.mode=0;a->category=0;a->slot=1;a->interaction_request.reset();check(!g::resume_offline_interaction(world,id));++offline_resume_refusals;
    check(g::start_color_fade(world,{},g::FadeDirection::increase,1,2)==g::FadeStatus::unavailable&&g::advance_color_fade(world,{},g::FadeDirection::increase)==g::FadeStatus::unavailable);++color_fade_refusals;
    check(world.close()==g::Status::completed&&!g::resume_offline_interaction(world,id));++offline_resume_refusals;check(g::start_color_fade(world,id,g::FadeDirection::increase,1,2)==g::FadeStatus::unavailable&&g::advance_color_fade(world,id,g::FadeDirection::increase)==g::FadeStatus::unavailable);++color_fade_refusals;
}
