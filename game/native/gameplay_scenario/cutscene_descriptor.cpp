#include "cutscene_descriptor.hpp"
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_scenario {
namespace {
std::uint32_t word(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||4>bytes.size()-at)throw std::invalid_argument("Native0950 descriptor word outside asset");
    std::uint32_t value;std::memcpy(&value,bytes.data()+at,4);return value;
}
class Reader final {
public:
    explicit Reader(std::span<const std::byte> bytes):bytes_(bytes){}
    std::size_t position{40};
    std::uint32_t take(){const auto value=word(bytes_,position);position+=4;return value;}
    CutsceneSection fixed(std::uint32_t count,std::uint16_t stride){
        if(position>bytes_.size()||count>(bytes_.size()-position)/stride)
            throw std::invalid_argument("Native0950 descriptor section outside asset");
        const CutsceneSection result{std::uint32_t(position),count,stride};position+=std::size_t(count)*stride;return result;
    }
    CutsceneSection counted(std::uint16_t stride){const auto count=take();return fixed(count,stride);}
    template<std::size_t N>std::vector<std::array<CutsceneSection,N>> groups(std::uint32_t count,std::uint16_t stride){
        if(count>CutsceneDescriptor::maximum_groups)throw std::out_of_range("Native0950 descriptor group profile exceeded");
        std::vector<std::array<CutsceneSection,N>> result(count);
        for(auto& group:result)for(auto& section:group)section=counted(stride);
        return result;
    }
private:std::span<const std::byte> bytes_;
};
}
std::shared_ptr<const CutsceneDescriptor> CutsceneDescriptor::import(std::span<const std::byte> bytes){
    if(bytes.size()<40||bytes.size()>maximum_bytes||std::memcmp(bytes.data(),"0950",4))
        throw std::invalid_argument("Native cutscene descriptor version/extent unadmitted");
    auto result=std::shared_ptr<CutsceneDescriptor>(new CutsceneDescriptor);
    result->bytes_.assign(bytes.begin(),bytes.end());bytes=result->bytes_;Reader reader(bytes);
    for(unsigned index=0;index<3;++index)result->identity_[index]=std::uint8_t(word(bytes,4+4*index));
    result->duration_=word(bytes,32);const auto cameras=word(bytes,36);
    if(cameras>maximum_groups+1)throw std::out_of_range("Native0950 camera group profile exceeded");
    result->camera_selection_=reader.fixed(cameras,16);
    result->camera_streams_=reader.groups<2>(cameras?cameras-1:0,56);
    result->events_=reader.counted(24);result->general_=reader.counted(36);
    result->actors_=reader.groups<8>(reader.take(),36);result->objects_=reader.groups<7>(reader.take(),36);
    result->secondary_=reader.counted(40);
    if(reader.position==bytes.size())result->tail_=CutsceneTail::caller_terminal;
    else{
        const auto count=reader.take();
        if(count==0xffffffffu)result->tail_=CutsceneTail::explicit_terminal;
        else{
            result->extension_=reader.groups<2>(count,48);
            result->tail_first_=reader.counted(40);result->tail_second_=reader.counted(40);result->tail_last_=reader.counted(16);
        }
    }
    result->consumed_=reader.position;return result;
}
std::span<const std::byte> CutsceneDescriptor::section(CutsceneSection value)const{
    if(!value.stride||value.offset>bytes_.size()||value.count>(bytes_.size()-value.offset)/value.stride)
        throw std::out_of_range("Native0950 section outside retained descriptor");
    return std::span(bytes_).subspan(value.offset,std::size_t(value.count)*value.stride);
}
std::uint32_t CutsceneDescriptor::header_word(std::size_t index)const{
    if(index>=10)throw std::out_of_range("Native0950 header word outside header");
    return word(bytes_,4*index);
}
std::vector<CutsceneActorTrackGroup> CutsceneDescriptor::actor_tracks(std::span<const CutsceneActorBinding> bindings)const{
    if(bindings.size()!=actors_.size())throw std::invalid_argument("Native0950 actor bindings do not match descriptor groups");
    std::vector<CutsceneActorTrackGroup> result;result.reserve(bindings.size());
    for(std::size_t index=0;index<bindings.size();++index){
        CutsceneActorTrackGroup group;group.kind=bindings[index].kind;group.actor=bindings[index].actor;
        for(unsigned stream=0;stream<7;++stream)group.streams[stream]=CutsceneActorStream::import(section(actors_[index][stream]));
        result.push_back(std::move(group));
    }
    return result;
}
std::vector<CutsceneActorParameter> CutsceneDescriptor::actor_parameters(std::size_t group)const{
    const auto value=actors_.at(group)[3];const auto bytes=section(value);std::vector<CutsceneActorParameter> result;
    for(unsigned index=0;index<15;++index){
        if(index>=value.count)throw std::invalid_argument("Native cutscene actor parameters lack bounded terminal");
        std::uint16_t frame;std::memcpy(&frame,bytes.data()+36*index+2,2);if(frame==65535)return result;
        CutsceneActorParameter parameter;std::memcpy(&parameter.key,bytes.data()+36*index+6,2);parameter.value=word(bytes,36*index+8);result.push_back(parameter);
    }
    return result;
}
}
