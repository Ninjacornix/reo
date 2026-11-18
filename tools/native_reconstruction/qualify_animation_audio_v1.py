"""Seal canonical actor/resource cues through actual native bank mixing."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm','v3'),('gcc','v1')]:
        p=ROOT/'build-native-sjuni'/f'animation-audio-frontends-{compiler}-{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/animation-audio-frontends-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/ANIMATION_AUDIO_FRONTENDS.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    dependency=ROOT/'tools/native_reconstruction/native_gameplay_audio_qualification_v1.json'
    q={'schema':1,'status':'canonical actor/resource animation cues through real bank Session qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'bank_owner_dependency':{'path':dependency.relative_to(ROOT).as_posix(),'sha256':sha(dependency)},'limits':['Controlled valid banks/templates and explicit canonical camera surroundings, not runtime room/name installation.','Surface/node/scenario-remapped frontend consumers remain explicit reached refusals.','No game or real-device listening/performance claim.'],'preserved_fixture_failures':['build-native-sjuni/animation-audio-frontends-llvm-v1/receipt.json','build-native-sjuni/animation-audio-frontends-llvm-v2/receipt.json']}
    p=ROOT/'tools/native_reconstruction/native_animation_audio_frontends_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
