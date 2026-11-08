#!/usr/bin/env python3
"""Execute owned LSC allocation/construction/destruction instructions.

Stream counts, critical sections, diagnostics, memset and lower stop are
explicit ports. No game, decoder, worker, runtime authority or device is run.
"""
import argparse
import hashlib
import json
from pathlib import Path
import struct

import adxt_service_group_oracle as audit
import sjrb_oracle as ring
from sjuni_oracle import MASK32, OracleError, sext32

ROOT = Path(__file__).resolve().parents[2]
POOL, STRIDE, COUNT = 0x21e110, 0x238, 16
INPUT, VTABLE, COUNT_PORT, FILE = 0x630000, 0x631000, 0x6f0000, 0x620000
RANGES = {0x13CB50:0x13CBB0, 0x13CBB0:0x13CCB8, 0x13CCB8:0x13CD08,
          0x13CD08:0x13CD10, 0x13CED0:0x13CF10, 0x13CF78:0x13D000}
ENTRIES = {'lsc_allocate':(0x13CB50,True), 'lsc_construct':(0x13CBB0,True),
           'lsc_destroy':(0x13CCB8,False), 'lsc_attach':(0x13CD08,False)}


def encoded(value):
    return (json.dumps(value, indent=2, sort_keys=True) + '\n').encode()


def sha(data):
    return hashlib.sha256(data).hexdigest()


def authority():
    previous = audit.RANGES
    audit.RANGES = RANGES
    try:
        return audit.authority()
    finally:
        audit.RANGES = previous


def inputs():
    rows = []
    for free in range(16):
        rows.append(dict(name='first-free-' + str(free), free=[free], counts=[4096,4096], operations=['construct','attach','destroy','construct']))
    rows += [dict(name='full',free=[],counts=[4096,4096],operations=['construct']),
             dict(name='null-input',free=[0],counts=[4096,4096],null_input=True,operations=['construct']),
             dict(name='multiple-free',free=[3,7,15],counts=[4096,4096],operations=['allocate','construct','construct']),
             dict(name='null-destroy',free=[0],counts=[4096,4096],null_destroy=True,operations=['destroy']),
             dict(name='poisoned-free-storage',free=[0],free_fill=0xa5,counts=[4096,4096],operations=['construct','destroy'])]
    for count in ([0,0],[8192,0],[1,2],[0x7fffffff,1],[0x10000000,0],[0xffffffff,0xffffffff]):
        rows.append(dict(name='counts-' + '-'.join(map(str,count)),free=[0],counts=count,operations=['construct']))
    for phase in (0,1,2,3,255):
        for transfer in (0,1,2):
            rows.append(dict(name=f'destroy-{phase}-{transfer}',free=[],counts=[4096,4096],phase=phase,transfer=transfer,operations=['destroy']))
    return rows


class Machine(ring.Machine):
    def __init__(self, case):
        super().__init__()
        self.case, self.critical = case, []
        self.object = POOL + min(case.get('free') or [0]) * STRIDE
        for start,end in RANGES.items():
            raw = self.elf.read(start,end-start)
            self.code.update({start+i:struct.unpack_from('<I',raw,i)[0] for i in range(0,len(raw),4)})
        self.mem.map(POOL-16,STRIDE*COUNT+32,0xa5)
        for slot in range(COUNT):
            address=POOL+slot*STRIDE
            if slot in case['free']:self.mem.fill(address,STRIDE,case.get('free_fill',0))
            self.mem.store(address,1,0 if slot in case['free'] else 1)
        self.mem.map(INPUT,16);self.mem.store(INPUT,4,VTABLE)
        self.mem.map(VTABLE,0x28);self.mem.store(VTABLE+0x24,4,COUNT_PORT)
        if 'phase' in case:
            self.mem.store(self.object+1,1,case['phase'])
            self.mem.store(self.object+2,1,case['transfer'])
            self.mem.store(self.object+0x28,4,FILE)

    def state(self):
        raw=self.bytes(POOL-16,STRIDE*COUNT+32)
        return dict(pool_sha256=sha(raw),guards=[raw[:16].hex(),raw[-16:].hex()],
                    active=[self.mem.load(POOL+i*STRIDE,1) for i in range(COUNT)],
                    focused_object=self.object,focused_hex=self.bytes(self.object,STRIDE).hex(),
                    critical_depth=len(self.critical))

    def hook(self, pc):
        args=[self.regs[4+i]&MASK32 for i in range(3)]
        if pc==0x13D498:
            self.critical.append(args[0]);self.mem.store(args[0],4,0x13572468)
            self.events.append(dict(event='critical_enter',context=args[0]))
        elif pc==0x13D4B8:
            if not self.critical or self.critical.pop()!=args[0] or self.mem.load(args[0],4)!=0x13572468:
                raise OracleError('Unbalanced original critical token')
            self.events.append(dict(event='critical_leave',context=args[0]))
        elif pc==COUNT_PORT:
            if args[0]!=INPUT or args[1] not in (0,1):raise OracleError('Unadmitted stream count query')
            value=self.case['counts'][args[1]];self.regs[2]=sext32(value)
            self.events.append(dict(event='input_count',list=args[1],value=value))
        elif pc==0x13D4F8:
            self.events.append(dict(event='diagnostic',format=args[0]))
        elif pc==0x107C68:
            if args[0]!=self.object or args[1]!=0 or args[2]!=STRIDE:raise OracleError('Unadmitted original memset')
            self.mem.fill(args[0],args[2],args[1]);self.regs[2]=sext32(args[0])
            self.events.append(dict(event='zero_child',bytes=args[2]))
        elif pc==0x130748:
            if args[0]!=FILE:raise OracleError('Foreign lower stop')
            self.events.append(dict(event='lower_stop_async'))
        else:
            return False
        self.pc=self.regs[31]&MASK32
        return True

    def operation(self, name):
        args={'allocate':[], 'construct':[0 if self.case.get('null_input') else INPUT],
              'attach':[self.object,FILE], 'destroy':[0 if self.case.get('null_destroy') else self.object]}[name]
        result=self.run('lsc_'+name,args,step_cap=5000)
        if result['failure']:raise OracleError(str(result['failure']))
        return result


def generate(output):
    output=output.resolve()
    if output.exists() or not output.is_relative_to(ROOT/'build-native-sjuni/lsc-lifecycle'):
        raise ValueError('Fresh owned evidence directory required')
    auth=authority();ring.ENTRIES.update(ENTRIES)
    output.mkdir(parents=True);rows=[];instructions=0;operations=0
    for case in inputs():
        machine=Machine(case);observations=[]
        for name in case['operations']:
            result=machine.operation(name);observations.append(dict(operation=name,original=result))
            instructions+=result['original_instructions'];operations+=1
        path=output/(case['name']+'.json');path.write_bytes(encoded(dict(input=case,observations=observations)))
        rows.append(dict(name=case['name'],sha256=sha(path.read_bytes())))
    receipt=dict(schema=1,status='owned LSC lifecycle instructions observed',cases=len(rows),operations=operations,
                 original_instructions=instructions,authority=auth,oracle_sha256=sha(Path(__file__).read_bytes()),
                 rows=rows,game_run=False,device_opened=False,native_comparison=False,
                 ports=['stream count','critical section','diagnostic','memset','lower stop'])
    (output/'receipt.json').write_bytes(encoded(receipt));return receipt


if __name__=='__main__':
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',required=True,type=Path)
    a=p.parse_args();r=generate(a.output);print(json.dumps({k:r[k] for k in ['status','cases','operations','original_instructions']}))
