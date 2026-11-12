"""Seal paired immutable SP definitions, concrete conditions and canonical producers."""
import argparse,hashlib,json,struct,collections
from pathlib import Path
ROOT=Path(__file__).resolve().parents[2]
def sha(path):return hashlib.sha256(path.read_bytes()).hexdigest()
def main():
 p=argparse.ArgumentParser();p.add_argument('--archive',type=Path,required=True);p.add_argument('--contract-receipt',type=Path,action='append',required=True);a=p.parse_args()
 native=['game/native/gameplay_scenario/dialogue_response_program.'+x for x in ['hpp','cpp']]
 native+=['game/native/gameplay_world/'+name+ext for name in ['dialogue_conditions','dialogue_inventory_traits','dialogue_partner_characters']for ext in ['.hpp','.cpp']]
 native+=['game/native/gameplay_world/'+name for name in ['dialogue_pool.hpp','dialogue_pool.cpp','dialogue_flag_durations.hpp','speech_state.hpp','actor_initial_state.hpp','primary_actor_records_tests.cpp','dialogue_response_contract_tests.cpp']]
 tools=['tools/native_reconstruction/'+prefix+name+ext for name in ['dialogue_response_program','dialogue_conditions','dialogue_flag_durations','dialogue_flag_pool','dialogue_inventory_traits','dialogue_partner_characters']for prefix,ext in [('', '_tests.cpp'),('verify_', '.py')]]
 supporting=['tools/native_reconstruction/'+name for name in ['dialogue_pool_tests.cpp','cached_dialogue_pool_tests.cpp']]
 own=native+tools+supporting+['tools/native_reconstruction/qualify_dialogue_response_conditions_v1.py','docs/native-gameplay/DIALOGUE_RESPONSE_CONDITIONS.md']
 groups={'program':('dialogue-response-program','v2',4358844),'conditions_and_pool':('dialogue-conditions','v7',3915944),'durations':('dialogue-flag-durations','v3',2101248),'durations_in_pool':('dialogue-flag-pool','v2',2298936),'inventory_traits':('dialogue-inventory-traits','v1',1181211),'partner_segment':('dialogue-partner-characters','v1',8203),'actual_full_clears':('dialogue-partner-full-clears','v1',2237276)}
 receipts=[];observed={};proved=set()
 focused={
  'program':{'game/native/gameplay_scenario/dialogue_response_program.hpp','game/native/gameplay_scenario/dialogue_response_program.cpp'},
  'conditions_and_pool':set(native)-{'game/native/gameplay_world/dialogue_response_contract_tests.cpp','game/native/gameplay_world/primary_actor_records_tests.cpp'},
  'durations':{'game/native/gameplay_world/dialogue_flag_durations.hpp'},
  'durations_in_pool':{'game/native/gameplay_world/dialogue_pool.hpp','game/native/gameplay_world/dialogue_pool.cpp','game/native/gameplay_world/dialogue_flag_durations.hpp'},
  'inventory_traits':{'game/native/gameplay_world/dialogue_inventory_traits.hpp','game/native/gameplay_world/dialogue_inventory_traits.cpp'},
  'partner_segment':{'game/native/gameplay_world/dialogue_partner_characters.hpp','game/native/gameplay_world/dialogue_partner_characters.cpp','game/native/gameplay_world/speech_state.hpp'},
  'actual_full_clears':{'game/native/gameplay_world/actor_initial_state.hpp','game/native/gameplay_world/speech_state.hpp','game/native/gameplay_world/primary_actor_records_tests.cpp'}}
 for group,(directory,version,checks)in groups.items():
  pair=[]
  for compiler in ['gcc','llvm']:
   path=ROOT/'build-native-sjuni'/f'{directory}-{compiler}-{version}/receipt.json';d=json.loads(path.read_text());assert d['status']=='passed'and d['observed']['checks']==checks
   assert d.get('snapshot_unchanged',d.get('source_unchanged'))and not d.get('live_source_drift',[])
   snapshot=path.parent/'source'
   for name,digest in d['source_sha256'].items():
    if snapshot.exists():assert sha(snapshot/name)==digest
    if name in focused[group]or(name in tools and directory.replace('-','_')in Path(name).stem):
     assert sha(ROOT/name)==digest,(group,name);proved.add(name)
   for name,digest in d.get('output_sha256',{}).items():assert sha(path.parent/name)==digest
   receipts.append(dict(domain=group,path=path.relative_to(ROOT).as_posix(),sha256=sha(path),snapshot_unchanged=True,live_source_drift=[]));pair.append(d['observed'])
  assert pair[0]==pair[1];observed[group]=pair[0]
 for name in native:
  if name!='game/native/gameplay_world/dialogue_response_contract_tests.cpp':assert name in proved,name
 coverage=collections.Counter();asset_rows=json.loads((ROOT/'build-native-sjuni/dialogue-response-program-gcc-v2/receipt.json').read_text())['owned_assets'];asset_proofs=[]
 with a.archive.open('rb')as stream:
  for asset in asset_rows:
   if not asset['name'].startswith('sp')or asset['name'].startswith('spm'):continue
   stream.seek(asset['offset']);data=stream.read(asset['bytes']);assert hashlib.sha256(data).hexdigest()==asset['sha256'];asset_proofs.append(asset)
   table=struct.unpack_from('<I',data,20)[0]
   for offset in struct.unpack_from('<6000I',data,table):
    if offset:
     assert offset+48<=len(data)
     for i in range(4):coverage[data[offset+4+8*i]]+=1
 assert len(asset_proofs)==270
 admitted={0,1,2,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20,21,22,23,24,25,26,27,29,31,32,33,35,44,46,47,48,255}
 assert set(coverage)<=admitted
 contracts=[]
 for path in a.contract_receipt:
  path=path.resolve();d=json.loads(path.read_text());assert path.is_relative_to(ROOT)and d['status']=='passed'and not d['source_drift']and d['parent_tests']==28
  assert any('dialogue_response_contract_tests'in command for command in d['commands'])
  assert 'game/native/gameplay_world/dialogue_response_contract_tests.cpp'in d['source_sha256']
  for name in native:
   if name in d['source_sha256']:assert sha(ROOT/name)==d['source_sha256'][name],name
  for name,digest in d['output_sha256'].items():assert sha(path.parent/name)==digest
  contracts.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),purpose='Current strict CMake graph with native_dialogue_response_contract.'))
 assert len(contracts)==2
 fragments={}
 for name in ['game/native/gameplay_scenario/CMakeLists.txt','game/native/gameplay_world/CMakeLists.txt']:
  lines=(ROOT/name).read_text().splitlines();owned=[line for line in lines if 'dialogue_assets.cpp'in line or line.startswith('add_library(reo_native_dialogue STATIC')];start=next((i for i,line in enumerate(lines)if line.startswith('add_executable(dialogue_response_contract_tests ')),None)
  if start is not None:owned+=lines[start:start+7]
  text='\n'.join(owned)+'\n';fragments[name]=dict(text=text,sha256=hashlib.sha256(text.encode()).hexdigest())
 retained=[]
 for directory,reason in [('dialogue-response-program-gcc-v1','Strict fixture indentation compile failure.'),('dialogue-response-program-llvm-v1','Fixture assumed selection zero existed in every bank; corrected to a retained nonempty selection.'),('dialogue-flag-durations-gcc-v1','Reference fixture lacked signed shift macros.'),('dialogue-flag-durations-gcc-v2','Fixture omitted vector include.'),('dialogue-conditions-gcc-v2','Timed out in original nonadvancing inactive auxiliary-node branch; retained complete source and logs.'),('dialogue-conditions-llvm-v2','Same diagnosed original inactive-node loop.'),('dialogue-conditions-gcc-v3','Repeated source-loop timeout retained before the controlled input observer was installed.'),('dialogue-conditions-llvm-v3','Repeated source-loop timeout retained.'),('dialogue-conditions-gcc-v5','Fixture lacked explicit SceneResources include.'),('dialogue-conditions-llvm-v5','Same fixture-only missing include.')]:
  path=ROOT/'build-native-sjuni'/directory/'receipt.json';assert path.is_file();retained.append(dict(path=path.relative_to(ROOT).as_posix(),sha256=sha(path),reason=reason))
 result=dict(schema=1,status='qualified_native_sp_response_definitions_and_conditions',stage4_complete=False,game_run=False,audio_device_opened=False,source_sha256={name:sha(ROOT/name)for name in own},owned_cmake_fragments=fragments,results=observed,owned_condition_kind_counts=dict(sorted(coverage.items())),owned_sp_assets=asset_proofs,receipts=receipts,current_contract_receipts=contracts,retained_failures=retained,superseded_evidence=['Earlier dialogue pool/cache seals retain historical source hashes. Their prefix-field projection is superseded by the corrected B99 motion_style mapping in the integrated conditions v7 and flag-pool v2 pairs.','Initial limited condition v1/v2 evidence is superseded: source54F is motion_class, not response_class140.','The resource trait helper5B5350 is distinct from scenario flag5F8330 and bounded byte flag5709B0.'],limits=['All condition kinds present in the270 owned SP banks are represented. Additional dispatcher kinds using unproduced phase-dependent scratch remain explicit unsupported profiles.','The actual inactive-node branches in5F80F0/5F81A0 do not advance. Original bodies remain unchanged; test-only observers interrupt at the first reached inactive input. Native returns unsupported_profile without inventing a retail result.','The partner helper is the actual6B819C..8218 segment within complete6B8130. Complete original inactive profiles execute; active request/cooldown/response selection is not replaced by this segment. A fifth other character refuses before DB0 overwrite, preserving four completed writes.','Complete6B7610 is executed only as a projection onto represented canonical speech/record/flag/duration fields. Other response-monitor/timer roles are not established by this owner.','Outer6B7E40, live reply/monitor state, complete1D41F0 bank publication, actual visibility initialization and later text rendering still require their actual producers/consumers. No complete application-frame or full Stage4 acceptance is claimed.'])
 target=ROOT/'tools/native_reconstruction/native_dialogue_response_conditions_qualification_v1.json';target.write_text(json.dumps(result,indent=2)+'\n');print(result['status'])
if __name__=='__main__':main()
