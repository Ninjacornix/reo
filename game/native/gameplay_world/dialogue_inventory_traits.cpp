#include "dialogue_inventory_traits.hpp"
#include <bit>
namespace reo::native::gameplay_world {
std::optional<bool> dialogue_inventory_trait(const Actor& actor,
    const gameplay_scenario::SceneResources* resources,const gameplay_scenario::ResourceTemplates* templates,
    std::uint32_t full_selector)noexcept{
    const auto selector=std::bit_cast<std::int8_t>(std::uint8_t(full_selector));
    if(selector<0||selector>=8)return false;
    if(selector==5)return actor.inventory.storage[0]!=0;
    constexpr std::array<std::uint32_t,8> masks{1,0xc02,4,4,4,0,0x208,0x10};
    const auto matches=[&](std::uint8_t resource)->std::optional<bool>{
        if(!resources)return{};
        const auto identity=resources->slot(resource);
        const auto descriptor=identity?resources->get(*identity):std::nullopt;
        if(!descriptor)return{};
        if(!descriptor->active||descriptor->template_index==255)return false;
        if(!templates||descriptor->template_index>=templates->state().templates.size())return{};
        const auto& data=templates->state().templates[descriptor->template_index].encoded;
        std::uint32_t flags{};
        for(unsigned i=0;i<4;++i)flags|=std::uint32_t(std::to_integer<unsigned>(data[i]))<<(8*i);
        if(!(flags&masks[unsigned(selector)]))return false;
        const auto subtype=std::to_integer<unsigned>(data[10]);
        if(selector==2)return bool(subtype&15);
        if(selector==3)return bool(subtype&16);
        if(selector==4)return !(subtype&31);
        return true;
    };
    bool found{};
    const auto scan=[&](auto& inventory)->bool{
        for(const auto resource:inventory){
            if(!resource)continue;
            const auto match=matches(resource);
            if(!match)return false;
            if(*match){found=true;break;}
        }
        return true;
    };
    if(!scan(actor.inventory.carried))return{};
    // Source selector2 tests character==6 and then character==7 before
    // storage, so that particular storage path is unreachable.
    if(actor.character==6&&selector!=2&&!scan(actor.inventory.storage))return{};
    return found;
}
}
