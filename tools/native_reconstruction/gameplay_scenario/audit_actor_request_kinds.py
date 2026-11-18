"""Owned conservative-prefix actor request producer inventory; no arbitrary scan."""
import argparse,collections,hashlib,json,shutil,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--inventory',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni')
 inventory=a.inventory.resolve();receipt_path=inventory.parent/'receipt.json';receipt=json.loads(receipt_path.read_text());assert receipt['status']=='passed' and receipt['output_sha256'][inventory.name]==sha(inventory)
 records=json.loads(inventory.read_text());rows=[];counts={k:collections.Counter()for k in ['ordinary','offline_actor']};source_stamps={}
 for record in records:
  candidates=[(profile['profile'],candidate)for profile in record['profiles']for candidate in profile.get('candidate_records',[])if candidate['opcode']in[0x100,0x109]]
  if not candidates:continue
  archive=Path(record['archive']);stamp=(archive.stat().st_size,archive.stat().st_mtime_ns);source_stamps[str(archive)]=stamp
  with archive.open('rb')as f:f.seek(record['archive_offset']);raw=f.read(record['bytes'])
  assert hashlib.sha256(raw).hexdigest()==record['sha256']
  if record['format']=='R':offset,size=struct.unpack_from('<II',raw,8);assert size and offset<=len(raw) and size<=len(raw)-offset;bank=raw[offset:offset+size]
  else:bank=raw
  for profile,candidate in candidates:
   at=candidate['offset'];header=struct.unpack_from('<I',bank,at)[0];op=header&0xffffff;span=((1<<((header>>24)&31))*4)&0xffffffff;assert op==candidate['opcode'] and span and at+span<=len(bank)
   minimum=8 if op==0x100 else 12
   if span<minimum:rows.append(dict(member=record['member'],name=record['name'],profile=profile,offset=at,opcode=f'{op:03X}',refusal='truncated_source_request_payload'));continue
   authored=struct.unpack_from('<I',bank,at+4)[0];kind=authored&255;parameter=65535 if op==0x100 else struct.unpack_from('<I',bank,at+8)[0]&65535
   counts[profile][str(kind)]+=1;rows.append(dict(member=record['member'],name=record['name'],profile=profile,offset=at,opcode=f'{op:03X}',authored_word=authored,kind=kind,parameter=parameter,member_sha256=record['sha256'],runtime_reachability_proven=False))
 for path,stamp in source_stamps.items():assert (Path(path).stat().st_size,Path(path).stat().st_mtime_ns)==stamp
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';raw=overlay.read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';table=raw[0x711960-0x570000:0x7119c0-0x570000];assert hashlib.sha256(table).hexdigest()=='fbe1b3768e82f0497eb111dbdb3c39bc407fd6ba6b54746ee8c8b19f29d9f5ff'
 out.mkdir();shutil.copyfile(Path(__file__),out/Path(__file__).name);(out/'requests.json').write_text(json.dumps(rows,indent=2)+'\n');result=dict(status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},inventory_receipt=dict(path=receipt_path.relative_to(ROOT).as_posix(),sha256=sha(receipt_path)),inventory_sha256=sha(inventory),request_kind_counts={k:dict(v)for k,v in counts.items()},physical_24_callback_targets=[f'{x:08X}'for x in struct.unpack('<24I',table)],callback_table_sha256=hashlib.sha256(table).hexdigest(),rows=len(rows),output_sha256={'requests.json':sha(out/'requests.json')},game_launched=False,live_process_access=False,runtime_reachability_proven=False,limitations=['Only records reached by the prior bounded conservative prefix graph are inspected. Unsupported predecessors hide additional producers.','Both profiles and alternate paths overlap; counts are not gameplay frequencies.','The physical 24-pointer window is not proof of all possible runtime request kinds or bounds.','No actor command callback or request was executed.']);(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(result))
if __name__=='__main__':main()

