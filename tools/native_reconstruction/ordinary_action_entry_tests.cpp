#include "game/native/gameplay_world/ordinary_action_entry.hpp"
#include <cstdio>
#include <vector>
namespace w=reo::native::gameplay_world;
namespace u=reo::native::gameplay_update;
namespace {
unsigned checks{},cases{},dispatches{};
std::int16_t mode{};
std::vector<std::array<std::uint8_t,8>> packets;
void check(bool v){++checks;if(!v)throw std::runtime_error("ordinary entry check "+std::to_string(checks)+" case "+std::to_string(cases));}
struct Messages final:u::RoomClaimSink {
    std::vector<u::RoomClaimBeginMessage> claims;
    bool begin_room_claim(const u::RoomClaimBeginMessage& message)noexcept override{claims.push_back(message);return true;}
};
void port(std::uint8_t* ram,R5900Context* ctx,PS2Runtime*){
    switch(ctx->pc){
    case 0x1b0300:SET_GPR_S32(ctx,2,mode);break;
    case 0x66b960:++dispatches;check(ram[GPR_U32(ctx,4)+8]==1);break;
    case 0x810960:case 0x8129c0:{
        check(GPR_U32(ctx,4)==7&&GPR_U32(ctx,6)==0);
        std::array<std::uint8_t,8> message{};std::memcpy(message.data(),ram+GPR_U32(ctx,5),8);packets.push_back(message);break;
    }
    default:throw std::runtime_error("Unexpected ordinary-entry dependency");
    }
    ctx->pc=GPR_U32(ctx,31);
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{
    if(at==0x1aff90)return sub_001AFF90_0x1aff90;
    if(at==0x811970)return o9_00811970_0x811970;
    if(at==0x811140)return o8_00811140_0x811140;
    if(at==0x1b0300||at==0x66b960||at==0x810960||at==0x8129c0)return port;
    throw std::runtime_error("Unexpected ordinary-entry lookup "+std::to_string(at));
}
int main()try{
    std::vector<std::uint8_t> ram(0x900000);PS2Runtime runtime;
    w::World world({{{1,2,4}},1,{16,UINT64_MAX}},std::make_shared<w::Session>());
    for(unsigned slot=0;slot<4;++slot){auto actor=std::make_unique<w::Actor>();actor->slot=slot;check(bool(world.spawn_primary(slot,std::move(actor)).id));}
    constexpr unsigned actor_at=0x10000,done=0x1234;
    for(const auto selected_mode:{0,1,2,3})for(unsigned slot=0;slot<4;++slot)
    for(unsigned selected=0;selected<4;++selected)for(unsigned room:{0u,1u,127u,128u,65535u})
    for(unsigned category:{0u,1u,255u}){
        ++cases;mode=std::int16_t(selected_mode);world.mode=mode;world.selected_actor=selected;
        const auto actor=world.primary(slot);actor->primary=0;actor->visible=false;actor->category=category;
        actor->auxiliary_status=0x10203040;actor->response_lock=17;actor->room=room;
        actor->secondary_pose_history=w::SecondaryPoseHistory{{{{1,2,3},{4,5,6}}}};
        std::fill(ram.begin()+actor_at,ram.begin()+actor_at+0x1000,0x5a);
        ram[actor_at+1]=0;ram[actor_at+2]=category;ram[actor_at+3]=slot;ram[actor_at+8]=0;
        ram[actor_at+0xbd0]=17;ref_write(ram.data(),actor_at+0xba4,actor->auxiliary_status);
        ref_write(ram.data(),0x4a5e12+slot*4320,std::uint16_t(room));ram[0x4baded]=selected;
        packets.clear();const auto before_dispatch=dispatches;
        R5900Context ctx{};ctx.g[4].lo=actor_at;ctx.g[29].lo=0x50000;ctx.g[31].lo=done;
        o2_0066B8E0_0x66b8e0(ram.data(),&ctx,&runtime);
        Messages messages;check(w::enter_ordinary_action(world,*actor,&messages)==u::PublicationStatus::completed);
        check(ctx.pc==done&&dispatches==before_dispatch+1);
        check(actor->primary==ram[actor_at+8]&&actor->visible==(ram[actor_at+1]!=0));
        check(actor->auxiliary_status==ref_read<unsigned>(ram.data(),actor_at+0xba4));
        check(actor->response_lock==ram[actor_at+0xbd0]);
        check(messages.claims.size()==packets.size());
        for(unsigned joint=0;joint<2;++joint){const auto expected=ref_read<reo::native::transform_math::Vector>(ram.data(),actor_at+0xe58+36*joint);const auto actual=actor->secondary_pose_history->displacement[joint];check(expected.x==actual.x&&expected.y==actual.y&&expected.z==actual.z);}
        if(!packets.empty()){const auto& native=messages.claims[0];const auto& original=packets[0];
            check(original==std::array<std::uint8_t,8>{4,8,native.sender,4,0,native.sender,native.room,0});
            check(native.route==(mode?u::MessageRoute::mode_one:u::MessageRoute::mode_zero));
        }
    }
    world.mode=0;world.selected_actor=0;const auto actor=world.primary(0);actor->room=1;actor->category=0;actor->primary=0;actor->visible=false;actor->response_lock=9;
    check(w::enter_ordinary_action(world,*actor,nullptr)==u::PublicationStatus::message_unavailable);
    check(actor->primary==1&&actor->visible&&actor->response_lock==0&&(actor->auxiliary_status&0x08000000u));
    std::printf("{\"checks\":%u,\"cases\":%u,\"original_secondary_dispatches\":%u,\"game_run\":false}\n",checks,cases,dispatches);
    return 0;
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
