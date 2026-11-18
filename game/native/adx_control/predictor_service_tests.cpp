#include "predictor_service.hpp"

#include <algorithm>
#include <array>
#include <bit>
#include <cstdint>
#include <fstream>
#include <iostream>
#include <iterator>
#include <stdexcept>
#include <string>
#include <vector>

namespace adx = reo::native::adx_control;
namespace {
unsigned assertions{};
void check(bool condition) {
    ++assertions;
    if (!condition) throw std::runtime_error("predictor service check failed");
}
struct UnitDecoder final : adx::Decoder {
    std::int32_t result{};
    unsigned calls{}, mutation{};
    adx::DecodeRequest observed;
    adx::Phase observed_phase{};
    std::int32_t decode(const adx::DecodeRequest& request, adx::PredictorState& state) noexcept override {
        ++calls; observed=request; observed_phase=state.phase;
        if(mutation==1)adx::cancel(state);
        if(mutation==2)state={};
        if(mutation==3)state.mode=adx::ChannelMode::mono;
        if(mutation==4)state.mode=adx::ChannelMode::stereo;
        return result;
    }
};
void unit() {
    adx::PredictorState state;
    state.phase=adx::Phase::requested; state.completed_units=0xABCD;
    std::uint32_t flag=0xFEDC;
    const auto before=state;
    check(adx::service(state,flag,nullptr)==adx::ServiceDisposition::decoder_unavailable);
    check(state==before&&flag==0xFEDC);
    for(auto phase:{0u,3u,4u,0xFFFFFFFFu}) {
        state.phase=static_cast<adx::Phase>(phase);const auto saved=state;
        check(adx::service(state,flag,nullptr)==adx::ServiceDisposition::inactive);
        check(state==saved&&flag==0xFEDC);
    }
    for(auto mode:{0u,1u,2u,7u,0xFFFFFFFFu})for(auto result:{-3,-2,-1,0,1,2,3}) {
        state={};state.phase=adx::Phase::requested;state.mode=static_cast<adx::ChannelMode>(mode);
        state.encoded_input={{9},0xFFFFFFFE};state.left_output={{11},4};state.right_output={{12},8};
        state.requested_units=0x80000000;state.coefficients={-32768,32767};state.key={17,0x8001,0xF00D};
        UnitDecoder decoder;decoder.result=result;flag=0xAABBCCDD;
        check(adx::service(state,flag,&decoder)==adx::ServiceDisposition::decoded);
        check(decoder.calls==1&&decoder.observed_phase==adx::Phase::processing);
        check(decoder.observed.route==(mode==1?adx::DecodeRoute::mono:adx::DecodeRoute::stereo_selector));
        check(decoder.observed.encoded_input==adx::BufferPosition{{9},0xFFFFFFFE});
        check(decoder.observed.right_output==(mode==1?adx::BufferPosition{}:adx::BufferPosition{{12},8}));
        check(decoder.observed.requested_units==INT32_MIN&&decoder.observed.key_multiplier==-32767&&decoder.observed.key_addend==-4083);
        check(state.phase==adx::Phase::ready&&state.completed_units==std::bit_cast<std::uint32_t>(static_cast<std::int32_t>(result)));
        check(flag==(mode!=1&&result>0&&(result&1)?1u:0xAABBCCDDu));
    }
    for(unsigned mutation=1;mutation<=4;++mutation) {
        state={};state.phase=adx::Phase::processing;state.mode=adx::ChannelMode::stereo;state.history={1,2,3,4};
        UnitDecoder decoder;decoder.result=3;decoder.mutation=mutation;flag=0;
        check(adx::service(state,flag,&decoder)==adx::ServiceDisposition::decoded);
        check(state.phase==adx::Phase::ready&&state.completed_units==3&&flag==1);
        if(mutation<=2)check(state.history==std::array<std::int16_t,4>{});
    }
    state={};state.phase=adx::Phase::requested;state.mode=adx::ChannelMode::mono;
    UnitDecoder decoder;decoder.result=1;decoder.mutation=4;flag=7;
    check(adx::service(state,flag,&decoder)==adx::ServiceDisposition::decoded&&flag==7);
    std::cout<<"unit_assertions="<<assertions<<'\n';
}
struct Reader {
    std::vector<unsigned char> bytes;std::size_t at{};
    explicit Reader(const char* path){std::ifstream input(path,std::ios::binary);if(!input)throw std::runtime_error("fixture missing");bytes.assign(std::istreambuf_iterator<char>(input),{});}
    std::uint32_t word(){if(at+4>bytes.size())throw std::runtime_error("short fixture");std::uint32_t value=0;for(unsigned i=0;i<4;++i)value|=std::uint32_t(bytes[at++])<<(i*8);return value;}
    template<std::size_t N>std::array<unsigned char,N> raw(){if(at+N>bytes.size())throw std::runtime_error("short fixture");std::array<unsigned char,N> value;std::copy_n(bytes.begin()+static_cast<std::ptrdiff_t>(at),N,value.begin());at+=N;return value;}
    void name(){const auto n=word();if(n>256||at+n>bytes.size())throw std::runtime_error("bad name");at+=n;}
};
std::int16_t half(std::uint32_t word){return std::bit_cast<std::int16_t>(static_cast<std::uint16_t>(word));}
struct Image {
    std::array<std::uint32_t,15> words{};std::uint32_t flag{};
    std::array<unsigned char,64> left{},right{};
    friend bool operator==(const Image&,const Image&)=default;
};
Image image(Reader& reader){Image out;for(auto& value:out.words)value=reader.word();out.flag=reader.word();out.left=reader.raw<64>();out.right=reader.raw<64>();return out;}
adx::PredictorState import(const Image& in){
    const auto& w=in.words;adx::PredictorState out;
    out.phase=static_cast<adx::Phase>(w[3]);out.completed_units=w[4];out.mode=static_cast<adx::ChannelMode>(w[5]);
    out.encoded_input={{w[6]},0};out.requested_units=w[7];out.left_output={{w[8]},0};out.right_output={{w[9]},0};
    out.history={half(w[10]),half(w[10]>>16),half(w[11]),half(w[11]>>16)};
    out.coefficients={half(w[12]),half(w[12]>>16)};
    out.key={static_cast<std::uint16_t>(w[13]),static_cast<std::uint16_t>(w[13]>>16),static_cast<std::uint16_t>(w[14])};return out;
}
std::uint32_t pair(std::int16_t low,std::int16_t high){return std::bit_cast<std::uint16_t>(low)|(std::uint32_t(std::bit_cast<std::uint16_t>(high))<<16);}
void export_state(Image& image,const adx::PredictorState& s){auto& w=image.words;
    w[3]=static_cast<std::uint32_t>(s.phase);w[4]=s.completed_units;w[5]=static_cast<std::uint32_t>(s.mode);
    w[6]=static_cast<std::uint32_t>(s.encoded_input.span.value)+s.encoded_input.word_byte_offset;w[7]=s.requested_units;
    w[8]=static_cast<std::uint32_t>(s.left_output.span.value)+s.left_output.word_byte_offset;
    w[9]=static_cast<std::uint32_t>(s.right_output.span.value)+s.right_output.word_byte_offset;
    w[10]=pair(s.history[0],s.history[1]);w[11]=pair(s.history[2],s.history[3]);w[12]=pair(s.coefficients[0],s.coefficients[1]);
    w[13]=s.key.value|(std::uint32_t(s.key.multiplier)<<16);w[14]=(w[14]&0xFFFF0000u)|s.key.addend;
}
adx::DecodeRequest request(Reader& reader){adx::DecodeRequest out;out.route=reader.word()==1?adx::DecodeRoute::mono:adx::DecodeRoute::stereo_selector;
    out.encoded_input={{reader.word()},0};out.requested_units=std::bit_cast<std::int32_t>(reader.word());
    out.left_output={{reader.word()},0};out.right_output={{reader.word()},0};out.coefficients={half(reader.word()),half(reader.word())};out.key_multiplier=half(reader.word());out.key_addend=half(reader.word());return out;}
struct FixtureDecoder final:adx::Decoder {
    Image& live;Image before,after;adx::DecodeRequest expected_request;
    std::int32_t result{};unsigned effect{},calls{};bool payload{},matched=true;
    explicit FixtureDecoder(Image& value):live(value){}
    std::int32_t decode(const adx::DecodeRequest& req,adx::PredictorState& state) noexcept override {
        ++calls;export_state(live,state);matched&=req==expected_request&&live==before;
        if(payload){const std::array<unsigned char,8> l{0xEF,0xCD,0xAB,0x89,0x67,0x45,0x23,0x01};std::copy(l.begin(),l.end(),live.left.begin());state.history[0]=0x1234;state.history[1]=0x4321;
            if(req.route==adx::DecodeRoute::stereo_selector){const std::array<unsigned char,8> r{0x10,0x32,0x54,0x76,0x98,0xBA,0xDC,0xFE};std::copy(r.begin(),r.end(),live.right.begin());state.history[2]=0x5678;state.history[3]=half(0x8765);}state.key.value=0x3456;}
        if(effect==1)adx::cancel(state);
        if(effect==2){state={};live.words.fill(0);}
        if(effect==3)(void)adx::request_if_idle(state);
        if(effect==4)adx::acknowledge_ready(state);
        export_state(live,state);matched&=live==after;return result;
    }
};
void fixtures(const char* path){Reader reader(path);const auto magic=reader.raw<8>();check(magic==std::array<unsigned char,8>{'A','D','X','S','R','V','1',0});check(reader.word()==1);const auto cases=reader.word();check(cases==74);unsigned hooks=0,images=0;
    for(unsigned index=0;index<cases;++index){reader.name();auto live=image(reader);auto state=import(live);FixtureDecoder decoder(live);decoder.result=std::bit_cast<std::int32_t>(reader.word());decoder.effect=reader.word();decoder.payload=reader.word()!=0;const auto expected_hooks=reader.word();check(expected_hooks<=1);
        if(expected_hooks){decoder.expected_request=request(reader);decoder.before=image(reader);decoder.after=image(reader);}
        const auto expected=image(reader);const auto disposition=adx::service(state,live.flag,&decoder);export_state(live,state);
        check(live==expected);check(decoder.calls==expected_hooks&&decoder.matched);check(disposition==(expected_hooks?adx::ServiceDisposition::decoded:adx::ServiceDisposition::inactive));
        hooks+=decoder.calls;images+=1+2*decoder.calls;
    }
    check(reader.at==reader.bytes.size());check(hooks==54&&images==182);
    std::cout<<"cases="<<cases<<" hooks="<<hooks<<" state_images="<<images<<" context_words="<<images*15<<" payload_bytes="<<images*128<<" ignored_void_returns="<<cases<<'\n';
}
} // namespace
int main(int argc,char** argv){try{if(argc==2&&std::string(argv[1])=="--unit")unit();else if(argc==3&&std::string(argv[1])=="--fixtures")fixtures(argv[2]);else throw std::runtime_error("expected --unit or --fixtures path");return 0;}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
