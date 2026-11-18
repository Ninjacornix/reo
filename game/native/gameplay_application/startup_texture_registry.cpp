#include "startup_texture_registry.hpp"
#include "native_session.hpp"
#include <bit>
#include <cstdio>
#include "runtime/assets/virtual_afs.h"
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_application {
namespace {
std::string lower(std::string value){for(auto& c:value)if(c>='A'&&c<='Z')c+='a'-'A';return value;}
struct CommonArchive {
    const reo::assets::Source& source;std::uint64_t base{},bytes{};reo::assets::Table table;
    explicit CommonArchive(const reo::assets::Source& input):source(input){
        const auto root=reo::assets::table(source,0,source.size);
        const auto match=[](const auto& member){return lower(member.name)=="romdata_usa.afs";};
        const auto common=std::find_if(root.entries.begin(),root.entries.end(),match);
        if(common==root.entries.end()||std::find_if(common+1,root.entries.end(),match)!=root.entries.end())throw std::invalid_argument("Startup default archive unavailable");
        base=common->offset;bytes=common->size;table=reo::assets::table(source,base,bytes);
        if(table.entries.size()!=1342)throw std::invalid_argument("Startup default archive profile unavailable");
    }
    std::shared_ptr<const std::vector<std::byte>> read(const char* name)const{
        const auto entry=std::find_if(table.entries.begin(),table.entries.end(),[&](const auto& member){return lower(member.name)==name;});
        if(entry==table.entries.end()||!entry->size)return{};
        const auto extent=(std::uint64_t(entry->size)+2047)&~std::uint64_t(2047);
        if(extent>16*1024*1024||entry->offset>bytes||extent>bytes-entry->offset)throw std::invalid_argument("Startup default resource extent unavailable");
        auto result=std::make_shared<std::vector<std::byte>>(extent);source.read(base+entry->offset,result->size(),result->data());return result;
    }
};
}
StartupTextureRegistry::StartupTextureRegistry(gameplay_world::World& world,std::shared_ptr<const reo::assets::Source> source)noexcept:world_(world),source_(std::move(source)){}
bool StartupTextureRegistry::bound_to(const gameplay_world::World& world)const noexcept{return &world==&world_&&!closed_&&!world_.closed();}
std::shared_ptr<const gameplay_presentation::Texture> StartupTextureRegistry::texture(std::uint32_t id)const noexcept{
    if(!bound_to(world_))return{};
    const auto entry=std::find_if(bindings_.begin(),bindings_.end(),[&](const auto& row){return row.id==id;});
    return entry==bindings_.end()?nullptr:entry->texture;
}
bool StartupTextureRegistry::insert_binding(StartupTextureBinding row){
    std::array<bool,256> used{};for(const auto& current:bindings_)used[current.physical_slot]=true;
    const auto found=std::find(used.begin(),used.end(),false);if(found==used.end())return false;
    row.physical_slot=std::uint16_t(found-used.begin());
    const auto position=std::lower_bound(bindings_.begin(),bindings_.end(),row.physical_slot,
        [](const StartupTextureBinding& value,std::uint16_t slot){return value.physical_slot<slot;});
    bindings_.insert(position,std::move(row));return true;
}
StartupTextureStatus StartupTextureRegistry::bind_common(std::shared_ptr<const gameplay_presentation::CommonFrontendTextures> common)noexcept{
    if(closed_)return common?StartupTextureStatus::closed:StartupTextureStatus::completed;
    if(running_)return StartupTextureStatus::busy;
    if(common_==common)return StartupTextureStatus::completed;
    if(common_&&common)return StartupTextureStatus::unavailable;
    if(!common){
        const auto entry=std::find_if(bindings_.begin(),bindings_.end(),[](const auto& row){return row.id==0;});
        if(entry!=bindings_.end()){
            if(entry->references!=1)return StartupTextureStatus::unavailable;
            bindings_.erase(entry);
        }
        common_.reset();return StartupTextureStatus::completed;
    }
    if(!common->loading_texture())return StartupTextureStatus::unavailable;
    try{
        if(!insert_binding({0,"demo_com.tex:1e2740",common->loading_texture(),{}}))return StartupTextureStatus::unavailable;
        common_=std::move(common);return StartupTextureStatus::completed;
    }catch(const std::bad_alloc&){return StartupTextureStatus::no_memory;}
}
StartupTextureStatus StartupTextureRegistry::load_game_etc()noexcept{
    if(closed_||world_.closed())return StartupTextureStatus::closed;
    if(running_)return StartupTextureStatus::busy;
    if(!source_)return StartupTextureStatus::unavailable;
    running_=true;struct Reset{bool& value;~Reset(){value=false;}}reset{running_};
    try{
        // MAIN236308 selects GAME_ETC.TEX. The complete owned list is one
        // suuji TIM2 record; retain the source1CDE10 newline/NUL parsing and
        // basename/extension replacement before each id is published.
        const CommonArchive archive(*source_);if(world_.closed())return StartupTextureStatus::closed;
        const auto list=archive.read("game_etc.tex");if(world_.closed())return StartupTextureStatus::closed;
        if(!list)return StartupTextureStatus::unavailable;
        std::size_t at{};std::uint32_t id=0x2500;
        while(at<list->size()){
            std::string line;
            while(at<list->size()){
                const char c=char(std::to_integer<unsigned char>((*list)[at++]));
                if(!c||c=='\n')break;
                if(line.size()>=255)return StartupTextureStatus::invalid_asset;
                line.push_back(c);
            }
            const auto extension=line.rfind('.');
            if(extension!=std::string::npos)line.resize(extension);
            else if(const auto comma=line.rfind(',');comma!=std::string::npos)line.resize(comma);
            if(line.empty())break;
            const auto slash=line.rfind('/');if(slash!=std::string::npos)line.erase(0,slash+1);
            const auto name=lower(line+".tm2");
            const auto existing=std::find_if(bindings_.begin(),bindings_.end(),[&](const auto& row){return row.id==id;});
            if(existing!=bindings_.end()){
                const auto count=std::bit_cast<std::uint16_t>(existing->references);
                existing->references=std::bit_cast<std::int16_t>(std::uint16_t(count+1u));
            }else{
                if(bindings_.size()>=256)return StartupTextureStatus::unavailable;
                const auto alias=std::find_if(bindings_.begin(),bindings_.end(),[&](const auto& row){return row.name==name;});
                if(alias!=bindings_.end()){
                    const auto image=alias->texture;const auto encoded=alias->encoded;
                    if(!insert_binding({id,name,image,encoded}))return StartupTextureStatus::unavailable;
                }else{
                    const auto encoded=archive.read(name.c_str());if(world_.closed())return StartupTextureStatus::closed;
                    if(!encoded)return StartupTextureStatus::unavailable;
                    auto image=std::make_shared<const gameplay_presentation::Texture>(gameplay_presentation::decode_texture(*encoded));
                    if(!insert_binding({id,name,std::move(image),encoded}))return StartupTextureStatus::unavailable;
                }
            }
            ++id;
        }
        return StartupTextureStatus::completed;
    }catch(const std::bad_alloc&){return StartupTextureStatus::no_memory;}
    catch(const std::invalid_argument&){return StartupTextureStatus::invalid_asset;}
    catch(...){return StartupTextureStatus::unavailable;}
}
StartupTextureStatus StartupTextureRegistry::release_cockpit_pair()noexcept{
    if(closed_||world_.closed())return StartupTextureStatus::closed;
    if(running_)return StartupTextureStatus::busy;
    for(std::uint32_t id:{0x2600u,0x2601u}){
        const auto entry=std::find_if(bindings_.begin(),bindings_.end(),[&](const auto& row){return row.id==id;});
        if(entry==bindings_.end())continue;
        const auto count=std::bit_cast<std::uint16_t>(entry->references);
        entry->references=std::bit_cast<std::int16_t>(std::uint16_t(count-1u));
        if(entry->references<=0)bindings_.erase(entry);
    }
    return StartupTextureStatus::completed;
}
StartupTextureStatus StartupTextureRegistry::load_scenario_common(NativeSession& session)noexcept{
    if(closed_||world_.closed())return StartupTextureStatus::closed;
    if(running_)return StartupTextureStatus::busy;
    if(!source_||!session.open()||&session.world()!=&world_||!session.archive().bound_to(*source_))return StartupTextureStatus::unavailable;
    running_=true;struct Guard{bool& value;~Guard(){value=false;}}guard{running_};
    try{
        const CommonArchive archive(*source_);if(world_.closed()||!session.open())return StartupTextureStatus::closed;
        const auto compressed=archive.read("cockpit.tex");if(world_.closed()||!session.open())return StartupTextureStatus::closed;
        std::uint32_t next=0x2600;
        if(compressed){
            const auto expanded=std::make_shared<const std::vector<std::byte>>(gameplay_presentation::decompress_texture(*compressed));
            constexpr std::array<std::size_t,4> offsets{0,0x10500,0x20a00,0x21f00};
            for(const auto offset:offsets){
                if(offset>=expanded->size())return StartupTextureStatus::invalid_asset;
                auto image=std::make_shared<const gameplay_presentation::Texture>(gameplay_presentation::decode_texture(std::span(*expanded).subspan(offset)));
                if(!insert_binding({next,"cockpit.tex",std::move(image),expanded}))return StartupTextureStatus::unavailable;
                ++next;
            }
        }
        // The original reads the mode and scenario only after the cockpit
        // bank is published. Recheck after source I/O, which can reenter the
        // host, and retain those earlier publications on refusal.
        if(!world_.scenario||!world_.session().asset_loading_mode||!*world_.session().asset_loading_mode)return StartupTextureStatus::unavailable;
        const auto scenario=*world_.scenario;
        switch(scenario){case 1:case 2:case 28:case 35:case 41:break;default:return StartupTextureStatus::unavailable;}
        char name[24];const int length=std::snprintf(name,sizeof name,"sii_%03u.itt",unsigned(scenario));
        if(length<0||std::size_t(length)>=sizeof name)return StartupTextureStatus::unavailable;
        // 1CCD90 checks for an existing key only when its full mode is below
        // three. Scenario ITT uses 0x10001, so each retry publishes a new
        // physical entry even if the same key is already present.
        const auto encoded=session.archive().read_resource_sectors(scenario,name);
        if(world_.closed()||!session.open())return StartupTextureStatus::closed;
        if(!encoded)return StartupTextureStatus::completed; // source 1CCD90 leaves the absent key unbound
        const auto decoded=gameplay_presentation::decompress_texture(*encoded);
        auto image=std::make_shared<const gameplay_presentation::Texture>(gameplay_presentation::decode_texture(decoded));
        return insert_binding({next,name,std::move(image),encoded})?StartupTextureStatus::completed:StartupTextureStatus::unavailable;
    }catch(const std::bad_alloc&){return StartupTextureStatus::no_memory;}
    catch(const std::invalid_argument&){return StartupTextureStatus::invalid_asset;}
    catch(...){return StartupTextureStatus::unavailable;}
}
StartupTextureStatus StartupTextureRegistry::close()noexcept{
    if(closed_)return StartupTextureStatus::completed;
    if(running_||world_.busy())return StartupTextureStatus::busy;
    common_.reset();bindings_.clear();closed_=true;return StartupTextureStatus::completed;
}
}
