"""Seal actual constrained primary model plus resource-attachment composition."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 sources={};copies={};cohorts={};expected=None
 for compiler,directory in [('llvm','animation-constrained-attachments-llvm-v2'),('gcc','animation-constrained-attachments-gcc-v1')]:
  p=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and r['source_unchanged']
  if expected is None:expected=r
  assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed']
  assert r['observed']['attachment_cases']==1600 and r['observed']['raised_cases']==178
  for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h;sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
  for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
  cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'template_assets':r['template_assets'],'owned_floors':r['owned_floors'],'original_owned_bodies':[{k:v for k,v in proof.items()if k!='comparisons'}for proof in r['original_owned_bodies']]}
 smoke_path=ROOT/'build-native-sjuni/animation-world-driver-dependencies-llvm-v1/receipt.json';smoke=json.loads(smoke_path.read_bytes());assert smoke['status']=='passed'and smoke['source_unchanged']and smoke['observed']['checks']==14502490
 for n,h in smoke['source_sha256'].items():
  assert sha(ROOT/n)==h and sha(smoke_path.parent/'source'/n)==h
  if n in sources:assert sources[n]==h
  sources[n]=h;copies[n]={'path':(smoke_path.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
 for n,h in smoke['output_sha256'].items():assert sha(smoke_path.parent/n)==h
 seal=ROOT/'build-native-sjuni/animation-constrained-attachments-seal-v1';assert not seal.exists();seal.mkdir();deltas={}
 for filename,qname,added in [('verify_world_playback.py','native_animation_playback_qualification_v1.json',["'gameplay_world/linked_models.cpp',"]),('verify_attachments.py','native_animation_resource_attachments_qualification_v1.json',["'gameplay_world/linked_models.cpp',"]),('verify_model_poses.py','native_animation_models_qualification_v2.json',["'gameplay_world/model_constraints.cpp',","'gameplay_world/linked_models.cpp',","'animation/constraints.cpp',","'animation/constraint_math.cpp',"])]:
  previous=ROOT/'tools/native_reconstruction'/qname;old=json.loads(previous.read_bytes());n='tools/native_reconstruction/animation/'+filename;old_entry=old['immutable_source_evidence'][n];old_path=ROOT/old_entry['path'];assert sha(old_path)==old_entry['sha256'];text=(ROOT/n).read_text()
  for addition in added:text=text.replace(addition,'')
  assert text==old_path.read_text(),n
  deltas[n]={'old_immutable_source':old_entry,'new_sha256':sha(ROOT/n),'only_added_source_units':added}
  target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=sha(target);copies[n]={'path':target.relative_to(ROOT).as_posix(),'sha256':sha(target)}
 for n in ['docs/native-gameplay/ANIMATION_CONSTRAINED_ATTACHMENTS.md',Path(__file__).relative_to(ROOT).as_posix()]:
  target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=sha(target);copies[n]={'path':target.relative_to(ROOT).as_posix(),'sha256':sha(target)}
 q=dict(schema=1,status='complete primary constrained model followed by both actual resource attachments qualifies on both compilers within recorded profiles',game_run=False,installed_in_game=False,stage4_complete=False,production_algorithms_changed=False,active_constraint_resource_attachment_composition_qualified=True,physical_ps2_exceptional_parity=False,source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,driver_dependency_deltas=deltas,driver_smoke={'path':smoke_path.relative_to(ROOT).as_posix(),'sha256':sha(smoke_path),'compiler_scope':['llvm'],'observed':smoke['observed']},prerequisites={n:sha(ROOT/n)for n in ['tools/native_reconstruction/native_animation_linked_models_qualification_v1.json','tools/native_reconstruction/native_animation_resource_attachments_qualification_v1.json','tools/native_reconstruction/native_animation_models_qualification_v3.json']},limits=['Actual source/content/native ownership comparison only; no running-game installation, performance gain or Stage4 completion.','Same strict finite arithmetic, actual imported Skeleton/Clip/template/floor profiles and declared bounded source-copy/token/qualified617000 floor seams.','Concrete resource/model/texture creation and release,6BEA20 root-writer lifecycle, behavior/event prelude, full native frame/game installation and rendering remain separate gates.'])
 out=ROOT/'tools/native_reconstruction/native_animation_constrained_attachments_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
