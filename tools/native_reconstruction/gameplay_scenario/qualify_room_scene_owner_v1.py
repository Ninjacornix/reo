"""Publish the exact qualified room-import boundary and its explicit remainder."""
import hashlib,json
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
OWN=['game/native/gameplay_scenario/'+n for n in ['room_scene_input.hpp','room_scene_input.cpp','room_scene_owner.hpp','room_scene_owner.cpp','scene_controls.cpp','scene_matrix_programs.hpp']]+['game/native/gameplay_scene/records.hpp','game/native/gameplay_collision/ownership.cpp']
def main():
 cohorts={'room_initializer':['gameplay-room-scene-owner-llvm-v6','gameplay-room-scene-owner-gcc-v1'],'shared_views':['gameplay-shared-scene-owner-llvm-v4','gameplay-shared-scene-owner-gcc-v2'],'full_vm':['gameplay-scenario-llvm-v37','gameplay-scenario-gcc-v27']};result={};closures={}
 for role,names in cohorts.items():
  result[role]=[]
  for name in names:
   folder=ROOT/'build-native-sjuni'/name;path=folder/'receipt.json';r=json.loads(path.read_text());assert r['status']=='passed'
   for source,digest in r['source_sha256'].items():assert sha(folder/'source'/source)==digest
   for source,digest in r.get('original_source_sha256',{}).items():assert sha(folder/'source'/source)==digest
   result[role].append(dict(receipt=path.relative_to(ROOT).as_posix(),receipt_sha256=sha(path),compiler_sha256=r['compiler_sha256'],result=r['result'],source_sha256=r['source_sha256'],pinned_shared_sources=r.get('pinned_shared_sources',{}),pinned_current_source_drift=r.get('pinned_current_source_drift',{})))
  a,b=result[role];assert a['compiler_sha256']!=b['compiler_sha256']and a['result']==b['result']and a['source_sha256']==b['source_sha256'];closures[role]=a['source_sha256']
  if role=='room_initializer':
   for name in names:
    errors=(ROOT/'build-native-sjuni'/name/'run.stderr.txt').read_text().splitlines();assert errors==['Explicit stock profile refusal '+n+' status 3'for n in ['r0010100.rdt','r0012200.rdt','r0417300.rdt']]
 assert result['room_initializer'][0]['result']['stock_rooms']==166 and result['room_initializer'][0]['result']['stock_records']==2144
 for row in result['full_vm']:
  pins=row['pinned_shared_sources'];assert len(pins)==10
  for name,item in pins.items():assert item['commit']==('89e073ff'if'/gameplay_effects/'in name else'd6f2df32')and item['sha256']==row['source_sha256'][name]
 current={name:sha(ROOT/name)for name in OWN}
 for name,digest in current.items():
  assert closures['room_initializer'][name]==digest
  for role in ['shared_views','full_vm']:
   if name in closures[role]:assert closures[role][name]==digest
 corpus=ROOT/'build-native-sjuni/gameplay-room-scene-assets-v1/receipt.json';c=json.loads(corpus.read_text());assert c['status']=='passed'and c['rooms']==166 and c['base_records']==2144
 q=dict(schema=1,status='qualified_native_room_initializer_profile_not_installed',production_sha256=current,cohorts=result,asset_corpus=dict(receipt=corpus.relative_to(ROOT).as_posix(),receipt_sha256=sha(corpus),package_sha256=c['package_sha256']),original_entrypoints=['5C1120','5C11B0','5C12A0','5C1390','5C45C0','5C5D30','5C6100','5C66C0','5819C0','1900E0','191430','1919D0','1920A0','o0_370500','o0_370570'],initialized_identity_profile=dict(address='294E00',static_source_authority='195E50',bootstrap_dynamically_executed=False),native_capacity=128,stock_rooms_parsed=166,stock_base_records_parsed=2144,stock_rooms_admitted_under_controlled_external_poses=163,stock_rooms_refused_before_effects=['r0010100.rdt','r0012200.rdt','r0417300.rdt'],stock_room_model_construction_qualified=False,all_type_consumers_migrated=False,new_opcode_admissions=0,game_launched=False,live_process_access=False,installed_in_game=False,stage4_complete=False,limitations=['Native initializer owns known typed control/collision state, native84/85 helpers and middle-corner reprojection; remaining normal type callbacks/task/renderer consumers are not advertised as migrated.','External model poses are explicitly constructed test states, not recovered full room model construction. Importing an RDT does not manufacture live scene entities.','FiveFF references in three rooms require a separate legacy-alias investigation; no Model255 or256-entry sound-map shadow is created.','FullwordP58/P60 state remains shared. Missing typedP48 metadata cannot resurrect a stale fallback; its collision view is unavailable/inactive.','Source_type and model sound writes use canonical owners; installer requires matching controls/proxies/programs/models, empty shared pool, valid arithmetic/capacity, and serialized simulation ownership.','Nonempty-pool, stale, closed, FF, invalid-channel, degenerate-pose and malformed-section cases preserve state before refusal; allocation failure after partial pool admission retires the newly admitted IDs before returning.','RoomSceneOwner.close retires its own base/helper IDs; it does not reset external model sounds, matrix programs, flags, globals, or newly reused records owned elsewhere. Actual room teardown/reset composition remains required.','RoomSceneInput definitions retain immutable authored initial state for later typed consumers, never a parallel mutable runtime registry.','The VM explicitly pins qualified World/SceneResources and periodic effects source closures while other agents extend them; these cohorts do not qualify the newer general effect backend or attachment work.','Original finite/SIMD/SDK131 numeric surroundings and initialized identity are declared test profiles; no physical PS2 exceptional arithmetic, perceptual, performance or gameplay acceptance claim.'],retained_history=['LLVMv1: first whole-room projection comparison failed.','LLVMv2/v3: diagnostics isolated new parser selector offsets; type6P54/type7P70 corrected to input44/input60.','LLVMv4:64controlled rooms passed.','LLVMv5:all166ownedinputs parsed,163admitted under controlled poses,3explicit refusals; final v6 adds query/rollback/malformed/missing-field coverage.'])
 dest=ROOT/'tools/native_reconstruction/native_gameplay_room_scene_import_qualification_v1.json';assert not dest.exists();dest.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(status=q['status'],qualification=dest.relative_to(ROOT).as_posix(),sha256=sha(dest))))
if __name__=='__main__':main()
