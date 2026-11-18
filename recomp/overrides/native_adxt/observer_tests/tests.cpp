// Declared runtime and original-call ports. No original body is executed here.
#include "ps2_runtime.h"
#include "../runtime_observer.h"
#include "../handle_profile.h"
#include <windows.h>
#include <algorithm>
#include <atomic>
#include <chrono>
#include <cstring>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <thread>

namespace b=reo::native::adxt_binding;
unsigned checks{};thread_local std::uint32_t depth{1};
std::atomic<bool> block_call{},entered{},released{};
bool yield_call{},nested{};
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept{return depth;}
void check(bool value){++checks;if(!value)throw std::runtime_error("Observer check "+std::to_string(checks));}
template<class T>void store(std::uint8_t* ram,std::uint32_t at,T value){std::memcpy(ram+at,&value,sizeof(value));}
struct Memory {
    std::uint8_t* bytes=static_cast<std::uint8_t*>(VirtualAlloc(nullptr,b::ram_bytes,MEM_RESERVE|MEM_COMMIT,PAGE_READWRITE));
    ~Memory(){if(bytes)VirtualFree(bytes,0,MEM_RELEASE);}
    void protect(DWORD mode){DWORD prior{};check(VirtualProtect(bytes,b::ram_bytes,mode,&prior)!=0);}
};
void load_elf(Memory& memory,const char* path){
    check(memory.bytes!=nullptr);std::ifstream file(path,std::ios::binary|std::ios::ate);check(bool(file));
    std::vector<char> data(std::size_t(file.tellg()));file.seekg(0);file.read(data.data(),std::streamsize(data.size()));check(bool(file));
    const auto word=[&](std::size_t at){std::uint32_t v{};check(at+4<=data.size());std::memcpy(&v,data.data()+at,4);return v;};
    const auto half=[&](std::size_t at){std::uint16_t v{};check(at+2<=data.size());std::memcpy(&v,data.data()+at,2);return v;};
    const auto table=word(28);const auto stride=half(42),count=half(44);
    for(unsigned i=0;i<count;++i){const auto at=table+i*stride;if(word(at)!=1)continue;const auto offset=word(at+4),address=word(at+8),size=word(at+16);check(address<=b::ram_bytes && size<=b::ram_bytes-address && offset<=data.size() && size<=data.size()-offset);std::memcpy(memory.bytes+address,data.data()+offset,size);}
}
void construct(std::uint8_t* ram){
    const auto a=b::handles.base,d=b::decoders.base,f=b::files.base+39*b::files.stride,r=b::rnas.base,t=b::transfers.base,p=b::paired.base;
    ram[a]=1;ram[a+3]=1;store(ram,a+4,d);store(ram,a+8,f);store(ram,a+12,r);store(ram,a+16,0x300000u);store(ram,a+0x18,0x310000u);
    ram[d]=1;ram[d+2]=1;store(ram,d+8,0x300000u);store(ram,d+12,0x310000u);ram[f]=1;store(ram,f+4,0x300000u);
    ram[r]=1;store(ram,r+4,1u);store(ram,r+8,p);store(ram,r+0x10,t);store(ram,r+0x18,0x310000u);store(ram,r+0x20,0x1e0000u);
    ram[t]=1;store(ram,t+4,0x310000u);store(ram,t+8,0x320000u);ram[p]=1;store(ram,p+8,0x320000u);store(ram,0x221438,1u);
    store(ram,a+0xb4,0x330000u);std::memcpy(ram+0x330000,"NETBIO01.DAT",13);ram[a+0xac]=1;
}
void original(std::uint32_t address,std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime){
    if(address==0x1315e0)construct(ram);
    if(address==0x1328b8)store(ram,b::handles.base+0x38,std::uint32_t(c->r[5][0]));
    if(address==0x132c08)ram[b::handles.base+1]=3;
    if(address==0x131e38 && nested){R5900Context inner{};inner.pc=0x131ef8;inner.r[31][0]=0x100000;inner.r[4][0]=b::handles.base;runtime->lookupFunction(0x131ef8)(ram,&inner,runtime);}
    if(address==0x131918)std::memset(ram+b::handles.base,0,0xc4);
    if(address==0x132458 && block_call.load()){entered.store(true);while(!released.load())std::this_thread::yield();}
    c->r[2][0]=address==0x1315e0?b::handles.base:address^std::uint32_t(c->r[4][0]);c->r[2][1]=0xfedcba9876543210ull;
    c->r[3][0]=0xf0000000u|address;c->r[9][1]=0x123456789abcdef0ull;c->hi=0xdeadbeef;c->lo=0xcafef00d;
    c->pc=yield_call?0x1334ec:std::uint32_t(c->r[31][0]);
}
#define X(address,name,record) void name(std::uint8_t* r,R5900Context* c,PS2Runtime* p){original(address,r,c,p);}
#include "../observer_entries.inc"
#undef X
struct Entry {std::uint32_t address;PS2Runtime::RecompiledFunction fn;};
const Entry entries[]={
#define X(address,name,record) {address,name},
#include "../observer_entries.inc"
#undef X
};
void configure(PS2Runtime& runtime,Memory& memory){runtime.storage.ram=memory.bytes;for(const auto& entry:entries)runtime.registerFunction(entry.address,entry.fn);}
R5900Context context(std::uint32_t pc){R5900Context c{};for(unsigned i=1;i<32;++i)c.r[i]={0x1234000000000000ull+i,0xfedcba9876543210ull+i};c.r[4][0]=b::handles.base;c.r[5][0]=30;c.r[29][0]=0x1ff0000;c.r[31][0]=0x100008;c.pc=pc;return c;}
void path(const std::filesystem::path& p){check(_putenv_s("REO_ADXT_OBSERVE_PATH",p.string().c_str())==0);}
int main(int argc,char** argv)try{
    check(argc==4);Memory memory,expected;load_elf(memory,argv[1]);std::memcpy(expected.bytes,memory.bytes,b::ram_bytes);
    PS2Runtime runtime;configure(runtime,memory);const std::filesystem::path folder(argv[2]);const std::string mode(argv[3]);
    if(mode=="admission"){
        check(_putenv_s("REO_ADXT_OBSERVE_PATH","")==0);check(!b::observe_before_run(runtime) && runtime.workers.empty());
        path(folder/"late.jsonl");runtime.phase_open=false;check(!b::observe_before_run(runtime));runtime.phase_open=true;
        path(folder/"image.jsonl");memory.bytes[0x1315e0]^=1;check(!b::observe_before_run(runtime));memory.bytes[0x1315e0]^=1;
        path(folder/"binding.jsonl");runtime.registerFunction(0x131ef8,sub_00131F60_0x131f60);check(!b::observe_before_run(runtime));runtime.registerFunction(0x131ef8,sub_00131EF8_0x131ef8);
        const auto existing=folder/"existing.jsonl";{std::ofstream f(existing);f<<"keep";}path(existing);check(!b::observe_before_run(runtime));std::ifstream f(existing);std::string value;f>>value;check(value=="keep" && runtime.workers.empty());
        path(folder/"publication.jsonl");runtime.worker_allowed=false;check(!b::observe_before_run(runtime) && runtime.workers.empty());
        for(const auto& entry:entries)check(runtime.lookupFunction(entry.address)==entry.fn);
    }else{
        path(folder/(mode+".jsonl"));check(b::observe_before_run(runtime) && runtime.workers.size()==1);construct(memory.bytes);
        if(mode=="transparent"){
            nested=true;
            for(const auto& entry:entries){construct(memory.bytes);std::memcpy(expected.bytes,memory.bytes,b::ram_bytes);auto actual=context(entry.address);if(entry.address==0x1315e0)actual.r[4][0]=1;auto wanted=actual;entry.fn(expected.bytes,&wanted,&runtime);runtime.lookupFunction(entry.address)(memory.bytes,&actual,&runtime);check(!std::memcmp(&actual,&wanted,sizeof(actual)) && !std::memcmp(memory.bytes,expected.bytes,b::ram_bytes));}
            yield_call=true;auto c=context(0x133490);runtime.lookupFunction(c.pc)(memory.bytes,&c,&runtime);check(c.pc==0x1334ec);yield_call=false;
            depth=0;c=context(0x1328b8);runtime.lookupFunction(c.pc)(memory.bytes,&c,&runtime);depth=1;
            check(runtime.workers[0]->join() && runtime.workers[0]->join());
            // Captured bytes survive inaccessible target RAM. Late calls are
            // delegated but cannot observe RAM after the capture fence.
            memory.protect(PAGE_NOACCESS);check(runtime.workers[0]->join());memory.protect(PAGE_READWRITE);
        }else if(mode=="blocked"){
            block_call.store(true);auto c=context(0x132458);std::thread call([&]{runtime.lookupFunction(c.pc)(memory.bytes,&c,&runtime);});
            const auto deadline=std::chrono::steady_clock::now()+std::chrono::seconds(10);while(!entered.load()){check(std::chrono::steady_clock::now()<deadline);std::this_thread::yield();}
            runtime.workers[0]->requestStop();memory.protect(PAGE_NOACCESS);check(runtime.workers[0]->join());released.store(true);call.join();check(c.pc==0x100008);memory.protect(PAGE_READWRITE);
        }else if(mode=="overflow"){
            auto c=context(0x1328b8);for(unsigned i=0;i<40000;++i){c.pc=0x1328b8;runtime.lookupFunction(c.pc)(memory.bytes,&c,&runtime);}check(runtime.workers[0]->join());
        }else throw std::runtime_error("Unknown mode");
    }
    std::cout<<"original-call observer "<<mode<<" checks="<<checks<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
