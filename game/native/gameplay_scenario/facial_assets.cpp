#include "facial_assets.hpp"
#include "../../../runtime/assets/virtual_afs.h"
#include <algorithm>
#include <stdexcept>
#include <string>
namespace reo::native::gameplay_scenario {
namespace {
struct MatrixEntry {unsigned kind,character,ordinal;const char* name;};
struct LipEntry {unsigned scenario,cue,voice,speaker,ordinal;const char* name;};
#include "facial_asset_catalogue.inc"
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+='a'-'A';return value;}
}
File1FacialAssets::File1FacialAssets(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)){
    if(!source_)throw std::invalid_argument("Native facial File1 source unavailable");
    const auto root=reo::assets::table(*source_,0,source_->size);
    const auto matches=[](const auto& entry){return lower(entry.name)=="romdata_usa.afs";};
    const auto found=std::find_if(root.entries.begin(),root.entries.end(),matches);
    if(found==root.entries.end()||std::find_if(found+1,root.entries.end(),matches)!=root.entries.end())
        throw std::invalid_argument("Native facial default archive unavailable or ambiguous");
    const auto catalogue=reo::assets::table(*source_,found->offset,found->size);
    if(catalogue.entries.size()!=1342)throw std::invalid_argument("Native facial compiled catalogue profile unavailable");
    std::size_t slot{};
    const auto add=[&](const auto& declaration,bool matrix){
        const auto& entry=catalogue.entries.at(declaration.ordinal);
        const auto storage=(std::uint64_t(entry.size)+2047u)&~std::uint64_t(2047u);
        if(lower(entry.name)!=lower(declaration.name)||(matrix&&entry.size!=3072)||
           (!matrix&&(entry.size<20||entry.size>65536))||entry.offset>found->size||
           storage>std::uint64_t(found->size)-entry.offset||storage>65536)
            throw std::invalid_argument("Native facial owned asset extent/name unavailable");
        ranges_.at(slot++)={std::uint64_t(found->offset)+entry.offset,entry.size,std::uint32_t(storage)};
    };
    for(const auto& entry:matrix_entries)add(entry,true);
    for(const auto& entry:lip_entries)add(entry,false);
}
FacialAssetBytes File1FacialAssets::read(std::size_t slot)const{
    const auto& range=ranges_.at(slot);
    auto bytes=std::make_shared<std::vector<std::byte>>(range.storage);
    source_->read(range.offset,bytes->size(),bytes->data());return{std::move(bytes),range.logical};
}
FacialAssetBytes File1FacialAssets::matrix(FacialMatrixKind kind,std::uint16_t character)const{
    const auto numeric=kind==FacialMatrixKind::player?0u:1u;
    for(std::size_t index=0;index<std::size(matrix_entries);++index){const auto& entry=matrix_entries[index];if(entry.kind==numeric&&entry.character==character)return read(index);}
    return{};
}
FacialAssetBytes File1FacialAssets::lip(std::uint16_t scenario,std::uint16_t cue,std::uint16_t voice,std::uint32_t speaker)const{
    for(std::size_t index=0;index<std::size(lip_entries);++index){const auto& entry=lip_entries[index];if(entry.scenario==scenario&&entry.cue==cue&&entry.voice==voice&&entry.speaker==speaker)return read(std::size(matrix_entries)+index);}
    return{};
}
} // namespace reo::native::gameplay_scenario
