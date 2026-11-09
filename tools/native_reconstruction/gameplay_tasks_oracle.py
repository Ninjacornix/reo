"""Bounded File1 owned-word scheduling/timer oracle; verification only.

The production native core never imports this instruction runner or its memory.
Callbacks, memset and flag-consumer effects are explicitly declared fixture ports.
"""
import hashlib,json,re,struct
from pathlib import Path
from sjuni_oracle import Memory,OracleError,MASK32,MASK64,sext32,signed
from movie_position_oracle import ClockIntegerInstructions
from ee_copy_store_oracle import CopyStoreInstructions
from audit_retail_effect_descriptors import compare_source

ROOT=Path(__file__).resolve().parents[2]
BASE=0x570000;RETURN=0xfff00000;TOP=0x70f000;CALLBACK=0x90000000
BODY_STARTS=(0x5735a0,0x573630,0x573740,0x573840,0x573890,0x5738f0,0x68c7b0,0x68e1f0,0x5fee80,0x5b91b0,0x5b92b0,0x5b93b0)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def authority():
    path=ROOT/'build-function-index/owned-overlays/o2.bin';data=path.read_bytes()
    assert sha(path)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
    assert struct.unpack_from('<I',data,8)[0]==BASE
    code={};profiles=[]
    for start in BODY_STARTS:
        source=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{start:08X}_0x{start:x}.cpp'))
        end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        profiles.append(compare_source('task/timer/clock',source.relative_to(ROOT).as_posix(),start,end,lambda a,n:data[a-BASE:a-BASE+n]))
        code.update({pc:struct.unpack_from('<I',data,pc-BASE)[0]for pc in range(start,end,4)})
    return code,profiles

