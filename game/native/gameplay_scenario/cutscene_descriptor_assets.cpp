#include "cutscene_descriptor.hpp"
#include "scenario_archive.hpp"
#include <cstdio>
namespace reo::native::gameplay_scenario {
std::shared_ptr<const CutsceneDescriptor> read_cutscene_descriptor(const content::ScenarioArchive& archive,
    std::uint16_t scenario,std::uint8_t sequence,std::uint8_t variant,std::uint8_t suffix){
    if(suffix>25)return{};
    std::array<char,24> name{};
    std::snprintf(name.data(),name.size(),"dm%02u%02u%c.bin",unsigned(sequence),unsigned(variant),int('a'+suffix));
    const auto bytes=archive.read_member(scenario,name.data());
    return bytes?CutsceneDescriptor::import(*bytes):nullptr;
}
}
