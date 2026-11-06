#include "cpu_authority_gate.hpp"
#include <algorithm>
#include <array>
#include <atomic>
#include <chrono>
#include <cmath>
#include <cstdint>
#include <cstdio>
#include <cstring>
#include <filesystem>
#include <functional>
#include <future>
#include <iostream>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <string>
#include <thread>
#include <utility>
#include <vector>
#include "runtime/input/input.h"
using namespace reo::native::ram_capture::v2;
// Surrounding input/window/source-provider mocks. The real Pad record builder,
// dynamic registration, writer helper and stop/join bodies are extracted intact.
void reo::Input::update(){}void reo::Input::update_controllers_only(){}
using DWORD=uint32_t;using WORD=uint16_t;using HWND=void*;
HWND GetForegroundWindow(){return nullptr;}void GetWindowThreadProcessId(HWND,DWORD*){}DWORD GetCurrentProcessId(){return 1;}
struct XINPUT_VIBRATION{WORD left,right;};unsigned XInputSetState(unsigned,XINPUT_VIBRATION*){return 0;}
void reoPad2Stop();
inline bool fake_gs_success=true;
struct R5900Context{};
struct PS2Memory{
    struct HwBridgeCallbacks{void (*onDmaStart)(uint32_t,uint32_t,uint32_t,uint32_t,const uint8_t*,void*){};void (*onGsRegWrite)(uint32_t,uint64_t,void*){};void* user{};};
    uint8_t* data{};uint8_t* getRDRAM(){return data;}void setHwBridge(HwBridgeCallbacks){}
};
struct PS2Runtime {
    PS2Memory ram;PS2Memory& memory(){return ram;}
    struct IoPaths{std::filesystem::path cdRoot;};static IoPaths getIoPaths(){return {};}
    struct HwBridgeVtable{void(*onVuStart)(int,uint32_t,uint8_t*,R5900Context*,void*){};const uint32_t*(*getFramebuffer)(int*,int*,void*){};bool(*onSifRpc)(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint8_t*,void*){};void*user{};};
    void setHwBridgeVt(HwBridgeVtable){}
};
constexpr uint32_t PS2_VU0_CODE_BASE=0x11000000u,PS2_VU0_DATA_BASE=0x11004000u,PS2_VU1_CODE_BASE=0x11008000u,PS2_VU1_DATA_BASE=0x1100c000u;
constexpr uint32_t PS2_VU0_CODE_SIZE=4096,PS2_VU0_DATA_SIZE=4096,PS2_VU1_CODE_SIZE=16384,PS2_VU1_DATA_SIZE=16384;
namespace reo {
struct GSRenderer{bool init(int,int,bool,bool){return fake_gs_success;}void shutdown(){}void submit_path1(const void*,uint32_t){}};
struct VUInterpreter{VUInterpreter(int,uint8_t*,uint32_t,uint8_t*,uint32_t){}void set_xgkick_callback(void(*)(const void*,uint32_t,void*),void*){}};
struct CDVD{explicit CDVD(const std::filesystem::path&) {}};
bool Input::init(){return true;}void Input::shutdown(){}
}
struct ReoTraceLogger{static ReoTraceLogger& instance(){static ReoTraceLogger value;return value;}void init(){}void shutdown(){}};
struct ReoHwBridge {
    static ReoHwBridge* s_instance;PS2Runtime* m_runtime{};uint8_t* m_nativeRamWriterBacking{};
    std::unique_ptr<int> m_network,m_privateKeyboard,m_netProfile;
    reo::GSRenderer* m_gs{};reo::VUInterpreter* m_vu0{};reo::VUInterpreter* m_vu1{};reo::Input* m_input{};reo::CDVD* m_cdvd{};
    bool m_bridgeGfx{};unsigned long long m_gifPackets{},m_vif1Dmas{},m_vu0Runs{},m_vu1Runs{},m_gsRegWrites{};
    bool init(PS2Runtime&);void shutdown();
    static void onDmaStart(uint32_t,uint32_t,uint32_t,uint32_t,const uint8_t*,void*){}
    static void onGsRegWrite(uint32_t,uint64_t,void*){}
    static void onVuStart(int,uint32_t,uint8_t*,R5900Context*,void*){}
    static const uint32_t* getFramebuffer(int*,int*,void*){return nullptr;}
    static bool onSifRpc(uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint32_t,uint8_t*,void*){return false;}
    static ReoHwBridge* instance(){return nullptr;}reo::Input* input(){return nullptr;}
    Coordinator* nativeSoundRamWriterCoordinator(PS2Runtime&)const noexcept;
};
ReoHwBridge* ReoHwBridge::s_instance{};
constexpr uint32_t ps2RamBackingBytes=0x2000000u;uint32_t ps2RamBackingMask(){return ps2RamBackingBytes-1;}
namespace reo_parent_natural {struct OwnedSourceFailure:std::runtime_error{using std::runtime_error::runtime_error;};}
std::vector<uint8_t> ram(ps2RamBackingBytes);std::mutex bytes_mutex;std::atomic<bool> interleaved{};std::atomic<unsigned> writes{};
std::atomic<bool> pause_first_write{},write_paused{};std::promise<void> first_write,continue_write;auto write_resume=continue_write.get_future().share();
bool guestDestination(const void* p,std::size_t n){const auto at=reinterpret_cast<uintptr_t>(p),base=reinterpret_cast<uintptr_t>(ram.data());return at>=base&&at-base<ram.size()&&n<=ram.size()-(at-base);}
namespace reo_source_instrumentation {
void* copyBytes(void* dst,const void* src,std::size_t n){std::lock_guard lock(bytes_mutex);if(guestDestination(dst,n)){
    if(process_coordinator().observe(ram.data()).cpu_groups)interleaved=true;++writes;
    if(pause_first_write&&!write_paused.exchange(true)){first_write.set_value();write_resume.wait();}}
    return std::memcpy(dst,src,n);}
void* copyBytesForBank(const void*,void* dst,const void* src,std::size_t n){return copyBytes(dst,src,n);}
template<class T>struct Cell{T* p;T operator=(T value){copyBytes(p,&value,sizeof(value));return value;}};
template<class T>Cell<T> bankCell(const void*,T* p){return {p};}
}
uint16_t pad2TestRoute(uint8_t*,double){return 0;}uint16_t pad2AutomaticAccount(uint8_t*,double){return 0;}
bool pad2TestRoomSoak(uint8_t*,double,reo::DualShock2State&,uint16_t&){return false;}
bool pad2TestInteractQuit(uint8_t*,double,reo::DualShock2State&,uint16_t&){return false;}
uint16_t pad2TestWorldTarget(uint8_t*,double,reo::DualShock2State&){return 0;}
void pad2ParseScript(){}
#include "actual_pad.inc"
void check(bool x,const char* why){if(!x)throw std::runtime_error(why);}
template<class F>void until(F f){const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(3);while(!f()&&std::chrono::steady_clock::now()<end)std::this_thread::yield();check(f(),"bounded event timeout");}
uint32_t word(uint32_t at){std::lock_guard lock(bytes_mutex);uint32_t value;std::memcpy(&value,ram.data()+at,4);return value;}
void witness(){PS2Runtime runtime,foreign;runtime.ram.data=ram.data();foreign.ram.data=ram.data();ReoHwBridge bridge;
    bridge.m_runtime=&runtime;ReoHwBridge::s_instance=&bridge;
    check(!bridge.nativeSoundRamWriterCoordinator(runtime),"partially initialized bridge issued witness");
    bridge.m_nativeRamWriterBacking=ram.data();
#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
    check(bridge.nativeSoundRamWriterCoordinator(runtime)==&process_coordinator(),"wrong shared actual coordinator");
    check(!bridge.nativeSoundRamWriterCoordinator(foreign),"foreign runtime witness");runtime.ram.data=ram.data()+1;check(!bridge.nativeSoundRamWriterCoordinator(runtime),"changed backing witness");runtime.ram.data=ram.data();
#else
    check(!bridge.nativeSoundRamWriterCoordinator(runtime),"flagoff witness");
#endif
    ReoHwBridge::s_instance=nullptr;check(!bridge.nativeSoundRamWriterCoordinator(runtime),"foreign singleton witness");}
