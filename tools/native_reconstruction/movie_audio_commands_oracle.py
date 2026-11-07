#!/usr/bin/env python3
"""Original movie audio dispatch/control joined to the movie timing context.

SDK pause/discard/frequency are declared ports. Their existing independent SDK
qualifications are not replaced by this movie policy/ordering comparison.
"""
import argparse
import copy
import hashlib
import json
from pathlib import Path
import struct
import movie_buffering_oracle as buffering

j=buffering.joined;ROOT=j.ROOT;BASE=ROOT/'build-native-sjuni/movie-audio-commands'
INTERVALS={0x177BE0:0x177C30,0x166630:0x166688,0x165E00:0x165EF0,
           0x165EF0:0x165F40,0x165F40:0x165F88,0x165F88:0x165FC8,
           0x165FC8:0x166018,0x1656E8:0x165710}
PORTS={0x132E50:'device_pause',0x133058:'device_discard',0x1324F8:'device_frequency'}
ENTRIES={'audio_requested':0x165EF0,'audio_temporary':0x165F40,'audio_command':0x177BE0}
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


class Machine(buffering.Machine):
    def __init__(self,case,worker,qualified):
        self.device_pause=0;super().__init__(case,worker,qualified)
        for start,end in INTERVALS.items():
            raw=self.elf.read(start,end-start);self.body_ids[hex(start)+':'+hex(end)]=hashlib.sha256(raw).hexdigest()
            for n in range(0,len(raw),4):self.code[start+n]=struct.unpack_from('<I',raw,n)[0]
        for table in [0x240600,0x2405A8]:
            self.mem.span('interface_'+hex(table),table,56,False,0);self.mem.store(table,56,int.from_bytes(self.elf.read(table,56),'little'))
        self.mem.store(j.MAIN+0x1C88,4,0x240600 if case['channel'] else 0)
        self.mem.store(j.MAIN+0x1B78,4,0x2405A8 if case['decoder'] else 0)
        self.mem.store(j.CHILD+0x2C,4,case['requested_pause']);self.mem.store(j.CHILD+0x30,4,case['residual'])
        self.mem.store(j.FILTER+12,4,case['filter_mode']);self.initial=self.capture()

    def capture(self):
        value=super().capture();value['audio_control']=[self.mem.load(j.CHILD+0x2C,4),self.mem.load(j.CHILD+0x30,4),self.device_pause]
        return value

    def port(self,pc):
        if pc not in PORTS:return super().port(pc)
        kind=PORTS[pc];args=[v&0xFFFFFFFF for v in self.regs[4:7]]
        if args[0]!=j.ADXT:raise j.OracleError('Control device identity')
        self.events.append(dict(kind=kind,value=args[1] if kind in ['device_pause','device_discard'] else 0,before=self.capture()))
        returned=0
        if kind=='device_pause':self.device_pause=args[1]&255;returned=0xA1234567
        elif kind=='device_frequency':returned=self.operation['sample_frequency']
        # Original File #1 discard returns zero; the supplied quantity is not
        # a seek request. Complete SDK service/rebase was qualified separately.
        for register in [1,*range(2,16),24,25]:self.regs[register]=0xCDCD000000000000+register
        self.regs[2]=j.sext32(returned);return self.regs[31]&0xFFFFFFFF

    def execute(self,op):
        self.operation=op
        if op['kind'] not in ENTRIES:
            row=super().execute(op)
        else:
            for name,value in op['facts'].items():self.mem.store(j.MAIN+j.FACTS[name],4,value)
            self.mem.store(j.ADXT+1,1,op['adxt_status']);self.mem.store(j.HELPER_FREQUENCY,8,op['helper_frequency'])
            before=self.capture();start=self.steps;events=len(self.events)
            args=[j.MAIN,7,8,op['value'],0] if op['kind']=='audio_command' else [j.MAIN,op['value']]
            returned=self.run_body(ENTRIES[op['kind']],args);after=self.capture()
            if before['main_guard_sha256']!=after['main_guard_sha256']:raise j.OracleError('Control escaped declared main state')
            row=dict(operation=op,before=before,after=after,instructions=self.steps-start,return_defined=True,returned=returned&0xFFFFFFFF,events=self.events[events:])
        # SDK Pause and the original filter setter are void. Preserve observed
        # register evidence, but do not claim it as a native control return ABI.
        row['return_defined']=row['return_defined'] and not any(e['kind']=='device_pause' for e in row['events'])
        return row


def operation(kind,value=0,**kw):
    op=j.operation(kind,value);op['sample_frequency']=48000;op.update(kw);return op


