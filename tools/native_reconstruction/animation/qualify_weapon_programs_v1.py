"""Seal actual WMD imports, complete selectors/samplers and reached events."""
import hashlib,json,re,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    sources={};copies={};cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'weapon-programs-{compiler}-v2/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and r['source_unchanged']
        if previous:assert r['source_sha256']==previous['source_sha256']and r['observed']==previous['observed']and r['weapon_assets']==previous['weapon_assets']
        previous=r
        for n,h in r['source_sha256'].items():
            frozen=p.parent/'source'/n;assert sha(ROOT/n)==h and sha(frozen)==h,n;sources[n]=h;copies[n]={'path':frozen.relative_to(ROOT).as_posix(),'sha256':h}
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h,n
        cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'weapon_assets':r['weapon_assets']}
    seal=ROOT/'build-native-sjuni/weapon-programs-seal-v1';assert not seal.exists();seal.mkdir()
    for n in ['docs/native-gameplay/WEAPON_PROGRAMS.md','game/native/animation/CMakeLists.txt','game/native/gameplay_world/CMakeLists.txt',Path(__file__).relative_to(ROOT).as_posix()]:
        p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';static=[]
    for at in [0x6b4ae0,0x5932f0,0x6b45c0]:
        n=f'recomp/config/output_ovl/o2/o2_{at:08X}_0x{at:x}.cpp';source=ROOT/n;end=int(re.search(r'// Address: 0x[0-9a-f]+ - 0x([0-9a-f]+)',source.read_text())[1],16)
        static.append(compare_source('static asset-loader and open callback authority; not executed by this cohort',n,at,end,lambda pos,size:raw[pos-0x570000:pos-0x570000+size]));p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes(source.read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
    checks={}
    for compiler in ['llvm','gcc']:
        for kind in ['v2','tests-v1']:
            p=ROOT/'build-native-sjuni'/f'stage4-weapon-program-parent-{compiler}-{kind}.txt';text=p.read_text(encoding='utf-16');assert 'FAILED:'not in text
            if kind=='tests-v1':assert '100% tests passed, 0 tests failed out of 4'in text
            checks[p.relative_to(ROOT).as_posix()]=sha(p)
    q={'schema':1,'status':'canonical resource WMD selector and owned scalar curves qualified on both compilers','game_run':False,'installed_in_game':False,'stage4_complete':False,'source_sha256':sources,'immutable_source_evidence':copies,'cohorts':cohorts,'parent_checks':checks,'static_open_loader_callback_authority':static,'limits':['Full6B4420/6B4A30 and reached596470 event calls execute; full6B45C0/5932F0 callbacks remain open.','WMD selection words can overlap key data: unavailable native trees are explicit reached refusals, not guessed empty programs.','Actual asset/resource construction/loading, visual updates and coherent native gameplay acceptance remain open.'],'preserved_compile_failure':'build-native-sjuni/weapon-programs-gcc-v1/receipt.json'}
    p=ROOT/'tools/native_reconstruction/native_weapon_programs_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
