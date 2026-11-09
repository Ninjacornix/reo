"""Seal full scene sound consumers plus real matrix-to-bank integration."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    sources={};copies={};cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'scene-bank-audio-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/scene-bank-audio-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/SCENE_BANK_AUDIO.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    dependencies={}
    for name in ['native_gameplay_audio_qualification_v1.json','native_scene_matrix_playback_qualification_v1.json']:
        p=ROOT/'tools/native_reconstruction'/name;dependencies[name]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    checks={}
    for compiler in ['llvm','gcc']:
        for kind in ['v1','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-scene-audio-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16')
            if kind=='tests-v1':assert '100% tests passed, 0 tests failed out of 4' in text
            else:assert 'FAILED:' not in text
            checks[p.relative_to(ROOT).as_posix()]=sha(p)
    q={'schema':1,'status':'canonical scene matrix to real bank audio qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'dependencies':dependencies,'parent_build_and_tests':checks,'limits':['Full6B60E0/1B9360 consumer executed; curve/state semantics reuse the separate full6B4BA0 qualification.','Controlled bank and camera surroundings; runtime room/name installation remains open.','No game/device or complete native gameplay claim.']}
    p=ROOT/'tools/native_reconstruction/native_scene_bank_audio_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
