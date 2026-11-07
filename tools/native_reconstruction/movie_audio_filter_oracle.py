#!/usr/bin/env python3
"""Owned integer audio-time filter; actual helpers and null-CSV branch only."""
import argparse
import hashlib
import json
from pathlib import Path
import struct
from adx_stereo_oracle import EeDivInstructions
from ee_copy_store_oracle import CopyStoreInstructions
from movie_position_oracle import ClockIntegerInstructions,AccessMemory,BODIES as POSITION_BODIES,NORM,NORM_BYTES,OriginalBreak,UndefinedInstruction
from sjuni_oracle import Elf,OracleError,StepLimit,MASK32,MASK64,sext32

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-audio-filter'
BODIES={
    0x107C68:(0x107D28,'09c7829fb0e061976495f53e07fa77cde5f74607c3657deb18319097cf4a51be'),
    0x10FAA0:(0x10FB18,'70669c3ba87e12e9bfb652b4327a7733cf84852ebb189592cf6b990f9c121f4a'),
    0x10FB18:POSITION_BODIES[0x10FB18],
    0x177CB0:(0x177D90,'9af514fdbe17dd0028cc473232cbb14e52792c4d33d1f5c4e980bef02a5c1563'),
    0x177D90:(0x177DD0,'392fefed9f48657dbae8864ca513dd4655948bdcd587b10242de7ed5b94db0be'),
    0x177DD0:(0x177DD8,'eb145aa2915f561839a1eff7c9da12adc93c631a1d0f8f08f1581bd859231e5f'),
    0x177DD8:(0x177DF0,'d77fa0fb1c83a9d4d9d25019c3f05e8ec0510e9771c8b1eaeeebb56ce128f8aa'),
    0x177DF0:(0x177E08,'d370f1ee4ceae4769f6f80977dcaccb0f926f3876300df078d2e4b2f26204681'),
    0x177E08:(0x177E20,'2931a9f0cbd7a2882c8ca82ecc6d16ff349d8de042b796672866a690885e27f0'),
    0x177E20:(0x177E38,'f21c73a8e4588fd48fce694e3f6219045ccb99e9718ef3f87051d3f59d027fec'),
    0x177E38:(0x177E48,'8df034f9c239d27327bbf3518569360d121a2290df1b1abd12631ed6f44b3bb3'),
    0x177E48:(0x177E50,'997c251e609b12c456504efab684cb701d5fbfdd5503181190a12e87a7018129'),
    0x177E50:(0x177E58,'80cd297c0a26df8ec5f387cc5cb1e8039897493be7456a05b23f5b596b2181aa'),
    0x177E58:(0x177EB0,'911013b42403a0568285abb91b960ce2449d2c23a50bc02309cf61966639ef30'),
    0x177EB0:(0x178318,'6e64f248d9dd8a2e64b74d03a09c8040c86e72c7b849335f36cca3042dcf801e'),
    0x178318:(0x178378,'f003aa2a9a037c193753cd496b7488fb4a95d1e6bdffd52c132f866560c07910'),
    0x178378:(0x1783D8,'0f0a153ec06b8316f0d887912708d34cc181d931d6fc53b75f694eec0981410a'),
    0x1783D8:(0x178428,'78d0ad8ca30d32acac553136c5b68f0f429f5bff0e274298302f1b87436f03b5'),
    0x178440:(0x17859C,'7d1288229a9827d5dadf26a608428c3bc5a910bf65ccd532ed2f9e6ad1223af2'),
    0x1785A0:(0x1787E8,'dbdfb84bd0a03c45ffde39636a43beda5004cbde57dd5cc3ce669ee89452b2c7')}
FILTER,INPUT,HELPER,OUTPUT,PARAMETER=0x400000,0x500000,0x500040,0x500080,0x5000C0
STACK,TOP,RETURN=0x700000,0x701000,0xFFFFF0
GLOBALS,HEADER=0x22F1D8,0x240B60
WORDS=dict(enabled=0,pause=4,active=8,mode=12,window=16,sample_counter=20,
           reanchors=0x190,positive_steps=0x194,negative_steps=0x198,resets=0x19C,excess_resets=0x1A0,
           average_before=0x1A4,average_after=0x1A8,inactive_max=0x1AC,inactive_min=0x1B0,active_max=0x1B4,active_min=0x1B8)
