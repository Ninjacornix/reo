#include "game/native/gameplay_save/snapshot.hpp"
#include "original_fixture.hpp"
#include <algorithm>
#include <iostream>
#include <memory>
#include <vector>
#include "original_declarations.inc"
namespace save=reo::native::gameplay_save;
namespace {
std::uint32_t random_value{},draws{},checks{};
std::vector<std::uint32_t> events;
void check(bool value){++checks;if(!value)throw std::runtime_error("Save differential assertion "+std::to_string(checks));}
void returned(R5900Context* ctx){ctx->pc=GPR_U32(ctx,31);}
constexpr std::uint32_t base=0x10000,context=0x80000;
void original(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::uint32_t a0){
    R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,a0);SET_GPR_U32(&ctx,29,0x3f0000);SET_GPR_U32(&ctx,31,0xdeadbeef);
    fn(ram.data(),&ctx,&runtime);check(ctx.pc==0xdeadbeef);
}
int original_result(PS2Runtime::Function fn,std::vector<std::uint8_t>& ram,std::uint32_t a0){
    R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,a0);SET_GPR_U32(&ctx,29,0x3f0000);SET_GPR_U32(&ctx,31,0xdeadbeef);
    fn(ram.data(),&ctx,&runtime);check(ctx.pc==0xdeadbeef);return GPR_S32(&ctx,2);
}
int decode_original(std::vector<std::uint8_t>& ram){
    R5900Context ctx;PS2Runtime runtime;SET_GPR_U32(&ctx,4,base);SET_GPR_U32(&ctx,31,0xdeadbeef);
    sub_001C5760_0x1c5760(ram.data(),&ctx,&runtime);check(ctx.pc==0xdeadbeef);return GPR_S32(&ctx,2);
}
void stamp(void*,save::HeaderView h)noexcept{events.push_back(10);for(unsigned i=0;i<8;++i)h[i]=std::byte(0xc0+i);}
std::uint32_t random(void*,std::uint32_t argument)noexcept{events.push_back(20+argument);++draws;return random_value;}
void notify(void*,save::LiveState& s)noexcept {
    events.push_back(30);events.push_back(std::to_integer<unsigned>(s.settings[0]));events.push_back(std::to_integer<unsigned>(s.profile_flag));
    s.profile_flag^=std::byte(0x5a);
}
save::Services services{nullptr,stamp,random,notify};
template<std::size_t N>void import_bytes(std::array<std::byte,N>& out,const std::vector<std::uint8_t>& ram,std::size_t at){std::memcpy(out.data(),ram.data()+at,N);}
template<std::size_t N>void compare_bytes(const std::array<std::byte,N>& out,const std::vector<std::uint8_t>& ram,std::size_t at){check(std::memcmp(out.data(),ram.data()+at,N)==0);}
void import(save::LiveState& s,const std::vector<std::uint8_t>& r){
    import_bytes(s.settings,r,0x3241a0);import_bytes(s.first,r,0x31fb60);import_bytes(s.second,r,0x318b60);import_bytes(s.third,r,0x35f080);import_bytes(s.tail,r,0x36f080);import_bytes(s.conditional_tail,r,0x3165a8);
    s.profile_flag=std::byte(r[0x324476]);s.second_flag=std::byte(r[0x324488]);s.resume_selector=std::byte(r[0x32448d]);
}
void compare(const save::LiveState& s,const std::vector<std::uint8_t>& r){
    compare_bytes(s.settings,r,0x3241a0);compare_bytes(s.first,r,0x31fb60);compare_bytes(s.second,r,0x318b60);compare_bytes(s.third,r,0x35f080);compare_bytes(s.tail,r,0x36f080);compare_bytes(s.conditional_tail,r,0x3165a8);
    check(s.profile_flag==std::byte(r[0x324476]));check(s.second_flag==std::byte(r[0x324488]));check(s.resume_selector==std::byte(r[0x32448d]));
}
std::uint32_t rng=0x97139123;
std::uint8_t byte(){rng^=rng<<13;rng^=rng>>17;rng^=rng<<5;return std::uint8_t(rng);}
void fill(std::vector<std::uint8_t>& r){for(auto& b:r)b=byte();}
}
void sub_00107AB0_0x107ab0(std::uint8_t* rdram,R5900Context* ctx,PS2Runtime*){std::memmove(rdram+GPR_U32(ctx,4),rdram+GPR_U32(ctx,5),GPR_U32(ctx,6));SET_GPR_U32(ctx,2,GPR_U32(ctx,4));returned(ctx);}
void sub_0010B5F8_0x10b5f8(std::uint8_t* r,R5900Context* c,PS2Runtime* p){sub_00107AB0_0x107ab0(r,c,p);}
void sub_00107C68_0x107c68(std::uint8_t* rdram,R5900Context* ctx,PS2Runtime*){std::memset(rdram+GPR_U32(ctx,4),int(GPR_U32(ctx,5)),GPR_U32(ctx,6));returned(ctx);}
void sub_001AEC80_0x1aec80(std::uint8_t*,R5900Context* ctx,PS2Runtime*){events.push_back(20+GPR_U32(ctx,4));++draws;SET_GPR_U32(ctx,2,random_value);returned(ctx);}
void sub_001BF660_0x1bf660(std::uint8_t* rdram,R5900Context* ctx,PS2Runtime*){events.push_back(10);for(unsigned i=0;i<8;++i)rdram[GPR_U32(ctx,4)+i]=std::uint8_t(0xc0+i);returned(ctx);}
void sub_001BADF0_0x1badf0(std::uint8_t* rdram,R5900Context* ctx,PS2Runtime*){events.push_back(30);events.push_back(rdram[0x3241a0]);events.push_back(rdram[0x324476]);rdram[0x324476]^=0x5a;returned(ctx);}
#define UNUSED(n) void n(std::uint8_t*,R5900Context*,PS2Runtime*){throw std::runtime_error("Unadmitted icon/card path in codec fixture");}
UNUSED(sub_001290C8_0x1290c8) UNUSED(sub_00129350_0x129350) UNUSED(sub_001297A0_0x1297a0)
UNUSED(sub_00129C08_0x129c08) UNUSED(sub_00129D48_0x129d48) UNUSED(sub_001C12C0_0x1c12c0)
int main()try{
    events.reserve(64);std::vector<std::uint8_t> ram(0x400000);auto native=std::make_unique<save::Container>();auto state=std::make_unique<save::LiveState>();
    // Whole-container parity, high seed bits, zero-seed first word, overflow and failures.
    for(unsigned test=0;test<72;++test){
        fill(ram);std::memcpy(native->data(),ram.data()+base,save::container_bytes);
        constexpr std::array<std::uint32_t,8> seeds{0,1,0xffff,0xff53,0xff54,0x10000,0xffffffff,176};
        random_value=test<seeds.size()?seeds[test]:rng;
        draws=0;events.clear();original(sub_001C56A0_0x1c56a0,ram,base);check(draws==1);check(events==std::vector<std::uint32_t>{21});
        save::encode(*native,random_value);compare_bytes(*native,ram,base);
        if(test%4==1){ram[base]^=1;(*native)[0]^=std::byte(1);}
        if(test%4==2){ram[base+save::container_bytes-1]^=1;native->back()^=std::byte(1);}
        if(test%4==3){ram[base+4]^=1;(*native)[4]^=std::byte(1);}
        const auto expected=decode_original(ram);check(int(save::decode(*native))==expected);compare_bytes(*native,ram,base);
    }
    // Complete real original capture/restore call chain and dependency order.
    for(unsigned test=0;test<16;++test){
        fill(ram);ram[0x36f080]=test%2?0:0x91;ram[0x36f081]=0xff;
        import(*state,ram);std::memcpy(native->data(),ram.data()+base,save::container_bytes);
        fixture_write<std::uint32_t>(ram.data(),context+0xe8,base);random_value=test?0x12340000+test:0;
        draws=0;events.clear();original(sub_001C5410_0x1c5410,ram,context);const auto capture_events=events;check(draws==1);
        draws=0;events.clear();check(save::capture(*native,*state,services));check(draws==1);check(events==capture_events);compare_bytes(*native,ram,base);
        // Destination differs, including old flags observed by settings notification.
        for(unsigned i=0x310000;i<0x380000;++i){ram[i]=byte();}
        import(*state,ram);
        fixture_write<std::uint32_t>(ram.data(),context+0xec,base);
        events.clear();original(sub_001C55C0_0x1c55c0,ram,context);const auto restore_events=events;
        events.clear();const auto restored=save::restore(*native,*state,services);check(restored.original_return==0&&restored.decode==save::DecodeResult::ok);check(events==restore_events);
        compare(*state,ram);compare_bytes(*native,ram,base);
    }
    for(auto mode:{0u,1u,2u,3u,4u,5u,0xffffffffu}){
        fill(ram);import(*state,ram);fixture_write<std::uint32_t>(ram.data(),context+0x20,mode);
        original(sub_001C5630_0x1c5630,ram,context);save::clear_second_for_root_mode(*state,mode);compare(*state,ram);
    }
    // Whole restore refuses failed format/checksum before any live state or
    // settings notification, while retaining the original payload mutation.
    for(unsigned test=0;test<8;++test){
        fill(ram);import(*state,ram);std::memcpy(native->data(),ram.data()+base,save::container_bytes);
        random_value=0x98760000+test;original(sub_001C56A0_0x1c56a0,ram,base);save::encode(*native,random_value);
        const auto at=test%2?4u:0u;ram[base+at]^=1;(*native)[at]^=std::byte(1);
        fixture_write<std::uint32_t>(ram.data(),context+0xec,base);events.clear();
        check(original_result(sub_001C55C0_0x1c55c0,ram,context)==-1);check(events.empty());
        const auto result=save::restore(*native,*state,services);check(result.original_return==-1);
        check(result.decode==(test%2?save::DecodeResult::bad_checksum:save::DecodeResult::bad_magic));check(events.empty());
        compare(*state,ram);compare_bytes(*native,ram,base);
    }
    // Native admission refuses missing dependencies before changing caller buffers.
    const auto before=std::make_unique<save::Container>(*native);check(!save::capture(*native,*state,{}));check(*native==*before);
    check(save::restore(*native,*state,{}).decode==save::DecodeResult::dependency_unavailable);check(*native==*before);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"codec_cases\":72,\"full_capture_restore_cases\":16,\"failed_restore_cases\":8,\"mode_cases\":7,\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
