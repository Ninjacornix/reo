#!/usr/bin/env python3
"""Independently count selected PES elementary picture headers across boundaries."""
import argparse,collections,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def pictures(data):
    at=0;es=bytearray()
    while at<len(data):
        if data[at:at+3]!=b'\0\0\1':raise ValueError('Program prefix')
        code=data[at+3]
        if code==0xB9:
            if any(v not in [0,255] for v in data[at+4:]):raise ValueError('Program tail')
            break
        if code==0xBA:
            at+=12 if data[at+4]>>4==2 else 14+(data[at+13]&7);continue
        end=at+6+int.from_bytes(data[at+4:at+6],'big')
        if end>len(data) or end==at+6:raise ValueError('Packet extent')
        if code==0xE0:
            cursor=at+6
            if data[cursor]&0xC0==0x80:cursor+=3+data[cursor+2]
            else:
                while cursor<end and data[cursor]==255:cursor+=1
                if data[cursor]&0xC0==0x40:cursor+=2
                control=data[cursor]>>4
                if control==2:cursor+=5
                elif control==3:cursor+=10
                elif data[cursor]==15:cursor+=1
                else:raise ValueError('PES optional-header layout')
            if cursor>end:raise ValueError('Payload extent')
            es.extend(data[cursor:end])
        at=end
    counts=collections.Counter();cursor=0
    while True:
        cursor=es.find(b'\0\0\1\0',cursor)
        if cursor<0:break
        if cursor+6>len(es):raise ValueError('Short picture header')
        kind=(es[cursor+5]>>3)&7
        if kind not in [1,2,3]:raise ValueError('Unadmitted picture kind')
        counts[kind]+=1;cursor+=4
    return {str(k):counts[k] for k in [1,2,3]}
def main():
    p=argparse.ArgumentParser();p.add_argument('--catalogue',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/movie-matrix'):raise ValueError('Fresh owned scope required')
    catalogue=json.loads(a.catalogue.read_bytes())
    if catalogue['status']!='complete catalogue executed' or catalogue['failed']:raise ValueError('Complete successful GPU catalogue required')
    out.mkdir(parents=True);rows=[]
    for row in catalogue['results']:
        payload=a.catalogue.parent/f"{row['index']:03d}"/'owned.sfd'
        if sha(payload)!=row['asset']['sha256']:raise ValueError('Payload drift')
        counts=pictures(payload.read_bytes());total=sum(counts.values())
        if total!=row['result']['decoded'] or total!=row['result']['presented']:raise ValueError('Independent picture count mismatch')
        rows.append(dict(index=row['index'],asset=row['asset']['names'],pictures=total,kinds=counts))
    (out/'counts.json').write_text(json.dumps(rows,indent=2)+'\n',encoding='utf-8',newline='\n')
    record=dict(status='all selected elementary picture counts match GPU outputs',catalogue_sha256=sha(a.catalogue),source_sha256=sha(Path(__file__)),counts_sha256=sha(out/'counts.json'),members=len(rows),pictures=sum(row['pictures'] for row in rows),kinds={k:sum(row['kinds'][k] for row in rows) for k in ['1','2','3']},game_run=False,audio_device_opened=False)
    (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n');print(json.dumps(record))
if __name__=='__main__':main()
