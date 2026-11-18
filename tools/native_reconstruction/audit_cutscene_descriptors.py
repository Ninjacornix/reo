"""Inventory owned DM descriptors with bounded0950 walks; no game or original execution."""
import argparse,collections,hashlib,json,re,struct,sys
from pathlib import Path
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def walk(raw):
    if len(raw)<40:raise ValueError('Truncated0950 header')
    def word(at):
        if at>len(raw) or 4>len(raw)-at:raise ValueError('Truncated0950 count')
        return struct.unpack_from('<I',raw,at)[0]
    at=40
    def fixed(count,width):
        nonlocal at
        if count>(len(raw)-at)//width:raise ValueError('0950 section outside member')
        start=at;at+=count*width
        return dict(count=count,offset=start,bytes=count*width,width=width)
    def counted(width):
        nonlocal at
        count=word(at);at+=4;return fixed(count,width)
    cameras=word(36);camera_selection=fixed(cameras,16)
    camera_streams=[[counted(56)for _ in range(2)]for _ in range(max(cameras-1,0))]
    events=counted(24);general=counted(36)
    actors=word(at);at+=4;actor_streams=[[counted(36)for _ in range(8)]for _ in range(actors)]
    objects=word(at);at+=4;object_streams=[[counted(36)for _ in range(7)]for _ in range(objects)]
    secondary=counted(40)
    appended=at==len(raw)
    extension=None if appended else word(at)
    #5ED900 appends exactly-1 after a successful read. Record that caller
    # contract explicitly when EOF occurs at this optional count.
    partial=appended or extension==0xffffffff
    result=dict(identity=[word(i)&255 for i in [4,8,12]],duration=word(32),camera_selection=camera_selection,
        camera_streams=camera_streams,events=events,general=general,actors=actor_streams,
        objects=object_streams,secondary=secondary,partial_terminal=partial,caller_appended_terminal=appended,
        extension_groups=[],terminal_offset=at)
    if partial:
        result['consumed_bytes']=at if appended else at+4
        return result
    at+=4
    result['extension_groups']=[[counted(48)for _ in range(2)]for _ in range(extension)]
    result['tail_first']=counted(40);result['tail_second']=counted(40);result['tail_last']=counted(16)
    result['consumed_bytes']=at;result['trailing_bytes']=len(raw)-at
    return result

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--data-root',type=Path,required=True);parser.add_argument('--output',type=Path,required=True);a=parser.parse_args()
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json'
    assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2'
    members={r['member']:r for r in json.loads(inventory.read_bytes())}
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';binary=overlay.read_bytes()
    proofs=[]
    for address in [0x5f15a0,0x5ed900]:
        source=ROOT/f'recomp/config/output_ovl/o2/o2_{address:08X}_0x{address:x}.cpp';end=int(re.search(r'// Address: 0x[\da-f]+ - (0x[\da-f]+)',source.read_text())[1],16)
        proofs.append(compare_source('descriptor parser and caller-appended sentinel authority',source.relative_to(ROOT).as_posix(),address,end,lambda at,n:binary[at-0x570000:at-0x570000+n]))
    archive=a.data_root/'NETBIO00.DAT';stamp=archive.stat().st_size,archive.stat().st_mtime_ns
    rows=[];package=[];stats=collections.Counter()
    with archive.open('rb')as stream:
        outer=read_toc(stream,0)
        for top,(name,_)in enumerate(outer[2]):
            if not re.fullmatch(r'r(?:001|002|028|035|041)\.afs',name.lower()):continue
            base=outer[0][top][0];directory=read_toc(stream,base)
            for index,(label,_)in enumerate(directory[2]):
                if not re.fullmatch(r'dm\d{4}[a-z]\.bin',label.lower()):continue
                offset,size=directory[0][index];stream.seek(base+offset);raw=stream.read(size)
                member=f'NETBIO00.DAT/{top}/{index}';expected=members[member]
                assert len(raw)==size==expected['bytes'] and hashlib.sha256(raw).hexdigest()==expected['sha256']
                version=raw[:4].decode('ascii',errors='replace');stats['version_'+version]+=1
                row=dict(member=member,name=label,scenario=int(name[1:4]),offset=base+offset,bytes=size,sha256=expected['sha256'],version=version)
                if version!='0950':row['status']='unadmitted_version'
                else:
                    try:
                        parsed=walk(raw);row.update(status='bounded_layout',layout=parsed,package_index=len(package));package.append(raw)
                        stats['parsed_0950']+=1;stats['partial_terminal']+=parsed['partial_terminal'];stats['actor_groups']+=len(parsed['actors'])
                        stats['groups_over_16']+=len(parsed['actors'])>16
                        for group in parsed['actors']:
                            for section in group[:7]:
                                stats['actor_streams']+=1;stats['actor_stream_count_'+str(section['count'])]+=1
                                if section['count']==1 and struct.unpack_from('<H',raw,section['offset']+2)[0]==65535:stats['single_terminal_streams']+=1
                    except ValueError as error:row.update(status='layout_refused',error=str(error));stats['layout_refused']+=1
                rows.append(row)
    assert (archive.stat().st_size,archive.stat().st_mtime_ns)==stamp
    out.mkdir();(out/'owned_descriptors.bin').write_bytes(struct.pack('<I',len(package))+b''.join(struct.pack('<I',len(raw))+raw for raw in package))
    receipt=dict(schema=1,status='static_layout_inventory',game_launched=False,source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},original_owned_bodies=proofs,
        stats=stats,rows=rows,package_sha256=sha(out/'owned_descriptors.bin'),limits=['Bounds-checked layout walk, not original parser execution or actual scene acceptance.','Legacy0930/0940 members are unadmitted, not asserted unused.','More than16 groups need explicit native ownership and acceptance; original output arrays can overlap.'])
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(status=receipt['status'],stats=stats,files=len(rows),package_sha256=receipt['package_sha256'])))
if __name__=='__main__':main()
