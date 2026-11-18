"""Freeze native room-object commands and complete live C4 consumer v15."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in ['gameplay-scenario-llvm-v30','gameplay-scenario-gcc-v21','gameplay-room-object-commands-llvm-v2','gameplay-room-object-commands-gcc-v2']];data=[json.loads(p.read_text())for p in paths]
 for d in data:
  assert (d['status']=='passed' or d['status']=='native complete C4 and stock room-object consumer composition passed') and not d['game_launched'] and not d.get('installed_in_game',False)
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest,p
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a.get('result',a.get('results'))==b.get('result',b.get('results'))
 source={p:digest for d in data for p,digest in d['source_sha256'].items()}
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8)for i in range(432)];masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v14.json';docs=[ROOT/'docs/native-gameplay/SCENARIO_ROOM_OBJECT_COMMANDS.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.scenario.qualification.v15',status='qualified_partial_native_room_object_commands_and_live_move_consumer',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,new_opcodes=list(range(0xc2,0xc8)),
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),owned_overlay_sha256=owned,source_sha256=source,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d.get('compiler'),compiler_sha256=d['compiler_sha256'],result=d.get('result',d.get('results')),legacy_result=d.get('legacy_results'),real_model_result=d.get('real_model_results'),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments',sum(x['matched_comments']for x in d.get('original_word_audits',[]))))for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True)for k,v in masks.items()},bindings=bindings,
  canonical_owners=dict(room_objects=32,cached_queries=8,successful_import_readiness=True,query_grid_readiness_required=True,flags_only_import_without_grid_admitted=True,live_lifetime_identity_required_for_c4=True,coordinates_low_unsigned_bytes=True,first_active_external_match=True,live_instance_material_proxy_consumer=True,original_enable_disable_inactive_shadow_not_reused=True),
  oracle_profile=dict(actual_original_wrappers=True,actual_original_c4_center_and_proxy_children=True,dispatcher_only_instance_free_profile=True,live_consumers_tested_separately=True,original_mips_only_offline=True),
  limitations=['Whole native stock programs, actual game caller installation and runtime reachability remain unproven.','Algorithm masks include original no-op bindings and do not measure full provider or gameplay completion.','Pre-grid cached-query physical-slot aliases remain unadmitted; imported flags-only state does not require a grid.','Original instructions and CPU/RAM scaffolding exist only in offline tests; production uses canonical typed native owners.','Assertion and invocation counts overlap and are not unique instruction coverage.','Remaining script/event providers, actual native content admission and stock/co-op/save validation remain open.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v15.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
