"""Seal the shared128 owner; preserve all original and private source receipts."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 cohorts={
 'allocator':['gameplay-shared-record-pool-llvm-v1','gameplay-shared-record-pool-gcc-v1'],
 'cross_consumer':['gameplay-shared-scene-owner-llvm-v3','gameplay-shared-scene-owner-gcc-v1'],
 'full_vm':['gameplay-scenario-llvm-v36','gameplay-scenario-gcc-v26'],
 'existing_proxy_oracle':['gameplay-unified-proxies-llvm-v1','gameplay-unified-proxies-gcc-v1']}
 results={};closures={}
 for role,names in cohorts.items():
  results[role]=[]
  for name in names:
   folder=ROOT/'build-native-sjuni'/name;path=folder/'receipt.json';r=json.loads(path.read_text());assert r['status']in['passed','native collision owner/model geometry/caller comparisons passed']
   for source,digest in r['source_sha256'].items():
    snapshot=folder/'source'/source
    if snapshot.exists():assert sha(snapshot)==digest
   result=r.get('result',r.get('results'));results[role].append(dict(receipt=path.relative_to(ROOT).as_posix(),receipt_sha256=sha(path),compiler_sha256=r['compiler_sha256'],result=result,source_sha256=r['source_sha256']))
  a,b=results[role]
  assert a['compiler_sha256']!=b['compiler_sha256']and a['result']==b['result']
  closures[role]=a['source_sha256']
 for role in ['cross_consumer','full_vm']:assert all(sha(ROOT/name)==digest for name,digest in closures[role].items()if name in production)
 own={name:sha(ROOT/name)for name in production}
 for role in ['cross_consumer','full_vm']:
  assert all(closures[role][name]==digest for name,digest in own.items()if name in closures[role])
 asset=ROOT/'build-native-sjuni/gameplay-shared-proxy-assets-v1/receipt.json';ar=json.loads(asset.read_text());assert ar['status']=='passed'and ar['rooms']==166 and ar['records']==2144
 result=dict(schema=1,status='qualified_native_shared_owner_not_installed',production_sha256=own,cohorts=results,asset_inventory=dict(receipt=asset.relative_to(ROOT).as_posix(),sha256=sha(asset),rooms=166,base_records=2144,maximum_base_records=39),capacity=128,canonical_identity=True,canonical_activation=True,canonical_priority=True,canonical_type_payload=True,canonical_order=True,retained_invocation_leases=True,collision_snapshot_revision_invalidation=True,new_opcode_admissions=0,game_launched=False,live_process_access=False,installed_in_game=False,stage4_complete=False,limitations=['Complete5C1390 importer and original helper/resource initialization remain required; inventory counts omit helper-created/runtime records.','Standalone SceneControls append preserves its earlier traversal order by inserting at oldest; the actual importer must explicitly use newest as5C11B0(0).','Collision get pointers are derived synchronous projections and must not be retained across mutation; use acquire for strong invocation lifetime.','Simulation owner serializes access and calls RecordPool.touch before direct canonical edits; no cross-thread safety claimed.','Missing collision geometry remains inactive; typed command fixtures do not manufacture admitted room collision.','Full-word P58/P60 storage is shared; matrix selector narrows to its original low-byte kind. Existing fixture/oracle profiles and numeric limitations remain.','Five initial table0 model references areFF; their source adjacent matrix-work alias is an explicit importer-admission frontier, not an invented valid model or an established runtime incident.','Other agents may extend transitive native modules after these sealed snapshots; these receipts qualify their exact captured sources, not later changes.'],retained_failed_fixtures=['gameplay-shared-scene-owner-llvm-v1: test tried bool(EntityCreated); production unaffected.'],historical_checkpoint='3004bfb5 prior opcode131 v17; all prior receipts remain independent')
 dest=ROOT/'tools/native_reconstruction/native_gameplay_shared_scene_records_qualification_v1.json';assert not dest.exists();dest.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(status=result['status'],qualification=str(dest.relative_to(ROOT)),sha256=sha(dest))))
production=['game/native/gameplay_scene/record_pool.hpp','game/native/gameplay_scene/records.hpp','game/native/gameplay_scenario/scene_control_types.hpp','game/native/gameplay_scenario/scene_controls.hpp','game/native/gameplay_scenario/scene_controls.cpp','game/native/gameplay_collision/ownership.hpp','game/native/gameplay_collision/ownership.cpp','game/native/gameplay_scenario/periodic_effects.cpp']
if __name__=='__main__':main()
