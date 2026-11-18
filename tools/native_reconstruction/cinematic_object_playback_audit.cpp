#include "game/native/gameplay_world/cinematic_object_construction.hpp"
#include "game/native/gameplay_world/cinematic_object_motion_assets.hpp"
#include "runtime/assets/virtual_afs.h"
#include <fstream>
#include <algorithm>
#include <cmath>
#include <iostream>
#include <immintrin.h>
#include <set>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
std::uint64_t checks{},descriptors{},model_failures{},bank_failures{},pairs{},complete{},missing_slots{},absent_models{},clip_refusals{},playback_refusals{},updates{};
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error("Object playback audit check "+std::to_string(at.line()));}
w::Profile profile(){w::Profile value;value.layouts.push_back({});return value;}
int main(int argc,char** argv)try{
    check(argc==5);const auto old=_mm_getcsr();struct Restore{unsigned old;~Restore(){_mm_setcsr(old);}}restore{old};_mm_setcsr(0x1f80);
    auto source=std::make_shared<reo::assets::Source>(argv[1]);auto archive=std::make_shared<s::content::ScenarioArchive>(source);w::CinematicObjectAssets assets(archive);w::CinematicObjectMotionAssets motions(source);
    std::ifstream package(argv[2],std::ios::binary),requests(argv[3]);std::ofstream evidence(argv[4]);check(bool(package)&&bool(requests)&&bool(evidence));unsigned count{};package.read(reinterpret_cast<char*>(&count),4);check(count==548);evidence<<"descriptor\tgroup\tmotion\tclock_mode\tstatus\tdetail\n";
    for(unsigned index=0;index<count;++index){
        unsigned area{},scene{},variant{},expected_available{},size{};std::string name;requests>>area>>scene>>variant>>expected_available>>name;check(bool(requests));package.read(reinterpret_cast<char*>(&size),4);check(size>=40&&size<0x100000);std::vector<std::byte> bytes(size);package.read(reinterpret_cast<char*>(bytes.data()),size);check(bool(package));const auto descriptor=s::CutsceneDescriptor::import(bytes);++descriptors;
        std::shared_ptr<const w::PreparedCinematicObjects> prepared;try{prepared=w::CinematicObjectConstruction::prepare(*descriptor,{std::uint8_t(area),std::uint8_t(scene),std::uint8_t(variant)},assets);}catch(const std::exception& e){check(!expected_available);evidence<<name<<"\t-1\t0\t0\tmissing_model_request\t"<<e.what()<<'\n';++model_failures;continue;}check(expected_available&&prepared);
        if(prepared->size()==0)continue;
        const auto bank=motions.read(descriptor->identity()[0],std::uint16_t(area));if(bank.status!=w::CinematicObjectMotionStatus::loaded){++bank_failures;evidence<<name<<"\t-1\t0\t0\tmissing_object_bank\t"<<unsigned(bank.status)<<'\n';continue;}check(bool(bank.bank));
        w::World world(profile(),std::make_shared<w::Session>());world.paused=1;auto& pool=world.cinematic_objects();check(pool.initialize()==w::CinematicObjectStatus::completed);w::CinematicObjectConstruction factory(world);const auto built=factory.create(*prepared);check(built.status==w::CinematicObjectStatus::completed&&built.constructed==prepared->size());const auto groups=prepared->tracks(built.bindings);
        for(unsigned group=0;group<groups.size();++group){
            std::set<std::uint32_t> keys;
            for(const auto& stream:groups[group].streams)for(unsigned row=0;row<stream->size();++row){const auto event=stream->record(row);if(std::to_integer<unsigned>(event[1])!=2||stream->frame(row)==65535)continue;std::uint32_t key;std::memcpy(&key,event.data()+4,4);keys.insert(key);}
            for(auto key:keys)for(unsigned clock:{0u,1u}){
                ++pairs;auto value=pool.resolve(built.bindings[group].object);check(value&&value->model_asset==prepared->asset(group));
                const auto record=[&](const char* status,const std::string& detail){evidence<<name<<'\t'<<group<<'\t'<<key<<'\t'<<clock<<'\t'<<status<<'\t'<<detail<<'\n';};
                if(!value->model){++absent_models;record("absent_skeleton",value->model_asset->name().data());continue;}
                const auto slot=200ull*(key/100)+key%100;
                if(slot>=a::MotionBank::capacity||!bank.bank->slots()[std::size_t(slot)]){++missing_slots;record("missing_motion_slot",std::to_string(slot));continue;}
                std::shared_ptr<const a::Clip> clip;
                try{clip=bank.bank->slots()[std::size_t(slot)]->clip();}catch(const std::exception& e){++clip_refusals;record("unadmitted_clip",e.what());continue;}
                for(unsigned i=0;i<prepared->size();++i)pool.resolve(built.bindings[i].object)->active=false;
                value->model=value->model_asset->make_instance();value->active=value->visible=true;value->phase=value->animation_phase=0;value->motion=key;value->flags=1;value->pose.reset();value->timing={};value->position={};value->angles={};world.session().clock_mode=std::uint8_t(clock);
                try{
                    for(unsigned tick=0;tick<17;++tick){const auto output=pool.run(*bank.bank,0);if(output.status!=w::CinematicObjectStatus::completed){throw std::runtime_error("Required object data unavailable in model pass");}check(output.called==1&&output.published==1&&value->model->retain()&&value->model->retain()->joints.size()==value->model->nodes().size()&&!world.busy());++updates;}
                    ++complete;record("completed_17_controlled_updates",std::to_string(value->model->nodes().size()));
                }catch(const std::exception& e){++playback_refusals;
                    float maximum_angle{};for(const auto& node:value->model->nodes())for(unsigned lane=3;lane<6;++lane)maximum_angle=std::max(maximum_angle,std::abs(node.parameters[lane]));
                    const auto ids=value->model->track_ids();const auto matching=std::count(ids.begin(),ids.end(),0);
                    record("bind_sample_or_pose_refused",std::string(e.what())+";nodes="+std::to_string(ids.size())+";track0_nodes="+std::to_string(matching)+";clip_tracks="+std::to_string(clip->tracks().size())+";frame="+std::to_string(value->timing.frame)+";maximum_angle="+std::to_string(maximum_angle));check(!world.busy());}
                value->active=false;
            }
        }
        check(world.close()==w::Status::completed);
    }
    check(model_failures==12&&pairs>0&&complete>0);evidence.flush();check(bool(evidence));
    std::cout<<"{\"checks\":"<<checks<<",\"descriptors\":"<<descriptors<<",\"model_request_failures\":"<<model_failures<<",\"bank_request_failures\":"<<bank_failures<<",\"model_motion_clock_pairs\":"<<pairs<<",\"completed_pairs\":"<<complete<<",\"completed_updates\":"<<updates<<",\"missing_slots\":"<<missing_slots<<",\"absent_skeletons\":"<<absent_models<<",\"clip_refusals\":"<<clip_refusals<<",\"playback_refusals\":"<<playback_refusals<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
