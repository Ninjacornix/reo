#pragma once
#include "../resources/resource_session.hpp"
#include <atomic>
#include <condition_variable>
#include <memory>
#include <mutex>
#include <vector>
#include <algorithm>
namespace reo::native::adxt_shared_player::testing {
namespace r=resources;
struct File: r::ByteView {
    std::vector<std::uint8_t> bytes;mutable std::atomic<unsigned> reads{};
    std::uint64_t size()const noexcept override{return bytes.size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override {
        ++reads;if(at>bytes.size() || out.size()>bytes.size()-at)return{r::Status::invalid_range,0};
        for(std::size_t i=0;i<out.size();++i)out[i]=std::byte(bytes[static_cast<std::size_t>(at)+i]);
        return{r::Status::ok,out.size()};
    }
};
inline void be16(std::vector<std::uint8_t>& v,std::size_t at,std::uint16_t n){v[at]=static_cast<std::uint8_t>(n>>8);v[at+1]=static_cast<std::uint8_t>(n);}
inline void be32(std::vector<std::uint8_t>& v,std::size_t at,std::uint32_t n){for(unsigned i=0;i<4;++i)v[at+i]=static_cast<std::uint8_t>(n>>(24-i*8));}
inline std::shared_ptr<File> file(unsigned ch,unsigned rate,unsigned total){
    auto f=std::make_shared<File>();auto& d=f->bytes;const auto blocks=(total+31)/32*ch;
    d.resize(((96+blocks*18+2047)/2048)*2048);
    be16(d,0,0x8000);be16(d,2,92);d[4]=3;d[5]=18;d[6]=4;d[7]=static_cast<std::uint8_t>(ch);
    be32(d,8,rate);be32(d,12,total);be16(d,16,500);d[18]=3;
    for(unsigned b=0;b<blocks;++b){const auto at=96+b*18;d[at+1]=3;std::fill_n(d.begin()+at+2,16,static_cast<std::uint8_t>(0x11+b%7));}
    return f;
}
struct Blocked final:File {
    mutable std::mutex mutex;mutable std::condition_variable cv;mutable bool entered{},released{};
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override{
        {std::unique_lock lock(mutex);entered=true;cv.notify_all();cv.wait(lock,[&]{return released;});}
        return File::read(at,out);
    }
};
}
