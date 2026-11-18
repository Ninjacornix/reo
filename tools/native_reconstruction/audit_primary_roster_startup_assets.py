"""Verify the exact owned File1 assets consumed by the startup qualification."""
import argparse,hashlib,json,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sys.path.insert(0,str(ROOT/'tools/assets'))
from afs_inspect import read_toc
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--archive',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();assert not a.output.exists()
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members={row['member']:row for row in json.loads(inventory.read_bytes())};profiles={};keys=[]
 for name,include in [('primary-actor-member','primary_actor_members.inc'),('humanoid-motion-member','humanoid_motion_members.inc')]:
  receipt=ROOT/f'build-native-sjuni/{name}-profile-v1/receipt.json';profile=json.loads(receipt.read_bytes());assert profile['status']=='passed'and sha(ROOT/'game/native/gameplay_world'/include)==profile['output_sha256'];profiles[name]=dict(receipt=receipt.relative_to(ROOT).as_posix(),sha256=sha(receipt))
  if name=='primary-actor-member':selected=[row for row in profile['rows']if row['appearance']==0 and row['model_class']==0]
  else:selected=[row for row in profile['rows']if row['index']==0 and row['character']==255]
  assert len(selected)==(8 if name=='primary-actor-member'else 1);keys.extend('NETBIO00.DAT/0/'+str(row['member'])for row in selected)
 for basename in ['r001.npc','e001.emd','sgl_e001.emd']:
  selected=[row['member']for row in members.values()if row['names']==['r001.afs',basename]];assert len(selected)==1;keys.extend(selected)
 rows=[];stamp=a.archive.stat().st_size,a.archive.stat().st_mtime_ns;tables={}
 with a.archive.open('rb')as stream:
  for key in keys:
   base=0;names=[];size=0
   for ordinal in map(int,key.split('/')[1:]):
    if base not in tables:tables[base]=read_toc(stream,base)
    table=tables[base];offset,size=table[0][ordinal];names.append(table[2][ordinal][0]);base+=offset
   expected=members[key];stream.seek(base);data=stream.read(size);assert len(data)==size==expected['bytes']and hashlib.sha256(data).hexdigest()==expected['sha256']and [name.lower()for name in names]==[name.lower()for name in expected['names']];rows.append(dict(member=key,names=names,offset=base,bytes=size,sha256=expected['sha256']))
 assert stamp==(a.archive.stat().st_size,a.archive.stat().st_mtime_ns)
 result=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},inventory_sha256=sha(inventory),profiles=profiles,assets=rows,game_run=False);a.output.parent.mkdir(parents=True,exist_ok=True);a.output.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',assets=len(rows))))
if __name__=='__main__':main()
