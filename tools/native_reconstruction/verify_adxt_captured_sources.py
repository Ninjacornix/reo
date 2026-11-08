#!/usr/bin/env python3
"""Offline native playback of ranges captured from original ordinary ADXT starts."""
import argparse,hashlib,json,os,subprocess,time
from pathlib import Path
from analyze_adxt_observer import analyze
ROOT=Path(__file__).resolve().parents[2]
META=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','data','trace','native-receipt','manifest','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding'):raise ValueError('Fresh scoped output required')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(a.manifest) or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching native archive cohort required')
    inventory=json.loads((META/'receipt.json').read_bytes())
    for name in ('members.json','archives.json'):
        if sha(META/name)!=inventory['output_sha256'][name]:raise ValueError('Inventory drift')
    baseline=ROOT/'build-native-sjuni/adx-asset-streams/full-gcc-v1/results.jsonl'
    if sha(baseline)!='43b3876e4855a7b5cce35b448b1e1fa7b1fa707c8ed6be599508b2a6b80a12b9':raise ValueError('Finite baseline drift')
    finite={r['member']:r for r in map(json.loads,baseline.read_text().splitlines()) if r['decode_requested']}
    members=json.loads((META/'members.json').read_bytes());archives=json.loads((META/'archives.json').read_bytes())
    roots={r['member']:r for r in archives if r['member']==r['container']}
    indexed={(r['container'],r['iso_offset']-roots[r['container']]['iso_offset']):r for r in members if r['container'] in roots}
    findings=analyze(a.trace.resolve())
    if findings['status']!='completed bounded original-call evidence' or findings['header']['dropped']:raise ValueError('Complete zero-drop original capture required')
    recipes=[r for r in findings['ordinary_file_recipes'] if r['entry']=='133490']
    handles=sorted({r['handle'] for r in recipes})
    if handles!=[0x20f3c8,0x20f48c,0x20f550]:raise ValueError('Qualified 2/2/1 constructor profile required')
    plan=[];cases=[]
    # Baseline deduplication decoded only one reference for identical payloads.
    finite_by_hash={r['sha256']:finite[r['member']] for r in members if r['member'] in finite}
    for r in recipes:
        root=r['path'].upper();m=indexed[(root,r['start_sector']*2048)];meta=m['adx']
        if r['parent'] or r['channels']!=meta['channels'] or r['sector_count']*2048!=(m['bytes']+2047)//2048*2048:raise ValueError('Unmatched captured recipe')
        loop=bool(r['loop_enabled'] and meta['loop'].get('enabled'))
        plan.append(' '.join(map(str,(r['line'],handles.index(r['handle']),r['path'],r['start_sector'],r['sector_count'],r['channels'],meta['frequency'],meta['total_samples'],int(loop),r['service_divisor'],m['member']))))
        expected=None if loop else finite_by_hash[m['sha256']]
        cases.append(dict(line=r['line'],member=m['member'],loop=loop,payload_sha256=m['sha256'],expected=expected))
    if not cases:raise ValueError('Empty capture')
    inputs={n:d for n,d in manifest['files'].items() if n.startswith('game/native/') or n.startswith('recomp/overrides/native_banks/')}
    for path in (Path(__file__),Path(__file__).with_name('analyze_adxt_observer.py'),Path(__file__).with_name('adxt_captured_sources.cpp'),ROOT/'recomp/overrides/native_adxt/source_profile.h',ROOT/'recomp/overrides/native_adxt/source_profile.cpp'):inputs[path.relative_to(ROOT).as_posix()]=sha(path)
    def verify():
        for n,d in {**inputs,**native['libraries']}.items():
            if sha(ROOT/n)!=d:raise ValueError('Source/archive drift '+n)
    verify();data=a.data.resolve();imported=data.parent/'import.json'
    if sha(imported)!='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b':raise ValueError('Actual File1 import required')
    paths=[data/r['Name'] for r in json.loads(imported.read_bytes())['Files']];before={str(p):p.stat() for p in paths}
    out.mkdir(parents=True);(out/'plan.txt').write_text('\n'.join(plan)+'\n',encoding='utf-8',newline='\n');(out/'cases.json').write_text(json.dumps(cases,indent=2)+'\n',encoding='utf-8',newline='\n')
    record=dict(status='failed',sources=inputs,compiler_sha256=sha(a.compiler),native_receipt_sha256=sha(a.native_receipt),manifest_sha256=sha(a.manifest),trace_sha256=sha(a.trace),inventory_receipt_sha256=sha(META/'receipt.json'),finite_baseline_sha256=sha(baseline),game_run=False,device_opened=False,original_gameplay_pcm_parity=False,original_timing_replayed=False,original_mix_order_replayed=False,checks=[])
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    def run(label,command,timeout):
        started=time.monotonic();r=subprocess.run(list(map(str,command)),env=env,text=True,capture_output=True,timeout=timeout);(out/(label+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(label=label,exit=r.returncode,elapsed_seconds=time.monotonic()-started))
        if r.returncode:raise ValueError(label+' failed; see retained log')
    try:
        exe=out/'captured.exe';run('compile',[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I'+str(ROOT),ROOT/'recomp/overrides/native_adxt/source_profile.cpp',Path(__file__).with_name('adxt_captured_sources.cpp'),'-Wl,--start-group',*[ROOT/n for n in native['libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',exe],180)
        print('compile passed; replaying '+str(len(cases))+' captured sources',flush=True)
        run('captured',[exe,data,out/'plan.txt',out/'results.jsonl'],900)
        results=list(map(json.loads,(out/'results.jsonl').read_text().splitlines()))
        if len(results)!=len(cases):raise ValueError('Incomplete replay')
        for row,case in zip(results,cases):
            if row['line']!=case['line'] or row['member']!=case['member'] or row['status']!='passed' or not row['joined']:raise ValueError('Replay identity/fence mismatch')
            if case['expected'] and (row['samples']!=case['expected']['samples'][0] or row['byte_digest']!=case['expected']['byte_digest']):raise ValueError('Finite PCM baseline mismatch at '+case['member'])
        verify();record.update(status='captured ordinary file sources passed native offline playback',sources_replayed=len(results),finite_pcm_baselines_compared=sum(not c['loop'] for c in cases),two_iteration_loops=sum(c['loop'] for c in cases),executable_sha256=sha(exe))
    except Exception as e:record['failure']=str(e);raise
    finally:
        record['source_stats_unchanged']=all((s.st_size,s.st_mtime_ns,s.st_ino)==((t:=Path(n).stat()).st_size,t.st_mtime_ns,t.st_ino) for n,s in before.items());record['import_manifest_unchanged']=sha(imported)=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
        if not record['source_stats_unchanged'] or not record['import_manifest_unchanged']:record['status']='failed source drift'
        record['outputs_sha256']={p.name:sha(p) for p in out.iterdir() if p.suffix in ('.txt','.jsonl') or p.name=='cases.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
