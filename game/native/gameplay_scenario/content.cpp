#include "content.hpp"
#include <limits>
#include <stdexcept>
#include <utility>

namespace reo::native::gameplay_scenario::content {
namespace {
std::uint32_t word(const std::byte* p)noexcept{
    return std::to_integer<std::uint32_t>(p[0])|(std::to_integer<std::uint32_t>(p[1])<<8)|
        (std::to_integer<std::uint32_t>(p[2])<<16)|(std::to_integer<std::uint32_t>(p[3])<<24);
}
void bounded(const Bytes& bytes,std::size_t header){
    if(!bytes||bytes->size()<header||bytes->size()>std::numeric_limits<std::uint32_t>::max())throw std::invalid_argument("Native content extent");
}
}
RdtDirectory::RdtDirectory(Bytes bytes):bytes_(std::move(bytes)){
    bounded(bytes_,256);
    for(std::size_t i=0;i<sections_.size();++i){const auto* p=bytes_->data()+8*i;auto& s=sections_[i];s={word(p),word(p+4)};
        if(s.bytes&&(s.offset>bytes_->size()||s.bytes>bytes_->size()-s.offset))throw std::invalid_argument("RDT section outside owned file");
    }
}
std::optional<Range> RdtDirectory::range(std::size_t index)const noexcept{
    if(index>=sections_.size()||!sections_[index].bytes)return{};
    return sections_[index];
}
std::optional<std::span<const std::byte>> RdtDirectory::section(std::size_t index)const noexcept{
    const auto r=range(index);if(!r)return{};
    return std::span<const std::byte>(*bytes_).subspan(r->offset,r->bytes);
}
ScriptBank::ScriptBank(Bytes bytes,BankFormat format):bytes_(std::move(bytes)),format_(format),count_(format==BankFormat::scenario_evb?32:16){
    bounded(bytes_,count_*4);
    for(std::size_t i=0;i<count_;++i){offsets_[i]=word(bytes_->data()+4*i);
        if(offsets_[i]&&(offsets_[i]<4*count_||offsets_[i]>bytes_->size()))throw std::invalid_argument("Script table reference outside owned bank");
    }
}
std::optional<ObjectBound> ScriptBank::object(std::size_t index)const noexcept{
    if(index>=count_||!offsets_[index])return{};
    const auto start=offsets_[index];auto end=std::uint32_t(bytes_->size());
    for(std::size_t i=0;i<count_;++i)if(offsets_[i]>start&&offsets_[i]<end)end=offsets_[i];
    ObjectRole role=ObjectRole::unknown;
    if(format_==BankFormat::room_section){if(index>=8)role=ObjectRole::executable_candidate;}
    else if(index<8)role=ObjectRole::executable_candidate;
    else if(index<16)role=ObjectRole::configuration_data;
    else if(index<24)role=ObjectRole::indirect_references;
    return ObjectBound{std::uint8_t(index),role,{start,end-start}};
}
std::vector<ObjectBound> ScriptBank::executable_candidates()const{
    std::vector<ObjectBound> result;
    for(std::size_t i=0;i<count_;++i)if(const auto found=object(i);found&&found->role==ObjectRole::executable_candidate)result.push_back(*found);
    return result;
}
std::optional<std::vector<std::uint32_t>> ScriptBank::indirect_references(std::size_t index)const{
    const auto found=object(index);if(!found)return{};
    if(found->role!=ObjectRole::indirect_references)throw std::invalid_argument("Not a declared indirect-reference table");
    const auto data=view(*found);std::vector<std::uint32_t> result;
    for(std::size_t at=0;at+4<=data.size();at+=4){const auto offset=word(data.data()+at);if(!offset)return result;
        if(offset<4*count_||offset>bytes_->size())throw std::invalid_argument("Indirect script reference outside owned bank");
        result.push_back(offset);
    }
    throw std::invalid_argument("Unterminated bounded script reference table");
}
std::span<const std::byte> ScriptBank::view(const ObjectBound& bound)const{
    if(bound.bound.offset>bytes_->size()||bound.bound.bytes>bytes_->size()-bound.bound.offset)throw std::invalid_argument("Unowned script object range");
    return std::span<const std::byte>(*bytes_).subspan(bound.bound.offset,bound.bound.bytes);
}
std::optional<gameplay_collision::delivery::RoomCounterPolicy::ScenarioRows>
import_room_counter_rows(const ScriptBank& bank) {
    if (bank.format() != BankFormat::scenario_evb)
        throw std::invalid_argument("Room counter policy requires a scenario EVB");
    const auto object = bank.object(13);
    if (!object) return {};
    const auto bytes = bank.view(*object);
    gameplay_collision::delivery::RoomCounterPolicy::ScenarioRows rows;
    if (bytes.size() < rows.size() * rows.front().size() * sizeof(std::uint32_t))
        throw std::invalid_argument("Truncated EVB room counter policy");
    std::size_t offset = 0;
    for (auto& row : rows) {
        for (auto& entry : row) {
            entry = word(bytes.data() + offset);
            offset += sizeof(entry);
        }
    }
    return rows;
}
} // namespace reo::native::gameplay_scenario::content
