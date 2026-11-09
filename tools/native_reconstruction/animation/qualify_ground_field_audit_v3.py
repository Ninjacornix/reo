"""Seal corrected174/54F export coverage without rewriting historical receipts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 results={};sources={};copies={};expected=None
 for compiler in ['llvm','gcc']:
  path=ROOT/f'build-native-sjuni/animation-ground-field-audit-{compiler}-v1/receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
  if expected is None:expected=r
  assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed']
  assert r['observed']['surface_one_queries']==480 and r['observed']['ground_cases']==800
  for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h and sha(path.parent/'source'/n)==h;sources[n]=h;copies[n]={'path':(path.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
  for n,h in r['output_sha256'].items():assert sha(path.parent/n)==h
  results[compiler]={'path':path.relative_to(ROOT).as_posix(),'sha256':sha(path),'observed':r['observed'],'compiler_sha256':r['compiler_sha256'],'original_owned_bodies':[{k:v for k,v in proof.items()if k!='comparisons'}for proof in r['original_owned_bodies']]}
 seal=ROOT/'build-native-sjuni/animation-ground-field-audit-seal-v3';assert not seal.exists();seal.mkdir()
 for n in ['docs/native-gameplay/ANIMATION_GROUND_FIELD_AUDIT.md',Path(__file__).relative_to(ROOT).as_posix()]:
  target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=sha(target);copies[n]={'path':target.relative_to(ROOT).as_posix(),'sha256':sha(target)}
 q=dict(schema=3,status='corrected original174 surface-kind branch coverage qualified on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,production_model_constraints_changed=False,previous_coverage_gap='v2 fixture exported surface_kind to54F and left174 zero; it did not cover174==1. Native implementation already uses canonical174 surface_kind. Corrected fixture separately exports54F motion_class and174 surface_kind.',cohorts=results,source_sha256=sources,immutable_source_evidence=copies,prerequisites={n:sha(ROOT/n)for n in ['tools/native_reconstruction/native_animation_models_qualification_v2.json','tools/native_reconstruction/native_animation_curves_qualification_v2.json','tools/native_reconstruction/native_animation_playback_qualification_v1.json']},limits=['Same finite native math/content/floor seam and inactive-attachment profiles as existing model v2 qualification.','No game, native runtime installation, physical PS2 exceptional parity, speedup or full Stage4 claim.'])
 out=ROOT/'tools/native_reconstruction/native_animation_models_qualification_v3.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
