#!/usr/bin/env python3
"""Original picture admission arithmetic with audited current-runtime FP words."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import adx_header_math_oracle as fp
from adx_stereo_oracle import EeDivInstructions
from movie_position_oracle import AccessMemory,ClockIntegerInstructions
from sjuni_oracle import Elf,OracleError,StepLimit,sext32,signed

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-admission'
MAIN,OUT,STACK,TOP,RETURN,FREQUENCY=0x400000,0x500000,0x700000,0x701000,0xFFFFF0,0x22F140
FIELDS=dict(selector=0x9DC,tolerance=0xA58,rate=0x920,increment=0xF28,count=0xF38,tracked_bits=0xF3C,cached=0xF40,previous_bits=0xF44,auxiliary=0xF48)
INTERVALS={0x1770F0:0x177240,0x177240:0x1772B8,0x1772B8:0x1773A8,0x1501E8:0x150230}
ENTRIES=dict(core=0x1770F0,fallback=0x177240,hysteresis=0x1772B8)
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def worker_source(statements):
    source=fp.worker_source(statements)
    changes=[
        ('if(rs==8 && (ft==1 || ft==3)) { branch=bool(ctx->fcr31&0x800000);likely=bool(ft&2);return; }','if(rs==8 && ft<=3) { branch=bool(ctx->fcr31&0x800000)==bool(ft&1);likely=bool(ft&2);return; }'),
        ('case 50:ctx->fcr31=FPU_C_EQ_S(ctx->f[fs],ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;',
         'case 50:ctx->fcr31=FPU_C_EQ_S(ctx->f[fs],ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;\n case 52:ctx->fcr31=(ctx->f[fs]<ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;\n case 54:ctx->fcr31=(ctx->f[fs]<=ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;')]
    for old,new in changes:
        if source.count(old)!=1:raise OracleError('Scoped worker extension selector changed')
        source=source.replace(old,new)
    macros=fp.MACROS.read_text(encoding='utf-8');lines=[]
    for name in ['FPU_C_OLT_S','FPU_C_OLE_S']:
        match=re.search(r'^#define '+name+r'\([^\n]+',macros,re.M)
        if not match:raise OracleError('Missing authoritative ordered compare macro')
        lines.append(match[0])
    return source.replace('void generic(', '\n'.join(lines)+'\nvoid generic(',1)


class Machine(EeDivInstructions,ClockIntegerInstructions):
    def __init__(self,case,worker,words):
        self.elf=Elf(ROOT/'game_data/SLUS_207.65')
        if self.elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise OracleError('Owned ELF identity')
        self.code={};self.body_identities={};self.worker=worker;self.words=words;self.fp_steps=0
        for start,end in INTERVALS.items():
            data=self.elf.read(start,end-start);self.body_identities[hex(start)]=dict(end=hex(end),sha256=hashlib.sha256(data).hexdigest())
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        self.mem=AccessMemory()
        for name,address,length,write,fill in [('main',MAIN,0x3000,True,0xA5),('output',OUT-16,36,True,0x5A),('stack',STACK,0x2000,True,0xCC),('frequency',FREQUENCY,4,False,0)]:self.mem.span(name,address,length,write,fill)
        for name,offset in FIELDS.items():self.mem.store(MAIN+offset,4,case['state'][name])
        self.mem.store(FREQUENCY,4,case['frequency']);self.regs=[0]*32
        for register in (*range(16,24),30):self.regs[register]=0x1234567800000000+register
        self.saved={register:self.regs[register] for register in (*range(16,24),30)}
        self.fpr=fp.fpr_seed();self.fcr31=0x183FFFF
        self.initialize_mac(hi=1,lo=2,hi1=3,lo1=4);self.extension_counts={};self.steps=0;self.visited={};self.calls={};self.events=[]

    def instruction(self,pc,word):
        if not fp.fp_word(word):return super().instruction(pc,word)
        if word not in self.words:raise OracleError('Unqualified admission FP word')
        op=word>>26;address=0;memory=0
        if op in [0x31,0x39]:
            address=((self.regs[(word>>21)&31]&0xFFFFFFFF)+signed(word,16))&0xFFFFFFFF
            if op==0x31:memory=self.mem.load(address,4)
        result=self.worker.step(word,self.fcr31,self.regs,self.fpr,memory)
        self.regs=result['regs'];self.regs[0]=0;self.fpr=result['fpr'];self.fcr31=result['fcr31'];self.fp_steps+=1
        if op in [0x31,0x39] and result['memory_address']!=address:raise OracleError('FP memory address mismatch')
        if result['memory_write']:self.mem.store(address,4,result['memory_value'])
        if op==0x11 and (word>>21)&31==8:return result['branch'],(pc+4+signed(word,16)*4)&0xFFFFFFFF,result['likely']
        return None

    def capture(self):
        active,self.mem.active=self.mem.active,False
        raw=bytearray(self.mem.load(MAIN,0x3000).to_bytes(0x3000,'little'))
        for offset in FIELDS.values():raw[offset:offset+4]=bytes(4)
        value=dict(state={name:self.mem.load(MAIN+offset,4) for name,offset in FIELDS.items()},decision=self.mem.load(OUT,4),main_guard_sha256=hashlib.sha256(raw).hexdigest(),prefix=self.mem.words(OUT-16,4),suffix=self.mem.words(OUT+4,4),fpr=self.fpr.copy(),fcr31=self.fcr31)
        self.mem.active=active;return value

    def execute(self,operation):
        self.regs[29]=TOP;self.regs[31]=RETURN;kind=operation['kind']
        args=[MAIN,operation['query'][0],operation['query'][1],OUT,operation['slack']] if kind=='core' else [MAIN,operation['query'][0],operation['query'][1],OUT] if kind=='fallback' else [MAIN,OUT]
        for n,value in enumerate(args):self.regs[4+n]=value if n==0 or value==OUT else sext32(value)
        self.mem.store(TOP-0x50,4,operation['scratch'][0]);self.mem.store(TOP-0x4C,4,operation['scratch'][1])
        self.fpr[12]=operation['query_bits'];self.fpr[13]=operation['current_bits']
        before=self.capture();start=self.steps;fp_start=self.fp_steps;event_start=len(self.events);write_start=len(self.mem.writes);read_start=len(self.mem.reads)
        pc,pending=ENTRIES[kind],None;self.mem.active=True
        while pc!=RETURN:
            if self.steps-start>=2000:raise StepLimit('Admission operation exhausted')
            if pc==0x176350:
                if pending is not None or self.regs[4]!=MAIN or self.regs[5]!=TOP-0x50 or self.regs[6]!=TOP-0x4C:raise OracleError('Cached-clock port identity')
                self.events.append(dict(kind='cached_clock',before=self.capture(),prior=[self.mem.load(self.regs[5],4),self.mem.load(self.regs[6],4)]))
                for n,value in enumerate(operation['sample']):
                    if operation['mask']&(1<<n):self.mem.store(self.regs[5+n],4,value)
                for name,value in operation['updates'].items():
                    if name not in FIELDS:raise OracleError('Undeclared post-query update')
                    self.mem.store(MAIN+FIELDS[name],4,value)
                for register in [1,*range(2,16),24,25]:self.regs[register]=0xCBCB000000000000+register
                self.regs[2]=sext32(operation['query_status']);pc=self.regs[31]&0xFFFFFFFF;continue
            if pc not in self.code or pc%4:raise OracleError('Unowned admission transfer '+hex(pc))
            self.steps+=1;self.visited[pc]=self.visited.get(pc,0)+1
            if pc in INTERVALS:self.calls[pc]=self.calls.get(pc,0)+1
            branch=self.instruction(pc,self.code[pc])
            if pending is not None:
                if branch is not None:raise OracleError('Branch in delay slot')
                pc,pending=pending,None
            elif branch is None:pc+=4
            else:
                taken,target,likely=branch
                if likely and not taken:pc+=8
                else:pending=target if taken else pc+8;pc+=4
        self.mem.active=False;after=self.capture()
        if self.regs[29]!=TOP or any(self.regs[register]!=value for register,value in self.saved.items()):raise OracleError('Admission ABI restoration')
        if any(before[name]!=after[name] for name in ['main_guard_sha256','prefix','suffix']):raise OracleError('Admission escaped declared fields')
        return dict(operation=operation,before=before,after=after,instructions=self.steps-start,fp_steps=self.fp_steps-fp_start,events=self.events[event_start:],writes=self.mem.writes[write_start:],reads=self.mem.reads[read_start:])


def operation(kind='core',**changes):
    value=dict(kind=kind,query=[1600,48000],sample=[1600,48000],slack=0,scratch=[0xCCCCCCCC,0xCCCCCCCC],mask=3,query_status=0,updates={},query_bits=0x447A0000,current_bits=0x447A0000)
    value.update(changes)
    for name in ['query','sample','scratch']:value[name]=[v&0xFFFFFFFF for v in value[name]]
    value['slack'] &= 0xFFFFFFFF
    return value


def corpus():
    cases=[]
    def add(name,operations,state=None,frequency=48000):
        initial=dict(selector=0,tolerance=10,rate=1,increment=1000,count=100,tracked_bits=0xBF800000,cached=1,previous_bits=0xBF800000,auxiliary=0xFFFFFFFF)
        initial.update({name:value&0xFFFFFFFF for name,value in (state or {}).items()});cases.append(dict(name=name,state=initial,frequency=frequency&0xFFFFFFFF,operations=operations))
    samples=[[-2,1],[-1,1],[0,1],[1000,90000],[1600,48000],[0,0],[0x7FFFFFFF,0x7FFFFFFF],[-2147483648,-1]]
    queries=[[0,1],[1000,48000],[1600,48000],[-1,48000],[1600,-1],[1600,0],[0x7FFFFFFF,1],[-2147483648,0x7FFFFFFF]]
    for sample in samples:
        for query in queries:
            for selector in [0,1,2]:add('core-'+str(len(cases)),[operation(sample=sample,query=query)],dict(selector=selector))
    for auxiliary in [-2147483648,-1,0,1,1600,2147483647]:
        for frequency in [0,48000,-1]:add('fallback-'+str(len(cases)),[operation('fallback',query=[1600,48000])],dict(auxiliary=auxiliary),frequency)
    for frequency in [1,-1,-2147483648,59940]:
        for denominator,slack in [(48000,5000),(-2147483648,1),(0x7FFFFFFF,0x7FFFFFFF)]:add('slack-'+str(len(cases)),[operation(sample=[1600,denominator],slack=slack)],frequency=frequency)
    raw_queries=[0,0x80000000,0x44778000,0x4477C000,0x447A0000,0x447C4000,0x447C8000,0x7FC12345,0x7FA12345,0x7F800000,0xFF800000]
    for bits in raw_queries:
        for count in [0,1,2,0xFFFFFFFF]:
            for frequency in [48000,59940]:add('hysteresis-'+str(len(cases)),[operation('hysteresis',query_bits=bits)],dict(count=count,cached=0),frequency)
    for rate,increment in [(-1,1000),(2,1000),(3,1000),(1,999),(1,1001)]:add('special-threshold-'+str(len(cases)),[operation('hysteresis',query_bits=0x447A0000,current_bits=0x44790000)],dict(rate=rate,increment=increment,count=1,cached=7),59940)
    for previous,tracked in [(0x44778000,0),(0,0x44778000),(0x80000000,0),(0x7FC12345,0x7FC12345)]:add('duplicate-'+str(len(cases)),[operation('hysteresis',query_bits=0x44778000)],dict(previous_bits=previous,tracked_bits=tracked,count=0xFFFFFFFF))
    add('stateful-hysteresis',[operation('hysteresis',query_bits=bits) for bits in [0x44778000,0x44778000,0x4477C000,0x447A0000,0x447A0000,0x447C8000,0x447A0000]])
    for mask in [0,1,2]:add('partial-query-'+str(mask),[operation(mask=mask,scratch=[900,48000],sample=[1000,90000],query_status=0x81234567)])
    add('post-query-facts',[operation(updates=dict(selector=1,tolerance=0,auxiliary=1000),query_status=0x81234567)])
    for sign in [1,-1]:add('wrapped-margin-'+str(sign),[operation(sample=[0,48000],query=[sign*48000,48000],slack=sign*100000)],dict(selector=1))
    for numerator,denominator in [(1000,48000),(1001,48000),(1601,90000),(16777217,48000)]:
        add('equal-rounded-ratios-'+str(numerator),[operation(sample=[numerator,denominator],query=[numerator,denominator])],dict(selector=1))
    return cases


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    out.mkdir(parents=True);fp.FP_INTERVALS={0x1770F0:0x177240,0x1772B8:0x1773A8};statements=fp.reference_statements(ROOT/'recomp/config/output');source=worker_source(statements)
    cpp=out/'fp_worker.cpp';cpp.write_text(source,encoding='utf-8',newline='\n');binary=out/'fp_worker.exe'
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-msse4.1','-fno-fast-math','-ffp-contract=off','-frounding-math',str(cpp),'-o',str(binary)]
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','');os.environ['PATH']=env['PATH']
    built=subprocess.run(flags,text=True,capture_output=True,env=env,timeout=60);(out/'compiler.txt').write_text(built.stdout+built.stderr,encoding='utf-8',newline='\n')
    if built.returncode:raise OracleError('Scoped FP worker compilation failed')
    cases=corpus();sources=[Path(__file__)]+[ROOT/'tools/native_reconstruction'/name for name in ['adx_header_math_oracle.py','adx_header_oracle.py','adx_window_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','movie_position_oracle.py','sjuni_oracle.py']]
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(path.relative_to(ROOT)):sha(path) for path in sources},fp_emission=statements,native_exists=(ROOT/'game/native/movie_admission').exists(),compiler=cc,compiler_sha256=sha(Path(cc)),fp_worker_sha256=sha(binary),fp_worker_source_sha256=sha(cpp),runtime_identity=fp.implementation_identity(),cached_clock_port='Declared selective words and authored post-query state updates; not actual provider/lifetime proof.',game_run=False,device_opened=False)
    manifest['existing_native_sources']={path.name:sha(path) for path in (ROOT/'game/native/movie_admission').iterdir() if path.is_file() and path.suffix in ['.cpp','.hpp','.py','.txt','.json']}
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    results=[];micro=[];excluded=[]
    try:
        with fp.FpuWorker(binary) as worker:
            words=set(fp.fp_words().values())
            for word in sorted(words):
                for index,value in enumerate([0,0x80000000,1,0x3F800000,0xBF800000,0x7F7FFFFF,0x7F800000,0xFF800000,0x7FC12345,0x7FA12345,0xFFFFFFFF]):
                    regs=[0]+[(0x1234567800000000+value+n)&((1<<64)-1) for n in range(1,32)]
                    values=[0,0x80000000,0x3F800000,0xBF800000,0x7FC12345];fpr=[values[(n+index)%len(values)] for n in range(32)];fpr[(word>>11)&31]=value
                    for fcr in [0,0x800000]:
                        reference=worker.step(word,fcr,regs,fpr,value,mode=1);generic=worker.step(word,fcr,regs,fpr,value,mode=0)
                        if reference!=generic:raise OracleError('Original emitted/extended FP worker mismatch '+hex(word))
                        micro.append(dict(word=word,value=value,fcr=fcr,result=reference))
            for case in cases:
                machine=Machine(case,worker,words);rows=[machine.execute(op) for op in case['operations']];results.append(dict(name=case['name'],operations=rows,instructions=machine.steps,fp_steps=machine.fp_steps,calls={hex(pc):count for pc,count in machine.calls.items()},visits={hex(pc):count for pc,count in machine.visited.items()}))
            for denominator,updates in [(48000,{}),(0,{}),(48000,dict(count=7,selector=1))]:
                case=json.loads(json.dumps(cases[0]));case['frequency']=0;op=operation(sample=[1600,denominator],updates=updates)
                machine=Machine(case,worker,words);before=machine.capture()
                try:
                    machine.execute(op);raise AssertionError('Excluded zero-frequency source arithmetic unexpectedly returned')
                except OracleError as error:
                    machine.mem.active=False;excluded.append(dict(input=case,operation=op,error=str(error),status='partial architectural DIV-by-zero refusal before original BREAK; not returned original failure parity',before=before,after=machine.capture(),instructions=machine.steps,events=machine.events))
        for name,value in [('original.json',results),('micro-qualification.json',micro),('exclusions.json',excluded)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt=dict(schema=1,status='original bounded admission arithmetic returned',cases=len(cases),operations=sum(len(case['operations']) for case in cases),instructions=sum(row['instructions'] for row in results),fp_steps=sum(row['fp_steps'] for row in results),raw_bit_qualification_cases=len(micro),excluded_partial_cases=len(excluded),native_exists=manifest['native_exists'],outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json','micro-qualification.json','exclusions.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(status='failed',completed_cases=len(results),failure=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],operations=receipt['operations'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
