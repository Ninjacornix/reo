"""Audit actual bounded room proxy inputs before shared ownership migration."""
import argparse,collections,hashlib,json,struct,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 parser=argparse.ArgumentParser();parser.add_argument('--output',type=Path,required=True);args=parser.parse_args();out=args.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 inventory=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v13/inventory.json';receipt_path=inventory.parent/'receipt.json';receipt=json.loads(receipt_path.read_text());assert receipt['status']=='passed'and receipt['output_sha256']['inventory.json']==sha(inventory)
 rows=[];assets=[];combinations=collections.Counter();descriptors=collections.defaultdict(collections.Counter);maximum=0;roster_extents=collections.Counter();models=collections.Counter()
 for asset in json.loads(inventory.read_text()):
  if asset['format']!='R':continue
  archive=Path(asset['archive'])
  with archive.open('rb')as f:f.seek(asset['archive_offset']);raw=f.read(asset['bytes'])
  assert hashlib.sha256(raw).hexdigest()==asset['sha256'];offset,size=struct.unpack_from('<II',raw,80);assert size and offset<=len(raw)and size<=len(raw)-offset;data=raw[offset:offset+size];count=struct.unpack_from('<I',data,4)[0];assert count<=128 and 8+count*4<=len(data);maximum=max(maximum,count)
  script_offset,script_bytes=struct.unpack_from('<II',raw,8);assert script_bytes and script_offset+script_bytes<=len(raw);script=raw[script_offset:script_offset+script_bytes];references=struct.unpack_from('<16I',script);start=references[0];assert 64<=start<=len(script);end=min([v for v in references if v>start]+[len(script)]);roster=script[start:end];roster_extents[str(len(roster))]+=1
  assets.append(dict(member=asset['member'],name=asset['name'],sha256=asset['sha256'],section_bytes=size,section_sha256=hashlib.sha256(data).hexdigest(),records=count,model_roster_sha256=hashlib.sha256(roster).hexdigest(),model_roster_bytes=len(roster)))
  for ordinal in range(count):
   at=struct.unpack_from('<I',data,8+4*ordinal)[0];assert at>=8+count*4 and at<=len(data)and 0xb0<=len(data)-at;record=data[at:at+0xb0];tag,event=struct.unpack_from('<II',record);identifier=struct.unpack_from('<I',record,0x30)[0];combinations[f'{tag}:{event}']+=1
   row=dict(member=asset['member'],name=asset['name'],ordinal=ordinal,type=tag,query=event,authored_id=identifier,record_offset=at,record_sha256=hashlib.sha256(record).hexdigest())
   if tag in [0,2]:
    descriptor=struct.unpack_from('<I',record,0x44 if tag==0 else 0x38)[0];resource_class=struct.unpack_from('<I',record,0x50 if tag==0 else 0x48)[0];assert identifier<len(roster);mapped=roster[identifier];models[str(mapped)]+=1;descriptors[str(tag)][f'descriptor:{descriptor}']+=1;descriptors[str(tag)][f'class_word:{resource_class}']+=1;row['matrix']=dict(mapped_model=mapped,descriptor=descriptor,resource_class_word=resource_class,mode_byte=record[0x61])
   rows.append(row)
 image=ROOT/'build-function-index/owned-overlays/o2.bin';owned=image.read_bytes();assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';proof=[];source={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))}
 for at in [0x5c1120,0x5c11b0,0x5c12a0,0x5c1390,0x5819c0]:
  name=f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';path=ROOT/name;t=path.read_text();import re
  begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',t).groups()];proof.append(compare_source('shared pool/import/lookup source authority',name,begin,end,lambda pos,n:owned[pos-0x570000:pos-0x570000+n]));source[name]=sha(path)
 out.mkdir();(out/'records.json').write_text(json.dumps(rows,indent=2)+'\n');result=dict(status='passed',source_sha256=source,inventory_receipt=dict(path=receipt_path.relative_to(ROOT).as_posix(),sha256=sha(receipt_path)),owned_overlay_sha256=sha(image),assets=assets,rooms=len(assets),records=len(rows),maximum_base_records=maximum,type_query_counts=dict(combinations),matrix_type_fields={k:dict(v)for k,v in descriptors.items()},mapped_matrix_models=dict(models),model_roster_extent_counts=dict(roster_extents),original_word_audits=proof,records_sha256=sha(out/'records.json'),game_launched=False,live_process_access=False,installed_in_game=False,limitations=['Base input counts do not prove total pool demand after helper-created/runtime proxies.','This is bounded source/asset inventory, not an implemented complete importer or unified owner.','Model roster extents are declared data-object bounds; no arbitrary bytes are interpreted as script code.','Stock files and static metadata do not prove all runtime state mutations or all reachable branches.']);(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:result[k]for k in ['status','rooms','records','maximum_base_records','type_query_counts','matrix_type_fields','mapped_matrix_models','model_roster_extent_counts']}))
if __name__=='__main__':main()
