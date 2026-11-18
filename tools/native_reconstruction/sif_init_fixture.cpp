// Declared runtime/audio/lock/logging ports for the complete actual SDK init
// body. This is host instrumentation parity, not original PS2 IOP execution.
#include <atomic>
#include <array>
#include <chrono>
#include <cstdarg>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <map>
#include <mutex>
#include <sstream>
#include <thread>
unsigned held{},tokens{},scopes{},acquires{},scope_starts{},scope_ends{},binds{},resets{};
bool call_valid=true,call_native=true,delay_audio{},delay_lock{},delay_log{};bool reset_native{};
struct Mutex {
    std::mutex value;
    void lock(){value.lock();++held;if(delay_lock)std::this_thread::sleep_for(std::chrono::milliseconds(3));}
    bool try_lock(){if(!value.try_lock())return false;++held;return true;}
    void unlock(){--held;value.unlock();}
};
Mutex g_rpc_mutex,g_dtx_rpc_mutex;
std::map<int,int> g_rpc_servers,g_rpc_clients;
unsigned g_rpc_next_id=9,g_rpc_packet_index=8,g_rpc_server_index=7,g_rpc_active_queue=6,dtx=0xABC;
bool g_rpc_initialized=false;
struct {bool initialized=true;}g_soundDriverRpcState;
struct R5900Context {int result=99;};
struct PS2Runtime {
    uint8_t* ram{};uint8_t* bound{};
    auto& memory(){return *this;}auto& iop(){return *this;}
    uint8_t* getRDRAM(){return ram;}
    void init(uint8_t* value){++binds;bound=value;}
};
namespace ps2_cri_audio {
struct SoundCall {
    bool valid{};
    SoundCall(bool v):valid(v){if(valid)++tokens;}
    SoundCall(const SoundCall&)=delete;
    ~SoundCall(){if(valid)--tokens;}
    explicit operator bool()const{return valid;}
    bool native()const{return call_native;}
};
SoundCall acquireSoundCall(PS2Runtime*){++acquires;if(delay_audio)std::this_thread::sleep_for(std::chrono::milliseconds(3));return SoundCall(call_valid);}
struct SoundCallScope {explicit SoundCallScope(const SoundCall&){++scopes;++scope_starts;}~SoundCallScope(){--scopes;++scope_ends;}};
}
void resetDtxRpcStateUnlocked(void*,ps2_cri_audio::SoundCall* call){++resets;dtx=0;reset_native=bool(call);}
void setReturnS32(R5900Context* c,int value){c->result=value;}
std::ostringstream sink;
void log_event(){if(delay_log)std::this_thread::sleep_for(std::chrono::milliseconds(3));}
#define RUNTIME_LOG(x) do {log_event();sink<<x;}while(0)
unsigned timing_reports{},bad_report_scope{};
int probe_fprintf(FILE* stream,const char* format,...){
    ++timing_reports;if(held || tokens || scopes)++bad_report_scope;
    va_list args;va_start(args,format);const auto result=std::vfprintf(stream,format,args);va_end(args);return result;
}
#include "body.inc"
int main(int argc,char** argv){
    if(argc!=2)return 2;const std::string mode=argv[1];
    call_valid=mode!="unavailable" && mode!="refused_slow";call_native=mode!="legacy_null";
    delay_audio=mode=="delay_audio" || mode=="refused_slow";delay_lock=mode=="delay_lock";delay_log=mode=="delay_log" || mode=="disabled_delay_log";
    _putenv_s("REO_CRI_SERVER_SLOW_MS",mode=="disabled_delay_log"?"0":"1");
    std::array<uint8_t,256> ram;for(unsigned i=0;i<ram.size();++i)ram[i]=uint8_t(i*17);
    PS2Runtime runtime;runtime.ram=ram.data();R5900Context c;
    for(unsigned n=0;n<70;++n){
        g_rpc_servers[int(n)]=int(n*7);g_rpc_clients[int(n)]=int(n*11);g_soundDriverRpcState.initialized=true;
        const bool foreign=mode=="foreign" && n==0;
        ps2_syscalls::SifInitRpc(ram.data()+(foreign?1:0),&c,mode=="legacy_null"?nullptr:&runtime);
        unsigned hash=0;for(const auto byte:ram)hash=hash*33+byte;
        std::cout<<n<<','<<c.result<<','<<g_rpc_initialized<<','<<g_rpc_servers.size()<<','<<g_rpc_clients.size()<<','<<g_rpc_next_id<<','<<g_rpc_packet_index<<','<<g_rpc_server_index<<','<<g_rpc_active_queue<<','<<g_soundDriverRpcState.initialized<<','<<dtx<<','<<resets<<','<<reset_native<<','<<binds<<','<<(runtime.bound==ram.data())<<','<<acquires<<','<<scope_starts<<','<<scope_ends<<','<<tokens<<','<<held<<','<<hash<<'\n';
    }
    std::fprintf(stderr,"[FIXTURE-AUDIT] reports=%u bad_scope=%u\n",timing_reports,bad_report_scope);
    return bad_report_scope?3:0;
}
