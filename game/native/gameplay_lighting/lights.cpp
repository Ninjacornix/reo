#include "lights.hpp"
namespace reo::native::gameplay_lighting {
Created Pool::allocate()noexcept{return create({},0,0);}
Created Pool::create(const std::optional<Definition>& definition,std::uint8_t selector,std::uint8_t variant)noexcept{
    if(closed_)return{};
    const auto index=owner_.allocate(definition?&*definition:nullptr,selector,variant);
    if(!index)return{Status::full,{},{}};
    const auto id=owner_.handle(*index);
    if(!id)return{Status::foreign_or_stale,{},{}};
    return{Status::completed,*id,owner_.light(*id)};
}
Status Pool::retire(const LightId& id)noexcept{if(closed_)return Status::closed;return owner_.release(id)?Status::completed:Status::foreign_or_stale;}
Status Pool::replace(const LightId& id,const Definition& value)noexcept{if(closed_)return Status::closed;return owner_.replace(id,value)?Status::completed:Status::foreign_or_stale;}
std::optional<Light> Pool::retain(const LightId& id)const noexcept{return closed_?std::nullopt:owner_.light(id);}
std::optional<std::uint8_t> Pool::physical_slot(const LightId& id)const noexcept{return closed_?std::nullopt:owner_.slot(id);}
std::vector<FrameEntry> Pool::snapshot()const{std::vector<FrameEntry> result;if(closed_)return result;result.reserve(size());for(unsigned i=0;i<64;++i){const auto id=owner_.handle(std::uint8_t(i));if(id)result.push_back({*id,*owner_.light(*id)});}return result;}
Status Pool::reset()noexcept{if(closed_)return Status::closed;for(unsigned i=0;i<64;++i)if(owner_.primary()[i].active&&!owner_.release(std::uint8_t(i)))return Status::foreign_or_stale;return Status::completed;}
void Pool::close()noexcept{if(closed_)return;(void)reset();closed_=true;}
}
