#include "runtime_observer.h"
#include "handle_profile.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include <windows.h>
#include <array>
#include <atomic>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <filesystem>
#include <memory>
#include <mutex>
#include <sstream>
#include <vector>

#if !defined(PS2_RUNTIME_HAS_EXTERNAL_WORKERS) || !PS2_RUNTIME_HAS_EXTERNAL_WORKERS
#error Original ADXT observation requires the audited external-worker runtime API
#endif
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;
#define X(address,name,record) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "observer_entries.inc"
#undef X

namespace reo::native::adxt_binding {
namespace {
using Function=PS2Runtime::RecompiledFunction;
constexpr std::size_t entry_count=0
#define X(address,name,record) +1
#include "observer_entries.inc"
#undef X
;
constexpr std::size_t capacity=65536;
struct Arguments {std::array<std::uint32_t,6> values;std::uint32_t pc{},ra{},sp{};};
struct Event {
    std::uint64_t qpc{};std::uint32_t entry{},stage{},thread{},tick{},handle{},result{},result2{},pc{},admission{};
    Arguments arguments;
    std::array<std::uint8_t,0xc4> adxt{};
    std::array<std::uint8_t,0x9c> decoder{};
    std::array<std::uint8_t,0x5c> file{};
    std::array<std::uint8_t,0x60> rna{};
    std::array<std::uint8_t,256> path{};
};
class Trace;
std::shared_ptr<Trace> installed;
std::mutex installed_mutex;
std::shared_ptr<Trace> current_trace(){std::lock_guard lock(installed_mutex);return installed;}
template<std::uint32_t Address,Function Original,bool Record>
void dispatch(std::uint8_t*,R5900Context*,PS2Runtime*);
struct Entry {std::uint32_t address;Function original,wrapper;};
const std::array<Entry,entry_count> entries{{
#define X(address,name,record) {address,name,dispatch<address,name,record>},
#include "observer_entries.inc"
#undef X
}};
constexpr reo_native_image_identity::Digest digest(const char (&value)[65]) {
    reo_native_image_identity::Digest result{};const auto nibble=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(std::size_t i=0;i<result.size();++i)result[i]=std::uint8_t(nibble(value[2*i])*16+nibble(value[2*i+1]));
    return result;
}
bool image(const std::uint8_t* ram)noexcept {
    return ram && reo_native_image_identity::sha256(ram+0x12a658,0x308)==digest("77fb81fa81b4ce75251107a09cadb1041516f1722afb167fce07aadfea425610") &&
        reo_native_image_identity::sha256(ram+0x1315e0,0x373c)==digest("f1edb1cfb980358f350913e82a81cbd8bbc875b26269c11d779065a9e8f25646");
}
std::uint64_t now()noexcept{LARGE_INTEGER value{};QueryPerformanceCounter(&value);return std::uint64_t(value.QuadPart);}
template<class T>T load(const std::uint8_t* ram,std::uint32_t at)noexcept{T result;std::memcpy(&result,ram+at,sizeof(result));return result;}
template<std::size_t N>void child(const std::uint8_t* ram,std::uint32_t at,Pool pool,std::array<std::uint8_t,N>& out)noexcept{
    std::uint32_t slot{};if(detail::slot(pool,at,slot))std::memcpy(out.data(),ram+at,N);
}
std::string hex(std::span<const std::uint8_t> bytes){
    constexpr char digits[]="0123456789abcdef";std::string result(bytes.size()*2,'0');
    for(std::size_t i=0;i<bytes.size();++i){result[2*i]=digits[bytes[i]>>4];result[2*i+1]=digits[bytes[i]&15];}return result;
}
class Trace final:public PS2Runtime::ExternalWorker {
public:
    PS2Runtime* const runtime;std::uint8_t* const ram;
    Trace(PS2Runtime& r,std::uint8_t* memory,HANDLE output):runtime(&r),ram(memory),output_(output),events_(capacity){
        LARGE_INTEGER frequency{};QueryPerformanceFrequency(&frequency);frequency_=std::uint64_t(frequency.QuadPart);
    }
    ~Trace()override{if(output_!=INVALID_HANDLE_VALUE)CloseHandle(output_);}
    void requestStop()noexcept override{stopping_.store(true,std::memory_order_release);}
    bool join()noexcept override{
        requestStop();std::lock_guard lock(mutex_);if(joined_)return true;
        bool ok=true;
        try{
            std::ostringstream head;head<<"{\"schema\":1,\"mode\":\"original ABI observation\",\"qpc_frequency\":"<<frequency_<<",\"capacity\":"<<capacity<<",\"events\":"<<size_<<",\"dropped\":"<<dropped_<<",\"native_sources_selected\":false}\n";ok=write(head.str());
            for(std::size_t i=0;i<entries.size() && ok;++i){std::ostringstream line;line<<"{\"entry\":"<<entries[i].address<<",\"calls\":"<<calls_[i]<<"}\n";ok=write(line.str());}
            for(std::size_t i=0;i<size_ && ok;++i){const auto& e=events_[i];std::ostringstream line;
                line<<"{\"entry\":"<<e.entry<<",\"stage\":"<<e.stage<<",\"qpc\":"<<e.qpc<<",\"thread\":"<<e.thread<<",\"tick\":"<<e.tick<<",\"handle\":"<<e.handle<<",\"pc\":"<<e.pc<<",\"v0\":"<<e.result<<",\"v1\":"<<e.result2<<",\"handle_status\":"<<e.admission<<",\"call_pc\":"<<e.arguments.pc<<",\"ra\":"<<e.arguments.ra<<",\"sp\":"<<e.arguments.sp<<",\"args\":[";
                for(unsigned j=0;j<e.arguments.values.size();++j){if(j)line<<',';line<<e.arguments.values[j];}
                line<<"],\"adxt\":\""<<hex(e.adxt)<<"\",\"decoder\":\""<<hex(e.decoder)<<"\",\"file\":\""<<hex(e.file)<<"\",\"rna\":\""<<hex(e.rna)<<"\",\"path\":\""<<hex(e.path)<<"\"}\n";ok=write(line.str());
            }
            if(ok)ok=write("{\"capture_closed\":true,\"export_complete\":true}\n");
        }catch(...){ok=false;}
        if(ok)ok=FlushFileBuffers(output_)!=0;
        CloseHandle(output_);output_=INVALID_HANDLE_VALUE;joined_=true;
        std::fprintf(stderr,"[ADXT-OBSERVE] capture_closed events=%zu dropped=%llu exported=%u; original calls preserved\n",size_,static_cast<unsigned long long>(dropped_),unsigned(ok));
        // Export failure is a diagnostics failure. No source/device worker is
        // owned here, and it must not make runtime shutdown retry forever.
        return true;
    }
    bool belongs(PS2Runtime* r,const std::uint8_t* memory)const noexcept{return r==runtime && memory==ram && !stopping_.load(std::memory_order_acquire);}
    void capture(std::uint32_t entry,bool record,bool after,const Arguments& args,const R5900Context& context)noexcept{
        if(stopping_.load(std::memory_order_acquire))return;
        std::lock_guard lock(mutex_);if(stopping_.load(std::memory_order_acquire))return;
        std::size_t index=0;while(index<entries.size() && entries[index].address!=entry)++index;if(index==entries.size())return;
        if(!after && calls_[index]!=UINT64_MAX)++calls_[index];
        if(record){const auto address=entry==0x1315e0 && after && context.pc==args.ra?GPR_U32((&context),2):args.values[0];append(entry,after?1:0,args,context,address);}
        if(after && entry==0x132c08){
            for(unsigned i=0;i<handles.count;++i){const auto at=handles.base+handles.stride*i;
                // Observe actual status changes and a bounded periodic sample.
                // No decoder service, source poll or callback is introduced.
                const auto state=std::uint64_t(load<std::uint32_t>(ram,at)) |
                    std::uint64_t(ram[at+0x71])<<32 | std::uint64_t(ram[at+0xac])<<40 |
                    std::uint64_t(load<std::uint16_t>(ram,at+0x60))<<48;
                if(state!=previous_[i] || (ram[at]==1 && (calls_[index]&255)==1))append(entry,2,args,context,at);
                previous_[i]=state;
            }
        }
    }
private:
    HANDLE output_;std::vector<Event> events_;std::size_t size_{};std::uint64_t dropped_{},frequency_{};
    std::array<std::uint64_t,entry_count> calls_{};std::array<std::uint64_t,16> previous_{};
    std::atomic<bool> stopping_{};std::mutex mutex_;bool joined_{};
    bool write(const std::string& text)noexcept{
        DWORD done{};return text.size()<=MAXDWORD && WriteFile(output_,text.data(),DWORD(text.size()),&done,nullptr) && done==text.size();
    }
    void append(std::uint32_t entry,std::uint32_t stage,const Arguments& args,const R5900Context& c,std::uint32_t at)noexcept{
        if(size_==events_.size()){if(dropped_!=UINT64_MAX)++dropped_;return;}
        auto& e=events_[size_++];e.qpc=now();e.entry=entry;e.stage=stage;e.arguments=args;e.pc=c.pc;
        e.thread=GetCurrentThreadId();e.tick=load<std::uint32_t>(ram,0x20f3c4);e.result=GPR_U32((&c),2);e.result2=GPR_U32((&c),3);e.handle=at;
        e.admission=unsigned(inspect_handle({ram,ram_bytes},at).status);std::uint32_t slot{};
        if(!detail::slot(handles,at,slot))return;
        std::memcpy(e.adxt.data(),ram+at,e.adxt.size());
        if(ram[at]!=1)return;
        child(ram,load<std::uint32_t>(ram,at+4),decoders,e.decoder);child(ram,load<std::uint32_t>(ram,at+8),files,e.file);child(ram,load<std::uint32_t>(ram,at+12),rnas,e.rna);
        // Pending/started file sources own this bounded filename pointer. Do
        // not read constructor scratch or arbitrary pre-source workarea bytes.
        if(ram[at+0xac]==1 || ram[at+1]!=0){const auto path=load<std::uint32_t>(ram,at+0xb4);
            if(path && path<=ram_bytes-e.path.size())for(std::size_t i=0;i<e.path.size();++i){e.path[i]=ram[path+i];if(!e.path[i])break;}}
    }
};
template<std::uint32_t Address,Function Original,bool Record>
void dispatch(std::uint8_t* ram,R5900Context* context,PS2Runtime* runtime){
    const auto trace=current_trace();
    const bool capture=trace && context && trace->belongs(runtime,ram) && ps2ActualGuestExecutionDepth(runtime)!=0;
    Arguments args{};
    if(capture){for(unsigned i=0;i<args.values.size();++i)args.values[i]=GPR_U32(context,4+i);args.pc=context->pc;args.ra=GPR_U32(context,31);args.sp=GPR_U32(context,29);trace->capture(Address,Record,false,args,*context);}
    // Invoke the exact admitted original body, preserving all guest context,
    // callbacks, resume PCs, queue operations and return behavior.
    Original(ram,context,runtime);
    if(capture)trace->capture(Address,Record,true,args,*context);
}
}
bool observe_before_run(PS2Runtime& runtime)noexcept{
    const auto* path=std::getenv("REO_ADXT_OBSERVE_PATH");if(!path || !*path)return false;
    HANDLE output=INVALID_HANDLE_VALUE;
    try{
        auto setup=runtime.acquirePreRunSetup();if(!setup)return false;
        auto* ram=runtime.memory().getRDRAM();if(!image(ram))return false;
        const auto old=current_trace();if(old && old->belongs(&runtime,ram))return false;
        for(const auto& entry:entries)if(!runtime.hasFunction(entry.address) || runtime.lookupFunction(entry.address)!=entry.original)return false;
        const std::filesystem::path destination(std::u8string(path,path+std::strlen(path)));if(!destination.is_absolute())return false;
        output=CreateFileW(destination.c_str(),GENERIC_WRITE,FILE_SHARE_READ,nullptr,CREATE_NEW,FILE_ATTRIBUTE_NORMAL,nullptr);
        if(output==INVALID_HANDLE_VALUE)return false;
        auto trace=std::make_shared<Trace>(runtime,ram,output);output=INVALID_HANDLE_VALUE;
        if(!runtime.registerExternalWorker(trace))return false;
        {std::lock_guard lock(installed_mutex);installed=trace;}
        std::size_t changed{};
        try{for(const auto& entry:entries){runtime.registerFunction(entry.address,entry.wrapper);++changed;}}
        catch(...){trace->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,entries[i].original);(void)trace->join();return false;}
        std::fprintf(stderr,"[ADXT-OBSERVE] installed entries=%zu capacity=%zu mode=original; bounded evidence exports after capture closes\n",entry_count,capacity);return true;
    }catch(...){if(output!=INVALID_HANDLE_VALUE)CloseHandle(output);return false;}
}
} // namespace reo::native::adxt_binding
