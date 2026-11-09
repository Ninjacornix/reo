"""Seal opt-in authored absence and every affected paired bounded regression."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    cohorts={};current={};copies={}
    for group in ['repair','models','selectors','playback','default','vm']:
        previous=None
        for compiler in ['llvm','gcc']:
            p=ROOT/'build-native-sjuni'/f'gameplay-no-model-final-{group}-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
            if previous:assert previous['source_sha256']==r['source_sha256'] and previous['result']==r['result']
            previous=r;pinned=r.get('pinned_shared_sources',{})
            for n,h in r['source_sha256'].items():
                frozen=p.parent/'source'/n;assert frozen.is_file() and sha(frozen)==h,n
                if n not in pinned:
                    assert sha(ROOT/n)==h,n
                    if n in current:assert current[n]==h,n
                    current[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
                else:assert pinned[n]['sha256']==h,n
            for key in ['original_source_sha256','original_sources_sha256']:
                for n,h in r.get(key,{}).items():assert sha(ROOT/n)==h,n
            manifest={f.relative_to(p.parent).as_posix():sha(f) for f in p.parent.rglob('*') if f.is_file() and f!=p}
            cohorts[group+'_'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'result':r['result'],'pinned_shared_sources':pinned,'output_sha256':manifest}
    seal=ROOT/'build-native-sjuni/no-model-final-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/SCENARIO_AUTHORED_NO_MODEL_REPAIR.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());current[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    probe=ROOT/'tools/native_reconstruction/native_gameplay_unbound_scene_alias_probe_qualification_v1.json'
    q={'schema':1,'status':'opt-in authored NoModel repair and bounded consumer regressions qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'default_enabled':False,'source_sha256':current,'immutable_source_evidence':copies,'cohorts':cohorts,'original_probe':{'path':probe.relative_to(ROOT).as_posix(),'sha256':sha(probe)},'intentional_differences':['No high-byte writes into room contact counters.','No physical binding bit or guest-pointer writes for authored absence.','No style31 visibility mutation for admitted authored absence; expired typed leases refuse before prefix effects.','Native generation/provenance replace unchecked guest aliasing.'],'remaining':['Actual three-room acceptance and native room/resource installation.','Remaining outer matrix path including ten-channel opcode93.','Raw room-object lifetime FF consumers without authored provenance remain unavailable.','Current full World/effects VM composition and Stage4 game acceptance.']}
    p=ROOT/'tools/native_reconstruction/native_gameplay_authored_no_model_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
