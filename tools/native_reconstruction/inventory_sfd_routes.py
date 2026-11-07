#!/usr/bin/env python3
"""Identify real SFD elementary stream routes in hash-verified imported members."""
import argparse,collections,hashlib,json,mmap
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-routes'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--data',type=Path,required=True);p.add_argument('--members',type=Path,required=True);p.add_argument('--containers',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned output required')
 members=json.loads(a.members.read_bytes());containers={r['path']:r for r in json.loads(a.containers.read_bytes())};rows=[];out.mkdir(parents=True)
 for container in sorted({r['container'] for r in members if r.get('recognition')=='mpeg_program_stream_undemuxed'}):
  with (a.data/container).open('rb') as f,mmap.mmap(f.fileno(),0,access=mmap.ACCESS_READ) as mapped:
   for member in members:
    if member['container']!=container or member.get('recognition')!='mpeg_program_stream_undemuxed':continue
    start=member['iso_offset']-containers[container]['offset'];stop=start+member['bytes']
    if start<0 or stop>len(mapped):raise ValueError('Member outside imported container')
    view=memoryview(mapped)[start:stop];digest=hashlib.sha256(view).hexdigest();view.release()
    if digest!=member['sha256']:raise ValueError('Owned member hash mismatch '+str(member['names']))
    at=start;packets=collections.Counter();error=None;program_end=False
    while at<stop:
     if program_end:
      if any(value not in [0,255] for value in mapped[at:stop]):error='non-padding after program end'
      at=stop;break
     if stop-at<4 or mapped[at:at+3]!=b'\0\0\1':error='packet prefix';break
     code=mapped[at+3];packets[code]+=1
     if code==0xb9:count=4;program_end=True
     elif code==0xba:
      if stop-at<5:error='short pack';break
      if mapped[at+4]>>4==2:count=12
      elif mapped[at+4]&0xc0==0x40 and stop-at>=14:count=14+(mapped[at+13]&7)
      else:error='pack layout';break
     else:
      if stop-at<6:error='short packet';break
      count=6+int.from_bytes(mapped[at+4:at+6],'big')
      if count==6:error='unbounded/empty packet';break
     if at+count>stop:error='packet exceeds member';break
     at+=count
    sequence=mapped.find(b'\0\0\1\xb3',start,stop);geometry=None
    if sequence>=0 and sequence+8<=stop:
     value=int.from_bytes(mapped[sequence+4:sequence+8],'big');geometry=dict(width=value>>20,height=(value>>8)&4095,rate=value&15)
    rows.append(dict(container=container,names=member['names'],source_offset=start,bytes=member['bytes'],sha256=digest,packets={f'{k:02x}':v for k,v in sorted(packets.items())},audio_ids=[f'{k:02x}' for k in packets if 0xc0<=k<=0xdf or k==0xbd],geometry=geometry,complete=error is None,error=error))
 (out/'members.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n')
 receipt=dict(status='owned SFD packet routes inventoried',members=len(rows),bytes=sum(r['bytes'] for r in rows),members_with_audio=sum(bool(r['audio_ids']) for r in rows),incomplete=sum(not r['complete'] for r in rows),geometry_counts={str(g):sum(r['geometry']==g for r in rows) for g in sorted({str(r['geometry']):r['geometry'] for r in rows}.values(),key=str)},sources={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},input_manifests={str(a.members):sha(a.members),str(a.containers):sha(a.containers)},members_sha256=sha(out/'members.json'),game_run=False,audio_device_opened=False)
 (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps({k:v for k,v in receipt.items() if k not in ['sources','input_manifests','geometry_counts']}))
if __name__=='__main__':main()
