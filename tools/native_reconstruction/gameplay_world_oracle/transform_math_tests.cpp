#include "game/native/transform_math/transform_math.hpp"
#include "reference.hpp"
#include <cfenv>
#include <iostream>
#include <vector>
namespace t=reo::native::transform_math;
#include "owned_constants.hpp"
std::uint64_t checks{},angle_cases{},trig_cases{},euler_cases{},matrix_cases{},direction_cases{},scale_cases{},provider_calls{};
std::uint64_t wide_trig_cases{};
void check(bool yes,const char* why){++checks;if(!yes)throw std::runtime_error(why);}
template<class T>T get(const std::uint8_t* p,std::uint32_t at){return transform_read<T>(p,at);}
template<class T>void put(std::uint8_t* p,std::uint32_t at,T v){transform_write(p,at,v);}
std::uint32_t random_word(std::uint32_t& x){x^=x<<13;x^=x>>17;x^=x<<5;return x;}
std::vector<std::uint32_t> call_trace;
#include "functions.h"
void original_transform_port(std::uint8_t* m,R5900Context* c,PS2Runtime* r){
    ++provider_calls;call_trace.push_back(c->pc);
    switch(c->pc){
    case 0x18f570:sub_0018F570_0x18f570(m,c,r);break;
    case 0x18fdf0:sub_0018FDF0_0x18fdf0(m,c,r);break;
    case 0x18fe20:sub_0018FE20_0x18fe20(m,c,r);break;
    case 0x18fe60:sub_0018FE60_0x18fe60(m,c,r);break;
    case 0x1902d0:sub_001902D0_0x1902d0(m,c,r);break;
    case 0x190a10:sub_00190A10_0x190a10(m,c,r);break;
    case 0x191300:sub_00191300_0x191300(m,c,r);break;
    case 0x1919d0:sub_001919D0_0x1919d0(m,c,r);break;
    case 0x191f80:sub_00191F80_0x191f80(m,c,r);break;
    case 0x370220:o0_00370220_0x370220(m,c,r);break;
    case 0x370320:o0_00370320_0x370320(m,c,r);break;
    default:throw std::runtime_error("unexecuted merged transform entry reached");
    }
}
#include "original_transforms.cpp"
constexpr std::uint32_t matrix_at=0x10000,other_at=0x11000,vector_at=0x12000,result_at=0x13000;
R5900Context context(std::uint32_t at){R5900Context c;c.pc=at;SET_GPR_U32(&c,29,0x30000);SET_GPR_U32(&c,31,0xabcdef);return c;}
void returned(const R5900Context& c){check(c.pc==0xabcdef && GPR_U32(&c,29)==0x30000,"complete original helper returns with intact stack");}
void same(float a,float b){check(std::bit_cast<std::uint32_t>(a)==std::bit_cast<std::uint32_t>(b),"transform differs at float-bit precision");}
void same(const t::Matrix& a,const t::Matrix& b){for(unsigned col=0;col<4;++col)for(unsigned lane=0;lane<4;++lane)same(a[col][lane],b[col][lane]);}
void same(t::Vector a,t::Vector b){same(a.x,b.x);same(a.y,b.y);same(a.z,b.z);}
int main()try{
    const auto previous_mxcsr=_mm_getcsr();struct Reset{unsigned value;~Reset(){_mm_setcsr(value);}} reset{previous_mxcsr};_mm_setcsr(0x1f80);
    std::vector<std::uint8_t> memory(0x2000000,0xa5);owned_constants(memory.data());put(memory.data(),0x294e00,t::identity());PS2Runtime runtime;
    check(std::bit_cast<std::uint32_t>(t::identity()[3][3])==0x3f800000,"admitted initialized identity profile");std::uint32_t random=0x18f570;
    for(unsigned turn=0;turn<65536;++turn){
        auto c=context(0x191f80);SET_GPR_U32(&c,4,turn);sub_00191F80_0x191f80(memory.data(),&c,&runtime);returned(c);const auto angle=t::radians(std::uint16_t(turn));same(angle,c.f[0]);++angle_cases;
        c=context(0x18f570);SET_GPR_U32(&c,4,result_at);c.f[12]=angle;sub_0018F570_0x18f570(memory.data(),&c,&runtime);returned(c);const auto result=t::sin_cos(angle);const auto expected=get<std::array<float,4>>(memory.data(),result_at);same(result.sine,expected[0]);same(result.cosine,expected[1]);same(expected[2],0);same(expected[3],0);++trig_cases;
    }
    for(unsigned i=0;i<8192;++i){
        const float angle=i<4?std::array<float,4>{-6.2831854820251465f,-3.1415927410125732f,3.1415927410125732f,6.2831854820251465f}[i]:float(std::int32_t(random_word(random)%131073)-65536)*(6.2831854820251465f/65536.0f);
        auto c=context(0x18f570);SET_GPR_U32(&c,4,result_at);c.f[12]=angle;sub_0018F570_0x18f570(memory.data(),&c,&runtime);returned(c);const auto expected=get<std::array<float,4>>(memory.data(),result_at);const auto result=t::sin_cos(angle);same(result.sine,expected[0]);same(result.cosine,expected[1]);++trig_cases;
    }
    for(auto bits:{0u,0x80000000u,1u,0x80000001u,0x00800000u,0x80800000u,0x3fc90fdau,0x3fc90fdbu,0x3fc90fdcu,0xbfc90fdau,0xbfc90fdbu,0xbfc90fdcu,0x40490fdau,0x40490fdcu,0xc0490fdau,0xc0490fdcu}){
        const auto angle=std::bit_cast<float>(bits);auto c=context(0x18f570);SET_GPR_U32(&c,4,result_at);c.f[12]=angle;sub_0018F570_0x18f570(memory.data(),&c,&runtime);returned(c);const auto expected=get<std::array<float,4>>(memory.data(),result_at);const auto result=t::sin_cos(angle);same(result.sine,expected[0]);same(result.cosine,expected[1]);++trig_cases;
    }
    const auto compare_wide=[&](float angle){
        auto c=context(0x18f570);SET_GPR_U32(&c,4,result_at);c.f[12]=angle;sub_0018F570_0x18f570(memory.data(),&c,&runtime);returned(c);
        const auto expected=get<std::array<float,4>>(memory.data(),result_at);const auto result=t::sin_cos(angle);same(result.sine,expected[0]);same(result.cosine,expected[1]);++wide_trig_cases;
    };
    for(int period=-32765;period<=32765;++period){const auto center=float(period)*std::bit_cast<float>(0x40490fdbu);
        for(const auto angle:{std::nextafter(center,-INFINITY),center,std::nextafter(center,INFINITY)})compare_wide(angle);
    }
    for(unsigned i=0;i<65536;++i)compare_wide(float(std::int32_t(random_word(random)%3200001)-1600000)*.0625f);
    const auto number=[&]{return float(std::int32_t(random_word(random)%16385)-8192)*.125f;};
    for(unsigned turn=0;turn<65536;++turn){
        t::Matrix initial;for(auto& col:initial)for(auto& lane:col)lane=number();
        // These fields are not arithmetic inputs of either Euler operation.
        if(turn<16){initial[1][3]=std::bit_cast<float>(0x7f800001u+turn);initial[3][1]=std::bit_cast<float>(0xffc00000u+turn);}
        const t::Angles angles{std::uint16_t(turn),std::uint16_t(turn*257+19),std::uint16_t(turn*251+32768)};
        for(bool compose:{false,true}){
            put(memory.data(),matrix_at,initial);auto c=context(compose?0x370220:0x370320);SET_GPR_S32(&c,4,std::int16_t(angles[0]));SET_GPR_S32(&c,5,std::int16_t(angles[1]));SET_GPR_S32(&c,6,std::int16_t(angles[2]));SET_GPR_U32(&c,7,matrix_at);call_trace.clear();
            if(compose)o0_00370220_0x370220(memory.data(),&c,&runtime);else o0_00370320_0x370320(memory.data(),&c,&runtime);returned(c);
            const std::vector<std::uint32_t> expected_calls=compose?std::vector<std::uint32_t>{0x191f80,0x191f80,0x191f80,0x190a10,0x18f570,0x18f570,0x18f570}:std::vector<std::uint32_t>{0x191f80,0x191f80,0x191f80,0x1902d0,0x18fe20,0x18f570,0x18f570,0x18f570};
            check(call_trace==expected_calls,"complete Euler/helper call order");auto actual=initial;if(compose)t::compose_euler_axes(actual,angles);else t::reset_euler_axes(actual,angles);same(actual,get<t::Matrix>(memory.data(),matrix_at));++euler_cases;
        }
    }
    for(unsigned i=0;i<4096;++i){
        t::Matrix a,b;for(auto& col:a)for(auto& lane:col)lane=number();for(auto& col:b)for(auto& lane:col)lane=number();
        put(memory.data(),matrix_at,a);put(memory.data(),other_at,b);auto c=context(0x191300);SET_GPR_U32(&c,4,matrix_at);SET_GPR_U32(&c,5,i&1?matrix_at:other_at);sub_00191300_0x191300(memory.data(),&c,&runtime);returned(c);auto actual=a;t::concatenate_left(actual,i&1?actual:b);same(actual,get<t::Matrix>(memory.data(),matrix_at));++matrix_cases;
        const t::Vector v{number(),number(),number()};put(memory.data(),vector_at,v);put(memory.data(),matrix_at,a);c=context(0x1919d0);SET_GPR_U32(&c,4,result_at);SET_GPR_U32(&c,5,vector_at);SET_GPR_U32(&c,6,matrix_at);sub_001919D0_0x1919d0(memory.data(),&c,&runtime);returned(c);same(t::direction(a,v),get<t::Vector>(memory.data(),result_at));++direction_cases;
        c=context(0x18fe60);SET_GPR_U32(&c,4,result_at);c.f[12]=v.x;c.f[13]=v.y;c.f[14]=v.z;sub_0018FE60_0x18fe60(memory.data(),&c,&runtime);returned(c);same(t::scale(v),get<t::Matrix>(memory.data(),result_at));++scale_cases;
    }
    bool refused{};try{(void)t::sin_cos(INFINITY);}catch(const std::domain_error&){refused=true;}check(refused,"nonfinite trig input refused");
    refused=false;try{(void)t::sin_cos(200000);}catch(const std::domain_error&){refused=true;}check(refused,"unqualified winding-wrap range refused before integer conversion");
    const auto before=t::identity();auto next=before;next[0][0]=INFINITY;const auto invalid=next;refused=false;try{t::compose_euler_axes(next,{1,2,3});}catch(const std::domain_error&){refused=true;}check(refused && std::memcmp(&invalid,&next,sizeof next)==0,"invalid composition leaves destination unpublished");
    _mm_setcsr(0x3f80);refused=false;try{(void)t::radians(1);}catch(const std::domain_error&){refused=true;}check(refused,"nonnearest profile explicitly refused");_mm_setcsr(0x1f80);
    for(auto control:{0x9f80u,0x1fc0u}){_mm_setcsr(control);refused=false;try{(void)t::radians(1);}catch(const std::domain_error&){refused=true;}check(refused,"flush/denormal-zero profile explicitly refused");}_mm_setcsr(0x1f80);
    next=before;auto large=before;next[0][0]=large[0][0]=std::numeric_limits<float>::max();const auto original_large=next;refused=false;try{t::concatenate_left(next,large);}catch(const std::domain_error&){refused=true;}check(refused && std::memcmp(&next,&original_large,sizeof next)==0,"overflow result rejected before matrix publication");
    std::cout<<"{\"checks\":"<<checks<<",\"angle_cases\":"<<angle_cases<<",\"trig_cases\":"<<trig_cases<<",\"wide_trig_cases\":"<<wide_trig_cases<<",\"euler_cases\":"<<euler_cases<<",\"matrix_cases\":"<<matrix_cases<<",\"direction_cases\":"<<direction_cases<<",\"scale_cases\":"<<scale_cases<<",\"original_helper_calls\":"<<provider_calls<<",\"original_body_executed\":true,\"game_run\":false}\n";
}catch(const std::exception& error){std::cerr<<error.what()<<'\n';return 1;}
