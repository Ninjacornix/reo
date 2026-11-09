#include "resource_models.hpp"
#include <stdexcept>
namespace reo::native::gameplay_world {
void ResourceModel::retire_data()noexcept{
    retired_=true;correction={};pose={};position={};flags=0;program={};
    active=visible=false;physical_slot=resource_slot=draw_layer=0;asset_index=0;
    part_enabled={};parts={};angles={};work.reset();
}
ResourceModels::ResourceModels(){for(unsigned i=0;i<64;++i)free_[i]=std::uint8_t(i);}
ResourceModels::~ResourceModels(){if(close()==ResourceModelStatus::busy)std::terminate();}
std::shared_ptr<ResourceModels::Node> ResourceModels::find(const ResourceModelId& id)const noexcept{
    if(closed_||!id)return{};
    for(const auto& node:slots_)if(node&&node->id==id)return node;
    return{};
}
ResourceModelCreated ResourceModels::create(ResourceModelPlacement placement){
    if(closed_)return {ResourceModelStatus::closed,{},{}};
    if(!free_count_)return {ResourceModelStatus::full,{},{}};
    try{
        auto node=std::make_shared<Node>();auto model=std::make_unique<ResourceModel>(animation::Matrix{},animation::Matrix{},animation::Vector{},0);
        // EntityStore owns the same object the resource descriptor retains.
        struct Entry final:actors::Entity {std::shared_ptr<ResourceModel> model;};
        auto entry=std::make_unique<Entry>();entry->model=std::move(model);node->model=entry->model;
        const auto created=ids_.create(std::move(entry));if(created.status!=actors::EntityStatus::completed)return {ResourceModelStatus::no_memory,{},{}};
        node->id=created.id;const auto slot=free_[--free_count_];node->model->physical_slot=slot;slots_[slot]=node;
        if(!head_)head_=tail_=slot;
        else if(placement==ResourceModelPlacement::front){node->next=head_;slots_[*head_]->previous=slot;head_=slot;}
        else{node->previous=tail_;slots_[*tail_]->next=slot;tail_=slot;}
        return {ResourceModelStatus::completed,node->id,node->model};
    }catch(const std::bad_alloc&){return {ResourceModelStatus::no_memory,{},{}};}
}
ResourceModelStatus ResourceModels::retire(const ResourceModelId& id)noexcept{
    if(closed_)return ResourceModelStatus::closed;
    const auto node=find(id);if(!node)return ResourceModelStatus::foreign_or_stale;
    const auto index=physical_slot(id);if(!index)return ResourceModelStatus::foreign_or_stale;
    free_[free_count_++]=*index;
    if(node->previous)slots_[*node->previous]->next=node->next;else head_=node->next;
    if(node->next)slots_[*node->next]->previous=node->previous;else tail_=node->previous;
    node->previous.reset();node->next.reset();slots_[*index].reset();
    // Current callback has an invocation lease, but observes cleared model data
    // after retirement just as the source does. It cannot become a new object.
    (void)ids_.retire(id);node->model->retire_data();return ResourceModelStatus::completed;
}
std::shared_ptr<ResourceModel> ResourceModels::retain(const ResourceModelId& id)const noexcept{const auto node=find(id);return node?node->model:nullptr;}
std::optional<std::uint8_t> ResourceModels::physical_slot(const ResourceModelId& id)const noexcept{
    if(closed_||!id)return{};
    for(unsigned i=0;i<64;++i)if(slots_[i]&&slots_[i]->id==id)return std::uint8_t(i);
    return{};
}
ResourceModelId ResourceModels::head()const noexcept{return head_?slots_[*head_]->id:ResourceModelId{};}
ResourceModelId ResourceModels::tail()const noexcept{return tail_?slots_[*tail_]->id:ResourceModelId{};}
ResourceModelId ResourceModels::previous(const ResourceModelId& id)const noexcept{const auto node=find(id);return node&&node->previous?slots_[*node->previous]->id:ResourceModelId{};}
ResourceModelId ResourceModels::next(const ResourceModelId& id)const noexcept{const auto node=find(id);return node&&node->next?slots_[*node->next]->id:ResourceModelId{};}
ResourceModelPass ResourceModels::update(bool skip,ResourceModelPostUpdate* post,std::size_t budget){
    if(closed_)return {ResourceModelStatus::closed,0};
    if(running_)return {ResourceModelStatus::busy,0};
    if(skip)return{};
    running_=true;struct End{bool& value;~End(){value=false;}}end{running_};refresh_=false;ResourceModelPass result;
    auto node=tail_?slots_[*tail_]:nullptr;
    while(node){
        if(result.called>=budget)return {ResourceModelStatus::budget_exhausted,result.called};
        const auto slot=physical_slot(node->id);
        const auto work=node->model->work;if(!work)return {ResourceModelStatus::unavailable,result.called};
        work->update(*this,node->id,*node->model);++result.called;
        if(slot&&slots_[*slot]&&slots_[*slot]!=node)return {ResourceModelStatus::unadmitted_reuse,result.called};
        node=node->previous?slots_[*node->previous]:nullptr;
    }
    if(refresh_){if(!post)return {ResourceModelStatus::unavailable,result.called};post->apply(*this);}
    return result;
}
ResourceModelStatus ResourceModels::close()noexcept{
    if(running_)return ResourceModelStatus::busy;
    if(closed_)return ResourceModelStatus::closed;
    closed_=true;auto old=std::move(slots_);slots_={};head_.reset();tail_.reset();free_count_=64;
    for(auto& node:old)if(node){node->previous.reset();node->next.reset();node->model->retire_data();}
    ids_.shutdown();return ResourceModelStatus::completed;
}
}
