"""Bind NPC construction metadata to owned aliases and witnessed scene headers."""
import argparse,hashlib,json,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    aliases=ROOT/'build-native-sjuni/npc-actor-member-profile-v1/receipt.json';profile=json.loads(aliases.read_bytes());assert profile['status']=='passed'and sha(ROOT/'game/native/gameplay_world/npc_actor_members.inc')==profile['output_sha256']
    identifiers={int(row['name'][1:-4])+1 for row in profile['rows']if row['name'].startswith('N')};assert len(identifiers)==125
    inventory=ROOT/'build-native-sjuni/cutscene-descriptor-inventory-v2/receipt.json';receipt=json.loads(inventory.read_bytes());package=inventory.parent/'owned_descriptors.bin';assert sha(package)==receipt['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
    raw=package.read_bytes();at=4;blocks=[]
    for _ in range(struct.unpack_from('<I',raw)[0]):length=struct.unpack_from('<I',raw,at)[0];at+=4;blocks.append(raw[at:at+length]);at+=length
    witnesses=[]
    for row in receipt['rows']:
        if row['status']!='bounded_layout':continue
        for group,sections in enumerate(row['layout']['actors']):
            timestamp,kind,identity=struct.unpack_from('<HhH',blocks[row['package_index']],sections[7]['offset']+2)
            if timestamp!=65535 and kind==1:identifiers.add(identity);witnesses.append(dict(scenario=row['scenario'],name=row['name'],member_sha256=row['sha256'],group=group,id=identity))
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes()
    source=ROOT/'recomp/config/output_ovl/o2/o2_006837C0_0x6837c0.cpp';proof=compare_source('complete NPC constructor metadata authority',source.relative_to(ROOT).as_posix(),0x6837c0,0x683a88,lambda at,n:raw[at-0x570000:at-0x570000+n])
    rows=[];lines=['// Owned File1 NPC construction rows. Reproduce with generate_npc_actor_definitions.py.','constexpr std::array<NpcDefinitionRecord,'+str(len(identifiers))+'> npc_definitions{{']
    for identifier in sorted(identifiers):
        at=0x716450+20*identifier-0x570000;block=raw[at:at+20];assert len(block)==20
        model_id=struct.unpack_from('<H',block)[0];style,subtype,contact=block[2:5];health=struct.unpack_from('<h',block,6)[0];scale,height=struct.unpack_from('<II',block,8)
        lines.append('    {'+','.join(map(str,(identifier,model_id,style,subtype,contact,health)))+',std::bit_cast<float>('+hex(scale)+'u),std::bit_cast<float>('+hex(height)+'u)},')
        rows.append(dict(id=identifier,address=hex(at+0x570000),bytes=block.hex(),filename_witness=any(row['name']=='N'+str(identifier-1).zfill(2)+'.NBD' for row in profile['rows'])))
    lines.append('}};');target=ROOT/'game/native/gameplay_world/npc_actor_definitions.inc'
    if target.exists():assert target.read_text()=='\n'.join(lines)+'\n'
    else:target.write_text('\n'.join(lines)+'\n')
    root=struct.unpack_from('<I',raw,0x716440-0x570000)[0];hit_rows=[];hit_text=[]
    for index in range(16):
        record=raw[root-0x570000+20*index:root-0x570000+20*(index+1)];x,y,z,radius,joint=struct.unpack('<5I',record)
        if radius==0xbf800000:break
        hit_rows.append(dict(address=hex(root+20*index),bytes=record.hex()))
        f=lambda value:'std::bit_cast<float>('+hex(value)+'u)'
        hit_text.append('    {{'+','.join(map(f,[x,y,z]))+'},'+f(radius)+','+str(joint)+'},')
    else:raise ValueError('NPC hit profile lacks bounded terminal')
    hit_target=ROOT/'game/native/gameplay_world/npc_actor_hit_definitions.inc';hit_data='// Owned File1 default NPC hit definitions.\nconstexpr std::array<gameplay_collision::hit_regions::Definition,'+str(len(hit_rows))+'> npc_hit_definitions{{\n'+'\n'.join(hit_text)+'\n}};\n'
    if hit_target.exists():assert hit_target.read_text()==hit_data
    else:hit_target.write_text(hit_data)
    out.mkdir();result=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},original_owned_body=proof,alias_profile=dict(path=str(aliases),sha256=sha(aliases)),descriptor_inventory=dict(path=str(inventory),sha256=sha(inventory)),rows=rows,scene_witnesses=witnesses,hit_rows=hit_rows,hit_output_sha256=sha(hit_target),output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',definitions=len(rows),scene_headers=len(witnesses),output_sha256=sha(target))))
if __name__=='__main__':main()
