#include "attenuation.hpp"
#include <fstream>
#include <iostream>
#include <stdexcept>
namespace n=reo::native::adxt_attenuation;
int main(int argc,char**argv)try{
    if(argc!=4)return 2;
    std::array<std::uint32_t,n::table_words> words{};std::ifstream table(argv[1],std::ios::binary);
    table.read(reinterpret_cast<char*>(words.data()),sizeof(words));if(!table || table.peek()!=std::char_traits<char>::eof())throw std::runtime_error("Exact table input required");
    const auto prepared=n::Table::from_words(words);if(prepared.status!=n::Status::completed)throw std::runtime_error("Table refused");
    std::ifstream input(argv[2]);std::ofstream output(argv[3]);if(!input || !output)throw std::runtime_error("Plan/output required");
    std::string name;std::uint32_t request,presence,phase,metadata;
    while(input>>name>>request>>presence>>phase>>metadata){
        if(phase>255 || metadata>65535)throw std::runtime_error("Metadata outside declared wire widths");
        const auto result=prepared.table->apply(request,{presence,static_cast<std::uint8_t>(phase),static_cast<std::uint16_t>(metadata)});
        output<<"{\"name\":\""<<name<<"\",\"stored_i16\":"<<result.requested<<",\"rna_i32\":"<<result.clamped<<",\"volume_u32\":"<<result.volume<<"}\n";
    }
    if(!input.eof() || !output)throw std::runtime_error("Incomplete fixture input/output");
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
