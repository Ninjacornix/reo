"""Seal independent native playback copies and source animation continuations."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_playback_ownership_copies_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected={}
    for cc in ['llvm','gcc']:
        cohorts[cc]={}
        for kind,directory in [('playback',f'playback-independent-copy-{cc}-v2'),('models',f'primary-model-independent-copy-{cc}-v1')]:
            path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
            observed=r.get('observed',r.get('owned'));assert observed
            if kind in expected:assert observed==expected[kind]
            expected[kind]=observed
            if kind=='playback':assert observed['independent_copies']==72 and observed['copy_continuations']==1288 and observed['copy_isolations']==64 and observed['checks']==3113688
            else:assert observed['independent_detached_copies']==256 and observed['checks']==107089 and observed['entry_cases']==385 and observed['scene_cases']==1196
            for name,digest in r['source_sha256'].items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest
                sources[name]=digest
            for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
            cohorts[cc][kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
    target.write_text(json.dumps(dict(schema=1,status='qualified independent native playback ownership snapshots',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'This native deep ownership copy is not an original allocation-copy routine; original5F1400 copies Actor model pointers.',
        'Both owned skeletons, secondary policies, original animation continuation, isolated mutation and detached lifetime cases are tested.',
        'Actual typed Actor construction, physical model-slot choice, constraints/cache handoff and complete scene adoption remain open.',
        'No game launch, installation or measured performance change is claimed.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
