"""Audit source-located room remaps and reachable-prefix transform selectors."""
import argparse,collections,hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main(a):
 out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 inventory_path=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v8/inventory.json';inventory=json.loads(inventory_path.read_text())
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 sources={};words=0
 for name in ['00581830','005D7D60','0068C570','00690600','00690640','00690700']:
  p=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_'+name+'_*'));text=p.read_text();sources[p.relative_to(ROOT).as_posix()]=sha(p)
  for pc,word in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',text):assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(word,16);words+=1
 rooms=[];bounds=collections.Counter();values=collections.Counter();presets=collections.Counter();logical=collections.Counter()
 for item in inventory:
  if item['format']!='R':continue
  with Path(item['archive']).open('rb') as f:f.seek(item['archive_offset']);data=f.read(item['bytes'])
  assert hashlib.sha256(data).hexdigest()==item['sha256'];start,length=struct.unpack_from('<II',data,8);assert length and start+length<=len(data);section=data[start:start+length]
  refs=struct.unpack_from('<16I',section);offset=refs[1];assert offset and offset>=64 and offset+32<=len(section)
  end=min([x for x in refs if x>offset]+[len(section)]);assert offset+32<=end
  mapping=list(section[offset:offset+32]);bounds[end-offset]+=1;values.update(mapping)
  records=[]
  for profile in item['profiles']:
   for candidate in profile['candidate_records']:
    if candidate['opcode'] not in [0xb0,0xb1,0xb4]:continue
    pc=candidate['offset'];header=struct.unpack_from('<I',section,pc)[0];assert header&0xffffff==candidate['opcode'];span=((1<<((header>>24)&31))*4)&0xffffffff;assert span>=8 and pc+span<=len(section)
    authored=section[pc+4];slot=mapping[authored] if authored<32 else 0;logical[(authored,slot)]+=1
    record=dict(profile=profile['profile'],opcode=f'{candidate["opcode"]:03X}',offset=pc,authored=authored,resolved=slot)
    if candidate['opcode']==0xb4:
     assert span>=12;index=struct.unpack_from('<I',section,pc+8)[0];record['preset']=index;presets[index]+=1
    records.append(record)
  rooms.append(dict(member=item['member'],name=item['name'],sha256=item['sha256'],section_offset=start,section_bytes=length,remap_offset=offset,remap_upper_bound=end-offset,remap_sha256=hashlib.sha256(bytes(mapping)).hexdigest(),remap=mapping,prefix_model_commands=records))
 proof=dict(status='passed',game_launched=False,installed_in_game=False,live_process_access=False,owned_rooms=len(rooms),inventory=dict(path=inventory_path.relative_to(ROOT).as_posix(),sha256=sha(inventory_path)),source_authority_sha256=sources,checked_owned_instruction_comments=words,
  remap_upper_bounds=dict(sorted(bounds.items())),remap_value_counts=dict(sorted(values.items())),prefix_transform_preset_counts=dict(sorted(presets.items())),prefix_resolutions=[dict(authored=k[0],resolved=k[1],occurrences=v) for k,v in sorted(logical.items())],rooms=rooms,
  limitations=['A declared next-object range is only an upper bound; exactly32 mapping bytes are read from the source-located tableindex1.','Prefix commands come from the conservative partial graph, not real runtime reachability or complete stock opcode usage.','Unused mapping bytes and source out-of-range pose accesses do not establish caller admission.','No model flags/poses were installed or rendered.'])
 (out/'receipt.json').write_text(json.dumps(proof,indent=2)+'\n');print(json.dumps({k:proof[k] for k in ['status','owned_rooms','remap_upper_bounds','remap_value_counts','prefix_transform_preset_counts']}))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);main(p.parse_args())
