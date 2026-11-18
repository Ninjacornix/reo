#!/usr/bin/env python3
"""Compare an owned selected-clock context to frozen original-word call paths."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2];BASE=ROOT/'build-native-sjuni/movie-selected-clock'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
COUNTER=['actual','requested','pause','buffering_pause','property_47','active_counter','increment','elapsed_counter','elapsed_origin','external_accumulator']
EXTRA=['selector_f','pending','cached_numerator','cached_denominator','previous_sample','external_denominator']
FACTS=['actual','pause','buffering_pause','property_47']
KINDS={0:0,0x1764B0:1,0x1764F8:2,0x176558:3,0x176578:4,0xF00000:5}


def snapshot(original):
    state=original['state']
    return [state[n] for n in COUNTER+EXTRA]+[int(bool(state['external_callback']))]+[KINDS[state['slot'+str(n)]] for n in range(7)]+[original['guard_depth'],original['guard_tag']]


def plan(row,original):
    fields=[row[n] for n in COUNTER+EXTRA+['frequency','guard_hooks','guard_depth','guard_tag']]
    fields += [{'default':0,'custom':1,'null':2}[row['slot_kind']],int(row['external_present'])]
    fields += [row[n] for n in ['numerator','denominator','refresh_scratch_numerator','refresh_scratch_denominator','external_scratch_numerator','external_scratch_denominator','reply_mask','reply_numerator','reply_denominator','reply_status']]
    scratch={entry['kind']:entry['words'] for entry in original['scratch_observations']}
    # These are actual observed prior local words at their point of use, not
    # the selected callback's result or a computed playback timestamp.
    if 'refresh' in scratch:fields[24:26]=scratch['refresh']
    if 'external' in scratch:fields[26:28]=scratch['external']
    fields += [sum(1<<n for n,f in enumerate(FACTS) if f in row['fact_updates'])]
    fields += [row['fact_updates'].get(f,0) for f in FACTS]+[int(row['remove_selected_slot'])]
    return row['operation']+' '+' '.join(map(str,fields))


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scope required')
    frozen=BASE/'original-freeze-v3';receipt=json.loads((frozen/'receipt.json').read_bytes())
    if sha(frozen/'receipt.json')!='2222c67232104f85caf3a025f2bb2cf20ca6d1b9733b313f9052e4bfb0511f7d' or not receipt['native_exists']:raise ValueError('Point-of-use observation cohort required')
    prior=BASE/'original-freeze-v2';pre=json.loads((prior/'receipt.json').read_bytes())
    if sha(prior/'receipt.json')!='fbaa8b3d40e5b56689d9c1f1b031dbfa6a2b650eab6c5db1edd4600d267af89a' or pre['native_exists']:raise ValueError('Pre-native authority required')
    for name,digest in pre['outputs_sha256'].items():
        if sha(prior/name)!=digest:raise ValueError('Pre-native output drift')
    for name,digest in receipt['outputs_sha256'].items():
        if sha(frozen/name)!=digest:raise ValueError('Original expectation drift')
    authority=json.loads((frozen/'input-manifest.json').read_bytes())
    for name,digest in authority['existing_native_sources'].items():
        if sha(BASE/'failed-v2-inputs'/name)!=digest:raise ValueError('Pre-correction native snapshot drift')
    if sha(ROOT/'game_data/SLUS_207.65')!=authority['elf_sha256']:raise ValueError('Owned ELF drift')
    for name,digest in authority['sources'].items():
        if sha(ROOT/name)!=digest:raise ValueError('Original engine/source drift')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return[n for n,d in manifest['files'].items() if sha(ROOT/n)!=d]
    if drift():raise ValueError('Native source drift '+str(drift()))
    cases=json.loads((frozen/'inputs.json').read_bytes());expected=json.loads((frozen/'original.json').read_bytes())
    if (frozen/'inputs.json').read_bytes()!=(prior/'inputs.json').read_bytes() or json.loads((prior/'original.json').read_bytes())!=[{k:v for k,v in row.items() if k!='scratch_observations'} for row in expected]:raise ValueError('Original results changed beyond added scratch observation')
    text='\n'.join(plan(row,original) for row,original in zip(cases,expected,strict=True))+'\n'
    out.mkdir(parents=True);(out/'plan.txt').write_text(text,encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(HERE)]
    dependency=ROOT/'game/native/movie_counter_clock/clock.cpp'
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),original_receipt_sha256=sha(frozen/'receipt.json'),checks=[],negative_controls=[],game_run=False,device_opened=False,production_selected=False,original_whole_movie_parity=False)

    def run(name,command,input=None,negative=False):
        r=subprocess.run([str(v) for v in command],cwd=ROOT,env=env,text=True,input=input,capture_output=True,timeout=60)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(v) for v in command],exit=r.returncode))
        if not negative and r.returncode or negative and not r.returncode:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout

    def unit(name,source,negative=False):
        binary=out/(name+'-units.exe');run(name+'-units-compile',flags+[source,dependency,HERE/'clock_tests.cpp','-o',binary]);return run(name+'-units',[binary],negative=negative)

    def compare(name,source):
        binary=out/(name+'.exe');run(name+'-compile',flags+[source,dependency,HERE/'fixture.cpp','-o',binary]);lines=run(name,[binary],text).splitlines()
        if len(lines)!=len(cases):raise ValueError('Incomplete native transcript')
        differences=[]
        for case,original,line in zip(cases,expected,lines,strict=True):
            tokens=line.split()
            if tokens[0]!='row':raise ValueError('Native row schema')
            values=[int(v) for v in tokens[1:]];errors=[]
            if values[:26]!=snapshot(original['after']):errors.append('owned state/registry/guard')
            if values[26:28]!=[original['after']['numerator'],original['after']['denominator']]:errors.append('caller rational words')
            if bool(values[28])!=original['return_defined'] or original['return_defined'] and values[29]!=(original['raw_v0_lower64']&0xFFFFFFFF):errors.append('defined callback status')
            count=values[30]
            if len(values)!=31+29*count:raise ValueError('Probe schema')
            records=[values[31+n*29:31+(n+1)*29] for n in range(count)]
            phases=[(r[0],r[3:]) for r in records if r[0] in [0,3]]
            old_phases=[(0 if r['phase']=='enter' else 3,snapshot(r['snapshot'])) for r in original['phases']]
            if phases!=old_phases:errors.append('guard envelope snapshots')
            ports=[(r[0],r[3:],r[1:3] if r[0]==2 else None) for r in records if r[0] in [1,2,4]]
            old_ports=[({'query':2,'guard_enter':1,'guard_leave':4}[r['port']],snapshot(r['snapshot']),r.get('before_pair')) for r in original['ports']]
            if ports!=old_ports:errors.append('actual callback/hook snapshots and scratch')
            if errors:differences.append(dict(name=case['name'],differences=errors))
        (out/(name+'-differences.json')).write_text(json.dumps(differences,indent=2)+'\n',encoding='utf-8',newline='\n');report.setdefault('executables',{})[name]=sha(binary)
        return differences

    try:
        report['units']=unit('native',HERE/'clock.cpp').strip();differences=compare('native',HERE/'clock.cpp')
        if differences:raise ValueError('Native mismatch '+str(differences[:4]))
        source=(HERE/'clock.cpp').read_text(encoding='utf-8')
        variants=[('all-negative-cache-miss',[('config_.state.cached.numerator!=0xFFFFFFFBu','(config_.state.cached.numerator&0x80000000u)==0')]),
                  ('ignore-failed-query-refresh',[('auto words=scratch.refresh;(void)selected(words,scratch.external);auto& state=config_.state;','auto words=scratch.refresh;if(selected(words,scratch.external)!=0)return;auto& state=config_.state;')]),
                  ('stale-post-callback-gate',[('const auto status=callback(provider,scratch);auto& state=config_.state;','auto before=config_.state.counter;const auto status=callback(provider,scratch);auto& state=config_.state;'),('counter::execute(state.counter,counter::Operation::active_gate','counter::execute(before,counter::Operation::active_gate')]),
                  ('ignore-previous-sentinel',[('state.previous_sample!=0xFFFFFFFBu','true')]),
                  ('rebase-unchanged-cache',[('if(words.numerator!=state.cached.numerator || words.denominator!=state.cached.denominator)','if(true)')])]
        for name,changes in variants:
            changed=source
            for old,new in changes:
                if changed.count(old)!=1:raise ValueError('Mutation selector drift '+name)
                changed=changed.replace(old,new)
            path=out/(name+'.cpp');path.write_text(changed,encoding='utf-8',newline='\n');differences=compare(name,path)
            if not differences:raise ValueError('Undetected counterfactual '+name)
            report['negative_controls'].append(dict(name=name,differences=len(differences),source_sha256=sha(path)))
        old='const auto query=callbacks_[slot];'
        if source.count(old)!=1:raise ValueError('Callback lifetime selector drift')
        path=out/'missing-callback-retention.cpp';path.write_text(source.replace(old,'const auto& query=callbacks_[slot];'),encoding='utf-8',newline='\n');unit('missing-callback-retention',path,negative=True)
        report['negative_controls'].append(dict(name='missing-callback-retention',source_sha256=sha(path)))
        old='const auto provider=external_;'
        if source.count(old)!=1:raise ValueError('External callback lifetime selector drift')
        path=out/'missing-external-retention.cpp';path.write_text(source.replace(old,'const auto& provider=external_;'),encoding='utf-8',newline='\n');unit('missing-external-retention',path,negative=True)
        report['negative_controls'].append(dict(name='missing-external-retention',source_sha256=sha(path)))
        report.update(status='passed owned selected-clock/cache/external history and seven detected counterfactuals',cases=len(cases),original_instructions=receipt['instructions'],native_transcript_sha256=sha(out/'native.txt'))
    except Exception as error:report.update(status='failed',failure=str(error));raise
    finally:
        report['input_drift']=drift()
        if report['input_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],cases=report['cases'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
