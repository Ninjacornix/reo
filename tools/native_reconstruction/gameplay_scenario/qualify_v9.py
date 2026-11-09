"""Freeze native engine stream controls, real instance adapter and VM v9."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-scenario-llvm-v17','gameplay-scenario-gcc-v14','gameplay-stream-channels-llvm-v7','gameplay-stream-channels-gcc-v6','gameplay-stream-instances-llvm-v6','gameplay-stream-instances-gcc-v6']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 assert all(d['status']=='passed' and not d['game_launched'] and not d['installed_in_game'] for d in data)
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
 assert data[4]['source_sha256']==data[5]['source_sha256'] and data[4]['native_cpp_source_sha256']==data[5]['native_cpp_source_sha256'] and data[4]['native_header_source_sha256']==data[5]['native_header_source_sha256']
 for d in data[4:]:assert d['result']['status']=='passed' and d['result']['underrun_frames']==0 and d['result']['background_visits']>0 and d['result']['output_frames']>0 and d['result']['game_tick']==1000 and not d['hardware_output']
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
 native={**data[4]['native_cpp_source_sha256'],**data[4]['native_header_source_sha256']}
 for p,digest in native.items():assert sha(ROOT/p)==digest
 docs=[ROOT/'docs/native-gameplay/SCENARIO_STREAM_CHANNELS.md',ROOT/'tools/native_reconstruction/gameplay_scenario/audit_sequence_capacity.py',Path(__file__)]
 result=dict(schema='reo.native.gameplay.scenario.qualification.v9',status='qualified_partial_native_engine_stream_controls_and_instance_adapter',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,hardware_output=False,
  owned_overlay_sha256=owned,source_sha256=source,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],assertions=d['result']['checks'],original_invocations=d['result'].get('original_dispatch_invocations',d['result'].get('original_invocations')),checked_owned_instruction_comments=d.get('checked_owned_instruction_comments'),result=d['result']) for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},bindings=bindings,
  new_stream_opcodes=[0x70,0x71],stream_profile=dict(channels=3,maximum_and_current_range=[0,323],nonnegative_finite_level=True,finite_step=True,nonfinite_quantization_refused=True,suspect_generator_zeroextension_policy_in_production=False),
  audio_tick=dict(optional=True,default_unavailable=True,explicit_zero_valid=True,missing_refused_before_effects=True,offline_wrapper_preflight=True,simulation_clock_alias=False),
  gain_curve_sha256=data[2]['owned_gain_curve_sha256'],owned_sdk_attenuation_sha256=data[4]['owned_attenuation_table_sha256'],
  actual_native_adapter=dict(native_dependency_sha256=native,owned_adx=data[4]['owned_asset'],synthetic_afs_fixture=True,stock_archive_route_admitted=False,explicit_test_mixer_order=[0,1,2],production_mixer_order_proven=False,withheld_engine_seconds=2,withheld_tick=1000,nonzero_engine_ramp_frozen=True,post_explicit_engine_service_ramp_advances=True),
  corrected_sequence_profile=dict(records=32,old_v5_projection=256,old_outside_owner_tests_establish_valid_ownership=False,owned_section0_cases=capacity['rdt_count'],owned_max_records=capacity['max_count'],audit_receipt=dict(path=capacity_path.relative_to(ROOT).as_posix(),sha256=sha(capacity_path))),
  original_numeric_handler_invocations_per_compiler=65536,
  limitations=['Algorithm masks do not establish complete reachable stock coverage, production providers, actual caller installation, performance or complete gameplay.','All programs containing unsupported handlers are refused before native installation; stock importer/admission remains incomplete.','Actual stream initialization/options application, source registration, mixer authority, prepared waits/named/voice routes and remaining query wrappers remain caller/domain gates.','Real native adapter tests use declared synthetic AFS metadata around a hash-verified owned ADX payload; they do not attest stock archive registration.','Software output tests do not establish physical audio, real-time device cadence, A/V sync, game speed or historical stutter fixes.','The numeric state profile excludes negative/outlier maxima and nonfinite quantization instead of promoting a suspect MFC1 code-generator edge into production policy.','Original instruction/register/memory scaffolding is offline oracle only. No MIPS execution ships in these native owners.','Native dependency hashes include translation units from the generated build graph; successful target build logs identify the actually compiled dependency cohort.','Receipt instruction and assertion counts overlap; do not add cohorts as unique original coverage.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v9.json';assert not out.exists();out.write_text(json.dumps(result,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=result['coverage'])))
if __name__=='__main__':main()
