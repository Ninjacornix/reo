#include "fixture.hpp"
#include "original_declarations.inc"
#include "recomp/overrides/native_gameplay/save_session.hpp"
#include "game/native/gameplay_save/snapshot.hpp"
#include "source_instruction_access.hpp"
#include <chrono>
#include <fstream>
#include <iostream>
#include <thread>
#include <string>
#include <io.h>
using namespace reo::native;
namespace binding=native_gameplay;
static unsigned checks{},comparisons{};static std::vector<std::uint8_t> admission;
static std::atomic<bool> hold_provider{},provider_entered{};
static void require(bool v,const char* s){++checks;if(!v)throw std::runtime_error(s);}
std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime* rt)noexcept{return rt?rt->depth.load():0;}
#define X(at,name,kind) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "recomp/overrides/native_gameplay/entries.inc"
#undef X
#define P(at,name,back,depth) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "recomp/overrides/native_gameplay/providers.inc"
#undef P
struct Entry {std::uint32_t at;PS2Runtime::RecompiledFunction original;};
static const Entry entries[]={
#define X(at,name,kind) {at,&name},
#include "recomp/overrides/native_gameplay/entries.inc"
#undef X
};
static const Entry providers[]={
#define P(at,name,back,depth) {at,&name},
#include "recomp/overrides/native_gameplay/providers.inc"
#undef P
};
static void provider(std::uint32_t at,std::uint8_t* ram,R5900Context* ctx,PS2Runtime* rt){
 rt->events.push_back(at);rt->events.push_back(GPR_U32(ctx,4));if(at==0x1af790)rt->events.push_back(GPR_U32(ctx,5));rt->events.push_back(GPR_U32(ctx,29));rt->events.push_back(GPR_U32(ctx,31));
 ++rt->provider_count;const auto back=GPR_U32(ctx,31);
 if(rt->provider_throw)throw std::runtime_error("Declared provider failed");
 if(rt->reenter)rt->lookupFunction(0x1aec80)(ram,ctx,rt);
 if(hold_provider.load()){provider_entered=true;while(hold_provider.load())std::this_thread::yield();ctx->pc=back;return;}
 if(at==0x1bf660){
  const auto h=GPR_U32(ctx,4)&0x1fffffffu;for(unsigned i=0;i<8;++i)ram[h+i]=std::uint8_t(41+i);
  if(rt->provider_mutation){ram[0x3241a0]=3;ram[0x31fb60]=55;ram[0x324488]=44;}
 }else if(at==0x1b8290){if(rt->provider_mutation)ram[0x3241af]=202;}
 else if(at==0x1af790){
  // Every live option has already been published before the first observer.
  for(const auto& [live,saved]:std::array<std::pair<std::uint32_t,unsigned>,8>{{{0x3243c5,0},{0x3243c9,1},{0x3243ca,2},{0x3243ec,3},{0x3243ef,4},{0x3243f0,5},{0x3243ed,6},{0x3243ee,7}}})
   require(ram[live]==ram[0x3241a0+saved],"All options precede first observer");
  if(rt->provider_mutation){
   ram[0x3243c5]=11;ram[0x3243ca]=5;ram[0x3243c9]=6;ram[0x324476]=199;ram[0x3165a8]=207;
   if(rt->active_container){ram[rt->active_container+8+0x18]=77;ram[rt->active_container+0x108]=88;ram[rt->active_container+0x108+0x37bc0]=0;}
  }
 }else if(rt->provider_mutation&&at==0x1b86c0)ram[0x3243ca]=3;
 else if(rt->provider_mutation&&at==0x1b86f0)ram[0x3243c9]=4;
 else if(rt->provider_mutation&&at==0x1b8780)ram[0x3243f0]=155;
 // Deliberately clobber volatile registers. The original callee ABI permits
 // these changes; the adapter saves/restores the actual context around them.
 for(unsigned n=2;n<16;++n)SET_GPR_U64(ctx,n,0xaabb0000+n);
 ctx->pc=rt->bad_return?back+4:back;
}
#define P(at,name,back,depth) void name(std::uint8_t* r,R5900Context* c,PS2Runtime* rt){provider(at,r,c,rt);}
#include "recomp/overrides/native_gameplay/providers.inc"
#undef P
void sub_00107AB0_0x107ab0(std::uint8_t* r,R5900Context* c,PS2Runtime*){
 const auto dst=GPR_U32(c,4),src=GPR_U32(c,5),n=GPR_U32(c,6);if(dst>0x2000000-n||src>0x2000000-n)throw std::runtime_error("Original copy bound");std::memcpy(r+dst,r+src,n);c->pc=GPR_U32(c,31);
}
void sub_00107C68_0x107c68(std::uint8_t* r,R5900Context* c,PS2Runtime*){
 const auto dst=GPR_U32(c,4),n=GPR_U32(c,6);if(dst>0x2000000-n)throw std::runtime_error("Original fill bound");std::memset(r+dst,int(GPR_U32(c,5)),n);c->pc=GPR_U32(c,31);
}
struct Case {
 std::vector<std::uint8_t> ram;PS2Runtime rt;R5900Context ctx;
 explicit Case(unsigned seed=1):ram(admission){
  std::uint32_t v=seed;for(unsigned i=0x300000;i<0x500100;++i){v=v*1664525u+1013904223u;ram[i]=std::uint8_t(v>>24);}
  rt.storage.ram=ram.data();for(const auto& e:entries)rt.functions[e.at]=e.original;for(const auto& e:providers)rt.functions[e.at]=e.original;
  for(unsigned i=1;i<32;++i){ctx.gpr[i].words[0]=0x44000000+i;ctx.gpr[i].words[1]=0x8877665544332200ull+i;}
  ctx.pc=0x1c5410;SET_GPR_U32(&ctx,29,0x1f00000);SET_GPR_U32(&ctx,31,0x1c4ab8);SET_GPR_U32(&ctx,4,0x500000);
  put(0x5000e8,0x400000u);put(0x5000ec,0x480000u);put(0x500020,0u);
 }
 template<class T>void put(std::uint32_t at,T v){std::memcpy(ram.data()+at,&v,sizeof(v));}
 bool install(){return binding::install_save_session_before_run(rt,true).status==binding::InstallStatus::installed;}
 void call(unsigned index){ctx.pc=entries[index].at;rt.lookupFunction(entries[index].at)(ram.data(),&ctx,&rt);}
 ~Case(){rt.requestStop();rt.join();}
};
static void compare(Case& original,Case& native,unsigned entry,bool result=false){
 original.call(entry);native.call(entry);++comparisons;
 for(unsigned i=0;i<0x1efff00;++i)if(original.ram[i]!=native.ram[i]){
  std::cerr<<"entry "<<entry<<" RAM mismatch at "<<std::hex<<i<<": "<<unsigned(original.ram[i])<<" vs "<<unsigned(native.ram[i])<<"; original events ";for(auto e:original.rt.events)std::cerr<<e<<',';std::cerr<<" native ";for(auto e:native.rt.events)std::cerr<<e<<',';std::cerr<<std::dec<<'\n';break;
 }
 // Dead stack-frame bytes and volatile register residue are not observable
 // entry results. Everything else in the 32MiB RAM image must match exactly.
 require(std::memcmp(original.ram.data(),native.ram.data(),0x1efff00)==0,"Original/native RAM before dead stack");
 require(std::memcmp(original.ram.data()+0x1f00000,native.ram.data()+0x1f00000,0x100000)==0,"Original/native RAM after dead stack");
 require(original.rt.events==native.rt.events,"Original/native observer order and values");
 require(original.ctx.pc==native.ctx.pc,"Original/native return PC");if(result)require(GPR_U64(&original.ctx,2)==GPR_U64(&native.ctx,2),"Original/native return value");
}
template<class F>static void rejected(F&& f){bool threw=false;try{f();}catch(const std::exception&){threw=true;}require(threw,"Visible refusal required");}
static void equivalent_entries(){
 for(unsigned seed=1;seed<=8;++seed){
  for(unsigned index=3;index<9;++index){Case a(seed),b(seed);require(b.install(),"install session");a.rt.provider_mutation=b.rt.provider_mutation=true;if(index==4)SET_GPR_U32(&a.ctx,4,seed%5),SET_GPR_U32(&b.ctx,4,seed%5);compare(a,b,index,index==4);}
  for(unsigned mode=0;mode<4;++mode){Case a(seed),b(seed);require(b.install(),"install clear");a.put(0x500020,mode);b.put(0x500020,mode);compare(a,b,2);}
  Case a(seed),b(seed);require(b.install(),"install capture");a.rt.provider_mutation=b.rt.provider_mutation=true;compare(a,b,0);
  require(b.ram[0x480000]!=b.ram[0x400000]||std::memcmp(b.ram.data()+0x480000,b.ram.data()+0x400000,32)!=0,"Capture uses E8 not EC");
  // Restore from the captured encoded E8 data, through the DIFFERENT EC field.
  std::memcpy(a.ram.data()+0x480000,a.ram.data()+0x400000,gameplay_save::container_bytes);std::memcpy(b.ram.data()+0x480000,b.ram.data()+0x400000,gameplay_save::container_bytes);
  a.rt.active_container=b.rt.active_container=0x480000;a.rt.events.clear();b.rt.events.clear();SET_GPR_U32(&a.ctx,4,0x500000);SET_GPR_U32(&b.ctx,4,0x500000);compare(a,b,1,true);
  require(b.ram[0x324476]==77&&b.ram[0x31fb60]==88,"Observer container changes survive restore");require(b.ram[0x3165a8]==207,"Zero-tail condition retains observer change");
 }
 // Bad magic is unchanged; bad checksum decodes full payload but never notifies.
 for(unsigned kind=0;kind<2;++kind){Case a(19),b(19);require(b.install(),"install invalid restore");gameplay_save::Container c{};for(unsigned i=0;i<c.size();++i)c[i]=std::byte(i*19);gameplay_save::encode(c,4321);if(kind==0)c[0]=std::byte{};else c[4]^=std::byte{1};std::memcpy(a.ram.data()+0x480000,c.data(),c.size());std::memcpy(b.ram.data()+0x480000,c.data(),c.size());compare(a,b,1,true);require(b.rt.provider_count==0,"Bad decode never notifies");}
}
static void admission_cases(){
 {Case c;const auto f=c.rt.functions;require(binding::install_save_session_before_run(c.rt,false).status==binding::InstallStatus::disabled,"Default disabled");require(c.rt.functions==f&&c.rt.workers.empty(),"Disabled untouched");}
 {Case c;c.rt.phase_open=false;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::phase_closed,"Late install refused");}
 {Case c;c.ram[0x1c5410]^=1;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::unsupported_image,"Wrong text refused");}
 {Case c;c.ram[0x24fe30]^=1;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::unsupported_image,"Wrong defaults refused");}
 {Case c;c.rt.functions.erase(0x1aec80);require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::registry_mismatch,"Missing original refused");}
 {Case c;c.rt.functions[0x1af790]=providers[0].original;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::registry_mismatch,"Wrong observer refused");}
 {Case c;c.rt.worker_allowed=false;const auto f=c.rt.functions;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::publication_refused,"Worker refused");require(c.rt.functions==f,"No hooks without lifetime");}
 {Case c;c.rt.fail_change=5;const auto f=c.rt.functions;require(binding::install_save_session_before_run(c.rt,true).status==binding::InstallStatus::publication_refused,"Publication failure");require(c.rt.functions==f,"Registry rolled back");}
 {Case a,b;require(a.install()&&b.install(),"Two runtimes independently installed");a.ram[0x324199]=41;b.ram[0x324199]=197;a.call(3);b.call(3);require(fixture_read<std::uint16_t>(a.ram.data(),0x3244b0)==41&&fixture_read<std::uint16_t>(b.ram.data(),0x3244b0)==197,"Independent runtime random state");}
}
static unsigned plaintext_seen{};
static void plaintext_observer(const void* memory,std::uint32_t at,std::size_t bytes){
 if(at!=0x3244b0||bytes!=2)return;
 const auto* r=static_cast<const std::uint8_t*>(memory);
 require(r[0x400008]==41&&r[0x400010]==3&&r[0x400108]==55&&r[0x400021]==44,"Plaintext and timestamp/live observer edits visible before RNG store");++plaintext_seen;
}
static void ordering_and_failures(){
 {Case a,b;require(b.install(),"plaintext setup");a.rt.provider_mutation=b.rt.provider_mutation=true;fixture_before_write=&plaintext_observer;compare(a,b,0);fixture_before_write=nullptr;require(plaintext_seen==2,"Both original and native expose plaintext at RNG step");}
 {Case a,b;require(b.install(),"shared streams setup");for(unsigned i=0;i<128;++i){
  const auto selector=i%6;SET_GPR_U32(&a.ctx,4,selector);SET_GPR_U32(&b.ctx,4,selector);
  if(i%13==0){a.put<std::uint16_t>(0x3244b0,std::uint16_t(i*19));b.put<std::uint16_t>(0x3244b0,std::uint16_t(i*19));a.put<std::uint16_t>(0x3244b8,std::uint16_t(i*23));b.put<std::uint16_t>(0x3244b8,std::uint16_t(i*23));}
  compare(a,b,4,true);
 }}
 {Case c;require(c.install(),"restore failure setup");c.rt.provider_mutation=true;c.call(0);std::memcpy(c.ram.data()+0x480000,c.ram.data()+0x400000,gameplay_save::container_bytes);c.ram[0x324476]=219;const auto first=c.ram[0x31fb60];c.rt.provider_throw=true;c.rt.provider_count=0;SET_GPR_U32(&c.ctx,4,0x500000);rejected([&]{c.call(1);});require(c.rt.provider_count==1&&c.ram[0x324476]==219&&c.ram[0x31fb60]==first,"No later flag or data export after noexcept notification failure");require(c.ram[0x480008]==41&&c.ram[0x3241a0]==3,"Decoded container and settings published before failed observer");}
 {Case c;require(c.install(),"capture failure setup");const auto seed=fixture_read<std::uint16_t>(c.ram.data(),0x3244b0);c.rt.provider_throw=true;rejected([&]{c.call(0);});require(fixture_read<std::uint16_t>(c.ram.data(),0x3244b0)==seed,"Failed timestamp never requests RNG");}
 {Case c;require(c.install(),"continuation setup");c.ctx.pc=0x1c5438;const auto before=c.ram;rejected([&]{c.rt.lookupFunction(0x1c5410)(c.ram.data(),&c.ctx,&c.rt);});require(c.ram==before,"Interior continuation never repeats native capture");}
 {Case c;require(c.install(),"bank aliases setup");c.put(0x5000e8,0xa0400000u);SET_GPR_U32(&c.ctx,4,0x80500000);c.call(0);require(fixture_read<std::uint16_t>(c.ram.data(),0x400000)==0x5963,"Accepted bank aliases resolve to same RAM");}
 {Case c;require(c.install(),"bounded diagnostic history setup");for(unsigned i=0;i<80;++i)c.call(5);require(c.rt.provider_count==80,"Trace retention never suppresses operations");}
 {Case c;require(c.install(),"diagnostic output failure setup");c.call(3);const auto ram=c.ram;const int saved=_dup(_fileno(stderr));require(saved>=0,"Retain fixture stderr descriptor");auto* readonly=std::freopen("NUL","r",stderr);require(readonly!=nullptr,"Open read-only diagnostic stream");c.rt.requestStop();const bool joined=c.rt.join();std::fflush(stderr);const bool failed=std::ferror(stderr)!=0||std::fputs("deliberate read-only diagnostic failure probe",stderr)==EOF;auto* writable=std::freopen("NUL","w",stderr);const int restored=writable?_dup2(saved,_fileno(stderr)):-1;_close(saved);std::clearerr(stderr);std::setvbuf(stderr,nullptr,_IONBF,0);require(restored==0&&failed&&joined&&c.ram==ram,"Diagnostic write failure cannot change state or prevent join");}
}
static void runtime_refusals(){
 {Case a,b;require(a.install(),"wrong runtime setup");auto f=a.rt.lookupFunction(0x1aec80);const auto before=b.ram;rejected([&]{f(b.ram.data(),&b.ctx,&b.rt);});require(b.ram==before&&b.rt.stopped,"Wrong runtime stopped before effects");}
 {Case c;require(c.install(),"stale setup");c.rt.functions[0x1af790]=providers[0].original;const auto before=c.ram;rejected([&]{c.call(0);});require(c.ram==before,"Stale provider no effects");}
 {Case c;require(c.install(),"depth setup");c.rt.depth=0;const auto before=c.ram;rejected([&]{c.call(0);});require(c.ram==before,"No guest scope no effects");}
 {Case c;require(c.install(),"ram setup");const auto before=c.ram;rejected([&]{c.rt.lookupFunction(0x1c5410)(c.ram.data()+1,&c.ctx,&c.rt);});require(c.ram==before,"Wrong RAM no effects");}
 {Case c;require(c.install(),"context bounds setup");SET_GPR_U32(&c.ctx,4,0xfffffff0);const auto before=c.ram;rejected([&]{c.call(0);});require(c.ram==before,"Context overflow no effects");}
 {Case c;require(c.install(),"container bounds setup");c.put(0x5000e8,0x1fffff0u);const auto before=c.ram;rejected([&]{c.call(0);});require(c.ram==before,"Container overflow no effects");}
 {Case c;require(c.install(),"alias setup");c.put(0x5000e8,0x31fb60u);const auto before=c.ram;rejected([&]{c.call(0);});require(c.ram==before,"Aliased projection refused");}
 {Case c;require(c.install(),"joined setup");auto f=c.rt.lookupFunction(0x1aec80);c.rt.requestStop();require(c.rt.join(),"Worker joined");const auto before=c.ram;rejected([&]{f(c.ram.data(),&c.ctx,&c.rt);});require(c.ram==before,"Stale hook after join no effects");}
 {Case c;require(c.install(),"reentry setup");c.rt.reenter=true;c.ctx.pc=entries[8].at;const auto ctx=c.ctx;rejected([&]{c.call(8);});require(c.rt.provider_count==1&&c.rt.stopped,"Reentry fails before later providers");require(std::memcmp(&ctx,&c.ctx,sizeof(ctx))==0,"Failure preserves caller context");}
 {Case c;require(c.install(),"provider yield setup");c.rt.bad_return=true;rejected([&]{c.call(8);});require(c.rt.provider_count==1&&c.rt.stopped,"Unexpected provider PC no later effects");}
 {Case c;require(c.install(),"provider throw setup");c.rt.provider_throw=true;const auto flag=c.ram[0x324476];rejected([&]{c.call(8);});require(c.rt.provider_count==1&&c.ram[0x324476]==flag&&c.rt.stopped,"Throwing observer stops later effects");}
 {Case c;require(c.install(),"register preservation setup");const auto original=c.ctx;SET_GPR_U32(&c.ctx,4,2);const auto expected=c.ctx;c.call(4);for(unsigned n=0;n<32;++n)if(n!=2)require(std::memcmp(&c.ctx.gpr[n],&expected.gpr[n],sizeof(FixtureVec))==0,"Native hook preserves unreturned registers");require(c.ctx.gpr[2].words[1]==original.gpr[2].words[1],"Return preserves upper GPR");}
 {Case c;require(c.install(),"join race setup");hold_provider=true;provider_entered=false;std::atomic<bool> done{},call_failed{};std::thread call([&]{try{c.call(8);}catch(...){call_failed=true;}});while(!provider_entered)std::this_thread::yield();std::thread join([&]{c.rt.requestStop();done=c.rt.join();});std::this_thread::sleep_for(std::chrono::milliseconds(10));require(!done,"Join drains accepted synchronous observer");hold_provider=false;call.join();join.join();require(done&&call_failed,"Stopped hook joined after provider returns");}
}
int main(int argc,char** argv){try{require(argc==2,"Input RAM path");std::ifstream f(argv[1],std::ios::binary);admission.resize(0x2000000);f.read(reinterpret_cast<char*>(admission.data()),admission.size());require(bool(f),"Admission RAM read");equivalent_entries();admission_cases();runtime_refusals();ordering_and_failures();std::cout<<"{\"checks\":"<<checks<<",\"original_entry_comparisons\":"<<comparisons<<",\"real_entries\":9,\"game_run\":false}\n";}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
