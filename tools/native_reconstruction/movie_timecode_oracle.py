#!/usr/bin/env python3
"""Joined original video timecode reconstruction, baseline and publication."""
import argparse,copy,hashlib,json,os,struct
from pathlib import Path
import movie_timestamp_oracle as temporal
j=temporal.j;ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-timecode';META=temporal.META
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
class OriginalConstants(j.math.AccessMemory):
 def __init__(self,previous,elf):self.__dict__=previous.__dict__;self.elf=elf;self.constants={}
 def load(self,address,size):
  if self.active and not any(base<=address and address+size<=base+length for _,base,length,_ in self.allowed):
   if not(0x200000<=address and address+size<=0x280000):raise j.OracleError('Unowned timecode read '+hex(address))
   data=self.elf.read(address,size)
   if data is None:raise j.OracleError('Non-file-backed timecode constant')
   self.span('constant-'+hex(address),address,size,False,0);active=self.active;self.active=False;self.store(address,size,int.from_bytes(data,'little'));self.active=active;self.constants[f'{address:x}:{size}']=hashlib.sha256(data).hexdigest()
  return super().load(address,size)
class Machine(temporal.Machine):
 def instruction(self,pc,word):
  if word>>26==0 and word&63==0x16 and ((word>>6)&31)==0:
   rs,rt,rd=(word>>21)&31,(word>>16)&31,(word>>11)&31
   if rd:self.regs[rd]=(self.regs[rt]&0xffffffffffffffff)>>(self.regs[rs]&63)
   return None
  if word>>26==0 and word&63==7 and ((word>>6)&31)==0:
   rs,rt,rd=(word>>21)&31,(word>>16)&31,(word>>11)&31
   if rd:self.regs[rd]=j.sext32(j.signed(self.regs[rt],32)>>(self.regs[rs]&31))
   return None
  if word>>26==1 and ((word>>16)&31) in [2,3]:
   rs=(word>>21)&31;positive=j.signed(self.regs[rs],64)>=0
   return (positive if ((word>>16)&31)==3 else not positive),(pc+4+j.signed(word,16)*4)&0xFFFFFFFF,True
  return super().instruction(pc,word)
 def __init__(self,case,worker,words):
  self.flow_ready=False;super().__init__(case,worker,words)
  for start,end in {0x16DB20:0x16E230,0x1769C0:0x176D08,0x175460:0x175588,0x15BAF0:0x15BBA0,0x110000:0x123000}.items():
   raw=self.elf.read(start,end-start);self.body_ids[f'{start:x}:{end:x}']=hashlib.sha256(raw).hexdigest()
   for i in range(0,len(raw),4):self.code[start+i]=struct.unpack_from('<I',raw,i)[0]
  self.mem=OriginalConstants(self.mem,self.elf)
  self.mem.store(j.MAIN+0xA70,4,0);self.mem.store(j.MAIN+0xA74,4,0);self.mem.store(j.MAIN+0x2AB0,4,0)
  for at in [0xCDC,0xD04,0xD54]:self.mem.store(j.MAIN+at,4,0)
  self.flow_ready=True;self.initial=self.capture()
 def capture(self):
  if not self.flow_ready:return super().capture()
  return dict(temporal=super().capture(),property34=self.mem.load(j.MAIN+0xA70,4),first=self.mem.words(j.MAIN+0xCDC,10),latest=self.mem.words(j.MAIN+0xD04,10),current=self.mem.words(j.MAIN+0xD54,10),metadata=self.mem.words(META,16))
 def port(self,pc):
  if pc==0x155E60:
   destination,source,count=[value&0xFFFFFFFF for value in self.regs[4:7]];self.mem.store(destination,count,self.mem.load(source,count));self.regs[2]=destination;return self.regs[31]&0xFFFFFFFF
  return super().port(pc)
 def execute_flow(self,op):
  self.operation=dict(error_status=0xFF000221)
  for offset,key in [(0x10,'rate'),(0x14,'reference'),(0x18,'kind'),(0x1C,'drop'),(0x20,'hours'),(0x24,'minutes'),(0x28,'seconds'),(0x2C,'frames'),(0x30,'gop')]:self.mem.store(META+offset,4,op[key])
  before=self.capture();start=self.steps
  stamp=0xFFFFFFFF
  if op['stamp'] is not None:
   for i,v in enumerate([op['stamp'],op['begin'],op['bytes']]):self.mem.store(temporal.STAMP+4*i,4,v)
   stamp=self.run_body(0x16D988,[j.CLOCK,temporal.TEMP,META,temporal.STAMP,op['changed']])&0xFFFFFFFF
  self.run_body(0x16DB20,[j.MAIN,META,stamp,op['changed']]);self.run_body(0x16E038,[j.MAIN,META]);self.run_body(0x16E0E0,[j.MAIN,META])
  return dict(before=before,after=self.capture(),stamp=stamp,instructions=self.steps-start)
