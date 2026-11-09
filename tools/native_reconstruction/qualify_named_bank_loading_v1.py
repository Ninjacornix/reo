"""Seal original aliases, actual native archive loading and core regressions."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
    sources={};copies={};cohorts={};previous=None
    for compiler,version in [('llvm','v4'),('gcc','v2')]:
        p=ROOT/'build-native-sjuni'/f'named-bank-loading-{compiler}-{version}/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r['source_drift']
        if previous:assert r['source_sha256']==previous['source_sha256']and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results'],'owned_iso_sha256':r['owned_iso_sha256']}
    regressions={}
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'gameplay-audio-loader-regression-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and not r['source_drift']
        for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h,n
        assert r['results']['checks']==891629;regressions[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'results':r['results']}
    seal=ROOT/'build-native-sjuni/named-bank-loading-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/NAMED_BANK_LOADING.md',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    dependencies={}
    for n in ['native_gameplay_audio_qualification_v1.json']:
        p=ROOT/'tools/native_reconstruction'/n;dependencies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    checks={}
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'stage4-named-bank-parent-{compiler}-v2.txt';assert 'FAILED:'not in p.read_text(encoding='utf-16');checks[p.relative_to(ROOT).as_posix()]=sha(p)
    q={'schema':1,'status':'bounded original sound aliases and actual native named bank loading qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'core_regressions':regressions,'dependencies':dependencies,'parent_builds':checks,
       'limits':['Complete original alias lookup executes; bounded native queue ownership is an explicit modernization, not exact legacy pointer-alias execution.','Actual pinned owned archive feeds native async reading, preparation and bank mixer; direct-bank PCM comparison reuses independently qualified native bank semantics.','Staged/combined enemy banks, original session-mode gate, caller migration and whole-game acceptance remain open.'],
       'preserved_draft_failures':['build-native-sjuni/named-bank-loading-llvm-v1/receipt.json','build-native-sjuni/named-bank-loading-gcc-v1/receipt.json']}
    p=ROOT/'tools/native_reconstruction/native_named_bank_loading_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
