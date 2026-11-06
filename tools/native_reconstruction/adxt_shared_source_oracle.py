#!/usr/bin/env python3
"""New authored Source2 clients, original refill/SJRB/typed-target instruction replay.

Freeze inputs separately before replay. No native core is imported/executed.
Prepared loop fields are explicit client inputs, not header/parser equivalence.
"""
from __future__ import annotations
import argparse,hashlib,importlib.util,json,struct
from pathlib import Path
import adxt_refill_oracle as refill
import adx_shared_window_oracle as shared
from sjuni_oracle import OracleError,MASK32,signed

ROOT=Path(__file__).resolve().parents[2]
HERE=Path(__file__).resolve().parent
OUTER,INNER,MAIN=0x660000,0x670000,0x680000
SLOTS=[refill.SCRATCH+i*16 for i in range(4)]
sha=lambda b:hashlib.sha256(b).hexdigest()
def serialized(value):return (json.dumps(value,sort_keys=True,indent=2)+'\n').encode()
def source(status=0,accept='requested',inline=False):return dict(kind='source',entry=0x130b78,statuses=[status,3],accept=accept,inline_write=inline)
def borrow(two=True,first=0x7fffffff,second=0x7fffffff):return dict(kind='borrow',shape=2 if two else 1,first=first,second=second if two else 0)
def finish(plan,prefix=0):return dict(kind='finish',plan=plan,prefix=prefix)

