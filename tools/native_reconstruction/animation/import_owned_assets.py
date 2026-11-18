"""Extract a bounded owned File1 model/motion corpus without changing assets."""
import argparse,hashlib,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda b:hashlib.sha256(b).hexdigest()

def extract(data,out):
 assert not out.exists()and out.resolve().is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 manifest=data.parent/'import.json';assert sha(manifest.read_bytes())=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
 archive=data/'NETBIO00.DAT';assets=[];clips=[];skeletons=[]
 selected={'P00_00.NBD','HP00.NBD','PC_000.BIN','PC_001.BIN'}
 with archive.open('rb')as f:
  top=read_toc(f,0);assert top[2][0][0].lower()=='romdata_usa.afs';base=top[0][0][0];toc=read_toc(f,base)
  for i,(offset,length)in enumerate(toc[0]):
   name=toc[2][i][0]
   if name.upper()not in selected:continue
   f.seek(base+offset);body=f.read(length);assert len(body)==length
   asset=dict(name=name,archive=str(archive.resolve()),archive_offset=base+offset,bytes=length,sha256=sha(body));assets.append(asset);(out/name).write_bytes(body)
   if name.lower().endswith('.nbd'):
    at,size=struct.unpack_from('<II',body,0x24);assert at and size and at+size<=len(body);chunk=body[at:at+size];skeletons.append(chunk);asset['skeleton']=dict(offset=at,bytes=size,sha256=sha(chunk))
   else:
    seen=set()
    for bank in range(2):
     for group in range(20):
      n,table=struct.unpack_from('<II',body,8+bank*160+group*8);assert n<=10000 and table+n*4<=len(body)
      live=[(entry,struct.unpack_from('<i',body,table+4*entry)[0])for entry in range(n)if struct.unpack_from('<i',body,table+4*entry)[0]!=-1]
      picks=sorted({0,len(live)//3,(2*len(live))//3,len(live)-1})if live else []
      for pick in picks:
       entry,at=live[pick]
       if at in seen:continue
       seen.add(at);assert at>=0 and at+20<=len(body);size=struct.unpack_from('<I',body,at+8)[0];assert size>=20 and at+size<=len(body)
       chunk=body[at:at+size];clips.append(chunk);asset.setdefault('clips',[]).append(dict(bank=bank,group=group,entry=entry,offset=at,bytes=size,sha256=sha(chunk)))
 assert {x['name'].upper()for x in assets}==selected
 for name,chunks in [('owned_clips.bin',clips),('owned_skeletons.bin',skeletons)]:
  package=struct.pack('<I',len(chunks))+b''.join(struct.pack('<I',len(b))+b for b in chunks);(out/name).write_bytes(package)
 (out/'source_import_owned_assets.py').write_bytes(Path(__file__).read_bytes())
 q=dict(schema=1,source_tool_sha256=sha(Path(__file__).read_bytes()),selection='up to four evenly distributed distinct live entries per group in both adjacent20-descriptor player banks',import_manifest=dict(path=str(manifest.resolve()),sha256=sha(manifest.read_bytes())),assets=assets,clips=len(clips),skeletons=len(skeletons),output_sha256={p.name:sha(p.read_bytes())for p in out.iterdir()if p.is_file()},game_run=False)
 (out/'receipt.json').write_text(json.dumps(q,indent=2)+'\n');return q
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--data',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();q=extract(a.data,a.output);print(json.dumps(dict(clips=q['clips'],skeletons=q['skeletons'],output=str(a.output))))
