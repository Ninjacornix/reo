#!/usr/bin/env python3
"""Actual import/native workers after a declared runtime port releases its RAM."""
import argparse,hashlib,json,os,shutil,struct,subprocess,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
BASE=ROOT/'build-native-sjuni/media-mount-handoff'
META=ROOT/'build-native-sjuni/audio-asset-inventory/file1-v1'
BASELINE=ROOT/'build-native-sjuni/adx-asset-streams/full-gcc-v1'
MANIFEST='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    p=argparse.ArgumentParser();p.add_argument('--compiler',type=Path,required=True);p.add_argument('--data',type=Path,required=True)
    p.add_argument('--native-receipt',type=Path,required=True);p.add_argument('--output',type=Path,required=True);a=p.parse_args();out=a.output.resolve()
    if out.exists() or not out.is_relative_to(BASE):raise ValueError('Fresh owned output required')
    manifest=ROOT/'tools/native_reconstruction/native_audio_submix_manifest_v4.json';sources=json.loads(manifest.read_bytes())['files'].copy()
    native=json.loads(a.native_receipt.read_bytes())
    if native['status']!='native media pipeline standalone build and tests passed' or native['manifest_sha256']!=sha(manifest) or native['compiler_sha256']!=sha(a.compiler):raise ValueError('Matching native cohort/compiler required')
    libraries={ROOT/n:d for n,d in native['libraries'].items()}
    tests=ROOT/'recomp/overrides/native_resource_reads/tests'
    fixture=Path(__file__).with_name('media_mount_handoff_check.cpp')
    for path in [Path(__file__),fixture,tests/'ps2_runtime.h',tests/'reo_hw_bridge.h',tests.parent/'runtime_adapter.cpp',tests.parent/'runtime_adapter.h',ROOT/'recomp/overrides/native_geometry/reo_vu_native_sha256.h']:
        sources[path.relative_to(ROOT).as_posix()]=sha(path)
    def verify():
        for name,digest in sources.items():
            if sha(ROOT/name)!=digest:raise ValueError('Source drift '+name)
        for path,digest in libraries.items():
            if sha(path)!=digest:raise ValueError('Archive drift '+str(path))
    verify()
    if sha(BASELINE/'receipt.json')!='15e362bc1da039f20f88c7353a6e35f34250718c6350c275f73cdf8bcd97486e':raise ValueError('Qualified PCM baseline drift')
    baseline=json.loads((BASELINE/'receipt.json').read_bytes())
    if sha(BASELINE/'results.jsonl')!=baseline['outputs_sha256']['results.jsonl']:raise ValueError('PCM results drift')
    expected={x['member']:x for x in map(json.loads,(BASELINE/'results.jsonl').read_text().splitlines())}
    inventory=json.loads((META/'receipt.json').read_bytes())
    for name in ['members.json','archives.json']:
        if sha(META/name)!=inventory['output_sha256'][name]:raise ValueError('Inventory drift')
    members=json.loads((META/'members.json').read_bytes());archives={x['member']:x for x in json.loads((META/'archives.json').read_bytes())}
    eligible=[x for x in members if x.get('recognition')=='adx_structural_header' and x['adx']['loop']['status']!='fields_read' and x['adx']['frequency']==48000 and 4096<=x['adx']['total_samples']<=250000]
    selected=[next(x for x in eligible if x['adx']['channels']==channels)for channels in (1,2)]
    data=a.data.resolve();imported=data.parent/'import.json'
    if sha(imported)!=MANIFEST:raise ValueError('Installed import manifest differs')
    entries=json.loads(imported.read_bytes())['Files'];before={x['Name']:(data/x['Name']).stat()for x in entries};manifest_stat=imported.stat()
    out.mkdir(parents=True);(out/'include').mkdir()
    for name in ['ps2_runtime.h','reo_hw_bridge.h']:shutil.copyfile(tests/name,out/'include'/name)
    lines=[]
    for row in selected:
        parts=row['member'].split('/');root=archives[parts[0]];indices=list(map(int,parts[1:]));adx=row['adx']
        lines.append(' '.join(map(str,[row['member'],root['member'],root['sha256'],root['bytes'],row['iso_offset']-root['iso_offset'],len(indices),*indices,row['bytes'],adx['channels'],adx['frequency'],adx['total_samples']])))
    (out/'plan.txt').write_text('\n'.join(lines)+'\n',encoding='utf-8',newline='\n')
    sys.path.insert(0,str(ROOT/'tools/function_index'));from index import Elf
    elf=Elf(ROOT/'game_data/SLUS_207.65')
    if elf.sha256!='06bd5fd7243144cd30cdd0c0023763a369738cb91b177b35e85f6a4782b4ca46':raise ValueError('Owned ELF differs')
    (out/'identity.bin').write_bytes(b''.join(struct.pack('<II',pc,size)+elf.read(pc,size) for pc,size in [(0x101788,0x1e0),(0x1004d8,0xb8),(0x100298,0xa0)]))
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    record=dict(schema=1,status='failed',compiler_sha256=sha(a.compiler),manifest_sha256=sha(manifest),native_receipt_sha256=sha(a.native_receipt),sources=sources,
        qualified_native_pcm_baseline_sha256=sha(BASELINE/'receipt.json'),inventory_sha256=sha(META/'receipt.json'),elf_sha256=elf.sha256,game_run=False,device_opened=False,
        original_scheduler_executed=False,runtime_lifecycle='declared mock with actual adapter and native imported-file providers',checks=[])
    def run(name,command):
        result=subprocess.run(list(map(str,command)),capture_output=True,text=True,env=env,timeout=180)
        (out/(name+'.txt')).write_text(result.stdout+result.stderr,encoding='utf-8',newline='\n');record['checks'].append(dict(name=name,exit=result.returncode,command=list(map(str,command))))
        if result.returncode:raise ValueError(name+' failed; see retained log')
        print(name+': passed',flush=True)
    try:
        binary=out/'handoff.exe'
        flags=[a.compiler,'-std=c++20','-O1','-fno-fast-math','-ffp-contract=off','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-pthread','-DREO_GAME_FILE1=1','-DREO_BUILD_NATIVE_RESOURCE_READS=1','-I'+str(out/'include'),'-I'+str(ROOT)]
        run('compile',flags+[fixture,tests.parent/'runtime_adapter.cpp','-Wl,--start-group',*libraries,'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject','-o',binary])
        run('actual-import-workers',[binary,data,out/'identity.bin',out/'plan.txt',out/'result.json'])
        result=json.loads((out/'result.json').read_bytes())
        if result['manifest_sha256']!=MANIFEST or not result['private_fenced'] or result['provider_joined'] or result['underrun_frames'] or not result['runtime_destroyed_before_source_start'] or not result['mount_released_before_service']:raise ValueError('Missing lifetime/output evidence')
        if len(result['members'])!=len(selected):raise ValueError('Missing actual sources')
        for actual,planned in zip(result['members'],selected):
            prior=expected[planned['member']]
            if actual['member']!=planned['member'] or any(actual[n]!=prior[n]for n in ['source_bytes','samples','byte_digest']):raise ValueError('Actual source/PCM differs from qualified baseline')
        verify();record.update(status='actual imported native sources survive declared runtime/mount handoff and match qualified PCM baseline',members=result['members'],binary_sha256=sha(binary))
    finally:
        after={x['Name']:(data/x['Name']).stat()for x in entries}
        record['source_stats_unchanged']=all((s.st_size,s.st_mtime_ns,s.st_ino)==(after[n].st_size,after[n].st_mtime_ns,after[n].st_ino)for n,s in before.items())
        record['import_manifest_unchanged']=sha(imported)==MANIFEST and imported.stat().st_mtime_ns==manifest_stat.st_mtime_ns
        if not record['source_stats_unchanged']or not record['import_manifest_unchanged']:record['status']='failed input drift'
        record['outputs_sha256']={x.name:sha(x)for x in out.iterdir()if x.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf-8',newline='\n')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))
if __name__=='__main__':main()
