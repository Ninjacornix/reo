#!/usr/bin/env python3
"""Owned ADXT estimated-clock words plus separately qualified emitter FP steps.

Freeze inputs before replay. No game/native clock core, sample-position result
hook, scheduling, audio provider, or original hardware is used.
"""
from __future__ import annotations
import argparse
import copy
import hashlib
import json
import os
from pathlib import Path
import re
import shutil
import struct
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
sys.path.insert(0,str(HERE.parent))
import adxt_integer_clock_oracle as integer
import adx_header_math_oracle as prior_fp
from sjuni_oracle import Elf,OracleError,MASK32,signed

SDK=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4'
SDK_PROOF=ROOT/'build-native-sjuni/dependency-gs-sound-profile-reapply-v4-receipt.json'
SDK_PROOF_SHA='909917fc2f766c8a43a10abbc0b94189fa24254ecfaa7f710e4eb24dc941b58a'
MACROS=SDK/'ps2xRuntime/include/ps2_runtime_macros.h'
CONVERT=MACROS.with_name('ps2_fpu_convert.h')
NEW_INTERVALS={0x132160:0x132458,0x132458:0x1324A8,0x132E50:0x132F80,
               0x133058:0x133140,0x12C700:0x12C718,0x13EC50:0x13EC58,
               0x12C8B0:0x12C8D8,0x13F158:0x13F180,0x132C08:0x132CD8}
ENGINES=('adxt_integer_clock_oracle.py','adx_header_math_oracle.py','adx_window_oracle.py',
         'adx_header_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','sjuni_oracle.py')
TICK=0x20F3C4;ENTER,LEAVE=0x1264E0,0x1264F8
sha=lambda data:hashlib.sha256(data).hexdigest()
serialized=lambda value:(json.dumps(value,sort_keys=True,indent=2)+'\n').encode()


def fp_word(word):return word>>26 in (0x11,0x31,0x39)


def authority():
    if sha(SDK_PROOF.read_bytes())!=SDK_PROOF_SHA:raise OracleError('Final127 proof drift')
    proof=json.loads(SDK_PROOF.read_bytes())
    for path in (MACROS,CONVERT):
        if sha(path.read_bytes())!=proof['source_sha256'][path.relative_to(SDK).as_posix()]:raise OracleError('Pinned runtime FP authority drift')
    elf=Elf(ROOT/'game_data/SLUS_207.65');rows=[]
    for start,end in NEW_INTERVALS.items():
        path=ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp'
        data=path.read_bytes();comments={int(a,16):int(b,16)for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',data)}
        matched=0;zero=[]
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc]!=word:raise OracleError('Owned comment disagreement '+hex(pc))
                matched+=1
            elif word:raise OracleError('Missing nonzero original word '+hex(pc))
            else:zero.append(pc)
        rows.append(dict(start=start,end=end,body_sha256=sha(elf.read(start,end-start)),
                         source=path.relative_to(ROOT).as_posix(),source_sha256=sha(data),matched_words=matched,omitted_zero_pcs=zero))
    return dict(elf_sha256=elf.sha256,integer_authority=integer.audit(),new_ranges=rows,
                sdk_proof_sha256=SDK_PROOF_SHA,macro_sha256=sha(MACROS.read_bytes()),convert_sha256=sha(CONVERT.read_bytes()))


def balanced(text,start):
    depth=0
    for at in range(start,len(text)):
        if text[at]=='{':depth+=1
        elif text[at]=='}':
            depth-=1
            if not depth:return text[start:at+1]
    raise OracleError('Unbalanced emitted statement')


