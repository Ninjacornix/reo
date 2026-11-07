#!/usr/bin/env python3
"""Compare actual coded-order movie inputs with independently executed EE bodies.

The input trace is a parser observation, not the reference result. Every input
is replayed through owned instructions and its complete native fixture state.
"""
import argparse, copy, hashlib, json, os, subprocess
from pathlib import Path
import movie_timecode_oracle as original

ROOT=original.ROOT
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser()
    p.add_argument('--trace',type=Path,required=True)
    p.add_argument('--compiler',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/movie-matrix'):
        raise ValueError('Fresh owned scope required')
    prior=ROOT/'build-native-sjuni/movie-timing-context/original-llvm-v3'
    identity=json.loads((prior/'input-manifest.json').read_bytes())
    binary=prior/'fp_worker.exe'
    if sha(binary)!=identity['fp_worker_sha256']:raise ValueError('Original worker drift')
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    os.environ['PATH']=str(Path(identity['compiler']).parent)+os.pathsep+os.environ.get('PATH','')
    j=original.j
    j.fp.FP_INTERVALS={0x175A50:0x175C50,0x1770F0:0x177240,0x1772B8:0x1773A8}
    j.PORTS[0x155E60]='memory_copy'
    rows=[json.loads(s) for s in a.trace.read_text().splitlines()]
    if not rows:raise ValueError('Empty picture trace')
    case=copy.deepcopy(original.corpus()[0]);case['operations']=[]
    out.mkdir(parents=True)
    record=dict(status='failed',trace_sha256=sha(a.trace),compiler_sha256=sha(a.compiler),
                worker_sha256=sha(binary),elf_sha256=identity['elf_sha256'],pictures=len(rows),
                sources={f.relative_to(ROOT).as_posix():sha(f) for f in [Path(__file__),Path(original.__file__),Path(original.temporal.__file__),ROOT/'game/native/movie_timestamp/timecode.cpp',ROOT/'game/native/movie_timestamp/timestamp.cpp',ROOT/'game/native/movie_timestamp/timecode_fixture.cpp']},
                game_run=False,audio_device_opened=False)
    try:
        expected=[];plan=[];observations=[]
        def flat(s):return [s['temporal']['baseline']]+s['temporal']['state']+[s['property34']]+s['first']+s['latest']+s['current']+s['metadata']
        with j.fp.FpuWorker(binary) as worker:
            machine=original.Machine(case,worker,set(j.fp.fp_words().values()))
            initial=machine.initial['temporal']
            plan.append(' '.join(map(str,[0,initial['baseline']]+initial['state']+[len(rows)])))
            expected.append('row 0 -1 4294967295 '+' '.join(map(str,flat(machine.initial))))
            for index,row in enumerate(rows):
                op={k:row[k] for k in ['rate','reference','kind','drop','hours','minutes','seconds','frames','gop','changed','stamp']}
                op.update(begin=row['account_begin'],bytes=row['account_bytes'])
                result=machine.execute_flow(op);observations.append(result)
                expected.append('row 0 '+str(index)+' '+str(result['stamp'])+' '+' '.join(map(str,flat(result['after']))))
                words=[op[k] for k in ['rate','reference','kind','drop','hours','minutes','seconds','frames','gop','changed']]+[int(op['stamp'] is not None),op['stamp'] or 0,op['begin'],op['bytes']]
                plan.append(' '.join(map(str,words)))
            record.update(instructions=machine.steps,body_ids=machine.body_ids,constants=machine.mem.constants)
        (out/'original.json').write_text(json.dumps(observations,indent=2)+'\n',encoding='utf-8',newline='\n')
        command=[str(a.compiler),'-std=c++20','-O2','-ffp-contract=off',*[str(ROOT/'game/native/movie_timestamp'/name) for name in ['timecode.cpp','timestamp.cpp','timecode_fixture.cpp']],'-o',str(out/'native.exe')]
        result=subprocess.run(command,capture_output=True,text=True,env=env)
        (out/'compile.txt').write_text(result.stdout+result.stderr,encoding='utf-8')
        if result.returncode:raise ValueError('Native fixture compile failed')
        result=subprocess.run([str(out/'native.exe')],input='\n'.join(plan)+'\n',capture_output=True,text=True,env=env,timeout=30)
        (out/'native.txt').write_text(result.stdout+result.stderr,encoding='utf-8')
        differences=[dict(row=i,expected=e,actual=v) for i,(e,v) in enumerate(zip(expected,result.stdout.splitlines())) if e!=v]
        (out/'differences.json').write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8')
        if result.returncode or len(result.stdout.splitlines())!=len(expected) or differences:raise ValueError('Actual-input native/original mismatch')
        record.update(status='actual movie timecode inputs match owned execution',differences=0)
    finally:
        record['outputs_sha256']={f.name:sha(f) for f in out.iterdir() if f.suffix in ['.json','.txt'] and f.name!='receipt.json'}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k] for k in ['status','pictures','instructions','differences']}))

if __name__=='__main__':main()
