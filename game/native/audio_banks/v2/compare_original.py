#!/usr/bin/env python3
"""Regression of allocator-policy v2 against previously seen frozen original.

No claim of an independent blind DSP implementation is made for this cohort.
"""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import sys
HERE=Path(__file__).resolve().parent
BASE=HERE.parent
sys.path.insert(0,str(BASE))
spec=importlib.util.spec_from_file_location('baseline_comparison',BASE/'compare_original.py')
baseline=importlib.util.module_from_spec(spec);spec.loader.exec_module(baseline)
from derive import derive
spec2=importlib.util.spec_from_file_location('budget_verification',HERE/'verify.py')
budget_verification=importlib.util.module_from_spec(spec2);spec2.loader.exec_module(budget_verification)
ROOT=HERE.parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def transport():
    text=(BASE/'native_transport.hpp').read_text(encoding='utf-8')
    text=text.replace('namespace n=reo::native::audio_banks;','namespace n=reo::native::audio_banks::v2;')
    text=text.replace('static const Bank empty;','static const Bank empty(n::acquire_asset(std::make_shared<n::Budget>(64u*1024u*1024u,128)));')
    first=text.index('    n::OwnedBankBytes bytes;');last=text.index('\n    if(asset.status==',first)
    text=text[:first]+'''    auto captured=session.capture(token,n::BankSizes{hn,bn,tn});
    if(captured.status==n::Status::invalid_asset)return false;
    check(captured.status);
    if(hn)std::copy_n(hd,hn,captured.value.hd().data());
    if(bn)std::copy_n(bd,bn,captured.value.bd().data());
    if(tn)std::copy_n(tq,tn,captured.value.tq().data());
    auto asset=session.prepare(token,std::move(captured.value));'''+text[last:]
    text=text.replace('inline n::Session session;','inline n::Session session;\ninline Bank makeProbeBank(){return Bank(n::acquire_asset(std::make_shared<n::Budget>(64u*1024u*1024u,128)));}')
    return text
def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve()
    if not cc or not out.is_relative_to(ROOT/'build-native-sjuni/audio-bank-budget-v2'):raise ValueError('Existing compiler/ignored budget-v2 output required')
    budget_verification.check_cohort()
    derived=derive()
    for name,text in derived.items():
        if (HERE/name).read_text(encoding='utf-8')!=text:raise ValueError('Allocator derivation drift '+name)
    for name,digest in baseline.PINNED.items():
        if sha(baseline.ORACLE/name)!=digest:raise ValueError('Original oracle identity changed: '+name)
    out.mkdir(parents=True,exist_ok=True)
    (out/'native_transport.hpp').write_text(transport(),encoding='utf-8',newline='\n')
    observer=(baseline.ORACLE/'harness.cpp').read_text(encoding='utf-8').replace('#include "source/ReoSoundBanks.cpp"','#include "native_transport.hpp"').replace('namespace s = ps2_reo_sound;','namespace s = native_transport;').replace('s::Bank b;','auto b=s::makeProbeBank();').replace('s::DecodedSample d;','s::DecodedSample d(b.allocation_lease());')
    observer=observer.replace('template<class T>void nums(std::ostream&o,const std::vector<T>&v)','template<class T,class A>void nums(std::ostream&o,const std::vector<T,A>&v)')
    harness=out/'transport.cpp';harness.write_text(observer,encoding='utf-8',newline='\n');exe=out/'transport.exe';actual=out/'actual.json'
    cmd=[cc,'-std=c++20','-O1','-ffp-contract=off','-fno-fast-math','-Wall','-Wextra','-Wpedantic','-Wno-misleading-indentation','-pthread','-I',str(HERE),str(harness),'-o',str(exe)]
    env=dict(os.environ);env['PATH']=str(Path(cc).resolve().parent)+os.pathsep+env.get('PATH','')
    identities={p.name:sha(p) for p in HERE.iterdir() if p.is_file() and (p.suffix in ('.cpp','.hpp','.py') or p.name=='cohort_identity.json')}
    receipt=dict(schema=2,status='running',original_expectations_previously_seen=True,historical_blind_baseline='384a0cb036a34ca3578376b036d143902332412a',source_oracle=baseline.PINNED,authored=identities,compiler=cc,compiler_sha256=sha(Path(cc)),command=cmd,game_run=False,device_opened=False)
    try:
        c=subprocess.run(cmd,capture_output=True,text=True,env=env,timeout=120);receipt['compile']=dict(exit_code=c.returncode,stderr=c.stderr)
        if c.returncode:raise RuntimeError(c.stderr)
        r=subprocess.run([str(exe),str(baseline.ORACLE/'input.bin'),str(actual)],capture_output=True,text=True,env=env,timeout=120);receipt['run']=dict(exit_code=r.returncode,stdout=r.stdout,stderr=r.stderr)
        if r.returncode:raise RuntimeError(r.stderr)
        expected=json.loads((baseline.ORACLE/'0/expected.json').read_text(encoding='utf-8'));observed=json.loads(actual.read_text(encoding='utf-8'));diff=list(baseline.differences(expected,observed))
        (out/'differences.json').write_text(json.dumps(diff,indent=2)+'\n',encoding='utf-8',newline='\n')
        receipt.update(status='different' if diff else 'passed',differences=len(diff),actual_sha256=sha(actual),cases=len(expected['cases']),actions=sum(len(c['actions']) for c in expected['cases']),float_words=sum(len(a['pcm_bits']) for c in expected['cases'] for a in c['actions']),gain_calls=sum(len(a['gain_calls']) for c in expected['cases'] for a in c['actions']))
        print(json.dumps({k:receipt[k] for k in ['status','differences','cases','actions','float_words','gain_calls']}))
        for d in diff[:10]:print(json.dumps(d))
    except Exception as error:receipt.update(status='failed',failure=str(error));raise
    finally:
        receipt['postcheck_changed']=[name for name,digest in identities.items() if sha(HERE/name)!=digest]
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    if diff or receipt['postcheck_changed']:raise SystemExit(1)
if __name__=='__main__':main()
