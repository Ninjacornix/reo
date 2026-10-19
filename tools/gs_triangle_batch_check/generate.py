"""Freeze private GS copies; no compilation or execution. No game code bytes."""
import argparse,hashlib,json,pathlib,re
ROOT=pathlib.Path(__file__).resolve().parents[2]
HERE=pathlib.Path(__file__).resolve().parent
OUT=ROOT/'build-ninja/m2-gs-triangle-batch'
LIB=ROOT/'third_party/ps2recomp/ps2xRuntime/src/lib'

def replace_once(s,old,new):
    if s.count(old)!=1:raise ValueError('Expected unique source anchor '+old[:100])
    return s.replace(old,new,1)

def function(s,signature):
    start=s.index(signature);a=s.index('{',start)
    masked=re.sub(r'//[^\n]*|/\*.*?\*/|"(?:\\.|[^"\\])*"',lambda m:' '*len(m[0]),s,flags=re.S)
    depth=0
    for i in range(a,len(s)):
        depth+=(masked[i]=='{')-(masked[i]=='}')
        if not depth:return start,i+1
    raise ValueError('Unclosed '+signature)

def main():
    ap=argparse.ArgumentParser();ap.add_argument('--refresh',action='store_true');args=ap.parse_args()
    OUT.mkdir(parents=True,exist_ok=True)
    if (OUT/'source-manifest.json').exists() and not args.refresh:raise SystemExit('Frozen copies exist; explicit --refresh required.')
    manifest={}
    sources={}
    for name in ['ps2_gs_gpu.cpp','ps2_gs_rasterizer.cpp']:
        raw=(LIB/name).read_bytes();sources[name]=raw.decode('utf8').replace('\r\n','\n')
        (OUT/(name+'.baseline')).write_bytes(raw)
        manifest[name]={'live_sha256':hashlib.sha256(raw).hexdigest()}
    raster=sources['ps2_gs_rasterizer.cpp'];gpu=sources['ps2_gs_gpu.cpp']
    raster=replace_once(raster,'#include <optional>','#include <optional>\n#include <climits>')
    raster=raster.replace('namespace\n{','namespace\n{\n'+(HERE/'batch_private.inc').read_text(),1)
    a,b=function(raster,'    bool triangleParallelSafe(')
    safe=raster[a:b].replace('triangleParallelSafe(', 'triangleBatchSafe(',1)
    safe=safe.replace('uint64_t(maxX) >= width * 64u || maxY - minY < 16 ||\n            uint64_t(maxX - minX + 1) * uint64_t(maxY - minY + 1) < 32768u ||',
                      'ctx.frame.fbw == 0u || uint64_t(maxX) >= width * 64u ||')
    if '32768u' in safe or 'maxY - minY < 16' in safe:raise ValueError('Size gate removal failed')
    raster=raster[:b]+'\n'+safe+raster[b:]
    hooks='''
void ps2GsTriangleBatchBegin(GS* gs) {
    if(!triangleBatchEnabled())return;
    auto& b=t_triangleBatch;
    if(b.depth)flushTriangleBatch(b.owner);
    else b.owner=gs;
    ++b.depth;
}
void ps2GsTriangleBatchEnd(GS* gs) {
    if(!triangleBatchEnabled())return;
    auto& b=t_triangleBatch;
    if(b.depth==1&&b.owner==gs)flushTriangleBatch(gs);
    if(b.depth&&!--b.depth) {b.owner=nullptr;b.count=0;b.render={};}
}
void ps2GsTriangleBatchBarrier(GS* gs) {if(triangleBatchEnabled())flushTriangleBatch(gs);}
uint64_t ps2GsTriangleBatchStat(unsigned index) {
    return index==0?s_batchParallel.load():index==1?s_batchParallelTriangles.load():s_batchSerialTriangles.load();
}
void ps2GsTriangleBatchTestCancelAfterRows(uint64_t rows) {
    s_batchTestRows=0;s_batchTestCancelled=false;s_batchTestRowLimit=rows;
}
'''
    raster=replace_once(raster,'void GSRasterizer::drawPrimitive(GS *gs)',hooks+'\nvoid GSRasterizer::drawPrimitive(GS *gs)')
    raster=replace_once(raster,'    case GS_PRIM_TRIFAN:\n        drawTriangle(gs);',
                       '    case GS_PRIM_TRIFAN:\n'+(HERE/'batch_collect.inc').read_text())
    # Non-triangle primitive must flush before any of its destination accesses.
    raster=replace_once(raster,'void GSRasterizer::drawPrimitive(GS *gs)\n{\n    const PixelDepthScope primitiveDepth;',
        'void GSRasterizer::drawPrimitive(GS *gs)\n{\n    const PixelDepthScope primitiveDepth;\n    if(gs->m_prim.type!=GS_PRIM_TRIANGLE&&gs->m_prim.type!=GS_PRIM_TRISTRIP&&gs->m_prim.type!=GS_PRIM_TRIFAN)\n        ps2GsTriangleBatchBarrier(gs);')
    a,b=function(raster,'void GSRasterizer::drawTriangle(GS *gs)')
    triangle=raster[a:b]
    triangle=triangle.replace('    const GSVertex &v0 = gs->m_vtxQueue[0];',
        '    const GSVertex* triangleVertices=t_batchVertices?t_batchVertices:gs->m_vtxQueue;\n    const GSVertex &v0 = triangleVertices[0];',1)
    triangle=triangle.replace('gs->m_vtxQueue[1]','triangleVertices[1]').replace('gs->m_vtxQueue[2]','triangleVertices[2]')
    triangle=triangle.replace('gs->m_prim, gs->m_vtxQueue','gs->m_prim, triangleVertices')
    triangle=triangle.replace('const bool parallel = parallelEnabled &&','const bool parallel = !t_batchVertices && parallelEnabled &&',1)
    triangle=replace_once(triangle,'            if (ps2GsWorkerStopRequested()) return;',
        '            if (ps2GsWorkerStopRequested() || triangleBatchTestCancelRow()) return;')
    triangle=replace_once(triangle,'    else\n        band(minY, maxY);',
        '    else\n        band(t_batchRowClip?std::max(minY,t_batchY0):minY, t_batchRowClip?std::min(maxY,t_batchY1):maxY);')
    raster=raster[:a]+triangle+raster[b:]
    gpu=replace_once(gpu,'void GS::processGIFPacket(const uint8_t *data, uint32_t sizeBytes)',
'''void ps2GsTriangleBatchBegin(GS*);
void ps2GsTriangleBatchEnd(GS*);
void ps2GsTriangleBatchBarrier(GS*);
namespace {
struct GsTrianglePacketScope {
    GS* gs;
    explicit GsTrianglePacketScope(GS* value):gs(value){ps2GsTriangleBatchBegin(gs);}
    ~GsTrianglePacketScope(){ps2GsTriangleBatchEnd(gs);}
};
bool batchVertexRegister(uint8_t reg) {
    return reg==GS_REG_RGBAQ||reg==GS_REG_ST||reg==GS_REG_UV||reg==GS_REG_XYZF2||
           reg==GS_REG_XYZ2||reg==GS_REG_FOG||reg==GS_REG_XYZF3||reg==GS_REG_XYZ3;
}
}
void GS::processGIFPacket(const uint8_t *data, uint32_t sizeBytes)''')
    a,b=function(gpu,'void GS::processGIFPacket(')
    packet=gpu[a:b]
    packet=replace_once(packet,'    g_gsPacketsAccepted.fetch_add(1, std::memory_order_relaxed);',
        '    const GsTrianglePacketScope trianglePacket(this);\n    g_gsPacketsAccepted.fetch_add(1, std::memory_order_relaxed);')
    gpu=gpu[:a]+packet+gpu[b:]
    a,b=function(gpu,'void GS::writeRegisterPacked(')
    packed=gpu[a:b]
    packed=replace_once(packed,'    switch (regDesc)',
        '    if(regDesc!=1&&regDesc!=2&&regDesc!=3&&regDesc!=4&&regDesc!=5&&regDesc!=0xA&&regDesc!=0xC&&regDesc!=0xD)\n        ps2GsTriangleBatchBarrier(this);\n    switch (regDesc)')
    gpu=gpu[:a]+packed+gpu[b:]
    a,b=function(gpu,'void GS::writeRegister(uint8_t')
    reg=gpu[a:b]
    reg=replace_once(reg,'    std::lock_guard<std::recursive_mutex> lock(m_stateMutex);',
        '    std::lock_guard<std::recursive_mutex> lock(m_stateMutex);\n    if(!batchVertexRegister(regAddr))ps2GsTriangleBatchBarrier(this);')
    gpu=gpu[:a]+reg+gpu[b:]
    # Barrier declared early for captures/reset/transfer methods before parser.
    gpu=replace_once(gpu,'void GS::init(uint8_t *vram, uint32_t vramSize, GSRegisters *privRegs)',
        'void ps2GsTriangleBatchBarrier(GS*);\n\nvoid GS::init(uint8_t *vram, uint32_t vramSize, GSRegisters *privRegs)')
    for signature in ['void GS::reset()', 'void GS::snapshotVRAM()', 'void GS::refreshDisplaySnapshot()',
       'void GS::latchHostPresentationFrame()', 'void GS::performLocalToLocalTransfer()',
       'void GS::processImageData(', 'void GS::performLocalToHostToBuffer()',
       'bool GS::clearFramebufferContext(', 'bool GS::clearActiveFramebuffer(',
       'uint32_t GS::consumeLocalToHostBytes(']:
        a,b=function(gpu,signature);brace=gpu.index('{',a)
        gpu=gpu[:brace+1]+'\n    ps2GsTriangleBatchBarrier(this);'+gpu[brace+1:]
    for name,s in [('ps2_gs_gpu.cpp',gpu),('ps2_gs_rasterizer.cpp',raster)]:
        (OUT/name).write_text(s,encoding='utf8',newline='\n')
        manifest[name]['candidate_sha256']=hashlib.sha256((OUT/name).read_bytes()).hexdigest()
    (OUT/'source-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf8')
    print(json.dumps(manifest,indent=2))

if __name__=='__main__':main()
