#!/usr/bin/env python3
"""One owned movie: H.264 conversion and complete Windows native decoder proof.

This is an offscreen experiment, not an installed game replacement. Reuses the
launcher's pinned converter; never downloads tools or modifies imported data.
"""
import argparse,hashlib,json,os,re,shutil,subprocess,time
from check_movie_catalog_counts import pictures
from fractions import Fraction
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
ELF='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
CONVERTER='3256173f3f8bffd7df12227c68adf68025edb1832273a9530688a7bb1ed8edec'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def frames(path):
    text=path.read_text();tb=re.search(r'^#tb 0: (\d+)/(\d+)$',text,re.M)
    if not tb:raise ValueError('Missing decoded time base')
    base=Fraction(int(tb[1]),int(tb[2]));rows=[]
    for line in text.splitlines():
        if line.startswith('#') or not line.strip():continue
        parts=[part.strip()for part in line.split(',')]
        if len(parts)<6 or parts[0]!='0':raise ValueError('Unexpected decoded frame row')
        rows.append((int(parts[2])*base,int(parts[3])*base))
    if not rows:raise ValueError('No decoded frames')
    return [(t-rows[0][0],duration)for t,duration in rows]

def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ['import-root','members','ffmpeg','compiler','output']:p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--asset',default='adxsnd.afs/PS2continue.sfd');a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/mp4-movie-probe'):raise ValueError('Fresh private experiment directory required')
    imported=json.loads((a.import_root/'import.json').read_bytes())
    if imported.get('Game')!='file1'or imported.get('ElfSha256')!=ELF:raise ValueError('Owned File1 import required')
    if sha(a.ffmpeg)!=CONVERTER:raise ValueError('Expected existing pinned launcher converter')
    members=json.loads(a.members.read_bytes());matches=[r for r in members if '/'.join(r['names'])==a.asset]
    if len(matches)!=1:raise ValueError('Unique inventoried movie required')
    asset=matches[0]
    if asset['audio_ids']or not asset['complete']or not 0<asset['bytes']<=64*1024*1024:raise ValueError('Bounded complete video-only source required')
    container=(a.import_root/'data'/asset['container']).resolve()
    if not container.is_relative_to((a.import_root/'data').resolve())or asset['source_offset']<0 or asset['source_offset']+asset['bytes']>container.stat().st_size:raise ValueError('Imported source bounds')
    if shutil.disk_usage(ROOT).free<512*1024*1024:raise ValueError('Experiment needs 512MiB free reserve')
    with container.open('rb')as f:f.seek(asset['source_offset']);data=f.read(asset['bytes'])
    if hashlib.sha256(data).hexdigest()!=asset['sha256']:raise ValueError('Owned movie hash mismatch')
    sequence=data.find(b'\0\0\1\xb3')
    if sequence<0 or sequence+8>len(data) or data[sequence+7]&15!=4:raise ValueError('This first conversion profile admits declared 30000/1001 cadence only')
    picture_count=sum(pictures(data).values())
    out.mkdir(parents=True);source=out/'owned.sfd';source.write_bytes(data)
    result=dict(schema=1,status='failed',asset=asset,elf_sha256=ELF,converter_sha256=CONVERTER,compiler_sha256=sha(a.compiler),members_sha256=sha(a.members),
        source_sha256={f.relative_to(ROOT).as_posix():sha(f)for f in [Path(__file__),Path(__file__).with_name('mp4_decode_probe.cpp')]},checks=[],game_run=False,audio_device_opened=False,screen_presentation=False,game_hooks_installed=False)
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    def run(label,cmd,timeout=120):
        started=time.monotonic();r=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=timeout)
        (out/(label+'.log')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');result['checks'].append(dict(label=label,command=list(map(str,cmd)),exit_code=r.returncode,seconds=round(time.monotonic()-started,6)))
        if r.returncode:raise ValueError(label+' failed; see retained log')
        return r.stdout
    try:
        prefix=[a.ffmpeg,'-hide_banner','-loglevel','error','-nostdin','-n','-threads','2'];mp4=out/'owned-h264.mp4'
        # SFD demux timestamps can repeat or jump. Keep every decoded picture,
        # ordered at the rate declared by the MPEG sequence header. This is an
        # explicit asset conversion policy, not a claim to preserve raw PES PTS.
        run('convert',prefix+['-i',source,'-map','0:v:0','-an','-sn','-dn','-map_metadata','-1','-vf','settb=expr=1/90000,setpts=N*3003','-c:v','libx264','-preset','veryfast','-crf','18','-pix_fmt','yuv420p','-threads','2','-enc_time_base','1:90000','-fps_mode','passthrough','-video_track_timescale','90000','-movflags','+faststart',mp4])
        for label,video in [('original',source),('converted',mp4)]:
            run(label+'-decode',prefix+['-i',video,'-map','0:v:0','-an','-sn','-dn','-fps_mode','passthrough','-f','framecrc',out/(label+'-frames.txt')])
        original=frames(out/'original-frames.txt');converted=frames(out/'converted-frames.txt')
        if len(original)!=picture_count or len(converted)!=picture_count:raise ValueError('Conversion changed decoded picture count')
        if any(t!=Fraction(i*1001,30000) or duration!=Fraction(1001,30000)for i,(t,duration)in enumerate(converted)):raise ValueError('Converted cadence differs from declared rate')
        original_sar=re.search(r'^#sar 0: (\d+)/(\d+)$',(out/'original-frames.txt').read_text(),re.M)
        converted_sar=re.search(r'^#sar 0: (\d+)/(\d+)$',(out/'converted-frames.txt').read_text(),re.M)
        if not original_sar or not converted_sar or original_sar.groups()!=converted_sar.groups():raise ValueError('Pixel aspect changed')
        binary=out/'native-mp4-decode.exe'
        run('compile-native',[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Werror','-municode',Path(__file__).with_name('mp4_decode_probe.cpp'),'-o',binary,'-lmfreadwrite','-lmfplat','-lmfuuid','-lole32'])
        native=json.loads(run('native-decode',[binary,mp4]));times=native['timestamps_100ns']
        if len(times)!=picture_count or any(abs(Fraction(t-times[0],10000000)-row[0])>Fraction(1,10000000)for t,row in zip(times,converted)):raise ValueError('Native reader frame count/timing mismatch')
        if (native['width'],native['height'])!=(asset['geometry']['width'],asset['geometry']['height']):raise ValueError('Native reader geometry mismatch')
        if native['pixel_aspect']!=list(map(int,original_sar.groups())):raise ValueError('Native reader pixel aspect mismatch')
        result.update(status='one complete converted movie decodes through Windows native reader at declared cadence',frames=picture_count,all_source_pictures_retained=True,cadence_policy='one picture per 1001/30000 seconds from sequence-header rate code4; raw SFD demux PTS normalized',raw_pts_preserved=False,raw_source_nonincreasing_pts=sum(original[i][0]<=original[i-1][0]for i in range(1,len(original))),native_timestamps_match_mp4=True,source_bytes=len(data),mp4_bytes=mp4.stat().st_size,mp4_sha256=sha(mp4),native_binary_sha256=sha(binary),native=native,
            evidence_sha256={f.name:sha(f)for f in sorted(out.iterdir())if f.is_file()})
    finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:result[k]for k in ['status','frames','source_bytes','mp4_bytes']}))
if __name__=='__main__':main()
