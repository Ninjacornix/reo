#include "game/native/gameplay_scenario/script_program.hpp"
#include <fstream>
#include <iostream>
#include <sstream>
#include <stdexcept>

namespace vm=reo::native::gameplay_scenario;
namespace content=vm::content;
int main(int argc,char** argv)try{
    if(argc!=2)throw std::runtime_error("Expected checked owned-bank manifest");
    std::ifstream list(argv[1]);if(!list)throw std::runtime_error("Missing manifest");
    std::cout<<"{\"coverage\":[";bool first=true;
    for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
        if(!first)std::cout<<',';
        first=false;std::cout<<'[';bool first_op=true;
        for(auto op:vm::Interpreter::coverage(profile)){if(!first_op)std::cout<<',';first_op=false;std::cout<<unsigned(op.native_algorithm);}
        std::cout<<']';
    }
    std::cout<<"],\"banks\":[";first=true;std::string line;
    while(std::getline(list,line)){
        std::istringstream row(line);std::string format,path,offset,extent;
        if(!(std::getline(row,format,'\t')&&std::getline(row,path,'\t')&&std::getline(row,offset,'\t')&&std::getline(row,extent,'\t')))
            throw std::runtime_error("Malformed manifest");
        const auto size=std::stoull(extent);if(size>16*1024*1024)throw std::runtime_error("Bank size");
        auto bytes=std::make_shared<std::vector<std::byte>>(size);std::ifstream input(path,std::ios::binary);input.seekg(std::stoll(offset));
        if(!input.read(reinterpret_cast<char*>(bytes->data()),std::streamsize(size)))throw std::runtime_error("Truncated owned bank");
        content::Bytes backing=bytes;
        if(format=="R"){
            const auto section=content::RdtDirectory(backing).section(1);
            backing=section?std::make_shared<const std::vector<std::byte>>(section->begin(),section->end()):nullptr;
        }else if(format!="E")throw std::runtime_error("Bank format");
        if(!first)std::cout<<',';
        first=false;std::cout<<'[';bool first_profile=true;
        for(auto profile:{vm::DispatchProfile::ordinary,vm::DispatchProfile::offline_actor}){
            content::ScriptProgram result;
            if(backing)result=content::admit_script_program(content::ScriptBank(backing,format=="E"?content::BankFormat::scenario_evb:content::BankFormat::room_section),profile);
            if(result.status==content::ScriptAdmission::admitted){
                if(!result.program||result.program->unsupported())throw std::runtime_error("Unsupported admitted program");
                vm::Interpreter interpreter;
                for(unsigned channel=0;channel<2;++channel)if(result.entries[channel]&&interpreter.install(channel,result.program,*result.entries[channel])!=vm::Status::completed)
                    throw std::runtime_error("Program install refused");
            }
            if(!first_profile)std::cout<<',';
            first_profile=false;
            std::cout<<"{\"status\":"<<unsigned(result.status)<<",\"block\":"<<result.failure.block<<",\"offset\":"<<result.failure.offset<<",\"opcode\":"<<result.opcode<<'}';
        }
        std::cout<<']';
    }
    std::cout<<"]}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}
