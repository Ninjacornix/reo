"""Build/test actual adaptive encoded-refill component; no game/device execution."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]


def sha(path):
    with path.open('rb') as stream:return hashlib.file_digest(stream,'sha256').hexdigest()


def main():
    p=argparse.ArgumentParser(description=__doc__)
    for name in ('compiler','cmake','ninja','build','output'):p.add_argument('--'+name,type=Path,required=True)
    a=p.parse_args();build=a.build.resolve();out=a.output.resolve()
    for path in (build,out):assert not path.exists() and path.is_relative_to(ROOT/'build-native-sjuni')
    assert build!=out
    paths=[]
    for directory in ('adxt_refill','resources','resource_io','tasks','sjrb'):
        paths.extend(x for x in (ROOT/'game/native'/directory).rglob('*') if x.is_file() and (x.suffix in ('.cpp','.hpp','.h') or x.name=='CMakeLists.txt'))
    paths += [ROOT/'runtime/assets/virtual_afs.h',Path(__file__)]
    sources={x.relative_to(ROOT).as_posix():sha(x) for x in paths}
    out.mkdir(parents=True);env=dict(os.environ);env['PATH']=str(a.compiler.resolve().parent)+os.pathsep+env.get('PATH','')
    snapshot=out/'source-snapshot'
    for name,digest in sources.items():
        target=snapshot/name;target.parent.mkdir(parents=True,exist_ok=True)
        shutil.copyfile(ROOT/name,target);assert sha(target)==digest
    record=dict(schema=1,status='failed',game_run=False,device_opened=False,process_access=False,
        actual_adaptive_refill=True,actual_resource_and_async_worker=True,
        compiler_sha256=sha(a.compiler),cmake_sha256=sha(a.cmake),ninja_sha256=sha(a.ninja),sources=sources,checks=[])
    def run(label,command):
        result=subprocess.run(list(map(str,command)),env=env,capture_output=True,text=True,timeout=180)
        (out/(label+'.txt')).write_text(result.stdout+result.stderr,encoding='utf8')
        record['checks'].append(dict(label=label,exit=result.returncode,command=list(map(str,command))))
        if result.returncode:raise ValueError(label+' failed; retained log')
        print(label+': passed',flush=True)
    try:
        run('configure',[a.cmake,'-S',snapshot/'game/native/adxt_refill','-B',build,'-G','Ninja','-DCMAKE_BUILD_TYPE=Release','-DCMAKE_CXX_COMPILER='+str(a.compiler.resolve()),'-DCMAKE_MAKE_PROGRAM='+str(a.ninja.resolve())])
        run('build',[a.cmake,'--build',build,'-j','2'])
        run('tests',[a.cmake.with_name('ctest.exe' if os.name=='nt' else 'ctest'),'--test-dir',build,'--output-on-failure','-V'])
        for name,value in sources.items():assert sha(ROOT/name)==value,'Source drift: '+name
        record['status']='adaptive resident refill component checks passed'
        record['libraries_sha256']={x.relative_to(ROOT).as_posix():sha(x) for x in build.rglob('*.a')}
    except Exception as error:record['failure']=str(error);raise
    finally:
        record['outputs_sha256']={x.name:sha(x) for x in out.iterdir() if x.is_file()}
        (out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n',encoding='utf8')
    print(json.dumps(dict(status=record['status'],receipt_sha256=sha(out/'receipt.json'))))


if __name__=='__main__':main()
