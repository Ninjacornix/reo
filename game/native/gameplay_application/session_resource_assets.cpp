#include "session_resources.hpp"
#include <cstdio>
#include <stdexcept>
namespace reo::native::gameplay_application {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||bytes.size()-at<4)throw std::invalid_argument("Truncated item asset header");
    std::uint32_t value{};for(unsigned i=0;i<4;++i)value|=std::uint32_t(std::to_integer<std::uint8_t>(bytes[at+i]))<<(8*i);return value;
}
}
std::shared_ptr<const SessionResourceAssets> SessionResourceAssets::load(
    const gameplay_scenario::content::ScenarioArchive& archive,std::uint16_t scenario,
    std::string_view model_key,std::shared_ptr<const gameplay_effects::EffectBank> effects,
    std::shared_ptr<const gameplay_collision::delivery::Catalog> contacts){
    if(!effects||!contacts||model_key.empty())throw std::invalid_argument("Actual resource asset capabilities required");
    (void)contacts->tables();char name[32];const int count=std::snprintf(name,sizeof name,"item%03u.dat",unsigned(scenario));
    if(count<0||std::size_t(count)>=sizeof name)throw std::invalid_argument("Resource asset key extent");
    const auto item=archive.read_resource(scenario,name),geometry=archive.read_resource(scenario,model_key);
    if(!item||!geometry)throw std::invalid_argument("Owned item/static resource asset unavailable");
    auto result=std::make_shared<SessionResourceAssets>();result->scenario=scenario;result->item_key=name;result->model_key=model_key;result->item_file=item;
    //5920C0 admits each pair only when both offset and length are nonzero.
    // Validate all retained sections, but do not silently execute missing live
    // placement or tuning imports merely by owning their immutable bytes.
    for(unsigned i=0;i<3;++i){const auto at=word(*item,8*i),size=word(*item,8*i+4);
        if(!at||!size)continue;
        if(at>item->size()||size>item->size()-at)throw std::invalid_argument("Item asset section extent");
        if(i==0&&!result->templates.load(std::span(*item).subspan(at,size)))throw std::invalid_argument("Item template version unavailable");
    }
    if(!result->templates.state().count)throw std::invalid_argument("Item template table unavailable");
    result->models=gameplay_world::ResourceStaticAssets::import_nbd(*geometry);
    result->effects=std::move(effects);result->contacts=std::move(contacts);return result;
}
}
