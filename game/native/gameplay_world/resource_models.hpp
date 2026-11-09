#pragma once
#include "model_attachments.hpp"
#include <array>
#include <optional>
namespace reo::native::gameplay_world {
using ResourceModelId=actors::EntityId;
class ResourceModels;
class ResourceModelWork {
public:
    virtual ~ResourceModelWork()=default;
    virtual void update(ResourceModels&,const ResourceModelId&,ResourceModel&)=0;
};
class ResourceModelPostUpdate {
public:
    virtual ~ResourceModelPostUpdate()=default;
    virtual void apply(ResourceModels&)=0;
};
enum class ResourceModelStatus {completed,full,no_memory,unavailable,foreign_or_stale,busy,closed,budget_exhausted};
enum class ResourceModelPlacement {front,back};
struct ResourceModelCreated {ResourceModelStatus status{ResourceModelStatus::unavailable};ResourceModelId id;std::shared_ptr<ResourceModel> model;};
struct ResourceModelPass {ResourceModelStatus status{ResourceModelStatus::completed};std::size_t called{};};
// One64-object590BE0/590C70/590D80 owner. Descriptor primary capabilities
// retain these same models; retirement invalidates both IDs and retained models.
// Update work is a required concrete native consumer, never a raw guest entry.
class ResourceModels final {
public:
    ResourceModels();
    ~ResourceModels();
    ResourceModels(const ResourceModels&)=delete;
    ResourceModels& operator=(const ResourceModels&)=delete;
    ResourceModelCreated create(ResourceModelPlacement=ResourceModelPlacement::back);
    ResourceModelStatus retire(const ResourceModelId&)noexcept;
    std::shared_ptr<ResourceModel> retain(const ResourceModelId&)const noexcept;
    std::optional<std::uint8_t> physical_slot(const ResourceModelId&)const noexcept;
    ResourceModelId identity_of(const ResourceModel&)const noexcept;
    std::size_t available()const noexcept{return free_count_;}
    ResourceModelId head()const noexcept;
    ResourceModelId tail()const noexcept;
    ResourceModelId previous(const ResourceModelId&)const noexcept;
    ResourceModelId next(const ResourceModelId&)const noexcept;
    ResourceModelPass update(bool skip,ResourceModelPostUpdate* = nullptr,std::size_t budget=4096);
    void request_refresh()noexcept{refresh_=true;}
    bool refresh_requested()const noexcept{return refresh_;}
    ResourceModelStatus close()noexcept;
private:
    struct Node {ResourceModelId id;std::shared_ptr<ResourceModel> model;std::optional<std::uint8_t> previous,next;};
    actors::EntityStore ids_{{64}};
    std::array<std::shared_ptr<Node>,64> slots_;
    std::array<std::uint8_t,64> free_;
    std::size_t free_count_{64};
    std::optional<std::uint8_t> head_,tail_;
    bool running_{},closed_{},refresh_{};
    std::shared_ptr<Node> find(const ResourceModelId&)const noexcept;
};
}
