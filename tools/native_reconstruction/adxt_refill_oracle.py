#!/usr/bin/env python3
"""Original ADXF refill words and real SJRB; explicitly scripted external I/O."""
from __future__ import annotations

import argparse
import hashlib
import json
from pathlib import Path
import re
import struct

from adx_window_oracle import Machine as BoundedRunner, WindowInstructions, ObservedMemory
from sjrb_oracle import BODIES as RING_BODIES
from sjuni_oracle import Elf, OracleError, MASK32, sext32
from ee_mac_oracle import implementation_identity

ROOT = Path(__file__).resolve().parents[2]
BODIES = {
    **RING_BODIES,
    0x130108: (0x130218, 'd52e6d240130169793eed4a19d74b5139e40c41d6b7de13b02d6cc2a1afe2ff2'),
    0x130420: (0x130D44, 'b2639127d95411cd463eb4772bcd408a232ce0a98089c9d5c5330152700b45fd'),
    0x130E18: (0x130E58, '58939e6073707bc7291ee907cb04786eed6d9f895580e5c44d501f0161c018ce'),
}
GLOBAL, POOL, BUFFER, SCRATCH = 0x224C20, 0x224C60, 0x400010, 0x630004
RECORD, STACK, SP, RETURN = 0x600000, 0x700000, 0x701000, 0xFFFFF0
FILE, CALLBACK, ERROR = 0xFFFF80, 0xFFFF10, 0xFFFF00
ENTER = (0x13F258, 0x1416D0, 0x1264E0)
LEAVE = (0x13F270, 0x1416E8, 0x1264F8)
STATUS, SEEK, REQUEST, CLOSE = 0x135F50, 0x135D60, 0x135DC8, 0x135C80
MEMSET, MEMCPY, REPORT = 0x107C68, 0x107AB0, 0x13F288
TRACE = {0x130800:'refill', 0x130B78:'lifecycle', 0x130620:'reset', 0x1306E0:'stop',
         0x13FA88:'ring_get', 0x13FBF8:'ring_put', 0x13FD58:'ring_unget', 0x1407E0:'split'}


def sha(data): return hashlib.sha256(data).hexdigest()
def serialized(value): return (json.dumps(value, sort_keys=True, indent=2)+'\n').encode()


