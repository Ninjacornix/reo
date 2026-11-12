"""Audit owned object headers/capacity and literal requested asset names."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';owned=overlay.read_bytes();proofs=[];sources={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))}
 for entry in [0x571010,0x571080,0x5710f0,0x571150,0x5712d0,0x5f1390,0x5f0610]:
  path=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{entry:08X}_*'));begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];key=path.relative_to(ROOT).as_posix();proofs.append(compare_source('complete cinematic object ownership/service/header body',key,begin,end,lambda at,n:owned[at-0x570000:at-0x570000+n]));sources[key]=sha(path)
 inventory=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';r=json.loads(inventory.read_bytes());assert r['status']=='static_layout_inventory';package=inventory.parent/'owned_descriptors.bin';assert sha(package)==r['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c';data=package.read_bytes();at=4;blocks=[]
 for _ in range(struct.unpack_from('<I',data)[0]):length=struct.unpack_from('<I',data,at)[0];at+=4;blocks.append(data[at:at+length]);at+=length
 assert at==len(data)
 members_path=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(members_path)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=json.loads(members_path.read_bytes());names={(x['names'][0].lower(),name.lower())for x in members for name in x['names'][1:]};rows=[];counts={};headers=0;matches=0
 for row in r['rows']:
  if row['status']!='bounded_layout':continue
  blob=blocks[row['package_index']];objects=row['layout']['objects'];counts[str(len(objects))]=counts.get(str(len(objects)),0)+1;valid=[];requests=[];dm=re.fullmatch(r'dm(\d{2})(\d{2})([a-z])\.bin',row['name'],re.I);assert dm
  for index,streams in enumerate(objects):
   header=streams[2];assert header['count']>0;offset=header['offset'];enabled=struct.unpack_from('<H',blob,offset+2)[0]!=65535;valid.append(enabled)
   motion,model=struct.unpack_from('<II',blob,offset+4);stem='obj%02d_%02d_%s_%02d.nbd'%(int(dm[1]),int(dm[2]),dm[3].lower(),model);found=('r%03d.afs'%row['scenario'],stem)in names;matches+=found;headers+=enabled
   requests.append(dict(group=index,enabled=enabled,motion=motion,model=model,request_derived_leaf=stem,exact_named_member_in_same_scenario=found))
  assert len(objects)<=16 and all(valid)and not any(valid[i]and not all(valid[:i])for i in range(len(valid)))
  if objects:rows.append(dict(scenario=row['scenario'],descriptor=row['name'],sha256=row['sha256'],requests=requests))
 assert sum(counts.values())==548 and headers==726 and matches==452
 literal={}
 for address,expected in [(0x73edb0,r'data\rom\tex\demo\r%03d\obj%02d_%02d_%c_%02d.tex'),(0x73edf0,r'data\rom\model\demo\r%03d\obj%02d_%02d_%c_%02d')]:
  raw=owned[address-0x570000:].split(b'\0',1)[0];assert raw.decode('ascii')==expected;literal[hex(address)]=expected
 result=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,original_owned_bodies=proofs,descriptor_inventory=dict(path=inventory.relative_to(ROOT).as_posix(),sha256=sha(inventory),package_sha256=sha(package)),asset_inventory=dict(path=members_path.relative_to(ROOT).as_posix(),sha256=sha(members_path)),stats=dict(descriptors=548,object_scenes=len(rows),object_groups=headers,maximum_objects=max(map(int,counts)),header_holes=0,scene_counts=counts,request_derived_exact_names=matches,unresolved_request_derived_names=headers-matches),format_literals=literal,rows=rows,limits=['Static owned-asset evidence; no original scene was launched or object loaded.','Request-derived names use descriptor filenames as candidate scene requests, not header words4/8/12. These names are not proof of live request/global identity.','274 unmatched request-derived names remain unresolved: aliases, merged requests, unused content and real loading behavior are not inferred.','Construction, binding, authored event cadence and installed gameplay remain separate acceptance gates.'])
 out.mkdir();(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result['stats']))
if __name__=='__main__':main()
