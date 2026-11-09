"""Seal real scenario template ownership and original actor attachment consumers."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 sources={};copies={};cohorts={};expected=None
 for compiler,directory in [('llvm','animation-attachments-llvm-v2'),('gcc','animation-attachments-gcc-v1')]:
  p=ROOT/'build-native-sjuni'/directory/'receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'and r['source_unchanged']
  if expected is None:expected=r
  assert r['source_sha256']==expected['source_sha256']and r['observed']==expected['observed']
  for n,h in r['source_sha256'].items():assert sha(ROOT/n)==h and sha(p.parent/'source'/n)==h;sources[n]=h;copies[n]={'path':(p.parent/'source'/n).relative_to(ROOT).as_posix(),'sha256':h}
  for n,h in r['output_sha256'].items():assert sha(p.parent/n)==h
  cohorts[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'compiler_sha256':r['compiler_sha256'],'observed':r['observed'],'template_assets':r['template_assets'],'original_owned_bodies':[{k:v for k,v in proof.items()if k!='comparisons'}for proof in r['original_owned_bodies']]}
 regressions={};previous=None
 for compiler in ['llvm','gcc']:
  p=ROOT/f'build-native-sjuni/scene-resources-attachment-regression-{compiler}-v1/receipt.json';r=json.loads(p.read_bytes());assert r['status']=='passed'
  if previous is None:previous=r
  assert r['source_sha256']==previous['source_sha256']and r['result']==previous['result']
  for n,h in (r['source_sha256']|r['original_sources_sha256']).items():
   assert sha(ROOT/n)==h and sha(p.parent/Path(n).name)==h
   if n in sources:assert sources[n]==h
   sources[n]=h;copies[n]={'path':(p.parent/Path(n).name).relative_to(ROOT).as_posix(),'sha256':h}
  regressions[compiler]={'path':p.relative_to(ROOT).as_posix(),'sha256':sha(p),'observed':r['result'],'compiler_sha256':r['compiler_sha256']}
 seal=ROOT/'build-native-sjuni/animation-attachments-seal-v1';assert not seal.exists();seal.mkdir()
 for n in ['docs/native-gameplay/ANIMATION_RESOURCE_ATTACHMENTS.md','tools/native_reconstruction/animation/qualify_attachment_profile_v1.py',Path(__file__).relative_to(ROOT).as_posix()]:
  target=seal/'source'/n;target.parent.mkdir(parents=True,exist_ok=True);target.write_bytes((ROOT/n).read_bytes());sources[n]=sha(target);copies[n]={'path':target.relative_to(ROOT).as_posix(),'sha256':sha(target)}
 q=dict(schema=1,status='native runtime-loaded resource templates and actual actor attachment transforms qualify on both compilers',game_run=False,installed_in_game=False,stage4_complete=False,actor_shadow_copy=False,duplicate_logical_resource_owner=False,linked_actor_models_complete=False,physical_ps2_exceptional_parity=False,source_sha256=sources,immutable_source_evidence=copies,cohorts=cohorts,scene_resource_regressions=regressions,prerequisites={n:sha(ROOT/n)for n in ['tools/native_reconstruction/native_animation_playback_qualification_v1.json','tools/native_reconstruction/native_animation_models_qualification_v3.json','build-native-sjuni/attachment-profile-v2/receipt.json','build-native-sjuni/audio-asset-inventory/file1-v1/members.json']},limits=['ResourceModel creation requires explicit admitted matrices/position/flags from the actual resource owner; full construction/release remains a separate gate.','Styles0/1,64file-backed action rows, completed model publication and bounded runtime template indices only; unknown capabilities and invalid/stale owners refuse.','Complete original3769F0 consumer comparison uses paused/standard model route. Active constrained composition remains open, independently qualified constraints have inactive resource attachments.','Original counted byte copy and resource token identity are explicit bounded test seams. All actual curve/model/trig/matrix and template-control bodies execute.','Runtime-loaded template catalog74BB50 is imported from five actual item.dat sections, never treated as file-backed o2 bytes.','No game run, full native world, speedup or Stage4 closure.'])
 out=ROOT/'tools/native_reconstruction/native_animation_resource_attachments_qualification_v1.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps({'path':out.relative_to(ROOT).as_posix(),'sha256':sha(out)}))
if __name__=='__main__':main()
