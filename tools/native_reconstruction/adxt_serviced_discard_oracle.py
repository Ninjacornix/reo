#!/usr/bin/env python3
"""Original discard/rebase through actual complete group envelopes and FP words.

Individual group children have declared literal external queue effects. No
native clock, sample-position return, device progress or CPU result is supplied.
"""
import argparse
import copy
import json
import os
from pathlib import Path
import struct

from adxt_estimated_clock_oracle import oracle as clock
import adxt_transfer_groups_oracle as groups
from sjuni_oracle import OracleError,MASK32

ROOT=groups.ROOT;BASE=ROOT/'build-native-sjuni/adxt-serviced-discard'
FP=ROOT/'build-native-sjuni/adxt-estimated-clock'
sha=groups.sha;encoded=groups.encoded
BODY_CLOCK_MANIFEST_SHA='2f888a4513ad1968512bc032806de3fccdafbb97aff808dd8f03f5777ecd19c0'


def authority():
    identity=json.loads((FP/'frozen-v1/input-manifest.json').read_bytes())
    if sha((FP/'frozen-v1/input-manifest.json').read_bytes())!=BODY_CLOCK_MANIFEST_SHA or identity['authority']!=clock.authority()or identity['emission']!=clock.statements():raise OracleError('Qualified clock/emitter authority drift')
    workers={}
    for name in ('gcc-v1','llvm-v1'):
        receipt=FP/name/'receipt.json';proof=json.loads(receipt.read_bytes());binary=FP/name/'fp_worker.exe'
        if sha(binary.read_bytes())!=proof['worker_binary_sha256']or sha(Path(proof['compiler']).read_bytes())!=proof['compiler_sha256']:raise OracleError('Exact qualified compiler/FP worker drift')
        workers[name]=dict(receipt_sha256=sha(receipt.read_bytes()),worker_sha256=sha(binary.read_bytes()),compiler_sha256=proof['compiler_sha256'])
    return dict(clock_manifest_sha256=BODY_CLOCK_MANIFEST_SHA,clock_authority=identity['authority'],transfer_authority=groups.authority(),workers=workers,
                clock_oracle_sha256=sha(Path(clock.__file__).read_bytes()),transfer_oracle_sha256=sha(Path(groups.__file__).read_bytes()))


def inputs():
    rows=[]
    def add(name,**kw):
        c=dict(name=name,entry=0,state=3,decoded=40017,total=100000,frequency=48000,depth_mode=0,depth_code=0,base=17,offset=3,
               output_present=True,output_bytes=192,rna_free_bytes=16000,mode=1,ratio=6000,counter=17,argument=0,
               rebase_mode=0,service_guard=0,tick=100,tick_base=41,estimate_base=0x12345678,paused=1,play=0,drift_bits=0x12345678,
               fcr31=0x100003,fpr_u32=clock.prior_fp.fpr_seed(),updates=[])
        c.update(kw);rows.append(c);return c
    for paused in (0,1,2,255):
        for busy in (0,1,2,3,0xFFFFFFFF):
            for state in (3,4,5):add(f'paused-{paused}-busy-{busy}-state-{state}',paused=paused,play=int(paused!=1),service_guard=busy,state=state)
    for rate in (24000,44100,48000):
        for ratio in (0,1,6000,10000,0x7FFFFFFF,0x80000000):
            add(f'baseline-{rate}-{ratio}',frequency=rate,ratio=ratio,decoded=rate+1)
    for decoded in (0,1,0x7FFFFFFF,0x80000000,0xFFFFFFFF):add('signed-raw-'+str(decoded),decoded=decoded,frequency=1,base=0,offset=0)
    for value in (0,1,0xFFFFFFFF):add('selector-'+str(value),mode=value,counter=0xFFFFFFFF,tick=0xFFFFFFFE)
    for field,value in [('decoded',42000),('output_bytes',1024),('rna_free_bytes',14000),('state',4)]:
        add('fresh-after-service-'+field,updates=[dict(event='decode'if field=='decoded'else'dtr',field=field,value=value)])
    add('multiple-service-effects',updates=[dict(event='decode',field='decoded',value=42000),dict(event='dtr',field='output_bytes',value=2048),dict(event='dtx',field='rna_free_bytes',value=12000)])
    # Retain literal original zero-denominator execution outside native admission.
    add('zero-frequency-original-only',frequency=0,native_exclusion='zero raw denominator')
    # Historical case name retained. Actual inactive raw query is base/1.
    add('inactive-original-only',state=1)
    return rows


