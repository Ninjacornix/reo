// Explicit, temporary guest-state projection for the nine complete native entries.
#include "save_session.hpp"
#include "game/native/gameplay_save/snapshot.hpp"
#include "game/native/gameplay_session/session.hpp"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include "source_instruction_access.hpp"
#include <algorithm>
#include <atomic>
#include <bit>
#include <chrono>
#include <cstdio>
#include <cstring>
#include <memory>
#include <mutex>
#include <stdexcept>
#include <unordered_map>
#include <iterator>
#include <vector>

#if !defined(REO_BUILD_NATIVE_GAMEPLAY_SAVE) || !REO_BUILD_NATIVE_GAMEPLAY_SAVE
#error Native gameplay save/session requires explicit candidate compilation
#endif
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*) noexcept;
#define X(at,name,kind) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "entries.inc"
#undef X
#define P(at,name,back,depth) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "providers.inc"
#undef P

namespace reo::native::native_gameplay {
namespace {
namespace save=gameplay_save;namespace session=gameplay_session;
using Function=PS2Runtime::RecompiledFunction;
enum class Kind {capture,restore,clear_second,seed,random,defaults,capture_options,sanitize,restore_options};
struct Entry {std::uint32_t at;Function original,replacement;Kind kind;};
struct Provider {std::uint32_t at;Function original;std::uint32_t back,depth;};
class Binding;
std::mutex registry_mutex;
std::unordered_map<PS2Runtime*,std::shared_ptr<Binding>> registry;
void invoke(Kind,std::uint8_t*,R5900Context*,PS2Runtime*);
#define X(at,name,kind) void hook_##name(std::uint8_t* ram,R5900Context* ctx,PS2Runtime* rt){invoke(Kind::kind,ram,ctx,rt);}
#include "entries.inc"
#undef X
const Entry entries[]={
#define X(at,name,kind) {at,&name,&hook_##name,Kind::kind},
#include "entries.inc"
#undef X
};
const Provider providers[]={
#define P(at,name,back,depth) {at,&name,back,depth},
#include "providers.inc"
#undef P
};
// Native-only bounded observations. No file/string allocation or I/O during a
// hook, and no row for each RNG request. Entry counts are retained separately.
struct Observations {
    struct Counts {std::atomic<std::uint64_t> accepted{},completed{},failed{},rejected{};};
    struct Row {std::uint64_t sequence{},operation{},ns{};Kind kind{};const char* event{};std::int32_t detail{};};
    std::array<Counts,9> counts{};std::array<Row,128> rows{};
    // Shadow mode: original authoritative, native compared on scratch regions.
    struct ShadowCounts {std::uint64_t compared{},mismatched{},native_failed{},passthrough{};};
    struct Mismatch {Kind kind{};std::uint32_t at{};std::uint64_t native{},original{};};
    std::array<ShadowCounts,9> shadow{};std::array<Mismatch,16> mismatches{};std::uint64_t mismatch_rows{};bool shadow_mode{};
    void mismatch(Kind kind,std::uint32_t at,std::uint64_t native,std::uint64_t original) noexcept {
        if(mismatch_rows<mismatches.size())mismatches[mismatch_rows]={kind,at,native,original};
        ++mismatch_rows;
    }
    std::uint64_t sequence{},operation{},restore_ok{},restore_error{};bool emitted{},installed{};
    inline static std::atomic<std::uint64_t> next_id{};
    const std::uint64_t id=next_id.fetch_add(1,std::memory_order_relaxed)+1;
    void record(Kind kind,const char* event,std::int32_t detail=0) noexcept {
        if(kind==Kind::random)return;
        const auto seq=++sequence;
        const auto ns=std::uint64_t(std::chrono::duration_cast<std::chrono::nanoseconds>(std::chrono::steady_clock::now().time_since_epoch()).count());
        rows[(seq-1)%rows.size()]={seq,operation,ns,kind,event,detail};
    }
    void dump() noexcept {
        if(emitted){return;}
        emitted=true;
        const auto retained=std::min<std::uint64_t>(sequence,rows.size());
        std::fprintf(stderr,"[NATIVE-GAMEPLAY-SAVE-JOIN] schema=1 binding=%llu joined=1 installed=%u restore_ok=%llu restore_error=%llu trace_rows=%llu trace_overwritten=%llu rng_rows=0\n",
            static_cast<unsigned long long>(id),unsigned(installed),static_cast<unsigned long long>(restore_ok),static_cast<unsigned long long>(restore_error),
            static_cast<unsigned long long>(retained),static_cast<unsigned long long>(sequence-retained));
        for(unsigned i=0;i<counts.size();++i){const auto& c=counts[i];
            std::fprintf(stderr,"[NATIVE-GAMEPLAY-SAVE-ENTRY] binding=%llu at=0x%x accepted=%llu completed=%llu failed=%llu rejected=%llu\n",
                static_cast<unsigned long long>(id),entries[i].at,
                static_cast<unsigned long long>(c.accepted.load()),static_cast<unsigned long long>(c.completed.load()),
                static_cast<unsigned long long>(c.failed.load()),static_cast<unsigned long long>(c.rejected.load()));
        }
        if(shadow_mode){
            for(unsigned i=0;i<shadow.size();++i){const auto& s=shadow[i];
                std::fprintf(stderr,"[NATIVE-GAMEPLAY-SAVE-SHADOW] binding=%llu at=0x%x compared=%llu mismatched=%llu native_failed=%llu passthrough=%llu\n",
                    static_cast<unsigned long long>(id),entries[i].at,static_cast<unsigned long long>(s.compared),
                    static_cast<unsigned long long>(s.mismatched),static_cast<unsigned long long>(s.native_failed),
                    static_cast<unsigned long long>(s.passthrough));
            }
            const auto shown=std::min<std::uint64_t>(mismatch_rows,mismatches.size());
            for(std::uint64_t i=0;i<shown;++i){const auto& m=mismatches[i];
                // at=0xffffffff is the v0 return value; otherwise the first differing guest byte.
                std::fprintf(stderr,"[NATIVE-GAMEPLAY-SAVE-SHADOW-MISMATCH] entry=0x%x at=0x%x native=0x%llx original=0x%llx\n",
                    entries[static_cast<unsigned>(m.kind)].at,m.at,static_cast<unsigned long long>(m.native),static_cast<unsigned long long>(m.original));
            }
        }
        for(std::uint64_t seq=sequence-retained+1;seq<=sequence;++seq){const auto& r=rows[(seq-1)%rows.size()];
            std::fprintf(stderr,"[NATIVE-GAMEPLAY-SAVE-TRACE] binding=%llu seq=%llu operation=%llu ns=%llu at=0x%x event=%s detail=%d\n",
                static_cast<unsigned long long>(id),static_cast<unsigned long long>(r.sequence),static_cast<unsigned long long>(r.operation),
                static_cast<unsigned long long>(r.ns),entries[static_cast<unsigned>(r.kind)].at,r.event,int(r.detail));
        }
        // Diagnostic write failures do not alter accepted gameplay outcomes or
        // quiescence. There is no throw, retry, fallback, or per-frame output.
    }
};
constexpr reo_native_image_identity::Digest digest(const char(&s)[65]){
    reo_native_image_identity::Digest d{};
    for(unsigned i=0;i<32;++i){const auto digit=[](char c){return c<='9'?c-'0':c-'a'+10;};d[i]=std::uint8_t(digit(s[i*2])*16+digit(s[i*2+1]));}
    return d;
}
bool image(const std::uint8_t* ram){
    if(!ram)return false;
#define H(at,bytes,sha) if(reo_native_image_identity::sha256(ram+at,bytes)!=digest(sha))return false;
#include "image.inc"
#undef H
    return true;
}
std::uint32_t physical(std::uint32_t address,std::size_t bytes){
    const auto bank=address&0xfe000000u;const auto at=address&0x1fffffffu;
    if((bank!=0 && bank!=0x20000000u && bank!=0x80000000u && bank!=0xa0000000u)||at>=0x02000000u||bytes>0x02000000u-at)
        throw std::runtime_error("Native gameplay guest range refused");
    return at;
}
struct Region {std::uint32_t at;std::size_t bytes;};
constexpr Region projections[]={{0x3241a0,16},{0x31fb60,0x4234},{0x318b60,0x7000},{0x35f080,0x8000},{0x36f080,0x40},{0x3165a8,8},{0x324476,1},{0x324488,1},{0x32448d,1}};
constexpr std::uint32_t option_at[]={0x3243c5,0x3243c9,0x3243ca,0x3243ec,0x3243ef,0x3243f0,0x3243ed,0x3243ee};
class Binding final:public PS2Runtime::ExternalWorker {
public:
    PS2Runtime* runtime;std::uint8_t* ram;
    std::atomic<bool> stopped{},active{};std::mutex operation;
    save::Container container{};save::LiveState state{};session::Random random;
    Observations observations;Kind current_kind{};
    R5900Context* context{};std::uint32_t container_at{},restore_depth{};bool failed{};
    // Shadow scratch: same physical layout as guest RAM; only declared regions are valid.
    std::vector<std::uint8_t> scratch;bool on_scratch{};
    Binding(PS2Runtime& r):runtime(&r),ram(r.memory().getRDRAM()){}
    void requestStop() noexcept override {stopped.store(true,std::memory_order_release);}
    bool join() noexcept override {
        requestStop();
        // Joining from a synchronous provider/guest hook cannot prove quiescence.
        if(current_binding==this)return false;
        std::lock_guard guard(operation);active.store(false,std::memory_order_release);
        {std::lock_guard lock(registry_mutex);const auto it=registry.find(runtime);
            if(it!=registry.end() && it->second.get()==this)registry.erase(it);}
        observations.dump();
        return true;
    }
    inline static thread_local Binding* current_binding{};
    void check() const {
        if(stopped.load(std::memory_order_acquire)||failed)throw std::runtime_error("Native gameplay binding stopped");
    }
    void copy(std::uint32_t at,void* data,std::size_t bytes,bool write){
        check();const auto p=physical(at,bytes);
        if(on_scratch){ // shadow run: never touches guest RAM or its instrumentation
            if(write)std::memcpy(scratch.data()+p,data,bytes);else std::memcpy(data,scratch.data()+p,bytes);
            return;
        }
        if(write)reo_source_instrumentation::copyBytesForBank(ram,ram+p,data,bytes);
        else reo_source_instrumentation::copyBytesForBank(ram,data,ram+p,bytes);
    }
    template<class T>T read(std::uint32_t at){T value{};copy(at,&value,sizeof(value),false);return value;}
    template<class T>void write(std::uint32_t at,T value){copy(at,&value,sizeof(value),true);}
    template<class T>void transfer(std::uint32_t at,T& value,bool writing){copy(at,value.data(),value.size()*sizeof(value[0]),writing);}
    void live(bool writing){
        transfer(0x3241a0,state.settings,writing);transfer(0x31fb60,state.first,writing);transfer(0x318b60,state.second,writing);
        transfer(0x35f080,state.third,writing);transfer(0x36f080,state.tail,writing);transfer(0x3165a8,state.conditional_tail,writing);
        if(writing){write(0x324476,state.profile_flag);write(0x324488,state.second_flag);write(0x32448d,state.resume_selector);}
        else{state.profile_flag=read<std::byte>(0x324476);state.second_flag=read<std::byte>(0x324488);state.resume_selector=read<std::byte>(0x32448d);}
    }
    session::Options options(){
        std::uint8_t v[8]{};for(unsigned i=0;i<8;++i)v[i]=read<std::uint8_t>(option_at[i]);
        return{v[0],v[1],v[2],v[3],v[4],v[5],std::bit_cast<std::int8_t>(v[6]),std::bit_cast<std::int8_t>(v[7])};
    }
    void options(const session::Options& o){
        const std::uint8_t values[]={o.audio_mode,o.music_volume,o.effects_volume,o.controller_profile,o.vibration,o.brightness,
            std::bit_cast<std::uint8_t>(o.screen_x),std::bit_cast<std::uint8_t>(o.screen_y)};
        for(unsigned i=0;i<8;++i)write(option_at[i],values[i]);
    }
    std::uint32_t draw(std::uint32_t selector){
        random.restore({read<std::uint16_t>(0x3244b0),read<std::uint16_t>(0x3244b8),read<std::uint8_t>(0x2b8de8)});
        const auto value=random.request(selector);const auto s=random.state();
        if(selector==1)write(0x3244b0,s.primary);else if(selector==3)write(0x3244b8,s.secondary);
        return value;
    }
    void provider(unsigned index,std::uint32_t a0,std::uint32_t a1=0){
        [[maybe_unused]] auto* rdram=ram; // actual SDK context-write bank macro
        check();const auto& p=providers[index];const auto saved=*context;
        const auto sp=GPR_U32(context,29);
        if(sp<p.depth+restore_depth || (sp&15))throw std::runtime_error("Native gameplay provider stack refused");
        const auto target_sp=sp-p.depth-restore_depth;physical(target_sp,0x10);
        SET_GPR_U32(context,29,target_sp);SET_GPR_U32(context,31,p.back);
        SET_GPR_S32(context,4,a0);SET_GPR_S32(context,5,a1);context->pc=p.at;context->in_delay_slot=false;
        try{
            observations.record(current_kind,"provider_begin",std::int32_t(p.at));
            p.original(ram,context,runtime);
            if(context->pc!=p.back || GPR_U32(context,29)!=target_sp || context->in_delay_slot || !ps2ActualGuestExecutionDepth(runtime))
                throw std::runtime_error("Native gameplay provider did not return synchronously");
            check();
            observations.record(current_kind,"provider_return",std::int32_t(p.at));
        }catch(...){*context=saved;throw;}
        *context=saved;
    }
    struct OptionsServices final:session::OptionServices {
        Binding& b;explicit OptionsServices(Binding& value):b(value){}
        void defaults_changed(session::SavedOptions& saved) override {
            b.transfer(0x3241a0,saved,true);b.provider(1,0x3241a0,0x24fe30);b.transfer(0x3241a0,saved,false);
        }
        void call(session::Options& o,unsigned index,std::uint32_t a,std::uint32_t c=0){
            b.options(o);b.provider(index,a,c);o=b.options();
        }
        void screen_offset(session::Options& o,std::int8_t x,std::int8_t y)override{call(o,2,std::uint32_t(std::int32_t(x)),std::uint32_t(std::int32_t(y)));}
        void audio_mode(session::Options& o,std::uint8_t v)override{call(o,3,v);}
        void effects_volume(session::Options& o,std::uint8_t v)override{call(o,4,v);}
        void music_volume(session::Options& o,std::uint8_t v)override{call(o,5,v);}
    };
    void restore_options(){
        session::SavedOptions saved{};transfer(0x3241a0,saved,false);auto o=options();OptionsServices services(*this);
        session::restore_options(saved,o,services);
        // Last provider already saw/published every value; rereading after it
        // preserves its mutations. No stale options object is exported later.
    }
    static void settings(void* opaque,save::LiveState& value)noexcept{
        auto& b=*static_cast<Binding*>(opaque);
        try{
            b.transfer(b.container_at,b.container,true);b.transfer(0x3241a0,value.settings,true);
            b.observations.record(b.current_kind,"restore_decoded_settings");
            b.restore_depth=0x50; // outer restore0x30 + original header helper0x20
            b.restore_options();b.restore_depth=0;
            b.observations.record(b.current_kind,"restore_options_return");
            b.live(false); // observers may mutate any projected live region
            // The original header helper reads flags, and subsequent section
            // helpers read data, AFTER observers return. Retain those changes.
            b.transfer(b.container_at,b.container,false);
            b.observations.record(b.current_kind,"restore_observer_refresh");
        }catch(...){b.restore_depth=0;b.failed=true;}
    }
    std::uint32_t context_field(std::uint32_t offset){
        const auto base=GPR_U32(context,4);physical(base,std::size_t(offset)+4);
        return read<std::uint32_t>(base+offset);
    }
    void select_container(std::uint32_t offset){
        container_at=context_field(offset);const auto at=physical(container_at,save::container_bytes);
        if(at&1)throw std::runtime_error("Native gameplay container alignment refused");
        // The native-owned snapshot has a nonaliasing contract. Refuse overlaps
        // explicitly, rather than silently changing memcpy/loop dependencies.
        for(const auto& p:projections)if(at<p.at+p.bytes && p.at<at+save::container_bytes)
            throw std::runtime_error("Native gameplay aliased container refused");
        transfer(container_at,container,false);
    }
    bool run(Kind kind){
        [[maybe_unused]] auto* rdram=ram;
        switch(kind){
        case Kind::capture:{
            select_container(0xe8);
            provider(0,container_at+8); // timestamp writes guest first
            observations.record(current_kind,"capture_timestamp_return");
            transfer(container_at,container,false);live(false);
            observations.record(current_kind,"capture_live_import");
            save::HeaderView h(container.data()+8,save::header_bytes);save::DataView d(container.data()+0x108,save::data_bytes);
            save::capture_header(h,state);save::capture_first(d,state);save::capture_second(h,d,state);save::capture_tail(d,state);
            transfer(container_at,container,true); // original plaintext visible before RNG
            observations.record(current_kind,"capture_plaintext");
            const auto seed=draw(1);observations.record(current_kind,"capture_rng");
            save::encode(container,seed);transfer(container_at,container,true);observations.record(current_kind,"capture_encoded");return false;
        }
        case Kind::restore:{
            select_container(0xec);live(false);save::Services services{};services.context=this;services.settings_changed=&settings;
            const auto result=save::restore(container,state,services);check();
            // On success settings() already published decoded bytes before
            // observers; publishing again here would erase their mutations.
            if(result.decode==save::DecodeResult::bad_checksum){transfer(container_at,container,true);observations.record(current_kind,"restore_bad_checksum");}
            if(result.original_return==0){
                // Original header flags become visible before subsequent section writes.
                write(0x324476,state.profile_flag);write(0x324488,state.second_flag);write(0x32448d,state.resume_selector);
                transfer(0x31fb60,state.first,true);transfer(0x318b60,state.second,true);transfer(0x35f080,state.third,true);transfer(0x36f080,state.tail,true);
                if(state.tail[0]!=std::byte{})transfer(0x3165a8,state.conditional_tail,true);
                observations.record(current_kind,"restore_live_export");
            }
            SET_GPR_S32(context,2,result.original_return);return true;
        }
        case Kind::clear_second:{
            const auto mode=context_field(0x20);
            if(mode==0||mode==1){state.second.fill(std::byte{});write<std::uint8_t>(0x324488,0);transfer(0x318b60,state.second,true);}return false;
        }
        case Kind::seed:{
            random.seed(read<std::uint8_t>(0x324199));const auto s=random.state();
            write(0x2b8de8,s.observed);write(0x3244b8,s.secondary);write(0x3244b0,s.primary);return false;
        }
        case Kind::random:SET_GPR_U32(context,2,draw(GPR_U32(context,4)));return true;
        case Kind::defaults:{session::SavedOptions saved{};OptionsServices services(*this);session::initialize_saved_options(saved,services);return false;}
        case Kind::capture_options:{session::SavedOptions saved{};transfer(0x3241a0,saved,false);session::capture_options(options(),saved);transfer(0x3241a0,saved,true);return false;}
        case Kind::sanitize:{auto o=options();session::sanitize_options(o);options(o);return false;}
        case Kind::restore_options:restore_options();return false;
        }
        throw std::runtime_error("Native gameplay action refused");
    }
};
[[noreturn]]void failure(PS2Runtime* rt){
    if(rt){rt->requestStop();}
    std::fputs("[NATIVE-GAMEPLAY-SAVE-ERROR] native save/session admission or provider failed\n",stderr);
    throw std::runtime_error("Native gameplay save/session stopped; no legacy fallback");
}
Function original_of(Kind kind) noexcept {
    for(const auto& e:entries)if(e.kind==kind)return e.original;
    return nullptr;
}
// Entries whose native body makes no guest provider call. Their whole guest
// footprint is the declared regions below, so native can run on scratch.
bool shadowable(Kind kind) noexcept {
    return kind==Kind::random||kind==Kind::seed||kind==Kind::sanitize||kind==Kind::clear_second||kind==Kind::capture_options;
}
// Guest bytes these entries may read or write (native side): RNG state, seed
// source, option bytes and the projected save regions.
void shadow_regions(Kind kind,R5900Context ctx,std::vector<Region>& out){ // copy: GPR macros need a mutable context
    out.assign(std::begin(projections),std::end(projections));
    for(const auto at:option_at)out.push_back({at,1});
    out.push_back({0x3244b0,2});out.push_back({0x3244b8,2});out.push_back({0x2b8de8,1});out.push_back({0x324199,1});
    if(kind==Kind::clear_second)out.push_back({GPR_U32(&ctx,4)+0x20u,4});
}
// While an original runs under shadow, nested hooked entries run their original too.
thread_local bool shadow_passthrough=false;
struct PassthroughScope {PassthroughScope(){shadow_passthrough=true;}~PassthroughScope(){shadow_passthrough=false;}};
void run_original(Kind kind,std::uint8_t* ram,R5900Context* ctx,PS2Runtime* rt){
    const auto back=GPR_U32(ctx,31);
    PassthroughScope scope;original_of(kind)(ram,ctx,rt);
    if(ctx->pc!=back||ctx->in_delay_slot)throw std::runtime_error("Original save/session entry did not return synchronously");
}
void shadow(Binding& b,Kind kind,std::uint8_t* ram,R5900Context* ctx,PS2Runtime* rt,const R5900Context& saved){
    auto& s=b.observations.shadow[static_cast<unsigned>(kind)];
    if(!shadowable(kind)){run_original(kind,ram,ctx,rt);++s.passthrough;return;}
    std::vector<Region> regions;shadow_regions(kind,saved,regions);
    for(const auto& r:regions){const auto p=physical(r.at,r.bytes);
        reo_source_instrumentation::copyBytesForBank(ram,b.scratch.data()+p,ram+p,r.bytes);}
    // Native on scratch, with a private context copy.
    R5900Context native_ctx=saved;bool has_result=false,native_ok=true;
    b.context=&native_ctx;b.on_scratch=true;
    try{has_result=b.run(kind);}catch(...){native_ok=false;}
    b.on_scratch=false;b.failed=false;b.context=ctx;
    // Original on guest RAM: the only result the game sees.
    run_original(kind,ram,ctx,rt);
    ++s.compared;
    if(!native_ok){++s.native_failed;++s.mismatched;b.observations.mismatch(kind,0xfffffffeu,0,0);return;}
    bool same=true;
    if(has_result && GPR_U64(&native_ctx,2)!=GPR_U64(ctx,2)){
        same=false;b.observations.mismatch(kind,0xffffffffu,GPR_U64(&native_ctx,2),GPR_U64(ctx,2));
    }
    std::vector<std::uint8_t> actual;
    for(const auto& r:regions){const auto p=physical(r.at,r.bytes);actual.resize(r.bytes);
        reo_source_instrumentation::copyBytesForBank(ram,actual.data(),ram+p,r.bytes);
        if(std::memcmp(actual.data(),b.scratch.data()+p,r.bytes)){
            std::size_t i=0;while(actual[i]==b.scratch[p+i])++i;
            same=false;b.observations.mismatch(kind,r.at+std::uint32_t(i),b.scratch[p+i],actual[i]);
        }
    }
    if(!same)++s.mismatched;
}
void invoke(Kind kind,std::uint8_t* ram,R5900Context* ctx,PS2Runtime* rt){
    [[maybe_unused]] auto* rdram=ram;
    if(shadow_passthrough){run_original(kind,ram,ctx,rt);return;}
    std::shared_ptr<Binding> b;
    {std::lock_guard lock(registry_mutex);const auto it=registry.find(rt);if(it!=registry.end())b=it->second;}
    if(!b || !ctx || !b->active.load(std::memory_order_acquire)){
        if(b)++b->observations.counts[static_cast<unsigned>(kind)].rejected;
        failure(rt);
    }
    std::unique_lock lock(b->operation,std::try_to_lock);
    if(!lock.owns_lock() || Binding::current_binding){++b->observations.counts[static_cast<unsigned>(kind)].rejected;failure(rt);}
    const auto saved=*ctx;Binding::current_binding=b.get();b->context=ctx;b->failed=false;
    auto& counts=b->observations.counts[static_cast<unsigned>(kind)];bool accepted=false;b->current_kind=kind;
    try{
        b->check();if(ram!=b->ram || ram!=rt->memory().getRDRAM() || !ps2ActualGuestExecutionDepth(rt))throw std::runtime_error("Wrong native gameplay runtime");
        bool entry_pc=false;for(const auto& e:entries)if(e.kind==kind&&ctx->pc==e.at)entry_pc=true;
        if(!entry_pc||ctx->in_delay_slot)throw std::runtime_error("Native gameplay continuation refused");
        reo_source_instrumentation::EntryScope source_scope(rt,ctx);
        for(const auto& e:entries)if(!rt->hasFunction(e.at)||rt->lookupFunction(e.at)!=e.replacement)throw std::runtime_error("Stale native gameplay registry");
        for(const auto& p:providers)if(!rt->hasFunction(p.at)||rt->lookupFunction(p.at)!=p.original)throw std::runtime_error("Stale native gameplay provider");
        ++counts.accepted;accepted=true;++b->observations.operation;b->observations.record(kind,"begin");
        if(b->observations.shadow_mode){
            // Original stays authoritative and leaves ctx at its return address.
            shadow(*b,kind,ram,ctx,rt,saved);
            ++counts.completed;b->context=nullptr;Binding::current_binding=nullptr;return;
        }
        const bool has_result=b->run(kind);const auto result=GPR_U64(ctx,2);
        *ctx=saved;if(has_result)SET_GPR_U64(ctx,2,result);ctx->pc=GPR_U32(ctx,31);ctx->in_delay_slot=false;
        if(kind==Kind::restore){if(std::int32_t(result)==0)++b->observations.restore_ok;else ++b->observations.restore_error;}
        ++counts.completed;b->observations.record(kind,"complete",has_result?std::int32_t(result):0);
        b->context=nullptr;Binding::current_binding=nullptr;
    }catch(...){
        if(accepted){++counts.failed;b->observations.record(kind,"failed");}else ++counts.rejected;
        *ctx=saved;b->failed=true;b->context=nullptr;Binding::current_binding=nullptr;failure(rt);
    }
}
}
InstallResult install_save_session_before_run(PS2Runtime& rt,bool selected,bool shadow_mode) noexcept {
    if(!selected)return{InstallStatus::disabled};
    auto lease=rt.acquirePreRunSetup();if(!lease)return{InstallStatus::phase_closed};
    try{
        if(!image(rt.memory().getRDRAM()))return{InstallStatus::unsupported_image};
        for(const auto& e:entries)if(!rt.hasFunction(e.at)||rt.lookupFunction(e.at)!=e.original)return{InstallStatus::registry_mismatch};
        for(const auto& p:providers)if(!rt.hasFunction(p.at)||rt.lookupFunction(p.at)!=p.original)return{InstallStatus::registry_mismatch};
        auto b=std::make_shared<Binding>(rt);
        if(shadow_mode){b->scratch.assign(0x02000000u,0);b->observations.shadow_mode=true;}
        std::lock_guard lock(registry_mutex);
        if(registry.contains(&rt))return{InstallStatus::publication_refused};
        registry.emplace(&rt,b);
        if(!rt.registerExternalWorker(b)){registry.erase(&rt);return{InstallStatus::publication_refused};}
        try{for(const auto& e:entries)rt.registerFunction(e.at,e.replacement);}
        catch(...){
            b->requestStop();bool reverted=true;
            for(const auto& e:entries)try{rt.registerFunction(e.at,e.original);}catch(...){reverted=false;}
            registry.erase(&rt);if(!reverted)rt.requestStop();return{InstallStatus::publication_refused};
        }
        b->observations.installed=true;b->active.store(true,std::memory_order_release);return{InstallStatus::installed};
    }catch(...){return{InstallStatus::allocation_failed};}
}
}
