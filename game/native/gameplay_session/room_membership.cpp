#include "room_membership.hpp"
#include <algorithm>

namespace reo::native::gameplay_session {
namespace {
void remove_at(RoomMembers& row,unsigned index)noexcept{
    for(;index<3;++index)row[index]=row[index+1];
    row[3]=0xff;
}
}
bool RoomMembership::initialize(std::uint8_t mode)noexcept{
    if(mode>1)return false;
    constexpr RoomMembers empty{0xff,0xff,0xff,0xff};
    authority_.fill(empty);published_.fill(empty);received_.fill(empty);
    mode_=mode;return true;
}
bool RoomMembership::begin_update()noexcept{
    if(!mode_)return false;
    authority_=published_;return true; //o9:8104C0..4D4; o8 uses its own equal-sized tables.
}
RoomMembershipStatus RoomMembership::claim(std::uint8_t actor,std::uint16_t room,
    std::optional<std::int8_t> authority)noexcept{
    if(!mode_)return RoomMembershipStatus::unavailable;
    // Complete receive branches o9:811970 and o8:811140. The offline helper
    // admits actor zero only; both helpers gate before touching their tables.
    if(actor>=4||(*mode_==0&&actor!=0))return RoomMembershipStatus::completed;
    if(!authority)return RoomMembershipStatus::unavailable;
    if(!*authority)return RoomMembershipStatus::completed;
    if(room>=authority_.size())return RoomMembershipStatus::unavailable;
    auto& destination=authority_[room];
    if(std::find(destination.begin(),destination.end(),actor)!=destination.end())
        return RoomMembershipStatus::completed;
    const auto free=std::find(destination.begin(),destination.end(),0xff);
    if(free!=destination.end())*free=actor;
    // A full destination still removes prior claims. Preserve the byte scan
    // and first-match compaction, including its behavior on duplicate entries.
    for(unsigned byte=0;byte<512;++byte){
        const auto index=byte/4;
        if(index==room||authority_[index][byte%4]!=actor)continue;
        auto& row=authority_[index];
        const auto match=std::find(row.begin(),row.end(),actor);
        if(match!=row.end())remove_at(row,unsigned(match-row.begin()));
    }
    return RoomMembershipStatus::completed;
}
RoomMembershipStatus RoomMembership::release(std::uint8_t actor,std::uint16_t room,
    std::optional<std::int8_t> authority)noexcept{
    if(!mode_)return RoomMembershipStatus::unavailable;
    if(actor>=4||(*mode_==0&&actor!=0))return RoomMembershipStatus::completed;
    if(!authority)return RoomMembershipStatus::unavailable;
    if(!*authority)return RoomMembershipStatus::completed;
    if(room>=authority_.size())return RoomMembershipStatus::unavailable;
    auto& row=authority_[room];
    for(unsigned index=0;index<4;++index)if(row[index]==actor)remove_at(row,index);
    return RoomMembershipStatus::completed; //o9:811B30; o8:811300
}
RoomMembershipChanges RoomMembership::collect(std::optional<std::int8_t> authority,
    std::uint8_t sender)noexcept{
    if(!authority)return{RoomMembershipStatus::unavailable,{}};
    if(!*authority)return{};
    if(!mode_)return{RoomMembershipStatus::unavailable,{}};
    RoomMembershipUpdate update;update.sender=sender;
    unsigned changed{};
    for(unsigned room=0;room<authority_.size();++room){
        if(published_[room]==authority_[room])continue;
        if(changed<update.rows.size())update.rows[changed]={std::uint8_t(room),authority_[room]};
        ++changed;published_[room]=authority_[room];
    }
    // The original commits every comparison row before its count>8 failure
    // loop. Retain those commits and explicitly refuse that unsupported path.
    if(changed>update.rows.size())return{RoomMembershipStatus::too_many_changes,{}};
    if(!changed)return{};
    update.count=std::uint8_t(changed);return{RoomMembershipStatus::completed,update};
}
RoomMembershipStatus RoomMembership::receive(std::span<const RoomMembershipRow> rows)noexcept{
    if(!mode_)return RoomMembershipStatus::unavailable;
    for(const auto& row:rows){
        if(row.room>=received_.size())return RoomMembershipStatus::unavailable;
        received_[row.room]=row.members;
    }
    return RoomMembershipStatus::completed; //o9:8118F0; o8:8110C0
}
std::optional<bool> RoomMembership::first(std::uint16_t room,std::uint8_t actor)const noexcept{
    if(actor>=4||room>=received_.size())return false;
    if(!mode_)return{};
    return received_[room][0]==actor;
}
std::optional<bool> RoomMembership::contains(std::uint16_t room,std::uint8_t actor)const noexcept{
    if(actor>=4||room>=received_.size())return false;
    if(!mode_)return{};
    const auto& row=received_[room];return std::find(row.begin(),row.end(),actor)!=row.end();
}
std::optional<std::int32_t> RoomMembership::owner(std::uint16_t room)const noexcept{
    if(room>=received_.size())return -1;
    if(!mode_)return{};
    const auto actor=received_[room][0];return actor==0xff?-1:std::int32_t(actor);
}
}
