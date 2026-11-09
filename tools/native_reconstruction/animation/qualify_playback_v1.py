"""Seal source/content-qualified native actor motion playback and its curve admission correction."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 groups={
  'playback':{'llvm':'animation-playback-llvm-v17','gcc':'animation-playback-gcc-v2'},
  'world':{'llvm':'animation-world-playback-llvm-v9','gcc':'animation-world-playback-gcc-v3'},
  'curves':{'llvm':'animation-curves-unused-tangents-llvm-v1','gcc':'animation-curves-unused-tangents-gcc-v1'},
  'descriptors':{'llvm':'animation-motion-descriptors-llvm-v4','gcc':'animation-motion-descriptors-gcc-v5'},
  'pose_blending':{'llvm':'animation-pose-blending-playback-llvm-v1','gcc':'animation-pose-blending-playback-gcc-v1'}}
 sources={};copies={};results={}
 for group,cohorts in groups.items():
  results[group]={};expected=None
  for compiler,directory in cohorts.items():
   path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
   if expected is None:expected=r
   assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed'],group
   for n,h in r['source_sha256'].items():
    assert sha(ROOT/n)==h and sha(path.parent/'source'/n)==h,n
    if n in sources:assert sources[n]==h,n
    sources[n]=h;copies[n]=dict(path=(path.parent/'source'/n).relative_to(ROOT).as_posix(),sha256=h)
   for n,h in r['output_sha256'].items():assert sha(path.parent/n)==h,n
   results[group][compiler]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=r['compiler_sha256'],observed=r['observed'],original_owned_bodies=[{k:v for k,v in x.items()if k!='comparisons'}for x in r['original_owned_bodies']])
 seal=ROOT/'build-native-sjuni/animation-playback-seal-v1';assert not seal.exists();seal.mkdir()
 extras=['docs/native-gameplay/ANIMATION_PLAYBACK.md','tools/native_reconstruction/animation/qualify_motion_body_profile.py','tools/native_reconstruction/animation/qualify_motion_descriptor_profile_v2.py',Path(__file__).relative_to(ROOT).as_posix()]
 for n in extras:
  h=sha(ROOT/n);target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=h;copies[n]=dict(path=target.relative_to(ROOT).as_posix(),sha256=h)
 prerequisites={n:sha(ROOT/n)for n in ['tools/native_reconstruction/native_animation_motion_owners_qualification_v1.json','tools/native_reconstruction/native_animation_models_qualification_v2.json','tools/native_reconstruction/native_animation_curves_qualification_v1.json','build-native-sjuni/animation-owned-corpus-v2/receipt.json','build-native-sjuni/motion-descriptor-profile-v2/receipt.json','build-native-sjuni/motion-body-profile-v1/receipt.json','build-native-sjuni/animation-unused-tangent-previous-v1/receipt.json']}
 previous=json.loads((ROOT/'build-native-sjuni/animation-unused-tangent-previous-v1/receipt.json').read_bytes())
 for n,h in previous['source_sha256'].items():assert sha(ROOT/'build-native-sjuni/animation-unused-tangent-previous-v1'/Path(n).name)==h
 curve_path=ROOT/'tools/native_reconstruction/native_animation_curves_qualification_v2.json';assert not curve_path.exists()
 curve=dict(schema=2,status='qualified narrow sole-key unused tangent admission; used numeric guards remain active',game_run=False,installed_in_game=False,stage4_complete=False,cohorts=results['curves'],source_sha256={n:h for n,h in sources.items()if n in json.loads((ROOT/'build-native-sjuni/animation-curves-unused-tangents-llvm-v1/receipt.json').read_bytes())['source_sha256']},immutable_source_evidence={n:copies[n]for n in json.loads((ROOT/'build-native-sjuni/animation-curves-unused-tangents-llvm-v1/receipt.json').read_bytes())['source_sha256']},previous_source=previous,previous_source_receipt={'path':'build-native-sjuni/animation-unused-tangent-previous-v1/receipt.json','sha256':prerequisites['build-native-sjuni/animation-unused-tangent-previous-v1/receipt.json']},scope='For count1 only, tangent payloads are unobserved by the full original sole-key sampling branch. Native import omits them rather than rejecting authored NaN/Inf bits. Finite value/time and all used multi-key tangent checks remain.',physical_ps2_exceptional_parity=False)
 curve_path.write_text(json.dumps(curve,indent=2)+'\n');prerequisites[curve_path.relative_to(ROOT).as_posix()]=sha(curve_path)
 q=dict(schema=1,status='qualified native actor motion descriptor application, selection, channel configuration/root/dual playback within explicit content and provider profiles',game_run=False,installed_in_game=False,stage4_complete=False,native_guest_or_register_state=False,actor_shadow_copy=False,physical_ps2_exceptional_parity=False,actual_573430_behavior_prelude_ported=False,attachments_complete=False,cohorts=results,source_sha256=sources,immutable_source_evidence=copies,prerequisites=prerequisites,concrete_descriptor_profile={'root_records':568,'single_level_admitted_records':768,'storage_extent':1112,'unreferenced_holes_refused':344,'resource_classes':64,'character_subtype_bound':8},provider_lifetime='Strong invocation leases plus exact current actor generation/model checks after synchronous body/shape metadata and required behavior prelude; no retarget to retired owner',limits=['573430 category-specific behavior/event prelude requires an explicit nondefault concrete provider; the oracle uses a declared side-effecting seam.','Only current native primary actor slots support encoded related-actor category/slot resolution; other real actor pools remain unported and refuse. Direct B24 identity is generation checked.','Known unloaded resource is distinct from unknown loading/admission; the latter refuses. Invalid family15 preserves the source cache prefix then refuses undefined original saved-register return.','Collision body word-offset0 and eight verified profiles only; undefined category>1 descriptor body registers refuse.','Strict finite FP32 RNE/gradual underflow/contraction-off profile only. Sole-key unobserved tangent payloads are omitted; used nonfinite tangents still refuse.','Real immutable PC000/PC001/d00/d01 content is compared against owned original bodies. Duplicate basenames do not establish a room or movie identity.','Attachment/linked-object ownership, full resource creation/loading integration, concrete behavior providers and runtime installation remain open. No game run, speedup or complete native actor/world claim.'])
 out=ROOT/'tools/native_reconstruction/native_animation_playback_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),curve_sha256=sha(curve_path))))
if __name__=='__main__':main()