void actual_init_lifetime(){
    PS2Runtime runtime,foreign;runtime.ram.data=ram.data();foreign.ram.data=ram.data();ReoHwBridge bridge;
    check(!bridge.nativeSoundRamWriterCoordinator(runtime),"uninitialized witness");check(bridge.init(runtime),"actual init failed");
#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
    check(bridge.nativeSoundRamWriterCoordinator(runtime)==&process_coordinator(),"actual successful init did not issue witness");
#endif
    check(bridge.init(runtime),"actual double init failed");
#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
    check(bridge.nativeSoundRamWriterCoordinator(runtime)==&process_coordinator(),"actual double init invalidated witness");
#endif
    check(bridge.init(foreign)&&!bridge.nativeSoundRamWriterCoordinator(foreign),"double init adopted foreign runtime");
    bridge.shutdown();check(!bridge.nativeSoundRamWriterCoordinator(runtime),"actual shutdown retained witness");
    ReoHwBridge failed;fake_gs_success=false;check(!failed.init(runtime),"failed first init succeeded");check(!failed.nativeSoundRamWriterCoordinator(runtime),"failed init issued witness");failed.shutdown();fake_gs_success=true;
}
int main(int argc,char** argv)try{
    check(argc==2,"scenario required");const std::string mode=argv[1];witness();if(mode=="init"){actual_init_lifetime();std::cout<<"actual init lifetime passed\n";return 0;}constexpr uint32_t work=0x10000,socket=0x20000;
    if(mode=="wait"){
        pause_first_write=true;pad2SetWorkAddr(ram.data(),work);pad2RegisterSocket(ram.data(),socket,1);first_write.get_future().wait();
        std::mutex guest,rpc;auto reader=std::async(std::launch::async,[&]{std::scoped_lock caller_locks(guest,rpc);auto group=process_coordinator().wait_cpu_group(ram.data());
            if(!group.value)throw std::runtime_error("normal Pad wait refused");return word(work);});
        until([&]{return process_coordinator().observe(ram.data()).readers_waiting==1;});check(process_coordinator().observe(ram.data()).cpu_groups==0,"waiting reader held group");
        g_pad2.stop=true;continue_write.set_value();check(reader.get()==1,"wait copied before complete Pad batch");reoPad2Stop();
        check(!interleaved&&process_coordinator().observe(ram.data()).cpu_groups==0,"wait/read retirement");
    }else if(mode=="oversized"){
        auto held=process_coordinator().try_cpu_group(ram.data());check(bool(held.value),"held socket bound copy");
        // Pause automatic thread start until ALL source registrations exist.
        g_pad2.started=true;pad2SetWorkAddr(ram.data(),work);
        for(unsigned i=0;i<65;++i)pad2RegisterSocket(ram.data(),socket+i*0x100,1);
        g_pad2.thread=std::thread(pad2FeederLoop);
        until([&]{return process_coordinator().observe(ram.data()).cpu_capture_disabled;});check(writes==0,"socket overflow overtook admitted copy");
        held.value.release();until([&]{return word(socket+64*0x100+0x7c)>0;});reoPad2Stop();
        check(word(work)==1&&word(socket+64*0x100+0x7c)>0,"socket overflow truncated input");
        check(process_coordinator().try_cpu_group(ram.data()).status==Status::unavailable,"socket overflow did not withdraw capture");
    }else if(mode=="withdraw"){
        std::array<int,maximum_backings> other{};auto held=process_coordinator().try_cpu_group(&other[0]);check(bool(held.value),"held metadata copy");
        for(std::size_t i=1;i<other.size();++i){auto p=process_coordinator().try_cpu_group(&other[i]);check(bool(p.value),"fill metadata");}
        // Even capture exhaustion must not stop/drop the actual input thread.
        pad2SetWorkAddr(ram.data(),work);pad2RegisterSocket(ram.data(),socket,1);
        until([&]{return process_coordinator().observe(other.data()).cpu_capture_disabled;});
        check(writes==0&&word(work)==0,"Pad capacity path overtook admitted copy");held.value.release();
        until([&]{return word(work)==1;});reoPad2Stop();
        check(writes>0&&process_coordinator().observe(ram.data()).cpu_capture_disabled,"input/capture withdrawal");
        check(process_coordinator().try_cpu_group(ram.data()).status==Status::unavailable,"capture resumed after withdrawal");
    }else{
#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
        auto group=process_coordinator().try_cpu_group(ram.data());check(bool(group.value),"copy admission");
#endif
        pad2SetWorkAddr(ram.data(),work);check(pad2RegisterSocket(ram.data(),socket,1)==0,"socket id");
#if REO_BUILD_NATIVE_SOUND_RAM_CAPTURE >= 2
        until([&]{return process_coordinator().observe(ram.data()).writers_waiting!=0||interleaved.load();});
        const bool protected_copy=!interleaved&&writes==0&&word(work)==0;g_pad2.stop=true;group.value.release();reoPad2Stop();
        check(protected_copy,"actual Pad writer interleaved with admitted copy");
#else
        until([&]{return writes.load()!=0;});reoPad2Stop();
#endif
        check(word(work)==1&&word(socket+0x7c)>0,"actual final Pad batch/stop join");
        check(!g_pad2.thread.joinable(),"actual feeder thread outlived stop");
    }
    check(ram[socket]==1&&ram[socket+0x1e]==128&&ram[socket+0x21]==128,"Pad state changed");
    std::cout<<"actual Pad "<<mode<<" passed, writes="<<writes<<'\n';return 0;
}catch(const std::exception& e){g_pad2.stop=true;try{continue_write.set_value();}catch(const std::future_error&){}if(g_pad2.thread.joinable())g_pad2.thread.join();std::cerr<<e.what()<<'\n';return 1;}
