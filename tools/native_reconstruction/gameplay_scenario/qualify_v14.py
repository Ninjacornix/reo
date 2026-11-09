"""Freeze complete native scenario-two room rules and VM v14."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in ['gameplay-scenario-llvm-v27','gameplay-scenario-gcc-v19']];data=[json.loads(p.read_text())for p in paths]
 for d in data:
  assert d['status']=='passed' and not d['game_launched'] and not d['installed_in_game']
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest,p
 assert data[0]['source_sha256']==data[1]['source_sha256'] and data[0]['result']==data[1]['result']
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8)for i in range(432)];masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v13.json';docs=[ROOT/'docs/native-gameplay/SCENARIO_ROOM_RULES.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.scenario.qualification.v14',status='qualified_partial_native_scenario_specific_room_rules',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,new_opcodes=[0x191],
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),owned_overlay_sha256=owned,source_sha256=data[0]['source_sha256'],documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d['result'],checked_owned_instruction_comments=d['checked_owned_instruction_comments'])for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True)for k,v in masks.items()},bindings=bindings,
  room_rules=dict(original_body='001B3C40',wrapper='00694E70',scenario_bits=16,scenario_available_required=True,canonical_flag_alias_required=True,primary_owner=0,ordered_flag_rereads=True,flag114_clear=False,secondary_flag496_room31_disables_all_type3=True,list_disabled_sentinel_preserved=True,no_notifications_added=True),
  oracle_profile=dict(actual_room_rule_and_flag_children=True,address_aliases_prefer_defined_original_body=True,original_mips_only_offline=True,source_hash_closure_captured=True),
  limitations=['Whole native stock programs, actual game caller installation and runtime reachability remain unproven.','Algorithm masks include original no-op bindings and do not measure full provider or gameplay completion.','The bounded native scene-control ownership profile refuses unavailable/budget-exhausted state.','Original instructions and CPU/RAM scaffolding exist only in offline tests; production uses canonical typed native owners.','Assertion and invocation counts overlap and are not unique instruction coverage.','Remaining script/event providers, actual native content admission and stock/co-op/save validation remain open.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v14.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
