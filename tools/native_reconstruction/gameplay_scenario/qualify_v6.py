"""Freeze native lighting and corrected sequence owner profile, v6."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-scenario-llvm-v12','gameplay-scenario-gcc-v10','gameplay-lighting-llvm-v1','gameplay-lighting-gcc-v1']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 assert all(d['status']=='passed' and not d['game_launched'] and not d['installed_in_game'] for d in data)
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
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
 docs=[ROOT/'docs/native-gameplay/SCENARIO_LIGHTING_STATE.md',ROOT/'tools/native_reconstruction/gameplay_scenario/audit_sequence_capacity.py',Path(__file__)]
 result=dict(schema='reo.native.gameplay.scenario.qualification.v6',status='qualified_partial_native_lighting_state_and_corrected_sequence_profile',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,
  owned_overlay_sha256=owned,source_sha256=source,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],assertions=d['result']['checks'],original_invocations=d['result'].get('original_dispatch_invocations',d['result'].get('original_invocations')),checked_owned_instruction_comments=d['checked_owned_instruction_comments']) for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},bindings=bindings,
  new_lighting_opcodes=[0x20,0x23,0x24,0x25],lighting_profile=dict(banks=4,entries_per_bank=32,primary_pool=64,owned_rdt_section_b_cases=166,modern_renderer_consumer=False,guest_addresses=False),
  corrected_sequence_profile=dict(records=32,old_v5_projection=256,old_outside_owner_tests_establish_valid_ownership=False,owned_section0_cases=capacity['rdt_count'],owned_max_records=capacity['max_count'],audit_receipt=dict(path=capacity_path.relative_to(ROOT).as_posix(),sha256=sha(capacity_path))),
  original_numeric_handler_invocations_per_compiler=65536,
  limitations=['Algorithm masks do not establish complete reachable stock coverage, production providers, actual caller installation, performance or complete gameplay.','All programs containing unsupported handlers are refused before native installation; stock importer/admission remains incomplete.','Lighting game-state management is native; renderer consumption, auxiliary allocation, weighted selection, transient constructors and fog remain separate gates.','Sequence command ownership is corrected to32; complete sequence data import/playback/animation/camera consumers remain unimplemented.','Original instruction/register/memory scaffolding is offline oracle only. No MIPS execution ships in these native owners.','Receipt instruction and assertion counts overlap; do not add cohorts as unique original coverage.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v6.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=result['coverage'])))
if __name__=='__main__':main()
