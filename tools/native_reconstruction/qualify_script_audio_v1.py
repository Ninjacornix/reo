"""Seal independent audio bodies and full dispatcher composition evidence."""
import hashlib
import json
from pathlib import Path

ROOT=Path(__file__).resolve().parents[2]
def sha(path):
    return hashlib.sha256(path.read_bytes()).hexdigest()

def main():
    cohorts={}
    historical_changes={}
    domain={}
    for kind,prefix,version,result_key in [
        ('complete_audio','script-scenario-audio','v2','results'),
        ('interpreter','scene-record-retirement-script-audio','v1','result')]:
        previous=None
        for compiler in ('llvm','gcc'):
            receipt=ROOT/'build-native-sjuni'/f'{prefix}-{compiler}-{version}/receipt.json'
            record=json.loads(receipt.read_bytes())
            assert record['status']=='passed'
            results=record[result_key]
            if previous is not None:assert results==previous
            previous=results
            changes={}
            for name,digest in record['source_sha256'].items():
                frozen=receipt.parent/'source'/name
                assert frozen.is_file() and sha(frozen)==digest,name
                if sha(ROOT/name)!=digest:changes[name]={'qualified':digest,'current':sha(ROOT/name)}
                if name.startswith('game/native/gameplay_audio/') or name in (
                    'game/native/gameplay_scenario/script_audio.hpp',
                    'game/native/gameplay_scenario/script_audio.cpp',
                    'game/native/gameplay_scenario/interpreter.hpp',
                    'game/native/gameplay_scenario/interpreter.cpp'):
                    assert sha(ROOT/name)==digest,name
                    if name in domain:assert domain[name]==digest
                    domain[name]=digest
            # These later constructor defaults are covered by current-source
            # parent regressions. They are not relabelled as this old snapshot.
            assert set(changes)<=set([
                'game/native/gameplay_world/actor_initial_state.hpp',
                'game/native/gameplay_update/scripted_actor_construction.cpp'])
            historical_changes[f'{kind}/{compiler}']=changes
            reported=results if kind=='complete_audio' else {name:value for name,value in results.items()if name=='checks' or name.startswith('script_audio_')}
            cohorts[f'{kind}/{compiler}']={
                'receipt':receipt.relative_to(ROOT).as_posix(),
                'sha256':sha(receipt),'compiler_sha256':record['compiler_sha256'],
                'results':reported}
    parents={}
    for compiler in ('llvm','gcc'):
        receipt=ROOT/'build-native-sjuni'/f'reaction-script-parents-{compiler}-v2/receipt.json'
        record=json.loads(receipt.read_bytes())
        assert record['status']=='passed' and not record['source_drift'] and record['parent_tests']==12
        parents[compiler]={'receipt':receipt.relative_to(ROOT).as_posix(),'sha256':sha(receipt),'parent_tests':12}
    output=ROOT/'tools/native_reconstruction/native_script_scenario_audio_qualification_v1.json'
    assert not output.exists()
    for name in ['docs/native-gameplay/SCRIPT_SCENARIO_AUDIO.md',Path(__file__).relative_to(ROOT).as_posix()]:
        domain[name]=sha(ROOT/name)
    record=dict(schema=1,status='passed',game_run=False,installed_in_game=False,
        stage4_complete=False,source_sha256=domain,cohorts=cohorts,
        later_dependency_changes=historical_changes,current_constructor_parent_regressions=parents,
        limits=[
            'Complete original68F640/1B8930 and lower sound bodies execute in the independent audio oracle.',
            'Full ordinary/offline dispatcher composition declares1B8930 as an explicit port into a separate real native bank owner.',
            'All immutable source snapshots retain their actual identities; later constructor/default changes are separately recorded.',
            'No actual scenario bank assignment, camera publication, device listening or complete native game acceptance claim.'],
        preserved_failure='build-native-sjuni/script-scenario-audio-llvm-v1/receipt.json')
    output.write_text(json.dumps(record,indent=2)+'\n')
    print(sha(output))

if __name__=='__main__':
    main()
