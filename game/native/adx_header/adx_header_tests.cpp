#include "adx_header.hpp"
#include <bit>
#include <cfenv>
#include <cstdio>
#include <cstdlib>
#include <immintrin.h>
#include <new>
#include <vector>

bool deny_allocations{};
__attribute__((noinline)) void* operator new(std::size_t size) {
    if(deny_allocations) throw std::bad_alloc();
    if(void* memory=std::malloc(size?size:1)) return memory;
    throw std::bad_alloc();
}
__attribute__((noinline)) void operator delete(void* pointer) noexcept {std::free(pointer);}
__attribute__((noinline)) void operator delete(void* pointer,std::size_t) noexcept {std::free(pointer);}

namespace h=reo::native::adx_header;
namespace refill=reo::native::adxt_refill;
namespace {
int checks{};
void check(bool value,const char* message) {
    ++checks;if(!value) {std::fprintf(stderr,"FAILED: %s\n",message);std::abort();}
}
void be16(std::vector<std::uint8_t>& data,std::size_t at,std::uint16_t value) {
    data[at]=static_cast<std::uint8_t>(value>>8);data[at+1]=static_cast<std::uint8_t>(value);
}
void be32(std::vector<std::uint8_t>& data,std::size_t at,std::uint32_t value) {
    for(int n=0;n<4;++n) data[at+static_cast<std::size_t>(n)]=static_cast<std::uint8_t>(value>>(24-8*n));
}
std::vector<std::uint8_t> header(std::uint32_t rate=44100,std::uint8_t version=3) {
    std::vector<std::uint8_t> data(96);be16(data,0,0x8000);be16(data,2,92);
    data[4]=3;data[5]=18;data[6]=4;data[7]=1;be32(data,8,rate);be32(data,12,1000);
    be16(data,16,500);data[18]=version;return data;
}
h::DecoderState initial_state() {
    h::DecoderState state;
    state.header_phase=0x6D6D;state.base.frequency=0x6D6D6D6D;state.base.total_samples=0x6D6D6D6D;
    state.filter=0x6D6D;state.format_tag=0x6D6D;state.output_cursor=0x6D6D6D6D;
    state.predictor.history.fill(0x4B4B);state.predictor.coefficients.fill(0x4B4B);state.predictor.key.fill(0x4B4B);
    state.borrowed_pcm={8192,8288,1};state.active_pcm={0x6D6D6D6D,0x6D6D6D6D,0x6D6D6D6D};state.output_channels=2;
    state.active_channels=state.active_block_bytes=state.active_samples_per_block=0x6D6D6D6D;
    state.loop={0x6D6D6D6D,0x6D6D,0x6D6D,{0x6D6D6D6D,0x6D6D6D6D,0x6D6D6D6D,0x6D6D6D6D}};
    state.ainf.value=0x6D6D6D6D;state.ainf.payload.fill(0x6D);state.ainf.code=0x6D6D;state.ainf.halves.fill(0x6D6D);
    return state;
}
struct Environment {
    std::fenv_t env{};std::uint32_t mxcsr=_mm_getcsr();
    Environment() {check(std::fegetenv(&env)==0,"unit saves environment");}
    ~Environment() {(void)std::fesetenv(&env);_mm_setcsr(mxcsr);}
};
void math_and_environment() {
    Environment restore;
    check(h::supported_fp_environment(),"normal profile ambient environment");
    const std::array<std::uint32_t,3> rates{24000,44100,48000};
    const std::array<std::array<std::int16_t,2>,3> values{{{6687,-2729},{7334,-3283},{7400,-3342}}};
    for(std::size_t n=0;n<3;++n) {
        _mm_setcsr(0x1FA0);std::array<std::int16_t,2> result{};
        check(h::coefficients(rates[n],500,result)==h::Status::completed && result==values[n],"source-derived complete finite math");
        check(_mm_getcsr()==0x1FA0,"caller accrued FP flags preserved");
    }
    for(const auto csr:{0x3F80u,0x5F80u,0x7F80u,0x9F80u,0x1FC0u,0x1F00u}) {
        _mm_setcsr(csr);std::array<std::int16_t,2> result{123,456};
        check(h::coefficients(44100,500,result)==h::Status::unsupported_fp_environment,"unsupported ambient mode refuses");
        check(_mm_getcsr()==csr && result==std::array<std::int16_t,2>{123,456},"ambient refusal never reconfigures or writes output");
    }
    _mm_setcsr(0x1F80);std::array<std::int16_t,2> result{123,456};
    check(h::coefficients(0,500,result)==h::Status::unsupported_profile,"zero rate not guessed");
    check(h::coefficients(44100,8000,result)==h::Status::unsupported_profile,"argument reduction unsupported");
    check(result==std::array<std::int16_t,2>{123,456},"profile refusal leaves output intact");
}
void pure_selective_parsers() {
    auto data=header();h::Base base;
    check(h::parse_base(data,base)==0 && base.frequency==44100 && base.total_samples==1000 && base.samples_per_block==32,"base integer fields");
    data[5]=255;data[6]=255;data[7]=255;be32(data,8,0xFFFFFFFF);be32(data,12,0x80000001);
    check(h::parse_base(data,base)==0 && base.samples_per_block==24 && base.channels==-1 && base.frequency==0xFFFFFFFF,"signed source bytes and raw words");
    be16(data,2,0xFFFE);check(h::parse_base(data,base)==0 && base.header_bytes==2,"header halfword wrap");
    auto saved=base;check(h::parse_base(std::span(data).first(15),base)==-1 && base.frequency==saved.frequency,"short base leaves output");
    data=header(44100,4);be16(data,24,0x1234);be16(data,26,0xFEDC);be16(data,28,0x5678);be16(data,30,0xBA98);
    h::Histories history;
    check(h::parse_history(data,history)==0 && std::uint16_t(history.first[1])==0x5678 && std::uint16_t(history.second[0])==0xFEDC,"history array layout");
    h::Loop loop{77,123,456,{1,2,3,4}};
    check(h::parse_loop(data,loop)==-2 && loop.enabled==0 && loop.count==0 && loop.index==456 && loop.positions[3]==4,"absent loop selective clear");
    h::Ainf ainf;ainf.value=77;ainf.payload.fill(0x5A);ainf.code=123;
    check(h::parse_ainf(data,ainf)==-2 && ainf.value==0 && ainf.payload[0]==0x5A && ainf.code==123,"absent AINF selective clear");
    data[18]=3;check(h::parse_history(data,history)==0 && history.first==std::array<std::int16_t,2>{} && history.second==std::array<std::int16_t,2>{},"old history version zeroes both arrays");
    h::KeyContext context{0,{23456,7,65527}};h::Key configured{};
    check(h::select_key(4,8,1000,configured,context)==h::Key{23456,7,65527} && configured==context.fallback,"fallback cache copied");
    check(h::select_key(4,16,0xFEDCBA98,configured,context)==h::Key{17383,19867,21787},"actual owned-table derivation");
    check(context.module_references==1,"lazy key-module transition");
    check(h::select_key(3,255,1000,configured,context)==h::Key{},"version lower than4 has zero key");
}
void pure_full_header() {
    h::KeyContext context{0,{23456,7,65527}};auto state=initial_state();auto data=header(44100,4);
    data[19]=8;be16(data,24,0x1234);be16(data,26,0xFEDC);be16(data,28,0x5678);be16(data,30,0xBA98);
    const auto result=h::decode_header(data,state,context);
    check(result.status==h::Status::completed && result.source_result==96,"full native parser return");
    check(state.header_phase==1 && state.format_tag==0 && state.output_cursor==0,"full selective publication fields");
    check(state.predictor.coefficients==std::array<std::int16_t,2>{7334,-3283},"coefficient stores source-derived");
    check(state.predictor.history==std::array<std::int16_t,4>{0x1234,std::bit_cast<std::int16_t>(std::uint16_t(0xFEDC)),0x5678,std::bit_cast<std::int16_t>(std::uint16_t(0xBA98))},"predictor history interleave");
    check(state.active_pcm==state.borrowed_pcm && state.active_channels==1 && state.active_block_bytes==18,"PCM metadata copied without storage allocation");
    state=initial_state();data=header();data.resize(19);
    check(h::decode_header(data,state,context).source_result==0 && state.header_phase==1 && state.base.frequency==44100,"short version keeps base effects");
    check(state.predictor.key==h::Key{0x4B4B,0x4B4B,0x4B4B},"short version never installs key");
    state=initial_state();data=header(0);const auto initial=state;
    check(h::decode_header(data,state,context).status==h::Status::unsupported_profile,"unsupported math admission before state");
    check(state==initial,"unsupported source partial not invented");
    Environment env;_mm_setcsr(0x9F80);data=header();state=initial_state();
    check(h::decode_header(data,state,context).status==h::Status::unsupported_fp_environment && state.header_phase==0x6D6D,"FP mode refusal before parser effects");
}
class NoRead final : public reo::native::resources::ByteView {
public:
    std::uint64_t size() const noexcept override {return 16384;}
    reo::native::resources::ReadResult read(std::uint64_t,std::span<std::byte>) const override {std::abort();}
};
class NoBackend final : public refill::Backend {
public:
    refill::Acceptance submit(std::shared_ptr<const reo::native::resources::ByteView>,std::uint64_t,std::uint32_t,std::uint64_t) noexcept override {std::abort();}
    refill::Completion poll() noexcept override {return {};}
    bool shutdown_and_join() noexcept override {return true;}
};
std::shared_ptr<refill::EncodedSource> source(std::span<const std::uint8_t> data,std::int32_t position=0) {
    refill::Config c;c.capacity=2048;c.byte_length=4096;c.threshold=2048;c.maximum_request_bytes=2048;
    return std::make_shared<refill::EncodedSource>(c,std::make_shared<NoRead>(),std::make_unique<NoBackend>(),refill::Hooks{},refill::InitialBuffer{position,data});
}
struct Observed {
    h::HeaderOwner* owner{};refill::EncodedSource* source{};int count{};std::array<h::Snapshot,2> states{};
    std::array<std::int32_t,2> data{};std::array<h::Status,2> reentry{};
    static void callback(void* raw,h::Diagnostic,const h::Snapshot& state) noexcept {
        auto& observer=*static_cast<Observed*>(raw);const auto n=static_cast<std::size_t>(observer.count++);
        if(n>=2) std::abort();
        observer.states[n]=state;observer.data[n]=observer.source->snapshot().ring.data;
        observer.reentry[n]=observer.owner->service();
    }
};
void shared_source_owner() {
    auto keys=std::make_shared<h::KeyContext>();auto data=header();auto input=source(data);
    h::Snapshot initial;initial.decoder=initial_state();initial.accepted_header_bytes=0x5A5A5A5A;
    h::HeaderOwner owner(input,keys,initial);
    check(owner.service()==h::Status::completed && owner.snapshot().outer_state==2,"actual shared-source header state2");
    auto ring=input->snapshot().ring;check(ring.data==0 && ring.free==2048 && ring.read==96 && ring.write==96,"actual header prefix/free credit");
    check(owner.snapshot().accepted_header_bytes==96 && !owner.snapshot().lease_held,"header length and lease retired");
    check(owner.service()==h::Status::inactive,"ready header no repeated borrow");
    input=source(data,2030);const auto before=input->snapshot().ring;h::HeaderOwner wrapped(input,keys,initial);
    check(wrapped.service()==h::Status::completed && wrapped.snapshot().outer_state==1,"wrapped54 declared96 defers");
    check(input->snapshot().ring==before && wrapped.snapshot().accepted_header_bytes==0x5A5A5A5A,"defer restores full actual input credit");
    check(wrapped.snapshot().decoder.predictor.coefficients==std::array<std::int16_t,2>{7334,-3283},"defer preserves completed selective parse");
    data=header(0);input=source(data);const auto unsupported_before=input->snapshot().ring;
    h::HeaderOwner unsupported(input,keys,initial);
    check(unsupported.service()==h::Status::unsupported_profile,"owner reports unsupported rather than original fallback");
    check(input->snapshot().ring==unsupported_before && unsupported.snapshot().decoder.header_phase==0x6D6D,"unsupported parser effects absent, ring credit returned");
    data=header();data[4]=5;input=source(data);Observed observer;observer.source=input.get();
    h::HeaderOwner rejected(input,keys,initial,{&observer,Observed::callback});observer.owner=&rejected;
    check(rejected.service()==h::Status::completed && rejected.snapshot().outer_state==4,"AHX absent plugin rejection");
    check(observer.count==2 && observer.states[0].lease_held && !observer.states[1].lease_held,"diagnostic source borrow ordering");
    check(observer.data[0]==0 && observer.data[1]==96 && observer.states[1].outer_state==1,"diagnostic sees credit return before state4");
    check(observer.reentry[0]==h::Status::reentrant_call && observer.reentry[1]==h::Status::reentrant_call,"diagnostic mutation refused");
    data=header();input=source(data);std::weak_ptr<refill::EncodedSource> weak=input;
    {h::HeaderOwner retained(input,keys,initial);input.reset();check(!weak.expired(),"header retains actual source lifetime");check(retained.service()==h::Status::completed,"retained source still parses");}
    check(weak.expired(),"normal returned lease permits source release");
    data=header();input=source(data);h::HeaderOwner allocation_free(input,keys,initial);
    deny_allocations=true;const auto no_alloc=allocation_free.service();deny_allocations=false;
    check(no_alloc==h::Status::completed && allocation_free.snapshot().outer_state==2,"whole header service performs no new allocation");
    check(allocation_free.return_held()==h::Status::completed,"explicit no-held retirement is harmless");
    data=header();data.resize(19);input=source(data);h::HeaderOwner short_header(input,keys,initial);
    check(short_header.service()==h::Status::completed && short_header.snapshot().outer_state==1,"short source keeps header state1");
    check(input->snapshot().ring.data==19 && !input->snapshot().consumer_bytes,"short source returns whole actual lease");
}
} // namespace
int main() {
    math_and_environment();pure_selective_parsers();pure_full_header();shared_source_owner();
    std::printf("Native ADX header checks passed: %d assertions\n",checks);
}
