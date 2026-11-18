"""Offline schedule recovery; original registers/instructions stay test-only."""
import argparse,hashlib,json,os,re,subprocess,sys
from collections import Counter,defaultdict
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
NAMES={0x595b70:'surface_pair_one',0x595c00:'surface_pair_zero',0x595c90:'actor_audio',0x595d30:'alternate_audio',0x595dd0:'resource_audio',0x595e30:'resource_callback',0x595fa0:'node_audio',0x596000:'position_audio',0x596060:'contact_action',0x596180:'model_action',0x596470:'resource_program',0x59ebb0:'common_tail'}
CONDITIONS={0x100:'ctx.actor.category == 0',0x101:'ctx.actor.motion_class == 0x39',0x102:'(ctx.metadata.action_flags(ctx.actor.resource_action) & 0x20) != 0'}
def tree(traces):
 if all(not t for t in traces):return ()
 assert all(traces)
 heads=[t[0]for t in traces];first=heads[0]
 if first[0]>=0x100 and first[0]<=0x102:
  assert all(x[0]==first[0]and x[1]==0 and x[2]in[0,1]and x[3:]==(0,0)for x in heads)
  branches=[]
  for b in [0,1]:
   selected=[t[1:]for t in traces if t[0][2]==b];assert selected
   branches.append(tree(selected))
  return (('if',first[0],branches[1],branches[0]),)
 assert all(x==first for x in heads),heads
 return (first,)+tree([t[1:]for t in traces])
def render(nodes,indent='    '):
 lines=[]
 for n in nodes:
  if n[0]=='if':
   lines.append(indent+'if ('+CONDITIONS[n[1]]+') {');lines.extend(render(n[2],indent+'    '));lines.append(indent+'} else {');lines.extend(render(n[3],indent+'    '));lines.append(indent+'}')
  else:
   kind,frame,a,b,c=n
   if kind==0x59ebb0:lines.append(indent+'common_tail(ctx, ctx.playback.channel(animation::ModelBank::primary, 1).selector);')
   else:
    signed=frame if frame<0x80000000 else frame-0x100000000
    lines.append(indent+f'ctx.emit(Event{{EventKind::{NAMES[kind]}, {signed}, {a}u, {b}u, {c}u}});')
 return lines
def main():
 p=argparse.ArgumentParser();p.add_argument('--compiler',required=True,type=Path);p.add_argument('--output',required=True,type=Path);a=p.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
 image=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(image)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';raw=image.read_bytes();sources=[];proof=[]
 for at in [0x5965a0,0x59a820,0x59ebb0]:
  src=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));begin,end=[int(x,16)for x in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',src.read_text()).groups()];proof.append(compare_source('complete player frame-event schedule',src.relative_to(ROOT).as_posix(),begin,end,lambda at,n:raw[at-0x570000:at-0x570000+n]));sources.append(src.relative_to(ROOT).as_posix())
 helpers=['tools/native_reconstruction/gameplay_world_oracle/transform_reference.hpp','tools/native_reconstruction/animation/schedule_extract.cpp',Path(__file__).relative_to(ROOT).as_posix()];before={n:sha(ROOT/n)for n in sources+helpers};record=dict(schema=1,status='failed',source_sha256=before,compiler_sha256=sha(a.compiler),original_owned_bodies=proof,game_run=False)
 try:
  for n in before:dest=out/'source'/n;dest.parent.mkdir(parents=True,exist_ok=True);dest.write_bytes((ROOT/n).read_bytes())
  (out/'reference.hpp').write_bytes((ROOT/helpers[0]).read_bytes());(out/'extract.cpp').write_bytes((ROOT/helpers[1]).read_bytes());body='\n'.join((ROOT/n).read_text()for n in sources);(out/'original.cpp').write_text(body);actual={Path(n).stem for n in sources};calls=set(re.findall(r'\b(o2_[0-9A-Fa-f]+_0x[0-9a-f]+)\(rdram',body));decl=''.join('void '+n+'(std::uint8_t*,R5900Context*,PS2Runtime*);\n'for n in sorted(actual));decl+=''.join('inline void '+n+'(std::uint8_t*m,R5900Context*c,PS2Runtime*r){original_transform_port(m,c,r);}\n'for n in sorted(calls-actual));(out/'functions.h').write_text(decl)
  for n in ['ps2_runtime.h','ps2_runtime_macros.h']:(out/n).write_text('#pragma once\n#include "reference.hpp"\n')
  for n in ['o2_functions.h','ps2_recompiled_stubs.h','ps2_syscalls.h','ps2_stubs.h']:(out/n).write_text('#pragma once\n')
  env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','');binary=out/'extract.exe';cmd=[str(a.compiler),'-std=c++20','-O2','-msse4.1','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-unused-label','-Wno-unused-parameter','-I'+str(out),str(out/'extract.cpp'),'-o',str(binary)];record['command']=cmd;r=subprocess.run(cmd,env=env,capture_output=True,text=True,timeout=120);(out/'compile.txt').write_text(r.stdout+r.stderr);assert r.returncode==0,'compile failed'
  with(out/'traces.txt').open('w')as f:r=subprocess.run([str(binary),str(image)],stdout=f,stderr=subprocess.PIPE,env=env,text=True,timeout=180)
  (out/'extract-stderr.txt').write_text(r.stderr);assert r.returncode==0,'extraction failed'
  families=defaultdict(lambda:defaultdict(list));rows=0
  with(out/'traces.txt').open()as f:
   for line in f:
    parts=line.split();family,selector,variant=map(int,parts[:3]);assert variant==len(families[family][selector]);families[family][selector].append(tuple(tuple(map(int,x.split(',')))for x in parts[3:]));rows+=1
  functions=[];groups={};total=0
  for family,name in [(2,'common_tail'),(3,'lower_zero'),(4,'lower_one'),(0,'upper_zero'),(1,'upper_one')]:
   assert len(families[family])==65536;bucket=defaultdict(list)
   for selector,traces in families[family].items():bucket[tree(traces)].append(selector)
   default=max(bucket,key=lambda k:len(bucket[k]));lines=[f'void {name}(Context& ctx, std::uint16_t selector) {{','    switch (selector) {']
   for body,selectors in bucket.items():
    if body==default:continue
    for sel in selectors:lines.append(f'    case {sel}:')
    lines.extend(render(body,'        '));lines.append('        return;')
   lines.append('    default:');lines.extend(render(default,'        '));lines.extend(['        return;','    }','}']);functions.append('\n'.join(lines));groups[name]=len(bucket);total+=len(bucket)
  (out/'player_event_schedule.inc').write_text('// Recovered offline from complete owned File1 player event bodies.\n// Native typed selector branches; no guest instruction or address execution.\n'+'\n\n'.join(functions)+'\n');record.update(status='passed',rows=rows,groups=groups,source_unchanged=all(sha(ROOT/n)==h for n,h in before.items()));assert record['source_unchanged']
 finally:record['output_sha256']={p.relative_to(out).as_posix():sha(p)for p in out.rglob('*')if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
 print(json.dumps({k:record[k]for k in['status','rows','groups']}))
if __name__=='__main__':main()