def statements():
    elf=Elf(ROOT/'game_data/SLUS_207.65');result={}
    for start,end in NEW_INTERVALS.items():
        text=(ROOT/f'recomp/config/output/sub_{start:08X}_0x{start:x}.cpp').read_text()
        matches=list(re.finditer(r'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)[^\n]*\n',text))
        for index,match in enumerate(matches):
            pc,word=int(match[1],16),int(match[2],16)
            if not start<=pc<end or not fp_word(word):continue
            if int.from_bytes(elf.read(pc,4),'little')!=word:raise OracleError('FP emitter word disagreement')
            block=text[match.end():matches[index+1].start()if index+1<len(matches)else len(text)]
            if word>>26==0x11 and (word>>21)&31==8:
                branch=re.search(r'const bool branch_taken_0x[0-9a-f]+\s*=\s*([^;]+);',block)
                if not branch:raise OracleError('Missing emitted FP branch')
                statement='branch=bool('+branch[1]+');likely='+str(bool((word>>16)&2)).lower()+';'
            elif re.search(r'if \(ctx->f\[',block):
                division=re.search(r'if \(ctx->f\[.*?else\s+ctx->f\[.*?;',block,re.S)
                if not division:raise OracleError('Missing complete emitted DIV statement')
                statement=division[0]
            elif '{'in block and 'ctx->f['in block:
                statement=balanced(block,block.index('{'))
            else:
                assignment=re.search(r'ctx->(?:f\[\d+\]|fcr31)\s*=.*?;',block,re.S)
                if not assignment:raise OracleError('Unrecognized emitted FP statement '+hex(pc))
                statement=assignment[0]
            if word in result and result[word]['statement']!=statement:raise OracleError('Inconsistent repeated FP opcode')
            result[word]=dict(pc=pc,word_u32=word,statement=statement)
    return list(result.values())


def worker_source(emission,convert_path):
    text=MACROS.read_text();helpers=text[text.index('static inline int32_t Ps2ExtractEpi32'):text.index('static inline int64_t Ps2ExtractEpi64')]
    helpers+=text[text.index('static inline void Ps2SetGprLow64'):text.index('#define SET_GPR_U32')]
    names=('PS2_EXTRACT_EPI32_0','ADD32','GPR_U32','FPU_ADD_S','FPU_SUB_S','FPU_MUL_S','FPU_SQRT_S',
           'FPU_MOV_S','FPU_NEG_S','FPU_CVT_S_W','FPU_CVT_W_S','FPU_C_EQ_S','FPU_C_OLT_S','FPU_C_OLE_S')
    macros=[]
    for name in names:
        match=re.search(r'^#define '+name+r'\([^\n]+',text,re.M)
        if not match:raise OracleError('Missing actual macro '+name)
        macros.append(match[0])
    setter=re.search(r'#define SET_GPR_U32[^\n]*\\\n.*?while\s*\(0\)',text,re.S)
    if not setter:raise OracleError('Missing actual GPR setter')
    macros.append(setter[0])
    source=prior_fp.CPP
    old='if(rs==8 && (ft==1 || ft==3)) { branch=bool(ctx->fcr31&0x800000);likely=bool(ft&2);return; }'
    new='if(rs==8 && ft<=3) { branch=bool(ctx->fcr31&0x800000)==bool(ft&1);likely=bool(ft&2);return; }'
    if source.count(old)!=1:raise OracleError('Pinned worker branch adaptation drift')
    source=source.replace(old,new)
    anchor='case 50:ctx->fcr31='
    at=source.index(anchor)
    source=source[:at]+'''case 52:ctx->fcr31=FPU_C_OLT_S(ctx->f[fs],ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;
 case 54:ctx->fcr31=FPU_C_OLE_S(ctx->f[fs],ctx->f[ft])?(ctx->fcr31|0x800000):(ctx->fcr31&~0x800000);break;
 '''+source[at:]
    switches='\n'.join(f"case {row['word_u32']}u: {{ {row['statement']} }} break;"for row in emission)
    return source.replace('CONVERT_HEADER',convert_path.as_posix()).replace('PINNED_HELPERS',helpers).replace('PINNED_MACROS','\n'.join(macros)).replace('REFERENCE_SWITCH',switches)


