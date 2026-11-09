"""Audit owned static grid route encodings without starting or attaching to the game."""
import argparse,hashlib,json,re,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(data):return hashlib.sha256(data).hexdigest()
def triangles(data):
 def word(at):
  if at<0 or at+4>len(data):raise ValueError('Grid read outside owned member')
  return struct.unpack_from('<I',data,at)[0]
 columns,rows=word(16),word(20)
 if not word(8)or not word(12)or not columns or not rows or columns*rows>1048576:raise ValueError('Invalid grid dimensions')
 directory,records=word(32)+8,word(36)+8
 if directory+columns*rows*4>len(data)or records>len(data):raise ValueError('Invalid grid directory')
 found={}
 for index in range(columns*rows):
  cursor=word(directory+4*index)+8
  for _ in range(len(data)//4):
   relative=word(cursor);cursor+=4
   if relative==0xffffffff:break
   at=records+relative
   if at+56>len(data):raise ValueError('Invalid triangle extent')
   found[relative]=word(at)
  else:raise ValueError('Unterminated grid list')
 return found
def main():
 p=argparse.ArgumentParser();p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve();allowed=(ROOT/'build-native-sjuni').resolve()
 if out.exists()or not out.is_relative_to(allowed):raise ValueError('Fresh private evidence output required')
 inventory=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1/members.json';raw=inventory.read_bytes()
 if sha(raw)!='276264fd0f5d14e8e0ef1e17f008560d611c6ca30c2ad811259a004b7a54fbc2':raise ValueError('Owned member inventory changed')
 assets=[];upper=[];sweep_upper=[];sweep_edges={};counts=dict(w=0,g=0,triangles=0,routable_triangles=0,upper_routes=0,upper_beyond23=0,sweep_primary_candidates=0,sweep_primary_beyond23=0)
 with (ROOT/'iso/Resident Evil - Outbreak (v2.00).iso').open('rb')as stream:
  for entry in json.loads(raw):
   names=[n for n in entry['names']if re.fullmatch(r'[wg][0-9]{7}\.bin',n)]
   if not names:continue
   stream.seek(entry['iso_offset']);data=stream.read(entry['bytes'])
   if len(data)!=entry['bytes']or sha(data)!=entry['sha256']:raise ValueError('Owned member changed')
   records=triangles(data);kind=names[0][0];counts[kind]+=1;counts['triangles']+=len(records)
   encodings={}
   for relative,flags in records.items():
    # 5DB320 primary radius query uses include24002: types1/14 plus
    # high20000. It decodes a route UNCONDITIONALLY on that query's hit,
    # unlike the later line/angular4002 test. This is only static admission.
    if kind=='w' and flags&255 in (1,14) and flags&0x20000:
     counts['sweep_primary_candidates']+=1;sweep_edge=((flags>>24)&15)+(0 if flags&2 else 16)
     sweep_edges[sweep_edge]=sweep_edges.get(sweep_edge,0)+1
     if sweep_edge>=24:
      counts['sweep_primary_beyond23']+=1;sweep_upper.append(dict(names=names,relative=relative,flags=flags,edge=sweep_edge,kind=kind))
    if not flags&0x4002:continue
    counts['routable_triangles']+=1;encoded=(flags>>24)&15;edge=encoded if flags&2 else encoded+16
    encodings[edge]=encodings.get(edge,0)+1
    if flags&2==0:
     counts['upper_routes']+=1
     if edge>=24:
      counts['upper_beyond23']+=1;upper.append(dict(names=names,relative=relative,flags=flags,edge=edge,kind=kind))
   assets.append(dict(names=names,bytes=entry['bytes'],sha256=entry['sha256'],triangles=len(records),route_edges=encodings))
 record=dict(schema=2,status='owned static line/angular and sweep-primary route admission audit; no live reachability claim',game_launched=False,process_attached=False,inventory_sha256=sha(raw),tool_sha256=sha(Path(__file__).read_bytes()),grid_import_source_sha256=sha((ROOT/'game/native/gameplay_collision/response.cpp').read_bytes()),counts=counts,assets=assets,line_angular_upper_beyond23=upper,sweep_primary_edges=sweep_edges,sweep_primary_beyond23=sweep_upper,limits=['Only static w/g members in the verified File1 inventory are covered','Line/angular flags4002 and sweep-primary include24002 are different admission paths','Dynamic authored polygons, transformed scene records and gameplay query filters remain separate admission gates','A potential encoded route does not prove a stock runtime query reaches that branch'])
 out.parent.mkdir(parents=True,exist_ok=True);out.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(counts))
if __name__=='__main__':main()
