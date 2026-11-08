#!/usr/bin/env python3
"""Compare measured game ring sizes against owned instructions and native Ring.

Only harness storage bounds/addresses expand. Original words, native core and
the previously qualified comparator remain unchanged. No game or device runs.
"""
import argparse,hashlib,json,os,subprocess,sys
from contextlib import contextmanager
from pathlib import Path
import sjrb_oracle as ring

ROOT=Path(__file__).resolve().parents[2];HERE=ROOT/'game/native/sjrb'
sys.path.insert(0,str(HERE));import compare_original as compare
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

@contextmanager
def layout():
    changes=dict(MAX_CAPACITY=1048576,MAX_COPY_BYTES=1048612,BUFFER=0x800010,SLOTS=0xa00004,STACK=0xb00000,STACK_TOP=0xb01000)
    before={n:getattr(ring,n)for n in changes}
    try:
        for n,v in changes.items():setattr(ring,n,v)
        yield changes
    finally:
        for n,v in before.items():setattr(ring,n,v)

def inputs(capacity):
    c=ring.call;b=ring.BUFFER;s=lambda n:ring.SLOTS+16*n;p=ring.POOL
    actions=[c('initialize'),c('create',b,capacity,36),c('set_error',p,ring.ERROR,ring.CONTEXT),
        c('get',p,0,capacity-20,s(0)),c('put',p,1,s(0)),c('get',p,1,capacity-20,s(1)),c('put',p,0,s(1)),
        c('get',p,0,64,s(2)),ring.data(b+capacity-20,56,0x70),c('put',p,1,s(2)),
        c('get',p,0,8,s(3)),ring.data(b+36,8,0xa8),c('put',p,1,s(3)),
        c('get',p,1,64,s(4)),c('split',s(4),20,s(5),s(6)),c('put',p,0,s(5)),c('unget',p,1,s(6)),
        c('get',p,1,44,s(7)),c('put',p,0,s(7)),c('count',p,0),c('count',p,1),c('reset',p)]
    return dict(name='capacity-'+str(capacity),capacity=capacity,extension=36,actions=actions)

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--compiler',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/large-sjrb'):raise ValueError('Fresh owned output required')
    frozen=json.loads((HERE/'frozen_identity.json').read_bytes())
    for n,d in frozen['source_sha256'].items():
        if sha(HERE/n)!=d:raise ValueError('Original-qualified native Ring drift: '+n)
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    body=(HERE/'fixture_runner.cpp').read_text();anchor='constexpr std::int64_t buffer = 0x400010, slots_base = 0x500004;'
    if body.count(anchor)!=1:raise ValueError('Synthetic transport layout changed')
    body=body.replace(anchor,'constexpr std::int64_t buffer = 0x800010, slots_base = 0xa00004;')
    fixture=out/'fixture.cpp';fixture.write_text(body,encoding='utf-8',newline='\n')
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),driver_sha256=sha(Path(__file__)),
        frozen_native_identity_sha256=sha(HERE/'frozen_identity.json'),native_core_sha256=sha(HERE/'sjrb.cpp'),
        native_header_sha256=sha(HERE/'sjrb.hpp'),comparator_sha256=sha(HERE/'compare_original.py'),
        adapted_transport_sha256=sha(fixture),game_run=False,device_opened=False,cases=[],checks=[])
    def run(label,cmd):
        r=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,env=env,timeout=90)
        (out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit_code=r.returncode,command=list(map(str,cmd))))
        if r.returncode:raise ValueError('Check failed: '+label)
        return r.stdout
    try:
        exe=out/'ring.exe';run('compile',[a.compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),HERE/'sjrb.cpp',fixture,'-o',exe])
        record['source_authority']=ring.source_audit(ROOT/'recomp/config/output')
        with layout() as selected:
            cases=[inputs(n)for n in [53248,272384]];record['harness_geometry']=selected
            (out/'inputs.json').write_bytes(ring.canonical(dict(cases=cases)))
            record['inputs_sha256']=sha(out/'inputs.json')
            for case in cases:
                expected=ring.execute_case(case);name=case['name'];original=out/(name+'-original.json');original.write_bytes(ring.canonical(expected))
                commands=out/(name+'.commands');commands.write_text(compare.commands(case),encoding='utf-8',newline='\n')
                native=run(name,[exe,commands]);observed=[json.loads(n)for n in native.splitlines()]
                result=compare.compare_case(case,expected,observed)
                record['cases'].append(dict(name=name,original_sha256=sha(original),native_sha256=hashlib.sha256(native.encode()).hexdigest(),commands_sha256=sha(commands),**result))
        record.update(status='actual large ring instructions and native observations match',totals={n:sum(r[n]for r in record['cases'])for n in ['calls','state_words','physical_bytes','descriptor_bytes','guard_events','error_callbacks','defined_returns']})
    finally:
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],cases=len(record['cases']),**record['totals'])))
if __name__=='__main__':main()
