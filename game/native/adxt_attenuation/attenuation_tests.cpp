#include "attenuation.hpp"
#include <cstdio>
#include <cstdlib>
namespace n=reo::native::adxt_attenuation;
unsigned checks{};void check(bool value){++checks;if(!value)std::exit(1);}
int main(){
    std::array<std::uint32_t,n::table_words> words{};words[0]=256;words[1]=200;
    auto opened=n::Table::from_words(words);check(opened.status==n::Status::completed && bool(opened.table));
    check(n::Table::from_words({}).status==n::Status::invalid_table);
    check(n::Table::from_words(std::span(words).first(999)).status==n::Status::invalid_table);
    words[0]=255;check(n::Table::from_words(words).status==n::Status::invalid_table);words[0]=256;
    words.back()=1;check(n::Table::from_words(words).status==n::Status::invalid_table);words.back()=0;
    words[2]=201;check(n::Table::from_words(words).status==n::Status::invalid_table);words[2]=0;
    words[1]=400;check(n::Table::from_words(words).status==n::Status::invalid_table);words[1]=1;
    check(opened.table->apply(0xffffffffu,{}).volume==200); // Retained immutable copy.
    std::printf("%u attenuation table admission/ownership checks passed\n",checks);
}