class Machine(CopyStoreInstructions,ClockIntegerInstructions):
    def __init__(self,code):
        self.code=code;self.mem=Memory()
        for base,size in ((0x3b5000,0x1000),(0x3b6400,0x2200),(0x415890,0x1800),(0x4bad80,0x100),(0x3243c0,0x20),(0x600000,0x1000),(0x700000,0x10000)):self.mem.map(base,size)
        self.regs=[0]*32;self.initialize_copy_store();self.initialize_mac(hi=0,lo=0,hi1=0,lo1=0)
        self.extension_counts={};self.depth=0;self.steps=0;self.visited=set();self.entries=set();self.events=[];self.success=[];self.handles={};self.actions={};self.secondary=False;self.mutation=False;self.event_mode=False;self.session_mode=0
        self.invoke(0x5735a0,[])
    def instruction(self,pc,word):
        op=word>>26;rs=(word>>21)&31;rt=(word>>16)&31;fn=word&63
        if op==0x1e:
            address=(self.regs[rs]+signed(word,16))&MASK32;address&=~15
            value=self.mem.load(address,16);self.regs[rt]=value&MASK64;self.upper[rt]=value>>64;return None
        if op==0 and fn==0x1a:
            a,b=signed(self.regs[rs],32),signed(self.regs[rt],32)
            if not b or (a==-2147483648 and b==-1):raise OracleError('Unadmitted DIV')
            quotient=(abs(a)//abs(b))*(-1 if (a<0)!=(b<0)else 1)
            self.lo,self.hi=sext32(quotient),sext32(a-quotient*b);return None
        return super().instruction(pc,word)
    def invoke(self,entry,args):
        self.entries.add(entry)
        saved=(self.regs[:],dict(self.upper),self.hi,self.lo);self.depth+=1
        if self.depth>12:raise OracleError('Fixture call depth')
        self.regs=[0]*32;self.upper={i:0x12340000+i for i in range(32)};self.upper[0]=0
        self.regs[29]=TOP-self.depth*1024;self.regs[31]=RETURN
        stack=self.regs[29]
        for i,arg in enumerate(args):self.regs[4+i]=sext32(arg)
        pc=entry;pending=None;count=0
        while pc!=RETURN:
            count+=1
            if count>50000:raise OracleError('Finite fixture step bound')
            if pc not in self.code:
                self.hook(pc);pc=self.regs[31]&MASK32;continue
            self.steps+=1;self.visited.add(pc);branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Transfer in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        if self.regs[29]!=stack:raise OracleError('Original stack restoration')
        result=self.regs[2]&MASK32
        self.regs,self.upper,self.hi,self.lo=saved;self.depth-=1;return result
    def create(self,label,placement,active,mask,secondary,action=0,arg=0):
        address=self.invoke(0x573630,[0]) if placement else self.invoke(0x573890,[label,CALLBACK+label*16])
        self.success.append(int(bool(address)))
        if not address:return
        self.handles[label]=address;self.actions[label]=(action,arg)
        for offset,value,size in ((0,active,1),(1,mask,1),(0x14,CALLBACK+label*16,4),(0x18,CALLBACK+label*16 if secondary else 0,4),(0x28,label,4)):
            self.mem.store(address+offset,size,value)
    def erase(self,label):
        self.success.append(int(bool(self.invoke(0x573740,[self.handles[label]]))))
        del self.handles[label]
    def hook(self,pc):
        if pc==0x1b02d0:self.regs[2]=sext32(self.session_mode);return
        if pc==0x107c68:
            address,value,size=(self.regs[i]&MASK32 for i in (4,5,6));self.mem.fill(address,size,value&255);self.regs[2]=sext32(address);return
        if pc in (0x5703e0,0x5705f0):
            slot=self.regs[16]&MASK32;self.events.extend([slot,int(pc==0x5705f0),self.regs[4]&MASK32])
            if self.mutation and slot==0:
                self.mutation=False;self.arm(0,0,31,2);self.arm(1,1,32,1)
            return
        if CALLBACK<=pc<CALLBACK+256*16:
            label=(pc-CALLBACK)//16;action,arg=self.actions[label];self.actions[label]=(0,arg)
            if self.event_mode:
                address=self.handles[label];offset=address-0x3b64d0
                self.events.extend([label,offset//0xaa0,(offset%0xaa0)//0x110,self.mem.load(0x4baded,1)])
                if action==1:self.event_erase(label)
                elif action==2:self.event_install(label+100,arg//10,arg%10,0,0)
                elif action==3:self.event_erase(arg)
                elif action==4:self.mem.store(0x4baded,1,arg)
                return
            self.events.append(label+(1000 if self.secondary else 0))
            if action==1:self.erase(label)
            elif action==2:self.create(arg,0,1,0,0)
            elif action==3:self.create(arg,1,1,0,0)
            elif action==4:self.erase(arg)
            elif action==5:self.erase(arg);self.create(arg+2,0,1,0,0)
            return
        raise OracleError('Undeclared external port '+hex(pc))
    def arm(self,slot,scope,ident,ticks):
        for n,v in enumerate((scope,ident,slot,ticks)):self.mem.store(0x600000+4*n,4,v)
        self.invoke(0x68e1f0,[0x600000])
    def event_install(self,label,bank,slot,action,arg):
        address=0x3b64d0+bank*0xaa0+slot*0x110
        assert address not in self.handles.values(),'Fixture install requires an unowned slot'
        previous=self.session_mode;self.session_mode=1
        self.invoke(0x5b92b0,[slot,0,CALLBACK+label*16,bank]);self.session_mode=previous
        self.mem.store(address+0x60,4,label);self.handles[label]=address;self.actions[label]=(action,arg);self.success.append(1)
    def event_erase(self,label):
        self.invoke(0x5b93b0,[self.handles[label]]);del self.handles[label];self.success.append(1)

def plans():
    out=[]
    def add(name,kind,ops):out.append(dict(name=name,kind=kind,ops=ops))
    c=lambda label,action=0,arg=0:['C',label,0,1,0,0,action,arg]
    add('head-child-same-pass','S',[c(1,2,3),c(2),['P']])
    add('head-child-from-current-head','S',[c(1),c(2,2,3),['P']])
    add('tail-child-next-pass','S',[c(1,3,3),c(2),['P'],['P']])
    add('remove-predecessor','S',[c(1,4,2),c(2),c(3),['P']])
    add('self-retire','S',[c(1,1),c(2),['P'],['P']])
    add('replace-other-child','S',[c(1,5,2),c(2),c(3),['P']])
    add('stock-capacity-and-reuse','S',[*[c(i)for i in range(1,34)],['D',1],c(34),['P']])
    for active in (0,1,2,128,255):
        for mask in (0,1,2,128,255):
            for secondary in (0,1):add(f'gates-{active}-{mask}-{secondary}','S',[['C',1,0,active,mask,secondary,0,0],['P'],['R']])
    for ticks in (0,1,2,30,32767,32768,65535,65536,0xffffffff):
        for scope in (0,1):add(f'timer-{ticks}-{scope}','T',[['A',i,scope,32760+i,ticks]for i in range(8)]+[['T'],['T']])
    add('timer-invalid-index-and-packed-scope','T',[['A',8,1,44,1],['A',0xffffffff,0,33,1],['A',0,0,0x8005,1],['T']])
    add('timer-sync-event-rearm','T',[['A',0,0,7,1],['M'],['T'],['T'],['T']])
    for mode in (0,1,2):
        for selected in (0,3,7):add(f'event-bank-order-{mode}-{selected}','E',[
            ['I',1,0,9,0,0],['I',2,0,0,0,0],['I',3,1,2,0,0],['I',4,2,1,0,0],['P',mode,selected]])
    add('event-later-slot-same-pass','E',[['I',1,0,0,2,5],['P',1,4]])
    add('event-earlier-slot-next-pass','E',[['I',1,0,5,2,0],['P',1,4],['P',1,4]])
    add('event-remove-upcoming','E',[['I',1,0,0,3,2],['I',2,0,5,0,0],['P',1,2]])
    add('event-disable-and-owner-mutation','E',[['I',1,0,0,4,5],['I',2,0,5,0,0],['I',3,1,0,0,0],['F',3,0],['P',1,2]])
    add('event-self-retire','E',[['I',1,0,0,1,0],['I',2,0,5,0,0],['P',0,7],['P',1,2]])
    for time in ((0,0,0,0),(0,0,0,58),(0,0,0,59),(0,0,59,59),(0,59,59,59),(99,59,59,59),(37,12,45,17)):
        for mode in (0,1,255):
            for ticks in (1,2,61):add(f'clock-{time}-{mode}-{ticks}','K',[ticks,*time,mode])
    return out

def execute(plan,code):
    machine=Machine(code);kind=plan['kind'];ops=plan['ops']
    if kind=='S':
        for op in ops:
            if op[0]=='C':machine.create(*op[1:])
            elif op[0]=='D':machine.erase(op[1])
            elif op[0]=='F':
                _,label,active,mask,secondary=op;at=machine.handles[label]
                machine.mem.store(at,1,active);machine.mem.store(at+1,1,mask);machine.mem.store(at+0x18,4,CALLBACK+label*16 if secondary else 0);machine.success.append(1)
            else:machine.secondary=op[0]=='R';machine.invoke(0x5738f0 if machine.secondary else 0x573840,[])
        alive=sorted(machine.handles);values=[len(machine.events),*machine.events,len(alive),*alive,len(machine.success),*machine.success]
    elif kind=='E':
        machine.event_mode=True
        for op in ops:
            if op[0]=='I':machine.event_install(*op[1:])
            elif op[0]=='D':machine.event_erase(op[1])
            elif op[0]=='F':machine.mem.store(machine.handles[op[1]],1,op[2]);machine.success.append(1)
            else:
                machine.session_mode=op[1];machine.mem.store(0x4baded,1,op[2]);machine.invoke(0x5b91b0,[])
        alive=sorted(machine.handles);values=[machine.mem.load(0x4baded,1),len(machine.events),*machine.events,len(alive),*alive,len(machine.success),*machine.success]
    elif kind=='T':
        for op in ops:
            if op[0]=='A':machine.arm(*op[1:])
            elif op[0]=='M':machine.mutation=True
            else:machine.invoke(0x68c7b0,[])
        values=[]
        for i in range(8):values.extend([signed(machine.mem.load(0x4bad88+2*i,2),16),machine.mem.load(0x4bad98+2*i,2)])
        values.extend([len(machine.events),*machine.events])
    else:
        ticks,h,m,s,f,mode=ops
        for n,value in enumerate((h,m,s,f)):machine.mem.store(0x4bae00+n,1,value)
        machine.mem.store(0x3243cc,1,mode)
        for _ in range(ticks):machine.invoke(0x5fee80,[])
        values=[machine.mem.load(0x4bae00+n,1)for n in range(4)]
    return kind+' '+' '.join(map(str,values)),machine.steps,len(machine.visited),sorted(machine.entries)

def serialize(plan):
    if plan['kind']=='K':return 'K '+' '.join(map(str,plan['ops']))
    return plan['kind']+' '+str(len(plan['ops']))+' '+' '.join(' '.join(map(str,op))for op in plan['ops'])
