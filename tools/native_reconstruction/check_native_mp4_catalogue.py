#!/usr/bin/env python3
"""Decode every unique converted movie through the qualified native OS reader.

Counts and relative timestamps are checked, not lossy pixel equivalence. This
does not open a game, window, audio device or GPU rendering pipeline.
"""
import argparse,hashlib,json,os,subprocess,time
from fractions import Fraction
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ['cache','probe-receipt','compiler-bin','output']:p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(ROOT/'build-native-sjuni/host-movie'):raise ValueError('Fresh private native decode evidence required')
    proof=json.loads(a.probe_receipt.read_bytes());binary=a.probe_receipt.parent/'native-mp4-decode.exe'
    if not proof.get('all_source_pictures_retained')or sha(binary)!=proof['native_binary_sha256']:raise ValueError('Qualified native decoder binary required')
    index=json.loads((a.cache/'movies.json').read_bytes())
    if not index['complete_catalogue']or index['prepared']!=201 or len(index['movies'])!=201:raise ValueError('Complete owned movie cache required')
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler_bin.resolve())+os.pathsep+env.get('PATH','')
    result=dict(schema=1,status='running',source_sha256=sha(Path(__file__)),probe_binary_sha256=sha(binary),probe_receipt_sha256=sha(a.probe_receipt),index_sha256=sha(a.cache/'movies.json'),results=[],game_run=False,screen_presentation=False,audible_sync_tested=False)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n');begin=time.monotonic();seen={}
    try:
        for i,row in enumerate(index['movies']):
            if row['file']!=row['source_key']+'.mp4' or len(row['source_key'])!=64 or any(c not in '0123456789abcdef'for c in row['source_key']):raise ValueError('Cache resource key')
            if row['source_key']in seen:
                if seen[row['source_key']]['frames']!=row['frames']:raise ValueError('Conflicting alias picture count')
                result['results'].append(dict(index=i,key=row['source_key'],alias_of=seen[row['source_key']]['index'],frames=row['frames']));continue
            path=a.cache/row['file']
            if sha(path)!=row['sha256']or path.stat().st_size!=row['bytes']:raise ValueError('Prepared asset changed')
            r=subprocess.run([str(binary),str(path.resolve())],capture_output=True,text=True,env=env,timeout=60)
            (out/f'{i:03d}.log').write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n')
            if r.returncode:raise ValueError('Native reader failed for '+row['source_name'])
            native=json.loads(r.stdout);times=native['timestamps_100ns']
            if len(times)!=row['frames']or any(abs(Fraction(t-times[0],10000000)-Fraction(j*1001,30000))>Fraction(1,10000000)for j,t in enumerate(times)):raise ValueError('Native decoded count/timestamp mismatch: '+row['source_name'])
            item=dict(index=i,key=row['source_key'],frames=row['frames'],width=native['width'],height=native['height'],pixel_aspect=native['pixel_aspect'],native_decode_seconds=native['elapsed_seconds'],log_sha256=sha(out/f'{i:03d}.log'))
            result['results'].append(item);seen[row['source_key']]=item
            (out/'progress.json').write_text(json.dumps(dict(rows=len(result['results']),unique=len(seen),last=row['source_name']))+'\n',encoding='utf-8',newline='\n')
        result.update(status='all prepared movie references decode with matching counts and nominal cadence',references=201,unique_movies=len(seen),pictures=sum(r['frames']for r in result['results']),seconds=round(time.monotonic()-begin,6))
    except Exception as error:result.update(status='failed',error=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:v for k,v in result.items()if k not in ['results']}))
if __name__=='__main__':main()
