#!/usr/bin/env python3
"""Compare complete seamless clip copies and retain scheduling/padding evidence."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2];BASE=ROOT/'build-native-sjuni/imported-adxt-sequences'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for n in ['left','right','output']:p.add_argument('--'+n,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped comparison required')
    runs=[]
    for folder in [a.left,a.right]:
        receipt=json.loads((folder/'receipt.json').read_bytes())
        if not receipt['status'].startswith('passed actual imported immutable seamless')or receipt['input_drift']or not receipt['source_stat_unchanged']or not receipt['manifest_unchanged']:raise ValueError('Failed or drifted input')
        if receipt['game_run']or receipt['device_opened']or receipt['original_iso_opened']:raise ValueError('Unexpected scope')
        for n,d in receipt['outputs_sha256'].items():
            if sha(folder/n)!=d:raise ValueError('Retained output drift')
        if sha(folder/'plan.txt')!=receipt['plan_sha256']or sha(folder/'cases.json')!=receipt['cases_sha256']:raise ValueError('Plan drift')
        rows=[json.loads(line)for line in (folder/'results.jsonl').read_text(encoding='utf-8').splitlines()]
        groups=[json.loads(line)for line in (folder/'groups.jsonl').read_text(encoding='utf-8').splitlines()]
        runs.append((receipt,rows,groups))
    left,right=runs
    for n in ['sources','manifest_sha256','plan_sha256','cases_sha256','import_manifest_sha256','inventory_receipt_sha256','baseline_receipt_sha256']:
        if left[0][n]!=right[0][n]:raise ValueError('Different inputs '+n)
    if left[0]['unique_payloads']!=6706 or right[0]['unique_payloads']!=6706 or left[1]!=right[1]:raise ValueError('Incomplete or different complete clip payloads/fences')
    if len(left[2])!=len(right[2])or len(left[2])!=421:raise ValueError('Incomplete group observations')
    variable={'copied_samples_including_padding','consumed_bytes_including_padding'};differences=[]
    for x,y in zip(left[2],right[2],strict=True):
        if x.keys()!=y.keys():raise ValueError('Group schema difference')
        changed={n for n in x if x[n]!=y[n]}
        if changed-variable:raise ValueError('Group source/clock/fence difference '+x['sequence'])
        if changed:differences.append(dict(sequence=x['sequence'],left={n:x[n]for n in variable},right={n:y[n]for n in variable}))
    ls,rs=left[0]['shared_session'],right[0]['shared_session'];session_differences={}
    if ls.keys()!=rs.keys():raise ValueError('Session schema difference')
    for session in [ls,rs]:
        if session['group_dtx_scans']!=2*session['group_visits']:raise ValueError('Unpaired transfer/control scans')
    for n in ls:
        if n not in ['group_dtx_scans','group_visits']and ls[n]!=rs[n]:raise ValueError('Provider/identity/fence difference')
        if ls[n]!=rs[n]:session_differences[n]=dict(left=ls[n],right=rs[n])
    out.mkdir(parents=True)
    result=dict(schema=1,status='complete imported seamless clip/source/clock/fence observations match; padding/scheduling retained separately',unique_payloads=6706,sequences=421,clip_copies=len(left[1]),complete_payload_rows_equal=True,padding_observation_differences=differences,session_observation_differences=session_differences,input_receipts={str(f):sha(f/'receipt.json')for f in [a.left,a.right]},comparator_sha256=sha(Path(__file__)),game_run=False,device_opened=False,original_iso_opened=False,original_whole_player_parity=False)
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(payloads=6706,sequences=421,padding_differences=len(differences),receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
