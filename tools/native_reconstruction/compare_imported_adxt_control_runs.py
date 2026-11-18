#!/usr/bin/env python3
"""Compare imported-player observations with both retained full run receipts."""
import argparse
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/imported-adxt-control'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('left','right','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();out=a.output.resolve()
    if out.exists()or not out.is_relative_to(BASE):raise ValueError('Fresh scoped comparison required')
    runs=[]
    for folder in (a.left,a.right):
        receipt=json.loads((folder/'receipt.json').read_bytes())
        if not receipt['status'].startswith('passed actual imported native hierarchy/owned media control session')or receipt['input_drift']or not receipt['source_stat_unchanged']or not receipt['manifest_unchanged']:raise ValueError('Failed or drifted input run')
        if receipt['original_iso_opened']or receipt['game_run']or receipt['device_opened']:raise ValueError('Unexpected runtime scope')
        for name,digest in receipt['outputs_sha256'].items():
            if sha(folder/name)!=digest:raise ValueError('Output drift')
        if sha(folder/'plan.txt')!=receipt['plan_sha256']or sha(folder/'cases.json')!=receipt['cases_sha256']:raise ValueError('Plan/input drift')
        runs.append((receipt,[json.loads(row)for row in (folder/'results.jsonl').read_text().splitlines()]))
    left,right=runs
    for name in ('import_manifest_sha256','inventory_receipt_sha256','plan_sha256','cases_sha256','sources','baseline_receipt_sha256'):
        if left[0][name]!=right[0][name]:raise ValueError('Different inputs '+name)
    # Poll/wait scheduling changes the number of real group visits. Retain it
    # explicitly; it is neither a device-frame count nor a payload discrepancy.
    session_variable={'group_dtx_scans','group_visits'};session_differences={}
    ls,rs=left[0]['shared_session'],right[0]['shared_session']
    if ls.keys()!=rs.keys():raise ValueError('Different shared session schemas')
    for session in (ls,rs):
        if session['group_dtx_scans']!=session['group_visits']*2:raise ValueError('Unpaired DTX/control visits')
    for name in ls:
        if name in session_variable:
            if any(not isinstance(v,int)or v<=0 for v in (ls[name],rs[name])):raise ValueError('Invalid paired group scans')
            if ls[name]!=rs[name]:session_differences[name]=dict(left=ls[name],right=rs[name])
        elif ls[name]!=rs[name]:raise ValueError('Shared session/fence mismatch '+name)
    if len(left[1])!=len(right[1])or len(left[1])!=8910:raise ValueError('Different or incomplete reference counts')
    variable={'copied_samples_including_padding','consumed_bytes_including_padding'}
    differences=[];compared=0
    for x,y in zip(left[1],right[1],strict=True):
        if x.keys()!=y.keys():raise ValueError('Different schemas')
        changed={k for k in x if x[k]!=y[k]}
        if changed-variable:raise ValueError('Payload/source/clock/fence difference '+x['member'])
        if x['decode_requested']:
            compared+=1
            if not x['joined']or not y['joined']or not x['stream_retired']or not y['stream_retired']or x['underrun_frames']or y['underrun_frames']or x['skipped_samples']or y['skipped_samples']:raise ValueError('Missing fence or starved model')
        if changed:differences.append(dict(member=x['member'],left={k:x[k]for k in sorted(variable)},right={k:y[k]for k in sorted(variable)}))
    if compared!=6706:raise ValueError('Incomplete finite corpus')
    out.mkdir(parents=True)
    result=dict(schema=1,status='exact imported control-session payload/source/clock/join observations match; group visit counts retained separately',references=len(left[1]),
                copied_payloads=compared,complete_run_observations_equal=not differences and not session_differences,complete_payload_rows_equal=not differences,session_observation_differences=session_differences,padding_observation_differences=differences,
                variable_fields=sorted(variable),game_run=False,device_opened=False,original_iso_opened=False,original_whole_player_parity=False,
                input_receipts={str(f):sha(f/'receipt.json')for f in (a.left,a.right)},comparator_sha256=sha(Path(__file__)))
    (out/'receipt.json').write_text(json.dumps(result,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(references=len(left[1]),payloads=compared,padding_differences=len(differences),receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
