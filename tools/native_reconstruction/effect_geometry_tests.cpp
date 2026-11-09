#include "game/native/gameplay_effects/geometry.hpp"
#include "reference.hpp"
#include "functions.h"
#include <fstream>
#include <iostream>
#include <source_location>
namespace e=reo::native::gameplay_effects;
unsigned checks{},calls{},assets{},roots{},meshes{},material_cases{},lookup_cases{},heap_allocations{},heap_releases{},unadmitted_palettes{},authored_parts{},unadmitted_parts{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Effect geometry check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* memory,std::uint32_t at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,std::uint32_t at,T value){transform_write(memory,at,value);}
constexpr std::uint32_t model=0x3b85b0,heap=0x800000,parts=0x900000,work=0x20000,piece=0x30000,descriptor=0x50000;
bool allocated{};
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;const auto done=[&](){context->pc=GPR_U32(context,31);};
    switch(context->pc){
    case 0x18dc50:check(!allocated&&GPR_U32(context,5)==4&&GPR_U32(context,4)<0x100000);allocated=true;++heap_allocations;SET_GPR_U32(context,2,1);done();return;
    case 0x18dca0:check(allocated&&GPR_U32(context,4)==1);SET_GPR_U32(context,2,heap);done();return;
    case 0x18dc90:check(allocated&&GPR_U32(context,4)==1);allocated=false;++heap_releases;done();return;
    case 0x1b10c0:case 0x1b1110:check(GPR_U32(context,4)==1);done();return; // Cache ownership bookkeeping only.
#include "original_dispatch.hpp"
    default:throw std::runtime_error("Unadmitted effect geometry source call "+std::to_string(context->pc));
    }
}
#pragma GCC diagnostic push
#pragma GCC diagnostic ignored "-Wunused-variable"
#include "original_geometry.cpp"
#pragma GCC diagnostic pop
R5900Context call(std::uint8_t* memory,std::uint32_t function,std::uint32_t a0,std::uint32_t a1=0,std::uint32_t a2=0,std::uint32_t a3=0){
    R5900Context context;context.pc=function;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
    SET_GPR_U32(&context,4,a0);SET_GPR_U32(&context,5,a1);SET_GPR_U32(&context,6,a2);SET_GPR_U32(&context,7,a3);PS2Runtime runtime;
    original_transform_port(memory,&context,&runtime);check(context.pc==0x100&&GPR_U32(&context,29)==0x1f00000);return context;
}
std::vector<std::vector<std::byte>> load(const char* path){
    std::ifstream source(path,std::ios::binary);std::uint32_t n{};source.read(reinterpret_cast<char*>(&n),4);check(n==12);std::vector<std::vector<std::byte>> data;
    for(unsigned i=0;i<n;++i){std::uint32_t size{};source.read(reinterpret_cast<char*>(&size),4);check(size&&size<0x200000);data.emplace_back(size);source.read(reinterpret_cast<char*>(data.back().data()),size);check(bool(source));}
    check(source.peek()==std::char_traits<char>::eof());return data;
}
int main(int argc,char** argv)try{
    check(argc==2);auto corpus=load(argv[1]);std::vector<std::uint8_t> ram(0x2000000);auto* memory=ram.data();
    for(unsigned asset=0;asset<corpus.size();asset+=2){
        const auto& nbd=corpus[asset];const auto& efdata=corpus[asset+1];
        auto geometry=e::Geometry::import_nbd(nbd);auto material=e::MaterialTracks::import(efdata,*geometry);
        auto tracks=e::Tracks::import(efdata);check(bool(tracks));++assets;roots+=unsigned(geometry->roots().size());meshes+=unsigned(geometry->meshes().size());
        std::memcpy(memory+0x100000,nbd.data(),nbd.size());std::memcpy(memory+0xa00000,efdata.data(),efdata.size());
        const auto raw_model=0x100000+get<std::uint32_t>(memory,0x100014),raw_forest=0x100000+get<std::uint32_t>(memory,0x100024);
        const auto mesh_count=call(memory,0x1a31b0,raw_model);check(GPR_U32(&mesh_count,2)==geometry->meshes().size());
        // Complete original count/list extraction supplies the material arrays
        // consumed by actual590790. No guessed list contents are substituted.
        put(memory,model+0x808,parts);
        for(unsigned i=0;i<geometry->meshes().size();++i){
            const auto c=call(memory,0x1a34b0,raw_model,i);const auto n=GPR_U32(&c,2);check(n==geometry->meshes()[i].indices.size());
            put(memory,parts+152*i+4,n);call(memory,0x1a3500,raw_model,i,parts+152*i+8);
            for(unsigned j=0;j<n;++j)check(get<std::uint32_t>(memory,parts+152*i+8+4*j)==geometry->meshes()[i].indices[j]);
        }
        put(memory,0x32440c,std::uint32_t(0x400000));call(memory,0x1d3350,model,raw_forest,0);
        check(!allocated&&heap_allocations==heap_releases);check(std::size_t(get<std::uint16_t>(memory,model+0x820))==geometry->roots().size());
        for(unsigned i=0;i<geometry->roots().size();++i){const auto& root=geometry->roots()[i];
            if(!root.palette_admitted){check(asset==8&&i==48&&root.id==53);check(!geometry->material(i,0));++unadmitted_palettes;continue;}
            if(root.id!=get<std::int16_t>(memory,model+0x824+2*i)||root.meshes.size()!=get<std::uint16_t>(memory,model+0xc24+2*i))
                throw std::runtime_error("Root mismatch asset="+std::to_string(asset/2)+" root="+std::to_string(i)+" id native="+std::to_string(root.id)+" original="+std::to_string(get<std::int16_t>(memory,model+0x824+2*i))+" count native="+std::to_string(root.meshes.size())+" original="+std::to_string(get<std::uint16_t>(memory,model+0xc24+2*i)));
            check(root.id==get<std::int16_t>(memory,model+0x824+2*i));check(root.meshes.size()==get<std::uint16_t>(memory,model+0xc24+2*i));
            for(unsigned j=0;j<root.meshes.size();++j)check(root.meshes[j]==get<std::uint16_t>(memory,model+0x1024+32*i+2*j));
        }
        for(unsigned i=0;i<4096;++i){const auto id=i<256?std::int16_t(i):std::bit_cast<std::int16_t>(std::uint16_t(i*4093));const auto native=geometry->resolve(id);auto c=call(memory,0x372720,std::uint16_t(id));const auto original=std::bit_cast<std::int16_t>(std::uint16_t(GPR_U32(&c,2)));check(original<0?!native:native&&*native==std::size_t(original));++lookup_cases;}
        for(const auto& group:tracks->groups())for(const auto& part:group.parts){
            ++authored_parts;if(!part.selector)continue;
            const auto root=geometry->resolve(part.resource);
            if(!root||!geometry->material(*root,part.material)||part.selector>group.parts.size()){
                ++unadmitted_parts;std::cerr<<"Unadmitted authored part asset="<<asset/2<<" resource="<<unsigned(part.resource)<<" material="<<unsigned(part.material)<<" selector="<<unsigned(part.selector)<<'\n';
            }
        }
        for(std::uint16_t logical:{36,37,38}){
            check(geometry->resolve(std::int16_t(logical)).has_value());const auto selected=tracks->resolve(logical,0);check(selected.has_value());const auto* group=tracks->group(*selected);check(group!=nullptr);
            for(const auto& part:group->parts){
                check(part.selector&&part.selector<=group->parts.size());const auto root=geometry->resolve(part.resource);check(root.has_value());const auto* mesh=geometry->material(*root,part.material);check(mesh!=nullptr);check(material->complete(*mesh));
                std::array<float,8> values;values.fill(std::numeric_limits<float>::quiet_NaN());material->sample(*mesh,0,values);
                for(std::size_t i=0;i<mesh->indices.size();++i)check(std::isfinite(values[i]));
            }
        }
        put(memory,descriptor+0x18,model);put(memory,descriptor+0x1c,std::uint32_t(0xa00400));put(memory,work+0x1f4,descriptor);
        for(unsigned root=0;root<geometry->roots().size();++root)for(unsigned slot=0;slot<geometry->roots()[root].meshes.size();++slot){
            if(!geometry->roots()[root].palette_admitted)continue;
            const auto* mesh=geometry->material(root,std::uint8_t(slot));check(mesh!=nullptr);
            for(auto time:{std::int16_t(-32768),std::int16_t(-1),std::int16_t(0),std::int16_t(1),std::int16_t(2),std::int16_t(17),std::int16_t(33),std::int16_t(32767)}){
                std::array<float,8> values;for(unsigned i=0;i<8;++i)values[i]=float(int(i)-3)*1.125f;
                std::memcpy(memory+piece+0x50,values.data(),sizeof values);put(memory,piece+1,std::uint8_t(slot));put(memory,piece+2,std::uint16_t(root));put(memory,work+0x10,time);
                call(memory,0x590790,work,piece);material->sample(*mesh,time,values);
                for(unsigned i=0;i<8;++i){check(std::bit_cast<std::uint32_t>(values[i])==get<std::uint32_t>(memory,piece+0x50+4*i));}
                ++material_cases;
            }
        }
        check(!geometry->material(geometry->roots().size(),0));
        bool missing{};std::array<float,1> scratch{};try{material->sample(e::MeshChannels{{UINT32_MAX}},0,scratch);}catch(const std::invalid_argument&){missing=true;}check(missing);
        const auto retained=geometry;geometry.reset();check(!retained->roots().empty());
    }
    for(unsigned n=0;n<48;++n){bool rejected{};try{e::Geometry::import_nbd(std::vector<std::byte>(n));}catch(const std::invalid_argument&){rejected=true;}check(rejected);}
    for(unsigned offset:{0x14,0x18,0x24,0x28}){
        auto corrupt=corpus[0];const auto invalid=UINT32_MAX;std::memcpy(corrupt.data()+offset,&invalid,sizeof invalid);bool rejected{};
        try{e::Geometry::import_nbd(corrupt);}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    }
    bool material_rejected{};try{e::MaterialTracks::import({},*e::Geometry::import_nbd(corpus[0]));}catch(const std::invalid_argument&){material_rejected=true;}check(material_rejected);
    check(unadmitted_palettes==1);
    std::cout<<"{\"checks\":"<<checks<<",\"assets\":"<<assets<<",\"roots\":"<<roots<<",\"meshes\":"<<meshes<<",\"material_cases\":"<<material_cases<<",\"lookup_cases\":"<<lookup_cases<<",\"original_helper_calls\":"<<calls<<",\"heap_allocations\":"<<heap_allocations<<",\"heap_releases\":"<<heap_releases<<",\"unadmitted_palettes\":"<<unadmitted_palettes<<",\"authored_parts\":"<<authored_parts<<",\"unadmitted_parts\":"<<unadmitted_parts<<",\"game_run\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