PAIRS=dict(previous_input=0x108,previous_helper=0x118,previous_output=0x128,quantum=0x138,threshold=0x148,first_offset=0x158,later_offset=0x168)
DOUBLES=dict(helper_anchor=0x178,master_anchor=0x180,raw_maximum=0x188)
ENTRIES=dict(construct=0x177CB0,clear=0x177D90,enabled=0x177DD0,quantum=0x177DD8,threshold=0x177DF0,
             first_offset=0x177E08,later_offset=0x177E20,window=0x177E38,pause=0x177E48,mode=0x177E50,
             baseline=0x177E58,filter=0x177EB0,push=0x178318,shift=0x178378,average=0x1783D8)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(CopyStoreInstructions,EeDivInstructions,ClockIntegerInstructions):
    def __init__(self):
        self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for start,(end,digest) in BODIES.items():
            data=self.elf.read(start,end-start)
            if hashlib.sha256(data).hexdigest()!=digest:raise OracleError('Original filter body identity '+hex(start))
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        self.mem=AccessMemory()
        for name,base,length,write,fill in [('filter',FILTER-64,0x280,True,0xA5),('pairs',INPUT,256,True,0x5A),
                                          ('stack',STACK,0x2000,True,0xCC),('globals',GLOBALS,20,True,0)]:self.mem.span(name,base,length,write,fill)
        for name,base,length in [('normalization',NORM,NORM_BYTES),('header',HEADER,274)]:
            self.mem.span(name,base,length,False,0);self.mem.store(base,length,int.from_bytes(self.elf.read(base,length),'little'))
        if hashlib.sha256(self.elf.read(HEADER,274)).hexdigest()!='8f432b384057db2941b8874f17a79417d693baf6cfb5e77d9334567b695bea52':raise OracleError('Owned CSV header identity')
        self.regs=[0]*32
        for r in (*range(16,24),30):self.regs[r]=0x1234567800000000+r
        self.saved={r:self.regs[r] for r in (*range(16,24),30)}
        self.initialize_copy_store();self.initialize_mac(hi=1,lo=2,hi1=3,lo1=4);self.extension_counts={};self.steps=0;self.calls={};self.visited={}

    def snapshot(self):
        active,self.mem.active=self.mem.active,False
        result=dict(words={n:self.mem.load(FILTER+offset,4) for n,offset in WORDS.items()},
                    pairs={n:[self.mem.load(FILTER+offset,8),self.mem.load(FILTER+offset+8,8)] for n,offset in PAIRS.items()},
                    doubles={n:self.mem.load(FILTER+offset,8) for n,offset in DOUBLES.items()},history=self.mem.words(FILTER+0x18,60),
                    unused_word=self.mem.load(FILTER+0x1BC,4),globals=self.mem.words(GLOBALS,5),
                    input=[self.mem.load(INPUT,8),self.mem.load(INPUT+8,8)],helper=[self.mem.load(HELPER,8),self.mem.load(HELPER+8,8)],output=[self.mem.load(OUTPUT,8),self.mem.load(OUTPUT+8,8)],
                    prefix=self.mem.words(FILTER-64,16),suffix=self.mem.words(FILTER+0x1C0,32))
        self.mem.active=active;return result

    def seed(self,seed):
        for name,value in seed.items():
            if name in WORDS:self.mem.store(FILTER+WORDS[name],4,value)
            elif name in DOUBLES:self.mem.store(FILTER+DOUBLES[name],8,value)
            elif name in PAIRS:
                for n,word in enumerate(value):self.mem.store(FILTER+PAIRS[name]+n*8,8,word)
            elif name=='history':
                if len(value)!=60:raise OracleError('Bounded authored history')
                for n,word in enumerate(value):self.mem.store(FILTER+0x18+n*4,4,word)
            else:raise OracleError('Undeclared seed field')

    def run(self,operation):
        name=operation['operation'];entry=ENTRIES[name];self.regs[29]=TOP;self.regs[31]=RETURN
        args=[FILTER]
        if name=='filter':
            for at,pair in [(INPUT,operation['input']),(HELPER,operation['helper'])]:
                for n,value in enumerate(pair):self.mem.store(at+n*8,8,value)
            args += [INPUT,HELPER,OUTPUT]
        elif name in PAIRS or name=='baseline':
            for n,value in enumerate(operation['pair']):self.mem.store(PARAMETER+n*8,8,value)
            args += [PARAMETER]
        elif name in ['enabled','window','pause','mode','push','shift']:args += [sext32(operation['value'])]
        for n,value in enumerate(args):self.regs[4+n]=value
        before=self.snapshot();prior_steps=self.steps;write_start=len(self.mem.writes);read_start=len(self.mem.reads);self.mem.active=True;pc,pending=entry,None
        while pc!=RETURN:
            if self.steps-prior_steps>=100000:raise StepLimit('Original filter operation exceeded bound')
            if pc not in self.code or pc%4:raise OracleError('Unowned filter transfer '+hex(pc))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in BODIES:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Branch in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.snapshot()
        if self.regs[29]!=TOP or any(self.regs[r]!=v for r,v in self.saved.items()):raise OracleError('Filter ABI restoration')
        if any(before[n]!=after[n] for n in ['prefix','suffix']):raise OracleError('Filter escaped owned extent')
        if after['globals'][1]!=0:raise OracleError('CSV profile changed')
        return dict(operation=operation,before=before,after=after,original_instructions=self.steps-prior_steps,raw_v0_lower64=self.regs[2],
                    return_defined=name in ['average','push'],writes=self.mem.writes[write_start:],reads=self.mem.reads[read_start:])


