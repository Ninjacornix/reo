"""Seal canonical fifty-node ownership and complete linked pose consumers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 groups={'linked':{'llvm':'animation-linked-models-llvm-v6','gcc':'animation-linked-models-gcc-v3'},'ground_after_prelude':{'llvm':'animation-ground-after-prelude-llvm-v3','gcc':'animation-ground-after-prelude-gcc-v3'}};sources={};copies={};results={}
 for group,cohorts in groups.items():
  results[group]={};expected=None
  for compiler,directory in cohorts.items():
   p=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and r['source_unchanged']
   if expected is None:expected=r
   assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed'],group
   for n,h in r['source_sha256'].items():
    assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h,n
    if n in sources:assert sources[n]==h,n
    sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
   for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
   results[group][compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'original_owned_bodies':[{k:v for k,v in proof.items()if k!='comparisons'}for proof in r['original_owned_bodies']]}
 prior=ROOT/'tools/native_reconstruction/native_animation_models_qualification_v3.json';old=json.loads(prior.read_bytes());name='game/native/gameplay_world/model_constraints.cpp';old_path=ROOT/old['immutable_source_evidence'][name]['path'];assert sha(old_path)==old['source_sha256'][name];needle='    const auto parent=matrix(actor.collision.basis);';old_tail=old_path.read_text().split(needle)[1];new_tail=(ROOT/name).read_text().split(needle)[1];assert old_tail==new_tail
 profile=ROOT/'build-native-sjuni/linked-model-profile-v1/receipt.json';pq=json.loads(profile.read_bytes());assert pq['status']=='passed'and sha(ROOT/pq['output_path'])==pq['output_sha256']
 seal=ROOT/'build-native-sjuni/animation-linked-models-seal-v1';assert not seal.exists();seal.mkdir()
 for n in ['docs/native-gameplay/ANIMATION_LINKED_MODELS.md','tools/native_reconstruction/animation/qualify_linked_model_profile_v1.py',Path(__file__).relative_to(ROOT).as_posix()]:
  target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=sha(target);copies[n]={'path':target.relative_to(ROOT).as_posix(),'sha256':sha(target)}
 q=dict(schema=1,status='canonical World-owned50linkedActorpool and complete linked pose traversal qualify on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,actor_shadow_copy=False,duplicate_actor_store=False,duplicate_pool_per_world=False,physical_ps2_exceptional_parity=False,cohorts=results,source_sha256=sources,immutable_source_evidence=copies,prerequisites={n:sha(ROOT/n)for n in ['tools/native_reconstruction/native_animation_models_qualification_v3.json','tools/native_reconstruction/native_animation_playback_qualification_v1.json','tools/native_reconstruction/native_animation_resource_attachments_qualification_v1.json','build-native-sjuni/linked-model-profile-v1/receipt.json']},primary_constraint_refactor={'previous_source_path':old_path.relative_to(ROOT).as_posix(),'previous_sha256':sha(old_path),'unchanged_5D6400_tail_sha256':hashlib.sha256(new_tail.encode()).hexdigest(),'primary_common_prelude_retained':True,'new_api':'rebuild_model_after_prelude','full_ground_regression':True},limits=['Canonical native World/entity ownership only; no running-game installation, renderer, speedup or full Stage4 claim.','376B80 full traversal/profile uses actual owned models with paused standard/5D6400 fast publication; unpaused active constraint behavior independently compared in full-ground regressions.','Native roots retain checked selected/observed IDs and require completed affine joint publication. Concrete6BEA20 root-writer and6BA5C0/6BA790 resource/model creation are not ported here.','No individual source pool-budget recycle is invented; explicit reset restores50. Native entity retirement independently prevents stale lookup.','Bounded zero fill, token identity and qualified floor617000 remain explicit oracle seams; original control/model/math/trig bodies execute fully.','Active constrained resource-attachment composition remains the next integration gate.'])
 out=ROOT/'tools/native_reconstruction/native_animation_linked_models_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
