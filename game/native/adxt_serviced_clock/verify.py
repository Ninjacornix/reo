#!/usr/bin/env python3
"""Compare serviced discard with original words and actual native group dispatch."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/adxt-serviced-discard'
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
import adxt_serviced_discard_oracle as oracle
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def body(text,needle):
    if text.count(needle)!=1:raise ValueError('Math selector drift')
    start=text.index('{',text.index(needle));depth=0
    for i in range(start,len(text)):
        if text[i]=='{':depth+=1
        elif text[i]=='}':
            depth-=1
            if not depth:return text[start:i+1]
    raise ValueError('Math body boundary')


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    frozen=ROOT/manifest['original_freeze'];identity=json.loads((frozen/'manifest.json').read_bytes())
    if sha(frozen/'manifest.json')!=manifest['original_freeze_sha256']or identity['authority']!=oracle.authority():raise ValueError('Original authority drift')
    if identity['native_exists']:
        prior=ROOT/identity['prior_freeze'];proof=json.loads((prior/'manifest.json').read_bytes())
        if proof['native_exists']or sha(prior/'manifest.json')!=identity['prior_manifest_sha256']or not identity['only_admission_annotations_changed']:raise ValueError('Missing pre-native behavior inputs')
        before=json.loads((prior/'inputs.json').read_bytes())['cases'];after=json.loads((frozen/'inputs.json').read_bytes())['cases']
        if sha(prior/'inputs.json')!=identity['prior_inputs_sha256']:raise ValueError('Ancestor input drift')
        for x,y in zip(before,after,strict=True):
            x=dict(x);y=dict(y);x.pop('native_exclusion',None);y.pop('native_exclusion',None)
            if x!=y:raise ValueError('Behavior input changed after native implementation')
    name='gcc-v1'if sha(Path(cc))==identity['authority']['workers']['gcc-v1']['compiler_sha256']else'llvm-v1'
    if sha(Path(cc))!=identity['authority']['workers'][name]['compiler_sha256']:raise ValueError('Unqualified exact compiler')
    original=ROOT/manifest['original_runs'][name];receipt=json.loads((original/'receipt.json').read_bytes())
    if sha(original/'receipt.json')!=manifest['original_receipts'][name]or sha(frozen/'inputs.json')!=identity['inputs_sha256']:raise ValueError('Original input/result drift')
    expected={}
    for row in receipt['rows']:
        path=original/(row['name']+'.json')
        if sha(path)!=row['sha256']:raise ValueError('Original row drift')
        expected[row['name']]=json.loads(path.read_bytes())
    current=(HERE/'completion.cpp').read_text();old=(ROOT/'game/native/adxt_estimated_clock/estimated_clock.cpp').read_text();math={}
    for needle in ('float signed_float(', 'std::uint32_t converted(', 'std::uint32_t baseline('):
        if body(current,needle)!=body(old,needle):raise ValueError('Inherited FP algorithm drift')
        math[needle]=hashlib.sha256(body(current,needle).encode()).hexdigest()
    cases=json.loads((frozen/'inputs.json').read_bytes())['cases'];plan=[]
    fields=['state','decoded','total','frequency','depth_mode','depth_code','base','offset','output_present','output_bytes','rna_free_bytes','mode','ratio','counter','rebase_mode','service_guard','tick','tick_base','estimate_base','paused','play','drift_bits']
    for c in cases:
        plan.append(' '.join(map(str,[c['name'],*[int(c[n])for n in fields],len(c['updates'])])))
        for u in c['updates']:plan.append(f"{u['event']} {u['field']} {u['value']}")
    out.mkdir(parents=True);(out/'plan.txt').write_text('\n'.join(plan)+'\n',encoding='utf-8',newline='\n');env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(original/'receipt.json'),inherited_math_bodies=math,checks=[],negative_controls=[],game_run=False,device_opened=False,production_player_binding=False)
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(HERE)]
    deps=[ROOT/'game/native'/n for n in ['adxt_estimated_clock/estimated_clock.cpp','adxt_integer_clock/integer_clock.cpp','adxt_service_group/service_group.cpp','adxt_transfer_groups/transfer_groups.cpp']]
    def run(name,cmd):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout.strip()
    def compare(path):
        rows=[json.loads(s)for s in path.read_text().splitlines()]
        if [r['name']for r in rows]!=[c['name']for c in cases]:raise ValueError('Missing native cases')
        mismatches=[];exclusions=[]
        for row,c in zip(rows,cases,strict=True):
            if c.get('native_exclusion'):
                if row['status']!=4 or row['dispatch']or row['diagnostics']:raise ValueError('Native exclusion had effects')
                initial=dict(estimate_base_u32=c['estimate_base'],tick_base_u32=c['tick_base'],paused_byte=c['paused'],rna_play_byte=c['play'],mode_u32=c['mode'],counter_u32=c['counter'],drift_bits_u32=c['drift_bits'])
                if row['projection']!=initial or row['service_busy']!=c['service_guard']:raise ValueError('Native exclusion changed state')
                exclusions.append(dict(name=c['name'],reason=c['native_exclusion']));continue
            prior=expected[c['name']];projection=prior['original']['projection'];result=prior['original']['result']
            busy=int.from_bytes(bytes.fromhex(result['after']['globals_hex'])[4:8],'little')
            diagnostics=sum(e.get('kind')=='external_diagnostic'for e in result['events'])
            fields_changed=[n for n,v in row['projection'].items()if projection[n]!=v]
            if row['status']or fields_changed or row['service_busy']!=busy or row['diagnostics']!=diagnostics or row['dispatch']!=prior['dispatch']or row['queue_after']!=prior['queue_after']:mismatches.append(dict(name=c['name'],projection_fields=fields_changed))
        return mismatches,exclusions
    try:
        binary=out/'units.exe';run('units-compile',flags+[HERE/'completion.cpp',HERE/'completion_tests.cpp',*deps,'-o',binary]);report['units']=run('units',[binary])
        binary=out/'fixture.exe';run('fixture-compile',flags+[HERE/'completion.cpp',HERE/'fixture_runner.cpp',*deps,'-o',binary]);run('fixture',[binary,out/'plan.txt',out/'results.jsonl']);differences,exclusions=compare(out/'results.jsonl')
        if differences:raise ValueError('Native/original mismatch '+str(differences))
        anchor='auto observation=service_->observation();const bool paused=stream_.paused!=0;'
        raw='const auto raw=clock::integer::query(clock::integer::Query::decoded_minus_queued,observation);\n    fresh.estimate_base='
        mutations=[('stale-queue',[(anchor,anchor+'const auto stale=observation;'),(raw,raw.replace(',observation)',',stale)'))]),
                   ('missing-service',[('const auto serviced=service_->run_and_refresh(fresh,observation);','const auto serviced=ServiceStatus::completed;')])]
        for name,edits in mutations:
            mutant=current
            for old,new in edits:
                if mutant.count(old)!=1:raise ValueError('Mutation source drift '+name)
                mutant=mutant.replace(old,new)
            path=out/(name+'.cpp');path.write_text(mutant,encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,HERE/'fixture_runner.cpp',*deps,'-o',binary]);run(name,[binary,out/'plan.txt',out/(name+'.jsonl')]);differences,_=compare(out/(name+'.jsonl'))
            if not differences:raise ValueError('Negative matched original '+name)
            (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report['negative_controls'].append(dict(name=name,differences=len(differences),source_sha256=sha(path)))
        report.update(status='passed native serviced-discard and complete original dispatch/FP comparison',cases=len(cases)-len(exclusions),explicit_exclusions=exclusions,original_instructions=receipt['original_instructions'],fp_steps=receipt['fp_steps'],executable_sha256=sha(out/'fixture.exe'),results_sha256=sha(out/'results.jsonl'))
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],cases=report['cases'],negative_controls=report['negative_controls'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
