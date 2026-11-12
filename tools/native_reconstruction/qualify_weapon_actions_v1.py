"""Seal complete canonical resource use and firing orchestration comparisons."""
import hashlib,json,os,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    domain=['game/native/gameplay_world/'+name for name in
        ['weapon_actions.hpp','weapon_actions.cpp','weapon_fire.hpp','weapon_fire.cpp','weapon_fire_profile.inc',
         'resource_depletion.hpp','resource_depletion.cpp','resource_deployment.hpp','resource_deployment.cpp']]
    domain+=['tools/native_reconstruction/'+name for name in
        ['weapon_actions_tests.inc','weapon_fire_tests.inc','verify_periodic_visuals.py','periodic_visuals_tests.cpp','generate_weapon_fire_profile.py','qualify_weapon_actions_v1.py']]
    domain+=['docs/native-gameplay/WEAPON_ACTIONS.md','game/native/gameplay_world/CMakeLists.txt']
    sources={name:sha(ROOT/name)for name in domain};cohorts={};observed=None
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'weapon-fire-{compiler}-v2/receipt.json'
        record=json.loads(path.read_bytes());assert record['status']=='passed' and record['source_unchanged']
        assert record['observed']['weapon_action_cases']==65536 and record['observed']['weapon_fire_cases']==32768
        assert record['observed']['weapon_fire_callbacks']==51257
        if observed is not None:assert observed==record['observed']
        observed=record['observed'];changes={}
        for name,digest in record['source_sha256'].items():
            assert sha(path.parent/'source'/name)==digest,name
            if name in sources:assert sources[name]==digest,name
            if sha(ROOT/name)!=digest:changes[name]={'qualified':digest,'current':sha(ROOT/name)}
        cohorts[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),
            'compiler_sha256':record['compiler_sha256'],'observed':record['observed'],
            'subsequent_dependency_changes':changes}
    subprocess.run(['python',str(ROOT/'tools/native_reconstruction/generate_weapon_fire_profile.py')],cwd=ROOT,check=True,capture_output=True)
    cmake=Path('C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe')
    builds={}
    for compiler in ('llvm','gcc'):
        build=ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1'
        command=[str(cmake),'--build',str(build),'--target','reo_native_weapon_actions','--parallel','2']
        result=subprocess.run(command,cwd=ROOT,capture_output=True,timeout=240);assert result.returncode==0,result.stderr.decode(errors='replace')
        binary=build/'gameplay_world/libreo_native_weapon_actions.a';assert binary.is_file()
        builds[compiler]={'command':command,'returncode':result.returncode,'library':binary.relative_to(ROOT).as_posix(),'sha256':sha(binary),'output':result.stdout.decode(errors='replace')}
    output=ROOT/'tools/native_reconstruction/native_weapon_actions_qualification_v1.json';assert not output.exists()
    record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,cmake_builds=builds,
        limits=['Feedback and four reached effect constructors are controlled ports, not newly supplied effect implementations.',
                'Audio selectorFF avoids bank requests in this caller cohort; no audible weapon claim.',
                'No native full-session installation or complete Stage4 acceptance claim.'])
    output.write_text(json.dumps(record,indent=2)+'\n');print(sha(output))
if __name__=='__main__':main()
