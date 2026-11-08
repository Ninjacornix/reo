#!/usr/bin/env python3
"""Read bounded media control observations from one owned File1 candidate only.

No suspension, input, guest writes, audio capture or UI loop dependency. Reads
are separate observations, never an atomic snapshot or original call trace.
"""
import argparse,hashlib,json,struct,sys,time
from contextlib import closing
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/coop_playtest'))
import coop_playtest as owned
from lobby_driver import GuestRam
ELF_SHA='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def words(value):return list(struct.unpack('<'+'I'*(len(value)//4),value))
def address(at,size):return at>=0x10000 and at%4==0 and at<=0x2000000 and 0<=size<=0x2000000-at
def sample(reader):
    phase=reader.read(0x4BADD0,0x40)
    clocks=dict(adxt=words(reader.read(0x20F3C4,4))[0],sofdec=words(reader.read(0x22F138,4))[0])
    pool=reader.read(0x20F3C8,16*0xC4);instances=[]
    lsc_callback=words(reader.read(0x21dfd8,12))
    for slot in range(16):
        row=pool[slot*0xC4:(slot+1)*0xC4]
        if row[0]:
            record=dict(slot=slot,active=row[0],state=row[1],source_mode=row[2],channels=row[3],pause=row[0x72],raw_hex=row.hex())
            child=struct.unpack_from('<I',row,12)[0];record['rna_pointer']=child
            # Exact verified File1 RNA pool only. This is diagnostic data, not
            # source authority; never chase arbitrary children from a torn C4.
            if row[0]==1 and row[3] in (1,2) and 0x223880<=child<0x223880+16*0x60 and (child-0x223880)%0x60==0:
                rna=reader.read(child,0x60);channels=struct.unpack_from('<I',rna,4)[0]
                record['rna']=dict(raw_hex=rna.hex(),active=rna[0],channels=channels,route=struct.unpack_from('<I',rna,0x20)[0],
                                   active_channels_match=rna[0]==1 and channels==row[3],end_matches=reader.read(child,0x60)==rna)
            else:record['rna_unavailable']='outside exact active File1 RNA pool/profile'
            child=struct.unpack_from('<I',row,0x94)[0];record['lsc_pointer']=child
            # Independently audited 13CB50/13CBB0/13CD08 child pool and links.
            # Copy metadata only; never follow queued names or the lower file.
            if row[0]==1 and row[3] in (1,2) and 0x21e110<=child<0x21e110+16*0x238 and (child-0x21e110)%0x238==0:
                lsc=reader.read(child,0x238);input_pointer=struct.unpack_from('<I',lsc,8)[0];file_pointer=struct.unpack_from('<I',lsc,0x28)[0]
                record['lsc']=dict(raw_hex=lsc.hex(),active=lsc[0],state=lsc[1],transferring=lsc[2],repeat=lsc[3],paused=lsc[4],
                    minimum_bytes=struct.unpack_from('<I',lsc,0x14)[0],capacity_bytes=struct.unpack_from('<I',lsc,0x18)[0],
                    tail=struct.unpack_from('<I',lsc,0x1c)[0],head=struct.unpack_from('<I',lsc,0x20)[0],count=struct.unpack_from('<I',lsc,0x24)[0],
                    input_pointer=input_pointer,file_pointer=file_pointer,
                    active_links_match=lsc[0]==1 and input_pointer==struct.unpack_from('<I',row,0x10)[0] and file_pointer==struct.unpack_from('<I',row,8)[0],
                    end_matches=reader.read(child,0x238)==lsc)
            else:record['lsc_unavailable']='outside exact active File1 LSC pool/profile'
            record['c4_end_matches']=reader.read(0x20F3C8+slot*0xC4,0xC4)==row
            instances.append(record)
    registry=words(reader.read(0x22F18C,32));movies=[]
    for slot,main in enumerate(registry):
        if not main:continue
        if not address(main,0x2ABC):
            movies.append(dict(slot=slot,address=main,admitted=False,reason='outside bounded aligned main profile'));continue
        scalars=reader.read(main+0x44,20);shared=words(reader.read(main+0x2AB0,4))[0]
        record=dict(slot=slot,address=main,admitted=True,scalars=words(scalars),properties=words(reader.read(main+0x9A0,400)),saved_properties=words(reader.read(main+0xB30,400)),
                    components=[words(reader.read(main+0x1AA0+68*i,8)) for i in range(9)],clock_and_video_hex=reader.read(main+0xCC0,0x298).hex(),shared_address=shared)
        if shared:
            if address(shared,0xDAC):record['shared_source_flags']=words(reader.read(shared+0xDA4,8))
            else:record['shared_reason']='outside bounded aligned shared profile'
        record['control_end_matches']=reader.read(main+0x44,20)==scalars and words(reader.read(main+0x2AB0,4))[0]==shared
        movies.append(record)
    return dict(phase=phase[0],modal=phase[0x1E],paused=phase[0x28],clocks=clocks,adxt=instances,movies=movies,
                lsc_callback_words=lsc_callback,lsc_callback_end_matches=words(reader.read(0x21dfd8,12))==lsc_callback,
                registry_end_matches=words(reader.read(0x22F18C,32))==registry,atomic=False)
