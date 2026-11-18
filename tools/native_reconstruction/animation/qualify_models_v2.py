"""Seal native model constraints, complete ground consumer and unchanged-model regressions."""
import hashlib,json,re,sys
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3];sys.path.insert(0,str(ROOT/'tools/native_reconstruction'))
from audit_retail_effect_descriptors import compare_source
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()

def main():
 groups={'model_regression':{'llvm':'animation-models-llvm-v5','gcc':'animation-models-gcc-v3'},'world_body_regression':{'llvm':'animation-model-poses-llvm-v4','gcc':'animation-model-poses-gcc-v4'},'constraint_core':{'llvm':'animation-constraints-llvm-v2','gcc':'animation-constraints-gcc-v2'},'ground':{'llvm':'animation-ground-constraints-llvm-v4','gcc':'animation-ground-constraints-gcc-v1'}}
 source={};immutable={};results={}
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
 overlay=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';data=overlay.read_bytes();creators=[]
 for at,sites in [(0x66a750,[0x66ab78,0x66ab9c]),(0x5eec50,[0x5eeee4,0x5eefa4]),(0x5f0610,[0x5f0708,0x5f07f8,0x5f09d8])]:
  p=next((ROOT/'recomp/config/output_ovl/o2').glob(f'o2_{at:08X}_*'));body=p.read_text();begin,end=[int(v,16)for v in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',body).groups()];proof=compare_source('complete original behavior-owned mirrored constraint creation caller',p.relative_to(ROOT).as_posix(),begin,end,lambda at,n:data[at-0x570000:at-0x570000+n]);assert [int(v,16)for v in re.findall(r'// (0x[0-9a-f]+): 0x[0-9a-f]+\s+jal\s+func_5D6850',body)]==sites
  creators.append(dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),sites=[hex(x)for x in sites],owned_words=proof))
 writes=[]
 for base in [ROOT/'recomp/config/output',ROOT/'recomp/config/output_ovl/o2']:
  for p in base.glob('*.cpp'):
   for line in p.read_text().splitlines():
    if re.search(r'\bsh\s+.*0x82\(',line):writes.append(dict(path=p.relative_to(ROOT).as_posix(),instruction=line.strip(),sha256=sha(p)))
 assert len(writes)==1 and writes[0]['path']=='recomp/config/output_ovl/o2/o2_005D5FA0_0x5d5fa0.cpp'
 q=dict(schema=2,status='native model constraints, behavior-owned mirrored creation and complete primary ground target consumer qualify on both compilers with owned model/motion/floor assets',game_run=False,installed_in_game=False,stage4_complete=False,full_primary_constraints=True,full_animation_descriptor_blending=False,linked_object_and_active_attachments_complete=False,render_bind_inverse_palette_complete=False,physical_ps2_exceptional_parity=False,native_actor_shadow_copy=False,native_guest_or_register_state=False,cohorts=results,source_sha256=source,immutable_source_evidence=immutable,behavior_owned_creation=creators,direct_context_offset_82_halfword_store_scan=writes,prerequisites={},extra_source_sha256={},limits=[
 'Original18DCA0 is an explicit owned-resource fixture resolver seam; complete original packing, model, math, creation, callbacks and ground policy execute.',
 'Original616F20 executes with native617000 Grid seam; separate independently qualified response cohort supplies original617000/grid verification. Five hash-checked real floor members are read at recorded ISO offsets.',
 'Full frameModel comparisons declare zero active attachments. Native attachments, linked-object model ownership, descriptor/bank selection/blending and runtime installation remain separate gates.',
 'Finite strict FP32 RNE/gradual-underflow/contraction-off profile; physical PS2 exceptional semantics not claimed.',
 'Canonical Actor.model/Actor.constraints exact identity is required; native contexts never retarget externally retained old model owners.',
 'Missing context ownership is unavailable, not presumed disabled. Known-zero contexts and signed nonzero pause paths admit standard publication.',
 'Generic modes1/2, all seven contexts and actual first-two creators are implemented. Additional enabled contexts2..6 cannot be recreated on model replacement without their original creator.',
 'Direct-store source scan is bounded to aligned halfword instructions with offset82 in main/o2, not proof about arbitrary aliases/full-word/block writes. No invented enable/disable producer is claimed.',
 'Category>2 with surface_kind1 inherits an unassigned original mask register and is explicitly refused.',
 'Mutable Instance and Constraints operations belong to the serialized native gameplay owner; immutable definitions and completed snapshots can be retained.'])
 for name in ['tools/native_reconstruction/native_animation_models_qualification_v1.json','tools/native_reconstruction/native_animation_curves_qualification_v1.json','tools/native_reconstruction/native_transform_math_qualification_v1.json','build-native-sjuni/animation-owned-corpus-v2/receipt.json','build-native-sjuni/model-scale-profile-v1/receipt.json','build-native-sjuni/gameplay-collision-response-llvm-v7/receipt.json']:
  p=ROOT/name;assert p.is_file();q['prerequisites'][name]=sha(p)
 for name in ['docs/native-gameplay/ANIMATION_CONSTRAINTS.md',Path(__file__).relative_to(ROOT).as_posix()]:q['extra_source_sha256'][name]=sha(ROOT/name)
 out=ROOT/'tools/native_reconstruction/native_animation_models_qualification_v2.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(qualification=out.relative_to(ROOT).as_posix(),sha256=sha(out))))
if __name__=='__main__':main()
