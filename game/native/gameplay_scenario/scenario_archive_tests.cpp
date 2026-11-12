#include "scenario_archive.hpp"
#include "script_program.hpp"
#include "../gameplay_update/update.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <iostream>
#include <source_location>
#include <sstream>
#include <stdexcept>
#include <algorithm>

namespace scenario=reo::native::gameplay_scenario;
namespace content=scenario::content;
namespace update=reo::native::gameplay_update;
namespace world=reo::native::gameplay_world;
namespace {
std::size_t checks{},loaded_members{},admitted_rooms{},refused_rooms{},npc_banks{},enemy_banks{},enemy_boundary_cases{};
void check(bool condition,std::source_location location=std::source_location::current()) {
    ++checks;
    if (!condition) throw std::runtime_error("Native archive check at "+std::to_string(location.line()));
}
struct Notifications final:scenario::FlagNotifications {
    bool changed(const scenario::ScenarioFlagChange&)noexcept override { std::terminate(); }
    bool changed(const scenario::StridedFlagChange&)noexcept override { std::terminate(); }
};
struct Memory final:reo::assets::PositionedSource {
    const std::vector<std::uint8_t> bytes;
    explicit Memory(std::vector<std::uint8_t> source):bytes(std::move(source)) {}
    std::uint64_t size()const noexcept override { return bytes.size(); }
    std::size_t read(std::uint64_t offset,std::size_t length,void* output)const override {
        if(offset>bytes.size()||length>bytes.size()-offset)throw std::runtime_error("Fixture extent");
        std::memcpy(output,bytes.data()+offset,length);
        return length;
    }
};
void enemy_boundaries() {
    std::vector<std::byte> bytes(16+96*258);
    const std::uint32_t start=16;
    std::memcpy(bytes.data(),&start,4);
    for(unsigned index=0;index<257;++index) {
        const auto base=16+96*index;
        bytes[base+2]=std::byte{1};
        bytes[base+0x33]=std::byte{8};
        bytes[base+0x49]=std::byte{1};
    }
    bytes[16+96*256+2]=std::byte{255};
    world::Session session;
    session.scenario=1;
    auto& descriptors=session.enemy_descriptors;
    const auto full=descriptors.import(bytes,session,false,0);
    check(full.status==scenario::EnemyImportStatus::completed&&full.count==256);
    check(descriptors.count()==0&&descriptors.room_counts()[0]==0);
    check(descriptors.record(255)->ordinal==255&&descriptors.record(255)->health==32767);
    ++enemy_boundary_cases;
    const auto random=session.random.state();
    descriptors.record(0)->variant=0xfe;
    descriptors.assignments().counts={17,19};
    bytes[16+96*256+2]=std::byte{1};
    bytes[16+96*257+2]=std::byte{255};
    const auto exceeded=descriptors.import(bytes,session,false,0);
    check(exceeded.status==scenario::EnemyImportStatus::full&&exceeded.count==256);
    check(descriptors.record(0)->variant==0xfe&&descriptors.assignments().counts==std::array<std::uint16_t,2>{17,19});
    check(session.random.state()==random);
    ++enemy_boundary_cases;
    bytes.resize(16+96*256+2);
    const auto truncated=descriptors.import(bytes,session,false,0);
    check(truncated.status==scenario::EnemyImportStatus::malformed);
    check(descriptors.record(0)->variant==0xfe&&session.random.state()==random);
    ++enemy_boundary_cases;
}
void resource_index_fixtures(){
    std::vector<std::uint8_t> bytes(6*16384);
    const auto table=[&](unsigned base,const std::vector<std::string>& names){
        std::memcpy(bytes.data()+base,"AFS\0",4);reo::assets::put32(bytes.data()+base+4,unsigned(names.size()));
        for(unsigned i=0;i<names.size();++i){
            const auto offset=base?2048+2048*i:(i<5?16384*(i+1):16384*(i-4)+12288);
            reo::assets::put32(bytes.data()+base+8+8*i,offset);reo::assets::put32(bytes.data()+base+12+8*i,base?128:(i<5?16384:56));
            std::memcpy(bytes.data()+base+256+48*i,names[i].data(),names[i].size());
        }
        reo::assets::put32(bytes.data()+base+8+8*names.size(),256);reo::assets::put32(bytes.data()+base+12+8*names.size(),unsigned(48*names.size()));
    };
    table(0,{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs","r001_h.bin","r002_h.bin","r028_h.bin","r035_h.bin","r041_h.bin"});
    for(unsigned i=0;i<5;++i){
        const auto base=16384*(i+1);table(base,{"display0","display1","display2","display3"});
        for(unsigned n=0;n<4;++n)bytes[base+2048+2048*n]=std::uint8_t(11+n);
        auto* header=bytes.data()+base+12288;reo::assets::put32(header,1);reo::assets::put32(header+4,3);
        std::memcpy(header+8,"OBJ00_00_A_00_NB",16);std::memcpy(header+24,"OBJ00_00_A_00_NB",16);std::memcpy(header+40,"FILE_TXT",8);
    }
    const auto source=[&]{return std::make_shared<reo::assets::Source>("indexed memory",std::make_shared<Memory>(bytes));};
    const content::ScenarioArchive archive(source());
    for(unsigned id:{1u,2u,28u,35u,41u}){
        for(const auto* key:{"obj00_00_a_00.nb","OBJ00_00_A_00_NB","directory/obj00_00_a_00.nb","directory\\obj00_00_a_00.nb"}){
            const auto actual=archive.read_resource(std::uint16_t(id),key);check(actual&&actual->size()==128&&(*actual)[0]==std::byte{12});
        }
        check(archive.read_resource(std::uint16_t(id),"file:txt")->at(0)==std::byte{14});
        check(archive.read_resource(std::uint16_t(id),"file.txt")->at(0)==std::byte{14});
        check(archive.read_resource(std::uint16_t(id),"dir/FILE\\TXT")->at(0)==std::byte{14});
        check(archive.read_resource(std::uint16_t(id),"dir\\FILE:TXT")->at(0)==std::byte{14});
        check(!archive.read_resource(std::uint16_t(id),"obj00_00_a_00.nbd"));
        check(!archive.read_resource(std::uint16_t(id),"display1"));
        check(archive.read_member(std::uint16_t(id),"display1")->at(0)==std::byte{12});
    }
    check(!archive.read_resource(19,"FILE_TXT")&&!archive.read_resource(1,"")&&!archive.read_resource(1,"folder/")&&!archive.read_resource(1,std::string(256,'a'))&&!archive.read_resource(1,std::string("file\0txt",8)));
    const auto malformed=[&]{bool refused{};try{content::ScenarioArchive candidate(source());}catch(const std::invalid_argument&){refused=true;}check(refused);};
    reo::assets::put32(bytes.data()+16384+12288,4);malformed(); // index starts past the available suffix
    reo::assets::put32(bytes.data()+16384+12288,1);reo::assets::put32(bytes.data()+16384+12292,4);malformed();
    reo::assets::put32(bytes.data()+16384+12292,2);malformed(); // trailing bytes do not match count
}
void fixtures() {
    resource_index_fixtures();
    enemy_boundaries();
    std::vector<std::uint8_t> bytes(6*4096);
    const auto table=[&](std::size_t base,const std::vector<std::string>& names) {
        std::memcpy(bytes.data()+base,"AFS\0",4);
        reo::assets::put32(bytes.data()+base+4,names.size());
        for(std::size_t i=0;i<names.size();++i) {
            reo::assets::put32(bytes.data()+base+8+8*i,base?2048:4096*(i+1));
            reo::assets::put32(bytes.data()+base+12+8*i,base?128:4096);
            std::memcpy(bytes.data()+base+64+48*i,names[i].data(),names[i].size());
        }
        reo::assets::put32(bytes.data()+base+8+8*names.size(),64);
        reo::assets::put32(bytes.data()+base+12+8*names.size(),48*names.size());
    };
    table(0,{"r001.afs","r002.afs","r028.afs","r035.afs","r041.afs"});
    const std::array<unsigned,5> scenarios{1,2,28,35,41};
    for(std::size_t i=0;i<scenarios.size();++i) {
        std::array<char,16> name;
        std::snprintf(name.data(),name.size(),"r%03u.evb",scenarios[i]);
        std::array<char,16> npc_name{};
        std::snprintf(npc_name.data(),npc_name.size(),"r%03u.npc",scenarios[i]);
        table(4096*(i+1),{name.data(),npc_name.data()});
    }
    const auto source=[&] {
        return std::make_shared<reo::assets::Source>("memory",std::make_shared<Memory>(bytes));
    };
    const content::ScenarioArchive archive(source());
    check(archive.scenario_scripts(1).has_value());
    check(archive.read_member(1,"R001.EVB")->size()==128);
    check(!archive.read_member(1,"r002.evb"));
    check(!archive.read_member(0,"r001.evb"));
    check(!archive.room({1,0,0}));
    world::World world({{{}},1,{16,UINT64_MAX}},std::make_shared<world::Session>());
    Notifications notifications;
    update::Owner owner(world,notifications);
    world.session().npc_descriptors.record(0)->health=313;
    check(owner.load_scenario_npcs(archive,1)==update::Status::completed);
    check(world.session().npc_descriptors.record(0)->health==313);
    check(owner.load_scenario_npcs(archive,0)==update::Status::actor_failure);
    check(world.session().npc_descriptors.record(0)->health==313);
    check(owner.load_scenario_enemies(archive)==update::Status::actor_failure);
    world.session().scenario=1;
    check(owner.load_scenario_enemies(archive)==update::Status::actor_failure);
    check(owner.close()==update::Status::completed);
    check(owner.load_scenario_npcs(archive,1)==update::Status::closed);
    check(owner.load_scenario_enemies(archive)==update::Status::closed);
    table(4096,{"r001.evb","R001.EVB"});
    const content::ScenarioArchive duplicate(source());
    bool refused=false;
    try { (void)duplicate.read_member(1,"r001.evb"); }
    catch(const std::invalid_argument&) { refused=true; }
    check(refused);
    std::memcpy(bytes.data()+64+48,"r001.afs",8);
    refused=false;
    try { const content::ScenarioArchive invalid(source()); }
    catch(const std::invalid_argument&) { refused=true; }
    check(refused);
    refused=false;
    try { const content::ScenarioArchive invalid(nullptr); }
    catch(const std::invalid_argument&) { refused=true; }
    check(refused);
}
std::vector<std::string> columns(const std::string& line) {
    std::istringstream input(line);
    std::vector<std::string> result;
    std::string column;
    while(std::getline(input,column,'\t')) result.push_back(column);
    return result;
}
void owned(const std::filesystem::path& archive_path,const std::filesystem::path& manifest) {
    auto source=std::make_shared<reo::assets::Source>(archive_path);
    const content::ScenarioArchive archive(source);
    check(!archive.scenario_scripts(0)&&!archive.scenario_scripts(65535));
    check(!archive.room({1,100,0})&&!archive.room({1,0,100}));
    check(!archive.read_member(1,"absent")&&!archive.read_member(1,std::string(33,'a')));
    world::Profile profile;
    profile.layouts.resize(1);
    world::World world(profile,std::make_shared<world::Session>());
    Notifications notifications;
    update::Owner owner(world,notifications);
    std::ifstream input(manifest);
    check(bool(input));
    std::string line;
    while(std::getline(input,line)) {
        const auto row=columns(line);
        check(row.size()==6);
        const auto scenario_id=std::uint16_t(std::stoul(row[1]));
        const auto name=row[2];
        const auto offset=std::stoull(row[3]);
        const auto length=std::stoull(row[4]);
        const auto bytes=archive.read_member(scenario_id,name);
        check(bytes&&bytes->size()==length);
        std::vector<std::byte> expected(length);
        source->read(offset,length,expected.data());
        check(*bytes==expected);
        ++loaded_members;
        if(row[0]=="M") {
            world.mode=name.starts_with("sgl_")?0:1;
            world.session().scenario=scenario_id;
            auto expected_descriptors=world.session().enemy_descriptors;
            // The direct importer has independent original-body comparisons.
            // This check exercises normal archive naming and Update ownership.
            auto expected_session=std::make_shared<world::Session>();
            expected_session->scenario=scenario_id;
            expected_session->random=world.session().random;
            expected_session->enemy_routes=world.session().enemy_routes;
            expected_session->ai_control_requests=world.session().ai_control_requests;
            const auto imported=expected_descriptors.import(expected,*expected_session,world.mode==0,
                                                            owner.action_choices().state().table_row);
            check(imported.status==scenario::EnemyImportStatus::completed);
            check(owner.load_scenario_enemies(archive)==update::Status::completed);
            const auto& actual=world.session().enemy_descriptors;
            check(actual.count()==expected_descriptors.count());
            for(unsigned index=0;index<256;++index) {
                const auto& value=actual.records()[index];
                const auto& wanted=expected_descriptors.records()[index];
                check(value.family==wanted.family&&value.variant==wanted.variant);
                check(value.health==wanted.health&&value.maximum==wanted.maximum);
                check(value.position==wanted.position&&value.orientation==wanted.orientation);
                check(value.room==wanted.room&&value.route_position==wanted.route_position);
            }
            check(world.session().random.state()==expected_session->random.state());
            const auto controls=world.session().ai_control_requests.registrations();
            const auto wanted_controls=expected_session->ai_control_requests.registrations();
            check(std::equal(controls.begin(),controls.end(),wanted_controls.begin()));
            ++enemy_banks;
            continue;
        }
        if(row[0]=="N") {
            auto expected_descriptors=world.session().npc_descriptors;
            const auto count=expected_descriptors.import(expected);
            check(count.has_value());
            check(owner.load_scenario_npcs(archive,scenario_id)==update::Status::completed);
            const auto actual=world.session().npc_descriptors.records();
            for(unsigned index=0;index<64;++index) {
                const auto& wanted=expected_descriptors.records()[index];
                check(actual[index].template_id==wanted.template_id&&actual[index].active==wanted.active);
                check(actual[index].health==wanted.health&&actual[index].control_mode==wanted.control_mode);
                check(actual[index].room==wanted.room&&actual[index].yaw==wanted.yaw);
                check(std::bit_cast<std::uint32_t>(actual[index].position.x)==std::bit_cast<std::uint32_t>(wanted.position.x));
                check(std::bit_cast<std::uint32_t>(actual[index].position.y)==std::bit_cast<std::uint32_t>(wanted.position.y));
                check(std::bit_cast<std::uint32_t>(actual[index].position.z)==std::bit_cast<std::uint32_t>(wanted.position.z));
            }
            ++npc_banks;
            continue;
        }
        if(row[0]=="E") {
            const auto bank=archive.scenario_scripts(scenario_id);
            check(bank&&*bank->backing()==expected);
            const auto previous=owner.scripts().channels()[0];
            // All five startup EVBs still contain unimplemented commands.
            check(owner.load_scenario_scripts(archive,scenario_id,0)==update::Status::script_failure);
            check(owner.scripts().channels()[0].program==previous.program);
            continue;
        }
        check(row[0]=="R"&&name.size()==12);
        const content::RoomId id{scenario_id,std::uint16_t(std::stoul(name.substr(4,2))),
                                std::uint16_t(std::stoul(name.substr(6,2)))};
        const auto room=archive.room(id);
        check(room&&*room->backing()==expected);
        const auto section=room->section(1);
        if(!section)continue;
        const auto script_bytes=std::make_shared<const std::vector<std::byte>>(section->begin(),section->end());
        const content::ScriptBank bank(script_bytes,content::BankFormat::room_section);
        for(const auto dispatch:{scenario::DispatchProfile::ordinary,scenario::DispatchProfile::offline_actor}) {
            world.mode=dispatch==scenario::DispatchProfile::ordinary?1:0;
            check(world.session().room_contacts.initialize_counters(0,content::import_room_counter_rows(*archive.scenario_scripts(scenario_id))));
            const auto expected_program=content::admit_script_program(bank,dispatch);
            const auto previous=owner.scripts().channels()[1];
            const auto status=owner.load_room_scripts(archive,id);
            if(expected_program.status==content::ScriptAdmission::admitted) {
                check(status==update::Status::completed);
                check(owner.scripts().channels()[1].current==expected_program.entries[0]);
                check(owner.scripts().channels()[1].program->profile()==dispatch);
                ++admitted_rooms;
            } else {
                check(status==update::Status::script_failure);
                check(owner.scripts().channels()[1].program==previous.program);
                ++refused_rooms;
            }
        }
    }
    check(loaded_members==186&&npc_banks==5&&enemy_banks==10);
    check(owner.close()==update::Status::completed);
    check(owner.load_room_scripts(archive,{1,1,0})==update::Status::closed);
    check(owner.load_scenario_scripts(archive,1,0)==update::Status::closed);
    std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"members\":"<<loaded_members
             <<",\"room_bindings\":"<<admitted_rooms<<",\"refused_room_bindings\":"<<refused_rooms
             <<",\"npc_banks\":"<<npc_banks
             <<",\"enemy_banks\":"<<enemy_banks
             <<",\"enemy_boundary_cases\":"<<enemy_boundary_cases
             <<",\"game_launched\":false}\n";
}
}
int main(int argc,char** argv)try {
    fixtures();
    check(argc==1||argc==3);
    if(argc==3) {
        const std::string_view archive(argv[1]),manifest(argv[2]);
        owned(std::filesystem::path(std::u8string(archive.begin(),archive.end())),
              std::filesystem::path(std::u8string(manifest.begin(),manifest.end())));
    } else std::cout<<checks<<" archive fixture checks passed\n";
}catch(const std::exception& error) {
    std::cerr<<error.what()<<'\n';
    return 1;
}
