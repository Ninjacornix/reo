#include "source_profile.h"
#include "game/native/afs_source_range/afs_source_range.hpp"
#include <climits>
#include <new>

namespace reo::native::resources {
// Internal native preparation capability. Construction performs no provider
// read; the first asynchronous/header read materializes the immutable view.
std::shared_ptr<const ByteView> retain_resident_view(std::shared_ptr<const ByteView>,std::string);
}
namespace reo::native::adxt_binding {
namespace {
bool canonical(std::string_view name,std::string& result){
    if(name.empty() || name.size()>255)return false;
    result.reserve(name.size());
    for(unsigned char c:name){if(c<32 || c>126)return false;if(c=='/')c='\\';if(c>='a' && c<='z')c=static_cast<unsigned char>(c-'a'+'A');result.push_back(static_cast<char>(c));}
    for(const auto prefix:{"CDROM0:","CDROM:","HOST:"})if(result.starts_with(prefix)){result.erase(0,std::char_traits<char>::length(prefix));break;}
    while(!result.empty() && result.front()=='\\')result.erase(0,1);
    const auto version=result.find(';');
    if(version!=std::string::npos){if(result.substr(version)!=";1")return false;result.resize(version);}
    if(result.empty() || result.find(':')!=std::string::npos)return false;
    std::size_t at{};
    while(at<result.size()){
        const auto end=result.find('\\',at);const auto part=std::string_view(result).substr(at,end==std::string::npos?std::string::npos:end-at);
        if(part.empty() || part=="." || part=="..")return false;
        if(end==std::string::npos)break;
        at=end+1;if(at==result.size())return false;
    }
    return true;
}
}
FileSource prepare_file_source(const std::shared_ptr<const resources::win32::MountedResources>& mount,FileRequest request)noexcept{
    if(!mount)return{};
    if(mount->identity().import_version!=1 || mount->identity().overlay_plan_sha256)return{FileStatus::unsupported_mount};
    if(request.backend_argument)return{FileStatus::unsupported_argument};
    try{
        FileSource result;
        if(!canonical(request.filename,result.canonical_key)){result.status=FileStatus::invalid_name;return result;}
        const auto root=mount->find_file(result.canonical_key);
        if(!root){result.status=FileStatus::missing_file;return result;}
        if(root->overlay || !root->view || root->view->size()!=root->bytes || root->bytes%2048 || root->bytes>INT32_MAX){result.status=FileStatus::unsupported_range;return result;}
        const auto range=afs_source_range::prepare_open(request.start_sector,request.sector_count,static_cast<std::uint32_t>(root->bytes/2048));
        result.start_sector=range.start_sector;result.bytes=range.byte_length;
        if(range.status!=afs_source_range::Status::completed || !range.inside_backend){result.status=FileStatus::unsupported_range;return result;}
        if(!range.byte_length){result.status=FileStatus::empty_range;return result;}
        const auto view=resources::bounded_view(root->view,std::uint64_t(range.start_sector)*2048,range.byte_length);
        if(view.status!=resources::Status::ok){result.status=view.status==resources::Status::no_memory?FileStatus::no_memory:FileStatus::unsupported_range;return result;}
        std::string identity="native-audio:";identity.reserve(384);
        constexpr char hex[]="0123456789abcdef";
        for(const auto byte:mount->identity().route_sha256){identity.push_back(hex[byte>>4]);identity.push_back(hex[byte&15]);}
        identity+=':';identity+=result.canonical_key;identity+='@';identity+=std::to_string(range.start_sector);identity+=':';identity+=std::to_string(range.byte_length);
        result.view=resources::retain_resident_view(view.view,std::move(identity));result.status=FileStatus::ready;return result;
    }catch(const std::bad_alloc&){return{FileStatus::no_memory};}
     catch(...){return{FileStatus::unsupported_range};}
}
}