def inputs(emission):
    cases=[]
    def add(name,operations=None,**changes):
        value=dict(name=name,state=3,decoded=48000,total=100000,frequency=48000,
                   depth_mode=0,depth_code=0,base=17,offset=3,output_present=False,
                   output_bytes=0,rna_free_bytes=16384,mode=1,ratio=6000,counter=17,argument=0,
                   rebase_mode=0,service_guard=1,tick=100,tick_base=100,estimate_base=6000,
                   paused=0,drift_bits=0x12345678,fcr31=0x100003,fpr_u32=prior_fp.fpr_seed(),
                   operations=operations or [dict(op='estimate')])
        value.update(changes);cases.append(value)
    for mode in (0,1,2,0xffffffff):
        for state in (0,2,3,4,5,6,128,255):add(f'mode-{mode}-state-{state}',mode=mode,state=state)
    for sign in (-1,1):
        for delta in (59,60,61):
            for rebase in (0,1):
                add(f'drift-nominal-{sign*delta}-rebase-{rebase}',frequency=1000,decoded=1000,
                    ratio=1000,estimate_base=1000-sign*delta,rebase_mode=rebase,base=0,offset=0)
    for mode in (0,1,2):
        add(f'counter-wrap-mode-{mode}',frequency=1000,decoded=1000,ratio=1000,
            estimate_base=1,rebase_mode=mode,counter=0xffffffff,base=0,offset=0)
    for tick,origin,base in [(0,0xffffffff,5),(0xffffffff,0xfffffffe,0xffffffff),(0x80000000,0,0x7fffffff)]:
        add(f'tick-wrap-{tick}-{origin}',tick=tick,tick_base=origin,estimate_base=base)
    for paused in (0,1,2,255):add(f'paused-get-{paused}',paused=paused)
    sequence=[dict(op='pause',value=1),dict(op='estimate',tick=123),dict(op='pause',value=1),
              dict(op='pause',value=0,tick=150),dict(op='estimate',tick=151),dict(op='centiseconds')]
    add('pause-resume-tick-sequence',operations=sequence)
    for state in (0,2,3,4,5,255):
        for value in (0,1,2,255):add(f'pause-state-{state}-value-{value}',operations=[dict(op='pause',value=value)],state=state)
    for samples in (0,1,0x3fffffff,0x7fffffff,0x80000000,0xffffffff):
        for ratio in (1,8,0x7fffffff,0x80000000):
            add(f'high-pause-{samples}-{ratio}',operations=[dict(op='pause',value=1)],decoded=samples,
                frequency=1,ratio=ratio,base=0,offset=0)
    for total in (0,1,0x7fffffff,0x80000000,0xffffffff):
        for mode,code in ((0,0),(2,2),(2,1),(2,0)):
            add(f'terminal-{total}-{mode}-{code}',state=5,total=total,depth_mode=mode,depth_code=code,
                base=0xfffffffe,estimate_base=0xffffffff)
    for paused in (0,1,2):
        add(f'discard-busy-guard-{paused}',operations=[dict(op='discard_rebase')],paused=paused)
    add('discard-unowned-service',operations=[dict(op='discard_rebase')],paused=1,service_guard=0)
    for frequency,ratio in ((0,6000),(48000,0),(0,0)):
        add(f'zero-denominators-{frequency}-{ratio}',frequency=frequency,ratio=ratio)
    add('centiseconds-high',operations=[dict(op='centiseconds')],decoded=0x7fffffff,frequency=1,mode=0,base=0,offset=0)
    values=[0,0x80000000,1,0x80000001,0x007fffff,0x00800000,0x3f000000,0x3f800000,
            0xbf800000,0x42700000,0x42700001,0x426fffff,0xc2700000,0xc2700001,
            0x4effffff,0x4f000000,0xcf000000,0x7f7fffff,0xff7fffff,0x7f800000,
            0xff800000,0x7fc12345,0x7fa12345,0xffffffff]
    micros=[]
    for word in sorted({row['word_u32']for row in emission}):
        op,rs,ft,fs=word>>26,(word>>21)&31,(word>>16)&31,(word>>11)&31
        for i,value in enumerate(values):
            fpr=[values[(n+i)%len(values)]for n in range(32)];fpr[fs]=value
            if ft!=fs:fpr[ft]=values[(i+7)%len(values)]
            regs=[0]+[(0x1234567800000000+values[(n+i)%len(values)])&((1<<64)-1)for n in range(1,32)]
            if op==0x11 and rs==4 and ft:regs[ft]=value
            for rounding in range(4)if op==0x11 and rs==16 and word&63==36 else (0,):
                micros.append(dict(word_u32=word,fcr31=[0,0x800000,0x100000,0x183ffff][i%4],
                                   regs=regs,fpr_u32=fpr,memory_u32=value,host_rounding=rounding))
    return dict(schema=1,provenance='Authored inputs/micro bit patterns frozen before expected execution; no native clock results.',cases=cases,micro_cases=micros)


