"""Bind paired full node/position callers to immutable native source evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm','v4'),('gcc','v1')]:
        p=ROOT/'build-native-sjuni'/f'node-position-audio-{compiler}-{version}/receipt.json';r=json.loads(p.read_bytes())
        assert r['status']=='passed' and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n
            sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results']}
    seal=ROOT/'build-native-sjuni/node-position-audio-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/ANIMATION_NODE_POSITION_AUDIO.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    dependencies={}
    for name in ['native_gameplay_audio_qualification_v1.json','native_animation_models_qualification_v2.json','native_gameplay_authored_no_model_qualification_v1.json']:
        p=ROOT/'tools/native_reconstruction'/name;dependencies[name]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    q={'schema':1,'status':'canonical node and scenario position audio qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'dependencies':dependencies,
       'limits':['The model builder/camera use separately qualified native surroundings, not a second oracle claim.','Controlled valid banks; actual named bank and room-model assignment remain open.','No complete native game or real-device listening claim.'],
       'preserved_draft_failures':[f'build-native-sjuni/node-position-audio-llvm-v{i}/receipt.json'for i in range(1,4)]}
    p=ROOT/'tools/native_reconstruction/native_animation_node_position_audio_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
