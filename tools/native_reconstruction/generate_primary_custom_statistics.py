"""Recover the initialized o0 custom-actor table and its owned o2 statistics."""
import argparse,hashlib,json,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    o0=ROOT/'build-function-index/owned-overlays/o0.bin';o2=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(o0)=='bfac1906d63d585736e46573295cff12e308720af6b49914e1ad8695dfcf50c2';assert sha(o2)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';zero=o0.read_bytes();two=o2.read_bytes();read=lambda at,n:two[at-0x570000:at-0x570000+n]
    proof=[]
    for address in [0x669860,0x603110,0x6dd7f0]:
        source=ROOT/f'recomp/config/output_ovl/o2/o2_{address:08X}_0x{address:x}.cpp';import re
        begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',source.read_text()).groups()];proof.append(compare_source('complete initialized custom-actor table consumer',source.relative_to(ROOT).as_posix(),begin,end,read))
    rows=[];raw_rows=[]
    for index in range(512):
        at=0x3898e0-0x370000+12*index;raw=zero[at:at+12];assert len(raw)==12;identity,classification,health,fraction,rate,multiplier,pad,damage=struct.unpack('<H6BI',raw)
        rows.append(dict(identity=identity,classification=classification,health_band=health,fraction_band=fraction,gauge_rate=rate,multiplier_band=multiplier,damage_bits=damage,bytes=raw.hex()));raw_rows.append(raw)
        if identity==999:break
    else:raise ValueError('No bounded custom-actor terminal')
    assert len(rows)==91 and len({r['identity']for r in rows})==91 and b''.join(raw_rows)[-12:]==bytes.fromhex('e70300000000000000000000')
    profile_path=ROOT/'build-native-sjuni/npc-actor-definition-profile-v3/receipt.json';profile=json.loads(profile_path.read_bytes());assert profile['status']=='passed'and sha(ROOT/'game/native/gameplay_world/npc_actor_definitions.inc')==profile['output_sha256']
    definitions=[]
    for row in profile['rows']:
        identity=row['id'];mask=struct.unpack('<I',read(0x716450+20*identity+16,4))[0];definitions.append(dict(variant=identity+1,hidden_parts=mask))
    f=lambda value:'std::bit_cast<float>('+hex(value)+'u)'
    text='// Initialized File1 o0 custom-actor rows; terminal fallback is intentional.\nconstexpr std::array<PrimaryCustomStatisticRow,91> primary_custom_statistic_rows{{\n'
    for row in rows:text+='    {'+','.join(str(row[k])for k in ['identity','classification','health_band','fraction_band','gauge_rate','multiplier_band'])+','+f(row['damage_bits'])+'},\n'
    text+='}};\nconstexpr std::array<PrimarySubstitutionDefinition,'+str(len(definitions))+'> primary_substitution_definitions{{\n'+''.join('    {'+str(row['variant'])+','+hex(row['hidden_parts'])+'u},\n'for row in definitions)+'}};\n'
    bands=[struct.unpack('<hh',read(0x71ad30+4*i,4))for i in range(8)];fraction_bits=struct.unpack('<8I',read(0x71ad50,32));multiplier_bits=struct.unpack('<8I',read(0x71acf0,32))
    assert all(high>=low for low,high in bands)
    text+='constexpr std::array<std::array<std::int16_t,2>,8> primary_custom_health_bands{{'+','.join('{{'+str(low)+','+str(high)+'}}'for low,high in bands)+'}};\n'
    text+='constexpr std::array<float,8> primary_custom_fractions{'+','.join(map(f,fraction_bits))+'};\nconstexpr std::array<float,8> primary_custom_multipliers{'+','.join(map(f,multiplier_bits))+'};\n'
    target=ROOT/'game/native/gameplay_world/primary_custom_statistics.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();result=dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},overlay_sha256=dict(o0=sha(o0),o2=sha(o2)),table=dict(address='0x3898e0',bytes=91*12,sha256=hashlib.sha256(b''.join(raw_rows)).hexdigest()),original_owned_bodies=proof,rows=rows,definitions=definitions,health_bands=bands,fraction_bits=fraction_bits,multiplier_bits=multiplier_bits,definition_profile=dict(path=str(profile_path),sha256=sha(profile_path)),output_sha256=sha(target),game_run=False)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status='passed',rows=len(rows),definitions=len(definitions),output_sha256=sha(target))))
if __name__=='__main__':main()
