"""Focused actual ordinary-adapter/native queue-feeder callback checks.

Reuses an identified passing native-80 archive cohort and independently
qualified fixture inputs. No native library rebuild, game or device launch.
"""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
HERE=ROOT/'recomp/overrides/native_adxt'
PORTS=ROOT/'build-native-sjuni/audio-media-factory/prepared-llvm-v1/snapshot'


def sha(path):
    with path.open('rb') as stream:return hashlib.file_digest(stream,'sha256').hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','native-receipt','manifest','baseline-fixture','data','output'):
        p.add_argument('--'+name,type=Path,required=True)
    p.add_argument('--detect-missing-feeder',action='store_true')
    a=p.parse_args();out=a.output.resolve();baseline=a.baseline_fixture.resolve()
    assert not out.exists() and out.is_relative_to(ROOT/'build-native-sjuni/adxt-binding')
    native=json.loads(a.native_receipt.read_bytes());manifest=json.loads(a.manifest.read_bytes())
    base=json.loads((baseline/'receipt.json').read_bytes())
    assert native['status']=='native media pipeline standalone build and tests passed'
    assert native['compiler_sha256']==sha(a.compiler) and native['manifest_sha256']==sha(a.manifest)
    assert base['status']=='ordinary game ABI declared-port checks passed'
    assert base['native_receipt_sha256']==sha(a.native_receipt) and base['native_manifest_sha256']==sha(a.manifest)
    for relative,digest in native['libraries'].items():assert sha(ROOT/relative)==digest
    unlinked_source_drift={}
    for relative,digest in manifest['files'].items():
        if relative.startswith('game/native/') and sha(ROOT/relative)!=digest:
            # V36 adds a private movie fault; this focused ordinary-audio test
            # excludes that entire archive rather than linking stale movie code.
            assert relative=='game/native/host_movie/session.cpp'
            assert digest=='5b4d5b6dc4d0808cd4c98ace8d49d3ea700f0af48079f966f125e8ad8665eb70'
            assert sha(ROOT/relative)=='7df89065b4f0f62905639f0bf4cbc206ffa1c06e0c31a316feb8f756181393de'
            unlinked_source_drift[relative]=dict(archive_cohort_source_sha256=digest,current_sha256=sha(ROOT/relative))
    imported=a.data.resolve().parent/'import.json'
    assert sha(imported)=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
    identities={row['Name']:(a.data/row['Name']).stat() for row in json.loads(imported.read_bytes())['Files']}
    out.mkdir(parents=True)
    for name in ('plan.txt','qualified-image.bin','handle_fixture.hpp'):
        assert sha(baseline/name)==base['output_sha256'][name]
        shutil.copyfile(baseline/name,out/name)
    for name,target in [('ordinary_runtime.cpp','ordinary_runtime_body.cpp'),('ordinary_tests/tests.cpp','tests.cpp')]:
        shutil.copyfile(HERE/name,out/target)
    sources={str(path.relative_to(ROOT)).replace('\\','/'):sha(path) for path in [HERE/'ordinary_runtime.cpp',HERE/'ordinary_runtime.h',HERE/'ordinary_entries.inc',HERE/'game_handles.cpp',HERE/'game_handles.h',HERE/'source_profile.cpp',HERE/'source_profile.h',HERE/'ordinary_tests/tests.cpp',Path(__file__)]}
    env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    for key in ('REO_NATIVE_ADXT_TRACE_FILE','REO_NATIVE_MEDIA_BACKGROUND_TEST','REO_NATIVE_ADXT_TEST_CONTROL_STALL','REO_NATIVE_ADXT_TEST_DISABLE_SERVICE'):env.pop(key,None)
    record=dict(schema=1,status='failed',game_run=False,process_access=False,device_opened=False,
        actual_ordinary_adapter=True,actual_native_queue_and_metadata_workers=True,
        production_composite_worker_linked=False,callback_registration_port_declared=True,
        native_owner_admission_actual=True,native_manifest_sha256=sha(a.manifest),
        native_receipt_sha256=sha(a.native_receipt),baseline_fixture_receipt_sha256=sha(baseline/'receipt.json'),
        compiler_sha256=sha(a.compiler),source_snapshot_sha256=sources,checks=[])
    record['unlinked_source_drift']=unlinked_source_drift
    record['excluded_libraries']=[n for n in native['libraries'] if '/host_movie/' in n]
    def run(label,command,negative=False):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=100)
        (out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf8')
        record['checks'].append(dict(label=label,exit=result.returncode,negative=negative))
        if (result.returncode==0)==negative:raise ValueError(label+' unexpected result; retained log')
        print(label+': '+('fault detected' if negative else 'passed'),flush=True)
    flags=[a.compiler,'-std=c++20','-O2','-pthread','-Wall','-Wextra','-Wpedantic','-Werror','-Wno-misleading-indentation','-fno-fast-math','-ffp-contract=off','-DNOMINMAX','-DWIN32_LEAN_AND_MEAN','-DREO_GAME_FILE1','-DREO_BUILD_NATIVE_RESOURCE_READS=1','-I'+str(HERE/'ordinary_tests'),'-I'+str(out),'-I'+str(HERE),'-I'+str(PORTS),'-I'+str(ROOT)]
    link=['-Wl,--start-group',*[ROOT/n for n in native['libraries'] if n not in record['excluded_libraries']],'-Wl,--end-group','-lbcrypt','-lole32','-lruntimeobject']
    try:
        binary=out/'native-queue.exe'
        run('compile',flags+[HERE/'game_handles.cpp',HERE/'source_profile.cpp',out/'tests.cpp',*link,'-o',binary])
        for case in ('native_queue_feed','native_queue_destroy','native_queue_order'):
            run(case,[binary,out/'qualified-image.bin',a.data,out/'plan.txt',case])
        if a.detect_missing_feeder:
            text=(out/'ordinary_runtime_body.cpp').read_text();anchor='native_queues[record.handle.slot]=queue;'
            assert text.count(anchor)==1
            changed=out/'missing-feeder-body.cpp';changed.write_text(text.replace(anchor,'(void)queue;'),encoding='utf8')
            test=out/'missing-feeder-tests.cpp';test.write_text((out/'tests.cpp').read_text().replace('#include "ordinary_runtime_body.cpp"','#include "missing-feeder-body.cpp"'),encoding='utf8')
            bad=out/'missing-feeder.exe'
            run('missing-feeder-compile',flags+[HERE/'game_handles.cpp',HERE/'source_profile.cpp',test,*link,'-o',bad])
            run('missing-feeder-detected',[bad,out/'qualified-image.bin',a.data,out/'plan.txt','native_queue_feed'],True)
        record['status']='actual ordinary adapter native queue feeder checks passed'
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['production_source_current_sha256']={name:sha(ROOT/name) for name in sources}
        record['compiled_adapter_snapshot_sha256']=sha(out/'ordinary_runtime_body.cpp')
        record['compiled_fixture_snapshot_sha256']=sha(out/'tests.cpp')
        record['source_stats_unchanged']=all((old.st_size,old.st_mtime_ns,old.st_ino)==((now:=(a.data/name).stat()).st_size,now.st_mtime_ns,now.st_ino) for name,old in identities.items())
        record['import_manifest_unchanged']=sha(imported)=='ae3668c7e98defe0eb16ce107490078451e9c2f57cb2fb87c162f37520f2600b'
        if not record['source_stats_unchanged'] or not record['import_manifest_unchanged']:record['status']='failed immutable input drift'
        record['output_sha256']={path.name:sha(path) for path in out.iterdir() if path.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
