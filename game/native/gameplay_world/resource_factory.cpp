#include "resource_factory.hpp"
#include <bit>
#include <new>
#include <stdexcept>
namespace reo::native::gameplay_world {
ResourceFactory::ResourceFactory(ResourceModels& models,ResourceFrames& frames,
    const gameplay_scenario::ResourceTemplates& templates,std::shared_ptr<const ResourceStaticAssets> assets):models_(models),frames_(frames),templates_(templates),assets_(std::move(assets)){
    if(!assets_||!frames_.open()||!frames_.bound_to(models_)||!frames_.templates_bound_to(templates_))throw std::invalid_argument("Native resource factory owners unavailable or foreign");
}
ResourceModelCreated ResourceFactory::create(std::uint16_t content,std::int8_t){
    if(!frames_.open())return{ResourceModelStatus::closed,{},{}};
    auto created=models_.create(ResourceModelPlacement::back);
    if(created.status!=ResourceModelStatus::completed)return created;
    try{
        const auto selector=std::bit_cast<std::uint8_t>(templates_.selector(std::bit_cast<std::int16_t>(content)));
        unsigned callback_class{};
        if(selector!=255){
            if(selector>=templates_.state().templates.size())throw std::runtime_error("Native resource callback template unavailable");
            callback_class=std::to_integer<std::uint8_t>(templates_.state().templates[selector].encoded[20]);
        }
        if(callback_class!=0&&callback_class!=1&&callback_class!=3)throw std::runtime_error("Native resource factory callback consumer unavailable");
        switch(content){case 0x75:case 0x135:case 0x1d:case 0x1c:case 0x3200:case 0x72:throw std::runtime_error("Native resource companion visual consumer unavailable");default:break;}
        const auto index=assets_->find(std::bit_cast<std::int16_t>(content));
        auto& model=*created.model;
        model.content_id=content;model.active=true;model.category=8;model.draw_tag=255;model.asset_index=index;
        model.pose=transform_math::identity();model.axis_scale={1,1,1};
        if(index>=0){
            model.base_parts=assets_->parts(index);model.visible=true;
            for(unsigned part=0;part<model.base_parts->count;++part){model.parts[part]=model.base_parts->poses[part];model.part_enabled[part]=1;}
        }
        if(callback_class==1)model.work=std::make_shared<WeaponModelWork>(frames_);
        else model.work=std::make_shared<CommonModelWork>(frames_);
        return created;
    }catch(const std::bad_alloc&){(void)models_.retire(created.id);return{ResourceModelStatus::no_memory,{},{}};}
    catch(const std::exception&){(void)models_.retire(created.id);return{ResourceModelStatus::unavailable,{},{}};}
}
}
