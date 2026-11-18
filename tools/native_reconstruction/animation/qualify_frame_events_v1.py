"""Seal original frame-window parity and exact World prelude step forwarding."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 sources={};copies={};cohorts={}
 for group,prefix,version in [('crossing','animation-frame-events','v1'),('world','animation-world-prelude-step','v2')]:
  prior=None
  for compiler in ['llvm','gcc']:
   p=ROOT/'build-native-sjuni'/f'{prefix}-{compiler}-{version}'/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed' and r['source_unchanged']
   if prior is not None:assert prior['observed']==r['observed'] and prior['source_sha256']==r['source_sha256']
   prior=r
   for n,h in r['source_sha256'].items():
    assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h
    if n in sources:assert sources[n]==h
    sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
   for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
   cohorts[group+'_'+compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'original_owned_bodies':[{k:v for k,v in x.items()if k!='comparisons'}for x in r['original_owned_bodies']]}
 seal=ROOT/'build-native-sjuni/animation-frame-events-seal-v1';assert not seal.exists();seal.mkdir()
 for n in ['docs/native-gameplay/ANIMATION_FRAME_EVENTS.md',Path(__file__).relative_to(ROOT).as_posix()]:
  p=seal/'source'/n;p.parent.mkdir(parents=True,exist_ok=True);p.write_bytes((ROOT/n).read_bytes());sources[n]=sha(p);copies[n]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p)}
 q=dict(schema=1,status='complete original573480 crossing and caller-step forwarding qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,physical_ps2_exceptional_parity=False,source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,preserved_unsealed_run='build-native-sjuni/animation-world-prelude-step-gcc-v1/receipt.json',limits=['Finite audited SDK arithmetic only; no game/performance claim.','Typed ModelReference transitive snapshot is recorded but its unrelated new behavior is not qualified by these animation tests.','Concrete573430 event family consumers and native game installation remain open.'])
 out=ROOT/'tools/native_reconstruction/native_animation_frame_events_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
