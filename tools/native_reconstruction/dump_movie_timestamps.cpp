#include "tools/parallel_gs_backend/movie_runtime/mpeg2_stream.h"
#include "game/native/movie_timestamp/timecode.hpp"
#include <fstream>
#include <iostream>
namespace gpu=reo_gpu_movie;
namespace n=reo::native::movie_timestamp;
struct Accounting {uint64_t begin,end;n::Stamp stamp;};
int main(int argc,char** argv){try{
    if(argc!=2)throw std::runtime_error("Owned SFD path required");
    std::ifstream file(argv[1],std::ios::binary|std::ios::ate);if(!file)throw std::runtime_error("Source open");const auto size=file.tellg();if(size<1 || size>256*1024*1024)throw std::runtime_error("Source bound");std::vector<uint8_t> bytes(static_cast<size_t>(size));file.seekg(0);file.read(reinterpret_cast<char*>(bytes.data()),size);if(!file)throw std::runtime_error("Source read");
    gpu::Mpeg2ElementaryStream elementary;std::vector<Accounting> stamps;
    gpu::MpegProgramStream program(elementary,0xe0,[&](uint8_t code,const gpu::PesTimestamp& time,std::span<const uint8_t>){if(code==0xe0 && time.hasPts)stamps.push_back({time.elementaryBegin,time.elementaryEnd,{static_cast<uint32_t>(time.pts33>>2),static_cast<uint32_t>(time.elementaryBegin),static_cast<uint32_t>(time.elementaryEnd-time.elementaryBegin)}});});
    n::FlowState state;uint64_t gop{};
    auto drain=[&]{while(elementary.hasPicture()){
        const auto& p=elementary.picture();n::FlowInput in;in.picture={p.rate,p.temporalReference,p.kind,p.drop,p.hours,p.minutes,p.seconds,p.frames,static_cast<uint32_t>(p.gop)};in.changed=p.gop!=gop;
        for(const auto& stamp:stamps)if(stamp.begin<=p.begin && p.begin<stamp.end){in.accounting=stamp.stamp;break;}
        const auto out=n::publish(state,in);if(!out.admitted)throw std::runtime_error("Timecode profile");
        std::cout<<"{\"ordinal\":"<<p.ordinal<<",\"begin\":"<<p.begin<<",\"rate\":"<<p.rate<<",\"reference\":"<<p.temporalReference<<",\"kind\":"<<unsigned(p.kind)<<",\"gop\":"<<p.gop<<",\"drop\":"<<p.drop<<",\"hours\":"<<p.hours<<",\"minutes\":"<<p.minutes<<",\"seconds\":"<<p.seconds<<",\"frames\":"<<p.frames<<",\"changed\":"<<in.changed<<",\"stamp\":";
        if(in.accounting)std::cout<<in.accounting->value;else std::cout<<"null";
        std::cout<<",\"account_begin\":"<<(in.accounting?in.accounting->begin:0)<<",\"account_bytes\":"<<(in.accounting?in.accounting->bytes:0)<<",\"value\":"<<out.value<<",\"scale\":"<<out.scale<<",\"latest_reference\":"<<state.latest.reference<<",\"latest_value\":"<<state.latest.value<<"}\n";
        gop=p.gop;elementary.pop();
    }};
    for(size_t at=0;at<bytes.size();){const auto count=std::min<size_t>(2048,bytes.size()-at);program.feed(at,std::span<const uint8_t>(bytes).subspan(at,count));at+=count;drain();}program.end();drain();return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}}
