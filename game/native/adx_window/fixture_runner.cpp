// Synthetic input transport and observation only; no expected state is read.
#include "adx_window.hpp"
#include <array>
#include <fstream>
#include <iostream>
#include <memory>
#include <stdexcept>
#include <string>
#include <vector>

using namespace reo::native::adx_window;
namespace {
void require(bool ok,const char* message) { if(!ok) throw std::runtime_error(message); }
std::string hex(std::span<const std::uint8_t> data) {
    static constexpr char digits[]="0123456789abcdef"; std::string out; out.reserve(data.size()*2);
    for(auto c:data) { out+=digits[c>>4];out+=digits[c&15]; } return out;
}
void span_json(const Span& s) { std::cout<<'['<<static_cast<unsigned>(s.buffer)<<','<<s.offset<<','<<s.bytes<<']'; }
void position_json(const reo::native::adx_control::BufferPosition& p) { std::cout<<'['<<p.span.value<<','<<p.word_byte_offset<<']'; }
void snapshot_json(const Snapshot& s,std::uint32_t channels) {
    const auto& o=s.outer; const auto& i=s.inner; const auto& p=s.predictor;
    std::cout<<"{\"outer\":{\"phase\":"<<static_cast<unsigned>(o.phase)<<",\"endflag\":"<<o.end_when_input_empty<<",\"input\":";
    span_json(o.encoded); std::cout<<",\"pcm\":[";
    for(std::uint32_t c=0;c<channels;++c) { if(c) std::cout<<',';span_json(o.pcm[c]); }
    std::cout<<"],\"counters\":["<<o.decoded_samples<<','<<o.encoded_bytes<<','<<o.position<<','<<o.max_request_samples<<','<<o.sample_limit<<','<<o.sample_progress<<','<<o.encoded_progress<<"]},\"inner\":{\"phase\":"<<static_cast<unsigned>(i.phase)<<",\"input\":";
    position_json(i.encoded_input);
    std::cout<<",\"values\":["<<i.input_blocks<<','<<i.sample_offset<<','<<i.available_samples<<','<<i.remaining_samples<<','<<i.decoded_total<<','<<i.local_output_offset<<','<<i.produced_samples<<','<<i.consumed_bytes<<"]},\"predictor\":{\"phase\":"<<static_cast<unsigned>(p.phase)<<",\"completed\":"<<p.completed_units<<",\"mode\":"<<static_cast<unsigned>(p.mode)<<",\"input\":";
    position_json(p.encoded_input); std::cout<<",\"requested\":"<<p.requested_units<<",\"left\":";position_json(p.left_output);
    std::cout<<",\"right\":";position_json(p.right_output);std::cout<<",\"history\":[";
    for(std::size_t n=0;n<4;++n) { if(n) std::cout<<','; std::cout<<p.history[n]; }
    std::cout<<"],\"coefficients\":["<<p.coefficients[0]<<','<<p.coefficients[1]<<"],\"key\":["<<p.key.value<<','<<p.key.multiplier<<','<<p.key.addend<<"]},\"odd\":"<<s.odd_result_flag<<",\"rings\":[";
    for(std::uint32_t c=0;c<=channels;++c) {
        if(c) std::cout<<',';
        const auto& r=s.rings[c];
        std::cout<<'['<<r.capacity<<','<<r.extension<<','<<r.data<<','<<r.free<<','<<r.write<<','<<r.read;
        for(auto total:r.totals) std::cout<<','<<total;
        std::cout<<']';
    }
    std::cout<<"]}";
}
struct PcmRecord {
    std::array<std::uint8_t,max_window_samples*2> payload{};
    std::array<std::array<std::uint8_t,pcm_capacity+pcm_extension>,2> planes{};
};
struct Event { char kind{}; std::uint32_t ring{}; int before{},after{},pcm_record{-1}; std::int32_t offset{},bytes{},code{}; Snapshot state; };
struct Observer {
    Window* owner{}; int depth{}; std::size_t count{},pcm_count{};
    std::array<Event,128> events{};
    std::unique_ptr<std::array<PcmRecord,2>> records=std::make_unique<std::array<PcmRecord,2>>();
    Event& event(char kind,std::uint32_t ring) noexcept {
        if(count>=events.size()) std::terminate();
        auto& e=events[count++]; e={};e.kind=kind;e.ring=ring;e.before=depth;
        if(kind=='E') ++depth;
        if(kind=='L') --depth;
        e.after=depth;e.state=owner->snapshot();return e;
    }
    static void guard(void* p,std::uint32_t ring,bool entering) noexcept { static_cast<Observer*>(p)->event(entering?'E':'L',ring); }
    static void error(void* p,std::uint32_t ring,std::int32_t code) noexcept { auto& s=*static_cast<Observer*>(p); s.event('X',ring).code=code; }
    static void pcm(void* p,std::uint32_t channel,const PcmView& view) noexcept {
        auto& s=*static_cast<Observer*>(p);auto& e=s.event('P',channel);
        if(s.pcm_count>=s.records->size() || view.bytes()<0 || view.bytes()>max_window_samples*2) std::terminate();
        e.pcm_record=static_cast<int>(s.pcm_count++);e.offset=view.offset();e.bytes=view.bytes();
        auto& r=(*s.records)[static_cast<std::size_t>(e.pcm_record)];
        if(view.read(std::span(r.payload).first(static_cast<std::size_t>(view.bytes())))!=reo::native::sjrb::Status::completed) std::terminate();
        for(std::uint32_t i=0;i<s.owner->config().channels;++i)
            if(s.owner->read_pcm_backing(i,r.planes[i])!=Status::completed) std::terminate();
    }
    void clear() { require(depth==0,"Unbalanced native observer");count=0;pcm_count=0; }
};
void backing_json(Window& owner) {
    std::array<std::uint8_t,encoded_capacity+encoded_extension> input{};
    std::array<std::uint8_t,pcm_capacity+pcm_extension> pcm{};
    require(owner.read_encoded_backing(input)==Status::completed,"Cannot read encoded backing");
    std::cout<<",\"encoded_hex\":\""<<hex(input)<<"\",\"pcm_hex\":[";
    for(std::uint32_t c=0;c<owner.config().channels;++c) { if(c) std::cout<<',';require(owner.read_pcm_backing(c,pcm)==Status::completed,"Cannot read PCM backing");std::cout<<'"'<<hex(pcm)<<'"'; }
    std::cout<<']';
}
void emit(Window& owner,Observer& observer,int index,const std::string& action,const Snapshot* replacement=nullptr,const Reservation* reservation=nullptr) {
    std::cout<<"{\"index\":"<<index<<",\"action\":\""<<action<<"\",\"state\":";
    snapshot_json(replacement?*replacement:owner.snapshot(),owner.config().channels);backing_json(owner);
    if(reservation) std::cout<<",\"reservation\":["<<reservation->offset<<','<<reservation->available<<','<<reservation->remaining<<','<<reservation->backing.span.value<<','<<reservation->backing.word_byte_offset<<']';
    std::cout<<",\"events\":[";
    for(std::size_t n=0;n<observer.count;++n) {
        if(n) std::cout<<',';
        const auto& e=observer.events[n];
        std::cout<<"{\"kind\":\""<<e.kind<<"\",\"ring\":"<<e.ring<<",\"before\":"<<e.before<<",\"after\":"<<e.after<<",\"state\":";
        snapshot_json(e.state,owner.config().channels);
        if(e.kind=='P') {
            const auto& p=(*observer.records)[static_cast<std::size_t>(e.pcm_record)];
            std::cout<<",\"offset\":"<<e.offset<<",\"bytes\":"<<e.bytes<<",\"payload\":\""<<hex(std::span<const std::uint8_t>(p.payload).first(static_cast<std::size_t>(e.bytes)))<<"\",\"planes\":[";
            for(std::uint32_t i=0;i<owner.config().channels;++i) { if(i) std::cout<<',';std::cout<<'"'<<hex(p.planes[i])<<'"'; }
            std::cout<<']';
        }
        if(e.kind=='X') std::cout<<",\"code\":"<<e.code;
        std::cout<<'}';
    }
    std::cout<<"]}\n";
}
}

