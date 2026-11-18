"""Seal guarded native cinematic construction and actual main-model retirement."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_primary_scene_construction_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected=None
    for cc in ['llvm','gcc']:
        path=ROOT/f'build-native-sjuni/primary-scene-construction-{cc}-v3/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged'];observed=r['owned']
        assert expected is None or observed==expected;expected=observed
        assert observed['checks']==117002 and observed['construction_cases']==258 and observed['construction_original_cases']==258 and observed['construction_refusals']==258 and observed['construction_guards']==3
        assert observed['owned_actor_copies']==515 and observed['entry_cases']==385 and observed['scene_cases']==1196
        assert any(p['start']=='0x5f1400'for p in r['original_owned_bodies'])
        for name,digest in r['source_sha256'].items():
            assert sha(ROOT/name)==digest,name
            assert name not in sources or sources[name]==digest
            sources[name]=digest
        for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
        parent=path.parent/'parents.log';raw=parent.read_bytes();log=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert '100% tests passed, 0 tests failed out of 4'in log
        cohorts[cc]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed,parents=dict(path=parent.relative_to(ROOT).as_posix(),sha256=sha(parent)))
    target.write_text(json.dumps(dict(schema=1,status='qualified guarded cinematic primary construction and main-model retirement',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Full5F1400/5EC270/5EC010 execute against owned words. Constructor comparison uses an explicit selected-field/control schema; not every native Actor field is represented as a raw layout.',
        'Bounded raw fill/copy and render/resource-helper observations are ports. Actual native ownership copying, bank publication and main-model retirement execute independently.',
        'New temporary generations preserve old leases and reject stale identities; allocation/full refusal before publication preserves the inactive slot.',
        'Failure after construction returns an ID and incomplete resource flags. The enclosing scene owner must latch that prefix.',
        'Temporary model-cache admission stays closed; physical slot handoff, temporary initialization, playback, objects and full entry/exit remain open.',
        'No game launch, installation or performance measurement is claimed.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
