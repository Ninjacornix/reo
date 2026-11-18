#include "frontend_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <stdexcept>

namespace reo::native::gameplay_presentation {
namespace {
std::string lower(std::string name){for(auto& c:name)if(c>='A'&&c<='Z')c+='a'-'A';return name;}
constexpr std::size_t loading_offset=0x1e2740,loading_size=0x8500;
}
CommonFrontendTextures::CommonFrontendTextures(std::vector<std::byte> bytes):bytes_(std::move(bytes)){
    if(bytes_.size()<loading_offset+loading_size)throw std::invalid_argument("Common loading texture unavailable");
    auto texture=decode_texture(std::span(bytes_).subspan(loading_offset,loading_size));
    if(texture.width!=256||texture.height!=128)throw std::invalid_argument("Common loading texture profile unavailable");
    loading_texture_=std::make_shared<Texture>(std::move(texture));
}
FrontendAssets::FrontendAssets(std::shared_ptr<const reo::assets::Source> source):source_(std::move(source)){
    if(!source_)throw std::invalid_argument("Frontend source unavailable");
    const auto root=reo::assets::table(*source_,0,source_->size);
    const auto match=[](const auto& member){return lower(member.name)=="romdata_usa.afs";};
    const auto found=std::find_if(root.entries.begin(),root.entries.end(),match);
    if(found==root.entries.end()||std::find_if(found+1,root.entries.end(),match)!=root.entries.end())throw std::invalid_argument("Frontend archive unavailable");
    base_=found->offset;bytes_=found->size;
}
std::vector<std::byte> FrontendAssets::read(std::size_t ordinal,const char* name)const{
    const auto table=reo::assets::table(*source_,base_,bytes_);
    if(table.entries.size()!=1342||ordinal>=table.entries.size())throw std::invalid_argument("Frontend archive profile unavailable");
    const auto& member=table.entries[ordinal];
    if(lower(member.name)!=name||!member.size||member.size>16*1024*1024||member.offset>bytes_||member.size>bytes_-member.offset)
        throw std::invalid_argument("Frontend asset unavailable");
    std::vector<std::byte> result(member.size);source_->read(base_+member.offset,result.size(),result.data());return result;
}
FontFace FrontendAssets::load_font()const{return FontFace(read(554,"s20le04.bin"));}
std::shared_ptr<const CommonFrontendTextures> FrontendAssets::load_common_textures()const{
    return std::make_shared<CommonFrontendTextures>(decompress_texture(read(557,"demo_com.tex")));
}
}
