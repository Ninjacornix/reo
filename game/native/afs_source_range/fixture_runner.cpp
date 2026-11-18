// Input contains raw authored index entries, never an expected parsed result.
#include "afs_source_range.hpp"
#include <fstream>
#include <iostream>
#include <string>
namespace a=reo::native::afs_source_range;
namespace r=reo::native::resources;
struct View final:r::ByteView {
    std::vector<std::byte> header;std::uint64_t extent{};
    std::uint64_t size()const noexcept override{return extent;}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override {
        if(at>extent||out.size()>extent-at)return{r::Status::invalid_range,0};
        for(std::size_t i=0;i<out.size();++i)out[i]=at+i<header.size()?header[at+i]:std::byte{0xa7};
        return{r::Status::ok,out.size()};
    }
    void word(std::uint32_t value){for(unsigned i=0;i<4;++i)header.push_back(std::byte(value>>(8*i)));}
};
int main(int argc,char**argv) {
    if(argc!=2)return 2;
    std::ifstream input(argv[1]);std::string kind;input>>kind;
    if(kind=="open") {
        std::uint32_t start,count,total;input>>start>>count>>total;const auto p=a::prepare_open(start,count,total);
        std::cout<<"{\"status\":"<<int(p.status)<<",\"start_sector\":"<<p.start_sector<<",\"byte_length\":"<<p.byte_length<<",\"inside_backend\":"<<p.inside_backend<<"}\n";
    }else{
        auto view=std::make_shared<View>();std::uint32_t n;input>>view->extent>>n;view->word(0x00534641);view->word(n);
        for(std::uint32_t i=0;i<n;++i){std::uint32_t offset,length;input>>offset>>length;view->word(offset);view->word(length);}
        auto result=a::Archive::open(view,0,view->size());std::cout<<"{\"status\":"<<int(result.status)<<",\"count\":"<<(result.archive?result.archive->count():0)<<",\"entries\":[";
        if(result.archive)for(std::uint32_t i=0;i<result.archive->count();++i){if(i)std::cout<<',';const auto&e=*result.archive->entry(i);std::cout<<'['<<e.start_sector<<','<<e.sectors<<','<<e.logical_bytes<<']';}
        std::cout<<"]}\n";
    }
    return input?0:3;
}
