#include "game/native/gameplay_scenario/cutscene_descriptor.hpp"
std::uint64_t cutscene_descriptors{},cutscene_descriptor_sections{},cutscene_descriptor_streams{},cutscene_descriptor_refusals{},cutscene_descriptor_partial{},cutscene_parameter_groups{},cutscene_parameters{};
void descriptor_equal(const std::vector<std::byte>& bytes,std::vector<std::uint8_t>& ram){
    constexpr std::uint32_t base=0x1000000;
    check(bytes.size()+4<0x1000000,"descriptor fits independent original arena");
    std::memset(ram.data()+0x38ec00,0xa5,0x1700);
    put(ram.data(),0x743520,0xa5a5a5a5u);put(ram.data(),0x743528,0xa5a5a5a5u);
    std::memcpy(ram.data()+base,bytes.data(),bytes.size());put(ram.data(),base+unsigned(bytes.size()),0xffffffffu);
    const auto original=call(ram.data(),0x5f15a0,base);
    const auto descriptor=cue::CutsceneDescriptor::import(bytes);const auto& d=*descriptor;
    for(unsigned i=0;i<3;++i)check(d.identity()[i]==ram[0x38ecc8+i],"original descriptor identity bytes");
    check(d.duration()==get<std::uint32_t>(ram.data(),0x38ecb0),"original duration");
    const auto section=[&](cue::CutsceneSection value,unsigned pointer){
        check(get<std::uint32_t>(ram.data(),pointer)==base+value.offset,"original section pointer "+std::to_string(pointer));
        const auto native=d.section(value);
        check(native.size()==std::size_t(value.count)*value.stride&&std::memcmp(native.data(),ram.data()+base+value.offset,native.size())==0,"retained original section bytes");
        ++cutscene_descriptor_sections;
    };
    const auto groups=[&](const auto& values,unsigned pointer){
        for(unsigned group=0;group<values.size();++group)
            for(unsigned stream=0;stream<values[group].size();++stream)
                section(values[group][stream],pointer+4*unsigned(values[group].size())*group+4*stream);
    };
    check(d.camera_selection().count==get<std::uint16_t>(ram.data(),0x38ecb4),"camera selection count");section(d.camera_selection(),0x3901a8);groups(d.camera_streams(),0x3900a0);
    section(d.events(),0x3901d0);section(d.general(),0x3901c8);
    check(std::uint8_t(d.general().count)==ram[0x38ecce],"narrowed original general count");
    check(d.actor_groups().size()==get<std::uint16_t>(ram.data(),0x38ecb6),"original actor group count");groups(d.actor_groups(),0x38fb60);
    const auto actor_start=d.general().offset+d.general().count*36+4;
    check(get<std::uint32_t>(ram.data(),0x38ff80)==base+actor_start,"actor table start");
    const auto object_start=d.actor_groups().empty()?actor_start+4:d.actor_groups().back().back().offset+d.actor_groups().back().back().count*36+4;
    check(get<std::uint32_t>(ram.data(),0x38fb50)==base+object_start,"object table start");
    check(d.object_groups().size()==get<std::uint16_t>(ram.data(),0x38ecb8),"original object group count");groups(d.object_groups(),0x38f7b0);
    section(d.secondary(),0x3901c0);check(d.secondary().count==get<std::uint16_t>(ram.data(),0x38ecba),"secondary count");
    if(d.tail_kind()==cue::CutsceneTail::complete){
        check(d.extension_groups().has_value(),"complete extension known");groups(*d.extension_groups(),0x38ff90);
        check(d.extension_groups()->size()==get<std::uint16_t>(ram.data(),0x38ecbc),"extension group count");
        check(get<std::uint32_t>(ram.data(),0x390098)==base+d.secondary().offset+d.secondary().count*40+4,"extension table start");
        section(*d.tail_first(),0x3901b8);section(*d.tail_second(),0x3901b0);section(*d.tail_last(),0x743528);
        check(d.tail_first()->count==get<std::uint16_t>(ram.data(),0x38ecbe)&&d.tail_second()->count==get<std::uint16_t>(ram.data(),0x38ecc2)&&d.tail_last()->count==get<std::uint16_t>(ram.data(),0x38ecc0),"tail counts");
        check(get<std::uint32_t>(ram.data(),0x743520)==base+d.consumed_bytes()&&GPR_U32(&original,2)==0,"complete original parser end and return");
    }else{
        check(!d.extension_groups()&&!d.tail_first()&&!d.tail_second()&&!d.tail_last(),"terminal absence retains unknown views");
        check(get<std::uint16_t>(ram.data(),0x38ecbc)==0&&get<std::uint16_t>(ram.data(),0x38ecbe)==0&&get<std::uint32_t>(ram.data(),0x390098)==0&&get<std::uint32_t>(ram.data(),0x3901b8)==0,"original early terminal clears only first views");
        check(get<std::uint16_t>(ram.data(),0x38ecc2)==0xa5a5&&get<std::uint16_t>(ram.data(),0x38ecc0)==0xa5a5&&get<std::uint32_t>(ram.data(),0x3901b0)==0xa5a5a5a5&&get<std::uint32_t>(ram.data(),0x743528)==0xa5a5a5a5&&get<std::uint32_t>(ram.data(),0x743520)==0xa5a5a5a5,"early terminal does not invent cleared later views");
        check(GPR_U32(&original,2)==1,"original terminal return");++cutscene_descriptor_partial;
    }
    check(GPR_U32(&original,4)==base+d.consumed_bytes()+(d.tail_kind()==cue::CutsceneTail::caller_terminal?4:0),"original physical/caller-appended consumed offset");
    check(d.trailing_data().size()==bytes.size()-d.consumed_bytes(),"unknown retained trailer extent");
    std::vector<cue::CutsceneActorBinding> bindings(d.actor_groups().size());
    const auto tracks=d.actor_tracks(bindings);check(tracks.size()==bindings.size(),"descriptor prepares all native actor groups");
    for(unsigned group=0;group<tracks.size();++group)for(unsigned stream=0;stream<7;++stream){
        const auto raw=d.section(d.actor_groups()[group][stream]);
        check(tracks[group].streams[stream]&&tracks[group].streams[stream]->size()==raw.size()/36,"actual empty versus retained stream");++cutscene_descriptor_streams;
    }
    for(unsigned group=0;group<d.actor_groups().size();++group){
        // Each data reducer is compared at original slot0, avoiding unrelated
        // output-array aliases when an asset declares more than16 actors.
        put(ram.data(),0x38fb60+12,base+d.actor_groups()[group][3].offset);
        call(ram.data(),0x5f0b50,0);const auto parameters=d.actor_parameters(group);
        check(parameters.size()==get<std::uint32_t>(ram.data(),0x38ede0),"original actor parameter count");
        for(unsigned index=0;index<parameters.size();++index){check(parameters[index].key==get<std::int32_t>(ram.data(),0x38ede4+4*index)&&parameters[index].value==get<std::uint32_t>(ram.data(),0x38ee24+4*index),"original signed key and parameter value");++cutscene_parameters;}
        ++cutscene_parameter_groups;
    }
    ++cutscene_descriptors;
}
void cutscene_descriptor_tests(const char* path,std::vector<std::uint8_t>& ram){
    const auto assets=load(path);check(assets.size()==548,"all pinned owned0950 assets");
    for(unsigned i=0;i<assets.size();++i){location="descriptor="+std::to_string(i);descriptor_equal(assets[i],ram);}
    const auto descriptor=cue::CutsceneDescriptor::import(assets[0]);
    auto partial=assets[0];const auto end=descriptor->secondary().offset+40*descriptor->secondary().count;
    partial.resize(end);descriptor_equal(partial,ram);partial.resize(end+4);const auto terminal=0xffffffffu;std::memcpy(partial.data()+end,&terminal,4);descriptor_equal(partial,ram);
    const auto refused=[&](const auto& action){bool bad=false;try{action();}catch(const std::invalid_argument&){bad=true;}catch(const std::out_of_range&){bad=true;}check(bad,"malformed descriptor visibly refused");++cutscene_descriptor_refusals;};
    for(unsigned size=0;size<40;++size)refused([&]{(void)cue::CutsceneDescriptor::import(std::span(assets[0]).first(size));});
    for(const char* version:{"0930","0940","XXXX"}){auto raw=assets[0];std::memcpy(raw.data(),version,4);refused([&]{(void)cue::CutsceneDescriptor::import(raw);});}
    for(const auto value:{34u,0xffffffffu}){auto raw=assets[0];std::memcpy(raw.data()+36,&value,4);refused([&]{(void)cue::CutsceneDescriptor::import(raw);});}
    for(const auto offset:{descriptor->general().offset-4,descriptor->secondary().offset-4}){auto raw=assets[0];std::memcpy(raw.data()+offset,&terminal,4);refused([&]{(void)cue::CutsceneDescriptor::import(raw);});}
    refused([&]{(void)descriptor->section({std::uint32_t(assets[0].size()),1,36});});
    refused([&]{(void)descriptor->header_word(10);});
    refused([&]{(void)descriptor->actor_tracks(std::vector<cue::CutsceneActorBinding>(descriptor->actor_groups().size()+1));});
    auto changed=assets[0];const auto retained=cue::CutsceneDescriptor::import(changed);std::fill(changed.begin(),changed.end(),std::byte{0});
    check(retained->header_word(0)==0x30353930u,"descriptor owns immutable input independently");
}