def sample(value,helper,rate=48000,frequency=90000):return dict(operation='filter',input=[value&MASK64,rate&MASK64],helper=[helper&MASK64,frequency&MASK64])
def set_word(name,value):return dict(operation=name,value=value)
def set_pair(name,num,den):return dict(operation=name,pair=[num&MASK64,den&MASK64])


def corpus():
    cases=[dict(name='constructor',seed={},operations=[])]
    for name in ['enabled','pause','mode']:
        for value in [0,1,2,0xFFFFFFFF]:cases.append(dict(name=name+'-'+str(value),seed={},operations=[set_word(name,value)]+[sample(n*1600,n*3000) for n in range(8)]))
    for window in [1,10,60,0,0xFFFFFFFF]:cases.append(dict(name='window-'+str(window),seed={},operations=[set_word('window',window)]+[sample(n*2400,n*3000) for n in range(16)]))
    for speed in [0,800,1600,2400]:cases.append(dict(name='trajectory-'+str(speed),seed={},operations=[sample(n*speed,n*3000) for n in range(64)]))
    cases.append(dict(name='jump-backward-and-pause',seed={},operations=[sample(n*1600,n*3000) for n in range(8)]+[sample(100000,24000),sample(100,27000),set_word('pause',1),sample(100000,30000),sample(102000,33000),set_word('pause',2),sample(104000,36000)]))
    for error in [-12001,-12000,-11999,-801,-800,-799,0,799,800,801,11999,12000,12001]:
        cases.append(dict(name='error-'+str(error),seed=dict(active=1,window=1,helper_anchor=0,master_anchor=20000),operations=[sample(20000+error,0)]))
    for mode in [0,1,2,0xFFFFFFFF]:cases.append(dict(name='inactive-anchor-mode-'+str(mode),seed=dict(mode=mode,raw_maximum=1000,helper_anchor=0,master_anchor=1000,previous_output=[900,48000]),operations=[sample(1000,90000),set_pair('baseline',300,48000),sample(1000,93000)]))
    cases.append(dict(name='paused-inactive-mode-zero-anchor',seed=dict(mode=0,pause=1,raw_maximum=1000,helper_anchor=0,master_anchor=1000,previous_output=[900,48000]),operations=[sample(1000,90000)]))
    for field in ['first_offset','later_offset']:
        for value in [-100000,0,100000]:cases.append(dict(name=field+'-'+str(value),seed={},operations=[set_pair(field,value,1000000),sample(1000,100),set_word('pause',1),sample(1000,3000),set_word('pause',0),sample(2000,6000)]))
    for active in [0,1,2,0xFFFFFFFF]:
        for pause in [0,1,2]:cases.append(dict(name='raw-state-'+str(active)+'-'+str(pause),seed=dict(active=active,pause=pause),operations=[sample(1600,3000),sample(1600,6000),sample(3200,9000)]))
    cases.append(dict(name='history-sum-wrap',seed=dict(active=1,window=60,helper_anchor=0,master_anchor=10000,history=[0x7FFFFFFF]*60),operations=[sample(10800,0)]))
    for freq in [1,90000]:
        for enabled in [0,1,2]:cases.append(dict(name='bypass-'+str(freq)+'-'+str(enabled),seed=dict(enabled=enabled,raw_maximum=12345,active=2,pause=1),operations=[sample(1000,6000,frequency=freq)]))
    cases.append(dict(name='history-controls',seed={},operations=[set_word('push',800),set_word('push',-800),set_word('shift',400),dict(operation='average'),dict(operation='clear')]))
    return cases


