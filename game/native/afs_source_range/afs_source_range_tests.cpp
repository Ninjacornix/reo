#include "afs_source_range.hpp"
#include <array>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <limits>
#include <new>
#include <stdexcept>

namespace a = reo::native::afs_source_range;
namespace r = reo::native::resources;
namespace {
unsigned checks{};
void check(bool value, const char* message) { ++checks; if (!value) { std::fprintf(stderr,"FAILED: %s\n",message);std::exit(1); } }
struct View final : r::ByteView {
    std::vector<std::byte> data;
    bool fail{}, throws{}; mutable unsigned reads{};
    View() : data(8192 + 37, std::byte{0xa7}) {
        word(0,0x00534641);word(4,2);word(8,2048);word(12,1);word(16,4096);word(20,2049);
    }
    void word(std::size_t at, std::uint32_t value) { for (unsigned i=0;i<4;++i)data[37+at+i]=std::byte(value>>(i*8)); }
    std::uint64_t size() const noexcept override { return data.size(); }
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out) const override {
        ++reads;
        if (at>data.size()||out.size()>data.size()-at)return {r::Status::invalid_range,0};
        for (std::size_t i=0;i<out.size();++i)out[i]=data[at+i];
        if (throws)throw std::runtime_error("private provider failed after output write");
        return fail?r::ReadResult{r::Status::source_failure,out.size()}:r::ReadResult{r::Status::ok,out.size()};
    }
};
void retained_bytes() {
    auto source=std::make_shared<View>();std::weak_ptr<View> lifetime=source;
    auto opened=a::Archive::open(source,37,8192);
    check(opened.status==a::Status::completed&&opened.archive->count()==2,"bounded index published only after admission");
    check(*opened.archive->entry(0)==a::Entry{1,1,1}&&*opened.archive->entry(1)==a::Entry{2,2,2049},"logical length distinct from actual sector backing");
    check(!opened.archive->entry(2)&&opened.archive->member(0xffffffff).status==a::Status::invalid_member,"invalid member never aliases a live range");
    auto first=opened.archive->member(0);auto second=opened.archive->member(1);
    check(first.status==a::Status::completed&&first.view->size()==2048&&second.view->size()==4096,"member view includes checked retained sector bytes");
    std::array<std::byte,2048> tail{};check(first.view->read(0,tail)==r::ReadResult{r::Status::ok,2048},"read real full retained sector");
    check(std::all_of(tail.begin(),tail.end(),[](auto b){return b==std::byte{0xa7};}),"tail bytes are actual parent bytes rather than zero padding");
    check(first.view->read(1,tail).status==r::Status::invalid_range,"cannot read neighbor beyond admitted sector view");
    opened.archive.reset();source.reset();
    check(!lifetime.expired()&&second.view->read(0,tail).status==r::Status::ok,"returned view retains backing after index dies");
    first.view.reset();second.view.reset();check(lifetime.expired(),"last view releases immutable parent");
}
void refusals() {
    auto v=std::make_shared<View>();
    check(a::Archive::open({},0,8192).status==a::Status::invalid_source,"missing parent");
    check(a::Archive::open(v,37,8193).status==a::Status::invalid_range,"archive extent outside parent");
    check(a::Archive::open(v,37,8192,1).status==a::Status::unsupported_profile,"member cap before table allocation");
    v->word(4,65536);check(a::Archive::open(v,37,8192).status==a::Status::unsupported_profile,"16-bit descriptor count boundary is excluded");v->word(4,2);
    v->word(0,0);check(a::Archive::open(v,37,8192).status==a::Status::bad_magic,"bad magic");v->word(0,0x00534641);
    v->word(16,6144);check(a::Archive::open(v,37,8192).status==a::Status::unsupported_profile,"raw offset gap disagrees with original cumulative table");v->word(16,4096);
    check(a::Archive::open(v,37,8191).status==a::Status::invalid_range,"rounded final sector is not silently fabricated");
    v->word(8,2049);check(a::Archive::open(v,37,8192).status==a::Status::unsupported_profile,"unaligned first offset");v->word(8,2048);
    v->fail=true;auto failure=a::Archive::open(v,37,8192);
    check(failure.status==a::Status::source_failure&&!failure.archive,"partial provider output stays private");
    v->fail=false;v->throws=true;failure=a::Archive::open(v,37,8192);
    check(failure.status==a::Status::source_failure&&!failure.archive,"provider exception stays typed and private");
    auto normal=a::prepare_open(2,3,4);check(normal.status==a::Status::completed&&normal.start_sector==2&&normal.byte_length==4096&&normal.inside_backend,"ordinary range clamp");
    auto beyond=a::prepare_open(8,3,4);check(beyond.start_sector==4&&!beyond.byte_length&&beyond.inside_backend,"start clamps to backend end");
    auto special=a::prepare_open(2,0xfffff,4);
    check(special.status==a::Status::completed&&special.start_sector==2&&special.byte_length==8192&&!special.inside_backend,
          "literal sentinel branch preserves unsafe original start but cannot authorize I/O");
    check(a::prepare_open(0,0x100000,4).status==a::Status::invalid_range,"unrepresentable shifted count refuses");
}
}
int main() {retained_bytes();refusals();std::printf("%u AFS range checks passed\n",checks);}
