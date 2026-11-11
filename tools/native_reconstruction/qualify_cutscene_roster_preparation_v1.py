"""Seal native eligible roster projection and canonical World publication."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_cutscene_roster_preparation_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected={}
    for cc in ['llvm','gcc']:
        cohorts[cc]={}
        for kind,directory in [('projection',f'cutscene-roster-preparation-{cc}-v2'),('world',f'primary-roster-world-{cc}-v1')]:
            path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged'];o=r.get('compared',r.get('owned'))
            assert kind not in expected or expected[kind]==o;expected[kind]=o
            if kind=='projection':assert o==dict(status='passed',checks=7954785,cases=414728,original_cases=396845,unavailable=17883,special_cases=2,game_run=False)
            else:assert o['checks']==124408 and o['roster_world_cases']==365 and o['roster_world_original_cases']==365 and o['roster_world_refusals']==43 and o['construction_guards']==3
            for name,digest in r['source_sha256'].items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest
                sources[name]=digest
            for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
            cohorts[cc][kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=o)
            if kind=='projection':
                parent=path.parent/'parents.log';raw=parent.read_bytes();text=raw.decode('utf-16'if raw.startswith(b'\xff\xfe')else'utf-8-sig');assert '100% tests passed, 0 tests failed out of 4'in text
                cohorts[cc][kind]['parents']=dict(path=parent.relative_to(ROOT).as_posix(),sha256=sha(parent))
    target.write_text(json.dumps(dict(schema=1,status='qualified cinematic eligible roster and World visibility publication',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,limitations=[
        'Full5ED340 executes, but graphics/resource/bank cleanup, NPC/object cleanup and temporary-pool reset are declared non-projecting ports.',
        'Native production code projects/publishes roster and visibility only, with fixed native values and no guest-addressed state.',
        'Unknown state and out-of-owner placement-room reads refuse before publication. No arbitrary zero fallback is granted.',
        'Complete cleanup, independent physical model resources, temporary model initialization and full scene/game acceptance remain open.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix())))
if __name__=='__main__':main()
