"""Seal real dual-pool weapon lights, task lifetime and firing adoption."""
import hashlib,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    domain=['game/native/gameplay_lighting/'+name for name in
        ['transient_lights.hpp','transient_lights.cpp','transient_light_policy.cpp','CMakeLists.txt']]
    domain+=['game/native/gameplay_world/'+name for name in ['transient_weapon_effects.hpp','transient_weapon_effects.cpp']]
    domain+=['game/native/gameplay_scenario/lighting.hpp','game/native/gameplay_scenario/lighting.cpp']
    domain+=['tools/native_reconstruction/'+name for name in ['transient_light_policy_tests.cpp','auxiliary_lighting_tests.inc','transient_lights_owner_tests.inc','verify_transient_light_policy.py','qualify_transient_weapon_lights_v1.py']]
    domain+=['docs/native-gameplay/TRANSIENT_WEAPON_LIGHTS.md']
    sources={name:sha(ROOT/name)for name in domain};cohorts={};parents={};observed=None
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'transient-light-owner-{compiler}-v3/receipt.json'
        record=json.loads(path.read_bytes());assert record['status']=='passed' and record['source_unchanged']
        assert record['observed']['owner_cases']==77 and record['observed']['owner_frames']==294
        if observed is not None:assert observed==record['observed']
        observed=record['observed'];changes={}
        for name,digest in record['source_sha256'].items():
            assert sha(path.parent/'source'/name)==digest,name
            if name in sources:assert sources[name]==digest,name
            if sha(ROOT/name)!=digest:changes[name]={'qualified':digest,'current':sha(ROOT/name)}
        cohorts[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'observed':record['observed'],'compiler_sha256':record['compiler_sha256'],'subsequent_dependency_changes':changes}
        parent=ROOT/'build-native-sjuni'/f'dual-light-primary-regression-{compiler}-v1/receipt.json'
        prior=json.loads(parent.read_bytes());assert prior['status']=='passed' and prior['source_unchanged']
        assert prior['source_sha256']['game/native/gameplay_scenario/lighting.cpp']==sources['game/native/gameplay_scenario/lighting.cpp']
        parents[compiler]={'path':parent.relative_to(ROOT).as_posix(),'sha256':sha(parent),'observed':prior['observed']}
    cmake='C:/Program Files/Microsoft Visual Studio/2022/Community/Common7/IDE/CommonExtensions/Microsoft/CMake/CMake/bin/cmake.exe';builds={}
    for compiler in ('llvm','gcc'):
        build=ROOT/'build-native-sjuni'/f'gameplay-native-{compiler}-v1';command=[cmake,'--build',str(build),'--target','reo_native_weapon_light_effects','--parallel','2']
        result=subprocess.run(command,cwd=ROOT,capture_output=True,timeout=240);assert result.returncode==0,result.stderr.decode(errors='replace')
        libraries=[build/'gameplay_lighting'/name for name in ['libreo_native_transient_lights.a','libreo_native_weapon_light_effects.a']]
        builds[compiler]={'command':command,'returncode':0,'output':result.stdout.decode(errors='replace'),'libraries':{path.relative_to(ROOT).as_posix():sha(path)for path in libraries}}
    output=ROOT/'tools/native_reconstruction/native_transient_weapon_lights_qualification_v1.json';assert not output.exists()
    record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,current_primary_light_regressions=parents,cmake_builds=builds,
        limits=['Original task allocation/retirement are controlled ports; actual native Update tasks execute in owner cases.',
                'Finite positions, native generation ownership and explicit stale-owner failure are admitted; undefined original pointer reuse is not reproduced.',
                'Other reached weapon effect families, complete session adoption and installed gameplay acceptance remain open.'])
    output.write_text(json.dumps(record,indent=2)+'\n');print(sha(output))
if __name__=='__main__':main()
