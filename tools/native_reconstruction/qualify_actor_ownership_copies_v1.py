"""Seal native Actor/constraint ownership copies with current source evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_actor_ownership_copies_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected={}
    for cc in ['llvm','gcc']:
        cohorts[cc]={}
        for kind,directory in [('constraints',f'constraints-ownership-copy-{cc}-v2'),('actors',f'primary-model-actor-copy-{cc}-v1')]:
            path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
            observed=r.get('observed',r.get('owned'));assert observed
            if kind in expected:assert observed==expected[kind]
            expected[kind]=observed
            if kind=='constraints':assert observed['ownership_copies']==512 and observed['ownership_isolations']==512 and observed['ownership_copy_refusals']==4 and observed['checks']==720664
            else:assert observed['owned_actor_copies']==515 and observed['actor_copy_refusals']==256 and observed['checks']==108885 and observed['entry_cases']==385
            for name,digest in r['source_sha256'].items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest
                sources[name]=digest
            for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
            cohorts[cc][kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
    target.write_text(json.dumps(dict(schema=1,status='qualified typed Actor and constraint ownership snapshots',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Native value/ownership preparation does not register World identities or apply scene construction stores.',
        'Exact-topology constraints preserve all contexts/callbacks; reconstruction on another topology remains independently restricted.',
        'Detached and old constraint-model relationships are preserved rather than silently retargeted.',
        'Actual5F1400 construction, model retirement/cache-row handoff, temporary traversal and full scene/game acceptance remain open.',
        'No game launch, installation or performance measurement is claimed.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
