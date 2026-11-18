"""Current native application resource graph with actual owned archive/assets."""
import argparse,hashlib,json,os,shutil,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
from verify_native_session import dependency_sources
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);a=parser.parse_args()
    out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir()
    build=ROOT/'build-native-sjuni'/f'gameplay-native-{a.compiler}-v1';compiler=COMPILERS[a.compiler]
    env=dict(os.environ,PATH=str(compiler.parent)+os.pathsep+os.environ.get('PATH',''))
    record=dict(schema='reo.native.session_resources.v1',status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,commands=[],compiler_sha256=sha(compiler))
    def run(command,label):
        command=list(map(str,command));done=subprocess.run(command,capture_output=True,env=env,timeout=600)
        (out/(label+'.log')).write_bytes(done.stdout+done.stderr);record['commands'].append(command)
        assert done.returncode==0,label+': '+(done.stdout+done.stderr).decode(errors='replace')[-4000:]
        return done.stdout.decode()
    try:
        run([CMAKE,'-S',ROOT/'game/native','-B',build],'configure')
        paths,libraries=dependency_sources(build,'gameplay_application/session_resources_tests.exe')
        paths=set(paths)|{Path(__file__).resolve()};before={p.relative_to(ROOT).as_posix():sha(p)for p in paths}
        for name in before:
            target=out/'source'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(ROOT/name,target)
        run([CMAKE,'--build',build,'--target','session_resources_tests','native_session_tests','--parallel','2'],'build')
        content=ROOT/'build-native-sjuni/gameplay-contact-content-llvm-v2/contact-content-v1.bin'
        assert sha(content)=='6e205620e37747181b4a14280f579e2cd85ed907f9b4634ffe28048e1e87a213'
        effects=ROOT/'build-native-sjuni/resource-flight-owner-llvm-v4/owned_effect_geometry.bin'
        parent=json.loads((effects.parent/'receipt.json').read_text());assert parent['status']=='passed'and sha(effects)==parent['output_sha256'][effects.name]
        for path in [content,effects]:shutil.copyfile(path,out/path.name)
        record['owned_asset_sha256']={p.name:sha(p)for p in [content,effects]}
        inventory=json.loads((ROOT/'build-native-sjuni/gameplay-script-content-llvm-v21/inventory.json').read_text());member=next(row for row in inventory if row['name']=='r0417300.rdt');archive=Path(member['archive'])
        with archive.open('rb')as source:source.seek(member['archive_offset']);assert hashlib.sha256(source.read(member['bytes'])).hexdigest()==member['sha256']
        identity=(archive.stat().st_size,archive.stat().st_mtime_ns)
        record['result']=json.loads(run([build/'gameplay_application/session_resources_tests.exe',archive,out/content.name,out/effects.name],'owned-graph'))
        record['fixture']=json.loads(run([build/'gameplay_application/native_session_tests.exe'],'session-fixtures'))
        assert identity==(archive.stat().st_size,archive.stat().st_mtime_ns)
        record['owned_archive_identity']=dict(bytes=identity[0],mtime_ns=identity[1],room_sha256=member['sha256'])
        record['source_sha256']=before;record['source_drift']={n:sha(ROOT/n)for n,digest in before.items()if sha(ROOT/n)!=digest};assert not record['source_drift']
        record['native_library_sha256']={name:sha(build/name)for name in libraries}
        for name,digest in record['native_library_sha256'].items():
            target=out/'libraries'/name;target.parent.mkdir(parents=True,exist_ok=True);shutil.copyfile(build/name,target);assert sha(target)==digest
        record['executable_sha256']=sha(build/'gameplay_application/session_resources_tests.exe');record['status']='passed'
    finally:
        record['output_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()and p.name!='receipt.json'};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps(dict(compiler=a.compiler,result=record['result'],sources=len(before),libraries=len(libraries))))
if __name__=='__main__':main()
