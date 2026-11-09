#include "footprint.hpp"
#include "ownership_reference.hpp"
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iterator>
#include <random>
#include <sstream>
namespace c=reo::native::gameplay_collision;
namespace r=c::room_objects;
namespace f=c::footprint;
unsigned checks{},cases{},slide_cases{},rooms{};float maximum_error{};
std::vector<std::uint8_t> memory(0x800000);
void check(bool value,const char* why){++checks;if(!value){std::fprintf(stderr,"footprint check %u failed: %s\n",checks,why);std::exit(1);}}
R5900Context context(std::uint32_t pc){R5900Context ctx;ctx.pc=pc;ctx.g[29].lo=0x7f0000;ctx.g[31].lo=0x1234;return ctx;}
std::uint32_t invoke(std::uint32_t pc,std::uint32_t a0=0,std::uint32_t a1=0,std::uint32_t a2=0){auto ctx=context(pc);ctx.g[4].lo=a0;ctx.g[5].lo=a1;ctx.g[6].lo=a2;PS2Runtime runtime;runtime.lookupFunction(pc)(memory.data(),&ctx,&runtime);return std::uint32_t(ctx.g[2].lo);}
std::vector<std::byte> load(const char* path){std::ifstream file(path,std::ios::binary);const std::vector<char> raw{std::istreambuf_iterator<char>(file),{}};check(!raw.empty(),"owned footprint fixture");const auto bytes=std::as_bytes(std::span(raw));return{bytes.begin(),bytes.end()};}
r::Owner prepare(std::span<const std::byte> types,std::span<const std::byte> sto,std::span<const std::byte> grid,std::uint16_t room){
    auto native=r::Owner::import(types,sto);invoke(0x6acf80);const auto* raw=reinterpret_cast<const std::uint8_t*>(types.data());const auto count=ref_read<std::uint32_t>(raw,4),offset=ref_read<std::uint32_t>(raw,8),models=ref_read<std::uint32_t>(raw,12);if(offset)std::memcpy(memory.data()+0x74b1c0,types.data()+offset,8*count);if(models)std::memcpy(memory.data()+0x74b180,types.data()+models,2*count);
    const auto records=ref_read<std::int32_t>(reinterpret_cast<const std::uint8_t*>(sto.data()),4);for(int i=0;i<records;++i){std::memcpy(memory.data()+0x1000,sto.data()+8+16*std::size_t(i),16);(void)invoke(0x6ad0f0,0x1000);}ref_write(memory.data(),0x3243dc,room);std::memcpy(memory.data()+0x20000,grid.data(),grid.size());invoke(0x6ad860,0x20000);check(native.install_grid(room,grid),"source-admitted room grid installed");return native;
}
void compare(const r::Owner& owner,c::Vec3 proposed,c::Vec3 previous,bool enabled,bool layers){
    memory[0x745d60]=enabled;memory[0x745d58]=layers;ref_write(memory.data(),0x1000,proposed);ref_write(memory.data(),0x1010,previous);ref_write(memory.data(),0x1020,c::Vec3{12345,23456,34567});invoke(0x57c0b0,0x1000,0x1010,0x1020);const auto original=ref_read<c::Vec3>(memory.data(),0x1020);const auto native=f::constrain(owner,proposed,previous,enabled,layers);if(native.status!=f::Status::complete)std::fprintf(stderr,"status%u previous(%g,%g,%g) proposed(%g,%g,%g)\n",unsigned(native.status),double(previous.x),double(previous.y),double(previous.z),double(proposed.x),double(proposed.y),double(proposed.z));check(native.status==f::Status::complete,"defined footprint caller classification available");
    bool failed{};for(const auto pair:{std::pair{native.position.x,original.x},std::pair{native.position.y,original.y},std::pair{native.position.z,original.z}}){const auto error=std::abs(pair.first-pair.second);maximum_error=std::max(maximum_error,error);failed|=error>0.001f;}if(failed)std::fprintf(stderr,"prev(%g,%g,%g) proposed(%g,%g,%g) native(%g,%g,%g) original(%g,%g,%g) passes%u\n",double(previous.x),double(previous.y),double(previous.z),double(proposed.x),double(proposed.y),double(proposed.z),double(native.position.x),double(native.position.y),double(native.position.z),double(original.x),double(original.y),double(original.z),unsigned(native.passes));check(!failed,"original four-pass footprint correction/order");if(native.passes)++slide_cases;check(native.passes<=4,"original bounded movement passes");++cases;
}
void synthetic(){
    std::vector<std::byte> types(26),sto(8+8*16),grid(0x934);const auto word=[](std::vector<std::byte>& b,unsigned at,std::uint32_t value){std::memcpy(b.data()+at,&value,4);};word(types,4,1);word(types,8,16);word(types,12,24);types[16]=std::byte{3};types[17]=std::byte{1};types[18]=std::byte{1};word(sto,0,2);word(sto,4,8);
    for(unsigned i=0;i<8;++i){const auto at=8+16*i;sto[at]=std::byte{1};sto[at+1]=std::byte(i);sto[at+3]=std::byte(10+(i%4)*4);sto[at+4]=std::byte(10+(i/4)*2);}
    word(grid,12,40);word(grid,16,40);auto native=prepare(types,sto,grid,1);std::mt19937 random(0x57c0b0);
    for(unsigned i=0;i<6000;++i){const c::Vec3 previous{450+float(random()%951),100,450+float(random()%301)},proposed{previous.x+float(int(random()%601)-300),100+float(i%2)*10,previous.z+float(int(random()%601)-300)};compare(native,proposed,previous,true,true);}
    compare(native,{600,100,600},{600,100,600},true,true);compare(native,{600,100,650},{600,100,600},true,true);compare(native,{650,100,600},{600,100,600},true,true);compare(native,{700,0,600},{600,0,600},true,false);compare(native,{700,100,600},{600,100,600},false,true);
}
int main(int argc,char** argv){check(argc==3,"footprint manifest/profile arguments");const auto profiles=load(argv[2]);std::memcpy(memory.data()+0x723740,profiles.data(),profiles.size());for(unsigned i=0;i<4;++i)memory[0x719900+i]=std::uint8_t(i*2);synthetic();std::ifstream manifest(argv[1]);std::string line;while(std::getline(manifest,line)){std::istringstream fields(line);std::string types,sto,number,grid;std::getline(fields,types,'\t');std::getline(fields,sto,'\t');std::getline(fields,number,'\t');std::getline(fields,grid);if(types.empty())continue;auto native=prepare(load(types.c_str()),load(sto.c_str()),load(grid.c_str()),std::uint16_t(std::stoi(number)));const auto* g=native.grid();for(const auto& id:native.objects()){const auto* object=native.get(id);if(object->room!=std::uint16_t(std::stoi(number)))continue;const auto center=native.center(*object);for(unsigned i=0;i<30;++i){const c::Vec3 previous{center.x+float(int(i%5)-2)*20,g->origin.y,center.z+float(int(i%3)-1)*25};compare(native,{previous.x+float(int(i%7)-3)*20,previous.y,previous.z+float(int(i%11)-5)*20},previous,true,false);}}++rooms;}check(rooms==7&&slide_cases>100,"stock room coverage and nontrivial elevated sliding");std::printf("{\"checks\":%u,\"maximum_error\":%.9g,\"cases\":%u,\"slide_cases\":%u,\"owned_rooms\":%u,\"game_launched\":false}\n",checks,double(maximum_error),cases,slide_cases,rooms);}
