#pragma once
#include "../gameplay_update/scenario_publication.hpp"

namespace reo::native::gameplay_scenario {
enum class SceneRecordParameterStatus {completed,unavailable};
struct SceneRecordParameterApplied {
    SceneRecordParameterStatus status{SceneRecordParameterStatus::unavailable};
    std::optional<std::uint8_t> ordinal{};
    bool notification_attempted{},notification_accepted{};
};
inline bool scene_record_parameter_notification_required(const gameplay_world::World& world)noexcept {
    const auto phase=world.session().message_phase;
    return (phase==1||phase==2)&&world.mode<=1;
}
inline bool scene_record_parameters_ready(const gameplay_world::World& world,
                                           const gameplay_update::GameplayMessageSink* messages)noexcept {
    return !world.closed()&&(!scene_record_parameter_notification_required(world)||
                            (messages&&messages->scene_record_parameters_ready()));
}
// Complete admitted5A8F40 +680FB0/1AFDD0 routing policy. Payload arguments
// narrow independently. Only the first matching row inside count() changes.
// A present transport's rejected send does not undo the local write or turn
// the original ignored result into a script failure; the result exposes it.
inline SceneRecordParameterApplied update_scene_record_parameter(
    gameplay_world::World& world,std::uint32_t condition,std::uint32_t parameter23,
    std::uint32_t value,gameplay_update::GameplayMessageSink* messages=nullptr)noexcept {
    if(!scene_record_parameters_ready(world,messages))return{};
    auto& descriptors=world.session().enemy_descriptors;
    for(std::uint32_t index=0;index<descriptors.count();++index){
        auto& record=*descriptors.record(index);
        if(record.condition!=std::uint8_t(condition)||record.parameter23!=std::uint8_t(parameter23))continue;
        record.parameter2e=std::uint8_t(value);
        SceneRecordParameterApplied result{SceneRecordParameterStatus::completed,std::uint8_t(index)};
        if(scene_record_parameter_notification_required(world)){
            result.notification_attempted=true;
            result.notification_accepted=messages->send(gameplay_update::SceneRecordParameterMessage{
                world.mode==0?gameplay_update::MessageRoute::mode_zero:gameplay_update::MessageRoute::mode_one,
                std::uint8_t(index),std::uint8_t(value)});
        }
        return result;
    }
    return{SceneRecordParameterStatus::completed};
}
}
