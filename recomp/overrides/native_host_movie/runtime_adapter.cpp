#include "runtime_adapter.h"
#include "render_bridge.h"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <atomic>
#include <array>
#include <bit>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <mutex>
#include <map>
#include <thread>

extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;
extern bool reoNativeHostMovieReviewedEntry(std::uint32_t,PS2Runtime::RecompiledFunction)noexcept;
#define X(address,name,action) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "entries.inc"
#undef X
namespace reo::native::host_movie_binding {
namespace {
constexpr std::uint32_t ram_bytes=0x2000000,game_context=0x340a40,configuration=game_context+4,vtable=0x22dce8;
using Function=PS2Runtime::RecompiledFunction;
enum class Action {size,create,destroy,frame,release,filename,unsupported,stop,pause,start_afs,status,time,information,start,loop,unlink,enqueue_afs,repeat_afs};
template<class T>T load(const std::uint8_t* ram,std::uint32_t at){T value;std::memcpy(&value,ram+at,sizeof(value));return value;}
template<class T>void store(std::uint8_t* ram,std::uint32_t at,T value){std::memcpy(ram+at,&value,sizeof(value));}
bool extent(std::uint32_t at,std::uint64_t bytes){return at>=0x10000&&at<=ram_bytes&&bytes<=ram_bytes-at;}
std::string lower(std::string value){for(auto& c:value){if(c=='\\')c='/';else if(c>='A'&&c<='Z')c=char(c-'A'+'a');}return value;}
class Binding final:public PS2Runtime::ExternalWorker {
public:
    PS2Runtime* const runtime;std::uint8_t* const ram;
    std::shared_ptr<const movie_assets::Catalogue> catalogue;
    host_movie::Session session;
    std::map<std::uint32_t,Function> originals;
    std::atomic<bool> active{},closing{};
    std::uint32_t proxy{},pixels{},width{},height{};
    bool alive{},repeat{},started{};
    host_movie::Generation generation{};
    std::uint64_t released{},sources{},frames{};
    std::vector<std::shared_ptr<const movie_assets::Asset>> playlist;
    std::shared_ptr<const host_movie::CpuFrame> held;
    Binding(PS2Runtime& r,std::uint8_t* bytes,std::shared_ptr<const movie_assets::Catalogue> assets):runtime(&r),ram(bytes),catalogue(std::move(assets)){}
    void requestStop()noexcept override{closing.store(true);session.request_stop();}
    bool join()noexcept override{requestStop();session.join();const auto s=session.snapshot();std::fprintf(stderr,"[NATIVE-HOST-MOVIE-REPORT] joined=%u sources=%llu delivered_frames=%llu error=%s\n",unsigned(s.joined),static_cast<unsigned long long>(sources),static_cast<unsigned long long>(frames),s.error.empty()?"none":s.error.c_str());return s.joined;}
    [[noreturn]]void fail(const char* reason,std::uint32_t address=0){std::fprintf(stderr,"[NATIVE-HOST-MOVIE-REFUSAL] boundary=%s address=%08x\n",reason,address);runtime->requestStop();throw std::runtime_error("Native movie game boundary refused");}
    void require(bool condition,const char* reason,std::uint32_t at=0){if(!condition)fail(reason,at);}
    std::string string(std::uint32_t at){require(extent(at,256),"string-range",at);std::string out;for(unsigned i=0;i<256;++i){const auto c=ram[at+i];if(!c)return out;require(c>=32&&c<127,"string-profile",at);out+=char(c);}fail("string-length",at);}
    void output(std::uint32_t at,std::size_t bytes){require(at%4==0&&extent(at,bytes),"output-range",at);require(at+bytes<=proxy||at>=pixels+std::uint64_t(width)*height*4,"output-proxy-alias",at);}
    void validate(){require(alive&&extent(proxy,8)&&load<std::uint32_t>(ram,proxy)==vtable&&load<std::uint32_t>(ram,proxy+4)==1&&load<std::uint32_t>(ram,game_context)==proxy,"proxy-lifetime",proxy);}
    std::uint32_t required(std::uint32_t config){require(config==configuration&&extent(config,48),"game-config",config);const auto w=load<std::uint32_t>(ram,config+8),h=load<std::uint32_t>(ram,config+12);require(w&&h&&w<=1024&&h<=1024&&w%16==0&&h%16==0,"game-dimensions",config);return w*h*4+64;}
    void create(std::uint32_t config,R5900Context& ctx){require(!alive,"duplicate-create");const auto bytes=required(config);const auto base=load<std::uint32_t>(ram,config+0x18),capacity=load<std::uint32_t>(ram,config+0x1c);
        require(base%64==0&&extent(base,capacity)&&capacity>=bytes,"game-arena",base);const auto work=load<std::uint32_t>(ram,0x56bae8);require(extent(work,40)&&load<std::uint32_t>(ram,work)==base,"game-arena-owner",base);
        proxy=base;pixels=base+64;width=load<std::uint32_t>(ram,config+8);height=load<std::uint32_t>(ram,config+12);alive=true;repeat=started=false;generation=released=0;playlist.clear();held.reset();
        std::memset(ram+proxy,0,64);store(ram,proxy,vtable);store(ram,proxy+4,1u);SET_GPR_U32((&ctx),2,proxy);
        std::fprintf(stderr,"[NATIVE-HOST-MOVIE] game object created renderer_grid=%ux%u original_decoder=unused\n",width,height);
    }
    std::shared_ptr<const movie_assets::Asset> afs(std::uint32_t type,std::uint32_t member){require(type==2||type==3,"archive-type",type);const auto descriptor=load<std::uint32_t>(ram,0x20cd00+type*4);require(extent(descriptor,0x110),"archive-descriptor",descriptor);auto path=lower(string(descriptor+16));const auto slash=path.find_last_of('/');const auto name=path.substr(slash==std::string::npos?0:slash+1);std::shared_ptr<const movie_assets::Asset> found;
        for(const auto& entry:catalogue->entries()){const auto label=lower(entry.label);if(entry.imported_member_index==member&&label.substr(0,label.find('/'))==name){require(!found||found==entry.asset,"ambiguous-archive-cue",member);found=entry.asset;}}
        require(bool(found),"unprepared-archive-cue",member);return found;
    }
    std::shared_ptr<const movie_assets::Asset> filename(std::uint32_t at){const auto wanted=lower(string(at));std::shared_ptr<const movie_assets::Asset> found;for(const auto& entry:catalogue->entries()){const auto label=lower(entry.label);if(label==wanted||label.substr(label.find_last_of('/')+1)==wanted){require(!found||found==entry.asset,"ambiguous-filename",at);found=entry.asset;}}require(bool(found),"unprepared-filename",at);return found;}
    void enqueue(std::shared_ptr<const movie_assets::Asset> asset){require(playlist.size()<256,"playlist-capacity");if(started)require(session.append(generation,asset),"append-admission");playlist.push_back(std::move(asset));}
    void start(){require(!held,"start-with-renderer-lease");require(!playlist.empty(),"empty-playlist");generation=session.start(playlist,repeat,width);released=0;started=true;++sources;std::fprintf(stderr,"[NATIVE-HOST-MOVIE] source started generation=%llu clips=%zu loop=%u\n",static_cast<unsigned long long>(generation),playlist.size(),unsigned(repeat));}
    void stop(){require(!held,"stop-with-renderer-lease");if(started)require(session.stop(generation),"stop-admission");started=false;generation=released=0;playlist.clear();}
    std::uint32_t status(){if(!started)return 0;const auto snapshot=session.snapshot();if(snapshot.state==host_movie::State::error){std::fprintf(stderr,"[NATIVE-HOST-MOVIE-ERROR] %s\n",snapshot.error.c_str());return 4;}const auto frame=session.frame(generation);if(snapshot.state==host_movie::State::ended&&(!frame||frame->serial<=released))return 3;return frame?2:1;}
    bool dispatch(Action action,std::uint32_t address,R5900Context& ctx){const auto argument=[&](unsigned i){return GPR_U32((&ctx),i);};const auto handle=argument(4);
        if(action==Action::size){SET_GPR_U32((&ctx),2,required(handle));return true;}
        if(action==Action::create){create(handle,ctx);return true;}
        if(handle!=proxy)return false;
        validate();
        switch(action) {
        case Action::destroy:stop();alive=false;store(ram,proxy+4,0u);return true;
        case Action::enqueue_afs:enqueue(afs(argument(5),argument(6)));return true;
        case Action::start_afs:case Action::repeat_afs:stop();repeat=action==Action::repeat_afs;enqueue(afs(argument(5),argument(6)));start();return true;
        case Action::filename:stop();enqueue(filename(argument(5)));start();return true;
        case Action::start:start();return true;
        case Action::stop:stop();return true;
        case Action::loop:repeat=argument(5)==1;if(started)require(session.loop(generation,repeat),"loop-admission");return true;
        case Action::pause:if(started)require(session.pause(generation,argument(5)!=0),"pause-admission");return true;
        case Action::unlink:return true;
        case Action::status:SET_GPR_U32((&ctx),2,status());return true;
        case Action::time:{const auto numerator=argument(5),denominator=argument(6);output(numerator,4);output(denominator,4);const auto frame=session.frame(generation);store(ram,numerator,frame?static_cast<std::uint32_t>(frame->ordinal):0u);store(ram,denominator,1u);SET_GPR_U32((&ctx),2,0);return true;}
        case Action::information:{output(argument(5),20);std::memset(ram+argument(5),0xff,20);return true;}
        case Action::frame:{const auto out=argument(5);output(out,76);std::memset(ram+out,0,76);require(!held,"nested-renderer-acquire");auto frame=session.frame(generation);if(!frame||frame->serial<=released)return true;
            copy_for_legacy_renderer(*frame,width,height,{ram+pixels,std::size_t(width)*height*4});held=std::move(frame);store(ram,out,pixels);store(ram,out+4,3u);store(ram,out+8,width);store(ram,out+12,height);store(ram,out+16,width*4);store(ram,out+24,1u);store(ram,out+28,30000u);store(ram,out+32,static_cast<std::uint32_t>(held->ordinal));store(ram,out+40,1001u);store(ram,out+48,static_cast<std::uint32_t>(held->ordinal));store(ram,out+72,2u);++frames;return true;}
        case Action::release:if(held){released=held->serial;held.reset();}return true;
        case Action::unsupported:fail("unsupported-public-api",address);
        case Action::size:case Action::create:break;
        }return false;
    }
};
std::mutex installed_mutex;std::shared_ptr<Binding> installed;
std::shared_ptr<Binding> current(){std::lock_guard lock(installed_mutex);return installed;}
template<Action What,std::uint32_t Address,Function Original>void route(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* runtime){const auto binding=current();const auto original=binding&&binding->originals.contains(Address)?binding->originals.at(Address):Original;if(!binding||!binding->active.load()){original(ram,ctx,runtime);return;}if(binding->closing.load()){if(ctx)ctx->pc=0;return;}
    binding->require(ctx&&binding->ram==ram&&binding->runtime==runtime&&ps2ActualGuestExecutionDepth(runtime),"guest-identity",Address);
    if(binding->dispatch(What,Address,*ctx))ctx->pc=GPR_U32(ctx,31);else original(ram,ctx,runtime);
}
struct Entry {std::uint32_t address;Function original,wrapper;};
const Entry entries[]{
#define X(address,name,action) {address,name,route<Action::action,address,name>},
#include "entries.inc"
#undef X
};
}
bool install_before_run(PS2Runtime& runtime,const std::filesystem::path& cache)noexcept {
    std::shared_ptr<Binding> binding;std::size_t changed{};std::array<Function,std::size(entries)> previous{};
    try {
        std::unique_lock publication(installed_mutex);
        if(installed&&installed->active.load())return false;
        auto setup=runtime.acquirePreRunSetup();if(!setup){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] pre-run setup unavailable\n");return false;}auto* ram=runtime.memory().getRDRAM();
        if(!ram||load<std::uint32_t>(ram,vtable+0x14)!=0x15d1d0||load<std::uint32_t>(ram,vtable+0x20)!=0x160060){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] public method table mismatch\n");return false;}
        constexpr reo_native_image_identity::Digest expected{0x58,0x59,0xa4,0x9d,0x20,0xf2,0x49,0x2c,0x00,0xfa,0x81,0xab,0xce,0xef,0x49,0x85,0xe8,0xb2,0xb9,0xdb,0xb0,0x3d,0x58,0x5c,0xfe,0xf2,0x48,0xe4,0x05,0x47,0x65,0x42};
        if(reo_native_image_identity::sha256(ram+0x15bf48,0x164128-0x15bf48)!=expected){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] owned code identity mismatch\n");return false;}
        for(std::size_t i=0;i<std::size(entries);++i){const auto& entry=entries[i];previous[i]=runtime.lookupFunction(entry.address);if(!runtime.hasFunction(entry.address)||(previous[i]!=entry.original&&!reoNativeHostMovieReviewedEntry(entry.address,previous[i]))){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] registry mismatch at %08x\n",entry.address);return false;}}
        auto assets=movie_assets::Catalogue::open(cache);binding=std::make_shared<Binding>(runtime,ram,std::move(assets));
        for(std::size_t i=0;i<std::size(entries);++i)binding->originals.emplace(entries[i].address,previous[i]);
        const auto end=std::chrono::steady_clock::now()+std::chrono::seconds(10);for(;;){const auto s=binding->session.snapshot();if(!s.error.empty()||s.joined)return false;if(s.device_ready)break;if(std::chrono::steady_clock::now()>end)return false;std::this_thread::sleep_for(std::chrono::milliseconds(1));}
        if(!runtime.registerExternalWorker(binding))return false;
        installed=binding;
        for(const auto& entry:entries){runtime.registerFunction(entry.address,entry.wrapper);++changed;}
        binding->active.store(true);std::fprintf(stderr,"[NATIVE-HOST-MOVIE] selected entries=%zu cache_entries=%zu decoder=windows-media-engine original_sfd=unused renderer=temporary-game-bridge\n",std::size(entries),binding->catalogue->entries().size());return true;
    }catch(const std::exception& error){std::fprintf(stderr,"[NATIVE-HOST-MOVIE] installation failed: %s\n",error.what());if(binding)binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,previous[i]);return false;}
    catch(...){if(binding)binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,previous[i]);return false;}
}
}
