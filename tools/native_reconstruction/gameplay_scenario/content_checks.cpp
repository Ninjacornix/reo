#include "game/native/gameplay_scenario/content.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>
#include <string>
namespace c=reo::native::gameplay_scenario::content;
namespace {
unsigned checks{};
void check(bool value){++checks;if(!value)throw std::runtime_error("Content check "+std::to_string(checks));}
void put(std::vector<std::byte>& b,std::size_t at,std::uint32_t value){for(unsigned i=0;i<4;++i)b.at(at+i)=std::byte((value>>(8*i))&255);}
template<class F>void refuses(F fn){bool refused=false;try{fn();}catch(const std::invalid_argument&){refused=true;}check(refused);}
void fixtures(){
    auto b=std::make_shared<std::vector<std::byte>>(512);put(*b,0,0);put(*b,4,10);put(*b,8,0xffffffff);put(*b,12,0);
    c::RdtDirectory directory(b);check(directory.range(0)==c::Range{0,10});check(directory.section(0)->size()==10);check(!directory.range(1));check(!directory.section(32));
    auto bad=std::make_shared<std::vector<std::byte>>(*b);put(*bad,16,0xfffffff0);put(*bad,20,32);refuses([&]{const c::RdtDirectory p(bad);});
    refuses([&]{const c::RdtDirectory p(std::make_shared<const std::vector<std::byte>>(255));});
    auto room=std::make_shared<std::vector<std::byte>>(256);put(*room,0,128);put(*room,4,128);put(*room,32,64);put(*room,36,256);
    const c::ScriptBank bank(room,c::BankFormat::room_section);check(bank.table_size()==16);check(bank.object(0)->bound==c::Range{128,128});check(bank.object(0)->bound==bank.object(1)->bound);
    check(bank.object(8)->role==c::ObjectRole::executable_candidate);check(bank.object(8)->bound==c::Range{64,64});check(bank.object(9)->bound.bytes==0);check(bank.executable_candidates().size()==2);check(!bank.object(16));
    auto evb=std::make_shared<std::vector<std::byte>>(256);put(*evb,0,128);put(*evb,32,160);put(*evb,64,192);put(*evb,96,224);put(*evb,192,128);put(*evb,196,160);put(*evb,200,0);
    put(*evb,136,0x3f000000); // Noncode inside a declared upper bound is retained.
    const c::ScriptBank archive(evb,c::BankFormat::scenario_evb);check(archive.object(0)->bound==c::Range{128,32});check(archive.object(8)->role==c::ObjectRole::configuration_data);
    check(archive.object(24)->role==c::ObjectRole::unknown);check(*archive.indirect_references(16)==std::vector<std::uint32_t>({128,160}));check(!archive.indirect_references(17));
    refuses([&]{archive.indirect_references(0);});refuses([&]{archive.view({0,c::ObjectRole::unknown,{255,2}});});
    auto unterminated=std::make_shared<std::vector<std::byte>>(*evb);for(unsigned at=192;at<224;at+=4)put(*unterminated,at,128);
    refuses([&]{const c::ScriptBank p(unterminated,c::BankFormat::scenario_evb);p.indirect_references(16);});
    auto escaped=std::make_shared<std::vector<std::byte>>(*evb);put(*escaped,0,127);refuses([&]{const c::ScriptBank p(escaped,c::BankFormat::scenario_evb);});
    put(*escaped,0,257);refuses([&]{const c::ScriptBank p(escaped,c::BankFormat::scenario_evb);});
    std::weak_ptr<const std::vector<std::byte>> lease=evb;evb.reset();check(!lease.expired());check(archive.view(*archive.object(0)).size()==32);
}
void probe(const char* manifest){
    std::ifstream list(manifest);if(!list)throw std::runtime_error("Missing content input manifest");std::string line;std::size_t index=0;
    std::cout<<"[";
    while(std::getline(list,line)){
        std::istringstream record(line);std::string kind,path,offset,length;
        if(!std::getline(record,kind,'\t')||!std::getline(record,path,'\t')||!std::getline(record,offset,'\t')||!std::getline(record,length,'\t'))throw std::runtime_error("Invalid content input record");
        const auto at=std::stoull(offset),bytes=std::stoull(length);if(bytes>16*1024*1024)throw std::runtime_error("Content admission extent");
        std::ifstream input(path,std::ios::binary);input.seekg(std::streamoff(at));auto data=std::make_shared<std::vector<std::byte>>(std::size_t(bytes));input.read(reinterpret_cast<char*>(data->data()),std::streamsize(bytes));if(!input||std::size_t(input.gcount())!=bytes)throw std::runtime_error("Truncated owned member");
        if(index)std::cout<<',';
        std::cout<<"{\"index\":"<<index++<<",\"objects\":[";
        c::Bytes bank_bytes=data;bool absent=false;
        if(kind=="R"){
            const c::RdtDirectory rdt(data);const auto section=rdt.section(1);absent=!section;
            if(section)bank_bytes=std::make_shared<const std::vector<std::byte>>(section->begin(),section->end());
        }else if(kind!="E")throw std::runtime_error("Unknown declared content kind");
        if(!absent){const c::ScriptBank bank(bank_bytes,kind=="E"?c::BankFormat::scenario_evb:c::BankFormat::room_section);bool first=true;
            for(std::size_t i=0;i<bank.table_size();++i)if(const auto object=bank.object(i)){
                if(!first)std::cout<<',';
                first=false;
                std::cout<<"{\"table_index\":"<<i<<",\"role\":"<<unsigned(object->role)<<",\"offset\":"<<object->bound.offset<<",\"upper_bound_bytes\":"<<object->bound.bytes;
                if(object->role==c::ObjectRole::indirect_references)std::cout<<",\"indirect_count\":"<<bank.indirect_references(i)->size();
                std::cout<<'}';
            }
        }
        std::cout<<"],\"absent\":"<<(absent?"true":"false")<<'}';
    }
    std::cout<<"]\n";
}
}
int main(int argc,char** argv)try{
    if(argc==2){probe(argv[1]);return 0;}if(argc!=1)throw std::runtime_error("Unsupported content probe arguments");
    fixtures();std::cout<<"{\"status\":\"passed\",\"checks\":"<<checks<<",\"game_launched\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
