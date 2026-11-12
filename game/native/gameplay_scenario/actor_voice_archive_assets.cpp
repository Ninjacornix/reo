#include "actor_voice_archive_assets.hpp"
#include "../resources/virtual_file_view.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+=char('a'-'A');return value;}
}
ActorVoiceArchiveAssets::ActorVoiceArchiveAssets(std::shared_ptr<reo::assets::Source> source){
    if(!source)throw std::invalid_argument("Native actor voice audio source unavailable");
    const auto root=reo::assets::table(*source,0,source->size);
    const auto match=[](const auto& entry){return lower(entry.name)=="adxsnd.afs";};
    const auto audio=std::find_if(root.entries.begin(),root.entries.end(),match);
    if(audio==root.entries.end()||std::find_if(audio+1,root.entries.end(),match)!=root.entries.end())
        throw std::invalid_argument("Native actor voice audio archive missing or ambiguous");
    const auto entries=reo::assets::table(*source,audio->offset,audio->size);
    if(entries.entries.size()<=408)throw std::invalid_argument("Native actor voice archive index profile unavailable");
    reo::assets::VirtualFile file;file.size=source->size;file.segments.push_back({0,source->size,0,std::move(source),{}});
    const auto retained=resources::VirtualFileView::create(file);
    if(retained.status!=resources::Status::ok||!retained.view)throw std::invalid_argument("Native actor voice source view unavailable");
    for(unsigned character=0;character<characters;++character){
        std::array<char,32> filename{};std::snprintf(filename.data(),filename.size(),"vo001%02u.afs",character);
        const auto& entry=entries.entries[catalog_id(std::uint8_t(character))];
        if(lower(entry.name)!=filename.data())throw std::invalid_argument("Native actor voice nested archive identity differs");
        const auto opened=afs_source_range::Archive::open(retained.view,std::uint64_t(audio->offset)+entry.offset,entry.size,1000);
        if(opened.status!=afs_source_range::Status::completed||!opened.archive||opened.archive->count()!=1000)
            throw std::invalid_argument("Native actor voice nested archive profile unavailable");
        archives_[character]=opened.archive;
        identities_[character]="File1 NETBIO01/adxsnd.afs/"+std::string(filename.data());
    }
}
}
