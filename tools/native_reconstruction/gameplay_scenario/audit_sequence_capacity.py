"""Bounded sequence-owner capacity from checked loader and owned RDT assets."""
import argparse,hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main(a):
 out=a.output.resolve();assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
 source=next((ROOT/'recomp/config/output_ovl/o2').glob('o2_005BE3E0_*'));raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes()
 assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 comments=0
 for pc,word in re.findall(r'// (0x[0-9a-f]+): (0x[0-9a-f]+)\s',source.read_text()):assert struct.unpack_from('<I',raw,int(pc,16)-0x570000)[0]==int(word,16);comments+=1
 base=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1';index=json.loads((base/'receipt.json').read_text());assert index['status']=='passed'
 for n,digest in index['output_sha256'].items():assert sha(base/n)==digest
 members=json.loads((base/'members.json').read_text());containers={x['path']:x for x in json.loads((base/'containers.json').read_text())}
 rows=[]
 for m in members:
  if not m['names'] or not m['names'][-1].lower().endswith('.rdt'):continue
  c=containers[m['container']];offset=m['iso_offset']-c['offset']
  with (a.data_root/m['container']).open('rb') as h:h.seek(offset);b=h.read(m['bytes'])
  assert hashlib.sha256(b).hexdigest()==m['sha256'];at,n=struct.unpack_from('<II',b);assert not n or at+n<=len(b)
  row=dict(name=m['names'][-1],rdt_sha256=m['sha256'],section_offset=at,section_size=n)
  if n:
   s=b[at:at+n];assert len(s)>=8;version,count=struct.unpack_from('<IH',s);row.update(version=version,count=count);assert 8+4*count<=len(s)
   refs=struct.unpack_from('<'+'I'*count,s,8) if count else [];assert all(x+4<=len(s) for x in refs)
   row['record_types']=[struct.unpack_from('<I',s,x)[0] for x in refs]
  rows.append(row)
 result=dict(status='passed',rdt_count=len(rows),present=sum(bool(r['section_size']) for r in rows),max_count=max(r.get('count',0) for r in rows),over32=[r['name'] for r in rows if r.get('count',0)>32],rows=rows,
  loader_clear_bytes=0x3334,header_bytes=0x34,stride_bytes=0x198,cleared_record_capacity=32,
  loader_source=dict(path=source.relative_to(ROOT).as_posix(),sha256=sha(source),checked_owned_instruction_comments=comments),
  source_pcs=dict(clear_size='5BE3EC',clear_call='5BE420',clear_destination_delay_slot='5BE424',count_read='5BE42C',count_store='5BE478'),
  loader_algorithm_executed=False,game_launched=False,limitations=['Capacity inferred from checked loader clear/stride and audited owned content; not a port of complete sequence record parsing or playback.','Stock observed max26 is not a proof that larger records are unreachable in all modes/content. Native32 capacity is explicit admission.'])
 (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:v for k,v in result.items() if k not in ['rows','limitations','loader_source']}))
if __name__=='__main__':
 p=argparse.ArgumentParser();p.add_argument('--output',required=True,type=Path);p.add_argument('--data-root',required=True,type=Path);main(p.parse_args())