def corpus():
    template=buffering.corpus()[0];cases=[]
    def add(name,ops,**kw):
        case=copy.deepcopy(template);case.update(name=name,operations=ops,channel=True,decoder=True,requested_pause=0,residual=0,filter_mode=1)
        case['facts']['selector']=2;case['buffer_state'].update(eligible=2,audio=1);case.update(kw);cases.append(case);return case
    for requested in [0,1,2,0xFFFFFFFF]:
        for user in [0,1,2,0xFFFFFFFF]:
            for kind in ['audio_requested','audio_temporary','audio_command']:
                case=add(f'{kind}-requested{requested}-user{user}',[operation(kind,v) for v in [1,1,0,0,2,0,0xFFFFFFFF]],requested_pause=requested,residual=123)
                case['facts']['pause']=user
    for rate in range(9):
        for frequency in [0,24000,44100,48000,0xFFFFFFFF]:
            for residual in [0,0x7FFFFFFF,0xFFFFFFFF]:
                case=add(f'frame-{rate}-{frequency}-{residual}',[operation('audio_command',2,sample_frequency=frequency),operation('audio_command',2,sample_frequency=frequency),operation('audio_command',0)],residual=residual)
                case['facts']['rate']=rate
    for state in [0,1,2,3,4,5,255]:add('readiness-'+str(state),[operation('audio_command',2,adxt_status=state)])
    for prop in [0,1,2,0xFFFFFFFF]:
        for channel,decoder in [(False,True),(True,False),(True,True)]:
            case=add(f'route-{prop}-{channel}-{decoder}',[operation('audio_command',v) for v in [0,1,2]],channel=channel,decoder=decoder,residual=19);case['buffer_state']['audio']=prop
    for mode in [0,1,2]:add('filter-baseline-'+str(mode),[operation('selected',1),operation('audio_command',2),operation('selected',2),operation('audio_requested',1),operation('selected',3)],filter_mode=mode)
    add('joined-user-buffer-frame',[operation('refresh',1),operation('buffer'),operation('pause',1),operation('pause',2),operation('buffer'),operation('pause',0),operation('audio_requested',1),operation('audio_command',0),operation('audio_requested',0),operation('tick',2),operation('selected',3)])
    return cases


def main():
    parser=argparse.ArgumentParser(description=__doc__);parser.add_argument('--worker-cohort',choices=['gcc','llvm'],required=True);parser.add_argument('--output',type=Path,required=True);args=parser.parse_args()
    out=args.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    frozen=ROOT/'build-native-sjuni/movie-timing-context'/('original-'+args.worker_cohort+'-v3');authority=json.loads((frozen/'input-manifest.json').read_bytes());worker=frozen/'fp_worker.exe'
    if sha(worker)!=authority['fp_worker_sha256'] or sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Worker/ELF drift')
    j.os.environ['PATH']=str(Path(authority['compiler']).parent)+j.os.pathsep+j.os.environ.get('PATH','')
    j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    for pc in [0x172CF8,0x172E78,0x177BE0]:j.PORTS.pop(pc)
    j.PORTS.update(buffering.QPORTS);j.PORTS.update(PORTS)
    out.mkdir(parents=True);cases=corpus();sources={str(p.relative_to(ROOT)):sha(p) for p in [Path(__file__),Path(buffering.__file__),Path(j.__file__)]}
    manifest=dict(elf_sha256=authority['elf_sha256'],sources=sources,worker_receipt_sha256=sha(frozen/'receipt.json'),worker_sha256=sha(worker),native_commands_exist=(ROOT/'game/native/movie_timing_context/audio_commands.cpp').exists(),sdk_ports='Pause/discard/frequency; discard zero result supported by original 133058/12C8B0/13F158 and prior SDK qualification.',game_run=False,device_opened=False)
    for name,value in [('inputs.json',cases),('input-manifest.json',manifest)]: (out/name).write_text(json.dumps(value,indent=2)+'\n',encoding='utf-8')
    results=[];receipt={'status':'failed'}
    try:
        with j.fp.FpuWorker(worker) as fpu:
            for case in cases:
                machine=Machine(case,fpu,set(j.fp.fp_words().values()));rows=[machine.execute(op) for op in case['operations']]
                results.append(dict(name=case['name'],initial=machine.initial,operations=rows,instructions=machine.steps,body_identities=machine.body_ids))
        (out/'original.json').write_text(json.dumps(results,indent=2)+'\n',encoding='utf-8')
        receipt=dict(status='original joined movie audio commands returned',cases=len(cases),operations=sum(len(c['operations']) for c in cases),instructions=sum(r['instructions'] for r in results),outputs_sha256={name:sha(out/name) for name in ['inputs.json','input-manifest.json','original.json']},game_run=False,device_opened=False)
    except Exception as error:receipt.update(failure=str(error),completed_cases=len(results));raise
    finally:(out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8')
    print(json.dumps({k:receipt[k] for k in ['status','cases','operations','instructions']}|{'receipt_sha256':sha(out/'receipt.json')}))


if __name__=='__main__':main()
