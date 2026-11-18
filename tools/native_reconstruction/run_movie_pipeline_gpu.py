#!/usr/bin/env python3
"""Offscreen video ownership check using an explicitly supplied sealed build kit.

No private build-folder defaults, package mutation, game/audio launch or runtime
dependency edits. The File #1 slice is read from the user's imported data and
verified by its independently inventoried payload hash before decoder use.
"""
import argparse
import hashlib
import json
import os
from pathlib import Path
import subprocess
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-pipeline'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
SOURCES=['context.cpp','video_frames.cpp','audio_commands.cpp','buffering.cpp']
LIBRARIES=['libgranite-vulkan.a','libgranite-util.a','libgranite-math.a','libgranite-volk.a','libfmt.a']

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--kit',type=Path,required=True);p.add_argument('--toolchain',type=Path,required=True);p.add_argument('--data',type=Path,required=True);p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args()
    kit=args.kit.resolve();out=args.output.resolve();toolchain=args.toolchain.resolve();data=args.data.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned output required')
    seal=json.loads((kit/'build-kit.json').read_bytes());files={row['path']:row['sha256'] for row in seal['files']};plan_path=kit/'compile-plan.json'
    if sha(plan_path)!=files['compile-plan.json']:raise ValueError('Sealed compile plan drift')
    plan=json.loads(plan_path.read_bytes());compiler=toolchain/plan['compiler'].removeprefix('{kit}/toolchain/')
    if not plan.get('externalToolchain') or sha(compiler)!=plan['externalCompilerSha256']:raise ValueError('Exact external compiler required')
    dependency_hashes={}
    prefix='source/build-ninja/parallel-gs-source/'
    for name,digest in files.items():
        if (name.startswith(prefix) and Path(name).suffix in ['.h','.hpp','.inl','.def']) or name in ['libraries/'+lib for lib in LIBRARIES]:
            if sha(kit/name)!=digest:raise ValueError('Sealed dependency drift '+name)
            dependency_hashes[name]=digest
    for lib in LIBRARIES:
        if 'libraries/'+lib not in dependency_hashes:raise ValueError('Missing sealed library '+lib)
    with (data/'NETBIO01.DAT').open('rb') as f:f.seek(710572032);payload=f.read(299008)
    if hashlib.sha256(payload).hexdigest()!='f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb':raise ValueError('Owned PS2continue.sfd payload identity')
    unit=next(u for u in plan['units'] if any('movie_owner_service.cpp' in name for name in u['sources']));flags=[]
    for option in unit['options']:
        if option.startswith('/I'):flags.append('-I'+option[2:].replace('{work}/project',str(kit/'source')))
        elif option.startswith('/D'):flags.append('-D'+option[2:])
        elif option!='/fp:precise':raise ValueError('Unhandled sealed GPU option '+option)
    flags += ['-I'+str(kit/'source/build-ninja/parallel-gs-source/Granite')]
    out.mkdir(parents=True);(out/'owned-program-stream.sfd').write_bytes(payload)
    core=ROOT/'game/native/movie_timestamp';manifest=json.loads((core/'manifest.json').read_bytes());core_hashes=manifest['files']
    def drift():return [name for name,digest in core_hashes.items() if sha(ROOT/name)!=digest]
    if drift():raise ValueError('Native source drift '+str(drift()))
    owned=[Path(__file__),ROOT/'tools/native_reconstruction/movie_pipeline_gpu_check.cpp']+[ROOT/'tools/parallel_gs_backend/movie_runtime'/name for name in ['native_video_graph.h','native_frame_surface.h','same_owner_movie_bridge.h','mpeg2_vld_core.h','mpeg2_stream.h','movie_picture_identity.h','import_receipt.h','movie_asset_sha256.h','assets/movie_ipu_csc_nv12.spv','import_receipt.cpp']]
    hashes={str(path.relative_to(ROOT)):sha(path) for path in owned};env=dict(os.environ);env['PATH']=str(compiler.parent)+os.pathsep+env.get('PATH','')
    record=dict(status='running',compiler=str(compiler),compiler_sha256=sha(compiler),kit_manifest_sha256=sha(kit/'build-kit.json'),compile_plan_sha256=sha(plan_path),sealed_dependency_hashes=dependency_hashes,native_manifest_sha256=sha(core/'manifest.json'),sources=hashes,owned_payload_sha256=hashlib.sha256(payload).hexdigest(),checks=[],game_run=False,audio_device_opened=False,visible_window_created=False)
    def run(label,command,timeout=90):
        value=subprocess.run([str(v) for v in command],capture_output=True,text=True,env=env,timeout=timeout);(out/(label+'.txt')).write_text(value.stdout+value.stderr,encoding='utf-8');record['checks'].append(dict(label=label,exit=value.returncode,command=[str(v) for v in command]))
        if value.returncode:raise ValueError(label+' failed; see '+str(out/(label+'.txt')))
        return value.stdout
    try:
        native=json.loads(args.native_receipt.read_bytes())
        if native['manifest_sha256']!=sha(core/'manifest.json') or native['compiler_sha256']!=sha(compiler) or native['status']!='native media pipeline standalone build and tests passed':raise ValueError('Exact native build receipt required')
        native_libraries=[]
        for name,digest in native['libraries'].items():
            path=ROOT/name
            if sha(path)!=digest:raise ValueError('Native library drift '+name)
            native_libraries.append(path)
        if not native_libraries:raise ValueError('Native library cohort absent')
        record['native_build_receipt_sha256']=sha(args.native_receipt)
        record['native_library_hashes']=native['libraries']
        objects=[]
        fixture=out/'gpu.o';run('gpu-compile',[compiler,'-std=c++20','-O1','-ffp-contract=off','-I'+str(ROOT),*flags,'-c',ROOT/'tools/native_reconstruction/movie_pipeline_gpu_check.cpp','-o',fixture])
        allocator=next(u for u in plan['units'] if u['id']=='movieAllocatorNative')
        allocator_source=Path(allocator['sources'][0].replace('{work}/project',str(kit/'source')))
        relative=allocator_source.relative_to(kit).as_posix()
        if relative not in files or sha(allocator_source)!=files[relative]:raise ValueError('Reviewed allocator provider source drift')
        provider_flags=[]
        for option in allocator['options']:
            if option.startswith('/I'):provider_flags.append('-I'+option[2:].replace('{work}/project',str(kit/'source')))
            elif option.startswith('/D'):provider_flags.append('-D'+option[2:])
            elif option!='/fp:precise':raise ValueError('Unhandled reviewed allocator option')
        provider=out/'reviewed-allocator.o';run('reviewed-allocator-compile',[compiler,'-std=c++20','-O2','-I'+str(ROOT/'tools/parallel_gs_backend'),*provider_flags,'-c',allocator_source,'-o',provider]);objects.append(provider)
        receipt_object=out/'import-receipt.o';run('import-receipt-compile',[compiler,'-std=c++20','-O2','-c',ROOT/'tools/parallel_gs_backend/movie_runtime/import_receipt.cpp','-o',receipt_object]);objects.append(receipt_object)
        record['reviewed_allocator_source_sha256']=sha(allocator_source)
        binary=out/'gpu_check.exe';run('gpu-link',[compiler,*objects,fixture,'-Wl,--start-group',*native_libraries,*[kit/'libraries'/lib for lib in LIBRARIES],'-Wl,--end-group',*['-l'+lib for lib in ['d3d11','dxgi','dxguid','user32','gdi32','winmm','bcrypt','ole32','uuid','shell32','advapi32','ws2_32','dwmapi']],'-o',binary])
        stdout=run('gpu-run',[binary,out/'owned-program-stream.sfd',ROOT/'tools/parallel_gs_backend/movie_runtime/assets/movie_ipu_csc_nv12.spv'],timeout=60)
        result=json.loads(next(line for line in reversed(stdout.splitlines()) if line.startswith('{')))
        if result['status']!='real GPU media pipeline checks passed' or not result['renderer_fence_blocked_rebuild']:raise ValueError('Incomplete real GPU proof')
        if drift() or any(sha(ROOT/name)!=digest for name,digest in hashes.items()):raise ValueError('Source changed during GPU check')
        record.update(status='real offscreen native movie pipeline qualified',result=result,binary_sha256=sha(binary))
    except Exception as error:record.update(status='failed',failure=str(error));raise
    finally:
        record['outputs_sha256']={f.name:sha(f) for f in out.iterdir() if f.is_file() and f.suffix in ['.txt','.json'] and f.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8')
    print(json.dumps(dict(status=record['status'],result=record['result'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