class Machine(BoundedRunner):
    """Reuse only the frozen bounded runner/ISA, not its window setup/codec."""
    def __init__(self, inputs):
        self.inputs = inputs
        self.capacity = inputs['capacity']; self.extension = 36
        if self.capacity not in (2048, 4096, 8192): raise OracleError('Finite sector-aligned capacity required')
        if not 0 <= inputs['position'] < self.capacity: raise OracleError('Position outside ring')
        if not 0 <= inputs['occupied'] <= self.capacity: raise OracleError('Invalid initial occupancy')
        self.file_bytes = bytes.fromhex(inputs['file_hex'])
        if len(self.file_bytes) > 16384: raise OracleError('Bounded synthetic file exceeded')
        self.elf = Elf(ROOT/'game_data/SLUS_207.65'); self.code = {}
        for start,(end,expected) in BODIES.items():
            data = self.elf.read(start,end-start)
            if data is None or sha(data) != expected: raise OracleError('Owned function identity mismatch')
            self.code.update({start+i:struct.unpack_from('<I',data,i)[0] for i in range(0,len(data),4)})
        self.mem = ObservedMemory()
        for address,size,fill in [(GLOBAL,0x4040,0),(BUFFER-16,self.capacity+68,0xA5),
                (RECORD,0x5C,0),(SCRATCH-4,0x100,0x5A),(STACK,0x2000,0xCC),(0x21A8B4,12,0)]:
            self.mem.map(address,size,fill)
        self.mem.store(GLOBAL+8,48,int.from_bytes(self.elf.read(GLOBAL+8,48),'little'))
        self.mem.store(0x21A8B4,4,inputs['retry_limit'])
        self.initialize_mac(hi=0x11111111,lo=0x22222222,hi1=0x33333333,lo1=0x44444444)
        self.regs=[0]*32; self.guard_depth=0; self.all_visited=set(); self.total_steps=0
        self.rings=[POOL]; self.buffers=[(BUFFER,self.capacity+self.extension)]; self.setup=[]
        self.jobs=[]; self.action={}; self.status_index=0; self.position=0; self.file_closed=False

    def small(self):
        return dict(record_hex=self.raw(RECORD,0x5C).hex(), ring_u32=self.mem.words(POOL,16),
                    diagnostic_u32=self.mem.load(0x21A8B8,4), jobs=[dict(j) for j in self.jobs],
                    file_position_sectors=self.position,file_closed=self.file_closed)

    def snapshot(self):
        value=self.small()
        value.update(backing_guard_hex=self.raw(BUFFER-16,self.capacity+68).hex(),
                     stack_frame_hex=self.raw(SP-0x200,0x200).hex(),
                     lower_stack_guard_hex=self.raw(STACK,32).hex(),caller_guard_hex=self.raw(SP,32).hex())
        return value

    def instruction(self,pc,word):
        if pc in TRACE:
            self.events.append(dict(kind='original_entry',name=TRACE[pc],pc=pc,from_pc=self.from_pc,
                                    arguments_u64=list(self.regs[4:9]),write_index=len(self.mem.writes)))
        return WindowInstructions.instruction(self,pc,word)

    def run(self,entry,arguments=(),**options):
        result=super().run(entry,arguments,**options)
        # Most service/control entries are void; a residual v0 is evidence only.
        result['return_is_defined']=entry in (0x13F8A8,0x1305C0,0x130608,0x130658,0x130698,
                                             0x130E18,0x130E28,0x130E38,0x130E40,0x130E50)
        return result

    def write_job(self,index):
        if not 0 <= index < len(self.jobs): raise OracleError('Unknown scripted I/O observation ID')
        job=self.jobs[index]
        if job['written']: raise OracleError('Script attempted duplicate physical job write')
        offset=job['sector']*2048; size=job['accepted_sectors']*2048
        if offset < 0 or offset+size > len(self.file_bytes): raise OracleError('Scripted read outside file')
        if not BUFFER <= job['destination'] <= job['destination']+size <= BUFFER+self.capacity+self.extension:
            raise OracleError('Scripted provider destination exceeds retained synthetic backing')
        for i,value in enumerate(self.file_bytes[offset:offset+size]): self.mem.store(job['destination']+i,1,value)
        job['written']=True

    def hook(self,pc):
        if pc not in (*ENTER,*LEAVE,MEMSET,MEMCPY,REPORT,ERROR,CALLBACK,STATUS,SEEK,REQUEST,CLOSE,0x128128): return False
        event=dict(pc=pc,from_pc=self.from_pc,arguments_u64=list(self.regs[4:9]),
                   depth_before=self.guard_depth,write_index_before=len(self.mem.writes))
        if pc in ENTER: event['kind']='external_guard_enter'; self.guard_depth+=1
        elif pc in LEAVE:
            event['kind']='external_guard_leave'; self.guard_depth-=1
            if self.guard_depth<0: raise OracleError('Unbalanced external guard')
        elif pc==MEMSET:
            dest,value,size=(v & MASK32 for v in self.regs[4:7])
            if not POOL<=dest<=dest+size<=POOL+0x4000: raise OracleError('Unadmitted pool memset')
            event['kind']='bounded_memset'; self.mem.fill(dest,size,value); self.regs[2]=self.regs[4]
        elif pc==MEMCPY:
            dest,source,size=(v & MASK32 for v in self.regs[4:7])
            if size>self.capacity or not (BUFFER<=dest<=dest+size<=BUFFER+self.capacity+self.extension and
                    BUFFER<=source<=source+size<=BUFFER+self.capacity+self.extension): raise OracleError('Unadmitted ring copy')
            if size and dest<source+size and source<dest+size: raise OracleError('Overlapping memcpy excluded')
            event['kind']='bounded_memcpy'; event['source_hex']=self.raw(source,size).hex()
            data=self.raw(source,size)
            for i,value in enumerate(data): self.mem.store(dest+i,1,value)
            self.regs[2]=sext32(dest)
        elif pc==STATUS:
            states=self.action.get('statuses',[0])
            if self.status_index>=len(states): raise OracleError('Unspecified external status poll')
            value=states[self.status_index]; self.status_index+=1
            event.update(kind='scripted_cvfs_status',return_i32=value); self.regs[2]=sext32(value)
        elif pc==SEEK:
            if self.regs[6] & MASK32: raise OracleError('Only prepared absolute-sector source supported')
            self.position=self.regs[5] & MASK32
            event.update(kind='scripted_cvfs_seek',return_i32=self.position); self.regs[2]=sext32(self.position)
        elif pc==REQUEST:
            requested=self.regs[5] & MASK32; destination=self.regs[6] & MASK32
            accepted=self.action.get('accept','unspecified')
            if accepted=='requested': accepted=requested
            if not isinstance(accepted,int) or not -3<=accepted<=requested<=8:
                raise OracleError('Unspecified or unbounded scripted request result')
            active=self.mem.active; self.mem.active=False; observed=self.small(); self.mem.active=active
            event.update(kind='scripted_cvfs_request',requested_sectors=requested,accepted_sectors=accepted,
                         observed_during_request=observed)
            if accepted>0:
                index=len(self.jobs)
                self.jobs.append(dict(observation_id=index,destination=destination,sector=self.position,
                                      accepted_sectors=accepted,written=False))
                event['observation_id']=index
                if self.action.get('inline_write',False): self.write_job(index)
            self.regs[2]=sext32(accepted)
        elif pc==CLOSE:
            event.update(kind='scripted_cvfs_close',record_file_u32=self.mem.load(RECORD+8,4))
            self.file_closed=True; self.regs[2]=0
        else:
            event['kind']='target_callback' if pc==CALLBACK else 'error_callback' if pc==ERROR else 'diagnostic'
            active=self.mem.active; self.mem.active=False; event['observed_before']=self.small(); self.mem.active=active
        event.update(depth_after=self.guard_depth,write_index_after=len(self.mem.writes)); self.events.append(event)
        self.pc=self.regs[31] & MASK32
        return True

    def prepare(self):
        self.setup_call(0x13F7F8,[])
        result=self.setup_call(0x13F8A8,[BUFFER,self.capacity,self.extension])
        if result['raw_v0_lower64_observation_only'] & MASK32 != POOL: raise OracleError('Original ring identity differed')
        self.setup_call(0x13F9E0,[POOL,ERROR,0x13572468])
        self.advance_empty(POOL,self.inputs['position'])
        self.produce(POOL,data=bytes((0xD0+i)%256 for i in range(self.inputs['occupied'])))
        self.setup_call(0x130108,[RECORD,FILE,self.inputs['start_sector'],self.inputs['byte_length'],POOL])
        # Explicit prepared already-open owner input, not simulated constructor/open success.
        self.mem.store(RECORD+0x45,1,1)
        self.setup_call(0x130E18,[RECORD,self.inputs['threshold'],self.inputs['max_request_bytes']])
        self.setup_call(0x130E28,[RECORD,self.inputs['max_sectors']])
        self.setup_call(0x1307A8,[RECORD,self.inputs['target']])
        self.setup_call(0x130798,[RECORD,CALLBACK if self.inputs['callback'] else 0,0x24681357])
        self.setup_call(0x130698,[RECORD,self.inputs['finite_limit']])


