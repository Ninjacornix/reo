#include "game/native/gameplay_effects/tracks.hpp"
#include "reference.hpp"
#include "functions.h"
#include "owned_constants.hpp"
#include <fstream>
#include <iostream>
#include <iterator>
#include <source_location>
namespace e=reo::native::gameplay_effects;
unsigned checks{},curve_cases{},transform_cases{},assets{},refusals{},groups{},parts{},calls{};
void check(bool value,std::source_location at=std::source_location::current()){
    ++checks;if(!value)throw std::runtime_error("Effect track check "+std::to_string(checks)+" line "+std::to_string(at.line()));
}
template<class T>T get(const std::uint8_t* memory,std::uint32_t at){return transform_read<T>(memory,at);}
template<class T>void put(std::uint8_t* memory,std::uint32_t at,T value){transform_write(memory,at,value);}
void original_transform_port(std::uint8_t* memory,R5900Context* context,PS2Runtime* runtime){
    ++calls;
    if(context->pc==0x590b10){o2_00590B10_0x590b10(memory,context,runtime);return;}
    throw std::runtime_error("Unadmitted effect track call "+std::to_string(context->pc));
}
#include "original_tracks.cpp"
float sample_original(std::uint8_t* memory,std::uint32_t at,std::int16_t count,std::int16_t time){
    R5900Context c;PS2Runtime runtime;SET_GPR_U32(&c,4,at);SET_GPR_S32(&c,5,time);SET_GPR_S32(&c,6,count);
    SET_GPR_U32(&c,31,0x100);o2_00590B10_0x590b10(memory,&c,&runtime);check(c.pc==0x100);return c.f[0];
}
bool same(float a,float b){return std::bit_cast<std::uint32_t>(a)==std::bit_cast<std::uint32_t>(b);}
void curve_check(std::uint8_t* memory,std::span<const std::byte> body,std::size_t offset,std::int16_t count,std::int16_t time){
    auto curve=e::Curve::import(body,offset,count);const auto actual=curve.sample(time);
    const auto expected=sample_original(memory,0x100000+std::uint32_t(offset),count,time);
    check(same(actual,expected));++curve_cases;
}
int main(int argc,char** argv)try{
    if(argc!=2)throw std::invalid_argument("owned corpus required");
    std::ifstream source(argv[1],std::ios::binary);std::vector<char> package((std::istreambuf_iterator<char>(source)),{});
    check(!package.empty());std::vector<std::uint8_t> ram(0x2000000,0xa5);auto* memory=ram.data();owned_constants(memory);
    std::size_t cursor{};const auto read=[&]<class T>(){if(cursor>package.size()||sizeof(T)>package.size()-cursor)throw std::runtime_error("Corpus truncated");T result;std::memcpy(&result,package.data()+cursor,sizeof result);cursor+=sizeof result;return result;};
    const auto count=read.operator()<std::uint32_t>();check(count==25);
    std::vector<std::byte> valid_asset;
    for(unsigned index=0;index<count;++index){
        const auto size=read.operator()<std::uint32_t>();check(size<=package.size()-cursor);
        std::span<const std::byte> body(reinterpret_cast<const std::byte*>(package.data()+cursor),size);cursor+=size;
        std::memcpy(memory+0x100000,body.data(),body.size());std::shared_ptr<const e::Tracks> tracks;
        try{tracks=e::Tracks::import(body);}catch(const std::invalid_argument& error){check(index==11);++refusals;std::cerr<<"asset "<<index<<" refused: "<<error.what()<<'\n';continue;}
        if(valid_asset.empty())valid_asset.assign(body.begin(),body.end());
        ++assets;groups+=unsigned(tracks->groups().size());
        check(!tracks->resolve(512,0));check(!tracks->group(tracks->groups().size()));
        bool bad_logical{};try{tracks->variants(512);}catch(const std::out_of_range&){bad_logical=true;}check(bad_logical);
        for(unsigned logical=0;logical<512;++logical){
            check(tracks->variants(std::uint16_t(logical))==get<std::int8_t>(memory,0x100200+logical));
            const auto map=get<std::uint8_t>(memory,0x100000+logical);const auto resolved=tracks->resolve(std::uint16_t(logical),0);
            check(map==255?!resolved:resolved&&*resolved==map);
        }
        for(unsigned group=0;group<tracks->groups().size();++group){
            const auto& g=tracks->groups()[group];parts+=unsigned(g.parts.size());
            const auto table=get<std::uint32_t>(memory,0x100400+group*20);
            check(g.lifetime==get<std::int16_t>(memory,0x100400+group*20+18));
            for(unsigned part=0;part<g.parts.size();++part){
                const auto& p=g.parts[part];const auto at=0x100400+table+part*8;
                check(p.resource==memory[at+4]&&p.material==memory[at+5]&&p.selector==memory[at+6]);
                const auto channels=get<std::uint32_t>(memory,at);
                for(unsigned channel=0;channel<p.channels.size();++channel){
                    const auto key_at=0x100400+channels+channel*8;const auto& c=p.channels[channel];
                    check(c.kind==get<std::int16_t>(memory,key_at+6));if(!c.curve)continue;
                    const auto n=get<std::int16_t>(memory,key_at+4);const auto offset=1024+get<std::uint32_t>(memory,key_at);
                    for(const auto time:{std::int16_t(-32768),std::int16_t(-1),std::int16_t(0),std::int16_t(1),std::int16_t(17),std::int16_t(32767)})curve_check(memory,body,offset,n,time);
                }
                for(const auto time:{std::int16_t(-32768),std::int16_t(-1),std::int16_t(0),std::int16_t(1),std::int16_t(2),std::int16_t(7),std::int16_t(17),std::int16_t(33),std::int16_t(127),std::int16_t(32767)}){
                    e::Parameters output{{1.25f,2.5f,-3.75f},{4.25f,5.5f,6.75f},{-123,456,-789,1234}};
                    static_assert(sizeof(output)==32);std::memcpy(memory+0x50000,&output,sizeof output);
                    put(memory,0x20000+0x1f4,std::uint32_t(0x30000));put(memory,0x30000+0x1c,std::uint32_t(0x100400));put(memory,0x20000+0x10,time);
                    R5900Context context;PS2Runtime runtime;SET_GPR_U32(&context,29,0x1f00000);SET_GPR_U32(&context,31,0x100);
                    SET_GPR_U32(&context,4,0x20000);SET_GPR_U32(&context,5,0x50000);SET_GPR_U32(&context,6,group);SET_GPR_U32(&context,7,part);
                    o2_005903E0_0x5903e0(memory,&context,&runtime);check(context.pc==0x100);
                    e::sample_transform(p.channels,time,output);e::Parameters expected;std::memcpy(&expected,memory+0x50000,sizeof expected);
                    check(same(output.scale.x,expected.scale.x));check(same(output.scale.y,expected.scale.y));check(same(output.scale.z,expected.scale.z));
                    check(same(output.translation.x,expected.translation.x));check(same(output.translation.y,expected.translation.y));check(same(output.translation.z,expected.translation.z));
                    check(output.rotation==expected.rotation);++transform_cases;
                }
            }
        }
    }
    check(cursor==package.size());check(assets==24&&refusals==1);
    // Unsorted, repeated, zero/negative counts, extreme signed values and all
    // signed query bit patterns retain the original literal first-greater scan.
    std::array<e::Key,20> keys{};std::uint32_t seed=0x19347a01;
    for(unsigned i=0;i<65536;++i){
        const auto random=[&](){seed=seed*1664525u+1013904223u;return std::bit_cast<std::int16_t>(std::uint16_t(seed>>8));};
        for(auto& key:keys){key.value=random();key.time=random();}
        if(i%3==0)for(unsigned j=0;j<keys.size();++j)keys[j].time=std::int16_t(j/2-5);
        std::memcpy(memory+0x100000,keys.data(),sizeof keys);const auto body=std::as_bytes(std::span(keys));
        const auto n=i%19==0?std::int16_t(-1):std::int16_t(i%19);
        curve_check(memory,body,4,n,std::bit_cast<std::int16_t>(std::uint16_t(i)));
    }
    // Bounds errors must refuse before an asset becomes a usable track owner.
    for(unsigned size=0;size<1044;++size){bool rejected{};try{e::Tracks::import(std::vector<std::byte>(size));}catch(const std::invalid_argument&){rejected=true;}check(rejected);}
    for(unsigned profile=0;profile<4;++profile){
        auto corrupt=valid_asset;const auto write=[&]<class T>(std::size_t at,T value){check(at<=corrupt.size()&&sizeof value<=corrupt.size()-at);std::memcpy(corrupt.data()+at,&value,sizeof value);};
        const auto original_read=[&]<class T>(std::size_t at){T value;std::memcpy(&value,valid_asset.data()+at,sizeof value);return value;};
        const auto first_part=1024+original_read.operator()<std::uint32_t>(1024);
        const auto first_channel=1024+original_read.operator()<std::uint32_t>(first_part);
        if(profile==0)write(1024,UINT32_MAX);
        if(profile==1)write(first_part,UINT32_MAX);
        if(profile==2)write(first_channel,UINT32_MAX);
        if(profile==3){write(first_channel,std::uint32_t(corrupt.size()-1024-2));write(first_channel+4,std::int16_t(100));}
        bool rejected{};try{e::Tracks::import(corrupt);}catch(const std::invalid_argument&){rejected=true;}check(rejected);
    }
    bool no_predecessor{};try{e::Curve::import({},0,0);}catch(const std::invalid_argument&){no_predecessor=true;}check(no_predecessor);
    bool uninitialized{};try{e::Curve{}.sample(0);}catch(const std::logic_error&){uninitialized=true;}check(uninitialized);
    std::cout<<"{\"checks\":"<<checks<<",\"curve_cases\":"<<curve_cases<<",\"transform_cases\":"<<transform_cases<<",\"assets\":"<<assets<<",\"refusals\":"<<refusals<<",\"groups\":"<<groups<<",\"parts\":"<<parts<<",\"original_helper_calls\":"<<calls<<",\"game_run\":false}\n";
    return 0;
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
