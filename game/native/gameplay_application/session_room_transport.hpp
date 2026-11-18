#pragma once
#include "native_session.hpp"
#include <array>
#include <variant>

namespace reo::native::gameplay_application {
enum class RoomTransportStatus {completed,unavailable,busy,closed,full};
struct RoomTransportStep {
    RoomTransportStatus status{RoomTransportStatus::completed};
    unsigned snapshots{},requests{},published{},scene_messages{};
};
// The offline channel7 and channel5 owner/scene-record message owner. Its queues
// correspond to810880's normal/priority queues. Other payload families retain
// their explicit missing consumer;
// this is not an implementation of the complete offline/network scheduler.
class SessionRoomTransport final:public gameplay_update::GameplayMessageSink {
public:
    explicit SessionRoomTransport(NativeSession&);
    ~SessionRoomTransport();
    SessionRoomTransport(const SessionRoomTransport&)=delete;
    SessionRoomTransport& operator=(const SessionRoomTransport&)=delete;
    RoomTransportStatus initialize()noexcept;
    // Actual810550 activation facts, from the live application's display clock.
    // Repeated frontend/startup calls must not reset these established facts.
    RoomTransportStatus activate(std::uint32_t display_tick)noexcept;
    RoomTransportStep pump()noexcept;
    RoomTransportStatus close()noexcept;
    bool active()const noexcept{return active_;}
    std::optional<std::uint32_t> activation_tick()const noexcept{return activation_tick_;}
    unsigned pending_requests()const noexcept{return requests_.count;}
    unsigned pending_snapshots()const noexcept{return snapshots_.count;}
    unsigned pending_scene_messages()const noexcept{return scene_messages_.count;}
    std::uint32_t frame_counter()const noexcept{return frame_counter_;}
    bool begin_room_claim(const gameplay_update::RoomClaimBeginMessage&)noexcept override;
    bool send(const gameplay_update::RoomClaimReleaseMessage&)noexcept override;
    bool send(const gameplay_update::RoomMembershipMessage&)noexcept override;
    std::optional<std::uint32_t> room_owner(gameplay_update::MessageRoute,std::uint16_t)noexcept override;
    using GameplayMessageSink::send;
    bool send(const gameplay_update::ScenarioOwnerMessage&)noexcept override;
    bool send(const gameplay_update::SceneRecordParameterMessage&)noexcept override;
    bool scene_record_parameters_ready()const noexcept override;
    bool send(const gameplay_update::ResourceOperationMessage&)noexcept override{return false;}
    bool send(const gameplay_update::ResourcePositionMessage&)noexcept override{return false;}
    bool send(const gameplay_update::ActorStatusMessage&)noexcept override{return false;}
private:
    using Request=std::variant<gameplay_update::RoomClaimBeginMessage,gameplay_update::RoomClaimReleaseMessage>;
    template<class T>struct Queue {
        // The owned o9 buffers are0x1000 bytes with0x100-byte entries. Refuse
        // overflow instead of reproducing writes into a neighboring buffer.
        std::array<std::optional<T>,16> entries;
        unsigned head{},count{};
        bool push(T value)noexcept{
            if(count==entries.size())return false;
            entries[(head+count)%entries.size()]=std::move(value);++count;return true;
        }
        T pop()noexcept{
            auto result=std::move(*entries[head]);entries[head].reset();
            head=(head+1)%entries.size();--count;return result;
        }
        void clear()noexcept{for(auto& entry:entries)entry.reset();head=count=0;}
    };
    NativeSession& session_;
    Queue<Request> requests_;
    Queue<gameplay_update::RoomMembershipMessage> snapshots_;
    using SceneValue=std::variant<gameplay_update::ScenarioOwnerMessage,gameplay_update::SceneRecordParameterMessage>;
    struct SceneMessage {SceneValue value;std::uint8_t sender{};};
    Queue<SceneMessage> scene_messages_;
    std::optional<std::uint32_t> activation_tick_;
    std::uint32_t frame_counter_{},sent_bytes_{};
    bool initialized_{},active_{},running_{},closed_{};
    bool ready(gameplay_update::MessageRoute)const noexcept;
    bool send_scene(SceneValue,gameplay_update::MessageRoute,unsigned length)noexcept;
};
}
