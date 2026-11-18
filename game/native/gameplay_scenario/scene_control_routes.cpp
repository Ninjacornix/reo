#include "scene_control_routes.hpp"
namespace reo::native::gameplay_scenario {
namespace {
class Target final:public gameplay_collision::delivery::RouteTarget {
    std::shared_ptr<SceneControls> owner_;SceneControlId id_;std::uint8_t type_;
public:
    Target(std::shared_ptr<SceneControls> owner,SceneControlId id,std::uint8_t type):owner_(std::move(owner)),id_(std::move(id)),type_(type){}
    std::uint8_t type()const noexcept override{return type_;}
    std::optional<gameplay_collision::delivery::RouteDestination> destination()const override{
        const auto record=owner_->get(id_);if(!record)return{};
        if(type_!=0)return{};
        const auto* zero=std::get_if<ControlTypeZero>(&record->body);
        const auto value=zero?zero->destination:std::nullopt;if(!value)return{};
        return gameplay_collision::delivery::RouteDestination{value->room,value->edge};
    }
};
}
gameplay_collision::delivery::RouteLookup lookup_scene_route(std::shared_ptr<SceneControls> owner,std::uint8_t edge)noexcept{
    if(!owner)return{};
    const auto found=owner->first_route(edge);if(found.status!=ControlStatus::completed)return{};if(!found.id)return{true,{}};
    const auto record=owner->get(*found.id);if(!record)return{};
    std::uint8_t type{};
    if(std::holds_alternative<ControlTypeTwo>(record->body))type=2;
    else if(const auto* other=std::get_if<ControlOther>(&record->body))type=other->type;
    else if(!std::holds_alternative<ControlTypeZero>(record->body))return{};
    try{return{true,std::make_shared<const Target>(std::move(owner),*found.id,type)};}catch(const std::bad_alloc&){return{};}
}
}
