#pragma once
// Command metadata only. None of these functions inspect vertex storage.
#include "gs_util.hpp"
#include <algorithm>
#include <vector>

namespace ParallelGS::ResidentMaterialDomain {
inline bool colorFormat(uint32_t psm) {
    return psm==PSMCT32 || psm==PSMCT24 || psm==PSMCT16 || psm==PSMCT16S;
}
inline bool depthFormat(uint32_t psm) {return psm==0 || psm==1 || psm==2 || psm==0xa;}
inline bool textureFormat(uint32_t psm) {return colorFormat(psm) || psm==PSMT8 || psm==PSMT4;}
inline bool paletteFormat(uint32_t psm) {return psm==PSMCT32 || psm==PSMCT16 || psm==PSMCT16S;}
struct Bounds {uint32_t x=0,y=0,width=0,height=0,tilesX=0,tilesY=0;};
inline bool bounds(const SCISSORBits &s,uint32_t fbw,Bounds &b) {
    // FBW=0 and PS2 row wrapping have distinct geometry semantics. They remain
    // outside this tier. Scissor is an inclusive literal command rectangle.
    if(!fbw || s.SCAX0>s.SCAX1 || s.SCAY0>s.SCAY1 || s.SCAX1>=fbw*64u) return false;
    b.x=uint32_t(s.SCAX0)&~15u;b.y=uint32_t(s.SCAY0)&~15u;
    b.tilesX=(uint32_t(s.SCAX1)>>4)-(uint32_t(s.SCAX0)>>4)+1;
    b.tilesY=(uint32_t(s.SCAY1)>>4)-(uint32_t(s.SCAY0)>>4)+1;
    b.width=b.tilesX*16;b.height=b.tilesY*16;
    return b.x+b.width<=fbw*64u && b.x+b.width<=2048 && b.y+b.height<=2048;
}
inline bool pageOverlap(const PageRect &a,const PageRect &b,uint32_t pages) {
    if(!pages)return true;
    std::vector<uint8_t> visited(pages,0);
    for(uint32_t y=0;y<a.page_height;++y)for(uint32_t x=0;x<a.page_width;++x)
        visited[(a.base_page+y*a.page_stride+x)%pages]=1;
    for(uint32_t y=0;y<b.page_height;++y)for(uint32_t x=0;x<b.page_width;++x)
        if(visited[(b.base_page+y*b.page_stride+x)%pages])return true;
    return false; // Conservative whole-page overlap; masked sharing not admitted.
}
template<class Context> inline PageRect colorPages(const Context &ctx,const Bounds &b) {
    auto rect=compute_page_rect(ctx.frame.desc.FBP*PGS_BLOCKS_PER_PAGE,b.x,b.y,b.width,b.height,
                                ctx.frame.desc.FBW,ctx.frame.desc.PSM);
    rect.write_mask&=~ctx.frame.desc.FBMSK;return rect;
}
template<class Context> inline PageRect depthPages(const Context &ctx,const Bounds &b) {
    return compute_page_rect(ctx.zbuf.desc.ZBP*PGS_BLOCKS_PER_PAGE,b.x,b.y,b.width,b.height,
                             ctx.frame.desc.FBW,ctx.zbuf.desc.PSM|ZBUFBits::PSM_MSB);
}
enum Reason : uint32_t {
    Topology=1u<<0,FST=1u<<1,AA1=1u<<2,ScanMask=1u<<3,Dither=1u<<4,
    ColorClamp=1u<<5,ColorPSM=1u<<6,DepthPSM=1u<<7,ScissorOrWrap=1u<<8,
    SameBase=1u<<9,TexturePSM=1u<<10,TextureDimensions=1u<<11,Mipmap=1u<<12,
    PalettePSM=1u<<13,ColorDepthPages=1u<<14
};
template<class Registers> inline uint32_t commandReasons(const Registers &r) {
    const auto &p=r.prim.desc;const auto &c=r.ctx[p.CTXT];uint32_t reasons=0;Bounds b{};
    if(p.PRIM!=4)reasons|=Topology;if(p.FST)reasons|=FST;if(p.AA1)reasons|=AA1;
    if(r.scanmsk.desc.has_mask())reasons|=ScanMask;if(r.dthe.desc.DTHE)reasons|=Dither;
    if(!r.colclamp.desc.CLAMP)reasons|=ColorClamp;
    if(!colorFormat(c.frame.desc.PSM))reasons|=ColorPSM;
    if(!depthFormat(c.zbuf.desc.PSM))reasons|=DepthPSM;
    if(!bounds(c.scissor.desc,c.frame.desc.FBW,b))reasons|=ScissorOrWrap;
    if(c.frame.desc.FBP==c.zbuf.desc.ZBP)reasons|=SameBase;
    if(p.TME){
        if(!textureFormat(c.tex0.desc.PSM))reasons|=TexturePSM;
        if(c.tex0.desc.TW>10 || c.tex0.desc.TH>10)reasons|=TextureDimensions;
        if(c.tex1.desc.mmin_has_mipmap())reasons|=Mipmap;
        if((c.tex0.desc.PSM==PSMT8 || c.tex0.desc.PSM==PSMT4) && !paletteFormat(c.tex0.desc.CPSM))reasons|=PalettePSM;
    }
    return reasons;
}
template<class Instance,class Context> inline bool matches(const Instance &i,const Context &c,const Bounds &b,bool sensitive) {
    return i.fb.frame.desc.compat(c.frame.desc) && i.fb.z.desc.compat(c.zbuf.desc) &&
        i.base_x==b.x && i.base_y==b.y && i.coarse_tiles_width==b.tilesX && i.coarse_tiles_height==b.tilesY &&
        i.opaque_fbmask==c.frame.desc.FBMSK && i.z_sensitive==sensitive &&
        i.z_write==(sensitive && c.zbuf.desc.ZMSK==0);
}
template<class Instance> inline bool instanceBounds(const Instance &i) {
    return colorFormat(i.fb.frame.desc.PSM) && depthFormat(i.fb.z.desc.PSM) &&
        i.fb.frame.desc.FBW && !(i.base_x&15u) && !(i.base_y&15u) &&
        i.coarse_tiles_width && i.coarse_tiles_height && i.coarse_tiles_width<=128 && i.coarse_tiles_height<=128 &&
        i.base_x<=2047 && i.base_y<=2047 && i.base_x+i.coarse_tiles_width*16<=2048 &&
        i.base_y+i.coarse_tiles_height*16<=2048 && i.base_x+i.coarse_tiles_width*16<=i.fb.frame.desc.FBW*64u;
}
} // namespace ParallelGS::ResidentMaterialDomain
