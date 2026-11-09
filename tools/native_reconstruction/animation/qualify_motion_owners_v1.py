"""Seal complete native motion content owners and exact pose-bank consumers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 groups={'banks':{'llvm':'animation-motion-banks-llvm-v4','gcc':'animation-motion-banks-gcc-v3'},'descriptors':{'llvm':'animation-motion-descriptors-llvm-v3','gcc':'animation-motion-descriptors-gcc-v1'},'pose_blending':{'llvm':'animation-pose-blending-llvm-v6','gcc':'animation-pose-blending-gcc-v1'}};sources={};copies={};results={}
 for group,cohorts in groups.items():
  results[group]={};expected=None
  for compiler,directory in cohorts.items():
   path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
   if expected is None:expected=r
   assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed']
   for n,h in r['source_sha256'].items():
    assert sha(ROOT/n)==h and sha(path.parent/'source'/n)==h,n
    if n in sources:assert sources[n]==h,n
    sources[n]=h;copies[n]=dict(path=(path.parent/'source'/n).relative_to(ROOT).as_posix(),sha256=h)
   for n,h in r['output_sha256'].items():assert sha(path.parent/n)==h,n
   results[group][compiler]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=r['compiler_sha256'],observed=r['observed'],original_owned_bodies=[{k:v for k,v in x.items()if k!='comparisons'}for x in r['original_owned_bodies']])
 previous=ROOT/'tools/native_reconstruction/native_animation_models_qualification_v2.json';old=json.loads(previous.read_bytes());modelcpp='game/native/animation/model.cpp';header='game/native/animation/model.hpp';assert sha(ROOT/modelcpp)==old['source_sha256'][modelcpp];old_header=ROOT/old['immutable_source_evidence'][header]['path'];assert sha(old_header)==old['source_sha256'][header];assert (ROOT/header).read_text().replace('    friend class PoseBlend;\n','')==old_header.read_text()
 q=dict(schema=1,status='native complete sparse/strided motion banks, concrete descriptor lookup/unpack and model-bank pose/link capture/blending qualify on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,full_actor_motion_application=False,full_actor_track_tick_orchestration=False,linked_objects_and_active_attachments_complete=False,native_guest_or_register_state=False,actor_shadow_copy=False,physical_ps2_exceptional_parity=False,cohorts=results,source_sha256=sources,immutable_source_evidence=copies,model_change='single additional PoseBlend friendship; model.cpp and all existing behavior byte-identical to v2',prerequisites={},extra_sources={},limits=['Original bank raw packing, token duplication and release are explicit provenance/identity seams; native shared ownership replaces those resource identities. Existing real Clip oracle qualifies actual parsing/sampling independently.','Concrete immutable File1 descriptor profile is bounded to its recorded table extents and resource action IDs0..63; unsupported indices fail rather than reading adjacent unrelated data.','Whole-bank bytes come from actual owned archives; duplicate cutscene basenames do not identify a specific room.','Mutable bank/Instance operations and lazy Clip decode belong to the serialized native resource/simulation owner. Corresponding model banks retain one immutable Skeleton identity.','Actor descriptor application, track transition/tick composition, collision metadata application, dual-bank orchestration and linked-object/attachment consumers remain open.','Finite strict FP32 RNE/gradual-underflow/contraction-off profile only; physical PS2 exceptional behavior is not claimed.'])
 for n in ['tools/native_reconstruction/native_animation_models_qualification_v2.json','tools/native_reconstruction/native_animation_curves_qualification_v1.json','build-native-sjuni/animation-owned-corpus-v2/receipt.json','build-native-sjuni/motion-descriptor-profile-v1/receipt.json']:
  q['prerequisites'][n]=sha(ROOT/n)
 for n in ['docs/native-gameplay/ANIMATION_BANKS_AND_DESCRIPTORS.md','tools/native_reconstruction/animation/qualify_motion_descriptor_profile.py',Path(__file__).relative_to(ROOT).as_posix()]:q['extra_sources'][n]=sha(ROOT/n)
 out=ROOT/'tools/native_reconstruction/native_animation_motion_owners_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
