#!/usr/bin/env python3
"""Compare complete loop cycles; retain timing-dependent stop-prefix observations."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/adx-loop-asset-streams'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--left',type=Path,required=True);p.add_argument('--right',type=Path,required=True);p.add_argument('--output',type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped output required')
    rows=[];proofs=[]
    for folder in (a.left,a.right):
        proof=json.loads((folder/'receipt.json').read_bytes())
        if not proof['status'].startswith('passed')or proof['input_drift']or not proof['source_stat_unchanged']:raise ValueError('Incomplete or drifted loop run')
        if sha(folder/'results.jsonl')!=proof['outputs_sha256']['results.jsonl']:raise ValueError('Raw observation drift')
        if sha(folder/'cases.json')!=proof['cases_sha256']:raise ValueError('Input selection drift')
        cases=json.loads((folder/'cases.json').read_bytes());observations=[json.loads(line)for line in(folder/'results.jsonl').read_text().splitlines()]
        if len(cases)!=len(observations):raise ValueError('Incomplete case observations')
        for case,row in zip(cases,observations,strict=True):
            if case['member']!=row['member']or row['status']!='passed':raise ValueError('Different or failed case')
            if case['decoded']:
                if not row['joined']or row['loop_iterations']!=2:raise ValueError('Missing loop boundary/fence')
                for ch in range(case['channels']):
                    if row['cycle_samples'][0][ch]!=row['loop_span']or row['cycle_samples'][1][ch]!=row['loop_span']or row['cycle_digest'][0][ch]!=row['cycle_digest'][1][ch]:raise ValueError('Cycle inconsistency')
        rows.append(observations);proofs.append(proof)
    if proofs[0]['plan_sha256']!=proofs[1]['plan_sha256']or proofs[0]['sources']!=proofs[1]['sources']:raise ValueError('Different native inputs')
    compared=[];prefix_differences=[]
    for left,right in zip(*rows,strict=True):
        # These two complete-stream observations include intro plus any third
        # cycle prefix from the service call which reports iteration2. Preserve
        # both values; compare every remaining field without broad filtering.
        project=lambda row:{k:v for k,v in row.items()if k not in('samples','byte_digest')}
        if project(left)!=project(right):raise ValueError('Stable cycle/source/fence difference '+left['member'])
        compared.append(project(left))
        if left.get('samples')!=right.get('samples')or left.get('byte_digest')!=right.get('byte_digest'):
            prefix_differences.append(dict(member=left['member'],left_samples=left.get('samples'),right_samples=right.get('samples'),
                                           left_digest=left.get('byte_digest'),right_digest=right.get('byte_digest')))
    out.mkdir(parents=True)
    report=dict(schema=1,status='passed complete-cycle comparison; full stop-prefix observations retained',references=len(compared),decoded_unique=proofs[0]['decoded_unique_payloads'],
                receipts={str(folder):sha(folder/'receipt.json')for folder in(a.left,a.right)},
                stable_projection_sha256=hashlib.sha256(json.dumps(compared,sort_keys=True,separators=(',',':')).encode()).hexdigest(),
                stop_prefix_differences=prefix_differences,full_run_byte_equality=False,game_run=False,device_opened=False)
    (out/'receipt.json').write_text(json.dumps(report,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=report['status'],references=report['references'],prefix_differences=len(prefix_differences),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
