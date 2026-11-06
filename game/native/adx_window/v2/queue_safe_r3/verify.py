#!/usr/bin/env python3
"""Qualify pure PCM sizing and retain the independent storage projection."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
HERE=Path(__file__).resolve().parent;ROOT=HERE.parents[4]
BASE=ROOT/'build-native-sjuni/adx-queue-safe-window'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',required=True,type=Path);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or out.exists() or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    frozen=json.loads((HERE/'manifest.json').read_bytes())
    def drift():return [n for n,d in frozen['files'].items() if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen source drift '+str(drift()))
    prior=(HERE.parent/'playback_r2/stream_window.cpp').read_text();current=(HERE/'stream_window.cpp').read_text()
    start=current.index('    // Native scheduling extension:');end=current.index('    const auto units = groups * channels;',start)
    normalized=(current[:start]+current[end:]).replace('#include "../playback_r2/stream_window.hpp"','#include "stream_window.hpp"',1).replace('auto groups = std::min({engine_.input_blocks / channels, available, budget, window});','const auto groups = std::min({engine_.input_blocks / channels, available, budget, window});')
    if normalized!=prior:raise ValueError('Unreviewed R2 algorithm delta')
    original=ROOT/'build-native-sjuni/adx-pcm-store/original-v1';phases=ROOT/'build-native-sjuni/adx-pcm-store/v2/phase-original-gcc-v1'
    if sha(original/'manifest.json')!='e04d6d6dc08547f58f33ce6e41c512dbd8c83b1f0020e52b14af9a247731f131':raise ValueError('Original storage input identity drift')
    m=json.loads((original/'manifest.json').read_bytes())
    if sha(original/'cases.json')!=m['cases_sha256']:raise ValueError('Original storage case drift')
    if sha(phases/'receipt.json')!='a7ea02d37d2b3eda1d24458f6928dedcaae7ef53cc8b149a78f76825b1295736':raise ValueError('Original phase identity drift')
    pr=json.loads((phases/'receipt.json').read_bytes())
    if sha(phases/'phases.json')!=pr['phases_sha256'] or not pr['original_transcripts_unchanged']:raise ValueError('Original phase drift')
    cases=json.loads((original/'cases.json').read_bytes());stage=json.loads((phases/'phases.json').read_bytes())
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    report=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),manifest_sha256=sha(HERE/'manifest.json'),checks=[],game_run=False,device_opened=False,original_whole_player_parity=False,r2_source_sha256=sha(HERE.parent/'playback_r2/stream_window.cpp'),r3_only_changes='include spelling; mutable group candidate; pure pre-codec admission/reduction/backpressure')
    pcm=ROOT/'game/native/adx_pcm_store/v2';flags=[cc,'-std=c++20','-O2','-Wall','-Wextra','-Wpedantic','-Werror','-I'+str(pcm)]
    def run(name,command,input=None,expected=0):
        r=subprocess.run([str(x) for x in command],input=input,cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/(name+'.txt')).write_text(r.stdout+r.stderr,encoding='utf-8',newline='\n');report['checks'].append(dict(name=name,command=[str(x) for x in command],exit=r.returncode,expected=expected))
        if r.returncode!=expected:raise ValueError(name+': '+r.stdout+r.stderr)
        return r.stdout
    try:
        deps=[ROOT/'game/native/sjrb/sjrb.cpp'];binary=out/'units.exe'
        run('units-compile',flags+[pcm/'pcm_store.cpp',*deps,pcm/'pcm_store_tests.cpp','-o',binary]);report['units']=run('units',[binary]);report['units_executable_sha256']=sha(binary)
        source=(pcm/'pcm_store.cpp').read_text();anchor='producer_[c] = suffix;'
        if source.count(anchor)!=1:raise ValueError('Post-effect fault cut drift')
        for name,text,arg,expected in [('posteffect',source.replace(anchor,anchor+'\n        if(c==0)return fail();'),'posteffect',0),('ignored-effect',source,'posteffect',1),('ids',source.replace('domain_->channels = config.channels;','domain_->channels = config.channels;\n    last_write_=last_read_=std::numeric_limits<std::uint64_t>::max();'),'ids',0)]:
            path=out/(name+'.cpp');path.write_text(text,encoding='utf-8',newline='\n');binary=out/(name+'.exe')
            run(name+'-compile',flags+[path,*deps,pcm/'pcm_store_tests.cpp','-o',binary]);run(name,[binary,arg],expected=expected)
        binary=out/'storage.exe';run('storage-compile',flags+[pcm/'pcm_store.cpp',*deps,pcm/'fixture_runner.cpp','-o',binary])
        data='\n'.join(f"{c['name']} {c['channels']} {c['queued_bytes']} {c['operation']} {c['produced']} {c['published']} {c['left_hex'] or '-'} {c['right_hex'] or '-'}" for c in cases)+'\n'
        rows=[json.loads(line) for line in run('storage',[binary],input=data).splitlines()]
        if len(rows)!=90 or len(rows)!=len(stage):raise ValueError('Incomplete storage projection')
        for c,s,r in zip(cases,stage,rows,strict=True):
            if c['name']!=s['name'] or c['original_case_sha256']!=s['original_transcript_sha256']:raise ValueError('Original phase/final case mismatch')
            expected=dict(name=c['name'],stage=None if s['stage'] is None else {n:s['stage'][n] for n in ('rings','backings')},callbacks=c['expected']['callbacks'],final={n:c['expected'][n] for n in ('rings','backings')})
            if r!=expected:raise ValueError('Original storage projection difference '+c['name'])
        report.update(status='passed pure sizing, protected queued audio, storage lifecycle and original stage/final projections',original_storage_clients=len(rows),original_stage_captures=sum(s['stage'] is not None for s in stage),storage_transcript_sha256=sha(out/'storage.txt'))
    except Exception as e:report.update(status='failed',failure=str(e));raise
    finally:
        report['input_drift']=drift()
        if report['input_drift']:report['status']='failed source drift'
        (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],units=report['units'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
