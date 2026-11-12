"""Seal canonical pose allocation/construction/callbacks and current integration."""
import hashlib,json,os,subprocess
from pathlib import Path
from verify_gameplay_collision import COMPILERS
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()


def main():
    domain=['game/native/gameplay_world/'+name for name in ['world.hpp','pose_work_state.hpp','pose_work_pool.hpp','pose_work_pool.cpp','resource_pose_work.hpp','resource_pose_work.cpp','resource_pose_updates.hpp','resource_pose_updates.cpp','pose_work_pool_tests.cpp','contact_weapon_effects.cpp','CMakeLists.txt']]
    domain+=['game/native/gameplay_effects/'+name for name in ['pose_lifetime.hpp','pose_lifetime.cpp']]
    domain+=['game/native/gameplay_contact_world/'+name for name in ['contacts.hpp','contacts.cpp','tests.cpp']]
    domain+=['tools/native_reconstruction/'+name for name in ['pose_lifetime_tests.cpp','verify_pose_lifetime.py','pose_work_tests.cpp','pose_work_updates_tests.inc','pose_work_mutation_tests.inc','verify_pose_work.py','verify_pose_work_current.py','qualify_pose_work_v1.py']]
    domain+=['docs/native-gameplay/POSE_WORK.md'];sources={name:sha(ROOT/name)for name in domain};cohorts={};parents={};observed={};syntax={}
    for compiler in ['llvm','gcc']:
        cohorts[compiler]={}
        for family,stem,version in [('lifetime','pose-work-lifetime',1),('owner','pose-work-updates',4),('current','pose-work-current',1)]:
            path=ROOT/'build-native-sjuni'/f'{stem}-{compiler}-v{version}/receipt.json';record=json.loads(path.read_bytes());assert record['status']=='passed'
            if family=='lifetime':assert record['source_unchanged']
            elif family=='owner':assert not record['current_owned_source_drift']
            else:assert not record['source_drift']
            result=record.get('observed',record.get('result'))
            if family in observed:assert result==observed[family],family
            observed[family]=result;changes={}
            for name,digest in record['source_sha256'].items():
                assert sha(path.parent/'source'/name)==digest,name
                current=sha(ROOT/name)
                if current!=digest:changes[name]={'qualified':digest,'current':current}
                if family=='owner' and name in sources and name.startswith(('game/native/gameplay_world/pose_work','game/native/gameplay_world/resource_pose','game/native/gameplay_effects/pose_lifetime','tools/native_reconstruction/pose_work','tools/native_reconstruction/verify_pose_work.py')):assert current==digest,name
            cohorts[compiler][family]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'observed':result,'compiler_sha256':record['compiler_sha256'],'subsequent_dependency_changes':changes}
        assert observed['lifetime']['cases']==16777216
        assert observed['owner']['pool_cases']==4096 and observed['owner']['factory_cases']==2048 and observed['owner']['update_cases']==32768 and observed['owner']['mutation_cases']==128
        path=ROOT/'build-native-sjuni'/f'session-rooms-parents-{compiler}-v4/receipt.json';record=json.loads(path.read_bytes());assert record['status']=='passed'and record['parent_tests']==23 and not record['source_drift']
        for name in ['game/native/gameplay_world/world.hpp','game/native/gameplay_world/pose_work_state.hpp','game/native/gameplay_contact_world/contacts.hpp','game/native/gameplay_contact_world/contacts.cpp','game/native/gameplay_world/CMakeLists.txt']:
            assert record['source_sha256'][name]==sources[name],name
        parents[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'parent_tests':23}
        command=[str(COMPILERS[compiler]),'-std=c++20','-Wall','-Wextra','-Wpedantic','-Werror','-fno-fast-math','-ffp-contract=off','-I.','-fsyntax-only','game/native/gameplay_world/contact_weapon_effects.cpp']
        result=subprocess.run(command,cwd=ROOT,capture_output=True,timeout=120);assert result.returncode==0,result.stderr.decode(errors='replace');syntax[compiler]={'command':command,'returncode':0,'stdout_sha256':hashlib.sha256(result.stdout).hexdigest(),'stderr_sha256':hashlib.sha256(result.stderr).hexdigest()}
    assert sources=={name:sha(ROOT/name)for name in domain}
    output=ROOT/'tools/native_reconstruction/native_pose_work_qualification_v1.json';assert not output.exists()
    record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,current_parent_tests=parents,current_contact_adapter_syntax=syntax,
        limits=['The original constructor metadata lookups and descriptor attachment are explicit ports; native canonical getters and actual owned Packets/Catalog run.',
                'Differential tests use immutable SessionRooms v4 native ABI inputs; separate current CMake and parent23 runs prove present build integration.',
                'Other concrete pose callbacks, generic/preset constructors, complete firing/frame/host adoption, renderer and installed gameplay acceptance remain open.'])
    output.write_text(json.dumps(record,indent=2)+'\n');print(sha(output))


if __name__=='__main__':main()
