#pragma once
#include "resident_material_domain.hpp"
#include <array>
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iomanip>
#include <map>
#include <mutex>
#include <sstream>

namespace ParallelGS::ResidentMaterialDomain {
// Effective command state only. TEX2 is merged by original GS handlers into
// TEX0; ContextState has no independent TEX2. RGBAQ/ST/UV/FOG/XYZ and internal
// Q are deliberately absent. The function never maps a GPU buffer or image.
class Recorder {
    bool enabled_=false;std::ofstream out_;std::mutex mutex_;
    std::map<std::array<uint64_t,23>,uint64_t> counts_;
    uint64_t ordinal_=0;uint32_t uniqueLimit_=512;
public:
    Recorder() noexcept {
        try {
            const char *path=std::getenv("REO_GPU_GS_MATERIAL_DOMAIN_DIR");
            if(!path || !*path)return;
            const std::filesystem::path dir(path);
            if(std::filesystem::exists(dir) || !std::filesystem::create_directories(dir))return;
            out_.open(dir/"command-domains.jsonl",std::ios::out);if(!out_)return;
            out_<<"{\"type\":\"schema\",\"version\":1,\"scope\":\"reached-ordinary-triangle-strip-command-state\",\"pixel_readbacks\":0,\"vertex_readbacks\":0,\"waits\":0,\"unique_limit\":512,\"names\":[\"PRIM\",\"FRAME\",\"ZBUF\",\"TEX0_effective\",\"TEX1\",\"CLAMP\",\"SCISSOR\",\"XYOFFSET\",\"TEST\",\"ALPHA\",\"FBA\",\"PRMODECONT\",\"TEXA\",\"TEXCLUT\",\"FOGCOL\",\"PABE\",\"DTHE\",\"DIMX\",\"COLCLAMP\",\"SCANMSK\",\"instances\",\"hazards\",\"command_reasons\"]}\n";
            enabled_=true;
        }catch(...){enabled_=false;}
    }
    template<class Registers> void observe(const Registers &r,uint32_t instances,uint32_t hazards,
                                           uint32_t ordinaryPrimitives,uint32_t queuedVertices,
                                           uint32_t vramPages,bool zSensitive) noexcept {
        if(!enabled_ || r.prim.desc.PRIM!=4)return;
        try {
            const auto &c=r.ctx[r.prim.desc.CTXT];uint32_t reasons=commandReasons(r);Bounds b{};
            if(zSensitive && !(reasons&(ColorPSM|DepthPSM|ScissorOrWrap)) && bounds(c.scissor.desc,c.frame.desc.FBW,b) &&
               pageOverlap(colorPages(c,b),depthPages(c,b),vramPages))reasons|=ColorDepthPages;
            const std::array<uint64_t,23> words{r.prim.bits,c.frame.bits,c.zbuf.bits,c.tex0.bits,c.tex1.bits,
                c.clamp.bits,c.scissor.bits,c.xyoffset.bits,c.test.bits,c.alpha.bits,c.fba.bits,
                r.prmodecont.bits,r.texa.bits,r.texclut.bits,r.fogcol.bits,r.pabe.bits,r.dthe.bits,r.dimx.bits,
                r.colclamp.bits,r.scanmsk.bits,instances,hazards,reasons};
            std::lock_guard<std::mutex> guard(mutex_);++ordinal_;
            auto it=counts_.find(words);
            if(it==counts_.end()){
                if(counts_.size()>=uniqueLimit_)return;
                it=counts_.emplace(words,0).first;
            }
            const auto count=++it->second;
            // Bounded logarithmic frequency rows avoid unbounded per-kick IO.
            if(count!=1 && ((count&(count-1))!=0 || count>65536))return;
            out_<<"{\"type\":\"command\",\"ordinal\":"<<ordinal_<<",\"occurrences\":"<<count
                <<",\"ordinary_primitive_queue\":"<<ordinaryPrimitives<<",\"vertex_queue_count\":"<<queuedVertices
                <<",\"vram_pages\":"<<vramPages<<",\"z_sensitive\":"<<(zSensitive?"true":"false")<<",\"words\":[";
            for(size_t i=0;i<words.size();++i){if(i)out_<<',';out_<<'"'<<std::hex<<std::setw(16)<<std::setfill('0')<<words[i]<<'"';}
            out_<<std::dec<<"]}\n";out_.flush();
        }catch(...){} // Optional diagnostics cannot change guest execution.
    }
};
template<class Registers> inline void record(const Registers &r,uint32_t instances,uint32_t hazards,
                                              uint32_t primitives,uint32_t vertices,uint32_t vramPages,bool zSensitive) noexcept {
    static Recorder recorder;recorder.observe(r,instances,hazards,primitives,vertices,vramPages,zSensitive);
}
} // namespace ParallelGS::ResidentMaterialDomain