int main(int argc,char** argv) {
    try {
        require(argc==2,"Expected authored command transcript");std::ifstream input(argv[1]);require(bool(input),"Cannot open transcript");
        Observer observer;std::unique_ptr<Window> owner;std::string command;
        while(input>>command) {
            if(command=="NEW") {
                Config c;int downmix,callback,key,multiplier,addend;
                input>>c.channels>>downmix>>c.total_samples>>c.max_request_samples>>c.sample_limit>>callback>>c.initial_encoded_cursor;
                c.downmix=downmix!=0;
                for(std::uint32_t i=0;i<c.channels;++i) input>>c.initial_pcm_cursor[i];
                for(std::uint32_t i=0;i<c.channels;++i) input>>c.initial_pcm_bytes[i];
                for(auto& h:c.history) input>>h;
                for(auto& coefficient:c.coefficients) input>>coefficient;
                input>>key>>multiplier>>addend;c.key=static_cast<std::uint16_t>(key);c.multiplier=static_cast<std::int16_t>(multiplier);c.addend=static_cast<std::int16_t>(addend);
                owner=std::make_unique<Window>(c,Hooks{&observer,Observer::guard,Observer::error,callback?Observer::pcm:nullptr,nullptr});observer.owner=owner.get();
            } else if(command=="FEED") {
                std::string text;input>>text;std::vector<std::uint8_t> bytes;
                if(text!="-") for(std::size_t i=0;i<text.size();i+=2) bytes.push_back(static_cast<std::uint8_t>(std::stoul(text.substr(i,2),nullptr,16)));
                require(owner->feed_encoded(bytes)==Status::completed,"Native feed refused");
            } else if(command=="INITIAL") { observer.clear();emit(*owner,observer,-1,"initial"); }
            else if(command=="ACTION") {
                int index;std::string action;input>>index>>action;observer.clear();
                if(action=="service") {
                    const auto status=owner->service(owner->request());
                    require(status==Status::completed || status==Status::inactive || status==Status::backpressure,"Native service refused admitted action");
                    emit(*owner,observer,index,action);
                } else if(action=="consume64") {
                    for(std::uint32_t i=0;i<owner->config().channels;++i) { std::int32_t count=0;require(owner->consume_pcm(i,64,count)==Status::completed && count==64,"Native consumer refused"); }
                    emit(*owner,observer,index,action);
                } else if(action=="default_reserve") {
                    // Authored oracle helper prewrites7/12, not expected results.
                    auto state=owner->snapshot();state.inner.local_output_offset=7;state.inner.decoded_total=12;
                    const auto reservation=constructor_default_reservation(state.inner,owner->config().total_samples);
                    emit(*owner,observer,index,action,&state,&reservation);
                } else throw std::runtime_error("Unknown native action");
            } else throw std::runtime_error("Unknown authored command");
            require(bool(input),"Truncated authored command");
        }
    } catch(const std::exception& error) { std::cerr<<error.what()<<'\n';return 1; }
}
