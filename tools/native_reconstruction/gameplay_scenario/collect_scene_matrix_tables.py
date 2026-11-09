"""Independently decode immutable owned scene matrix programs/curves/sounds."""
import argparse,hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];BASE=0x570000
EXPECTED='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
def digest(b):return hashlib.sha256(b).hexdigest()
def sha(p):return digest(p.read_bytes())
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);p.add_argument('--emit',type=Path);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');image=ROOT/'build-function-index/owned-overlays/o2.bin';raw=image.read_bytes();assert digest(raw)==EXPECTED
 def read(at,n):assert BASE<=at<=BASE+len(raw)and n<=BASE+len(raw)-at;return raw[at-BASE:at-BASE+n]
 def pointers(at,n):return struct.unpack('<'+str(n)+'I',read(at,n*4))
 programs=[];raw_programs=[]
 for i,at in enumerate(pointers(0x721ab0,36)):
  assert at==0x721990+8*i;data=read(at,8);end=data.index(255);assert 1<end<=7 and data[0]<=3 and all(g<59 for g in data[1:end]);programs.append(dict(transform=data[0],groups=list(data[1:end])));raw_programs.append(dict(address=f'{at:08X}',sha256=digest(data)))
 curve_refs=pointers(0x721b40,236);sound_refs=pointers(0x721fe0,236);curves_at=sorted(set(curve_refs));sounds_at=sorted(set(sound_refs)-{0});assert len(curves_at)==64 and len(sounds_at)==13
 def sequence(at,curve):
  rows=[];position=0;previous=None
  while True:
   value,time=struct.unpack('<Ii',read(at+position*8,8));position+=1
   if time==-1:break
   assert position<=64 and (previous is None or time>previous);previous=time
   if curve:assert struct.unpack('<f',struct.pack('<I',value))[0]==struct.unpack('<f',struct.pack('<I',value))[0]
   rows.append(dict(value_bits=value,time=time)if curve else dict(event=value,time=time))
  if curve:assert len(rows)>=2
  return rows,dict(address=f'{at:08X}',bytes=position*8,sha256=digest(read(at,position*8)))
 curves=[];sounds=[];authorities=[]
 for at in curves_at:r,proof=sequence(at,True);curves.append(r);authorities.append(proof)
 for at in sounds_at:r,proof=sequence(at,False);sounds.append(r);authorities.append(proof)
 groups=[dict(curves=[curves_at.index(v)for v in curve_refs[4*i:4*i+4]],sounds=[sounds_at.index(v)if v else-1 for v in sound_refs[4*i:4*i+4]])for i in range(59)]
 tables=dict(descriptors=list(read(0x70b190,4)),metadata=[list(v)for v in struct.iter_unpack('<BB',read(0x7218d0,128))],direct_remap=list(read(0x721950,64)),programs=programs,groups=groups,curves=curves,sounds=sounds)
 lines=['// Immutable native values decoded from the hash-verified owned File #1 asset.','namespace {']
 for i,keys in enumerate(curves):lines.append('constexpr std::array<SceneMatrixKey,'+str(len(keys))+'> curve_'+str(i)+'{{'+','.join('{std::bit_cast<float>(0x%08xu),%d}'%(k['value_bits'],k['time'])for k in keys)+'}};')
 for i,events in enumerate(sounds):lines.append('constexpr std::array<SceneMatrixSound,'+str(len(events))+'> sound_'+str(i)+'{{'+','.join('{0x%08xu,%d}'%(k['event'],k['time'])for k in events)+'}};')
 lines+=['const SceneMatrixTables tables{',' {'+','.join(str(v)for v in tables['descriptors'])+'},',' {{'+','.join('{%d,%d}'%tuple(v)for v in tables['metadata'])+'}},',' {'+','.join(str(v)for v in tables['direct_remap'])+'},',' {{'+','.join('{%d,%d,{%s}}'%(p['transform'],len(p['groups']),','.join(str(v)for v in p['groups']))for p in programs)+'}},',' {{'+','.join('{{%s},{%s}}'%(','.join(str(v)for v in g['curves']),','.join(str(v)for v in g['sounds']))for g in groups)+'}},',' {'+','.join('curve_'+str(i)for i in range(64))+'},',' {'+','.join('sound_'+str(i)for i in range(13))+'}','};','}']
 generated='\n'.join(lines)+'\n';out.mkdir();(out/'tables.json').write_text(json.dumps(tables,indent=2)+'\n');(out/'scene_matrix_program_tables.inc').write_text(generated)
 if a.emit:assert not a.emit.exists();a.emit.write_text(generated)
 result=dict(status='passed',source_sha256={Path(__file__).relative_to(ROOT).as_posix():sha(Path(__file__))},owned_overlay_sha256=EXPECTED,programs=36,groups=59,curves=64,keys=sum(map(len,curves)),sound_lists=13,sound_events=sum(map(len,sounds)),descriptor_profile_bytes=4,table_span_sha256={f'{at:08X}:{n:X}':digest(read(at,n))for at,n in [(0x70b190,4),(0x7218d0,128),(0x721950,64),(0x721990,288),(0x721ab0,144),(0x721b40,944),(0x721fe0,944)]},program_authorities=raw_programs,curve_and_sound_authorities=authorities,output_sha256={name:sha(out/name)for name in ['tables.json','scene_matrix_program_tables.inc']},game_launched=False,live_process_access=False,limitations=['The four-byte descriptor profile is explicit native admission, not proof of arbitrary runtime source indices.','Immutable data decoding does not implement playback, sound requests, native model binding or whole scene ownership.','Original addresses exist only in this offline evidence; generated native values contain no guest pointers.']);(out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n');print(json.dumps({k:result[k]for k in ['status','programs','groups','curves','keys','sound_lists','sound_events']}))
if __name__=='__main__':main()
