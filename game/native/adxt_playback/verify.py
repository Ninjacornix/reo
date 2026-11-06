#!/usr/bin/env python3
"""Compare native playback control and real PCM storage against owned words."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess

HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[2]
BASE=ROOT/'build-native-sjuni/adxt-playback'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
encode=lambda v:(json.dumps(v,sort_keys=True,indent=2)+'\n').encode()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True)
    p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    compiler=shutil.which(a.cxx)
    if not compiler or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    manifest=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [n for n,d in manifest['files'].items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    original=BASE/'original-v2';receipt=json.loads((original/'receipt.json').read_bytes())
    frozen=BASE/'frozen-v2';identity=json.loads((frozen/'manifest.json').read_bytes())
    if sha(original/'receipt.json')!=manifest['original_receipt_sha256']or sha(frozen/'manifest.json')!=receipt['frozen_manifest_sha256']or sha(frozen/'inputs.json')!=identity['inputs_sha256']:raise ValueError('Original authority drift')
    descriptors={c['name']:c for c in receipt['cases']}
    cases=json.loads((frozen/'inputs.json').read_bytes())['cases']
    admitted=[c for c in cases if len(set(c['occupied']))==1]
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(compiler).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=compiler,compiler_sha256=sha(Path(compiler)),
                manifest_sha256=sha(HERE/'manifest.json'),verifier_sha256=sha(Path(__file__)),
                original_receipt_sha256=sha(original/'receipt.json'),game_run=False,device_opened=False,
                checks=[],cases=[],exclusions=[dict(name=c['name'],reason='uneven channel queues outside matching-credit owner')for c in cases if c not in admitted],negative_controls=[])
    flags=[compiler,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror']
    deps=[ROOT/'game/native/adx_pcm_store/v2/pcm_store.cpp',ROOT/'game/native/sjrb/sjrb.cpp']
    def run(name,cmd):
        r=subprocess.run([str(x)for x in cmd],cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n')
        report['checks'].append(dict(name=name,command=[str(x)for x in cmd],exit=r.returncode))
        if r.returncode:raise RuntimeError(name+': '+r.stdout+r.stderr)
        return r.stdout
    def build(name,core,client):
        binary=out/(name+'.exe');run(name+'-compile',flags+[core,client,*deps,'-I'+str(HERE),'-o',binary]);return binary
    def expected(c):
        path=original/(c['name']+'.json')
        if sha(path)!=descriptors[c['name']]['sha256']:raise ValueError('Original transcript drift')
        raw=json.loads(path.read_bytes())['original']
        if raw['failure']:raise ValueError('Incomplete original')
        obs=raw['after']['projection'];result={n:obs[n]for n in ('phase','started','base','tick_base','padding','play','transfer','stop_seen','thru')}
        result.update(name=c['name'],status=0,rings=[r[3:7]+r[10:14]for r in obs['rings'][:c['channels']]],backings=obs['backings'][:c['channels']])
        return result
    fields=('phase','channels','request','queued','occupied','decoder','inhibit','paused','started','padding','base','tick_base','tick','cursor','play','transfer','thru')
    def line(c):return c['name']+' '+' '.join(str(c[n][0]if n=='occupied'else c[n])for n in fields)+'\n'
    inputs=out/'inputs.txt';inputs.write_text(''.join(line(c)for c in admitted),encoding='utf-8',newline='\n')
    try:
        units=build('units',HERE/'playback.cpp',HERE/'playback_tests.cpp');report['unit_stdout']=run('units',[units]).strip()
        binary=build('native',HERE/'playback.cpp',HERE/'fixture_runner.cpp')
        actual=[json.loads(row)for row in run('native',[binary,inputs]).splitlines()]
        wanted=[expected(c)for c in admitted]
        if len(actual)!=len(wanted):raise ValueError('Missing native cases')
        for observed,reference in zip(actual,wanted,strict=True):
            if observed!=reference:
                differences=[n for n in reference if observed.get(n)!=reference[n]]
                (out/'first-difference.json').write_bytes(encode(dict(name=reference['name'],fields=differences,actual=observed,expected=reference)))
                raise ValueError(reference['name']+': '+str(differences))
            report['cases'].append(dict(name=reference['name'],channels=len(reference['rings']),physical_bytes=sum(len(x)//2 for x in reference['backings'])))
        mutants=[('stereo-padding','pcm.silence(request*d.channels)','pcm.silence(request)'),
                 ('drain-boundary','return remaining>0 ?','return remaining>=0 ?'),
                 ('tail-threshold','if (bytes>=64)','if (bytes>=62)')]
        source=(HERE/'playback.cpp').read_text()
        for name,old,new in mutants:
            if source.count(old)!=1:raise ValueError('Negative control source drift')
            path=out/(name+'.cpp');path.write_text(source.replace(old,new),encoding='utf-8',newline='\n')
            bad=build(name,path,HERE/'fixture_runner.cpp')
            observations=[json.loads(row)for row in run(name,[bad,inputs]).splitlines()]
            differences=[ref['name']for obs,ref in zip(observations,wanted,strict=True)if obs!=ref]
            if not differences:raise ValueError('Undetected negative control '+name)
            report['negative_controls'].append(dict(name=name,source_sha256=sha(path),differences=differences))
        report['status']='passed exact playback state, PCM queues, totals and physical bytes'
    except Exception as error:
        report.update(status='failed',failure=str(error));raise
    finally:
        report['source_drift']=drift()
        if report['source_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_bytes(encode(report))
    print(json.dumps(dict(status=report['status'],cases=len(report['cases']),exclusions=len(report['exclusions']),units=report['unit_stdout'],negatives={r['name']:len(r['differences'])for r in report['negative_controls']})))


if __name__=='__main__':main()
