#include "raster.hpp"
#include "../gameplay_scenario/fog.hpp"
#include "font_face.hpp"
#include <algorithm>
#include <array>
#include <bit>
#include <cmath>
#include <limits>
#include <stdexcept>

namespace reo::native::gameplay_presentation {
namespace {
using Matrix=transform_math::Matrix;
using V4=std::array<float,4>;
V4 transform(const Matrix& matrix,V4 v){
    V4 out{};for(unsigned row=0;row<4;++row)for(unsigned col=0;col<4;++col)out[row]+=matrix[col][row]*v[col];return out;
}
bool finite(const Matrix& m){for(const auto& col:m)for(float x:col)if(!std::isfinite(x))return false;return true;}
struct Projected {float x{},y{},z{},reciprocal{},u{},v{},fog{};V4 color;};
struct ClipVertex {V4 clip;float u{},v{},fog{};V4 color;};
float edge(const Projected& a,const Projected& b,float x,float y){return (x-a.x)*(b.y-a.y)-(y-a.y)*(b.x-a.x);}
}
std::optional<RasterFog> prepare_scene_fog(const gameplay_scenario::FogState& source)noexcept{
    RasterFog value;value.near_distance=source.near_distance;value.far_distance=source.far_distance;
    if(!std::isfinite(value.near_distance)||!std::isfinite(value.far_distance))return std::nullopt;
    // 6B1660 publishes far+1 when the two source distances compare equal.
    if(value.far_distance==value.near_distance)value.far_distance+=1.f;
    if(!std::isfinite(value.far_distance)||value.far_distance==value.near_distance||
       !std::isfinite(value.far_distance-value.near_distance))return std::nullopt;
    for(unsigned i=0;i<3;++i){
        const auto adjustment=std::bit_cast<std::int8_t>(source.flash[i]);
        value.color[i]=std::uint8_t(std::clamp(int(source.color[i])+int(adjustment),0,255));
    }
    return value;
}
std::optional<std::uint8_t> fog_factor(float clip_w,const RasterFog& fog)noexcept{
    const float range=fog.far_distance-fog.near_distance;
    if(!std::isfinite(clip_w)||!std::isfinite(range)||range==0)return std::nullopt;
    const float inverse_range=1.f/range;
    const float factor=(fog.far_distance-clip_w)*inverse_range;
    if(!std::isfinite(factor))return std::nullopt;
    return std::uint8_t(std::clamp(factor*255.f,0.f,255.f));
}
Raster::Raster(std::uint32_t width,std::uint32_t height):width_(width),height_(height){
    if(!width||!height||width>4096||height>4096)throw std::invalid_argument("Invalid presentation extent");
    pixels_.resize(std::size_t(width)*height);depth_.resize(pixels_.size());clear();
}
void Raster::viewport(const gameplay_scenario::CameraViewport& viewport,const gameplay_scenario::CameraProjectionMatrices& matrices){
    if(viewport.width<=0||viewport.height<=0||!finite(matrices.perspective))throw std::invalid_argument("Invalid presentation projection");
    projection_=matrices.perspective;has_projection_=true;
}
void Raster::view(const Matrix& matrix){if(!finite(matrix))throw std::invalid_argument("Invalid presentation view");view_=matrix;has_view_=true;}
bool Raster::global_alpha(float alpha)noexcept{if(!std::isfinite(alpha)||alpha<0||alpha>1)return false;global_alpha_=alpha;return true;}
bool Raster::fog(std::optional<RasterFog> fog)noexcept{
    if(fog&&(!std::isfinite(fog->near_distance)||!std::isfinite(fog->far_distance)||
             fog->near_distance==fog->far_distance||!std::isfinite(fog->far_distance-fog->near_distance)))return false;
    fog_=fog;return true;
}
void Raster::clear(std::uint32_t argb)noexcept{std::fill(pixels_.begin(),pixels_.end(),argb);std::fill(depth_.begin(),depth_.end(),std::numeric_limits<float>::infinity());font_emitted_=0;}
bool Raster::text(const FontFace& face,std::span<const FontGlyph> glyphs)noexcept{
    constexpr std::array<int,4> alpha{0,42,85,128}; // first palette at MAIN234510
    for(const auto& glyph:glyphs){
        const auto bitmap=face.bitmap(glyph.index);if(bitmap.size()!=100)return false;
        const auto glyph_width=glyph.half_width?glyph.size/2:glyph.size;
        const auto draw=[&](int offset,bool shadow){
            const float left=float(glyph.x+offset)*float(width_)/640.f,top=float(glyph.y+offset)*float(height_)/448.f;
            const float right=float(glyph.x+offset+int(glyph_width))*float(width_)/640.f;
            const float bottom=float(glyph.y+offset+int(glyph.size))*float(height_)/448.f;
            const int x0=std::max(0,int(std::floor(left))),y0=std::max(0,int(std::floor(top)));
            const int x1=std::min(int(width_),int(std::ceil(right))),y1=std::min(int(height_),int(std::ceil(bottom)));
            if(right<=left||bottom<=top)return;
            for(int y=y0;y<y1;++y)for(int x=x0;x<x1;++x){
                const float fx=(float(x)+.5f-left)/(right-left),fy=(float(y)+.5f-top)/(bottom-top);
                if(fx<0||fx>=1||fy<0||fy>=1)continue;
                const auto col=std::min(unsigned(fx*float(glyph.half_width?10:20)),glyph.half_width?9u:19u);
                const auto row=std::min(unsigned(fy*20.f),19u),pixel=row*20+col;
                const auto packed=std::to_integer<unsigned>(bitmap[pixel/4]);
                const int a=alpha[(packed>>(6-2*(pixel%4)))&3]*int(glyph.alpha)/128;if(!a)continue;
                auto& target=pixels_[std::size_t(y)*width_+std::size_t(x)];const auto previous=target;
                const auto blend=[&](unsigned source_shift,unsigned target_shift){
                    const int source=shadow?0:std::min(255,int((glyph.rgb>>source_shift)&255u)*240/128);
                    const int dest=int((previous>>target_shift)&255u);
                    return unsigned(std::clamp((source*a+dest*(128-a))/128,0,255));
                };
                target=0xff000000u|(blend(0,16)<<16)|(blend(8,8)<<8)|blend(16,0);
            }
        };
        //1B4D40 configures512 slots for this source font.1B56A0 counts the
        // shadow and foreground separately, including an offscreen emission.
        if(font_emitted_>=512)break;
        draw(2,true);++font_emitted_;
        if(font_emitted_>=512)break;
        draw(0,false);++font_emitted_;
    }
    return true;
}
void Raster::rectangle(std::int32_t x,std::int32_t y,std::int32_t width,std::int32_t height,std::uint32_t argb)noexcept{
    if(width<=0||height<=0)return;
    const auto raw=unsigned(argb>>24),alpha=raw==255?128u:raw?std::max(1u,raw>>1):0u;if(!alpha)return;
    const auto x0=int(std::floor(std::clamp(float(x)*float(width_)/640.f,0.f,float(width_))));
    const auto y0=int(std::floor(std::clamp(float(y)*float(height_)/448.f,0.f,float(height_))));
    const auto x1=int(std::ceil(std::clamp(float(std::int64_t(x)+width)*float(width_)/640.f,0.f,float(width_))));
    const auto y1=int(std::ceil(std::clamp(float(std::int64_t(y)+height)*float(height_)/448.f,0.f,float(height_))));
    for(int py=y0;py<y1;++py)for(int px=x0;px<x1;++px){
        auto& value=pixels_[std::size_t(py)*width_+std::size_t(px)];const auto previous=value;
        const auto blend=[&](unsigned shift){return (((argb>>shift)&255)*alpha+((previous>>shift)&255)*(128-alpha))/128;};
        value=0xff000000u|(blend(16)<<16)|(blend(8)<<8)|blend(0);
    }
}
void Raster::triangle(const SurfaceVertex& a,const SurfaceVertex& b,const SurfaceVertex& c,const Texture& texture){
    if(!ready()||!texture.width||!texture.height||texture.rgba.size()!=std::size_t(texture.width)*texture.height*4)throw std::invalid_argument("Presentation resources unavailable");
    const std::array source{a,b,c};std::vector<ClipVertex> polygon;polygon.reserve(9);
    for(const auto& vertex:source){const auto clip=transform(projection_,transform(view_,{vertex.world.x,vertex.world.y,vertex.world.z,1}));
        if(!std::all_of(clip.begin(),clip.end(),[](float x){return std::isfinite(x);})||!std::isfinite(vertex.u)||!std::isfinite(vertex.v)||
           !std::all_of(vertex.color.begin(),vertex.color.end(),[](float x){return std::isfinite(x);}))return;
        float fog=255.f;
        if(fog_){
            // The reached VU program uses the signed reciprocal of clip W.
            // In this native projection W has the opposite sign; the bounded
            // scalar factor below matches the captured finite profile.
            const auto factor=fog_factor(clip[3],*fog_);
            if(!factor)throw std::invalid_argument("Native fog numeric profile unavailable");
            fog=float(*factor);
        }
        polygon.push_back({clip,vertex.u,vertex.v,fog,vertex.color});}
    // Clip all six homogeneous frustum planes before perspective division.
    // Interpolate texture coordinates in clip space; pixel interpolation later
    // uses the reciprocal-W correction for the new vertices as well.
    for(unsigned plane=0;plane<6&&!polygon.empty();++plane){
        const auto distance=[plane](const ClipVertex& v){return v.clip[3]+(plane&1?-v.clip[plane/2]:v.clip[plane/2]);};
        std::vector<ClipVertex> next;next.reserve(polygon.size()+1);
        auto previous=polygon.back();float prev_distance=distance(previous);
        for(const auto& current:polygon){const float current_distance=distance(current);const bool in=current_distance>=0,prev_in=prev_distance>=0;
            if(in!=prev_in){const float factor=prev_distance/(prev_distance-current_distance);ClipVertex crossing{};
                for(unsigned j=0;j<4;++j)crossing.clip[j]=previous.clip[j]+factor*(current.clip[j]-previous.clip[j]);
                crossing.u=previous.u+factor*(current.u-previous.u);crossing.v=previous.v+factor*(current.v-previous.v);
                crossing.fog=previous.fog+factor*(current.fog-previous.fog);
                for(unsigned j=0;j<4;++j)crossing.color[j]=previous.color[j]+factor*(current.color[j]-previous.color[j]);next.push_back(crossing);}
            if(in)next.push_back(current);previous=current;prev_distance=current_distance;
        }polygon=std::move(next);
    }
    if(polygon.size()<3)return;
    for(std::size_t triangle=1;triangle+1<polygon.size();++triangle){
    const std::array clipped{polygon[0],polygon[triangle],polygon[triangle+1]};std::array<Projected,3> p{};bool invalid=false;
    for(unsigned i=0;i<3;++i){const auto& vertex=clipped[i];if(vertex.clip[3]<=0){invalid=true;break;}
        const float inverse=1.f/vertex.clip[3],x=vertex.clip[0]*inverse,y=vertex.clip[1]*inverse;
        p[i]={(x*.5f+.5f)*float(width_),(.5f-y*.5f)*float(height_),vertex.clip[2]*inverse,inverse,vertex.u,vertex.v,vertex.fog,vertex.color};}
    if(invalid)continue;
    const float area=edge(p[0],p[1],p[2].x,p[2].y);if(!std::isfinite(area)||std::fabs(area)<0.00001f)continue;
    const float minx=std::max(0.f,std::floor(std::min({p[0].x,p[1].x,p[2].x}))),maxx=std::min(float(width_-1),std::ceil(std::max({p[0].x,p[1].x,p[2].x})));
    const float miny=std::max(0.f,std::floor(std::min({p[0].y,p[1].y,p[2].y}))),maxy=std::min(float(height_-1),std::ceil(std::max({p[0].y,p[1].y,p[2].y})));
    if(minx>maxx||miny>maxy)continue;
    for(int y=int(miny);y<=int(maxy);++y)for(int x=int(minx);x<=int(maxx);++x){
        const float px=float(x)+.5f,py=float(y)+.5f;
        const float wa=edge(p[1],p[2],px,py)/area,wb=edge(p[2],p[0],px,py)/area,wc=1.f-wa-wb;
        if(wa<0||wb<0||wc<0)continue;
        const float z=wa*p[0].z+wb*p[1].z+wc*p[2].z;const auto at=std::size_t(y)*width_+std::size_t(x);if(z>=depth_[at])continue;
        const float q=wa*p[0].reciprocal+wb*p[1].reciprocal+wc*p[2].reciprocal;if(q<=0)continue;
        const float u=(wa*p[0].u*p[0].reciprocal+wb*p[1].u*p[1].reciprocal+wc*p[2].u*p[2].reciprocal)/q;
        const float v=(wa*p[0].v*p[0].reciprocal+wb*p[1].v*p[1].reciprocal+wc*p[2].v*p[2].reciprocal)/q;
        if(!std::isfinite(u)||!std::isfinite(v))continue;
        const auto tx=std::min(std::uint32_t((u-std::floor(u))*texture.width),std::uint32_t(texture.width-1));
        const auto ty=std::min(std::uint32_t((v-std::floor(v))*texture.height),std::uint32_t(texture.height-1));
        V4 color{};for(unsigned j=0;j<4;++j){
            color[j]=std::clamp((wa*p[0].color[j]*p[0].reciprocal+wb*p[1].color[j]*p[1].reciprocal+wc*p[2].color[j]*p[2].reciprocal)/q,0.f,1.f);
        }
        const auto ti=(std::size_t(ty)*texture.width+tx)*4;const auto alpha=unsigned(float(texture.rgba[ti+3])*color[3]*global_alpha_);if(!alpha)continue;
        const auto old=pixels_[at];const auto blend=[&](unsigned channel,unsigned shift){
            auto source=unsigned(float(texture.rgba[ti+channel])*color[channel]);
            if(fog_){const auto f=unsigned(std::clamp(wa*p[0].fog+wb*p[1].fog+wc*p[2].fog,0.f,255.f));
                source=(source*f+unsigned(fog_->color[channel])*(255-f))/255;}
            return (source*alpha+((old>>shift)&255)*(255-alpha))/255;};
        pixels_[at]=0xff000000u|(blend(0,16)<<16)|(blend(1,8)<<8)|blend(2,0);depth_[at]=z;
    }
    }
}
}
