#!/usr/bin/env python3
"""Owned-word ADXT raw clock queries; prepared queue snapshots, no native core.

The estimated FP/tick clock and real concurrent output progress are out of scope.
Inputs are frozen in a separate command before any original execution.
"""
from __future__ import annotations
import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

import adx_window_oracle as window
from sjuni_oracle import Elf, OracleError, MASK32

ROOT = Path(__file__).resolve().parents[2]
BODIES = {
    0x131F28:(0x131F60,'dd36af2ed944e4c1b21faf642d22ca633d0dcb597d9f388cd9852dcdce22c36f'),
    0x131F60:(0x132028,'3858a4042e4b6cbfe545bd5b3a856c756ce0ec212af4ad7161ea4e701ce3298b'),
    0x132028:(0x132148,'db9a36ed4d9e2bcd74ea25c843c812e9763fa43317a75b7d5c98ca8d5df51b60'),
    0x132148:(0x132160,'f2bd59e366d41ac994183e7223a21bf471c623223108134d3c77391ff72798b9'),
    0x124E70:(0x124E78,'6070540d718f3afc53d751b8bcc1cc69d1b465eb874946a7fe6cae78fcce2d7f'),
    0x124E88:(0x124EE8,'f3882863727faa6ff127881173913912011742437336bf37597e9dcaf51af838'),
    0x124EF8:(0x124F48,'f0ed44c02fce441c0b814f548ad11153931965c92dd1808f52a1a4580fd05c1c'),
    0x12C718:(0x12C730,'b359503454104d75aa0aadffb67a41f5466ef815e278a4ccaa3dc1dee2b83a71'),
    0x12C730:(0x12C748,'db706966735f49bce03a69992121730dd2aabc5b930a0747c625dde2f3b581a7'),
    0x12D6E0:(0x12D6E8,'e891996c2125ec623cc7c7061ec66f141fc65f461e04e2e2392d30325f1e6495'),
    0x12D790:(0x12D7A8,'3bde652298c917ebb0f76569a6745c866e9e6ede617c0076f64460683fbf7f05'),
    0x12D7C0:(0x12D7D8,'84001e4d211774f04bfee1dfad40c842e0ee21ecf8ecb5c1005e6e5a9eda3529'),
    0x12D808:(0x12D838,'1fc48e33f324353f5a4f68ae435bf4016e750ccefef51aa6c1d170cba2d9574e'),
    0x132A08:(0x132BC8,'0559871538e5ac8a5faea7dba5c4871084d3ca2a0db193f4fcd1acd535d6eca7'),
    0x13ECA0:(0x13ECB0,'757edd040dfab3630532783a5ed3d3a6d21f84a1bde0405fbf077412fad2a2a4'),
    0x13ECB0:(0x13ECF0,'496feae3197f18280b1677361119cc278b88e57c67d048adcae4b1d0a604bf6f'),
    0x13FA38:(0x13FA88,'77673475e8edd4f371d658a0203a720be24900dc252ee3f5f6a1d2adad745452'),
}
MAIN, OUTER, INNER, RNA, DTR, OUTPUT_RING, RNA_RING = [0x600000+i*0x10000 for i in range(7)]
OUTPUT, GLOBAL, TABLE, SP = 0x680010, 0x21B750, 0x224C28, window.SP
SOURCE = ROOT/'recomp/config/output'
sha = lambda data: hashlib.sha256(data).hexdigest()
serialized = lambda value: (json.dumps(value,sort_keys=True,indent=2)+'\n').encode()


