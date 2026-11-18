#!/usr/bin/env python3
"""Original header/math words with compiled pinned-runtime raw-bit FP steps."""
from __future__ import annotations
import argparse
import copy
import json
from pathlib import Path
import re
import shutil
import struct
import subprocess

import adx_header_oracle as header
from sjuni_oracle import Elf, OracleError, MASK32, signed
from ee_mac_oracle import implementation_identity

ROOT=header.ROOT
MATH_BODIES={
    0x1223D0:(0x1224A4,'1c853c3b8c8b3d8dfdd8e401d55955b60f3b7e276d6f1c2f82c7de51a37755ee'),
    0x120F68:(0x1210B8,'f700e78b1d84eba817294b321975f0877968443cbc2cb8973c146855615e78b2')}
SOURCE=ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output'
MACROS=ROOT/'third_party/PS2Recomp/ps2xRuntime/include/ps2_runtime_macros.h'
CONVERT=MACROS.with_name('ps2_fpu_convert.h')
CONVERT_SHA='db9db81090400ac42fd7e391c0998887c4e922a1cb7c0d77516f47d3d8a9c8f3'
FP_INTERVALS={0x126510:0x12666C,0x1223D0:0x1224A4,0x120F68:0x1210B8}
sha,serialized=header.sha,header.serialized

