"""Package bounded hash-verified room sections for independent native tests."""
import argparse,hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 inv=ROOT/'build-native-sjuni/gameplay-script-content-llvm-v13/inventory.json';receipt=inv.parent/'receipt.json';ir=json.loads(receipt.read_text());assert ir['status']=='passed'and ir['output_sha256']['inventory.json']==sha(inv)
 packed=[];assets=[]
 for row in json.loads(inv.read_text()):
  if row['format']!='R':continue
  with Path(row['archive']).open('rb')as f:f.seek(row['archive_offset']);data=f.read(row['bytes'])
  assert hashlib.sha256(data).hexdigest()==row['sha256'];pieces=[]
  for index in [10,1]:
   at,n=struct.unpack_from('<II',data,8*index);assert n and at<=len(data)and n<=len(data)-at;pieces.append(data[at:at+n])
  section,script=pieces;name=row['name'];m=re.search(r'r(\d{3})(\d{2})(\d{2})\.rdt',name,re.I);assert m;scenario,room,variant=map(int,m.groups());encoded=name.encode();count=struct.unpack_from('<I',section,4)[0]
  packed.append(struct.pack('<5I',scenario,room,len(section),len(script),len(encoded))+section+script+encoded);assets.append(dict(name=name,member=row['member'],scenario=scenario,room=room,variant=variant,sha256=row['sha256'],section_a_sha256=hashlib.sha256(section).hexdigest(),script_section_sha256=hashlib.sha256(script).hexdigest(),base_records=count))
 assert len(assets)==166 and sum(r['base_records']for r in assets)==2144
 out.mkdir();package=out/'room_scene_inputs.bin';package.write_bytes(b'RSI1'+struct.pack('<I',len(packed))+b''.join(packed));r=dict(status='passed',collector_sha256=sha(Path(__file__)),inventory_receipt=dict(path=receipt.relative_to(ROOT).as_posix(),sha256=sha(receipt)),inventory_sha256=sha(inv),assets=assets,package_sha256=sha(package),rooms=len(assets),base_records=sum(r['base_records']for r in assets),game_launched=False,installed_in_game=False);(out/'receipt.json').write_text(json.dumps(r,indent=2)+'\n');print(json.dumps(dict(status='passed',rooms=166,base_records=2144,package_bytes=package.stat().st_size,package_sha256=sha(package))))
if __name__=='__main__':main()
