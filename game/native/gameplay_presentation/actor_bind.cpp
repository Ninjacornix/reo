#include "actor_bind.hpp"
#include <cmath>
#include <cstring>
#include <algorithm>
#include <stdexcept>
namespace reo::native::gameplay_presentation {
namespace {
using Bytes=std::span<const std::byte>;using Matrix=transform_math::Matrix;
template<class T>T read(Bytes data,std::size_t at){if(at>data.size()||sizeof(T)>data.size()-at)throw std::invalid_argument("Truncated actor bind pose");T value;std::memcpy(&value,data.data()+at,sizeof value);return value;}
float f(Bytes bytes,std::size_t at){const auto value=read<float>(bytes,at);if(!std::isfinite(value))throw std::invalid_argument("Nonfinite actor bind pose");return value;}
Matrix inverse(const Matrix& source){
    double rows[4][8]{};for(unsigned r=0;r<4;++r)for(unsigned c=0;c<4;++c){rows[r][c]=source[c][r];rows[r][c+4]=r==c?1:0;}
    for(unsigned col=0;col<4;++col){unsigned pivot=col;for(unsigned row=col+1;row<4;++row)if(std::fabs(rows[row][col])>std::fabs(rows[pivot][col]))pivot=row;
        if(std::fabs(rows[pivot][col])<1e-12)throw std::invalid_argument("Singular actor bind matrix");
        if(pivot!=col)for(unsigned j=0;j<8;++j)std::swap(rows[pivot][j],rows[col][j]);
        const double divisor=rows[col][col];for(auto& value:rows[col])value/=divisor;
        for(unsigned row=0;row<4;++row)if(row!=col){const double factor=rows[row][col];for(unsigned j=0;j<8;++j)rows[row][j]-=factor*rows[col][j];}
    }
    Matrix result{};for(unsigned r=0;r<4;++r)for(unsigned c=0;c<4;++c){result[c][r]=float(rows[r][c+4]);if(!std::isfinite(result[c][r]))throw std::invalid_argument("Invalid actor inverse bind matrix");}return result;
}
}
std::vector<Matrix> actor_inverse_bind(Bytes bytes){
    const auto begin=read<std::uint32_t>(bytes,0x24),size=read<std::uint32_t>(bytes,0x28);
    if(!begin||size<12||begin>bytes.size()||size>bytes.size()-begin)throw std::invalid_argument("Actor bind hierarchy unavailable");
    const auto data=bytes.subspan(begin,size);const auto records=read<std::uint32_t>(data,4),length=read<std::uint32_t>(data,8);
    if(length!=size||records<2||records>129)throw std::invalid_argument("Actor bind hierarchy profile unavailable");
    std::vector<Matrix> poses,inverses;poses.reserve(records-1);inverses.reserve(records-1);std::size_t at=12;
    for(std::uint32_t ordinal=0;ordinal<records;++ordinal){
        const auto type=read<std::uint32_t>(data,at),count=read<std::uint32_t>(data,at+4),extent=read<std::uint32_t>(data,at+8);
        if(extent<12||at>data.size()||extent>data.size()-at)throw std::invalid_argument("Actor bind node extent unavailable");
        if(!(type&255)){if(ordinal||!count||count>(extent-12)/4||read<std::uint32_t>(data,at+12)!=0)throw std::invalid_argument("Actor bind root unavailable");at+=extent;continue;}
        if(count!=1||extent<76||(type!=0x40000001u&&type!=0x40000003u))throw std::invalid_argument("Actor bind node profile unavailable");
        const auto p=at+12;const auto index=read<std::int32_t>(data,p),parent=read<std::int32_t>(data,p+4);
        if(index!=std::int32_t(poses.size())||parent< -1||parent>=index)throw std::invalid_argument("Actor bind node order unavailable");
        float sx=f(data,p+16),sy=f(data,p+20),sz=f(data,p+24),qx=f(data,p+32),qy=f(data,p+36),qz=f(data,p+40),qw=f(data,p+44);
        if(sx==0||sy==0||sz==0)throw std::invalid_argument("Actor bind scale unavailable");
        if(type==0x40000003u){sx=1/sx;sy=1/sy;sz=1/sz;qx=-qx;qy=-qy;qz=-qz;}
        const float length2=qx*qx+qy*qy+qz*qz+qw*qw;if(!std::isfinite(length2)||length2<=0.0001f)throw std::invalid_argument("Actor bind quaternion unavailable");
        const float q=1/std::sqrt(length2);qx*=q;qy*=q;qz*=q;qw*=q;
        Matrix m=transform_math::identity();
        m[0][0]=sx*(1-2*(qy*qy+qz*qz));m[0][1]=sx*2*(qx*qy+qz*qw);m[0][2]=sx*2*(qx*qz-qy*qw);
        m[1][0]=sy*2*(qx*qy-qz*qw);m[1][1]=sy*(1-2*(qx*qx+qz*qz));m[1][2]=sy*2*(qy*qz+qx*qw);
        m[2][0]=sz*2*(qx*qz+qy*qw);m[2][1]=sz*2*(qy*qz-qx*qw);m[2][2]=sz*(1-2*(qx*qx+qy*qy));
        m[3][0]=f(data,p+48);m[3][1]=f(data,p+52);m[3][2]=f(data,p+56);
        if(parent>=0)transform_math::concatenate_left(m,poses[std::size_t(parent)]);
        poses.push_back(m);inverses.push_back(inverse(m));at+=extent;
    }
    if(at!=size||poses.size()!=records-1)throw std::invalid_argument("Incomplete actor bind hierarchy");return inverses;
}
}
