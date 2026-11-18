#include "source_profile.h"
#include <array>
#include <iostream>
#include <stdexcept>

namespace b=reo::native::adxt_binding;
namespace m=reo::native::resources::win32;
namespace r=reo::native::resources;
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("File source check "+std::to_string(checks));}
int main(int argc,char** argv)try{
    check(argc==2);check(b::prepare_file_source({},{}).status==b::FileStatus::missing_mount);
    auto opened=m::MountedResources::open_file1_windows(std::filesystem::path(argv[1]));check(opened.status==m::MountStatus::ok);
    auto mount=std::move(opened.mount);check(mount->routes().size()==85 && mount->identity().import_version==1 && !mount->identity().overlay_plan_sha256);
    std::array<std::byte,4096> expected{},actual{};
    std::shared_ptr<const r::ByteView> retained;
    {
    auto root=mount->find_file("NETBIO01.DAT");check(root && root->bytes>8192 && root->bytes%2048==0);
    check(root->view->read(2048,expected).status==r::Status::ok);
    for(const auto path:{"NETBIO01.DAT","netbio01.dat","cdrom0:\\NETBIO01.DAT;1","CDROM:/netbio01.dat;1","host:\\NETBIO01.DAT","\\\\NETBIO01.DAT"}){
        const auto source=b::prepare_file_source(mount,{path,0,1,2});
        check(source.status==b::FileStatus::ready && source.canonical_key=="NETBIO01.DAT" && source.start_sector==1 && source.bytes==4096 && source.view && source.view->size()==4096);
        check(source.view->read(0,actual).status==r::Status::ok && actual==expected);retained=source.view;
        std::byte extra{};check(source.view->read(4096,{&extra,1}).status==r::Status::invalid_range);
    }
    for(const auto path:{"","../NETBIO01.DAT","NETBIO01.DAT/../x","NETBIO01.DAT//x","NETBIO01.DAT/","NETBIO01.DAT;2","C:\\NETBIO01.DAT","cdrom0:","NETBIO01.DAT;1;1"})
        check(b::prepare_file_source(mount,{path,0,0,1}).status==b::FileStatus::invalid_name);
    check(b::prepare_file_source(mount,{std::string_view("NETBIO\0.DAT",11),0,0,1}).status==b::FileStatus::invalid_name);
    check(b::prepare_file_source(mount,{std::string(256,'a'),0,0,1}).status==b::FileStatus::invalid_name);
    check(b::prepare_file_source(mount,{"MISSING.ADX",0,0,1}).status==b::FileStatus::missing_file);
    check(b::prepare_file_source(mount,{"NETBIO01.DAT",1,0,1}).status==b::FileStatus::unsupported_argument);
    const auto sectors=static_cast<std::uint32_t>(root->bytes/2048);
    const auto end=b::prepare_file_source(mount,{"NETBIO01.DAT",0,sectors-1,0xffffe});
    check(end.status==b::FileStatus::ready && end.start_sector==sectors-1 && end.bytes==2048);
    const auto empty=b::prepare_file_source(mount,{"NETBIO01.DAT",0,sectors+1,2});
    check(empty.status==b::FileStatus::empty_range && empty.start_sector==sectors && empty.bytes==0 && !empty.view);
    const auto zero=b::prepare_file_source(mount,{"NETBIO01.DAT",0,0,0});check(zero.status==b::FileStatus::empty_range && !zero.view);
    const auto whole=b::prepare_file_source(mount,{"NETBIO01.DAT",0,0,0xfffff});
    // The finite resident audio profile refuses an archive-sized range; it
    // never truncates that request into a playable prefix.
    check(whole.status==b::FileStatus::unsupported_range && !whole.view);
    const auto sentinel=b::prepare_file_source(mount,{"NETBIO01.DAT",0,1,0xfffff});
    check(sentinel.status==b::FileStatus::unsupported_range && sentinel.start_sector==1 && sentinel.bytes==root->bytes && !sentinel.view);
    check(b::prepare_file_source(mount,{"NETBIO01.DAT",0,0x100000,1}).status==b::FileStatus::unsupported_range);
    } // Drop EVERY other prepared view and root route before the retained read.
    mount.reset();check(retained->read(0,actual).status==r::Status::ok && actual==expected);
    std::cout<<"actual retained file source profile checks="<<checks<<" exact_subrange_bytes="<<retained->size()<<" mount_released=true\n";return 0;
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
