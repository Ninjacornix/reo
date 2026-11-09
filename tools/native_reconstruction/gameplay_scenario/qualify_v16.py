"""Freeze complete native admitted actor request callbacks and VM v16."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in ['gameplay-scenario-llvm-v33','gameplay-scenario-gcc-v23']];data=[json.loads(p.read_text())for p in paths]
 for d in data:
  assert d['status']=='passed' and not d['game_launched'] and not d['installed_in_game']
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest,p
 assert data[0]['source_sha256']==data[1]['source_sha256'] and data[0]['result']==data[1]['result']
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8)for i in range(432)];masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v15.json';docs=[ROOT/'docs/native-gameplay/SCENARIO_ACTOR_REQUESTS.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.scenario.qualification.v16',status='qualified_partial_native_actor_request_producers_and_complete_admitted_consumers',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,new_opcodes=[0x100,0x109],
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),owned_overlay_sha256=owned,source_sha256=data[0]['source_sha256'],documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d['result'],checked_owned_instruction_comments=d['checked_owned_instruction_comments'])for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True)for k,v in masks.items()},bindings=bindings,
  actor_requests=dict(supported_callback_kinds=[0,5,8,0x17,0x28],complete_64ae50_consumer=True,complete_6261d0_cleanup=True,complete_original_callbacks=True,uses_canonical_action_pose_snapshot=True,request_pending_distinct_from_control_pending=True,canonical_session_notice=True,pending_cleared_before_status80_rejection=True,source_other_kind_callbacks_not_claimed=True,unknown_active_kind_refuses_before_effects=True,original_ignored_unknown_branches_compared=True),
  canonical_strided_flags=dict(existing_shared_bank=True,raw_half_getter_checked=True,no_duplicate_mask_storage=True),
  oracle_profile=dict(actual_producers_consumer_cleanup_callbacks_and_snapshot=True,original_mips_only_offline=True,source_hash_closure_captured=True,full_record_byte_guards=True),
  limitations=['Whole native stock programs, actual game caller installation and runtime reachability remain unproven.','Algorithm masks include original no-op bindings and do not measure full provider or gameplay completion.','Actor request producer native admission supports five exact callback kinds; other active callback kinds remain unadmitted.','Original instructions and CPU/RAM scaffolding exist only in offline tests; production uses canonical typed native owners.','Assertion and invocation counts overlap and are not unique instruction coverage.','Remaining script/event providers, actual native content admission and stock/co-op/save validation remain open.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v16.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
