// Explicit private candidate; complete live qualification remains required.
#include "ordinary_runtime.h"
#include "recomp/overrides/native_sound_ram/composite_backend.h"
#include "game_handles.h"
#include "source_profile.h"
#include "recomp/overrides/native_resource_reads/runtime_adapter.h"
#include "recomp/overrides/native_geometry/reo_vu_native_sha256.h"
#include "ps2_runtime.h"
#include "ps2_runtime_macros.h"
#include <algorithm>
#include <atomic>
#include <bit>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <mutex>
#include <stdexcept>
#include <thread>

#if !defined(REO_BUILD_NATIVE_RESOURCE_READS) || !REO_BUILD_NATIVE_RESOURCE_READS
#error Ordinary native sources require the actual immutable resource mount handoff
#endif
extern std::uint32_t ps2ActualGuestExecutionDepth(PS2Runtime*)noexcept;
float reoAudioStreamGain(std::uint32_t);
#define X(address,name,action) void name(std::uint8_t*,R5900Context*,PS2Runtime*);
#include "ordinary_entries.inc"
#undef X

namespace reo::native::adxt_binding {
namespace {
using S=instances::Status;using Function=PS2Runtime::RecompiledFunction;
enum class Action {group,stop,destroy_child,pause,discard,rna_ratio,raw_ratio,estimate,centiseconds,total,frequency,channels,callback,unsupported};
struct Closing {};
template<class F>struct Operation final:control_owner::Operation {F fn;explicit Operation(F f):fn(std::move(f)){}void run(instances::Instances& value)noexcept override{fn(value);}};
template<class F>struct HandleWork final:HandleOperation {F fn;explicit HandleWork(F f):fn(std::move(f)){}void run(instances::Instances& p,const instances::Key& key,const Handle& h)noexcept override{fn(p,key,h);}};
template<class T>T load(const std::uint8_t* ram,std::uint32_t at)noexcept{T out;std::memcpy(&out,ram+at,sizeof(out));return out;}
template<class T>void store(std::uint8_t* ram,std::uint32_t at,T value)noexcept{std::memcpy(ram+at,&value,sizeof(value));}
constexpr reo_native_image_identity::Digest digest(const char(&text)[65]){
    reo_native_image_identity::Digest out{};const auto nibble=[](char c){return c<='9'?c-'0':c-'a'+10;};
    for(unsigned i=0;i<out.size();++i)out[i]=std::uint8_t(nibble(text[i*2])*16+nibble(text[i*2+1]));return out;
}
bool image(const std::uint8_t* ram)noexcept{
    return ram && reo_native_image_identity::sha256(ram+0x12a658,0x308)==digest("77fb81fa81b4ce75251107a09cadb1041516f1722afb167fce07aadfea425610") &&
        reo_native_image_identity::sha256(ram+0x1315e0,0x373c)==digest("f1edb1cfb980358f350913e82a81cbd8bbc875b26269c11d779065a9e8f25646") &&
        reo_native_image_identity::sha256(ram+0x12c680,0x30)==digest("6474bff5bad1e43e0c6e22ce4ca771dd5029f2fd1af15005ef49f4a25346d695") &&
        reo_native_image_identity::sha256(ram+0x220498,4000)==digest("ba7a4e40b40741d52daddb3e80bf6c55d0ddcf93df46580ba6de9ad8c5e9c138");
}
class Gains final:public adxt_output_session::StreamGains {float factor(std::uint32_t key)noexcept override{return reoAudioStreamGain(key);}};
struct Controls {
    std::uint32_t attenuation{},base{};std::int32_t divisor{};std::uint8_t loop{},inhibit{},pause{};
    friend bool operator==(const Controls&,const Controls&)=default;
};
class Binding final:public PS2Runtime::ExternalWorker {
public:
    struct Record {GameKey key;Handle handle;Controls controls;bool owned{},source{};std::uint64_t expected_start{};};
    PS2Runtime* const runtime;std::uint8_t* const ram;
    std::shared_ptr<control_owner::Owner> source_owner;
    std::shared_ptr<const resources::win32::MountedResources> mount;
    std::shared_ptr<const adxt_attenuation::Table> table;
    GameHandles mapped;std::array<Record,16> records;
    std::shared_ptr<const sound_ram::MediaInstallResult::PcmOrder> order;
    std::atomic<bool> active{},stopping{};
    Binding(PS2Runtime& r,std::uint8_t* bytes,std::shared_ptr<control_owner::Owner> owner,
            std::shared_ptr<const resources::win32::MountedResources> resource,
            std::shared_ptr<const adxt_attenuation::Table> volume)
        :runtime(&r),ram(bytes),source_owner(std::move(owner)),mount(std::move(resource)),table(std::move(volume)),mapped(source_owner){}
    void requestStop()noexcept override{stopping.store(true,std::memory_order_release);}
    bool join()noexcept override{
        // Never wait for a guest wrapper here: it may be retiring a source that
        // the later canonical SourceWorker must join. Accepted wrappers retain
        // this binding and its map. No RAM is read/exported during teardown.
        requestStop();return true;
    }
    [[noreturn]] void fail(const char* what,std::uint32_t address=0,unsigned status=0){
        if(stopping.load(std::memory_order_acquire))throw Closing{};
        std::fprintf(stderr,"[NATIVE-ADXT-REFUSAL] boundary=%s address=%08x status=%u; no original-source fallback\n",what,address,status);
        runtime->requestStop();throw std::runtime_error("Unadmitted ordinary native ADXT boundary");
    }
    void require(S status,const char* what,std::uint32_t address=0){if(status!=S::completed && status!=S::pending)fail(what,address,unsigned(status));}
    template<class F>void control(F fn){Operation op(std::move(fn));const auto admitted=source_owner->run(op);if(admitted!=control_owner::Admission::accepted)fail("controller",0,unsigned(admitted));}
    template<class F>void with(Record& record,F fn){HandleWork op(std::move(fn));require(mapped.with(record.key,op),"handle",record.handle.address);}
    std::uint32_t tick()const noexcept{return load<std::uint32_t>(ram,0x20f3c4);}
    void import_clock(){S result=S::fault;control([&](auto& p){result=p.configure_clock({{load<std::uint32_t>(ram,0x21b750),load<std::uint32_t>(ram,0x21b788),load<std::uint32_t>(ram,0x21b75c)},load<std::uint32_t>(ram,0x21b760),load<std::uint32_t>(ram,0x21b78c)});});require(result,"clock-import");}
    void publish_clock(){adxt_estimated_clock::Shared shared;control([&](auto& p){shared=p.snapshot().session.clock_state;});store(ram,0x21b75c,shared.mode.resynchronizations);store(ram,0x21b78c,shared.drift_bits);}
    Controls controls(std::uint32_t at){
        const auto loop=ram[at+0x6c];
        if(loop>1 || load<std::int16_t>(ram,at+0x42)!=-128 || load<std::int16_t>(ram,at+0x44)!=-128 || load<std::int16_t>(ram,at+0x46))fail("loop-pan-pitch-profile",at);
        const auto divisor=load<std::int32_t>(ram,at+0x38);if(divisor<=0)fail("service-divisor",at);
        return {static_cast<std::uint32_t>(load<std::int16_t>(ram,at+0x40)),load<std::uint32_t>(ram,at+0x88),divisor,loop,ram[at+0x70],ram[at+0x72]};
    }
    Record* find(std::uint32_t address){
        std::uint32_t slot{};if(!detail::slot(handles,address,slot) || !records[slot].owned)return nullptr;
        const auto current=inspect_handle({ram,ram_bytes},address);if(current.status!=HandleStatus::ready)fail("changed-handle",address,unsigned(current.status));
        const auto& h=current.value;const auto& previous=records[slot].handle;
        if(h.address!=previous.address || h.channels!=previous.channels || h.decoder!=previous.decoder || h.file!=previous.file || h.rna!=previous.rna || h.input!=previous.input || h.route!=previous.route || h.output!=previous.output || h.transfer!=previous.transfer || h.paired_record!=previous.paired_record)fail("replaced-child-identity",address);
        return &records[slot];
    }
    void adopt(){
        for(unsigned slot=0;slot<records.size();++slot){const auto at=handles.base+slot*handles.stride;if(ram[at]!=1)continue;
            auto& r=records[slot];if(r.owned){(void)find(at);continue;}
            const auto h=inspect_handle({ram,ram_bytes},at);
            // Original construction may yield before all opaque children exist.
            // It cannot publish a pending ordinary start until it completes.
            if(h.status!=HandleStatus::ready){if(ram[at+0xac] || ram[at+1])fail("incomplete-active-handle",at,unsigned(h.status));continue;}
            const auto admitted=mapped.adopt(h,table);require(admitted.status,"adopt",at);r={admitted.key,h.value,controls(at),true,false,0};
            S result=S::fault;with(r,[&](auto& p,const auto& key,const auto&){
                result=p.attenuation(key,r.controls.attenuation);if(result!=S::completed)return;
                result=p.set_time_base(key,r.controls.base);if(result!=S::completed)return;
                result=p.set_service_divisor(key,r.controls.divisor);if(result!=S::completed)return;
                result=p.set_loop_enabled(key,r.controls.loop!=0);if(result!=S::completed)return;
                result=p.set_start_inhibit(key,r.controls.inhibit!=0);if(result!=S::completed)return;
                result=p.pause(key,std::bit_cast<std::int8_t>(r.controls.pause),tick());
            });require(result,"initial-controls",at);
        }
    }
    void synchronize(Record& r){
        const auto next=controls(r.handle.address);S result=S::completed;
        with(r,[&](auto& p,const auto& key,const auto&){
            if(next.attenuation!=r.controls.attenuation)result=p.attenuation(key,next.attenuation);if(result!=S::completed)return;
            if(next.base!=r.controls.base)result=p.set_time_base(key,next.base);if(result!=S::completed)return;
            if(next.divisor!=r.controls.divisor)result=p.set_service_divisor(key,next.divisor);if(result!=S::completed)return;
            if(next.loop!=r.controls.loop)result=p.set_loop_enabled(key,next.loop!=0);if(result!=S::completed)return;
            if(next.inhibit!=r.controls.inhibit)result=p.set_start_inhibit(key,next.inhibit!=0);if(result!=S::completed)return;
            if(next.pause!=r.controls.pause)result=p.pause(key,std::bit_cast<std::int8_t>(next.pause),tick());
        });require(result,"controls",r.handle.address);r.controls=next;
    }
    instances::Observation inspect(Record& r){instances::Observation result;with(r,[&](auto& p,const auto& key,const auto&){result=p.inspect(key);});require(result.status,"inspect",r.handle.address);return result;}
    void mirror(Record& r){
        if(!r.source)return;const auto observed=inspect(r);if(observed.starts!=r.expected_start)return;
        if(!observed.source || observed.source->fault)fail("source-fault",r.handle.address);
        const auto& s=*observed.source;const auto at=r.handle.address;
        ram[at+1]=s.configured?static_cast<std::uint8_t>(s.playback.phase):1;
        ram[at+0x71]=s.playback.started?1:0;store(ram,at+0x48,s.playback.request_samples);
        store(ram,at+0x9c,s.clock.estimate_base);store(ram,at+0xa0,s.clock.tick_base);ram[at+0x72]=s.clock.paused;
    }
    void set_order(){
        std::array<std::uint32_t,2041> raw{};const auto copied=order->copy(raw);if(copied.status!=pcm_bridge::Status::ok || copied.value>raw.size())fail("raw-order",0,unsigned(copied.status));
        std::array<GameKey,16> keys;std::array<bool,16> seen{};unsigned count{};
        for(unsigned i=0;i<copied.value;++i)for(unsigned slot=0;slot<records.size();++slot){auto& r=records[slot];if(r.owned && raw[i]==r.handle.route){if(seen[slot])fail("duplicate-raw-route",r.handle.address);seen[slot]=true;keys[count++]=r.key;}}
        for(unsigned slot=0;slot<records.size();++slot){auto& r=records[slot];if(!r.owned || seen[slot])continue;if(r.source || ram[r.handle.address+0xac])fail("active-raw-route-missing",r.handle.address);keys[count++]=r.key;}
        require(mapped.set_order(std::span(keys).first(count)),"source-order");
    }
    void start_pending(Record& r){
        const auto at=r.handle.address;if(!ram[at+0xac])return;if(ram[at+2]!=1 || ram[at+1]!=1)fail("pending-source-kind",at);
        const auto name=load<std::uint32_t>(ram,at+0xb4);if(!name || name>ram_bytes-256)fail("filename-pointer",at);
        std::array<char,256> text{};unsigned n{};for(;n<text.size();++n){text[n]=static_cast<char>(ram[name+n]);if(!text[n])break;}if(n==text.size())fail("filename-length",at);
        auto prepared=prepare_file_source(mount,{std::string_view(text.data(),n),load<std::uint32_t>(ram,at+0xb8),load<std::uint32_t>(ram,at+0xbc),load<std::uint32_t>(ram,at+0xc0)});
        if(prepared.status!=FileStatus::ready)fail("file-source",at,unsigned(prepared.status));
        instances::Source source;source.input=std::move(prepared.view);source.player.decoder.channels=r.handle.channels;source.player.initial_tick=tick();source.player.decoder.source_config.byte_length=static_cast<std::int32_t>(prepared.bytes);
        S result=S::fault;std::uint64_t expected{};
        with(r,[&](auto& p,const auto& key,const auto&){expected=p.inspect(key).starts+1;result=p.start(key,std::move(source));});require(result,"start",at);
        r.expected_start=expected;r.source=true;ram[at+0xac]=0;ram[at+0x71]=0;
    }
    void service(){
        import_clock();adopt();for(auto& r:records)if(r.owned)synchronize(r);set_order();for(auto& r:records)if(r.owned)start_pending(r);
        require(mapped.service(tick()),"group");for(auto& r:records)if(r.owned)mirror(r);publish_clock();
    }
    void stop(Record& r){S result=S::fault;with(r,[&](auto& p,const auto& key,const auto&){result=p.stop(key);});require(result,"stop",r.handle.address);r.source=false;}
    void destroy(std::uint32_t rna){
        for(auto& r:records)if(r.owned && r.handle.rna==rna){
            for(;;){const auto result=mapped.destroy(r.key);if(result==S::completed){r={};return;}
                if(result==S::closed && source_owner->report().joined){r={};return;}
                require(result,"destroy",r.handle.address);
                if(stopping.load(std::memory_order_acquire))throw Closing{};
                // Actual native file workers need no guest callbacks or RPC.
                // Child storage cannot be freed/reused until they acknowledge.
                std::this_thread::yield();
            }
        }
    }
    std::uint32_t output_pointer(std::uint32_t raw){
        const auto segment=raw&0xe0000000u,at=raw&0x1fffffffu;
        if((segment && segment!=0x80000000u && segment!=0xa0000000u) || at<0x10000 || at>ram_bytes-4 || at%4)fail("query-output",raw);
        // This first profile excludes aliases into audio state/tables. It does
        // not invent atomic-snapshot equivalence for self-mutating pointers.
        if(at>=0x20b958 && at<0x224d00)fail("query-state-alias",raw);return at;
    }
    bool dispatch(Action action,std::uint32_t address,R5900Context& c){
        const auto at=GPR_U32((&c),4);
        if(action==Action::group){service();return true;}
        if(action==Action::destroy_child){destroy(at);return false;}
        if(action==Action::unsupported)fail("unsupported-producer",address);
        if(action==Action::callback){if(GPR_U32((&c),5))fail("before-pcm-callback",address);return false;}
        auto* record=find(at);if(!record)return false;
        if(action==Action::stop){stop(*record);return false;}
        import_clock();synchronize(*record);
        if(action==Action::pause){
            const auto argument=std::bit_cast<std::int32_t>(GPR_U32((&c),5));S result=S::fault;with(*record,[&](auto& p,const auto& key,const auto&){result=p.pause(key,argument,tick());});require(result,"pause",at);
            ram[at+0x72]=static_cast<std::uint8_t>(argument);record->controls.pause=ram[at+0x72];mirror(*record);publish_clock();return true;
        }
        const auto observed=inspect(*record);
        if(!record->source || observed.starts!=record->expected_start || !observed.source)return false;
        const auto& state=*observed.source;
        if(action==Action::discard){
            // The original second argument is unused; this operation is not a
            // seek or a request to consume that many samples. The canonical
            // Session services the actual group only for a nonzero pause byte,
            // then rebases from fresh queues. It does not poll source workers.
            // Refresh the actual voice permutation before that group visit.
            if(state.clock.paused){adopt();for(auto& r:records)if(r.owned)synchronize(r);set_order();}
            adxt_control_session::ClockControl result;
            with(*record,[&](auto& p,const auto& key,const auto&){result=p.discard_rebase(key,tick());});
            if(result.status!=adxt_control_session::Status::completed)fail("discard-rebase",at,unsigned(result.status));
            for(auto& r:records)if(r.owned)mirror(r);publish_clock();
            SET_GPR_S32((&c),2,0);return true;
        }
        if(action==Action::total || action==Action::frequency || action==Action::channels){
            std::uint32_t value{};if(ram[at+1]>=2)value=action==Action::total?state.decoder.header.base.total_samples:action==Action::frequency?state.decoder.header.base.frequency:state.decoder.header.base.channels;
            SET_GPR_S32((&c),2,std::bit_cast<std::int32_t>(value));return true;
        }
        if(action==Action::centiseconds){
            adxt_control_session::ClockResult result;with(*record,[&](auto& p,const auto& key,const auto&){result=p.centiseconds(key,tick());});if(result.status!=adxt_control_session::Status::completed)fail("centiseconds",at,unsigned(result.status));SET_GPR_S32((&c),2,std::bit_cast<std::int32_t>(result.value.result.value));mirror(*record);publish_clock();return true;
        }
        const auto numerator=output_pointer(GPR_U32((&c),5)),denominator=output_pointer(GPR_U32((&c),6));if(numerator==denominator)fail("query-output-alias",address);
        adxt_integer_clock::Ratio ratio{};
        if(action==Action::estimate){
            adxt_control_session::ClockResult result;with(*record,[&](auto& p,const auto& key,const auto&){result=p.estimate(key,tick());});if(result.status!=adxt_control_session::Status::completed)fail("estimate",at,unsigned(result.status));ratio=result.value.result.ratio;
        }else{
            adxt_control_session::RatioResult result;with(*record,[&](auto& p,const auto& key,const auto&){result=p.ratio(key,action==Action::rna_ratio?adxt_integer_clock::Query::rna_ratio:adxt_integer_clock::Query::decoded_minus_queued);});if(result.status!=adxt_control_session::Status::completed)fail("ratio",at,unsigned(result.status));ratio=result.value.ratio;
        }
        store(ram,numerator,ratio.numerator);store(ram,denominator,ratio.denominator);mirror(*record);publish_clock();return true;
    }
};
std::mutex installed_mutex;std::shared_ptr<Binding> installed;
std::shared_ptr<Binding> current(){std::lock_guard lock(installed_mutex);return installed;}
template<Action What,std::uint32_t Address,Function Original>
void dispatch(std::uint8_t* ram,R5900Context* c,PS2Runtime* runtime){
    const auto binding=current();if(!binding || !binding->active.load(std::memory_order_acquire)){Original(ram,c,runtime);return;}
    try{
        if(!c || binding->runtime!=runtime || binding->ram!=ram || !ps2ActualGuestExecutionDepth(runtime))binding->fail("guest-identity",Address);
        if(binding->stopping.load(std::memory_order_acquire))throw Closing{};
        if(binding->dispatch(What,Address,*c))c->pc=GPR_U32(c,31);else Original(ram,c,runtime);
    }catch(const Closing&){if(c)c->pc=0;}
}
struct Entry {std::uint32_t address;Function original,wrapper;};
const Entry entries[]{
#define X(address,name,action) {address,name,dispatch<Action::action,address,name>},
#include "ordinary_entries.inc"
#undef X
};
}
sound_ram::InstallResult install_ordinary_before_run(PS2Runtime& runtime,const reo_cd_async::ConfigurationReceipt& cd,bank_packets::v3::MemoryIdentity identity)noexcept{
    using I=sound_ram::InstallStatus;std::shared_ptr<Binding> binding;std::size_t changed{};bool selected{};
    try{
        auto setup=runtime.acquirePreRunSetup();if(!setup)return{I::phase_closed};auto* ram=runtime.memory().getRDRAM();if(!image(ram))return{I::unsupported_layout};
        // Process-wide SDK selection is single-runtime. A stopped flag alone
        // is not a proof that an earlier runtime's guest wrappers drained.
        const auto old=current();if(old && old->active.load(std::memory_order_acquire))return{I::publication_refused};
        for(const auto& entry:entries)if(!runtime.hasFunction(entry.address) || runtime.lookupFunction(entry.address)!=entry.original)return{I::unsupported_layout};
        auto mount=reo_native_resource_reads::retain_mount_before_run(runtime,ram,ram_bytes);if(!mount)return{I::memory_unavailable};
        std::array<std::uint32_t,adxt_attenuation::table_words> words{};std::memcpy(words.data(),ram+0x220498,sizeof(words));const auto table=adxt_attenuation::Table::from_words(words);if(!table.table)return{I::unsupported_layout};
        adxt_control_session::Config config;config.output.stream_gains=std::make_shared<Gains>();auto owner=std::make_shared<control_owner::Owner>(std::move(config));
        binding=std::make_shared<Binding>(runtime,ram,std::move(owner),std::move(mount),table.table);
        S started=S::fault;binding->control([&](auto& p){started=p.start_output();});binding->require(started,"submix-start");
        if(!runtime.registerExternalWorker(binding)){(void)binding->source_owner->join();return{I::publication_refused};}
        {std::lock_guard lock(installed_mutex);installed=binding;}
        // Known existing registry slots are replaced while the pre-run lease
        // excludes guest execution. Every wrapper remains inert until selection.
        for(const auto& entry:entries){runtime.registerFunction(entry.address,entry.wrapper);++changed;}
        auto media=sound_ram::install_prepared_native_sources(runtime,cd,identity,binding->source_owner);
        if(media.backend.status!=I::installed){
            binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,entries[i].original);(void)binding->source_owner->join();return media.backend;
        }
        selected=true;binding->order=std::move(media.pcm_order);if(!binding->order){std::fputs("[NATIVE-ADXT-FATAL] selected factory omitted order capability\n",stderr);std::abort();}
        binding->active.store(true,std::memory_order_release);
        std::fprintf(stderr,"[NATIVE-ADXT] ordinary-file binding selected entries=%zu source_owner=canonical original_pcm=refused lsc_sj_callbacks=unsupported\n",std::size(entries));return media.backend;
    }catch(...){
        if(selected){std::fputs("[NATIVE-ADXT-FATAL] exception after backend selection\n",stderr);std::abort();}
        if(binding){binding->requestStop();for(std::size_t i=0;i<changed;++i)runtime.registerFunction(entries[i].address,entries[i].original);(void)binding->source_owner->join();}
        return{I::allocation_failed};
    }
}
}
