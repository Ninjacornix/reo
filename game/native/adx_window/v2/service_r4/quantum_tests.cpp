#include "stream_window.hpp"
#include "quantum_cases.hpp"
#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

namespace w=reo::native::adx_window::service_r4;
namespace a=reo::native::adxt_refill;
namespace r=reo::native::resources;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Quantum check "+std::to_string(checks));}
struct File final:r::ByteView {
    std::vector<std::uint8_t> bytes;
    std::uint64_t size()const noexcept override{return bytes.size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        if(at>bytes.size() || out.size()>bytes.size()-at)return{r::Status::invalid_range,0};
        for(std::size_t i=0;i<out.size();++i)out[i]=std::byte(bytes[at+i]);
        return{r::Status::ok,out.size()};
    }
};
struct Backend final:a::Backend {
    a::Acceptance submit(std::shared_ptr<const r::ByteView>,std::uint64_t,std::uint32_t,std::uint64_t)noexcept override{return{};}
    a::Completion poll()noexcept override{return{};}
    bool shutdown_and_join()noexcept override{return true;}
};
void be16(std::vector<std::uint8_t>& b,std::size_t p,unsigned v){b[p]=std::uint8_t(v>>8);b[p+1]=std::uint8_t(v);}
void be32(std::vector<std::uint8_t>& b,std::size_t p,unsigned v){for(unsigned i=0;i<4;++i)b[p+i]=std::uint8_t(v>>(24-i*8));}
std::shared_ptr<File> file(unsigned channels,unsigned rate,bool loop){
    auto f=std::make_shared<File>();constexpr unsigned total=32000;
    const auto end=96+total/32*channels*18;
    auto& b=f->bytes;b.resize((end+18+2047)/2048*2048);
    be16(b,0,0x8000);be16(b,2,92);b[4]=3;b[5]=18;b[6]=4;b[7]=std::uint8_t(channels);
    be32(b,8,rate);be32(b,12,total);be16(b,16,500);b[18]=3;
    if(loop){be16(b,22,1);be16(b,26,1);be32(b,32,96);be32(b,36,total);be32(b,40,end);}
    for(unsigned at=96;at<end;at+=18){b[at+1]=3;std::fill_n(b.begin()+at+2,16,0x11);}
    be16(b,end,0x8001);be16(b,end+2,14);return f;
}
int main()try{
    unsigned original_rows{},accepted{},refused{},large_decodes{};
    for(const auto& row:quantum_cases)for(unsigned channels:{1u,2u}){
        const auto f=file(channels,row.rate,row.loop);w::Config c;c.channels=channels;
        c.source_config.byte_length=static_cast<std::int32_t>(f->size());
        w::StreamWindowOwner owner(c,f,std::make_unique<Backend>(),std::make_shared<reo::native::adx_header::KeyContext>(),{},
            {{0,4,std::span(f->bytes).first(8192)},0,0});
        check(owner.snapshot().service_divisor==60);
        check(owner.set_service_divisor(row.divisor)==w::Status::completed);
        check(owner.set_service_divisor(0)==w::Status::invalid_request && owner.set_service_divisor(-1)==w::Status::invalid_request);
        check(owner.snapshot().service_divisor==row.divisor);
        check(owner.service_header()==w::Status::completed);
        const auto result=owner.configure_ready();
        if(row.request>8192){
            check(result==w::Status::unsupported_profile && owner.snapshot().fault && !owner.snapshot().ready.play);++refused;
        }else{
            check(result==w::Status::completed);const auto before=owner.snapshot();
            check(before.outer.max_request==row.request && before.engine.request_setting==row.request && before.engine.request_copy==row.request &&
                before.engine.request_over_96==row.request/96 && before.engine.request_over_1536==row.request/1536 && before.ready.play);
            // This API stores an input to readiness. An active request remains
            // the one configured above, including when the setting is changed.
            check(owner.set_service_divisor(60)==w::Status::completed && owner.snapshot().outer.max_request==row.request);
            if(row.divisor==30){
                check(owner.service_decode(owner.request())==w::Status::completed);
                check(owner.snapshot().outer.decoded_samples==row.request);++large_decodes;
            }
            ++accepted;
        }
        const auto stop=owner.stop_decode();check(stop==w::Status::completed || stop==w::Status::retirement_pending || (row.request>8192 && stop==w::Status::owned_fault));
        while(owner.snapshot().pcm.rings[0].data){auto read=owner.borrow_pcm(16384);check(read.status==w::pcm::Status::completed);check(owner.finish_pcm(read.lease)==w::Status::completed);}
        check(owner.retire_on_control_thread()==w::Status::completed);
        check(owner.set_service_divisor(30)==(row.request>8192?w::Status::owned_fault:w::Status::closed));++original_rows;
    }
    check(original_rows==192 && accepted+refused==192 && large_decodes==12);
    std::cout<<"original ready rows="<<original_rows<<" accepted="<<accepted<<" refused="<<refused<<" divisor30 decodes="<<large_decodes<<" checks="<<checks<<'\n';return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
