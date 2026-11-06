#include "hierarchy.hpp"
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <stdexcept>
namespace h=reo::native::afs_hierarchy;
namespace r=reo::native::resources;
unsigned checks{};
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"FAILED: %s\n",why);std::exit(1);}}
struct View final:r::ByteView {
    std::vector<std::byte> bytes;mutable unsigned reads{};bool fail{};
    std::uint64_t size()const noexcept override{return bytes.size();}
    r::ReadResult read(std::uint64_t at,std::span<std::byte> out)const override {
        ++reads;if(at>bytes.size() || out.size()>bytes.size()-at)return{r::Status::invalid_range,0};
        std::copy_n(bytes.begin()+static_cast<std::ptrdiff_t>(at),out.size(),out.begin());
        return{fail?r::Status::source_failure:r::Status::ok,out.size()};
    }
};
void word(std::vector<std::byte>& bytes,unsigned at,unsigned value){for(unsigned i=0;i<4;++i)bytes[at+i]=std::byte((value>>(i*8))&255);}
std::shared_ptr<View> fixture(){
    auto view=std::make_shared<View>();view->bytes.resize(8192,std::byte{0xB7});
    word(view->bytes,0,0x00534641);word(view->bytes,4,2);word(view->bytes,8,2048);word(view->bytes,12,4096);
    word(view->bytes,16,6144);word(view->bytes,20,7);
    word(view->bytes,2048,0x00534641);word(view->bytes,2052,1);word(view->bytes,2056,2048);word(view->bytes,2060,7);
    return view;
}
void ordinary(){
    auto root=fixture();h::Tree tree(root);const std::array<std::uint32_t,2> path{0,0};
    auto result=tree.resolve(path);check(result.status==h::Status::completed,"nested archive resolves");
    check(result.depth==2 && result.logical_bytes==7 && result.view->size()==2048,"logical bytes and actual sector view separate");
    check(result.hops[0].root_byte_offset==2048 && result.hops[1].root_byte_offset==4096,"native root-relative path trace");
    std::array<std::byte,1> tail{};check(result.view->read(2047,tail).status==r::Status::ok && tail[0]==std::byte{0xB7},"real nonzero sector tail retained");
    check(result.view->read(2048,tail).status==r::Status::invalid_range,"tail view cannot read beyond owned range");
    const auto reads=root->reads;check(tree.resolve(path).status==h::Status::completed && root->reads==reads,"cached indices do not reread source");
    check(tree.snapshot().archives==2 && tree.snapshot().entries==3,"bounded parsed metadata accounting");
    const std::array<std::uint32_t,1> sibling{1};auto other=tree.resolve(sibling);
    check(other.status==h::Status::completed && other.hops[0].root_byte_offset==6144,"sibling does not reuse wrong path cache");
    const std::array<std::uint32_t,2> not_archive{1,0};auto refused=tree.resolve(not_archive);
    check(refused.status==h::Status::archive_refused && refused.archive_status==reo::native::afs_source_range::Status::bad_magic && !refused.view,"nonarchive child refuses without fabricated bytes");
}
void lifetime(){
    auto root=fixture();std::weak_ptr<View> weak=root;h::Resolved result;
    {h::Tree tree(root);const std::array<std::uint32_t,2> path{0,0};result=tree.resolve(path);root.reset();}
    check(!weak.expired(),"leaf retains actual provider after tree/root facade destruction");
    std::array<std::byte,1> byte{};check(result.view->read(7,byte).status==r::Status::ok && byte[0]==std::byte{0xB7},"retained padding remains readable");
    result.view.reset();check(weak.expired(),"provider retires with last actual view");
}
void limits(){
    auto root=fixture();const std::array<std::uint32_t,2> path{0,0};
    h::Tree cache(root,{1,65536,65535});auto full=cache.resolve(path);
    check(full.status==h::Status::cache_capacity && cache.snapshot().archives==1,"cache budget refuses deeper parse");
    h::Tree entries(root,{64,2,65535});auto counted=entries.resolve(path);
    check(counted.status==h::Status::entry_capacity && entries.snapshot().entries==2,"entry budget charged for accepted ancestor");
    h::Tree tree(root);const auto reads=root->reads;
    check(tree.resolve({}).status==h::Status::invalid_path && root->reads==reads,"empty path refuses before I/O");
    const std::array<std::uint32_t,9> deep{};
    check(tree.resolve(deep).status==h::Status::invalid_path && root->reads==reads,"overdepth refuses before I/O");
    const std::array<std::uint32_t,1> invalid{2};auto bad=tree.resolve(invalid);
    check(bad.status==h::Status::archive_refused && bad.archive_status==reo::native::afs_source_range::Status::invalid_member,"invalid member stays explicit");
    auto faulty=fixture();faulty->fail=true;h::Tree fail(faulty);auto result=fail.resolve(path);
    check(result.status==h::Status::archive_refused && result.archive_status==reo::native::afs_source_range::Status::source_failure && !result.view && !fail.snapshot().archives,"partial provider write never publishes parsed hierarchy");
    bool rejected=false;try{h::Tree wrong(root,{0,1,1});}catch(const std::invalid_argument&){rejected=true;}
    check(rejected,"invalid cache geometry before effects");
}
int main(){ordinary();lifetime();limits();std::printf("%u AFS hierarchy ownership checks passed\n",checks);}
