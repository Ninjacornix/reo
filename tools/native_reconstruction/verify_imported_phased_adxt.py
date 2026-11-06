#!/usr/bin/env python3
"""Verified actual import -> native AFS hierarchy -> clocked player, no ISO open."""
import argparse
import hashlib
import json
import os
from pathlib import Path
import shutil
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/imported-phased-adxt'
META=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
MANIFEST_SHA='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--data-root',type=Path,required=True)
    p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--limit',type=int)
    a=p.parse_args();cc=shutil.which(a.cxx);out=a.output.resolve();data_root=a.data_root.resolve();manifest_path=data_root.parent/'import.json'
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    if a.limit is not None and a.limit<1:raise ValueError('Positive explicit probe limit required')
    files={}
    for folder in ['game/native/afs_hierarchy','game/native/adxt_phased_player']:
        identity=json.loads((ROOT/folder/'manifest.json').read_bytes())
        for name,digest in identity['files'].items():
            if sha(ROOT/name)!=digest:raise ValueError('Frozen source drift '+name)
            files[name]=digest
    baseline=ROOT/'build-native-sjuni/adx-asset-streams/full-gcc-v1'
    if sha(baseline/'receipt.json')!='15e362bc1da039f20f88c7353a6e35f34250718c6350c275f73cdf8bcd97486e':raise ValueError('Qualified finite asset baseline changed')
    prior=json.loads((baseline/'receipt.json').read_bytes())
    if sha(baseline/'results.jsonl')!=prior['outputs_sha256']['results.jsonl']:raise ValueError('Baseline PCM result drift')
    expected={r['member']:r for r in map(json.loads,(baseline/'results.jsonl').read_text().splitlines())}
    proof=json.loads((META/'receipt.json').read_bytes())
    for name in ['members.json','archives.json']:
        if sha(META/name)!=proof['output_sha256'][name]:raise ValueError('Inventory drift')
    members=[x for x in json.loads((META/'members.json').read_bytes())if x['recognition']=='adx_structural_header']
    archives={x['member']:x for x in json.loads((META/'archives.json').read_bytes())}
    roots={r['member']:r for r in archives.values()if '/'not in r['member']}
    selected=members[:a.limit]if a.limit is not None else members
    seen=set();plan=[];descriptors=[]
    for row in selected:
        pieces=row['member'].split('/');root=roots[pieces[0]];indices=[int(x)for x in pieces[1:]];meta=row['adx']
        loop=meta['loop']['status']=='fields_read'
        decode=not loop and row['sha256']not in seen
        if decode:seen.add(row['sha256'])
        plan.append(' '.join(str(x)for x in [row['member'],root['member'],root['sha256'],root['bytes'],row['iso_offset']-root['iso_offset'],len(indices),*indices,row['bytes'],meta['channels'],meta['frequency'],meta['total_samples'],int(decode)]))
        descriptors.append(dict(member=row['member'],payload_sha256=row['sha256'],decoded=decode,
                                loop_metadata=loop,total_samples=meta['total_samples'],channels=meta['channels']))
    out.mkdir(parents=True);(out/'plan.txt').write_text('\n'.join(plan)+'\n',encoding='utf-8',newline='\n')
    (out/'cases.json').write_text(json.dumps(descriptors,indent=2)+'\n',encoding='utf-8',newline='\n')
    fixture=Path(__file__).with_name('imported_phased_adxt_check.cpp');files[fixture.relative_to(ROOT).as_posix()]=sha(fixture)
    for name in ['game/native/adxt_refill/adxt_refill.cpp','game/native/tasks/serial_worker.cpp','game/native/resource_io/async_read_owner.cpp',
                 'game/native/resources/resource_session.cpp','game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp']:
        files[name]=sha(ROOT/name)
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),sources=files,
                 verifier_sha256=sha(Path(__file__)),plan_sha256=sha(out/'plan.txt'),cases_sha256=sha(out/'cases.json'),
                 inventory_receipt_sha256=sha(META/'receipt.json'),game_run=False,device_opened=False,
                 scope='actual verified import/retained parent AFS/globally phased player/live raw clock/model output; no ISO, game, real device, original scheduler or performance claim',original_iso_opened=False,data_root=str(data_root),checks=[])
    if sha(manifest_path)!=MANIFEST_SHA:raise ValueError('Different installed import manifest')
    imported=json.loads(manifest_path.read_bytes())
    for n in ['game/native/resources_windows/mounted_resources.cpp','game/native/resources_windows/import_manifest.cpp','game/native/resources_windows/pinned_file.cpp']:
        files[n]=sha(ROOT/n)
    before={r['Name']:(data_root/r['Name']).stat()for r in imported['Files']}
    manifest_before=manifest_path.stat();env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    try:
        receipt['import_manifest_sha256']=sha(manifest_path)
        sources=['game/native/sjrb/sjrb.cpp','game/native/adxt_shared_source/shared_source.cpp','game/native/adxt_refill/adxt_refill.cpp',
                 'game/native/resource_io/async_read_owner.cpp','game/native/tasks/serial_worker.cpp','game/native/resources/resource_session.cpp',
                 'game/native/resources/virtual_file_view.cpp','game/native/resources/bounded_view.cpp','game/native/adx_header/adx_header.cpp',
                 'game/native/adx_workspace/adx_workspace.cpp','game/native/adx_pcm_store/v2/pcm_store.cpp','game/native/adx_window/v2/playback_r2/stream_window.cpp',
                 'game/native/adxt_playback/playback.cpp','game/native/adxt_phased_player/player.cpp','game/native/adxt_estimated_clock/estimated_clock.cpp','game/native/adxt_integer_clock/integer_clock.cpp','game/native/adxt_service_group/service_group.cpp','game/native/adxt_transfer_groups/transfer_groups.cpp','game/native/adxt_output_session/session.cpp','game/native/pcm/pcm.cpp','game/native/audio_output/audio_output_owner.cpp',
                 'game/native/afs_source_range/afs_source_range.cpp','game/native/afs_hierarchy/hierarchy.cpp','game/native/resources_windows/mounted_resources.cpp','game/native/resources_windows/import_manifest.cpp','game/native/resources_windows/pinned_file.cpp',str(fixture)]
        binary=out/'asset_streams.exe';command=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation',
                '-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT),*sources,'-lruntimeobject','-lole32','-lbcrypt','-o',str(binary)]
        built=subprocess.run(command,cwd=ROOT,env=env,text=True,capture_output=True,timeout=90)
        (out/'compile.txt').write_text(built.stdout+built.stderr,encoding='utf-8',newline='\n');receipt['checks'].append(dict(name='compile',command=command,exit=built.returncode))
        if built.returncode:raise RuntimeError(built.stderr)
        receipt['executable_sha256']=sha(binary);started=time.monotonic()
        command=[str(binary),str(data_root),str(out/'plan.txt'),str(out/'results.jsonl')]
        with (out/'run.txt').open('w',encoding='utf-8',newline='\n')as log:
            process=subprocess.Popen(command,cwd=ROOT,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
            for line in process.stdout:log.write(line);log.flush();print(line.rstrip(),flush=True)
            code=process.wait()
        receipt['checks'].append(dict(name='actual_player_assets',command=command,exit=code,elapsed_seconds=time.monotonic()-started))
        if code:raise RuntimeError('Actual asset graph failed; retained results identify first case')
        rows=[json.loads(line)for line in (out/'results.jsonl').read_text().splitlines()]
        if len(rows)!=len(selected)or any(row['status']!='passed'for row in rows):raise ValueError('Incomplete actual asset run')
        compared=0
        for row in rows:
            prior=expected[row['member']]
            if row['source_bytes']!=prior['source_bytes']:raise ValueError('Actual source extent changed')
            if row['decode_requested']:
                if row['samples']!=prior['samples']or row['byte_digest']!=prior['byte_digest']:raise ValueError('Copied actual PCM prefix differs: '+row['member'])
                if not row['stream_retired']or row['underrun_frames']or row['skipped_samples']:raise ValueError('Model output starvation/fence failure')
                compared+=1
        session=json.loads((out/'session.json').read_bytes())
        if any(session.get(n)!=v for n,v in dict(import_version=1,routes=85,manifest_sha256=MANIFEST_SHA,provider_joined=True,occupied=0,detach=1,stop=1,unload=1).items()):raise ValueError('Actual mount/shared provider summary differs')
        receipt.update(status='passed actual imported native hierarchy/globally phased player and independent native PCM prefix baseline',shared_session=session,baseline_receipt_sha256=sha(baseline/'receipt.json'),prefix_comparisons=compared,references=len(rows),decoded_unique_payloads=sum(d['decoded']for d in descriptors),
                       loop_references_not_decoded=sum(d['loop_metadata']for d in descriptors),
                       decoded_samples_per_channel_sum=sum(d['total_samples']for d in descriptors if d['decoded']),
                       outputs_sha256={n:sha(out/n)for n in ['results.jsonl','run.txt','session.json']})
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        after={r['Name']:(data_root/r['Name']).stat()for r in imported['Files']}
        receipt['source_stat_unchanged']=all((v.st_size,v.st_mtime_ns,v.st_ino)==(after[n].st_size,after[n].st_mtime_ns,after[n].st_ino)for n,v in before.items())
        receipt['manifest_unchanged']=sha(manifest_path)==MANIFEST_SHA and manifest_path.stat().st_mtime_ns==manifest_before.st_mtime_ns
        receipt['input_drift']=[n for n,d in files.items()if sha(ROOT/n)!=d]
        if not receipt['source_stat_unchanged']or not receipt['manifest_unchanged']or receipt['input_drift']:receipt.update(status='failed',failure='Input drift')
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],references=receipt['references'],decoded=receipt['decoded_unique_payloads'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
