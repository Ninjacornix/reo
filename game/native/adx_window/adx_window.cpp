#include "adx_window.hpp"
#include "../adx_block/adx_block.hpp"
#include "../adx_stereo/adx_stereo.hpp"
#include <algorithm>
#include <bit>
#include <limits>
#include <stdexcept>

namespace reo::native::adx_window {
namespace {
constexpr std::int32_t add(std::int32_t a, std::int32_t b) noexcept {
    return std::bit_cast<std::int32_t>(std::bit_cast<std::uint32_t>(a)+std::bit_cast<std::uint32_t>(b));
}
constexpr std::int32_t sub(std::int32_t a, std::int32_t b) noexcept {
    return std::bit_cast<std::int32_t>(std::bit_cast<std::uint32_t>(a)-std::bit_cast<std::uint32_t>(b));
}
constexpr std::int32_t mul(std::int32_t a, std::int32_t b) noexcept {
    return std::bit_cast<std::int32_t>(std::bit_cast<std::uint32_t>(a)*std::bit_cast<std::uint32_t>(b));
}
std::int32_t grant(const sjrb::Snapshot& r, bool data, std::int32_t requested) noexcept {
    return std::min({add(sub(r.capacity,data?r.read:r.write),r.extension),data?r.data:r.free,requested});
}
Span descriptor(Buffer role, const sjrb::Chunk& chunk) noexcept {
    return chunk.is_null()?Span{}:Span{role,chunk.offset(),chunk.bytes()};
}
std::int32_t budget_blocks(std::int32_t remaining) noexcept { return add(remaining,31)/32; }
std::int32_t gap(std::int32_t remaining) noexcept { return sub(sub(32,add(remaining,31)%32),1); }
}

struct Epoch { std::uint64_t generation{1}; bool closed{}; };
struct Window::Prepared {
    enum class Kind { empty_end, marker, position_end, pressure, decode } kind{Kind::decode};
    std::array<std::uint8_t, encoded_capacity+encoded_extension> encoded{};
    std::array<sjrb::Snapshot,3> rings{};
    std::int32_t input_bytes{}, output_offset{}, output_bytes{}, available{}, remaining{}, units{};
    std::int32_t marker_length{}, consumed{}, produced{};
    adx_block::Result mono;
    adx_stereo::Result stereo;
};
class Window::BusyScope final {
public:
    explicit BusyScope(Window& w) noexcept : owner_(w) { owner_.busy_=true; }
    ~BusyScope() { owner_.busy_=false; }
private: Window& owner_;
};

Reservation constructor_default_reservation(const InnerState& state, std::int32_t total_samples) noexcept {
    return {state.local_output_offset,sub(pcm_capacity/2,state.local_output_offset),sub(total_samples,state.decoded_total)};
}
std::int32_t PcmView::offset() const noexcept { return chunk_.offset(); }
std::int32_t PcmView::bytes() const noexcept { return chunk_.bytes(); }
sjrb::Status PcmView::read(std::span<std::uint8_t> output,std::size_t relative) const noexcept { return chunk_.read(output,relative); }

bool Window::admits(const Config& c) noexcept {
    if (c.channels<1 || c.channels>2 || c.total_samples<1 || c.total_samples>4096 ||
        c.max_request_samples<0 || c.max_request_samples>max_window_samples ||
        c.sample_limit< -1 || c.sample_limit>4096 || c.initial_encoded_cursor<0 ||
        c.initial_encoded_cursor>=encoded_capacity) return false;
    for (std::uint32_t i=0;i<c.channels;++i) {
        if (c.initial_pcm_cursor[i]<0 || c.initial_pcm_cursor[i]>=pcm_capacity || c.initial_pcm_cursor[i]%2 ||
            c.initial_pcm_bytes[i]<0 || c.initial_pcm_bytes[i]>pcm_capacity || c.initial_pcm_bytes[i]%2) return false;
        if (i && (c.initial_pcm_cursor[i]!=c.initial_pcm_cursor[0] || c.initial_pcm_bytes[i]!=c.initial_pcm_bytes[0])) return false;
    }
    return true;
}
Window::Window(Config config,Hooks hooks,std::uint8_t initial_byte):config_(config),hooks_(hooks) {
    if (!admits(config)) throw std::invalid_argument("ADX window profile");
    epoch_=std::make_shared<Epoch>();
    rings_[0]=std::make_unique<sjrb::Ring>(encoded_capacity,encoded_extension,sjrb::Hooks{},initial_byte);
    for (std::uint32_t i=0;i<config.channels;++i) rings_[i+1]=std::make_unique<sjrb::Ring>(pcm_capacity,pcm_extension,sjrb::Hooks{},initial_byte);
    if (!bootstrap_advance(0,config.initial_encoded_cursor)) throw std::logic_error("ADX encoded bootstrap");
    for (std::uint32_t i=0;i<config.channels;++i) {
        if (!bootstrap_advance(i+1,config.initial_pcm_cursor[i]) || !bootstrap_occupy(i+1,config.initial_pcm_bytes[i]))
            throw std::logic_error("ADX PCM bootstrap");
    }
    outer_.max_request_samples=config.max_request_samples; outer_.sample_limit=config.sample_limit;
    outer_.end_when_input_empty=config.end_when_input_empty;
    predictor_.history=config.history; predictor_.coefficients=config.coefficients;
    predictor_.key={config.key,std::bit_cast<std::uint16_t>(config.multiplier),std::bit_cast<std::uint16_t>(config.addend)};
    for (std::uint32_t i=0;i<=config.channels;++i) {
        ring_contexts_[i]={this,i};
        if (rings_[i]->set_hooks({&ring_contexts_[i],enter,leave,error})!=sjrb::Status::completed) throw std::logic_error("ADX hook installation");
    }
}
Window::~Window()=default;
const Config& Window::config() const noexcept { return config_; }
Request Window::request() const noexcept {
    Request r; if (!epoch_->closed) { r.owner_=epoch_; r.generation_=epoch_->generation; } return r;
}
void Window::enter(void* value) noexcept {
    auto& c=*static_cast<RingContext*>(value); if(c.owner->hooks_.guard) c.owner->hooks_.guard(c.owner->hooks_.context,c.ring,true);
}
void Window::leave(void* value) noexcept {
    auto& c=*static_cast<RingContext*>(value);
    if(c.owner->get_target_==static_cast<int>(c.ring)) {
        if(!c.ring) c.owner->outer_.encoded=descriptor(Buffer::encoded,c.owner->input_);
        else c.owner->outer_.pcm[c.ring-1]=descriptor(c.ring==1?Buffer::left_pcm:Buffer::right_pcm,c.owner->output_[c.ring-1]);
    }
    if(c.owner->hooks_.guard) c.owner->hooks_.guard(c.owner->hooks_.context,c.ring,false);
}
void Window::error(void* value,std::int32_t code) noexcept {
    auto& c=*static_cast<RingContext*>(value); c.owner->fault_=true; c.owner->epoch_->closed=true;
    if(c.owner->hooks_.error) c.owner->hooks_.error(c.owner->hooks_.context,c.ring,code);
}
bool Window::completed(sjrb::Status status) noexcept { return status==sjrb::Status::completed && !fault_; }
Status Window::fault() noexcept { fault_=true; epoch_->closed=true; return Status::invariant_fault; }
Snapshot Window::snapshot() const noexcept {
    Snapshot s{outer_,inner_,predictor_,odd_,{},epoch_->closed,fault_};
    for(std::uint32_t i=0;i<=config_.channels;++i) s.rings[i]=rings_[i]->snapshot();
    return s;
}
Status Window::read_encoded_backing(std::span<std::uint8_t> out) const noexcept {
    return rings_[0]->read_backing(out)==sjrb::Status::completed?Status::completed:Status::output_extent;
}
Status Window::read_pcm_backing(std::uint32_t channel,std::span<std::uint8_t> out) const noexcept {
    if(channel>=config_.channels) return Status::unsupported_geometry;
    return rings_[channel+1]->read_backing(out)==sjrb::Status::completed?Status::completed:Status::output_extent;
}

bool Window::bootstrap_advance(std::uint32_t index,std::int32_t count) noexcept {
    if (!count) return true;
    sjrb::Chunk span;
    return completed(rings_[index]->get(0,count,span)) && span.bytes()==count && completed(rings_[index]->put(1,span)) &&
           completed(rings_[index]->get(1,count,span)) && span.bytes()==count && completed(rings_[index]->put(0,span));
}
bool Window::bootstrap_occupy(std::uint32_t index,std::int32_t count) noexcept {
    while(count>0) {
        sjrb::Chunk span;
        if(!completed(rings_[index]->get(0,count,span)) || span.bytes()<=0) return false;
        count-=span.bytes(); if(!completed(rings_[index]->put(1,span))) return false;
    }
    return true;
}
Status Window::feed_encoded(std::span<const std::uint8_t> bytes) noexcept {
    if(busy_) return Status::busy;
    if(fault_) return Status::invariant_fault;
    if(epoch_->closed) return Status::admission_closed;
    if(bytes.size()>static_cast<std::size_t>(rings_[0]->snapshot().free)) return Status::backpressure;
    BusyScope scope(*this);
    std::size_t at=0;
    while(at<bytes.size()) {
        sjrb::Chunk span;
        if(!completed(rings_[0]->get(0,static_cast<std::int32_t>(bytes.size()-at),span)) || span.bytes()<=0) return fault();
        if(span.write(bytes.subspan(at,static_cast<std::size_t>(span.bytes())))!=sjrb::Status::completed) return fault();
        at+=static_cast<std::size_t>(span.bytes());
        if(!completed(rings_[0]->put(1,span))) return fault();
    }
    return Status::completed;
}
Status Window::consume_pcm(std::uint32_t channel,std::int32_t requested,std::int32_t& consumed) noexcept {
    if(busy_) return Status::busy;
    if(fault_) return Status::invariant_fault;
    if(channel>=config_.channels || requested<0 || requested%2) return Status::unsupported_geometry;
    BusyScope scope(*this); sjrb::Chunk span;
    if(!completed(rings_[channel+1]->get(1,requested,span))) return fault();
    consumed=span.bytes();
    if(!completed(rings_[channel+1]->put(0,span))) return fault();
    return Status::completed;
}
Status Window::stop() noexcept {
    if(busy_) return Status::busy;
    if(fault_) return Status::invariant_fault;
    if(!epoch_->closed) { epoch_->closed=true; ++epoch_->generation; }
    return Status::completed;
}

Status Window::prepare(Prepared& p) noexcept {
    if(inner_.phase!=EnginePhase::idle || predictor_.phase!=adx_control::Phase::idle) return Status::unsupported_state;
    for(std::uint32_t i=0;i<=config_.channels;++i) {
        p.rings[i]=rings_[i]->snapshot(); const auto& r=p.rings[i];
        if(r.data<0 || r.free<0 || std::int64_t(r.data)+r.free!=r.capacity || r.write<0 || r.read<0 || r.write>=r.capacity || r.read>=r.capacity)
            return Status::unsupported_state;
        if(i && ((r.write|r.read|r.free|r.data)&1)) return Status::unsupported_geometry;
        if(i>1 && (r.write!=p.rings[1].write || r.free!=p.rings[1].free)) return Status::unsupported_geometry;
    }
    if(outer_.end_when_input_empty && p.rings[0].data==0) { p.kind=Prepared::Kind::empty_end; return Status::completed; }
    p.input_bytes=grant(p.rings[0],true,std::numeric_limits<std::int32_t>::max());
    sjrb::Chunk input;
    if(!completed(rings_[0]->make_span(p.rings[0].read,p.input_bytes,input)) ||
       input.read(std::span(p.encoded).first(static_cast<std::size_t>(p.input_bytes)))!=sjrb::Status::completed) return Status::output_extent;
    if(p.input_bytes>=4 && p.encoded[0]==0x80 && p.encoded[1]==0x01) {
        if(p.input_bytes<16) return Status::malformed_marker;
        p.marker_length=std::bit_cast<std::int16_t>(static_cast<std::uint16_t>((std::uint16_t(p.encoded[2])<<8)+p.encoded[3]+4));
        if(p.marker_length<0) return Status::malformed_marker;
        p.kind=Prepared::Kind::marker; return Status::completed;
    }
    if(outer_.position>=config_.total_samples) { p.kind=Prepared::Kind::position_end; return Status::completed; }
    if(p.rings[1].free/2<32) { p.kind=Prepared::Kind::pressure; return Status::completed; }
    p.output_offset=p.rings[1].write/2;
    p.output_bytes=grant(p.rings[1],false,pcm_capacity);
    p.available=std::min(p.output_bytes/2,outer_.max_request_samples);
    p.remaining=outer_.sample_limit<0?0x1FFFFFFF:sub(outer_.sample_limit,outer_.sample_progress);
    if(p.remaining<0) return Status::unsupported_state;
    const auto blocks=p.input_bytes/18;
    auto window=add(sub(pcm_capacity/2,p.output_offset),31)/32;
    const auto budget=budget_blocks(p.remaining), padding=gap(p.remaining);
    if(budget<window) window=add(window,sub(add(p.output_offset,mul(window,32)),padding)<pcm_capacity/2?1:0);
    const auto available=add(p.available,p.remaining<p.available?padding:0)/32;
    const auto units=std::min({blocks/static_cast<std::int32_t>(config_.channels),available,budget,window});
    if(units<0 || units>max_window_samples/32) return Status::output_extent;
    p.units=mul(units,static_cast<std::int32_t>(config_.channels));
    const auto encoded=std::span<const std::uint8_t>(p.encoded).first(static_cast<std::size_t>(p.input_bytes));
    std::int32_t result=0;
    if(config_.channels==1) {
        p.mono=adx_block::decode_keyed_mono(encoded,p.units,{{predictor_.history[0],predictor_.history[1]},predictor_.key.value},
            {predictor_.coefficients[0],predictor_.coefficients[1],config_.multiplier,config_.addend},{max_window_samples});
        if(p.mono.status!=adx_block::Status::ok) return p.mono.status==adx_block::Status::no_memory?Status::no_memory:Status::codec_refusal;
        result=p.mono.kernel_return;
        if(p.mono.pcm.size()*2>static_cast<std::size_t>(p.output_bytes)) return Status::output_extent;
    } else {
        p.stereo=adx_stereo::decode_keyed_stereo(encoded,p.units,{{predictor_.history[0],predictor_.history[1]},
            {predictor_.history[2],predictor_.history[3]},predictor_.key.value},
            {predictor_.coefficients[0],predictor_.coefficients[1],config_.multiplier,config_.addend},
            config_.downmix?adx_stereo::Mode::downmix_7_over_10:adx_stereo::Mode::separate_channels,{max_window_samples});
        if(p.stereo.status!=adx_stereo::Status::ok) return p.stereo.status==adx_stereo::Status::no_memory?Status::no_memory:Status::codec_refusal;
        result=p.stereo.kernel_return;
        if(p.stereo.left_pcm.size()*2>static_cast<std::size_t>(p.output_bytes) || p.stereo.right_pcm.size()*2>static_cast<std::size_t>(p.output_bytes)) return Status::output_extent;
    }
    p.consumed=mul(18,result); p.produced=mul(32,result)/static_cast<std::int32_t>(config_.channels);
    if(result>=mul(budget,static_cast<std::int32_t>(config_.channels))) p.produced=sub(p.produced,padding);
    if(p.consumed<0 || p.consumed>p.input_bytes || p.produced<0 || mul(p.produced,2)>p.output_bytes) return Status::output_extent;
    const auto scratch=config_.channels==1?p.mono.pcm.size():std::max(p.stereo.left_pcm.size(),p.stereo.right_pcm.size());
    if(std::size_t(p.output_offset)*2+scratch*2>std::size_t(pcm_capacity+pcm_extension)) return Status::output_extent;
    return Status::completed;
}

bool Window::write_samples(std::uint32_t index,std::int32_t offset,std::span<const std::int16_t> samples) noexcept {
    std::array<std::uint8_t,max_window_samples*2> bytes{};
    if(samples.size()>max_window_samples) return false;
    for(std::size_t i=0;i<samples.size();++i) { const auto v=std::bit_cast<std::uint16_t>(samples[i]); bytes[2*i]=static_cast<std::uint8_t>(v); bytes[2*i+1]=static_cast<std::uint8_t>(v>>8); }
    sjrb::Chunk target;
    return completed(rings_[index]->make_span(offset,static_cast<std::int32_t>(samples.size()*2),target)) &&
        target.write(std::span<const std::uint8_t>(bytes).first(samples.size()*2))==sjrb::Status::completed;
}
bool Window::wrap(std::uint32_t index,std::int32_t samples) noexcept {
    if(samples<=0) return true;
    std::array<std::uint8_t,pcm_extension> bytes{}; sjrb::Chunk source,target;
    if(samples>pcm_extension/2) return false;
    return completed(rings_[index]->make_span(pcm_capacity,mul(samples,2),source)) &&
        source.read(std::span(bytes).first(static_cast<std::size_t>(samples)*2))==sjrb::Status::completed &&
        completed(rings_[index]->make_span(0,mul(samples,2),target)) &&
        target.write(std::span<const std::uint8_t>(bytes).first(static_cast<std::size_t>(samples)*2))==sjrb::Status::completed;
}
class Window::PreparedDecoder final:public adx_control::Decoder {
public:
    PreparedDecoder(Window& owner,Prepared& prepared) noexcept:owner_(owner),prepared_(prepared){}
    std::int32_t decode(const adx_control::DecodeRequest& request,adx_control::PredictorState& state) noexcept override {
        if(request.requested_units!=prepared_.units) owner_.fault_=true;
        if(owner_.config_.channels==1) {
            auto& result=prepared_.mono;
            if(!owner_.write_samples(1,mul(prepared_.output_offset,2),result.pcm)) owner_.fault_=true;
            state.history[0]=result.state.history.newest; state.history[1]=result.state.history.previous; state.key.value=result.state.key;
            return result.kernel_return;
        }
        auto& result=prepared_.stereo;
        if(!owner_.write_samples(1,mul(prepared_.output_offset,2),result.left_pcm) ||
           !owner_.write_samples(2,mul(prepared_.output_offset,2),result.right_pcm)) owner_.fault_=true;
        state.history={result.state.left.newest,result.state.left.previous,result.state.right.newest,result.state.right.previous}; state.key.value=result.state.key;
        return result.kernel_return;
    }
private: Window& owner_; Prepared& prepared_;
};

bool Window::put_input_prefix(std::int32_t bytes,bool in_place) noexcept {
    sjrb::Chunk prefix,suffix;
    if(sjrb::Chunk::split(input_,bytes,prefix,suffix)!=sjrb::Status::completed) return false;
    if(in_place) outer_.encoded=descriptor(Buffer::encoded,prefix);
    if(!completed(rings_[0]->put(0,prefix)) || !completed(rings_[0]->unget(1,suffix))) return false;
    input_borrowed_=false; return true;
}
bool Window::get_input() noexcept {
    input_borrowed_=true; get_target_=0;
    const auto status=rings_[0]->get(1,std::numeric_limits<std::int32_t>::max(),input_);
    get_target_=-1;
    return completed(status);
}
Status Window::execute(Prepared& p) noexcept {
    if(outer_.sample_limit>=0 && outer_.sample_progress>=outer_.sample_limit && hooks_.limit) hooks_.limit(hooks_.context);
    if(p.kind==Prepared::Kind::empty_end) { outer_.phase=OuterPhase::ended; return Status::completed; }
    if(!get_input()) return fault();
    if(p.kind==Prepared::Kind::marker) {
        outer_.phase=OuterPhase::ended;
        if(p.marker_length>input_.bytes()) {
            if(!completed(rings_[0]->unget(1,input_))) return fault();
            input_borrowed_=false; return Status::completed;
        }
        if(!put_input_prefix(p.marker_length,true)) return fault();
        for(std::int32_t pass=0;pass<=encoded_capacity;++pass) {
            if(!get_input()) return fault();
            if(input_.bytes()==0) { input_borrowed_=false; return Status::completed; }
            std::array<std::uint8_t,encoded_capacity+encoded_extension> bytes{};
            if(input_.read(std::span(bytes).first(static_cast<std::size_t>(input_.bytes())))!=sjrb::Status::completed) return fault();
            std::int32_t zeros=0; while(zeros<input_.bytes() && bytes[static_cast<std::size_t>(zeros)]==0) ++zeros;
            const bool nonzero=zeros<input_.bytes();
            if(!put_input_prefix(zeros,true)) return fault();
            if(nonzero) return Status::completed;
        }
        return fault();
    }
    if(p.kind==Prepared::Kind::position_end || p.kind==Prepared::Kind::pressure) {
        if(p.kind==Prepared::Kind::position_end) outer_.phase=OuterPhase::ended;
        if(!completed(rings_[0]->unget(1,input_))) return fault();
        input_borrowed_=false;
        return p.kind==Prepared::Kind::pressure?Status::backpressure:Status::completed;
    }
    inner_.encoded_input={adx_control::SpanToken{1},static_cast<std::uint32_t>(input_.offset())};
    inner_.input_blocks=input_.bytes()/18; inner_.produced_samples=0; inner_.consumed_bytes=0; inner_.phase=EnginePhase::requested;
    for(std::uint32_t i=0;i<config_.channels;++i) {
        output_borrowed_[i]=true; get_target_=static_cast<int>(i+1);
        const auto status=rings_[i+1]->get(0,pcm_capacity,output_[i]); get_target_=-1;
        if(!completed(status)) return fault();
    }
    inner_.sample_offset=output_[0].offset()/2;
    inner_.available_samples=std::min(output_[0].bytes()/2,outer_.max_request_samples);
    inner_.remaining_samples=outer_.sample_limit<0?0x1FFFFFFF:sub(outer_.sample_limit,outer_.sample_progress);
    const adx_control::WindowState window{inner_.encoded_input,{adx_control::SpanToken{2},0},
        static_cast<std::uint32_t>(inner_.sample_offset),pcm_spacing_samples};
    const auto units=static_cast<std::uint32_t>(p.units/static_cast<std::int32_t>(config_.channels));
    if(config_.channels==1) (void)adx_control::request_mono_window(predictor_,window,units);
    else (void)adx_control::request_stereo_window(predictor_,window,units);
    inner_.phase=EnginePhase::processing;
    PreparedDecoder decoder(*this,p);
    if(adx_control::service(predictor_,odd_,&decoder)!=adx_control::ServiceDisposition::decoded || fault_) return fault();
    inner_.consumed_bytes=p.consumed; inner_.produced_samples=p.produced;
    const auto overflow=sub(add(inner_.sample_offset,p.produced),pcm_capacity/2);
    if(overflow>=0) for(std::uint32_t i=0;i<config_.channels;++i) if(!wrap(i+1,overflow)) return fault();
    adx_control::acknowledge_ready(predictor_);
    inner_.local_output_offset=add(inner_.local_output_offset,p.produced); inner_.decoded_total=add(inner_.decoded_total,p.produced);
    inner_.phase=EnginePhase::ready;
    const auto valid=std::min(p.produced,sub(config_.total_samples,outer_.position));
    if(!put_input_prefix(p.consumed,false)) return fault();
    for(std::uint32_t i=0;i<config_.channels;++i) {
        sjrb::Chunk prefix,suffix;
        if(sjrb::Chunk::split(output_[i],mul(valid,2),prefix,suffix)!=sjrb::Status::completed) return fault();
        if(hooks_.pcm) { PcmView view; view.chunk_=prefix; hooks_.pcm(hooks_.context,i,view); }
        if(!completed(rings_[i+1]->put(1,prefix)) || !completed(rings_[i+1]->unget(0,suffix))) return fault();
        output_borrowed_[i]=false;
    }
    outer_.decoded_samples=add(outer_.decoded_samples,valid); outer_.position=add(outer_.position,valid);
    outer_.sample_progress=add(outer_.sample_progress,valid); outer_.encoded_bytes=add(outer_.encoded_bytes,p.consumed); outer_.encoded_progress=add(outer_.encoded_progress,p.consumed);
    adx_control::acknowledge_ready(predictor_); inner_.local_output_offset=0; inner_.phase=EnginePhase::idle;
    return Status::completed;
}
Status Window::service(const Request& r) noexcept {
    if(busy_) return Status::busy;
    if(fault_) return Status::invariant_fault;
    if(r.owner_!=epoch_ || r.generation_!=epoch_->generation) return Status::stale_request;
    if(epoch_->closed) return Status::admission_closed;
    if(outer_.phase!=OuterPhase::decoding) return Status::inactive;
    BusyScope scope(*this); Prepared prepared;
    const auto admitted=prepare(prepared); if(admitted!=Status::completed) return admitted;
    return execute(prepared);
}

} // namespace reo::native::adx_window
