"""Build and run the actual current CMake pose owner with its full input closure."""
import argparse,hashlib,json,os,re,shutil,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
CMAKE=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    parser=argparse.ArgumentParser();parser.add_argument('--compiler',choices=COMPILERS,required=True);parser.add_argument('--output',type=Path,required=True);a=parser.parse_args();out=a.output.resolve();assert not out.exists()and out.is_relative_to(ROOT/'build-native-sjuni');out.mkdir(parents=True)
    build=ROOT/'build-native-sjuni'/f'gameplay-native-{a.compiler}-v1';env=dict(os.environ,PATH=str(COMPILERS[a.compiler].parent)+os.pathsep+os.environ.get('PATH',''));commands=[];record=dict(schema=1,status='failed',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,compiler_sha256=sha(COMPILERS[a.compiler]))
    def run(command,label):
        command=[str(v)for v in command];result=subprocess.run(command,capture_output=True,env=env,timeout=600);(out/(label+'.stdout.txt')).write_bytes(result.stdout);(out/(label+'.stderr.txt')).write_bytes(result.stderr);commands.append({'command':command,'returncode':result.returncode});assert result.returncode==0,label+' failed';return result.stdout
    try:
        run([CMAKE,'-S',ROOT/'game/native','-B',build],'configure');rules={}
        for line in (build/'build.ninja').read_text().splitlines():
            match=re.match(r'^build ([^:]+): \S+\s*(.*)',line)
            if match:
                for output in match[1].split():rules[output]=match[2].split()
        pending=['gameplay_world/pose_work_pool_tests.exe'];visited=set();sources=set();libraries=set()
        while pending:
            node=pending.pop()
            if node in visited:continue
            visited.add(node)
            if node.endswith('.a'):libraries.add(node)
            for dependency in rules.get(node,[]):
                if dependency.endswith(('.a','.obj')):pending.append(dependency)
                elif dependency.endswith('.cpp'):
                    path=Path(dependency.replace('$:',':')).resolve();assert path.is_file()and path.is_relative_to(ROOT);sources.add(path)
        assert ROOT/'game/native/gameplay_world/pose_work_pool.cpp'in sources and ROOT/'game/native/gameplay_world/world.cpp'in sources
        pending=list(sources)
        for path in pending:
            for include in re.findall(r'#\s*include\s*"([^"]+)"',path.read_text()):
                candidate=next((p.resolve()for p in (path.parent/include,ROOT/include)if p.is_file()),None)
                if candidate and candidate.is_relative_to(ROOT)and candidate not in sources:sources.add(candidate);pending.append(candidate)
        sources.update([Path(__file__).resolve(),ROOT/'game/native/CMakeLists.txt'])
        for path in tuple(sources):
            cmake=path.parent/'CMakeLists.txt'
            if cmake.is_file():sources.add(cmake)
        frozen={p.relative_to(ROOT).as_posix():p.read_bytes()for p in sources}
        for name,contents in frozen.items():
            path=out/'source'/name;path.parent.mkdir(parents=True,exist_ok=True);path.write_bytes(contents)
        run([CMAKE,'--build',build,'--target','pose_work_pool_tests','--parallel','2'],'build')
        content=ROOT/'build-native-sjuni/gameplay-contact-content-llvm-v2/contact-content-v1.bin';assert sha(content)=='6e205620e37747181b4a14280f579e2cd85ed907f9b4634ffe28048e1e87a213';shutil.copyfile(content,out/content.name)
        record['result']=json.loads(run([build/'gameplay_world/pose_work_pool_tests.exe',out/content.name],'owned-contract'))
        assert record['result']['checks']==152 and record['result']['owned_catalog']
        tests=run([CMAKE.parent/'ctest.exe','--test-dir',build,'--output-on-failure','-R','^native_pose_work_slots$'],'ctest');assert b'100% tests passed, 0 tests failed out of 1'in tests
        record['source_sha256']={n:hashlib.sha256(v).hexdigest()for n,v in frozen.items()};record['source_drift']={n:sha(ROOT/n)for n,v in frozen.items()if (ROOT/n).read_bytes()!=v};assert not record['source_drift']
        record['native_library_sha256']={name:sha(build/name)for name in sorted(libraries)};record['executable_sha256']=sha(build/'gameplay_world/pose_work_pool_tests.exe');record['status']='passed'
    finally:
        record['commands']=commands;record['output_sha256']={p.name:sha(p)for p in out.iterdir()if p.is_file()};(out/'receipt.json').write_text(json.dumps(record,indent=2)+'\n')
    print(json.dumps({'compiler':a.compiler,'result':record['result'],'sources':len(record['source_sha256']),'libraries':len(record['native_library_sha256'])}))


if __name__=='__main__':main()