def inputs():
    result=[]
    def add(name, entry, **changes):
        value=dict(name=name,entry=entry,state=3,decoded=40017,total=60001,
            frequency=48000,depth_mode=0,depth_code=0,base=0,offset=0,
            output_present=True,output_bytes=192,rna_free_bytes=16000,
            mode=7,ratio=5994,counter=17,argument=0)
        value.update(changes);result.append(value)
    for entry in (0x131F60,0x132028):
        for state in (0,1,2,3,4,5,6,127,128,255):
            add(f'{entry:x}-state-{state}',entry,state=state,base=123,offset=71)
        for total in (0,1,40017,0x7fffffff,0x80000000,0xffffffff):
            for mode,code in ((0,0),(1,0),(2,2),(2,1),(2,0),(1,2),(-1,-1)):
                add(f'{entry:x}-terminal-{total}-{mode}-{code}',entry,state=5,
                    total=total,depth_mode=mode,depth_code=code,base=0xfffffffe,offset=0x7fffffff)
        for base,offset,decoded in ((0xffffffff,0x80000000,0),(0x7fffffff,1,0x7fffffff),
                                    (0x80000000,0xffffffff,0xffffffff)):
            add(f'{entry:x}-wrapping-{base}',entry,base=base,offset=offset,decoded=decoded)
        for present,count,free in ((False,0,16384),(True,1,16383),(True,191,16191),
                                   (True,16384,0),(True,0,16384)):
            add(f'{entry:x}-queue-{int(present)}-{count}-{free}',entry,
                output_present=present,output_bytes=count,rna_free_bytes=free)
    for mode in (0,1,2,3,0x7fffffff,0x80000000,0xffffffff):
        add(f'select-{mode}',0x131F28,argument=mode)
    for counter in (0,1,0x7fffffff,0xfffffffe,0xffffffff):
        add(f'counter-{counter}',0x132148,counter=counter)
    return dict(schema=1,scope='Raw ADXT ratio queries, selector and resync counter; no estimated FP clock or real DAC timestamp',
        provenance='New authored inputs before replay; prepared original field/ring snapshots, no expected values or native algorithm.',cases=result)


def audit():
    elf=Elf(ROOT/'game_data/SLUS_207.65');files=[];matched=0;zeros=[]
    for start,(end,digest) in BODIES.items():
        data=elf.read(start,end-start)
        if sha(data)!=digest:raise OracleError('Owned clock words changed')
        paths=list(SOURCE.glob(f'sub_{start:08X}_*.cpp'))
        if len(paths)!=1:raise OracleError(f'Unique source companion required for {start:x}')
        raw=paths[0].read_bytes()
        comments={int(a,16):int(b,16) for a,b in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',raw)}
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if comments[pc]!=word:raise OracleError('Source comment word mismatch')
                matched+=1
            elif word:raise OracleError(f'Missing nonzero source comment {pc:x}')
            else:zeros.append(pc)
        files.append(dict(start=start,end=end,body_sha256=digest,path=str(paths[0].relative_to(ROOT)),source_sha256=sha(raw)))
    return dict(files=files,matched_comments=matched,omitted_zero_pcs=zeros)


class Machine(window.Machine):
    def __init__(self, case):
        self.inputs=case;self.elf=Elf(ROOT/'game_data/SLUS_207.65');self.code={}
        for start,(end,digest) in BODIES.items():
            data=self.elf.read(start,end-start)
            if sha(data)!=digest:raise OracleError('Owned clock body mismatch')
            self.code.update({start+i:struct.unpack_from('<I',data,i)[0]for i in range(0,len(data),4)})
        self.mem=window.ObservedMemory()
        for a,n,fill in [(MAIN,0xd0,0),(OUTER,0x9c,0),(INNER,0xe4,0),(RNA,0x20,0),
            (DTR,0x20,0),(OUTPUT_RING,0x40,0),(RNA_RING,0x40,0),(OUTPUT-16,48,0x5a),
            (GLOBAL,0x40,0),(TABLE,48,0),(window.STACK,0x2000,0xcc)]:self.mem.map(a,n,fill)
        self.mem.store(TABLE,48,int.from_bytes(self.elf.read(TABLE,48),'little'))
        self.mem.store(MAIN+1,1,case['state'])
        for off,value in {4:OUTER,12:RNA,24:OUTPUT_RING if case['output_present']else 0,
                          0x88:case['base'],0xa4:case['offset']}.items():self.mem.store(MAIN+off,4,value)
        self.mem.store(OUTER+4,4,INNER);self.mem.store(OUTER+0x2c,4,case['decoded'])
        for off,value in {0x14:case['frequency'],0x18:case['total']}.items():self.mem.store(INNER+off,4,value)
        self.mem.store(INNER+0x98,2,case['depth_mode']);self.mem.store(INNER+0x9a,2,case['depth_code'])
        self.mem.store(RNA+8,4,DTR);self.mem.store(DTR+8,4,RNA_RING)
        for a,data,free in [(OUTPUT_RING,case['output_bytes'],16384-case['output_bytes']),
                            (RNA_RING,16384-case['rna_free_bytes'],case['rna_free_bytes'])]:
            for off,value in {0:TABLE,4:1,12:data,16:free,32:16384}.items():self.mem.store(a+off,4,value)
        for off,value in {0:case['mode'],12:case['counter'],56:case['ratio']}.items():self.mem.store(GLOBAL+off,4,value)
        self.regs=[0]*32;self.guard_depth=0;self.all_visited=set();self.total_steps=0
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)

    def small(self):
        return dict(output_guard_hex=self.raw(OUTPUT-16,48).hex(),main_hex=self.raw(MAIN,0xd0).hex(),
            inner_hex=self.raw(INNER,0xe4).hex(),outer_hex=self.raw(OUTER,0x9c).hex(),
            rings=[self.mem.words(a,16)for a in (OUTPUT_RING,RNA_RING)],globals_hex=self.raw(GLOBAL,0x40).hex())

    def snapshot(self):
        return dict(**self.small(),stack_frame_hex=self.raw(SP-0x400,0x400).hex(),
            lower_stack_guard_hex=self.raw(window.STACK,32).hex(),caller_guard_hex=self.raw(SP,32).hex())

    def hook(self, pc):
        if pc not in (window.ENTER,window.LEAVE):return False
        self.guard_depth+=1 if pc==window.ENTER else -1
        if self.guard_depth<0:raise OracleError('Unbalanced queue guard')
        self.events.append(dict(pc=pc,from_pc=self.from_pc,kind='enter'if pc==window.ENTER else'leave',
            arguments_u64=list(self.regs[4:8]),write_index=len(self.mem.writes)))
        self.pc=self.regs[31]&MASK32;return True


