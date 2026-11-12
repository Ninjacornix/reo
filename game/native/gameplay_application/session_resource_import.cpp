#include "session_resource_import.hpp"
#include <bit>
#include <cstdio>
#include <cstring>
#include <stdexcept>
namespace reo::native::gameplay_application {
namespace {
template<class T>T read(std::span<const std::byte> bytes,std::size_t at){
    if(at>bytes.size()||sizeof(T)>bytes.size()-at)throw std::invalid_argument("Resource import extent unavailable");
    T value;std::memcpy(&value,bytes.data()+at,sizeof value);return value;
}
std::span<const std::byte> part(std::span<const std::byte> bytes,unsigned index){
    const auto at=read<std::uint32_t>(bytes,8*index),size=read<std::uint32_t>(bytes,8*index+4);
    if(!at||!size)return{};
    if(at>bytes.size()||size>bytes.size()-at)throw std::invalid_argument("Resource section extent unavailable");
    return bytes.subspan(at,size);
}
constexpr std::array<std::array<std::uint16_t,2>,152> starting_resources{{
#include "starting_resources.inc"
}};
}
ResourceBootstrap::ResourceBootstrap(gameplay_world::World& world,gameplay_scenario::SceneResources& resources,
    gameplay_scenario::ResourceTemplates& templates,gameplay_world::WorldInventory& inventory):
    world_(world),resources_(resources),templates_(templates),inventory_(inventory){
    if(!inventory_.bound_to(world_,resources_,templates_))throw std::invalid_argument("Canonical resource bootstrap owners required");
}
void ResourceBootstrap::clear(){
    for(unsigned i=0;i<gameplay_scenario::SceneResources::capacity;++i){
        gameplay_scenario::SceneDescriptor cleared;cleared.template_index=0;
        if(!resources_.load(i,cleared))throw std::runtime_error("Resource descriptor generation unavailable");
    }
    templates_=gameplay_scenario::ResourceTemplates{};
    tuning_={};for(auto& record:tuning_)record.values[0]=50;
    world_.session().auxiliary_resources={};
}
void ResourceBootstrap::selection(std::span<const std::byte> bytes,std::uint16_t random,ResourceImportReport& report){
    const auto version=read<std::uint32_t>(bytes,0);const auto count=read<std::int32_t>(bytes,4);
    if(version!=4||count<=0)return;
    if(count>4096||std::size_t(count)>(bytes.size()-8)/12)throw std::invalid_argument("Resource selection rows unavailable");
    for(std::int32_t i=0;i<count;++i){std::int32_t remainder=random;
        for(unsigned choice=0;choice<3;++choice){const std::size_t at=8+12*std::size_t(i)+4*choice;
            remainder-=read<std::uint8_t>(bytes,at+3);if(remainder>=0)continue;
            const auto content=read<std::uint16_t>(bytes,at);if(content==65535)break;
            const auto made=resources_.allocate(0,std::uint16_t(i+1),0,templates_);
            if(made.status!=gameplay_scenario::SceneStatus::full&&made.status!=gameplay_scenario::SceneStatus::completed)
                throw std::runtime_error("Resource selection allocation unavailable");
            if(made.id){auto value=*resources_.get(*made.id);value.attachment_id=content;
                value.parameter=read<std::int8_t>(bytes,at+2);value.flags=0x800;
                if(content==0x3717)value.parameter=world_.session().clock_mode?600:1200;
                if(resources_.replace(*made.id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Resource selection identity unavailable");
                ++report.selected;
            }
            break;
        }
    }
}
void ResourceBootstrap::item(std::span<const std::byte> bytes,ResourceImportReport& report){
    if(const auto data=part(bytes,0);!data.empty())(void)templates_.load(data);
    if(const auto data=part(bytes,1);!data.empty()){
        const auto version=read<std::uint32_t>(data,0);const auto count=read<std::int32_t>(data,4);
        if(version==3&&count>0){
            if(count>4096||std::size_t(count)>(data.size()-8)/36)throw std::invalid_argument("Resource placement rows unavailable");
            for(std::int32_t i=0;i<count;++i){const std::size_t at=8+36*std::size_t(i);const auto authored=read<std::uint16_t>(data,at+2);
                for(unsigned slot=0;slot<gameplay_scenario::SceneResources::capacity;++slot){const auto id=*resources_.slot(slot);auto value=*resources_.get(id);
                    if(!value.active||value.authored_id!=authored)continue;
                    value.room=std::uint8_t(read<std::uint16_t>(data,at));
                    value.position={read<float>(data,at+4),read<float>(data,at+8),read<float>(data,at+12)};
                    value.tilt=read<std::uint16_t>(data,at+16);value.yaw=read<std::uint16_t>(data,at+18);
                    value.shape_profile=read<std::int8_t>(data,at+20);value.orientation_variant=read<std::int8_t>(data,at+21);value.saved_yaw=read<std::uint16_t>(data,at+22);
                    value.saved_position={read<float>(data,at+24),read<float>(data,at+28),read<float>(data,at+32)};
                    value.flags|=1;value.template_index=std::bit_cast<std::uint8_t>(templates_.selector(std::bit_cast<std::int16_t>(value.attachment_id)));
                    if(resources_.replace(id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Resource placement identity unavailable");
                    ++report.placed;break;
                }
            }
        }
    }
    if(const auto data=part(bytes,2);!data.empty()){
        const auto count=read<std::int32_t>(data,0);
        if(count>0){if(count>std::int32_t(tuning_.size())||std::size_t(count)>(data.size()-4)/8)throw std::invalid_argument("Resource tuning rows unavailable");
            for(std::int32_t i=0;i<count;++i)for(unsigned lane=0;lane<4;++lane)tuning_[std::size_t(i)].values[lane]=read<std::int16_t>(data,4+8*std::size_t(i)+2*lane);
            report.tuning_records=std::size_t(count);
        }
    }
}
void ResourceBootstrap::starting(ResourceImportReport& report){
    const auto count=std::bit_cast<std::int32_t>(*world_.session().primary_population);
    for(std::int32_t slot=0;slot<count;++slot){const auto actor=world_.primary(std::uint32_t(slot));const auto variant=actor->model_variant;
        if(!variant||variant>152)continue;
        std::int32_t available=4;
        for(auto carried:actor->inventory.carried)if(carried){const auto value=*resources_.get(*resources_.slot(carried));
            const bool doubled=value.active&&value.template_index!=255&&(templates_.flags(value.template_index)&0x20000u);
            available-=doubled?2:1;
        }
        if(!available)continue;
        const auto row=starting_resources[std::size_t(variant-1)];if(row[0]==65535||!row[1])continue;
        const auto made=resources_.allocate(0,0,row[0],templates_);
        if(made.status==gameplay_scenario::SceneStatus::full)break;
        if(!made.id)throw std::runtime_error("Starting resource allocation unavailable");
        auto value=*resources_.get(*made.id);value.flags=1;value.kind=0;value.parameter=std::bit_cast<std::int16_t>(row[1]);value.ownership_tag=std::uint16_t(slot+1);
        if(resources_.replace(*made.id,value)!=gameplay_scenario::SceneStatus::completed)throw std::runtime_error("Starting resource identity unavailable");
        inventory_.insert(world_.identity_of(*actor),made.slot);++report.starting;
    }
}
ResourceImportReport ResourceBootstrap::run(const gameplay_scenario::content::ScenarioArchive& archive)noexcept{
    ResourceImportReport report;
    if(world_.closed()){report.status=ResourceImportStatus::closed;return report;}
    if(running_||world_.busy()){report.status=ResourceImportStatus::busy;return report;}
    const auto& session=world_.session();
    if(!world_.mode||!world_.scenario||!session.difficulty||!session.asset_loading_mode||!*session.asset_loading_mode||!session.primary_population)return report;
    const auto count=std::bit_cast<std::int32_t>(*session.primary_population);
    if(count>std::int32_t(gameplay_world::World::primary_capacity))return report;
    for(std::int32_t i=0;i<count;++i)if(!world_.primary(std::uint32_t(i))){report.status=ResourceImportStatus::unavailable_actor;return report;}
    running_=world_.updating_=true;
    struct Guard{bool& local;bool& world;~Guard(){local=false;world=false;}}guard{running_,world_.updating_};
    try{
        clear();const auto variant=unsigned(*session.difficulty)*4+(world_.session().random.request(2)&3u);
        const auto random=std::uint16_t(world_.session().random.request(0)%100);char name[40];
        const int length=std::snprintf(name,sizeof name,"item%03u%02u.tbl",unsigned(*world_.scenario),variant);
        if(length<0||std::size_t(length)>=sizeof name)throw std::invalid_argument("Resource selection key unavailable");
        report.selection_key=name;
        if(const auto bytes=archive.read_resource(*world_.scenario,name)){report.selection_found=true;selection(*bytes,random,report);}
        const int item_length=std::snprintf(name,sizeof name,"item%03u.dat",unsigned(*world_.scenario));
        if(item_length<0||std::size_t(item_length)>=sizeof name)throw std::invalid_argument("Resource item key unavailable");
        if(const auto bytes=archive.read_resource(*world_.scenario,name)){report.item_found=true;item(*bytes,report);}
        starting(report);report.status=ResourceImportStatus::completed;
    }catch(const std::exception&){report.status=ResourceImportStatus::invalid_asset;}
    return report;
}
}