class Machine(integer.Machine):
    def __init__(self,case,worker,identity):
        super().__init__(case);self.worker=worker;self.fpr=case['fpr_u32'].copy();self.fcr31=case['fcr31'];self.fp_steps=0
        self.fp_words={row['word_u32']for row in identity['emission']}
        for row in identity['authority']['new_ranges']:
            start,end=row['start'],row['end'];data=self.elf.read(start,end-start)
            if sha(data)!=row['body_sha256']:raise OracleError('Original estimate body drift')
            self.code.update({start+i:struct.unpack_from('<I',data,i)[0]for i in range(0,len(data),4)})
        self.mem.map(TICK,4);self.mem.store(TICK,4,case['tick'])
        for base,data in self.mem.regions:
            if base==integer.RNA:data.extend(bytes(0x20))
        for off,value,size in [(0x72,case['paused'],1),(0x9c,case['estimate_base'],4),(0xa0,case['tick_base'],4)]:self.mem.store(integer.MAIN+off,size,value)
        for off,value in [(4,case['service_guard']),(16,case['rebase_mode']),(60,case['drift_bits'])]:self.mem.store(integer.GLOBAL+off,4,value)

    def small(self):
        value=super().small()
        value.update(rna_hex=self.raw(integer.RNA,0x40).hex(),tick_u32=self.mem.load(TICK,4))
        return value

    def hook(self,pc):
        if pc in (ENTER,LEAVE):
            self.guard_depth+=1 if pc==ENTER else -1
            if self.guard_depth<0:raise OracleError('External critical guard underflow')
            self.events.append(dict(kind='external_critical_enter'if pc==ENTER else'external_critical_leave',
                                    pc=pc,from_pc=self.from_pc,arguments_u64=list(self.regs[4:8]),write_index=len(self.mem.writes)))
            self.pc=self.regs[31]&MASK32;return True
        if pc==0x116848:
            self.events.append(dict(kind='external_diagnostic',pc=pc,from_pc=self.from_pc,arguments_u64=list(self.regs[4:8]),write_index=len(self.mem.writes)))
            self.pc=self.regs[31]&MASK32;return True
        return super().hook(pc)

    def instruction(self,pc,word):
        if not fp_word(word):return super().instruction(pc,word)
        if word not in self.fp_words:raise OracleError('Unqualified FP opcode '+hex(word))
        op=word>>26;address=memory=0
        if op in (0x31,0x39):
            address=((self.regs[(word>>21)&31]&MASK32)+signed(word,16))&MASK32
            if op==0x31:memory=self.mem.load(address,4)
        value=self.worker.step(word,self.fcr31,self.regs,self.fpr,memory)
        self.fp_steps+=1;self.fcr31=value['fcr31'];self.regs=value['regs'];self.fpr=value['fpr'];self.regs[0]=0
        if op in (0x31,0x39)and value['memory_address']!=address:raise OracleError('FP memory transport mismatch')
        if value['memory_write']:self.mem.store(address,4,value['memory_value'])
        if op==0x11 and (word>>21)&31==8:return value['branch'],(pc+4+signed(word,16)*4)&MASK32,value['likely']
        return None

    def operation(self,operation):
        if 'tick'in operation:self.mem.store(TICK,4,operation['tick'])
        kind=operation['op'];args=[integer.MAIN,integer.OUTPUT,integer.OUTPUT+4]
        if kind=='estimate':entry=0x132160
        elif kind=='centiseconds':entry,args=0x132458,[integer.MAIN]
        elif kind=='pause':entry,args=0x132E50,[integer.MAIN,operation['value']]
        elif kind=='discard_rebase':entry,args=0x133058,[integer.MAIN]
        else:raise OracleError('Unknown authored operation')
        before=dict(fpr_u32=self.fpr.copy(),fcr31=self.fcr31);steps=self.fp_steps
        result=self.run(entry,args,limit=50000)
        result.update(fp_before=before,fp_after=dict(fpr_u32=self.fpr.copy(),fcr31=self.fcr31),fp_steps=self.fp_steps-steps)
        return dict(op=kind,result=result,projection=dict(output_u32=self.mem.load(integer.OUTPUT,4),denominator_u32=self.mem.load(integer.OUTPUT+4,4),
            estimate_base_u32=self.mem.load(integer.MAIN+0x9c,4),tick_base_u32=self.mem.load(integer.MAIN+0xa0,4),
            paused_byte=self.mem.load(integer.MAIN+0x72,1),rna_play_byte=self.mem.load(integer.RNA+0x24,1),
            mode_u32=self.mem.load(integer.GLOBAL,4),counter_u32=self.mem.load(integer.GLOBAL+12,4),
            drift_bits_u32=self.mem.load(integer.GLOBAL+60,4)))