def bind_arrays():
    # Original constructors use these pools. The prepared clock fixture is
    # relocated to slot0, so its group visit and subsequent raw query refer to
    # the same object, not an unrelated synthetic peer.
    for field,table in [('MAIN','stream'),('OUTER','decoder'),('RNA','rna'),('DTR','dtr')]:setattr(clock.integer,field,groups.TABLES[table][0])


class Machine(clock.Machine):
    def __init__(self,case,worker,identity):
        bind_arrays();self.rna_depth=0;self.chunk_depth=0;self.dispatch=[];self.updates=copy.deepcopy(case['updates']);super().__init__(case,worker,identity)
        for a,b in groups.RANGES.items():
            raw=self.elf.read(a,b-a);self.code.update({a+i:struct.unpack_from('<I',raw,i)[0]for i in range(0,len(raw),4)})
        for name,(base,stride)in groups.TABLES.items():
            length=groups.COUNTS[name]*stride;found=False
            for address,data in self.mem.regions:
                if address==base:
                    if len(data)>length:raise OracleError('Prepared table overlaps its next owner')
                    data.extend(bytes(length-len(data)));found=True;break
            if not found:self.mem.map(base,length)
            self.mem.store(base,1,1)
        self.mem.store(clock.integer.OUTER+1,1,2);self.mem.store(clock.integer.RNA+0x24,1,case['play'])

    def queue_effect(self,field,value):
        i=clock.integer
        if field=='decoded':self.mem.store(i.OUTER+0x2C,4,value)
        elif field=='state':self.mem.store(i.MAIN+1,1,value)
        elif field=='output_bytes':
            self.mem.store(i.OUTPUT_RING+12,4,value);self.mem.store(i.OUTPUT_RING+16,4,16384-value)
        elif field=='rna_free_bytes':
            self.mem.store(i.RNA_RING+16,4,value);self.mem.store(i.RNA_RING+12,4,16384-value)
        else:raise OracleError('Unknown authored child effect')

    def observed(self):
        i=clock.integer
        return dict(state=self.mem.load(i.MAIN+1,1),decoded=self.mem.load(i.OUTER+0x2C,4),
                    output_bytes=self.mem.load(i.OUTPUT_RING+12,4),rna_free_bytes=self.mem.load(i.RNA_RING+16,4))

    def hook(self,pc):
        if pc in groups.GUARDS:
            event,change=groups.GUARDS[pc]
            if event.startswith('cri'):self.guard_depth+=change
            elif event.startswith('rna'):self.rna_depth+=change
            else:self.chunk_depth+=change
            if min(self.guard_depth,self.rna_depth,self.chunk_depth)<0:raise OracleError('Guard underflow')
            self.dispatch.append(dict(event=event,slot=-1,busy=self.mem.load(groups.prior.BUSY,4),cri=self.guard_depth,rna=self.rna_depth,chunk=self.chunk_depth))
            self.pc=self.regs[31]&MASK32;return True
        if pc not in groups.CHILDREN:return super().hook(pc)
        table,event=groups.CHILDREN[pc];base,stride=groups.TABLES[table];address=self.regs[4]&MASK32
        if not base<=address<base+groups.COUNTS[table]*stride or(address-base)%stride:raise OracleError('Unexpected original child identity')
        slot=(address-base)//stride
        self.dispatch.append(dict(event=event,slot=slot,busy=self.mem.load(groups.prior.BUSY,4),cri=self.guard_depth,rna=self.rna_depth,chunk=self.chunk_depth))
        for update in self.updates:
            if not update.get('done')and update['event']==event and slot==0:update['done']=True;self.queue_effect(update['field'],update['value'])
        self.pc=self.regs[31]&MASK32;return True


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--freeze',action='store_true');p.add_argument('--frozen',type=Path);p.add_argument('--annotation-correction-of',type=Path);p.add_argument('--worker',choices=['gcc-v1','llvm-v1']);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise OracleError('Fresh scoped output required')
    auth=authority();out.mkdir(parents=True)
    if a.freeze:
        (out/'inputs.json').write_bytes(encoded(dict(cases=inputs())))
        lineage={}
        if a.annotation_correction_of:
            prior=json.loads((a.annotation_correction_of/'manifest.json').read_bytes());old=json.loads((a.annotation_correction_of/'inputs.json').read_bytes())['cases']
            if prior['native_exists']or sha((a.annotation_correction_of/'inputs.json').read_bytes())!=prior['inputs_sha256']:raise OracleError('Unqualified pre-native ancestor')
            for before,after in zip(old,inputs(),strict=True):
                before=copy.deepcopy(before);after=copy.deepcopy(after);before.pop('native_exclusion',None);after.pop('native_exclusion',None)
                if before!=after:raise OracleError('Behavior input changed during annotation correction')
            lineage=dict(prior_freeze=str(a.annotation_correction_of.resolve().relative_to(ROOT)),prior_manifest_sha256=sha((a.annotation_correction_of/'manifest.json').read_bytes()),prior_inputs_sha256=prior['inputs_sha256'],only_admission_annotations_changed=True)
        (out/'manifest.json').write_bytes(encoded(dict(authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),inputs_sha256=sha((out/'inputs.json').read_bytes()),native_exists=(ROOT/'game/native/adxt_serviced_clock/completion.cpp').exists(),**lineage)))
        print('Frozen',len(inputs()),'independent serviced-discard cases');return
    if not a.frozen or not a.worker:raise OracleError('Frozen inputs and exact qualified worker required')
    frozen=json.loads((a.frozen/'manifest.json').read_bytes())
    if frozen['authority']!=auth or frozen['oracle_sha256']!=sha(Path(__file__).read_bytes())or frozen['inputs_sha256']!=sha((a.frozen/'inputs.json').read_bytes()):raise OracleError('Frozen authority/input drift')
    identity=json.loads((FP/'frozen-v1/input-manifest.json').read_bytes());worker=FP/a.worker/'fp_worker.exe';worker_proof=json.loads((FP/a.worker/'receipt.json').read_bytes())
    os.environ['PATH']=str(Path(worker_proof['compiler']).parent)+os.pathsep+os.environ.get('PATH','')
    rows=[];instructions=steps=0
    with clock.prior_fp.FpuWorker(worker)as fp:
        for case in json.loads((a.frozen/'inputs.json').read_bytes())['cases']:
            m=Machine(case,fp,identity);before=m.observed();result=m.operation(dict(op='discard_rebase'))
            if result['result']['failure']or m.rna_depth or m.chunk_depth:raise OracleError(str(result['result']['failure']))
            if case['paused']and not case['service_guard']and not all(u.get('done')for u in m.updates):raise OracleError('Unreached declared child effect')
            path=out/(case['name']+'.json');path.write_bytes(encoded(dict(input=case,original=result,dispatch=m.dispatch,queue_before=before,queue_after=m.observed())))
            n=result['result']['original_instructions'];f=result['result']['fp_steps'];instructions+=n;steps+=f;rows.append(dict(name=case['name'],sha256=sha(path.read_bytes()),instructions=n,fp_steps=f))
    receipt=dict(schema=1,status='passed complete original serviced-discard body and group envelopes',cases=len(rows),original_instructions=instructions,fp_steps=steps,rows=rows,
                 frozen_manifest_sha256=sha((a.frozen/'manifest.json').read_bytes()),authority=auth,worker=a.worker,game_run=False,device_opened=False,
                 limitations=['Group slot children have explicit authored literal queue effects, not executed decoder/device bodies.','Exact emitted-FP worker behavior, not PS2 FPU hardware proof.','Synthetic serialized guard depths do not establish original priority/preemption.','One zero-frequency original case remains outside proposed native numeric admission; inactive raw query is base/1.'])
    (out/'receipt.json').write_bytes(encoded(receipt));print(json.dumps(dict(cases=len(rows),instructions=instructions,fp_steps=steps,receipt_sha256=sha((out/'receipt.json').read_bytes()))))


if __name__=='__main__':main()
