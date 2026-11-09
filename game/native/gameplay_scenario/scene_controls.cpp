#include "scene_controls.hpp"
#include "action_choices.hpp"
#include <utility>

namespace reo::native::gameplay_scenario {
SceneControls::SceneControls(std::size_t maximum):pool_(std::make_shared<gameplay_scene::Records>(std::uint32_t(maximum))){
    if(maximum>128)throw std::invalid_argument("Native scene pool exceeds 128 records");
}
SceneControls::SceneControls(std::shared_ptr<gameplay_scene::Records> pool):pool_(std::move(pool)){
    if(!pool_)throw std::invalid_argument("Missing canonical scene record owner");
}
SceneControls::~SceneControls()=default;
std::shared_ptr<SceneControls::Node> SceneControls::acquire(const SceneControlId& id)const noexcept{return pool_->acquire(id);}
std::optional<SceneControlId> SceneControls::append(SceneControl value){
    if(clearing_)return{};
    gameplay_scene::Record record;static_cast<SceneControl&>(record)=std::move(value);
    // Standalone append preserves its established traversal order. The room
    // importer explicitly uses newest, as original 5C11B0(0) does.
    return pool_->create(std::move(record),gameplay_scene::Placement::oldest);
}
std::optional<SceneControl> SceneControls::get(const SceneControlId& id)const noexcept{
    const auto node=acquire(id);if(!node)return{};
    return node->value;
}
ControlStatus SceneControls::replace(const SceneControlId& id,SceneControl value)noexcept{
    const auto node=acquire(id);if(!node)return ControlStatus::invalid_identity;
    pool_->touch();static_cast<SceneControl&>(node->value)=std::move(value);return ControlStatus::completed;
}
ControlStatus SceneControls::reset_five(const SceneControlId& id)noexcept{
    const auto node=acquire(id);if(!node)return ControlStatus::invalid_identity;
    auto* five=std::get_if<ControlTypeFive>(&node->value.body);if(!five)return ControlStatus::invalid_profile;
    pool_->touch();node->value.enabled=0;five->selector=0;five->reset_sentinel=UINT16_MAX;
    five->reset_byte_a=0;five->reset_byte_b=0;five->duration=0;five->countdown=0;
    five->completion=UINT32_MAX;five->byte_parameter=UINT8_MAX;five->secondary_parameter=0;
    return ControlStatus::completed;
}
ControlStatus SceneControls::erase(const SceneControlId& id)noexcept{return pool_->retire(id)?ControlStatus::completed:ControlStatus::invalid_identity;}
void SceneControls::clear()noexcept{
    if(clearing_)return;
    clearing_=true;pool_->clear();clearing_=false;
}
ControlRouteResult SceneControls::first_route(std::uint8_t authored_id,std::size_t maximum_visits)const noexcept{
    ControlRouteResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    if(!enabled_)return result;
    for(auto node=pool_->first();node;node=node->next){
        if(result.visited>=maximum_visits){result.status=ControlStatus::budget_exhausted;return result;}
        ++result.visited;const auto* other=std::get_if<ControlOther>(&node->value.body);
        const bool type=std::holds_alternative<ControlTypeZero>(node->value.body)||std::holds_alternative<ControlTypeTwo>(node->value.body)||(other&&(other->type==0||other->type==2));
        if(type&&node->value.authored_id==authored_id){result.id=node->id;return result;}
    }
    return result;
}
ControlResult SceneControls::disable_three(std::size_t maximum_visits)noexcept{
    ControlResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    pool_->touch();
    if(!enabled_)return result;
    for(auto node=pool_->first();node;node=node->next){
        if(result.visited>=maximum_visits){result.status=ControlStatus::budget_exhausted;return result;}
        ++result.visited;const auto* other=std::get_if<ControlOther>(&node->value.body);
        if(std::holds_alternative<ControlTypeThree>(node->value.body)||(other&&other->type==3)){node->value.enabled=0;++result.matched;}
    }
    return result;
}
ControlResult SceneControls::choose_five(std::uint32_t authored_id,const std::array<std::uint32_t,4>& choices,ActionChoices& selection,std::uint8_t character,bool permitted,gameplay_session::Random& random,std::size_t maximum_visits)noexcept{
    ControlResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    pool_->touch();
    if(!enabled_||!permitted)return result;
    for(auto node=pool_->first();node;node=node->next)if(node->value.authored_id==authored_id){
        if(const auto* other=std::get_if<ControlOther>(&node->value.body);other&&other->type==5){result.status=ControlStatus::invalid_profile;return result;}
    }
    for(auto node=pool_->first();node;node=node->next){
        if(result.visited>=maximum_visits){result.status=ControlStatus::budget_exhausted;return result;}
        ++result.visited;
        if(node->value.authored_id!=authored_id||!std::holds_alternative<ControlTypeFive>(node->value.body))continue;
        const auto selected=selection.choose(choices,character,random);if(!selected)return result;
        (void)reset_five(node->id);node->value.enabled=1;--node->value.counter;
        std::get<ControlTypeFive>(node->value.body).reset_sentinel=std::uint16_t(*selected|0x4000u);
        result.matched=1;return result;
    }
    return result;
}
ControlResult SceneControls::apply_typed(bool enable,std::uint32_t type,std::uint32_t authored_id,std::uint32_t selector,std::size_t maximum_visits)noexcept{
    ControlResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    pool_->touch();
    if(!enabled_)return result;
    const bool supported=type==0||type==1||type==2||type==3||type==4||type==6||type==7||type==11||type==13;
    // An opaque tag does not supply the fields required by a typed command.
    // Refuse before mutating earlier records, rather than inventing values.
    if(supported)for(auto node=pool_->first();node;node=node->next){
        if(const auto* other=std::get_if<ControlOther>(&node->value.body);other&&other->type==type){result.status=ControlStatus::invalid_profile;return result;}
    }
    for(auto node=pool_->first();node;node=node->next){
        if(result.visited>=maximum_visits){result.status=ControlStatus::budget_exhausted;return result;}
        ++result.visited;auto& record=node->value;const auto& body=record.body;bool match=false;
        switch(type){
        case 0:match=std::holds_alternative<ControlTypeZero>(body)&&record.authored_id==authored_id;break;
        case 1:match=std::holds_alternative<ControlTypeOne>(body)&&record.authored_id==authored_id;break;
        case 2:if(const auto* v=std::get_if<ControlTypeTwo>(&body))match=record.authored_id==authored_id&&v->selector==selector;break;
        case 3:if(const auto* v=std::get_if<ControlTypeThree>(&body))match=record.authored_id==authored_id&&(v->mode&1u)==selector;break;
        case 4:if(const auto* v=std::get_if<ControlTypeFour>(&body))match=v->selector==authored_id;break;
        case 6:if(const auto* v=std::get_if<ControlTypeSix>(&body))match=v->selector==authored_id;break;
        case 7:if(const auto* v=std::get_if<ControlTypeSeven>(&body))match=v->selector==authored_id;break;
        case 11:match=std::holds_alternative<ControlTypeEleven>(body)&&record.authored_id==authored_id;break;
        case 13:if(const auto* v=std::get_if<ControlTypeThirteen>(&body))match=v->selector==authored_id;break;
        default:break;
        }
        if(match){record.enabled=enable?1:0;++result.matched;}
    }
    return result;
}
ControlResult SceneControls::apply(ControlCommand command,const ControlArguments& a,ControlEffects* effects,std::size_t maximum_visits)noexcept{
    ControlResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    pool_->touch();
    if(!enabled_)return result;
    // Missing dependencies refuse before any record in this operation mutates.
    if(!effects&&command==ControlCommand::refresh_zero_two){
        for(auto node=pool_->first();node;node=node->next)if(node->value.authored_id==a.authored_id){
            const auto& body=node->value.body;
            if(std::holds_alternative<ControlTypeZero>(body)||
                (std::holds_alternative<ControlTypeTwo>(body)&&std::get<ControlTypeTwo>(body).selector!=0)){
                result.status=ControlStatus::provider_unavailable;return result;
            }
        }
    }
    for(auto node=pool_->first();node;node=node->next){
        if(result.visited>=maximum_visits){result.status=ControlStatus::budget_exhausted;return result;}
        ++result.visited;auto& record=node->value;
        if(command==ControlCommand::enable_thirteen){const auto* thirteen=std::get_if<ControlTypeThirteen>(&record.body);if(!thirteen||thirteen->selector!=a.authored_id)continue;}
        else if(record.authored_id!=a.authored_id)continue;
        auto& body=record.body;bool matched=false;
        auto* zero=std::get_if<ControlTypeZero>(&body);auto* one=std::get_if<ControlTypeOne>(&body);auto* two=std::get_if<ControlTypeTwo>(&body);
        auto* three=std::get_if<ControlTypeThree>(&body);auto* four=std::get_if<ControlTypeFour>(&body);
        switch(command){
        case ControlCommand::zero_two_parameter:
            if(zero){zero->parameter=a.parameter;zero->byte_parameter=0;matched=true;}
            else if(two&&two->selector==a.selector){two->parameter=a.parameter;matched=true;}
            break;
        case ControlCommand::type_one_parameter:if(one){one->parameter=std::uint16_t(a.parameter);matched=true;}break;
        case ControlCommand::enable_even:case ControlCommand::disable_even:
            if((three&&(three->mode==0||three->mode==2))||(four&&four->mode==0)){
                record.enabled=command==ControlCommand::enable_even?1:0;
                if(command==ControlCommand::enable_even&&three&&three->mode==2)three->parameter=std::uint16_t(a.parameter);
                matched=true;
            }break;
        case ControlCommand::zero_word_byte:if(zero){zero->parameter=a.parameter;zero->byte_parameter=std::uint8_t(a.selector);matched=true;}break;
        case ControlCommand::restart_five:case ControlCommand::reset_five:case ControlCommand::restart_five_byte:
            if(std::holds_alternative<ControlTypeFive>(body)){
                if(effects)effects->reset(*this,node->id);else reset_five(node->id);
                pool_->touch(); // effects may have observed the reset activation
                auto* five=std::get_if<ControlTypeFive>(&node->value.body);
                if(!five){result.status=ControlStatus::invalid_profile;return result;}
                if(command!=ControlCommand::reset_five){node->value.enabled=1;five->selector=std::uint16_t(a.parameter);
                    if(command==ControlCommand::restart_five){five->duration=std::uint16_t(a.selector);five->countdown=0;five->completion=UINT32_MAX;}
                    else{five->byte_parameter=std::uint8_t(a.selector);five->secondary_parameter=a.extra;}
                }
                matched=true;
            }break;
        case ControlCommand::enable_odd:case ControlCommand::disable_odd:
            if((three&&(three->mode==1||three->mode==3))||(four&&four->mode==1)){
                record.enabled=command==ControlCommand::enable_odd?1:0;
                if(command==ControlCommand::enable_odd&&three&&three->mode==3)three->parameter=std::uint16_t(a.parameter);
                matched=true;
            }break;
        case ControlCommand::enable_one:case ControlCommand::disable_one:if(one){record.enabled=command==ControlCommand::enable_one?1:0;matched=true;}break;
        case ControlCommand::enable_zero_two:case ControlCommand::disable_zero_two:if(zero||two){record.enabled=command==ControlCommand::enable_zero_two?1:0;matched=true;}break;
        case ControlCommand::zero_two_half:if(zero){zero->half_parameter=std::uint16_t(a.parameter);matched=true;}else if(two){two->half_parameter=std::uint16_t(a.parameter);matched=true;}break;
        case ControlCommand::enable_nine:if(auto* nine=std::get_if<ControlTypeNine>(&body)){record.enabled=1;nine->parameter=a.parameter;matched=true;}break;
        case ControlCommand::enable_thirteen:if(auto* thirteen=std::get_if<ControlTypeThirteen>(&body)){record.enabled=1;thirteen->parameter=std::uint16_t(a.parameter);matched=true;}break;
        case ControlCommand::refresh_zero_two:
            if(zero){zero->refresh_parameter=std::uint8_t(a.parameter);effects->refresh(*this,node->id,std::uint8_t(record.authored_id));matched=true;}
            else if(two){two->refresh_parameter=std::uint8_t(a.parameter);if(two->selector)effects->refresh(*this,node->id,std::uint8_t(record.authored_id));matched=true;}
            break;
        }
        result.matched+=matched?1u:0u;
    }
    return result;
}
} // namespace reo::native::gameplay_scenario
