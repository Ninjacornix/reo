#!/usr/bin/env python3
"""Compare inputs-only native raw-clock results to frozen original instructions."""
import argparse
import hashlib
import json
from pathlib import Path
import shutil
import subprocess

BASE=Path(__file__).resolve().parent
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def freeze():
    for name,digest in json.loads((BASE/'frozen_identity.json').read_bytes())['files'].items():
        if sha(BASE/name)!=digest:raise RuntimeError('Frozen source changed: '+name)

def main():
    p=argparse.ArgumentParser(description=__doc__)
    p.add_argument('--compiler',required=True);p.add_argument('--fixture',type=Path,required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    freeze();manifest=json.loads((a.fixture/'manifest.json').read_bytes())
    for name in ('inputs','expected'):
        if sha(a.fixture/(name+'.json'))!=manifest[name+'_sha256']:raise RuntimeError('Original fixture changed')
    inputs=json.loads((a.fixture/'inputs.json').read_bytes())['cases']
    expected=json.loads((a.fixture/'expected.json').read_bytes())
    if len(inputs)!=len(expected):raise RuntimeError('Original row count mismatch')
    out=a.output.resolve()
    if out.exists():raise RuntimeError('Preserve earlier evidence; use a fresh directory')
    out.mkdir(parents=True);compiler=Path(shutil.which(a.compiler)or a.compiler).resolve()
    commands=[]
    def run(label,cmd,**kw):
        r=subprocess.run(list(map(str,cmd)),capture_output=True,text=True,**kw)
        (out/(label+'.stdout.txt')).write_text(r.stdout,encoding='utf-8',newline='\n')
        (out/(label+'.stderr.txt')).write_text(r.stderr,encoding='utf-8',newline='\n')
        commands.append(dict(label=label,command=list(map(str,cmd)),returncode=r.returncode))
        if r.returncode:raise RuntimeError(label+' failed: '+r.stderr)
        return r.stdout
    options=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I',BASE]
    run('unit-compile',options+[BASE/'integer_clock.cpp',BASE/'integer_clock_tests.cpp','-o',out/'unit.exe'])
    unit=run('unit-run',[out/'unit.exe'])
    keys=['entry','state','decoded','total','frequency','base','offset','depth_mode','depth_code',
          'output_present','output_bytes','rna_free_bytes','mode','ratio','counter','argument']
    transport=str(len(inputs))+'\n'+'\n'.join(' '.join(str(int(c[k]))for k in keys)for c in inputs)+'\n'
    (out/'input.txt').write_text(transport,encoding='utf-8',newline='\n')
    fields=['numerator_u32','denominator_u32','mode_u32','ratio_u32','counter_u32']
    def compare(lines):
        rows=lines.splitlines()
        if len(rows)!=len(expected):raise RuntimeError('Native row count mismatch')
        result=[]
        for c,e,line in zip(inputs,expected,rows,strict=True):
            observed=dict(zip(fields,map(int,line.split()),strict=True))
            passed=c['name']==e['name']and e['result']['status']=='returned'and observed==e['projection']
            result.append(dict(name=c['name'],passed=passed,observed=observed,expected=e['projection']))
        return result
    run('native-compile',options+[BASE/'integer_clock.cpp',BASE/'fixture_runner.cpp','-o',out/'probe.exe'])
    rows=compare(run('native-run',[out/'probe.exe'],input=transport))
    # Both tempting changes alter real admitted cases: offset applied to RNA,
    # and combining odd queue byte counts before individual truncation.
    source=(BASE/'integer_clock.cpp').read_text()
    mutations={
        'rna-offset':('value.numerator += o.base;','value.numerator += o.base + (kind == Query::rna_ratio ? o.offset : 0);'),
        'combined-halfwords':('value.numerator = o.decoded - rna - output + o.offset;',
            'value.numerator = o.decoded - ((16384u - o.rna_free_bytes + (o.output_present ? o.output_bytes : 0u)) / 2u) + o.offset;\n            (void)rna; (void)output;')}
    negative=[]
    for name,(old,new) in mutations.items():
        if source.count(old)!=1:raise RuntimeError('Mutation site drift')
        mutant=out/(name+'.cpp');mutant.write_text(source.replace(old,new),encoding='utf-8',newline='\n')
        binary=out/(name+'.exe')
        run(name+'-compile',options+[mutant,BASE/'fixture_runner.cpp','-o',binary])
        checks=compare(run(name+'-run',[binary],input=transport))
        failed=[r['name']for r in checks if not r['passed']]
        negative.append(dict(name=name,detected=bool(failed),failed_cases=failed))
    freeze()
    receipt=dict(schema=1,compiler=dict(path=str(compiler),sha256=sha(compiler)),commands=commands,
        fixture_manifest_sha256=sha(a.fixture/'manifest.json'),freeze_sha256=sha(BASE/'frozen_identity.json'),
        comparator_sha256=sha(Path(__file__)),runner_sha256=sha(BASE/'fixture_runner.cpp'),
        transport_sha256=sha(out/'input.txt'),unit_stdout=unit,comparisons=rows,negative_controls=negative,
        summary=dict(cases=len(rows),passed=sum(r['passed']for r in rows),negative_controls_detected=sum(r['detected']for r in negative)))
    (out/'receipt.json').write_text(json.dumps(receipt,indent=2,sort_keys=True)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(receipt['summary']))
    if not all(r['passed']for r in rows)or not all(r['detected']for r in negative):raise RuntimeError('Comparison failed; inspect preserved receipt')

if __name__=='__main__':main()