def service(status=0,accept='requested',inline=True,entry='lifecycle'):
    return dict(kind=entry,statuses=[status,3],accept=accept,inline_write=inline)


def corpus_inputs():
    cases=[]
    def add(name,actions,**changes):
        row=dict(name=name,capacity=4096,position=0,occupied=0,start_sector=0,byte_length=8192,
            target=-1,threshold=4096,max_request_bytes=4096,max_sectors=2,finite_limit=0xFFFFF,
            callback=True,retry_limit=2,file_hex=bytes((i*37+i//2048*19)%256 for i in range(16384)).hex(),actions=actions)
        row.update(changes); cases.append(row)
    add('synchronous-write-later-publication',[service(),service(1)],byte_length=4096)
    add('partial-accepted-prefix-return-suffix',[service(accept=1),service(1)])
    add('pending-keeps-whole-free-grant',[service(inline=False),service(2),dict(kind='write_job',id=0),service(1)])
    add('consumer-during-pending',[service(inline=False),dict(kind='consume',bytes=1024),dict(kind='write_job',id=0),service(1)],occupied=2048)
    add('wrapped-prefix-mirror-copy',[service(accept=1),service(1)],position=2060)
    add('split-next-sector-after-consume',[service(accept=1),service(1),dict(kind='consume',bytes=2048),service(accept=1),service(1)],position=2048)
    add('backpressure-no-request',[service()],occupied=4096)
    add('threshold-equality-no-request',[service()],occupied=2048,threshold=2048)
    add('zero-sector-physical-grant',[service(accept=0)],position=4090)
    add('zero-max-sector-request',[service(accept=0)],max_sectors=0)
    add('partial-sector-file-length',[service(),service(1),service(accept=0)],byte_length=2049)
    add('empty-source-terminal',[service()],byte_length=0)
    add('zero-acceptance-returns-free',[service(accept=0)])
    add('negative-acceptance-returns-free',[service(accept=-1)])
    add('zero-acceptance-nonerror-status',[dict(kind='lifecycle',statuses=[0,2],accept=0,inline_write=False)])
    add('retry-limit-terminal',[service(accept=-1),service(accept=-1),service(accept=-1)])
    add('negative-retry-limit-no-increment',[service(accept=-1)],retry_limit=-1)
    add('pending-error-returns-free',[service(),service(3)])
    add('pause-blocks-new-only',[dict(kind='pause',value=1),service(),dict(kind='pause',value=0),service(),dict(kind='pause',value=1),service(1)])
    add('stop-pending-late-completion',[service(inline=False),dict(kind='stop'),service(2),dict(kind='write_job',id=0),service(1),service()])
    add('close-deferred-until-completion',[service(inline=False),dict(kind='close'),service(2),dict(kind='write_job',id=0),service(1),service()])
    add('target-callback-exact',[service(accept=1),service(1)],target=1)
    add('finite-limit-terminal',[service(accept=1),service(1)],finite_limit=1)
    add('start-offset',[service(),service(1)],start_sector=2)
    add('small-capacity',[service(),service(1)],capacity=2048,threshold=2048,max_request_bytes=2048)
    add('large-capacity',[service(),service(1)],capacity=8192,threshold=8192,max_request_bytes=8192,max_sectors=4)
    add('reset-loses-outstanding-reservation',[service(inline=False),dict(kind='reset'),dict(kind='write_job',id=0),service(accept=0)])
    add('ring-reset-reuse-late-external-write',[service(inline=False),dict(kind='reset'),dict(kind='ring_reset'),dict(kind='produce',bytes=2048),dict(kind='write_job',id=0)])
    add('reset-close-late-external-write',[service(inline=False),dict(kind='reset'),dict(kind='close'),service(),dict(kind='write_job',id=0)])
    return dict(schema=1,provenance='Bounded synthetic original-file-refill inputs, frozen before replay; external I/O script is an input, not provider proof.',cases=cases)


def execute_case(inputs):
    machine=Machine(inputs); machine.prepare(); initial=machine.snapshot(); operations=[]
    for action in inputs['actions']:
        machine.action=action; machine.status_index=0; kind=action['kind']
        entries={'lifecycle':0x130B78,'refill':0x130800,'stop':0x1306E0,'close':0x130520,'reset':0x130620,
                 'ring_reset':0x13F9F0,'pause':0x130E48}
        if kind in entries:
            args=[POOL if kind=='ring_reset' else RECORD]
            if kind=='pause': args.append(action['value'])
            result=machine.run(entries[kind],args)
            operations.append(dict(input=action,expected=result))
            if result['failure']: break
        elif kind=='consume':
            results=[machine.run(0x13FA88,[POOL,1,action['bytes'],SCRATCH]),machine.run(0x13FBF8,[POOL,0,SCRATCH])]
            operations.append(dict(input=action,expected=results))
            if any(result['failure'] for result in results): break
        elif kind=='produce':
            begin=len(machine.setup); machine.produce(POOL,data=bytes([0xEE])*action['bytes'])
            operations.append(dict(input=action,expected=machine.setup[begin:])); del machine.setup[begin:]
        elif kind=='write_job':
            before=machine.snapshot(); machine.write_job(action['id'])
            operations.append(dict(input=action,external_effect=dict(before=before,after=machine.snapshot())))
        else: raise OracleError('Unknown frozen action')
    return dict(name=inputs['name'],setup=machine.setup,initial=initial,operations=operations,final=machine.snapshot(),
                original_instructions=machine.total_steps,visited_pcs=sorted(machine.all_visited))


def source_audit(source):
    elf=Elf(ROOT/'game_data/SLUS_207.65'); comments={}; files=[]
    for path in sorted(source.glob('*.cpp')):
        match=re.match(r'sub_([0-9A-Fa-f]+)_',path.name)
        if not match or not any(start<=int(match[1],16)<end for start,(end,_) in BODIES.items()): continue
        data=path.read_bytes(); files.append(dict(path=str(path.relative_to(ROOT)),sha256=sha(data)))
        for pc,word in re.findall(rb'//\s*0x([0-9a-fA-F]+):\s*0x([0-9a-fA-F]+)',data):
            pc,word=int(pc,16),int(word,16)
            if any(start<=pc<end for start,(end,_) in BODIES.items()):
                if pc in comments and comments[pc]!=word: raise OracleError('Conflicting original comments')
                comments[pc]=word
    omitted=[]
    for start,(end,_) in BODIES.items():
        for pc in range(start,end,4):
            word=int.from_bytes(elf.read(pc,4),'little')
            if pc in comments:
                if word!=comments[pc]: raise OracleError(f'Original comment mismatch {pc:#x}')
            elif word: raise OracleError(f'Omitted nonzero word {pc:#x}')
            else: omitted.append(pc)
    return dict(files=files,matched_comments=len(comments),omitted_zero_pcs=omitted)


def main():
    parser=argparse.ArgumentParser(description=__doc__); parser.add_argument('--output',required=True,type=Path)
    parser.add_argument('--reference-source',type=Path,default=ROOT/'build-native-sjuni/candidate-work-v6/project/recomp/config/output')
    args=parser.parse_args(); output=args.output.resolve(); frozen=output.with_name(output.stem+'-inputs.json')
    if output.exists() or frozen.exists(): raise OracleError('Never overwrite evidence; choose a new output')
    output.parent.mkdir(parents=True,exist_ok=True); frozen.write_bytes(serialized(corpus_inputs()))
    inputs=json.loads(frozen.read_bytes()); audit=source_audit(args.reference_source.resolve())
    rows=[execute_case(row) for row in inputs['cases']]
    def failures(row):
        return [v for op in row['operations'] for v in ([op['expected']] if isinstance(op.get('expected'),dict) else op.get('expected',[]))
                if v.get('failure')]
    result=dict(schema=1,provenance='Complete original130800/SJRB instruction execution on frozen synthetic source state; no device/game/full player.',
        elf_sha256=Elf(ROOT/'game_data/SLUS_207.65').sha256,inputs_file=str(frozen.relative_to(ROOT)),inputs_sha256=sha(frozen.read_bytes()),
        body_sha256={hex(a):h for a,(_,h) in BODIES.items()},source_word_audit=audit,isa_reference=implementation_identity(),
        engine_sha256={name:sha(Path(__file__).with_name(name).read_bytes()) for name in
            ('sjuni_oracle.py','ee_mac_oracle.py','adx_stereo_oracle.py','sjrb_oracle.py','adx_window_oracle.py','adxt_refill_oracle.py')},
        cases=rows,summary=dict(cases=len(rows),original_instructions=sum(r['original_instructions'] for r in rows),
            unique_visited_words=len({pc for r in rows for pc in r['visited_pcs']}),failed_cases=[r['name'] for r in rows if failures(r)]),
        limitations=['Status/seek/read acceptance, physical external write time and close are scripted inputs, not executed cvFs/OS providers.',
            'Already-open owner flag is explicit prepared input; source initializer/start/control/lifecycle and all ring operations execute original words.',
            'Observation IDs identify harness I/O writes only, never an invented original generation/cancellation protocol.',
            'Reset/reuse/late-write cases expose permissive original ordering, not safe native admission or a proven external writer fence.',
            'No header, codec, loop, playback clock, RNA credits, scheduler timing or complete ADXT player claim.'])
    output.write_bytes(serialized(result)); print(json.dumps(dict(**result['summary'],bytes=output.stat().st_size,sha256=sha(output.read_bytes()),inputs_sha256=result['inputs_sha256']),indent=2))


if __name__=='__main__': main()