def corpus_inputs():
    cases=[]
    def add(name,actions,**changes):
        value=dict(name=name,capacity=8192,position=7900,occupied=2048,start_sector=0,byte_length=8192,
            target=-1,threshold=8192,max_request_bytes=8192,max_sectors=4,finite_limit=0xfffff,retry_limit=2,
            initial_progress=1,callback=False,file_action='none',loop_enabled=False,header_geometry=[0,0,0,0],sample_limit=-1,
            file_hex=bytes((i*37+i//2048*19)%256 for i in range(16384)).hex(),seed_pattern='D0+i modulo256',actions=actions)
        value.update(changes);cases.append(value)
    add('single-prefix-zero',[borrow(False),finish('single',0)])
    add('single-prefix-full',[borrow(False),finish('single','all')])
    add('two-positive-reverse',[borrow(),finish('reverse')])
    add('two-positive-first-prefix',[borrow(),finish('first',100)])
    add('two-positive-second-prefix',[borrow(),finish('second',100)])
    add('zero-second',[borrow(),finish('second',0)],position=0)
    add('zero-first',[borrow(first=0),finish('second',0)])
    add('both-zero',[borrow(first=0,second=0),finish('reverse')],occupied=0,initial_progress=0)
    add('pending-two-positive-full',[source(),borrow(),source(2),dict(kind='write_job',id=0),source(1),finish('reverse')],byte_length=16384)
    add('pending-two-positive-partial',[source(accept=1),borrow(),dict(kind='write_job',id=0),source(1),finish('first',100)],byte_length=16384)
    add('pending-two-positive-error',[source(),borrow(),source(3),finish('second',100)],byte_length=16384)
    loop=dict(position=0,byte_length=4096,target=2,callback=True,file_action='file_loop',loop_enabled=True,
              header_geometry=[0,4096,0,32],sample_limit=32)
    actions=[source(accept=1),dict(kind='write_job',id=0),source(1)]
    add('physical-end-enabled',actions,**loop)
    add('physical-end-disabled',actions,**dict(loop,loop_enabled=False))
    add('pending-toggle-off',[source(accept=1),dict(kind='loop_enable',value=0),dict(kind='write_job',id=0),source(1)],**loop)
    add('pending-toggle-on',[source(accept=1),dict(kind='loop_enable',value=1),dict(kind='write_job',id=0),source(1)],**dict(loop,loop_enabled=False))
    add('pending-current-header',[source(accept=1),dict(kind='configure',header_geometry=[2048,4096,32,64],sample_limit=64,target=2,file_action='file_loop'),dict(kind='write_job',id=0),source(1)],**loop)
    add('target-clamps-loop-progress',actions,**dict(loop,header_geometry=[0x7ffff000,0x7fffffff,0,32]))
    add('read-only-target-no-action',actions,**dict(loop,file_action='none'))
    for name,control in [('stop',dict(kind='stop')),('close',dict(kind='close'))]:
        add('pending-'+name,[source(accept=1),borrow(),control,source(2),dict(kind='write_job',id=0),source(1),source(),finish('reverse')],byte_length=16384)
    add('pending-pause',[source(accept=1),dict(kind='pause',value=1),borrow(),dict(kind='write_job',id=0),source(1),finish('reverse'),source(),dict(kind='pause',value=2),source(accept=0)],byte_length=16384)
    add('zero-request-noop',[source(accept=0)],max_request_bytes=0,max_sectors=0)
    add('zero-sector-wrap-grant',[dict(kind='source',entry=0x130b78,statuses=[0,2],accept=0,inline_write=False)],occupied=0,initial_progress=0,position=8190)
    add('declined-error',[source(accept=0)])
    add('retry-terminal',[source(accept=-1),source(accept=-1),source(accept=-1)])
    add('empty-source',[source()],byte_length=0,occupied=0,initial_progress=0,position=0)
    add('wrapped-accepted-prefix',[source(accept=1),dict(kind='write_job',id=0),source(1)],occupied=0,initial_progress=0,position=2060)
    add('wrapped-full-sectors',[source(),dict(kind='write_job',id=0),source(1)],occupied=0,initial_progress=0,position=2060)
    add('repeat-preserves-cumulative',[source(),dict(kind='write_job',id=0),source(1),borrow(),finish('second',0),source(),dict(kind='write_job',id=1),source(1)],
        **dict(loop,occupied=0,initial_progress=0,finite_limit=4))
    # Exact earlier authored8192 case, with no consumer decisions imported from
    # its expected data. Other old geometries remain outside Source2 profile.
    add('prior-large-capacity',[source(inline=True),source(1,inline=True)],occupied=0,initial_progress=0,position=0,callback=True)
    return dict(schema=1,service_entry='130B78 complete lifecycle wrapper reaching130800 refill; raw130800 is a different boundary',
        provenance='NEW independently authored Source2 API clients patterned after historical shared39 families. No expected-derived consumer counts or native algorithm.',
        historical_shared39_sha256='e41b48940b06b95d5b5641160225e10b0902dd5808d9eaf1dca5b1aa0b127972',
        safety_refusals=['invalid prefix/shape/foreign/stale/lost token, ID/domain overflow, non8192 geometry and reset/reuse are separately native safety checks, not original parity'],cases=cases)

class Machine(refill.Machine):
    def __init__(self,inputs,bodies):
        super().__init__(inputs)
        for a,(end,digest)in bodies.items():
            data=self.elf.read(a,end-a)
            if sha(data)!=digest:raise OracleError('Owned body mismatch')
            self.code.update({a+i:struct.unpack_from('<I',data,i)[0]for i in range(0,len(data),4)})
        for a,n in ((OUTER,0x9c),(INNER,0xe4),(MAIN,0xd0)):self.mem.map(a,n,0)
        self.ring_events=[];self.target_events=[];self.target_return=None
    def small(self):
        value=super().small();value.update(sample_limit=signed(self.mem.load(OUTER+0x3c,4),32),loop_enabled=bool(self.mem.load(MAIN+0x6c,1)),
            header_geometry=[signed(self.mem.load(INNER+off,4),32)for off in (0x2c,0x34,0x28,0x30)])
        return value
    def observed(self):
        active=self.mem.active;self.mem.active=False
        try:return self.small()
        finally:self.mem.active=active
    def instruction(self,pc,word):
        if self.target_return==pc:
            self.target_events[-1]['after']=self.observed();self.target_return=None
        if pc==0x133ab8:
            self.target_events.append(dict(before=self.observed()));self.target_return=self.regs[31]&MASK32
        return super().instruction(pc,word)
    def hook(self,pc):
        if pc in (0x13f258,0x13f270):self.ring_events.append(dict(enter=pc==0x13f258,ring=self.observed()['ring_u32']))
        if pc==refill.CALLBACK:
            observed=self.observed();self.target_events.append(dict(before=observed,after=observed))
        return super().hook(pc)
    def configure(self,action,setup=False):
        for off,value in zip((0x2c,0x34,0x28,0x30),action['header_geometry']):self.mem.store(INNER+off,4,value)
        self.mem.store(OUTER+0x3c,4,action['sample_limit'])
        run=self.setup_call if setup else lambda a,b:self.run(a,b,full=False)
        results=[run(0x1307a8,[refill.RECORD,action['target']]),run(0x130798,[refill.RECORD,
            0x133ab8 if action['file_action']=='file_loop'else refill.CALLBACK if self.inputs['callback']else 0,
            MAIN if action['file_action']=='file_loop'else 0x24681357])]
        return results
    def prepare(self):
        super().prepare()
        self.mem.store(MAIN+4,4,OUTER);self.mem.store(MAIN+8,4,refill.RECORD);self.mem.store(OUTER+4,4,INNER)
        self.mem.store(MAIN+0x6c,1,int(self.inputs['loop_enabled']))
        self.setup_call(0x1305c0,[refill.RECORD,self.inputs['initial_progress']])
        self.configure(self.inputs,True)
        self.ring_events=[];self.target_events=[]

def project(state):
    raw=bytes.fromhex(state['record_hex']);q=state['ring_u32'];u=lambda o,n=4:int.from_bytes(raw[o:o+n],'little');i=lambda o,n=4:int.from_bytes(raw[o:o+n],'little',signed=True)
    return dict(ring=[q[k]for k in (8,9,3,4,5,6,10,11,12,13)],source=[i(1,1),i(0x1c),i(0x54),i(0x30),i(3,1),u(0x40,1),u(2,1),u(0x43,1),u(0x44,1),u(0x42,1),
        int(u(8)!=0 and u(0x45,1)==1),u(0x20)-refill.BUFFER if u(0x20)else 0,i(0x24)],
        loop=[state['sample_limit'],i(0x2c),int(state['loop_enabled']),*state['header_geometry']])

def execute(case,bodies,view_module):
    m=Machine(case,bodies);m.prepare();active=None;rows=[];proofs=[];calls=[]
    def call(entry,args):
        value=m.run(entry,args,full=False);calls.append(value)
        if value['failure']:raise OracleError(str(value['failure']))
    def emit(index):
        nonlocal active
        state=m.snapshot()
        if active is not None:
            views=[]
            for slot in SLOTS[:active]:
                pointer,n=m.mem.words(slot,2);views.append(dict(offset=pointer-refill.BUFFER,bytes=n,hex=m.raw(pointer,n).hex()))
        else:views=[view_module.original_view(state,proofs)]
        rows.append(dict(index=index,state=project(state),views=views,
            ring_events=[dict(enter=e['enter'],ring=[e['ring'][k]for k in (8,9,3,4,5,6,10,11,12,13)])for e in m.ring_events],
            targets=[dict(before=project(t['before']),after=project(t['after']))for t in m.target_events]))
        m.ring_events=[];m.target_events=[]
    emit(-1)
    for index,action in enumerate(case['actions']):
        m.action=action;m.status_index=0;kind=action['kind']
        if kind=='source':
            if action['entry']!=0x130b78:raise OracleError('Explicit complete lifecycle entry required')
            call(action['entry'],[refill.RECORD])
        elif kind=='borrow':
            if active is not None:raise OracleError('Authored duplicate borrow')
            active=action['shape']
            for slot,requested in zip(SLOTS[:active],(action['first'],action['second'])):call(0x13fa88,[refill.POOL,1,requested,slot])
        elif kind=='finish':
            if active is None:raise OracleError('Authored missing batch')
            plan=action['plan'];selected=1 if plan=='second'else 0;n=m.mem.load(SLOTS[selected]+4,4)
            prefix=n if action['prefix']=='all'else action['prefix']
            def restore(slot):call(0x13fd58,[refill.POOL,1,slot])
            def consume(slot):call(0x13fbf8,[refill.POOL,0,slot])
            def split(slot):call(0x1407e0,[slot,prefix,SLOTS[2],SLOTS[3]])
            if plan=='reverse':
                for slot in reversed(SLOTS[:active]):restore(slot)
            elif plan=='single':split(SLOTS[0]);consume(SLOTS[2]);restore(SLOTS[3])
            elif plan=='first':restore(SLOTS[1]);split(SLOTS[0]);consume(SLOTS[2]);restore(SLOTS[3])
            elif plan=='second':consume(SLOTS[0]);split(SLOTS[1]);consume(SLOTS[2]);restore(SLOTS[3])
            else:raise OracleError('Unknown plan')
            active=None
        elif kind=='write_job':m.write_job(action['id'])
        elif kind=='loop_enable':m.mem.store(MAIN+0x6c,1,action['value'])
        elif kind=='configure':calls.extend(m.configure(action))
        elif kind=='pause':call(0x130e48,[refill.RECORD,action['value']])
        elif kind in ('stop','close'):call(0x1306e0 if kind=='stop'else 0x130520,[refill.RECORD])
        else:raise OracleError('Unknown action '+kind)
        emit(index)
    return dict(name=case['name'],rows=rows,original_instructions=sum(c['original_instructions']for c in calls),
        original_view_proofs=proofs,setup_original_instructions=sum(c['expected']['original_instructions']for c in m.setup),
        visited_pcs=sorted(m.all_visited),partial=False)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--output',type=Path,required=True);p.add_argument('--replay',action='store_true');a=p.parse_args();out=a.output.resolve()
    if not out.is_relative_to(ROOT/'build-native-sjuni/adxt-shared-source-oracle'):raise OracleError('Fresh private oracle output required')
    manifest_path=out/'input-manifest.json';input_path=out/'inputs.json';core=ROOT/'game/native/adxt_shared_source/frozen_identity.json'
    if not a.replay:
        if out.exists():raise OracleError('Preserve previous evidence')
        out.mkdir(parents=True);inputs=corpus_inputs();input_path.write_bytes(serialized(inputs))
        manifest=dict(schema=1,stage='INPUTS_FROZEN_BEFORE_ORIGINAL_REPLAY',cases=len(inputs['cases']),inputs_sha256=sha(input_path.read_bytes()),
            oracle_source_sha256=sha(Path(__file__).read_bytes()),core_freeze_sha256=sha(core.read_bytes()),new_expected_generated=False)
        manifest_path.write_bytes(serialized(manifest));print(json.dumps(dict(**manifest,input_manifest_sha256=sha(manifest_path.read_bytes()))));return
    if (out/'expected.json').exists():raise OracleError('Never overwrite expected evidence')
    manifest=json.loads(manifest_path.read_bytes())
    if manifest['inputs_sha256']!=sha(input_path.read_bytes())or manifest['oracle_source_sha256']!=sha(Path(__file__).read_bytes())or manifest['core_freeze_sha256']!=sha(core.read_bytes()):raise OracleError('Frozen input/source drift')
    for n,d in json.loads(core.read_bytes())['files'].items():
        if sha((ROOT/n).read_bytes())!=d:raise OracleError('Frozen source dependency changed')
    spec=importlib.util.spec_from_file_location('prior_refill_projection',ROOT/'game/native/adxt_refill/compare_original.py');module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
    bodies=shared.owned_bodies();inputs=json.loads(input_path.read_bytes());rows=[]
    for case in inputs['cases']:
        result=execute(case,bodies,module);rows.append(result);print(case['name'],len(result['rows']),result['original_instructions'],flush=True)
    expected=dict(schema=1,input_manifest_sha256=sha(manifest_path.read_bytes()),inputs_sha256=manifest['inputs_sha256'],cases=rows,
        body_sha256={hex(a):dict(end=end,sha256=d)for a,(end,d)in bodies.items()},
        engine_sha256={name:sha((HERE/name).read_bytes())for name in shared.ENGINE_NAMES},oracle_sha256=sha(Path(__file__).read_bytes()),
        original_view_helper_sha256=sha((ROOT/'game/native/adxt_refill/compare_original.py').read_bytes()),
        limitations=['New authored Source-only client transactions, not full shared39 Window2 parity.','Prepared loop typedfields are input; no header/math/codec outcome is supplied or claimed.','Private-result staging excludes original unpublished free backing writes. Actual ring callbacks/state/published views and target-before/after remain compared.'])
    (out/'expected.json').write_bytes(serialized(expected));print(json.dumps(dict(cases=len(rows),expected_sha256=sha((out/'expected.json').read_bytes()))))
if __name__=='__main__':main()
