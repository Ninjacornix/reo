#include "game/native/gameplay_session/room_membership.hpp"
#include <cstdio>
#include <source_location>
#include <string>
#include <vector>
namespace session=reo::native::gameplay_session;
namespace {
std::vector<std::uint8_t> ram(0x1000000);
unsigned checks{},calls{},epoch{},mode{};
std::optional<session::RoomMembershipUpdate> sent;
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Membership mode "+std::to_string(mode)+" epoch "+std::to_string(epoch)+" line "+std::to_string(at.line()));
}
void port(std::uint8_t* memory,R5900Context* context,PS2Runtime*){
    if(context->pc==0x107ab0){std::memcpy(memory+GPR_U32(context,4),memory+GPR_U32(context,5),GPR_U32(context,6));}
    else if(context->pc==0x810960||context->pc==0x8129c0){
        check(GPR_U32(context,4)==7&&GPR_U32(context,6)==1&&GPR_U32(context,7)==4);
        const auto at=GPR_U32(context,5);check(memory[at]==4&&memory[at+3]==4&&memory[at+4]==2);
        session::RoomMembershipUpdate update;update.sender=memory[at+2];update.count=(memory[at+1]-6)/5;check(update.count<=8);
        for(unsigned i=0;i<update.count;++i){update.rows[i].room=memory[at+6+5*i];std::memcpy(update.rows[i].members.data(),memory+at+7+5*i,4);}
        sent=update;
    }else throw std::runtime_error("Undeclared membership boundary "+std::to_string(context->pc));
    context->pc=GPR_U32(context,31);
}
std::uint32_t call(PS2Runtime& runtime,unsigned at,unsigned a0=0,unsigned a1=0,unsigned a2=0){
    ++calls;R5900Context context{};context.pc=at;context.g[4].lo=a0;context.g[5].lo=a1;context.g[6].lo=a2;context.g[29].lo=0x50000;context.g[31].lo=0x1234;
    runtime.lookupFunction(at)(ram.data(),&context,&runtime);check(context.pc==0x1234);return GPR_U32(&context,2);
}
}
PS2Runtime::Fn PS2Runtime::lookupFunction(unsigned at)const{switch(at){/* ORIGINAL_LOOKUP */default:return port;}}
int main()try{
    PS2Runtime runtime;
    for(mode=0;mode<2;++mode){
        session::RoomMembership native;check(!native.first(0,0)&&!native.begin_update());check(native.initialize(mode));
        const unsigned table=mode?0x815430:0x82bbf0,authority=mode?0x815d25:0x83e2d5;
        const unsigned claim=mode?0x811140:0x811970,release=mode?0x811300:0x811b30,collect=mode?0x810f50:0x811780,receive=mode?0x8110c0:0x8118f0;
        const unsigned first=mode?0x8114b0:0x811c50,contains=mode?0x811550:0x811ca0,owner=mode?0x8115f0:0x811d40;
        std::memset(ram.data()+table,0xff,1536);ram[0x4baded]=mode?2:0;
        for(epoch=0;epoch<12;++epoch){
            check(native.begin_update());std::memcpy(ram.data()+table,ram.data()+table+512,512);
            for(unsigned request=0;request<12;++request){
                const auto actor=std::uint8_t((epoch+request)%5);
                const auto room=std::uint16_t((epoch*3+request)%8);
                const std::int8_t enabled=(epoch+request)%7?1:0;ram[authority]=enabled;
                const bool removing=(epoch+request)%3==0;
                call(runtime,removing?release:claim,actor,room,1);
                check((removing?native.release(actor,room,enabled):native.claim(actor,room,enabled))==session::RoomMembershipStatus::completed);
                check(std::memcmp(native.authority_rows().data(),ram.data()+table,512)==0);
            }
            ram[authority]=1;sent.reset();call(runtime,collect);
            const auto changes=native.collect(1,ram[0x4baded]);check(changes.status==session::RoomMembershipStatus::completed&&bool(changes.update)==bool(sent));
            check(std::memcmp(native.published_rows().data(),ram.data()+table+512,512)==0);
            if(sent){
                check(sent->sender==changes.update->sender&&sent->count==changes.update->count);
                for(unsigned row=0;row<sent->count;++row)check(sent->rows[row]==changes.update->rows[row]);
                // Claim/publication do not mutate the independently received table.
                check(std::memcmp(native.received_rows().data(),ram.data()+table+1024,512)==0);
                constexpr unsigned packet=0x60000;ram[packet+1]=6+5*sent->count;
                for(unsigned row=0;row<sent->count;++row){ram[packet+6+5*row]=sent->rows[row].room;std::memcpy(ram.data()+packet+7+5*row,sent->rows[row].members.data(),4);}
                call(runtime,receive,packet);check(native.receive(std::span(sent->rows).first(sent->count))==session::RoomMembershipStatus::completed);
                check(std::memcmp(native.received_rows().data(),ram.data()+table+1024,512)==0);
            }
            for(unsigned room:{0u,1u,3u,7u,9u,127u,128u,255u}){
                ref_write(ram.data(),0x3243dc,std::uint16_t(room));
                check(std::uint32_t(*native.owner(room))==call(runtime,owner,room));
                for(unsigned actor:{0u,1u,2u,3u,4u,255u}){
                    check(std::uint32_t(*native.first(room,actor))==call(runtime,first,actor));
                    check(std::uint32_t(*native.contains(room,actor))==call(runtime,contains,actor));
                }
            }
        }
        native.clear();check(!native.ready(mode)&&!native.owner(0));
    }
    std::printf("{\"checks\":%u,\"original_calls\":%u,\"modes\":2,\"epochs\":24,\"game_run\":false}\n",checks,calls);
}catch(const std::exception& error){std::fprintf(stderr,"%s\n",error.what());return 1;}