def exclusions():
    rows=[]
    for name,seed,operation in [
        ('zero-window-break',dict(window=0,active=1,helper_anchor=0,master_anchor=1000),sample(1800,0)),
        ('zero-helper-frequency',dict(active=1,helper_anchor=0,master_anchor=1000),sample(1800,1,frequency=0)),
        ('zero-scaled-quantum',dict(active=1,window=1,helper_anchor=0,master_anchor=1000,quantum=[0,1]),sample(2000,0)),
        ('negative-history-counter-alias',dict(active=1,window=10,sample_counter=0xFFFFFFFF,helper_anchor=0,master_anchor=1000),sample(1800,0)),
        ('window-exceeds-owned-history',dict(active=1,window=61,helper_anchor=0,master_anchor=1000),sample(1800,0))]:
        machine=Machine();machine.run(dict(operation='construct'));machine.seed(seed);before=machine.snapshot()
        try:
            result=machine.run(operation);rows.append(dict(name=name,status='original returned outside proposed native admission',seed=seed,operation=operation,result=result))
        except (OriginalBreak,UndefinedInstruction) as error:
            machine.mem.active=False;rows.append(dict(name=name,status='original arithmetic not admitted',seed=seed,operation=operation,error_type=type(error).__name__,error=str(error),before=before,after=machine.snapshot()))
    return rows


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    out.mkdir(parents=True);cases=corpus();sources=[Path(__file__),ROOT/'tools/native_reconstruction/ee_copy_store_oracle.py',ROOT/'tools/native_reconstruction/adx_stereo_oracle.py',ROOT/'tools/native_reconstruction/movie_position_oracle.py',ROOT/'tools/native_reconstruction/ee_mac_oracle.py',ROOT/'tools/native_reconstruction/sjuni_oracle.py']
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(p.relative_to(ROOT)):sha(p) for p in sources},native_exists=(ROOT/'game/native/movie_audio_filter').exists(),argument_profile='word controls canonical signextended32; ratio/input/helper lanes raw64',csv_buffer='null only; actual original branch executes',game_run=False,device_opened=False)
    (out/'inputs.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8',newline='\n');(out/'input-manifest.json').write_text(json.dumps(manifest,indent=2)+'\n',encoding='utf-8',newline='\n')
    results=[]
    try:
        for case in cases:
            machine=Machine();constructor=machine.run(dict(operation='construct'));machine.seed(case['seed']);rows=[machine.run(op) for op in case['operations']]
            results.append(dict(name=case['name'],constructor=constructor,seeded_initial=rows[0]['before'] if rows else machine.snapshot(),operations=rows,instructions=machine.steps,calls={hex(k):v for k,v in machine.calls.items()},visits={hex(k):v for k,v in machine.visited.items()},copy_store_counts=machine.copy_store_counts))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n')
        excluded=exclusions();(out/'exclusions.json').write_text(json.dumps(excluded,indent=2)+'\n',encoding='utf-8',newline='\n')
        seen={int(pc,16) for r in results for pc in r['visits']};unvisited=[hex(pc) for pc in range(0x177EB0,0x178318,4) if pc not in seen]
        receipt=dict(schema=1,status='original complete bounded audio-filter corpus returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),excluded_cases=len(excluded),unvisited_main_words=unvisited,native_exists=manifest['native_exists'],outputs_sha256={n:sha(out/n) for n in ['inputs.json','input-manifest.json','original.json','exclusions.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(schema=1,status='failed',completed_cases=len(results),failure=str(error));raise
    finally:
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],operations=receipt['operations'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