def fp_word(word):return word>>26 in (0x11,0x31,0x39)
def fp_words():
    elf=Elf(ROOT/'game_data/SLUS_207.65');result={}
    for begin,end in FP_INTERVALS.items():
        for pc in range(begin,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if fp_word(word):result[pc]=word
    return result

def reference_statements(source=SOURCE):
    """Audit exact owned FP statement lines, never emit an expected math result."""
    words=fp_words();result={};files=[]
    for begin in FP_INTERVALS:
        path=next(source.glob(f'sub_{begin:08X}_*.cpp'));data=path.read_bytes();text=data.decode()
        files.append(dict(path=str(path.relative_to(ROOT)),sha256=sha(data)))
        matches=list(re.finditer(r'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)[^\n]*\n',text))
        for n,match in enumerate(matches):
            pc,word=int(match[1],16),int(match[2],16)
            if pc not in words:continue
            if words[pc]!=word:raise OracleError('Original FP statement word mismatch')
            block=text[match.end():matches[n+1].start() if n+1<len(matches) else len(text)]
            if word>>26==0x11 and (word>>21)&31==8:
                branch=re.search(r'const bool branch_taken_0x[0-9a-f]+\s*=\s*([^;]+);',block)
                if not branch:raise OracleError('Unrecognized original FP branch emission')
                statement='branch = bool('+branch[1]+'); likely = '+str(bool((word>>16)&2)).lower()+';'
            else:
                lines=[x.strip() for x in block.splitlines() if ('ctx->f[' in x or 'WRITE32(' in x) and not x.lstrip().startswith('//')]
                if len(lines)!=1:raise OracleError(f'Unrecognized exact FP statement at{pc:#x}: {lines}')
                statement=lines[0]
            if word in result and result[word]['statement']!=statement:raise OracleError('Same opcode emitted inconsistently')
            result[word]=dict(pc=pc,word_u32=word,statement=statement)
    if set(words.values())!=set(result):raise OracleError('Missing owned FP emission')
    return dict(files=files,instructions=list(result.values()))

CPP=r'''
#include <array>
#include <bit>
#include <cfenv>
#include <cmath>
#include <cstdint>
#include <cstring>
#include <iostream>
#include <limits>
#include <immintrin.h>
#include "CONVERT_HEADER"
struct R5900Context { __m128i r[32]{}; float f[32]{}; uint32_t fcr31{}; };
PINNED_HELPERS
PINNED_MACROS
uint32_t mem_value{},mem_address{};bool memory_write{};
#define READ32(address) (mem_address=uint32_t(address),mem_value)
#define WRITE32(address,value) (mem_address=uint32_t(address),mem_value=uint32_t(value),memory_write=true)
void generic(R5900Context* ctx,uint32_t word,bool& branch,bool& likely) {
 const unsigned op=word>>26,rs=(word>>21)&31,ft=(word>>16)&31,fs=(word>>11)&31,fd=(word>>6)&31,fn=word&63;
 if(op==0x31) { uint32_t bits=READ32(ADD32(GPR_U32(ctx,rs),int16_t(word)));std::memcpy(&ctx->f[ft],&bits,4);return; }
 if(op==0x39) { float value=ctx->f[ft];uint32_t bits;std::memcpy(&bits,&value,4);WRITE32(ADD32(GPR_U32(ctx,rs),int16_t(word)),bits);return; }
 if(op!=0x11) throw 1;
 if(rs==0) { uint32_t bits;std::memcpy(&bits,&ctx->f[fs],4);SET_GPR_U32(ctx,ft,bits);return; }
 if(rs==4) { uint32_t bits=GPR_U32(ctx,ft);std::memcpy(&ctx->f[fs],&bits,4);return; }
 if(rs==8 && (ft==1 || ft==3)) { branch=bool(ctx->fcr31&0x800000);likely=bool(ft&2);return; }
 if(rs==20 && fn==32) { int32_t bits;std::memcpy(&bits,&ctx->f[fs],4);ctx->f[fd]=FPU_CVT_S_W(bits);return; }
 if(rs!=16) throw 2;
 switch(fn) {
 case 0:ctx->f[fd]=FPU_ADD_S(ctx->f[fs],ctx->f[ft]);break;
 case 1:ctx->f[fd]=FPU_SUB_S(ctx->f[fs],ctx->f[ft]);break;
 case 2:ctx->f[fd]=FPU_MUL_S(ctx->f[fs],ctx->f[ft]);break;
 case 3:if(ctx->f[ft]==0.0f) {ctx->fcr31|=0x100000;uint32_t sign=(std::bit_cast<uint32_t>(ctx->f[fs])^std::bit_cast<uint32_t>(ctx->f[ft]))&0x80000000u;ctx->f[fd]=std::bit_cast<float>(0x7F7FFFFFu|sign);} else ctx->f[fd]=ctx->f[fs]/ctx->f[ft];break;
 case 4:ctx->f[fd]=FPU_SQRT_S(ctx->f[ft]);break;
 case 6:ctx->f[fd]=FPU_MOV_S(ctx->f[fs]);break;
 case 7:ctx->f[fd]=FPU_NEG_S(ctx->f[fs]);break;
 case 36:{int32_t bits=FPU_CVT_W_S(ctx->f[fs]);std::memcpy(&ctx->f[fd],&bits,4);}break;
 case 50:ctx->fcr31=FPU_C_EQ_S(ctx->f[fs],ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;
 default:throw 3;
 }
}
void reference(R5900Context* ctx,uint32_t word,bool& branch,bool& likely) {
 (void)ctx;(void)branch;(void)likely;
 switch(word) { REFERENCE_SWITCH default:throw 4; }
}
int main() {
 static_assert(sizeof(float)==4 && std::numeric_limits<float>::is_iec559);
 std::ios::sync_with_stdio(false);
 std::cout<<"READY "<<std::fegetround()<<' '<<_mm_getcsr()<<'\n'<<std::flush;
 uint32_t mode,round,word,fcr,memory;
 while(std::cin>>mode>>round>>word>>fcr>>memory) {
  R5900Context context{};
  for(int n=0;n<32;++n) {uint64_t value;std::cin>>value;context.r[n]=_mm_set_epi64x(0x123456789ABCDEF0ll,std::bit_cast<int64_t>(value));}
  for(auto& value:context.f) {uint32_t bits;std::cin>>bits;std::memcpy(&value,&bits,4);}
  if(!std::cin) return 2;
  const int rounds[]={FE_TONEAREST,FE_DOWNWARD,FE_UPWARD,FE_TOWARDZERO};
  if(round>3 || std::fesetround(rounds[round])) return 3;
  std::feclearexcept(FE_ALL_EXCEPT);
  context.fcr31=fcr;mem_value=memory;mem_address=0;memory_write=false;bool branch=false,likely=false;
  try {if(mode==0) generic(&context,word,branch,likely);else if(mode==1) reference(&context,word,branch,likely);else return 4;}
  catch(...) {return 5;}
  std::cout<<context.fcr31<<' '<<mem_address<<' '<<mem_value<<' '<<memory_write<<' '<<branch<<' '<<likely;
  for(auto value:context.r) std::cout<<' '<<uint64_t(_mm_cvtsi128_si64(value));
  for(auto value:context.f) {uint32_t bits;std::memcpy(&bits,&value,4);std::cout<<' '<<bits;}
  std::cout<<'\n'<<std::flush;
 }
}
'''

def worker_source(statements):
    implementation_identity()
    if sha(CONVERT.read_bytes())!=CONVERT_SHA:raise OracleError('Current CVT authority changed')
    text=MACROS.read_text()
    helpers=text[text.index('static inline int32_t Ps2ExtractEpi32'):text.index('static inline int64_t Ps2ExtractEpi64')]
    helpers+=text[text.index('static inline void Ps2SetGprLow64'):text.index('#define SET_GPR_U32')]
    lines=[]
    for name in ('PS2_EXTRACT_EPI32_0','ADD32','GPR_U32','FPU_ADD_S','FPU_SUB_S','FPU_MUL_S','FPU_SQRT_S',
                 'FPU_MOV_S','FPU_NEG_S','FPU_CVT_S_W','FPU_CVT_W_S','FPU_C_EQ_S'):
        match=re.search(r'^#define '+name+r'\([^\n]+',text,re.M)
        if not match:raise OracleError('Missing pinned macro '+name)
        lines.append(match[0])
    match=re.search(r'#define SET_GPR_U32[^\n]*\\\n.*?while\s*\(0\)',text,re.S)
    if not match:raise OracleError('Missing pinned GPR setter')
    lines.append(match[0])
    switches='\n'.join(f"case {row['word_u32']}u: {{ {row['statement']} }} break;" for row in statements['instructions'])
    return CPP.replace('CONVERT_HEADER',CONVERT.as_posix()).replace('PINNED_HELPERS',helpers).replace('PINNED_MACROS','\n'.join(lines)).replace('REFERENCE_SWITCH',switches)

class FpuWorker:
    def __init__(self,binary):
        self.process=subprocess.Popen([str(binary)],stdin=subprocess.PIPE,stdout=subprocess.PIPE,stderr=subprocess.PIPE,
            text=True,bufsize=1,creationflags=getattr(subprocess,'CREATE_NO_WINDOW',0))
        ready=self.process.stdout.readline().split()
        if len(ready)!=3 or ready[0]!='READY':raise OracleError('Compiled FP worker handshake failed')
        self.environment=dict(host_round=int(ready[1]),mxcsr=int(ready[2]))
        if self.environment['host_round']!=0 or self.environment['mxcsr']&0x8040:raise OracleError('Unqualified host rounding/flush environment')
    def step(self,word,fcr,regs,fpr,memory=0,mode=0,rounding=0):
        self.process.stdin.write(' '.join(map(str,[mode,rounding,word,fcr,memory,*regs,*fpr]))+'\n');self.process.stdin.flush()
        line=self.process.stdout.readline()
        if not line:raise OracleError('Compiled FP step failed: '+self.process.stderr.read())
        values=list(map(int,line.split()))
        if len(values)!=70:raise OracleError('Corrupt compiled FP response')
        return dict(fcr31=values[0],memory_address=values[1],memory_value=values[2],memory_write=bool(values[3]),
            branch=bool(values[4]),likely=bool(values[5]),regs=values[6:38],fpr=values[38:])
    def close(self):
        self.process.stdin.close()
        status=self.process.wait(timeout=10)
        self.process.stdout.close();self.process.stderr.close()
        if status:raise OracleError('FP worker exited unsuccessfully')
    def __enter__(self):return self
    def __exit__(self,kind,value,trace):self.close()

def fpr_seed():return [0x3F000001+n*0x10203 for n in range(32)]

class Machine(header.Machine):
    def __init__(self,inputs,worker):
        super().__init__(inputs);self.worker=worker;self.fpr=inputs.get('fpr_u32',fpr_seed()).copy();self.fcr31=inputs.get('fcr31',0)
        self.fp_steps=0;self.qualified_fp_words=set(fp_words().values())
        for a,(b,digest) in MATH_BODIES.items():
            data=self.elf.read(a,b-a)
            if sha(data)!=digest:raise OracleError('Original math body identity changed')
            self.code.update({a+i:struct.unpack_from('<I',data,i)[0] for i in range(0,len(data),4)})
    def instruction(self,pc,word):
        if not fp_word(word):return super().instruction(pc,word)
        if word not in self.qualified_fp_words:raise OracleError(f'Unqualified FP word{word:#x}')
        op=word>>26;address=0;memory=0
        if op in (0x31,0x39):
            address=((self.regs[(word>>21)&31]&MASK32)+signed(word,16))&MASK32
            if op==0x31:memory=self.mem.load(address,4)
        result=self.worker.step(word,self.fcr31,self.regs,self.fpr,memory)
        self.fp_steps+=1;self.fcr31=result['fcr31'];self.regs=result['regs'];self.fpr=result['fpr'];self.regs[0]=0
        if op in (0x31,0x39) and result['memory_address']!=address:raise OracleError('FP address transport mismatch')
        if result['memory_write']:self.mem.store(address,4,result['memory_value'])
        if op==0x11 and (word>>21)&31==8:
            return result['branch'],(pc+4+signed(word,16)*4)&MASK32,result['likely']
        return None
    def run(self,entry,arguments=(),**options):
        before=dict(fpr_u32=self.fpr.copy(),fcr31=self.fcr31);steps=self.fp_steps
        result=super().run(entry,arguments,**options)
        result['fp_before']=before;result['fp_after']=dict(fpr_u32=self.fpr.copy(),fcr31=self.fcr31)
        result['fp_steps']=self.fp_steps-steps
        return result

def corpus_inputs():
    cases=copy.deepcopy(header.corpus_inputs()['cases'])
    for rate in (24000,48000):
        case=copy.deepcopy(cases[0]);case.update(name=f'outer-mono-{rate}-500',kind='outer',header_hex=bytes(header.header(rate=rate)).hex());cases.append(case)
    loop=header.header(version=4)
    loop[0x20:0x38]=bytes.fromhex('000100010000000000000020000000720000004000000084')
    case=copy.deepcopy(cases[0]);case.update(name='outer-v4-complete-loop-metadata',kind='outer',header_hex=bytes(loop).hex());cases.append(case)
    case=copy.deepcopy(next(row for row in cases if row['name']=='ainf-v4'))
    case.update(name='outer-v4-complete-AINF-metadata',kind='outer');cases.append(case)
    for case in cases:case.update(fpr_u32=fpr_seed(),fcr31=0x100003)
    for rate,filter_value,name in [(24000,500,'math-24000-500'),(44100,500,'math-44100-500'),(48000,500,'math-48000-500'),
                                  (44100,8000,'math-reduction-refuses'),(0,500,'math-zero-rate-refuses')]:
        case=copy.deepcopy(cases[0]);case.update(name=name,kind='math',rate=rate,filter_value=filter_value,header_hex=bytes(header.header()).hex());cases.append(case)
    values=[0,0x80000000,1,0x80000001,0x007FFFFF,0x00800000,0x3F000000,0x3F800000,0xBF800000,
        0x3FC00000,0xBFC00000,0x3FFFFFFF,0x4EFFFFFF,0x4F000000,0xCF000000,0x7F7FFFFF,0xFF7FFFFF,
        0x7F800000,0xFF800000,0x7FC12345,0x7FA12345,0xFFC12345,0x7FFFFFFF,0xFFFFFFFF,0x80000000]
    micros=[]
    for word in sorted(set(fp_words().values())):
        op,rs,ft,fs=word>>26,(word>>21)&31,(word>>16)&31,(word>>11)&31
        for i,value in enumerate(values):
            fpr=[values[(n+i)%len(values)] for n in range(32)];fpr[fs]=value
            if ft!=fs:fpr[ft]=values[(i+7)%len(values)]
            regs=[0]+[(0x1234567800000000+values[(n+i)%len(values)])&((1<<64)-1) for n in range(1,32)]
            if op==0x11 and rs==4 and ft:regs[ft]=value
            rounds=range(4) if op==0x11 and rs==16 and word&63==36 else (0,)
            for rounding in rounds:micros.append(dict(word_u32=word,fcr31=[0,0x800000,0x100000,0x183FFFF,1,2,3][i%7],
                regs=regs,fpr_u32=fpr,memory_u32=value,host_rounding=rounding))
    return dict(schema=1,provenance='Authored raw-bit/runtime compatibility and original-function inputs, frozen before any FP expected replay.',
                cases=cases,micro_cases=micros)

def execute_case(inputs,worker):
    m=Machine(inputs,worker);m.prepare();kind=inputs['kind'];length=inputs['supplied_length']
    if length is None:length=len(bytes.fromhex(inputs['header_hex']))
    if kind=='math':entry,args=0x126510,[inputs['filter_value'],inputs['rate'],header.OUTPUT,header.OUTPUT+2]
    elif kind=='outer':entry,args=0x12D638,[header.OUTER]
    elif kind=='base':
        m.mem.store(header.SP,4,header.OUTPUT+32);m.mem.store(header.SP+8,4,header.OUTPUT+36)
        entry,args=0x126798,[header.DIRECT,length,header.OUTPUT,header.OUTPUT+4,header.OUTPUT+5,header.OUTPUT+6,header.OUTPUT+7,header.OUTPUT+16]
    elif kind in ('version','history'):entry,args=(0x126918 if kind=='version' else 0x126990),[header.DIRECT,length,header.OUTPUT,header.OUTPUT+4]
    elif kind=='filter':entry,args=0x126898,[header.DIRECT,length,header.OUTPUT]
    elif kind=='loop':
        m.mem.store(header.SP,4,header.OUTPUT+32)
        entry,args=0x126AC8,[header.DIRECT,length,header.OUTPUT,header.OUTPUT+4,header.OUTPUT+6,header.OUTPUT+16,header.OUTPUT+20,header.OUTPUT+24]
    elif kind=='ainf':entry,args=0x126D28,[header.DIRECT,length,header.OUTPUT,header.OUTPUT+4,header.OUTPUT+32,header.OUTPUT+36]
    elif kind=='key':
        data=bytes.fromhex(inputs['header_hex']);entry,args=0x1250A0,[header.INNER,data[18],data[19],int.from_bytes(data[12:16],'big'),header.OUTPUT,header.OUTPUT+2,header.OUTPUT+4]
    else:raise OracleError('Unknown authored math/header case')
    initial=m.snapshot();result=m.run(entry,args)
    return dict(name=inputs['name'],kind=kind,setup=m.setup,initial=initial,result=result,
                original_instructions=m.total_steps,visited_pcs=sorted(m.all_visited))

def qualify(worker,inputs):
    rows=[]
    for index,case in enumerate(inputs['micro_cases']):
        args=[case[k] for k in ('word_u32','fcr31','regs','fpr_u32','memory_u32')]
        a=worker.step(*args,mode=0,rounding=case['host_rounding']);b=worker.step(*args,mode=1,rounding=case['host_rounding'])
        if a!=b:raise OracleError(f'Runtime emitter FP raw-bit mismatch micro{index}: {a} !={b}')
        rows.append(dict(index=index,raw_result=a))
    return rows

def math_source_audit(source=SOURCE):
    elf=Elf(ROOT/'game_data/SLUS_207.65');files=[];matched=0;zeros=[]
    for a,(b,_) in MATH_BODIES.items():
        path=next(source.glob(f'sub_{a:08X}_*.cpp'));data=path.read_bytes()
        comments={int(pc,16):int(word,16) for pc,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',data)}
        for pc in range(a,b,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if word!=comments[pc]:raise OracleError('Original math comment mismatch')
                matched+=1
            elif word:raise OracleError(f'Missing nonzero original math comment{pc:#x}')
            else:zeros.append(pc)
        files.append(dict(path=str(path.relative_to(ROOT)),sha256=sha(data)))
    return dict(files=files,matched_comments=matched,omitted_zero_pcs=zeros)

def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--output',type=Path,required=True);parser.add_argument('--compiler',required=True)
    args=parser.parse_args();output=args.output.resolve()
    if output.exists():raise OracleError('Preserve earlier evidence; choose unused directory')
    output.mkdir(parents=True);frozen=output/'inputs.json';frozen.write_bytes(serialized(corpus_inputs()))
    inputs=json.loads(frozen.read_bytes());statements=reference_statements();source=worker_source(statements)
    cpp=output/'fp_worker.cpp';cpp.write_text(source);binary=output/'fp_worker.exe';compiler=shutil.which(args.compiler) or args.compiler
    command=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-msse4.1','-fno-fast-math','-ffp-contract=off','-frounding-math',str(cpp),'-o',str(binary)]
    built=subprocess.run(command,capture_output=True,text=True);(output/'compiler.stdout.txt').write_text(built.stdout);(output/'compiler.stderr.txt').write_text(built.stderr)
    if built.returncode:raise OracleError('Compiled raw-bit worker failed; see retained compiler stderr')
    with FpuWorker(binary) as worker:
        micros=qualify(worker,inputs);(output/'micro-qualification.json').write_bytes(serialized(micros))
        rows=[execute_case(case,worker) for case in inputs['cases']];environment=worker.environment
    value=dict(schema=1,provenance='Original integer/control/math instructions with locally qualified compiled pinned-runtime FP steps; no Python FP math or substituted math calls.',
        elf_sha256=Elf(ROOT/'game_data/SLUS_207.65').sha256,inputs_sha256=sha(frozen.read_bytes()),
        body_sha256={hex(a):digest for a,(_,digest) in {**header.BODIES,**MATH_BODIES}.items()},source_word_audit=header.source_audit(SOURCE),math_source_word_audit=math_source_audit(),
        isa_reference=implementation_identity(),convert_sha256=sha(CONVERT.read_bytes()),fp_emission=statements,
        engine_sha256={name:sha(Path(__file__).with_name(name).read_bytes()) for name in ('sjuni_oracle.py','ee_mac_oracle.py','adx_stereo_oracle.py','sjrb_oracle.py','adx_window_oracle.py','adx_header_oracle.py','adx_header_math_oracle.py')},
        cases=rows,summary=dict(cases=len(rows),returned=sum(r['result']['failure'] is None for r in rows),
            partial=[dict(name=r['name'],**r['result']['failure']) for r in rows if r['result']['failure']],
            original_instructions=sum(r['original_instructions'] for r in rows),fp_steps=sum(r['result']['fp_steps'] for r in rows),
            micro_cases=len(micros),qualified_unique_fp_words=len(statements['instructions'])),
        compatibility=dict(compiler=compiler,compiler_sha256=sha(Path(compiler).read_bytes()),compile_command=command,
            worker_source_sha256=sha(cpp.read_bytes()),worker_binary_sha256=sha(binary.read_bytes()),environment=environment,
            micro_qualification_sha256=sha((output/'micro-qualification.json').read_bytes())),
        limitations=['Scoped current-runtime/emitter binary32 compatibility under recorded compiler/rounding/flush environment, not measured PS2 hardware FPU equivalence.',
            'Only actual126510/1223D0/120F68 math bodies admitted; unexpected range reduction/software fallback remains unowned/refused with partial evidence.',
            'Bounded synthetic prepared records and caller storage; no game, device, actual-header population, scheduling, native migration or performance claim.'])
    fixture=output/'original-fixture.json';fixture.write_bytes(serialized(value));print(json.dumps(dict(**value['summary'],fixture_sha256=sha(fixture.read_bytes()),inputs_sha256=value['inputs_sha256']),indent=2))

if __name__=='__main__':main()
