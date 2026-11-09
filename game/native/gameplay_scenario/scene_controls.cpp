#include "scene_controls.hpp"
#include <utility>

namespace reo::native::gameplay_scenario {
struct SceneControlDomain {};
SceneControls::SceneControls(std::size_t maximum):domain_(std::make_shared<SceneControlDomain>()),maximum_(maximum){}
SceneControls::~SceneControls(){clear();}
std::shared_ptr<SceneControls::Node> SceneControls::acquire(const SceneControlId& id)const noexcept{
    if(id.domain_!=domain_)return{};
    const auto found=records_.find(id.serial_);return found==records_.end()?nullptr:found->second.lock();
}
std::optional<SceneControlId> SceneControls::append(SceneControl value){
    if(clearing_||!next_serial_||records_.size()>=maximum_)return{};
    SceneControlId id;id.domain_=domain_;id.serial_=next_serial_;
    auto node=std::make_shared<Node>(Node{id,std::move(value),{}});
    records_.emplace(next_serial_,node);++next_serial_;
    if(tail_)tail_->next=node;else head_=node;
    tail_=node;return id;
}
std::optional<SceneControl> SceneControls::get(const SceneControlId& id)const noexcept{
    const auto node=acquire(id);if(!node)return{};
    return node->value;
}
ControlStatus SceneControls::replace(const SceneControlId& id,SceneControl value)noexcept{
    const auto node=acquire(id);if(!node)return ControlStatus::invalid_identity;
    node->value=std::move(value);return ControlStatus::completed;
}
ControlStatus SceneControls::erase(const SceneControlId& id)noexcept{
    const auto node=acquire(id);if(!node)return ControlStatus::invalid_identity;
    if(head_==node)head_=node->next;
    else{auto previous=head_;while(previous&&previous->next!=node)previous=previous->next;
        if(!previous)return ControlStatus::invalid_identity;
        previous->next=node->next;
        if(tail_==node)tail_=previous;
    }
    if(tail_==node)tail_=head_;
    records_.erase(id.serial_);return ControlStatus::completed;
}
void SceneControls::clear()noexcept{
    if(clearing_)return;
    clearing_=true;records_.clear();tail_.reset();
    auto current=std::move(head_);
    while(current){auto next=std::move(current->next);current.reset();current=std::move(next);}
    clearing_=false;
}
ControlResult SceneControls::apply(ControlCommand command,const ControlArguments& a,ControlEffects* effects,std::size_t maximum_visits)noexcept{
    ControlResult result;if(clearing_){result.status=ControlStatus::closed;return result;}
    if(!enabled_)return result;
    const bool reset=command==ControlCommand::restart_five||command==ControlCommand::reset_five||command==ControlCommand::restart_five_byte;
    // Missing dependencies refuse before any record in this operation mutates.
    if(!effects&&(reset||command==ControlCommand::refresh_zero_two)){
        for(auto node=head_;node;node=node->next)if(node->value.authored_id==a.authored_id){
            const auto& body=node->value.body;
            if((reset&&std::holds_alternative<ControlTypeFive>(body))||
               (command==ControlCommand::refresh_zero_two&&(std::holds_alternative<ControlTypeZero>(body)||
                (std::holds_alternative<ControlTypeTwo>(body)&&std::get<ControlTypeTwo>(body).selector!=0)))){
                result.status=ControlStatus::provider_unavailable;return result;
            }
        }
    }
    for(auto node=head_;node;node=node->next){
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
                effects->reset(*this,node->id);auto* five=std::get_if<ControlTypeFive>(&node->value.body);
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
