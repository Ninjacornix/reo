"""Freeze complete typed live/saved control commands and interpreter v10."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-scenario-llvm-v18','gameplay-scenario-gcc-v15','gameplay-typed-controls-llvm-v1','gameplay-typed-controls-gcc-v1','gameplay-scene-controls-llvm-v5','gameplay-scene-controls-gcc-v5']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json' for n in names];data=[json.loads(p.read_text()) for p in paths]
 for d in data:
  assert d['status']=='passed' and not d['game_launched'] and not d['installed_in_game']
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest,(p,digest)
 for a,b in [(data[0],data[1]),(data[2],data[3]),(data[4],data[5])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
 sources={p:digest for d in data for p,digest in d['source_sha256'].items()}
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8) for i in range(432)]
 masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v9.json';prior=json.loads(previous.read_text())
 for p,digest in prior['source_sha256'].items():
  if Path(p).name in ['stream_channels.hpp','stream_channels.cpp','stream_gain_curve.inc','stream_instances.hpp','stream_instances.cpp']:assert sha(ROOT/p)==digest
 docs=[ROOT/'docs/native-gameplay/SCENARIO_TYPED_CONTROLS.md',Path(__file__)]
 q=dict(schema='reo.native.gameplay.scenario.qualification.v10',status='qualified_partial_native_live_and_saved_typed_controls',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),owned_overlay_sha256=owned,source_sha256=sources,documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p) for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d['result'],checked_owned_instruction_comments=d['checked_owned_instruction_comments']) for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True) for k,v in masks.items()},bindings=bindings,
  new_opcodes=[0x104,0x105],new_original_bodies=['6920E0','6922B0','7020E0','702380'],saved_control_profile=dict(owner_banks=3,default_records_per_owner=1024,stock_capacity_proven=False,full_saved_descriptor_projection=False),
  limitations=['Algorithm masks do not establish reachable stock coverage, actual provider admission, caller installation, performance or complete gameplay.','Saved descriptor owner projects only fields consumed by these commands; trailing authored data and actual stock importer/consumers remain unported.','Unknown native records carrying a supported live type tag refuse instead of inventing missing typed fields.','Default native descriptor capacity is an explicit admission profile; stock capacity remains unknown.','Context filtering, relation-zero sentinel early return and nonzero-relation saved writes are distinct original behaviors.','Complete original-body oracles execute only in private offline test outputs, not in native production.','Earlier stream qualifiers remain independent; the v10 VM retains null tick refusal before effects.','Assertion/instruction counts overlap across cohorts and must not be added as unique original coverage.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v10.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
