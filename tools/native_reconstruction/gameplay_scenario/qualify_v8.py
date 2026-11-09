"""Freeze native linked controls, actual type-five reset and File1 leaf, v8."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-scenario-llvm-v16','gameplay-scenario-gcc-v13','gameplay-scene-reset-llvm-v1','gameplay-scene-reset-gcc-v1','gameplay-scene-controls-llvm-v4','gameplay-scene-controls-gcc-v4']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 assert all(d['status']=='passed' and not d['game_launched'] and not d['installed_in_game'] for d in data)
 for a,b in [(data[0],data[1]),(data[2],data[3]),(data[4],data[5])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
 source={}
 for d in data:
  for p,digest in d['source_sha256'].items():
   assert sha(ROOT/p)==digest
   if p in source:assert source[p]==digest
   source[p]=digest
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8) for i in range(432)]
 masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 capacity_path=ROOT/'build-native-sjuni/gameplay-sequence-capacity-v2/receipt.json';capacity=json.loads(capacity_path.read_text());assert capacity['status']=='passed' and capacity['cleared_record_capacity']==32 and capacity['max_count']==26
 docs=[ROOT/'docs/native-gameplay/SCENARIO_LINKED_CONTROL_VM.md',ROOT/'tools/native_reconstruction/gameplay_scenario/audit_sequence_capacity.py',Path(__file__)]
 result=dict(schema='reo.native.gameplay.scenario.qualification.v8',status='qualified_partial_native_linked_controls_reset_and_file1_leaf',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,
  owned_overlay_sha256=owned,source_sha256=source,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],assertions=d['result']['checks'],original_invocations=d['result'].get('original_dispatch_invocations',d['result'].get('original_invocations')),checked_owned_instruction_comments=d['checked_owned_instruction_comments']) for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},bindings=bindings,
  new_ordinary_linked_opcodes=[i for i in range(0x50,0x60) if i!=0x5a]+[0x72,0xb5,0xf6],
  identical_offline_linked_opcodes=[0x51,0x55,0x56,0x57,0x5f,0x72,0xb5],different_offline_linked_opcodes_still_unsupported=[0x50,0x52,0x53,0x54,0x58,0x59,0x5b,0x5c,0x5d,0x5e,0xf6],
  native_type_five_reset=dict(complete_original_stores=10,fields_added=3,effect_double_used_in_reset_cohort=False),
  file1_return_only_opcode=dict(opcode=0x190,main_elf_sha256=data[0]['original_main_elf_sha256'],leaf=data[0]['original_main_leaf'],opcode191_unsupported=True),
  corrected_sequence_profile=dict(records=32,old_v5_projection=256,old_outside_owner_tests_establish_valid_ownership=False,owned_section0_cases=capacity['rdt_count'],owned_max_records=capacity['max_count'],audit_receipt=dict(path=capacity_path.relative_to(ROOT).as_posix(),sha256=sha(capacity_path))),
  original_numeric_handler_invocations_per_compiler=65536,
  limitations=['Algorithm masks do not establish complete reachable stock coverage, production providers, actual caller installation, performance or complete gameplay.','All programs containing unsupported handlers are refused before native installation; stock importer/admission remains incomplete.','Linked command state/reset are native; full linked-record creation/content/update consumers and refresh6B5E10 require actual providers.','Eleven different offline linked handlers remain unsupported; ordinary numeric bindings do not establish those semantics.','Opcode190 return-only behavior is admitted only for the pinned File1 main ELF;191 actual scenario-specific side effects remain unsupported.','Original instruction/register/memory scaffolding is offline oracle only. No MIPS execution ships in these native owners.','Receipt instruction and assertion counts overlap; do not add cohorts as unique original coverage.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v8.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=result['coverage'])))
if __name__=='__main__':main()
