"""Seal complete dialogue sequence, canonical timer adoption and application worker evidence."""
import hashlib,json,re
from audit_retail_effect_descriptors import compare_source
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
sha=lambda p:hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 owned=['game/native/gameplay_world/'+name+ext for name in ['dialogue_response_uses','dialogue_input_request','dialogue_targeting','dialogue_response_choice','dialogue_responses_state','inventory_dialogue_presentation']for ext in ['.hpp','.cpp']]
 owned+=['game/native/gameplay_world/'+name for name in ['dialogue_responses.hpp','dialogue_pool.hpp','dialogue_pool.cpp','speech_state.hpp','actor_initial_state.hpp','primary_actor_records_tests.cpp']]
 owned+=['game/native/gameplay_update/dialogue_workers.'+ext for ext in ['hpp','cpp']]
 owned+=['game/native/gameplay_scenario/auxiliary_room_rows.'+ext for ext in ['hpp','cpp']]
 owned+=['game/native/gameplay_application/dialogue_workers_tests.cpp']
 helpers=['tools/native_reconstruction/'+prefix+name+ext for name in ['dialogue_response_uses','dialogue_input_request','dialogue_targeting','dialogue_response_choice','dialogue_responses']for prefix,ext in [('', '_tests.cpp'),('verify_', '.py')]]
 helpers+=['tools/native_reconstruction/verify_dialogue_response_parents.py','tools/native_reconstruction/qualify_dialogue_responses_v1.py','tools/native_reconstruction/dialogue_conditions_tests.cpp','docs/native-gameplay/DIALOGUE_RESPONSES.md']
 overlay_path=ROOT/'build-function-index/owned-overlays/o2.bin';assert sha(overlay_path)=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226';overlay=overlay_path.read_bytes()
 phase_source='recomp/config/output_ovl/o2/o2_005FED00_0x5fed00.cpp';begin,end=[int(value,16)for value in re.search(r'// Address: (0x[0-9a-f]+) - (0x[0-9a-f]+)',(ROOT/phase_source).read_text()).groups()]
 phase_proof=compare_source('complete outer ordinary worker order',phase_source,begin,end,lambda at,n:overlay[at-0x570000:at-0x570000+n]);assert int.from_bytes(overlay[0x5fee00-0x570000:0x5fee04-0x570000],'little')==0x0c1adf90
 helpers.append(phase_source)
 receipts=[];results={};final_pairs={}
 groups={'use_counts':('dialogue-response-uses','v1'),'input':('dialogue-input-request','v2'),'targeting':('dialogue-targeting','v3'),'choice_and_all_conditions':('dialogue-response-choice','v4'),'full_clear':('dialogue-response-full-clears','v3'),'complete_sequence':('dialogue-responses','v8'),'current_parents':('dialogue-response-parents','v2')}
 for domain,(directory,version)in groups.items():
  observations=[]
  for cc in ['gcc','llvm']:
   path=ROOT/'build-native-sjuni'/f'{directory}-{cc}-{version}/receipt.json';record=json.loads(path.read_text());assert record['status']=='passed',(domain,cc)
   for name,digest in record.get('output_sha256',{}).items():assert sha(path.parent/name)==digest,(domain,name)
   if domain=='current_parents':
    assert record['parent_tests']==30 and not record['source_drift'];assert '31 checks'in record['owned_worker_output'];value=dict(parent_tests=30,owned_worker_checks=31);final_pairs[cc]=record
   else:
    assert record.get('snapshot_unchanged',record.get('source_unchanged')),(domain,cc);value=record['observed']
   if domain=='complete_sequence':
    assert record['observed']['exact_unsupported_read_prefixes']==2 and record['observed']['external_shared_timer_commands']>0
    for name,digest in record['source_sha256'].items():assert sha(path.parent/'source'/name)==digest,name
    for name,digest in record['native_archives'].items():assert sha(path.parent/'archives'/name)==digest,name
    for name in owned:
     if name!='game/native/gameplay_world/primary_actor_records_tests.cpp':assert record['source_sha256'].get(name)==sha(ROOT/name),name
   if domain=='full_clear':
    for name in ['game/native/gameplay_world/actor_initial_state.hpp','game/native/gameplay_world/speech_state.hpp','game/native/gameplay_world/primary_actor_records_tests.cpp']:assert record['source_sha256'][name]==sha(ROOT/name),name
   observations.append(value);receipts.append(dict(domain=domain,path=path.relative_to(ROOT).as_posix(),sha256=sha(path),snapshot_unchanged=record.get('snapshot_unchanged',record.get('source_unchanged')),live_source_drift=record.get('live_source_drift',[])))
  assert observations[0]==observations[1],domain;results[domain]=observations[0]
 for cc,parent in final_pairs.items():
  for name in owned:
   if name!='game/native/gameplay_world/primary_actor_records_tests.cpp':assert parent['source_sha256'].get(name)==sha(ROOT/name),(cc,name)
 fragments={}
 for name in ['game/native/gameplay_world/CMakeLists.txt','game/native/gameplay_application/CMakeLists.txt']:
  lines=(ROOT/name).read_text().splitlines();selected=[line for line in lines if line.startswith('add_library(reo_native_dialogue STATIC')or line.startswith('target_sources(reo_native_dialogue PRIVATE')]
  start=next((i for i,line in enumerate(lines)if line.startswith('add_executable(dialogue_workers_tests ')),None)
  if start is not None:selected+=lines[start:start+6]
  text='\n'.join(selected)+'\n';fragments[name]=dict(text=text,sha256=hashlib.sha256(text.encode()).hexdigest())
 failures=[]
 for directory,reason in [('dialogue-responses-gcc-v1','Initial source crawler encountered a generated conditional fixture include.'),('dialogue-responses-gcc-v2','Fixture supplied a null completion RuleBook; fixed to the real file1 RuleBook.'),('dialogue-responses-llvm-v2','Same fixture-only null RuleBook failure.'),('dialogue-responses-gcc-v5','New negative-target fixture retained nonzero variant and therefore did not reach the intended fallback choice.'),('dialogue-responses-llvm-v5','Same incorrectly prepared refusal fixture.'),('dialogue-responses-gcc-v6','Diagnostic fixture identified the nonzero-variant early return; corrected the actual menu-actions producer.'),('dialogue-response-choice-gcc-v1','Fixture restored target-context with a promoted four-byte write; final explicit widths preserve adjacent DC8.'),('dialogue-response-choice-gcc-v2','Repeated fixture width mismatch retained.'),('dialogue-response-choice-llvm-v2','Same fixture width mismatch retained.'),('dialogue-targeting-gcc-v2','Draft negative locked-target branch mismatch; corrected to source fallback before final paired targeting proof.')]:
  path=ROOT/'build-native-sjuni'/directory/'receipt.json'
  if path.is_file():failures.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),reason=reason))
 result=dict(schema=1,status='qualified_native_dialogue_response_sequence_and_worker',stage4_complete=False,game_run=False,audio_device_opened=False,source_sha256={name:sha(ROOT/name)for name in owned+helpers},owned_cmake_fragments=fragments,outer_phase_original_body=phase_proof,results=results,receipts=receipts,retained_failures=failures,superseded_evidence=['Earlier pool/condition snapshots retained separate flags/counters. Final production delegates to the existing Session AuxiliaryScene, the same state written by script commands120/121.','The first worker contract used gameplay_ui; complete5FED00 places6B7E40 at5FEE00, Worker::sequences. Final adapter uses the sequence prefix and the existing Update owner performs final6B80A0 once.','Full responsev3/v4/v7 remain exact immutable historical snapshots. Currentv8 plus parentv2 qualify the consolidated source and latest Actor ABI.'],limits=['Complete6B7E40 and admitted reached bodies execute against actual canonical native owners. The original transport send boundary captures defined speech payload roles; native uses real Update publication and ActorMessageQueue. No network-delivery/game-frame claim is made.','Mode-zero input without fresh direction uses the actual caller physical-loop index. Other unproduced direction history and negative primary target address profiles stop at exact test-only original reads and return typed native refusal.','Positive full-sequence auxiliary profiles are passive or inactive for voice. NPC archive activation, full1D41F0 bank loading/6B7720 reset, later glyph rendering and complete application startup remain separate reached integration.','The worker borrows explicit menu input/actions. Its real InventoryUi blocked-byte producer is preserved; unknown reached state refuses. No inferred global input/default UI producer or duplicated World/flags/actor ownership is introduced.'])
 target=ROOT/'tools/native_reconstruction/native_dialogue_responses_qualification_v1.json';target.write_text(json.dumps(result,indent=2)+'\n');print(result['status'])
if __name__=='__main__':main()
