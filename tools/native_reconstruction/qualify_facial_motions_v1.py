"""Seal actual facial assets, curves, actor ownership and corrected caller binding."""
import argparse,hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda path:hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--parents-pattern',required=True);a=p.parse_args()
 sources=['game/native/animation/facial_curves.hpp','game/native/animation/facial_curves.cpp','game/native/animation/CMakeLists.txt','game/native/gameplay_scenario/facial_assets.hpp','game/native/gameplay_scenario/facial_assets.cpp','game/native/gameplay_scenario/facial_asset_catalogue.inc','game/native/gameplay_scenario/facial_motions.hpp','game/native/gameplay_scenario/facial_motions.cpp','game/native/gameplay_scenario/facial_motions_assets_tests.cpp','game/native/gameplay_scenario/cutscene_playback.hpp','game/native/gameplay_scenario/cutscene_playback.cpp','game/native/gameplay_scenario/CMakeLists.txt','tools/native_reconstruction/animation/facial_curves_tests.cpp','tools/native_reconstruction/animation/verify_facial_curves.py','tools/native_reconstruction/audit_facial_resources.py','tools/native_reconstruction/facial_assets_tests.cpp','tools/native_reconstruction/verify_facial_assets.py','tools/native_reconstruction/facial_motions_tests.cpp','tools/native_reconstruction/verify_facial_motions.py','tools/native_reconstruction/verify_facial_motions_current.py','tools/native_reconstruction/qualify_facial_motions_v1.py','docs/native-gameplay/FACIAL_MOTIONS.md']
 current={name:sha(ROOT/name)for name in sources};loaded=[];receipts={}
 for role,pattern in [('curves','facial-curves-{}-v2'),('assets','facial-assets-{}-v1'),('owner_caller','facial-motions-{}-v6'),('current_assets','facial-motions-current-{}-v1'),('current_parents',a.parents_pattern)]:
  for compiler in ['llvm','gcc']:
   path=ROOT/'build-native-sjuni'/pattern.format(compiler)/'receipt.json';value=json.loads(path.read_bytes());assert value['status']=='passed'and value.get('source_unchanged',True)and not value.get('source_drift')and not value.get('owned_source_drift')
   for proof in value.get('original_owned_bodies',[]):assert proof['conflicts']==0 and proof['matched_comments']>0
   key=role+'_'+compiler;loaded.append((key,value));receipts[key]=dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),compiler_sha256=value.get('compiler_sha256'),observed=value.get('observed',value.get('result')),parent_tests=value.get('parent_tests'),source_drift=value.get('source_drift',value.get('owned_source_drift')))
 inventory=ROOT/'build-native-sjuni/facial-resource-inventory-v2/receipt.json';value=json.loads(inventory.read_bytes());assert value['status']=='passed'and value['tool_sha256']==current['tools/native_reconstruction/audit_facial_resources.py'];assert value['maximum_preload_requests']==2 and value['worst_case_lip_end']==0xd800
 matches={}
 for name,digest in current.items():
  if name.startswith('docs/')or name.endswith('qualify_facial_motions_v1.py')or name.endswith('audit_facial_resources.py'):continue
  matches[name]=[key for key,value in loaded if value.get('source_sha256',{}).get(name)==digest];assert matches[name],name
 record=dict(schema=1,status='passed',scope='Actual File1 facial namespace/sector workspace, five curves, eight-instance reset/preload/claim/update, native model track4 world-pose patching and corrected5EEC50 cue binding.',game_run=False,device_opened=False,installed_in_game=False,stage4_complete=False,source_sha256=current,matching_qualified_snapshots=matches,inventory=dict(path=inventory.relative_to(ROOT).as_posix(),sha256=sha(inventory)),receipts=receipts,limits=[
 'Twelve complete original entries execute in the owner/caller comparison. Formatter10A830, SDK sector transfer1CC8F0 and the failed voice boundary1ADB30 are declared fixture ports in that cohort. The separate actual File1 reader compares every sector byte; SDK scheduling and complete real speech playback are not claimed.',
 'All33 actual LIPs, all18 actual MAT/base-NBD pairs and all548 descriptor preload bounds are inventoried. Actual caller admission consumes six track4 nodes; HP03/HN39 unused nonfinite ordinal6 remains preserved. Finite consumed FP32 and increasing-time profile only; no physical PS2 exceptional arithmetic claim.',
 'The bounded64KiB asset workspace preserves physical sector overlap and old bytes. All32LIP metadata records execute; the unsafe33rd original aliasing route refuses. Matrix capacity beyond8, arbitrary replacement assets or unproved caller metadata remain outside profile.',
 'The actual controller now passes current.area for38ECD0. Claim is admitted during the original actor-track traversal while its own running/closed/sole-binding guards remain. A failed voice callback preserves its real facial prefix and returns unavailable overall.',
 'The worker tick still belongs to actual5FF1B0 after6BBBA0; full outer orchestration, concrete speech consumer, complete scene entry/movie/renderer services and fullStep4 application installation remain separate work.',
 ])
 path=ROOT/'tools/native_reconstruction/native_facial_motions_qualification_v1.json';path.write_text(json.dumps(record,indent=2)+'\n');print(json.dumps(dict(status='passed',receipts=len(receipts),sources=len(sources),seal_sha256=sha(path))))
if __name__=='__main__':main()