def execute(case):
    m=Machine(case)
    args=[MAIN,OUTPUT,OUTPUT+4] if case['entry']in(0x131f60,0x132028)else[case['argument']]if case['entry']==0x131f28 else[]
    result=m.run(case['entry'],args)
    return dict(name=case['name'],result=result,projection=dict(
        numerator_u32=m.mem.load(OUTPUT,4),denominator_u32=m.mem.load(OUTPUT+4,4),
        mode_u32=m.mem.load(GLOBAL,4),ratio_u32=m.mem.load(GLOBAL+56,4),counter_u32=m.mem.load(GLOBAL+12,4)))


def main():
    parser=argparse.ArgumentParser(description=__doc__)
    parser.add_argument('--output',type=Path,required=True)
    parser.add_argument('--replay',action='store_true')
    args=parser.parse_args();out=args.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni'):raise OracleError('Private artifact directory required')
    if not args.replay:
        if out.exists():raise OracleError('Preserve old evidence; use a fresh directory')
        out.mkdir(parents=True);data=serialized(inputs());(out/'inputs.json').write_bytes(data)
        plan=dict(schema=1,inputs_sha256=sha(data),oracle_sha256=sha(Path(__file__).read_bytes()),source_audit=audit(),
            engines={name:sha(Path(__file__).with_name(name).read_bytes())for name in
                     ('adx_window_oracle.py','sjrb_oracle.py','adx_stereo_oracle.py','ee_mac_oracle.py','sjuni_oracle.py')})
        (out/'input-manifest.json').write_bytes(serialized(plan));print('Inputs frozen; no original execution')
        return
    plan=json.loads((out/'input-manifest.json').read_bytes());data=(out/'inputs.json').read_bytes()
    if sha(data)!=plan['inputs_sha256']or sha(Path(__file__).read_bytes())!=plan['oracle_sha256']or audit()!=plan['source_audit']:
        raise OracleError('Input/oracle/authority drift')
    for name,want in plan['engines'].items():
        if sha(Path(__file__).with_name(name).read_bytes())!=want:raise OracleError('Engine drift')
    if(out/'expected.json').exists():raise OracleError('Preserve earlier expected observations')
    rows=[execute(case)for case in json.loads(data)['cases']]
    expected=serialized(rows);(out/'expected.json').write_bytes(expected)
    summary=dict(cases=len(rows),returned=sum(r['result']['status']=='returned'for r in rows),
        instructions=sum(r['result']['original_instructions']for r in rows),
        unique_pcs=len(set(pc for r in rows for pc in r['result']['visited_pcs'])),
        partials=[dict(name=r['name'],failure=r['result']['failure'])for r in rows if r['result']['failure']])
    (out/'manifest.json').write_bytes(serialized(dict(schema=1,input_manifest_sha256=sha((out/'input-manifest.json').read_bytes()),
        inputs_sha256=sha(data),expected_sha256=sha(expected),summary=summary)))
    print(json.dumps(summary,indent=2))


if __name__=='__main__':main()
