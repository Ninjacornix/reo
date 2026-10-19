"""Freeze diagnostic-only GS copies. Does not compile or run any renderer."""
import argparse, hashlib, json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
HERE=Path(__file__).resolve().parent
OUT=ROOT/'build-ninja/m2-clut-shadow-proposal'
LIB=ROOT/'third_party/ps2recomp/ps2xRuntime/src/lib'
def once(src,old,new,count=1):
    if src.count(old)!=count:raise ValueError(f'Expected {count} anchors: {old[:80]}')
    return src.replace(old,new)
def main():
    ap=argparse.ArgumentParser();ap.add_argument('--refresh',action='store_true');a=ap.parse_args()
    if (OUT/'source-manifest.json').exists() and not a.refresh:raise SystemExit('Frozen; use --refresh explicitly.')
    OUT.mkdir(parents=True,exist_ok=True);manifest={};sources={}
    for name in ('ps2_gs_gpu.cpp','ps2_gs_rasterizer.cpp'):
        raw=(LIB/name).read_bytes();(OUT/(name+'.baseline')).write_bytes(raw)
        manifest[name]={'live_sha256':hashlib.sha256(raw).hexdigest()}
        sources[name]=raw.decode().replace('\r\n','\n')
    gpu=sources['ps2_gs_gpu.cpp']
    gpu=once(gpu,'#include <thread>','#include <thread>\n'+(HERE/'shadow_runtime.inc').read_text())
    start=gpu.index('void GS::reset()');stop=gpu.index('\nvoid GS::snapshotVRAM()',start)
    reset=once(gpu[start:stop],'    std::lock_guard<std::recursive_mutex> lock(m_stateMutex);',
               '    std::lock_guard<std::recursive_mutex> lock(m_stateMutex);\n    clutShadowReset(this);')
    gpu=gpu[:start]+reset+gpu[stop:]
    gpu=once(gpu,'        t.cld = static_cast<uint8_t>((value >> 61) & 0x7);',
                    '        t.cld = static_cast<uint8_t>((value >> 61) & 0x7);\n        clutShadowLoad(this,t,m_texclut,m_vram,m_vramSize);',2)
    raster=sources['ps2_gs_rasterizer.cpp']
    raster=once(raster,'void GSRasterizer::drawPrimitive(GS *gs)',
       '#include "clut_shadow.h"\nbool ps2GsClutShadowEnabled();\nvoid ps2GsClutShadowInspect(const void*,const clut_shadow::Primitive&,const uint8_t*,uint32_t);\n\nvoid GSRasterizer::drawPrimitive(GS *gs)')
    raster=once(raster,'void GSRasterizer::drawPrimitive(GS *gs)\n{\n    const PixelDepthScope primitiveDepth;',
       'void GSRasterizer::drawPrimitive(GS *gs)\n{\n    const PixelDepthScope primitiveDepth;\n'+(HERE/'shadow_primitive.inc').read_text())
    for name,src in [('ps2_gs_gpu.cpp',gpu),('ps2_gs_rasterizer.cpp',raster)]:
        (OUT/name).write_text(src,encoding='utf8',newline='\n')
        manifest[name]['candidate_sha256']=hashlib.sha256((OUT/name).read_bytes()).hexdigest()
    (OUT/'clut_shadow.h').write_bytes((HERE/'clut_shadow.h').read_bytes())
    manifest['diagnostic_only']=True
    manifest['generation_inputs']={p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in (HERE/'clut_shadow.h',HERE/'shadow_runtime.inc',HERE/'shadow_primitive.inc',HERE/'generate.py')}
    manifest['fixtures']={p.name:hashlib.sha256(p.read_bytes()).hexdigest() for p in (HERE/'core.cpp',HERE/'integration.cpp',HERE/'compare.py',HERE/'run.bat',HERE/'README.md')}
    (OUT/'source-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n')
    print(json.dumps(manifest,indent=2))
if __name__=='__main__':main()
