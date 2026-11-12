"""Bind the corrected eight-slot command to fresh complete-body/VM evidence."""
import hashlib
import json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
    sources={};cohorts={}
    for label,prefix,version,key in [('complete_audio','script-scenario-audio','v3','results'),('interpreter','scene-record-parameters-vm','v2','result')]:
        previous=None
        for compiler in ('llvm','gcc'):
            path=ROOT/'build-native-sjuni'/f'{prefix}-{compiler}-{version}/receipt.json'
            record=json.loads(path.read_bytes());assert record['status']=='passed'
            if previous is not None:assert record[key]==previous
            previous=record[key];changes={}
            for name,digest in record['source_sha256'].items():
                frozen=path.parent/'source'/name
                assert frozen.is_file() and sha(frozen)==digest,name
                if sha(ROOT/name)!=digest:changes[name]={'qualified':digest,'current':sha(ROOT/name)}
                if name.startswith('game/native/gameplay_audio/') or name in ['game/native/gameplay_scenario/script_audio.hpp','game/native/gameplay_scenario/script_audio.cpp','game/native/gameplay_scenario/interpreter.hpp','game/native/gameplay_scenario/interpreter.cpp']:
                    assert sha(ROOT/name)==digest,name
                    if name in sources:assert sources[name]==digest
                    sources[name]=digest
            results=record[key] if label=='complete_audio' else {n:v for n,v in record[key].items()if n=='checks' or n.startswith('script_audio_')}
            cohorts[f'{label}/{compiler}']={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'compiler_sha256':record['compiler_sha256'],'results':results,'subsequent_dependency_changes':changes}
    parents={}
    for compiler in ('llvm','gcc'):
        path=ROOT/'build-native-sjuni'/f'scene-record-parameters-parents-{compiler}-v2/receipt.json'
        record=json.loads(path.read_bytes());assert record['status']=='passed' and not record.get('source_drift')
        assert record['source_sha256']['game/native/gameplay_scenario/script_audio.cpp']==sources['game/native/gameplay_scenario/script_audio.cpp']
        parents[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'tests':13}
    output=ROOT/'tools/native_reconstruction/native_script_scenario_audio_qualification_v2.json';assert not output.exists()
    old=ROOT/'tools/native_reconstruction/native_script_scenario_audio_qualification_v1.json'
    for name in ['docs/native-gameplay/SCRIPT_SCENARIO_AUDIO.md',Path(__file__).relative_to(ROOT).as_posix()]:sources[name]=sha(ROOT/name)
    record=dict(schema=2,status='passed',game_run=False,installed_in_game=False,stage4_complete=False,
        source_sha256=sources,cohorts=cohorts,current_parent_regressions=parents,
        supersedes={'path':old.relative_to(ROOT).as_posix(),'sha256':sha(old),'reason':'The first profile rejected physical primary slots5-7 despite canonical World capacity8. Corrected command and both source oracles now exercise all8 selectors/selected values.'},
        limits=['Complete-body audio and full dispatcher source snapshots retain their real identities; subsequent dependency changes are explicit.',
            'The full VM declares1B8930 as a port into a separate real bank owner; the independent cohort executes that complete original body.',
            'No actual scenario bank/camera/device/session installation or complete native gameplay acceptance claim.'])
    output.write_text(json.dumps(record,indent=2)+'\n');print(sha(output))
if __name__=='__main__':main()
