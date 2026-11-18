"""Pin cinematic object bundles, constructor words and cold material metadata."""
import argparse,hashlib,json,re,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source,elf_reader
from verify_actor_assets import skeleton_nodes,model_parts
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def material_count(payload):
 offset,length=struct.unpack_from('<II',payload,0x14)
 if not offset:return 0
 raw=payload[offset:offset+length];assert len(raw)==length;count=struct.unpack_from('<I',raw,4)[0];at=12
 for _ in range(count):
  kind,number,size=struct.unpack_from('<III',raw,at);assert size>=12 and at+size<=len(raw)
  if kind==9:return number
  at+=size
 return 0
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
 elf=ROOT/'game_data/SLUS_207.65';assert sha(elf)=='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46';read=elf_reader(elf.read_bytes());overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';two=overlay.read_bytes();proof=[];sources={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__)), 'tools/native_reconstruction/verify_actor_assets.py':sha(ROOT/'tools/native_reconstruction/verify_actor_assets.py')}
 for at in [0x1d13f0,0x1d25b0,0x1d27d0,0x1d2c00,0x1cdfe0,0x1ce110,0x1aaad0,0x1a31b0,0x1a32b0,0x1a33b0,0x1d3540,0x571010]:
  path=next((ROOT/'recomp/config/output_ovl/o2'if at>=0x570000 else ROOT/'recomp/config/output').glob(f'{"o2"if at>=0x570000 else "sub"}_{at:08X}_*'));name=path.relative_to(ROOT).as_posix();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',path.read_text()).groups()];proof.append(compare_source('complete cinematic object constructor/material/skeleton authority',name,begin,end,read if begin<0x570000 else lambda at,n:two[at-0x570000:at-0x570000+n]));sources[name]=sha(path)
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';assert sha(inventory)=='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2';members=[x for x in json.loads(inventory.read_bytes())if any(re.fullmatch(r'OBJ\d{2}_\d{2}_[a-z]_\d+\.NBD',n,re.I)for n in x['names'])];assert len(members)==452
 payloads=[];rows=[]
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as iso:
  for item in members:
   iso.seek(item['iso_offset']);payload=iso.read(item['bytes']);assert hashlib.sha256(payload).hexdigest()==item['sha256'];name=next(n for n in item['names']if re.fullmatch(r'OBJ\d{2}_\d{2}_[a-z]_\d+\.NBD',n,re.I));match=re.fullmatch(r'OBJ(\d{2})_(\d{2})_([a-z])_(\d+)\.NBD',name,re.I);mats=material_count(payload);parts=model_parts(payload);nodes=skeleton_nodes(payload);assert mats<=3 and nodes<=25
   canonical='obj%02d_%02d_%s_%02d.nbd'%(int(match[1]),int(match[2]),match[3].lower(),int(match[4]));assert re.fullmatch(r'r\d{3}\.afs',item['names'][0],re.I)
   rows.append(dict(package_index=len(payloads),member=item['member'],name=name,scenario=int(item['names'][0][1:4]),request=[int(match[1]),int(match[2]),ord(match[3].lower())-97],model=int(match[4]),canonical_request_name=canonical,canonical_name_matches=canonical==name.lower(),bytes=item['bytes'],sha256=item['sha256'],parts=parts,materials=mats,first_root_nodes=nodes,cold_unused_material_scale_bits=[0,0,0]));payloads.append(payload)
 package=struct.pack('<I',len(payloads))+b''.join(struct.pack('<I',len(raw))+raw for raw in payloads);out.mkdir();(out/'owned_objects.bin').write_bytes(package);(out/'owned_objects.json').write_text(json.dumps(rows,indent=2)+'\n')
 stats=dict(bundles=len(rows),skeletons=sum(bool(x['first_root_nodes'])for x in rows),absent_skeletons=sum(not x['first_root_nodes']for x in rows),maximum_materials=max(x['materials']for x in rows),maximum_parts=max(x['parts']for x in rows),maximum_first_root_nodes=max(x['first_root_nodes']for x in rows),canonical_names=sum(x['canonical_name_matches']for x in rows))
 result=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,original_owned_bodies=proof,inventory_sha256=sha(inventory),stats=stats,output_sha256={n:sha(out/n)for n in ['owned_objects.bin','owned_objects.json']},cold_profile_contract=['571010 clears the complete object record before construction.','Model work starts at record70.1D25B0 writes halfword material indices at work8+2*i; source attachment reads objectB4/B8/BC, aliasing material indices30..35.','All452 named cinematic bundles declare at most3 materials. Their cold construction leaves these six unused indices zero; native code must retain a semantic zero-gain profile, not a simulated work buffer.','1D13F0 selects root0 through1CDFE0/1D2C00, independently of other raw forest roots.'],limits=['Static constructor authority and actual owned bundle data, not an actual game recording.','The cold invariant must be paired with controlled original constructor/material/skeleton execution before real caller admission.','One bundle declares14 parts despite the literal8 model-work allocation request. Native import preserves the count; allocator reuse and actual rendering capacity are not inferred.','No model instance is fabricated for the two absent skeleton sections. Runtime scene admission and renderer consumption remain separate.'])
 (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(stats))
if __name__=='__main__':main()
