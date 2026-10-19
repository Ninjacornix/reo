"""Freeze an isolated counter candidate and extend the existing full-VRAM oracle."""
from pathlib import Path
import hashlib

root = Path(__file__).resolve().parents[2]
out = root / 'build-ninja/m2-gs-counters'
out.mkdir(parents=True, exist_ok=True)
source = (root / 'third_party/PS2Recomp/ps2xRuntime/src/lib/ps2_gs_rasterizer.cpp').read_text()
(out / 'baseline.cpp').write_text(source)
def replace_once(text, old, new):
    assert text.count(old) == 1, (old[:90], text.count(old))
    return text.replace(old, new, 1)
candidate = replace_once(source, 'namespace\n{\n    struct TriangleProbeCounts', '''// Existing heartbeat counters; pixel loops aggregate them per triangle band.
extern std::atomic<uint32_t> g_pxCalls, g_pxScissor, g_pxAlpha;

namespace
{
    struct TriangleProbeCounts''')
candidate = replace_once(candidate, '    struct TriangleProbeCounts', '''    struct TrianglePixelCounters { uint32_t calls=0, scissor=0, alpha=0; };
    thread_local TrianglePixelCounters* t_trianglePixelCounters=nullptr;
    struct TrianglePixelCounterScope {
        TrianglePixelCounters counters;
        TrianglePixelCounters* previous=t_trianglePixelCounters;
        TrianglePixelCounterScope() { t_trianglePixelCounters=&counters; }
        ~TrianglePixelCounterScope() {
            t_trianglePixelCounters=previous;
            if(counters.calls) g_pxCalls.fetch_add(counters.calls,std::memory_order_relaxed);
            if(counters.scissor) g_pxScissor.fetch_add(counters.scissor,std::memory_order_relaxed);
            if(counters.alpha) g_pxAlpha.fetch_add(counters.alpha,std::memory_order_relaxed);
        }
    };

    struct TriangleProbeCounts''')
for member, symbol in [('calls','g_pxCalls'),('scissor','g_pxScissor'),('alpha','g_pxAlpha')]:
    candidate = replace_once(candidate, f'{symbol}.fetch_add(1, std::memory_order_relaxed);',
        f'if(t_trianglePixelCounters) ++t_trianglePixelCounters->{member};\n    else {symbol}.fetch_add(1, std::memory_order_relaxed);')
candidate = replace_once(candidate, '    auto band = [&](int yBegin, int yEnd) {',
    '    auto band = [&](int yBegin, int yEnd) {\n        const TrianglePixelCounterScope pixelCounters;')
(out / 'candidate.cpp').write_text(candidate)
for name in ('baseline', 'candidate'):
    print(name, hashlib.sha256((out / (name+'.cpp')).read_bytes()).hexdigest())

fixture = (root / 'tools/gs_triangle_parallel_check/main.cpp').read_text()
fixture = replace_once(fixture, 'if(dump){dump.write', 'if(dump.is_open()){dump.write')
fixture = replace_once(fixture, 'namespace {', '''extern std::atomic<uint32_t> g_pxCalls, g_pxScissor, g_pxAlpha;
namespace {''')
fixture = replace_once(fixture, '        setup(c);triangle(c);if(c.sequence)triangle(c,300);', '''        setup(c);
        g_pxCalls.store(0xFFFFFFF0u);g_pxScissor.store(0xFFFFFFF0u);g_pxAlpha.store(0xFFFFFFF0u);
        triangle(c);if(c.sequence)triangle(c,300);
        std::printf("COUNTERS %u %s %u %u %u\\n",caseIndex,c.name.c_str(),
            g_pxCalls.load(),g_pxScissor.load(),g_pxAlpha.load());''')
fixture = replace_once(fixture, '    if(bench){Case c;', '''    // Independent atomic fallback controls outside triangle-band scope.
    {Case c;c.textured=false;setup(c);g_pxCalls.store(0);g_pxScissor.store(0);g_pxAlpha.store(0);
        gs.writeRegister(GS_REG_PRIM,GS_PRIM_POINT);
        gs.writeRegister(GS_REG_RGBAQ,New|(uint64_t(bits(1.0f))<<32));
        gs.writeRegister(GS_REG_XYZ2,(64ull*16)|((64ull*16)<<16)|(200ull<<32));
        check("point fallback counters",g_pxCalls.load()==1 && g_pxScissor.load()==0 && g_pxAlpha.load()==0);
        gs.writeRegister(GS_REG_XYZ2,(1023ull*16)|((1023ull*16)<<16)|(200ull<<32));
        check("point outside scissor counters",g_pxCalls.load()==2 && g_pxScissor.load()==1);
        gs.writeRegister(GS_REG_PRIM,GS_PRIM_LINE);
        gs.writeRegister(GS_REG_XYZ2,(64ull*16)|((64ull*16)<<16)|(200ull<<32));
        gs.writeRegister(GS_REG_XYZ2,(67ull*16)|((64ull*16)<<16)|(200ull<<32));
        check("line fallback counters",g_pxCalls.load()==6 && g_pxScissor.load()==1);
    }
    if(bench){Case c;''')
(root / 'tools/gs_counter_check/main.cpp').write_text(fixture)