def main():
    p=argparse.ArgumentParser();p.add_argument('--session',type=Path,required=True);p.add_argument('--seconds',type=float,default=30);p.add_argument('--interval',type=float,default=0.2);p.add_argument('--name',default='media-control');a=p.parse_args()
    folder,manifest=owned.session_record(a.session)
    if not folder.is_relative_to(ROOT/'build-native-sjuni/playtests') or manifest['game']!='file1' or len(manifest['players'])!=1:raise ValueError('One private File1 candidate required')
    if not 0<a.seconds<=600 or not 0.1<=a.interval<=5 or not a.name or any(c not in 'abcdefghijklmnopqrstuvwxyz0123456789-' for c in a.name):raise ValueError('Bounded duration, interval and simple report name required')
    run=json.loads((folder/'run.json').read_bytes())
    if run.get('finishedUtc') or len(run['players'])!=1:raise ValueError('One running owned candidate required')
    player=run['players'][0];identity={k:player[k] for k in ['pid','image','creationFileTime']}
    image=Path(manifest['players'][0]['image'])
    if image.resolve()!=Path(identity['image']).resolve() or sha(image)!=manifest['sourceSha256'] or owned.process_identity(identity['pid'])!=identity:raise ValueError('Owned process/image identity mismatch')
    if sha(Path(manifest['elf']))!=ELF_SHA:raise ValueError('Owned File1 ELF identity required')
    output=folder/(a.name+'.jsonl');receipt=folder/(a.name+'-receipt.json')
    if output.exists() or receipt.exists():raise ValueError('Fresh evidence names required')
    result=dict(schema='reo-native-media-observation-v1',status='failed',identity=identity,executable_sha256=manifest['sourceSha256'],elf_sha256=ELF_SHA,source_sha256=sha(Path(__file__)),records=0,errors=[],atomic=False,guest_writes=False,threads_suspended=False)
    started=time.monotonic()
    try:
        with closing(GuestRam(identity,manifest['elf'])) as reader,output.open('x',encoding='utf-8',newline='\n') as stream:
            while time.monotonic()-started<a.seconds:
                reader.check();begin=time.monotonic();row=sample(reader);reader.check()
                row.update(seconds=round(begin-started,6),read_seconds=round(time.monotonic()-begin,6));stream.write(json.dumps(row,separators=(',',':'))+'\n');stream.flush();result['records']+=1
                time.sleep(max(0,a.interval-(time.monotonic()-begin)))
        result['status']='bounded read-only observations completed'
    except Exception as error:result['errors'].append(str(error));raise
    finally:
        result['elapsed_seconds']=round(time.monotonic()-started,6)
        if output.exists():result['output_sha256']=sha(output)
        receipt.write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:result[k] for k in ['status','records','elapsed_seconds']}))
if __name__=='__main__':main()
