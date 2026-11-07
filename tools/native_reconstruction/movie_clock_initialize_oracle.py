#!/usr/bin/env python3
"""Original complete clock initialization with qualified emitted FP bit moves."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import struct
import subprocess
import adx_header_math_oracle as fp
from movie_position_oracle import AccessMemory,ClockIntegerInstructions
from sjuni_oracle import Elf,OracleError,StepLimit

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/movie-clock-initialize'
MAIN,CLOCK,STACK,TOP,RETURN=0x400000,0x400CC0,0x700000,0x701000,0xFFFFF0
BODIES={0x175A50:(0x175C50,'4239555a0189dccae97c91e84fd795ee1f3257327fb8abdd76b485be69c462c7'),0x175C50:(0x175C98,None),0x175C98:(0x175CB8,None),0x1769B0:(0x1769C0,None)}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(ClockIntegerInstructions):
    def __init__(self,case,worker,qualified_words):
        self.elf=Elf(ROOT/'game_data/SLUS_207.65')
        if self.elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise OracleError('Owned ELF identity')
        self.code={};self.body_identities={};self.worker=worker;self.qualified_words=qualified_words;self.fp_steps=0
        for start,(end,digest) in BODIES.items():
            data=self.elf.read(start,end-start);actual=hashlib.sha256(data).hexdigest()
            if digest and actual!=digest:raise OracleError('Owned constructor identity')
            self.body_identities[hex(start)]=dict(end=hex(end),sha256=actual)
            self.code.update({start+n:struct.unpack_from('<I',data,n)[0] for n in range(0,len(data),4)})
        self.mem=AccessMemory();self.mem.span('main',MAIN,0x3000,True,case['fill']);self.mem.span('stack',STACK,0x2000,True,0xCC)
        self.regs=[0]*32
        for reg in (*range(16,24),30):self.regs[reg]=0x1234567800000000+reg
        self.saved={reg:self.regs[reg] for reg in (*range(16,24),30)}
        self.regs[4]=MAIN;self.regs[5]=CLOCK;self.regs[29]=TOP;self.regs[31]=RETURN
        self.fpr=[(case['fpr_seed']+n*0x10203)&0xFFFFFFFF for n in range(32)];self.fcr31=case['fcr31']
        self.initialize_mac(hi=1,lo=2,hi1=3,lo1=4);self.extension_counts={};self.steps=0;self.calls={};self.visited={}

    def instruction(self,pc,word):
        if not fp.fp_word(word):return super().instruction(pc,word)
        if word not in self.qualified_words:raise OracleError('Unqualified constructor FP word')
        result=self.worker.step(word,self.fcr31,self.regs,self.fpr)
        self.regs=result['regs'];self.regs[0]=0;self.fpr=result['fpr'];self.fcr31=result['fcr31'];self.fp_steps+=1
        if result['memory_write']:self.mem.store(result['memory_address'],4,result['memory_value'])
        return None

    def capture(self):
        active,self.mem.active=self.mem.active,False
        raw=bytearray(self.mem.load(MAIN,0x3000).to_bytes(0x3000,'little'));raw[0xCC0:0xF60]=bytes(0x2A0)
        value=dict(clock=self.mem.words(CLOCK,168),main_guard_sha256=hashlib.sha256(raw).hexdigest(),fpr=self.fpr.copy(),fcr31=self.fcr31)
        self.mem.active=active;return value

    def run(self):
        before=self.capture();pc,pending=0x175A50,None;self.mem.active=True
        while pc!=RETURN:
            if self.steps>=2000:raise StepLimit('Clock initialization bound exhausted')
            if pc not in self.code or pc%4:raise OracleError('Unowned constructor transfer '+hex(pc))
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
        self.mem.active=False;after=self.capture()
        if self.regs[29]!=TOP or any(self.regs[reg]!=value for reg,value in self.saved.items()):raise OracleError('Constructor ABI restoration')
        if before['main_guard_sha256']!=after['main_guard_sha256']:raise OracleError('Constructor escaped clock block')
        if before['fcr31']!=after['fcr31'] or before['fpr'][1:]!=after['fpr'][1:] or after['fpr'][0]!=0xBF800000:raise OracleError('Unexpected FP bit-move effects')
        written={byte for row in self.mem.writes if row['span']=='main' for byte in range(row['offset'],row['offset']+row['bytes'])}
        if written!=set(range(0xCC0,0xF60)):raise OracleError('Incomplete/escaped clock initialization extent')
        return dict(before=before,after=after,instructions=self.steps,fp_steps=self.fp_steps,calls={hex(pc):count for pc,count in self.calls.items()},visits={hex(pc):count for pc,count in self.visited.items()},writes=self.mem.writes,reads=self.mem.reads)


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);args=p.parse_args();out=args.output.resolve();cc=shutil.which(args.cxx)
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    out.mkdir(parents=True);fp.FP_INTERVALS={0x175A50:0x175C50}
    statements=fp.reference_statements(ROOT/'recomp/config/output');source=fp.worker_source(statements)
    cpp=out/'fp_worker.cpp';cpp.write_text(source,encoding='utf-8',newline='\n');binary=out/'fp_worker.exe'
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-msse4.1','-fno-fast-math','-ffp-contract=off','-frounding-math',str(cpp),'-o',str(binary)]
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','');os.environ['PATH']=env['PATH']
    built=subprocess.run(flags,text=True,capture_output=True,env=env,timeout=60);(out/'compiler.txt').write_text(built.stdout+built.stderr,encoding='utf-8',newline='\n')
    if built.returncode:raise OracleError('FP worker compilation failed')
    cases=[dict(name='fill-'+str(fill),fill=fill,fpr_seed=seed,fcr31=fcr) for fill,seed,fcr in [(0,0,0),(165,0x7FA12345,0x183FFFF),(255,0x80000000,0x800000),(90,0x3F800000,3)]]
    sources=[Path(__file__)]+[ROOT/'tools/native_reconstruction'/name for name in ['adx_header_math_oracle.py','adx_header_oracle.py','adx_window_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','movie_position_oracle.py','sjuni_oracle.py']]
    manifest=dict(schema=1,elf_sha256=sha(ROOT/'game_data/SLUS_207.65'),sources={str(path.relative_to(ROOT)):sha(path) for path in sources},fp_emission=statements,native_exists=(ROOT/'game/native/movie_clock_initialize').exists(),compiler=cc,compiler_sha256=sha(Path(cc)),fp_worker_sha256=sha(binary),fp_worker_source_sha256=sha(cpp),convert_sha256=sha(fp.CONVERT),runtime_identity=fp.implementation_identity(),game_run=False,device_opened=False)
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
    micro=[];results=[]
    try:
        with fp.FpuWorker(binary) as worker:
            words=set(fp.fp_words().values())
            for word in sorted(words):
                for value in [0,1,0x80000000,0xBF800000,0x7F800000,0x7FC12345,0x7FA12345,0xFFFFFFFF]:
                    regs=[0]+[(0x1234567800000000+value+n)&((1<<64)-1) for n in range(1,32)]
                    fpr=[(value+n*0x10203)&0xFFFFFFFF for n in range(32)]
                    reference=worker.step(word,0x183FFFF,regs,fpr,mode=1);generic=worker.step(word,0x183FFFF,regs,fpr,mode=0)
                    if reference!=generic:raise OracleError('Original emitted/raw-bit worker mismatch')
                    micro.append(dict(word=word,value=value,result=reference))
            for case in cases:results.append(dict(name=case['name'],**Machine(case,worker,words).run()))
        for name,value in [('original.json',results),('micro-qualification.json',micro)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt=dict(schema=1,status='original complete movie clock constructor returned',cases=len(cases),instructions=sum(row['instructions'] for row in results),fp_bit_move_steps=sum(row['fp_steps'] for row in results),raw_bit_qualification_cases=len(micro),native_exists=manifest['native_exists'],outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json','micro-qualification.json']},game_run=False,device_opened=False)
    except Exception as error:
        (out/'partial.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8',newline='\n');receipt=dict(status='failed',completed_cases=len(results),failure=str(error));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],cases=receipt['cases'],instructions=receipt['instructions'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