def corpus():
 cases=[];base=temporal.corpus()[0]
 def op(ref=0,stamp=None,rate=4,kind=1,gop=1,changed=0,drop=0,h=0,m=0,s=0,f=0):return dict(reference=ref,stamp=stamp,rate=rate,kind=kind,gop=gop,changed=changed,drop=drop,hours=h,minutes=m,seconds=s,frames=f,begin=100,bytes=4096)
 def add(name,ops):
  c=copy.deepcopy(base);c['name']=name;c['operations']=ops;cases.append(c)
 for rate in range(1,9):
  for drop in [0,1]:
   for stamp in [0,22500,225000]:
    add(f'flow-{rate}-{drop}-{stamp}',[op(0,stamp,rate,changed=1,drop=drop),op(3,None,rate,2,drop=drop),op(1,None,rate,3,drop=drop),op(2,None,rate,3,drop=drop),op(0,None,rate,1,gop=2,changed=1,drop=drop),op(1,None,rate,2,gop=2,drop=drop)])
 for rate in [1,3,4,7]:
  add('authored-gop-'+str(rate),[op(0,None,rate,gop=0,h=1,m=2,s=3,f=4),op(1,None,rate,gop=0,h=1,m=2,s=3,f=4),op(0,None,rate,gop=1,changed=1,h=1,m=2,s=4,f=0)])
 for rate in [1,4,7]:
  for drop in [0,1]:
   for value in [1,374,375,750,751,1349999,1350000,13499999,13500000,80999999,81000000]:
    add(f'fixed-origin-{rate}-{drop}-{value}',[op(0,value,rate,changed=1,drop=drop),op(1,None,rate,kind=2,drop=drop),op(0,None,rate,gop=2,changed=1,drop=drop)])
    cases[-1]['baseline']=0
 for rate in [1,4,7]:
  add(f'no-initial-stamp-{rate}',[op(0,None,rate,gop=1,changed=1,h=1,m=2,s=3,f=4),op(1,None,rate,gop=1,h=1,m=2,s=3,f=4),op(0,None,rate,gop=2,changed=1,h=1,m=2,s=4,f=0)])
 return cases
def main():
 probe=Machine.__new__(Machine);probe.regs=[0]*32
 for value,shift,expected in [(0x8000000000000000,63,1),(0x8000000000000000,64,0x8000000000000000),(0xffffffffffffffff,1,0x7fffffffffffffff),(0x123456789abcdef0,32,0x12345678)]:
  probe.regs[1]=shift;probe.regs[2]=value;probe.instruction(0x1000,(1<<21)|(2<<16)|(3<<11)|0x16);assert probe.regs[3]==expected
 for value,shift,expected in [(0x80000000,1,0xffffffffc0000000),(0x7fffffff,1,0x3fffffff),(0x80000000,0,0xffffffff80000000),(0x80000000,33,0xffffffffc0000000),(0x12345678ffffffff,31,0xffffffffffffffff)]:
  probe.regs[1]=shift;probe.regs[2]=value;probe.instruction(0x1000,(1<<21)|(2<<16)|(3<<11)|7);assert probe.regs[3]==expected
 for value,less,greater in [(0,False,True),(1,False,True),(0xffffffffffffffff,True,False),(0x8000000000000000,True,False)]:
  probe.regs[6]=value
  assert probe.instruction(0x16dcb4,0x04c20009)==(less,0x16dcdc,True)
  assert probe.instruction(0x16dcb4,0x04c30009)==(greater,0x16dcdc,True)
 p=argparse.ArgumentParser();p.add_argument('--cohort',choices=['gcc','llvm'],required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
 if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scope required')
 prior=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+a.cohort+'-v3');identity=json.loads((prior/'input-manifest.json').read_bytes());binary=prior/'fp_worker.exe';assert sha(binary)==identity['fp_worker_sha256']
 os.environ['PATH']=str(Path(identity['compiler']).parent)+os.pathsep+os.environ.get('PATH','');j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8};j.PORTS[0x155E60]='memory_copy'
 out.mkdir(parents=True);cases=corpus();record=dict(status='failed',native_flow_exists=(ROOT/'game/native/movie_timestamp/timecode.cpp').exists(),elf_sha256=identity['elf_sha256'],worker_sha256=sha(binary),sources={p.relative_to(ROOT).as_posix():sha(p) for p in [Path(__file__),Path(temporal.__file__),Path(j.__file__)]});results=[]
 (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8',newline='\n')
 try:
  with j.fp.FpuWorker(binary) as worker:
   for case in cases:
    machine=Machine(case,worker,set(j.fp.fp_words().values()));ops=[machine.execute_flow(op) for op in case['operations']];results.append(dict(name=case['name'],initial=machine.initial,operations=ops,instructions=machine.steps,body_ids=machine.body_ids,constants=machine.mem.constants))
  (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');record.update(status='original joined timecodes returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),game_run=False,device_opened=False)
 except Exception as error:record.update(failure=str(error),completed_cases=len(results));raise
 finally:
  record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix=='.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
 print(json.dumps({k:v for k,v in record.items() if k not in ['sources','outputs_sha256']}))
if __name__=='__main__':main()
