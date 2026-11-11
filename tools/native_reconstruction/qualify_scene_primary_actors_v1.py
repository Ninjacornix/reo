"""Seal the separate cinematic Actor domain and affected current regressions."""
import hashlib,json,subprocess
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    target=ROOT/'tools/native_reconstruction/native_scene_primary_actors_qualification_v1.json';assert not target.exists()
    sources={};cohorts={};expected={}
    for cc in ['llvm','gcc']:
        cohorts[cc]={}
        for kind,name in [('pool',f'scene-primary-storage-{cc}-v2'),('models',f'scene-pool-primary-models-{cc}-v1'),('initialization',f'scene-pool-initialization-{cc}-v1'),('world',f'scene-pool-world-{cc}-v1'),('behavior',f'scene-pool-behavior-{cc}-v1'),('banks',f'scene-pool-shared-banks-{cc}-v1')]:
            path=ROOT/'build-native-sjuni'/name/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r.get('source_unchanged',True)
            observed=r.get('observed',r.get('owned',r.get('result')));assert observed
            if kind in expected:assert observed==expected[kind],kind
            expected[kind]=observed
            if kind=='pool':assert observed==dict(status='passed',checks=48214,original_cases=1025,guard_checks=34,capacity_cases=23,model_refusals=3,game_run=False)
            if kind=='models':assert observed['checks']==106065 and observed['entry_cases']==385 and observed['scene_cases']==1196
            if kind=='initialization':assert observed['checks']==39664817 and observed['saved_initializations']==65536
            if kind=='world':assert observed['checks']==2799371 and observed['original_calls']==8216138
            if kind=='behavior':assert observed['cases']==32768 and observed['trace_words']==2572551
            if kind=='banks':assert observed['original_bank_cases']==948 and r['publication']['publications']==7
            for name,digest in r['source_sha256'].items():
                assert sha(ROOT/name)==digest,name
                assert name not in sources or sources[name]==digest,name
                sources[name]=digest
            for name,digest in r.get('output_sha256',{}).items():assert sha(path.parent/name)==digest,name
            cohorts[cc][kind]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),observed=observed)
    drivers={}
    for name in ['effect_work_sources.py','gameplay_update_sources.py','verify_gameplay_world.py','verify_resource_frames.py','verify_target_metrics.py']+['animation/verify_'+n+'.py'for n in ['attachments','constrained_attachments','ground_constraints','linked_models','model_poses','primitives','world_playback']]:
        path=ROOT/'tools/native_reconstruction'/name;relative=path.relative_to(ROOT).as_posix()
        previous=subprocess.run(['git','show','a159eb44:'+relative],cwd=ROOT,check=True,capture_output=True).stdout.decode()
        current=path.read_text();normalized=current.replace(",'gameplay_world/scene_primary_actors.cpp'",'').replace(",'scene_primary_actors'",'')
        assert normalized==previous,name
        drivers[relative]=dict(sha256=sha(path),previous_commit='a159eb44',change='required scene_primary_actors.cpp link dependency only')
    target.write_text(json.dumps(dict(schema=1,status='qualified separate eight-actor cinematic storage and selection',game_run=False,installed_in_game=False,stage4_complete=False,source_sha256=sources,cohorts=cohorts,driver_dependency_deltas=drivers,limitations=[
        'Complete owned5F1290/5F1330 bodies execute; zero-fill and downstream category10 initializer are explicit fixture ports.',
        'Native reset uses atomic generation replacement and explicitly refuses insufficient capacity or attached models.',
        '5F0DC0 assignment, typed actor cloning, physical model-slot handoff, sixteen object records and scene traversal/exit remain open.',
        'The primary model cache continues to refuse temporary identities; no bypass was added.',
        'No game run, installation, subjective validation or slowdown improvement is claimed.']),indent=2)+'\n')
    print(json.dumps(dict(status='passed',seal=target.relative_to(ROOT).as_posix(),cohorts=len(cohorts)*len(expected))))
if __name__=='__main__':main()
