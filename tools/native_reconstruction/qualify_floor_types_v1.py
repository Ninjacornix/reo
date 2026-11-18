"""Seal the explicit high-bit floor correction without replacing old evidence."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
    cohorts={};previous=None
    for compiler in ['llvm','gcc']:
        p=ROOT/'build-native-sjuni'/f'gameplay-collision-response-{compiler}-v8/receipt.json'
        r=json.loads(p.read_bytes());assert r['status']=='native capsule/floor/grid response focused comparisons passed'
        if previous:assert r['source_sha256']==previous['source_sha256'] and r['results']==previous['results']
        previous=r
        for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h
        for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
        cohorts[compiler]={'receipt':p.relative_to(ROOT).as_posix(),'receipt_sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'results':r['results'],'source_sha256':r['source_sha256']}
    q={'schema':1,'status':'explicit floor type request correction qualified on both compilers','stage4_complete':False,'game_run':False,'installed_in_game':False,'cohorts':cohorts,'limits':['Original617000 and point-in-triangle bodies checked; scalar vector helpers and cell lookup are declared oracle seams.','No game installation or performance claim.']}
    p=ROOT/'tools/native_reconstruction/native_floor_explicit_types_qualification_v1.json';assert not p.exists();p.write_text(json.dumps(q,indent=2)+'\n');print(sha(p))
if __name__=='__main__':main()
