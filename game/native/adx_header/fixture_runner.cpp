// Authored input and prepared-state convention only; no expected outputs.
#include "adx_header.hpp"
#include <bit>
#include <fstream>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>

namespace h=reo::native::adx_header;
namespace r=reo::native::adxt_refill;
namespace {
void require(bool ok,const char* message) {if(!ok) throw std::runtime_error(message);}
std::int16_t s16(std::uint16_t n) {return std::bit_cast<std::int16_t>(n);}
std::vector<std::uint8_t> unhex(const std::string& input) {
    std::vector<std::uint8_t> bytes;
    if(input!="-") for(std::size_t i=0;i<input.size();i+=2) bytes.push_back(static_cast<std::uint8_t>(std::stoul(input.substr(i,2),nullptr,16)));
    return bytes;
}
std::string hex(std::span<const std::uint8_t> bytes) {
    constexpr char digits[]="0123456789abcdef";std::string text;
    for(auto byte:bytes) {text+=digits[byte>>4];text+=digits[byte&15];}return text;
}
template<class T>void array_json(const T& array) {
    std::cout<<'[';bool first=true;for(auto value:array) {if(!first) std::cout<<',';first=false;std::cout<<+value;}std::cout<<']';
}
void ring_json(const reo::native::sjrb::Snapshot& q) {
    std::cout<<'['<<q.capacity<<','<<q.extension<<','<<q.data<<','<<q.free<<','<<q.write<<','<<q.read;
    for(auto total:q.totals) std::cout<<','<<total;
    std::cout<<']';
}
void geometry_json(const h::PcmGeometry& g) {std::cout<<'['<<g.capacity_samples<<','<<g.spacing_samples<<','<<g.binding_role<<']';}
void decoder_json(const h::DecoderState& d) {
    std::cout<<"{\"phase\":"<<d.header_phase<<",\"base\":["<<+d.base.encoding<<','<<+d.base.bits<<','<<+d.base.block_bytes<<','<<+d.base.channels
        <<','<<d.base.frequency<<','<<d.base.total_samples<<','<<d.base.samples_per_block<<"],\"filter\":"<<d.filter<<",\"tag\":"<<d.format_tag<<",\"configured_key\":";
    array_json(d.configured_key);std::cout<<",\"history\":";array_json(d.predictor.history);
    std::cout<<",\"coefficients\":";array_json(d.predictor.coefficients);std::cout<<",\"key\":";array_json(d.predictor.key);
    std::cout<<",\"loop\":["<<d.loop.count<<','<<d.loop.enabled<<','<<d.loop.index;for(auto value:d.loop.positions) std::cout<<','<<value;
    std::cout<<"],\"ainf\":{\"value\":"<<d.ainf.value<<",\"payload\":\""<<hex(d.ainf.payload)<<"\",\"halves\":["<<d.ainf.code<<','<<d.ainf.halves[0]<<','<<d.ainf.halves[1]
        <<"]},\"borrowed_pcm\":";geometry_json(d.borrowed_pcm);std::cout<<",\"active_pcm\":";geometry_json(d.active_pcm);
    std::cout<<",\"output_channels\":"<<d.output_channels<<",\"active\":["<<d.active_channels<<','<<d.active_block_bytes<<','<<d.active_samples_per_block<<','<<d.output_cursor<<"]}";
}
void state_json(const h::Snapshot& s,const reo::native::sjrb::Snapshot& ring,const h::KeyContext& keys) {
    std::cout<<"{\"decoder\":";decoder_json(s.decoder);
    std::cout<<",\"outer\":["<<+s.outer_state<<','<<s.end_flag<<','<<s.accepted_header_bytes<<"],\"ring\":";ring_json(ring);
    std::cout<<",\"keys\":["<<keys.module_references;for(auto key:keys.fallback) std::cout<<','<<key;std::cout<<"]}";
}
h::Snapshot prepared(const h::Key& configured) {
    // Exactly the declared synthetic setup in the independent original oracle,
    // represented as named typed values. These are inputs, never expected output.
    h::Snapshot s;s.outer_state=1;s.accepted_header_bytes=0x5A5A5A5A;auto& d=s.decoder;
    d.header_phase=0x6D6D;d.base.encoding=d.base.bits=d.base.block_bytes=d.base.channels=0x6D;
    d.base.frequency=d.base.total_samples=0x6D6D6D6D;d.base.samples_per_block=0x6D6D6D6D;
    d.filter=d.format_tag=0x6D6D;d.configured_key=configured;d.predictor.history.fill(0x4B4B);d.predictor.coefficients.fill(0x4B4B);d.predictor.key.fill(0x4B4B);
    d.loop={0x6D6D6D6D,0x6D6D,0x6D6D,{0x6D6D6D6D,0x6D6D6D6D,0x6D6D6D6D,0x6D6D6D6D}};
    d.ainf.value=0x6D6D6D6D;d.ainf.payload.fill(0x6D);d.ainf.code=0x6D6D;d.ainf.halves.fill(0x6D6D);
    d.borrowed_pcm={8192,8288,1};d.active_pcm={0x6D6D6D6D,0x6D6D6D6D,0};d.output_channels=2;
    d.active_channels=d.active_block_bytes=d.active_samples_per_block=d.output_cursor=0x6D6D6D6D;return s;
}
class View final : public reo::native::resources::ByteView {
public:
    std::uint64_t size() const noexcept override {return 16384;}
    reo::native::resources::ReadResult read(std::uint64_t,std::span<std::byte>) const override {std::terminate();}
};
class Backend final : public r::Backend {
public:
    r::Acceptance submit(std::shared_ptr<const reo::native::resources::ByteView>,std::uint64_t,std::uint32_t,std::uint64_t) noexcept override {std::terminate();}
    r::Completion poll() noexcept override {return {};}
    bool shutdown_and_join() noexcept override {return true;}
};
struct Observer {
    r::EncodedSource* source{};h::KeyContext* keys{};std::size_t count{};
    struct Event {h::Diagnostic kind{};h::Snapshot state;reo::native::sjrb::Snapshot ring;h::KeyContext keys;};
    std::array<Event,4> events{};
    static void diagnostic(void* p,h::Diagnostic kind,const h::Snapshot& s) noexcept {
        auto& self=*static_cast<Observer*>(p);if(self.count==self.events.size()) std::terminate();
        self.events[self.count++]={kind,s,self.source->snapshot().ring,*self.keys};
    }
};
} // namespace
int main(int argc,char** argv) {
    try {
        require(argc==2,"Expected input-only transcript");std::ifstream input(argv[1]);require(bool(input),"Cannot read input");
        std::string kind,text;std::int32_t position,length,rate,filter;h::Key configured{},fallback{};
        input>>kind>>position>>length>>rate>>filter;for(auto& value:configured) input>>value;for(auto& value:fallback) input>>value;input>>text;
        auto bytes=unhex(text);require(length>=0 && static_cast<std::size_t>(length)<=bytes.size(),"Invalid supplied length");
        r::Config c;c.capacity=2048;c.byte_length=4096;c.threshold=2048;c.maximum_request_bytes=2048;
        auto source=std::make_shared<r::EncodedSource>(c,std::make_shared<View>(),std::make_unique<Backend>(),r::Hooks{},r::InitialBuffer{position,bytes});
        auto keys=std::make_shared<h::KeyContext>();keys->fallback=fallback;auto state=prepared(configured);
        Observer observer;observer.source=source.get();observer.keys=keys.get();h::Status status=h::Status::completed;
        std::int32_t result{};bool defined=true;std::string helper="null";
        auto data=std::span<const std::uint8_t>(bytes).first(static_cast<std::size_t>(length));
        if(kind=="outer") {
            h::HeaderOwner owner(source,keys,state,{&observer,Observer::diagnostic});status=owner.service();state=owner.snapshot();defined=false;
        } else if(kind=="math") {
            std::array<std::int16_t,2> output{0x5A5A,0x5A5A};status=h::coefficients(static_cast<std::uint32_t>(rate),s16(static_cast<std::uint16_t>(filter)),output);
            helper='['+std::to_string(output[0])+','+std::to_string(output[1])+']';defined=false;
        } else if(kind=="base") {
            h::Base output{0x5A5A,0x5A,0x5A,0x5A,0x5A,0x5A5A5A5A,0x5A5A5A5A,0x5A5A5A5A};result=h::parse_base(data,output);
            helper='['+std::to_string(static_cast<std::uint16_t>(output.header_bytes))+','+std::to_string(static_cast<std::uint8_t>(output.encoding))+','+
                std::to_string(static_cast<std::uint8_t>(output.bits))+','+std::to_string(static_cast<std::uint8_t>(output.block_bytes))+','+
                std::to_string(static_cast<std::uint8_t>(output.channels))+','+std::to_string(output.frequency)+','+std::to_string(output.total_samples)+','+std::to_string(output.samples_per_block)+']';
        } else if(kind=="version") {
            h::Version output{0x5A,0x5A};result=h::parse_version(data,output);helper='['+std::to_string(output.number)+','+std::to_string(output.control)+']';
        } else if(kind=="filter") {
            std::int16_t output=0x5A5A;result=h::parse_filter(data,output);helper='['+std::to_string(static_cast<std::uint16_t>(output))+']';
        } else if(kind=="history") {
            h::Histories output{{0x5A5A,0x5A5A},{0x5A5A,0x5A5A}};result=h::parse_history(data,output);helper="[";
            for(auto value:{output.first[0],output.first[1],output.second[0],output.second[1]}) {if(helper!="[") helper+=',';helper+=std::to_string(static_cast<std::uint16_t>(value));}helper+=']';
        } else if(kind=="loop") {
            h::Loop output{0x5A5A5A5A,0x5A5A,0x5A5A,{0x5A5A5A5A,0x5A5A5A5A,0x5A5A5A5A,0x5A5A5A5A}};result=h::parse_loop(data,output);
            helper='['+std::to_string(output.count)+','+std::to_string(output.enabled)+','+std::to_string(output.index);for(auto value:output.positions) helper+=','+std::to_string(value);helper+=']';
        } else if(kind=="ainf") {
            h::Ainf output;output.value=0x5A5A5A5A;output.payload.fill(0x5A);output.code=0x5A5A;output.halves.fill(0x5A5A);result=h::parse_ainf(data,output);
            helper="{\"value\":"+std::to_string(output.value)+",\"payload\":\""+hex(output.payload)+"\",\"halves\":["+std::to_string(output.code)+','+std::to_string(output.halves[0])+','+std::to_string(output.halves[1])+"]}";
        } else if(kind=="key") {
            require(bytes.size()>=20,"Missing key helper input");const auto samples=(std::uint32_t(bytes[12])<<24)|(std::uint32_t(bytes[13])<<16)|(std::uint32_t(bytes[14])<<8)|bytes[15];
            const auto output=h::select_key(bytes[18],bytes[19],samples,state.decoder.configured_key,*keys);
            helper='['+std::to_string(output[0])+','+std::to_string(output[1])+','+std::to_string(output[2])+']';
        } else throw std::runtime_error("Unsupported authored kind");
        std::cout<<"{\"status\":"<<static_cast<int>(status)<<",\"state\":";state_json(state,source->snapshot().ring,*keys);
        std::cout<<",\"return\":"<<(defined?std::to_string(result):"null")<<",\"helper\":"<<helper<<",\"diagnostics\":[";
        for(std::size_t n=0;n<observer.count;++n) {
            if(n) std::cout<<',';
            const auto& event=observer.events[n];std::cout<<"{\"kind\":"<<static_cast<int>(event.kind)<<",\"state\":";
            state_json(event.state,event.ring,event.keys);std::cout<<'}';
        }
        std::cout<<"]}\n";
    } catch(const std::exception& error) {std::cerr<<error.what()<<'\n';return 1;}
}
