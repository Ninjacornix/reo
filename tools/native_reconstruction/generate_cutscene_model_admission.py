"""Admit only owned0950-witnessed model indices beyond declared table groups."""
import argparse,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--inventory',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    inventory=a.inventory/'receipt.json';receipt=json.loads(inventory.read_bytes());assert receipt['status']=='static_layout_inventory'
    package=a.inventory/'owned_descriptors.bin';assert sha(package)==receipt['package_sha256']=='047d14cca0b28ad1f4335660db09389a525679c313f1841bfda1779c2c49629c'
    payload=package.read_bytes();at=4;blocks=[]
    for _ in range(struct.unpack_from('<I',payload)[0]):length=struct.unpack_from('<I',payload,at)[0];at+=4;blocks.append(payload[at:at+length]);at+=length
    assert at==len(payload)
    overlay=ROOT/'build-function-index/owned-overlays/o0.bin';assert sha(overlay)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';raw=overlay.read_bytes()
    roots=[struct.unpack_from('<II',raw,0x387e90-0x370000+8*i)for i in range(62)]
    pointers=sorted({pointer for pointer,count in roots if pointer}|{0x387e90})
    spans={pointer:max((pointers[i+1]-pointer)//16,max(count for root,count in roots if root==pointer))for i,pointer in enumerate(pointers[:-1])}
    witnessed={}
    for row in receipt['rows']:
        if row['status']!='bounded_layout':continue
        data=blocks[row['package_index']]
        for group,sections in enumerate(row['layout']['actors']):
            pos=sections[7]['offset'];timestamp,kind,code=struct.unpack_from('<Hhh',data,pos+2)
            if timestamp==65535 or kind!=2:continue
            type_id=int(code/100)&255;variant=(code-int(code/100)*100)&255
            assert type_id<len(roots);pointer,count=roots[type_id];assert pointer
            if variant<spans[pointer]:continue
            witnessed.setdefault((type_id,variant),[]).append(dict(scenario=row['scenario'],name=row['name'],group=group,member_sha256=row['sha256']))
    assert set(witnessed)=={(0,i)for i in [10,14,48,49,50,51,52]}
    lines=['// Exact owned0950-witnessed rows. Reproduce with generate_cutscene_model_admission.py.',
           'struct CutsceneModelDefinition {std::uint8_t type;std::uint16_t variant;LinkedModelDefinition value;};',
           'constexpr std::array<CutsceneModelDefinition,7> cutscene_model_definitions{{'];rows=[]
    for (type_id,variant),evidence in sorted(witnessed.items()):
        address=roots[type_id][0]+16*variant;offset=address-0x370000;assert 0<=offset<=len(raw)-16
        model,texture,sound=struct.unpack_from('<3B',raw,offset);scale=struct.unpack_from('<I',raw,offset+8)[0];visibility=struct.unpack_from('<b',raw,offset+12)[0];construction=raw[offset+4];shadow,shadow_asset=struct.unpack_from('<bh',raw,offset+13)
        lines.append('    {'+str(type_id)+','+str(variant)+',{'+','.join(map(str,(model,texture,sound)))+',std::bit_cast<float>('+hex(scale)+'u),'+','.join(map(str,(visibility,construction,shadow,shadow_asset)))+'}},')
        rows.append(dict(type=type_id,variant=variant,address=hex(address),bytes=raw[offset:offset+16].hex(),witnesses=evidence))
    lines.append('}};');target=ROOT/'game/native/gameplay_world/cutscene_model_definitions.inc';target.write_text('\n'.join(lines)+'\n')
    out.mkdir();record=dict(schema=1,status='passed',inventory=dict(path=str(inventory),sha256=sha(inventory)),overlay_sha256=sha(overlay),source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},rows=rows,output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',admitted_rows=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
