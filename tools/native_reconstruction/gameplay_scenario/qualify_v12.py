"""Freeze native scene-model state/import/transform owner and VM v12."""
import hashlib,json,struct
from pathlib import Path
ROOT=Path(__file__).resolve().parents[3]
def sha(p):return hashlib.sha256(p.read_bytes()).hexdigest()
def main():
 names=['gameplay-scenario-llvm-v25','gameplay-scenario-gcc-v17','gameplay-scene-models-llvm-v2','gameplay-scene-models-gcc-v2']
 paths=[ROOT/'build-native-sjuni'/n/'receipt.json'for n in names];data=[json.loads(p.read_text())for p in paths]
 for d in data:
  assert d['status']=='passed' and not d['game_launched'] and not d['installed_in_game']
  for p,digest in d['source_sha256'].items():assert sha(ROOT/p)==digest,p
 for a,b in [(data[0],data[1]),(data[2],data[3])]:assert a['source_sha256']==b['source_sha256'] and a['result']==b['result']
 source={p:digest for d in data for p,digest in d['source_sha256'].items()}
 raw=(ROOT/'build-function-index/owned-overlays/o2.bin').read_bytes();owned=hashlib.sha256(raw).hexdigest();assert owned=='45360a971e88878312576abaebd1a7b8346f7e94cc032adde9172343f14e6226'
 ordinary=struct.unpack_from('<432I',raw,0x717830-0x570000);offline=[struct.unpack_from('<IBBBB',raw,0x73cbe0-0x570000+i*8)for i in range(432)];masks=data[0]['result']['coverage'];bindings=[]
 for i in range(432):bindings.append(dict(opcode=i,opcode_hex=f'{i:03X}',ordinary=dict(original_target=f'{ordinary[i]:08X}',native_algorithm=masks['ordinary']['native_algorithm'][i]),offline_actor=dict(original_target=f'{offline[i][0]:08X}',native_algorithm=masks['offline_actor']['native_algorithm'][i],relation_one=offline[i][1],restricted_category=offline[i][2],relation_two=offline[i][3]),installed_in_game=False,production_provider_coverage_proven=False))
 audit_path=ROOT/'build-native-sjuni/gameplay-model-remaps-v1/receipt.json';audit=json.loads(audit_path.read_text());assert audit['status']=='passed' and audit['owned_rooms']==166 and audit['remap_upper_bounds']=={'32':166}
 math=ROOT/'tools/native_reconstruction/native_transform_math_qualification_v1.json';previous=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v11.json';docs=[ROOT/'docs/native-gameplay/SCENARIO_MODELS.md',Path(__file__),ROOT/'tools/native_reconstruction/gameplay_scenario/audit_model_remaps.py']
 q=dict(schema='reo.native.gameplay.scenario.qualification.v12',status='qualified_partial_native_room_model_state_and_transforms',complete=False,stage4_complete=False,installed_in_game=False,game_launched=False,live_process_access=False,physical_ps2_exceptional_parity=False,
  previous_qualification=dict(path=previous.relative_to(ROOT).as_posix(),sha256=sha(previous)),native_math_qualification=dict(path=math.relative_to(ROOT).as_posix(),sha256=sha(math)),owned_overlay_sha256=owned,source_sha256=source,
  documentation_and_tools_sha256={p.relative_to(ROOT).as_posix():sha(p)for p in docs},
  receipts=[dict(path=p.relative_to(ROOT).as_posix(),sha256=sha(p),compiler=d['compiler'],compiler_sha256=d['compiler_sha256'],result=d['result'],checked_owned_instruction_comments=d.get('checked_owned_instruction_comments',sum(x['matched_comments']for x in d.get('original_owned_bodies',[]))))for p,d in zip(paths,data)],
  coverage={k:dict(native_algorithm=v['count'],total=432,unsupported=432-v['count'],includes_original_noop_bindings=True)for k,v in masks.items()},bindings=bindings,new_opcodes=[0xb0,0xb1,0xb4],
  model_profile=dict(remap_bytes=32,visibility_bytes=128,style_words=128,poses=128,presets=8,explicit_style_bit_alias_for_visibility_indices_128_to_255=True,pose_style_outside_owned_slots_refused=True,initialized_identity_profile_required=True,renderer_implemented=False,external_pose_binding_implemented=False),
  owned_content_audit=dict(path=audit_path.relative_to(ROOT).as_posix(),sha256=sha(audit_path),rooms=166,remap_upper_bounds=audit['remap_upper_bounds'],conservative_prefix_preset_counts=audit['prefix_transform_preset_counts'],runtime_reachability_proven=False),
  preset_sha256=data[2]['owned_preset_sha256'],owned_assets=data[2]['owned_assets'],
  oracle_profile=dict(vu_capable_qualified_finite_simd=True,sdk131_sign_extended_word_setter=True,historical_scalar_cohorts_retained=True,prior_admitted_handler_divergence_observed=False,fast_math=False,contraction=False,transitive_native_header_closure_captured=True),
  limitations=['Native algorithm masks do not establish complete reachable stock scripts, actual provider admission or game caller installation.','Native model state omits external pose bindings, actual model resource construction, scheduled pose programs and renderer consumers.','Visibility index128..255 mutates an explicit style-word bit; this does not establish those conservative prefix paths executed in a game.','Default native pose transform profile admits eight verified presets; other source table indices remain refused and unknown.','Wider source pose/style indexing is refused rather than exporting writes into unrelated state.','Original complete instruction bodies and CPU/VU state exist only in offline tests, not native production.','Qualified finite FP32/SIMD behavior is distinct from physical PS2 exceptional arithmetic/flags/accumulator proof.','Oracle/context and assertion counts overlap across cohorts and are not unique instruction or full-game completion totals.'])
 out=ROOT/'tools/native_reconstruction/gameplay_scenario_qualification_v12.json';assert not out.exists();out.write_text(json.dumps(q,indent=2)+'\n');print(json.dumps(dict(path=out.relative_to(ROOT).as_posix(),sha256=sha(out),coverage=q['coverage'])))
if __name__=='__main__':main()
