#pragma once
#include "reception.hpp"
#include <variant>
namespace reo::native::gameplay_update {
enum class ActorQueueStatus {completed,closed,busy,unavailable};
struct ActorQueueDrain {ActorQueueStatus status{ActorQueueStatus::completed};std::size_t consumed{},pending{};};
// Bounded simulation-owner queue for the admitted native actor messages. It
// owns typed values, with no allocation on enqueue and no retained caller stack.
// Unsupported message families and missing room routing remain unavailable.
class ActorMessageQueue final:public GameplayMessageSink {
public:
    explicit ActorMessageQueue(ActorReception&,std::size_t capacity=64);
    using GameplayMessageSink::send;
    bool send(const ScenarioOwnerMessage&)noexcept override{return false;}
    bool send(const ResourceOperationMessage&)noexcept override{return false;}
    bool send(const ResourcePositionMessage&)noexcept override{return false;}
    bool send(const ActorStatusMessage&)noexcept override;
    bool send(const ActorAlignmentMessage&)noexcept override;
    bool send(const ActorInteractionMessage&)noexcept override;
    bool send(const ActorInventoryMessage&)noexcept override;
    bool send(const ActorResourcePairMessage&)noexcept override;
    bool send(const ActorRoomObjectMessage&)noexcept override;
    bool send(const ActorPeerMessage&)noexcept override;
    bool send(const ActorSpeechMessage&)noexcept override;
    ActorQueueDrain drain(std::size_t budget,bool local_echo=false)noexcept;
    ActorQueueStatus close()noexcept;
    std::size_t pending()const noexcept{return count_;}
    std::size_t capacity()const noexcept{return slots_.size();}
private:
    using Message=std::variant<ActorStatusMessage,ActorAlignmentMessage,ActorInteractionMessage,ActorInventoryMessage,ActorResourcePairMessage,ActorRoomObjectMessage,ActorPeerMessage,ActorSpeechMessage>;
    ActorReception& receiver_;
    std::vector<std::optional<Message>> slots_;
    std::size_t head_{},count_{};
    bool closed_{},draining_{};
    template<class T>bool enqueue(const T& value)noexcept{
        if(closed_||count_==slots_.size())return false;
        slots_[(head_+count_)%slots_.size()].emplace(value);++count_;return true;
    }
};
}
