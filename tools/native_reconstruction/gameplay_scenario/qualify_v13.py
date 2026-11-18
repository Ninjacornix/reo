"""Freeze real model target ownership and checked room-object lifetime consumers."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def observed(d):return d.get('result',d.get('results'))
def main():
 names=['gameplay-scenario-llvm-v26','gameplay-scenario-gcc-v18','gameplay-model-bindings-llvm-v2','gameplay-model-bindings-gcc-v2','gameplay-model-lifetime-llvm-v2','gameplay-model-lifetime-gcc-v2','gameplay-object-lifetime-llvm-v10','gameplay-object-lifetime-gcc-v10']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in names];data=[json.loads(p.read_text())for p in paths]
 for i,d in enumerate(data):
  assert not d['game_launched'] and d['status']!='failed'
  for p,h in d['source_sha256'].items():assert sha(ROOT/p)==h,p
  if i in [0,1,2,3]:assert d['status']=='passed'
 for i in [0,2,4,6]:assert data[i]['source_sha256']==data[i+1]['source_sha256'] and observed(data[i])==observed(data[i+1])
 for d in data[4:6]:assert d['results']['real_rooms']==14 and d['results']['real_instances']==22 and d['results']['model_refusal_cases']==d['results']['numeric_refusal_cases']==10
 source={p:h for d in data for p,h in d['source_sha256'].items()}
 previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v12.json';prior=json.loads(previous.read_text());masks=data[0]['result']['coverage']
 for k,v in masks.items():assert v['count']==prior['coverage'][k]['native_algorithm']
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();assert hashlib.sha256(raw).hexdigest()=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 for b in prior['bindings']:
  i=b['opcode'];assert b['ordinary']['native_algorithm']==masks['ordinary']['native_algorithm'][i] and b['offline_actor']['native_algorithm']==masks['offline_actor']['native_algorithm'][i]
  assert int(b['ordinary']['original_target'],16)==struct.unpack_from('<I',raw,0x717830-0x570000+4*i)[0]
 docs=[ROOT/'docs/native-gameplay/SCENARIO_MODEL_BINDINGS.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.scenario.qualification.v13',status='qualified_partial_real_model_bindings_and_checked_lifetime',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,new_opcodes=[],
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),source_sha256=source,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},
  coverage=prior['coverage'],bindings=prior['bindings'],
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d.get('compiler'),compiler_sha256=d['compiler_sha256'],result=observed(d),legacy_result=d.get('legacy_results'),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments',sum(x['matched_comments']for x in d.get('original_word_audits',[]))))for p,d in zip(paths,data)],
  real_provider=dict(canonical_scene_models=True,canonical_entity_store=True,strong_native_target_leases=True,stale_generation_refused=True,mutable_external_pose_reads=True,object_pose_components=16,legacy_missing_w_refused=True,script_visibility_or80_distinct_from_constructor_mark1=True,ff_create_mark_without_bind=True,outside128_retirement_refused=True),
  caller_failures=dict(model_refusal_before_flags_and_allocation=True,numeric_refusal_before_flags_and_allocation=True,postcall_health_propagated=True,checked_close_retains_failure_and_drains=True,mutation_and_close_reentry_refused=True),
  composition=dict(unique_owned_rooms=7,room_variant_cases=14,declared_variants=['stock','controlled legacy type/placement profile'],instances=22,updates=176,first_disables=14,model_refusal_cases=10,numeric_refusal_cases=10,actual_original_remap_bind_unbind=True,actual_original_caller_bodies=True,renderer_implemented=False),
  numeric=dict(native_original_polynomial_object_yaw=True,qualified_math_source_unchanged=True,corrected_test_yaw_preserves_w_translation=True,physical_ps2_exceptional_parity=False),
  limitations=['No new opcode mask entry is claimed; this checkpoint closes a real native consumer dependency and fixes missing canonical W ownership.','Seven owned rooms plus declared controlled variants are not all rooms, full stock reachability or game installation.','Original geometry retains declared surrounding/tolerance profiles; complete bit-exact rendering/whole-physics parity is not established.','Invalid native identities/slots refuse; dangling original pointer reuse and unowned out-of-range source writes are not reproduced.','The real adapter explicitly refuses its legacy twelve-float retain route instead of inventing W values.','Original instructions/register/RAM representations exist only in offline tests; production uses typed native objects and matrices.','Counts overlap across cohorts and cannot be added as unique instruction coverage.','Actual game callers, renderer/model asset initialization, remaining script/event providers and full stock/co-op/save validation remain open.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v13.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
