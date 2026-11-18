"""Join sealed native model and canonical World consumer cohorts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 groups={'core':{'llvm':'animation-models-llvm-v4','gcc':'animation-models-gcc-v2'},'world':{'llvm':'animation-model-poses-llvm-v3','gcc':'animation-model-poses-gcc-v3'}};source={};immutable={};results={}
 for group,cohorts in groups.items():
  expected=None;results[group]={}
  for compiler,directory in cohorts.items():
   path=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(path.read_bytes());assert r['status']=='passed'and r['source_unchanged']
   if expected is None:expected=r
   assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed']
   for name,digest in r['source_sha256'].items():
    assert sha(ROOT/name)==digest and sha(path.parent/'source'/name)==digest,name
    if name in source:assert source[name]==digest,name
    source[name]=digest;immutable[name]=dict(path=(path.parent/'source'/name).relative_to(ROOT).as_posix(),sha256=digest)
   for name,digest in r['output_sha256'].items():assert sha(path.parent/name)==digest,name
   results[group][compiler]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=r['compiler_sha256'],observed=r['observed'],original_owned_bodies=[{k:v for k,v in x.items()if k!='comparisons'}for x in r['original_owned_bodies']])
 q=dict(schema=1,status='native owned skeleton/clip/joint/root model owner and concrete World model/body consumers qualify on both compilers with real assets',game_run=False,installed_in_game=False,stage4_complete=False,full_primary_constraints=False,full_animation_descriptor_blending=False,linked_object_and_active_attachments_complete=False,render_bind_inverse_palette_complete=False,physical_ps2_exceptional_parity=False,native_actor_shadow_copy=False,native_guest_or_register_state=False,cohorts=results,source_sha256=source,immutable_source_evidence=immutable,
  prerequisites={},extra_source_sha256={},limits=['Original resource18DCA0 resolver is an explicit owned-resource fixture seam; original model import/sample/math/root/timing chains execute.','Each Actor requires its own mutable Instance; immutable assets and snapshots can be shared. Calls belong to serialized gameplay owner.','Complete original standard/paused frameModel comparisons use attachment IDs zero; active attachments and linked objects are not claimed.','Unpaused primary without0x12 still requires actual typed constraint data; absent contexts never become fake all-disabled success.','Native joint snapshots serve gameplay; original constructor render bind-inverse computation executes only in the oracle and is not a native render-palette claim.','Full motion descriptor selection/bank transition/blending, typed constraints/callbacks, scene/object attachments, actual nativeWorld installation and game retest remain open.'])
 for name in ['tools/native_reconstruction/native_animation_curves_qualification_v1.json','tools/native_reconstruction/native_transform_math_qualification_v1.json','build-native-sjuni/animation-owned-corpus-v2/receipt.json','build-native-sjuni/model-scale-profile-v1/receipt.json']:
  p=ROOT/name;assert p.is_file();q['prerequisites'][name]=sha(p)
 for name in ['tools/native_reconstruction/animation/qualify_model_scale_profile.py','docs/native-gameplay/ANIMATION_MODELS.md',Path(__file__).relative_to(ROOT).as_posix()]:q['extra_source_sha256'][name]=sha(ROOT/name)
 profile=json.loads((ROOT/'build-native-sjuni/model-scale-profile-v1/receipt.json').read_bytes());assert sha(ROOT/'game/native/gameplay_world/model_scale_profile.inc')==profile['output_sha256'];q['model_scale_profile']=dict(player_types=8,named_npc_variants=125,loader_owned_words=profile['loader_owned_words'],name_table=profile['archive_name_table'])
 out=ROOT/'tools/native_reconstruction/native_animation_models_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(qualification=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
