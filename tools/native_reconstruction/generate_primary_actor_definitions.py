"""Reproduce the eight owned default primary actor statistic and contact profiles."""
import argparse,hashlib,json,struct
from pathlib import Path
from audit_retail_effect_descriptors import compare_source
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni')
    overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=overlay.read_bytes();read=lambda at,n:raw[at-0x570000:at-0x570000+n]
    source=ROOT/'recomp/config/output_ovl/o2/o2_0066A750_0x66a750.cpp';proof=compare_source('complete primary initialization and restore body',source.relative_to(ROOT).as_posix(),0x66a750,0x66ac48,read)
    rows=[];text='// Exact default primary profiles from owned File1 o2.\nconstexpr std::array<PrimaryDefaultDefinition,8> primary_default_definitions{{\n';f=lambda bits:'std::bit_cast<float>('+hex(bits)+'u)'
    for c in range(8):
        style=struct.unpack('<b',read(0x71adf0+c,1))[0];subtype=read(0x71adf8+c,1)[0];health=struct.unpack('<h',read(0x71b020+2*c,2))[0];scales=struct.unpack('<3I',read(0x71ae00+12*c,12));height=struct.unpack('<I',read(0x71ae60+4*c,4))[0]
        header=struct.unpack('<I',read(0x71bdc0+4*c,4))[0];contact=struct.unpack('<I',read(header,4))[0];hits=[]
        for index in range(32):
            record=struct.unpack('<5I',read(contact+20*index,20))
            if record[3]==0xbf800000:break
            hits.append(record)
        else:raise ValueError('Primary contact list lacks bounded terminator')
        assert len(hits)==4
        text+='    {'+','.join(map(str,[style,subtype,health]))+',{'+','.join(map(f,scales))+'},'+f(height)+',{{'+','.join('{{'+','.join(map(f,r[:3]))+'},'+f(r[3])+','+str(r[4])+'}'for r in hits)+'}}},\n'
        rows.append(dict(character=c,style=style,subtype=subtype,health=health,scale_bits=scales,height_bits=height,contact_header=hex(header),contact_address=hex(contact),contact_bytes=read(contact,100).hex()))
    text+='}};\n';target=ROOT/'game/native/gameplay_world/primary_actor_definitions.inc'
    if target.exists():assert target.read_text()==text
    else:target.write_text(text)
    out.mkdir();(out/'receipt.json').write_text(json.dumps(dict(schema=1,status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},overlay_sha256=sha(overlay),original_owned_body=proof,rows=rows,output_sha256=sha(target),game_run=False),indent=2)+'\n');print(json.dumps(dict(status='passed',characters=len(rows),output_sha256=sha(target))))
if __name__=='__main__':main()
