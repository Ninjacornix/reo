#!/usr/bin/env python3
"""Actual imported finite clips through prepared seamless owners; no ISO/device."""
import argparse
import hashlib
import importlib.util
import json
import os
from pathlib import Path
import shutil
import subprocess
import time

ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/imported-adxt-sequences'
META=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
MANIFEST_SHA='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__);p.add_argument('--data-root',type=Path,required=True);p.add_argument('--cxx',required=True);p.add_argument('--output',type=Path,required=True);p.add_argument('--limit',type=int);a=p.parse_args()
    cc=shutil.which(a.cxx);out=a.output.resolve();data_root=a.data_root.resolve();manifest_path=data_root.parent/'import.json'
    if not cc or out.exists()or not out.is_relative_to(BASE):raise ValueError('Exact compiler and fresh scoped output required')
    if a.limit is not None and a.limit<2:raise ValueError('Explicit probe requires at least two payloads')
    frozen=json.loads((ROOT/'game/native/adx_sequence/manifest.json').read_bytes());files=frozen['files']
    def drift():return[n for n,d in files.items()if sha(ROOT/n)!=d]
    if drift():raise ValueError('Frozen input drift '+str(drift()))
    baseline=ROOT/'build-native-sjuni/adx-asset-streams/full-gcc-v1'
    if sha(baseline/'receipt.json')!='15e362bc1da039f20f88c7353a6e35f34250718c6350c275f73cdf8bcd97486e':raise ValueError('Finite decoder baseline changed')
    b=json.loads((baseline/'receipt.json').read_bytes())
    if sha(baseline/'results.jsonl')!=b['outputs_sha256']['results.jsonl']:raise ValueError('Baseline PCM drift')
    expected={r['member']:r for r in map(json.loads,(baseline/'results.jsonl').read_text(encoding='utf-8').splitlines())}
    proof=json.loads((META/'receipt.json').read_bytes())
    for n in ['members.json','archives.json']:
        if sha(META/n)!=proof['output_sha256'][n]:raise ValueError('Owned inventory drift')
    seen=set();selected=[]
    for row in json.loads((META/'members.json').read_bytes()):
        if row['recognition']!='adx_structural_header'or row['adx']['loop']['status']=='fields_read'or row['sha256']in seen:continue
        seen.add(row['sha256']);selected.append(row)
    selected=selected[:a.limit]if a.limit is not None else selected
    categories={}
    for row in selected:categories.setdefault((row['adx']['channels'],row['adx']['frequency']),[]).append(row)
    groups=[]
    for key,pool in sorted(categories.items()):
        at=0
        while at<len(pool):
            take=min(16,len(pool)-at)
            if len(pool)-at-take==1:take-=1
            group=pool[at:at+take];at+=take
            if len(group)==1:group=group*2
            groups.append(group)
    archives=json.loads((META/'archives.json').read_bytes());roots={r['member']:r for r in archives if '/'not in r['member']}
    plan=[];descriptors=[]
    for i,group in enumerate(groups):
        identity='sequence-'+str(i);plan.append(identity+' '+str(len(group)))
        for row in group:
            pieces=row['member'].split('/');root=roots[pieces[0]];indices=[int(x)for x in pieces[1:]];h=row['adx']
            plan.append(' '.join(map(str,[row['member'],root['member'],root['sha256'],root['bytes'],row['iso_offset']-root['iso_offset'],len(indices),*indices,row['bytes'],h['channels'],h['frequency'],h['total_samples']])))
            descriptors.append(dict(sequence=identity,member=row['member'],payload_sha256=row['sha256'],channels=h['channels'],frequency=h['frequency'],samples=h['total_samples']))
    if sha(manifest_path)!=MANIFEST_SHA:raise ValueError('Different installed import manifest')
    imported=json.loads(manifest_path.read_bytes());before={r['Name']:(data_root/r['Name']).stat()for r in imported['Files']};manifest_before=manifest_path.stat()
    out.mkdir(parents=True);(out/'plan.txt').write_text('\n'.join(plan)+'\n',encoding='utf-8',newline='\n');(out/'cases.json').write_text(json.dumps(descriptors,indent=2)+'\n',encoding='utf-8',newline='\n')
    env=dict(os.environ);env['PATH']=str(Path(cc).parent)+os.pathsep+env.get('PATH','')
    receipt=dict(schema=1,status='running',compiler=cc,compiler_sha256=sha(Path(cc)),sources=files,manifest_sha256=sha(ROOT/'game/native/adx_sequence/manifest.json'),verifier_sha256=sha(Path(__file__)),plan_sha256=sha(out/'plan.txt'),cases_sha256=sha(out/'cases.json'),import_manifest_sha256=MANIFEST_SHA,inventory_receipt_sha256=sha(META/'receipt.json'),baseline_receipt_sha256=sha(baseline/'receipt.json'),data_root=str(data_root),original_iso_opened=False,game_run=False,device_opened=False,original_whole_player_parity=False,checks=[])
    try:
        helper=ROOT/'game/native/adxt_control_session/verify.py';spec=importlib.util.spec_from_file_location('native_control_dependencies',helper);module=importlib.util.module_from_spec(spec);spec.loader.exec_module(module)
        sources=[str(ROOT/'game/native'/n)for n in module.SOURCES]+[str(ROOT/n)for n in ['game/native/adxt_control_session/control_session.cpp','game/native/resources/bounded_view.cpp','game/native/afs_source_range/afs_source_range.cpp','game/native/afs_hierarchy/hierarchy.cpp','game/native/resources_windows/mounted_resources.cpp','game/native/resources_windows/import_manifest.cpp','game/native/resources_windows/pinned_file.cpp']]
        sources=list(dict.fromkeys(sources))
        original=(ROOT/'game/native/adxt_phased_player/player.cpp').read_text(encoding='utf-8');anchor='if(output->copy(spans[0],spans[1])!=output::Status::completed)return fail();'
        if original.count(anchor)!=1:raise ValueError('Accepted-copy source drift')
        declaration='void test_after_accepted_sequence_copy(std::span<const std::byte>,std::span<const std::byte>,const reo::native::adx_window::v2::Snapshot&) noexcept;\n'
        derived=original.replace('namespace reo::native::adxt_phased_player {',declaration+'namespace reo::native::adxt_phased_player {',1).replace(anchor,anchor+'\n            ::test_after_accepted_sequence_copy(spans[0],spans[1],before);')
        instrumented=out/'accepted_copy_player.cpp';instrumented.write_text(derived,encoding='utf-8',newline='\n');receipt['observer_source_sha256']=sha(instrumented)
        sources[sources.index(str(ROOT/'game/native/adxt_phased_player/player.cpp'))]=str(instrumented);fixture=Path(__file__).with_name('imported_adxt_sequence_check.cpp');sources.append(str(fixture))
        binary=out/'sequences.exe';command=[cc,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-frounding-math','-I'+str(ROOT),'-I'+str(ROOT/'game/native/adxt_phased_player'),*sources,'-lruntimeobject','-lole32','-lbcrypt','-o',str(binary)]
        built=subprocess.run(command,cwd=ROOT,env=env,text=True,capture_output=True,timeout=90);(out/'compile.txt').write_text(built.stdout+built.stderr,encoding='utf-8',newline='\n');receipt['checks'].append(dict(name='compile',command=command,exit=built.returncode))
        if built.returncode:raise RuntimeError(built.stderr)
        receipt['executable_sha256']=sha(binary);command=[str(binary),str(data_root),str(out/'plan.txt'),str(out/'results.jsonl')];start=time.monotonic()
        with (out/'run.txt').open('w',encoding='utf-8',newline='\n')as log:
            process=subprocess.Popen(command,cwd=ROOT,env=env,text=True,stdout=subprocess.PIPE,stderr=subprocess.STDOUT)
            for line in process.stdout:log.write(line);log.flush();print(line.rstrip(),flush=True)
            code=process.wait()
        receipt['checks'].append(dict(name='actual_imported_sequences',command=command,exit=code,elapsed_seconds=time.monotonic()-start))
        if code:raise ValueError('Actual sequence failed; retained group report identifies boundary')
        rows=[json.loads(line)for line in (out/'results.jsonl').read_text(encoding='utf-8').splitlines()];observations=[json.loads(line)for line in (out/'groups.jsonl').read_text(encoding='utf-8').splitlines()]
        if len(rows)!=len(descriptors)or len(observations)!=len(groups):raise ValueError('Incomplete accepted-copy run')
        for row,description in zip(rows,descriptors,strict=True):
            prior=expected[row['member']]
            if row['member']!=description['member']or row['sequence']!=description['sequence']or row['status']!='passed'or not row['source_joined']or not row['stream_retired']:raise ValueError('Source/sequence/fence difference')
            if any(row[n]!=prior[n]for n in ['source_bytes','samples','byte_digest']):raise ValueError('Complete accepted clip PCM differs '+row['member'])
        if any(r['status']!='passed'or r['underrun_frames']or r['skipped_samples']or not r['source_joined']or not r['stream_retired']for r in observations):raise ValueError('Starved or unfenced sequence')
        summary=json.loads((out/'session.json').read_bytes())
        if any(summary.get(n)!=v for n,v in dict(import_version=1,routes=85,manifest_sha256=MANIFEST_SHA,groups=len(groups),references=len(rows),provider_joined=True,occupied=0,detach=1,stop=1,unload=1).items())or summary['group_dtx_scans']!=2*summary['group_visits']:raise ValueError('Shared provider/group result differs')
        receipt.update(status='passed actual imported immutable seamless sequences and independent per-clip PCM baseline',groups=len(groups),clip_copies=len(rows),unique_payloads=len(selected),complete_channel_samples=sum(d['samples']*d['channels']for d in descriptors),shared_session=summary,outputs_sha256={n:sha(out/n)for n in ['results.jsonl','groups.jsonl','session.json','run.txt']})
    except Exception as e:receipt.update(status='failed',failure=str(e));raise
    finally:
        after={r['Name']:(data_root/r['Name']).stat()for r in imported['Files']};receipt['source_stat_unchanged']=all((v.st_size,v.st_mtime_ns,v.st_ino)==(after[n].st_size,after[n].st_mtime_ns,after[n].st_ino)for n,v in before.items());receipt['manifest_unchanged']=sha(manifest_path)==MANIFEST_SHA and manifest_path.stat().st_mtime_ns==manifest_before.st_mtime_ns;receipt['input_drift']=drift()
        if not receipt['source_stat_unchanged']or not receipt['manifest_unchanged']or receipt['input_drift']:receipt.update(status='failed',failure='Input drift')
        (out/'receipt.json').write_text(json.dumps(receipt,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=receipt['status'],groups=receipt['groups'],payloads=receipt['unique_payloads'],receipt_sha256=sha(out/'receipt.json'))))

if __name__=='__main__':main()
