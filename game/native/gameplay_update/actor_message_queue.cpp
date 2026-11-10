#include "actor_message_queue.hpp"
#include <stdexcept>
namespace reo::native::gameplay_update {
ActorMessageQueue::ActorMessageQueue(ActorReception& receiver,std::size_t capacity):receiver_(receiver),slots_(capacity){if(!capacity)throw std::invalid_argument("Native actor message queue requires positive capacity");}
bool ActorMessageQueue::send(const ActorStatusMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorAlignmentMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorInteractionMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorInteractionRequestMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorInventoryMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorResourcePairMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorRoomObjectMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorPeerMessage& value)noexcept{return enqueue(value);}
bool ActorMessageQueue::send(const ActorSpeechMessage& value)noexcept{return enqueue(value);}
ActorQueueStatus ActorMessageQueue::close()noexcept{
    if(draining_)return ActorQueueStatus::busy;
    closed_=true;for(auto& slot:slots_)slot.reset();head_=count_=0;return ActorQueueStatus::completed;
}
ActorQueueDrain ActorMessageQueue::drain(std::size_t budget,bool local_echo)noexcept{
    if(closed_)return{ActorQueueStatus::closed,0,count_};
    if(draining_)return{ActorQueueStatus::busy,0,count_};
    draining_=true;std::size_t consumed{};
    while(count_&&consumed<budget){
        const auto value=std::move(*slots_[head_]);slots_[head_].reset();head_=(head_+1)%slots_.size();--count_;++consumed;
        // Consume before invoking state owners. A failed application can have
        // a retained mutation prefix and must never be silently replayed.
        const auto applied=std::visit([&](const auto& message){return receiver_.receive(message,local_echo);},value);
        if(applied.status!=ReceptionStatus::completed){draining_=false;return{ActorQueueStatus::unavailable,consumed,count_};}
    }
    draining_=false;return{ActorQueueStatus::completed,consumed,count_};
}
}
