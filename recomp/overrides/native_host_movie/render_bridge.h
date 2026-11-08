#pragma once
#include "game/native/host_movie/session.hpp"
#include <algorithm>
#include <span>
#include <stdexcept>

namespace reo::native::host_movie_binding {
// Temporary adapter to the unmigrated game renderer's image format. Native
// playback has square pixels/BGRA textures. This conversion restores the old
// renderer's requested pixel grid and 16x16 column order, not its movie decoder,
// queues, clock or transfer workers. Stage5 can remove this entire adapter.
inline void copy_for_legacy_renderer(const host_movie::CpuFrame& source,
    std::uint32_t width,std::uint32_t height,std::span<std::uint8_t> output) {
    if(!width||!height||width>2048||height>2048||source.height>2048||width%16||height%16||width!=source.width||!source.height||source.pitch<std::uint64_t(width)*4||
       source.bgra.size()<std::uint64_t(source.pitch)*(source.height-1)+std::uint64_t(width)*4||output.size()!=std::uint64_t(width)*height*4)
        throw std::invalid_argument("Native movie renderer bridge dimensions");
    const auto denominator=height*2;
    for(std::uint32_t y=0;y<height;++y) {
        const auto scaled=std::int64_t(y*2+1)*source.height-height;
        auto row=scaled<=0?0:static_cast<std::uint32_t>(scaled/denominator);
        const auto fraction=scaled<=0?0:static_cast<std::uint32_t>(scaled%denominator);
        row=std::min(row,source.height-1);const auto next=std::min(row+1,source.height-1);
        for(std::uint32_t x=0;x<width;++x) {
            const auto at=(std::size_t(x/16)*(height/16)+y/16)*1024+((y%16)*16+x%16)*4;
            const auto* a=source.bgra.data()+std::size_t(row)*source.pitch+x*4;
            const auto* b=source.bgra.data()+std::size_t(next)*source.pitch+x*4;
            for(unsigned channel=0;channel<3;++channel)output[at+channel]=static_cast<std::uint8_t>((unsigned(a[2-channel])*(denominator-fraction)+unsigned(b[2-channel])*fraction+denominator/2)/denominator);
            output[at+3]=128;
        }
    }
}
}
