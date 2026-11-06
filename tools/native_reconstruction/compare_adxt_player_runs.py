#!/usr/bin/env python3
"""Compare exact copied payloads while retaining every padding observation."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/adxt-player-assets'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--left',type=Path,required=True)
    p.add_argument('--right',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args()
    out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped comparison required')
    runs=[]
    for folder in (a.left,a.right):
        receipt=json.loads((folder/'receipt.json').read_bytes())
        if not receipt['status'].startswith('passed actual native player')or receipt['input_drift']or not receipt['source_stat_unchanged']:raise ValueError('Failed or drifted input run')
        for name,digest in receipt['outputs_sha256'].items():
            if sha(folder/name)!=digest:raise ValueError('Output drift')
        if sha(folder/'plan.txt')!=receipt['plan_sha256']or sha(folder/'cases.json')!=receipt['cases_sha256']:raise ValueError('Plan/input drift')
        runs.append((receipt,[json.loads(row)for row in (folder/'results.jsonl').read_text().splitlines()]))
    left,right=runs
    for n in ('iso_sha256','plan_sha256','cases_sha256','sources','baseline_receipt_sha256'):
        if left[0][n]!=right[0][n]:raise ValueError('Different comparison inputs '+n)
    if len(left[1])!=len(right[1]):raise ValueError('Different reference counts')
    variable={'copied_samples_including_padding','consumed_bytes_including_padding'}
    differences=[];compared=0
    for x,y in zip(left[1],right[1],strict=True):
        if x.keys()!=y.keys():raise ValueError('Different result schemas')
        changed={k for k in x if x[k]!=y[k]}
        if changed-variable:raise ValueError('Copied payload/source/fence difference '+x['member'])
        if x['decode_requested']:
            compared+=1
            if not x['joined']or not y['joined']or not x['model_provider_joined']or not y['model_provider_joined']or x['underrun_frames']or y['underrun_frames']or x['skipped_samples']or y['skipped_samples']:raise ValueError('Missing fence or starved model')
        if changed:differences.append(dict(member=x['member'],left={k:x[k]for k in sorted(variable)},right={k:y[k]for k in sorted(variable)}))
    out.mkdir(parents=True)
    result=dict(schema=1,status='exact copied payload/source/join observations match',references=len(left[1]),
                copied_payloads=compared,complete_run_observations_equal=not differences,padding_observation_differences=differences,
                variable_fields=sorted(variable),game_run=False,device_opened=False,original_whole_player_parity=False,
                input_receipts={str(f):sha(f/'receipt.json')for f in (a.left,a.right)},comparator_sha256=sha(Path(__file__)))
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(references=len(left[1]),payloads=compared,padding_differences=len(differences),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
