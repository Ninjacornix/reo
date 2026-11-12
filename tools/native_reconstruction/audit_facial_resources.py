"""Inventory owned facial asset storage and actual548-descriptor preload bounds."""
import argparse
import hashlib
import json
import math
import re
import struct
import sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
from audit_retail_effect_descriptors import compare_source,elf_reader
sha=lambda data:hashlib.sha256(data).hexdigest()


def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    image=ROOT/'game_data/SLUS_207.65';assert sha(image.read_bytes())=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(image.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay.read_bytes())=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';o2=overlay.read_bytes();proof=[]
    for address in [0x1baec0,0x67c250,0x67c2e0,0x67c590,0x67c6d0,0x5f0b50,0x5ecf90]:
        owner='sub'if address<0x570000 else'o2';folder=ROOT/('recomp/config/output'if owner=='sub'else'recomp/config/output_ovl/o2');path=next(folder.glob(f'{owner}_{address:08X}_*'));start,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('static facial allocation, preload/claim/update and actual caller authority',path.relative_to(ROOT).as_posix(),start,end,read if owner=='sub'else lambda at,n:o2[at-0x570000:at-0x570000+n]))
    keys=[bytes(v^255 for v in read(pointer,512).split(b'\0')[0]).decode('ascii')for pointer in struct.unpack('<1342I',read(0x2322c0,1342*4))]
    prior=json.loads((ROOT/'build-native-sjuni/primary-scene-scope-llvm-v4/receipt.json').read_text());archive=Path(prior['commands'][2]['command'][1]);stamp=archive.stat().st_size,archive.stat().st_mtime_ns;assets=[];matrices=[]
    with archive.open('rb')as source:
        root,_,names=read_toc(source,0);base,parent=next(entry for entry,(name,_)in zip(root,names)if name.lower()=='romdata_usa.afs');entries,_,names=read_toc(source,base);assert len(entries)==1342
        for ordinal,key in enumerate(keys):
            lip=re.fullmatch(r'MOTION_FACE_R(\d{3})_LIP(\d{2})_(\d{2})_(\d)_BIN',key);matrix=re.fullmatch(r'MOTION_FACE_(HP\d{2}|HN\d{2,3})_MAT',key)
            if not lip and not matrix:continue
            offset,length=entries[ordinal];storage=(length+2047)//2048*2048;assert offset+storage<=parent;source.seek(base+offset);data=source.read(storage);assert len(data)==storage;row=dict(key=key,ordinal=ordinal,display_name=names[ordinal][0],archive_offset=base+offset,logical_bytes=length,storage_bytes=storage,sha256=sha(data[:length]),sector_sha256=sha(data))
            if matrix:
                assert length==3072;row['nonzero_padding_bytes']=sum(value!=0 for value in data[length:]);matrices.append(row);continue
            row['identity']=list(map(int,lip.groups()));channels=[]
            for channel,begin in enumerate(struct.unpack_from('<5I',data)):
                assert begin<=length-16;at=begin;times=[];values=[]
                while at+8<=length:
                    time,value=struct.unpack_from('<if',data,at);times.append(time);values.append(value);at+=8
                    if time<0:break
                assert len(times)>=2 and times[0]>=0 and times[-1]<0 and all(time>=0 for time in times[:-1]);assert all(math.isfinite(value)for value in values)
                channels.append(dict(offset=begin,keys=len(times),first_time=times[0],last_time=times[-2],terminal=times[-1],equal_time_pairs=sum(x==y for x,y in zip(times,times[1:])),decreasing_nonterminal_pairs=sum(x>y for x,y in zip(times[:-2],times[1:-1])),minimum_value=min(values),maximum_value=max(values),sha256=sha(data[begin:at])))
            row['channels']=channels;assets.append(row)
        assert len(assets)==33 and len(matrices)==18
        inventory_path=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';inventory=json.loads(inventory_path.read_text());scenes=[];histogram={};maximum_requests=0;maximum_keys=0
        for row in inventory['rows']:
            if row['version']!='0950':continue
            source.seek(row['offset']);data=source.read(row['bytes']);assert sha(data)==row['sha256'];requests=[]
            for group,sections in enumerate(row['layout']['actors']):
                kind=struct.unpack_from('<h',data,sections[7]['offset']+4)[0]
                if kind not in [0,1,3]:continue
                section=sections[3]
                for index in range(min(15,section['count'])):
                    at=section['offset']+36*index
                    if struct.unpack_from('<H',data,at+2)[0]==65535:break
                    voice,facial=struct.unpack_from('<hI',data,at+6);requests.append(dict(group=group,kind=kind,voice=voice&65535,facial=facial&65535))
            # Assuming distinct actor identities per group is a conservative
            # count upper bound. The source reload flag accumulates ANY mismatch.
            matrix_keys=[]
            for request in requests:
                key=request['group'],request['facial']
                if not matrix_keys or any(previous!=key for previous in matrix_keys):matrix_keys.append(key)
            maximum_requests=max(maximum_requests,len(requests));maximum_keys=max(maximum_keys,len(matrix_keys));histogram[str(len(matrix_keys))]=histogram.get(str(len(matrix_keys)),0)+1
            cue=int(re.fullmatch(r'dm(\d{2})\d{2}[a-z]\.bin',row['name'],re.I)[1]);lip_bytes=0
            for request in requests:
                candidates=[asset for asset in assets if asset['identity'][:3]==[row['layout']['identity'][0],cue,request['voice']]]
                request['candidate_lip_keys']=[asset['key']for asset in candidates];request['maximum_lip_storage']=max((asset['storage_bytes']for asset in candidates),default=0);lip_bytes+=request['maximum_lip_storage']
            scenes.append(dict(scenario=row['scenario'],name=row['name'],sha256=row['sha256'],requests=requests,matrix_key_upper_bound=len(matrix_keys),lip_storage_upper_bound=lip_bytes))
    assert len(scenes)==548 and maximum_requests==2 and maximum_keys==2 and stamp==(archive.stat().st_size,archive.stat().st_mtime_ns)
    largest=max(row['storage_bytes']for row in assets);maximum_lip_storage=max(row['lip_storage_upper_bound']for row in scenes);assert 0x6000+maximum_lip_storage<=0x10000 and(maximum_keys-1)*0xc00+4096<=0x6000
    record=dict(schema=1,status='passed',game_run=False,stage4_complete=False,tool_sha256=sha(Path(__file__).read_bytes()),afs_reader_sha256=sha((ROOT/'tools/assets/afs_inspect.py').read_bytes()),archive_identity=dict(size=stamp[0],mtime_ns=stamp[1]),original_static_authorities=proof,default_catalogue_count=len(keys),matrix_assets=matrices,lip_assets=assets,descriptor_inventory_sha256=sha(inventory_path.read_bytes()),scenes=scenes,matrix_key_upper_bound_histogram=histogram,maximum_preload_requests=maximum_requests,maximum_matrix_keys=maximum_keys,largest_lip_storage_bytes=largest,maximum_scene_lip_storage=maximum_lip_storage,declared_face_slice_bytes=0x10000,lip_offset=0x6000,worst_case_lip_end=0x6000+maximum_lip_storage,limits=['Static owned-data/caller inventory only. Actor kind/model-class admission can suppress loads; distinct groups conservatively bound matrix entries. All available character suffixes are admitted when bounding each actual scenario/cue/voice request. No actor construction, SDK scheduling, facial instance playback or game installation is established.','The declared64KiB face slice derives from1BAEC0 allocation324424=18000 and alias324434=324424+8000. This inventory establishes the current548-descriptor bound, not safety of arbitrary replacement assets or out-of-profile manual loader calls.','MAT sector storage is4096 bytes despite3072-byte bank strides. Actual padding is retained in digests; no invented zeros or disjoint bank storage is assumed.'])
    out.mkdir();(out/'source_tool.py').write_bytes(Path(__file__).read_bytes());(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',lip_assets=len(assets),matrix_assets=len(matrices),scenes=len(scenes),maximum_preloads=maximum_requests,largest_lip_storage=largest,worst_lip_end=record['worst_case_lip_end'])))


if __name__=='__main__':main()