def replay_case(case,worker,identity):
    machine=Machine(case,worker,identity);operations=[]
    for operation in case['operations']:
        row=machine.operation(operation);operations.append(row)
        if row['result']['failure']:break
    return dict(name=case['name'],operations=operations)


def freeze(out):
    if out.exists():raise OracleError('Preserve earlier evidence; use a fresh frozen directory')
    checked=authority();emission=statements();data=serialized(inputs(emission))
    out.mkdir(parents=True);(out/'inputs.json').write_bytes(data)
    identity=dict(schema=1,authority=checked,emission=emission,inputs_sha256=sha(data),oracle_sha256=sha(Path(__file__).read_bytes()),
                  engines={name:sha((HERE.parent/name).read_bytes())for name in ENGINES})
    (out/'input-manifest.json').write_bytes(serialized(identity))
    print(json.dumps(dict(status='inputs_frozen_no_execution',cases=len(json.loads(data)['cases']),micro_cases=len(json.loads(data)['micro_cases']),inputs_sha256=sha(data))))


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);p.add_argument('--freeze',action='store_true')
    p.add_argument('--frozen',type=Path);p.add_argument('--compiler');args=p.parse_args();out=args.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni/adxt-estimated-clock'):raise OracleError('Private scoped output required')
    if args.freeze:return freeze(out)
    if not args.frozen or not args.compiler or out.exists():raise OracleError('Frozen inputs, exact compiler and fresh output required')
    frozen=args.frozen.resolve();identity=json.loads((frozen/'input-manifest.json').read_bytes());data=(frozen/'inputs.json').read_bytes()
    if sha(data)!=identity['inputs_sha256']or sha(Path(__file__).read_bytes())!=identity['oracle_sha256']or authority()!=identity['authority']or statements()!=identity['emission']:raise OracleError('Frozen oracle/input/authority drift')
    for name,d in identity['engines'].items():
        if sha((HERE.parent/name).read_bytes())!=d:raise OracleError('Imported engine drift')
    compiler=shutil.which(args.compiler)
    if not compiler:raise OracleError('Actual installed compiler required')
    out.mkdir(parents=True);authority_dir=out/'authority';authority_dir.mkdir();convert=authority_dir/CONVERT.name;convert.write_bytes(CONVERT.read_bytes())
    cpp=out/'fp_worker.cpp';cpp.write_text(worker_source(identity['emission'],convert),encoding='utf-8',newline='\n');binary=out/'fp_worker.exe'
    command=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-msse4.1','-fno-fast-math','-ffp-contract=off','-frounding-math','-Wl,--no-insert-timestamp',str(cpp),'-o',str(binary)]
    os.environ['PATH']=str(Path(compiler).parent)+os.pathsep+os.environ.get('PATH','')
    compiled=subprocess.run(command,capture_output=True,text=True,timeout=90)
    (out/'compiler.stdout.txt').write_text(compiled.stdout);(out/'compiler.stderr.txt').write_text(compiled.stderr)
    if compiled.returncode:raise OracleError('FP worker compilation failed; retained diagnostics')
    corpus=json.loads(data);micros=[]
    with prior_fp.FpuWorker(binary)as worker:
        for index,case in enumerate(corpus['micro_cases']):
            values=[case[k]for k in ('word_u32','fcr31','regs','fpr_u32','memory_u32')]
            generic=worker.step(*values,mode=0,rounding=case['host_rounding']);reference=worker.step(*values,mode=1,rounding=case['host_rounding'])
            if generic!=reference:raise OracleError('Independent FP step/emitter mismatch '+str(index))
            micros.append(dict(index=index,literal_result=generic))
        rows=[replay_case(case,worker,identity)for case in corpus['cases']];environment=worker.environment
    (out/'micro-qualification.json').write_bytes(serialized(micros));(out/'expected.json').write_bytes(serialized(rows))
    all_operations=[operation for row in rows for operation in row['operations']]
    summary=dict(cases=len(rows),operations=len(all_operations),returned=sum(x['result']['status']=='returned'for x in all_operations),
                 partials=[dict(name=row['name'],op=op['op'],failure=op['result']['failure'])for row in rows for op in row['operations']if op['result']['failure']],
                 original_instructions=sum(x['result']['original_instructions']for x in all_operations),fp_steps=sum(x['result']['fp_steps']for x in all_operations),
                 micro_cases=len(micros),qualified_fp_words=len(identity['emission']))
    receipt=dict(schema=1,status='completed_literal_observations',summary=summary,frozen_manifest_sha256=sha((frozen/'input-manifest.json').read_bytes()),inputs_sha256=sha(data),
                 compiler=compiler,compiler_sha256=sha(Path(compiler).read_bytes()),compile_command=command,environment=environment,
                 worker_cpp_sha256=sha(cpp.read_bytes()),worker_binary_sha256=sha(binary.read_bytes()),
                 outputs={n:sha((out/n).read_bytes())for n in ['micro-qualification.json','expected.json']},
                 source_postcheck=[]if authority()==identity['authority']else['authority_changed'],
                 limitations=['Current emitted runtime FP behavior under exact compiler/host environment, not PS2 hardware FPU proof',
                              'Actual raw integer queries/ring words; no supplied sample-position return',
                              'External critical sections/diagnostic are observation hooks; no concurrency or scheduler proof',
                              '133058 service-busy path is actual early-return coverage; busy0 stops at first unowned worker',
                              'Partial evidence labels harness boundaries, not original admission refusals'],game_run=False,device_opened=False)
    (out/'receipt.json').write_bytes(serialized(receipt));print(json.dumps(summary,indent=2))


if __name__=='__main__':main()
