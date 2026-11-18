#!/usr/bin/env python3
"""Joined original timing workflows; declared samples/commands, no game/device."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import adx_header_math_oracle as fp
import movie_admission_oracle as admission
import movie_audio_clock_oracle as audio
import movie_audio_filter_oracle as filters
import movie_clock_initialize_oracle as initialize
import movie_counter_clock_oracle as counters
import movie_pause_oracle as pause
import movie_position_oracle as math
import movie_selected_clock_oracle as selected
from adx_stereo_oracle import EeDivInstructions
from ee_copy_store_oracle import CopyStoreInstructions
from sjuni_oracle import Elf,OracleError,StepLimit,sext32,signed

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-timing-context'
MAIN,CLOCK,FILTER=0x400000,0x400CC0,0x400F60
CHILD,ADXT,NUM,DEN,OUT,NESTED=0x600000,0x600100,0x600200,0x600204,0x600208,0x600220
STACK,TOP,RETURN=0x700000,0x701000,0xFFFFF0
DIAGNOSTIC,LAST,FREQUENCY,HELPER_FREQUENCY=0x22EF68,0x22EF80,0x22F140,0x22F980
FACTS=dict(actual=0x48,requested=0x4C,pause=0x50,depth=0x54,pending=0x44,buffering=0x964,episodes=0x968,
           rate=0x920,property_e=0x9D8,selector=0x9DC,property_47=0xABC,tolerance=0xA58,admit_slack=0xA50,requested_slack=0xA54)
ENTRIES=dict(selected=0x176418,cached=0x176350,refresh=0x176930,tick=0x175E00,pause=0x1720C8,buffer=0x172C48,admit=0x176F68,requested_admit=0x177028,picture_request=0x176FA0)
PORTS={0x132160:'estimate',0x17E870:'counter',0x177BE0:'command',0x172CF8:'pause_predicate',0x172E78:'resume_predicate',0x169C10:'error',0xF00010:'guard_enter',0xF00020:'guard_leave'}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(CopyStoreInstructions,EeDivInstructions,math.ClockIntegerInstructions):
    def __init__(self,case,worker,qualified):
        self.elf=Elf(ROOT/'game_data/SLUS_207.65')
        if self.elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise OracleError('Owned full ELF identity')
        self.code={};self.body_ids={};self.worker=worker;self.qualified=qualified;self.case=case
        intervals=[]
        for group in [filters.BODIES,counters.BODIES,selected.BODIES,audio.BODIES,initialize.BODIES]:
            intervals += [(start,end,digest) for start,(end,digest) in group.items()]
        intervals += [(start,end,None) for group in [pause.INTERVALS,admission.INTERVALS] for start,end in group.items()]
        intervals += [(0x15BA80,*math.BODIES[0x15BA80]),(0x131EF8,0x131F28,None),(0x17E998,0x17E9A8,None),(0x176F68,0x176FA0,None),(0x176FA0,0x177028,None),(0x177028,0x1770F0,None)]
        for start,end,digest in intervals:
            data=self.elf.read(start,end-start);actual=hashlib.sha256(data).hexdigest()
            if digest and actual!=digest:raise OracleError('Joined body identity '+hex(start))
            self.body_ids[hex(start)+':'+hex(end)]=actual
            for n in range(0,len(data),4):
                word=struct.unpack_from('<I',data,n)[0]
                if start+n in self.code and self.code[start+n]!=word:raise OracleError('Conflicting owned word')
                self.code[start+n]=word
        self.mem=math.AccessMemory()
        for name,address,length,write,fill in [('main',MAIN,0x3000,True,0xA5),('child',CHILD,64,True,0),('adxt',ADXT,64,False,0),('outputs',NUM,0x80,True,0x5A),('stack',STACK,0x3000,True,0xCC),
            ('diagnostic',DIAGNOSTIC,4,True,0),('last',LAST,4,True,0),('frequency',FREQUENCY,4,False,0),('helper_frequency',HELPER_FREQUENCY,8,False,0),
            ('csv',filters.GLOBALS,20,True,0),('guard_hooks',selected.HOOKS,16,False,0),('guard_state',selected.GUARD,8,True,0)]:self.mem.span(name,address,length,write,fill)
        for name,address,length in [('normalization',math.NORM,math.NORM_BYTES),('rates',math.RATE,36),('csv_header',filters.HEADER,274)]:
            self.mem.span(name,address,length,False,0);self.mem.store(address,length,int.from_bytes(self.elf.read(address,length),'little'))
        self.mem.store(FREQUENCY,4,case['frequency']);self.mem.store(HELPER_FREQUENCY,8,case['helper_frequency'])
        for n,value in enumerate([0xF00010 if case['hooks'] else 0,0x11223344,0xF00020 if case['hooks'] else 0,0x55667788]):self.mem.store(selected.HOOKS+n*4,4,value)
        self.mem.store(selected.GUARD,4,case['guard_depth']);self.mem.store(selected.GUARD+4,4,case['guard_tag'])
        for name,offset in FACTS.items():self.mem.store(MAIN+offset,4,case['facts'][name])
        self.mem.store(MAIN+0x1B74,4,CHILD);self.mem.store(CHILD,4,ADXT);self.mem.store(CHILD+0x24,4,0);self.mem.store(CHILD+0x28,4,1)
        self.regs=[0]*32
        for register in (*range(16,24),30):self.regs[register]=0x1234567800000000+register
        self.saved={register:self.regs[register] for register in (*range(16,24),30)}
        self.fpr=fp.fpr_seed();self.fcr31=0x183FFFF;self.initialize_copy_store();self.initialize_mac(hi=1,lo=2,hi1=3,lo1=4);self.extension_counts={}
        self.steps=0;self.fp_steps=0;self.calls={};self.visits={};self.events=[];self.operation={};self.nesting=0
        self.run_body(0x175A50,[MAIN,CLOCK]);self.run_body(0x177CB0,[FILTER]);self.mem.store(CLOCK+8,4,0x165B48)
        self.initial=self.capture()

    def instruction(self,pc,word):
        if not fp.fp_word(word):return super().instruction(pc,word)
        if word not in self.qualified:raise OracleError('Unqualified joined FP word')
        op=word>>26;address=0;memory=0
        if op in [0x31,0x39]:
            address=((self.regs[(word>>21)&31]&0xFFFFFFFF)+signed(word,16))&0xFFFFFFFF
            if op==0x31:memory=self.mem.load(address,4)
        result=self.worker.step(word,self.fcr31,self.regs,self.fpr,memory);self.regs=result['regs'];self.regs[0]=0;self.fpr=result['fpr'];self.fcr31=result['fcr31'];self.fp_steps+=1
        if op in [0x31,0x39] and result['memory_address']!=address:raise OracleError('FP memory address mismatch')
        if result['memory_write']:self.mem.store(address,4,result['memory_value'])
        if op==0x11 and (word>>21)&31==8:return result['branch'],(pc+4+signed(word,16)*4)&0xFFFFFFFF,result['likely']
        return None

    def capture(self):
        active,self.mem.active=self.mem.active,False
        value=dict(facts={name:self.mem.load(MAIN+offset,4) for name,offset in FACTS.items()},clock=self.mem.words(CLOCK,168),filter=self.mem.words(FILTER,112),audio_cache=self.mem.words(CHILD+0x24,2),guard=[self.mem.load(selected.GUARD,4),self.mem.load(selected.GUARD+4,4)],diagnostic=self.mem.load(DIAGNOSTIC,4),validated=self.mem.load(LAST,4),last_filter=self.mem.load(filters.GLOBALS+8,4),caller=self.mem.words(NUM,3))
        raw=bytearray(self.mem.load(MAIN,0x3000).to_bytes(0x3000,'little'))
        raw[0xCC0:0x1120]=bytes(0x460)
        for offset in FACTS.values():raw[offset:offset+4]=bytes(4)
        value['main_guard_sha256']=hashlib.sha256(raw).hexdigest();self.mem.active=active;return value

    def port(self,pc):
        kind=PORTS[pc];args=[value&0xFFFFFFFF for value in self.regs[4:9]];event=dict(kind=kind,before=self.capture(),arguments=args,nesting=self.nesting);self.events.append(event)
        returned=0
        if kind=='estimate':
            if self.regs[4]!=ADXT:raise OracleError('Joined estimator identity')
            for address,value in zip(self.regs[5:7],self.operation['sample'],strict=True):self.mem.store(address,4,value)
            returned=0x81234567
        elif kind=='counter':returned=self.operation['counter']
        elif kind in ['pause_predicate','resume_predicate']:returned=self.operation['predicate']
        elif kind=='command':
            if args[:3]!=[MAIN,7,8] or args[4]!=0:raise OracleError('Joined fixed command route')
            if self.operation['nested_query']:
                saved_return=self.regs[31];saved_sp=self.regs[29];self.nesting+=1
                nested=self.run_body(0x176418,[MAIN,NESTED,NESTED+4],top=saved_sp,return_pc=0xFFFFE0)
                event['nested_result']=dict(pair=self.mem.words(NESTED,2),returned=nested&0xFFFFFFFF);self.nesting-=1;self.regs[31]=saved_return;self.regs[29]=saved_sp
            for name,value in self.operation['command_updates'].items():
                if name not in FACTS:raise OracleError('Undeclared command update')
                self.mem.store(MAIN+FACTS[name],4,value)
            returned=self.operation['command_status']
        elif kind=='error':returned=self.operation['error_status']
        for register in [1,*range(2,16),24,25]:self.regs[register]=0xCDCD000000000000+register
        self.regs[2]=sext32(returned) if kind!='counter' else returned&((1<<64)-1)
        return self.regs[31]&0xFFFFFFFF

    def run_body(self,entry,arguments,top=TOP,return_pc=RETURN):
        entry_saved={register:self.regs[register] for register in self.saved}
        self.regs[29]=top;self.regs[31]=return_pc
        for n,value in enumerate(arguments):self.regs[4+n]=value if value in [MAIN,CLOCK,FILTER,NUM,DEN,OUT,NESTED,NESTED+4] else sext32(value)
        pc,pending=entry,None;start=self.steps;active=self.mem.active;self.mem.active=True
        try:
            while pc!=return_pc:
                if self.steps-start>=100000:raise StepLimit('Joined original operation exhausted')
                if pc in PORTS:
                    if pending is not None:raise OracleError('Port in delay slot')
                    pc=self.port(pc);continue
                if pc not in self.code or pc%4:raise OracleError('Unowned joined transfer '+hex(pc))
                self.steps+=1;self.visits[pc]=self.visits.get(pc,0)+1
                if any(int(key.split(':')[0],16)==pc for key in self.body_ids):self.calls[pc]=self.calls.get(pc,0)+1
                branch=self.instruction(pc,self.code[pc])
                if pending is not None:
                    if branch is not None:raise OracleError('Branch in delay slot')
                    pc,pending=pending,None
                elif branch is None:pc+=4
                else:
                    taken,target,likely=branch
                    if likely and not taken:pc+=8
                    else:pending=target if taken else pc+8;pc+=4
        finally:self.mem.active=active
        if self.regs[29]!=top or any(self.regs[register]!=value for register,value in entry_saved.items()):raise OracleError('Joined callee-save restoration')
        return self.regs[2]

    def execute(self,operation):
        self.operation=operation
        for name,value in operation['facts'].items():self.mem.store(MAIN+FACTS[name],4,value)
        self.mem.store(ADXT+1,1,operation['adxt_status']);self.mem.store(HELPER_FREQUENCY,8,operation['helper_frequency'])
        # Source paths with a guaranteed defining callback do not consume these
        # scratch words; leave them authored for transparent partial records.
        before=self.capture();start=self.steps;event_start=len(self.events);write_start=len(self.mem.writes);read_start=len(self.mem.reads)
        kind=operation['kind'];args=[MAIN,NUM,DEN] if kind in ['selected','cached'] else [MAIN,operation['value']] if kind=='pause' else [MAIN,*operation['query'],OUT] if kind=='requested_admit' else [MAIN,*operation['query']] if kind in ['admit','picture_request'] else [MAIN]
        returned=self.run_body(ENTRIES[kind],args);after=self.capture()
        if before['main_guard_sha256']!=after['main_guard_sha256']:raise OracleError('Joined controller escaped declared state')
        return dict(operation=operation,before=before,after=after,instructions=self.steps-start,return_defined=kind not in ['refresh','tick'],returned=returned&0xFFFFFFFF,events=self.events[event_start:],writes=self.mem.writes[write_start:],reads=self.mem.reads[read_start:])


def operation(kind,number=0,**changes):
    value=dict(kind=kind,value=number&0xFFFFFFFF,query=[6400,48000],sample=[number*1600&0xFFFFFFFF,48000],counter=number*19200,helper_frequency=576000,adxt_status=3,predicate=1,nested_query=False,command_status=0,error_status=0x81234567,command_updates={},facts={})
    value.update(changes);return value


def corpus():
    cases=[]
    def add(name,operations,facts=None,**changes):
        initial=dict(actual=4,requested=4,pause=0,depth=0,pending=0,buffering=0,episodes=0,rate=4,property_e=0,selector=2,property_47=1,tolerance=10,admit_slack=0,requested_slack=0)
        initial.update({name:value&0xFFFFFFFF for name,value in (facts or {}).items()})
        case=dict(name=name,facts=initial,frequency=48000,helper_frequency=576000,hooks=0,guard_depth=0,guard_tag=0,operations=operations);case.update(changes);cases.append(case)
    sequence=[operation('selected',0),operation('selected',1),operation('cached',2),operation('refresh',3),operation('cached',999),operation('tick',4),operation('picture_request',query=[8000,48000]),operation('admit',query=[6400,48000]),operation('pause',1,nested_query=True,sample=[8000,48000],counter=96000),operation('tick',5),operation('pause',2,nested_query=True,sample=[9600,48000],counter=115200),operation('buffer',6),operation('pause',0),operation('buffer',7,nested_query=True),operation('requested_admit',8),operation('requested_admit',9,facts=dict(property_e=1,requested=3)),operation('requested_admit',10,facts=dict(requested=4)),operation('selected',11,facts=dict(actual=0xFFFFFFFC)),operation('pause',1,facts=dict(actual=0))]
    add('joined-progress-pause-buffer-due',sequence,hooks=1)
    for hooks in [0,1]:
        for depth,tag in [(0,0),(1,9),(0xFFFFFFFF,9)]:
            add('nested-buffer-query-'+str(len(cases)),[operation('buffer',1,nested_query=True),operation('buffer',2,nested_query=True),operation('refresh',3),operation('admit',4)],hooks=hooks,guard_depth=depth,guard_tag=tag)
    for selector in [0,1,2,5]:
        for actual in [4,-4,6,-6,0]:add('prepared-source-'+str(len(cases)),[operation('cached',1),operation('refresh',2),operation('tick',3),operation('admit',4),operation('requested_admit',5,facts=dict(property_e=1))],dict(selector=selector,actual=actual),hooks=1)
    for prop in [0,1,2]:
        for pause_word in [0,1,2]:add('tick-gates-'+str(len(cases)),[operation('refresh',1),operation('tick',2),operation('pause',1),operation('tick',3),operation('pause',0),operation('tick',4)],dict(property_47=prop,pause=pause_word,depth=int(bool(pause_word))))
    add('component-published-state',[operation('buffer',1,nested_query=True,command_status=19,command_updates=dict(actual=6,requested=3,pause=2,depth=7,pending=99)),operation('selected',2),operation('tick',3)],hooks=1)
    add('counter-clock-observed-during-frame-step',[operation('pause',2,nested_query=True),operation('tick',3),operation('admit',4)],dict(selector=1,pause=1,depth=1),hooks=1)
    add('counter-clock-observed-during-buffer-command',[operation('buffer',1,nested_query=True),operation('buffer',2,nested_query=True),operation('tick',3)],dict(selector=1),hooks=1)
    add('component-property-effects',[operation('buffer',1,nested_query=True,command_updates=dict(property_e=1,selector=1,property_47=0,tolerance=0)),operation('admit',2),operation('requested_admit',3),operation('tick',4)],hooks=1)
    return cases


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh output required')
    out.mkdir(parents=True);fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8};statements=fp.reference_statements(ROOT/'recomp/config/output');source=admission.worker_source(statements)
    cpp=out/'fp_worker.cpp';cpp.write_text(source,encoding='utf-8',newline='\n');binary=out/'fp_worker.exe';env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','');os.environ['PATH']=env['PATH']
    command=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-msse4.1','-fno-fast-math','-ffp-contract=off','-frounding-math',str(cpp),'-o',str(binary)]
    built=admission.subprocess.run(command,text=True,capture_output=True,env=env,timeout=60);(out/'compiler.txt').write_text(built.stdout+built.stderr,encoding='utf-8',newline='\n')
    if built.returncode:raise OracleError('Joined FP worker compilation failed')
    cases=corpus();sources=[Path(__file__)]+[ROOT/'tools/native_reconstruction'/name for name in ['movie_admission_oracle.py','movie_audio_clock_oracle.py','movie_audio_filter_oracle.py','movie_clock_initialize_oracle.py','movie_counter_clock_oracle.py','movie_pause_oracle.py','movie_position_oracle.py','movie_selected_clock_oracle.py','ee_copy_store_oracle.py','adx_header_math_oracle.py','adx_header_oracle.py','adx_window_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','sjuni_oracle.py']]
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(path.relative_to(ROOT)):sha(path) for path in sources},fp_emission=statements,native_exists=(ROOT/'game/native/movie_timing_context').exists(),compiler=cc,compiler_sha256=sha(Path(cc)),fp_worker_sha256=sha(binary),fp_worker_source_sha256=sha(cpp),runtime_identity=fp.implementation_identity(),profile='Prepared one-context audio binding; actual estimator/counter, complete predicates/commands/errors are declared ports; command ports optionally perform real nested original selected query.',game_run=False,device_opened=False)
    manifest['existing_native_sources']={str(path.relative_to(ROOT)):sha(path) for path in (ROOT/'game/native/movie_timing_context').iterdir() if path.is_file()}
    manifest['control_extension_sources']={str(path.relative_to(ROOT)):sha(path) for path in [ROOT/'game/native/movie_selected_clock'/name for name in ['clock.cpp','clock.hpp']]+[ROOT/'game/native/movie_pause'/name for name in ['controller.cpp','controller.hpp']]+[ROOT/'game/native/movie_audio_clock/clock.cpp']}
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    results=[];micro=[]
    try:
        with fp.FpuWorker(binary) as worker:
            words=set(fp.fp_words().values())
            for word in sorted(words):
                for fcr in [0,0x800000]:
                    regs=[0]+[0x1234567800000000+n for n in range(1,32)];fpr=fp.fpr_seed()
                    a=worker.step(word,fcr,regs,fpr,0x7FA12345,mode=0);b=worker.step(word,fcr,regs,fpr,0x7FA12345,mode=1)
                    if a!=b:raise OracleError('Joined emitted FP word mismatch')
                    micro.append(dict(word=word,fcr=fcr,result=b))
            for case in cases:
                machine=Machine(case,worker,words);rows=[machine.execute(op) for op in case['operations']];results.append(dict(name=case['name'],initial=machine.initial,operations=rows,instructions=machine.steps,fp_steps=machine.fp_steps,body_identities=machine.body_ids,calls={hex(pc):count for pc,count in machine.calls.items()}))
        for name,value in [('original.json',results),('micro-qualification.json',micro)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt=dict(schema=1,status='joined original prepared movie timing workflows returned',cases=len(cases),operations=sum(len(case['operations']) for case in cases),instructions=sum(row['instructions'] for row in results),fp_steps=sum(row['fp_steps'] for row in results),qualified_joined_word_cases=len(micro),native_exists=manifest['native_exists'],outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json','micro-qualification.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(status='failed',completed_cases=len(results),failure=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],operations=receipt['operations'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
