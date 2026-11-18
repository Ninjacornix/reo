"""Extract exact object-motion ROM aliases without relying on duplicate names."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());aliases=[];rows=[]
 for ordinal in range(1342):
  address=struct.unpack('<I',read(0x2322c0+4*ordinal,4))[0];raw=bytearray()
  for i in range(256):
   value=read(address+i,1)[0]
   if not value:break
   raw.append(value^255)
  else:raise ValueError('Unbounded owned ROM alias')
  alias=raw.decode('ascii');aliases.append(alias);match=re.fullmatch(r'MOTION_DEMO_R(\d{3})_B(\d{2})_BIN',alias)
  if match:rows.append(dict(scenario=int(match[1]),area=int(match[2]),member=ordinal,alias=alias))
 assert len(set(aliases))==1342 and len(rows)==52 and len({(r['scenario'],r['area'])for r in rows})==52
 text='// File1 owned object-motion ROM aliases; AFS display names are not identities.\nconstexpr std::array<CinematicObjectMotionMember,52> cinematic_object_motion_members{{\n'+''.join('    {'+','.join(str(row[k])for k in ['scenario','area','member'])+'},\n'for row in rows)+'}};\n';proof=[];sources={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))}
 for at in [0x1d1e00,0x1d1960,0x1cc8f0,0x1aa480,0x1aa110,0x1ab050]:
  path=next((ROOT/'recomp/config/output').glob(f'sub_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete cinematic object bank load/parse/ROM authority',name,begin,end,read));sources[name]=sha(path)
 fmt=read(0x2564c0,100).split(b'\0')[0].decode('ascii');assert fmt==r'data\rom\motion\demo\r%03d\b%02d.bin';out.mkdir();(out/'cinematic_object_motion_members.inc').write_text(text)
 receipt=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,elf_sha256=sha(elf),alias_table_sha256=hashlib.sha256('\n'.join(aliases).encode()).hexdigest(),original_owned_bodies=proof,format=fmt,rows=rows,output_sha256={'cinematic_object_motion_members.inc':sha(out/'cinematic_object_motion_members.inc')},limits=['Static member authority only; no game run, live bank publication or clip playback.','Actual52 bank reads, failed-read retention and scene caller ownership must be qualified separately.'])
 (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n');print(json.dumps(dict(members=len(rows),sha256=receipt['output_sha256'])))
if __name__=='__main__':main()
