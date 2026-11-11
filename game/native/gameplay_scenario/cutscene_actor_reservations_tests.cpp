#include "cutscene_actor_reservations.hpp"
#include <algorithm>
#include <cstring>
#include <iostream>
#include <limits>
#include <source_location>
#include <stdexcept>
#include <vector>
#ifdef REO_CUTSCENE_RESERVATIONS_ORIGINAL
#include "reservation_reference.hpp"
#endif
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},initializations{},queries{},appends{},refusals{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error(std::string("Cutscene reservation check ")+at.file_name()+":"+std::to_string(at.line()));
}
#ifdef REO_CUTSCENE_RESERVATIONS_ORIGINAL
std::vector<std::uint8_t> memory(0x2000000);
unsigned clear_calls{},copy_calls{};
std::uint32_t invoke(unsigned at,std::int32_t arg=0,unsigned count=0){
    R5900Context c;PS2Runtime runtime;c.pc=at;SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);SET_GPR_S32(&c,4,arg);SET_GPR_U32(&c,5,count);
    if(at==0x5f0c60)o2_005F0C60_0x5f0c60(memory.data(),&c,&runtime);
    else if(at==0x5f0cf0)o2_005F0CF0_0x5f0cf0(memory.data(),&c,&runtime);
    else o2_005F0D90_0x5f0d90(memory.data(),&c,&runtime);
    check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);return GPR_U32(&c,2);
}
void compare_state(const s::CutsceneActorReservations& owner){
    check(owner.requested().size()==memory[0x743518]&&owner.reserved().size()==memory[0x743510]);
    for(unsigned i=0;i<32;++i){check(memory[0x7434f0+i]==(i<owner.requested().size()?owner.requested()[i]:0x88));check(memory[0x7434d0+i]==(i<owner.reserved().size()?owner.reserved()[i]:0x88));}
}
void compare_query(const s::CutsceneActorReservations& owner,std::int32_t value){check(owner.contains(value)==bool(invoke(0x5f0cf0,value)));++queries;}
void initialize(s::CutsceneActorReservations& owner,std::span<const std::uint8_t> input){
    std::memset(memory.data()+0x7434d0,0x55,64);std::memcpy(memory.data()+0x100000,input.data(),input.size());clear_calls=copy_calls=0;
    check(owner.initialize(input)==s::CutsceneReservationStatus::completed);invoke(0x5f0c60,0x100000,unsigned(input.size()));
    check(clear_calls==2&&copy_calls==1);compare_state(owner);++initializations;
}
#else
void compare_state(const s::CutsceneActorReservations&){}
void compare_query(const s::CutsceneActorReservations& owner,std::int32_t value){(void)owner.contains(value);++queries;}
void initialize(s::CutsceneActorReservations& owner,std::span<const std::uint8_t> input){check(owner.initialize(input)==s::CutsceneReservationStatus::completed);++initializations;}
#endif
void append(s::CutsceneActorReservations& owner,std::uint8_t value){
    check(owner.reserve(value)==s::CutsceneReservationStatus::completed);
#ifdef REO_CUTSCENE_RESERVATIONS_ORIGINAL
    invoke(0x5f0d90,value);
#endif
    compare_state(owner);++appends;
}
void cases(){
    s::CutsceneActorReservations owner;check(owner.contains(255)&&!owner.contains(-1)&&owner.requested().empty()&&owner.reserved().empty());
    std::array<std::uint8_t,33> input{};
    for(unsigned count=0;count<=32;++count)for(unsigned seed=0;seed<4;++seed){
        for(unsigned i=0;i<32;++i)input[i]=std::uint8_t(i*37+seed*81);
        initialize(owner,std::span(input).first(count));
        for(int value=-128;value<384;++value)compare_query(owner,value);
        compare_query(owner,std::numeric_limits<std::int32_t>::min());compare_query(owner,std::numeric_limits<std::int32_t>::max());
        // Native rejection must preserve both lists, including assignments.
        append(owner,std::uint8_t(count+seed));const auto requested=std::vector(owner.requested().begin(),owner.requested().end());const auto reserved=std::vector(owner.reserved().begin(),owner.reserved().end());
        check(owner.initialize(input)==s::CutsceneReservationStatus::invalid_count&&std::ranges::equal(requested,owner.requested())&&std::ranges::equal(reserved,owner.reserved()));++refusals;
    }
    for(unsigned byte=0;byte<256;++byte){
        initialize(owner,{});
        for(unsigned i=0;i<32;++i){
            const auto value=std::uint8_t(byte+i*13);append(owner,value);
            for(std::int32_t query:{std::int32_t(value),std::int32_t(std::bit_cast<std::int8_t>(value)),255,-1,128,-128,0,7})compare_query(owner,query);
        }
        check(owner.reserve(std::uint8_t(byte))==s::CutsceneReservationStatus::full);compare_state(owner);++refusals;
    }
    // Initialization from an existing view is safe; source memcpy preconditions
    // do not require native callers to retain an unnecessary extra buffer.
    initialize(owner,std::span(input).first(8));const auto retained=std::vector(owner.requested().begin(),owner.requested().end());
    check(owner.initialize(owner.requested())==s::CutsceneReservationStatus::completed&&std::ranges::equal(retained,owner.requested())&&owner.reserved().empty());
    append(owner,9);append(owner,9);check(owner.reserved().size()==2&&owner.reserved()[0]==9&&owner.reserved()[1]==9);
}
}
#ifdef REO_CUTSCENE_RESERVATIONS_ORIGINAL
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime*){
    const auto at=GPR_U32(c,4),size=GPR_U32(c,6);check(at<0x2000000&&size<=0x2000000-at);
    if(c->pc==0x107c68){check(size==32&&GPR_U32(c,5)==0x88);std::memset(m+at,0x88,size);++clear_calls;}
    else if(c->pc==0x107ab0){const auto from=GPR_U32(c,5);check(size<=32&&from<0x2000000&&size<=0x2000000-from);std::memcpy(m+at,m+from,size);++copy_calls;}
    else throw std::runtime_error("Undeclared reservation source port");
    SET_GPR_U32(c,2,at);c->pc=GPR_U32(c,31);
}
#endif
int main(){try{cases();std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"initializations\":"<<initializations<<",\"queries\":"<<queries<<",\"appends\":"<<appends<<",\"refusals\":"<<refusals<<",\"game_run\":false}\n";return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
