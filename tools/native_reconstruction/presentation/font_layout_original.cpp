#include "reference.hpp"
#include "functions.h"
#include "game/native/gameplay_presentation/font_face.hpp"
#include <algorithm>
#include <array>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <stdexcept>
#include <string>
#include <vector>
#include "game/native/gameplay_scenario/system_text_messages.inc"

struct Run {std::int32_t x{},y{},size{};std::uint32_t color{};std::string text;friend bool operator==(const Run&,const Run&)=default;};
static std::int32_t cursor_x{},cursor_y{},size{};
static std::uint32_t color{};
static std::vector<Run> actual;
static bool wide(unsigned c){return (c>=0x80&&c<0xa0)||c>=0xe0;}
static std::uint32_t code(std::uint8_t c){return c<0x60?0x851fu+c:c<0x80?0x8520u+c:c==0xa5?0x85a3u:0x84feu+c;}
static std::uint32_t index(std::uint16_t pair){
    const auto hi=std::uint32_t(pair>>8);auto lo=std::uint32_t(pair&255);
    auto row=(std::uint32_t(std::uint16_t(hi-(hi<0xa0?0x71:0xb1)))*2u+1u)&65535u;
    if(lo>=0x80)--lo;if(lo>=0x9e){lo=(lo-0x7d)&65535u;row=(row+1u)&65535u;}else lo=(lo-0x1f)&65535u;
    const auto translated=(row<<8)|lo;return (((translated>>8)&255u)-0x21u)*94u+((translated&255u)-0x21u);
}
static std::string text_at(std::uint8_t* memory,std::uint32_t address){
    std::string result;while(memory[address]){if(result.size()>1024)throw std::runtime_error("original string bound");result.push_back(char(memory[address++]));}return result;
}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    const auto a=GPR_U32(context,4),b=GPR_U32(context,5);
    switch(context->pc){
    case 0x1b55d0:size=std::int32_t(a);break;
    case 0x1b5640:break;
    case 0x1b5650:color=a;break;
    case 0x1b55f0:cursor_x=std::int32_t(a);cursor_y=std::int32_t(b);break;
    case 0x1b3fa0:sub_001B3FA0_0x1b3fa0(memory,context,runtime);return;
    case 0x10ae78:{const auto left=text_at(memory,a),right=text_at(memory,b);SET_GPR_S32(context,2,left.compare(right));break;}
    case 0x1b6c70:SET_GPR_U32(context,2,text_at(memory,a).size());break;
    case 0x1b56a0:{auto value=text_at(memory,a);actual.push_back({cursor_x,cursor_y,size,color,value});
        for(std::size_t i=0;i<value.size();++i){const auto c=std::uint8_t(value[i]);if(wide(c)&&i+1<value.size()){++i;cursor_x+=size;}else cursor_x+=size/2;}break;}
    default:throw std::runtime_error("Unexpected text-layout boundary");
    }
    context->pc=GPR_U32(context,31);
}
static std::size_t line_units(const std::string& text,std::size_t at){
    std::size_t count=0;while(at<text.size()&&text[at]!='\n'){
        const auto c=std::uint8_t(text[at++]);if(wide(c)){++count;if(at<text.size()){++at;++count;}else break;}
        else if(c=='<'&&at+2<text.size()&&(text[at]=='c'||text[at]=='p')&&text[at+2]=='>')at+=3;
        else ++count;
    }return count;
}
static std::vector<Run> candidate(const std::string& text,std::int32_t x,std::int32_t y,std::int32_t height,std::uint8_t alpha){
    constexpr std::uint32_t palette[]{0,0x80,0x8000,0x800000,0x8080,0x808000,0x8080,0x808080};
    std::vector<Run> result;std::string run;std::int32_t location=x,draw_x=x,draw_y=y;unsigned cindex=7;int center=0;bool positioned=false;
    const auto flush=[&]{if(!run.empty()){result.push_back({draw_x,draw_y,height,(std::uint32_t(alpha)<<24)|palette[cindex],run});run.clear();}};
    std::size_t at=0;
    while(at<text.size()&&text[at]!='\r'){
        if(!positioned&&center){const auto units=line_units(text,at);if(!units)break;location=(640-std::int32_t(units)*(height/2))/2;draw_x=location;draw_y=y;positioned=true;}
        const auto c=std::uint8_t(text[at++]);
        if(c=='\n'){flush();location=x;y+=height;draw_x=location;draw_y=y;positioned=false;continue;}
        if(wide(c)){run.push_back(char(c));if(at>=text.size())break;run.push_back(text[at++]);location+=height;continue;}
        if(c=='<'&&at+2<text.size()&&(text[at]=='c'||text[at]=='p')&&text[at+2]=='>'){
            const auto kind=text[at],value=text[at+1];at+=3;flush();
            if(kind=='c'){if(value<'0'||value>'7')throw std::runtime_error("fixture color bound");cindex=unsigned(value-'0');}
            else center=value-'0';draw_x=location;draw_y=y;continue;
        }
        run.push_back(char(c));location+=height/2;
    }
    flush();return result;
}
int main(){try{
    std::vector<std::uint8_t> memory(0x2000000);constexpr std::uint32_t base=0x10000,stack=0x1fff000;
    reo::native::gameplay_presentation::FontFace face(std::vector<std::byte>(780800));
    constexpr std::uint32_t palette[]{0x80000000,0x80000080,0x80008000,0x80800000,0x80008080,0x80808000,0x80008080,0x80808080};
    std::memcpy(memory.data()+0x234480,palette,sizeof palette);std::memcpy(memory.data()+0x24ff10,"<p >\0\0\0\0<c >",13);
    std::vector<std::string> cases{"Hello world","first\nsecond","<c1>red<c7> white","<p1>center", "<p1>first\nsecond", "A<c2>B<c3>C", "<p0>left", "Wide \x82\x60 test", "\rignored", "<q1>literal"};
    const std::vector<std::string> tokens{"A","9"," ","\n","<p0>","<p1>","<c0>","<c1>","<c2>","<c3>","<c4>","<c5>","<c6>","<c7>","<q1>","\x82\x60"};
    for(std::size_t i=0;i<tokens.size();++i)for(std::size_t j=0;j<tokens.size();++j)
        cases.push_back(tokens[i]+"abc"+tokens[j]+" z");
    for(const auto [offset,length]:system_text_rows){
        if(!length||system_text_bytes[offset+length-1]!=0)throw std::runtime_error("owned system text extent");
        cases.emplace_back(reinterpret_cast<const char*>(system_text_bytes+offset),length-1);
    }
    unsigned checks=0;
    for(const auto& value:cases)for(const auto height:{7,20,31})for(const auto alpha:{0,96,128}){
        const std::int32_t initial_x=height==7?-13:44,initial_y=height==31?447:72;
        std::memcpy(memory.data()+base,value.c_str(),value.size()+1);actual.clear();R5900Context ctx{};PS2Runtime runtime;
        SET_GPR_U32(&ctx,4,initial_x);SET_GPR_U32(&ctx,5,initial_y);SET_GPR_U32(&ctx,6,height);SET_GPR_U32(&ctx,7,base);SET_GPR_U32(&ctx,8,alpha);SET_GPR_U32(&ctx,29,stack);
        sub_001B4100_0x1b4100(memory.data(),&ctx,&runtime);const auto expected=candidate(value,initial_x,initial_y,height,std::uint8_t(alpha));
        if(actual!=expected){std::cerr<<"layout mismatch "<<value<<" source="<<actual.size()<<" candidate="<<expected.size()<<'\n';for(const auto& r:actual)std::cerr<<"source "<<r.x<<','<<r.y<<" color="<<std::hex<<r.color<<std::dec<<" text="<<r.text<<'\n';for(const auto& r:expected)std::cerr<<"candidate "<<r.x<<','<<r.y<<" color="<<std::hex<<r.color<<std::dec<<" text="<<r.text<<'\n';throw std::runtime_error("layout mismatch");}++checks;
        reo::native::gameplay_scenario::CachedText record;record.active=true;record.x=std::int16_t(initial_x);record.y=std::int16_t(initial_y);record.height=std::uint8_t(height);record.alpha=std::uint8_t(alpha);
        if(value.size()>=record.text.size())throw std::runtime_error("fixture text too long");
        std::memcpy(record.text.data(),value.data(),value.size());const auto glyphs=face.layout(record);if(!glyphs)throw std::runtime_error("native layout refused");
        std::vector<reo::native::gameplay_presentation::FontGlyph> reference_glyphs;
        for(const auto& run:actual){auto x=run.x;for(std::size_t n=0;n<run.text.size();++n){
            const auto c=std::uint8_t(run.text[n]);const bool full=wide(c);std::uint32_t pair{};
            if(full){if(n+1>=run.text.size())break;pair=(std::uint32_t(c)<<8)|std::uint8_t(run.text[++n]);}else pair=code(c);
            const auto number=index(std::uint16_t(pair));if(c!=' '&&number<7808)reference_glyphs.push_back({x,run.y,std::uint32_t(run.size),run.color&0xffffffu,number,std::uint8_t(run.color>>24),!full});
            x+=full?run.size:run.size/2;
        }}
        if(*glyphs!=reference_glyphs)throw std::runtime_error("native glyph layout differs from original renderer calls");++checks;
    }
    std::cout<<"{\"cases\":"<<cases.size()<<",\"owned_system_texts\":"<<system_text_rows.size()<<",\"checks\":"<<checks<<",\"game_run\":false}\n";
}catch(const std::exception& e){std::cerr<<e.what()<<'\n';return 1;}}
