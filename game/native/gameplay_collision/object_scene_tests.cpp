#define main historical_object_lifetime_main
#include "object_lifetime_tests.cpp"
#undef main
#include "object_scene.hpp"
unsigned outer_cases{},outer_selected{},outer_constructed{},outer_pool_full{},outer_inactive{};
void outer_room(const std::array<std::string,6>& files,unsigned variant){
    const auto types=load(files[0].c_str()),placements=load(files[1].c_str()),grid=load(files[3].c_str());
    const auto number=std::uint16_t(std::stoi(files[2]));
    auto objects=r::Owner::import(types,placements);r::InteractionOwner interactions(objects);
    const auto walls=c::response::Grid::import(load(files[4].c_str())),floors=c::response::Grid::import(load(files[5].c_str()));
    geometry_fixture::walls=&walls;lifetime_fixture::floors=&floors;
    geometry_fixture::filter={};geometry_fixture::filter.disabled=variant==1?0x10000000u:0;
    invoke(0x6acf80);invoke(0x5c1120);invoke(0x590be0);invoke(0x6ad820);
    const auto* tb=reinterpret_cast<const std::uint8_t*>(types.data());
    const auto* pb=reinterpret_cast<const std::uint8_t*>(placements.data());
    const auto type_count=ref_read<std::uint32_t>(tb,4),type_at=ref_read<std::uint32_t>(tb,8),model_at=ref_read<std::uint32_t>(tb,12);
    std::memcpy(memory.data()+0x74b1c0,tb+type_at,type_count*8);
    std::memcpy(memory.data()+0x74b180,tb+model_at,type_count*2);
    for(unsigned i=0;i<ref_read<std::uint32_t>(pb,4);++i){std::memcpy(memory.data()+0x1000,pb+8+16*i,16);check(invoke(0x6ad0f0,0x1000)!=0,"outer owned placement import");}
    ref_write(memory.data(),0x3243dc,number);
    std::memcpy(memory.data()+0x20000,grid.data(),grid.size());invoke(0x6ad860,0x20000);check(objects.install_grid(number,grid),"outer actual owned grid");
    if(variant==2){invoke(0x6ad820);objects.reset_room_grid();check(!objects.grid(),"actual6AD820 resets grid admission");for(unsigned i=0;i<8;++i)check(!objects.mapped(i),"actual6AD820 clears grid-derived mapping capabilities");++outer_inactive;}
    for(const auto& id:objects.objects()){
        const auto& object=*objects.get(id);const auto ordinal=*interactions.source_ordinal(id);const auto at=0x3c4580+60*unsigned(ordinal);
        // Declared nonzero entry state, fed identically to both complete callers.
        (void)objects.change_external_flags(object.external_id,2,0);interactions.request_primary(id,std::uint16_t(ordinal*0x4000));
        const auto& input=*objects.get(id);ref_write(memory.data(),at+0x24,input.control_flags);
        memory[at+0x1c]=std::uint8_t(input.requests);memory[at+0x1d]=input.direction;memory[at+0x1e]=input.secondary_direction;
    }
    a::EntityStore entities({64});c::ownership::Proxies proxies;Bindings bindings;bindings.initialize(entities);
    if(variant==3){while(entities.size()<64)check(bool(entities.create(std::make_unique<a::Entity>()).id)&&invoke(0x590c70,1)!=0,"outer declared actual pool exhaustion");++outer_pool_full;}
    r::Scene scene(objects,entities,proxies,*bindings.real,walls,floors);
    const auto result=scene.initialize(number,geometry_fixture::filter);invoke(0x6ad4e0);
    check(result.status==r::SceneStatus::complete,"complete native outer construction");
    check(scene.count()==memory[0x745d60]&&result.selected==scene.count(),"outer source count includes natural no-instance branches");
    initialized_centers.clear();for(const auto& id:objects.objects())if(objects.get(id)->room==number&&objects.grid())initialized_centers.insert(*interactions.source_ordinal(id));
    compare(objects,interactions,scene.lifetime(),proxies);binding_events(bindings);dynamic(scene.lifetime());
    for(const auto& id:objects.objects()){const auto& object=*objects.get(id);const auto at=0x3c4580+60*unsigned(*interactions.source_ordinal(id));
        check(object.secondary_direction==memory[at+0x1e],"outer exact secondary direction reset");
        check(object.requests==0&&object.direction==0&&!(object.control_flags&2),"outer resets active records outside current room too");
    }
    check(scene.initialize(number,{}).status==r::SceneStatus::already_started,"outer cannot abandon an installed lifetime on retry");
    outer_selected+=unsigned(result.selected);outer_constructed+=unsigned(result.constructed);++outer_cases;
    check(scene.close()==r::InstanceStatus::complete,"outer native checked room teardown");
    check(proxies.size()==0&&entities.size()==(variant==3?64u:0u),"outer releases all owned instances and proxies");
    for(const auto& id:objects.objects()){const auto& object=*objects.get(id);check(!object.instance,"outer clears canonical instance identity");for(const auto& proxy:object.proxies)check(!proxy,"outer clears canonical proxy identities");}
}
int main(int argc,char** argv){
    check(argc==4,"outer owned manifest/profile/table arguments");
    const auto profiles=load(argv[2]),tables=load(argv[3]);std::memcpy(memory.data()+0x723740,profiles.data(),profiles.size());std::memcpy(memory.data()+0x719900,tables.data(),tables.size());
    for(unsigned i=0;i<4;++i){memory[0x719900+i]=std::uint8_t(i*2);ref_write(memory.data(),0x719910+4*i,0x6aebe0u);}
    ref_write(memory.data(),0x38b280,0.0054931640625f);ref_write(memory.data(),0x241c88,3.1415927410125732f);ref_write(memory.data(),0x241c78,-6.2831854820251465f);
    use_real_model_provider=true;lifetime_fixture::real_model_bindings=true;
    for(unsigned i=0;i<32;++i)real_model_map[i]=std::uint8_t(i);
    std::ifstream manifest(argv[1]);std::string line;
    while(std::getline(manifest,line)){if(line.empty())continue;std::istringstream fields(line);std::array<std::string,6> values;for(auto& value:values)std::getline(fields,value,'\t');for(unsigned variant=0;variant<4;++variant)outer_room(values,variant);}
    check(outer_cases==28&&outer_constructed>0&&outer_selected>outer_constructed&&outer_pool_full==7&&outer_inactive==7,"outer owned and controlled constructor branches exercised");
    std::printf("{\"checks\":%u,\"outer_cases\":%u,\"selected\":%u,\"constructed\":%u,\"pool_full_cases\":%u,\"inactive_grid_cases\":%u,\"maximum_error\":%.9g,\"game_launched\":false}\n",checks,outer_cases,outer_selected,outer_constructed,outer_pool_full,outer_inactive,double(maximum_error));
}
