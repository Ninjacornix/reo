#!/usr/bin/env python3
"""Compile/run the actual Windows Media Engine player, with an owned MP4.

No game or PS2 runtime. --window also presents real native D3D11 textures.
"""
import argparse,hashlib,json,os,shutil,subprocess,time
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    for key in ['compiler','movie-receipt','output']:p.add_argument('--'+key,type=Path,required=True)
    p.add_argument('--window',action='store_true');a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/host-movie'):raise ValueError('Fresh private native movie output required')
    movie=json.loads(a.movie_receipt.read_bytes());source=a.movie_receipt.parent/'owned-h264.mp4'
    if not movie.get('all_source_pictures_retained')or not movie.get('native_timestamps_match_mp4')or movie['frames']!=195 or movie['asset']['sha256']!='f003fe27fc6c402e9e2142a3786828a492bcb26c4b933b8f1a2a944a6d1e94bb' or sha(source)!=movie['mp4_sha256']:raise ValueError('Expected qualified owned continue movie')
    out.mkdir(parents=True);clip=out/'owned movie #1.mp4';shutil.copyfile(source,clip);corrupt=out/'corrupt.mp4';corrupt.write_bytes(bytes(64))
    sources=[ROOT/'game/native/host_movie'/n for n in ['player.hpp','player.cpp','CMakeLists.txt']]+[Path(__file__),Path(__file__).with_name('host_movie_check.cpp')]
    result=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),movie_receipt_sha256=sha(a.movie_receipt),mp4_sha256=sha(clip),source_sha256={s.relative_to(ROOT).as_posix():sha(s)for s in sources},checks=[],game_run=False,audible_sync_tested=False)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    def run(label,cmd,seconds):
        begin=time.monotonic();r=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=seconds)
        (out/(label+'.log')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');result['checks'].append(dict(label=label,command=list(map(str,cmd)),exit_code=r.returncode,seconds=round(time.monotonic()-begin,6)))
        if r.returncode:raise ValueError(label+' failed; see retained log')
        return r.stdout
    try:
        binary=out/'host-movie-check.exe'
        run('compile',[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-municode','-I'+str(ROOT),ROOT/'tools/native_reconstruction/host_movie_check.cpp',ROOT/'game/native/host_movie/player.cpp','-o',binary,'-lmfplat','-lmfuuid','-lole32','-loleaut32','-lshlwapi','-ld3d11','-ldxguid'],90)
        observation=json.loads(run('playback',[binary,clip,corrupt]+(['--window']if a.window else []),60))
        result.update(status=observation['status'],observation=observation,binary_sha256=sha(binary),screen_presentation=a.window)
    finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(result.get('observation',{'status':result['status']})))
if __name__=='__main__':main()
