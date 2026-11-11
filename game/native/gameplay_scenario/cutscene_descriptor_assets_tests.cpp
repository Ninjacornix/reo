#include "cutscene_descriptor.hpp"
#include "scenario_archive.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <cstring>
namespace s=reo::native::gameplay_scenario;
namespace {
std::uint64_t checks{},loaded{},legacy{},groups{},streams{},large{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Descriptor asset check "+std::to_string(at.line()));
}
void contracts(){
    std::vector<std::byte> raw(76);std::memcpy(raw.data(),"0950",4);
    const auto descriptor=s::CutsceneDescriptor::import(raw);
    check(descriptor->consumed_bytes()==76&&descriptor->tail_kind()==s::CutsceneTail::complete&&descriptor->trailing_data().empty());
    check(descriptor->actor_groups().empty()&&descriptor->actor_tracks({}).empty()&&descriptor->extension_groups()->empty());
    raw.resize(60);check(s::CutsceneDescriptor::import(raw)->tail_kind()==s::CutsceneTail::caller_terminal);
    raw.resize(64);const std::uint32_t terminal=0xffffffff;std::memcpy(raw.data()+60,&terminal,4);
    check(s::CutsceneDescriptor::import(raw)->tail_kind()==s::CutsceneTail::explicit_terminal);
    raw.resize(63);bool refused=false;try{(void)s::CutsceneDescriptor::import(raw);}catch(const std::invalid_argument&){refused=true;}check(refused);
}
void owned(const char* archive,const char* manifest){
    auto source=std::make_shared<reo::assets::Source>(archive);s::content::ScenarioArchive assets(source);
    std::ifstream rows(manifest);check(bool(rows));unsigned scenario{},sequence{},variant{},suffix{},version{};std::uint64_t offset{};std::uint32_t length{};
    while(rows>>scenario>>sequence>>variant>>suffix>>offset>>length>>version){
        try{
        std::vector<std::byte> expected(length);source->read(offset,length,expected.data());
        if(version!=950){bool refused=false;try{(void)s::read_cutscene_descriptor(assets,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));}catch(const std::invalid_argument&){refused=true;}check(refused);++legacy;continue;}
        const auto descriptor=s::read_cutscene_descriptor(assets,std::uint16_t(scenario),std::uint8_t(sequence),std::uint8_t(variant),std::uint8_t(suffix));check(bool(descriptor));
        for(unsigned word=0;word<10;++word){std::uint32_t value;std::memcpy(&value,expected.data()+4*word,4);check(value==descriptor->header_word(word));}
        const auto section=[&](s::CutsceneSection value){const auto raw=descriptor->section(value);check(value.offset<=expected.size()&&raw.size()<=expected.size()-value.offset);check(std::memcmp(raw.data(),expected.data()+value.offset,raw.size())==0);};
        section(descriptor->camera_selection());section(descriptor->events());section(descriptor->general());section(descriptor->secondary());
        const auto sections=[&](const auto& values){for(const auto& group:values)for(auto value:group)section(value);};
        sections(descriptor->camera_streams());sections(descriptor->actor_groups());sections(descriptor->object_groups());
        check(descriptor->tail_kind()==s::CutsceneTail::complete);sections(*descriptor->extension_groups());section(*descriptor->tail_first());section(*descriptor->tail_second());section(*descriptor->tail_last());
        const auto trailing=descriptor->trailing_data();check(std::memcmp(trailing.data(),expected.data()+descriptor->consumed_bytes(),trailing.size())==0);
        const auto tracks=descriptor->actor_tracks(std::vector<s::CutsceneActorBinding>(descriptor->actor_groups().size()));
        for(unsigned group=0;group<tracks.size();++group)for(unsigned stream=0;stream<7;++stream){const auto raw=descriptor->section(descriptor->actor_groups()[group][stream]);check(tracks[group].streams[stream]->size()==raw.size()/36);for(unsigned row=0;row<raw.size()/36;++row)check(std::memcmp(tracks[group].streams[stream]->record(row).data(),raw.data()+36*row,36)==0);++streams;}
        groups+=tracks.size();large+=tracks.size()>16;++loaded;
        }catch(const std::exception& error){throw std::runtime_error("Scenario "+std::to_string(scenario)+" dm "+std::to_string(sequence)+"/"+std::to_string(variant)+"/"+std::to_string(suffix)+" version "+std::to_string(version)+": "+error.what());}
    }
    check(rows.eof()&&loaded==548&&legacy==142&&large==17&&groups==1469&&streams==10283);
    check(!s::read_cutscene_descriptor(assets,999,0,0,0)&&!s::read_cutscene_descriptor(assets,1,99,98,25)&&!s::read_cutscene_descriptor(assets,1,0,0,26));
}
}
int main(int argc,char** argv)try{
    contracts();if(argc==3)owned(argv[1],argv[2]);else check(argc==1);
    std::cout<<"{\"checks\":"<<checks<<",\"loaded\":"<<loaded<<",\"legacy_refused\":"<<legacy<<",\"actor_groups\":"<<groups<<",\"actor_streams\":"<<streams<<",\"large_scenes\":"<<large<<",\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
