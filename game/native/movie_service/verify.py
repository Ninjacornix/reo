#!/usr/bin/env python3
"""Compare state and ordered provider boundaries with independently run bodies."""
import argparse,copy,hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];HERE=Path(__file__).resolve().parent;BASE=ROOT/'build-native-sjuni/movie-service'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
ACTIONS=['counter','broadcast','shared','extent','requested_count','start','end_transition','buffer_pause','statistics']
SCALARS=['actual','requested','pending','buffered','threshold']
def flat(s):return [s[k] for k in SCALARS]+s['properties']+s['cached']+s['shared']
def patches(write):
    result=[(SCALARS.index(k),v) for k,v in write.items() if k in SCALARS]
    result += [(5+int(k),v) for k,v in write.get('properties',{}).items()]
    for key,offset in [('cached',105),('shared',109)]:result += [(offset+i,v) for i,v in enumerate(write.get(key,[]))]
    return result
def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--reference',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned scope required')
    reference=json.loads((a.reference/'receipt.json').read_bytes())
    if reference['status']!='owned pending service and transitions executed':raise ValueError('Incomplete original reference')
    for name,digest in reference['outputs_sha256'].items():
        if sha(a.reference/name)!=digest:raise ValueError('Original output drift')
    for name,digest in reference['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original source drift')
    cases=json.loads((a.reference/'inputs.json').read_bytes());results=json.loads((a.reference/'original.json').read_bytes());plan=[];expected=[]
    for identity,(case,result) in enumerate(zip(cases,results,strict=True)):
        plan.append(' '.join(map(str,[identity,len(case['operations'])]+flat(result['initial']))))
        for index,(op,evidence) in enumerate(zip(case['operations'],result['operations'],strict=True)):
            changes=patches(op.get('write',{}));words=[len(changes)]+[v for pair in changes for v in pair]+[len(evidence['events'])]
            expected.append('begin '+str(identity)+' '+str(index)+' '+' '.join(map(str,flat(evidence['before']))))
            for event in evidence['events']:
                kind=event['kind'];before=event['before'];after=flat(before);rule=op.get('ports',{}).get(kind,{})
                for at,value in patches(rule.get('write',{})):after[at]=value
                argument=event['args'][0] if event['args'] else 0
                words += [ACTIONS.index(kind),argument,event['returned']]+flat(before)+after
                expected.append('event '+str(ACTIONS.index(kind))+' '+str(argument)+' '+' '.join(map(str,flat(before))))
            plan.append(' '.join(map(str,words)))
            expected.append('end '+str(identity)+' '+str(index)+' '+' '.join(map(str,flat(evidence['after']))))
    out.mkdir(parents=True);text='\n'.join(plan)+'\n';(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    sources={p.relative_to(ROOT).as_posix():sha(p) for p in [HERE/'service.cpp',HERE/'service.hpp',HERE/'fixture.cpp',Path(__file__)]}
    record=dict(status='failed',compiler_sha256=sha(a.compiler),reference_receipt_sha256=sha(a.reference/'receipt.json'),sources=sources,cases=len(cases),operations=sum(len(c['operations']) for c in cases),rows=len(expected),negative_controls=[])
    def compare(label,source):
        binary=out/(label+'.exe');run=subprocess.run([str(a.compiler),'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE),str(source),str(HERE/'fixture.cpp'),'-o',str(binary)],capture_output=True,text=True,env=env)
        (out/(label+'-compile.txt')).write_text(run.stdout+run.stderr,encoding='utf-8')
        if run.returncode:raise ValueError('Fixture compile failed '+label)
        run=subprocess.run([str(binary)],input=text,capture_output=True,text=True,env=env,timeout=30)
        (out/(label+'.txt')).write_text(run.stdout+run.stderr,encoding='utf-8',newline='\n');actual=run.stdout.splitlines()
        differences=[dict(row=i,expected=e,actual=v) for i,(e,v) in enumerate(zip(expected,actual)) if e!=v]
        count=len(differences)+abs(len(expected)-len(actual))
        (out/(label+'-differences.json')).write_text(json.dumps(differences[:30],indent=2)+'\n',encoding='utf-8')
        return count,run.returncode
    try:
        differences,exit_code=compare('native',HERE/'service.cpp')
        record.update(native_differences=differences,native_exit=exit_code)
        if differences or exit_code:raise ValueError('Native pending-service mismatch')
        body=(HERE/'service.cpp').read_text()
        for label,old,new in [('clear-rescheduled-work','state.actual=transition(state,ports);','state.pending=0;state.actual=transition(state,ports);'),('dispatch-stale-state','state.actual=transition(state,ports);','state.actual=initial;state.actual=transition(state,ports);'),('skip-shared-prepass','(void)ports.call(Action::shared,0,state);','/* omitted shared prepass */'),('infer-ready','if(!ready(state))return initial;','if(!ready(state) && false)return initial;'),('ignore-end-transition','if(ports.call(Action::end_transition,0,state))return state.actual;','if(ports.call(Action::end_transition,0,state) && false)return state.actual;')]:
            if old not in body:raise ValueError('Mutation site missing '+label)
            path=out/(label+'.cpp');path.write_text(body.replace(old,new),encoding='utf-8',newline='\n');different,code=compare(label,path)
            if not different and not code:raise ValueError('Undetected fault '+label)
            record['negative_controls'].append(dict(name=label,differing_rows=different,exit=code))
        for name,digest in sources.items():
            if sha(ROOT/name)!=digest:raise ValueError('Native source changed during qualification')
        record['status']='native pending service and transitions qualified'
    finally:
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ['.txt','.json','.cpp'] and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps({k:record[k] for k in ['status','cases','operations','rows','native_differences']}))
if __name__=='__main__':main()
