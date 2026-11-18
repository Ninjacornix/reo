#include "game/native/gameplay_world/cinematic_object_assets.hpp"
#include "game/native/gameplay_world/model_parts.hpp"
#include "runtime/assets/virtual_afs.h"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <future>
#include <iostream>
#include <source_location>
namespace w=reo::native::gameplay_world;
namespace a=reo::native::animation;
namespace s=reo::native::gameplay_scenario;
namespace t=reo::native::transform_math;
std::uint64_t checks{},original_calls{},assets{},nodes{},constructors{},material_entries{},archive_reads{},absent{},large_parts{},refusals{},count_cases{};
std::string location;
constexpr unsigned object=0x800000,work=object+0x70,payload=0x100000,node_base=0xd00000,resource=0xc00000;
unsigned next_material{},next_node{},requested_index{},source_loader{},render_settings{};
std::vector<std::pair<unsigned,unsigned>> render_calls;
void check(bool value,std::source_location at=std::source_location::current()){++checks;if(!value)throw std::runtime_error(std::string(at.file_name())+":"+std::to_string(at.line()));}
template<class T>T get(const std::uint8_t* m,unsigned at){return transform_read<T>(m,at);}
template<class T>void put(std::uint8_t* m,unsigned at,T value){transform_write(m,at,value);}
void invoke(std::uint8_t* m,unsigned pc,std::array<unsigned,4> args){
    static unsigned depth{};const unsigned stack=0x1f00000-0x10000*depth++;
    struct Reset{unsigned& value;~Reset(){--value;}}reset{depth};
    R5900Context c;PS2Runtime runtime;c.pc=pc;for(unsigned i=0;i<4;++i)SET_GPR_U32(&c,4+i,args[i]);SET_GPR_U32(&c,29,stack);SET_GPR_U32(&c,31,0xabcdef);
    original_transform_port(m,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==stack);
}
unsigned returned(std::uint8_t* m,unsigned pc,unsigned arg){
    R5900Context c;PS2Runtime runtime;c.pc=pc;SET_GPR_U32(&c,4,arg);SET_GPR_U32(&c,29,0x1f00000);SET_GPR_U32(&c,31,0xabcdef);
    original_transform_port(m,&c,&runtime);check(c.pc==0xabcdef&&GPR_U32(&c,29)==0x1f00000);return GPR_U32(&c,2);
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++original_calls;const auto a0=GPR_U32(context,4),a1=GPR_U32(context,5),a2=GPR_U32(context,6),a3=GPR_U32(context,7);
    switch(context->pc){
#include "original_dispatch.hpp"
    case 0x1cd1c0:check(a0==0x3000+8*requested_index);SET_GPR_U32(context,2,0);break;
    case 0x1af780:render_calls.emplace_back(a0,a1);++render_settings;break;
    case 0x1b2a70:check(a0==8&&a1==11);SET_GPR_U32(context,2,0x1234);break;
    case 0x1ce110:case 0x1aaad0:{
        ++source_loader;check(a3==3);
        if(context->pc==0x1ce110)check(a0==requested_index&&a1==UINT32_MAX&&a2==work);
        else check(a0==0&&a1==work&&a2==requested_index);
        // Explicit archive/renderer boundary: the actual owned bundle supplied
        // by the host reader is routed to complete material/root constructors.
        const auto model=get<unsigned>(memory,payload+0x14),skeleton=get<unsigned>(memory,payload+0x24);
        if(model)invoke(memory,0x1d25b0,{work,payload+model,0,0});
        if(skeleton)invoke(memory,0x1d2c00,{work,payload+skeleton,0,0});
        break;}
    case 0x1b1360:SET_GPR_U32(context,2,++next_material);break;
    case 0x1cd1e0:case 0x1cd250:case 0x1cd2c0:SET_GPR_U32(context,2,0x77);break;
    case 0x18dc50:check(a0>=16&&a0<0x10000&&a1==4);SET_GPR_U32(context,2,resource);break;
    case 0x18dca0:check(a0==resource);SET_GPR_U32(context,2,resource);break;
    case 0x1b10c0:check(a0==resource);break;
    case 0x1b1260:check(next_node<32);SET_GPR_U32(context,2,node_base+400*next_node++);break;
    default:throw std::runtime_error("undeclared original cinematic asset call "+std::to_string(context->pc));
    }
    context->pc=GPR_U32(context,31);
}
template<class Action>void refused(Action&& action){bool caught{};try{action();}catch(const std::exception&){caught=true;}check(caught);++refusals;}
void compare(std::uint8_t* memory,const w::CinematicObjectAsset& asset,unsigned index,unsigned mode){
    std::memset(memory+object,0,0x1200);std::memset(memory+node_base,0,32*400);std::memset(memory+resource,0,0x10000);
    put(memory,0x32440c,0x900000u);memory[0x3243d7]=std::uint8_t(mode);next_node=next_material=0;render_calls.clear();requested_index=index&255;source_loader=render_settings=0;
    invoke(memory,0x1d13f0,{object,index,0x98765432,0});
    const std::vector<std::pair<unsigned,unsigned>> expected{{21,2},{1,2048},{18,32768},{98,0},{12,1},{102,0},{2,0},{0,0}};
    check(render_calls==expected&&render_settings==8&&source_loader==1);
    check(get<unsigned>(memory,work)==object+0x890&&get<unsigned>(memory,work+4)==0&&get<unsigned>(memory,work+0x818)==object+0x910&&get<unsigned>(memory,work+0x808)==0x1234);
    check(get<std::uint16_t>(memory,work+0x814)==asset.materials()&&next_material==asset.materials());
    for(unsigned i=0;i<asset.materials();++i){check(get<std::uint16_t>(memory,work+8+2*i)==i+1);++material_entries;}
    check(asset.cold_attachment_scale().has_value());const auto scale=*asset.cold_attachment_scale();
    check(get<unsigned>(memory,object+0xb4)==std::bit_cast<unsigned>(scale.x)&&get<unsigned>(memory,object+0xb8)==std::bit_cast<unsigned>(scale.y)&&get<unsigned>(memory,object+0xbc)==std::bit_cast<unsigned>(scale.z));
    const auto model=asset.make_instance();check(bool(model)==bool(asset.skeleton()));
    check(get<std::uint16_t>(memory,work+0x816)==(model?model->nodes().size():0)&&next_node==(model?model->nodes().size():0));
    if(model){
        check(!model->retain()&&asset.inverse_bind_pose().size()==model->nodes().size());
        for(unsigned n=0;n<model->nodes().size();++n){
            const auto at=node_base+400*n;const auto& definition=model->skeleton().nodes()[n];const auto& pose=model->nodes()[n];const auto& links=model->links()[n];
            check(get<unsigned>(memory,object+0x890+4*n)==at);
            check(get<std::int16_t>(memory,at+0xc4)==definition.palette_index&&get<std::uint16_t>(memory,at+0xc6)==definition.track&&get<std::int32_t>(memory,at+0x174)==definition.static_index);
            const auto node_pointer=[](std::optional<std::size_t> value){return value?node_base+400*unsigned(*value):0u;};
            check(get<unsigned>(memory,at+0xc8)==node_pointer(links.parent)&&get<unsigned>(memory,at+0xd0)==node_pointer(links.child)&&get<unsigned>(memory,at+0xcc)==node_pointer(links.sibling));
            for(unsigned p=0;p<9;++p)check(get<unsigned>(memory,at+0x104+4*p)==std::bit_cast<unsigned>(pose.parameters[p]));
            const auto& inverse_bind=asset.inverse_bind_pose()[n];
            if(std::memcmp(memory+at+0x40,&pose.local,64)||std::memcmp(memory+at+0x80,&inverse_bind,64)){
                for(unsigned space=0;space<2;++space)for(unsigned col=0;col<4;++col)for(unsigned lane=0;lane<4;++lane){
                    const auto actual=std::bit_cast<unsigned>((space?inverse_bind:pose.local)[col][lane]),expected_bits=get<unsigned>(memory,at+0x40+64*space+16*col+4*lane);
                    if(actual!=expected_bits)std::cerr<<"node="<<n<<" space="<<space<<" col="<<col<<" lane="<<lane<<" actual="<<actual<<" expected="<<expected_bits<<'\n';
                }
            }
            check(std::memcmp(memory+at+0x40,&pose.local,64)==0&&std::memcmp(memory+at+0x80,&inverse_bind,64)==0);
            ++nodes;
        }
    }
    ++constructors;
}
void controls(std::uint8_t* memory){
    refused([]{w::CinematicObjectAsset::import("absent",{});});
    for(unsigned size:{0u,47u})refused([&]{w::CinematicObjectAsset::import("short",std::make_shared<const std::vector<std::byte>>(size));});
    auto bad=std::make_shared<std::vector<std::byte>>(48);unsigned offset=49,size=4;std::memcpy(bad->data()+0x14,&offset,4);std::memcpy(bad->data()+0x18,&size,4);refused([&]{w::CinematicObjectAsset::import("extent",bad);});
    refused([]{(void)w::CinematicObjectAssets::model_name({1,2,26},0);});
    check(w::CinematicObjectAssets::model_name({255,255,25},UINT32_MAX)=="obj255_255_z_-1.nbd");
    refused([]{w::CinematicObjectAssets owner({});});
    for(unsigned type:{2u,9u})for(unsigned count:{1u,0x80000001u})for(unsigned value:{0u,14u,31u,65535u,65536u,UINT32_MAX}){
        std::vector<std::byte> raw(24);const unsigned extent=24,record=12;std::memcpy(raw.data()+4,&count,4);std::memcpy(raw.data()+8,&extent,4);std::memcpy(raw.data()+12,&type,4);std::memcpy(raw.data()+16,&value,4);std::memcpy(raw.data()+20,&record,4);std::memcpy(memory+payload,raw.data(),raw.size());
        check((type==2?w::model_part_count(raw):w::model_material_count(raw))==returned(memory,type==2?0x1a31b0:0x1a32b0,payload));++count_cases;
        if(count!=1)continue; // Other-type search through this deliberately
        // negative-count control has no bounded termination and is not imported.
        auto bundle=std::make_shared<std::vector<std::byte>>(72);const unsigned start=48;std::memcpy(bundle->data()+0x14,&start,4);std::memcpy(bundle->data()+0x18,&extent,4);std::memcpy(bundle->data()+48,raw.data(),24);
        if(count==1&&value>65535)refused([&]{w::CinematicObjectAsset::import("count",bundle);});
        else {const auto asset=w::CinematicObjectAsset::import("count",bundle);check(asset->cold_attachment_scale().has_value()==(type==2||count!=1||value<=30));}
    }
    for(unsigned size:{0u,7u,12u,15u}){std::vector<std::byte> bytes(size);if(size>=8){const unsigned count=1;std::memcpy(bytes.data()+4,&count,4);}refused([&]{(void)w::model_material_count(bytes);});}
}
int main(int argc,char** argv)try{
    check(argc==4);const auto old=_mm_getcsr();struct Restore{unsigned old;~Restore(){_mm_setcsr(old);}}restore{old};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> memory(0x2000000);owned_constants(memory.data());put(memory.data(),0x294e00,t::identity());
    auto source=std::make_shared<reo::assets::Source>(argv[1]);auto archive=std::make_shared<s::content::ScenarioArchive>(source);w::CinematicObjectAssets owner(archive);
    std::ifstream package(argv[2],std::ios::binary),manifest(argv[3]);check(bool(package)&&bool(manifest));unsigned count{};package.read(reinterpret_cast<char*>(&count),4);check(count==452);
    for(unsigned i=0;i<count;++i){
        unsigned size{},scenario{},area{},scene{},variant{},number{},parts{},materials{},joint_count{},canonical{};std::string name;
        package.read(reinterpret_cast<char*>(&size),4);check(size>=48&&size<0x100000);auto bytes=std::make_shared<std::vector<std::byte>>(size);package.read(reinterpret_cast<char*>(bytes->data()),size);check(bool(package));
        manifest>>scenario>>area>>scene>>variant>>number>>name>>parts>>materials>>joint_count>>canonical;check(bool(manifest));location=name;
        const auto asset=w::CinematicObjectAsset::import(name,bytes);check(asset->bytes().data()==bytes->data()&&asset->parts()==parts&&asset->materials()==materials);
        auto first=asset->make_instance(),second=asset->make_instance();check(bool(first)==bool(joint_count)&&bool(second)==bool(joint_count));
        if(first){check(first!=second&&first->nodes().size()==joint_count);first->rebuild(t::identity());second->rebuild(t::identity());const auto retained=first->retain();first->local_translation(0,{17,18,19});check(second->retain()&&retained&&first->retain()==nullptr&&retained->joints==second->retain()->joints);}else ++absent;
        if(parts>8)++large_parts;
        std::memcpy(memory.data()+payload,bytes->data(),bytes->size());const auto section=get<unsigned>(memory.data(),payload+0x14);
        if(section){check(returned(memory.data(),0x1a31b0,payload+section)==parts&&returned(memory.data(),0x1a32b0,payload+section)==materials);count_cases+=2;}
        for(unsigned mode:{0u,1u,128u,255u})compare(memory.data(),*asset,i+0x100u,mode);
        if(canonical){const s::CutsceneCue cue{std::uint8_t(area),std::uint8_t(scene),std::uint8_t(variant)};const auto loaded=owner.read(std::uint16_t(scenario),cue,number);check(loaded&&loaded->parts()==parts&&loaded->materials()==materials&&loaded->bytes().size()==bytes->size()&&std::memcmp(loaded->bytes().data(),bytes->data(),bytes->size())==0);check(owner.read(std::uint16_t(scenario),cue,number)==loaded);
            if(archive_reads==0){std::array<std::future<std::shared_ptr<const w::CinematicObjectAsset>>,8> futures;for(auto& future:futures)future=std::async(std::launch::async,[&]{return owner.read(std::uint16_t(scenario),cue,number);});for(auto& future:futures)check(future.get()==loaded);}++archive_reads;}
        ++assets;
    }
    check(assets==452&&archive_reads==450&&absent==2&&large_parts==1);check(!owner.read(19,{1,2,0},0)&&!owner.read(1,{99,99,25},0));
    location="malformed/count controls";controls(memory.data());
    std::cout<<"{\"checks\":"<<checks<<",\"assets\":"<<assets<<",\"source_constructors\":"<<constructors<<",\"source_nodes\":"<<nodes<<",\"material_entries\":"<<material_entries<<",\"archive_reads\":"<<archive_reads<<",\"absent_skeletons\":"<<absent<<",\"large_part_models\":"<<large_parts<<",\"count_cases\":"<<count_cases<<",\"refusals\":"<<refusals<<",\"original_calls\":"<<original_calls<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<location<<" "<<e.what()<<'\n';return 1;}
